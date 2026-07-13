// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/* DO NOT EDIT. Generated from components/cronet/native/generated/tt_quiche.idl
 */

#ifndef COMPONENTS_CRONET_NATIVE_GENERATED_TT_QUICHE_IDL_C_H_
#define COMPONENTS_CRONET_NATIVE_GENERATED_TT_QUICHE_IDL_C_H_
#include "cronet_export.h"

#include "cronet.idl_c.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef const char* Cronet_String;
typedef void* Cronet_RawDataPtr;
typedef void* Cronet_ClientContext;

// Forward declare interfaces.
typedef struct TTQuicHe_Engine TTQuicHe_Engine;
typedef struct TTQuicHe_Engine* TTQuicHe_EnginePtr;
typedef struct TTQuicHe_PreconnectCallback TTQuicHe_PreconnectCallback;
typedef struct TTQuicHe_PreconnectCallback* TTQuicHe_PreconnectCallbackPtr;
typedef struct TTQuicHe_HttpRequest TTQuicHe_HttpRequest;
typedef struct TTQuicHe_HttpRequest* TTQuicHe_HttpRequestPtr;
typedef struct TTQuicHe_HttpRequestCallback TTQuicHe_HttpRequestCallback;
typedef struct TTQuicHe_HttpRequestCallback* TTQuicHe_HttpRequestCallbackPtr;

// Forward declare structs.
typedef struct TTQuicHe_PreconnectInfo TTQuicHe_PreconnectInfo;
typedef struct TTQuicHe_PreconnectInfo* TTQuicHe_PreconnectInfoPtr;
typedef struct TTQuicHe_HttpInfo TTQuicHe_HttpInfo;
typedef struct TTQuicHe_HttpInfo* TTQuicHe_HttpInfoPtr;
typedef struct TTQuicHe_HostParams TTQuicHe_HostParams;
typedef struct TTQuicHe_HostParams* TTQuicHe_HostParamsPtr;

