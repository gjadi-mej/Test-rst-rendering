/*
 * Copyright 2015-2019 IS2T. All rights reserved.
 * For demonstration purpose only.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */


#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef __X_RAM_SPEED_H
#define __X_RAM_SPEED_H

//#define CONFIG_TEST_PRINTF_ON

/** Debug macro */
#ifndef TEST_DBG
#ifdef CONFIG_TEST_PRINTF_ON
    #define TEST_DBG      printf
#else
    #define TEST_DBG(...) (void)0
#endif
#endif

/** Ram speed tests pattern definition */

#define X_RAM_SPEED_PATTERN32                    0xAAAAAAAA
#define X_RAM_SPEED_PATTERN16                    0xAAAA
#define X_RAM_SPEED_PATTERN8                     0xAA



/** public function declaration */
double X_RAM_SPEED_getAverageWriteSpeed(void);
double X_RAM_SPEED_getAverageReadSpeed(void);
double X_RAM_SPEED_getAverageTransfertSpeed(void);

/** weak function declaration */
    void X_RAM_SPEED_writeBlock32(volatile uint32_t *address, volatile uint32_t value, uint32_t size);
    void X_RAM_SPEED_readBlock32(volatile uint32_t *address, uint32_t size);
    void X_RAM_SPEED_transfertBlock32(volatile uint32_t *src, volatile uint32_t *dest, uint32_t size);
    void X_RAM_SPEED_writeBlock16(volatile uint16_t *address, volatile uint16_t value, uint32_t size);
    void X_RAM_SPEED_readBlock16(volatile uint16_t *address, uint32_t size);
    void X_RAM_SPEED_transfertBlock16(volatile uint16_t *src, volatile uint16_t *dest, uint32_t size);
    void X_RAM_SPEED_writeBlock8(volatile uint8_t *address, volatile uint8_t value, uint32_t size);
    void X_RAM_SPEED_readBlock8(volatile uint8_t *address, uint32_t size);
    void X_RAM_SPEED_transfertBlock8(volatile uint8_t *src, volatile uint8_t *dest, uint32_t size);


#endif
