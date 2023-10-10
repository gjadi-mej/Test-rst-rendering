/*
 * C
 *
 * Copyright 2023 MicroEJ Corp. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be found with this software.
 */

#include <stdio.h>
#include <stdarg.h>
#include "t_llkernel.h"
#include "../../../../framework/c/embunit/embUnit/embUnit.h"

void T_LLKERNEL_main(void) {
	TestRunner_start();
	TestRunner_runTest(T_LLKERNEL_tests());
	TestRunner_end();
	return;
}
