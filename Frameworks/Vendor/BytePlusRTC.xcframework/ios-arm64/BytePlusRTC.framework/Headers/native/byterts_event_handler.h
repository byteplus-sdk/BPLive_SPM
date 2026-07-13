/*
 * Copyright (c) 2020 The BytePlusRTC project authors. All Rights Reserved.
 * @brief BytePlusRTC Event Handler Lite
*/

#pragma once

#include "rtc/bytertc_rts_defines.h"

namespace bytertc {
/** 
 * @type callback
 * @brief Audio & video engine event callback interface
 */
class IRTSEventHandler {
public:

    /**
     * @hidden constructor/destructor
     */
    virtual ~IRTSEventHandler() {
    }

    /** 
     * @type callback
     * @region Warning code
     * @brief This callback informs you of a warning message.
     * @param  [in] warn
     *        Warning identification code, see: WarningCode{@link #WarningCode}
     */
    virtual void onWarning(int warn) {
        (void)warn;
    }

    /** 
     * @type callback
     * @region Error code
     * @brief This callback informs you of an error message.
     * @param  [in] err Error code. See ErrorCode{@link #ErrorCode}
     */
    virtual void onError(int err) {
        (void)err;
    }

    /**
    * {en}
    * @valid since 3.52
    * @type callback
    * @brief Failed to access the extension.
    *        RTC SDK provides some features with extensions. Without implementing the extension, you cannot use the corresponding feature.
    * @param [in] extension_name The name of extension.
    * @param [in] msg Error message.
    */
     void onExtensionAccessError(const char* extension_name, const char* msg) {
        (void)extension_name;
        (void)msg;
     }

    /** 
     * @type callback
     * @region  engine management
     * @brief  Terminal monitoring log callback. The callback is triggered when a terminal monitoring event is generated.
     * @param  [in] log_type <br>
     *         Event type. The current type is fixed to "live_webrtc_monitor_log".
     * @param  [in] log_content <br>
     *         Terminal monitoring log content.
     */
    virtual void onLogReport(const char* log_type, const char* log_content) {
        (void)log_type;
        (void)log_content;
    }

    /** 
     * @type callback
     * @region  engine management
     * @brief SDK  connection state change callback with signaling server. Triggered when the connection state changes.
     * @param  [in] state The current connection status between the SDK and the signaling server. See ConnectionState{@link #ConnectionState}.
     * @notes Refer to [Getting Connection Status](https:
     */
    virtual void onConnectionStateChanged(bytertc::ConnectionState state) {
    }

    /** 
     * @type callback
     * @region Engine management
     * @brief SDK Current network connection type change callback. Callbacks the event when the current network connection type of the SDK changes.
     * @param  [in] type <br>
     *        SDK The current network connection type, see: NetworkType{@link #NetworkType}.
     */
    virtual void onNetworkTypeChanged(bytertc::NetworkType type) {
    }

    /** 
     * @type callback
     * @region  engine management
     * @brief  Periodically (2s) issue callbacks to report the current cpu and memory usage
     * @param  [in] stats Return the current system state information. See SysStats{@link #SysStats}
     */
    virtual void onSysStats(const bytertc::SysStats& stats) {
    }

    /** 
     * @type callback
     * @region Engine Management
     * @brief Callback on create room failure.
     * @param room_id  Room ID.
     * @param error_code Create room error code. See ErrorCode{@link #ErrorCode} for specific indications.
     */
    virtual void onCreateRoomStateChanged(const char* room_id, int error_code) {
        (void)room_id;
        (void)error_code;
    }

    /** 
     * @type callback
     * @deprecated since 3.52, will be deleted at 3.57, use onLocalProxyStateChanged{@link #IRTSEventHandler#onLocalProxyStateChanged} instead
     * @region Proxy callback
     * @brief HTTP Receive the callback when the proxy connection state changes.
     * @param  [in] state The current HTTP proxy connection status. See HttpProxyState{@link #HttpProxyState}
     */
        virtual void onHttpProxyState(int state) {
    }

    /** 
     * @type callback
     * @deprecated since 3.52, will be deleted at 3.57, use onLocalProxyStateChanged{@link #IRTSEventHandler#onLocalProxyStateChanged} instead
     * @region Proxy callback
     * @brief HTTPS Receive the callback when the proxy connection state changes.
     * @param   [out] State the current HTTPS proxy connection status. See HttpProxyState{@link #HttpProxyState}
     */
    virtual void onHttpsProxyState(int state) {
    }

    /** 
     * @type callback
     * @deprecated since 3.52, will be deleted at 3.57, use onLocalProxyStateChanged{@link #IRTSEventHandler#onLocalProxyStateChanged} instead
     * @region Proxy callback
     * @brief Socks5 Receive the callback when the proxy state changes.
     * @param  [out] State SOCKS5 proxy connection status. See Socks5ProxyState{@link #Socks5ProxyState}
     * @param  [out] Cmd every step of the proxy connection operating command
     * @param  [out] Proxy_address proxy address information
     * @param  [out] Local_address the local address used by the current connection
     * @param  [out] Remote_address the remote connection address
     */
    virtual void onSocks5ProxyState(int state,
        const char* cmd,
        const char* proxy_address,
        const char* local_address,
        const char* remote_address) {
    }

