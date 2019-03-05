/*
 * Copyright 2019 IS2T. All rights reserved.
 * For demonstration purpose only.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

/* Prevent recursive inclusion */

#ifndef __UTIL_PRINT_H
#define __UTIL_PRINT_H

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>

/** Public constant declaration */

/** public structure declaration */

/** public function declaration */
// weak function to implement
void UTIL_print_initialize(void);
void UTIL_print_string(const char* string);
void UTIL_print_integer(int integer);
void UTIL_print_float(double value);
void UTIL_print_longlong(long long value);

#ifdef __cplusplus
}
#endif

#endif
