[![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)]()
[![forthebadge](https://forthebadge.com/images/badges/made-with-java.svg)]() \
[![Documentation badge](https://img.shields.io/badge/documentation-incomplete-red.svg)](https://shields.io/) \
[![Master badge](https://img.shields.io/badge/masterbranch-behind-red.svg)](https://shields.io/)
# godot-nuitrack
Godot C++ and Java module for interacting with the Nuitrack body tracking API. 

**Currently only supporting Android Builds from Linux!** \
**Latest working branch: gd-cpp-java-module**
## Getting Started

### Prerequisites
  - Latest Nuitrack.apk \
    `Download latest version from` [Nuitrack installation instructions](http://download.3divi.com/Nuitrack/doc/Installation_page.html)
  - Latest Nuitrack SDK\
    `Download latest version from` [Nuitrack SDK](https://nuitrack.com/#api) \
     **do not use their github repo of the Nuitrack SDk, it is outdated and some files are corrupted I believe**
  - Godot \
    ` >= v3.2` [Godot download](https://godotengine.org/download)


### Android
For Android devices running >= 
- Installing Nuitrack.apk on the Android device. \
  ` 1. Install the Nuitrack.apk application onto your Android device.` \
  ` 2. Open the Nuitrack application and run the compatability test.` \
  ` 3. Enter your license and activate it.` \
      **Check your license type as perpetual license can only be activated for one device** \
- Setting up Godot Editor. \
  ` Follow these instructions to setup a custom build environment for android:` [Godot custom builds for Android](https://docs.godotengine.org/en/3.2/getting_started/workflow/export/android_custom_build.html#doc-android-custom-build) \
  ` In the "Using from GDScript" section replace 'org/godotengine/godot/MySingleton' with 'org/godotengine/godot/gdNuitrack'` \
  ` You do not need to install Android Studio, use the Android SDK Command line tools instructions `
- Setting up File Structure. \
  ```
  Your file structure should be as follows 
  
  Godot-Project
  |   Main.gd
  |   Main.tscn
  |   project.godot
  └───addons
  |      gNuitrack.gdns
  |      libgNuitrack.gdnlib
  |      libgdnuitrack.so
  |      libmiddleware.so
  |      libnuitrack.so
  └───android
         └───build (do not edit, automatically created from previous step)
         └───gdNuitrack (Android plugin files)
  ```
  
  ... **README write up in progress**
### Linux
### Windows
