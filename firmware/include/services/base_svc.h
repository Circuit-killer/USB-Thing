
#ifndef BASE_SVC_H
#define BASE_SVC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "em_usb.h"

int base_handle_setup(const USB_Setup_TypeDef *setup);

#ifdef __cplusplus
}
#endif

#endif

