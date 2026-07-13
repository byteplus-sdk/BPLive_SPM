/*
 * Copyright (c) 2020 The BytePlusRTC project authors. All Rights Reserved.
 * @brief BytePlusRTC Room
*/

#import <CoreMedia/CMTime.h>
#import "rtc/ByteRTCDefines.h"
#import "rtc/ByteRTCRangeAudio.h"
#import "rtc/ByteRTCSpatialAudio.h"

@class ByteRTCRoom;


/**
 * 
 * @type callback
 * @brief  Room event callback interface <br>
 * Note: Callback functions are thrown synchronously in a non-UI thread within the SDK. Therefore, you must not perform any time-consuming operations or direct UI operations within the callback function, as this may cause the app to crash.
 */
@protocol ByteRTCRoomDelegate <NSObject>
@optional

 
 /**
  * 
  * @type callback
  * @region Multi-room
  * @brief Callback on room state changes. Via this callback you get notified of room relating warnings,  errors and events. For example, the user joins the room, the user is removed from the room, and so on.
  * @param rtcRoom ByteRTCAudioRoom instance
  * @param roomId  Room ID.
  * @param uid  User ID.
  * @param state Room state code. <br>
  *              - 0: Join room success.
  *              - !0: Failed to join a room, abnormal exit, room-related warnings or errors. See ByteRTCErrorCode{@link #ByteRTCErrorCode} and ByteRTCWarningCode{@link #ByteRTCWarningCode} for specific indications.
  * @param extraInfo Extra information. <br>
  *                 `join_type` indicates the type of room the user joins. `0` means the user joins the room for the first time, and `1` means the user rejoins the room. <br>
  *                 `elapsed` indicates the time interval from calling joinRoom:userInfo:roomConfig:{@link #ByteRTCRoom#joinRoom:userInfo:roomConfig:} to successfully joining room, in ms.
  * @list Room Management
  */
- (void)rtcRoom:(ByteRTCRoom *_Nonnull)rtcRoom onRoomStateChanged:(NSString *_Nonnull)roomId
             withUid:(nonnull NSString *)uid
           state:(NSInteger)state
           extraInfo:(NSString *_Nonnull)extraInfo;


/**
 * 
 * @type callback
 * @region Multi-room
 * @brief Callback on stream state changes. The user will receive this callback when they receive stream relating warnings and errors.
 * @param roomId  Room ID.
 * @param uid  User ID.
 * @param state Room state code. See ByteRTCErrorCode{@link #ByteRTCErrorCode} and ByteRTCWarningCode{@link #ByteRTCWarningCode} for specific indications.
 * @param extraInfo Extra information. Currently unavailable.
 */
- (void)rtcRoom:(ByteRTCRoom *_Nonnull)rtcRoom onStreamStateChanged:(NSString *_Nonnull)roomId
            withUid:(nonnull NSString *)uid
          state:(NSInteger)state
          extraInfo:(NSString *_Nonnull)extraInfo;


/**
 * 
 * @type callback
 * @region Multiple rooms
 * @brief Leave the room successfully callback. <br>
 *        When the user calls the leaveRoom{@link #ByteRTCRoom#leaveRoom} method, the SDK stops all publish subscription streams and releases all call-related audio & video resources. This callback notifies the user when the SDK completes all resource releases.
 * @param rtcRoom  ByteRTCRoom object.
 * @param stats Reserved parameter.
 * @note
 *        - After the user calls the leaveRoom{@link #ByteRTCRoom#leaveRoom} method to leave the room, if destroy{@link #ByteRTCRoom#destroy} is called to destroy the room instance or destroyRTCVideo{@link #ByteRTCVideo#destroyRTCVideo} method is called to destroy the RTC engine immediately, this callback event will not be received.
 *        - If the app needs to use the system audio & video device after leaving the room, it is recommended to initialize the audio & video device after receiving this callback, otherwise the initialization may fail due to the SDK occupying the audio & video device.
  * @list Room Management
 */
- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onLeaveRoom:(ByteRTCRoomStats *_Nonnull)stats;

 
 /**
  * 
  * @deprecated since 3.45 and will be deleted in 3.51, use rtcRoom:onRoomStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomStateChanged:withUid:state:extraInfo:} and rtcRoom:onStreamStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onStreamStateChanged:withUid:state:extraInfo:} instead.
  * @type callback
  * @region Multiple rooms
  * @brief Warning callback occurred. <br>
  *        A warning occurred during the SDK runtime. The SDK usually recovers automatically and warnings can be ignored.
  * @param rtcRoom ByteRTCRoom object.
  * @param warningCode Warning code. See enumeration type ByteRTCWarningCode{@link #ByteRTCWarningCode}.
  */
- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onRoomWarning:(ByteRTCWarningCode)warningCode __deprecated_msg("Will be removed in new version");


/**
 * 
 * @deprecated since 3.45 and will be deleted in 3.51, use rtcRoom:onRoomStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomStateChanged:withUid:state:extraInfo:} and rtcRoom:onStreamStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onStreamStateChanged:withUid:state:extraInfo:} instead.
 * @type callback
 * @region Multiple rooms
 * @brief Error callback occurred. <br>
 *        An error occurred during the SDK runtime. The SDK usually does not recover automatically, and the app needs to take action.
 * @param rtcRoom  ByteRTCRoom object.
 * @param errorCode  Error code. See enumeration type ByteRTCErrorCode{@link #ByteRTCErrorCode}.
 */
- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onRoomError:(ByteRTCErrorCode)errorCode __deprecated_msg("Will be removed in new version");


/**
 * 
 * @type callback
 * @region Multi-Room
 * @brief Stream publisher will receive this callback when the A/V synchronization state changes after setMultiDeviceAVSync:{@link #ByteRTCRoom#setMultiDeviceAVSync:} is called.
 * @param rtcRoom The ByteRTCRoom instance.
 * @param state A/V synchronization state, see ByteRTCAVSyncState{@link #ByteRTCAVSyncState}.
 */
- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onAVSyncStateChange:(ByteRTCAVSyncState)state;


- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onVideoPublishStateChanged:(NSString *_Nonnull)roomId
             Uid:(nonnull NSString *)uid
           state:(ByteRTCPublishState)state
           reason:(ByteRTCPublishStateChangeReason)reason;


- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onAudioPublishStateChanged:(NSString *_Nonnull)roomId
             Uid:(nonnull NSString *)uid
           state:(ByteRTCPublishState)state
           reason:(ByteRTCPublishStateChangeReason)reason;


- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onScreenVideoPublishStateChanged:(NSString *_Nonnull)roomId
             Uid:(nonnull NSString *)uid
           state:(ByteRTCPublishState)state
           reason:(ByteRTCPublishStateChangeReason)reason;



- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onScreenAudioPublishStateChanged:(NSString *_Nonnull)roomId
             Uid:(nonnull NSString *)uid
           state:(ByteRTCPublishState)state
           reason:(ByteRTCPublishStateChangeReason)reason;


- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onVideoSubscribeStateChanged:(NSString *_Nonnull)roomId
             Uid:(nonnull NSString *)uid
           state:(ByteRTCSubscribeState)state
           reason:(ByteRTCSubscribeStateChangeReason)reason;


- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onAudioSubscribeStateChanged:(NSString *_Nonnull)roomId
             Uid:(nonnull NSString *)uid
           state:(ByteRTCSubscribeState)state
           reason:(ByteRTCSubscribeStateChangeReason)reason;


- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onScreenVideoSubscribeStateChanged:(NSString *_Nonnull)roomId
             Uid:(nonnull NSString *)uid
           state:(ByteRTCSubscribeState)state
           reason:(ByteRTCSubscribeStateChangeReason)reason;


- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onScreenAudioSubscribeStateChanged:(NSString *_Nonnull)roomId
             Uid:(nonnull NSString *)uid
           state:(ByteRTCSubscribeState)state
           reason:(ByteRTCSubscribeStateChangeReason)reason;


/**
 * 
 * @type callback
 * @region Multiple rooms
 * @brief In-room call statistics callback. <br>
 *        After the user enters the room and starts the call, he receives this callback every 2s.
 * @param rtcRoom  ByteRTCRoom object.
 * @param stats Current ByteRTCRoom statistics, see: ByteRTCRoomStats{@link #ByteRTCRoomStats}
 * @list Room Management
 */
- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onRoomStats:(ByteRTCRoomStats *_Nonnull)stats NS_SWIFT_NAME(rtcRoom(_:onRoomStats:));


/**
 * 
 * @type callback
 * @region Multi-room
 * @brief Local stream data statistics and network quality callback. <br>
 *        After the local user publishes the flow successfully, the SDK will periodically (2s) notify the user through this callback event of the quality statistics of the published flow during this reference period. <br>
 *        Statistics are passed to the user through the callback parameters of the ByteRTCLocalStreamStats{@link #ByteRTCLocalStreamStats} type, including the sent audio & video bit rate, sent frame rate, encoded frame rate, network quality, etc.
 * @param rtcRoom  ByteRTCRoom object.
 * @param stats   Current room local stream data statistics. See: ByteRTCLocalStreamStats{@link #ByteRTCLocalStreamStats}
 */
- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onLocalStreamStats:(ByteRTCLocalStreamStats *_Nonnull)stats NS_SWIFT_NAME(rtcRoom(_:onLocalStreamStats:));


/**
 * 
 * @type callback
 * @region Multi-room
 * @brief Remote audio/video stream statistics and network quality callbacks for local subscriptions. <br>
 *        After the local user subscribes to the stream successfully, the SDK will periodically (2s) notify the user through this callback event of the quality statistics of the subscribed stream during this reference period, including: sending audio & video bit rate, sending frame rate, encoded frame rate, network quality, etc.
 * @param rtcRoom  ByteRTCRoom object.
 * @param stats  Current room local stream statistics. See: ByteRTCRemoteStreamStats{@link #ByteRTCRemoteStreamStats}
 */
- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onRemoteStreamStats:(ByteRTCRemoteStreamStats *_Nonnull)stats NS_SWIFT_NAME(rtcRoom(_:onRemoteStreamStats:));


