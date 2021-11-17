/*
 * C
 *
 * Copyright 2019-2021 MicroEJ Corp. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be found with this software.
 */

/* Prevent recursive inclusion */

#ifndef __T_UI_TEARING_H
#define __T_UI_TEARING_H

#ifdef __cplusplus
extern "C" {
#endif

/* Public function declarations */

/*
 * @brief Shows alternately black and white screens. The tearing effect is visible when the screen is
 * cut in two or more parts.
 */
TestRef T_UI_TEARING_tests(void);

#ifdef __cplusplus
}
#endif

#endif
