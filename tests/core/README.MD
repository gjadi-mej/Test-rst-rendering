<!--
	Markdown
	
	Copyright 2019 IS2T. All rights reserved.
	Modification and distribution is permitted under certain conditions.
	
	IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
-->

# Overview
This folder is a part of a project which gathers the platform qualification tools. It contains sources and projects to check drivers and implementation of printf, time base, RAM, Core, and micro JVM.

**Folder descriptions:**
* /framework  (common files and third party tools)
    * /c (C language)
        * /embunit (Embedded Unit framework)
        * /utils ( MicroEJ test common files)
            * /src ( Source files)
            * /inc ( Header files)
                
    * java (Java language)     
* /tests ( test  source files )
    * /core
        * /c ( C language source and header files)
            * /src 
            * /inc
        * /java (eclipse Java project)


    

# Dependencies
Embedded Unit
Coremark 

# Use

1. In the platform BSP project IDE:
    * Add to "include folders", the folders 'framework/c/utils/inc', 'framework/c/embunit' and 'tests/core/c/inc'
    * Add to "source files" all files of the folders 'framework/c/utils/src', 'framework/c/embunit' and 'tests/core/c/src'

    * Download and port EEMBC CoreMark (http://www.eembc.org/coremark/index.php). Add it to the BSP project.

    * Implement useful following functions:

```
    X_RAM_CHECKS_zone_t* X_RAM_CHECKS_get32bitZones(void)
    X_RAM_CHECKS_zone_t* X_RAM_CHECKS_get16bitZones(void)
    X_RAM_CHECKS_zone_t* X_RAM_CHECKS_get8bitZones(void)
    uint8_t X_RAM_CHECKS_get32bitZoneNumber(void)
    uint8_t X_RAM_CHECKS_get16bitZoneNumber(void)
    uint8_t X_RAM_CHECKS_get8bitZoneNumber(void)
    void UTIL_TIME_BASE_initialize(void)
    uint64_t UTIL_TIME_BASE_getTime(void)
    bool X_CORE_BENCHMARK_run(void)
```
2. In the MicroEJ SDK platform environment:
    * import the Java MicroEJ project 'JVM.Portage.Validation' into folder 'tests/core/java'
    *  Build 'JVM.Portage.Validation' MicroEJ Application  against the checked platform
    
3. Build the binairy firmware and run it on the target

# Output example

```start
.
*************************************************************************
**                      Platform Qualification Core                    **
**                              version 1.0                            **
*************************************************************************
*           Copyright 2013-2016 IS2T. All rights reserved.              *
* Modification and distribution is permitted under certain conditions.  *
* IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.       *
*************************************************************************

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
VM START
*************************************************************************
*                    LLMJVM Port Validation - 2.2.5                     *
*************************************************************************
* Copyright 2013-2016 IS2T. All rights reserved.                             *
* Modification and distribution is permitted under certain conditions.  *
* IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.       *
*************************************************************************

-> Check visible clock (LLMJVM_IMPL_getCurrentTime validation)...
1
2
3
4
5
6
7
8
9
10

-> Check schedule request and wakeup (LLMJVM_IMPL_scheduleRequest and LLMJVM_IMPL_wakeupVM validation)...
Waiting for 5s...
...done

-> Check FPU (soft/hard FP option)...
In BSP, write and compile the following functions:
--------------------
#include "sni.h"
jfloat Java_com_is2t_microjvm_test_MJVMPortValidation_testFPU__FF (jfloat a, jfloat b) {return a * b;}
jdouble Java_com_is2t_microjvm_test_MJVMPortValidation_testFPU__DD (jdouble a, jdouble b) {return a * b;}
--------------------

-> Check isInReadOnlyMemory (LLBSP_IMPL_isInReadOnlyMemory validation)...
Test synchronize on literal string
Test synchronize on class
Test multiple synchronize

-> Check monotonic time (LLMJVM_IMPL_getCurrentTime, LLMJVM_IMPL_setApplicationTime validation)...
Waiting for 5s...
...done

-> Check Java round robin (LLMJVM_IMPL_scheduleRequest validation)...
Task 3is waiting for start...
Task 2is waiting for start...
Task 1is waiting for start...
Task 0is waiting for start...
Starting tasks...
Task 3 starts.
Task 2 starts.
Task 1 starts.
Task 0 starts.
...done. Stopping tasks...
Task 0 ends.
Task 1 ends.
Task 2 ends.
Task 3 ends.
...done.
MAX DELTA = 21875, at 991175 loops
Error : com.is2t.microjvm.test.MJVMPortValidation deltaPer10000=50
 ( == false ) , expected true
@ASSERTIONS_OK:17#
@ASSERTIONS_NOK:1#
com.is2t.microjvm.test.MJVMPortValidation FAILED
VM END (exit code = 0)
```

