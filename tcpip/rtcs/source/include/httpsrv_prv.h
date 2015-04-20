/*HEADER**********************************************************************
*
* Copyright 2013 Freescale Semiconductor, Inc.
*
* This software is owned or controlled by Freescale Semiconductor.
* Use of this software is governed by the Freescale MQX RTOS License
* distributed with this Material.
* See the MQX_RTOS_LICENSE file distributed for more details.
*
* Brief License Summary:
* This software is provided in source form for you to use free of charge,
* but it is not open source software. You are allowed to use this software
* but you cannot redistribute it or derivative works of it in source form.
* The software may be used only in connection with a product containing
* a Freescale microprocessor, microcontroller, or digital signal processor.
* See license agreement file for full license terms including other
* restrictions.
*****************************************************************************
*
* Comments:
*
*   Header for HTTPSRV.
*
*
*END************************************************************************/

#ifndef HTTPSRV_PRV_H_
#define HTTPSRV_PRV_H_

#include <httpsrv.h>
#include <httpsrv_ws_prv.h>

#if 0 == MQX_USE_IO_OLD
#include <stdio.h>
#else
#include <fio.h>
#endif


#define HTTPSRV_SERVER_STACK_SIZE           (1500)
#define HTTPSRV_SESSION_STACK_SIZE          (3000)
#define HTTPSRV_SSL_SERVER_STACK_SIZE       (6000)  /* IAR Release 1500 Debug 6000 */
#define HTTPSRV_SSL_SESSION_STACK_SIZE      (14000) /* IAR. Release 3000 Debug 14000     Origin 18000 */

#define HTTPSRV_PRODUCT_STRING        "RTCS HTTPSRV/2.4 - Freescale Embedded Web Server v2.4"
#define HTTPSRV_PROTOCOL_STRING       "HTTP/1.1"
#define HTTPSRV_CGI_VERSION_STRING    "CGI/1.1"
#define HTTPSRV_SESSION_VALID         (1)
#define HTTPSRV_SESSION_INVALID       (0)
#define HTTPSRV_SES_BUF_SIZE_PRV      (HTTPSRVCFG_SES_BUFFER_SIZE & PSP_MEMORY_ALIGNMENT_MASK)
#define HTTPSRV_CGI_HANDLER_STACK     (850)
#define HTTPSRV_TMP_BUFFER_SIZE       (128)
#define HTTPSRV_CODE_UPGRADE          (101)
#define HTTPSRV_CODE_OK               (200)
#define HTTPSRV_CODE_BAD_REQ          (400)
#define HTTPSRV_CODE_UNAUTHORIZED     (401)
#define HTTPSRV_CODE_FORBIDDEN        (403)
#define HTTPSRV_CODE_NOT_FOUND        (404)
#define HTTPSRV_CODE_NO_LENGTH        (411)
#define HTTPSRV_CODE_URI_TOO_LONG     (414)
#define HTTPSRV_CODE_UPGRADE_REQUIRED (426)
#define HTTPSRV_CODE_INTERNAL_ERROR   (500)
#define HTTPSRV_CODE_NOT_IMPLEMENTED  (501)
#define HTTPSRV_PLUGIN_NUM_MESSAGES   (5)

/*
**  Wildcard typedef for CGI/SSI callback prototype
*/
typedef _mqx_int(*HTTPSRV_FN_CALLBACK)(void *param);

/*
 * Plugin callbacks prototypes
 */
typedef void* (*HTTPSRV_PLUGIN_CREATE_FUNC)(void *message);
typedef void (*HTTPSRV_PLUGIN_DESTROY_FUNC)(void *plugin_context);
typedef void (*HTTPSRV_PLUGIN_WAIT_FUNC)(void *plugin_context);
typedef void (*HTTPSRV_PLUGIN_PROCESS_FUNC)(void *message, void *plugin_context);

/*
 * HTTP server plugin callbacks.
 */
typedef struct httpsrv_plugin_callbacks
{
    HTTPSRV_PLUGIN_CREATE_FUNC  create;
    HTTPSRV_PLUGIN_DESTROY_FUNC destroy;
    HTTPSRV_PLUGIN_WAIT_FUNC    wait;
    HTTPSRV_PLUGIN_PROCESS_FUNC process;
}HTTPSRV_PLUGIN_CALLBACKS;

