/*
 * Copyright 2015-2019 IS2T. All rights reserved.
 * For demonstration purpose only.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

#include "ram_test-conf.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef __RAM_TEST_SPEED_INTERN_H
#define __RAM_TEST_SPEED_INTERN_H

/** to have a test precision with speed you must provide a function
 * that get us since start of application */
#define TEST_TIME_getTime()   (time_hardware_timer_getTimeNanos() / 1000)

/** private function declaration */
    __weak void RAM_TEST_SPEED_writeBlock32(volatile uint32_t *address, volatile uint32_t value, uint32_t size);
    __weak void RAM_TEST_SPEED_readBlock32(volatile uint32_t *address, uint32_t size);
    __weak void RAM_TEST_SPEED_transfertBlock32(volatile uint32_t *src, volatile uint32_t *dest, uint32_t size);
    __weak void RAM_TEST_SPEED_writeBlock16(volatile uint16_t *address, volatile uint16_t value, uint32_t size);
    __weak void RAM_TEST_SPEED_readBlock16(volatile uint16_t *address, uint32_t size);
    __weak void RAM_TEST_SPEED_transfertBlock16(volatile uint16_t *src, volatile uint16_t *dest, uint32_t size);
    __weak void RAM_TEST_SPEED_writeBlock8(volatile uint8_t *address, volatile uint8_t value, uint32_t size);
    __weak void RAM_TEST_SPEED_readBlock8(volatile uint8_t *address, uint32_t size);
    __weak void RAM_TEST_SPEED_transfertBlock8(volatile uint8_t *src, volatile uint8_t *dest, uint32_t size);


#endif