/**
 * 
 * @type callback
 * @region Multi-room
 * @brief Callback for when a remote visible user joins the room, or when an invisible user in the room switches to being visible. <br>
 *        1. When a remote user sets themselves to be visible by calling the setUserVisibility:{@link #ByteRTCRoom#setUserVisibility:} method and then joins the room, other users in the room will receive this event. <br>
 *        2. When a remote visible user who has been disconnected re-enters the room, other users in the room will receive this event. <br>
 *        3. When a hidden remote user in the room switches to being visible by calling the setUserVisibility:{@link #ByteRTCRoom#setUserVisibility:} method, other users in the room will receive this event. <br>
 *        4. A new user entering the room will receive an entry callback notification for visible users who were already in the room before they entered.
 * @param rtcRoom ByteRTCRoom object.
 * @param userInfo  For user information. See ByteRTCUserInfo{@link #ByteRTCUserInfo}.
 * @param elapsed  Reserved field, meaningless
 * @list Room Management
 */
- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onUserJoined:(ByteRTCUserInfo *_Nonnull)userInfo elapsed:(NSInteger)elapsed;


/**
 * 
 * @type callback
 * @brief This callback is triggered when a remote user is disconnected or turns invisible.
 * @param rtcRoom ByteRTCRoom object.
 * @param uid ID of the user who leaves the room, or switches to invisible.
 * @param reason Reason to leave the room: <br>
 *               - 0: The remote client calls leaveRoom{@link #ByteRTCRoom#leaveRoom} to leave the room.
 *               - 1: The remote client is disconnected because of poor network connection or expired Token.
 *               - 2: The remote client calls setUserVisibility:{@link #ByteRTCRoom#setUserVisibility:} to turn invisible.
 *               - 3: The remote user has been removed from the room by the administrator via a OpenAPI call.
 * @list Room Management
 */
- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onUserLeave:(NSString *_Nonnull)uid reason:(ByteRTCUserOfflineReason)reason;

 /**
 * 
 * @type callback
 * @brief Callback triggered 30s before the joining room privilege of the Token expires. <br>
 *        After receiving this callback, you must call updateToken:{@link #ByteRTCRoom#updateToken:} to update the joining room privilege Token.
 * @param rtcRoom ByteRTCRoom object.
 * @note After a user's joining room privilege expires: <br>
 *        - When attempting to join a room, the user will receive rtcRoom:onRoomStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomStateChanged:withUid:state:extraInfo:} with the error code "-1000" indicating that the Token is invalid.
 *        - If the user is already in the room, he/she will be removed from the room and receive rtcRoom:onRoomStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomStateChanged:withUid:state:extraInfo:} with the error code "-1009" indicating that the Token is expired. Remote users in the room will receive rtcRoom:onUserLeave:reason:{@link #ByteRTCRoomDelegate#rtcRoom:onUserLeave:reason:} with the reason "2" indicating that the Token is invalid.
 * @list Engine Management
 * @order 10
 */
- (void)onTokenWillExpire:( ByteRTCRoom *_Nonnull)rtcRoom;

/**
 * 
 * @type callback
 * @brief Callback triggered 30s before the publishing privilege of the Token expires. <br>
 *        After receiving this callback, you must call updateToken:{@link #ByteRTCRoom#updateToken:} to update the publishing privilege Token.
 * @param rtcRoom ByteRTCRoom object.
 * @note Once a user's publishing privilege expires: <br>
     *        - Either during stream publishing or when attempting to publish a stream, the user will get the notification of `kPublishStateChangeReasonNoPublishPermission` via rtcRoom:onVideoPublishStateChanged:Uid:state:reason:{@link #ByteRTCRoomDelegate#rtcRoom:onVideoPublishStateChanged:Uid:state:reason:}, rtcRoom:onAudioPublishStateChanged:Uid:state:reason:{@link #ByteRTCRoomDelegate#rtcRoom:onAudioPublishStateChanged:Uid:state:reason:}, rtcRoom:onScreenVideoPublishStateChanged:Uid:state:reason:{@link #ByteRTCRoomDelegate#rtcRoom:onScreenVideoPublishStateChanged:Uid:state:reason:}, and/or rtcRoom:onScreenAudioPublishStateChanged:Uid:state:reason:{@link #ByteRTCRoomDelegate#rtcRoom:onScreenAudioPublishStateChanged:Uid:state:reason:}.
     *        - The publishing streams of the user will be removed, and remote users in the room will get informed via rtcRoom:onUserPublishStreamVideo:uid:isPublish:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishStreamVideo:uid:isPublish:}, rtcRoom:onUserPublishStreamAudio:uid:isPublish:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishStreamAudio:uid:isPublish:}, rtcRoom:onUserPublishScreenVideo:uid:isPublish:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishScreenVideo:uid:isPublish:}, and/or rtcRoom:onUserPublishScreenAudio:uid:isPublish:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishScreenAudio:uid:isPublish:}.
     * @list Engine Management
 * @order 15
 */
- (void)onPublishPrivilegeTokenWillExpire:( ByteRTCRoom *_Nonnull)rtcRoom;

/**
 * 
 * @type callback
 * @brief Callback triggered 30s before the subscribing privilege of the Token expires. <br>
 *        After receiving this callback, you must call updateToken:{@link #ByteRTCRoom#updateToken:} to update the subscribing privilege Token.
 * @param rtcRoom ByteRTCRoom object.
 * @note After a user's subscribing privilege expires, the user will fail to subscribe to new streams, or the subscribed streams will be removed, and he/she will receive rtcRoom:onStreamStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onStreamStateChanged:withUid:state:extraInfo:} with error code "-1003" indicating no permission to subscribe to streams.
 * @list Engine Management
 * @order 16
 */
- (void)onSubscribePrivilegeTokenWillExpire:( ByteRTCRoom *_Nonnull)rtcRoom;
 
 /**
  * 
  * @deprecated since 3.45 and will be deleted in 3.51, use rtcRoom:onUserPublishStream:type:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishStream:type:} and rtcRoom:onUserPublishScreen:type:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishScreen:type:} instead.
  * @type callback
  * @region Multiple rooms
  * @brief The following conditions trigger this callback: <br>
  *         - When users in the room post a new audio & video stream, other users in the room will receive this callback notification.
  *         - When the user's original audio and video stream in the room is removed and the audio & video stream is republished, other users in the room will receive this callback notification.
  *         - When the user first joins the room, he receives this callback, including all published streams in the room.
  * @param rtcRoom   ByteRTCRoom object.
  * @param stream  Stream property. See ByteRTCStream{@link #ByteRTCStream}.
  */
- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onStreamAdd:(id<ByteRTCStream> _Nonnull)stream __deprecated_msg("Will be removed in new version");

 
 /**
  * 
  * @hidden
  * @deprecated since 3.45 and will be deleted in 3.51, use rtcRoom:onUserUnpublishStream:type:reason:{@link #ByteRTCRoomDelegate#rtcRoom:onUserUnpublishStream:type:reason:} and rtcRoom:onUserUnpublishScreen:type:reason:{@link #ByteRTCRoomDelegate#rtcRoom:onUserUnpublishScreen:type:reason:} instead.
  * @type callback
  * @region Multi-room
  * @brief When a remote user in the room stops publishing audio & video streams, local users will receive this callback notification.
  * @param rtcRoom ByteRTCRoom object
  * @param uid User ID of the remote stream source.
  * @param stream  The properties of the stream. See ByteRTCStream{@link #ByteRTCStream}.
  * @param reason  For reasons of remote stream removal. See ByteRTCStreamRemoveReason{@link #ByteRTCStreamRemoveReason}.
  */
- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onStreamRemove:(NSString *_Nonnull)uid
              stream:(id<ByteRTCStream> _Nonnull)stream
              reason:(ByteRTCStreamRemoveReason)reason
              __deprecated_msg("Will be removed in new version");


/**
 * 
 * @hidden for internal use only
 * @type callback
 * @region multiroom
 * @brief Callback the event
 * @param rtcRoom  ByteRTCRoom object when the release stream is successful.
 * @param userId  User ID
 * @param isScreen  Whether the stream is a screen stream <br>
 *
 */

- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onStreamPublishSuccess:(NSString *_Nonnull)userId isScreen:(BOOL)isScreen;


/**
  * 
  * @type callback
  * @valid since 3.60
  * @brief Stream publisher will receive this callback when the A/V synchronization error occurs after setMultiDeviceAVSync:{@link #ByteRTCRoom#setMultiDeviceAVSync:} is called.
  * @param roomId  Room ID.
  * @param userId  User ID.
  * @param eventCode A/V synchronization error, see ByteRTCAVSyncEvent{@link #ByteRTCAVSyncEvent}.
  */
- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onAVSyncEvent:(NSString *_Nonnull)roomId userId:(NSString *_Nonnull)userId eventCode:(ByteRTCAVSyncEvent)eventCode;


/**
  * 
  * @type callback
  * @valid since 3.60
  * @brief Callback on remote camera-video streams in the room.
  * @param roomId Room ID.
  * @param uid The ID of the remote user who published the stream.
  * @param isPublish Whether the stream is published.
  *         + `true`: Published
  *         + `false`: Removed
  * @note You will receive this callback after a remote user successfully published media streams captured by camera/microphone in the room with publishStreamVideo{@link #IRTCRoom#publishStreamVideo}. Then you can choose whether to call subscribeStreamVideo{@link #IRTCRoom#subscribeStreamVideo} to subscribe to the streams or not.
  */
- (void)rtcRoom:(ByteRTCRoom* _Nonnull)rtcRoom onUserPublishStreamVideo:(NSString* _Nonnull)roomId uid:(NSString* _Nonnull)uid isPublish:(BOOL)isPublish;


/**
  * 
  * @type callback
  * @valid since 3.60
  * @region Room management
  * @brief Callback on remote microphone-audio streams in the room.
  * @param roomId Room ID.
  * @param uid The ID of the remote user who published the stream.
  * @param isPublish Whether the stream is published.
  *         + `true`: Published
  *         + `false`: Removed
  * @note You will receive this callback after a remote user successfully published media streams captured by camera/microphone in the room with publishStreamAudio:{@link #ByteRTCRoom#publishStreamAudio:}. Then you can choose whether to call subscribeStreamAudio{@link #IRTCRoom#subscribeStreamAudio} to subscribe to the streams or not.
  */
- (void)rtcRoom:(ByteRTCRoom* _Nonnull)rtcRoom onUserPublishStreamAudio:(NSString* _Nonnull)roomId uid:(NSString* _Nonnull)uid isPublish:(BOOL)isPublish;


/**
  * 
  * @type callback
  * @valid since 3.60
  * @region Room management
  * @brief Callback on remote screen streams in the room.
  * @param roomId Room ID.
  * @param uid The ID of the remote user who published the stream.
  * @param isPublish Whether the stream is published.
  *         + `true`: Published
  *         + `false`: Removed
  * @note You will receive this callback after a remote user successfully published screen streams in the room with publishScreenVideo{@link #IRTCRoom#publishScreenVideo}. Then you can choose whether to call subscribeScreenVideo{@link #IRTCRoom#subscribeScreenVideo} to subscribe to the streams or not.
  */
