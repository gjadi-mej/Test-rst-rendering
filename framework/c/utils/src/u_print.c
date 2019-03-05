/*
 * Copyright 2019 IS2T. All rights reserved.
 * For demonstration purpose only.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "../../../../framework/c/utils/inc/u_print.h"
#include "../../../../framework/c/utils/inc/bsp_util.h"
#include "../../../../framework/c/embunit/embunit/config.h"

/** public function definitions */

BSP_DECLARE_WEAK_FCNT void UTIL_print_initialize(void)
{
	
}

BSP_DECLARE_WEAK_FCNT void UTIL_print_string(const char* string)
{
	printf("%s",string);
}

BSP_DECLARE_WEAK_FCNT void UTIL_print_integer(int integer)
{
		printf("%i",integer);
}

BSP_DECLARE_WEAK_FCNT void UTIL_print_float(double value)
{
		printf("%f",value);
}

BSP_DECLARE_WEAK_FCNT void UTIL_print_longlong(long long value)
{
		printf("%llu",value);
}
