<!--
	Markdown
	
	Copyright 2017 IS2T. All rights reserved.
	Modification and distribution is permitted under certain conditions.
	
	IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
-->

# Overview
This project provides a guide to validate your MJVM portage.

# Requirements
* MicroEJ SDK 4.0 or later
* Java JDK 1.7 or later 

# Usage
1. Add the C file **c/MJVMPortValidation.c** in your BSP and build your platform.
2. Create a new launcher with com.is2t.microjvm.test.MJVMPortValidation as main class.
3. Set at least 10 threads in Configuration->Target->Memory->Number of threads. 
4. Run the application and take a look at the result.

# Run
Set up a terminal on the board serial port and press the reset input. 
'''
....
@ASSERTIONS_OK:18#
@ASSERTIONS_NOK:0#
com.is2t.microjvm.test.MJVMPortValidation PASSED
'''

# Result
At the end, the result of testsuite is stored in **target~/test/html/test**. 

# Dependencies
N/A

# Source
N/A

# Restrictions
N/A