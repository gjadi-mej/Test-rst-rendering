..
    Copyright 2020 MicroEJ Corp. All rights reserved.
    Use of this source code is governed by a BSD-style license that can be found with this software.
..

**********************************
MicroEJ FS Testsuite
**********************************

This folder is a part of a project which gathers the platform qualification tools. It contains a Java project which tests file and directory creation, access permissions, and file content read/write.

=============
Prerequisites
=============

Before starting the test, make sure you have the following requirements:

- MicroEJ SDK version 5.1.1 or later
- A MicroEJ Platform which has been built using the `Platform Configuration Additions <framework/platform/README.rst>`_.

A platform is composed of two parts: a platform project (like: ``lpcxpresso_freertos-platform``) and bsp project (like: ``lpcxpresso_freertos-bsp``).

=======================
Testsuite configuration
=======================

- Load the ``java/java-testsuite-fs`` project in your MicroEJ SDK
- Copy/Paste the ``config.properties.tpl``, rename it to
  ``config.properties``.  The platform may provide a
  ``config.properties`` and ``microej-testsuite-common.properties``
  files.  Check the platform documentation and the files under
  ``PLATFORM-configuration/testsuites/fs/``.
- Open the ``config.properties``
- Set ``target.platform.dir``: This is the platform path, which is the
  parent folder of the ``release.properties`` file.  This property is
  **mandatory**.
- Depending on the `BSP Connection
  <https://docs.microej.com/en/latest/PlatformDeveloperGuide/platformCreation.html#bsp-connection>`__
  of the MicroEJ Platform, configure the following properties (refer
  the comment in the configuration file):

  - ``microej.testsuite.properties.deploy.dir.microejapp``
  - ``microej.testsuite.properties.deploy.dir.microejlib``
  - ``microej.testsuite.properties.deploy.dir.microejinc``
  - ``microej.testsuite.properties.deploy.bsp.microejscript``
  
If your board dump it trace on a serial port, you need to run the serial to socket transmitter tool.

- In the MicroEJ SDK go to ``Run > Run Configurations...``
- Right Click on ``MicroEJ Tool`` and click on ``New``
- Select your platform in the ``Target > Platform`` option
- Select ``Serial To Socket Transmitter`` in the ``Execution > Settings`` option
- Go to the ``Configuration`` tab and set the ``Serial options``.
- In the ``config.properties`` file, uncomment the following properties:

	- ``microej.testsuite.properties.testsuite.trace.ip``
	- ``microej.testsuite.properties.testsuite.trace.port`` (use the same value you set in the Serial Options)

- Click on ``Run``

=================
Run the testsuite
=================

Right click on the ``java-testsuite-fs`` project and click on ``Build Module``.
