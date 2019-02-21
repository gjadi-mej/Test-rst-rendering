/*
 * Copyright 2014-2019 IS2T. All rights reserved.
 * For demonstration purpose only.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "x_ram_checks.h"
#include "bsp_util.h"


/** public weak function default definitions */


/**
 * @brief 
 *
 * @return 
 */

BSP_DECLARE_WEAK_FCNT X_RAM_CHECKS_zone_t* X_RAM_CHECKS_get32bitZones(void)
{
	return (X_RAM_CHECKS_zone_t*)NULL;
}


/**
 * @brief 
 *
 * @return 
 */

BSP_DECLARE_WEAK_FCNT X_RAM_CHECKS_zone_t* X_RAM_CHECKS_get16bitZones(void)
{
	return (X_RAM_CHECKS_zone_t*)NULL;
}


/**
 * @brief 
 *
 * @return 
 */

BSP_DECLARE_WEAK_FCNT X_RAM_CHECKS_zone_t* X_RAM_CHECKS_get8bitZones(void)
{
	return (X_RAM_CHECKS_zone_t*)NULL;
}


/**
 * @brief 
 *
 * @return 
 */

BSP_DECLARE_WEAK_FCNT uint8_t X_RAM_CHECKS_get32bitZoneNumber(void)
{
	return 0;
}


/**
 * @brief 
 *
 * @return 
 */

BSP_DECLARE_WEAK_FCNT uint8_t X_RAM_CHECKS_get16bitZoneNumber(void)
{
	return 0;
}


/**
 * @brief 
 *
 * @return 
 */

BSP_DECLARE_WEAK_FCNT uint8_t X_RAM_CHECKS_get8bitZoneNumber(void)
{
	return 0;
}


/**
 * @brief 
 *
 * @return 
 */

BSP_DECLARE_WEAK_FCNT X_RAM_CHECKS_zone_t* X_RAM_CHECKS_get32bitSourceZone(void)
{
	return (X_RAM_CHECKS_zone_t*)NULL;
}


/**
 * @brief 
 *
 * @return 
 */

BSP_DECLARE_WEAK_FCNT X_RAM_CHECKS_zone_t* X_RAM_CHECKS_get16bitSourceZone(void)
{
	return (X_RAM_CHECKS_zone_t*)NULL;
}


/**
 * @brief 
 *
 * @return 
 */

BSP_DECLARE_WEAK_FCNT X_RAM_CHECKS_zone_t* X_RAM_CHECKS_get8bitSourceZone(void)
{
		return (X_RAM_CHECKS_zone_t*)NULL;
}
