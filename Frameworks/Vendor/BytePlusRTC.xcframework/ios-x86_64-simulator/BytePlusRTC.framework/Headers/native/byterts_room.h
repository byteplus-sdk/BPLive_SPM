/*
 * Copyright (c) 2022 The BytePlusRTC project authors. All Rights Reserved.
 * @brief BytePlusRTC Room Interface
 */

#pragma once

#include "rtc/bytertc_rts_defines.h"
#include "byterts_room_event_handler.h"

namespace bytertc {

/** 
 * @type api
 * @brief  Room interface
 */
class IRTSRoom {
public:
    /** 
     * @hidden constructor/destructor
     * @brief  Destructor
     */
    virtual ~IRTSRoom() {
    }

    /** 
     * @type api
     * @region  multi-room
     * @brief  Leave and destroy the room instance created by calling createRoom{@link #IRTS#createRoom}.
     */
    virtual void destroy() = 0;

    /** 
     * @type api
     * @region Multi-room
     * @brief Create/join a room: create a room when the room does not exist; when the room exists, users who have not joined the room can join the room.   <br>
     *        Users in the same room can talk to each other. <br>
     *         Repeated calls after entering the room are invalid. The user must call `leaveRoom` to exit the current room before joining the next room.
     * @return   <br>
     *         + 0: Success <br>
     *         + -1: Room_id/user_info.uid contains invalid parameters. <br>
     *         + -2: Already in the room. 
     * @notes   <br>
     *        + In the same room with the same App ID, the user ID of each user must be unique. If two users have the same user ID, the user who entered the room later will kick the user who entered the room out of the room, and the user who entered the room will receive the OnError{@link #IRTCAudioEventHandler#OnError} callback notification. For the error type. See kErrorCodeDuplicateLogin in ErrorCode{@link #ErrorCode}. <br>
     *        + Local users will receive onRoomStateChanged{@link #IRTSRoomEventHandler#onRoomStateChanged} callback notification after calling this method to join the room successfully. <br>
     *        + After the user successfully joins the room, the SDK may lose connection to the server in case of poor local network conditions, and the SDK will automatically reconnect at this time. After a successful reconnection, you will receive a local onRoomStateChanged{@link #IRTSRoomEventHandler#onRoomStateChanged} callback notification. If the user is set to visiable, the remote user will receive onUserJoined{@link #IRTSRoomEventHandler#onUserJoined} callback notification. 
     */
    virtual int joinRoom() = 0;

    /** 
     * @type api
     * @region Multiple rooms
     * @brief Leave the room.   <br>
     *        The user calls this method to leave the room, end the call process, and release all call-related resources. <br>
     * @return  <br>
     *        + 0: Success.
     *        + < 0 : Fail. See ReturnStatus{@link #ReturnStatus} for more details
     * @notes   <br>
     *        + This method is an asynchronous operation and does not really exit the room when the call returns. After you actually exit the room, you will receive a callback notification from onLeaveRoom{@link #IRTSRoomEventHandler#onLeaveRoom} locally. <br>
     *        + After the visible user leaves the room, other users in the room will receive an onUserLeave{@link #IRTSRoomEventHandler#onUserLeave} callback notification. <br>
     *        + If the engine is destroyed immediately after this method is called, the SDK will not be able to trigger the onLeaveRoom{@link #IRTSRoomEventHandler#onLeaveRoom} callback. <br>
     *        + After calling the joinRoom{@link #IRTSRoom#joinRoom} method to join the room, you must call this method to leave the room, otherwise you cannot enter the next room. This method can be called regardless of whether it is currently in the room. Repeated calls to this method have no negative impact. <br>
     */
    virtual int leaveRoom() = 0;

    /** 
     * @type api
     * @region multiroom
     * @brief Set the event handle of the IRTSRoom{@link #IRTSRoom} object.
     *         You can listen for callback events for the room corresponding to this IRTSRoom{@link #IRTSRoom} object by setting the event handle.
     * @param  [in] room_event_handler Callback processor. See IRTSRoomEventHandler{@link #IRTSRoomEventHandler}.
     * @return  <br>
     *        + 0: Success.
     *        + < 0 : Fail. See ReturnStatus{@link #ReturnStatus} for more details
     */
    virtual int setRTSRoomEventHandler(IRTSRoomEventHandler* room_event_handler) = 0;

    /** 
     * @type api
     * @region Multi-room
     * @brief Send broadcast messages to all other users in the room.
     * @param  [in] message <br>
     *        The broadcast message sent by the user <br>
     *        Message does not exceed 62KB.
     * @return The number of the message sent this time is incremented from 1.
     * @notes   <br>
     *        + Before sending in-room binary messages, you must call joinRoom{@link #IRTSRoom#joinRoom} to join the room. <br>
     *        + After calling this function, you get an onRoomMessageSendResult{@link #IRTSRoomEventHandler#onRoomMessageSendResult} callback. <br>
     *        + Other users in the same room receive an onRoomMessageReceived{@link #IRTSRoomEventHandler#onRoomMessageReceived} callback.
     */
    virtual int64_t sendRoomMessage(const char* message) = 0;
    /** 
     * @type api
     * @region Multi-room
     * @brief Send broadcast messages to all other users in the room.
     * @param  [in] size <br>
     *        The length of the binary message sent
     * @param  [in] message <br>
     *        The binary broadcast message sent by the user <br>
     *        The message does not exceed 46KB.
     * @return The number of the message sent this time is incremented from 1.
     * @notes   <br>
     *        + Before sending in-room binary messages, you must call joinRoom{@link #IRTSRoom#joinRoom} to join the room. <br>
     *        + After calling this function, you get an onRoomMessageSendResult{@link #IRTSRoomEventHandler#onRoomMessageSendResult} callback. <br>
     *        + Other users in the same room receive an onRoomBinaryMessageReceived{@link #IRTSRoomEventHandler#onRoomBinaryMessageReceived} callback.
     */
    virtual int64_t sendRoomBinaryMessage(int size, const uint8_t* message) = 0;
};

}  
