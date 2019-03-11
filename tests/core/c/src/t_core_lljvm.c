/*
 * Copyright 2014-2019 MicroEJ Corp. All rights reserved.
 * For demonstration purpose only.
 * MicroEJ Corp. PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

#include <stdint.h>
#include <stdio.h>
#include <embUnit/embUnit.h>
#define LLMJVM_IMPL_getSingleton LLMJVM_IMPL_getSingleton_undef
#define LLMJVM_getSingleton_instance LLMJVM_getSingleton_instance_undef
#include "LLMJVM_impl.h"

void checkTime(long expectedTime, long effectiveTime)
{
    char failText[128];

    sprintf((char *)failText, "Effective time %lu does not match expected time %lu", effectiveTime, expectedTime);

    /* Compares the effective time against the expected time plus a certain threshold */
    TEST_ASSERT_MESSAGE(effectiveTime >= (expectedTime - 1), failText);
    TEST_ASSERT_MESSAGE(effectiveTime <= (expectedTime + 1), failText);
}

void (*scheduleHook)(void) = NULL;

int32_t LLMJVM_schedule(void)
{
    /* Call the user defined schedule hook if available */
    if (scheduleHook != NULL)
    {
        scheduleHook();
    }

    /* Wakeup the JVM */
    LLMJVM_IMPL_wakeupVM();

    return 0;
}

static void setUp(void)
{

}

static void tearDown(void)
{

}

static void core_test_init_f(void)
{
    /* Initialize the JVM, then check that it was started */
    TEST_ASSERT_EQUAL_INT(LLMJVM_IMPL_initialize(), LLMJVM_OK);
    TEST_ASSERT_EQUAL_INT(LLMJVM_IMPL_vmTaskStarted(), LLMJVM_OK);
}

static void core_test_init_masquerade_f(void)
{
    /* Check that the JVM was not started, then initialize it */
    TEST_ASSERT_EQUAL_INT(LLMJVM_IMPL_vmTaskStarted(), LLMJVM_ERROR);
    TEST_ASSERT_EQUAL_INT(LLMJVM_IMPL_initialize(), LLMJVM_OK);
}

static void core_test_init_mutiple_call_f(void)
{
    /* Check double calls of the JVM initialization functions */
    TEST_ASSERT_EQUAL_INT(LLMJVM_IMPL_initialize(), LLMJVM_OK);
    TEST_ASSERT_EQUAL_INT(LLMJVM_IMPL_initialize(), LLMJVM_ERROR);
    TEST_ASSERT_EQUAL_INT(LLMJVM_IMPL_vmTaskStarted(), LLMJVM_OK);
    TEST_ASSERT_EQUAL_INT(LLMJVM_IMPL_vmTaskStarted(), LLMJVM_ERROR);
}

static void core_test_deinit_f(void)
{
    /* Shutdown the JVM */
    TEST_ASSERT_EQUAL_INT(LLMJVM_IMPL_shutdown(), LLMJVM_OK);
}

static void core_test_deinit_mutiple_call_f(void)
{
    /* Check double calls of the JVM shutdown functions */
    TEST_ASSERT_EQUAL_INT(LLMJVM_IMPL_shutdown(), LLMJVM_OK);
    TEST_ASSERT_EQUAL_INT(LLMJVM_IMPL_shutdown(), LLMJVM_ERROR);
}

static void core_test_check_time_f(void)
{
    #define TEST_DURATION 5000LL

    int64_t t0System;
    int64_t t0App;
    int64_t tEndNano;
    int64_t tEndSystem;
    int64_t tEndApp;
    int64_t expectedTEndSystem;
    int64_t expectedTEndApp;

    /* Get the current time using JVM API */
    t0System = LLMJVM_IMPL_getCurrentTime(1);
    t0App = LLMJVM_IMPL_getCurrentTime(0);
    tEndNano = LLMJVM_IMPL_getTimeNanos() + (TEST_DURATION * 1000000LL);

    /* Wait TEST_DURATION ms */
    while(LLMJVM_IMPL_getTimeNanos() < tEndNano);

    /* Get the current time using JVM API */
    tEndSystem = LLMJVM_IMPL_getCurrentTime(1);
    tEndApp = LLMJVM_IMPL_getCurrentTime(0);

    /* Compute the expected time */
    expectedTEndSystem = t0System + TEST_DURATION;
    expectedTEndApp = t0App + TEST_DURATION;

    /* Check expected vs effecting time, validating the correct functionality of the JVM API */
    checkTime(expectedTEndSystem, tEndSystem);
    checkTime(expectedTEndApp, tEndApp);
}

