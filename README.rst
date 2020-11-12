..
    Copyright 2019-2020 MicroEJ Corp. All rights reserved.
	This library is provided in source code for use, modification and test, subject to license terms.
	Any modification of the source code will break MicroEJ Corp. warranties on the whole library.

.. |TARGET_NAME| replace:: ESP32-WROVER
.. |BOARDPRINTABLENAME| replace:: ESP32-WROVER-KIT v4.1
.. |BOARDREVISION| replace:: v4.1
.. |RI_NAME| replace:: ESP32 WROVER Platform Reference Implementation
.. |RI_VER| replace:: v1.6.0

.. |RCP| replace:: MicroEJ SDK
.. |GUIDE.INTERNAL.EMB| replace:: MicroEJ Platform
.. |GUIDE.INTERNAL.EMB.TITLE| replace:: MicroEJ Platform
.. |GUIDE_INTERNAL_STANDALONE| replace:: Standalone Application
.. |GUIDE.INTERNAL.SIM| replace:: MicroEJ Simulator
.. |GUIDE.INTERNAL.PLATFORM| replace:: MicroEJ Platform
.. |GUIDE.INTERNAL.XPF| replace:: MicroEJ Architecture
.. |CIDE.PRINTABLENAME| replace:: MicroEJ SDK
.. |RTOS.PRINTABLENAME RTOS| replace:: FreeRTOS RTOS
.. |GUIDE.INTERNAL.EMBS| replace:: MicroEJ Platforms
.. |DEPLOYTOOLPRINTABLENAME| replace:: Espressif Esptool
.. |MANUFACTURER| replace:: Espressif

=======================================
 Readme: MicroEJ ESP32-WROVER Platform 
=======================================

This project is used to build MicroEJ reference implementation platform for
ESP32-WROVER-KIT development board.

Clone the repository with ``git clone --recursive https://github.com/MicroEJ/ESP32-WROVER``.

Requirements
=============

- PC with Windows 10
- |RCP| environment (v20.10 or later, available `here <https://developer.microej.com/get-started/>`_)
- A |BOARDPRINTABLENAME| board

Board Technical Specifications
==============================

- Name: |BOARDPRINTABLENAME|
- Revision: |BOARDREVISION|
- MCU part number: ESP32-WROVER-B
- MCU revision: -
- MCU architecture: Xtensa LX6
- MCU max clock frequency: 240 MHz
- Internal flash size: 540 KB
- Internal RAM size: 520 KB
- External flash size: 4 MB
- External RAM size: 8 MB 
- Power supply: USB, External 5V

Here is a list of |BOARDPRINTABLENAME| usefull documentation links:

- Board documentation available `here <https://docs.espressif.com/projects/esp-idf/en/v3.3.4/hw-reference/modules-and-boards.html#esp-wrover-kit-v4-1>`__
- |MANUFACTURER| board Getting Started available `here <https://docs.espressif.com/projects/esp-idf/en/v3.3.4/get-started/get-started-wrover-kit.html>`__
- Board schematics available `here <https://dl.espressif.com/dl/schematics/ESP-WROVER-KIT_V4_1.pdf>`__
- MCU Technical Reference Manual available `here <https://www.espressif.com/sites/default/files/documentation/esp32_technical_reference_manual_en.pdf>`__
- MCU Datasheet available `here <https://espressif.com/sites/default/files/documentation/esp32_datasheet_en.pdf>`__
- MCU Errata available `here <https://espressif.com/sites/default/files/documentation/eco_and_workarounds_for_bugs_in_esp32_en.pdf>`__

Required Tools Installation Procedure
=====================================

Please setup the |MANUFACTURER| toolchain as described `here <https://docs.espressif.com/projects/esp-idf/en/v3.3.4/get-started/index.html#setup-toolchain>`__.

Validate the installation of the toolchain by executing the script
``{PLATFORM}-bsp/Projects/microej/scripts/build.bat`` on Windows
(``{PLATFORM}-bsp/Projects/microej/scripts/build.sh`` on Linux).

