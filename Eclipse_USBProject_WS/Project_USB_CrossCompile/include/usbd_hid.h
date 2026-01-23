#ifndef USBD_HID_H
#define USBD_HID_H

#include "types.h"

//B_REQUEST_CLASS
#define CLASS_GET_REPORT		(1UL)
#define CLASS_GET_IDLE			(2UL)
#define CLASS_GET_PROTOCOL		(3UL)
#define CLASS_SET_REPORT		(9UL)
#define CLASS_SET_IDLE			(10UL)
#define CLASS_SET_PROTOCOL		(11UL)

//W_VALUE_DESCRIPTOR_TYPES
#define DESC_HID				(0x21UL)
#define DESC_REPORT				(0x22UL)
#define DESC_PHYSICALREPORT		(0x23UL)

//Report Type
#define INPUT_REPORT			(uint8)1
#define OUTPUT_REPORT			(uint8)2
#define FEATURE_REPORT			(uint8)3

uint8* GetFSReportDescriptor(uint16* length);


#endif
