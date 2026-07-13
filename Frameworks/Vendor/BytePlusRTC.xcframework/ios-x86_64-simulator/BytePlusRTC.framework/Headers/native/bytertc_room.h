/*
 * Copyright (c) 2020 The BytePlusRTC project authors. All Rights Reserved.
 * @brief BytePlusRTC Room Interface
 */

#pragma once

#include "rtc/bytertc_video_effect_interface.h"  
#include "rtc/bytertc_defines.h"
#include "bytertc_room_event_handler.h"
#include "rtc/bytertc_transcoder_interface.h"
#include "rtc/bytertc_publicstream_interface.h"
#include "rtc/bytertc_range_audio_interface.h"
#include "rtc/bytertc_spatial_audio_interface.h"
#include "rtc/bytertc_panoramic_video_interface.h"
namespace bytertc {


/**
 * 
 * @type api
 * @brief  Room interface
 */
class IRTCRoom {
public:
    
    /**
     * 
     * @hidden constructor/destructor
     * @brief Destructor
     */
    virtual ~IRTCRoom() {
    }

    
    /**
     * 
     * @type api
     * @region  multi-room
     * @brief  Leave and destroy the room instance created by calling createRTCRoom{@link #IRTCVideo#createRTCRoom}.
     */
    virtual void destroy() = 0;

    
    /**
     * 
     * @type api
     * @region Room management
     * @brief Set the visibility of the user in the room. The local user is visible to others by default before calling this API. <br>
     *        An RTC room can accommodate a maximum of 50 visible users, and 30 media streams can be published simultaneously. For more information, see [Room Capacity](https:
     * @param enable Visibility of the user in the room. <br>
     *        - true: The user can publish media streams. The other users in the room get informed of the behaviors of the user, such as joining room, starting video capture, and leaving room.
     *        - false: The user cannot publish media streams. The other users in the room do not get informed of the behaviors of the user, such as joining room, starting video capture, or leaving room.
     * @return
     *        - 0: Success.
     *        - < 0 : Failure. See ReturnStatus{@link #ReturnStatus}.
     *        You will receive onUserVisibilityChanged{@link #IRTCRoomEventHandler#onUserVisibilityChanged} after calling this API. (Available since v3.54)
     *        - If you call this API before joining room, and the set value is different from the default value, you will receive the callback when you join the room.
     *        - If you call this API after joining room, and the current visibility is different from the previous value, you will receive the callback.
     *        - When reconnecting after losing internet connection, if the visibility changes, you will receive the callback.
     * @note
     *        - You can call this API whether the user is in a room or not.
     *        - When you call this API while you are in the room, the other users in the room will be informed via the following callback.
     *   &#x0020;  • When you switch from `false` to `true`, they will receive onUserJoined{@link #IRTCRoomEventHandler#onUserJoined}. <br>
     *   &#x0020;  • When you switch from `true` to `false`, they will receive onUserLeave{@link #IRTCRoomEventHandler#onUserLeave}. <br>
     *   &#x0020;  • The invisible user will receive the warning code, `kWarningCodePublishStreamForbidden`, when trying to publish media streams.
     */
    virtual int setUserVisibility(bool enable) = 0;

    
    /**
     * 
     * @type api
     * @region multiroom
     * @brief Listens for event callbacks related to the IRTCRoom{@link #IRTCRoom} instance by setting the event handler of this instance.
     * @param room_event_handler Refer to IRTCRoomEventHandler{@link #IRTCRoomEventHandler}.
     * @return
     *        - 0: Success.
     *        - < 0 : Fail. See ReturnStatus{@link #ReturnStatus} for more details
     */
    virtual int setRTCRoomEventHandler(IRTCRoomEventHandler* room_event_handler) = 0;

    
    /**
     * 
     * @type api
     * @region Multi-room
     * @brief Join the room. <br>
     *        After creating a room by calling createRTCRoom{@link #IRTCVideo#createRTCRoom}, call this API to join the room and make audio & video calls with other users in the room.
     * @param token Dynamic key for authenticating the logged-in user. <br>
     *         You need to bring Token to enter the room. When testing, you can use the console to generate temporary tokens. The official launch requires the use of the key SDK to generate and issue tokens at your server level. See [Authentication with Token](70121) for token validity and generation method. <br>
     *        - Apps with different App IDs cannot communicate with each other.
     *        - Make sure that the App ID used to generate the Token is the same as the App ID used to create the engine, otherwise it will cause the join room to fail.
     * @param user_info User information. See UserInfo{@link #UserInfo}.
     * @param config Room parameter configuration, set the room mode and whether to automatically publish or subscribe to the flow. See RTCRoomConfig{@link #RTCRoomConfig} for the specific configuration mode.
     * @return
     *         - 0: Success. 
     *            - Local users receive notifications of the room state via onRoomStateChanged{@link #IRTCRoomEventHandler#onRoomStateChanged}. 
     *            - Local users receive notifications of the local-stream state via onVideoPublishStateChanged{@link #IRTCRoomEventHandler#onVideoPublishStateChanged}, onAudioPublishStateChanged{@link #IRTCRoomEventHandler#onAudioPublishStateChanged}, onScreenVideoPublishStateChanged{@link #IRTCRoomEventHandler#onScreenVideoPublishStateChanged}, and/or onScreenAudioPublishStateChanged{@link #IRTCRoomEventHandler#onScreenAudioPublishStateChanged}.
     *            - Local users receive notifications of the subscribed-stream state via onUserPublishStreamVideo{@link #IRTCRoomEventHandler#onUserPublishStreamVideo}, onUserPublishStreamAudio{@link #IRTCRoomEventHandler#onUserPublishStreamAudio}, onUserPublishScreenVideo{@link #IRTCRoomEventHandler#onUserPublishScreenVideo}, and/or onUserPublishScreenAudio{@link #IRTCRoomEventHandler#onUserPublishScreenAudio}.
     *            - Local users receive notifications of the published-stream state via onUserPublishStreamVideo{@link #IRTCRoomEventHandler#onUserPublishStreamVideo}, onUserPublishStreamAudio{@link #IRTCRoomEventHandler#onUserPublishStreamAudio}, onUserPublishScreenVideo{@link #IRTCRoomEventHandler#onUserPublishScreenVideo}, and/or onUserPublishScreenAudio{@link #IRTCRoomEventHandler#onUserPublishScreenAudio}.
     *            - If the local user is also a visible user, the other participants receive onUserJoined{@link #IRTCRoomEventHandler#onUserJoined} callback.
     *         - -1: Room_id/user_info.uid contains invalid parameters.
     *         - -2: Already in the room. After the interface call is successful, as long as the return value of 0 is received and leaveRoom:{@link #IRTCRoom#leaveRoom} is not called successfully, this return value is triggered when the room entry interface is called again, regardless of whether the filled room ID and user ID are duplicated.
     *         The reason for the failure will be communicated via the onRoomStateChanged{@link #IRTCRoomEventHandler#onRoomStateChanged} callback.
     * @note
     *        - In the same room with the same App ID, the user ID of each user must be unique. If two users have the same user ID, the user who entered the room later will kick the user who entered the room out of the room, and the user who entered the room will receive the onRoomStateChanged{@link #IRTCRoomEventHandler#onRoomStateChanged} callback notification. For the error type. See kErrorCodeDuplicateLogin in ErrorCode{@link #ErrorCode}.
     *        - By default, the user is visible in an RTC room. Joining fails when the number of users in an RTC room reaches the upper limit. To avoid this, call setUserVisibility{@link #IRTCRoom#setUserVisibility} to change the visibility of the audience users to `false` by considering the capacity for the invisible users is much larger than that for visible users. An RTC room can accommodate a maximum of 50 visible users, and 30 media streams can be published simultaneously. For more information, see [Capability of Users and Streams](https:
     *        - After the user successfully joins the room, the SDK may lose connection to the server in case of poor local network conditions. At this point, onConnectionStateChanged{@link #IRTCVideoEventHandler#onConnectionStateChanged} callback will be triggered and the SDK will automatically retry until it successfully reconnects to the server. After a successful reconnection, you will receive a local onRoomStateChanged{@link #IRTCRoomEventHandler#onRoomStateChanged} callback notification.
     */
    virtual int joinRoom(const char* token, const UserInfo& user_info, const RTCRoomConfig& config) = 0;

    
    /**
     * 
     * @type api
     * @region  room management
     * @brief  Leave RTC room. <br>
     *        The user calls this method to leave the RTC room, end the call process, and release all call-related resources. <br>
     *        It is an asynchronous operation, and the call returns without actually exiting the room. When actually exiting the room, you will receive onLeaveRoom{@link #IRTCRoomEventHandler#onLeaveRoom}.
     * @return
     *        - 0: Success. If the user is a host:
     *            - The other participants receive onUserLeave{@link #IRTCRoomEventHandler#onUserLeave} callback.
     *            - The publishing streams stop and the other participants receive notifications of the stream states via onVideoPublishStateChanged{@link #IRTCRoomEventHandler#onVideoPublishStateChanged}, onAudioPublishStateChanged{@link #IRTCRoomEventHandler#onAudioPublishStateChanged}, onScreenVideoPublishStateChanged{@link #IRTCRoomEventHandler#onScreenVideoPublishStateChanged} and/or onScreenAudioPublishStateChanged{@link #IRTCRoomEventHandler#onScreenAudioPublishStateChanged} callback.
     *        - < 0 : Fail. See ReturnStatus{@link #ReturnStatus} for more details
     * @note
     *        - When visible users leave the room, others in the room will receive onUserLeave{@link #IRTCRoomEventHandler#onUserLeave}.
     *        - If the engine is destroyed immediately after this method is called, you will not receive onLeaveRoom{@link #IRTCRoomEventHandler#onLeaveRoom}.
     */
    virtual int leaveRoom() = 0;

    
    /**
     * 
     * @type api
     * @brief Update Token. <br>
     *        You must call this API to update token to ensure the RTC call to continue when you receive onTokenWillExpire{@link #IRTCRoomEventHandler#onTokenWillExpire}, onPublishPrivilegeTokenWillExpire{@link #IRTCRoomEventHandler#onPublishPrivilegeTokenWillExpire}, or onSubscribePrivilegeTokenWillExpire{@link #IRTCRoomEventHandler#onSubscribePrivilegeTokenWillExpire}.
     * @param token  Valid token. <br>
     *        If the Token is invalid, you will receive onRoomStateChanged{@link #IRTCRoomEventHandler#onRoomStateChanged} with the error code of `-1010`.
     * @return API call result: <br>
     *        - 0: Success.
     *        - <0: Failure. See ReturnStatus{@link #ReturnStatus} for specific reasons.
     * @note
     *      - In versions before 3.50, the publish and subscribe privileges contained in the Token are reserved parameters with no actual control permissions. In version 3.50 and later, the publish/subscribe privileges will be effective for whitelisted users. Please contact the technical support team to include you in the whitelist if you need this function.
     *      - Do not call both updateToken{@link #IRTCRoom#updateToken} and joinRoom{@link #IRTCRoom#joinRoom} to update the Token. If you fail to join the room or have been removed from the room due to an expired or invalid Token, call joinRoom{@link #IRTCRoom#joinRoom} with a valid token to rejoin the room.
     */
    virtual int updateToken(const char* token) = 0;

    
    /**
     * 
     * @type api
     * @region Multi-room
     * @brief Send a text message (P2P) to the specified user in the room
     * @param uid User ID of the message receiver
     * @param message <br>
     *        Text message content sent. <br>
     *         Message does not exceed 64 KB.
     * @param config Message type, see MessageConfig{@link #MessageConfig}.
     * @return The number of the message sent this time is incremented from 1.
     * @note
     *        - Before sending an in-room text message, you must call joinRoom{@link #IRTCRoom#joinRoom} to join the room.
     *        - After calling this function, you will receive an onUserMessageSendResult{@link #IRTCRoomEventHandler#onUserMessageSendResult} callback to notify the message sender that the sending was successful or failed;
     *        - If the text message is sent successfully, the user specified by uid will receive onUserMessageReceived{@link #IRTCRoomEventHandler#onUserMessageReceived} callback.
     */
    virtual int64_t sendUserMessage(const char* uid, const char* message, MessageConfig config = kMessageConfigReliableOrdered) = 0;

    
    /**
     * 
     * @type api
     * @region multi-room
     * @brief Sends a binary message (P2P) to the specified user in the room
     * @param uid User ID of the message receiver
     * @param length <br>
     *        The length of the binary string.
     * @param message <br>
     *         The content of the binary message. The message does not exceed 46KB. <br>
     *         The number of the message sent this time is incremented from
     * @param config Message type, see MessageConfig{@link #MessageConfig}.
     * @return Serial number of the message, starting form 1.
     * @note   + Before sending in-room binary messages, you must call joinRoom{@link #IRTCRoom#joinRoom} to join the room.
     *        - After calling this function, you will receive an onUserMessageSendResult{@link #IRTCRoomEventHandler#onUserMessageSendResult} callback to notify the sender of the success or failure of the message;
     *        - If the binary message is sent successfully, the user specified by uid will receive the onUserBinaryMessageReceived{@link #IRTCRoomEventHandler#onUserBinaryMessageReceived} callback.
     */
    virtual int64_t sendUserBinaryMessage(const char* uid, int length, const uint8_t* message, MessageConfig config = kMessageConfigReliableOrdered) = 0;

    
    /**
     * 
     * @type api
     * @region Multi-room
     * @brief Send broadcast messages to all other users in the room.
     * @param message <br>
     *        The broadcast message sent by the user <br>
     *        Message does not exceed 64 KB.
     * @note
     *        - Before sending in-room binary messages, you must call joinRoom{@link #IRTCRoom#joinRoom} to join the room.
     *        - After calling this function, you get an onRoomMessageSendResult{@link #IRTCRoomEventHandler#onRoomMessageSendResult} callback.
     *        - Other users in the same room receive an onRoomMessageReceived{@link #IRTCRoomEventHandler#onRoomMessageReceived} callback.
     */
    virtual int64_t sendRoomMessage(const char* message) = 0;
    
