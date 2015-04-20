/**HEADER********************************************************************
* 
* Copyright (c) 2008, 2013 - 2014 Freescale Semiconductor;
* All Rights Reserved
*
*************************************************************************** 
*
* THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR 
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES 
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  
* IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
* THE POSSIBILITY OF SUCH DAMAGE.
*
**************************************************************************
*
* $FileName: usb_otg_prv.h$
* $Version : 
* $Date    : 
*
* Comments:
*
*         
*****************************************************************************/
#ifndef __usb_otg_prv_h__
#define __usb_otg_prv_h__

#include "usb_otg_khci.h"

enum
{
    USB_OTG_PERIPHERAL_MAX3353 = 0,
};

#define USB_OTG_PERIPHERAL_ID    USB_OTG_PERIPHERAL_MAX3353

#if (USB_OTG_PERIPHERAL_ID == USB_OTG_PERIPHERAL_MAX3353)
#include "usb_otg_max3353.h"
#endif

typedef struct usb_otg_peripheral_functions_struct
{
    /* The Host/Device pre-init function */
    usb_status (* otg_peripheral_preinit)(void*, void**);
    /* The Host/Device init function */
    usb_status (* otg_peripheral_init)(void*);
    /* The function to shutdown the host/device */
    usb_status (* otg_peripheral_shutdown)(void*);
    /* The function to get status */
    usb_status (* otg_peripheral_get_status)(void*);
    /* The function to send vbus */
    usb_status (* otg_peripheral_set_vbus)(void*, bool);
    /* The function to set pull downs */
    usb_status (* otg_peripheral_set_pulldowns)(void*,  uint8_t);
    /* The function to set dp pull up */
    usb_status (* otg_peripheral_set_dp_pullup)(void*, bool);
    /* The function to generate resume signal  */
    usb_status (* otg_peripheral_generate_resume)(void*, bool);
} usb_otg_peripheral_functions_struct_t;

typedef struct usb_otg_struct
{
    usb_otg_state_struct_t                 g;
    usb_otg_peripheral_functions_struct_t* peripheral_api_list_ptr;
    usb_otg_khci_call_struct_t  *          khci_call_ptr;
    void*                                  peripheral_call_ptr;
} usb_otg_struct_t;

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif

/* EOF */
