@echo off

REM Copyright 2019-2021 MicroEJ Corp. All rights reserved.
REM Use of this source code is governed by a BSD-style license that can be found with this software.

REM 'run.bat' implementation for IAR Embedded Workbench.

REM 'run.bat' is responsible for flashing the executable file on the target device 
REM then resetting target device

REM This file has concatenated and made portable options from 'settings/lpcxpresso.Debug.driver.xcl' and 'lpcxpresso.Debug.general.xcl'
REM Any changes in the IAR settings must be reported to the command line above.

CALL "%~dp0\set_project_env.bat"
IF %ERRORLEVEL% NEQ 0 (
	exit /B %ERRORLEVEL%
)

IF "%~1"=="" (
	SET APPLICATION_FILE=%cd%\application.out
) ELSE (
	SET APPLICATION_FILE=%~1
)

IF NOT EXIST "%APPLICATION_FILE%" (
	echo FAILED - file '%APPLICATION_FILE%' does not exist
	exit /B 1
)


@echo on

copy /Y "%APPLICATION_FILE%" %IAREW_PROJECT_EXECUTABLE_FILE%
"%IAREW_INSTALLATION_DIR%\common\bin\cspybat" --download_only "%IAREW_INSTALLATION_DIR%\arm\bin\armproc.dll" "%IAREW_INSTALLATION_DIR%\arm\bin\armjlink2.dll" "%IAREW_PROJECT_DIR%\%IAREW_PROJECT_CONFIGURATION%\%IAREW_PROJECT_NAME%.out"  --plugin="%IAREW_INSTALLATION_DIR%\arm\bin\armbat.dll" --device_macro="%IAREW_INSTALLATION_DIR%\%IAREW_PROJECT_DEVICE_MACRO%" --flash_loader="%IAREW_INSTALLATION_DIR%\%IAREW_PROJECT_FLASH_LOADER%" --backend "--endian=little" "--cpu=Cortex-M4" "--fpu=VFPv4_SP" "-p"  "%IAREW_PROJECT_DIR%/LPC54608J512ET180.ddf" "--semihosting" "--device=LPC54628J512" "--drv_communication=USB0" "--drv_interface_speed=auto" "--jlink_initial_speed=32" "--jlink_reset_strategy=0,0" "--drv_interface=SWD" "--drv_catch_exceptions=0x000" "--drv_swo_clock_setup=180000000,0,2000000" 