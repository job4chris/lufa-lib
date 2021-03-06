/*
             LUFA Library
     Copyright (C) Dean Camera, 2010.
              
  dean [at] fourwalledcubicle [dot] com
      www.fourwalledcubicle.com
*/

/*
  Copyright 2010  Dean Camera (dean [at] fourwalledcubicle [dot] com)

  Permission to use, copy, modify, distribute, and sell this 
  software and its documentation for any purpose is hereby granted
  without fee, provided that the above copyright notice appear in 
  all copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting 
  documentation, and that the name of the author not be used in 
  advertising or publicity pertaining to distribution of the 
  software without specific, written prior permission.

  The author disclaim all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/

/** \file
 *
 *  Header file for ConfigDescriptor.c.
 */

#ifndef _CONFIGDESCRIPTOR_H_
#define _CONFIGDESCRIPTOR_H_

	/* Includes: */
		#include <LUFA/Drivers/USB/USB.h>
		
		#include "MouseHost.h"
		
	/* Macros: */
		/** Interface Class value for the Human Interface Device class. */
		#define MOUSE_CLASS                 0x03

		/** Interface Protocol value for a Boot Protocol Mouse compliant device. */
		#define MOUSE_PROTOCOL              0x02
	
	/* Enums: */
		/** Enum for the possible return codes of the \ref ProcessConfigurationDescriptor() function. */
		enum MouseHost_GetConfigDescriptorDataCodes_t
		{
			SuccessfulConfigRead            = 0, /**< Configuration Descriptor was processed successfully */
			ControlError                    = 1, /**< A control request to the device failed to complete successfully */
			DescriptorTooLarge              = 2, /**< The device's Configuration Descriptor is too large to process */
			InvalidConfigDataReturned       = 3, /**< The device returned an invalid Configuration Descriptor */
			NoHIDInterfaceFound             = 4, /**< A compatible HID interface was not found in the device's Configuration Descriptor */
			NoEndpointFound                 = 5, /**< A compatible HID IN endpoint was not found in the device's HID interface */
		};

	/* Function Prototypes: */
		uint8_t ProcessConfigurationDescriptor(void);

		uint8_t DComp_NextMouseInterface(void* CurrentDescriptor);
		uint8_t DComp_NextMouseInterfaceDataEndpoint(void* CurrentDescriptor);

#endif
