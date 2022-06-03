..
    Copyright 2020-2022 MicroEJ Corp. All rights reserved.
    Use of this source code is governed by a BSD-style license that can be found with this software.
..

*********************
Filesystem Test Suite
*********************

This folder contains a ready-to-use project for testing `File System <https://docs.microej.com/en/latest/PlatformDeveloperGuide/fs.html>`_ implementations on a device.
This Test Suite will typically test file and directory creation, access permissions, and file content read/write...

Specifications
--------------

- Tested Foundation Library: `FS <https://repository.microej.com/modules/ej/api/fs/>`_
- Test Suite Module: `com.microej.pack.fs#fs-testsuite <https://repository.microej.com/modules/com/microej/pack/fs/fs-testsuite/>`_

Set the FS Test Suite module version in the `module.ivy
<java-testsuite-runner-fs/module.ivy>`_ to match the pack version of the platform
tested.

Please refer to `Platform Qualification Test Suite Versioning
<https://docs.microej.com/en/latest/PlatformDeveloperGuide/platformQualification.html#test-suite-versioning>`_
to determine the FS Test Suite module version.

Requirements
-------------

- See Platform Test Suites `documentation <../README.rst>`_.

Usage
-----

- In MicroEJ SDK, import the ``java-testsuite-runner-fs`` project in your workspace.
- Follow the configuration and execution steps described in Platform Test Suites `documentation <../README.rst>`_.

Troubleshooting
---------------

See Platform Test Suites `documentation <../README.rst>`_.

Source Code
-----------

The source code of the tests is available in the module.

1. Download the Test Suite Module `com.microej.pack.fs#fs-testsuite <https://repository.microej.com/modules/com/microej/pack/fs/fs-testsuite/>`_ (refer to `Platform Qualification Test Suite Versioning <https://docs.microej.com/en/latest/PlatformDeveloperGuide/platformQualification.html#test-suite-versioning>`_ to determine the FS Test Suite module version).
2. Unzip the ``RIP`` (it is zip file) of the Test Suite ``fs-testsuite-[version].rip``.
3. Open the Java archive ``JAR`` (it is a zip file) ``/content/javaLibs/fs-testsuite-[version].jar/``.
4. Open the desired test, for instance : ``/com/microej/fs/tests/constructors/TestFileInputStream.java``.
