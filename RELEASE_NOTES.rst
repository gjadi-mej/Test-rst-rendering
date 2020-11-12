..
    Copyright 2019-2020 MicroEJ Corp. All rights reserved.
	This library is provided in source code for use, modification and test, subject to license terms.
	Any modification of the source code will break MicroEJ Corp. warranties on the whole library.

.. |TARGET_NAME| replace:: ESP32 WROVER
.. |RI_NAME| replace:: ESP32 WROVER Platform Reference Implementation
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
  * bluetooth: 2.0.0
  * fs (File System): 4.0.2
  * trace-systemview: 2.0.1
  * device: 1.1.0

- BSP specific packs:

  * esp_idf (ESP_IDF Wrapper): 1.0.0
  * esp_idf API (ESP_IDF Wrapper API): 1.0.1
  * esp_idf-impl (ESP_IDF extra implementation): 1.0.0
  * esp_idf-mock (ESP_IDF Mock-Up): 1.0.0
  * esp-idf: 3.3.1

Environment
===========

The |RI_NAME| |RI_VER| requires the following environment:

For development:

- MicroEJ SDK (`<http://developer.microej.com/packages/SDK/20.10/>`_),
- Espressif ESP32 toolchain.  Please setup the |MANUFACTURER|
  toolchain as described `here
  <https://docs.espressif.com/projects/esp-idf/en/v3.3.4/get-started/index.html#setup-toolchain>`__.


   - For Windows: https://docs.espressif.com/projects/esp-idf/en/v3.3.4/get-started/windows-setup.html
   - For Linux: https://docs.espressif.com/projects/esp-idf/en/v3.3.4/get-started/linux-setup.html


For debugging, please refers to the |MANUFACTURER| documentation
available `here
<https://docs.espressif.com/projects/esp-idf/en/v3.3.4/api-guides/jtag-debugging/index.html>`__
for more details.


Known issues/limitations
========================

- P0065ESP32WROVER-192: LLNET_CHANNEL_IMPL_setOption cannot change the socket
  send and receive buffer sizes,
- P0065ESP32WROVER-184: Provided Filesystem pack does not support file
  write/read with offset from/to immortal arrays,
- P0065ESP32WROVER-183: Provided Filesystem pack does not support file backward
  skip,
- P0065ESP32WROVER-188: IPV6 is not supported,
- SystemView is enabled only on the single application platform,
- OTA is enabled only on the single application platform,
- |TARGET_NAME| can be debugged with OpenOCD only if SD Card interface is not
  used,
- As described in espressif documentation, LCD and microSD cannot be used at
  the same time without unsoldering the resistor R167 (`https://docs.espressif.com/projects/esp-idf/en/latest/esp32/hw-reference/esp32/get-started-wrover-kit.html#allocation-of-esp32-pins`).