- (void)rtcRoom:(ByteRTCRoom* _Nonnull)rtcRoom onUserPublishScreenVideo:(NSString* _Nonnull)roomId uid:(NSString* _Nonnull)uid isPublish:(BOOL)isPublish;


/**
  * 
  * @type callback
  * @valid since 3.60
  * @region Room management
  * @brief Callback on remote computer-audio streams in the room.
  * @param roomId Room ID.
  * @param uid The ID of the remote user who published the stream.
  * @param isPublish Whether the stream is published.
  *         + `true`: Published
  *         + `false`: Removed
  * @note You will receive this callback after a remote user successfully published media streams captured by camera/microphone in the room with publishScreenAudio{@link #IRTCRoom#publishScreenAudio}. Then you can choose whether to call subscribeScreenAudio{@link #IRTCRoom#subscribeScreenAudio} to subscribe to the streams or not.
  */
- (void)rtcRoom:(ByteRTCRoom* _Nonnull)rtcRoom onUserPublishScreenAudio:(NSString* _Nonnull)roomId uid:(NSString* _Nonnull)uid isPublish:(BOOL)isPublish;
 
 /**
  * 
  * @type callback
  * @region Multi-room
  * @brief Receive this callback when you receive a broadcast text message from the room called sendRoomMessage:{@link #ByteRTCRoom#sendRoomMessage:}.
  * @param rtcRoom ByteRTCRoom object
  * @param uid User ID of the message sender.
  * @param message The content of the received text message.
  */
- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onRoomMessageReceived:(NSString *_Nonnull)uid
        message:(NSString *_Nonnull)message;

 
 /**
  * 
  * @type callback
  * @region Multi-room
  * @brief Receive this callback when you receive a broadcast binary message sent by the room call sendRoomBinaryMessage:{@link #ByteRTCRoom#sendRoomBinaryMessage:}.
  * @param rtcRoom ByteRTCRoom object
  * @param uid User ID of the message sender.
  * @param message The binary message content received.
  */
- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onRoomBinaryMessageReceived:(NSString *_Nonnull)uid
        message:(NSData *_Nonnull)message;

 
 /**
  * 
  * @type callback
  * @region Multi-room
  * @brief Receive text messages (P2P) from other users in the room via sendUserMessage:message:config:{@link #ByteRTCRoom#sendUserMessage:message:config:}.
  * @param rtcRoom ByteRTCRoom object
  * @param uid The user ID of the sender of the message.
  * @param message The content of the received text message.
  */
- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onUserMessageReceived:(NSString *_Nonnull)uid
               message:(NSString *_Nonnull)message;

 
/**
 * 
 * @type callback
 * @region Multi-room
 * @brief Receive a binary message from another user in the room via sendUserBinaryMessage:message:config:{@link #ByteRTCRoom#sendUserBinaryMessage:message:config:} Receive this callback.
 * @param rtcRoom ByteRTCRoom object
 * @param uid The user ID of the sender of the message.
 * @param message The binary message content received.
 */
- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onUserBinaryMessageReceived:(NSString *_Nonnull)uid
               message:(NSData *_Nonnull)message;

 
 /**
  * 
  * @type callback
  * @region Multi-room
  * @brief After sending a text or binary message (P2P) to a single user in the room, the message sender will receive a callback with the result of the message.
  * @param rtcRoom ByteRTCRoom object.
  * @param msgid The ID of this message.
  * @param error Message result. See ByteRTCUserMessageSendResult{@link #ByteRTCUserMessageSendResult}
  * @note
  *         - You should call sendUserMessage:message:config:{@link #ByteRTCRoom#sendUserMessage:message:config:} to send a text message to a single user in the room
  *         - You should call sendUserBinaryMessage:message:config:{@link #ByteRTCRoom#sendUserBinaryMessage:message:config:} to send a binary message to a single user in the room
  */
- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onUserMessageSendResult:(NSInteger)msgid error:(ByteRTCUserMessageSendResult)error;

 
 /**
  * 
  * @type callback
  * @region Multi-room
  * @brief Receives this callback after sending a text message or a binary message to a room with sendRoomMessage:{@link #ByteRTCRoom#sendRoomMessage:} or sendRoomBinaryMessage:{@link #ByteRTCRoom#sendRoomBinaryMessage:}.
  * @param rtcRoom ByteRTCRoom object.
  * @param msgid The ID of this message.
  * @param error  Message sending results. See ByteRTCRoomMessageSendResult{@link #ByteRTCRoomMessageSendResult}
  * @note
  *         - You should call sendRoomMessage:{@link #ByteRTCRoom#sendRoomMessage:} Send a mass text message to the room
  *         - You should call sendRoomBinaryMessage:{@link #ByteRTCRoom#sendRoomBinaryMessage:} Send a mass binary message to the room
  */
- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onRoomMessageSendResult:(NSInteger)msgid error:(ByteRTCRoomMessageSendResult)error;


/**
 * 
 * @valid since 3.52.
 * @type callback
 * @region Multi-room
 * @brief Receives this callback after invoke setRoomExtraInfo:value:{@link #ByteRTCRoom#setRoomExtraInfo:value:}.
 * @param rtcRoom ByteRTCRoom object.
 * @param taskId The ID of this setRoomExtraInfo invoke.
 * @param error setRoomExtraInfo result. See ByteRTCSetRoomExtraInfoResult{@link #ByteRTCSetRoomExtraInfoResult}
 * @list Room Management
 */
- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onSetRoomExtraInfoResult:(NSInteger)taskId error:(ByteRTCSetRoomExtraInfoResult)error;


/**
 * 
 * @valid since 3.52.
 * @type callback
 * @region Multi-room
 * @brief Receive a callback when other user invoke setRoomExtraInfo:value:{@link #ByteRTCRoom#setRoomExtraInfo:value:} . <br>
 *        or when user joinRoom success and this room has room extra info.
 * @param rtcRoom ByteRTCRoom object.
 * @param key Key of room attribute
 * @param value Key of room attribute
 * @param lastUpdateUserId The userId that last updated this attribute
 * @param lastUpdateTimeMs The last time this attribute was updated, in milliseconds，unixtime style
 * @list Room Management
 */
- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onRoomExtraInfoUpdate:(NSString *_Nonnull)key value:(NSString *_Nonnull)value lastUpdateUserId:(NSString *_Nonnull)lastUpdateUserId 
                 lastUpdateTimeMs:(NSInteger)lastUpdateTimeMs;


/**
 * 
 * @valid since 3.54
 * @type callback
 * @region Room Management
 * @brief Callback for user to set user visibility by calling setUserVisibility:{@link #ByteRTCRoom#setUserVisibility:}.
 * @param currentUserVisibility Visibility of the current user. <br>
 *        - YES: Visible. The user can publish media streams. The other users in the room get informed of the behaviors of the user, such as joining room, starting video capture, and leaving room.
 *        - NO: Invisible. The user cannot publish media streams. The other users in the room do not get informed of the behaviors of the user, such as joining room, starting video capture, or leaving room.
 * @param errorCode Error code for setting user visibility. See ByteRTCUserVisibilityChangeError{@link #ByteRTCUserVisibilityChangeError}.
 */
- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onUserVisibilityChanged:(BOOL)currentUserVisibility errorCode:(ByteRTCUserVisibilityChangeError)errorCode;


/**
 * 
 * @type callback
 * @region Video management
 * @brief All the users in the room will get informed via this callback when a user is banned or the ban of the user has been lifted by calling BanUserStream/UnbanUserStream on the server side.
 * @param uid Disabled/unbanned video stream user ID
 * @param banned Video stream sending status <br>
 *         - true: Video stream sending is disabled
 *         - false: Video stream sending is unbanned
 * @note
 *         - When the specified user in the room is banned/unbanned video stream sending, all users in the room will receive the callback.
 *         - If the banned user leaves or disconnects and then rejoins the room, the user is still banned from publishing audio stream, and all users in the room will be informed via the callback.
 *         - After the specified user is banned, other users in the room will check out and enter the room again, and will receive the callback again.
 *         - After the same room is disbanded and created again, the status in the room is cleared.
 */
- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onVideoStreamBanned:(NSString *_Nonnull)uid isBanned:(BOOL)banned;


/**
 * 
 * @type callback
 * @region Audio event callback
 * @brief All the users in the room will get informed via this callback when a user is banned or the ban of the user has been lifted by calling BanUserStream/UnbanUserStream on the server side.
 * @param uid Disabled/unbanned audio stream user ID
 * @param banned Audio stream sending status <br>
 *         - true: Audio stream sending is disabled
 *         - false: Audio stream sending is unbanned
 * @note
 *         - When the specified user in the room is disabled/unbanned audio stream sending, all users in the room will receive the callback.
 *        - If the banned user leaves or disconnects and then rejoins the room, the user is still banned from publishing audio stream, and all users in the room will be informed via the callback.
 *         - After the specified user is banned, other users in the room will check out and enter the room again, and will receive the callback again.
 *         - After the same room is disbanded and created again, the status in the room is cleared.
 *         - If the Audio selection is enabled in the console, only the user whose stream is banned will receive this callback.
 */
- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onAudioStreamBanned:(NSString *_Nonnull)uid isBanned:(BOOL)banned;

#pragma mark ForwardStream related callback
    
    /**
     * 
     * @type callback
     * @region Multi-room
     * @brief Callback returning the state and errors during relaying the media stream to each of the rooms
     * @param rtcRoom ByteRTCRoom object
     * @param infos Array of the state and errors of each designated room. Refer to ByteRTCForwardStreamStateInfo{@link #ByteRTCForwardStreamStateInfo} for more information.
     */
- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onForwardStreamStateChanged:(NSArray<ByteRTCForwardStreamStateInfo *> * _Nonnull)infos;
    
    /**
     * 
     * @type callback
     * @region Multi-room
     * @brief Callback returning the events during relaying the media stream to each room
     * @param rtcRoom RTCRoom object
     * @param infos Array of the event of each designated room. Refer to ByteRTCForwardStreamEventInfo{@link #ByteRTCForwardStreamEventInfo} for more information.
     */
- (void)rtcRoom:( ByteRTCRoom * _Nonnull)rtcRoom onForwardStreamEvent:(NSArray<ByteRTCForwardStreamEventInfo *> * _Nonnull)infos;


