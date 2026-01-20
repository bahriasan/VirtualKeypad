#include "usbd.h"

uint8 USB_StringUnicode[USBD_MAX_STR_DESC_SIZ] = {0};

uint8 FSDeviceDescriptor[18] =
{
	0x12,		//		uint8 bLength;
	0x01,		//		uint8 bDescriptorType;
	0x00,		//		uint8 bcdUSB[0];
	0x02,		//		uint8 bcdUSB[1];
	0x00,		//		uint8 bDeviceClass;			0 means: Use class information in the Interface Descriptors
	0x00,		//		uint8 bDeviceSubClass;
	0x00,		//		uint8 bDeviceProtocol;
	0x40,		//		uint8 bMaxPacketSize0;
	0x83,		//		uint8 idVendor[0];	1155
	0x04,		//		uint8 idVendor[1];
	0x2B,		//		uint8 idProduct[0];	22315
	0x57,		//		uint8 idProduct[1];
	0x00,		//		uint8 bcdDevice[0];
	0x02,		//		uint8 bcdDevice[1];
	/*String descriptors are optional. As noted previously, if a device does not support string descriptors, all
	references to string descriptors within device, configuration, and interface descriptors must be reset to zero.*/
	0,//USBD_IDX_MFC_STR,			//		uint8 iManufacter;			(0x01)
	0,//USBD_IDX_PRODUCT_STR,		//		uint8 iProduct;				(0x02)
	0,//USBD_IDX_SERIAL_STR,		//		uint8 iSerialNumber;		(0x03)
	0x01		//		uint8 bNumConfigurations;
};

uint8 FSDeviceQualifierDescriptor[10] =
{
	0x0A,							//uint8 bLength;
	DESC_DEVICE_QUALIFIER,			//uint8 bDescriptorType;
	0x00,							//uint8 bcdUSB[0];
	0x02,							//uint8 bcdUSB[1];
	0x00,							//uint8 bDeviceClass;
	0x00,							//uint8 bDeviceSubClass;
	0x00,							//uint8 bDeviceProtocol;
	0x40,							//uint8 bMaxPacketSize0;
	0x01,							//uint8 bNumConfigurations;
	0x00							//uint8 bReserved;
};

FSConfigurationDescriptorType FSConfigurationDescriptor =
{	//FSConfiguration
   {0x09,					//	uint8 bLength;
	0x02,					//	uint8 bDescriptorType;
   {0x22,					//	uint8 wTotalLength[0];
	0x00},					//	uint8 wTotalLength[1];
	0x01,					//	uint8 bNumInterfaces;
	0x01,					//	uint8 bConfigurationValue;
	0x00,					//	uint8 iConfiguration;
	SET_BM_ATTR(BP_NO,SP_YES,RW_NO),		//	uint8 bmAttributes;
	0x32},					//	uint8 bMaxPower;
	//FSInterface
	{0x09,					//	uint8 bLength;
	0x04,					//	uint8 bDescriptorType;
	0x00,					//	uint8 bInterfaceNumber;
	0x00,					//	uint8 bAlternateSetting;
	0x01,					//	uint8 bNumEndpoints;
	0x03,					//	uint8 bInterfaceClass;	 	0x03: HID (Human Interface Device)
	0x00,					//	uint8 bInterfaceSubClass;	0x01: Boot 0x00: No Boot
	0x01,					//	uint8 bInterfaceProtocol;	0x01: Keyboard
	0x00},					//	uint8 iInterface;
	//FSHid
	{0x09,					//	uint8 bLength;
	0x21,					//	uint8 bDescriptorType;		HID descriptor type (assigned by USB)
	{0x11,					//	uint8 bcdHID[0];
	0x01},					//	uint8 bcdHID[1];
	0x00,					//	uint8 bCountryCode;
	0x01,					//	uint8 bNumDescriptors;
	0x22,					//	uint8 bDescriptorType;		Report descriptor type
	{0x3F,					//	uint8 wDescriptorLength[0];
	0x00}},					//	uint8 wDescriptorLength[1];
	//FSEndpoint
	{0x07,					//	uint8 bLength;
	0x05,					//	uint8 bDescriptorType;
	ENDIN1,					//	uint8 bEndpointAddress;
	ATTR_INTERRUPT,			//	uint8 bmAttributes;
	{0x40,					//	uint8 wMaxPacketSize[0];
	0x00},					//	uint8 wMaxPacketSize[1];
	0x0A}					//	uint8 bInterval;
};

