
Platform Test Suites
====================

The `Platform Test Suites <https://docs.microej.com/en/latest/PlatformDeveloperGuide/platformQualification.html#platform-test-suite>`_ validate the Abstraction Layer that implements the Low Level APIs of a Foundation Libraries by automatically running Java tests on the device.

Setup
-----

The Platform Test Suites require a minimal configuration:

- MicroEJ SDK version ``5.1.1`` or higher.
- A MicroEJ Platform imported in the workspace, which has been built using `Platform Configuration Additions <framework/platform/README.rst>`_ version ``1.0.0`` or higher.
- A device connected to the PC both for programming and to get output traces. See Platform specific documentation for setup. 
- If the Platform requires output traces redirection (e.g. when your device dumps the standard output on a serial port), start the
  `Serial to Socket Transmitter <https://docs.microej.com/en/latest/ApplicationDeveloperGuide/serialToSocketTransmitter.html>`_ tool.

Troubleshooting
---------------

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
   Copyright 2019-2022 MicroEJ Corp. All rights reserved.
   Use of this source code is governed by a BSD-style license that can be found with this software.
