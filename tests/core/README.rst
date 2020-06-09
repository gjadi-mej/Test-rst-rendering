.. ReStructuredText
.. Copyright 2019-2020 MicroEJ Corp.  MicroEJ Corp. All rights reserved.
.. Use of this source code is governed by a BSD-style license that can be found with this software.


Overview
========

This folder is a part of a project which gathers the platform
qualification tools. It contains sources and projects to check drivers
and implementation of print, time base, RAM, Core, and micro JVM.

All tests can be run in one step: all tests will be executed one by one
and are run in a specific order, *next one* expects *previous one* is
passed.

For each test, its configuration and its results are described in a
dedicated section. See `SumUp`_ chapter which resume how to configure the
tests, how to launch them and the expected results.

Dependencies
============

-  Follow the main readme file
-  EEMBC Coremark

Tests Description
=================

Print: t_core_print.c
---------------------

An implementation of ``print`` is required by MicroEJ platform to debug
the Java exceptions. Furthermore this implementation is also required to
check this qualification bundle.

**Configuration**

The default implementation (the one implemented in the ``weak``
functions, see ``u_print.c``) calls ``stdio``\ ’s ``printf`` functions.
Write your own functions if necessary.

**Expected results**

A message is just printed:

::

   ****************************************************************************
   **                      Platform Qualification Core                       **
   **                              version 1.0                               **
   ****************************************************************************
   *           Copyright 2013-2019 MicroEJ Corp. All rights reserved.         *
   * Modification and distribution is permitted under certain conditions.     *
   * MicroEJ Corp. PROPRIETARY/CONFIDENTIAL. Use is subject to license terms. *
   ****************************************************************************

   Print test:
    if this message is displayed, the test is passed!

Timer: t_core_time_base.c
-------------------------

A time counter is required by MicroEJ platform. This timer must respect
the following rules: \* during MicroEJ application, this counter must
not return to zero (return in the past), \* its precision must be around
one or ten microseconds (often running at 1MHz).

This timer can be the OS timer but most of time the OS timer does not
respect the expected conditions. A hardware timer is often used instead.
Its interrupt should be programmed to occur when the timer exceeds the
half of the counter. Under interrupt, a software counter is updated.
When application asks the time, an addition between this software
counter and the current hardware timer is performed.

This timer is used by the next qualification tests and by the LLMJVM
implementation (see ``LLMJVM_impl.h``, functions
``LLMJVM_IMPL_getCurrentTime`` and ``LLMJVM_IMPL_getTimeNanos``).

This test ensures a timer is implemented but it does not check its
accuracy (tested later).

**Configuration**

The default implementation (the one implemented in the ``weak``
functions, see ``u_time_base.c``) returns always ``0``. Write your own
functions to implement the timer counter.

**Expected results**

No error must be thrown when executing this test:

::

   Time base check:
   .

RAM Tests: t_core_ram.c
-----------------------

This test is useful to check external RAM when it is available on the
hardware. The test performs several read and write actions, with
different patterns. All accesses are aligned on value to write: 8, 16 or
32 bits, like the MicroEJ platform will use the RAM.

To run, several functions must be implemented. See ``x_ram_checks.h``:
\* ``X_RAM_CHECKS_zone_t* X_RAM_CHECKS_get32bitZones(void)`` \*
``X_RAM_CHECKS_zone_t* X_RAM_CHECKS_get16bitZones(void)`` \*
``X_RAM_CHECKS_zone_t* X_RAM_CHECKS_get8bitZones(void)`` \*
``uint8_t X_RAM_CHECKS_get32bitZoneNumber(void)`` \*
``uint8_t X_RAM_CHECKS_get16bitZoneNumber(void)`` \*
``uint8_t X_RAM_CHECKS_get8bitZoneNumber(void)``

**Configuration**

Some default weak functions are already implemented and return ``NULL``
or ``0``; that means the test will not been performed.

**Expected results**

No error must be thrown when executing this test:

::

   RAM tests:
   .....................

RAM Benchs: t_core_ram.c
------------------------

This test is useful to bench external RAM accesses when it is available
on the hardware. This test only performs some benches. In addition with
previous test, the external RAM timings can be adjusted to obtain the
faster RAM accesses (and without any error!).

**Configuration**

To run, several functions must be implemented. See ``x_ram_checks.h``:
\* ``X_RAM_CHECKS_zone_t* X_RAM_CHECKS_get32bitSourceZone(void)`` \*
``X_RAM_CHECKS_zone_t* X_RAM_CHECKS_get16bitSourceZone(void)`` \*
``X_RAM_CHECKS_zone_t* X_RAM_CHECKS_get8bitSourceZone(void)``

These *sources* can target a region in internal flash, internal RAM or
any other regions.

**Expected results**

::

   RAM speed benchmark:
   .RAM speed average read access (according to your configuration file 8/16/32 bits) : 51.180522MBytes/s
   .RAM speed average write access (according to your configuration file 8/16/32 bits) : 131.289164 MBytes/s
   .RAM speed average transfert access (according to your configuration file 8/16/32 bits) : 86.466471MBytes/s

**Notes**

These results can be sent to MicroEJ in order to compare the BSP
implementation with all others MicroEJ platforms.

Coremark: t_core_core_benchmark.c
---------------------------------