/*
**  Wildcard data type for CGI/SSI callback link structure
*/
typedef struct httpsrv_fn_link_struct
{
    char*               fn_name;
    HTTPSRV_FN_CALLBACK callback;
    uint32_t            stack_size;
} HTTPSRV_FN_LINK_STRUCT;

/*
** Types of callbacks
*/
typedef enum httpsrv_callback_type
{
    HTTPSRV_CGI_CALLBACK,
    HTTPSRV_SSI_CALLBACK
}HTTPSRV_CALLBACK_TYPE;

/*
* HTTP session state machine status
*/
typedef enum httpsrv_ses_state
{
    HTTPSRV_SES_WAIT_REQ,
    HTTPSRV_SES_PROCESS_REQ,
    HTTPSRV_SES_END_REQ,
    HTTPSRV_SES_CLOSE,
    HTTPSRV_SES_RESP
}HTTPSRV_SES_STATE;

/*
 * Protocols to which session can be upgraded to.
 *
 */
typedef enum httpsrv_upgrade_prot
{
    HTTPSRV_NO_PROTOCOL,
    HTTPSRV_WS_PROTOCOL
}HTTPSRV_UPGRADE_PROT;

/*
* HTTP request parameters
*/
typedef struct httpsrv_req_struct
{
    HTTPSRV_REQ_METHOD       method;          /* Request method (GET, POST, HEAD) */
    int                      content_type;    /* Request entity content type */
    _mqx_int                 content_length;  /* Content length */
    bool                     process_header;  /* Flag for indication of header processing */
    char                     *path;           /* Requested path */
    char                     *query;          /* Data send in URL */
    bool                     has_host;        /* Flag determining if request header has "host" field */
    HTTPSRV_AUTH_USER_STRUCT auth;            /* Authentication credentials received from client */
    bool                     upgrade;         /* Flag indicating if client requested connection upgrade. */
    HTTPSRV_UPGRADE_PROT     upgrade_to;      /* Protocol to upgrade to. Zero = no upgrade. */    
} HTTPSRV_REQ_STRUCT;

/*
* HTTP response parameters
*/
typedef struct httpsrv_res_struct {
#if MQX_USE_IO_OLD
    MQX_FILE*                  file;             /* Handle to a file to send */
#else
    FILE                       *file;            /* Handle to a file to send */
#endif
    _mqx_int                   status_code;      /* Status code - httpsrv_sendhdr transforms it to a text */
    _mqx_int                   len;              /* Response length */
    bool                       cacheable;        /* Determines if response is cacheable */
    bool                       transcoded;       /* Transcoding flag */
    HTTPSRV_AUTH_REALM_STRUCT* auth_realm;       /* Authentication realm */
    int                        content_type;     /* Content type */
    char                       script_buffer[3]; /* Buffer for script tag search. */
    char                       hdrsent;          /* Protection against multiple header sending */
} HTTPSRV_RES_STRUCT;

/*
* HTTP session buffer
*/
typedef struct httpsrv_buffer
{
    uint32_t offset;   /* Write offset */
    char*    data;     /* Buffer data */
}HTTPSRV_BUFF_STRUCT;

/*
 * Session process function prototype
 */
typedef void(*HTTPSRV_SES_FUNC)(void *server, void *session);

/*
* HTTP session structure
*/
typedef struct httpsrv_session_struct
{
    HTTPSRV_SES_FUNC         process_func;       /* Session process function */
    HTTPSRV_SES_STATE        state;              /* HTTP session state */
    volatile bool            valid;              /* non zero (1) = session is valid - data in this entry is valid */
    _mqx_uint                keep_alive;         /* Keep-alive status for the session */
    bool                     keep_alive_enabled; /* Keep-alive enabled/disabled for session */
    volatile _mqx_int        sock;               /* Session socket */
    volatile uint32_t        time;               /* Session time. Updated when there is some activity in session. Used for timeout detection. */
    uint32_t                 timeout;            /* Session timeout in ms. timeout_time = time + timeout */
    HTTPSRV_BUFF_STRUCT      buffer;             /* Session internal read/write buffer */
    HTTPSRV_REQ_STRUCT       request;            /* Data read from the request */
    HTTPSRV_RES_STRUCT       response;           /* Response data */
    LWSEM_STRUCT             lock;               /* Session lock */
    volatile _task_id        script_tid;         /* Session script handler */
    HTTPSRV_PLUGIN_STRUCT    *plugin;            /* Plugin to be invoked for session. */
    HTTPSRV_PLUGIN_CALLBACKS *p_callbacks;       /* Callbacks for selected plugin */
    WS_HANDSHAKE_STRUCT      *ws_handshake;      /* WebSocket hand-shake */
#if RTCSCFG_ENABLE_SSL
    uint32_t                 ssl_sock;           /* SSL context handle */
#endif
} HTTPSRV_SESSION_STRUCT;

