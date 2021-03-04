Build and Run Scripts Examples
==============================

This directory contains examples of build scripts for several toolchains and run scripts for several programming tools.

Overview
--------

Within each directory, the following scripts are available:

- ``build.XXX`` compiles and links the BSP to produce a MicroEJ
  Firmware.
- ``run.XXX`` flash the MicroEJ Firmware onto the device and reset the
  device.
- ``set_project_env.XXX`` checks the environment settings and set
  required environment variables.

Both ``build.XXX`` and ``run.XXX`` load the ``set_project_env.XXX``
script to ensure the environment is properly set up.

The behavior of ``build.XXX`` MUST follow the
specification described in `BSP Build Script File
<https://docs.microej.com/en/latest/PlatformDeveloperGuide/platformCreation.html#build-script-file>`_.

The behavior of ``run.XXX`` MUST follow the
specification described in `BSP Run Script File
<https://docs.microej.com/en/latest/PlatformDeveloperGuide/platformCreation.html#run-script-file>`_.

Usage
-----

Add the build scripts to the BSP.

General recommendation for build scripts
----------------------------------------

In addition to the specification of the build scripts, here some
general recommendation for the build scripts:

- Provide sensible default (e.g. default path for the toolchain).
- Allow the user to override the default settings with global
  environment variables and with a local script (see
  ``set_local_env.XXX.tpl``).

Test Scripts
------------

After developing a new script or modifying existing scripts for you needs, check the script works using the following tests sequence:

#. Initialization
   
   - Create a temporary directory which contains spaces and accented characters (e.g. ``c:\tmp\my rép``)
   - Create a ``c:\tmp\my rép\bsp`` and ``c:\tmp\my rép\test`` directory
   - Copy the BSP (including build and run scripts) into ``c:\tmp\my rép\bsp`` directory 
   - Open a terminal
   - Change current directory to ``c:\tmp\my rép\test``

#. Test Build
   
   - Launch ``c:\tmp\my rép\bsp\[path_to_build_script]\build.bat``
   - After successful build, check the ``c:\tmp\my rép\test\application.out`` exists
   
#. Test Build Overwrite
   
   - Touch the ``c:\tmp\my rép\test\application.out``
   - Launch ``c:\tmp\my rép\bsp\[path_to_build_script]\build.bat``
   - After successful build, check the ``c:\tmp\my rép\test\application.out`` date has been modified

#. Test Run

   - Launch ``c:\tmp\my rép\bsp\[path_to_build_script]\run.bat``
   - Check the executable has been programmed and started on device

.. ReStructuredText
.. Copyright 2020-2021 MicroEJ Corp. All rights reserved.
.. Use of this source code is governed by a BSD-style license that can be found with this software.
