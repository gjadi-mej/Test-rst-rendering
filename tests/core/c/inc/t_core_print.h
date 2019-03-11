/*
 * Copyright 2019 MicroEJ Corp. All rights reserved.
 * For demonstration purpose only.
 * MicroEJ Corp. PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */
 
/* Prevent recursive inclusion */

#ifndef __T_CORE_PRINT_H
#define __T_CORE_PRINT_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "../../../../framework/c/embunit/embunit/embUnit.h"

/* Public function declarations */
/**
 *@brief This test uses the 'UTIL_print_ xx' functions to display a message.
 *  If the message appears on the display peripheral, this test is passed.
 */
TestRef T_CORE_PRINT_tests(void);

#ifdef __cplusplus
}
#endif

#endif