// Declare enums
typedef enum TTQuicHe_RESULT {
  TTQuicHe_RESULT_SUCCESS = 0,
  TTQuicHe_RESULT_ILLEGAL_ARGUMENT = -100,
  TTQuicHe_RESULT_ILLEGAL_ARGUMENT_STORAGE_PATH_MUST_EXIST = -101,
  TTQuicHe_RESULT_ILLEGAL_ARGUMENT_INVALID_URL = -102,
  TTQuicHe_RESULT_ILLEGAL_ARGUMENT_INVALID_HTTP_METHOD = -103,
  TTQuicHe_RESULT_ILLEGAL_ARGUMENT_INVALID_HTTP_HEADER = -104,
  TTQuicHe_RESULT_ILLEGAL_ARGUMENT_INVALID_HTTP_PROTOCOL = -105,
  TTQuicHe_RESULT_ILLEGAL_ARGUMENT_EMPTY_ADDRESS_LIST = -107,
  TTQuicHe_RESULT_ILLEGAL_ARGUMENT_INVALID_ADDRESS = -108,
  TTQuicHe_RESULT_ILLEGAL_IO_STATE = -200,
  TTQuicHe_RESULT_ILLEGAL_STATE_STORAGE_PATH_IN_USE = -201,
  TTQuicHe_RESULT_ILLEGAL_STATE_ENGINE_ALREADY_STARTED = -203,
  TTQuicHe_RESULT_ILLEGAL_STATE_REQUEST_ALREADY_STARTED = -204,
  TTQuicHe_RESULT_ILLEGAL_STATE_REQUEST_NOT_INITIALIZED = -205,
  TTQuicHe_RESULT_ILLEGAL_STATE_REQUEST_ALREADY_INITIALIZED = -206,
  TTQuicHe_RESULT_ILLEGAL_STATE_REQUEST_NOT_STARTED = -207,
  TTQuicHe_RESULT_ILLEGAL_STATE_ENGINE_ALREADY_SHUTDOWN = -211,
  TTQuicHe_RESULT_ILLEGAL_STATE_SESSION_NOT_CREATED = -212,
  TTQuicHe_RESULT_ILLEGAL_STATE_METHOD_DISABLED = -213,
  TTQuicHe_RESULT_NULL_POINTER = -300,
  TTQuicHe_RESULT_NULL_POINTER_ENGINE = -304,
  TTQuicHe_RESULT_NULL_POINTER_CALLBACK = -306,
  TTQuicHe_RESULT_NULL_POINTER_HEADER_NAME = -309,
  TTQuicHe_RESULT_NULL_POINTER_HEADER_VALUE = -310,
  TTQuicHe_RESULT_NULL_POINTER_REQUEST_PARAMS = -311,
  TTQuicHe_RESULT_NULL_POINTER_HOST_PARAMS = -312,
  TTQuicHe_RESULT_RESPONSE_FAILED_TIMEOUT = -400,
  TTQuicHe_RESULT_RESPONSE_FAILED_WITH_EMPTY = -401,
  TTQuicHe_RESULT_RESPONSE_FAILED_HAS_BODY_TO_SENT = -402,
  TTQuicHe_RESULT_RESPONSE_FAILED_REQUEST_CLOSED = -403,
  TTQuicHe_RESULT_RESPONSE_FAILED_INVALID_RESULT = -404,
  TTQuicHe_RESULT_RESPONSE_FAILED_NO_RESULT = -405,
  TTQuicHe_RESULT_WRITE_IO_PENDING = -500,
  TTQuicHe_RESULT_WRITE_FAILED = -501,
  TTQuicHe_RESULT_WRITE_SYNC_ALREADY_PENDED = -502,
  TTQuicHe_RESULT_WRITE_SYNC_FAILED_TIMEOUT = -503,
  TTQuicHe_RESULT_WRITE_SYNC_FAILED_ERROR = -504,
  TTQuicHe_RESULT_WRITE_SYNC_FAILED_REQUEST_NOT_READY = -505,
  TTQuicHe_RESULT_WRITE_SYNC_FAILED_REQUEST_CANCELED = -506,
  TTQuicHe_RESULT_WRITE_SYNC_FAILED_REQUEST_FAILED = -507,
  TTQuicHe_RESULT_WRITE_SYNC_FAILED_SESSION_UNAVAILABLE = -508,
  TTQuicHe_RESULT_READ_ASYNC_IO_PENDING = -600,
  TTQuicHe_RESULT_READ_ASYNC_FAILED = -601,
  TTQuicHe_RESULT_READ_ASYNC_ALREADY_PENDED = -602,
  TTQuicHe_RESULT_READ_SYNC_IO_PENDING = -603,
  TTQuicHe_RESULT_READ_SYNC_FAILED = -604,
  TTQuicHe_RESULT_READ_SYNC_ALREADY_PENDED = -605,
  TTQuicHe_RESULT_READ_SYNC_UNINVOKED = -606,
  TTQuicHe_RESULT_SAFE_READ_FAILED_ALREADY_PENDED = -607,
  TTQuicHe_RESULT_SAFE_READ_FAILED_SYNC_WITH_BUFFER = -608,
  TTQuicHe_RESULT_SAFE_READ_FAILED_ASYNC_WITHOUT_BUFFER = -609,
  TTQuicHe_RESULT_READ_FAILED_REQUEST_ALREADY_DONE = -610,
  TTQuicHe_RESULT_REQUEST_FAILED_FIN_RECEIVED_BUT_READ_NOT_DONE = -700,
  TTQuicHe_RESULT_REQUEST_FAILED_FIN_NOT_RECEIVED = -701,
  TTQuicHe_RESULT_REQUEST_CANCELED_BY_REQUEST_TIMEOUT = -702,
  TTQuicHe_RESULT_REQUEST_CANCELED_BY_CONNECT_TIMEOUT = -703,
  TTQuicHe_RESULT_REQUEST_CANCELED_BY_APPLICATION = -704,
  TTQuicHe_RESULT_REQUEST_CANCELED_BY_APPLICATION_BEFORE_STARTED = -705,
  TTQuicHe_RESULT_REQUEST_CANCELED_BY_APPLICATION_AFTER_STOPPED = -706,
  TTQuicHe_RESULT_REQUEST_CANCELED_BY_RESPONSE_HEADER_TIMEOUT = -707,
  TTQuicHe_RESULT_REQUEST_CANCELED_BY_READ_TIMEOUT = -708,
  TTQuicHe_RESULT_REQUEST_FAILED_TO_CREATE_STREAM = -709,
} TTQuicHe_RESULT;

typedef enum TTQuicHe_HTTP_PROTOCOL {
  TTQuicHe_HTTP_PROTOCOL_UNKNOWN = 0,
  TTQuicHe_HTTP_PROTOCOL_HTTP1_1 = 1,
  TTQuicHe_HTTP_PROTOCOL_HTTP2 = 2,
  TTQuicHe_HTTP_PROTOCOL_HTTP3 = 3,
  TTQuicHe_HTTP_PROTOCOL_QUIC = TTQuicHe_HTTP_PROTOCOL_HTTP3,
  TTQuicHe_HTTP_PROTOCOL_LAST = TTQuicHe_HTTP_PROTOCOL_HTTP3,
} TTQuicHe_HTTP_PROTOCOL;

