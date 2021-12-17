Description
===========

The Platform Qualification Tools (PQT) project provides the tools required to validate each component of a MicroEJ Platform.
After porting or adding a feature to a MicroEJ Platform, it is necessary to validate its integration.

Clone this repository with ``git clone --recursive https://github.com/MicroEJ/PlatformQualificationTools``.

Test Suites Available
=====================

Core Engine Test Suite
----------------------

The CORE Test Suite contains a C Test Suite, a Java Test Suite and a Platform Test Suite. It is the most basic Test Suite to run.
It ensures MicroEJ Application will run correctly.

All other Test Suites assume the CORE Test Suite is validated.

See `CORE Readme <tests/core/README.rst>`_

Graphical User Interface Test Suite
-----------------------------------

The UI Test Suite is a C Test Suite, a Java Test Suite and a Platform Test Suite. 
It checks the integration of the ``LLUI*`` API and the tearing signal usage.
It also provides indication about the minimum draw time allowed to display animations at a given framerate.

See `UI Readme <tests/ui/README.rst>`_

Filesystem Test Suite
---------------------

The FS Test Suite is a Java Test Suite. It checks the integration of the ``LLFS*`` APIs over a C File System library.

See `FS Readme <tests/fs/README.rst>`_


Platform Qualification Tools Overview
=====================================

The Platform Qualification Tools (PQT) contains:

- a ``framework/`` folder with scripts and frameworks used by the tests
- a ``tests/`` folder with one sub-folder per Test Suite (e.g. ``tests/core/`` for the CORE Test Suite, etc.)

Each Test Suite sub-folder contains a ``README.rst`` that explain how to use the Test Suite in details.

The following sections give an overview of the Platform Qualification Tools (PQT).

Framework
---------

The ``framework/`` folder contains the infrastructure required to build and run the tests.

C infrastructure
----------------

The ``framework/c/`` folders contains the following:

- Embedded Unit (embUnit) is a unit testing framework used for C tests.
- CoreMark is a processor benchmark used by the CORE Test Suite.
- utils provides several utilities used by various C tests

Platform Configuration Additions
--------------------------------

The ``framework/platform/content`` folder contains the MicroEJ Platform Configuration Additions.
See the `Platform Configuration Additions README <framework/platform/README.rst>`_ for more information.
For licenses management, please refer to `License <https://docs.microej.com/en/latest/overview/licenses.html>`_ .

Build and Run Scripts Examples
------------------------------

The ``framework/platform/scripts`` folder contains Build and Run Scripts examples for several third-party toolchains.
See the ``Build and Run Scripts Examples README <framework/platform/scripts/README.rst`_ for more information.

Test Suites
-----------

The Platform Qualification Tools (PQT) provides three kinds of Test Suite:

- C Test Suites that must be added to the BSP
- Java Test Suites that are launched as standard MicroEJ Application
- Platform Test Suites to launch automatically some tests on a device

A Test Suite validates a particular component of a MicroEJ Platform.
The CORE Test Suite is applicable to every MicroEJ Platform.
The other Test Suites depends on the capabilities provided by the MicroEJ Platform to validate.

A detailed explanation how to use each Test Suite is provided in the ``README.rst`` present in each sub-folder.
For example, for the CORE Test Suite, refer to the `CORE Readme <tests/core/README.rst>`_.

C Test Suites
-------------

The C Test Suites validate that the hardware and RTOS (if applicable) are properly integrated in the BSP.

The C Test Suites uses Embunit framework. They have to be launched just
before MicroEJ Application (just before the call to ``microjvm_main()``).
At this moment, the BSP is fully initialized and the OS is started.

The C Test Suites perform some basic checks which ensures MicroEJ Application
will run. Unless specified otherwise, C Test Suites are linked with a MicroEJ Application
(``microejapp.o``) and a MicroEJ runtime library (``microejruntime.a``).

The C Test Suites often require some additional data (some specific functions have to
be implemented in addition of LLAPI implementation functions).

Java Test Suites
----------------

The Java Test Suites validate the Foundation Libraries integration.

The Java Test Suites verify the integration of the MicroEJ Platform over the
BSP. No specific unit test framework is used, each test describes how it
works.

Platform Test Suites
--------------------

The `Platform Test Suites <https://docs.microej.com/en/latest/PlatformDeveloperGuide/platformQualification.html#platform-test-suite>`_ validate the Abstraction Layer that implements the Low Level APIs of a Foundation Libraries by automatically running Java tests on the device.