The build script expects the toolchain to be installed at a known
path.  If you installed it elsewhere, see `Advanced Customization of
BSP Build`_ for how to customize its path.


Board Usage
===========

Please refers to the |MANUFACTURER| documentation available `here <https://docs.espressif.com/projects/esp-idf/en/v3.3.4/get-started/get-started-wrover-kit.html>`__ for more details.

Powering
--------

The board can be powered using USB cable or exernal 5V power supply.

Please refers to the Espressif documentation available `here
<https://docs.espressif.com/projects/esp-idf/en/v3.3.4/get-started/get-started-wrover-kit.html>`__
for more details.

Programming
-----------

Please refers to `Deploy the Application`_ to have more information on how to deploy on a firmware on the |BOARDPRINTABLENAME| board.

|MANUFACTURER| build and flash documentation are also available `here
<https://docs.espressif.com/projects/esp-idf/en/v3.3.4/get-started/index.html#build-and-flash>`__
for more details.

Logs Output
-----------

MicroEJ platform uses the virtual UART from the |BOARDPRINTABLENAME| USB port. A COM port is automatically mounted when the board is plugged to a computer using USB cable. All board logs are available through this COM port.

The COM port uses the following parameters:

- Baudrate: 115200
- Data bits bits: 8
- Parity bits: None
- Stop bits: 1
- Flow control: None

When running a Testsuite, a secondary UART port is needed.  Please
refers to `Run a Testsuite`_ for a
detailed explanation.

Please refers to the |MANUFACTURER| documentation available `here
<https://docs.espressif.com/projects/esp-idf/en/v3.3.4/get-started/establish-serial-connection.html>`__
for more details.

Debugging
---------

A JTAG interface is also directly available through the USB interface.

Please refers to the |MANUFACTURER| documentation available `here
<https://docs.espressif.com/projects/esp-idf/en/v3.3.4/api-guides/jtag-debugging/index.html>`__
for more details.

Board Development Environment
=============================

Windows Toolchain
-----------------

- C/C++ toolchain name: esp32_win32_msys2_environment_and_toolchain_idf3-20200714
- C/C++ toolchain version: 20200714
- C/C++ toolchain download link: https://dl.espressif.com/dl/esp32_win32_msys2_environment_and_toolchain_idf3-20200714.zip

Please refers to the |MANUFACTURER| documentation available `here
<https://docs.espressif.com/projects/esp-idf/en/v3.3.4/get-started/windows-setup.html>`__
for more details.

Linux Toolchain
---------------

- C/C++ toolchain name: xtensa-esp32-elf-linux
- C/C++ toolchain version: 1.22.0-96-g2852398-5.2.0
- C/C++ toolchain download link for 64-bit Linux: https://dl.espressif.com/dl/xtensa-esp32-elf-linux64-1.22.0-96-g2852398-5.2.0.tar.gz
- C/C++ toolchain download link for 32-bit Linux: https://dl.espressif.com/dl/xtensa-esp32-elf-linux32-1.22.0-96-g2852398-5.2.0.tar.gz  

Please refers to the |MANUFACTURER| documentation available `here
<https://docs.espressif.com/projects/esp-idf/en/v3.3.4/get-started/linux-setup.html>`__
for more details.

Board Support Package
---------------------

- BSP provider: |MANUFACTURER| (``esp-idf``)
- BSP version: v3.3.4

Please refers to the |MANUFACTURER| ``esp-idf`` GitHub git repository
available `here
<https://github.com/espressif/esp-idf/releases/tag/v3.3.4>`__.

Third Party Software
--------------------

Third party softwares used in BSP can be found `here <https://github.com/espressif/esp-idf/tree/v3.3.4/components>`__. Here is a list of the most important ones:

- RTOS name / version: FreeRTOS V8.2.0
- TCP/IP stack name / version: esp_lwip 2.0.3
- Cryptographic stack name / version: Mbed TLS 2.16.5
- File System stack name / version: FatFS R0.13a
- Bluetooth stack name / version: BLUEDROID