typedef enum TTQuicHe_HttpInfo_EVENT_TYPE {
  TTQuicHe_HttpInfo_EVENT_TYPE_NONE = 0,
  TTQuicHe_HttpInfo_EVENT_TYPE_HANDSHAKE_START = 1,
  TTQuicHe_HttpInfo_EVENT_TYPE_HANDSHAKE_END = 2,
  TTQuicHe_HttpInfo_EVENT_TYPE_REQUEST_SENT = 3,
  TTQuicHe_HttpInfo_EVENT_TYPE_RESPONSE_RECEIVED = 4,
  TTQuicHe_HttpInfo_EVENT_TYPE_REQUEST_DONE = 5,
} TTQuicHe_HttpInfo_EVENT_TYPE;

// Declare constants

///////////////////////
// Concrete interface TTQuicHe_Engine.

// Create an instance of TTQuicHe_Engine.
CRONET_EXPORT TTQuicHe_EnginePtr TTQuicHe_Engine_Create(void);
// Destroy an instance of TTQuicHe_Engine.
CRONET_EXPORT void TTQuicHe_Engine_Destroy(TTQuicHe_EnginePtr self);
// Set and get app-specific Cronet_ClientContext.
CRONET_EXPORT void TTQuicHe_Engine_SetClientContext(
    TTQuicHe_EnginePtr self,
    Cronet_ClientContext client_context);
CRONET_EXPORT Cronet_ClientContext
TTQuicHe_Engine_GetClientContext(TTQuicHe_EnginePtr self);
// Concrete methods of TTQuicHe_Engine implemented by Cronet.
// The app calls them to manipulate TTQuicHe_Engine.
CRONET_EXPORT
TTQuicHe_RESULT TTQuicHe_Engine_StartWithParams(TTQuicHe_EnginePtr self,
                                                Cronet_EngineParamsPtr params);
CRONET_EXPORT
TTQuicHe_RESULT TTQuicHe_Engine_Shutdown(TTQuicHe_EnginePtr self);
CRONET_EXPORT
void TTQuicHe_Engine_Destroy(TTQuicHe_EnginePtr self);
CRONET_EXPORT
TTQuicHe_RESULT TTQuicHe_Engine_UpdateHostConfig(TTQuicHe_EnginePtr self,
                                                 Cronet_String json_str);
CRONET_EXPORT
TTQuicHe_RESULT TTQuicHe_Engine_UpdateAltSvcResponse(TTQuicHe_EnginePtr self,
                                                     Cronet_String host,
                                                     Cronet_String altsvc_str);
CRONET_EXPORT
bool TTQuicHe_Engine_IsHostSupportProtocol(
    TTQuicHe_EnginePtr self,
    Cronet_String host,
    TTQuicHe_HTTP_PROTOCOL http_protocol);
CRONET_EXPORT
TTQuicHe_RESULT TTQuicHe_Engine_Preconnect(
    TTQuicHe_EnginePtr self,
    Cronet_String host,
    int32_t port,
    TTQuicHe_HostParamsPtr host_params,
    TTQuicHe_PreconnectCallbackPtr callback);
CRONET_EXPORT
TTQuicHe_PreconnectInfoPtr TTQuicHe_Engine_IsHostConnected(
    TTQuicHe_EnginePtr self,
    Cronet_String host,
    int32_t port,
    TTQuicHe_HTTP_PROTOCOL http_protocol);
// Concrete interface TTQuicHe_Engine is implemented by Cronet.
// The app can implement these for testing / mocking.
typedef TTQuicHe_RESULT (*TTQuicHe_Engine_StartWithParamsFunc)(
    TTQuicHe_EnginePtr self,
    Cronet_EngineParamsPtr params);
typedef TTQuicHe_RESULT (*TTQuicHe_Engine_ShutdownFunc)(
    TTQuicHe_EnginePtr self);
typedef void (*TTQuicHe_Engine_DestroyFunc)(TTQuicHe_EnginePtr self);
typedef TTQuicHe_RESULT (*TTQuicHe_Engine_UpdateHostConfigFunc)(
    TTQuicHe_EnginePtr self,
    Cronet_String json_str);
