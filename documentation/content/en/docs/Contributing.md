---
weight: 998
title: "Contributing"
description: ""
icon: "heart_plus"
date: "2026-09-01T21:45:18+02:00"
lastmod: "2026-09-01T21:45:18+02:00"
draft: false
toc: true
---

This site is built using [Hugo](https://gohugo.io/) and uses the [Lotusdocs theme](https://github.com/colinwilson/lotusdocs).

The requirements to build the site is:
- git
- Go ≥ v1.21
- Hugo ≥ v0.140.0 (Extended Version)

To edit any content, edit the corresponding markdown file in the `contents/docs/` directory and run the `hugo` command to regenerate the site. Then push any changes to the [GitHub repo](https://github.com/ChalmersRobotics/CRF-SumoBot). The contents of the `public` directory is then served by GitHub as a static page located on [chalmersrobotics.github.io/CRF-SumoBot](https://chalmersrobotics.github.io/CRF-SumoBot)

To make a new page run the command `hugo new docs/example-page.md` to create the page "Example-page". Then change the `draft: true` to `false` for it to be visible. Then push the changes as above to update the site. 

To see your changes before they are pushed you may use the `hugo server` command, where the `-D` and `--disableFastRender` flags may be needed to see your post change. Please note that you need to change the `draft: true` to `false` for it to be visible.
