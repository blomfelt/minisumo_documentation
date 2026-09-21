
// Make sure that the following libraries are installed:
// - "NimBLE_Arduino" by h2zero

// Define your robot name below:
#define BLUETOOTH_NAME "MiniSumo Example"

// Define the speeds
#define SPEED_FORWARDS 150
#define SPEED_BACKWARDS 150 
#define SPEED_ROTATE 150

// NO NEED TO TOUCH ANYTHING BELOW THIS LINE
// ----------------------------------------------------------------------------

#include <NimBLEDevice.h>

// Create easier to read names for the pins
enum PinMappings
{
  SIG_KILL,
  MOTOR_IN1,
  MOTOR_IN2,
  MOTOR_IN3,
  MOTOR_IN4,
  _SIZE_LIMIT,
};

// Set up the pin numbers for each sensor, with an easier to read name than just the numbers
static uint8_t const pin[_SIZE_LIMIT] = {
    [SIG_KILL] = 18,
    [MOTOR_IN1] = 0,
    [MOTOR_IN2] = 1,
    [MOTOR_IN3] = 2,
    [MOTOR_IN4] = 3,
};

// Connection status led blinking variables
bool deviceConnected = false;
bool isAdvertising = false;
unsigned long previousMillis = 0;
const unsigned long blinkInterval = 500;
bool ledState = LOW;

// Setup UUID:s which are needed by the BLE
#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

// A simpler function to flash the LED X times
void flash_led(int times){
  for (int i = 0; i < times; i++){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
  }
}

// We want to be informed of when the status of the server changes
class ServerCallbacks : public NimBLEServerCallbacks {
  void onConnect(NimBLEServer* server, NimBLEConnInfo& connInfo) override {
    Serial.println("Client connected");
    deviceConnected = true;
  }

  void onDisconnect(NimBLEServer* server, NimBLEConnInfo& connInfo, int reason) override {
    Serial.print("Client disconnected, reason: ");
    Serial.println(reason);
    deviceConnected = false;

    // Start advertising after a disconnect, otherwise a reboot would be needed
    NimBLEDevice::getAdvertising()->start();
    isAdvertising = true;
  }
};

// We want to be informed when there is a write request to the characteristic
class CommandCallbacks : public NimBLECharacteristicCallbacks {
  void onWrite(
      NimBLECharacteristic* characteristic,
      NimBLEConnInfo& connInfo
  ) override {
    NimBLEAttValue value = characteristic->getValue();
    

    Serial.print("Text: ");
    Serial.println(value);

    switch (static_cast<char>(value[0])) {
      case 'A':
        Serial.println("Forward");
        //flash_led(1);
        forward(SPEED_FORWARDS);
        delay(150);
        stop();
        break;

      case 'B':
        Serial.println("Right");
        //flash_led(2);
        rotateRight(SPEED_FORWARDS);
        delay(150);
        stop();
        break;

      case 'C':
        Serial.println("Backward");
        //flash_led(3);
        backward(SPEED_FORWARDS);
        delay(150);
        stop();
        break;

      case 'D':
        Serial.println("Left");
        //flash_led(4);
        rotateLeft(SPEED_FORWARDS);
        delay(150);
        stop();
        break;

      case 'a':
        Serial.println("Forward");
        //flash_led(1);
        forward(SPEED_FORWARDS);
        delay(100);
        stop();
        break;

      case 'b':
        Serial.println("Right");
        //flash_led(2);
        rotateRight(SPEED_FORWARDS);
        delay(100);
        stop();
        break;

      case 'c':
        Serial.println("Backward");
        //flash_led(3);
        backward(SPEED_FORWARDS);
        delay(100);
        stop();
        break;

      case 'd':
        Serial.println("Left");
        //flash_led(4);
        rotateLeft(SPEED_FORWARDS);
        delay(100);
        stop();
        break;

      case 'E':
        Serial.println("Triangle");
        //flash_led(1);
        stop();
        break;

      case 'F':
        Serial.println("Circle");
        //flash_led(2);
        stop();
        break;

      case 'G':
        Serial.println("Cross");
        //flash_led(3);
        stop();
        break;

      case 'H':
        Serial.println("Square");
        //flash_led(4);
        stop();
        break;

      default:
        Serial.print("Unknown command: ");
        Serial.println(value);
        break;
    }
  }
};

