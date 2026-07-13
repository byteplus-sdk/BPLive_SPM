/*
 * Copyright (c) 2020 The BytePlusRTC project authors. All Rights Reserved.
 * @brief BytePlusRTC Room Event Handler Interface
*/

#pragma once

#include "rtc/bytertc_defines.h"

namespace bytertc {

/**
 * 
 * @type callback
 * @brief  Audio & video room event callback interface <br>
 * Note: Callback functions are thrown synchronously in a non-UI thread within the SDK. Therefore, you must not perform any time-consuming operations or direct UI operations within the callback function, as this may cause the app to crash.
 */
class IRTCRoomEventHandler {
public:
    
    /**
     * 
     * @hidden constructor/destructor
     */
    virtual ~IRTCRoomEventHandler() {
    }

    
    /**
     * 
     * @type callback
     * @region Multi-room
     * @brief Callback on room state changes. Via this callback you get notified of room relating warnings,  errors and events. For example, the user joins the room, the user is removed from the room, and so on.
     * @param room_id  Room ID.
     * @param uid  User ID.
     * @param state Room state code. <br>
     *              - 0: Join room success.
     *              - !0: Failed to join a room, abnormal exit, room-related warnings or errors. See ErrorCode{@link #ErrorCode} and WarningCode{@link #WarningCode} for specific indications.
     * @param extra_info Extra information. <br>
     *                 `join_type` indicates the type of room the user joins. `0` means the user joins the room for the first time, and `1` means the user rejoins the room. <br>
     *                 `elapsed` indicates the time interval from calling joinRoom{@link #IRTCRoom#joinRoom} to successfully joining room, in ms.
     * @list Room Management
     */
    virtual void onRoomStateChanged(
            const char* room_id, const char* uid, int state, const char* extra_info) {
        (void)room_id;
        (void)state;
        (void)extra_info;
    }

    
    /**
     * 
     * @type callback
     * @valid since 3.60
     * @brief Callback on video-stream state changes.
     * @param room_id Room ID.
     * @param uid User ID.
     * @param state State code. See PublishState{@link #PublishState} for more.
     * @param reason See PublishStateChangeReason{@link #PublishStateChangeReason} for more.
     * @note
     *       Besides, you will also receive this callback when the local user joins the room.
     */
    virtual void onVideoPublishStateChanged(
            const char* room_id, const char* uid, PublishState state, PublishStateChangeReason reason) {
        (void)room_id;
        (void)uid;
        (void)state;
        (void)reason;
    }

    
     /**
      * 
      * @type callback
      * @region Room management
      * @brief After leaving the room successfully, receives the callback. <br>
      *        When the user calls the leaveRoom{@link #IRTCRoom#leaveRoom}, the SDK will stop all publishing subscription streams and release all call-related media resources. After that, the user receives this callback .
      * @param stats Reserved parameter.
      * @note
      *        - After the user calls the leaveRoom{@link #IRTCRoom#leaveRoom} method to leave the room, if destroy{@link #IRTCRoom#destroy} is called to destroy the room instance or destroyRTCVideo{@link #destroyRTCVideo} method is called to destroy the RTC engine immediately, this callback event will not be received.
      *        - If the app needs to use the system audio & video device after leaving the room, it is recommended to initialize the audio & video device after receiving this callback, otherwise the initialization may fail due to the SDK occupying the audio & video device.
     * @list Room Management
      */
    virtual void onLeaveRoom(const RtcRoomStats& stats) {
        (void)stats;
    }
    