Platform Memory Layout
======================

Memory Sections
---------------

Each memory section is discribed in the GCC linker file available `here <https://github.com/espressif/esp-idf/blob/v3.3.4/components/esp32/ld/esp32.ld>`__

Memory Layout
-------------

- MicroEJ resident applications statics (named ``.bss.features.installed``): put in the ``.ext_ram.bss`` section (external PSRAM)
- MicroEJ application static (named ``.bss.soar``): put in the ``.bss`` section (internal RAM)
- MicroEJ application threads stack blocks (named ``.bss.vm.stacks.java``): put in the ``.ext_ram.bss`` section (external PSRAM)
- MicroEJ Core Engine internal heap (named ``ICETEA_HEAP``): put in the ``.ext_ram.bss`` section (external PSRAM)
- MicroEJ application heap (named ``_java_heap``) location: put in the ``.ext_ram.bss`` section (external PSRAM)
- MicroEJ application immortal heap (named ``_java_immortals``) location: put in the ``.ext_ram.bss`` section (external PSRAM)
- MicroEJ application resources (named ``.rodata.resources``) location: put in the ``.rodata`` section (external QSPI)
- MicroEJ resident applications code and resources (named ``.rodata.soar.features``) location: put in the ``.rodata`` section (external QSPI)
- MicroEJ shielded Plug data (named ``.shieldedplug``) location: put in the ``.rodata`` section (external QSPI)
- MicroEJ application and library code (named ``.text.soar``) location: put in the ``.rodata`` section (external QSPI)
- MicroEJ MicroUI display framebuffer location: put in the ``.ext_ram.bss`` section (external PSRAM)
- C heap: Please refers to the |MANUFACTURER| documentation available `here <https://docs.espressif.com/projects/esp-idf/en/v3.3.4/api-reference/system/heap_debug.html#heap-information>`__

Information on MicroEJ memory sections can be found `here
<./ESP32-WROVER-Xtensa-FreeRTOS-bsp/Projects/microej/components/microej_gen/Makefile.projbuild>`__. Please
also refers to the MicroEJ docs website page available `here
<https://docs.microej.com/en/latest/PlatformDeveloperGuide/coreEngine.html#link>`__
for more details.


A list of BSP linker files defining firmware memory layout is available `here <https://github.com/espressif/esp-idf/blob/v3.3.4/components/esp32/ld>`__.

Platform Configurations
=======================

The |RI_NAME| |RI_VER| is declined into:

- a single application platform
- a multi application platform

Those declinations are themselves declined into:

- an evaluation platform (eval):

  - requires a SDK evaluation license from
    https://license.microej.com/.
  - When limitation is reached, the MicroEJ runtime will
    terminate. Exit code is described in the MicroEJ Device
    Developer's Guide provided with your SDK.

- a production platform (prod):

  - requires a SDK USB dongle license.
  - Production platforms do not implement limitation. If used
    properly, the platform can be run indifinitely or within the
    limits of the development board.

By default, the platform is configured as a Single Application
Evaluation Platform.  See `Advanced Build Options`_ for more
details on how to customize the platform configuration.

Single Application Platform
---------------------------

The single application platform is designed to give optimum performances and
resources for single application firmwares.
It embeds a specific MicroEJ virtual machine for this purpose.

It also supports SEGGER SystemView and OTA (Over The Air) update management.

Multi Application Platform
--------------------------

The multi application platform is designed for multiple application firmwares.
It embeds a specific MicroEJ virtual machine for this purpose.

SEGGER SystemView and OTA have been disabled in order to reduce the memory
footprint.

Platform Graphical User Interface
=================================

|GUIDE.INTERNAL.EMB| features a graphical user interface.  It includes
a display, one user LED and a runtime PNG decoder.

Display
-------

The display module drives a 320 x 240 LCD display.  The pixel format
is 16 bits-per-pixel.  The display device is clocked at 60Hz and it is
connected to the MCU via a SPI link, clocked at 80MHz for ST7789V LCP
display and at 33MHz for ILI9341V LCD display.