EEMBC Coremark allows to compare CPU and BSP configurations. Refer to
EEMBC Coremark website (http://www.eembc.org/coremark/index.php) to have
more information about results. The Github repository containing the sources of Coremark (https://github.com/eembc/coremark.git) is linked as a submodule of this repository.



**Configuration**

To run this test, create ``core_portme.h`` and ``core_portme.h`` files to port EEMBC CoreMark and insert the directive line :code:`#define main core_main` into the ``core_portme.h``.

**Expected results**

::

   Core/Flash benchmark:
   .2K performance run parameters for coremark.
   CoreMark Size    : 666
   Total ticks      : 12052657
   Total time (secs): 12.052657
   Iterations/Sec   : 497.815544
   Iterations       : 6000
   Compiler version : ARMCC V5.06 update 4 (build 422)
   Compiler flags   : -c --cpu Cortex-M4.fp -D__MICROLIB -g -O3 -Otime --apcs=interwork --split_sections -D__UVISION_VERSION="523" -D_RTE_ -DSTM32L496xx -DUSE_HAL_DRIVER -DSTM32L496xx
   Memory location  : STATIC
   seedcrc          : 0xe9f5
   [0]crclist       : 0xe714
   [0]crcmatrix     : 0x1fd7
   [0]crcstate      : 0x8e3a
   [0]crcfinal      : 0xa14c
   Correct operation validated. See readme.txt for run and reporting rules.
   CoreMark 1.0 : 497.815544 / ARMCC V5.06 update 4 (build 422) -c --cpu Cortex-M4.fp -D__MICROLIB -g -O3 -Otime --apcs=interwork --split_sections -D__UVISION_VERSION="523" -D_RTE_ -DSTM32L496xx -DUSE_HAL_DRIVER -DSTM32L496xx / STATIC

MicroEJ Core Validation
-----------------------

Follow the MicroEJ Core Validation `README <./java/microej-core-validation/README.rst>`_.

SumUp
=====

Configuration
-------------

1. Add all files of these folders as source files:

   - ``tests/core/c/src``
   - ``framework/c/utils/src``
   - ``framework/c/embunit/embUnit``
   - ``framework/c/CoreMark/``

2. Add these folders as include folders:

   - ``tests/core/c/inc``
   - ``framework/c/utils/inc``
   - ``framework/c/embunit/embUnit``
   - ``framework/c/CoreMark/``

3. Create ``core_portme.h`` and ``core_portme.h`` files to port EEMBC CoreMark
   (http://www.eembc.org/coremark/index.php). Insert the directive line :code:`#define main core_main` in the ``core_portme.h``. Add CoreMark files to the BSP project.

4. Implement all functions defined in these files:

   -  ``x_ram_checks.h``: see `RAM Tests: t_core_ram.c`_ and `RAM Benchs: t_core_ram.c`_
   -  ``x_core_benchmark.h``: Call EEMBC Coremark implementation.

5. Include ``t_core_main.h`` header and add a call to the function
   ``T_CORE_main()`` just before the call to ``microjvm_main()``.
6. In the MicroEJ SDK platform environment, import the MicroEJ project
   ``microej-core-validation`` from the folder ``tests/core/java``
7. Build this MicroEJ application against the platform to qualify
8. Build the BSP and link it with the MicroEJ platform runtime library
   and MicroEJ application.

Expected Results
----------------

::

   start
   .
   ****************************************************************************
   **                      Platform Qualification Core                       **
   **                              version 1.0                               **
   ****************************************************************************
   *           Copyright 2013-2019 MicroEJ Corp. All rights reserved.         *
   * Modification and distribution is permitted under certain conditions.     *
   * MicroEJ Corp. PROPRIETARY/CONFIDENTIAL. Use is subject to license terms. *
   ****************************************************************************

   Print test:
    if this message is displayed, the test is passed!

   Time base check:
   .
   RAM tests:
   .....................
   RAM speed benchmark:
   .RAM speed average read access (according to your configuration file 8/16/32 bits) : 51.180522MBytes/s
   .RAM speed average write access (according to your configuration file 8/16/32 bits) : 131.289164 MBytes/s
   .RAM speed average transfert access (according to your configuration file 8/16/32 bits) : 86.466471MBytes/s

   Core/Flash benchmark:
   .2K performance run parameters for coremark.
   CoreMark Size    : 666
   Total ticks      : 12052657
   Total time (secs): 12.052657
   Iterations/Sec   : 497.815544
   Iterations       : 6000
   Compiler version : ARMCC V5.06 update 4 (build 422)
   Compiler flags   : -c --cpu Cortex-M4.fp -D__MICROLIB -g -O3 -Otime --apcs=interwork --split_sections -D__UVISION_VERSION="523" -D_RTE_ -DSTM32L496xx -DUSE_HAL_DRIVER -DSTM32L496xx
   Memory location  : STATIC
   seedcrc          : 0xe9f5
   [0]crclist       : 0xe714
   [0]crcmatrix     : 0x1fd7
   [0]crcstate      : 0x8e3a
   [0]crcfinal      : 0xa14c
   Correct operation validated. See readme.txt for run and reporting rules.
   CoreMark 1.0 : 497.815544 / ARMCC V5.06 update 4 (build 422) -c --cpu Cortex-M4.fp -D__MICROLIB -g -O3 -Otime --apcs=interwork --split_sections -D__UVISION_VERSION="523" -D_RTE_ -DSTM32L496xx -DUSE_HAL_DRIVER -DSTM32L496xx / STATIC

   OK (27 tests)