    /**
     * 
     * @type callback
     * @valid since 3.60
     * @brief Callback on audio-stream state changes.
     * @param room_id Room ID.
     * @param uid User ID.
     * @param state State code. See PublishState{@link #PublishState} for more.
     * @param reason See PublishStateChangeReason{@link #PublishStateChangeReason} for more.
     * @note
     *       Besides, you will also receive this callback when the local user joins the room.
     */
    virtual void onAudioPublishStateChanged(
            const char* room_id, const char* uid, PublishState state, PublishStateChangeReason reason) {
        (void)room_id;
        (void)uid;
        (void)state;
        (void)reason;
    }

    
    /**
     * 
     * @type callback
     * @valid since 3.60
     * @brief Callback on state changes of the screen stream.
     * @param room_id Room ID.
     * @param uid User ID.
     * @param state Room state code. See PublishState{@link #PublishState} for more.
     * @param reason See PublishStateChangeReason{@link #PublishStateChangeReason} for more.
     * @note
     *       Besides, you will also receive this callback when the local user joins the room.
     */
    virtual void onScreenVideoPublishStateChanged(
            const char* room_id, const char* uid, PublishState state, PublishStateChangeReason reason) {
        (void)room_id;
        (void)uid;
        (void)state;
        (void)reason;
    }

    
    /**
     * 
     * @type callback
     * @valid since 3.60
     * @brief Callback on state changes of the device-audio stream.
     * @param room_id Room ID.
     * @param uid User ID.
     * @param state Room state code. See PublishState{@link #PublishState} for more.
     * @param reason See PublishStateChangeReason{@link #PublishStateChangeReason} for more.
     * @note
     *       Besides, you will also receive this callback when the local user joins the room.
     */
    virtual void onScreenAudioPublishStateChanged(
            const char* room_id, const char* uid, PublishState state, PublishStateChangeReason reason) {
        (void)room_id;
        (void)uid;
        (void)state;
        (void)reason;
    }

    
    /**
     * 
     * @type callback
     * @valid since 3.60
     * @brief Callback on state changes of the subscription to camera-video streams.
     * @param room_id Room ID.
     * @param uid User ID.
     * @param state Room state code. See SubscribeState{@link #SubscribeState} for more.
     * @param reason See SubscribeStateChangeReason{@link #SubscribeStateChangeReason} for more.
     */
    virtual void onVideoSubscribeStateChanged(
            const char* room_id, const char* uid, SubscribeState state, SubscribeStateChangeReason reason) {
        (void)room_id;
        (void)uid;
        (void)state;
        (void)reason;
    }

    
    /**
     * 
     * @type callback
     * @valid since 3.60
     * @region Multi-room
     * @brief Callback on state changes of the subscription to microphone-audio streams.
     * @param room_id  Room ID.
     * @param uid  User ID.
     * @param state Room state code. See SubscribeState{@link #SubscribeState} for more.
     * @param reason The reason why room state changes. See SubscribeStateChangeReason{@link #SubscribeStateChangeReason} for more.
     */
    virtual void onAudioSubscribeStateChanged(
            const char* room_id, const char* uid, SubscribeState state, SubscribeStateChangeReason reason) {
        (void)room_id;
        (void)uid;
        (void)state;
        (void)reason;
    }

    
    /**
     * 
     * @type callback
     * @valid since 3.60
     * @region Multi-room
     * @brief Callback on state changes of the subscription to screen streams.
     * @param room_id  Room ID.
     * @param uid  User ID.
     * @param state Room state code. See SubscribeState{@link #SubscribeState} for more.
     * @param reason The reason why room state changes. See SubscribeStateChangeReason{@link #SubscribeStateChangeReason} for more.
     */
    virtual void onScreenVideoSubscribeStateChanged(
            const char* room_id, const char* uid, SubscribeState state, SubscribeStateChangeReason reason) {
        (void)room_id;
        (void)uid;
        (void)state;
        (void)reason;
    }

    
    /**
     * 
     * @type callback
     * @valid since 3.60
     * @region Multi-room
     * @brief Callback on state changes of the subscription to computer-audio streams.
     * @param room_id  Room ID.
     * @param uid  User ID.
     * @param state Room state code. See SubscribeState{@link #SubscribeState} for more.
     * @param reason The reason why room state changes. See SubscribeStateChangeReason{@link #SubscribeStateChangeReason} for more.
     */
    virtual void onScreenAudioSubscribeStateChanged(
            const char* room_id, const char* uid, SubscribeState state, SubscribeStateChangeReason reason) {
        (void)room_id;
        (void)uid;
        (void)state;
        (void)reason;
    }

    
    /**
     * 
     * @hidden
     * @deprecated since 3.45 and will be deleted in 3.51, use onRoomStateChanged{@link #IRTCRoomEventHandler#onRoomStateChanged} and onStreamStateChanged{@link #IRTCRoomEventHandler#onStreamStateChanged} instead.
     * @type callback
     * @region Room Management
     * @brief SDK Warning callback occurred. When a recoverable error is encountered inside the <br>
     *        SDK, the user is notified via this callback while attempting automatic recovery. This callback event is only used as a notification.
     * @param warn Code. See WarningCode{@link #WarningCode}.
     */
    BYTERTC_DEPRECATED virtual void onRoomWarning(int warn) {
        (void)warn;
    }

    
    /**
     * 
     * @deprecated since 3.45 and will be deleted in 3.51, use onRoomStateChanged{@link #IRTCRoomEventHandler#onRoomStateChanged} and onStreamStateChanged{@link #IRTCRoomEventHandler#onStreamStateChanged} instead.
     * @type callback
     * @region Room management
     * @brief SDK Error callback occurred. <br>
     *        SDK internal encountered an unrecoverable error, will notify the App through this callback, requires the App to operate according to the error code or prompt the user.
     * @param err Error code. See ErrorCode{@link #ErrorCode}.
     */
    virtual void onRoomError(int err) {
        (void)err;
    }
    