    /** 
     * @type callback
     * @region Real-time messaging
     * @brief login result callback
     * @param  [in] uid <br>
     *        Login user ID
     * @param  [in] error_code <br>
     *        Login result <br>
     *        See LoginErrorCode{@link #LoginErrorCode}.
     * @param  [in] elapsed <br>
     *         The time taken from the call to the login{@link #IRTS#login} interface to return the result is <br>
     *         In ms. This callback is received after
     * @notes login{@link #IRTS#login} is called. login{@link #IRTS#login}
     */
    virtual void onLoginResult(const char* uid, int error_code, int elapsed) {
        (void)uid;
        (void)error_code;
        (void)elapsed;
    }
    /** 
     * @type callback
     * @region Real-time messaging
     * @brief Callback of logout result
     * @param reason It describes the reason why users log out. See LogoutReason{@link #LogoutReason}
     * @notes You will receive this callback when calling logout{@link #IRTS#logout} or when the local user is kicked out because another user logs in with the same UserId.
     */
    virtual void onLogout(LogoutReason reason) {
    }
    /** 
     * @type callback
     * @region Real-time messaging
     * @brief Set the return result of the application server parameter
     * @param  [in] error <br>
     *         + 200, set successfully <br>
     *         + Return other, set failed
     * @notes Receive this callback after calling setServerParams{@link #IRTS#setServerParams}.
     */
    virtual void onServerParamsSetResult(int error) {
        (void)error;
    }
    /** 
     * @type callback
     * @region Real-time messaging
     * @brief The return result of querying the login status of the peer or local user
     * @param  [in] peer_user_id User ID
     * @param  [in] status <br>
     *        The user login status of the query <br>
     *        See UserOnlineStatus{@link #UserOnlineStatus}.
     * @notes You must first call getPeerOnlineStatus{@link #IRTS#getPeerOnlineStatus} to receive this callback.
     */
    virtual void onGetPeerOnlineStatus(const char* peer_user_id, int status) {
        (void)peer_user_id;
        (void)status;
    }
    /** 
     * @type callback
     * @region Real-time messaging
     * @brief Receive this callback when you receive a text message from an out-of-room user calling sendMessage{@link #IRTS#sendMessage}
     * @param  [in] uid <br>
     *        User ID of the message sender
     * @param  [in] message <br>
     *        Received text message content
     */
    virtual void onMessageReceived(const char* uid, const char* message) {
        (void)uid;
        (void)message;
    }
    /** 
     * @type callback
     * @region Real-time messaging
     * @brief Receive this callback when you receive a binary message from an out-of-room user calling sendBinaryMessage{@link #IRTS#sendBinaryMessage}
     * @param  [in] uid <br>
     *        User ID of the message sender
     * @param  [in] size <br>
     *        Binary message length
     * @param  [in] message <br>
     *         Binary message content received
     */
    virtual void onBinaryMessageReceived(const char* uid, int size, const uint8_t* message) {
        (void)uid;
        (void)size;
        (void)message;
    }
    /** 
     * @type callback
     * @region Real-time messaging
     * @brief A callback that sends a message to a specified user outside the room
     * @param  [in] msgid <br>
     *        The ID of this message <br>
     *        All P2P and P2Server messages share a single ID sequence.
     * @param  [in] error <br>
     *         Message sending result <br>
     *         See UserMessageSendResult{@link #UserMessageSendResult}.
     * @notes Receive this callback when a message is sent by calling sendMessage{@link #IRTS#sendMessage} or sendBinaryMessage{@link #IRTS#sendBinaryMessage}.
     */
    virtual void onMessageSendResult(int64_t msgid, int error) {
        (void)msgid;
        (void)error;
    }

    /** 
     * @type callback
     * @region Real-time messaging
     * @brief Callback to send a message to the application server
     * @param [in] msgid The ID of this message <br>
     *        All P2P and P2Server messages share a single ID sequence.
     * @param [in] error Message Sending Results. See UserMessageSendResult{@link #UserMessageSendResult}.
     * @param message The message returned in ACK when the application server receives HTTP request.
     * @notes Receive this callback when you call sendServerMessage{@link #IRTS#sendServerMessage} or sendServerBinaryMessage{@link #IRTS#sendServerBinaryMessage} to send a message to your application server.
     */
    virtual void onServerMessageSendResult(int64_t msgid, int error, const bytertc::ServerACKMsg& msg) {
        (void)msgid;
        (void)error;
        (void)msg;
    }

    /** 
     * @type callback
     * @brief Receives the callback when you call StartCloudProxy{@link #IRtcEngineLite#StartCloudProxy} to start cloud proxy, and the SDK connects the proxy server successfully.
     * @param [in] interval The interval in ms between starting cloud proxy and connects the cloud proxy server successfully.
     */
    virtual void onCloudProxyConnected(int interval) {
        (void)interval;
    }

    /** 
     * @type callback
     * @brief Receives the callback when you call setLocalProxy{@link #IRTS#setLocalProxy} to set proxy, and the SDK connects the proxy server and call with state
     * @param [in] local_proxy_type local proxy type: socks5 or httptunnel
     * @param [in] local_proxy_state The states of local proxy connection. Refer to LocalProxyState{@link #LocalProxyState} for details.  <br>
     * @param [in] local_proxy_error The errors of local proxy connection. Refer to LocalProxyError{@link #LocalProxyError} for details.
     */
    virtual void onLocalProxyStateChanged(LocalProxyType local_proxy_type, LocalProxyState local_proxy_state, LocalProxyError local_proxy_error) {
        (void)local_proxy_type;
        (void)local_proxy_state;
        (void)local_proxy_error;
    }
};

} 

