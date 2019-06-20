/*
 * Copyright 2019 MicroEJ Corp. All rights reserved.
 * For demonstration purpose only.
 * MicroEJ Corp. PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

/* Prevent recursive inclusion */

#ifndef __T_UI_API_H
#define __T_UI_API_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../framework/c/embunit/embunit/embUnit.h"

/* Public function declarations */

/**
 * @brief Performs several tests on LLDisplay API to validate LLDisplay implementation.
 */
TestRef T_UI_API_tests(void);

#ifdef __cplusplus
}
#endif

#endif
