/*
 * Copyright 2015-2019 IS2T. All rights reserved.
 * For demonstration purpose only.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

#include <embUnit/embUnit.h>
#include <embUnit/config.h>
#include "time_base_test.h"

#define T_CORE_TIME_BASE_MAX_WAITING	10000

static void T_CORE_TIME_BASE_setUp(void)
{
	TIME_BASE_TEST_initialize();
}

static void T_CORE_TIME_BASE_tearDown(void)
{

}

static void T_CORE_TIME_BASE_check_time_evolution(void)
{
	uint64_t startTime = TIME_BASE_TEST_getTime();
	stdimpl_print("waiting ...");
	for (int32_t i = 0; i < T_CORE_TIME_BASE_MAX_WAITING; i++)
	{
	};
	TEST_ASSERT_MESSAGE(startTime < TIME_BASE_TEST_getTime(), " ");
}

TestRef T_CORE_TIME_BASE_tests(void)
{
    EMB_UNIT_TESTFIXTURES(fixtures) { 
			new_TestFixture("Check time progression", T_CORE_TIME_BASE_check_time_evolution),
		};
		EMB_UNIT_TESTCALLER(timeBaseTest, "Time_base_tests", T_CORE_TIME_BASE_setUp, T_CORE_TIME_BASE_tearDown, fixtures);

    return (TestRef)&timeBaseTest;
}
