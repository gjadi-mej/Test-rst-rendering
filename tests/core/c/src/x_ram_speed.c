/*
 * Copyright 2014-2019 IS2T. All rights reserved.
 * For demonstration purpose only.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "time_base_test.h"
#include "ram_test.h"
#include "ram/ram_test_speed-intern.h"


/** public variables */

/** private constant definition */

/** private variable definitions */

/** private function declaration */


    double RAM_TEST_SPEED_getWriteSpeed32(void);
    double RAM_TEST_SPEED_getReadSpeed32(void);
    double RAM_TEST_SPEED_getTransfertSpeed32(void);

    double RAM_TEST_SPEED_getWriteSpeed16(void);
    double RAM_TEST_SPEED_getReadSpeed16(void);
    double RAM_TEST_SPEED_getTransfertSpeed16(void);

    double RAM_TEST_SPEED_getWriteSpeed8(void);
    double RAM_TEST_SPEED_getReadSpeed8(void);
    double RAM_TEST_SPEED_getTransfertSpeed8(void);



/** function definitions */
double RAM_TEST_getAverageWriteSpeed(void)
{
    double avrSpeed = 0;
    double counter = 0;


    avrSpeed += RAM_TEST_SPEED_getWriteSpeed32();
    counter++;


    avrSpeed += RAM_TEST_SPEED_getWriteSpeed16();
    counter++;


    avrSpeed += RAM_TEST_SPEED_getWriteSpeed8();
    counter++;


    if (counter != 0)
    {
        return (avrSpeed / counter);
    }
    else
    {
        return 0;
    }
}

double RAM_TEST_getAverageReadSpeed(void)
{
    double avrSpeed = 0;
    double counter = 0;


    avrSpeed += RAM_TEST_SPEED_getReadSpeed32();
    counter++;

    avrSpeed += RAM_TEST_SPEED_getReadSpeed16();
    counter++;

    avrSpeed += RAM_TEST_SPEED_getReadSpeed8();
    counter++;

    if (counter != 0)
    {
        return (avrSpeed / counter);
    }
    else
    {
        return 0;
    }
}

double RAM_TEST_getAverageTransfertSpeed(void)
{
    double avrSpeed = 0;
    double counter = 0;



    avrSpeed += RAM_TEST_SPEED_getTransfertSpeed32();
    counter++;

    avrSpeed += RAM_TEST_SPEED_getTransfertSpeed16();
    counter++;

    avrSpeed += RAM_TEST_SPEED_getTransfertSpeed8();
    counter++;


    if (counter != 0)
    {
        return (avrSpeed / counter);
    }
    else
    {
        return 0;
    }
}


double RAM_TEST_SPEED_getWriteSpeed32(void)
{
	int64_t time;
	double speed, average_speed = 0;
	uint32_t z;
	
	for( z = 0; z < RAM_TEST_get32bitZoneNumber(); z++ )
	{
		// gets zone definition array 
		RAM_TEST_zone_t* zones = RAM_TEST_get32bitZones();	
		
		time = TIME_BASE_TEST_getTime();
    RAM_TEST_SPEED_writeBlock32((volatile uint32_t *)zones[z].start_address, RAM_TEST_SPEED_PATTERN32, zones[z].end_address - zones[z].start_address);
    time = TIME_BASE_TEST_getTime() - time;

    speed = ( zones[z].end_address - zones[z].start_address) / time;   /* bytes per us */
    speed *= 1000.0;                /* bytes per ms */
    speed *= 1000.0;                /* bytes per  s */
		zones[z].write_speed = speed;
		average_speed += speed;
    TEST_DBG("RAM_TEST_Speed with 32-bit write access : %f MBytes/s \n", (speed / 1024.0) / 1024.0);		
	}
	return average_speed / RAM_TEST_get32bitZoneNumber();
}