MicroUI requires a RAM buffer to store the dynamic images data.  A
dynamic is an image decoded at runtime (PNG image) or an image created
by the MicroEJ application thanks to the API ``Image.create(width, height)``.
This buffer is located in external RAM.

Inputs
------

The board provides an RGB matrix with 3 colored LEDs (red, green ,
blue).  However, only the red LED is available for the user.  The two
others LEDs use GPIOs multiplexed for other uses.

Use API ``ej.microui.led.Leds`` from ``ej.api#microui`` to manage the
LED.

Network
=======

|GUIDE.INTERNAL.EMB| features a network interface with Wi-Fi as an
underlying hardware media.  A limited number of 16 sockets could be
used for TCP connections, 16 for TCP listening (server) connections
and 16 for UDP connections. A DHCP client could be activated to
retrieve IP address. All DNS requests could be handled by a MicroEJ
software implementation or a native one.

SSL
===

|GUIDE.INTERNAL.EMB| features a network secure interface. Available
secured protocols are SSL 3.0, TLS 1.0, TLS 1.1, TLS 1.2. Supported
keys and certificates formats are PKCS#5 and PKCS#12, PEM or DER
encoded.

File System
===========

|GUIDE.INTERNAL.EMB| features a file system interface. A SD card is
used for the storage (previously formated to a FAT32 file system). Up
to 2 files could be opened simultaneously.

Platform Build
==============

The platform has to be build before using it. Please follow steps below:

- Select the ``{PLATFORM}-configuration`` project in your |RCP| worksapce
- Click on ``Build Selected Module``

  The platform build is now launched. Please wait for the final message:

.. code-block::

                          BUILD SUCCESSFUL 

Please also refers to the MicroEJ platform creation docs website page
available `here
<https://docs.microej.com/en/latest/PlatformDeveloperGuide/platformCreation.html>`__
for more details.

Advanced Build Options
----------------------

Following options can be modified in your
``{PLATFORM}-configuration/module.properties`` to build the platform
with specific options:

- ``com.microej.platformbuilder.module.multi.enabled``: set to
  ``true`` to build a Multi application platform, ``false`` to build a
  Single application platform (``false`` by default)
- ``com.microej.platformbuilder.architecture.usage``: set to ``prod``
  to build a production platform, ``eval`` to build an evaluation
  platform (``eval`` by default)
- ``com.microej.platformbuilder.bsp.build.enabled``: set to ``true``
  to launch a platform BSP build during the platform build, ``false``
  otherwise (``false`` by default)


Create and Use Your First |GUIDE.INTERNAL.PLATFORM|
===================================================

The aim of this chapter is to create a |GUIDE.INTERNAL.EMB| from a
|GUIDE.INTERNAL.XPF|. The platform will then be used to run a MicroEJ
|GUIDE_INTERNAL_STANDALONE| in subsequent chapters.

Although it is possible to use |RCP| to create every aspect of a
|GUIDE.INTERNAL.EMB| in accordance with specific requirements, in this
chapter we will use a pre-packaged example of a |GUIDE.INTERNAL.EMB|
that is already configured for the |BOARDPRINTABLENAME|.

Inside |RCP|, the selected example is imported as several projects
prefixed by the given name:

-  ``{PLATFORM}-configuration``: Contains the platform reference
   implementation configuration description. Some modules are
   described in a specific sub-folder / with some optional
   configuration files (``.properties`` and / or ``.xml``).

-  ``{PLATFORM}-bsp``: Contains a ready-to-use BSP software project for
   the |BOARDPRINTABLENAME| board, including a |CIDE.PRINTABLENAME|
   project, an implementation of MicroEJ core engine (and extensions)
   port on |RTOS.PRINTABLENAME RTOS| and the |BOARDPRINTABLENAME| board
   support package.

