Description
===========

This project allows to qualify a MicroEJ platform. Some tests are
written in C and have to be added in platform BSP project. Some tests
are written in Java and have to be launched as a standard MicroEJ
application.

Each feature (*core*, *ui*, *net* etc.) holds its set of tests. However,
all features (except *core*) consider *core* feature has been fully
tested and validated.

C Tests
-------

The C tests are using Embunit framework. They have to be launched just
before MicroEJ application (just before the call to
``microjvm_main()``). At this moment, the BSP is fully initialized and
the OS is started.

The C tests perform some basic checks which ensures MicroEJ application
will run. However, the tests cannot be launched without a MicroEJ
platform: C tests cannot be linked when a MicroEJ application
(``microejapp.o``) and a MicroEJ runtime library (``microejruntime.a``)
are not linked with the BSP.

The tests require some additional data (some specific functions have to
be implemented in addition of LLAPI implementation functions). In case
of these additional functions are not implemented, some parts of tests
cannot run and some asserts can be thrown.

See `Usage`_ section to have more information on each C test, on
additional functions to implement and on expected results.

Java Tests
----------

The Java tests verify the integration of the MicroEJ platform over the
BSP. No specific testuinit framework is used, each test describes how it
works.

See `Usage`_ section to have more information on each Java test, on
additional functions to implement and on expected results.

Folder Description
------------------

The folder contains C files and Java projects.

-  ``/framework`` (common files and third party tools)

   -  ``/c`` (C language)

      -  ``/embunit`` (Embedded Unit framework)
      -  ``/utils`` (MicroEJ test common files)

         -  ``/src`` (Source files)
         -  ``/inc`` (Header files)

-  ``/tests`` (test source files)

   -  ``/_feature_`` (core, ui, net etc.)

      -  ``/c`` (C language source and header files)

         -  ``/src`` (Source files)
         -  ``/inc`` (Header files)

      -  ``/java`` (MicroEJ projects)

BSP Project Configuration
=========================

1. Add all files of these folders as source files:

   -  ``framework/c/embunit``
   -  ``framework/c/utils/src``

2. Implement all functions defined in these files:

   -  ``u_time_base.h``: Some default weak functions are already
      implemented and throw some warnings. Without a valid
      implementation, the *core* feature cannot be fully tested.

3. Optionaly, implement all functions defined in these files:

   -  ``u_print.h``: The default weak functions redirect the trace to
      ``printf`` API.

Usage
=====

Core
----

See `CORE Readme <tests/core/README.rst>`_

UI
--

See `UI Readme <tests/ui/README.rst>`_

..
   Copyright 2019-2020 MicroEJ Corp. All rights reserved.
   Use of this source code is governed by a BSD-style license that can be found with this software.
