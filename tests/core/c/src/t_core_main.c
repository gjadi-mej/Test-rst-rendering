/*
 * C
 *
 * Copyright 2019 IS2T. All rights reserved.
 * For demonstration purpose only.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */
#include <stdio.h>
#include <stdarg.h>
#include <embUnit/embUnit.h>
#include "t_core_ram.h"



void T_CORE_main(void) {

	static TestCaller test;

	TestRunner_start();
	TestRunner_runTest(UT_ram_tests());
	TestRunner_runTest(UT_ram_speed_tests());
	TestRunner_end();
	return;
}
