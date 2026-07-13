/*
 * Copyright (c) 2020 The BytePlusRTC project authors. All Rights Reserved.
 * @brief BytePlusRTC Interface
 */

#pragma once

#include <stddef.h>
#include <stdio.h>
#include <stdarg.h>
#include <memory>
#include "rtc/bytertc_rts_defines.h"
#include "byterts_event_handler.h"
#include "byterts_room.h"

namespace bytertc {

class IRTSRoomEventHandler;
/** 
 * @type api
 * @brief Engine API
 *      IRtcEngine uses IRtcEngineering EventHandler to register interface class methods to send callback notifications to applications
 */
class IRTS {
public:

    /** 
     * @hidden constructor/destructor
     * @brief Destructor
     */
    virtual ~IRTS() {
    }

    /** 
     * @type api
     * @region Engine management
     * @brief  Sets the business ID   <br>
     *         You can use businessId to distinguish different business scenarios. You can customize your businessId to serve as a sub AppId, which can share and refine the function of the AppId, but it does not need authentication.
     * @param  [in] business_id <br>
     *         Your customized businessId
     *         BusinessId is a tag, and you can customize its granularity.
     * @return   <br>
     *         + 0: Success <br>
     *         + < 0: Failure. See BusinessCheckCode{@link #BusinessCheckCode} for specific reasons. <br>
     *         + -6001: The user is already in the room. <br>
     *         + -6002: The input is invalid. Legal characters include all lowercase letters, uppercase letters, numbers, and four other symbols, including '.', '-','_', and '@'.
     * @notes   <br>
     *         + You must call this API before joining a room, otherwise it will be invalid.
     */
    virtual int setBusinessId(const char* business_id) = 0;

    /** 
     * @type api
     * @region Real-time messaging
     * @brief Log in to send P2P messages or send messages to a server.<br>
     *        To log out, call logout{@link #IRTS#logout}. <br>
     * @param  [in] token <br>
     *        Token is required during login for authentication. <br>
     *        This Token is different from that required by calling joinRoom. You can assign any value even null to `roomId` to generate a login token. During developing and testing, you can use temporary tokens generated on the console. Deploy the token generating application on your server.
     * @param  [in] uid <br>
     *        User ID <br>
     *        User ID is unique within one appid.
     * @return <br>
     *        + `0`: Success<br>
     *        + `-1`: Failure due to invalid parameter<br>
     *        + `-2`: Invalid call. RTC will return this value when you call this API after the user has been logged in to the server. <br>
     * @notes  You will receive onLoginResult{@link #IRTSEventHandler#onLoginResult} after calling this API and log in successfully. But remote users will not receive notification about that.
     */
    virtual int login(const char* token, const char* uid) = 0;

    /** 
     * @type After api
     * @region  real-time messaging
     * @brief  Calls this interface to log out, it is impossible to call methods related to out-of-room messages and end-to-server messages or receive related callbacks.
     * @return  <br>
     *        + 0: Success.
     *        + < 0 : Fail. See ReturnStatus{@link #ReturnStatus} for more details
     * @notes   <br>
     *        + Before calling this interface to log out, you must call login{@link #IRTS#login} to log in. <br>
     *        + After local users call this method to log out, they will receive the result of the onLogout{@link #IRTSEventHandler#onLogout} callback notification, and remote users will not receive the notification.
     */
    virtual int logout() = 0;

    /** 
     * @type api
     * @region Real-time messaging
     * @brief Update the Token <br>
     *        Token used by the user to log in has a certain valid period. When the Token expires, you need to call this method to update the login Token information. <br>
     *         When calling the login{@link #IRTS#login} method to log in, if an expired token is used, the login will fail and you will receive an onLoginResult{@link #IRTSEventHandler#onLoginResult} callback notification with an error code of kLoginErrorCodeInvalidToken. You need to reacquire the token and call this method to update the token.
     * @param  [in] token <br>
     *        Updated dynamic key
     * @return  <br>
     *        + 0: Success.
     *        + < 0 : Fail. See ReturnStatus{@link #ReturnStatus} for more details
     * @notes   <br>
     *        + If the token is invalid and the login fails, call this method. After updating the token, the SDK will automatically log back in, and the user does not need to call the login{@link #IRTS#login} method. <br>
     *        + Token expires, if you have successfully logged in, it will not be affected. An expired Token error will be notified to the user the next time you log in with an expired Token, or when you log in again due to a disconnection due to poor local network conditions.
     */
    virtual int updateLoginToken(const char* token) = 0;

