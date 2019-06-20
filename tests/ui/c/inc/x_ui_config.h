/*
 * Copyright 2019 MicroEJ Corp. All rights reserved.
 * For demonstration purpose only.
 * MicroEJ Corp. PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

/* Prevent recursive inclusion */

#ifndef __T_UI_CONFIG_H
#define __T_UI_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

#define UI_LCD_BPP_ARGB8888 32
#define UI_LCD_BPP_RGB888 24
#define UI_LCD_BPP_RGB565 16
#define UI_LCD_BPP_RGB1555 16
#define UI_LCD_BPP_RGB4444 16

/* Public function declarations */

/**
 * @brief XXX
 */
uint32_t UI_CONFIG_getBPP(void);

#ifdef __cplusplus
}
#endif

#endif