    /**
     * 
     * @type api
     * @region Multi-room
     * @brief Send broadcast messages to all other users in the room.
     * @param size <br>
     *        The length of the binary message sent
     * @param message <br>
     *        The binary broadcast message sent by the user <br>
     *        The message does not exceed 46KB.
     * @return The number of the message sent this time is incremented from 1.
     * @note
     *        - Before sending in-room binary messages, you must call joinRoom{@link #IRTCRoom#joinRoom} to join the room.
     *        - After calling this function, you get an onRoomMessageSendResult{@link #IRTCRoomEventHandler#onRoomMessageSendResult} callback.
     *        - Other users in the same room receive an onRoomBinaryMessageReceived{@link #IRTCRoomEventHandler#onRoomBinaryMessageReceived} callback.
     */
    virtual int64_t sendRoomBinaryMessage(int size, const uint8_t* message) = 0;

    
    /**
     * 
     * @type api
     * @valid since 3.60.
     * @brief Start or stop publishing video streams captured by camera in the current room.
     * @param publish Whether to publish the media stream.
     * @return
     *        - 0: Success.
     *        - < 0 : Fail. See ReturnStatus{@link #ReturnStatus} for more details
     * @note
     *        - You don't need to call this API if you set it to Auto-publish when calling joinRoom{@link #IRTCRoom#joinRoom}.
     *        - An invisible user cannot publish media streams. Call setUserVisibility{@link #IRTCRoom#setUserVisibility} to change your visibility in the room.
     *        - Call publishScreenAudio{@link #IRTCRoom#publishScreenAudio} (not supported on Linux) and/or publishScreenVideo{@link #IRTCRoom#publishScreenVideo} to start or stop screen sharing.
     *        - Call publishStreamAudio{@link #IRTCRoom#publishStreamAudio} to start or stop publishing the audio stream captured by the microphone.
     *        - Call startForwardStreamToRooms{@link #IRTCRoom#startForwardStreamToRooms} to forward the published streams to the other rooms.
     *        - After you call this API, the other users in the room will receive onUserPublishStreamVideo{@link #IRTCRoomEventHandler#onUserPublishStreamVideo}. Those who successfully received your streams will receive onFirstRemoteVideoFrameDecoded{@link #IRTCEngineEventHandler#onFirstRemoteVideoFrameDecoded} at the same time.
     */
    virtual int publishStreamVideo(bool publish) = 0;

    
    /**
     * 
     * @type api
     * @valid since 3.60.
     * @brief Start or stop publishing media streams captured by the local microphone in the current room.
     * @param publish Whether to publish the media stream.
     * @return
     *        - 0: Success.
     *        - < 0 : Fail. See ReturnStatus{@link #ReturnStatus} for more details
     * @note
     *        - You don't need to call this API if you set it to Auto-publish when calling joinRoom{@link #IRTCRoom#joinRoom}.
     *        - An invisible user cannot publish media streams. Call setUserVisibility{@link #IRTCRoom#setUserVisibility} to change your visibility in the room.
     *        - Call publishScreenAudio{@link #IRTCRoom#publishScreenAudio} (not supported on Linux) and/or publishScreenVideo{@link #IRTCRoom#publishScreenVideo} to start or stop screen sharing.
     *        - Call publishStreamVideo{@link #IRTCRoom#publishStreamVideo} to start or stop publishing the video stream captured by the camera.
     *        - Call startForwardStreamToRooms{@link #IRTCRoom#startForwardStreamToRooms} to forward the published streams to the other rooms.
     *        - After you call this API, the other users in the room will receive onUserPublishStreamAudio{@link #IRTCRoomEventHandler#onUserPublishStreamAudio}. Those who successfully received your streams will receive onFirstRemoteAudioFrame{@link #IRTCEngineEventHandler#onFirstRemoteAudioFrame} at the same time.
     */
    virtual int publishStreamAudio(bool publish) = 0;

   
    /**
     * 
     * @type api
     * @valid since 3.60.
     * @brief Start or stop sharing the local screen in the room.
     *        If you need to share your screen in multiple rooms, you can use the same uid to join multiple rooms and call this API in each room. Also, you can publish different types of screen-sharing streams in different rooms.
     * @param publish Whether to publish video stream.
     * @return
     *        - 0: Success.
     *        - < 0 : Fail. See ReturnStatus{@link #ReturnStatus} for more details
     * @note
     *        - You need to call this API to publish screen even if you set it to Auto-publish when calling joinRoom{@link #IRTCRoom#joinRoom}.
     *        - An invisible user cannot publish media streams. Call setUserVisibility{@link #IRTCRoom#setUserVisibility} to change your visibility in the room.
     *        - Call publishScreenAudio{@link #IRTCRoom#publishScreenAudio} (not supported on Linux) to start or stop sharing computer audio.
     *        - Call publishStreamVideo{@link #IRTCRoom#publishStreamVideo} to start or stop publishing the video stream captured by the camera.
     *        - Call publishStreamAudio{@link #IRTCRoom#publishStreamAudio} to start or stop publishing the audio stream captured by the microphone.
     *        - Call startForwardStreamToRooms{@link #IRTCRoom#startForwardStreamToRooms} to forward the published streams to the other rooms.
     *        - After you called this API, the other users in the room will receive onUserPublishScreenVideo{@link #IRTCRoomEventHandler#onUserPublishScreenVideo}. Those who successfully received your streams will receive onFirstRemoteVideoFrameDecoded{@link #IRTCEngineEventHandler#onFirstRemoteVideoFrameDecoded} at the same time.
     *        - After calling this API, you'll receive onScreenVideoFrameSendStateChanged{@link #IRTCEngineEventHandler#onScreenVideoFrameSendStateChanged}.
     *        - Refer to [Sharing Screen in PC](https:
     */
    virtual int publishScreenVideo(bool publish) = 0;
   