static void core_test_check_time_delta_f(void)
{
    #define DELTA 0LL
    #define COMPENSATION_TIME 0LL

    int64_t tSystem1;
    int64_t tApp1;
    int64_t tNano1;
    int64_t tApp2;
    int64_t tSystem2;
    int64_t tNano2;
    int64_t expectedTApp2;
    int64_t expectedTSystem2;
    int64_t expectedTNano2;

    /* Get the current time using JVM API */
    tApp1 = LLMJVM_IMPL_getCurrentTime(0);
    tSystem1 = LLMJVM_IMPL_getCurrentTime(1);
    tNano1 = LLMJVM_IMPL_getTimeNanos();

    /* Sets the application time to a custom value */
    LLMJVM_IMPL_setApplicationTime(tApp1 + DELTA);

    /* Get the current time using JVM API */
    tNano2 = LLMJVM_IMPL_getTimeNanos();
    tApp2 = LLMJVM_IMPL_getCurrentTime(0);
    tSystem2 = LLMJVM_IMPL_getCurrentTime(1);

    /* Compute the expected time */
    expectedTApp2 = tApp1 + DELTA;
    expectedTSystem2 = tSystem1;
    expectedTNano2 = tNano1;

    /* Check expected vs effecting time, validating the correct functionality of the JVM API */
    checkTime(expectedTApp2, tApp2);
    checkTime(expectedTSystem2, tSystem2);
    checkTime(expectedTNano2, tNano2 - COMPENSATION_TIME);
}

static void core_test_schedule_with_idle_f(void)
{
    #define DELAY 3000LL

    int64_t tEnd;
    int64_t expectedTEnd;
    int64_t t0;

    /* Get the current time using JVM API */
    t0 = LLMJVM_IMPL_getCurrentTime(1);

    /* Schedule a request to the JVM with a certain delay, them put the JVM in idle */
    TEST_ASSERT_EQUAL_INT(LLMJVM_IMPL_scheduleRequest(LLMJVM_IMPL_getCurrentTime(1) + DELAY), LLMJVM_OK);
    TEST_ASSERT_EQUAL_INT(LLMJVM_IMPL_idleVM(), LLMJVM_OK);

    /* Get the current time using JVM API */
    tEnd = LLMJVM_IMPL_getCurrentTime(1);

    /* Compute the expected time */
    expectedTEnd = t0 + DELAY;

    /* Check expected vs effecting time, validating the correct functionality of the JVM API */
    checkTime(expectedTEnd, tEnd);
}

volatile int done = 0;

void scheduleDone()
{
    done = 1;
}

static void core_test_schedule_with_polling_f(void)
{
    #define DELAY 3000LL

    int64_t t0;
    int64_t tEnd;
    int64_t expectedTEnd;

    scheduleHook = scheduleDone;

    /* Get the current time using JVM API */
    t0 = LLMJVM_IMPL_getCurrentTime(1);

    /* Schedule a request to the JVM with a certain delay, then wait in a polling loop for the execution to be resumed, putting the JVM in idle when it happens */
    TEST_ASSERT_EQUAL_INT(LLMJVM_IMPL_scheduleRequest(t0 + DELAY), LLMJVM_OK);
    while (!done);
    TEST_ASSERT_EQUAL_INT(LLMJVM_IMPL_idleVM(), LLMJVM_OK);

    /* Get the current time using JVM API */
    tEnd = LLMJVM_IMPL_getCurrentTime(1);

    /* Compute the expected time */
    expectedTEnd = t0 + DELAY;

    /* Check expected vs effecting time, validating the correct functionality of the JVM API */
    checkTime(expectedTEnd, tEnd);
}