double RAM_TEST_SPEED_getReadSpeed32(void)
{
	int64_t time;
	double speed, average_speed = 0;
	uint32_t z;
	
	for( z = 0; z < RAM_TEST_get32bitZoneNumber(); z++ )
	{
    
		// gets zone definition array 
		RAM_TEST_zone_t* zones = RAM_TEST_get32bitZones();	
		
		time = TIME_BASE_TEST_getTime();
		
    RAM_TEST_SPEED_readBlock32((volatile uint32_t *) zones[z].start_address, zones[z].end_address - zones[z].start_address);
    time = TIME_BASE_TEST_getTime() - time;

    speed = (zones[z].end_address - zones[z].start_address) / time;   /* bytes per us */
    speed *= 1000.0;                /* bytes per ms */
    speed *= 1000.0;                /* bytes per  s */
		zones[z].read_speed = speed;
		average_speed += speed;
    TEST_DBG("RAM_TEST_Speed with 32-bit read access : %f MBytes/s \n", (speed / 1024.0) / 1024.0);
	}
	return average_speed / RAM_TEST_get32bitZoneNumber();
}

double RAM_TEST_SPEED_getTransfertSpeed32(void)
{
	int64_t time;
	double speed, average_speed = 0;
	uint32_t z;
	// if no source zone defined, the test is stopped 
	if (RAM_TEST_get32bitSourceZone() == NULL )
	{
		return 0.0;
	}
	for( z = 0; z < RAM_TEST_get32bitZoneNumber(); z++ )
	{
    // gets zone definition array 
		RAM_TEST_zone_t* zones = RAM_TEST_get32bitZones();
		
		time = TIME_BASE_TEST_getTime();
		
    RAM_TEST_SPEED_transfertBlock32((volatile uint32_t *) RAM_TEST_get32bitSourceZone()->start_address, 
			(volatile uint32_t *) zones[z].start_address, 
			RAM_TEST_get32bitSourceZone()->end_address - RAM_TEST_get32bitSourceZone()->start_address);
    
		time = TIME_BASE_TEST_getTime() - time;

    speed = (RAM_TEST_get32bitSourceZone()->end_address - RAM_TEST_get32bitSourceZone()->start_address) / time;   /* bytes per us */
    speed *= 1000.0;                      /* bytes per ms */
    speed *= 1000.0;                      /* bytes per  s */
		zones[z].transfert_speed = speed;
		average_speed += speed;
    TEST_DBG("RAM_TEST_Speed with 32-bit transfert access : %f MBytes/s \n", (speed / 1024.0) / 1024.0);
		}
		return average_speed / RAM_TEST_get32bitZoneNumber();
}



double RAM_TEST_SPEED_getWriteSpeed16(void)
{
	int64_t time;
	double speed, average_speed = 0;
	uint32_t z;
	
	for( z = 0; z < RAM_TEST_get16bitZoneNumber(); z++ )
	{
    // gets zone definition array 
		RAM_TEST_zone_t* zones = RAM_TEST_get16bitZones();

    time = TIME_BASE_TEST_getTime();
    RAM_TEST_SPEED_writeBlock16((volatile uint16_t *) zones[z].start_address, RAM_TEST_SPEED_PATTERN16, 
			zones[z].end_address - zones[z].start_address);
    time = TIME_BASE_TEST_getTime() - time;

    speed = (zones[z].end_address - zones[z].start_address) / time;   /* bytes per us */
    speed *= 1000.0;                /* bytes per ms */
    speed *= 1000.0;                /* bytes per  s */
		zones[z].write_speed = speed;
		average_speed += speed;
    TEST_DBG("RAM_TEST_Speed with 16-bit write access : %f MBytes/s \n", (speed / 1024.0) / 1024.0);
	}
	return average_speed / RAM_TEST_get16bitZoneNumber();
}

double RAM_TEST_SPEED_getReadSpeed16(void)
{
	int64_t time;
	double speed, average_speed = 0;
	uint32_t z;
	
	for( z = 0; z < RAM_TEST_get16bitZoneNumber(); z++ )
	{
    // gets zone definition array 
		RAM_TEST_zone_t* zones = RAM_TEST_get16bitZones();
		
    time = TIME_BASE_TEST_getTime();
    RAM_TEST_SPEED_readBlock16((volatile uint16_t *) zones[z].start_address, zones[z].end_address - zones[z].start_address);
    time = TIME_BASE_TEST_getTime() - time;

    speed = (zones[z].end_address - zones[z].start_address) / time;   /* bytes per us */
    speed *= 1000.0;                /* bytes per ms */
    speed *= 1000.0;                /* bytes per  s */
		zones[z].read_speed = speed;
		average_speed += speed;
		TEST_DBG("RAM_TEST_Speed with 16-bit read access : %f MBytes/s \n", (speed / 1024.0) / 1024.0);
	}

	return average_speed / RAM_TEST_get16bitZoneNumber();
}


