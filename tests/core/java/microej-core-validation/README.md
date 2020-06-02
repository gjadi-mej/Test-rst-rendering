# README

## Overview
MicroEJ Core Validation: this project contains JUnit test cases to validate the port of MicroEJ CORE.

## Requirements
 - MicroEJ SDK 19.05 
 - MicroEJ Platform with CORE

## Usage
 - Select `Run > Run Configurations...`. A launcher named `microej-core-validation` should be available under `MicroEJ Application`, run it to compile the MicroEJ Application.

 - Before linking the application against the platform, add the following code in your BSP to test the FPU configuration:

```c
#include "sni.h"
jfloat Java_com_microej_MicroejCoreValidation_testFloat (jfloat a, jfloat b) {return a * b;}
jdouble Java_com_microej_MicroejCoreValidation_testDouble (jdouble a, jdouble b) {return a * b;}
```

- For a best result in the Java Round Robin test, disable all the C native tasks except the MicroEJ task.

- Run the application on the platform.

- Once all the tests have passed successfully, MicroEJ CORE is validated.

## Dependencies
_All dependencies are retrieved transitively by Ivy resolver_.

## Source
N/A

## Restrictions
None.

---

_Copyright 2020 MicroEJ Corp. All rights reserved._  
_This library is provided in source code for use, modification and test, subject to license terms._  
_Any modification of the source code will break MicroEJ Corp. warranties on the whole library._  
