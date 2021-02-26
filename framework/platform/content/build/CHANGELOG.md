# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.2.0] - Unreleased

### Added

- Add `default.platform` to allow any empty project to be converted as a Platform project (no longer need to import a MicroEJ Architecture first).
- Fix default module version to `0.1.0` as other MicroEJ SDK skeletons.
- Fix default module organization to `com.mycompany` as other MicroEJ SDK skeletons.

### Fixed

- Fix documentation in `bsp.properties`, the variable `${project.prefix}` is no longer supported.
- Use a new private configuration ``embedded`` as the default for the platform dependencies.  This prevents an instance of "Too many loaded Platforms" error in `platform-loader`.

## [1.1.1] - 2021-02-11

### Fixed

- Fix execution of `run.[bat|sh]` in the directory where is defined `application.out`.

## [1.1.0] - 2021-01-08

### Changed

 - Added scripts and `module.ivy` file for Platform module build and publication.

## [1.0.0] - 2020-06-24

### Added

  - Initial version with scripts for BSP connection.
  
---
_Copyright 2020-2021 MicroEJ Corp. All rights reserved._
_Use of this source code is governed by a BSD-style license that can be found with this software._
