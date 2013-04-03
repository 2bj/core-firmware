/**
 ******************************************************************************
 * @file    main.h
 * @author  Spark Application Team
 * @version V1.0.0
 * @date    13-March-2013
 * @brief   Header for main.c module
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/

#include "hw_config.h"
#include "hci.h"
#include "wlan.h"
#include "arduinito.h"

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */

/* WLAN Application related callbacks passed to wlan_init */
void WLAN_Async_Callback(long lEventType, char *data, unsigned char length);
char *WLAN_Firmware_Patch(unsigned long *length);
char *WLAN_Driver_Patch(unsigned long *length);
char *WLAN_BootLoader_Patch(unsigned long *length);

#endif /* __MAIN_H */
