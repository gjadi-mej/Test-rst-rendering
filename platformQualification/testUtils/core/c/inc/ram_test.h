/*
 * Copyright 2014-2019 IS2T. All rights reserved.
 * For demonstration purpose only.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

/* Prevent recursive inclusion */

#ifndef __RAM_TEST_H
#define __RAM_TEST_H
#include <stdint.h>

/** Public constant declaration */

/**
 *    Test definitions
 */
#define RAM_TEST_ALL_LOW_DATA       0x0001
#define RAM_TEST_ALL_HIGH_DATA      0x0002
#define RAM_TEST_HALF_HIGH_DATA     0x0004
#define RAM_TEST_ODD_BIT_DATA       0x0008
#define RAM_TEST_EVEN_BIT_DATA      0x0010
#define RAM_TEST_GENERIC_DATA       0x0020
#define RAM_TEST_ADDRESS_BIT        0x0100
#define RAM_TEST_READ_SPEED         0x1000
#define RAM_TEST_WRITE_SPEED        0x2000
#define RAM_TEST_TRANSFERT_SPEED    0x4000
#define RAM_TEST_ALL_FUNCTIONAL     0x0FFF
#define RAM_TEST_ALL_TESTS          0xFFFF


/** public structure declaration */

typedef struct {
	uint32_t start_address;
	uint32_t end_address;
	double write_speed;
	double read_speed;
	double transfert_speed;
} RAM_TEST_zone_t;

/** public function declaration */

uint32_t RAM_TEST_check32bitWriteAllNextReadAll(uint16_t patternType);
uint32_t RAM_TEST_check32bitWriteRead(uint16_t patternType);
uint32_t RAM_TEST_checkAddress32(void);
uint32_t RAM_TEST_check16bitWriteAllNextReadAll(uint16_t patternType);
uint32_t RAM_TEST_check16bitWriteRead(uint16_t patternType);
uint32_t RAM_TEST_checkAddress16(void);
uint32_t RAM_TEST_check8bitWriteAllNextReadAll(uint16_t patternType);
uint32_t RAM_TEST_check8bitWriteRead(uint16_t patternType);
uint32_t RAM_TEST_checkAddress8(void);

double RAM_TEST_getAverageWriteSpeed(void);
double RAM_TEST_getAverageReadSpeed(void);
double RAM_TEST_getAverageTransfertSpeed(void);

void RAM_TEST_MemoryCleanup(void);

// weak function to implement
RAM_TEST_zone_t* RAM_TEST_get32bitZones(void);
RAM_TEST_zone_t* RAM_TEST_get16bitZones(void);
RAM_TEST_zone_t* RAM_TEST_get8bitZones(void);
RAM_TEST_zone_t* RAM_TEST_get32bitSourceZone(void);
RAM_TEST_zone_t* RAM_TEST_get16bitSourceZone(void);
RAM_TEST_zone_t* RAM_TEST_get8bitSourceZone(void);
uint8_t RAM_TEST_get32bitZoneNumber(void);
uint8_t RAM_TEST_get16bitZoneNumber(void);
uint8_t RAM_TEST_get8bitZoneNumber(void);

#endif
