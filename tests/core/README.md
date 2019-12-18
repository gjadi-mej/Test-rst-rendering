
# Overview

This folder is a part of a project which gathers the platform qualification tools. It contains sources and projects to check drivers and implementation of print, time base, RAM, Core, and micro JVM.

All tests can be run in one step: all tests will be executed one by one and are run in a specific order, _next one_ expects _previous one_ is passed.

For each test, its configuration and its results are described in a dedicated section. See #SumUp chapter which resume how to configure the tests, how to launch them and the expected results.

# Dependencies

* Follow the main readme file
* EEMBC Coremark

# Tests Description

## Print: _t_core_print.c_

An implementation of `print` is required by MicroEJ platform to debug the Java exceptions. Furthermore this implementation is also required to check this qualification bundle.

**Configuration**

The default implementation (the one implemented in the `weak` functions, see `u_print.c`) calls `stdio`'s `printf` functions. Write your own functions if necessary.

**Expected results**

A message is just printed:

```
Create VM
VM START
*****************************************************************************************************
*                                  LLMJVM Port Validation - 2.4.0                                   *
*****************************************************************************************************
* Copyright 2013-2019 MicroEJ Corp. All rights reserved.                                            *
* This library is provided in source code for use, modification and test, subject to license terms. *
* Any modification of the source code will break MicroEJ Corp. warranties on the whole library.     *
*****************************************************************************************************

-> Check visible clock (LLMJVM_IMPL_getCurrentTime validation)...
Property 'MJVMPortValidation.clock.seconds' is not set (default to '10' seconds)
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

-> Check monotonic time (LLMJVM_IMPL_getCurrentTime, LLMJVM_IMPL_setApplicationTime validation)...
Waiting for 5s...
...done

-> Check FPU (soft/hard FP option)...

-> Check isInReadOnlyMemory (LLBSP_IMPL_isInReadOnlyMemory validation)...
Test synchronize on literal string
Test synchronize on class
Test multiple synchronize

-> Check Java round robin (LLMJVM_IMPL_scheduleRequest validation)...
For a best resut, please disable all the C native tasks except the MicroEJ task.
Task 3 is waiting for start...
Task 2 is waiting for start...
Task 1 is waiting for start...
Task 0 is waiting for start...
Starting tasks and wait for 10 seconds...
Task 1 ends.
Task 2 ends.
Task 3 ends.
Task 0 ends.
...done.
@ASSERTIONS_OK:21#
@ASSERTIONS_NOK:0#
com.is2t.microjvm.test.MJVMPortValidation PASSED
VM END (exit code = 0)
```


---
_Copyright 2019 MicroEJ Corp. All rights reserved._
_For demonstration purpose only._
_MicroEJ Corp. PROPRIETARY/CONFIDENTIAL. Use is subject to license terms._