    /** 
     * @type api
     * @region Real-time messaging
     * @brief Set application server parameters   <br>
     *        Client side calls sendServerMessage{@link #IRTS#sendServerMessage} or sendServerBinaryMessage{@link #IRTS#sendServerBinaryMessage} Before sending a message to the business server, a valid signature and business server address must be set.
     * @param [in] signature Dynamic signature. The App server may use the signature to verify the source of messages.<br>
     *         You need to define the signature yourself. It can be any non-empty string. It is recommended to encode information such as UID into the signature.<br>
     *         The signature will be sent to the address set through the "url" parameter in the form of a POST request.
     * @param [in] url The address of the application server
     * @return  <br>
     *        + 0: Success.
     *        + < 0 : Fail. See ReturnStatus{@link #ReturnStatus} for more details
     * @notes   <br>
     *        + The user must call login{@link #IRTS#login} to log in before calling this interface. <br>
     *        + After calling this interface, the SDK will use onServerParamsSetResult{@link #IRTSEventHandler#onServerParamsSetResult} to return the corresponding result.
     */
    virtual int setServerParams(const char* signature, const char* url) = 0;

    /** 
     * @type api
     * @region Real-time messaging
     * @brief Query the login status of the opposite or local user
     * @param  [in] peer_user_id <br>
     *        User ID to be queried
     * @return  <br>
     *        + 0: Success.
     *        + < 0 : Fail. See ReturnStatus{@link #ReturnStatus} for more details
     * @notes   <br>
     *        + login{@link #IRTS#login} must be called before this interface can be called. <br>
     *        + After calling this interface, the SDK notifies the query result using the onGetPeerOnlineStatus{@link #IRTSEventHandler#onGetPeerOnlineStatus} callback. <br>
     *        + Before sending an out-of-room message, the user can know whether the peer user is logged in through this interface to decide whether to send a message. You can also check your login status through this interface.
     */
    virtual int getPeerOnlineStatus(const char* peer_user_id) = 0;

