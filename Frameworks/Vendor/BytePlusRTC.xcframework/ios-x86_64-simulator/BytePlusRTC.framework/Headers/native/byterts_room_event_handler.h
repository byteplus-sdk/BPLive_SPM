/*
 * Copyright (c) 2022 The BytePlusRTC project authors. All Rights Reserved.
 * @brief BytePlusRTC Room Event Handler Interface
*/

#pragma once

namespace bytertc {
/** 
 * @type callback
 * @brief  Audio & video room event callback interface
 */
class IRTSRoomEventHandler {
public:
    /** 
     * @hidden constructor/destructor
     * @brief Destructor
     */
    virtual ~IRTSRoomEventHandler() {}

    /** 
     * @type callback
     * @region Multi-room
     * @brief Callback on room state changes. Via this callback you get notified of room relating warnings,  errors and events. For example, the user joins the room, the user is removed from the room, and so on.
     * @param [in] room_id  Room ID.
     * @param [in] uid  User ID.
     * @param [in] state Room state code. <br>
     *              + 0: Join room success. <br>
     *              + !0: Failed to join a room, abnormal exit, room-related warnings or errors. See ErrorCode{@link #ErrorCode} and WarningCode{@link #WarningCode} for specific indications.
     * @param [in] extra_info Extra information.
     *                 `join_type` indicates the type of room the user joins. `0` means the user joins the room for the first time, and `1` means the user rejoins the room. <br>
     *                 `elapsed` indicates the time interval from calling joinRoom{@link #IRTSRoom#joinRoom} to successfully joining room, in ms.
     */
    virtual void onRoomStateChanged(const char* room_id, const char* uid,
            int state, const char* extra_info) {
        (void)room_id;
        (void)state;
        (void)extra_info;
    }

    /** 
     * @type callback
     * @region Room management
     * @brief Leave the room callback.   <br>
     *        After the user calls the leaveRoom{@link #IRTSRoom#leaveRoom} method, the SDK stops all publishing subscription streams and notifies the user to leave the room successfully through this callback after releasing all audio & video resources related to the call. <br>
     * @notes   <br>
     *        + After the user calls the leaveRoom{@link #IRTSRoom#leaveRoom} method to leave the room, if destroy{@link #IRTSRoom#destroy} is called to destroy the room instance or destroyRTS{@link #destroyRTS} method is called to destroy the RTS engine immediately, this callback event will not be received. <br>
     *        + If the app needs to use the system audio & video device after leaving the room, it is recommended to initialize the audio & video device after receiving this callback, otherwise the initialization may fail due to the SDK occupying the audio & video device. <br>
     */
    virtual void onLeaveRoom() {
    }

    /** 
     * @deprecated since 3.45 and will be deleted in 3.51, use onRoomStateChanged{@link #IRTSRoomEventHandler#onRoomStateChanged} instead.
     * @type callback
     * @region Room Management
     * @brief SDK Warning callback occurred. When a recoverable error is encountered inside the <br>
     *        SDK, the user is notified via this callback while attempting automatic recovery. This callback event is only used as a notification. <br>
     * @param  [in] warn Code. See WarningCode{@link #WarningCode}. <br>
     */
    virtual void onRoomWarning(int warn) {
        (void)warn;
    }

    /** 
     * @deprecated since 3.45 and will be deleted in 3.51, use onRoomStateChanged{@link #IRTSRoomEventHandler#onRoomStateChanged} instead.
     * @type callback
     * @region Room management
     * @brief SDK Error callback occurred. <br>
     *        SDK internal encountered an unrecoverable error, will notify the App through this callback, requires the App to operate according to the error code or prompt the user. <br>
     * @param  [in] err Error code. See ErrorCode{@link #ErrorCode}. <br>
     */
    virtual void onRoomError(int err) {
        (void)err;
    }

    /** 
     * @type callback
     * @region Room management
     * @brief Callback about remote users joining the room.
     * @param [in] uid ID of the remote user who enters the room. <br>
     * @param [in] elapsed This parameter is meaningless.
     */
    virtual void onUserJoined(const char* uid, int elapsed) {
        (void)uid;
        (void)elapsed;
    }

    /** 
     * @type callback
     * @brief This callback is triggered when a remote user is disconnected.
     * @param [in] uid ID of the user who leaves the room. <br>
     * @param [in] reason Reason to leave the room. See UserOfflineReason{@link #UserOfflineReason}.
     */
    virtual void onUserLeave(const char* uid, UserOfflineReason reason) {
        (void)uid;
        (void)reason;
    }

    /** 
     * @type callback
     * @region Real-time messaging
     * @brief Receives a callback for broadcast messages in the room.
     * @param  [in] uid <br>
     *         User ID of the message sender
     * @param  [in] message <br>
     *         Received message content
     * @notes Other users in the same room will receive this callback when they call sendRoomMessage{@link #IRTSRoom#sendRoomMessage} to send a broadcast message.
     */
    virtual void onRoomMessageReceived(const char* uid, const char* message) {
        (void)uid;
        (void)message;
    }

    /** 
     * @type callback
     * @region Real-time messaging
     * @brief Receives a callback to a binary broadcast message in the room.
     * @param  [in] uid <br>
     *         User ID of the message sender
     * @param  [in] size <br>
     *         Binary message length received
     * @param  [in] message <br>
     *        Binary message content received
     * @notes Other users in the same room call sendRoomBinaryMessage{@link #IRTSRoom#sendRoomBinaryMessage} Receive this callback when sending a binary broadcast message.
     */
    virtual void onRoomBinaryMessageReceived(const char* uid, int size, const uint8_t* message) {
        (void)uid;
        (void)size;
        (void)message;
    }

    /** 
     * @type callback
     * @region Real-time messaging
     * @brief When the sendRoomMessage{@link #IRTSRoom#sendRoomMessage} function is called to send a message, the sending result of this message (feedback) is called back.
     * @param [in] msgid <br>
     *         ID of this message
     * @param [in] error <br>
     *         Message sending result <br>
     *         See RoomMessageSendResult{@link #RoomMessageSendResult}
     */
    virtual void onRoomMessageSendResult(int64_t msgid, int error) {
        (void)msgid;
        (void)error;
    }
};

}  

