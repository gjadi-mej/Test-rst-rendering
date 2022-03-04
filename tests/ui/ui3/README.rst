.. ReStructuredText
.. Copyright 2021-2022 MicroEJ Corp.  MicroEJ Corp. All rights reserved.
.. Use of this source code is governed by a BSD-style license that can be found with this software.

***********************************
Graphical User Interface Test Suite
***********************************

Overview
========

This folder contains sources and projects to check drivers and implementation of LLAPI ``LLUI_DISPLAY_IMPL``.

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

- Follow the `main Readme <../../README.rst>`_.
- Follow the `CORE Readme <../../core/README.rst>`_.

Quick Start
===========

#. Follow the configuration of the `CORE Test Suite <../../core/README.rst>`_.
#. In the MicroEJ SDK, import the MicroEJ project ``java-testsuite-runner-ui3`` from the folder ``tests/ui/ui3``.
#. Build this MicroEJ Application against the MicroEJ Platform to qualify.
#. Build the BSP and link it with the MicroEJ Platform runtime library and MicroEJ Application.

Expected results
================

No error must be thrown when executing this test. A typical execution trace is described in the MicroEJ UI Validation `README <./java-testsuite-runner-ui3/README.rst>`_.