typedef TTQuicHe_RESULT (*TTQuicHe_Engine_UpdateAltSvcResponseFunc)(
    TTQuicHe_EnginePtr self,
    Cronet_String host,
    Cronet_String altsvc_str);
typedef bool (*TTQuicHe_Engine_IsHostSupportProtocolFunc)(
    TTQuicHe_EnginePtr self,
    Cronet_String host,
    TTQuicHe_HTTP_PROTOCOL http_protocol);
typedef TTQuicHe_RESULT (*TTQuicHe_Engine_PreconnectFunc)(
    TTQuicHe_EnginePtr self,
    Cronet_String host,
    int32_t port,
    TTQuicHe_HostParamsPtr host_params,
    TTQuicHe_PreconnectCallbackPtr callback);
typedef TTQuicHe_PreconnectInfoPtr (*TTQuicHe_Engine_IsHostConnectedFunc)(
    TTQuicHe_EnginePtr self,
    Cronet_String host,
    int32_t port,
    TTQuicHe_HTTP_PROTOCOL http_protocol);
// Concrete interface TTQuicHe_Engine is implemented by Cronet.
// The app can use this for testing / mocking.
CRONET_EXPORT TTQuicHe_EnginePtr TTQuicHe_Engine_CreateWith(
    TTQuicHe_Engine_StartWithParamsFunc StartWithParamsFunc,
    TTQuicHe_Engine_ShutdownFunc ShutdownFunc,
    TTQuicHe_Engine_DestroyFunc DestroyFunc,
    TTQuicHe_Engine_UpdateHostConfigFunc UpdateHostConfigFunc,
    TTQuicHe_Engine_UpdateAltSvcResponseFunc UpdateAltSvcResponseFunc,
    TTQuicHe_Engine_IsHostSupportProtocolFunc IsHostSupportProtocolFunc,
    TTQuicHe_Engine_PreconnectFunc PreconnectFunc,
    TTQuicHe_Engine_IsHostConnectedFunc IsHostConnectedFunc);

///////////////////////
// Abstract interface TTQuicHe_PreconnectCallback is implemented by the app.

// There is no method to create a concrete implementation.

// Destroy an instance of TTQuicHe_PreconnectCallback.
CRONET_EXPORT void TTQuicHe_PreconnectCallback_Destroy(
    TTQuicHe_PreconnectCallbackPtr self);
// Set and get app-specific Cronet_ClientContext.
CRONET_EXPORT void TTQuicHe_PreconnectCallback_SetClientContext(
    TTQuicHe_PreconnectCallbackPtr self,
    Cronet_ClientContext client_context);
CRONET_EXPORT Cronet_ClientContext TTQuicHe_PreconnectCallback_GetClientContext(
    TTQuicHe_PreconnectCallbackPtr self);
// Abstract interface TTQuicHe_PreconnectCallback is implemented by the app.
// The following concrete methods forward call to app implementation.
// The app doesn't normally call them.
CRONET_EXPORT
void TTQuicHe_PreconnectCallback_OnFinished(
    TTQuicHe_PreconnectCallbackPtr self,
    TTQuicHe_PreconnectInfoPtr preconnect_info);
// The app implements abstract interface TTQuicHe_PreconnectCallback by defining
// custom functions for each method.
typedef void (*TTQuicHe_PreconnectCallback_OnFinishedFunc)(
    TTQuicHe_PreconnectCallbackPtr self,
    TTQuicHe_PreconnectInfoPtr preconnect_info);
// The app creates an instance of TTQuicHe_PreconnectCallback by providing
// custom functions for each method.
CRONET_EXPORT TTQuicHe_PreconnectCallbackPtr
TTQuicHe_PreconnectCallback_CreateWith(
    TTQuicHe_PreconnectCallback_OnFinishedFunc OnFinishedFunc);

///////////////////////
// Concrete interface TTQuicHe_HttpRequest.

// Create an instance of TTQuicHe_HttpRequest.
CRONET_EXPORT TTQuicHe_HttpRequestPtr TTQuicHe_HttpRequest_Create(void);
// Destroy an instance of TTQuicHe_HttpRequest.
CRONET_EXPORT void TTQuicHe_HttpRequest_Destroy(TTQuicHe_HttpRequestPtr self);
// Set and get app-specific Cronet_ClientContext.
CRONET_EXPORT void TTQuicHe_HttpRequest_SetClientContext(
    TTQuicHe_HttpRequestPtr self,
    Cronet_ClientContext client_context);
