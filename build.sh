#!/bin/sh

set -x # print command log

SOURCE_DIR=`pwd`
BUILD_DIR=${BUILD_DIR:-../../build_heper}
BUILD_TYPE=${BUILD_DIR:-release}
INSTALL_DIR=${INSTALL_DIR:-../${BUILD_TYPE}-install-c99}
CXX=${CXX:-gcc}

mkdir -p $BUILD_DIR/$BUILD_TYPE-c99 \
    && cd $BUILD_DIR/$BUILD_TYPE-c99 \
    && cmake \
            -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
            -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR \
            -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
            $SOURCE_DIR \
    && make $*