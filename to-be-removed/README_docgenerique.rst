

==================== TO BE moved docs.microej.com =======================================



the steps for configuring a MicroEJ Platform for running automated MicroEJ testsuites.
Basically, this document the MicroEJ build chain is extended to execute the C project build, to produce the final executable ``application.out``.

`dropins <SDK5.1.x_Architecture7.x-dropins>`_



Configuration
        		
Launch Options required for build and testsuite full chain BSP application.out build

Mode 1 (relative locations provided by the Platform)
 	Launch options
		BSP location									
						deploy.bsp.root.dir (optional VS BUILD OPTION)
	
		Mandatory
						deploy.bsp.microejapp=true
						deploy.bsp.microejscript=true
		Recommended (it can be disconnected in case the BSP project already embeds header files and microejruntime.a, which can speed-up the build) 				
						deploy.bsp.microejinc=true
						deploy.bsp.microejlib=true

	Build Options
		Absolute BSP location        	
		       		toolchain.dir="C:\Users\user\Documents\work\workspacePQT\lpcxpresso_freertos-bsp" (optional)
					
Mode 2 - absolute locations provided by the firmware builder
 	Launch options
		deploy.bsp.microejapp=false
		deploy.bsp.microejlib=false
		deploy.bsp.microejinc=false
		deploy.bsp.microejscript=false
		deploy.dir.microejapp=[APP_DIR]
		deploy.dir.microejlib=[LIB_DIR]
		deploy.dir.microejinc=[INC_DIR]
		deploy.dir.microejscript=[SCRIPT_DIR]

Both modes can be mixed for each option. 					

Common Build Option
	Absolute Platform location        	
	   		target.platform.dir="C:\Users\user\Documents\work\workspacePQT\lpcxpresso_freertos-platform\source"

					

       		
How to pass launch options
 => build/*.properties
How to pass build options
 <ea:property /> in module.ivy or Ant properties (Eclipse Ant Preferences / Jenkins Ant plugin)
 

le 'bsp.available' c'est que quand on a un repertoire BSP - celui qui ne veut pas connecter un BSP ça ne doit pas tester.
 
un nouveau 'configuration.xml' pour generer les properties bsp specifiques
 + demande de gbalan de charger tous les 'autoconfiguration.xml'
 + bien penser a reinjecter le deployInBSP.properties => 
 
si pas de rep BSP et pas d'option de settée (.o, .a et .h) alors les outputs sont toujours dans l'output du main java folder - depuis la 7.10

generer le folder platform avec les infos du platform et de la naming convention 

.. ReStructuredText
.. Copyright 2020 MicroEJ Corp. All rights reserved.
.. Use of this source code is governed by a BSD-style license that can be found with this software.