CRONET_EXPORT Cronet_ClientContext
TTQuicHe_HttpRequest_GetClientContext(TTQuicHe_HttpRequestPtr self);
// Concrete methods of TTQuicHe_HttpRequest implemented by Cronet.
// The app calls them to manipulate TTQuicHe_HttpRequest.
CRONET_EXPORT
TTQuicHe_RESULT TTQuicHe_HttpRequest_InitWithParams(
    TTQuicHe_HttpRequestPtr self,
    TTQuicHe_EnginePtr engine,
    Cronet_String url,
    bool fin,
    int64_t read_buffer_size,
    TTQuicHe_HttpRequestCallbackPtr callback,
    Cronet_UrlRequestParamsPtr request_params,
    TTQuicHe_HostParamsPtr host_params);
CRONET_EXPORT
TTQuicHe_RESULT TTQuicHe_HttpRequest_Start(TTQuicHe_HttpRequestPtr self);
CRONET_EXPORT
void TTQuicHe_HttpRequest_Cancel(TTQuicHe_HttpRequestPtr self);
CRONET_EXPORT
void TTQuicHe_HttpRequest_Destroy(TTQuicHe_HttpRequestPtr self);
CRONET_EXPORT
bool TTQuicHe_HttpRequest_IsDone(TTQuicHe_HttpRequestPtr self);
CRONET_EXPORT
Cronet_String TTQuicHe_HttpRequest_GetRequestLog(TTQuicHe_HttpRequestPtr self);
CRONET_EXPORT
int64_t TTQuicHe_HttpRequest_UnsafeWrite(TTQuicHe_HttpRequestPtr self,
                                         Cronet_RawDataPtr body,
                                         uint64_t body_len,
                                         bool fin);
CRONET_EXPORT
TTQuicHe_RESULT TTQuicHe_HttpRequest_Read(TTQuicHe_HttpRequestPtr self,
                                          int64_t read_limit);
// Concrete interface TTQuicHe_HttpRequest is implemented by Cronet.
// The app can implement these for testing / mocking.
typedef TTQuicHe_RESULT (*TTQuicHe_HttpRequest_InitWithParamsFunc)(
    TTQuicHe_HttpRequestPtr self,
    TTQuicHe_EnginePtr engine,
    Cronet_String url,
    bool fin,
    int64_t read_buffer_size,
    TTQuicHe_HttpRequestCallbackPtr callback,
    Cronet_UrlRequestParamsPtr request_params,
    TTQuicHe_HostParamsPtr host_params);
typedef TTQuicHe_RESULT (*TTQuicHe_HttpRequest_StartFunc)(
    TTQuicHe_HttpRequestPtr self);
typedef void (*TTQuicHe_HttpRequest_CancelFunc)(TTQuicHe_HttpRequestPtr self);
typedef void (*TTQuicHe_HttpRequest_DestroyFunc)(TTQuicHe_HttpRequestPtr self);
typedef bool (*TTQuicHe_HttpRequest_IsDoneFunc)(TTQuicHe_HttpRequestPtr self);
typedef Cronet_String (*TTQuicHe_HttpRequest_GetRequestLogFunc)(
    TTQuicHe_HttpRequestPtr self);
typedef int64_t (*TTQuicHe_HttpRequest_UnsafeWriteFunc)(
    TTQuicHe_HttpRequestPtr self,
    Cronet_RawDataPtr body,
    uint64_t body_len,
    bool fin);
typedef TTQuicHe_RESULT (*TTQuicHe_HttpRequest_ReadFunc)(
    TTQuicHe_HttpRequestPtr self,
    int64_t read_limit);
// Concrete interface TTQuicHe_HttpRequest is implemented by Cronet.
// The app can use this for testing / mocking.
CRONET_EXPORT TTQuicHe_HttpRequestPtr TTQuicHe_HttpRequest_CreateWith(
    TTQuicHe_HttpRequest_InitWithParamsFunc InitWithParamsFunc,
    TTQuicHe_HttpRequest_StartFunc StartFunc,
    TTQuicHe_HttpRequest_CancelFunc CancelFunc,
    TTQuicHe_HttpRequest_DestroyFunc DestroyFunc,
    TTQuicHe_HttpRequest_IsDoneFunc IsDoneFunc,
    TTQuicHe_HttpRequest_GetRequestLogFunc GetRequestLogFunc,
    TTQuicHe_HttpRequest_UnsafeWriteFunc UnsafeWriteFunc,
    TTQuicHe_HttpRequest_ReadFunc ReadFunc);