    /**
     * 
     * @hidden(Linux)
     * @type api
     * @valid since 3.60.
     * @brief Manually publishes local screen-sharing streams in the current room. <br>
     *        If you need to share your screen in multiple rooms, you can use the same uid to join multiple rooms and call this API in each room. Also, you can publish different types of screen-sharing streams in different rooms.
     * @param publish Media stream type, used for specifying whether to publish audio stream or video stream.
     * @return
     *        - 0: Success.
     *        - < 0 : Fail. See ReturnStatus{@link #ReturnStatus} for more details
     * @note
     *        - You need to call this API to publish screen even if you set it to Auto-publish when calling joinRoom{@link #IRTCRoom#joinRoom}.
     *        - An invisible user cannot publish media streams. Call setUserVisibility{@link #IRTCRoom#setUserVisibility} to change your visibility in the room.
     *        - Call publishScreenVideo{@link #IRTCRoom#publishScreenVideo} to start or stop sharing the local screen.
     *        - Call publishStreamVideo{@link #IRTCRoom#publishStreamVideo} to start or stop publishing the video stream captured by the camera.
     *        - Call publishStreamAudio{@link #IRTCRoom#publishStreamAudio} to start or stop publishing the audio stream captured by the microphone.
     *        - Call startForwardStreamToRooms{@link #IRTCRoom#startForwardStreamToRooms} to forward the published streams to the other rooms.
     *        - After you called this API, the other users in the room will receive onUserPublishScreenAudio{@link #IRTCRoomEventHandler#onUserPublishScreenAudio}. Those who successfully received your streams will receive onFirstRemoteAudioFrame{@link #IRTCEngineEventHandler#onFirstRemoteAudioFrame} at the same time.
     *        - After calling this API, you'll receive onScreenAudioFrameSendStateChanged{@link #IRTCEngineEventHandler#onScreenAudioFrameSendStateChanged}.
     *        - Refer to [Sharing Screen in PC](https:
     */
    virtual int publishScreenAudio(bool publish) = 0;
    
