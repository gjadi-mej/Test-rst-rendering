/*
 * Copyright 2014-2019 IS2T. All rights reserved.
 * For demonstration purpose only.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "u_time_base.h"
#include "bsp_util.h"
#include "embunit/config.h"
/** Private constant declarations */



/** private variable definitions */

/** public function definitions */

BSP_DECLARE_WEAK_FCNT void UTIL_TIME_BASE_initialize(void)
{
	stdimpl_print("[Warning]: No implementation of UTIL_TIME_BASE_initialize found!\n");
}	

BSP_DECLARE_WEAK_FCNT uint64_t UTIL_TIME_BASE_getTime(void)
{
	return 0;
}

/** private function definitions */

