/*
 * C
 * 
 * Copyright 2019-2021 MicroEJ Corp. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be found with this software.
 */

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "t_ui_main.h"
#include "x_ui_config.h"
#include "bsp_util.h"
#include "LLUI_DISPLAY.h"
#include "../../../../framework/c/embunit/embUnit/embUnit.h"

/**
 * 
 * @brief This function provides an invalid value of LCD BPP (bit-per-pixel).
 *
 * @return 0
 */

BSP_DECLARE_WEAK_FCNT uint32_t UI_CONFIG_getBPP(void)
{
	return 0;
}

#ifdef ENABLE_FLUSH_TESTS

void LLUI_DISPLAY_flushDone(bool from_isr)
{
	// Overrides the Graphics Engine's function.
	// - To run the PQT UI tests, change caller to use T_UI_LCD_flush_done() function instead.
	// - To run the MicroEJ VEE application, restore caller.
	// In both cases, comment, rename or remove this function.
	// Note: the function T_UI_LCD_flush_done() is calling Graphics Engine's LLUI_DISPLAY_flushDone() function
	// when PQT UI tests are not running (MicroEJ VEE is running). However this call performs an indirection.
	// @see ENABLE_FLUSH_TESTS
	
	TEST_FAIL("Call T_UI_LCD_flush_done() instead of LLUI_DISPLAY_flushDone() to run the PQT UI tests.");
}

#endif // ENABLE_FLUSH_TESTS
