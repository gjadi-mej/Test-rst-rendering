/*
 * Copyright 2019 MicroEJ Corp. All rights reserved.
 * For demonstration purpose only.
 * MicroEJ Corp. PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "x_ram_checks.h"
#include "bsp_util.h"


/* public weak function default definitions */


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