The Platform Test Suites require a minimal configuration:

- MicroEJ SDK version ``5.1.1`` or higher.
- A MicroEJ Platform imported in the workspace, which has been built using `Platform Configuration Additions <framework/platform/README.rst>`_ version ``1.0.0`` or higher.
- A device connected to the PC both for programming and to get output traces. See Platform specific documentation for setup. 
- If the Platform requires output traces redirection (e.g. when your device dumps the standard output on a serial port), start the
  `Serial to Socket Transmitter <https://docs.microej.com/en/latest/ApplicationDeveloperGuide/serialToSocketTransmitter.html>`_ tool.

The next chapters describe the troubleshootings you may encounter when executing a Platform Test Suite.

No activity on input stream
~~~~~~~~~~~~~~~~~~~~~~~~~~~

The following error indicates that no output have been seen by the
Serial To Socket.

- Ensure that the COM port configured for the Serial To Socket is
  correct.
- Check the Platform documentation on how to connect to the UART
  output for the test suites.

.. code-block::

   [testsuite:javaTestsuite] [traceAnalyzer:socketTraceAnalyzer] 1 : TraceAnalyzer ERROR :
   [testsuite:javaTestsuite] [traceAnalyzer:socketTraceAnalyzer] [M3] - No activity on input stream since 75 s.
   [testsuite:javaTestsuite] [traceAnalyzer:socketTraceAnalyzer] 
   [testsuite:javaTestsuite] [traceAnalyzer:socketTraceAnalyzer] 2 : TraceAnalyzer ERROR :
   [testsuite:javaTestsuite] [traceAnalyzer:socketTraceAnalyzer] [M5] - No encountered success/failure tag.
   [testsuite:javaTestsuite] [traceAnalyzer:socketTraceAnalyzer] 
   [testsuite:javaTestsuite] BUILD FAILED
   [testsuite:javaTestsuite] C:\Program Files\MicroEJ\MicroEJ-SDK-20.12\rcp\configuration\org.eclipse.osgi\11\data\repositories\microej-build-repository\com\is2t\easyant\plugins\microej-testsuite\3.4.0\microej-testsuite-harness-jpf-emb-3.4.0.xml:85: TraceAnalyzer ends with errors.

Could not open port 'COMxxx'
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The following error indicates that the COM port can not be opened.

- Ensure that the COM port configured for the Serial To Socket is
  correct.
- Only one application may open a given COM port.  Ensure no other
  application are using this COM port.
- COM port may changed when the device is unplugged.  Ensure that the
  COM port configured for the Serial To Socket is correct.

.. code-block::

   serial.serialutil.SerialException: could not open port 'COM7': FileNotFoundError(2, 'The system cannot find the file specified.', None, 2)

No loaded Platform
~~~~~~~~~~~~~~~~~~

.. code-block::

   No loaded Platform.
   Possible options to load a platform are: 
   - (1) Set the property `platform-loader.target.platform.file` to a Platform file absolute path.
   - (2) Set the property `platform-loader.target.platform.dir` to a Platform directory absolute path.
   - (3) Declare a dependency in `module.ivy`.
   - (4) Copy/Paste a Platform file into the folder defined by the property `platform-loader.target.platform.dropins` (by default its value is `dropins`).
   A Platform declared using (1) or (2) is loaded prior to (3) or (4).

Ensure the property ``target.platform.dir`` is set in
``config.properties`` and points to the Platform source folder.

Could not connect to localhost:5555
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block::

   [testsuite:javaTestsuite] [traceAnalyzer:socketTraceAnalyzer] 1 : SocketTraceAnalyzerError ERROR :
   [testsuite:javaTestsuite] [traceAnalyzer:socketTraceAnalyzer] [M1] - Could not connect to localhost:5555
   [testsuite:javaTestsuite] [traceAnalyzer:socketTraceAnalyzer] 
   [testsuite:javaTestsuite] BUILD FAILED

- Ensure the Serial To Socket is started and configured to listen on
  the port 5555.  The host and port properties used by the Test Suite
  Engine are configured in ``config.properties``.

The test suite runs but some tests are failing
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- Ensure the Low Level Implementations tested by the test suite are
  correctly implemented.
- Check your Platform documentation on test suites.  The Platform may
  provide specific ``config.properties`` and
  ``microej-testsuite-common.properties``.

..
   Copyright 2019-2021 MicroEJ Corp. All rights reserved.
   Use of this source code is governed by a BSD-style license that can be found with this software.