     /**
     * 
     * @type callback
     * @brief Callback triggered 30s before the joining room privilege of the Token expires. <br>
     *        After receiving this callback, you must call updateToken{@link #IRTCRoom#updateToken} to update the joining room privilege Token.
     * @note After a user's joining room privilege expires: <br>
     *        - When attempting to join a room, the user will receive onRoomStateChanged{@link #IRTCRoomEventHandler#onRoomStateChanged} with the error code "-1000" indicating that the Token is invalid.
     *        - If the user is already in the room, he/she will be removed from the room and receive onRoomStateChanged{@link #IRTCRoomEventHandler#onRoomStateChanged} with the error code "-1009" indicating that the Token is expired. Remote users in the room will receive onUserLeave{@link #IRTCRoomEventHandler#onUserLeave} with the reason "2" indicating that the Token is invalid.
     * @list Engine Management
     * @order 10
     */
    virtual void onTokenWillExpire() {

    }
    
    /**
     * 
     * @type callback
     * @brief Callback triggered 30s before the publishing privilege of the Token expires. <br>
     *        After receiving this callback, you must call updateToken{@link #IRTCRoom#updateToken} to update the publishing privilege Token.
     * @note Once a user's publishing privilege expires: <br>
     *        - Either during stream publishing or when attempting to publish a stream, the user will get the notification of `kPublishStateChangeReasonNoPublishPermission` via onVideoPublishStateChanged{@link #IRTCRoomEventHandler#onVideoPublishStateChanged}, onAudioPublishStateChanged{@link #IRTCRoomEventHandler#onAudioPublishStateChanged}, onScreenVideoPublishStateChanged{@link #IRTCRoomEventHandler#onScreenVideoPublishStateChanged}, and/or onScreenAudioPublishStateChanged{@link #IRTCRoomEventHandler#onScreenAudioPublishStateChanged}.
     *        - The publishing streams of the user will be removed, and remote users in the room will get informed via onUserPublishStreamVideo{@link #IRTCRoomEventHandler#onUserPublishStreamVideo}, onUserPublishStreamAudio{@link #IRTCRoomEventHandler#onUserPublishStreamAudio}, onUserPublishScreenVideo{@link #IRTCRoomEventHandler#onUserPublishScreenVideo}, and/or onUserPublishScreenAudio{@link #IRTCRoomEventHandler#onUserPublishScreenAudio}.
     * @list Engine Management
     * @order 15
     */
    virtual void onPublishPrivilegeTokenWillExpire() {

    }
    
    /**
     * 
     * @type callback
     * @brief Callback triggered 30s before the subscribing privilege of the Token expires. <br>
     *        After receiving this callback, you must call updateToken{@link #IRTCRoom#updateToken} to update the subscribing privilege Token.
     * @note After a user's subscribing privilege expires, the user will get the notification of `kSubscribeStateChangeReasonNoSubscribePermission` via onVideoSubscribeStateChanged{@link #IRTCRoomEventHandler#onVideoSubscribeStateChanged}, onAudioSubscribeStateChanged{@link #IRTCRoomEventHandler#onAudioSubscribeStateChanged}, onScreenVideoSubscribeStateChanged{@link #IRTCRoomEventHandler#onScreenVideoSubscribeStateChanged}, and/or onScreenAudioSubscribeStateChanged{@link #IRTCRoomEventHandler#onScreenAudioSubscribeStateChanged}.
     * @list Engine Management
     * @order 16
     */
    virtual void onSubscribePrivilegeTokenWillExpire() {

    }

    
    /**
     * 
     * @type callback
     * @region  data statistics
     * @brief  In-room call statistics callback. <br>
     *        After the user enters the room and starts the call, he receives this callback every 2s.
     * @param stats Current RtcEngine statistics. See RtcRoomStats{@link #RtcRoomStats}
     * @list Room Management
     */
    virtual void onRoomStats(const RtcRoomStats& stats) {
        (void)stats;
    }
    