    /**
     * 
     * @type api
     * @valid since 3.60.
     * @brief Subscribes to specific remote media streams captured by the local camera.  Or update the subscribe options of the subscribed user.
     * @param user_id The ID of the remote user who published the target video stream.
     * @param subscribe Whether to subscribe to the stream.
     * @return API call result: <br>
     *        - 0: Success.
     *        - <0: Failure. See ReturnStatus{@link #ReturnStatus} for specific reasons.
     * @note
     *        - Calling this API to update the subscribe configuration when the user has subscribed the remote user either by calling this API or by auto-subscribe.
     *        - You must first get the remote stream information through onUserPublishStreamVideo{@link #IRTCRoomEventHandler#onUserPublishStreamVideo} before calling this API to subscribe to streams accordingly.
     *        - After calling this API, you will be informed of the calling result with onVideoSubscribeStateChanged{@link #IRTCRoomEventHandler#onVideoSubscribeStateChanged}.
     *        - Once the local user subscribes to the stream of a remote user, the subscription to the remote user will sustain until the local user leaves the room or unsubscribe from it by calling subscribeStreamVideo{@link #IRTCRoom#subscribeStreamVideo}.
     *        - Any other exceptions will be included in onVideoSubscribeStateChanged{@link #IRTCRoomEventHandler#onVideoSubscribeStateChanged}, see SubscribeStateChangeReason{@link #SubscribeStateChangeReason} for the reasons.
     */
    virtual int subscribeStreamVideo(const char *user_id, bool subscribe) = 0;
    
    /**
     * 
     * @type api
     * @valid since 3.60.
     * @brief Subscribes to specific remote media streams captured by the local microphone.  Or update the subscribe options of the subscribed user.
     * @param user_id The ID of the remote user who published the target media stream.
     * @param subscribe Whether to subscribe to the audio stream.
     * @return API call result: <br>
     *        - 0: Success.
     *        - <0: Failure. See ReturnStatus{@link #ReturnStatus} for specific reasons.
     * @note
     *        - Calling this API to update the subscribe configuration when the user has subscribed the remote user either by calling this API or by auto-subscribe.
     *        - You must first get the remote stream information through onUserPublishStreamAudio{@link #IRTCRoomEventHandler#onUserPublishStreamAudio} before calling this API to subscribe to streams accordingly.
     *        - After calling this API, you will be informed of the calling result with onAudioSubscribeStateChanged{@link #IRTCRoomEventHandler#onAudioSubscribeStateChanged}.
     *        - Once the local user subscribes to the stream of a remote user, the subscription to the remote user will sustain until the local user leaves the room or unsubscribe from it by calling subscribeStreamAudio{@link #IRTCRoom#subscribeStreamAudio}.
     *        - Any other exceptions will be included in onAudioSubscribeStateChanged{@link #IRTCRoomEventHandler#onAudioSubscribeStateChanged}, see ErrorCode{@link #ErrorCode} for the reasons.
     */
    virtual int subscribeStreamAudio(const char *user_id, bool subscribe) = 0;
    