double RAM_TEST_SPEED_getTransfertSpeed16(void)
{
	int64_t time;
	double speed, average_speed = 0;
	uint32_t z;
	
	// if no source zone defined, the test is stopped 
	if (RAM_TEST_get16bitSourceZone() == NULL )
	{
		return 0.0;
	}
	
	for( z = 0; z < RAM_TEST_get16bitZoneNumber(); z++ )
	{
    // gets zone definition array 
		RAM_TEST_zone_t* zones = RAM_TEST_get16bitZones();
		

    time = TIME_BASE_TEST_getTime();
    RAM_TEST_SPEED_transfertBlock16((volatile uint16_t *) RAM_TEST_get16bitSourceZone()->start_address, 
			(volatile uint16_t *) zones[z].start_address, 
				RAM_TEST_get16bitSourceZone()->end_address - RAM_TEST_get16bitSourceZone()->start_address);
    time = TIME_BASE_TEST_getTime() - time;

    speed = (RAM_TEST_get16bitSourceZone()->end_address - RAM_TEST_get16bitSourceZone()->start_address) / time;   /* bytes per us */
    speed *= 1000.0;                      /* bytes per ms */
    speed *= 1000.0;                      /* bytes per  s */
		zones[z].transfert_speed = speed;
		average_speed += speed;
    TEST_DBG("RAM_TEST_Speed with 16-bit transfert access : %f MBytes/s \n", (speed / 1024.0) / 1024.0);
	}
	return average_speed / RAM_TEST_get16bitZoneNumber();
}


double RAM_TEST_SPEED_getWriteSpeed8(void)
{
	int64_t time;
	double speed, average_speed = 0;
	uint32_t z;
	
	for( z = 0; z < RAM_TEST_get8bitZoneNumber(); z++ )
	{
    // gets zone definition array 
		RAM_TEST_zone_t* zones = RAM_TEST_get8bitZones();
    time = TIME_BASE_TEST_getTime();
    RAM_TEST_SPEED_writeBlock8((volatile uint8_t *) zones[z].start_address, RAM_TEST_SPEED_PATTERN8, 
			zones[z].end_address - zones[z].start_address);
    time = TIME_BASE_TEST_getTime() - time;

    speed = (zones[z].end_address - zones[z].start_address) / time;   /* bytes per us */
    speed *= 1000.0;                /* bytes per ms */
    speed *= 1000.0;                /* bytes per  s */
		zones[z].write_speed = speed;
		average_speed += speed;
    TEST_DBG("RAM_TEST_Speed with 8-bit write access : %f MBytes/s \n", (speed / 1024.0) / 1024.0);
		
	}
  return average_speed / RAM_TEST_get8bitZoneNumber();
}


double RAM_TEST_SPEED_getReadSpeed8(void)
{
	int64_t time;
	double speed, average_speed = 0;
	uint32_t z;
	
	for( z = 0; z < RAM_TEST_get8bitZoneNumber(); z++ )
	{
		// gets zone definition array 
		RAM_TEST_zone_t* zones = RAM_TEST_get8bitZones();
    time = TIME_BASE_TEST_getTime();
    RAM_TEST_SPEED_readBlock8((volatile uint8_t *) zones[z].start_address, 
			zones[z].end_address - zones[z].start_address);
    time = TIME_BASE_TEST_getTime() - time;

    speed = (zones[z].end_address - zones[z].start_address) / time;   /* bytes per us */
    speed *= 1000.0;                /* bytes per ms */
    speed *= 1000.0;                /* bytes per  s */
		zones[z].read_speed = speed;
		average_speed += speed;
    TEST_DBG("RAM_TEST_Speed with 8-bit read access : %f MBytes/s \n", (speed / 1024.0) / 1024.0);
	}
  return average_speed / RAM_TEST_get8bitZoneNumber();
}

