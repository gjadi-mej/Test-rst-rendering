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
#include "../../../../framework/c/utils/inc/u_print.h"
#include "x_version.h"
#include "t_core_print.h"


static void T_CORE_PRINT_setUp(void)
{
	UTIL_print_initialize();
}

static void T_CORE_PRINT_tearDown(void)
{

}

static void T_CORE_PRINT_displayMessage(void)
{
	UTIL_print_string("\n**************************************************************************\n");
	UTIL_print_string("**                      Platform Qualification Core                     **\n");
	UTIL_print_string("**                              version ");
	UTIL_print_string(X_VERSION);
	UTIL_print_string("                             **\n");
	UTIL_print_string("****************************************************************************\n");
	UTIL_print_string("*           Copyright 2013-2019 MicroEJ Corp. All rights reserved.         *\n");
	UTIL_print_string("* Modification and distribution is permitted under certain conditions.     *\n");
	UTIL_print_string("* MicroEJ Corp. PROPRIETARY/CONFIDENTIAL. Use is subject to license terms. *\n");
	UTIL_print_string("****************************************************************************\n");
	
	UTIL_print_string("\nPrint test:\n if this message is displayed, the test is passed!\n");
}

TestRef T_CORE_PRINT_tests(void)
{
    EMB_UNIT_TESTFIXTURES(fixtures) { 
			new_TestFixture("Print message", T_CORE_PRINT_displayMessage),
		};
		
		EMB_UNIT_TESTCALLER(printTest, "Print_tests", T_CORE_PRINT_setUp, T_CORE_PRINT_tearDown, fixtures);

    return (TestRef)&printTest;
}
