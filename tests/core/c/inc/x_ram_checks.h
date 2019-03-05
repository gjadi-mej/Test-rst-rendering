/*
 * Copyright 2014-2019 IS2T. All rights reserved.
 * For demonstration purpose only.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

/* Prevent recursive inclusion */

#ifndef __X_RAM_CHECKS_H
#define __X_RAM_CHECKS_H

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>

/** Public constant declaration */

/**
 *    Test definitions
 */
#define X_RAM_CHECKS_ALL_LOW_DATA       0x0001
#define X_RAM_CHECKS_ALL_HIGH_DATA      0x0002
#define X_RAM_CHECKS_HALF_HIGH_DATA     0x0004
#define X_RAM_CHECKS_ODD_BIT_DATA       0x0008
#define X_RAM_CHECKS_EVEN_BIT_DATA      0x0010
#define X_RAM_CHECKS_GENERIC_DATA       0x0020
#define X_RAM_CHECKS_ADDRESS_BIT        0x0100
#define X_RAM_CHECKS_READ_SPEED         0x1000
#define X_RAM_CHECKS_WRITE_SPEED        0x2000
#define X_RAM_CHECKS_TRANSFERT_SPEED    0x4000
#define X_RAM_CHECKS_ALL_FUNCTIONAL     0x0FFF
#define X_RAM_CHECKS_ALL_TESTS          0xFFFF


/* public structure declaration */

/**
 * @brief provide a memory zone definition and a storage location for memory benchmark result
 */
typedef struct {
	uint32_t start_address;
	uint32_t end_address;
	double write_speed;
	double read_speed;
	double transfert_speed;
} X_RAM_CHECKS_zone_t;

/* public function declaration */

uint32_t X_RAM_CHECKS_check32bitWriteAllNextReadAll(uint16_t patternType);
uint32_t X_RAM_CHECKS_check32bitWriteRead(uint16_t patternType);
uint32_t X_RAM_CHECKS_checkAddress32(void);
uint32_t X_RAM_CHECKS_check16bitWriteAllNextReadAll(uint16_t patternType);
uint32_t X_RAM_CHECKS_check16bitWriteRead(uint16_t patternType);
uint32_t X_RAM_CHECKS_checkAddress16(void);
uint32_t X_RAM_CHECKS_check8bitWriteAllNextReadAll(uint16_t patternType);
uint32_t X_RAM_CHECKS_check8bitWriteRead(uint16_t patternType);
uint32_t X_RAM_CHECKS_checkAddress8(void);

void X_RAM_CHECKS_MemoryCleanup(void);

// weak function to implement
X_RAM_CHECKS_zone_t* X_RAM_CHECKS_get32bitZones(void);
X_RAM_CHECKS_zone_t* X_RAM_CHECKS_get16bitZones(void);
X_RAM_CHECKS_zone_t* X_RAM_CHECKS_get8bitZones(void);
X_RAM_CHECKS_zone_t* X_RAM_CHECKS_get32bitSourceZone(void);
X_RAM_CHECKS_zone_t* X_RAM_CHECKS_get16bitSourceZone(void);
X_RAM_CHECKS_zone_t* X_RAM_CHECKS_get8bitSourceZone(void);
uint8_t X_RAM_CHECKS_get32bitZoneNumber(void);
uint8_t X_RAM_CHECKS_get16bitZoneNumber(void);
uint8_t X_RAM_CHECKS_get8bitZoneNumber(void);

#ifdef __cplusplus
}
#endif

#endif
