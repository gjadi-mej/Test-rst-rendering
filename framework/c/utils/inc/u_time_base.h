/*
 * Copyright 2019 IS2T. All rights reserved.
 * For demonstration purpose only.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
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
void UTIL_TIME_BASE_initialize(void);
uint64_t UTIL_TIME_BASE_getTime(void);

#ifdef __cplusplus
}
#endif

#endif
