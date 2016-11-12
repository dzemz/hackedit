#!/usr/bin/env bash

export GTEST_COLOR=1

if [[ $TRAVIS_OS_NAME == 'osx' ]]; then
    brew install qt5
    export CMAKE_PREFIX_PATH=/usr/local/opt/qt5
else
    sudo add-apt-repository ppa:beineri/opt-qt57-trusty -y
    sudo add-apt-repository ppa:george-edison55/cmake-3.x -y
    sudo apt-get update -q
    sudo apt-get install cmake qt57base qt57declarative qt57quickcontrols2 lcov -y
    gem install coveralls-lcov
    source /opt/qt57/bin/qt57-env.sh
fi