    /**
     * 
     * @type api
     * @valid since 3.60.
     * @brief Subscribes to specific screen sharing media stream. Or update the subscribe options of the subscribed user.
     * @param user_id The ID of the remote user who published the target screen video stream.
     * @param subscribe Whether to subscribe to the screen video stream.
     * @return API call result: <br>
     *        - 0: Success.
     *        - <0: Failure. See ReturnStatus{@link #ReturnStatus} for specific reasons.
     * @note
     *        - Calling this API to update the subscribe configuration when the user has subscribed the remote user either by calling this API or by auto-subscribe.
     *        - You must first get the remote stream information through onUserPublishScreenVideo{@link #IRTCRoomEventHandler#onUserPublishScreenVideo} before calling this API to subscribe to streams accordingly.
     *        - After calling this API, you will be informed of the calling result with onScreenVideoSubscribeStateChanged{@link #IRTCRoomEventHandler#onScreenVideoSubscribeStateChanged}.
     *        - Once the local user subscribes to the stream of a remote user, the subscription to the remote user will sustain until the local user leaves the room or unsubscribe from it by calling subscribeScreenVideo{@link #IRTCRoom#subscribeScreenVideo}.
     *        - Any other exceptions will be included in onScreenVideoSubscribeStateChanged{@link #IRTCRoomEventHandler#onScreenVideoSubscribeStateChanged}, see SubscribeStateChangeReason{@link #SubscribeStateChangeReason} for the reasons.
     */
    virtual int subscribeScreenVideo(const char *user_id, bool subscribe) = 0;
    