///////////////////////
// Abstract interface TTQuicHe_HttpRequestCallback is implemented by the app.

// There is no method to create a concrete implementation.

// Destroy an instance of TTQuicHe_HttpRequestCallback.
CRONET_EXPORT void TTQuicHe_HttpRequestCallback_Destroy(
    TTQuicHe_HttpRequestCallbackPtr self);
// Set and get app-specific Cronet_ClientContext.
CRONET_EXPORT void TTQuicHe_HttpRequestCallback_SetClientContext(
    TTQuicHe_HttpRequestCallbackPtr self,
    Cronet_ClientContext client_context);
CRONET_EXPORT Cronet_ClientContext
TTQuicHe_HttpRequestCallback_GetClientContext(
    TTQuicHe_HttpRequestCallbackPtr self);
// Abstract interface TTQuicHe_HttpRequestCallback is implemented by the app.
// The following concrete methods forward call to app implementation.
// The app doesn't normally call them.
CRONET_EXPORT
void TTQuicHe_HttpRequestCallback_OnEvent(TTQuicHe_HttpRequestCallbackPtr self,
                                          TTQuicHe_HttpRequestPtr request,
                                          TTQuicHe_HttpInfoPtr info);
CRONET_EXPORT
void TTQuicHe_HttpRequestCallback_OnWriteStarted(
    TTQuicHe_HttpRequestCallbackPtr self,
    TTQuicHe_HttpRequestPtr request);
CRONET_EXPORT
void TTQuicHe_HttpRequestCallback_OnResponseStarted(
    TTQuicHe_HttpRequestCallbackPtr self,
    TTQuicHe_HttpRequestPtr request,
    Cronet_UrlResponseInfoPtr response_info,
    TTQuicHe_HttpInfoPtr info);
CRONET_EXPORT
void TTQuicHe_HttpRequestCallback_OnReadCompleted(
    TTQuicHe_HttpRequestCallbackPtr self,
    TTQuicHe_HttpRequestPtr request,
    Cronet_BufferPtr buffer,
    uint64_t bytes_read);
CRONET_EXPORT
void TTQuicHe_HttpRequestCallback_OnSucceeded(
    TTQuicHe_HttpRequestCallbackPtr self,
    TTQuicHe_HttpRequestPtr request);
CRONET_EXPORT
void TTQuicHe_HttpRequestCallback_OnFailed(TTQuicHe_HttpRequestCallbackPtr self,
                                           TTQuicHe_HttpRequestPtr request,
                                           TTQuicHe_RESULT result);
CRONET_EXPORT
void TTQuicHe_HttpRequestCallback_OnCanceled(
    TTQuicHe_HttpRequestCallbackPtr self,
    TTQuicHe_HttpRequestPtr request,
    TTQuicHe_RESULT result);
// The app implements abstract interface TTQuicHe_HttpRequestCallback by
// defining custom functions for each method.
typedef void (*TTQuicHe_HttpRequestCallback_OnEventFunc)(
    TTQuicHe_HttpRequestCallbackPtr self,
    TTQuicHe_HttpRequestPtr request,
    TTQuicHe_HttpInfoPtr info);
typedef void (*TTQuicHe_HttpRequestCallback_OnWriteStartedFunc)(
    TTQuicHe_HttpRequestCallbackPtr self,
    TTQuicHe_HttpRequestPtr request);
typedef void (*TTQuicHe_HttpRequestCallback_OnResponseStartedFunc)(
    TTQuicHe_HttpRequestCallbackPtr self,
    TTQuicHe_HttpRequestPtr request,
    Cronet_UrlResponseInfoPtr response_info,
    TTQuicHe_HttpInfoPtr info);
typedef void (*TTQuicHe_HttpRequestCallback_OnReadCompletedFunc)(
    TTQuicHe_HttpRequestCallbackPtr self,
    TTQuicHe_HttpRequestPtr request,
    Cronet_BufferPtr buffer,
    uint64_t bytes_read);
typedef void (*TTQuicHe_HttpRequestCallback_OnSucceededFunc)(
    TTQuicHe_HttpRequestCallbackPtr self,
    TTQuicHe_HttpRequestPtr request);
typedef void (*TTQuicHe_HttpRequestCallback_OnFailedFunc)(
    TTQuicHe_HttpRequestCallbackPtr self,
    TTQuicHe_HttpRequestPtr request,
    TTQuicHe_RESULT result);
