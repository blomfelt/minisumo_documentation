
// Make sure that the following libraries are installed:
// - "HCSR04" by Martin Sosic

// Define the speeds
#define SPEED_FORWARDS 150
#define SPEED_BACKWARDS 150 
#define SPEED_ROTATE 150

// NO NEED TO TOUCH ANYTHING BELOW THIS LINE
// ----------------------------------------------------------------------------

#include <HCSR04.h>

// Create easier to read names for the pins
enum PinMappings
{
  SIG_START,
  SIG_KILL,
  MOTOR_IN1,
  MOTOR_IN2,
  MOTOR_IN3,
  MOTOR_IN4,
  SENSOR_IR_FRONT,
  SENSOR_IR_BACK,
  SENSOR_SND_TRIG,
  SENSOR_SND_ECHO,
  _SIZE_LIMIT,
};

// Set up the pin numbers for each sensor, with an easier to read name than just the numbers
static uint8_t const pin[_SIZE_LIMIT] = {
    [SIG_START] = 14,
    [SIG_KILL] = 18,
    [MOTOR_IN1] = 0,
    [MOTOR_IN2] = 1,
    [MOTOR_IN3] = 2,
    [MOTOR_IN4] = 3,
    [SENSOR_IR_FRONT] = 4,
    [SENSOR_IR_BACK] = 5,
    [SENSOR_SND_TRIG] = 6,
    [SENSOR_SND_ECHO] = 7,
};

// Distance in cm 
UltraSonicDistanceSensor hcsr04(pin[SENSOR_SND_TRIG], pin[SENSOR_SND_ECHO]);

void setup()
{
  Serial.begin(115200);
  // A delay since otherwise the serial output may not show up
  delay(1000);
  // Set up the motor pins
  pinMode(pin[MOTOR_IN1], OUTPUT);
  pinMode(pin[MOTOR_IN2], OUTPUT);
  pinMode(pin[MOTOR_IN3], OUTPUT);
  pinMode(pin[MOTOR_IN4], OUTPUT);

  //waitStartSignal();
  
  Serial.println("Started measuring");
}

void loop()
{
  float distanceCm = hcsr04.measureDistanceCm();

  // Rotate left to find opponent
  rotateLeft(SPEED_ROTATE);

  // If opponent found
  while (distanceCm < 40 && distanceCm > 0)
  {
    // IR value = 0 if senses border
    int frontIR = digitalRead(pin[SENSOR_IR_FRONT]);
    Serial.print("Front IR: ");
    Serial.println(frontIR);
    // IR value = 0 if senses border 
    int backIR = digitalRead(pin[SENSOR_IR_BACK]);
    Serial.print("Back IR: ");
    Serial.println(backIR);
    
    if (checkBorder()) {
      // Border is present, drive away from it and then exit loop
      break;
    }
    // Drive towards opponent
    forward(SPEED_FORWARDS); 
    // Update the measurement, is the opponent gone?
    distanceCm = hcsr04.measureDistanceCm();
  }
  // Check so not fall off
  checkBorder();
 
  Serial.println(distanceCm);
  delay(150);
}

void waitStartSignal()
{
  Serial.println(__func__);
  while (digitalRead(pin[SIG_START]) != HIGH)
  {
    Serial.println("Waiting for start signal");
  }
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

// Check so not fall off
// Returns true if border is either in front or back of us.
// Returns false if border is not present
bool checkBorder()
{
  // IR value = 0 if senses border
  int frontIR = digitalRead(pin[SENSOR_IR_FRONT]);
  int backIR = digitalRead(pin[SENSOR_IR_BACK]);
  // Check if edge is in front of us 
  if (frontIR == 0)
  {
    backward(SPEED_BACKWARDS);
    delay(500);
    return true;
  }

  // Check if edge is behind us
  if (backIR == 0)
  {
    forward(SPEED_FORWARDS);
    delay(500);
    return true;
  }

  return false;
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

void rotateLeft(int speed)
{
  Serial.println(__func__);
  analogWrite(pin[MOTOR_IN1], 0);
  analogWrite(pin[MOTOR_IN2], speed);
  analogWrite(pin[MOTOR_IN3], 0);
  analogWrite(pin[MOTOR_IN4], speed);
  checkStopSignal();
}

void rotateRight(int speed)
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