FSConfigurationDescriptorType* FSConfigurationDescriptorArray[1] = {&FSConfigurationDescriptor};


uint8 FSLangIdStringDescriptor[4] =
{
	4U,								//bLength
	DESC_STRING,					//bDescriptorType
	(ENGLISH_USA & 0x00FF),			//LB_wLANGID[0]
	((ENGLISH_USA & 0xFF00) >> 8)	//HB_wLANGID[0]
};


static uint8 GetLen(uint8* str)
{
	uint8 len = 0;

	while(str[len] != (uint8)'\0')
	{
		len++;
	}

	return len;
}

static void GetString(uint8* str, uint8* unicode, uint16* length)
{
	uint8 idx = 0U;
	uint8* pstr = str;
	*length = MIN(USBD_MAX_STR_DESC_SIZ, (((uint16)GetLen(str) + 1) * 2));

	unicode[idx] = *(uint8*)length;
	idx++;
	unicode[idx] = DESC_STRING;
	idx++;

	while(*pstr != (uint8)'\0')
	{
		unicode[idx] = *pstr;
		pstr++;
		idx++;

		unicode[idx] = 0U;
		idx++;
	}
}

static void IntToUnicode(uint32_t value, uint8_t * pbuf, uint8_t len)
{
  uint8_t idx = 0;

  for (idx = 0; idx < len; idx++)
  {
    if (((value >> 28)) < 0xA)
    {
      pbuf[2 * idx] = (value >> 28) + '0';
    }
    else
    {
      pbuf[2 * idx] = (value >> 28) + 'A' - 10;
    }

    value = value << 4;

    pbuf[2 * idx + 1] = 0;
  }
}

static void GetSerial(uint8* unicode, uint16* length)
{
	uint32 deviceSerial0;
	uint32 deviceSerial1;
	uint32 deviceSerial2;

	*length = USB_SIZ_STRING_SERIAL;

	deviceSerial0 = *(uint32*)UID_BASE;
	deviceSerial1 = *(uint32*)(UID_BASE+4);
	deviceSerial2 = *(uint32*)(UID_BASE+8);

	deviceSerial0 += deviceSerial2;

	if(0 != deviceSerial0)
	{
		unicode[0] = USB_SIZ_STRING_SERIAL;
		unicode[1] = DESC_STRING;
		IntToUnicode(deviceSerial0, &unicode[2], 8);
		IntToUnicode(deviceSerial1, &unicode[18], 4);
	}
}

uint8* GetFSDeviceDescriptor(uint16* length)
{
	*length = sizeof(FSDeviceDescriptor);
	return FSDeviceDescriptor;
}

uint8* GetFSDeviceQualifierDescriptor(uint16* length)
{
	*length = sizeof(FSDeviceQualifierDescriptor);
	return FSDeviceQualifierDescriptor;
}

uint8* GetFSConfigDescriptor(uint16* length)
{
	*length = sizeof(FSConfigurationDescriptor);
	return (uint8*)&FSConfigurationDescriptor;
}

uint8* GetFSLangIdStringDescriptor(uint16* length)
{
	*length = sizeof(FSLangIdStringDescriptor);
	return FSLangIdStringDescriptor;
}

uint8* GetFSMfcIdStringDescriptor(uint16* length)
{
	GetString(USBD_MANUFACTURER_STRING, USB_StringUnicode, length);
	return USB_StringUnicode;
}

uint8* GetFSPdcIdStringDescriptor(uint16* length)
{
	GetString((uint8*)USBD_PRODUCT_STRING_FS, USB_StringUnicode, length);
	return USB_StringUnicode;
}

uint8* GetFSSerialStringDescriptor(uint16* length)
{
	GetSerial(USB_StringUnicode, length);
	return USB_StringUnicode;
}

uint8* GetFSConfigStringDescriptor(uint16* length)
{
	GetString(USBD_CONFIGURATION_STRING_FS, USB_StringUnicode, length);
	return USB_StringUnicode;
}

uint8* GetFSInterfaceStringDescriptor(uint16* length)
{
	GetString(USBD_INTERFACE_STRING_FS, USB_StringUnicode, length);
	return USB_StringUnicode;
}