typedef void (*TTQuicHe_HttpRequestCallback_OnCanceledFunc)(
    TTQuicHe_HttpRequestCallbackPtr self,
    TTQuicHe_HttpRequestPtr request,
    TTQuicHe_RESULT result);
// The app creates an instance of TTQuicHe_HttpRequestCallback by providing
// custom functions for each method.
CRONET_EXPORT TTQuicHe_HttpRequestCallbackPtr
TTQuicHe_HttpRequestCallback_CreateWith(
    TTQuicHe_HttpRequestCallback_OnEventFunc OnEventFunc,
    TTQuicHe_HttpRequestCallback_OnWriteStartedFunc OnWriteStartedFunc,
    TTQuicHe_HttpRequestCallback_OnResponseStartedFunc OnResponseStartedFunc,
    TTQuicHe_HttpRequestCallback_OnReadCompletedFunc OnReadCompletedFunc,
    TTQuicHe_HttpRequestCallback_OnSucceededFunc OnSucceededFunc,
    TTQuicHe_HttpRequestCallback_OnFailedFunc OnFailedFunc,
    TTQuicHe_HttpRequestCallback_OnCanceledFunc OnCanceledFunc);

///////////////////////
// Struct TTQuicHe_PreconnectInfo.
CRONET_EXPORT TTQuicHe_PreconnectInfoPtr TTQuicHe_PreconnectInfo_Create(void);
CRONET_EXPORT void TTQuicHe_PreconnectInfo_Destroy(
    TTQuicHe_PreconnectInfoPtr self);
// TTQuicHe_PreconnectInfo setters.
CRONET_EXPORT
void TTQuicHe_PreconnectInfo_host_set(TTQuicHe_PreconnectInfoPtr self,
                                      const Cronet_String host);
CRONET_EXPORT
void TTQuicHe_PreconnectInfo_port_set(TTQuicHe_PreconnectInfoPtr self,
                                      const int32_t port);
CRONET_EXPORT
void TTQuicHe_PreconnectInfo_status_set(TTQuicHe_PreconnectInfoPtr self,
                                        const TTQuicHe_RESULT status);
CRONET_EXPORT
void TTQuicHe_PreconnectInfo_addr_list_add(TTQuicHe_PreconnectInfoPtr self,
                                           const Cronet_String element);
CRONET_EXPORT
void TTQuicHe_PreconnectInfo_msg_set(TTQuicHe_PreconnectInfoPtr self,
                                     const Cronet_String msg);
// TTQuicHe_PreconnectInfo getters.
CRONET_EXPORT
Cronet_String TTQuicHe_PreconnectInfo_host_get(
    const TTQuicHe_PreconnectInfoPtr self);
CRONET_EXPORT
int32_t TTQuicHe_PreconnectInfo_port_get(const TTQuicHe_PreconnectInfoPtr self);
CRONET_EXPORT
TTQuicHe_RESULT TTQuicHe_PreconnectInfo_status_get(
    const TTQuicHe_PreconnectInfoPtr self);
CRONET_EXPORT
uint32_t TTQuicHe_PreconnectInfo_addr_list_size(
    const TTQuicHe_PreconnectInfoPtr self);
CRONET_EXPORT
Cronet_String TTQuicHe_PreconnectInfo_addr_list_at(
    const TTQuicHe_PreconnectInfoPtr self,
    uint32_t index);
CRONET_EXPORT
void TTQuicHe_PreconnectInfo_addr_list_clear(TTQuicHe_PreconnectInfoPtr self);
CRONET_EXPORT
Cronet_String TTQuicHe_PreconnectInfo_msg_get(
    const TTQuicHe_PreconnectInfoPtr self);

///////////////////////
// Struct TTQuicHe_HttpInfo.
CRONET_EXPORT TTQuicHe_HttpInfoPtr TTQuicHe_HttpInfo_Create(void);
CRONET_EXPORT void TTQuicHe_HttpInfo_Destroy(TTQuicHe_HttpInfoPtr self);
// TTQuicHe_HttpInfo setters.
CRONET_EXPORT
void TTQuicHe_HttpInfo_event_type_set(
    TTQuicHe_HttpInfoPtr self,
    const TTQuicHe_HttpInfo_EVENT_TYPE event_type);
CRONET_EXPORT
void TTQuicHe_HttpInfo_quic_conn_err_set(TTQuicHe_HttpInfoPtr self,
                                         const int64_t quic_conn_err);
