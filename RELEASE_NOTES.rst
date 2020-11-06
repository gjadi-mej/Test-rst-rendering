..
    Copyright 2019-2020 MicroEJ Corp. All rights reserved.
	This library is provided in source code for use, modification and test, subject to license terms.
	Any modification of the source code will break MicroEJ Corp. warranties on the whole library.

.. |TARGET_NAME| replace:: ESP32 WROVER
.. |RI_NAME| replace:: ESP32 WROVER platform reference implementation
.. |RI_VER| replace:: v1.6.0

.. _release-notes:

==============================================
 Release notes: MicroEJ ESP32-WROVER Platform
==============================================

Description
===========

This is the release note of the |RI_NAME| |RI_VER|.
This reference platform is designed for the ESP32-WROVER-Kit.

Versions
========

Platform
--------

|RI_NAME| |RI_VER|.

Dependencies
------------

The |RI_NAME| |RI_VER| contains the following dependencies:

- MicroEJ ESP32 specific packs:

  * simikou2 (Architecture): 7.14.0
  * simikou2UI (User Interface): 12.1.5

- MicroEJ generic packs:

  * net: 9.2.1
  * net-addons: 2.1.6
  * hal (Hardware Abstraction Layer): 2.0.1
  * hal-stub (stubs for Hardware Abstraction Layer): 1.1.1
  * bluetooth: 2.0.0
  * fs (File System): 4.0.2
  * microej-util: 1.3.0
  * trace-systemview: 2.0.1
  * wadapps (Multi Application Framework): 1.0.1
  * wadapps.impl (extra implementation for Multi Application Framework): 1.0.2
  * device: 1.1.0

- BSP specific packs:

  * esp_idf (ESP_IDF Wrapper): 1.0.0
  * esp_idf API (ESP_IDF Wrapper API): 1.0.1
  * esp_idf-impl (ESP_IDF extra implementation): 1.0.0
  * esp_idf-mock (ESP_IDF Mock-Up): 1.0.0
  * esp-idf: 3.3.1

- Third party tools

  * esptool (Flashing tool): 1.2.0

Environment
===========

The |RI_NAME| |RI_VER| requires the following environment:

For development:

- MicroEJ SDK (`<http://developer.microej.com/packages/SDK/19.05/>`_),
- Espressif ESP32 toolchain (`<https://dl.espressif.com/dl/esp32_win32_msys2_environment_and_toolchain-20181001.zip>`_).

For debugging:

- OpenOCD (Open On-Chip Debugger) (`<https://github.com/espressif/openocd-esp32/releases/download/v0.10.0-esp32-20190313/openocd-esp32-win32-0.10.0-esp32-20190313.zip>`_),
- Zadig (generic USB driver installer) (`<https://github.com/pbatard/libwdi/releases/download/v1.3.0/zadig-2.3.exe>`_).

Known issues/limitations
========================

- P0065ESP32WROVER-192: LLNET_CHANNEL_IMPL_setOption cannot change the socket
  send and receive buffer sizes,
- P0065ESP32WROVER-184: Provided Filesystem pack does not support file
  write/read with offset from/to immortal arrays,
- P0065ESP32WROVER-183: Provided Filesystem pack does not support file backward
  skip,
- P0065ESP32WROVER-188: IPV6 is not supported,
- SystemView is enabled only on the single application platform (UID: HDAHT)
- OTA is enabled only on the single application platform (UID: HDAHT),
- |TARGET_NAME| can be debugged with OpenOCD only if SD Card interface is not
  used,
- As described in espressif documentation, LCD and microSD cannot be used at
  the same time without unsoldering the resistor R167 (`https://docs.espressif.com/projects/esp-idf/en/latest/esp32/hw-reference/esp32/get-started-wrover-kit.html#allocation-of-esp32-pins`).
