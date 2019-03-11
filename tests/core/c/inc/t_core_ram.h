/*
 * Copyright 2019 MicroEJ Corp. All rights reserved.
 * For demonstration purpose only.
 * MicroEJ Corp. PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

/* Prevent recursive inclusion */

#ifndef __T_CORE_RAM_H
#define __T_CORE_RAM_H
#include "../../../../framework/c/embunit/embUnit/embUnit.h"

#ifdef __cplusplus
 extern "C" {
#endif

/* Public function declarations */
/**
 * @fn TestRef  T_CORE_RAM_tests(void)
 * @brief For each RAM access word width ( 8, 16 and 32 bits ), if memory areas are defined, the test use the following 
 * patterns to check the memory integrity:
 * -# pattern value where all word bits are in low level state
 * -# pattern value where  all word bits are in high level state
 * -# pattern value where  the half word bits are in high level state
 * -# pattern value where  all odd bits of the word are in high level state
 * -# pattern value where  all even bits of the word are in high level state
 * -# a generic data .
 * If  some integrity errors are detected, the test fails.
 *
 * @fn TestRef  T_CORE_RAM_speed_tests(void)
 * @brief For each RAM access word width ( 8, 16 and 32 bits ), if memory target and source areas are defined, this test computes 
 * the average speeds for read accesses, write accesses and data transfert ( source to target area ). This tests displays the computation results. It always pass.
 */
TestRef  T_CORE_RAM_tests(void);
TestRef  T_CORE_RAM_speed_tests(void);

#ifdef __cplusplus
}
#endif

#endif
