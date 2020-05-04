#!/bin/bash

# Copyright 2019-2020 MicroEJ Corp. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be found with this software.

# This script downloads and installs the MicroEJ Platform configuration additions to an existing MicroEJ Platform configuration project.
# Requirements: SVN client
#   sudo apt-get install subversion
#
# Variable 'PLATFORM_CONFIG_DIR' is used to specifiy the MicroEJ Platform configuration directory where to install 
# the file additions. By default when not set, this script must be executed in the MicroEJ Platform configuration directory to be updated.
# Variable 'ADDITIONS_DIR' is used to specifiy the MicroEJ Platform configuration additions local directory
# the file additions. By default when not set, this script must be executed in the MicroEJ Platform configuration directory to be updated.

if [ -z $PLATFORM_CONFIG_DIR ]; then
    PLATFORM_CONFIG_DIR=$PWD
    echo [INFO] MicroEJ Platform configuration directory set to current directory.
fi

pushd $PLATFORM_CONFIG_DIR > /dev/null

exit_ko() {
    popd > /dev/null
    exit 1
}

exit_ok() {
    popd > /dev/null
    exit 0
}

PLATFORM_FILE=`ls *.platform 2>/dev/null`

if [ $? -ne 0 ]; then
    echo [ERROR] The current directory is not a valid MicroEJ Platform configuration project.
    exit_ko
else
    echo [INFO] MicroEJ Platform configuration file detected: $PLATFORM_FILE.
fi

if [ "$ADDITIONS_DIR" = "" ]; then
    GITHUB_URL=https://github.com/MicroEJ/PlatformQualificationTools/trunk/framework/platform-configuration-additions
    echo [INFO] Downloading MicroEJ Platform configuration additions from $GITHUB_URL...
    TMP_DIR=/tmp/pdt_install_$(date +%s)
    svn checkout $GITHUB_URL $TMP_DIR
    if [ $? -ne 0 ]; then
        echo [ERROR] Cannot connect Github URL.
        exit_ko
    fi
    ADDITIONS_DIR=$TMP_DIR/platform-configuration-additions
else
    echo [INFO] Using MicroEJ Platform configuration additions local directory $ADDITIONS_DIR...
fi

THIS_SCRIPT_NAME=`basename "$0"`

cp -r ${ADDITIONS_DIR}/* .
rm README.rst
rm $THIS_SCRIPT_NAME

echo [INFO] MicroEJ Platform configuration additions successfully installed to $PWD.

exit_ok