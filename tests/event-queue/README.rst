..
    Copyright 2023 MicroEJ Corp. All rights reserved.
    Use of this source code is governed by a BSD-style license that can be found with this software.
..

**********************
Event Queue Test Suite
**********************

This folder contains a ready-to-use project for testing `Event Queue <https://docs.microej.com/en/latest/VEEPortingGuide/eventQueue.html>`_ implementations on a device.
This Test Suite will create some listeners and send basic/extended events with different primitive types of data.

Specifications
--------------

- Tested Foundation Library: `Event Queue <https://repository.microej.com/modules/ej/api/event/>`_
- Test Suite Module: `ej.api.event#event-testsuite <https://repository.microej.com/modules/ej/api/event/event-testsuite/>`_

Set the Event Queue Test Suite module version in the `module.ivy
<java-testsuite-runner-event-queue/module.ivy>`_ to match the pack version of the VEE Port
tested.

Please refer to `Platform Qualification Test Suite Versioning
<https://docs.microej.com/en/latest/PlatformDeveloperGuide/platformQualification.html#test-suite-versioning>`_
to determine the Event Queue Test Suite module version.

Requirements
-------------

- Read VEE Port Test Suites `documentation <../README.rst>`_.
- Read External resource loader Test Suites `documentation <./java-testsuite-runner-event-queue/README.md>`_.

Usage
-----

- In MicroEJ SDK, import the ``java-testsuite-runner-event-queue`` project in your workspace.
- Follow the configuration and execution steps described in VEE Port Test Suites `documentation <../README.rst>`_.

Test Suite Source Code Navigation
---------------------------------

- See VEE Port Test Suites `documentation <../README.rst>`_.

Troubleshooting
---------------

See Vee Port Test Suites `documentation <../README.rst>`_.