double RAM_TEST_SPEED_getTransfertSpeed8(void)
{
	int64_t time;
	double speed, average_speed = 0;
	uint32_t z;
	
	// if no source zone defined, the test is stopped 
	if (RAM_TEST_get8bitSourceZone() == NULL )
	{
		return 0.0;
	}
	
	for( z = 0; z < RAM_TEST_get8bitZoneNumber(); z++ )
	{
		// gets zone definition array 
		RAM_TEST_zone_t* zones = RAM_TEST_get8bitZones();
    time = TIME_BASE_TEST_getTime();
    RAM_TEST_SPEED_transfertBlock8((volatile uint8_t *)  RAM_TEST_get8bitSourceZone()->start_address, 
			(volatile uint8_t *) zones[z].start_address, 
				RAM_TEST_get8bitSourceZone()->end_address - RAM_TEST_get8bitSourceZone()->start_address);
    time = TIME_BASE_TEST_getTime() - time;

    speed = (RAM_TEST_get8bitSourceZone()->end_address - RAM_TEST_get8bitSourceZone()->start_address) / time;   /* bytes per us */
    speed *= 1000.0;                      /* bytes per ms */
    speed *= 1000.0;                      /* bytes per  s */
		zones[z].transfert_speed = speed;
		average_speed += speed;
    TEST_DBG("RAM_TEST_Speed with 8-bit transfert access : %f MBytes/s \n", (speed / 1024.0) / 1024.0);
	}
	return average_speed / RAM_TEST_get8bitZoneNumber();
}



__weak void RAM_TEST_SPEED_writeBlock32(volatile uint32_t *address, volatile uint32_t value, uint32_t size)
{
    uint32_t i;

    for (i = 0; i < (size / sizeof(uint32_t)); i++)
    {
        *address++ = value;
    }
}

__weak void RAM_TEST_SPEED_readBlock32(volatile uint32_t *address, uint32_t size)
{
    volatile uint32_t value;
    uint32_t i;

    for (i = 0; i < (size / sizeof(uint32_t)); i++)
    {
        value = *address++;
    }
}

__weak void RAM_TEST_SPEED_transfertBlock32(volatile uint32_t *src, volatile uint32_t *dest, uint32_t size)
{
    uint32_t i;

    for (i = 0; i < (size / sizeof(uint32_t)); i++)
    {
        *dest++ = *src++;
    }
}

__weak void RAM_TEST_SPEED_writeBlock16(volatile uint16_t *address, volatile uint16_t value, uint32_t size)
{
    uint32_t i;

    for (i = 0; i < (size / sizeof(uint16_t)); i++)
    {
        *address++ = value;
    }
}

__weak void RAM_TEST_SPEED_readBlock16(volatile uint16_t * address, uint32_t size)
{
    volatile uint16_t value;
    uint32_t i;

    for (i = 0; i < (size / sizeof(uint16_t)); i++)
    {
        value = *address++;
    }
}

__weak void RAM_TEST_SPEED_transfertBlock16(volatile uint16_t *src, volatile uint16_t *dest, uint32_t size)
{
    uint32_t i;

    for (i = 0; i < (size / sizeof(uint16_t)); i++)
    {
        *dest++ = *src++;
    }
}

__weak void RAM_TEST_SPEED_writeBlock8(volatile uint8_t *address, volatile uint8_t value, uint32_t size)
{
    uint32_t i;

    for (i = 0; i < (size / sizeof(uint8_t)); i++)
    {
        *address++ = value;
    }
}

__weak void RAM_TEST_SPEED_readBlock8(volatile uint8_t *address, uint32_t size)
{
    volatile uint8_t value;
    uint32_t i;

    for (i = 0; i < (size / sizeof(uint8_t)); i++)
    {
        value = *address++;
    }
}

__weak void RAM_TEST_SPEED_transfertBlock8(volatile uint8_t *src, volatile uint8_t *dest, uint32_t size)
{
    uint32_t i;

    for (i = 0; i < (size / sizeof(uint8_t)); i++)
    {
        *dest++ = *src++;
    }
}