-  ``{PLATFORM}-fp``: Contains the board description and images for the
   |GUIDE.INTERNAL.SIM|. This project is updated once the platform
   is built.

Click on ``{PLATFORM}-configuration`` project and then click on the 
``Build Selected Module`` blue button on the |RCP| tools bar.

The build starts. This step may take several minutes. You can see the
progress of the build steps in the MicroEJ console. Please wait for
the final message:

.. code-block::

                          BUILD SUCCESSFUL

At the end of the execution the |GUIDE.INTERNAL.EMB| is fully built
for the |BOARDPRINTABLENAME| board and is ready to be linked into the
|CIDE.PRINTABLENAME| project.

The |GUIDE.INTERNAL.EMB| is now ready for use and available in the
|GUIDE.INTERNAL.EMBS| list of your MicroEJ repository (``Windows
> Preferences > MicroEJ > Platforms in workspace``).


Run an Example on the |GUIDE.INTERNAL.SIM|
==========================================

The aim of this chapter is to create a MicroEJ |GUIDE_INTERNAL_STANDALONE|
from a built-in example.

Initially, this example will run on the |GUIDE.INTERNAL.SIM|.
Then, in the next section, this application will be compiled and deployed
on the |BOARDPRINTABLENAME| board using the |GUIDE.INTERNAL.EMB|.


Create Example
--------------

-  Open |RCP|.

-  Open the ``File > New > MicroEJ Standalone Application Project``
   menu.

-  Enter your project name (e.g. HelloWorld).

   .. figure:: ESP32-WROVER-Xtensa-FreeRTOS-documentation/images/application/sim/HelloWorld-creation.png
      :alt: MicroEJ |GUIDE_INTERNAL_STANDALONE| Creation

      MicroEJ |GUIDE_INTERNAL_STANDALONE| Creation

-  Click on Finish.
  
The example is created into a project with the given
name. The main class (the class which contains the ``main()`` method)
is automatically generated.


Run Example
-----------

-  Select the project in the Package Explorer tree

-  Right-click on this project and select
   ``Run As > MicroEJ Application``

   .. figure:: ESP32-WROVER-Xtensa-FreeRTOS-documentation/images/application/sim/HelloWorld-run.png
      :alt: MicroEJ |GUIDE_INTERNAL_STANDALONE| Running
      :width: 100.0%

      MicroEJ |GUIDE_INTERNAL_STANDALONE| Running

   The application starts. It is executed on the |GUIDE.INTERNAL.SIM|
   of the selected |GUIDE.INTERNAL.EMB|.
   The result of the test is printed in the console:

   .. code-block::

                              Hello World!


Run the Example on the |BOARDPRINTABLENAME| Board
=================================================

Compile MicroEJ |GUIDE_INTERNAL_STANDALONE|
-------------------------------------------

-  Open the run dialog (``Run > Run configurations...``).

-  Select the MicroEJ Application launcher ``EXAMPLENAME Main`` that is
   created by the previous chapter.

-  Open ``Execution`` tab.

-  Select ``Execute on Device``.

   .. figure:: ESP32-WROVER-Xtensa-FreeRTOS-documentation/images/application/emb/basic-launcher.png
      :alt: Execution on Device
      :width: 100.0%

      Execution on Device

-  Click ``Run``: the application is compiled, and the compilation
   result (an ELF file) is copied into a well-known location in the
   example project.


Compile and Link Platform BSP
-----------------------------

BSP Manual Compilation
~~~~~~~~~~~~~~~~~~~~~~

To build the ``{PLATFORM}-bsp`` project, open a Windows command terminal and enter the following command lines:

On Windows:
+++++++++++

.. code-block:: sh

      $ cd "xxx/{PLATFORM}-bsp/Projects/microej/scripts"
      $ build.bat 

On Linux / Mac OS:
++++++++++++++++++

.. code-block:: sh

      $ cd "xxx/{PLATFORM}-bsp/Projects/microej/scripts"
      $ build.sh 

The BSP project build is launched. Please wait for the final message:

.. code-block::

      To flash all build output, run 'make flash' or:

