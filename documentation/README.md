# Documentation for the new minisumo version

This site's documention, built with [Hugo](https://gohugo.io/) and hosted on [chalmersrobotics.github.io/CRF-SumoBot](https://chalmersrobotics.github.io/CRF-SumoBot)
The site uses the [Lotusdocs theme](https://github.com/colinwilson/lotusdocs).

The requirements to build the site is:
- git
- Go ≥ v1.21
- Hugo ≥ v0.140.0 (Extended Version)

To edit any content, edit the corresponding markdown file in the `contents/docs/` directory. 
Then push any changes of the markdown files to the [GitHub repo](https://github.com/ChalmersRobotics/CRF-SumoBot). 
The contents of the `public` directory is then served by GitHub as a static page located on [chalmersrobotics.github.io/CRF-SumoBot](https://chalmersrobotics.github.io/CRF-SumoBot)

To make a new page run the command `hugo new docs/example-page.md` to create the page "Example-page". 
Then change the `draft: true` to `false` for it to be visible. Then push the changes as above to update the site. 

To see your changes before they are pushed you may use the `hugo server` command, where the `-D` and `--disableFastRender` flags may be needed to see your post change. 
Please note that you need to change the `draft: true` to `false` for it to be visible.
