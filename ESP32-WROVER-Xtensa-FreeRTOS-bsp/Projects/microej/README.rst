.. 
	Copyright 2019-2020 MicroEJ Corp. All rights reserved.
	This library is provided in source code for use, modification and test, subject to license terms.
	Any modification of the source code will break MicroEJ Corp. warranties on the whole library.

================
ESP32-WROVER BSP
================

This project contains the BSP sources of MicroEJ platform demo for the ESP32-WROVER-KIT 4.1.
The BSP project is based on Espressif IoT Development Framework (ESP IDF).

Getting Started
---------------

In order to be able to develop the BSP with the IDF, setup your environment accordingly to the Espressif documentation.
Follow the section `Get Started <https://docs.espressif.com/projects/esp-idf/en/release-v3.3/get-started/index.html>`_ to do so.

Build & Flash
-------------

In the folder ``scripts/`` are two sets of scripts that can be used to build and flash the BSP, each set is meant to run in a Windows (.bat) or Linux (.sh) environment.

In order to run these scripts you will have to define four environment variables which are the following:

- ``MSYS_PATH``: path to the msys32 installation (Windows).
- ``XTENSA_PATH``: path to the Xtensa toolchain installation (Linux).
- ``IDF_PATH``: path to the esp-idf directory.
- ``ENV_BASH_CMD``: command line to compile the BSP, for example, to build a Single App ESP32 platform it would be set to ``"./build_singleapp.sh all"``. 
- ``ENV_FLASH_CMD``: command line to flash and execute the firmware produced by the build script, if you set the previous variable to build a Single App platform, it would be set to ``"./build_singleapp.sh flash monitor"``.

If you have to use another serial port than the one defined in the configuration, you can append the command with the ``ESPPORT`` variable.
For example you can set ``ENV_FLASH_CMD`` to: ``"./build_multiapp.sh monitor ESPPORT=COM1"``. See this `section of Espressif documentation <https://docs.espressif.com/projects/esp-idf/en/release-v3.3/get-started/index.html#environment-variables>`_
for other possible variables.

Flash the board with the Espressif flash tool
---------------------------------------------

- Start ESP32 Flash Download Tool (available `here <https://www.espressif.com/en/support/download/other-tools>`_)
- Click on ESP32 DownloadTool button
- Select the tab SPI Download
- Fill the first blank line as following:
  - Select the check box on the left
  - Click on ... and browse the application.bin file
  - Type the value 0 into the address text field on the right (after the @ symbol)
- Set COM to the previously mounted COM port
- Set Baud to 921600
- Click on START

The flashing process starts with a green progress bar. Wait until the message FINISH is shown.

Debugging with a WROVER dev kit
-------------------------------

Follow `these steps <https://docs.espressif.com/projects/esp-idf/en/release-v3.3/api-guides/jtag-debugging/configure-wrover.html>`_ to configure the dev kit jumpers and USB drivers.

Then `install OpenOCD <https://docs.espressif.com/projects/esp-idf/en/release-v3.3/api-guides/jtag-debugging/index.html#jtag-debugging-setup-openocd>`_.

You can run OpenOCD as `explained here <https://docs.espressif.com/projects/esp-idf/en/release-v3.3/api-guides/jtag-debugging/index.html#run-openocd>`_.

Or you can configure the launcher ``[ATTACH] Start GDB Server`` depending on your OpenOCD and msys32 installation and then run it.

If not already done, create a ``gdbinit`` file with the following commands:

::

	target remote :3333
	set remote hardware-watchpoint-limit 2
	mon reset halt
	flushregs
	thb app_main
	c

Finally, you can run gdb from the microej C project:

::

	xtensa-esp32-elf-gdb -x gdbinit build/microej.elf
	
Debugging commands examples can be found in `this section <https://docs.espressif.com/projects/esp-idf/en/release-v3.3/api-guides/jtag-debugging/debugging-examples.html#jtag-debugging-examples-command-line>`_.

Tips
====

If you encounter the following error:

::

	Warning:
	Cannot insert breakpoint 2.
	Cannot access memory at address 0x4013c808
	
Add your breakpoint using the command ``hb`` instead of ``b``.

Convert a PEM private key to DER
--------------------------------

MicroEJ requires private keys in DER format. To convert your PEM private keys use the following command:

::

	openssl.exe pkcs8 -inform PEM -in key1.pem -topk8 -outform DER -out key1.der -v1 PBE-SHA1-3DES -passout pass:<my_password>

Convert a backtrace without make monitor
----------------------------------------

The following command:

::

	xtensa-esp32-elf-addr2line.exe -pfiaC -e build/microej.elf 0x400d316d

Should output the corresponding instruction at the address given in the last parameter.

If you want to decode multiple instructions, copy/paste the backtrace in a text file and run this command:

::

	cat backtrace.txt | sed 's/\ 0x/\n0x/' | sed 's/\:.*//' | grep '\ 0x' backtrace | xargs xtensa-esp32-elf-addr2line.exe -pfiaC -e build/microej.elf