    /**
     * 
     * @type api
     * @valid since 3.60.
     * @brief Subscribes to specific screen sharing media stream. Or update the subscribe options of the subscribed user.
     * @param user_id The ID of the remote user who published the target screen audio stream.
     * @param subscribe Whether to subscribe to the screen audio stream.
     * @return API call result: <br>
     *        - 0: Success.
     *        - <0: Failure. See ReturnStatus{@link #ReturnStatus} for specific reasons.
     * @note
     *        - Calling this API to update the subscribe configuration when the user has subscribed the remote user either by calling this API or by auto-subscribe.
     *        - You must first get the remote stream information through onUserPublishScreenAudio{@link #IRTCRoomEventHandler#onUserPublishScreenAudio} before calling this API to subscribe to streams accordingly.
     *        - After calling this API, you will be informed of the calling result with onScreenAudioSubscribeStateChanged{@link #IRTCRoomEventHandler#onScreenAudioSubscribeStateChanged}.
     *        - Once the local user subscribes to the stream of a remote user, the subscription to the remote user will sustain until the local user leaves the room or unsubscribe from it by calling subscribeScreenAudio{@link #IRTCRoom#subscribeScreenAudio}.
     *        - Any other exceptions will be included in onScreenAudioSubscribeStateChanged{@link #IRTCRoomEventHandler#onScreenAudioSubscribeStateChanged}, see SubscribeStateChangeReason{@link #SubscribeStateChangeReason} for the reasons.
     */
    virtual int subscribeScreenAudio(const char *user_id, bool subscribe) = 0;

    
    /**
     * 
     * @type api
     * @region Video Management
     * @brief Sets your expected configuration of the remote video stream that you want to subscribe to or have subscribed to.
     * @param user_id ID of the remote video stream publisher you expect to configure subscription parameters for.
     * @param remote_video_config The parameters you expect to configure for the remote video stream, see RemoteVideoConfig{@link #RemoteVideoConfig}.
     * @return API call result: <br>
     *        - 0: Success.
     *        - <0: Failure. See ReturnStatus{@link #ReturnStatus} for specific reasons.
     * @note
     *        - This API only works after the publisher calls enableSimulcastMode{@link #IRTCVideo#enableSimulcastMode} to enable publishing multiple video streams, in which case the subscriber will receive the stream from the publisher that is closest to the set configuration;  otherwise the subscriber will only receive one video stream with a resolution of 640px × 360px and a frame rate of 15fps.
     *        - If you don't call this API after the publisher enables the function of publishing multiple streams, you will receive by default the video stream with the largest resolution set by the publisher.
     *        - You should call this API in the room. If you want to call it before entering the room, you should set the `remote_video_config` in the `room_config` when calling joinRoom{@link #IRTCRoom#joinRoom}.
     *        - SDK will automatically select the stream to be published or subscribed based on the settings of both sides.
     */
    virtual int setRemoteVideoConfig(const char *user_id,const RemoteVideoConfig &remote_video_config) = 0;

    
     /**
     * 
     * @type api
     * @region Room Management
     * @brief Subscribes to all remote media streams captured by camera/microphone. Or update the subscribe options of all subscribed user.
     * @param type Media stream type, used for specifying whether to subscribe to the audio stream or the video stream. See MediaStreamType{@link #MediaStreamType}.
     * @return API call result: <br>
     *        - 0: Success
     *        - !0: Failure
     * @note
     *        - If the subscription options conflict with the previous ones, they are subject to the configurations in the last call.
     *        - With the Audio selection enabled, if the number of media streams exceeds the limit, we recommend you subscribe each target media stream with the API follows: subscribeStreamVideo{@link #IRTCRoom#subscribeStreamVideo}, subscribeStreamAudio{@link #IRTCRoom#subscribeStreamAudio}, subscribeScreenVideo{@link #IRTCRoom#subscribeScreenVideo},  or subscribeScreenAudio{@link #IRTCRoom#subscribeScreenAudio}.
     *        - After calling this API, you will be informed of the calling result with onVideoSubscribeStateChanged{@link #IRTCRoomEventHandler#onVideoSubscribeStateChanged}, onAudioSubscribeStateChanged{@link #IRTCRoomEventHandler#onAudioSubscribeStateChanged}, onScreenVideoSubscribeStateChanged{@link #IRTCRoomEventHandler#onScreenVideoSubscribeStateChanged}, and/or onScreenAudioSubscribeStateChanged{@link #IRTCRoomEventHandler#onScreenAudioSubscribeStateChanged}. You can also find exceptions cause from the callbacks above.
     *        - Once the local user subscribes to the stream of a remote user, the subscription to the remote user will sustain until the local user leaves the room or unsubscribe from it by calling subscribeStreamVideo{@link #IRTCRoom#subscribeStreamVideo}, subscribeStreamAudio{@link #IRTCRoom#subscribeStreamAudio}, subscribeScreenVideo{@link #IRTCRoom#subscribeScreenVideo},  or subscribeScreenAudio{@link #IRTCRoom#subscribeScreenAudio}.
     */
    virtual int subscribeAllStreams(MediaStreamType type) = 0;

    
    /**
     * 
     * @type api
     * @region Room Management
     * @brief Unsubscribes from all remote media streams captured by camera/microphone. <br>
     *        You can call this API to unsubscribe from streams that are subscribed to either automatically or manually.
     * @param type Media stream type, used for specifying whether to unsubscribe from the audio stream or the video stream. See MediaStreamType{@link #MediaStreamType}.
     * @return API call result: <br>
     *        - 0: Success
     *        - !0: Failure
     * @note
     *        After calling this API, you will be informed of the calling result with onVideoSubscribeStateChanged{@link #IRTCRoomEventHandler#onVideoSubscribeStateChanged}, onAudioSubscribeStateChanged{@link #IRTCRoomEventHandler#onAudioSubscribeStateChanged}, onScreenVideoSubscribeStateChanged{@link #IRTCRoomEventHandler#onScreenVideoSubscribeStateChanged}, and/or onScreenAudioSubscribeStateChanged{@link #IRTCRoomEventHandler#onScreenAudioSubscribeStateChanged}. You can also find exceptions cause from the callbacks above.
     */
    virtual int unsubscribeAllStreams(MediaStreamType type) = 0;

    
    /**
    * 
     * @hidden for internal use only.
     */
    virtual int enableSubscribeLocalStream(bool enable) = 0;

    
    /**
     * 
     * @type api
     * @region Multi-room
     * @brief Pause receiving remote media streams.
     * @param media_type Media stream type subscribed to. Refer to PauseResumeControlMediaType{@link #PauseResumeControlMediaType}.
     * @return
     *        - 0: Success.
     *        - < 0 : Fail. See ReturnStatus{@link #ReturnStatus} for more details
     * @note
     *         - Calling this API does not change the capture state and the transmission state of the remote clients.
     *         - Calling this API does not cancel the subscription or change any subscription configuration.
     *         - To resume, call resumeAllSubscribedStream{@link #IRTCRoom#resumeAllSubscribedStream}.
     *         - In a multi-room scenario, this API only pauses the reception of streams published in the current room.
     */
    virtual int pauseAllSubscribedStream(PauseResumeControlMediaType media_type) = 0;

    
    /**
     * 
     * @type api
     * @region  multi-room
     * @brief  Resume receiving remote media streams
     * @param media_type Media stream type subscribed to. Refer to PauseResumeControlMediaType{@link #PauseResumeControlMediaType}
     * @return
     *        - 0: Success.
     *        - < 0 : Fail. See ReturnStatus{@link #ReturnStatus} for more details
     * @note
     *         - Calling this API does not change the capture state and the transmission state of the remote clients.
     *         - Calling this API does not change any subscription configuration.
     */
    virtual int resumeAllSubscribedStream(PauseResumeControlMediaType media_type) = 0;


    
    /**
     * 
     * @type api
     * @region Multi-room
     * @brief Synchronizes published audio and video. <br>
     *        When the same user simultaneously uses separate devices to capture and publish audio and video, there is a possibility that the streams are out of sync due to the network disparity. In this case, you can call this API on the video publisher side and the SDK will automatically line the video stream up according to the timestamp of the audio stream, ensuring that the audio the receiver hears corresponds to the video the receiver watches.
     * @param audio_user_id The ID of audio publisher. You can stop the current A/V synchronization by setting this parameter to null.
     * @return
     *        - 0: Success.
     *        - < 0 : Fail. Learn more details via onAVSyncEvent{@link #IRTCRoomEventHandler#onAVSyncEvent}.
     * @note
     *        - You can call this API anytime before or after entering the room.
     *        - The source user IDs of the audio and video stream to be synchronized must be in the same RTC room.
     *        - When the A/V synchronization state changes, you will receive onAVSyncStateChange{@link #IRTCRoomEventHandler#onAVSyncStateChange}.
     *        - More than one pair of audio and video can be synchronized simultaneously in the same RTC room, but you should note that one single audio source cannot be synchronized with multiple video sources at the same time.
     *        - If you want to change the audio source, call this API again with a new `audio_user_id`. If you want to change the video source, you need to stop the current synchronization first, then call this API on the new video publisher side.
     */
    virtual int setMultiDeviceAVSync(const char* audio_user_id) = 0;

    
    /**
     * 
     * @hidden for internal use only.
     */
    virtual int updateCloudRendering(const char* cloudrender_json_string) = 0;

    
    /**
     * 
     * @hidden for internal use only.
     */
    virtual int setCustomUserRole(const char* role) = 0;

    
    /**
     * 
     * @type api
     * @region Multi-room
     * @brief Start relaying media stream across rooms. <br>
     *        After calling joinRoom{@link #IRTCRoom#joinRoom}, you can call this method to publish the media stream to multiple rooms that applies to scenarios such as anOnline talent contest and so on.
     * @param configuration Information of the rooms where you want to relay the media stream to. Refer to ForwardStreamConfiguration{@link #ForwardStreamConfiguration} for more information.
     * @return
     *        0: Success <br>
     *        <0: Failure
     * @note
     *        - Call this method will trigger onForwardStreamStateChanged{@link #IRTCRoomEventHandler#onForwardStreamStateChanged}.
     *        - After calling this method, listen the events from each room during the relaying by registering onForwardStreamEvent{@link #IRTCRoomEventHandler#onForwardStreamEvent}.
     *        - Once the relaying begins, the other users in the room will receive callback of onUserJoined{@link #IRTCRoomEventHandler#onUserJoined}, onUserPublishStreamVideo{@link #IRTCRoomEventHandler#onUserPublishStreamVideo}, onUserPublishStreamAudio{@link #IRTCRoomEventHandler#onUserPublishStreamAudio}, onUserPublishScreenVideo{@link #IRTCRoomEventHandler#onUserPublishScreenVideo}, and/or onUserPublishScreenAudio{@link #IRTCRoomEventHandler#onUserPublishScreenAudio}.
     *        - Call updateForwardStreamToRooms{@link #IRTCRoom#updateForwardStreamToRooms} to add or remove the target room(s) after calling this method.
     *        - Call stopForwardStreamToRooms{@link #IRTCRoom#stopForwardStreamToRooms} to stop relaying to all rooms after calling this method.
     *        - Call pauseForwardStreamToAllRooms{@link #IRTCRoom#pauseForwardStreamToAllRooms} to pause relaying to all rooms after calling this method.
     */
    virtual int startForwardStreamToRooms(const ForwardStreamConfiguration& configuration) = 0;

    
    /**
     * 
     * @type api
     * @region Multi-room
     * @brief Update information of the rooms where you want to relay the media stream to after calling startForwardStreamToRooms{@link #IRTCRoom#startForwardStreamToRooms}. <br>
     *        Adding and removing rooms by calling this method will trigger onForwardStreamStateChanged{@link #IRTCRoomEventHandler#onForwardStreamStateChanged} on the local.
     * @param configuration Information of the rooms where you want to relay the media stream to. Refer to ForwardStreamConfiguration{@link #ForwardStreamConfiguration} for more information.
     * @return
     *         - 0: Success
     *         - <0: Failure
     * @note
     *        Users in the room which is added or removed from the target list by calling this method will receive onUserJoined{@link #IRTCRoomEventHandler#onUserJoined}, onUserPublishStreamVideo{@link #IRTCRoomEventHandler#onUserPublishStreamVideo}, onUserPublishStreamAudio{@link #IRTCRoomEventHandler#onUserPublishStreamAudio}, onUserPublishScreenVideo{@link #IRTCRoomEventHandler#onUserPublishScreenVideo}, and/or onUserPublishScreenAudio{@link #IRTCRoomEventHandler#onUserPublishScreenAudio}.
     */
    virtual int updateForwardStreamToRooms(const ForwardStreamConfiguration& configuration) = 0;

    
    /**
     * 
     * @type api
     * @region Multi-room
     * @brief Call to this method to stop relaying media stream to all rooms after calling startForwardStreamToRooms{@link #IRTCRoom#startForwardStreamToRooms}.
     * @return
     *        - 0: Success.
     *        - < 0 : Fail. See ReturnStatus{@link #ReturnStatus} for more details
     * @note
     *        - Call this method will trigger onForwardStreamStateChanged{@link #IRTCRoomEventHandler#onForwardStreamStateChanged}.
     *        - The other users in the room will receive callback of onUserJoined{@link #IRTCRoomEventHandler#onUserJoined}, onUserPublishStreamVideo{@link #IRTCRoomEventHandler#onUserPublishStreamVideo}, onUserPublishStreamAudio{@link #IRTCRoomEventHandler#onUserPublishStreamAudio}, onUserPublishScreenVideo{@link #IRTCRoomEventHandler#onUserPublishScreenVideo}, and/or onUserPublishScreenAudio{@link #IRTCRoomEventHandler#onUserPublishScreenAudio} when you stop relaying.
     *        - To stop relaying media stream to specific rooms, call updateForwardStreamToRooms{@link #IRTCRoom#updateForwardStreamToRooms} instead.
     *        - To resume the relaying in a short time, call pauseForwardStreamToAllRooms{@link #IRTCRoom#pauseForwardStreamToAllRooms} instead and then call resumeForwardStreamToAllRooms{@link #IRTCRoom#resumeForwardStreamToAllRooms} to recsume after that.
     */
    virtual int stopForwardStreamToRooms() = 0;

    
     /**
     * 
     * @type api
     * @region Multi-room
     * @brief Call this method to pause relaying media stream to all rooms after calling startForwardStreamToRooms{@link #IRTCRoom#startForwardStreamToRooms}. <br>
     *        After that, call resumeForwardStreamToAllRooms{@link #IRTCRoom#resumeForwardStreamToAllRooms} to resume.
     * @return
     *        - 0: Success.
     *        - < 0 : Fail. See ReturnStatus{@link #ReturnStatus} for more details
     * @note The other users in the room will receive callback of onUserPublishStreamVideo{@link #IRTCRoomEventHandler#onUserPublishStreamVideo}, onUserPublishStreamAudio{@link #IRTCRoomEventHandler#onUserPublishStreamAudio}, onUserPublishScreenVideo{@link #IRTCRoomEventHandler#onUserPublishScreenVideo}, and/or onUserPublishScreenAudio{@link #IRTCRoomEventHandler#onUserPublishScreenAudio} when you pause relaying.
     */
    virtual int pauseForwardStreamToAllRooms() = 0;

    
    /**
     * 
     * @type api
     * @region Multi-room
     * @brief Call this method to resume relaying to all rooms from the pause by calling pauseForwardStreamToAllRooms{@link #IRTCRoom#pauseForwardStreamToAllRooms}.
     * @return
     *        - 0: Success.
     *        - < 0 : Fail. See ReturnStatus{@link #ReturnStatus} for more details
     * @note The other users in the room will receive callback of onUserJoined{@link #IRTCRoomEventHandler#onUserJoined}, onUserPublishStreamVideo{@link #IRTCRoomEventHandler#onUserPublishStreamVideo}, onUserPublishStreamAudio{@link #IRTCRoomEventHandler#onUserPublishStreamAudio}, onUserPublishScreenVideo{@link #IRTCRoomEventHandler#onUserPublishScreenVideo}, and/or onUserPublishScreenAudio{@link #IRTCRoomEventHandler#onUserPublishScreenAudio} when you resume relaying.
     */
    virtual int resumeForwardStreamToAllRooms() = 0;

    
    /**
     * 
     * @hidden(Linux)
     * @type api
     * @region Range Audio
     * @brief Gets range audio instance.
     * @return API call result: <br>
     *        - IRangeAudio: Success. You will get an IRangeAudio{@link #IRangeAudio} returned from the SDK.
     *        - nullptr: Failure. The current SDK does not offer range audio function.
     * @note The first time this API is called must be between you create a room and you actually enter the room. Refer to [Range Voice](https:
     */
    virtual IRangeAudio* getRangeAudio() = 0;

    
    /**
     * 
     * @hidden(Linux)
     * @type api
     * @region Spatial Audio
     * @brief Gets spatial audio instance.
     * @return API call result: <br>
     *        - ISpatialAudio: Success. You will get an ISpatialAudio{@link #ISpatialAudio} returned from the SDK.
     *        - nullptr: Failure. The current SDK does not offer spatial audio function.
     * @note
     *        - The first time this API is called must be between you create a room and you actually enter the room.  Refer to [Spatial Audio](https:
     *        - Only using real dual-channel playback device can you actually enjoy spatial audio effect.
     *        - Low-end device may have audio stalling issues due to its poor performance, so it is not recommended to enable spatial audio function on such kind of devices.
     *        - SDK currently supports up to 30 users publishing audio with spatial audio enabled at the same time in the same room.
     */
    virtual ISpatialAudio* getSpatialAudio() = 0;
    
