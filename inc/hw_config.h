/**
 ******************************************************************************
 * @file    hw_config.h
 * @author  Spark Application Team
 * @version V1.0.0
 * @date    13-March-2013
 * @brief   Hardware Configuration & Setup
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __HW_CONFIG_H
#define __HW_CONFIG_H
/* Includes ------------------------------------------------------------------*/

#include "platform_config.h"
#include "cc3000_common.h"
#include "usb_type.h"

/* Exported types ------------------------------------------------------------*/
typedef enum
{
	LOW = 0, HIGH = 1
} DIO_State_TypeDef;

typedef enum
{
	FAIL = -1, OK = 0
} DIO_Error_TypeDef;

typedef enum
{
	D0 = 0, D1 = 1, D2 = 2, D3 = 3, D4 = 4, D5 = 5, D6 = 6, D7 = 7
} DIO_TypeDef;

typedef enum
{
	LED1 = 0, LED2 = 1, LED3 = 2, LED4 = 3, LED3_LED4_LED2 = 231
} Led_TypeDef;

typedef enum
{
	BUTTON1 = 0, BUTTON2 = 1
} Button_TypeDef;

typedef enum
{
	BUTTON_MODE_GPIO = 0, BUTTON_MODE_EXTI = 1
} ButtonMode_TypeDef;

typedef enum
{
	CC3000_DMA_TX = 0, CC3000_DMA_RX = 1
} CC3000_DMADirection_TypeDef;

/* Exported constants --------------------------------------------------------*/

/* Exported macros ------------------------------------------------------------*/

/* Select CC3000: ChipSelect pin low */
#define CC3000_CS_LOW()		GPIO_ResetBits(CC3000_WIFI_CS_GPIO_PORT, CC3000_WIFI_CS_PIN)
/* Deselect CC3000: ChipSelect pin high */
#define CC3000_CS_HIGH()	GPIO_SetBits(CC3000_WIFI_CS_GPIO_PORT, CC3000_WIFI_CS_PIN)

/* Select sFLASH: Chip Select pin low */
#define sFLASH_CS_LOW()		GPIO_ResetBits(sFLASH_MEM_CS_GPIO_PORT, sFLASH_MEM_CS_PIN)
/* Deselect sFLASH: Chip Select pin high */
#define sFLASH_CS_HIGH()	GPIO_SetBits(sFLASH_MEM_CS_GPIO_PORT, sFLASH_MEM_CS_PIN)

#define USART_RX_DATA_SIZE	256	//2048

#if defined (USE_SPARK_CORE_V02)
//Extended LED Types
#define LED_RED				LED3
#define LED_GREEN			LED4
#define LED_BLUE			LED2
#define LED_RGB				LED3_LED4_LED2
#define LED_USER			LED1

//RGB Basic Colors
#define RGB_COLOR_RED		0xFF0000
#define RGB_COLOR_GREEN		0x00FF00
#define RGB_COLOR_BLUE		0x0000FF
#define RGB_COLOR_YELLOW	0xFFFF00
#define RGB_COLOR_CYAN		0x00FFFF
#define RGB_COLOR_MAGENTA	0xFF00FF
#define RGB_COLOR_WHITE		0xFFFFFF
#endif

/* Exported functions ------------------------------------------------------- */
void Set_System(void);
void NVIC_Configuration(void);

#if defined (USE_SPARK_CORE_V02)
void RTC_Configuration(void);
#endif

void IWDG_Reset_Enable(uint32_t msTimeout);

void DIO_Init(DIO_TypeDef Dx);
DIO_Error_TypeDef DIO_SetState(DIO_TypeDef Dx, DIO_State_TypeDef State);

void UI_Timer_Configure(void);

#if defined (USE_SPARK_CORE_V02)
void LED_SetRGBColor(uint32_t RGB_Color);

//
//	optionally lets the user firmware take control of the RGB led, for testing purposes
//

void Set_RGBUserMode(int override);
void USERLED_SetRGBColor(uint32_t RGB_Color);
void USERLED_On(Led_TypeDef Led);
void USERLED_Off(Led_TypeDef Led);
void USERLED_Toggle(Led_TypeDef Led);
void USERLED_Fade(Led_TypeDef Led);
#endif

void LED_Init(Led_TypeDef Led);
void LED_On(Led_TypeDef Led);
void LED_Off(Led_TypeDef Led);
void LED_Toggle(Led_TypeDef Led);
void LED_Fade(Led_TypeDef Led);

void BUTTON_Init(Button_TypeDef Button, ButtonMode_TypeDef Button_Mode);
void BUTTON_EXTI_Config(Button_TypeDef Button, FunctionalState NewState);
uint8_t BUTTON_GetState(Button_TypeDef Button);
uint16_t BUTTON_GetDebouncedTime(Button_TypeDef Button);
void BUTTON_ResetDebouncedState(Button_TypeDef Button);

/* CC3000 Hardware related methods */
void CC3000_WIFI_Init(void);
void CC3000_SPI_Init(void);
void CC3000_DMA_Config(CC3000_DMADirection_TypeDef Direction, uint8_t* buffer, uint16_t NumData);
void CC3000_SPI_DMA_Init(void);
void CC3000_SPI_DMA_Channels(FunctionalState NewState);

/* CC3000 Hardware related callbacks passed to wlan_init */
long CC3000_Read_Interrupt_Pin(void);
void CC3000_Interrupt_Enable(void);
void CC3000_Interrupt_Disable(void);
void CC3000_Write_Enable_Pin(unsigned char val);

/* Serial Flash Hardware related methods */
void sFLASH_SPI_DeInit(void);
void sFLASH_SPI_Init(void);

/* USB hardware peripheral related methods */
void USB_Disconnect_Config(void);
void Set_USBClock(void);
void Enter_LowPowerMode(void);
void Leave_LowPowerMode(void);
void USB_Interrupts_Config(void);
void USB_Cable_Config(FunctionalState NewState);
void USB_USART_Init(uint32_t baudRate);
uint8_t USB_USART_Available_Data(void);
int32_t USB_USART_Receive_Data(void);
void USB_USART_Send_Data(uint8_t Data);
void Handle_USBAsynchXfer(void);
void Get_SerialNum(void);

/* External variables --------------------------------------------------------*/
extern unsigned char wlan_rx_buffer[];
extern unsigned char wlan_tx_buffer[];

#endif  /*__HW_CONFIG_H*/
