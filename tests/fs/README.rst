..
    Copyright 2019 MicroEJ Corp. All rights reserved.
    MicroEJ Corp. PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
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

A platform is composed of two parts: a platform project (like: lpcxpresso_freertos-platform) and bsp project (like: lpcxpresso_freertos-bsp).

=============
Testsuite configuration
=============

- Load the ``java/java-testsuite-fs`` project in your MicroEJ SDK
- Copy/Paste the ``config.properties.template``, rename it to ``config.properties``
- Open the ``config.properties``, uncomment the following properties, and set the right value for each of them:

	- target.platform.dir: This is the platform path, which is the parent folder of the release.properties file
	- microej.testsuite.properties.deploy.dir.microejapp: The is the folder where the microejapp.o file should be copied, it is usually a subfolder of the bsp project.
	- microej.testsuite.properties.external.scripts.dir: The is the path where the ``build.bat`` and ``run.bat`` scripts are.

If your board dump it trace on a serial port, you need to run the serial to socket transmitter tool.

- In the McioEJ SDK go to ``Run > Run Configurations...``
- Right Click on ``MicroEJ Tool`` and click on ``New``
- Select your platform in the ``Target > Platform`` option
- Select ``Serial To Socket Transmitter`` in the ``Execution > Settings`` option
- Go to the ``Configuration`` tab and set the ``Serial options``.
- In the ``config.properties`` file, uncomment the following properties:

	- microej.testsuite.properties.testsuite.trace.ip
	- microej.testsuite.properties.testsuite.trace.port (use the same value you set in the Serial Options)

- Click on ``Run``

=============
Run the testsuite
=============
Right click on the ``java-testsutie-fs`` project and click on ``Build Module``.