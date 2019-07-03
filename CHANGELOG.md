# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## 1.1.0 - 

### Added

  - Add UI test `t_ui_api.c`: test LLDisplay implementation.
  - Add UI test `t_ui_tearing.c`: test LCD tearing synchronization.
  - Add UI test `t_ui_framerate.c`: retrieve LCD framerate.

### Fixed

  - Fix `X_RAM_CHECKS_checkAddress16()`: test checked memory accesses outside memory range

## 1.0.1 - 2019-04-25

### Fixed

  - Delete `t_core_lljvm.c` (workaround before fixing).

## 1.0.0 - 2019-03-07

### Added

  - Initial revision with CORE tests only.
  
---  
_Copyright 2019 MicroEJ Corp. All rights reserved._  
_For demonstration purpose only._  
_MicroEJ Corp. PROPRIETARY/CONFIDENTIAL. Use is subject to license terms._  
