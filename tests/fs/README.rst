..
    Copyright 2020-2021 MicroEJ Corp. All rights reserved.
    Use of this source code is governed by a BSD-style license that can be found with this software.
..

*********************
Filesystem Test Suite
*********************

This folder contains a ready-to-use project for testing `File System <https://docs.microej.com/en/latest/PlatformDeveloperGuide/fs.html>`_ implementations on a device.
This test suite will typically test file and directory creation, access permissions, and file content read/write...

Specifications
--------------

- Tested Foundation Library: `FS 2.0 <https://repository.microej.com/artifacts/ej/api/fs/>`_ 
- Test Suite Module: `com.microej.pack.fs.fs-testsuite <https://repository.microej.com/artifacts/com/microej/pack/fs/fs-testsuite/>`_

Prerequisites
-------------

Before starting the test suite, make sure you have the following requirements:

- MicroEJ SDK version ``5.1.1`` or higher.
- A MicroEJ Platform imported in the workspace, which has been built using `Platform Configuration Additions <framework/platform/README.rst>`_ version ``1.0.0`` or higher.
- A device connected to the PC both for programming and to get output traces. See Platform specific documentation for setup. 
- If the Platform requires output traces redirection (e.g. when your device dumps the standard output on a serial port), start the
  `Serial to Socket Transmitter <https://docs.microej.com/en/latest/ApplicationDeveloperGuide/serialToSocketTransmitter.html>`_ tool.

Test Suite Configuration
------------------------

- In MicroEJ SDK, import the ``java/java-testsuite-fs`` project in your workspace.
- Create the local ``config.properties`` file. The Platform may provide a pre-configured ``config.properties`` file under
  ``[platform]-configuration/testsuites/fs/`` folder. By default, copy the ``config.properties.tpl`` to ``config.properties``.
- Open the ``config.properties`` file.
- Fill the options marked as ``[required]``, particularly:

  - Target Platform: set the absolute path to the Platform being tested (the parent folder of the ``release.properties`` file),
  - `BSP Connection <https://docs.microej.com/en/latest/PlatformDeveloperGuide/platformCreation.html#bsp-connection>`_: check the Platform specific documentation to get the kind of configured BSP connection.
  - Trace Redirection (if the Platform requires output traces redirection): set options in sync with the Serial to Socket Transmitter options.
- Check `Application Options <https://docs.microej.com/en/m0078ddg-26-fix_limitation_chapter/ApplicationDeveloperGuide/applicationOptions.html>`_ declared in ``validation/microej-testsuite-common.properties``. 
  By default, options are initialized with suitable values to successfully execute the whole test suite and should not be changed. 
  However in some particular cases, you can adjust test suite specific options or memory settings.

Test Suite Execution
--------------------

Right-click on the ``java-testsuite-fs`` project and click on ``Build Module``.

Please refer to `Platform Qualification documentation <https://docs.microej.com/en/m0078ddg-26-fix_limitation_chapter/PlatformDeveloperGuide/platformQualification.html>`_ to know more about test suites and how to get reports.



