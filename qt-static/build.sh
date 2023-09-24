#!/usr/bin/env bash
cd "$(dirname $(realpath $0))"
git submodule update --init qtbase
cd $1
#if [[ $@ == *'--clean'* ]]
#then
#    git clean -xdf
#fi
./configure -static -release -qpa windows -style-windowsvista # -qt-zlib -qt-libjpeg -qt-libpng -qt-freetype -qt-pcre -qt-harfbuzz
cmake --build . --parallel
cmake --build . --target install