    /** 
     * @type api
     * @region Real-time messaging
     * @brief Send a text message (P2P) to a specified user outside the room
     * @param  [in] uid User ID of the message receiver
     * @param  [in] message <br>
     *        Text message content sent <br>
     *        Message does not exceed 62KB.
     * @return   <br>
     *         + > 0: Sent successfully, return the number of the sent message, increment from 1 <br>
     *         + -1: Sent failed, RtcEngine instance not created <br>
     *         + -2: Sent failed, uid is empty
     * @notes   <br>
     *        + You must call login{@link #IRTS#login} to complete the login before you can send a message in a foreign text of the room. <br>
     *        + After the user calls this interface to send a text message, he will receive an onMessageSendResult{@link #IRTSEventHandler#onMessageSendResult} callback to know whether the message was successfully sent. <br>
     *        + If the text message is sent successfully, the user specified by uid receives the message via the onMessageReceived{@link #IRTSEventHandler#onMessageReceived} callback.
     */
    virtual int64_t sendMessage(const char* uid, const char* message, MessageConfig config) = 0;
    /** 
     * @type api
     * @region Real-time messaging
     * @brief Send binary messages (P2P) to a specified user outside the room
     * @param  [in] uid <br>
     *        ID of the user receiving the message
     * @param  [in] length <br>
     *        Length of the binary string
     * @param  [in] message <br>
     *        Content of the binary message sent <br>
     *        Message does not exceed 46KB.
     * @return   <br>
     *         + > 0: sent successfully, return the number of the sent message, increment from 1 <br>
     *         + -1: Sent failed, RtcEngine instance not created <br>
     *         + -2: Sent failed, uid is empty
     * @notes   <br>
     *        + You must call this API after login by calling login{@link #IRTS#login}. <br>
     *        + After the user calls this interface to send a binary message, he will receive an onMessageSendResult{@link #IRTSEventHandler#onMessageSendResult} callback to notify whether the message was sent successfully. <br>
     *        + If the binary message is sent successfully, the user specified by uid will receive the message through the onBinaryMessageReceived{@link #IRTSEventHandler#onBinaryMessageReceived} callback.
     */
    virtual int64_t sendBinaryMessage(const char* uid, int length, const uint8_t* message, MessageConfig config) = 0;
    /** 
     * @type api
     * @region Real-time messaging
     * @brief The client side sends a text message to the application server (P2Server)
     * @param  [in] message <br>
     *        The content of the text message sent <br>
     *        The message does not exceed 62KB.
     * @return   <br>
     *         + > 0: Sent successfully, return the number of the sent message, increment from 1 <br>
     *         + -1: Sent failed, RtcEngine instance not created
     * @notes   <br>
     *        + Before sending a text message to the business server, you must first call login{@link #IRTS#login} to complete the login, and then call setServerParams{@link #IRTS#setServerParams} to set up the business server. <br>
     *        + After calling this interface, you will receive an onServerMessageSendResult{@link #IRTSEventHandler#onServerMessageSendResult} callback to inform the message sender whether the message was sent successfully. <br>
     *        + If the text message is sent successfully, the business server that previously called setServerParams{@link #IRTS#setServerParams} will receive the message.
     */
    virtual int64_t sendServerMessage(const char* message) = 0;
    /** 
     * @type api
     * @region Real-time messaging
     * @brief Client side sends binary messages to the application server (P2Server)
     * @param  [in] length <br>
     *        Length of binary string
     * @param  [in] message <br>
     *        Binary message content sent <br>
     *        Message does not exceed 46KB.
     * @return   <br>
     *         + > 0: Sent successfully, return the number of the sent message, increment from 1 <br>
     *         + -1: Sent failed, RtcEngine instance not created
     * @notes   <br>
     *        + Before sending a binary message to the business server, you must first call login{@link #IRTS#login} to complete the login, and then call setServerParams{@link #IRTS#setServerParams} Set up the business server. <br>
     *        + After calling this interface, you will receive an onServerMessageSendResult{@link #IRTSEventHandler#onServerMessageSendResult} callback to inform the message sender that the sending succeeded or failed. <br>
     *        + If the binary message is sent successfully, the business server that previously called setServerParams{@link #IRTS#setServerParams} will receive the message.
     */
    virtual int64_t sendServerBinaryMessage(int length, const uint8_t* message) = 0;

    /** 
     * @type api
     * @region Room Management
     * @brief Create a room instance.
     *        This API only returns a room instance. You still need to call joinRoom{@link #IRTSRoom#joinRoom} to actually create/join the room.
     *        Each call of this API creates one IRTSRoom{@link #IRTSRoom} instance. Call this API as many times as the number of rooms you need, and then call joinRoom{@link #IRTSRoom#joinRoom} of each IRTSRoom instance to join multiple rooms at the same time.
     *        In multi-room mode, a user can subscribe to media streams in the joined rooms at the same time.
     * @param [in] room_id The string matches the regular expression: `[a-zA-Z0-9_@\-\.]{1,128}`.
     * @return IRTSRoom{@link #IRTSRoom} instance.
     * @notes <br>
     *       + If the room that you wish to join already exists, you still need to call this API first to create the IRTSRoom instance, and then call joinRoom{@link #IRTSRoom#joinRoom}.
     *       + In multi-room mode, you need to use different room_id to create multiple rooms.
     */
    virtual IRTSRoom* createRoom(const char* room_id) = 0;

