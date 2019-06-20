/*
 * C
 *
 * Copyright 2019 MicroEJ Corp. All rights reserved.
 * For demonstration purpose only.
 * MicroEJ Corp. PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */
#include <stdio.h>
#include <stdarg.h>
#include "../../../../framework/c/embunit/embUnit/embUnit.h"
#include "t_ui_api.h"
#include "t_ui_framerate.h"

void T_UI_main(void)
{
	TestRunner_start();
	TestRunner_runTest(T_UI_API_tests());
	TestRunner_runTest(T_UI_FRAMERATE_tests());
	TestRunner_end();
	return;
}