/**
 * 
 * @type callback
 * @brief Report the network quality of the users every 2s after the local user joins the room and starts publishing or subscribing to a stream.
 * @param rtcRoom ByteRTCRoom object
 * @param localQuality Local network quality. Refer to ByteRTCNetworkQualityStats{@link #ByteRTCNetworkQualityStats}.
 * @param remoteQualities Network quality of the subscribed users. Refer to ByteRTCNetworkQualityStats{@link #ByteRTCNetworkQualityStats} for details.
 * @note See [In-call Stats](106866) for more information.
 */
- (void)rtcRoom:(ByteRTCRoom * _Nonnull)rtcRoom onNetworkQuality:(ByteRTCNetworkQualityStats *_Nonnull)localQuality remoteQualities:(NSArray<ByteRTCNetworkQualityStats*> *_Nonnull)remoteQualities;


/**
 * 
 * @hidden currently not available
 * @type callback
 * @region Subtitle translation service
 * @brief  Callback on subtitle states. <br>
 *         After you call startSubtitle:{@link #ByteRTCRoom#startSubtitle:} and stopSubtitle{@link #ByteRTCRoom#stopSubtitle}, you will receive this callback which informs you of the states and error codes of the subtitling task, as well as detailed information on the third party services' errors.
 * @param rtcRoom ByteRTCRoom instance.
 * @param state The states of subtitles. Refer to ByteRTCSubtitleState{@link #ByteRTCSubtitleState} for details.
 * @param errorCode  Error codes of the subtitling task. Refer to  ByteRTCSubtitleErrorCode{@link #ByteRTCSubtitleErrorCode} for details.
 * @param errorMessage  Detailed information on the third party services' errors. If the states of subtitles are changed due to the third party services, you will receive this parameter which informs you of the detailed information on the third party services' errors.
 */
- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onSubtitleStateChanged:(ByteRTCSubtitleState)state
                                                             errorCode:(ByteRTCSubtitleErrorCode)errorCode
                                                          errorMessage:(NSString *_Nonnull)errorMessage;
                                                          

/**
 * 
 * @hidden currently not available
 * @type callback
 * @region Subtitle translation service
 * @brief Callback on subtitle messages. <br>
 *        After calling startSubtitle:{@link #ByteRTCRoom#startSubtitle:}, you will receive this callback which informs you of the related information on subtitles.
 * @param rtcRoom ByteRTCRoom instance.
 * @param subtitles  Subtitle messages. Refer to ByteRTCSubtitleMessage{@link #ByteRTCSubtitleMessage} for details.
 */
- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onSubtitleMessageReceived:(NSArray<ByteRTCSubtitleMessage*> * _Nonnull)subtitles;
@end


/**
 * 
 * @type api
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCRoom : NSObject

/** 
 * @type callback
 */
@property(nonatomic, weak) id<ByteRTCRoomDelegate> _Nullable delegate;

#pragma mark - Core Methods


/**
 * 
 * @type api
 * @region multi-room
 * @brief Leave and destroy the room instance created by calling createRTCRoom:{@link #ByteRTCVideo#createRTCRoom:}.
 * @list Room Management
 */
- (void)destroy;


/**
 * 
 * @type api
 * @brief Get room ID.
 * @return Room ID.
 */
- (NSString *_Nonnull)getRoomId;


/**
 * 
 * @type api
 * @region Multi-room
 * @brief Listens for event callbacks related to the ByteRTCRoom{@link #ByteRTCRoom} instance by setting the event handler of this instance.
 * @param roomDelegate Refer to ByteRTCRoomDelegate{@link #ByteRTCRoomDelegate}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @list Room Management
 */

- (int)setRTCRoomDelegate:(id<ByteRTCRoomDelegate> _Nullable)roomDelegate;


/**
 * 
 * @type api
 * @region Multiple rooms
 * @brief Join the room. <br>
 *        After creating a room by calling createRTCRoom:{@link #ByteRTCVideo#createRTCRoom:}, call this API to join the room and make audio & video calls with other users in the room.
 * @param token Dynamic key for authentication and verification of users entering the room. <br>
 *         You need to bring Token to enter the room. When testing, you can use the console to generate temporary tokens. The official launch requires the use of the key SDK to generate and issue tokens at your server level. See [Authentication with Token](70121) for token validity and generation method. <br>
 *         Apps with different AppIDs are not interoperable. <br>
 *         Make sure that the AppID used to generate the Token is the same as the AppID used to create the engine, otherwise it will cause the join room to fail.
 * @param userInfo User information. See ByteRTCUserInfo{@link #ByteRTCUserInfo}.
 * @param roomConfig Room parameter configuration, set the room mode and whether to automatically publish or subscribe to the flow. See ByteRTCRoomConfig{@link #ByteRTCRoomConfig} for the specific configuration mode.
 * @return  Method call result. <br>
 *         - 0: Success. 
 *            - Local users receive notifications of the room state via onRoomStateChanged{@link #ByteRTCRoomDelegate#onRoomStateChanged}. 
 *            - Local users receive notifications of the local-stream state via rtcRoom:onVideoPublishStateChanged:Uid:state:reason:{@link #ByteRTCRoomDelegate#rtcRoom:onVideoPublishStateChanged:Uid:state:reason:}, rtcRoom:onAudioPublishStateChanged:Uid:state:reason:{@link #ByteRTCRoomDelegate#rtcRoom:onAudioPublishStateChanged:Uid:state:reason:}, rtcRoom:onScreenVideoPublishStateChanged:Uid:state:reason:{@link #ByteRTCRoomDelegate#rtcRoom:onScreenVideoPublishStateChanged:Uid:state:reason:}, and/or rtcRoom:onScreenAudioPublishStateChanged:Uid:state:reason:{@link #ByteRTCRoomDelegate#rtcRoom:onScreenAudioPublishStateChanged:Uid:state:reason:}.
 *            - Local users receive notifications of the subscribed-stream state via rtcRoom:onUserPublishStreamVideo:uid:isPublish:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishStreamVideo:uid:isPublish:}, rtcRoom:onUserPublishStreamAudio:uid:isPublish:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishStreamAudio:uid:isPublish:}, rtcRoom:onUserPublishScreenVideo:uid:isPublish:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishScreenVideo:uid:isPublish:}, and/or rtcRoom:onUserPublishScreenAudio:uid:isPublish:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishScreenAudio:uid:isPublish:}.
 *            - Local users receive notifications of the published-stream state via rtcRoom:onUserPublishStreamVideo:uid:isPublish:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishStreamVideo:uid:isPublish:}, rtcRoom:onUserPublishStreamAudio:uid:isPublish:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishStreamVideo:uid:isPublish:}, rtcRoom:onUserPublishScreenVideo:uid:isPublish:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishScreenVideo:uid:isPublish:}, and/or rtcRoom:onUserPublishScreenAudio:uid:isPublish:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishScreenAudio:uid:isPublish:}.
 *            - If the local user is also a visible user, the other participants receive onUserJoined{@link #ByteRTCRoomDelegate#onUserJoined} callback.
 *         - -1: Invalid parameter
 *         - -2: Already in the room. After the interface call is successful, as long as the return value of 0 is received and leaveRoom{@link #ByteRTCRoom#leaveRoom} is not called successfully, this return value will be triggered when the room entry interface is called again, regardless of whether the filled room ID and user ID are duplicated.
 *         The reason for the failure will be communicated via the rtcRoom:onRoomStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomStateChanged:withUid:state:extraInfo:} callback.
 * @note
 *         - In the same room with the same AppID, the user ID of each user must be unique. If two users have the same user ID, the user who joined the room later will kick the user who joined the room first out of the room, and the user who joined the room first will receive rtcRoom:onRoomStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomStateChanged:withUid:state:extraInfo:} callback notification, the error type is duplicate login ByteRTCErrorCodeDuplicateLogin.
 *         - Local users will receive rtcRoom:onRoomStateChanged:withUid:state:reason:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomStateChanged:withUid:state:reason:} callback notification after calling this method to join the room successfully. If the local user is also a visible user, the remote user will receive an rtcRoom:onUserJoined:{@link #ByteRTCRoomDelegate#rtcRoom:onUserJoined:} callback notification when joining the room.
 *         - By default, the user is visible in an RTC room. Joining fails when the number of users in an RTC room reaches its upper limit. To avoid this, call setUserVisibility:{@link #ByteRTCRoom#setUserVisibility:} to change the visibility of the audience users to `false` by considering the capacity for the invisible users is much larger than that for visible users. An RTC room can accommodate a maximum of 50 visible users, and 30 media streams can be published simultaneously. For more information, see [Capability of Users and Streams](https:
 *         - After the user successfully joins the room, the SDK may lose connection to the server in case of poor local network conditions. At this time rtcEngine:onConnectionStateChanged:{@link #ByteRTCVideoDelegate#rtcEngine:onConnectionStateChanged:} callback will be triggered and the SDK will automatically retry until it successfully reconnects to the server. After successful reconnection, you will receive a callback notification from rtcRoom:onUserJoined:elapsed:{@link #ByteRTCRoomDelegate#rtcRoom:onUserJoined:elapsed:} locally.
 * @list Room Management
 */
- (int)joinRoom:(NSString *_Nullable)token userInfo:(ByteRTCUserInfo *_Nonnull)userInfo roomConfig:(ByteRTCRoomConfig *_Nonnull)roomConfig NS_SWIFT_NAME(joinRoom(_:userInfo:roomConfig:));


/**
 * 
 * @type api
 * @region Room management
 * @brief Set the visibility of the user in the room. The local user is visible to others by default before calling this API. <br>
 *        An RTC room can accommodate a maximum of 50 visible users, and 30 media streams can be published simultaneously. For more information, see [Room Capacity](https:
 * @param enable Visibility of the user in the room. <br>
 *        - YES: The user can publish media streams. The other users in the room get informed of the behaviors of the user, such as joining room, starting video capture, and leaving room.
 *        - NO: The user cannot publish media streams. The other users in the room do not get informed of the behaviors of the user, such as joining room, starting video capture, or leaving room.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
 *        You will receive rtcRoom:onUserVisibilityChanged:errorCode:{@link #ByteRTCRoomDelegate#rtcRoom:onUserVisibilityChanged:errorCode:} after calling this API. (Available since v3.54)
 *        - If you call this API before joining room, and the set value is different from the default value, you will receive the callback when you join the room. 
 *        - If you call this API after joining room, and the current visibility is different from the previous value, you will receive the callback. 
 *        - When reconnecting after losing internet connection, if the visibility changes, you will receive the callback. 
 * @note
 *        - You can call this API whether the user is in a room or not.
 *        - When you call this API while you are in the room, the other users in the room will be informed via the following callback.
 *   &#x0020;  • When you switch from `false` to `true`, they will receive rtcRoom:onUserJoined:elapsed:{@link #ByteRTCRoomDelegate#rtcRoom:onUserJoined:elapsed:}. <br>
 *   &#x0020;  • When you switch from `true` to `false`, they will receive rtcRoom:onUserLeave:reason:{@link #ByteRTCRoomDelegate#rtcRoom:onUserLeave:reason:}. <br>
 *   &#x0020;  • The invisible user will receive the warning code, `ByteRTCWarningCodeSubscribeStreamForbiden`, when trying to publish media streams.
 * @list Room Management
 */