    /** 
     * @type api
     * @region Engine management
     * @brief Set runtime parameters
     * @param  [in] json_string String after json serialization
     * @return  <br>
     *        + 0: Success.
     *        + < 0 : Fail. See ReturnStatus{@link #ReturnStatus} for more details
     * @notes
     */
    virtual int setRuntimeParameters(const char * json_string) = 0;

    /** 
     * @hidden(macOS, Windows, Linux)
     * @type api
     * @brief Enable cellular network assisted communication to improve call quality.
     * @param [in] enhance Enable or not. Off by default.
     * @return Method call result:   <br>
     *        + 0: Success. <br>
     *        + -1: Failure, internal error. <br>
     */
    virtual int setCellularEnhancement(bool enhance) = 0;

    /** 
     * @type api
     * @region   proxy
     * @brief  set local proxy
     * @notes To set local proxy, call setLocalProxy{@link #IRTS#setLocalProxy}.
     */
    virtual int setLocalProxy(
        const LocalProxyConfiguration* configurations,
        int configuration_num) = 0;
};

/** 
 * @type api
 * @region Engine Management
 * @brief Create an engine instance.   <br>
 *        This is the very first API that you must call if you want to use all the RTC capabilities.  <br>
 *        If there is no engine instance in current thread, calling this API will create one. If an engine instance has been created, calling this API again will create another instance.
 * @param [in] app_id A unique identifier for each App, randomly generated by the RTC console. Only instances created with the same app_id are able to communicate with each other.
 * @param [in] event_handler Handler sent from SDK to App. See IRTSEventHandler{@link #IRTSEventHandler}.
 * @param [in] parameters Reserved parameter, in JSON string.
 * @return  <br>
 *        + IRTS：A successfully created engine instance  <br>
 *        + Null：Creation failed
 * @notes   <br>
 *         + If you create multiple engine instances in the same thread, you must destroy each of these instances by calling destroyRTS{@link #destroyRTS}.
 *         + The number of engine instances created on a Linux platform depends on the hardware performance of the system.
 */
BYTERTC_API bytertc::IRTS* createRTS(const char* app_id,
        bytertc::IRTSEventHandler* event_handler, const char* parameters);

/** 
 * @type api
 * @region Engine Management
 * @brief Destroy the engine instance created by createRTS{@link #createRTS}, and release all related resources.
 * @param [in] engine The engine instance created by createRTS{@link #createRTS}.
 * @notes  <br>
 *         + Call this API after all business scenarios related to the engine instance are destroyed.  <br>
 *         + When the API is called, RTC SDK destroys all memory associated with the engine instance and stops any interaction with the media server.  <br>
 *         + Calling this API will start the SDK exit logic. The engine thread is held until the exit logic is complete. The engine thread is retained until the exit logic is complete. Therefore, do not call this API directly in the callback thread, or it will cause a deadlock. This function takes a long time to execute, so it's not recommended to call this API in the main thread, or the main thread may be blocked.
 */
BYTERTC_API void destroyRTS();

/** 
 * @type api
 * @region  error code
 * @brief  Get the description of the error code
 * @param  [in] code Needs to get the description of the error code
 * @return  The description of the error code
 * @notes  This interface is a general function and does not need to rely on the engine object when calling.
 */
BYTERTC_API const char* getErrorDescription(int code);

/** 
 * @type api
 * @region  engine management
 * @brief  Get the current SDK version information.
 * @return Current SDK version information.
 */
BYTERTC_API const char* getSDKVersion();

/** 
 * @type api
 * @region Engine Management
 * @brief Configures the local log parameters of RTC SDK, including the logging level, directory, and the limits for total log file size.
 * @param [in] log_config Local log parameters. See LogConfig{@link #LogConfig}.
 * @return <br>
 *        + 0: Success.
 *        + –1: Failure. This API must be called before creating engine.
 *        + –2: Failure. Invalid parameters.
 * @notes This API must be called before createRTS{@link #createRTS}.
 */
BYTERTC_API int setLogConfig(const LogConfig& log_config);

}    