    /**
     * 
     * @type api
     * @region  multi-room
     * @brief Adjusts the audio playback volume from all the remote users in a room.
     * @param volume Ratio(%) of playback volume to original volume, in the range [0, 400], with overflow protection. <br>
     *               To ensure the audio quality, we recommend setting the volume to `100`. <br>
     *               - 0: mute
     *               - 100: original volume. Default value.
     *               - 400: Up to 4 times the original volume (with overflow protection)
     * @return
     *        - 0: Success.
     *        - < 0 : Fail. See ReturnStatus{@link #ReturnStatus} for more details
     * @note Suppose a remote user A is always within the range of the target user whose playback volume will be adjusted, <br>
     *        - If you use both this method and setRemoteAudioPlaybackVolume{@link #IRTCVideo#setRemoteAudioPlaybackVolume}, the volume that the local user hears from user A is the volume set by the method called later.
     *        - If you use both this method and setPlaybackVolume{@link #IRTCVideo#setPlaybackVolume}, the volume that the local user hears from user A is the overlay of both settings.
     */
    virtual int setRemoteRoomAudioPlaybackVolume(int volume) = 0;
    
    /**
     * 
     * @hidden for internal use only on Windows and Android
     * @type api
     * @brief Gets panoramic video engine.
     * @return API call result: <br>
     *        - IPanoramicVideo: Success. You will get an IPanoramicVideo{@link #IPanoramicVideo} returned from the SDK.
     *        - null: Failure. The current SDK does not offer range audio function.
     * @note
     *        - The API call sequence on the subscriber side is createRTCVideo{@link #createRTCVideo} > createRTCRoom{@link #IRTCVideo#createRTCRoom} > this API > joinRoom{@link #IRTCRoom#joinRoom}.
     *        - After calling this API, you can call updateQuaternionf{@link #IPanoramicVideo#updateQuaternionf} to update the position of the head represented as a quaternion.
     *        - Refer to setRemoteVideoSink{@link #IRTCVideo#setRemoteVideoSink} for details on how to render the panoramic video with an external renderer.
     */
    virtual IPanoramicVideo* getPanoramicVideo() = 0;

    
    /**
     * 
     * @valid since 3.52.
     * @type api
     * @region Room Management
     * @brief Set the priority of the local audio stream to be published.
     * @param audio_selection_priority The priority of the local audio stream which defaults to be subscribable only up to the result of the Audio Selection. Refer to AudioSelectionPriority{@link #AudioSelectionPriority}.
     * @note
     *       - You must enable Audio Selection in the RTC console before using this API. You can call this API whether the user has joined a room. Refer to [Audio Selection](https:
     *       - The setting is independent in each room that the user joins.
     */
    virtual int setAudioSelectionConfig(AudioSelectionPriority audio_selection_priority) = 0;

    
    /**
     * 
     * @valid since 3.52.
     * @type api
     * @region Room Management
     * @brief Sets extra information about the room the local user joins.
     * @param key Key of the extra information, less than 10 bytes in length. <br>
     *        A maximum of 5 keys can exist in the same room, beyond which the first key will be replaced.
     * @param value Content of the extra information, less than 128 bytes in length.
     * @return API call result: <br>
     *        - 0: Success with a taskId returned.
     *        - <0: Failure. See SetRoomExtraInfoResult{@link #SetRoomExtraInfoResult} for the reasons.
     * @note
     *        - Call joinRoom{@link #IRTCRoom#joinRoom} first before you call this API to set extra information.
     *        - After calling this API, you will receive onSetRoomExtraInfoResult{@link #IRTCRoomEventHandler#onSetRoomExtraInfoResult} callback informing you the result of the setting.
     *        - After the extra information is successfully set, other users in the same room will receive the information through onRoomExtraInfoUpdate{@link #IRTCRoomEventHandler#onRoomExtraInfoUpdate} callback.
     *        - Users who join the room later will be notified of all extra information in the room set prior to entering.
     */
    virtual int64_t setRoomExtraInfo(const char*key,const char*value) = 0;

    
    /**
     * 
     * @hidden currently not available
     * @type api
     * @region Subtitle translation service
     * @brief Recognizes or translates the speech of all speakers in the room and converts the results into captions. <br>
     *        When calling this method, you can choose the subtitle mode in the SubtitleMode{@link #SubtitleMode}. If you choose the recognition mode, you will receive the onSubtitleMessageReceived{@link #IRTCRoomEventHandler#onSubtitleMessageReceived} callback which contains the transcribed text. <br>
     *        If you choose the translation mode, you will receive two onSubtitleMessageReceived{@link #IRTCRoomEventHandler#onSubtitleMessageReceived} callbacks simultaneously, one contains the transcribed text and the other contains the translated text. <br>
     *        After calling this method, you will receive the onSubtitleStateChanged{@link #IRTCRoomEventHandler#onSubtitleStateChanged} to inform you of whether subtitles are on.
     * @param subtitle_config Subtitle configurations. Refer to SubtitleConfig{@link #SubtitleConfig} for details.
     * @return
     *        -  0: Success.
     *        - !0: Failure.
     * @note
     *        - Call this method after joining the room.
     *        - You can set your source language to Chinese by calling `joinRoom`  and importing a json formatted string `"source_language": "zh"` through the parameter of extraInfo, to English by importing `"source_language": "en"` , and to Japanese by importing `"source_language": "ja"` . If you don't set the source language, SDK will set the language of your system as the source language. If the language of your system is not Chinese, English or Japanese, SDK will set Chinese as the source language.
     */
    virtual int startSubtitle(const SubtitleConfig& subtitle_config) = 0;
    
    /**
     * 
     * @hidden currently not available
     * @type api
     * @region Subtitle translation service
     * @brief Turns off subtitles. <br>
     *        After calling this method, you will receive the onSubtitleStateChanged{@link #IRTCRoomEventHandler#onSubtitleStateChanged} to inform you of whether subtitles are off.
     * @return
     *        -  0: Success.
     *        - !0: Failure.
     */
    virtual int stopSubtitle() = 0;
    
    /**
     * 
     * @valid since 3.53
     * @type api
     * @brief Get room ID.
     * @return Room ID.
     */
    virtual const char* getRoomId() = 0;

    
    virtual const char* getCallId() = 0;
};

} 