..
	Copyright 2020-2022 MicroEJ Corp. All rights reserved.
	Use of this source code is governed by a BSD-style license that can be found with this software.
..

**********************************
MicroEJ NET Testsuite
**********************************

This folder contains a ready-to-use project for testing the `Network Core Engine <https://docs.microej.com/en/latest/PlatformDeveloperGuide/networkCoreEngine.html>`_ implementation on a device.
This test suite will typically create TCP sockets, UDP sockets, test client side and server side...

==============
Specifications
==============

- Tested Foundation Library: `NET <https://repository.microej.com/modules/ej/api/net/>`_
- Test Suite Module:  `com.microej.pack.net#net-testsuite <https://repository.microej.com/modules/com/microej/pack/net/net-testsuite/>`_

Update the NET Test Suite module version in the `module.ivy
<java/java-testsuite-net/module.ivy>`_ to match the requirement of the platform
tested.

Please refer to `Platform Qualification Test Suite Versioning
<https://docs.microej.com/en/latest/PlatformDeveloperGuide/platformQualification.html#test-suite-versioning>`_
to determine the NET Test Suite module version.

=============
Prerequisites
=============

Before starting the test suite, make sure you have the following requirements:

- MicroEJ SDK version ``5.1.1`` or higher.
- A MicroEJ Platform imported in the workspace, which has been built using `Platform Configuration Additions <../../framework/platform/README.rst>`_ version ``1.0.0`` or higher.
- A device connected to the PC both for programming and to get output traces. See Platform specific documentation for setup. 
- If the Platform requires output traces redirection (e.g. when your device dumps the standard output on a serial port), start the
  `Serial to Socket Transmitter <https://docs.microej.com/en/latest/ApplicationDeveloperGuide/serialToSocketTransmitter.html>`_ tool.

========================
Test Suite Configuration
========================

- In MicroEJ SDK, import the ``java/java-testsuite-net`` project in your workspace.
- Create the local ``config.properties`` file. The Platform may provide a pre-configured ``config.properties`` file under
  ``[platform]-configuration/testsuites/net/`` folder. By default, copy the ``config.properties.tpl`` to ``config.properties``.
- Open the ``config.properties`` file.
- Fill the options marked as ``[required]``, particularly:

  - Target Platform: set ``target.platform.dir`` to the absolute path of the Platform being tested (the parent folder of the ``release.properties`` file and the platform sources, see `Setup a Platform for Tests <https://docs.microej.com/en/latest/ApplicationDeveloperGuide/testsuite.html#setup-a-platform-for-tests>`__),
  - `BSP Connection <https://docs.microej.com/en/latest/PlatformDeveloperGuide/platformCreation.html#bsp-connection>`_: check the Platform specific documentation to get the kind of configured BSP connection.
  - Trace Redirection (if the Platform requires output traces redirection): set options in sync with the Serial to Socket Transmitter options.

- Check `Application Options <https://docs.microej.com/en/latest/ApplicationDeveloperGuide/applicationOptions.html>`_ declared in ``validation/microej-testsuite-common.properties``. 
  By default, options are initialized with suitable values to successfully execute the whole test suite and should not be changed. 
  However in some particular cases, you can adjust test suite specific options or memory settings.

====================
Test Suite Execution
====================

Right-click on the ``java-testsuite-net`` project and click on ``Build Module``.

Please refer to `Platform Qualification documentation <https://docs.microej.com/en/latest/PlatformDeveloperGuide/platformQualification.html>`_ to know more about test suites and how to get reports.

=====================
Test Suite Properties
=====================

The NET test suite requires specific properties depending on the implementation and test environment.
All the properties described in this section are defined in the file `microej-testsuite-common.properties <./java/java-testsuite-net/validation/microej-testsuite-common.properties>`_
and prefixed by ``microej.java.property.``.

- Common properties:

  - ``testsuite.preferipv6`` (optional, false by default): set to true if the tests must use IPv6 by default.
  - ``init.service`` (optional, undefined by default): Name of a class that implements com.microej.tests.util.INetInit. If defined, during initialization, an instance of this class is created and the initialize() method is called.

- Properties to define if ``testsuite.preferipv6`` is ``false``:

  - ``wrong.machine.ipv4``: An invalid IPv4 address on the local network
  - ``remote.machine.ipv4``: IPv4 address of the testsuite server
  - ``netif.ipv4.name``: network interface name with an IPv4

- Properties to define if ``testsuite.preferipv6`` is ``true``:

  - ``wrong.machine.ipv6``: An invalid IPv6 address on the local network
  - ``remote.machine.ipv6``: IPv6 address of the testsuite server
  - ``netif.ipv6.name``: network interface name with an IPv6

- When testing a device with a dual-stack IPv6+IPv4, the following properties must be set:

  - ``remote.machine.ipv4``: see above
  - ``netif.ipv4.name``: see above
  - ``remote.machine.ipv6``: see above
  - ``netif.ipv6.name``: see above
