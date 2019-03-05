/*
 * Copyright 2019 IS2T. All rights reserved.
 * For demonstration purpose only.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

/* Prevent recursive inclusion */

#ifndef __T_CORE_RAM_H
#define __T_CORE_RAM_H
#include "../../../../framework/c/embunit/embUnit/embUnit.h"

#ifdef __cplusplus
 extern "C" {
#endif

/* Public function declarations */
TestRef  T_CORE_RAM_tests(void);
TestRef  T_CORE_RAM_speed_tests(void);

#ifdef __cplusplus
}
#endif

#endif
