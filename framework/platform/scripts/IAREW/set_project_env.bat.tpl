@echo off

REM Copyright 2019-2021 MicroEJ Corp. All rights reserved.
REM Use of this source code is governed by a BSD-style license that can be found with this software.

REM 'set_project_env.bat' implementation for IAR Embedded Workbench.

REM 'set_project_env' is responsible for
REM - checking the availability of required environment variables 
REM - setting project local variables for 'build.bat' and 'run.bat' 

REM Required Environment Variable
REM IAREW_CHANGEIT_INSTALLATION_DIR

IF "%IAREW_CHANGEIT_INSTALLATION_DIR%" == "" (
    ECHO Please set the environment variable 'IAREW_CHANGEIT_INSTALLATION_DIR'
    exit /B -1
)

REM Set the project variables required by the build script for IAR Embedded Workbench
SET IAREW_INSTALLATION_DIR=%IAREW_CHANGEIT_INSTALLATION_DIR%
SET IAREW_PROJECT_DIR=CHANGEIT
SET IAREW_PROJECT_NAME=CHANGEIT
SET IAREW_PROJECT_CONFIGURATION=CHANGEIT

REM Device macro file relative to IAREW_INSTALLATION_DIR (e.g.: arm\config\debugger\NXP\LPC5460x.dmac)
SET IAREW_PROJECT_DEVICE_MACRO=CHANGEIT

REM Device flash loader file relative to IAREW_INSTALLATION_DIR (e.g.: arm\config\flashloader\NXP\FlashNXPLPC5460xM4F512K.board)
SET IAREW_PROJECT_FLASH_LOADER=CHANGEIT


SET IAREW_PROJECT_EXECUTABLE_FILE="%IAREW_PROJECT_DIR%\%IAREW_PROJECT_CONFIGURATION%\%IAREW_PROJECT_NAME%.out"

ECHO IAREW_INSTALLATION_DIR=%IAREW_INSTALLATION_DIR%
ECHO IAREW_PROJECT_DIR=%IAREW_PROJECT_DIR%
ECHO IAREW_PROJECT_NAME=%IAREW_PROJECT_NAME%
ECHO IAREW_PROJECT_CONFIGURATION=%IAREW_PROJECT_CONFIGURATION%
exit /B 0