void setup() {
  Serial.begin(115200);
  delay(1000);
  // Set up the LED pin
  pinMode(LED_BUILTIN, OUTPUT);
  // Set up the motor pins
  pinMode(pin[MOTOR_IN1], OUTPUT);
  pinMode(pin[MOTOR_IN2], OUTPUT);
  pinMode(pin[MOTOR_IN3], OUTPUT);
  pinMode(pin[MOTOR_IN4], OUTPUT);


  NimBLEDevice::init(BLUETOOTH_NAME);

  NimBLEServer* server = NimBLEDevice::createServer();
  server->setCallbacks(new ServerCallbacks());

  NimBLEService* service =
      server->createService(SERVICE_UUID);

  NimBLECharacteristic* characteristic =
      service->createCharacteristic(
          CHARACTERISTIC_UUID,
          NIMBLE_PROPERTY::WRITE_NR
      );

  characteristic->setCallbacks(new CommandCallbacks());

  service->start();

  NimBLEAdvertising* advertising =
      NimBLEDevice::getAdvertising();

  advertising->addServiceUUID(SERVICE_UUID);
  advertising->start();
  isAdvertising = true;

  Serial.println("BLE server started");
  Serial.println("Waiting for connection...");
}

void loop() {
    if (!deviceConnected && isAdvertising) {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= blinkInterval) {
      previousMillis = currentMillis;

      ledState = !ledState;
      digitalWrite(LED_BUILTIN, ledState ? HIGH : LOW);
    }
  }
  delay(10);
}
// Is the stop button pressed?
// Optional for minisumo
void checkStopSignal()
{
//  if (digitalRead(pin[SIG_KILL]) != HIGH)
//  {
//    Serial.println("Got kill signal, stopping..");
//    stop();
//    delay(500);
//  }
}

void forward(int speed)
{
  Serial.println(__func__);
  analogWrite(pin[MOTOR_IN1], speed);
  analogWrite(pin[MOTOR_IN2], 0);
  analogWrite(pin[MOTOR_IN3], 0);
  analogWrite(pin[MOTOR_IN4], speed);
  checkStopSignal();
}

void backward(int speed)
{
  Serial.println(__func__);
  analogWrite(pin[MOTOR_IN1], 0);
  analogWrite(pin[MOTOR_IN2], speed);
  analogWrite(pin[MOTOR_IN3], speed);
  analogWrite(pin[MOTOR_IN4], 0);
  checkStopSignal();
}

void rotateRight(int speed)
{
  Serial.println(__func__);
  analogWrite(pin[MOTOR_IN1], 0);
  analogWrite(pin[MOTOR_IN2], speed);
  analogWrite(pin[MOTOR_IN3], 0);
  analogWrite(pin[MOTOR_IN4], speed);
  checkStopSignal();
}

void rotateLeft(int speed)
{
  Serial.println(__func__);
  analogWrite(pin[MOTOR_IN1], speed);
  analogWrite(pin[MOTOR_IN2], 0);
  analogWrite(pin[MOTOR_IN3], speed);
  analogWrite(pin[MOTOR_IN4], 0);
  checkStopSignal();
}

void stop()
{
  Serial.println(__func__);
  analogWrite(pin[MOTOR_IN1], 0);
  analogWrite(pin[MOTOR_IN2], 0);
  analogWrite(pin[MOTOR_IN3], 0);
  analogWrite(pin[MOTOR_IN4], 0);
}