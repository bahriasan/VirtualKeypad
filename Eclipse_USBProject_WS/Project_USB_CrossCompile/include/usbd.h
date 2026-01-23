#ifndef USBD_H
#define USBD_H

/*
 * usbd.h
 */

#include "stm32f407xx.h"
#include "types.h"


//SETUP FRAME[0] DEFINITIONS
#define BM_REQUEST_TYPE_POS					(0U)
#define BM_REQUEST_TYPE_MASK				(0xFFUL << BM_REQUEST_TYPE_POS)
#define BM_REQUEST_TYPE						BM_REQUEST_TYPE_MASK
#define BM_REQUEST_TYPE_RECIPIENT_POS		(0U)
#define BM_REQUEST_TYPE_RECIPIENT_MASK		(0x1FUL << BM_REQUEST_TYPE_RECIPIENT_POS)
#define BM_REQUEST_TYPE_RECIPIENT			BM_REQUEST_TYPE_RECIPIENT_MASK
#define BM_REQUEST_TYPE_TYPE_POS			(5U)
#define BM_REQUEST_TYPE_TYPE_MASK			(0x3UL << BM_REQUEST_TYPE_TYPE_POS)
#define BM_REQUEST_TYPE_TYPE				BM_REQUEST_TYPE_TYPE_MASK
#define BM_REQUEST_TYPE_DIRECTION_POS		(7U)
#define BM_REQUEST_TYPE_DIRECTION_MASK		(0x1UL << BM_REQUEST_TYPE_DIRECTION_POS)
#define BM_REQUEST_TYPE_DIRECTION			BM_REQUEST_TYPE_DIRECTION_MASK
#define B_REQUEST_POS						(8U)
#define B_REQUEST_MASK						(0xFFUL << B_REQUEST_POS)
#define B_REQUEST							B_REQUEST_MASK
#define W_VALUE_POS							(16U)
#define W_VALUE_MASK						(0xFFFFUL << W_VALUE_POS)
#define W_VALUE								W_VALUE_MASK
#define W_VALUE_LB_POS						(16U)
#define W_VALUE_LB							(0x00FFUL << W_VALUE_POS)
#define W_VALUE_HB_POS						(24U)
#define W_VALUE_HB							(0xFF00UL << W_VALUE_POS)

//BM_REQUEST_TYPE_RECIPIENT
#define DEVICE				(0UL)
#define INTERFACE			(1UL)
#define ENDPOINT			(2UL)
#define OTHER				(3UL)
//BM_REQUEST_TYPE_TYPE
#define STANDART			(0UL)
#define CLASS				(1UL)
#define VENDOR				(2UL)
//BM_REQUEST_TYPE_DIRECTION
#define HOST2DEV			(0UL)
#define DEV2HOST			(1UL)
//B_REQUEST_STD
#define STD_GET_STATUS			(0UL)
#define STD_CLEAR_FEATURE		(1UL)
#define STD_SET_FEATURE			(3UL)
#define STD_SET_ADDRESS			(5UL)
#define STD_GET_DESCRIPTOR		(6UL)
#define STD_SET_DESCRIPTOR		(7UL)
#define STD_GET_CONFIGURATION	(8UL)
#define STD_SET_CONFIGURATION	(9UL)
#define STD_GET_INTERFACE		(10UL)
#define STD_SET_INTERFACE		(11UL)
#define STD_SYNCH_FRAME			(12UL)
//W_VALUE_DESCRIPTOR_TYPES
#define DESC_DEVICE						(1UL)
#define DESC_CONFIGURATION				(2UL)
#define DESC_STRING						(3UL)
#define DESC_INTERFACE					(4UL)
#define DESC_ENDPOINT					(5UL)
#define DESC_DEVICE_QUALIFIER			(6UL)
#define DESC_OTHER_SPEED_CONFIGURATION	(7UL)
#define DESC_INTERFACE_POWER1			(8UL)
//W_VALUE INDEX TYPES
#define USBD_IDX_LANGID_STR				(0UL)
#define USBD_IDX_MFC_STR				(1UL)
#define USBD_IDX_PRODUCT_STR			(2UL)
#define USBD_IDX_SERIAL_STR				(3UL)
#define USBD_IDX_CONFIG_STR				(4UL)
#define USBD_IDX_INTERFACE_STR			(5UL)

//LANG_IDS
#define	ENGLISH_USA		(uint16)0x0409
#define TURKISH			(uint16)0x041F

//SETUP FRAME[1] DEFINITIONS
#define W_INDEX_POS							(0U)
#define W_INDEX_MASK						(0xFFFFUL << W_INDEX_POS)
#define W_INDEX								W_INDEX_MASK
#define W_INDEX_EPNO_POS					(0U)
#define W_INDEX_EPNO						(0x000FUL << W_INDEX_EPNO_POS)
#define W_INDEX_EPDIR_POS					(7U)
#define W_INDEX_EPDIR						(0x0080UL << W_INDEX_EPDIR_POS)
#define W_LENGTH_POS						(16U)
#define W_LENGTH_MASK						(0xFFFFUL << W_LENGTH_POS)
#define W_LENGTH							W_LENGTH_MASK

#define EP_NO_POS	(0U)
#define EP_NO_MASK	(uint8)(0xFU << EP_NO_POS)
#define EP_DIR_POS	(7U)
#define EP_DIR_MASK	(uint8)(0xFU << EP_DIR_POS)
#define IN_DIR		(uint8)(0x1)
#define OUT_DIR		(uint8)(0x0)

