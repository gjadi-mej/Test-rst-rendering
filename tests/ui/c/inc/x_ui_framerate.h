/*
 * Copyright 2019 MicroEJ Corp. All rights reserved.
 * For demonstration purpose only.
 * MicroEJ Corp. PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

/* Prevent recursive inclusion */

#ifndef __X_UI_FRAMERATE_H
#define __X_UI_FRAMERATE_H

#ifdef __cplusplus
extern "C" {
#endif

/* Public function declarations */

/**
 * @brief Retrieves the LCD minimal time to refresh itself (framerate in us) and the time to perform
 * the copy from back buffer to frame buffer
 */
void X_UI_FRAMERATE_get(uint32_t buffer_address, uint32_t* framerate_time_us, uint32_t* flush_copy_time_us);

#ifdef __cplusplus
}
#endif

#endif