- (int)setUserVisibility:(BOOL)enable;


/**
 * 
 * @type api
 * @region Multi-room
 * @brief Synchronizes published audio and video. <br>
 *        When the same user simultaneously uses separate devices to capture and publish audio and video, there is a possibility that the streams are out of sync due to the network disparity. In this case, you can call this API on the video publisher side and the SDK will automatically line the video stream up according to the timestamp of the audio stream, ensuring that the audio the receiver hears corresponds to the video the receiver watches.
 * @param audioUserId The ID of audio publisher. You can stop the current A/V synchronization by setting this parameter to null.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. Learn more details via rtcRoom:onAVSyncEvent:userId:eventCode:{@link #ByteRTCRoomDelegate#rtcRoom:onAVSyncEvent:userId:eventCode:}.
 * @note
 *        - You can call this API anytime before or after entering the room.
 *        - The source user IDs of the audio and video stream to be synchronized must be in the same RTC room.
 *        - When the A/V synchronization state changes, you will receive rtcRoom:onAVSyncStateChange:{@link #ByteRTCRoomDelegate#rtcRoom:onAVSyncStateChange:}.
 *        - More than one pair of audio and video can be synchronized simultaneously in the same RTC room, but you should note that one single audio source cannot be synchronized with multiple video sources at the same time.
 *        - If you want to change the audio source, call this API again with a new `audioUserId`. If you want to change the video source, you need to stop the current synchronization first, then call this API on the new video publisher side.
 */
- (int)setMultiDeviceAVSync:(NSString* _Nullable) audioUserId;


/**
 * 
 *  @type api
 *  @region room management
 *  @brief Leaves the room. <br>
 *         The user calls this method to leave the room, end the call process, and release all call-related resources.
 * @return
 *        - 0: Success. If the user is a host:
 *            - The other participants receive rtcRoom:onUserLeave:reason:{@link #ByteRTCRoomDelegate#rtcRoom:onUserLeave:reason:} callback.
 *            - The publishing streams stop and the other participants receive notifications of the stream states via rtcRoom:onVideoPublishStateChanged:Uid:state:reason:{@link #ByteRTCRoomDelegate#rtcRoom:onVideoPublishStateChanged:Uid:state:reason:}, rtcRoom:onAudioPublishStateChanged:Uid:state:reason:{@link #ByteRTCRoomDelegate#rtcRoom:onAudioPublishStateChanged:Uid:state:reason:}, rtcRoom:onScreenVideoPublishStateChanged:Uid:state:reason:{@link #ByteRTCRoomDelegate#rtcRoom:onScreenVideoPublishStateChanged:Uid:state:reason:} and/or rtcRoom:onScreenAudioPublishStateChanged:Uid:state:reason:{@link #ByteRTCRoomDelegate#rtcRoom:onScreenAudioPublishStateChanged:Uid:state:reason:} callback.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *         - After the user leaves the room, the local will receive a callback for rtcRoom:onLeaveRoom:{@link #ByteRTCRoomDelegate#rtcRoom:onLeaveRoom:};
 *         - Call setUserVisibility:{@link #ByteRTCRoom#setUserVisibility:} method sets itself to be visible. After the user leaves the room, other users in the room will receive rtcRoom:onUserLeave:reason:{@link #ByteRTCRoomDelegate#rtcRoom:onUserLeave:reason:} callback notification.
 * @list Room Management
 */
- (int)leaveRoom NS_SWIFT_NAME(leaveRoom());



/**
 * 
 * @type api
 * @brief Update Token. <br>
 *        You must call this API to update token to ensure the RTC call to continue when you receive onTokenWillExpire:{@link #ByteRTCRoomDelegate#onTokenWillExpire:}, onPublishPrivilegeTokenWillExpire:{@link #ByteRTCRoomDelegate#onPublishPrivilegeTokenWillExpire:}, or onSubscribePrivilegeTokenWillExpire:{@link #ByteRTCRoomDelegate#onSubscribePrivilegeTokenWillExpire:}.
 * @param token  Valid token. <br>
 *        If the Token is invalid, you will receive rtcRoom:onRoomStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomStateChanged:withUid:state:extraInfo:} with the error code of `-1010`.
 * @return
 *        - 0: Success
 *        - !0: Failure
 * @note
 *      - In versions before 3.50, the publish and subscribe privileges contained in the Token are reserved parameters with no actual control permissions. In version 3.50 and later, the publish/subscribe privileges will be effective for whitelisted users. Please contact the technical support team to include you in the whitelist if you need this function.
 *      - Do not call both updateToken:{@link #ByteRTCRoom#updateToken:} and joinRoom:userInfo:roomConfig:{@link #ByteRTCRoom#joinRoom:userInfo:roomConfig:} to update the Token. If you fail to join the room or have been removed from the room due to an expired or invalid Token, call joinRoom:userInfo:roomConfig:{@link #ByteRTCRoom#joinRoom:userInfo:roomConfig:} with a valid token to rejoin the room.
 * @list Room Management
 */
- (int)updateToken:(NSString *_Nullable)token;

/**
 * 
 * @type api
 * @region Video Management
 * @brief Sets your expected configuration of the remote video stream that you want to subscribe to or have subscribed to.
 * @param userId ID of the remote video stream publisher you expect to configure subscription parameters for.
 * @param remoteVideoConfig The parameters you expect to configure for the remote video stream, see ByteRTCRemoteVideoConfig{@link #ByteRTCRemoteVideoConfig}.
 * @return API call result: <br>
 *        - 0: Success
 *        - !0: Failure
 * @note
 *        - This API only works after the publisher calls enableSimulcastMode:{@link #ByteRTCVideo#enableSimulcastMode:} to enable publishing multiple video streams, in which case the subscriber will receive the stream from the publisher that is closest to the set configuration;  otherwise the subscriber will only receive one video stream with a resolution of 640px × 360px and a frame rate of 15fps.
 *        - If you don't call this API after the publisher enables the function of publishing multiple streams, you will receive by default the video stream with the largest resolution set by the publisher.
 *        - You should call this API in the room. If you want to call it before entering the room, you should set the `remoteVideoConfig` in the `roomConfig ` when calling joinRoom:userInfo:roomConfig:{@link #ByteRTCRoom#joinRoom:userInfo:roomConfig:}.
 *        - SDK will automatically select the stream to be published or subscribed based on the settings of both sides. See [Simulcasting](https:
 */
- (int) setRemoteVideoConfig:(NSString * _Nonnull) userId remoteVideoConfig:(ByteRTCRemoteVideoConfig *_Nonnull) remoteVideoConfig;


/**
  * 
  * @type api
  * @valid since 3.60.
  * @brief Start or stop publishing video streams captured by camera in the current room.
  * @param publish Whether to publish the media stream.
  * @return
  *        - 0: Success.
  *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
  * @note
  *        - You don't need to call this API if you set it to Auto-publish when calling joinRoom:userInfo:roomConfig:{@link #ByteRTCRoom#joinRoom:userInfo:roomConfig:}.
  *        - An invisible user cannot publish media streams. Call setUserVisibility{@link #IRTCRoom#setUserVisibility} to change your visibility in the room.
  *        - Call publishScreenAudio:{@link #ByteRTCRoom#publishScreenAudio:} (not supported on Linux) and/or publishScreenVideo:{@link #ByteRTCRoom#publishScreenVideo:} to start or stop screen sharing.
  *        - Call publishStreamAudio:{@link #ByteRTCRoom#publishStreamAudio:} to start or stop publishing the audio stream captured by the microphone.
  *        - Call startForwardStreamToRooms:{@link #ByteRTCRoom#startForwardStreamToRooms:} to forward the published streams to the other rooms.
  *        - After you call this API, the other users in the room will receive rtcRoom:onUserPublishStreamVideo:uid:isPublish:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishStreamVideo:uid:isPublish:}. Those who successfully received your streams will receive rtcEngine:onFirstRemoteVideoFrameDecoded:withFrameInfo:{@link #ByteRTCRoomDelegate#rtcEngine:onFirstRemoteVideoFrameDecoded:withFrameInfo:} at the same time.
  */
- (int)publishStreamVideo:(BOOL)publish;


/**
  * 
  * @type api
  * @valid since 3.60.
  * @brief Start or stop publishing media streams captured by the local microphone in the current room.
  * @param publish Whether to publish the media stream.
  * @return
  *        - 0: Success.
  *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
  * @note
  *        - You don't need to call this API if you set it to Auto-publish when calling joinRoom:userInfo:roomConfig:{@link #ByteRTCRoom#joinRoom:userInfo:roomConfig:}.
  *        - An invisible user cannot publish media streams. Call setUserVisibility{@link #IRTCRoom#setUserVisibility} to change your visibility in the room.
  *        - Call publishScreenAudio:{@link #ByteRTCRoom#publishScreenAudio:} (not supported on Linux) and/or publishScreenVideo:{@link #ByteRTCRoom#publishScreenVideo:} to start or stop screen sharing.
  *        - Call publishStreamVideo:{@link #ByteRTCRoom#publishStreamVideo:} to start or stop publishing the video stream captured by the camera.
  *        - Call startForwardStreamToRooms:{@link #ByteRTCRoom#startForwardStreamToRooms:} to forward the published streams to the other rooms.
  *        - After you call this API, the other users in the room will receive rtcRoom:onUserPublishStreamAudio:uid:isPublish:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishStreamAudio:uid:isPublish:}. Those who successfully received your streams will receive rtcEngine:onFirstRemoteAudioFrame:{@link #ByteRTCEngineDelegate#rtcEngine:onFirstRemoteAudioFrame:} at the same time.
  */
- (int)publishStreamAudio:(BOOL)publish;


