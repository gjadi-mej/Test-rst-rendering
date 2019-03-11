/*
 * Copyright 2019 MicroEJ Corp. All rights reserved.
 * For demonstration purpose only.
 * MicroEJ Corp. PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

/* Prevent recursive inclusion */

#ifndef __T_CORE_TIME_BASE_H
#define __T_CORE_TIME_BASE_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "../../../../framework/c/embunit/embUnit/embUnit.h"

/* Public function declarations */
/**
 *@brief This test checks the proper functioning of the time reference. First it calls the 'UTIL_TIME_BASE_getTime' method, next it runs some loops.
 * Finaly it calls a second time, the  'UTIL_TIME_BASE_getTime' method, and computes the time gap between the two calls. If the gap is equal to 0, the test fails.
 */
TestRef T_CORE_TIME_BASE_tests(void);

#ifdef __cplusplus
}
#endif

#endif
