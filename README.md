[![Releases](https://img.shields.io/github/downloads/VenomModding/Kobra/total.svg)](https://github.com/VenomModding/Kobra/releases)
[![License](https://img.shields.io/github/license/VenomModding/Kobra.svg)](https://github.com/VenomModding/Kobra/blob/master/LICENSE)
[![Discord](https://img.shields.io/badge/chat-Discord-blue.svg)](https://discord.com/invite/4nbDEytXXc)

Kobra is a fork of [Greyhound](https://github.com/Scobalula/Greyhound), an asset extractor for various titles running on the [IW Engine](https://en.wikipedia.org/wiki/IW_(game_engine)) (primarily Call of Duty games), and is based off the famous [Wraith Archon](https://github.com/dtzxporter/WraithXArchon/) that was originally developed by [DTZxPorter](https://github.com/dtzxporter/). Kobra's aim is to provide people access to assets from the games for various purposes including working mods such custom zombie maps or weapon mods, 3D Art, and thumbnails for content creation. Kobra adds XEffect and GDT support, due to it being cut from Greyhound because "barely any users used it".

For detailed information such as game support, settings, FAQs, etc. please refer to the original Greyhound's wiki: [Wiki](https://scobalula.github.io/Greyhound/) Work is being done to populate the wiki with information and tutorials so stay tuned!

We will no longer provide support in the Discord as it has been archived due to Venom leaving the CoD Modding scene. However a link will be provided. -> [Venom Modding Archives](https://discord.com/invite/4nbDEytXXc)

## Ricochet Info

Ricochet means we can no longer export from in-game, Parasyte is now required that works with Kobra to allow exporting from newer titles:

[https://wiki.codmods.com/docs/parasyte/index](https://wiki.codmods.com/docs/parasyte/index)

## Requirements

* Windows 10 x64 or above (Windows 7/8/8.1 should work, but are untested)
* Microsoft Visual Studio 2017 Runtime ([x86](https://aka.ms/vs/16/release/vc_redist.x86.exe) and [x64](https://aka.ms/vs/16/release/vc_redist.x64.exe))
* Official copies of the games (only the latest copies from official distributors are tested)

## Current plans
* Possible implementation of ripping Infinity Ward (IW1/IW2/IW3/IW4/IW5/IW6/IW7/IW8) and Sledgehammer-based (S1, S2, S4, H1, H2) FXs using the implementation of [ZoneTool](https://github.com/ZoneTool/zonetool)
* Build Mecha inside of Kobra, for easier sound ripping...
* Figure out the Parasyte source code to get COD: Online support working, for models + anim ripping (using [Momo5502](https://github.com/momo5502)'s IFS ripping tools to rip the Models + Anims)

The following tools/plugins are required/recommended for some assets/games:

* [SETools](https://github.com/dtzxporter/SETools) by DTZxPorter (.seanim & .semodel) (Autodesk Maya)
* [io_anim_seanim](https://github.com/SE2Dev/io_anim_seanim) by SE2Dev (.seanim) (Blender)
* [io_model_semodel](https://github.com/dtzxporter/io_model_semodel) by DTZxPorter (.semodel) (Blender)
* [FileTypeDDS](https://github.com/dtzxporter/FileTypeDDS) by DTZxPorter (support in Paint .NET for newer DXGI formats) (Paint .NET)
* [Intel TextureWorks](https://software.intel.com/en-us/articles/intel-texture-works-plugin) by Intel (DDS + Utils) (Photoshop)
* [DarkIris](https://aviacreations.com/modme/index.php?view=topic&tid=831) by DTZxPorter (Texture Utils) (Paint .NET)

## Links:
* Discord Server: [https://discord.com/invite/VenomModdingArchives](https://discord.com/invite/4nbDEytXXc)
* This Github Repo: [https://github.com/VenomModding/Kobra](https://github.com/VenomModding/Kobra)
* Change Log: [https://github.com/VenomModding/Kobra/blob/master/CHANGELOG.md](https://github.com/VenomModding/Kobra/blob/master/CHANGELOG.md)
* Latest Release: [https://github.com/VenomModding/Kobra/releases](https://github.com/VenomModding/Kobra/releases)

## License/Disclaimer

Kobra, like Greyhound, Wraith Archon and the WraithX Library, is licensed under the General Public License 3.0, you are free to use Kobra, both it and its source code, under the terms of the GPL. Kobra is distributed in the hope it will be useful to, but it comes WITHOUT ANY WARRANTY, without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE, see the [LICENSE](https://github.com/VenomModding/Kobra/blob/master/LICENSE) file for more information.

This repo is in no shape or form associated (apart from being a fork of course) with Scobalula, DTZxPorter or Activision and the developers. These tools are developed to allow users access to assets for use in other Call of Duty SDKs (such as the Black Ops III Mod Tools) and for use in 3D art such as YouTube thumbnails, etc. The assets extracted by these tools are property of their respective owners and what you do with the assets is your own responsbility.

Kobra is distributed with an automatic updater that will check for updates each time the application is launched by requesting the releases data via the Github API. If you do not wish for Kobra to check for updates you can simply delete the Kobra Updater executable.

## Credits/Contributors

* JustVenom - Re-adding FX and GDT support and old Kobra maintainer
* hindercanrun - New Kobra maintainer
* Scobalula - Developer/Maintainer/Research
* Blakintosh - MWR Material Support
* Eric Maynard - Help on BOCW from ModelGetter, ZM Hashes for BOCW Base
* DTZxPorter - Original Developer of the entire Wraith Project, Game Research
* ID-Daemon - Game Research

**If you use Kobra in any of your projects, it would be highly appreciated if you credit the people/parties listed in the Credits list.**
