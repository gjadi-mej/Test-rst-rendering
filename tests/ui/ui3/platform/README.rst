..
    Copyright 2021 MicroEJ Corp. All rights reserved.
    Use of this source code is governed by a BSD-style license that can be found with this software.
..

*******************
Platform Test Suite
*******************

This folder contains a ready-to-use project for testing `MicroEJ UI <https://docs.microej.com/en/latest/PlatformDeveloperGuide/ui.html>`_ implementations on a device.

Prerequisites
-------------

Consult `main Readme <../../../README.rst>`_ (chapter *Platform Test Suites*).

Configuration
-------------

- In MicroEJ SDK, import the ``java-testsuite-ui`` project in your workspace.
- Create the local ``config.properties`` file. Copy the ``config.properties.tpl`` to ``config.properties``.
- Open the ``config.properties`` file.
- Fill the options marked as ``[required]``, particularly:

  - Target Platform: set ``target.platform.dir`` to the absolute path of the Platform being tested (the parent folder of the ``release.properties`` file and the platform sources, see `Setup a Platform for Tests <https://docs.microej.com/en/latest/ApplicationDeveloperGuide/testsuite.html#setup-a-platform-for-tests>`__),
  - `BSP Connection <https://docs.microej.com/en/latest/PlatformDeveloperGuide/platformCreation.html#bsp-connection>`_: check the Platform specific documentation to get the kind of configured BSP connection.
  - Trace Redirection (if the Platform requires output traces redirection): set options in sync with the Serial to Socket Transmitter options.

- Check `Application Options <https://docs.microej.com/en/latest/ApplicationDeveloperGuide/applicationOptions.html>`_ declared in ``validation/microej-testsuite-common.properties``. 
  By default, options are initialized with suitable values to successfully execute the whole test suite and should not be changed. 
  However in some particular cases, you can adjust test suite specific options or memory settings.

Execution
---------

Right-click on the ``java-testsuite-ui`` project and click on ``Build Module``.

Please refer to `Platform Qualification documentation <https://docs.microej.com/en/latest/PlatformDeveloperGuide/platformQualification.html>`_ to know more about test suites and how to get reports.

Troubleshooting
---------------

Consult `main Readme <../../../README.rst>`_ (chapter *Platform Test Suites*).
