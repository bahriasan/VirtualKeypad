#ifndef USB_H
#define USB_H

#include "stm32f407xx.h"
#include "types.h"
#include "usbd_hid.h"
#include "usbd.h"


#define USB_OTG_FS_Global			((USB_OTG_GlobalTypeDef*)(USB_OTG_FS_PERIPH_BASE + USB_OTG_GLOBAL_BASE))
#define USB_OTG_FS_Device			((USB_OTG_DeviceTypeDef*)(USB_OTG_FS_PERIPH_BASE + USB_OTG_DEVICE_BASE))
#define USB_OTG_FS_EPIN_0_Addr		((USB_OTG_INEndpointTypeDef*)(USB_OTG_FS_PERIPH_BASE + USB_OTG_IN_ENDPOINT_BASE))
#define USB_OTG_FS_EPIN_1_Addr		((USB_OTG_INEndpointTypeDef*)(USB_OTG_FS_PERIPH_BASE + USB_OTG_IN_ENDPOINT_BASE + USB_OTG_EP_REG_SIZE))
#define USB_OTG_FS_EPIN_2_Addr		((USB_OTG_INEndpointTypeDef*)(USB_OTG_FS_PERIPH_BASE + USB_OTG_IN_ENDPOINT_BASE + (2 * USB_OTG_EP_REG_SIZE)))
#define USB_OTG_FS_EPIN_3_Addr		((USB_OTG_INEndpointTypeDef*)(USB_OTG_FS_PERIPH_BASE + USB_OTG_IN_ENDPOINT_BASE + (3 * USB_OTG_EP_REG_SIZE)))
#define USB_OTG_FS_EPOUT_0_Addr		((USB_OTG_OUTEndpointTypeDef*)(USB_OTG_FS_PERIPH_BASE + USB_OTG_OUT_ENDPOINT_BASE))
#define USB_OTG_FS_EPOUT_1_Addr		((USB_OTG_OUTEndpointTypeDef*)(USB_OTG_FS_PERIPH_BASE + USB_OTG_OUT_ENDPOINT_BASE + USB_OTG_EP_REG_SIZE))
#define USB_OTG_FS_EPOUT_2_Addr		((USB_OTG_OUTEndpointTypeDef*)(USB_OTG_FS_PERIPH_BASE + USB_OTG_OUT_ENDPOINT_BASE + (2 * USB_OTG_EP_REG_SIZE)))
#define USB_OTG_FS_EPOUT_3_Addr		((USB_OTG_OUTEndpointTypeDef*)(USB_OTG_FS_PERIPH_BASE + USB_OTG_OUT_ENDPOINT_BASE + (3 * USB_OTG_EP_REG_SIZE)))
#define USB_OTG_FS_FIFO_BASE		((uint32*)(USB_OTG_FS_PERIPH_BASE + USB_OTG_FIFO_BASE))
#define USB_OTG_FS_PCGCCTL			((uint32*)(USB_OTG_FS_PERIPH_BASE + USB_OTG_PCGCCTL_BASE))



//DAINT InterruptMask Bit Addresses
#define USB_OTG_DAINT_IEP0M		(1 << USB_OTG_DAINT_IEPINT_Pos)
#define USB_OTG_DAINT_IEP1M		(2 << USB_OTG_DAINT_IEPINT_Pos)
#define USB_OTG_DAINT_IEP2M		(4 << USB_OTG_DAINT_IEPINT_Pos)
#define USB_OTG_DAINT_IEP3M		(8 << USB_OTG_DAINT_IEPINT_Pos)

#define USB_OTG_DAINT_OEP0M		(1 << USB_OTG_DAINT_OEPINT_Pos)
#define USB_OTG_DAINT_OEP1M		(2 << USB_OTG_DAINT_OEPINT_Pos)
#define USB_OTG_DAINT_OEP2M		(4 << USB_OTG_DAINT_OEPINT_Pos)
#define USB_OTG_DAINT_OEP3M		(8 << USB_OTG_DAINT_OEPINT_Pos)

//DAINTMSK InterruptMask Bit Addresses
#define USB_OTG_DAINTMSK_IEP0M	(1 << USB_OTG_DAINTMSK_IEPM_Pos)
#define USB_OTG_DAINTMSK_IEP1M	(2 << USB_OTG_DAINTMSK_IEPM_Pos)
#define USB_OTG_DAINTMSK_IEP2M	(4 << USB_OTG_DAINTMSK_IEPM_Pos)
#define USB_OTG_DAINTMSK_IEP3M	(8 << USB_OTG_DAINTMSK_IEPM_Pos)

#define USB_OTG_DAINTMSK_OEP0M	(1 << USB_OTG_DAINTMSK_OEPM_Pos)
#define USB_OTG_DAINTMSK_OEP1M	(2 << USB_OTG_DAINTMSK_OEPM_Pos)
#define USB_OTG_DAINTMSK_OEP2M	(4 << USB_OTG_DAINTMSK_OEPM_Pos)
#define USB_OTG_DAINTMSK_OEP3M	(8 << USB_OTG_DAINTMSK_OEPM_Pos)

