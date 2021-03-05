@echo off

REM Copyright 2021 MicroEJ Corp. All rights reserved.
REM Use of this source code is governed by a BSD-style license that can be found with this software.

REM 'run.bat' implementation stub.

REM 'run.bat' is responsible for flashing the executable file on the target device 
REM then resetting target device

IF NOT EXIST application.out (
	echo FAILED - missing 'application.out' file
	exit /B 1
)

echo PASSED