CRONET_EXPORT
void TTQuicHe_HttpInfo_quic_stream_err_set(TTQuicHe_HttpInfoPtr self,
                                           const int64_t quic_stream_err);
CRONET_EXPORT
void TTQuicHe_HttpInfo_hs_start_set(TTQuicHe_HttpInfoPtr self,
                                    const int64_t hs_start);
CRONET_EXPORT
void TTQuicHe_HttpInfo_hs_end_set(TTQuicHe_HttpInfoPtr self,
                                  const int64_t hs_end);
CRONET_EXPORT
void TTQuicHe_HttpInfo_req_sent_set(TTQuicHe_HttpInfoPtr self,
                                    const int64_t req_sent);
CRONET_EXPORT
void TTQuicHe_HttpInfo_resp_recv_set(TTQuicHe_HttpInfoPtr self,
                                     const int64_t resp_recv);
CRONET_EXPORT
void TTQuicHe_HttpInfo_cert_status_set(TTQuicHe_HttpInfoPtr self,
                                       const int32_t cert_status);
CRONET_EXPORT
void TTQuicHe_HttpInfo_sk_reused_set(TTQuicHe_HttpInfoPtr self,
                                     const int32_t sk_reused);
CRONET_EXPORT
void TTQuicHe_HttpInfo_peer_ip_set(TTQuicHe_HttpInfoPtr self,
                                   const Cronet_String peer_ip);
// TTQuicHe_HttpInfo getters.
CRONET_EXPORT
TTQuicHe_HttpInfo_EVENT_TYPE TTQuicHe_HttpInfo_event_type_get(
    const TTQuicHe_HttpInfoPtr self);
CRONET_EXPORT
int64_t TTQuicHe_HttpInfo_quic_conn_err_get(const TTQuicHe_HttpInfoPtr self);
CRONET_EXPORT
int64_t TTQuicHe_HttpInfo_quic_stream_err_get(const TTQuicHe_HttpInfoPtr self);
CRONET_EXPORT
int64_t TTQuicHe_HttpInfo_hs_start_get(const TTQuicHe_HttpInfoPtr self);
CRONET_EXPORT
int64_t TTQuicHe_HttpInfo_hs_end_get(const TTQuicHe_HttpInfoPtr self);
CRONET_EXPORT
int64_t TTQuicHe_HttpInfo_req_sent_get(const TTQuicHe_HttpInfoPtr self);
CRONET_EXPORT
int64_t TTQuicHe_HttpInfo_resp_recv_get(const TTQuicHe_HttpInfoPtr self);
CRONET_EXPORT
int32_t TTQuicHe_HttpInfo_cert_status_get(const TTQuicHe_HttpInfoPtr self);
CRONET_EXPORT
int32_t TTQuicHe_HttpInfo_sk_reused_get(const TTQuicHe_HttpInfoPtr self);
CRONET_EXPORT
Cronet_String TTQuicHe_HttpInfo_peer_ip_get(const TTQuicHe_HttpInfoPtr self);

///////////////////////
// Struct TTQuicHe_HostParams.
CRONET_EXPORT TTQuicHe_HostParamsPtr TTQuicHe_HostParams_Create(void);
CRONET_EXPORT void TTQuicHe_HostParams_Destroy(TTQuicHe_HostParamsPtr self);
// TTQuicHe_HostParams setters.
CRONET_EXPORT
void TTQuicHe_HostParams_http_protocol_set(
    TTQuicHe_HostParamsPtr self,
    const TTQuicHe_HTTP_PROTOCOL http_protocol);
CRONET_EXPORT
void TTQuicHe_HostParams_addr_list_add(TTQuicHe_HostParamsPtr self,
                                       const Cronet_String element);
// TTQuicHe_HostParams getters.
CRONET_EXPORT
TTQuicHe_HTTP_PROTOCOL TTQuicHe_HostParams_http_protocol_get(
    const TTQuicHe_HostParamsPtr self);
CRONET_EXPORT
uint32_t TTQuicHe_HostParams_addr_list_size(const TTQuicHe_HostParamsPtr self);
CRONET_EXPORT
Cronet_String TTQuicHe_HostParams_addr_list_at(
    const TTQuicHe_HostParamsPtr self,
    uint32_t index);
CRONET_EXPORT
void TTQuicHe_HostParams_addr_list_clear(TTQuicHe_HostParamsPtr self);

#ifdef __cplusplus
}
#endif

#endif  // COMPONENTS_CRONET_NATIVE_GENERATED_TT_QUICHE_IDL_C_H_