static void core_test_reschedule_f(void)
{
    #define DELAY1 3000LL
    #define DELAY2 1000LL
    #define DELAY3 5000LL

    int64_t t0;
    int64_t tEnd;
    int64_t expectedTEnd;

    /* Get the current time using JVM API */
    t0 = LLMJVM_IMPL_getCurrentTime(1);

    /* Re-schedule a request several times, putting the JVM in idle after the last one */
    TEST_ASSERT_EQUAL_INT(LLMJVM_IMPL_scheduleRequest(t0 + DELAY1), LLMJVM_OK);
    TEST_ASSERT_EQUAL_INT(LLMJVM_IMPL_scheduleRequest(t0 + DELAY2), LLMJVM_OK);
    TEST_ASSERT_EQUAL_INT(LLMJVM_IMPL_scheduleRequest(t0 + DELAY3), LLMJVM_OK);
    TEST_ASSERT_EQUAL_INT(LLMJVM_IMPL_idleVM(), LLMJVM_OK);

    /* Get the current time using JVM API */
    tEnd = LLMJVM_IMPL_getCurrentTime(1);

    /* Compute the expected time */
    expectedTEnd = t0 + DELAY2;

    /* Check expected vs effecting time, validating the correct functionality of the JVM API */
    checkTime(expectedTEnd, tEnd);
}

static void core_test_idle_after_wakeup_f(void)
{
    int64_t t0;
    int64_t tEnd;
    int64_t expectedTEnd;

    /* Wakeup the JVM */
    TEST_ASSERT_EQUAL_INT(LLMJVM_IMPL_wakeupVM(), LLMJVM_OK);

    /* Get the current time using JVM API */
    t0 = LLMJVM_IMPL_getCurrentTime(1);

    /* Put the JVM in idle */
    TEST_ASSERT_EQUAL_INT(LLMJVM_IMPL_idleVM(), LLMJVM_OK);

    /* Get the current time using JVM API */
    tEnd = LLMJVM_IMPL_getCurrentTime(1);

    /* Compute the expected time */
    expectedTEnd = t0;

    /* Check expected vs effecting time, validating the correct functionality of the JVM API */
    checkTime(expectedTEnd, tEnd);
}

static void core_test_multiple_wakeup_f(void)
{
    #define DELAY 3000LL

    int64_t t0;
    int64_t tEnd;
    int64_t expectedTEnd;
    int i;

    /* Switch the JVM state between wakeup / idle several times */
    for (i = 0; i <= 2000; i++)
    {
        TEST_ASSERT_EQUAL_INT(LLMJVM_IMPL_wakeupVM(), LLMJVM_OK);
        TEST_ASSERT_EQUAL_INT(LLMJVM_IMPL_ackWakeup(), LLMJVM_OK);
        TEST_ASSERT_EQUAL_INT(LLMJVM_IMPL_idleVM(), LLMJVM_OK);
    }

    /* Get the current time using JVM API */
    t0 = LLMJVM_IMPL_getCurrentTime(1);

    /* Schedule a request to the JVM, then put it in idle */
    TEST_ASSERT_EQUAL_INT(LLMJVM_IMPL_scheduleRequest(t0 + DELAY), LLMJVM_OK);
    TEST_ASSERT_EQUAL_INT(LLMJVM_IMPL_idleVM(), LLMJVM_OK);

    /* Get the current time using JVM API */
    tEnd = LLMJVM_IMPL_getCurrentTime(1);

    /* Compute the expected time */
    expectedTEnd = t0 + DELAY;

    /* Check expected vs effecting time, validating the correct functionality of the JVM API */
    checkTime(expectedTEnd, tEnd);
}

TestRef mjvm_tests(void)
{
    EMB_UNIT_TESTFIXTURES(fixtures) {
        new_TestFixture("core_test_init_f", core_test_init_f),
        new_TestFixture("core_test_init_masquerade_f", core_test_init_masquerade_f),
        new_TestFixture("core_test_init_mutiple_call_f", core_test_init_mutiple_call_f),
        new_TestFixture("core_test_deinit_f", core_test_deinit_f),
        new_TestFixture("core_test_deinit_mutiple_call_f", core_test_deinit_mutiple_call_f),
        new_TestFixture("core_test_check_time_f", core_test_check_time_f),
        new_TestFixture("core_test_check_time_delta_f", core_test_check_time_delta_f),
        new_TestFixture("core_test_schedule_with_idle_f", core_test_schedule_with_idle_f),
        new_TestFixture("core_test_schedule_with_polling_f", core_test_schedule_with_polling_f),
        new_TestFixture("core_test_reschedule_f", core_test_reschedule_f),
        new_TestFixture("core_test_idle_after_wakeup_f", core_test_idle_after_wakeup_f),
        new_TestFixture("core_test_multiple_wakeup_f", core_test_multiple_wakeup_f),
    };

    EMB_UNIT_TESTCALLER(mjvmTest,"mjvmTest",setUp,tearDown,fixtures);

    return (TestRef)&mjvmTest;
}
