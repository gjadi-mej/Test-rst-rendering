..
    Copyright 2019-2020 MicroEJ Corp. All rights reserved.
    This library is provided in source code for use, modification and test, subject to license terms.
    Any modification of the source code will break MicroEJ Corp. warranties on the whole library.

===========
 Changelog
===========

-------------
 [Unreleased]
-------------

Added
=====

- Scripts to build and flash

Changed
=======

- New platform build type
- Increase the number of characteristics which can be registered for notifications to 31.

----------------------
 [1.6.0] - 2020-05-26
----------------------

Changed
=======

- Replaced the async_netconn with async_select
- New platform builder

----------------------
 [1.5.1] - 2020-05-19
----------------------

Fixed
=====
- Net : update net pack to version 9.2.1. 

----------------------
 [1.5.0] - 2020-05-13
----------------------

Added
=====

- UI: Add support for LCD mode in portrait (via compile switch).
- Core: Print reset reason at startup.
- Device : Add device pack version 1.1.0.

Changed
=======

- Update esp-idf version to 3.3.1.
- Optimized disaply driver my moving the functions in IRAM.
- Optimized the JVM RTOS task scheduling.
- Architecture : update architecture to version 7.12.1.
- Net : update net pack to version 9.2.0 and addons pack to version 2.1.6.
- Bluetooth: update bluetooth pack to version 2.0.0.
- Bluetooth: update LLBLUETOOTH implementation.

Fixed
=====

- Issue with some file names case on Linux 
- Wifi Driver : allow to enable softAP in OPEN auth mode.
- Wifi Driver : Fix SSID length too long (null terminated string).
- Ecom-network: Fix isEnabled and isStarted natives.
- Filesystem: Fix get free space and get total space computation.
- Filesystem: Fix the verification of writing data to a file.
- Net: Fix memory leak by freeing the netconn when closing a socket.
- SSL: Reset the ssl session after closing the ssl connection.
- Documentation: Link to Getting-Started page.
- Documentation: Board image.
- Documentation: Instructions to get the traces.

----------------------
 [1.4.5] - 2019-11-25
----------------------

Fixed
=====

- Documentation is now compliant with MicroEJ distribution 19.05.
- Getting Started URL in the README.rst.
- SDK URL in the RELEASE_NOTES.rst.

----------------------
 [1.4.4] - 2019-11-13
----------------------

Fixed
=====

- An issue that prevents building the platform from sources in MicroEJ SDK.

----------------------
 [1.4.2] - 2019-09-12
----------------------

Fixed
=====

- An issue that prevents linking application on linux hosts.

----------------------
 [1.4.1] - 2019-09-05
----------------------

Added
=====

- Bluetooth stub mock-up

Fixed
=====

- An issue that sometime prevents loading application in the simulator.
- Improve the WiFi mock-up user interface.

----------------------
 [1.4.0] - 2019-07-26
----------------------

This version differentiate configuration (sdkconfig) between singleapp (HDAHT)
and multiapp (9C5H4) platforms.

Added
=====

- Add Bluetooth support.
- Add new Mock Wi-Fi.
- Add SEGGER SytemView support for singleapp only.
- Disable OTA for multiapp only.
- Fix URLs to espressif.doc.
- Update OpenOCD version to win32-0.10.0-esp32-20190313,
- Improve documentation clarity.

Fixed
=====

- LwIP socket leak with esp-idf ESP_THREAD_SAFE option enabled

----------------------
 [1.3.0] - 2018-10-08
----------------------

Added
=====

- Java ``System.out.println`` trace output on a new UART (USB COM port no
  longer used).
- Add Java ESP32 <code>esp-idf</code> foundation library.
- Enable SNI 1.3 non immortal access feature

Fixed
=====

- LwIP issue that leads to lockup
- Net multi-thread access issues
- UI low level port do not support all LCD modules that can be included in
  ESP32-WROVER-KIT V3
- C stack overflow during complex TLS handshake

----------------------
 [1.2.0] - 2018-08-02
----------------------

Added
=====

- Wi-Fi throughput enhancement.
- Add UI MicroEJ pack and provides a device port.
- Add FS MicroEJ pack and provides a device port on SD card.

Fixed
=====

- Failure when trying to launch a Wi-Fi scan after mount and dismount.

----------------------
 [1.1.0] - 2018-05-30
----------------------

Added
=====

- Add HAL MicroEJ pack and provides a stubbed implementation.
- Add JPF MicroEJ platform.
- Update esptool MicroEJTool error messages.

Fixed
=====

- Failures when trying to attach a GDB debug session.

----------------------
 [1.0.0] - 2018-05-04
----------------------

Initial release of the platform.