//OTG_FS_GRXSTSP Register PKTSTS Selections
#define OUT_NAK 			0x1UL
#define OUT_DP_RCV 			0x2UL
#define OUT_XFER_CMP 		0x3UL
#define SETUP_TR_CMP  		0x4UL
#define SETUP_DP_RCV 		0x6UL

//OTG_FS_GRXSTSP Register DPID Selections
#define DATA0		0X0UL
#define DATA1		0X2UL
#define DATA2		0X1UL
#define MDATA		0X3UL

#define HOST_MODE 		0x1UL
#define DEVICE_MODE 	0x0UL

//Missing NAK DIEPMSK Definitions
#define USB_OTG_DIEPMSK_NAKM_Pos               (13U)
#define USB_OTG_DIEPMSK_NAKM_Msk               (0x1UL << USB_OTG_DIEPMSK_NAKM_Pos) /*!< 0x00000100 */
#define USB_OTG_DIEPMSK_NAKM                   USB_OTG_DIEPMSK_NAKM_Msk    /*!< FIFO underrun mask */

//Missing Babble Error DOEPINT
#define USB_OTG_DOEPINT_BERR_Pos                (12U)
#define USB_OTG_DOEPINT_BERR_Msk                (0x1UL << USB_OTG_DOEPINT_BERR_Pos) /*!< 0x00001000 */
#define USB_OTG_DOEPINT_BERR                    USB_OTG_DOEPINT_BERR_Msk      /*!< Babble error interrupt                   */

//MPSIZ Definitions for USB_OTG_DIEPCTL
#define USB_OTG_DIEPCTL0_MPSIZ_Pos				(0U)
#define USB_OTG_DIEPCTL0_MPSIZ_Msk				(0x3UL << USB_OTG_DIEPCTL0_MPSIZ_Pos)
#define USB_OTG_DIEPCTL0_MPSIZ					USB_OTG_DIEPCTL0_MPSIZ_Msk

#define BIT_SET		(0x1UL)

//DATA FIFO Address
#define DFIFOAddr(x)							*(uint32*)(USB_OTG_FS_PERIPH_BASE + USB_OTG_FIFO_BASE + ( x * USB_OTG_FIFO_SIZE ))

typedef enum
{
	EP_OUT,
	EP_IN
}EpInOut;

typedef enum
{
	EP_0,
	EP_1,
	EP_2,
	EP_3,
	EP_NA
}Ep_No;

typedef enum
{
	EP_Control,
	EP_Isochronous,
	EP_Bulk,
	EP_Interrupt
}Ep_Type;

typedef enum
{
	USB_Reset,
	Enum_Complete,
	SetAddress_Command,
	SetConfigInt_Command
}EP_Init_Reason_Type;

typedef enum
{
	DEF_STATE,
	ADDR_STATE,
	CFG_STATE
}Usb_State;

typedef enum
{
	STATE_NOTACTIVE,
	STATE_IDLE,
	STATE_BUSY
}EP_State;


typedef struct
{
	Ep_No num;
	EpInOut epDir;
	uint32 maxpacket;
	Ep_Type type;
	uint8* xfer_buffer;
	uint32 xfer_length;
	uint32 xfer_count;
	uint8 idleRate;
	EP_State state;
	USB_OTG_INEndpointTypeDef* InRegAddr;
	USB_OTG_OUTEndpointTypeDef* OutRegAddr;
}EP_Typedef;

typedef struct
{
	uint8 setupData[8];
	uint32 mode;
	boolean FS;
	Usb_State state;
	boolean remoteWU;	//0x00: No Remote WakeUp, 0x01: Remote WakeUp Enabled
	boolean selfPWD;	//0x00: bus-powered, 0x01: self-powered
	uint8 interfaceCount;
	uint32 deviceAddress;
	FSConfigurationDescriptorType* ConfigurationDescriptorArray[1];
	FSConfigurationDescriptorType* CurrentConfigurationDescription;
	USB_OTG_GlobalTypeDef* USB_OTG_FS_CoreRegister;
	USB_OTG_DeviceTypeDef* USB_OTG_FS_DeviceRegister;
	EP_Typedef INEP_Array[2];
	EP_Typedef OUTEP_Array[1];
	uint32* USB_OTG_FS_PCGCCTL_Register;
}Usb_Handler;

void USB_FS_IRQHandler(void);
void Usb_FS_Init(void);
void Usb_FS_SendReport(Usb_Handler* USB_FS_Ptr, uint8* buffer, uint16 size);
void Usb_FS_EP_ActivateAll(Usb_Handler* USB_FS);
void Usb_FS_EP_DeactivateAll(Usb_Handler* USB_FS);
void Helper_CopyByte(void* dst, const void* src, uint32 length);


extern Usb_Handler USB_FS;
extern uint8 inputArray[8];



#endif
