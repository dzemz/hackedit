# hackedit

The hackable and modern IDE, built with QML and Material design

This repository contains the main parts of the project:
 - the common libraries (logging,...)
 - the editor component (can be built separately from the application to be reused in other QtQuick/QtWidgets applications)
 - the application
 
# Requirements

- Qt >= 5.7
- CMake >= 3.2
- A c++11 compliant compiler: 
    - GCC >= 4.8
    - Clang >= 3.5
    - MSVC 2015 Update 2
    
# Compilation

## GNU/Linux

- mkdir build && cd build
- cmake ..
- make

## OSX

- mkdir build && cd build
- brew install qt5 cmake
- cmake -DCMAKE_PREFIX_PATH=/usr/local/opt/qt5 ..
- make

## Windows

- mkdir build && cd build
- cmake -G "Visual Studio 14 2015 Win64" -DCMAKE_BUILD_TYPE=Release .. 
- cmake --build . --config Release
