/*
 * Copyright 2019 IS2T. All rights reserved.
 * For demonstration purpose only.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

/* Prevent recursive inclusion */

#ifndef __T_CORE_MAIN_H
#define __T_CORE_MAIN_H

#ifdef __cplusplus
 extern "C" {
#endif

/* public function declaration */

/**
 * @brief this function is the entry point for the core test suite. By default, the executed test sequence is :
 *		-# the print test
 *		-# the time base test
 *		-# the RAM integrity tests
 *		-# the RAM speed benchmark
 *		-# the Coremark benchmark
 */
void T_CORE_main(void);

#ifdef __cplusplus
}
#endif

#endif
