/*
 * Copyright 2019 MicroEJ Corp. All rights reserved.
 * For demonstration purpose only.
 * MicroEJ Corp. PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

/* Prevent recursive inclusion */

#ifndef __UTIL_TIME_BASE_H
#define __UTIL_TIME_BASE_H

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>

/* Public constant declaration */

/* public structure declaration */

/* public function declaration */
// weak function to implement

/**
 * @fn void UTIL_TIME_BASE_initialize(void)
 * @brief This function is called by the SetUp functions of tests wich require some time references.
 *
 * @fn uint64_t UTIL_TIME_BASE_getTime(void)
 * @brief This function provides a time reference for tests
 * @return a current time in microsecond (µs)
 */
void UTIL_TIME_BASE_initialize(void);
uint64_t UTIL_TIME_BASE_getTime(void);

#ifdef __cplusplus
}
#endif

#endif
