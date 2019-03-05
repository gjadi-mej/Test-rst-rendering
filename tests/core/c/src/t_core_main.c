/*
 * C
 *
 * Copyright 2019 IS2T. All rights reserved.
 * For demonstration purpose only.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */
#include <stdio.h>
#include <stdarg.h>
#include "../../../../framework/c/embunit/embUnit/embUnit.h"
#include "t_core_print.h"
#include "t_core_time_base.h"
#include "t_core_ram.h"
#include "t_core_core_benchmark.h"



void T_CORE_main(void) {



	TestRunner_start();
	TestRunner_runTest(T_CORE_PRINT_tests());
	TestRunner_runTest(T_CORE_TIME_BASE_tests());
	TestRunner_runTest(T_CORE_RAM_tests());
	TestRunner_runTest(T_CORE_RAM_speed_tests());
	TestRunner_runTest(T_CORE_COREBENCH_tests());
	TestRunner_end();
	return;
}
