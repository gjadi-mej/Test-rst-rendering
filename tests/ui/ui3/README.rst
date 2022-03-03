.. ReStructuredText
.. Copyright 2021-2022 MicroEJ Corp.  MicroEJ Corp. All rights reserved.
.. Use of this source code is governed by a BSD-style license that can be found with this software.

***********************************
Graphical User Interface Test Suite
***********************************

Overview
========

It contains sources and projects to check drivers and implementation of LLAPI ``LLUI_DISPLAY_IMPL``.

.. note:: 

   These tests only concern the MicroEJ Platforms made against the MicroEJ UI Packs 13.0.0 and higher.
   For the older MicroEJ UI packs, see `UI2 Readme <../ui2/README.rst>`_.

All tests can be run in one step: all tests will be executed one by one
and are run in a specific order, *next one* expects *previous one* is
passed.

For each test, its configuration and its results are described in a
dedicated section. See `Quick Start`_ section which resume how to configure the
tests, how to launch them and the expected results.

Additionally, the `Tool-Java-Touch <https://github.com/MicroEJ/Tool-Java-Touch>`_ project
allows to test the correct behavior of MicroUI in a Java application. 

Dependencies
============

- Follow the `main Readme <../../../README.rst>`_.
- Follow the `CORE Readme <../../core/README.rst>`_.

Quick Start
===========

Configuration
-------------

#. Follow the configuration of the `CORE Test Suite <../../core/README.rst>`_.
#. In the MicroEJ SDK, import the MicroEJ project ``java-testsuite-runner-ui3`` from the folder ``tests/ui/ui3``.
#. Build this MicroEJ Application against the MicroEJ Platform to qualify.
#. Build the BSP and link it with the MicroEJ Platform runtime library and MicroEJ Application.

Expected Results
----------------

   ..LCD width = 480
   LCD height = 272
   .LCD memory width = 480
   LCD memory height = 272
   .LCD BPP = 16
   .LCD back buffer is [0xc003fc00, 0xc007f800[
   Try to write and verify something in this buffer...
   ...Refresh the LCD content with black and white data. Ensure about the tearing effect..Retrieve the LCD framerate...
   Retrieve the maximal drawing time (this will take several seconds)...
   
   LCD framerate time is 17.528000 ms (57.051579 Hz)
   The copy time is 7.708000 ms
   To have an animation at 57.051579 Hz, the drawing time cannot be higher than 9.820000 ms.
   To have an animation at 28.525789 Hz, the drawing time cannot be higher than 27.348000 ms.
   To have an animation at 19.017193 Hz, the drawing time cannot be higher than 44.875999 ms.
   
   OK (9 tests)
   
MicroEJ UI Validation
=====================

This MicroEJ Application validates the LLAPI ``LLUI_DISPLAY_impl.h`` implementation executing several tests. 
Two first tests check the LCD synchronization, and require an human check to be sure the time is correct.

**Configuration**

In the MicroEJ SDK, import the MicroEJ project `java-testsuite-runner-ui3`` <./java-testsuite-runner-ui3/>`_ from the folder ``tests/ui/ui3``.
Follow the MicroEJ Core Validation `README <./java-testsuite-runner-ui3/README.rst>`_ to build and link this MicroEJ Application against the MicroEJ Platform to qualify.

**Expected results**

No error must be thrown when executing this test. A typical execution trace is described in the MicroEJ UI Validation `README <./java-testsuite-runner-ui3/README.rst>`_.



