A table
-------

.. list-table:: |PLATFORM_NAME| |PLATFORM_VER| dependencies
   :header-rows: 1
   
   * - Section Name
     - Section Source
     - Section Destination
     - Memory Type
   * - MicroEJ System Application statics 
     - ``.bss.features.installed``
     - ``.ext_ram.bss``
     - external PSRAM
   * - MicroEJ application static 
     - ``.bss.soar``
     - ``.bss``
     - internal RAM
   * - MicroEJ application threads stack blocks 
     - ``.bss.vm.stacks.java``
     - ``.ext_ram.bss``
     - external PSRAM
   * - MicroEJ Core Engine internal heap 
     - ``ICETEA_HEAP``
     - ``.ext_ram.bss``
     - external PSRAM
   * - MicroEJ application heap 
     - ``_java_heap``
     - ``.ext_ram.bss``
     - external PSRAM
   * - MicroEJ application immortal heap 
     - ``_java_immortals``
     - ``.ext_ram.bss``
     - external PSRAM
   * - MicroEJ application resources 
     - ``.rodata.resources``
     - ``.rodata``
     - external QSPI
   * - MicroEJ resident applications code and resources 
     - ``.rodata.soar.features``
     - ``.rodata``
     - external QSPI
   * - MicroEJ shielded Plug data 
     - ``.shieldedplug``
     - ``.rodata``
     - external QSPI
   * - MicroEJ application and library code 
     - ``.text.soar``
     - ``.rodata``
     - external QSPI
   * - MicroEJ MicroUI display framebuffer
     - ``.ext_ram.bss``
     - external PSRAM
