# hackedit

[![Build Status](https://travis-ci.org/HackEdit/hackedit.svg?branch=master)](https://travis-ci.org/HackEdit/hackedit)
[![Build status](https://ci.appveyor.com/api/projects/status/x5xubrws4hhoixi2/branch/master?svg=true)](https://ci.appveyor.com/project/ColinDuquesnoy/hackedit/branch/master)

The hackable and modern IDE, built with QML and Material design

This repository contains the main parts of the project:
 - the common libraries (logging,...)
 - the editor component (can be built separately from the application to be reused in other QtQuick/QtWidgets applications)
 - the application
 
# Requirements

- **Qt** >= 5.7
- **CMake** >= 3.2
- A c++11 compliant compiler: 
    - GCC >= 4.8.4
    - Clang >= 3.5
    - MSVC 2015 Update 2
    
# Compilation

## GNU/Linux

```bash
mkdir build && cd build
cmake ..
make
```

## OSX

```bash
mkdir build && cd build
brew install qt5 cmake
cmake -DCMAKE_PREFIX_PATH=/usr/local/opt/qt5 ..
make
```

## Windows

```bash
mkdir build && cd build
cmake -G "Visual Studio 14 2015 Win64" -DCMAKE_BUILD_TYPE=Release .. 
cmake --build . --config Release
```

# Build options

You can specify the following options when calling cmake:

- ``-DCMAKE_BUILD_TYPE=``: *Debug* or *Release*
- ``-DBUILD_EXAMPLES``: *ON* or *OFF*
- ``-DBUILD_TESTS=``: *ON* or *OFF*
- ``-DBUILD_APPLICATION=``: *ON* or *OFF* (set this to OFF to build only the editor control and the common libs)