/**
  * 
  * @type api
  * @valid since 3.60.
  * @brief Start or stop sharing the local screen in the room.
  *        If you need to share your screen in multiple rooms, you can use the same uid to join multiple rooms and call this API in each room. Also, you can publish different types of screen-sharing streams in different rooms.
  * @param publish Whether to publish video stream.
  * @return
  *        - 0: Success.
  *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
  * @note
  *        - You need to call this API to publish screen even if you set it to Auto-publish when calling joinRoom:userInfo:roomConfig:{@link #ByteRTCRoom#joinRoom:userInfo:roomConfig:}.
  *        - An invisible user cannot publish media streams. Call setUserVisibility{@link #IRTCRoom#setUserVisibility} to change your visibility in the room.
  *        - Call publishScreenAudio:{@link #ByteRTCRoom#publishScreenAudio:} (not supported on Linux) to start or stop sharing computer audio.
  *        - Call publishStreamVideo:{@link #ByteRTCRoom#publishStreamVideo:} to start or stop publishing the video stream captured by the camera.
  *        - Call publishStreamAudio:{@link #ByteRTCRoom#publishStreamAudio:} to start or stop publishing the audio stream captured by the microphone.
  *        - Call startForwardStreamToRooms:{@link #ByteRTCRoom#startForwardStreamToRooms:} to forward the published streams to the other rooms.
  *        - After you called this API, the other users in the room will receive rtcRoom:onUserPublishScreenVideo:uid:isPublish:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishScreenVideo:uid:isPublish:}. Those who successfully received your streams will receive rtcEngine:onFirstRemoteVideoFrameDecoded:withFrameInfo:{@link #ByteRTCRoomDelegate#rtcEngine:onFirstRemoteVideoFrameDecoded:withFrameInfo:} at the same time.
  *        - After calling this API, you'll receive rtcEngine:onScreenVideoFrameSendStateChanged:rtcUser:state:{@link #ByteRTCEngineDelegate#rtcEngine:onScreenVideoFrameSendStateChanged:rtcUser:state:}.
  *        - Refer to [Sharing Screen in PC](https:
  */
