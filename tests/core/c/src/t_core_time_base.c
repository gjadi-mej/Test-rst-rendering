/*
 * Copyright 2015-2019 IS2T. All rights reserved.
 * For demonstration purpose only.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

#include <embUnit/embUnit.h>
#include <embUnit/config.h>
#include "u_time_base.h"

#define T_CORE_TIME_BASE_MAX_WAITING	10000

static void T_CORE_TIME_BASE_setUp(void)
{
	UTIL_TIME_BASE_initialize();
}

static void T_CORE_TIME_BASE_tearDown(void)
{

}

static void T_CORE_TIME_BASE_check_time_evolution(void)
{
	uint64_t startTime = UTIL_TIME_BASE_getTime();
	for (int32_t i = 0; i < T_CORE_TIME_BASE_MAX_WAITING; i++)
	{
	};
	TEST_ASSERT_MESSAGE(startTime < UTIL_TIME_BASE_getTime(), "the time base is not implemented or does not have sufficient accuracy");
}

TestRef T_CORE_TIME_BASE_tests(void)
{
    EMB_UNIT_TESTFIXTURES(fixtures) { 
			new_TestFixture("Check time progression", T_CORE_TIME_BASE_check_time_evolution),
		};
		
		stdimpl_print("\nTime base check:\n");
		EMB_UNIT_TESTCALLER(timeBaseTest, "Time_base_tests", T_CORE_TIME_BASE_setUp, T_CORE_TIME_BASE_tearDown, fixtures);

    return (TestRef)&timeBaseTest;
}