    /**
     * 
     * @hidden(Linux)
     * @type callback
     * @region Statistics
     * @brief Local stream data statistics and network quality callback. <br>
     *        After the local user publishes the flow successfully, the SDK will periodically (2s) notify the user through this callback event of the quality statistics of the published flow during this reference period. <br>
     *        Statistics are passed to the user through the callback parameters of the LocalStreamStats{@link #LocalStreamStats} type, including the sent audio & video bit rate, sent frame rate, encoded frame rate, network quality, etc.
     * @param stats Current RtcEngine statistics. See LocalStreamStats{@link #LocalStreamStats}
     */
    virtual void onLocalStreamStats(const LocalStreamStats& stats) {
        (void)stats;
    }
    
    /**
     * 
     * @type callback
     * @region Statistics
     * @brief Remote audio/video stream statistics and network quality callbacks for local subscriptions. <br>
     *        After the local user subscribes to the stream successfully, the SDK will periodically (2s) notify the user through this callback event of the quality statistics of the subscribed stream during this reference period, including: sending audio & video bit rate, sending frame rate, encoded frame rate, network quality, etc.
     * @param stats Current RtcEngine statistics. See RemoteStreamStats{@link #RemoteStreamStats}
     */
    virtual void onRemoteStreamStats(const RemoteStreamStats& stats) {
        (void)stats;
    }

    
     /**
      * 
      * @type callback
      * @region Room management
      * @brief Callback for when a remote visible user joins the room, or when an invisible user in the room switches to being visible. <br>
      *        1. When a remote user sets themselves to be visible by calling the setUserVisibility {@link #IRTCRoom#setUserVisibility} method and then joins the room, other users in the room will receive this event. <br>
      *        2. When a remote visible user who has been disconnected re-enters the room, other users in the room will receive this event. <br>
      *        3. When a hidden remote user in the room switches to being visible by calling the setUserVisibility {@link #IRTCRoom#setUserVisibility} method, other users in the room will receive this event. <br>
      *        4. A new user entering the room will receive an entry callback notification for visible users who were already in the room before they entered.
      * @param user_info See UserInfo{@link #UserInfo}.
      * @param elapsed Reserved parameter.
     * @list Room Management
      */
    virtual void onUserJoined(const UserInfo& user_info, int elapsed) {
        (void)user_info;
        (void)elapsed;
    }

    
    /**
     * 
     * @type callback
     * @brief This callback is triggered when a remote user is disconnected or turns invisible.
     * @param uid ID of the user who leaves the room, or switches to invisible.
     * @param reason Reason to leave the room. Refer to UserOfflineReason{@link #UserOfflineReason}. <br>
     *               - 0: The remote client calls leaveRoom{@link #IRTCRoom#leaveRoom} to leave the room.
     *               - 1: The remote client is disconnected because of poor network connection or expired Token.
     *               - 2: The remote client calls setUserVisibility{@link #IRTCRoom#setUserVisibility} to turn invisible.
     *               - 3: The remote user has been removed from the room by the administrator via a OpenAPI call.
     * @list Room Management
     */
    virtual void onUserLeave(const char* uid, UserOfflineReason reason) {
        (void)uid;
        (void)reason;
    }
    
