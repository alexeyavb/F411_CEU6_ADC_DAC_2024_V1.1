#ifndef __GLOBALVARIABLES_H__
#define __GLOBALVARIABLES_H__

#ifdef __cplusplus
extern "C" {
#endif
/* Defines ------------------------------------------------------------------*/
#define M_USB_STATUS_UNKNOWN         0x00100U;
#define M_USB_STATUS_UNDEFINED      M_USB_STATUS_UNKNOWN + 0x0DU
#define M_USB_STATUS_DISCONNECTED   M_USB_STATUS_UNDEFINED + 0x01U
#define M_USB_STATUS_CONNECTED      M_USB_STATUS_UNDEFINED + 0x02U
#define M_USB_STATUS_RESET          M_USB_STATUS_UNDEFINED + 0x03U
#define M_USB_STATUS_START          M_USB_STATUS_UNDEFINED + 0x04U
#define M_USB_STATUS_STOP           M_USB_STATUS_UNDEFINED + 0x05U
#define M_USB_STATUS_OPEN_EP        M_USB_STATUS_UNDEFINED + 0x06U
#define M_USB_STATUS_CLOSE_EP       M_USB_STATUS_UNDEFINED + 0x07U
#define M_USB_STATUS_FLUSH_EP       M_USB_STATUS_UNDEFINED + 0x09U
#define M_USB_STATUS_STALL_EP       M_USB_STATUS_UNDEFINED + 0x0AU
#define M_USB_STATUS_CLR_STALL_EP   M_USB_STATUS_UNDEFINED + 0x0BU
#define M_USB_STATUS_SETUP_FIFO     M_USB_STATUS_UNDEFINED + 0x0CU

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
/* USER CODE BEGIN Includes */

#define M_USB_STATUS_FLAG uint16_t
extern M_USB_STATUS_FLAG GlobalUsbStatusFlag;

/* USER CODE END Includes */

#ifdef __cplusplus
}
#endif

#endif /* __GLOBALVARIABLES_H__ */