- (int)publishScreenVideo:(BOOL)publish;


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
  *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
  * @note
  *        - You need to call this API to publish screen even if you set it to Auto-publish when calling joinRoom:userInfo:roomConfig:{@link #ByteRTCRoom#joinRoom:userInfo:roomConfig:}.
  *        - An invisible user cannot publish media streams. Call setUserVisibility{@link #IRTCRoom#setUserVisibility} to change your visibility in the room.
  *        - Call publishScreenVideo:{@link #ByteRTCRoom#publishScreenVideo:} to start or stop sharing the local screen.
  *        - Call publishStreamVideo:{@link #ByteRTCRoom#publishStreamVideo:} to start or stop publishing the video stream captured by the camera.
  *        - Call publishStreamAudio:{@link #ByteRTCRoom#publishStreamAudio:} to start or stop publishing the audio stream captured by the microphone.
  *        - Call startForwardStreamToRooms:{@link #ByteRTCRoom#startForwardStreamToRooms:} to forward the published streams to the other rooms.
  *        - After you called this API, the other users in the room will receive rtcRoom:onUserPublishScreenAudio:uid:isPublish:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishScreenAudio:uid:isPublish:}. Those who successfully received your streams will receive rtcEngine:onFirstRemoteAudioFrame:{@link #ByteRTCEngineDelegate#rtcEngine:onFirstRemoteAudioFrame:} at the same time.
  *        - Refer to [Sharing Screen in PC](https:
  */
- (int)publishScreenAudio:(BOOL)publish;


/**
  * 
  * @type api
  * @valid since 3.60.
  * @brief Subscribes to specific remote media streams captured by the local camera.  Or update the subscribe options of the subscribed user.
  * @param userId The ID of the remote user who published the target video stream.
  * @param subscribe Whether to subscribe to the stream.
  * @return API call result: <br>
  *        - 0: Success.
  *        - <0: Failure. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for specific reasons.
  * @note
  *        - Calling this API to update the subscribe configuration when the user has subscribed the remote user either by calling this API or by auto-subscribe.
  *        - You must first get the remote stream information through rtcRoom:onUserPublishStreamVideo:uid:isPublish:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishStreamVideo:uid:isPublish:} before calling this API to subscribe to streams accordingly.
  *        - After calling this API, you will be informed of the calling result with onVideoSubscribeStateChanged{@link #ByteRTCRoomDelegate#onVideoSubscribeStateChanged}.
  *        - Once the local user subscribes to the stream of a remote user, the subscription to the remote user will sustain until the local user leaves the room or unsubscribe from it by calling subscribeStreamVideo{@link #IRTCRoom#subscribeStreamVideo}.
  *        - Any other exceptions will be included in onVideoSubscribeStateChanged{@link #ByteRTCRoomDelegate#onVideoSubscribeStateChanged}, see SubscribeStateChangeReason{@link #SubscribeStateChangeReason} for the reasons.
  */
- (int)subscribeStreamVideo:(NSString *_Nonnull)userId subscribe:(BOOL)subscribe;


/**
  * 
  * @type api
  * @valid since 3.60.
  * @brief Subscribes to specific remote media streams captured by the local microphone.  Or update the subscribe options of the subscribed user.
  * @param userId The ID of the remote user who published the target media stream.
  * @param subscribe Whether to subscribe to the audio stream.
  * @return API call result: <br>
  *        - 0: Success.
  *        - <0: Failure. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for specific reasons.
  * @note
  *        - Calling this API to update the subscribe configuration when the user has subscribed the remote user either by calling this API or by auto-subscribe.
  *        - You must first get the remote stream information through rtcRoom:onUserPublishStreamAudio:uid:isPublish:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishStreamAudio:uid:isPublish:} before calling this API to subscribe to streams accordingly.
  *        - After calling this API, you will be informed of the calling result with onAudioSubscribeStateChanged{@link #ByteRTCRoomDelegate#onAudioSubscribeStateChanged}.
  *        - Once the local user subscribes to the stream of a remote user, the subscription to the remote user will sustain until the local user leaves the room or unsubscribe from it by calling subscribeStreamAudio{@link #IRTCRoom#subscribeStreamAudio}.
  *        - Any other exceptions will be included in onAudioSubscribeStateChanged{@link #ByteRTCRoomDelegate#onAudioSubscribeStateChanged}, see ErrorCode{@link #ErrorCode} for the reasons.
  */
- (int)subscribeStreamAudio:(NSString *_Nonnull)userId subscribe:(BOOL)subscribe;


/**
  * 
  * @type api
  * @valid since 3.60.
  * @brief Subscribes to specific screen sharing media stream. Or update the subscribe options of the subscribed user.
  * @param userId The ID of the remote user who published the target screen video stream.
  * @param subscribe Whether to subscribe to the screen video stream.
  * @return API call result: <br>
  *        - 0: Success.
  *        - <0: Failure. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for specific reasons.
  * @note
  *        - Calling this API to update the subscribe configuration when the user has subscribed the remote user either by calling this API or by auto-subscribe.
  *        - You must first get the remote stream information through rtcRoom:onUserPublishScreenVideo:uid:isPublish:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishScreenVideo:uid:isPublish:} before calling this API to subscribe to streams accordingly.
  *        - After calling this API, you will be informed of the calling result with onScreenVideoSubscribeStateChanged{@link #ByteRTCRoomDelegate#onScreenVideoSubscribeStateChanged}.
  *        - Once the local user subscribes to the stream of a remote user, the subscription to the remote user will sustain until the local user leaves the room or unsubscribe from it by calling subscribeScreenVideo{@link #IRTCRoom#subscribeScreenVideo}.
  *        - Any other exceptions will be included in onScreenVideoSubscribeStateChanged{@link #ByteRTCRoomDelegate#onScreenVideoSubscribeStateChanged}, see SubscribeStateChangeReason{@link #SubscribeStateChangeReason} for the reasons.
  */
- (int)subscribeScreenVideo:(NSString *_Nonnull)userId subscribe:(BOOL)subscribe;


/**
  * 
  * @type api
  * @valid since 3.60.
  * @brief Subscribes to specific screen sharing media stream. Or update the subscribe options of the subscribed user.
  * @param userId The ID of the remote user who published the target screen audio stream.
  * @param subscribe Whether to subscribe to the screen audio stream.
  * @return API call result: <br>
  *        - 0: Success.
  *        - <0: Failure. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for specific reasons.
  * @note
  *        - Calling this API to update the subscribe configuration when the user has subscribed the remote user either by calling this API or by auto-subscribe.
  *        - You must first get the remote stream information through rtcRoom:onUserPublishScreenAudio:uid:isPublish:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishScreenAudio:uid:isPublish:} before calling this API to subscribe to streams accordingly.
  *        - After calling this API, you will be informed of the calling result with onScreenAudioSubscribeStateChanged{@link #ByteRTCRoomDelegate#onScreenAudioSubscribeStateChanged}.
  *        - Once the local user subscribes to the stream of a remote user, the subscription to the remote user will sustain until the local user leaves the room or unsubscribe from it by calling subscribeScreenAudio{@link #IRTCRoom#subscribeScreenAudio}.
  *        - Any other exceptions will be included in onScreenAudioSubscribeStateChanged{@link #ByteRTCRoomDelegate#onScreenAudioSubscribeStateChanged}, see SubscribeStateChangeReason{@link #SubscribeStateChangeReason} for the reasons.
  */
- (int)subscribeScreenAudio:(NSString *_Nonnull)userId subscribe:(BOOL)subscribe;



/**
 * 
 * @type api
 * @region Room Management
 * @brief Subscribes to all remote media streams captured by camera/microphone. Or update the subscribe options of all subscribed user.
 * @param mediaStreamType Media stream type, used for specifying whether to subscribe to the audio stream or the video stream. See ByteRTCMediaStreamType{@link #ByteRTCMediaStreamType}.
 * @return API call result: <br>
 *        - 0: Success
 *        - !0: Failure
 * @note
 *        - If the subscription options conflict with the previous ones, they are subject to the configurations in the last call.
 *        - In the Audio selection, if the number of media streams exceeds the limit, we recommend you call subscribeStream:mediaStreamType:{@link #ByteRTCRoom#subscribeStream:mediaStreamType:} to subscribe each target media stream other than calling this API.
 *        - After calling this API, you will be informed of the calling result with rtcRoom:onStreamSubscribed:userId:subscribeConfig:{@link #ByteRTCRoomDelegate#rtcRoom:onStreamSubscribed:userId:subscribeConfig:}.
 *        - Once the local user subscribes to the stream of a remote user, the subscription to the remote user will sustain until the local user leaves the room or unsubscribe from it by calling unsubscribeStream:mediaStreamType:{@link #ByteRTCRoom#unsubscribeStream:mediaStreamType:} or unsubscribeAllStreamsWithMediaStreamType:{@link #ByteRTCRoom#unsubscribeAllStreamsWithMediaStreamType:}.
 *        - Any other exceptions will be included in rtcRoom:onRoomStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomStateChanged:withUid:state:extraInfo:}, see ByteRTCErrorCode{@link #ByteRTCErrorCode} for the reasons.
 */
- (int)subscribeAllStreamsWithMediaStreamType:(ByteRTCMediaStreamType)mediaStreamType;


/**
 * 
 * @type api
 * @region Room Management
 * @brief Unsubscribes from all remote media streams captured by camera/microphone. <br>
 *        You can call this API to unsubscribe from streams that are subscribed to either automatically or manually.
 * @param mediaStreamType Media stream type, used for specifying whether to unsubscribe from the audio stream or the video stream. See ByteRTCMediaStreamType{@link #ByteRTCMediaStreamType}.
 * @return API call result: <br>
 *        - 0: Success
 *        - !0: Failure
 * @note
 *        After calling this API, you will be informed of the calling result with onVideoSubscribeStateChanged{@link #ByteRTCRoomDelegate#onVideoSubscribeStateChanged}, onAudioSubscribeStateChanged{@link #ByteRTCRoomDelegate#onAudioSubscribeStateChanged}, onScreenVideoSubscribeStateChanged{@link #ByteRTCRoomDelegate#onScreenVideoSubscribeStateChanged}, and/or onScreenAudioSubscribeStateChanged{@link #ByteRTCRoomDelegate#onScreenAudioSubscribeStateChanged}. You can also find exceptions cause from the callbacks above.
 */
- (int)unsubscribeAllStreamsWithMediaStreamType:(ByteRTCMediaStreamType)mediaStreamType;

/**
 * 
 * @type api
 * @region Multi-room
 * @brief Pauses receiving remote media streams.
 * @param mediaType Media stream type subscribed to. Refer to ByteRTCPauseResumControlMediaType{@link #ByteRTCPauseResumControlMediaType} for more details.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *         - Calling this API does not change the capture and transmission state of the remote stream.
 *         - Calling this API does not cancel the subscription or change any subscription configuration.
 *         - To resume receiving streams,  call resumeAllSubscribedStream:{@link #ByteRTCRoom#resumeAllSubscribedStream:}.
 *         - In a multi-room scenario, this API only pauses the reception of streams published in the current room.
 */
- (int)pauseAllSubscribedStream:(ByteRTCPauseResumControlMediaType) mediaType;


/**
 * 
 * @type api
 * @region Multi-room
 * @brief Resumes receiving remote media streams.
 * @param mediaType Media stream type subscribed to. Refer to ByteRTCPauseResumControlMediaType{@link #ByteRTCPauseResumControlMediaType} for more details.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *         - Calling this API does not change the capture and transmission state of the remote stream.
 *         - Calling this API does not change any subscription configuration.
 */
- (int)resumeAllSubscribedStream:(ByteRTCPauseResumControlMediaType) mediaType;

 
 /**
  * 
  * @type api
  * @region Multi-room
  * @brief Sends a text message (P2P) to the specified user in the room.
  * @param userId ID of the user receiving the message
  * @param message Message content of which the length must not exceed 64 KB.
  * @param config Reliability of the message.
  * @return The number of the message sent this time is incremented from 1.
  * @note
  *       - Before sending an in-room text message, you must call joinRoom:userInfo:roomConfig:{@link #ByteRTCRoom#joinRoom:userInfo:roomConfig:} to join the room.
  *       - After calling this API, you will receive an rtcRoom:onUserMessageSendResult:error:{@link #ByteRTCRoomDelegate#rtcRoom:onUserMessageSendResult:error:} callback to notify the sender of the success or failure of the message.
  *       - If the text message is sent successfully, the user specified by uid will receive an rtcRoom:onUserMessageReceived:message:{@link #ByteRTCRoomDelegate#rtcRoom:onUserMessageReceived:message:} callback.
  */
- (NSInteger)sendUserMessage:(NSString *_Nonnull)userId message:(NSString *_Nonnull)message config:(ByteRTCMessageConfig)config;

 
 /**
  * 
  * @type The api
  * @region multiroom
  * @brief Sends a binary message (P2P) to the specified user in the room.
  * @param uid <br>
  *        Message Receiving user's ID
  * @param message <br>
  *        Binary message content sent <br>
  *        Message does not exceed 46KB.
  * @param config See ByteRTCMessageConfig{@link #ByteRTCMessageConfig}.
  * @return The number of the message sent this time is incremented from 1.
  * @note
  *       - Before sending the in-room binary message, you must call joinRoom:userInfo:roomConfig:{@link #ByteRTCRoom#joinRoom:userInfo:roomConfig:} to join the room.
  *       - After calling this function, you will receive an rtcRoom:onUserMessageSendResult:error:{@link #ByteRTCRoomDelegate#rtcRoom:onUserMessageSendResult:error:} callback to notify the sender of the success or failure of the message;
  *       - If the binary message is sent successfully, the user specified by uid will receive rtcRoom:onUserBinaryMessageReceived:message:{@link #ByteRTCRoomDelegate#rtcRoom:onUserBinaryMessageReceived:message:} callback.
  */
- (NSInteger)sendUserBinaryMessage:(NSString * _Nonnull)uid message:(NSData * _Nonnull)message config:(ByteRTCMessageConfig)config;

 
 /**
  * 
  * @type api
  * @region Multi-room
  * @brief Sends text messages to all other users in the room.
  * @param message <br>
  *        The content of the text message sent. <br>
  *         Message does not exceed 64 KB.
  * @return The number of the message sent this time is incremented from 1.
  * @note
  *       - Before sending an in-room text message, you must call joinRoom:userInfo:roomConfig:{@link #ByteRTCRoom#joinRoom:userInfo:roomConfig:} to join the room.
  *       - After calling this function, you will receive an rtcRoom:onRoomMessageSendResult:error:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomMessageSendResult:error:} callback to notify the sender of the success or failure of the message;
  *       - If the text message is sent successfully, all remote users in the room will receive rtcRoom:onRoomMessageReceived:message:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomMessageReceived:message:} callback.
  */
- (NSInteger)sendRoomMessage:(NSString *_Nonnull)message NS_SWIFT_NAME(sendRoomMessage(_:));

 
 /**
  * 
  * @type api
  * @region multiroom
  * @brief Sends binary messages to all other users in the room.
  * @param message <br>
  *        The binary broadcast message sent by the user <br>
  *        The message does not exceed 46KB.
  * @return The number of the message sent this time is incremented from 1.
  * @note
  *       - Before broadcasting binary messages in the room, you must call joinRoom:userInfo:roomConfig:{@link #ByteRTCRoom#joinRoom:userInfo:roomConfig:} to join the room.
  *       - After calling this function, you will receive an rtcRoom:onRoomMessageSendResult:error:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomMessageSendResult:error:} callback to notify the sender of the success or failure of the message;
  *       - If the binary message is successfully sent, all users in the room will receive rtcRoom:onRoomBinaryMessageReceived:message:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomBinaryMessageReceived:message:} callback.
  */
- (NSInteger)sendRoomBinaryMessage:(NSData *  _Nonnull)message NS_SWIFT_NAME(sendRoomBinaryMessage(_:));

#pragma mark ForwardStream
    
    /**
     * 
     * @type api
     * @region Multi-room
     * @brief Starts relaying media stream across rooms. <br>
     *        After calling joinRoom:userInfo:roomConfig:{@link #ByteRTCRoom#joinRoom:userInfo:roomConfig:}, call this API to achieve the relaying of media streams to multiple rooms, which applies to cross-room concatenation and other scenarios.
     * @param configurations Information of the rooms where you want to relay the media stream to. Refer to ByteRTCForwardStreamConfiguration{@link #ByteRTCForwardStreamConfiguration} for more inforamtion.
     * @return
     *        0: Success <br>
     *        <0: Failure
     * @note
     *        - Calling this method will trigger rtcRoom:onForwardStreamStateChanged:{@link #ByteRTCRoomDelegate#rtcRoom:onForwardStreamStateChanged:}.
     *        - After calling this method, listen the events from each room during the relaying by registering rtcRoom:onForwardStreamEvent:{@link #ByteRTCRoomDelegate#rtcRoom:onForwardStreamEvent:}.
     *        - Once the relaying begins, the other users in the room will receive callback of onUserJoined{@link #ByteRTCRoomDelegate#onUserJoined}, rtcRoom:onUserPublishStreamVideo:uid:isPublish:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishStreamVideo:uid:isPublish:}, rtcRoom:onUserPublishStreamAudio:uid:isPublish:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishStreamAudio:uid:isPublish:}, rtcRoom:onUserPublishScreenVideo:uid:isPublish:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishScreenVideo:uid:isPublish:}, and/or rtcRoom:onUserPublishScreenAudio:uid:isPublish:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishScreenAudio:uid:isPublish:}.
     *        - Call updateForwardStreamToRooms:{@link #ByteRTCRoom#updateForwardStreamToRooms:} to add or remove the designated room(s) after calling this method.
     *        - Call stopForwardStreamToRooms{@link #ByteRTCRoom#stopForwardStreamToRooms} to stop relaying to all rooms after calling this method.
     *        - Call pauseForwardStreamToAllRooms{@link #ByteRTCRoom#pauseForwardStreamToAllRooms} to pause relaying to all rooms after calling this method.
     */
- (int)startForwardStreamToRooms:(NSArray <ByteRTCForwardStreamConfiguration *> * _Nullable)configurations NS_SWIFT_NAME(startForwardStreamToRooms(_:));
    
    /**
     * 
     * @type api
     * @region Multi-room
     * @brief Updates information of the rooms where you want to relay the media stream to after calling startForwardStreamToRooms:{@link #ByteRTCRoom#startForwardStreamToRooms:}. <br>
     *        Adding and removing rooms by calling this method will trigger rtcRoom:onForwardStreamStateChanged:{@link #ByteRTCRoomDelegate#rtcRoom:onForwardStreamStateChanged:} on the local.
     * @param configurations Information of the rooms where you want to relay the media stream to. Refer to ByteRTCForwardStreamConfiguration{@link #ByteRTCForwardStreamConfiguration} for more information.
     * @return
     *         - 0: Success
     *         - <0: Failure
     * @note
     *        Users in the room which is added or removed from the target list by calling this method will receive onUserJoined{@link #ByteRTCRoomDelegate#onUserJoined}, rtcRoom:onUserPublishStreamVideo:uid:isPublish:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishStreamVideo:uid:isPublish:}, rtcRoom:onUserPublishStreamAudio:uid:isPublish:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishStreamAudio:uid:isPublish:}, rtcRoom:onUserPublishScreenVideo:uid:isPublish:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishScreenVideo:uid:isPublish:}, and/or rtcRoom:onUserPublishScreenAudio:uid:isPublish:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishScreenAudio:uid:isPublish:}.
     */
- (int)updateForwardStreamToRooms:(NSArray <ByteRTCForwardStreamConfiguration *> * _Nullable)configurations NS_SWIFT_NAME(updateForwardStreamToRooms(_:));

/**
 * 
 * @type api
 * @region Multi-room
 * @brief Stops relaying media stream to all rooms after calling startForwardStreamToRooms:{@link #ByteRTCRoom#startForwardStreamToRooms:}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *        - Calling this method will trigger rtcRoom:onForwardStreamStateChanged:{@link #ByteRTCRoomDelegate#rtcRoom:onForwardStreamStateChanged:}.
 *        - The other users in the room will receive callback of rtcRoom:onUserJoined:elapsed:{@link #ByteRTCRoomDelegate#rtcRoom:onUserJoined:elapsed:} and rtcRoom:onUserJoined:elapsed:{@link #ByteRTCRoomDelegate#rtcRoom:onUserJoined:elapsed:} when you stop relaying.
 *        - To stop relaying media stream to specific rooms, call updateForwardStreamToRooms:{@link #ByteRTCRoom#updateForwardStreamToRooms:} instead.
 *        - To pause the relaying for a short time, call pauseForwardStreamToAllRooms{@link #ByteRTCRoom#pauseForwardStreamToAllRooms}, and then call resumeForwardStreamToAllRooms{@link #ByteRTCRoom#resumeForwardStreamToAllRooms} to recsume after that.
 */
- (int)stopForwardStreamToRooms;

  /**
 * 
 * @type api
 * @region Multi-room
 * @brief Pauses relaying media stream to all rooms after calling startForwardStreamToRooms:{@link #ByteRTCRoom#startForwardStreamToRooms:}. <br>
 *        After that, call resumeForwardStreamToAllRooms{@link #ByteRTCRoom#resumeForwardStreamToAllRooms} to resume.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note The other users in the room will receive callback of rtcRoom:onUserPublishStreamVideo:uid:isPublish:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishStreamVideo:uid:isPublish:}, rtcRoom:onUserPublishStreamAudio:uid:isPublish:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishStreamAudio:uid:isPublish:}, rtcRoom:onUserPublishScreenVideo:uid:isPublish:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishScreenVideo:uid:isPublish:}, and/or rtcRoom:onUserPublishScreenAudio:uid:isPublish:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishScreenAudio:uid:isPublish:} when you pause relaying.
 */
- (int)pauseForwardStreamToAllRooms;

/**
 * 
 * @type api
 * @region Multi-room
 * @brief Resumes relaying media streams paused by calling pauseForwardStreamToAllRooms{@link #ByteRTCRoom#pauseForwardStreamToAllRooms} to all rooms.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note The other users in the room will receive callback of rtcRoom:onUserJoined:elapsed:{@link #ByteRTCRoomDelegate#rtcRoom:onUserJoined:elapsed:} and rtcRoom:onUserJoined:elapsed:{@link #ByteRTCRoomDelegate#rtcRoom:onUserJoined:elapsed:} when you resume relaying.
 */
- (int)resumeForwardStreamToAllRooms;



/**
 * 
 * @type api
 * @region Range Audio
 * @brief Gets range audio instance.
 * @return API call result: <br>
 *        - ByteRTCRangeAudio: Success. You will get a ByteRTCRangeAudio{@link #ByteRTCRangeAudio} returned from the SDK.
 *        - NULL: Failure. The current SDK does not offer range audio function.
 * @note The first time this API is called must be between creating a room and actually entering the room.  Refer to [Range Voice](https:
 */
- (ByteRTCRangeAudio *_Nullable)getRangeAudio;


/**
 * 
 * @type api
 * @region Spatial Audio
 * @brief Gets spatial audio instance.
 * @return API call result: <br>
 *        - ISpatialAudio: Success. You will get a ByteRTCSpatialAudio{@link #ByteRTCSpatialAudio} returned from the SDK.
 *        - NULL: Failure. The current SDK does not offer spatial audio function.
 * @note
 *        - The first time this API is called must be between you create a room and you actually enter the room.  Refer to [Spatial Audio](https:
 *        - Only using real dual-channel playback device can users actually enjoy spatial audio effect.
 *        - Low-end device may have audio stalling issues due to its poor performance, so it is not recommended to enable spatial audio function on such kind of devices.
 *        - SDK currently supports up to 30 users publishing audio with spatial audio enabled at the same time in the same room.
 */
- (ByteRTCSpatialAudio *_Nullable)getSpatialAudio;

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
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note Suppose a remote user A is always within the range of the target user whose playback volume will be adjusted, <br>
 *        - If you use both this method and setRemoteAudioPlaybackVolume:remoteUid:playVolume:{@link #ByteRTCVideo#setRemoteAudioPlaybackVolume:remoteUid:playVolume:}, the volume that the local user hears from user A is the volume set by the method called later.
 *        - If you use both this method and setPlaybackVolume:{@link #ByteRTCVideo#setPlaybackVolume:}, the volume that the local user hears from user A is the overlay of both settings.
 */
- (int)setRemoteRoomAudioPlaybackVolume:(NSInteger)volume;


/**
 * 
 * @hidden for internal use only.
 * @type api
 * @region Cloud Rendering
 * @brief Enable cloud rendering according to the incoming layout information.
 * @param rendingInfo  Rendering function related, parameters.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 */
- (int)startCloudRendering:(NSString *_Nonnull)rendingInfo;


/**
 * 
 * @hidden for internal use only.
 * @type api
 * @region Cloud Render
 * @brief Update the cloud rendering with the layout information passed in.
 * @param rendingInfo  Rendering function related, parameters.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 */
- (int)updateCloudRendering:(NSString *_Nonnull)rendingInfo;


/**
 * 
 * @hidden for internal use only.
 * @type api
 * @region  cloud rendering
 * @brief  Stop cloud rendering.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 */
- (int)stopCloudRendering;


/**
 * 
 * @valid since 3.52.
 * @type api
 * @region Room Management
 * @brief Set the priority of the local audio stream to be published.
 * @param audioSelectionPriority The priority of the local audio stream which defaults to be subscribable only up to the result of the Audio Selection. Refer to ByteRTCAudioSelectionPriority{@link #ByteRTCAudioSelectionPriority}.
 * @note
 * You must enable Audio Selection in the RTC console before using this API. You can call this API whether the user has joined a room. Refer to [Audio Selection](https:
 * The setting is independent in each room that the user joins.
 */
- (int)setAudioSelectionConfig:(ByteRTCAudioSelectionPriority)audioSelectionPriority;


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
 *        - <0: Failure. See ByteRTCSetRoomExtraInfoResult{@link #ByteRTCSetRoomExtraInfoResult} for the reasons.
 * @note
 *        - Call joinRoom:userInfo:roomConfig:{@link #ByteRTCRoom#joinRoom:userInfo:roomConfig:} first before you call this API to set extra information.
 *        - After calling this API, you will receive rtcRoom:onSetRoomExtraInfoResult:error:{@link #ByteRTCRoomDelegate#rtcRoom:onSetRoomExtraInfoResult:error:} callback informing you the result of the setting.
 *        - After the extra information is successfully set, other users in the same room will receive the information through rtcRoom:onRoomExtraInfoUpdate:value:lastUpdateUserId:lastUpdateTimeMs:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomExtraInfoUpdate:value:lastUpdateUserId:lastUpdateTimeMs:} callback.
 *        - Users who join the room later will be notified of all extra information in the room set prior to entering.
 * @list Room Management
 */
- (NSInteger)setRoomExtraInfo:(NSString *_Nonnull)key value:(NSString *_Nonnull)value;



/**
 * 
 * @hidden currently not available
 * @type api
 * @region Subtitle translation service
 * @brief Recognizes or translates the speech of all speakers in the room and converts the results into captions. <br>
 *        When calling this method, you can choose the subtitle mode in the ByteRTCSubtitleMode{@link #ByteRTCSubtitleMode}. If you choose the recognition mode, you will receive the rtcRoom:onSubtitleMessageReceived:{@link #ByteRTCRoomDelegate#rtcRoom:onSubtitleMessageReceived:} callback which contains the transcribed text. <br>
 *        If you choose the translation mode, you will receive two rtcRoom:onSubtitleMessageReceived:{@link #ByteRTCRoomDelegate#rtcRoom:onSubtitleMessageReceived:} callbacks simultaneously, one contains the transcribed text and the other contains the translated text. <br>
 *        After calling this method, you will receive the rtcRoom:onSubtitleStateChanged:errorCode:errorMessage:{@link #ByteRTCRoomDelegate#rtcRoom:onSubtitleStateChanged:errorCode:errorMessage:} to inform you of whether subtitles are on.
 * @param subtitleConfig Subtitle configurations. Refer to ByteRTCSubtitleConfig{@link #ByteRTCSubtitleConfig} for details.
 * @return
 *        -  0: Success.
 *        - !0: Failure.
 * @note
 *        - Call this method after joining the room.
 *        - You can set your source language to Chinese by calling `joinRoom` and importing a json formatted string `"source_language": "zh"` through the parameter of extraInfo, to English by importing `"source_language": "en"` , and to Japanese by importing `"source_language": "ja"` . If you don't set the source language, SDK will set the language of your system as the source language. If the language of your system is not Chinese, English or Japanese, SDK will set Chinese as the source language.
 */
- (int)startSubtitle:(ByteRTCSubtitleConfig *_Nonnull)subtitleConfig;


/**
 * 
 * @hidden currently not available
 * @type api
 * @region Subtitle translation service
 * @brief Turns off subtitles. <br>
 *        After calling this method, you will receive the rtcRoom:onSubtitleStateChanged:errorCode:errorMessage:{@link #ByteRTCRoomDelegate#rtcRoom:onSubtitleStateChanged:errorCode:errorMessage:} to inform you of whether subtitles are off.
 * @return
 *        -  0: Success.
 *        - !0: Failure.
 */
- (int)stopSubtitle;


- (NSString * _Nonnull)getCallId;
@end