/*
 * Message to be send to script handler task.
 */
typedef struct httpsrv_script_msg
{
    HTTPSRV_SESSION_STRUCT  *session;   /* Session requesting script */
    HTTPSRV_CALLBACK_TYPE   type;       /* Type of callback */
    char                    *name;      /* Function name */
    _task_id                ses_tid;    /* Session task id */
}HTTPSRV_SCRIPT_MSG;

/*
 * Message to be send to plugin handler task.
 */
typedef struct httpsrv_plugin_msg
{
    uint32_t                 sock;
    uint8_t                  *buffer;
    HTTPSRV_PLUGIN_STRUCT    *plugin;
    HTTPSRV_PLUGIN_CALLBACKS *callbacks;
}HTTPSRV_PLUGIN_MSG;

/*
** HTTP server main structure.
*/
typedef struct httpsrv_struct
{
    HTTPSRV_PARAM_STRUCT   params;          /* server parameters */
    uint32_t               sock_v4;         /* listening socket for IPv4 */
    uint32_t               sock_v6;         /* listening socket for IPv6 */
    HTTPSRV_SESSION_STRUCT **session;       /* array of pointers to sessions */
    volatile _task_id      server_tid;      /* Server task ID */
    volatile _task_id      *ses_tid;        /* Session task IDs */
    volatile _task_id      script_tid;      /* CGI task ID */
    void*                  script_msgq;     /* Message queue for CGI */
    LWSEM_STRUCT           tid_sem;         /* Semaphore for session TID array locking */
    LWSEM_STRUCT           ses_cnt;         /* Session counter */
    void                   *plugin_queue;   /* Queue for plugin task messages */
    volatile _task_id      plugin_tid;      /* Plugin handler task ID */
#if RTCSCFG_ENABLE_SSL
    void                   *ssl_ctx;        /* Pointer to SSL context */ 
#endif
} HTTPSRV_STRUCT;

/*
** Parameter for session task
*/
typedef struct httpsrv_ses_task_param
{
    HTTPSRV_STRUCT *server;  /* Pointer to server structure */
    uint32_t        sock;    /* Socket to be used by session */
} HTTPSRV_SES_TASK_PARAM;

/*
 * Parameters for detached script task
 */
typedef struct httpsrv_det_task_param
{
    HTTPSRV_SESSION_STRUCT* session;        /* Session to start task for. */
    HTTPSRV_CALLBACK_TYPE   type;           /* Callback type (SSI/CGI) */
    HTTPSRV_FN_CALLBACK     user_function;  /* User function to be called */
    uint32_t                stack_size;     /* Stack size for detached task */
    char*                   script_name;    /* Name of script */
} HTTPSRV_DET_TASK_PARAM;

/*
 * Parameters for server task
 */
typedef struct httpsrv_server_task_param
{
    uint32_t              handle;    /* [out] Server handle, non-zero if initialization was successful */
    HTTPSRV_PARAM_STRUCT *params;    /* [in] Server parameters */
}HTTPSRV_SERVER_TASK_PARAM;

/*
 * Parameters for plugin handler task
 */
typedef struct httpsrv_plugin_task_param
{
    /* Server pointer. */
    HTTPSRV_STRUCT    *server;
}HTTPSRV_PLUGIN_TASK_PARAM;

#ifdef __cplusplus
extern "C" {
#endif

void httpsrv_server_task(void *init_ptr, void *creator);
void httpsrv_script_task(void *param, void *creator);
void httpsrv_detached_task(void *param, void *creator);
void httpsrv_http_process(void *server_ptr, void *session_ptr);

#ifdef __cplusplus
}
#endif

#endif /* HTTP_PRV_H_ */