    /**
     * 
     * @hidden
     * @deprecated since 3.45 and will be deleted in 3.51, use onUserUnpublishStream{@link #IRTCRoomEventHandler#onUserUnpublishStream} and onUserUnpublishScreen{@link #IRTCRoomEventHandler#onUserUnpublishScreen} instead.
     * @type callback
     * @region Room Management
     * @brief Local users will receive this callback when a remote user in the room stops publishing audio & video streams. Properties of the
     * @param stream Stream. See MediaStreamInfo{@link #MediaStreamInfo}.
     * @param reason The reason for the removal of the remote stream. See StreamRemoveReason{@link #StreamRemoveReason}.
     */
    BYTERTC_DEPRECATED virtual void onStreamRemove(const MediaStreamInfo& stream, StreamRemoveReason reason) {
        (void)stream;
    }

    
    /**
     * 
     * @hidden
     * @deprecated since 3.45 and will be deleted in 3.51, use onUserPublishStream{@link #IRTCRoomEventHandler#onUserPublishStream} and onUserPublishScreen{@link #IRTCRoomEventHandler#onUserPublishScreen} instead.
     * @type callback
     * @region Room Management
     * @brief When users in the room post a new audio & video stream, other users in the room will receive this callback. Includes streams that are removed and republished.
     * @param stream Stream properties. See MediaStreamInfo{@link #MediaStreamInfo}.
     */
    BYTERTC_DEPRECATED virtual void onStreamAdd(const MediaStreamInfo& stream) {
        (void)stream;
    }

    
    /**
     * 
     * @type callback
     * @valid since 3.60
     * @brief Callback on remote camera-video streams in the room.
     * @param room_id Room ID.
     * @param uid The ID of the remote user who published the stream.
     * @param is_publish Whether the stream is published.
     *         + `true`: Published
     *         + `false`: Removed
     * @note You will receive this callback after a remote user successfully published media streams captured by camera/microphone in the room with publishStreamVideo{@link #IRTCRoom#publishStreamVideo}. Then you can choose whether to call subscribeStreamVideo{@link #IRTCRoom#subscribeStreamVideo} to subscribe to the streams or not.
     */
    virtual void onUserPublishStreamVideo(const char* room_id, const char* uid, bool is_publish){
        (void)room_id;
        (void)uid;
        (void)is_publish;
    }

    
    /**
     * 
     * @type callback
     * @valid since 3.60
     * @region Room management
     * @brief Callback on remote microphone-audio streams in the room.
     * @param room_id Room ID.
     * @param uid The ID of the remote user who published the stream.
     * @param is_publish Whether the stream is published.
     *         + `true`: Published
     *         + `false`: Removed
     * @note You will receive this callback after a remote user successfully published media streams captured by camera/microphone in the room with publishStreamAudio{@link #IRTCRoom#publishStreamAudio}. Then you can choose whether to call subscribeStreamAudio{@link #IRTCRoom#subscribeStreamAudio} to subscribe to the streams or not.
     */
    virtual void onUserPublishStreamAudio(const char* room_id, const char* uid, bool is_publish){
        (void)room_id;
        (void)uid;
        (void)is_publish;
    }

    
    /**
     * 
     * @type callback
     * @valid since 3.60
     * @region Room management
     * @brief Callback on remote screen streams in the room.
     * @param room_id Room ID.
     * @param uid The ID of the remote user who published the stream.
     * @param is_publish Whether the stream is published.
     *         + `true`: Published
     *         + `false`: Removed
     * @note You will receive this callback after a remote user successfully published screen streams in the room with publishScreenVideo{@link #IRTCRoom#publishScreenVideo}. Then you can choose whether to call subscribeScreenVideo{@link #IRTCRoom#subscribeScreenVideo} to subscribe to the streams or not.
     */
    virtual void onUserPublishScreenVideo(const char* room_id, const char* uid, bool is_publish){
        (void)room_id;
        (void)uid;
        (void)is_publish;
    }

    
    /**
     * 
     * @type callback
     * @valid since 3.60
     * @region Room management
     * @brief Callback on remote computer-audio streams in the room.
     * @param room_id Room ID.
     * @param uid The ID of the remote user who published the stream.
     * @param is_publish Whether the stream is published.
     *         + `true`: Published
     *         + `false`: Removed
     * @note You will receive this callback after a remote user successfully published media streams captured by camera/microphone in the room with publishScreenAudio{@link #IRTCRoom#publishScreenAudio}. Then you can choose whether to call subscribeScreenAudio{@link #IRTCRoom#subscribeScreenAudio} to subscribe to the streams or not.
     */
    virtual void onUserPublishScreenAudio(const char* room_id, const char* uid, bool is_publish){
        (void)room_id;
        (void)uid;
        (void)is_publish;
    }

    
    /**
     * 
     * @hidden for internal use only
     * @type callback
     * @region Room management
     * @brief Callback the event when the release flow is successful.
     * @param user_id The user ID of the published stream.
     * @param is_screen Whether the stream is a screen stream. <br>
     *              - Ture: Screen stream;
     *              - False: Non-screen stream.
     */
    virtual void onStreamPublishSuccess(const char* user_id, bool is_screen) {
        (void)is_screen;
    }

    
    /**
     * 
     * @type callback
     * @region Real-time messaging
     * @brief Receives a callback for broadcast messages in the room.
     * @param uid <br>
     *         User ID of the message sender
     * @param message <br>
     *         Received message content
     * @note Other users in the same room will receive this callback when they call sendRoomMessage{@link #IRTCRoom#sendRoomMessage} to send a broadcast message.
     */
    virtual void onRoomMessageReceived(const char* uid, const char* message) {
        (void)uid;
        (void)message;
    }

    
    /**
     * 
     * @type callback
     * @region Real-time messaging
     * @brief Receives a callback to a binary broadcast message in the room.
     * @param uid <br>
     *         User ID of the message sender
     * @param size <br>
     *         Length of the received binary message
     * @param message <br>
     *        Binary message content received
     * @note Other users in the same room call sendRoomBinaryMessage{@link #IRTCRoom#sendRoomBinaryMessage} Receive this callback when sending a binary broadcast message.
     */
    virtual void onRoomBinaryMessageReceived(const char* uid, int size, const uint8_t* message) {
        (void)uid;
        (void)size;
        (void)message;
    }
    