//Endpoint Descriptor bEndpointAddress
#define ENDIN1				(uint8)(((0x1 << EP_NO_POS) & EP_NO_MASK) | ((IN_DIR << EP_DIR_POS) & EP_DIR_MASK))

#define BP_YES	TRUE
#define BP_NO	FALSE
#define SP_YES	TRUE
#define SP_NO	FALSE
#define RW_YES	TRUE
#define RW_NO	FALSE
#define BP_POS	(7UL)
#define BP_MASK	(uint8)(1 << BP_POS)
#define SP_POS	(6UL)
#define SP_MASK	(uint8)(1 << SP_POS)
#define RW_POS	(5UL)
#define RW_MASK	(uint8)(1 << RW_POS)

#define SET_BM_ATTR(BP,SP,RW)	(uint8)((BP << BP_POS) | (SP << SP_POS) | (RW << RW_POS))

//Endpoint Descriptor bmAttributes
#define ATTR_CONTROL					(uint8)(0x00)
#define ATTR_ISOCHRONOUS				(uint8)(0x01)
#define ATTR_BULK						(uint8)(0x02)
#define ATTR_INTERRUPT					(uint8)(0x03)

//String Definitions
#define USBD_MANUFACTURER_STRING     	"STMicroelectronics"
#define USBD_PID_FS     				22315
#define USBD_PRODUCT_STRING_FS     		"STM32 Human interface"
#define USBD_CONFIGURATION_STRING_FS    "HID Config"
#define USBD_INTERFACE_STRING_FS     	"HID Interface"
#define USBD_MAX_STR_DESC_SIZ			512U
#define USB_SIZ_STRING_SERIAL			0x1A

#define MIN(x,y)						((x < y) ? x : y)

typedef struct deviceDescriptorType
{
	uint8 bLength;
	uint8 bDescriptorType;
	uint8 bcdUSB[2];
	uint8 bDeviceClass;
	uint8 bDeviceSubClass;
	uint8 bDeviceProtocol;
	uint8 bMaxPacketSize0;
	uint8 idVendor[2];
	uint8 idProduct[2];
	uint8 bcdDevice[2];
	uint8 iManufacter;
	uint8 iProduct;
	uint8 iSerialNumber;
	uint8 bNumConfigurations;
}deviceDescriptorType;

typedef struct deviceQualifierDescriptorType
{
	uint8 bLength;
	uint8 bDescriptorType;
	uint8 bcdUSB[2];
	uint8 bDeviceClass;
	uint8 bDeviceSubClass;
	uint8 bDeviceProtocol;
	uint8 bMaxPacketSize0;
	uint8 bNumConfigurations;
	uint8 bReserved;
}deviceQualifierDescriptorType;

typedef struct configurationDescriptorType
{
	uint8 bLength;
	uint8 bDescriptorType;
	uint8 wTotalLength[2];
	uint8 bNumInterfaces;
	uint8 bConfigurationValue;
	uint8 iConfiguration;
	uint8 bmAttributes;
	uint8 bMaxPower;
}configurationDescriptorType;

typedef struct otherSpeedConfigurationType
{
	uint8 bLength;
	uint8 bDescriptorType;
	uint8 wTotalLength[2];
	uint8 bNumInterfaces;
	uint8 bConfigurationValue;
	uint8 iConfiguration;
	uint8 bmAttributes;
	uint8 bMaxPower;
}otherSpeedConfigurationType;

typedef struct interfaceDescriptorType
{
	uint8 bLength;
	uint8 bDescriptorType;
	uint8 bInterfaceNumber;
	uint8 bAlternateSetting;
	uint8 bNumEndpoints;
	uint8 bInterfaceClass;
	uint8 bInterfaceSubClass;
	uint8 bInterfaceProtocol;
	uint8 iInterface;
}interfaceDescriptorType;

typedef struct endpointDescriptorType
{
	uint8 bLength;
	uint8 bDescriptorType;
	uint8 bEndpointAddress;
	uint8 bmAttributes;
	uint8 wMaxPacketSize[2];
	uint8 bInterval;
}endpointDescriptorType;

typedef struct hidDescriptorType
{
	uint8 bLength;
	uint8 bDscriptorType;
	uint8 bcdHID[2];
	uint8 bCountryCode;
	uint8 bNumDescriptors;
	uint8 bDescriptorType;
	uint8 wDescriptorLength[2];
	//No optional Descriptor, Report Descriptor only
}hidDescriptorType;

//String Descriptor is optional

typedef struct FSConfigurationDescriptorType
{
	configurationDescriptorType FSConfiguration;
	interfaceDescriptorType	FSInterface;
	hidDescriptorType FSHid;
	endpointDescriptorType FSEndpoint;
}FSConfigurationDescriptorType;

uint8* GetFSConfigDescriptor(uint16* length);
uint8* GetFSDeviceDescriptor(uint16* length);
uint8* GetFSLangIdStringDescriptor(uint16* length);
uint8* GetFSMfcIdStringDescriptor(uint16* length);
uint8* GetFSPdcIdStringDescriptor(uint16* length);
uint8* GetFSSerialStringDescriptor(uint16* length);
uint8* GetFSConfigStringDescriptor(uint16* length);
uint8* GetFSInterfaceStringDescriptor(uint16* length);
uint8* GetFSDeviceQualifierDescriptor(uint16* length);

extern FSConfigurationDescriptorType FSConfigurationDescriptor;


#endif