The platform BSP project is configured to build the Mono-Sandboxed
Firmware by default.  To build the Multi-Sandboxed Firmware, use the
build script ``build_no_ota_no_systemview``.  With Multi-Sandboxed
Firmware configuration, SystemView and OTA features are disabled and
partition table layout updated accordingly.

If you decide to invoke ``make`` directly, make sure you use the
correct ``sdkconfig``.  Check the build scripts in
``{PLATFORM}-bsp/Projects/microej/scripts``.

BSP Compilation from |RCP|
~~~~~~~~~~~~~~~~~~~~~~~~~~

To build the BSP project every time the Java Application is built,
proceed as follow:

-  Open the run dialog (``Run > Run configurations...``).

-  Select the MicroEJ Application launcher ``EXAMPLENAME Main`` that is
   created by the previous chapter.

-  Open ``Configuration`` tab.

- Select ``Deploy``

- Ensure the option ``Execute the MicroEJ Build Script (build.bat) at
  a location known by the 3rd-party BSP project.`` is checked.

|BOARDPRINTABLENAME| Elf executable firmware and associated binary files are available in ``{PLATFORM}-bsp/Projects/microej/build``

Advanced Customization of BSP Build
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Please refers to `README
<./ESP32-WROVER-Xtensa-FreeRTOS-bsp/Projects/microej/README.rst>`__
for details on how to customize the build process.

Deploy the Application
----------------------

The |BOARDPRINTABLENAME| board can be flashed using |MANUFACTURER| bootloader. Follow steps below to do it:

- Connect the USB connector of the board to your computer
- Take a look to the new COM port available
- Edit the ``{PLATFORM}-bsp/Projects/microej/scripts/run.xxx`` script (where ``xxx`` is ``bat`` for Windows and ``sh`` for Linux / Mac OS). Update the ``ESPPORT`` variable to put the new COM port discovered previously and uncomment the associated line if not already done.
- Open a terminal and enter the following command lines:

**On Windows:**

.. code-block:: sh

      $ cd "xxx/{PLATFORM}-bsp/Projects/microej/scripts"
      $ run.bat 

**On Linux / Mac OS:**

.. code-block:: sh

      $ cd "xxx/{PLATFORM}-bsp/Projects/microej/scripts"
      $ run.sh 

The BSP project deploy is launched. Please wait for the final message:

.. code-block::

      Leaving...
      Hard resetting...

Congratulations, you have deployed a MicroEJ |GUIDE_INTERNAL_STANDALONE| on a |GUIDE.INTERNAL.EMB|.


Run a Testsuite
===============

To run a Testsuite on the |BOARDPRINTABLENAME| board the property
``microej.testsuite.properties.debug.traces.uart`` must be set in the
``config.properties`` of the Testsuite.

This property redirect the UART onto a different GPIO port. Connect a
FTDI USB wire to the pin D0 of the JP4 connector and ground.

Testsuite FS
------------

A ``config.properties`` and ``microej-testsuite-common.properties`` is
provided in ``{PLATFORM}-documentation/testsuite-fs/``.

In ``config.properties``, the property ``target.platform.dir`` must be
set to the absolute path to the platform.  For example
``C:/P0065_ESP32-WROVER-Platform/ESP32-WROVER-Xtensa-FreeRTOS-platform/source``.

Other Files to Read
===================

This directory also contains

* `CHANGELOG <./CHANGELOG.rst>`_ to track the changes in the MicroEJ
  ESP32-WROVER-KIT reference implementation
* `RELEASE NOTES <./RELEASE_NOTES.rst>`_ to list:

  - the supported hardware,
  - the known issues and the limitations,
  - the development environment,
  - the list of the dependencies and their versions.

* `README <./ESP32-WROVER-Xtensa-FreeRTOS-bsp/Projects/microej/README.rst>`_ for MicroEJ C project developed with the |MANUFACTURER| IDF. Recommended for users familiar with |MANUFACTURER| IDF and advanced usage.