    /**
     * 
     * @type callback
     * @region Real-time messaging
     * @brief Receive this callback when you receive a text message (P2P) from another user in the room.
     * @param uid <br>
     *         User ID of the message sender.
     * @param message <br>
     *         The content of the received text message.
     * @note
     *         - You must call the sendUserMessage{@link #IRTCRoom#sendUserMessage} method before you can receive the callback.
     */
    virtual void onUserMessageReceived(const char* uid, const char* message) {
        (void)uid;
        (void)message;
    }

    
    /**
     * 
     * @type callback
     * @region Real-time Message Communication
     * @brief A single user receives a callback (P2P) of binary messages from other uid-owned users in the same room.
     * @param uid User ID of the message sender.
     * @param size Message length.
     * @param message The content of the received binary message.
     */
    virtual void onUserBinaryMessageReceived(const char* uid, int size, const uint8_t* message) {
        (void)uid;
        (void)size;
        (void)message;
    }

    
    /**
     * 
     * @type callback
     * @region Real-time messaging
     * @brief After sending a text or binary message (P2P) to a single user in the room, the message sender receives a callback with the result of the message.
     * @param msgid <br>
     *             The ID of this message.
     * @param error <br>
     *             Text or binary message sending results. See UserMessageSendResult{@link #UserMessageSendResult}
     * @note
     *         - You must first call the sendUserMessage{@link #IRTCRoom#sendUserMessage} or sendUserBinaryMessage{@link #IRTCRoom#sendUserBinaryMessage} interface to receive this callback.
     */
    virtual void onUserMessageSendResult(int64_t msgid, int error) {
        (void)msgid;
        (void)error;
    }

    
    /**
     * 
     * @type callback
     * @region Real-time messaging
     * @brief When the sendRoomMessage{@link #IRTCRoom#sendRoomMessage} function is called to send a message, the sending result of this message (feedback) is called back.
     * @param msgid <br>
     *         ID of this message
     * @param error <br>
     *         Message sending result <br>
     *         See RoomMessageSendResult{@link #RoomMessageSendResult}
     */
    virtual void onRoomMessageSendResult(int64_t msgid, int error) {
        (void)msgid;
        (void)error;
    }

    
     /**
     * 
     * @hidden for internal use only
     */ 
    virtual void onRoomModeChanged(RtcRoomMode mode) {
        (void)mode;
    }

    
    /**
     * 
     * @hidden for internal use only
     * @brief callback when the maximum screen share fps is changed
     * @param fps maximum screen share fps
     */
    virtual void onMaximumScreenShareFpsUpdated(int fps) {
        (void)fps;
    }

    
    /**
     * 
     * @hidden for internal use only
     * @brief Callback when the maximum screen shared pixels (resolution) is chang
     * @param screenPixels The recommended maximum video width × height value to maintain the frame rate.
     */
    virtual void onMaximumScreenSharePixelsUpdated(int screen_pixels) {
        (void)screen_pixels;
    }

    
    /**
     * 
     * @type callback
     * @region Video management
     * @brief All the users in the room will get informed via this callback when a user is banned or the ban of the user has been lifted by calling BanUserStream/UnbanUserStream on the server side.
     * @param uid User ID of the video stream that was disabled/unbanned
     * @param banned Video stream sending status <br>
     *         - true: Video stream sending was disabled
     *         - false: Video stream sending was unbanned
     * @note
     *         - When the specified user in the room is disabled/unbanned Video stream sending, all users in the room will receive the callback.
     *        - If the banned user leaves or disconnects and then rejoins the room, the user is still banned from publishing audio stream, and all users in the room will be informed via the callback.
     *         - After the specified user is banned, other users in the room will check out and enter the room again, and will receive the callback again.
     *         - If the Audio selection is enabled in the console, only the user whose stream is banned will receive this callback.
     */
    virtual void onVideoStreamBanned(const char* uid, bool banned) {
        (void)uid;
        (void)banned;
    }

    
    /**
     * 
     * @type callback
     * @region Multi-Room
     * @brief Stream publisher will receive this callback when the A/V synchronization state changes after setMultiDeviceAVSync{@link #IRTCRoom#setMultiDeviceAVSync} is called.
     * @param state A/V synchronization state, see AVSyncState{@link #AVSyncState}.
     */
    virtual void onAVSyncStateChange(AVSyncState state) {
        (void)state;
    }

    
    /**
     * 
     * @type callback
     * @region Audio event callback
     * @brief All the users in the room will get informed via this callback when a user is banned or the ban of the user has been lifted by calling BanUserStream/UnbanUserStream on the server side.
     * @param uid Disabled/unbanned audio stream user ID
     * @param banned Audio stream sending status <br>
     *         - true: audio stream sending is disabled
     *         - false: audio stream sending is unbanned
     * @note
     *         - Specified users in the room are prohibited/all users in the room when audio stream sending is unbanned Will receive the callback.
     *        - If the banned user leaves or disconnects and then rejoins the room, the user is still banned from publishing audio stream, and all users in the room will be informed via the callback.
     *         - After the specified user is banned, other users in the room will check out and enter the room again, and will receive the callback again.
     *         - The same room is created again after dissolution, and the state in the room is empty.
     *         - If the Audio selection is enabled in the console, only the user whose stream is banned will receive this callback.
     */
    virtual void onAudioStreamBanned(const char* uid, bool banned) {
        (void)uid;
        (void)banned;
    }

    
    /**
     * 
     * @type callback
     * @region Multi-room
     * @brief Callback returning the state and errors during relaying the media stream to each of the rooms
     * @param infos Array of the state and errors of each target room. Refer to ForwardStreamStateInfo{@link #ForwardStreamStateInfo} for more information.
     * @param info_count The number of the target rooms
     */
    virtual void onForwardStreamStateChanged(ForwardStreamStateInfo* infos, int info_count) {
    }

    
    /**
     * 
     * @type callback
     * @region Multi-room
     * @brief Callback returning the events during relaying the media stream to each room
     * @param infos Array of the event of each target room. Refer to ForwardStreamEventInfo{@link #ForwardStreamEventInfo} for more information.
     * @param info_count The number of the target rooms
     */
    virtual void onForwardStreamEvent(ForwardStreamEventInfo* infos, int info_count) {
    }

    
    /**
     * 
     * @type callback
     * @brief Report the network quality of the users every 2s after the local user joins the room and starts publishing or subscribing to a stream.
     * @param local_quality Local network quality. Refer to NetworkQualityStats{@link #NetworkQualityStats} for details.
     * @param remote_qualities Network quality of the subscribed users. Refer to NetworkQualityStats{@link #NetworkQualityStats} for details.
     * @param remote_quality_num Array length of `remoteQualities`
     * @note See [In-call Stats](106866) for more information.
     */
    virtual void onNetworkQuality(const NetworkQualityStats& local_quality, const NetworkQualityStats* remote_qualities, int remote_quality_num) {
    }

    
    /**
     * 
     * @valid since 3.52.
     * @type callback
     * @region Room Management
     * @brief Callback on the result of calling setRoomExtraInfo{@link #IRTCRoom#setRoomExtraInfo} to set extra information about the room.
     * @param task_id The task ID of the API call.
     * @param error_code See SetRoomExtraInfoResult{@link #SetRoomExtraInfoResult} for the setting results and reasons.
     * @list Room Management
     */
    virtual void onSetRoomExtraInfoResult(int64_t task_id, SetRoomExtraInfoResult error_code) {
        (void)task_id;
        (void)error_code;
    }

    
    /**
     * 
     * @valid since 3.52.
     * @type callback
     * @region Room Management
     * @brief Callback used to receive the extra information set by the other users in the same room with setRoomExtraInfo{@link #IRTCRoom#setRoomExtraInfo}.
     * @param key Key of the extra information.
     * @param value Content of the extra information.
     * @param last_update_user_id The ID of the last user who updated this information.
     * @param last_update_time_ms The Unix time in ms when this information was last updated.
     * @note The user will receive the all the historical information in the room once the user joins the room.
     * @list Room Management
     */
    virtual void onRoomExtraInfoUpdate(const char*key, const char* value, const char* last_update_user_id, int64_t last_update_time_ms) {
        (void)key;
        (void)value;
        (void)last_update_user_id;
        (void)last_update_time_ms;
    }

    
    /**
     * 
     * @valid since 3.54
     * @type callback
     * @region Room Management
     * @brief Callback for user to set user visibility by calling setUserVisibility{@link #IRTCRoom#setUserVisibility}.
     * @param current_user_visibility Visibility of the current user. <br>
     *        - true: Visible. The user can publish media streams. The other users in the room get informed of the behaviors of the user, such as joining room, starting video capture, and leaving room.
     *        - false: Invisible. The user cannot publish media streams. The other users in the room do not get informed of the behaviors of the user, such as joining room, starting video capture, or leaving room.
     * @param error_code Error code for setting user visibility. See UserVisibilityChangeError{@link #UserVisibilityChangeError}.
     */
    virtual void onUserVisibilityChanged(bool current_user_visibility, UserVisibilityChangeError error_code) {
        (void)current_user_visibility;
        (void)error_code;
    }

    
    /**
     * 
     * @hidden currently not available
     * @type callback
     * @region Subtitle translation service
     * @brief  Callback on subtitle states. <br>
     *         After you call startSubtitle{@link #IRTCRoom#startSubtitle} and stopSubtitle{@link #IRTCRoom#stopSubtitle}, you will receive this callback which informs you of the states and error codes of the subtitling task, as well as detailed information on the third party services' errors.
     * @param state The states of subtitles. Refer to SubtitleState{@link #SubtitleState} for details.
     * @param error_code  Error codes of the subtitling task. Refer to SubtitleErrorCode{@link #SubtitleErrorCode}.
     * @param error_message Detailed information on the third party services' errors.
     */
    virtual void onSubtitleStateChanged(SubtitleState state, SubtitleErrorCode error_code, const char* error_message) {
    }

    
    /**
     * 
     * @hidden currently not available
     * @type callback
     * @region Subtitle translation service
     * @brief  Callback on subtitle messages. <br>
     *         After calling startSubtitle{@link #IRTCRoom#startSubtitle}, you will receive this callback which informs you of the related information on subtitles.
     * @param subtitles Subtitle messages. Refer to SubtitleMessage{@link #SubtitleMessage} for details.
     * @param cnt The number of subtitle messages.
     */
    virtual void onSubtitleMessageReceived(const SubtitleMessage* subtitles, int cnt) {
    }

    
    /**
     * 
     * @type callback
     * @valid since 3.60
     * @brief Stream publisher will receive this callback when the A/V synchronization error occurs after setMultiDeviceAVSync{@link #IRTCRoom#setMultiDeviceAVSync} is called.
     * @param room_id  Room ID.
     * @param uid  User ID.
     * @param event A/V synchronization error, see AVSyncEvent{@link #AVSyncEvent}.
     */
    virtual void onAVSyncEvent(const char* room_id, const char* uid, AVSyncEvent event) {
    }
};

} 