@echo off

REM Copyright 2020-2021 MicroEJ Corp. All rights reserved.
REM Use of this source code is governed by a BSD-style license that can be found with this software.

REM 'set_project_env.bat' implementation for Keil µVision5.

REM 'set_project_env' is responsible for
REM - checking the availability of required environment variables 
REM - setting project local variables for 'build.bat' and 'run.bat' 

REM Required Environment Variable

REM Keil installation directory (e.g.: C:\Keil_v5)
SET KEIL_INSTALLATION_DIR=
IF "%KEIL_INSTALLATION_DIR%" == "" (
    ECHO Please set the environment variable 'KEIL_INSTALLATION_DIR'
    exit /B -1
)

REM Keil Project directory that contains the project files .uvprojx (e.g.: %~dp0\..\MDK-ARM)
SET KEIL_PROJECT_DIR=
IF "%KEIL_PROJECT_DIR%" == "" (
    ECHO Please set the environment variable 'KEIL_PROJECT_DIR'
    exit /B -1
)

REM Keil project file name without the extension .uvprojx (e.g.: Project)
SET KEIL_PROJECT_NAME=
IF "%KEIL_PROJECT_NAME%" == "" (
    ECHO Please set the environment variable 'KEIL_PROJECT_NAME'
    exit /B -1
)

REM Keil target name (e.g.: standalone)
SET KEIL_TARGETNAME=
IF "%KEIL_TARGETNAME%" == "" (
    ECHO Please set the environment variable 'KEIL_TARGETNAME'
    exit /B -1
)

ECHO KEIL_INSTALLATION_DIR=%KEIL_INSTALLATION_DIR%
ECHO KEIL_PROJECT_DIR=%KEIL_PROJECT_DIR%
ECHO KEIL_PROJECT_NAME=%KEIL_PROJECT_NAME%
ECHO KEIL_TARGETNAME=%KEIL_TARGETNAME%
exit /B 0
