/*
 * Copyright (c) 2022 The BytePlusRTC project authors. All Rights Reserved.
 * @brief Objective-C BytePlusRTC Common Defines
*/

#import "ByteRTCRtsDefines.h"

/**
 * 
 * @type keytype
 * @brief API call result.
 */
typedef NS_ENUM(NSInteger, ByteRTCReturnStatus) {
    
    /**
     * 
     * @brief Success.
     */
    ByteRTCReturnStatusSuccess = 0,
    
    /**
     * 
     * @brief Failure.
     */
    ByteRTCReturnStatusFailure = -1,
    
    /**
     * 
     * @brief Invalid parameter.
     */
    ByteRTCReturnStatusParameterErr = -2,
    
    /**
     * 
     * @brief API status error.
     */
    ByteRTCReturnStatusWrongState = -3,
    
    /**
     * 
     * @brief Failure. The user is already in the room.
     */
    ByteRTCReturnStatusHasInRoom = -4,
    
    /**
     * 
     * @brief Failure. The user has already logged in.
     */
    ByteRTCReturnStatusHasInLogin = -5,
    
    /**
     * 
     * @brief Failure. The user is already in a pre-call test.
     */
    ByteRTCReturnStatusHasInEchoTest = -6,
    
    /**
     * 
     * @brief Failure. Neither video nor audio is captured.
     */
    ByteRTCReturnStatusNeitherVideoNorAudio = -7,
    
    /**
     * 
     * @brief Failure. The roomId is already in use.
     */
    ByteRTCReturnStatusRoomIdInUse = -8,
    
    /**
     * 
     * @brief Failure. Screen stream is not supported.
     */
    ByteRTCReturnStatusScreenNotSupport = -9,
    
    /**
     * 
     * @brief Failure. Not supported.
     */
    ByteRTCReturnStatusNotSupport = -10,
    
    /**
     * 
     * @brief Failure. resource overflow.
     */
    ByteRTCReturnStatusResourceOverflow = -11,
    
    /**
     * 
     * @brief Failure. No audio frame.
     */
    ByteRTCReturnStatusAudioNoFrame = -101,
    
    /**
     * 
     * @brief Failure. No implemented.
     */
    ByteRTCReturnStatusAudioNotImplemented = -102,
    
    /**
     * 
     * @brief Failure. The audio capture device does not have microphone use permission, and the initialization of the device failed.
     */
    ByteRTCReturnStatusAudioNoPermission = -103,
    
    /**
     * 
     * @brief Failure. The device does not exist. This value is returned if there is currently no device or if the device has been removed.
     */
    ByteRTCReturnStatusAudioDeviceNotExists = -104,
    
    /**
     * 
     * @brief Failure. The device audio format is not supported.
     */
    ByteRTCReturnStatusAudioDeviceFormatNotSupport = -105,
    
    /**
     * 
     * @brief Failure. No device in system.
     */
    ByteRTCReturnStatusAudioDeviceNoDevice = -106,
    
    /**
     * 
     * @brief Failure. The current device is not available and need to be replaced.
     */
    ByteRTCReturnStatusAudioDeviceCannotUse = -107,
    
    /**
     * 
     * @brief Device initialization failed due to a system error.
     */
    ByteRTCReturnStatusAudioDeviceInitFailed = -108,
    
    /**
     * 
     * @brief Device start-up failed due to a system error.
     */
    ByteRTCReturnStatusAudioDeviceStartFailed = -109,
    
    /**
     * 
     * @hidden(iOS)
     * @brief Capture failed. The specified audio process does not exist.
     */
    ByteRTCReturnStatusAudioDeviceProcessNotExist = -110,
    
    /**
     * 
     * @brief Failure. The native layer is not initialized and the engine is invalid.
     */
    ByteRTCReturnStatusNativeInValid = -201,
};


/**
 * 
 * @type keytype
 * @brief The reason for the removal of the remote flow in the room.
 */
typedef NS_ENUM(NSInteger, ByteRTCStreamRemoveReason) {
    
    /**
     * 
     * @brief The remote user stops publishing the flow.
     */
    ByteRTCStreamRemoveReasonUnpublish = 0,
    
    /**
     * 
     * @brief The remote user failed to publish the flow.
     */
    ByteRTCStreamRemoveReasonPublishFailed = 1,
    
    /**
     * 
     * @brief Media server failed to receive media data from the client for 10 seconds.
     */
    ByteRTCStreamRemoveReasonKeepLiveFailed = 2,
    
    /**
     * 
     * @brief The remote user is disconnected.
     */
    ByteRTCStreamRemoveReasonClientDisconnected = 3,
    
    /**
     * 
     * @brief The remote user republishes the flow.
     */
    ByteRTCStreamRemoveReasonRepublish = 4,
    
    /**
     * 
     * @brief Other reasons.
     */
    ByteRTCStreamRemoveReasonOther = 5,
    
    /**
     * 
     * @brief The remote user's publishing privilege of the Token is expired.
     */
    ByteRTCStreamRemoveReasonPublishPrivilegeExpired = 6,
};


/**
 * 
 * @type keytype
 * @brief  Room profile <br>
 *        Choose an appropriate room-profile option to meet the requirement of the scenario for media encoding algorithm, video profiles, and network configurations. <br>
 *        Call `setAudioProfile` to apply another audio quality option.
 */
typedef NS_ENUM(NSInteger, ByteRTCRoomProfile) {
    
    /**
     * 
     * @brief General mode by default <br>
     *        It equals to `ByteRTCRoomProfileMeeting = 16`. <br>
     *        Contact us to alter the default settings.
     */
    ByteRTCRoomProfileCommunication = 0,
    
    /**
     * 
     * @deprecated since 3.45 and will be deleted in 3.51, use ByteRTCRoomProfileInteractivePodcast instead.
     * @hidden
     * @brief Live broadcasting mode. <br>
     *        Use this mode for high quality of the media. <br>
     *        In this mode, audio plays in media mode for Bluetooth earphones.
     */
    ByteRTCRoomProfileLiveBroadcasting = 1,
    
    /**
     * 
     * @brief Game voice mode. Low consumption of computing resources and network data <br>
     *        Additional performance optimizations have been made for low-end devices: <br>
     *             - Encodes frame length 40/60 for some low-end models.
     *             - Disables software 3A audio processing for some low-end models.
     *        Enhance iOS Compatibility with other screen recordings to avoid audio recordings being interrupted by RTC.
     */
    ByteRTCRoomProfileGame = 2,
    
    /**
     * 
     * @brief Cloud game mode. <br>
     *        Use this mode for game App requiring low latency. <br>
     *        During poor network connection, communication experiences get worse with this mode.
     */
    ByteRTCRoomProfileCloudGame = 3,
    
    /**
     * 
     * @brief Cloud render mode featuring extra-low latency. <br>
     *        Choose this mode if it is not a game App yet requires low latency. <br>
     *        In this mode, latency will significantly decrease at the cost of lower audio quality as well as the bad performance with weak network signal.
     */
    ByteRTCRoomProfileLowLatency = 4,
    
    /**
     * 
     * @brief For 1 vs 1 video and audio calls
     */
    ByteRTCRoomProfileChat = 5,
    
    /**
     * 
     * @brief For video and audio chat rooms of 3 or more people
     */
    ByteRTCRoomProfileChatRoom = 6,
    
    /**
     * 
     * @brief For scenarios such as "Watch together." and "Listen together." Multiple clients are capable of playing the same videos and audios synchronically. <br>
     *        In these scenarios, RTC does not involve the transportation of the sharing media but only synchronizes video/music playback across multiple clients via signaling.
     */
    ByteRTCRoomProfileLwTogether = 7,
    
    /**
     * 
     * @brief For the game apps demanding high-resolution audio. In this mode, RTC plays audio using the media mode only.
     */
    ByteRTCRoomProfileGameHD = 8,
    
    /**
     * 
     * @brief For the events of co-hosting in the live-streaming <br>
     *        During a livestreaming using a CDN network, the host can invite another host to join the co-hosting event using RTC.
     */
    ByteRTCRoomProfileCoHost = 9,
    
    /**
     * 
     * @brief For interactive podcasts that the host can have video and audio interactions with the audience. The voice mode is set to communication mode to avoid volume spiking and dipping acutely.
     */
    ByteRTCRoomProfileInteractivePodcast = 10,
    
    /**
     * 
     * @brief For the online karaoke with high-quality audio and low latency <br>
     *        In these scenarios, RTC transports the accompaniment and mixed audio, such as solo and non-realtime chorus.
     */
    ByteRTCRoomProfileKTV = 11,
    
    /**
     * 
     * @brief For the online-chorusing scenarios requiring high-quality audio and low latency. Contact our technical specialists before you apply it to your App.
     */
    ByteRTCRoomProfileChorus = 12,
    
    /**
     * 
     * @brief For VR chat with support for 192 KHz audio sample rate and feature of 360 Reality AudioAudio
     */
    ByteRTCRoomProfileVRChat = 13,
    
    /**
     * 
     * @brief For scenarios of streaming live videos to only one client on the LAN. It can be applied to devices on the Internet or LAN.
     */
    ByteRTCRoomProfileGameStreaming = 14,
    
    /**
     * 
     * @brief For scenarios of streaming live videos to multiple clients within the LAN with the support of 60fps @8K video stream with the bitrate of 100 Mbps <br>
     * A private media server is expected to be ready on the LAN.
     */
    ByteRTCRoomProfileLanLiveStreaming = 15,
    
    /**
     * 
     * @brief For meeting Apps installed on personal devices
     */
    ByteRTCRoomProfileMeeting = 16,
    
    /**
     * 
     * @brief For meeting Apps installed on terminals of meeting rooms, such as Rooms.
     */
    ByteRTCRoomProfileMeetingRoom = 17,
    
    /**
     * 
     * @brief For the online classrooms and lectures that over 10 participants in the room are allowed to join the video chat.
     */
    ByteRTCRoomProfileClassroom = 18,
};


/**
 * 
 * @hidden
 * @deprecated since 3.45 and will be delted in 3.51.
 * @type keytype
 * @brief User persona.
 */
typedef NS_ENUM(NSInteger, ByteRTCUserRoleType) {
    
    /**
     * 
     * @brief Live streaming host role. This role user can publish and subscribe to audio & video streams in the room, and other users in the room can perceive the presence of this user.
     */
    ByteRTCUserRoleTypeBroadcaster = 1,
    
    /**
     * 
     * @brief Stealth user persona. This role user can only subscribe to audio & video streams in the room, and other users in the room cannot perceive the presence of this user.
     */
    ByteRTCUserRoleTypeSilentAudience = 2,
};


/**
 * 
 * @type keytype
 * @brief User visibility state change error.
 */
 typedef NS_ENUM(NSInteger, ByteRTCUserVisibilityChangeError) {
    
    /**
     * 
     * @brief Success.
     */
    ByteRTCUserVisibilityChangeErrorOk = 0,
    
    /**
     * 
     * @brief Unknown error.
     */
    ByteRTCUserVisibilityChangeErrorUnknown = 1,
    
    /**
     * 
     * @brief Visible users in the room have reached the upper limit.
     */
    ByteRTCUserVisibilityChangeErrorTooManyVisibleUser = 2,
};


/**
 * 
 * @hidden currently not available
 * @type keytype
 * @brief Message source
 */
typedef NS_ENUM(NSInteger, ByteRTCDataMessageSourceType) {
    
    /**
     * 
     * @brief Customized messages inserted by calling API in the server or SDK.
     */
    ByteRTCDataMessageSourceTypeDefault = 0,
    
    /**
     * 
     * @brief System notification such as volume indication.
     */
    ByteRTCDataMessageSourceTypeSystem = 1,
};


/**
 * 
 * @type keytype
 * @brief SEI sending mode.
 */
typedef NS_ENUM(NSInteger,  ByteRTCSEICountPerFrame) {
    
    /**
     * 
     * @brief Single-SEI mode. When you send multiple SEI messages in 1 frame, they will be sent frame by frame in a queue.
     */
    ByteRTCSEICountPerFrameSingle = 0,
    
    /**
     * 
     * @brief Multi-SEI mode. When you send multiple SEI messages in 1 frame, they will be sent together in the next frame.
     */
    ByteRTCSEICountPerFrameMulti = 1,
};


/**
 * 
 * @type errorcode
 * @brief  Callback error code. When an unrecoverable error is encountered internally in the <br>
 *        SDK, the user is notified via an `rtcEngine:onError:` callback.
 */
typedef NS_ENUM(NSInteger, ByteRTCErrorCode) {
    
    /**
     * 
     * @brief Token is invalid. Receive message from rtcRoom:onRoomStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomStateChanged:withUid:state:extraInfo:}. <br>
     *        The Token used when calling joinRoom:userInfo:roomConfig:{@link #ByteRTCRoom#joinRoom:userInfo:roomConfig:} is invalid or expired. The user is required to retrieve the token and call the updateToken:{@link #ByteRTCRoom#updateToken:} to update the token.
     */
    ByteRTCErrorCodeInvalidToken               = -1000,
    
    /**
     * 
     * @brief Join room error. Receive message from rtcRoom:onRoomStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomStateChanged:withUid:state:extraInfo:}. <br>
     *        An unknown error occurred when joining the room, which caused the room to fail to join. Users are required to rejoin the room.
     */
    ByteRTCErrorCodeJoinRoom             = -1001,
    
    /**
     * 
     * @brief No permission to publish audio & video streams. Receive message from rtcRoom:onStreamStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onStreamStateChanged:withUid:state:extraInfo:}. <br>
     *        The user failed to publish the audio & video stream in the room. The reason for the failure is that the user does not have permission to publish the stream.
     */
    ByteRTCErrorCodeNoPublishPermission       = -1002,
    
    /**
     * 
     * @brief No subscription permissions for audio & video streams. Receive message from rtcRoom:onStreamStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onStreamStateChanged:withUid:state:extraInfo:}. <br>
     *        The user failed to subscribe to the audio & video stream in the room where the user is located. The reason for the failure is that the user does not have permission to subscribe to the stream.
     */
    ByteRTCErrorCodeNoSubscribePermission     = -1003,
    
    /**
     * 
     * @brief The user has been removed from the room because another with the same user ID joins the room. Receive message from rtcRoom:onRoomStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomStateChanged:withUid:state:extraInfo:}.
     */
    ByteRTCErrorCodeDuplicateLogin             = -1004,

    
    /**
     * 
     * @brief The user has been removed from the room by the administrator via a OpenAPI call. Receive message from rtcRoom:onRoomStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomStateChanged:withUid:state:extraInfo:}.
     */
    ByteRTCErrorCodeKickedOut = -1006,

    
    /**
     * 
     * @brief When calling `createRtcRoom:`, if the roomId is illegal, it will return null and throw the error. Receive message from rtcEngine:onCreateRoomStateChanged:errorCode:{@link #ByteRTCVideoDelegate#rtcEngine:onCreateRoomStateChanged:errorCode:}.
     */
    ByteRTCErrorCodeRoomIdIllegal = -1007,
    
    /**
     * 
     * @brief Token expired. This error code is returned when the user's token expires in the room. Receive message from rtcRoom:onRoomStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomStateChanged:withUid:state:extraInfo:}. <br>
     *        Call joinRoom:userInfo:roomConfig:{@link #ByteRTCRoom#joinRoom:userInfo:roomConfig:} to rejoin the room with a new required Token.
     */
    ByteRTCErrorCodeTokenExpired            = -1009,
        
    /**
     * 
     * @brief The Token you provided when calling `updateToken:` is invalid. Receive message from rtcRoom:onRoomStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomStateChanged:withUid:state:extraInfo:}.
     */
    ByteRTCErrorCodeUpdateTokenWithInvalidToken     = -1010,

    
    /**
     * 
     * @brief Users have been removed from the room because the administrator dismissed the room by calling OpenAPI. Receive message from rtcRoom:onRoomStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomStateChanged:withUid:state:extraInfo:}.
     */
    ByteRTCErrorCodeRoomDismiss = -1011,

    
    /**
     * 
     * @hidden internal use only
     * @brief Join room error. Receive message from rtcRoom:onRoomStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomStateChanged:withUid:state:extraInfo:}. <br>
     *        The LICENSE billing account does not use the LICENSE_AUTHENTICATE SDK while calling `joinRoom:userInfo:roomConfig:`, which caused the joining room to fail.
     */
    ByteRTCJoinRoomWithoutLicenseAuthenticateSDK = -1012,

    
    /**
     * 
     * @brief there is a room with the same roomId，whose room id is the same with echo test. Receive message from rtcEngine:onCreateRoomStateChanged:errorCode:{@link #ByteRTCVideoDelegate#rtcEngine:onCreateRoomStateChanged:errorCode:}.
     */
    ByteRTCRoomAlreadyExist = -1013,

    
    /**
     * 
     * @brief The local user joins multiple rooms with different uid. Receive message from rtcRoom:onRoomStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomStateChanged:withUid:state:extraInfo:}. <br>
     *        In the same engine instance, users need to use the same uid to join different rooms.
     */
    ByteRTCUserIDDifferent = -1014,
    
    /**
     * 
     * @hidden internal use only
     * @brief Server license expired, refused to enter the room. Receive message from rtcRoom:onRoomStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomStateChanged:withUid:state:extraInfo:}.
     */
    ByteRTCErrorCodeJoinRoomServerLicenseExpired = -1017,
    
    /**
     * 
     * @hidden internal use only
     * @brief Exceeds the upper limit of the concurrency allowed by the server license, and refuses to enter the room. Receive message from rtcRoom:onRoomStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomStateChanged:withUid:state:extraInfo:}.
     */
    ByteRTCErrorCodeJoinRoomExceedsTheUpperLimit = -1018,
    
    /**
     * 
     * @hidden internal use only
     * @brief The license parameter is wrong and refuses to enter the room. Receive message from rtcRoom:onRoomStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomStateChanged:withUid:state:extraInfo:}.
     */
    ByteRTCErrorCodeJoinRoomLicenseParameterError = -1019,
    
    /**
     * 
     * @hidden internal use only
     * @brief wrong license certificate path. Receive message from rtcRoom:onRoomStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomStateChanged:withUid:state:extraInfo:}.
     */
    ByteRTCErrorCodeJoinRoomLicenseFilePathError = -1020,
    
    /**
     * 
     * @hidden internal use only
     * @brief The license certificate is illegal, refuse to enter the room. Receive message from rtcRoom:onRoomStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomStateChanged:withUid:state:extraInfo:}.
     */
    ByteRTCErrorCodeJoinRoomLicenseIllegal = -1021,
    
    /**
     * 
     * @hidden internal use only
     * @brief License certificate has expired, refused to enter the room. Receive message from rtcRoom:onRoomStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomStateChanged:withUid:state:extraInfo:}.
     */
    ByteRTCErrorCodeJoinRoomLicenseExpired = -1022,
    
    /**
     * 
     * @hidden internal use only
     * @brief The content of the license certificate does not match. Receive message from rtcRoom:onRoomStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomStateChanged:withUid:state:extraInfo:}.
     */
    ByteRTCErrorCodeJoinRoomLicenseInformationNotMatch = -1023,
    
    /**
     * 
     * @hidden internal use only
     * @brief licenseThe current certificate does not match the cached certificate. Receive message from rtcRoom:onRoomStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomStateChanged:withUid:state:extraInfo:}.
     */
    ByteRTCErrorCodeJoinRoomLicenseNotMatchWithCache = -1024,
    
    /**
     * 
     * @brief The room has banned before the user calls `joinRoom`. Receive message from rtcRoom:onRoomStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomStateChanged:withUid:state:extraInfo:}.
     */
    ByteRTCErrorCodeJoinRoomRoomForbidden = -1025,
    
    /**
     * 
     * @brief The user has banned before calling `joinRoom`. Receive message from rtcRoom:onRoomStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomStateChanged:withUid:state:extraInfo:}.
     */
    ByteRTCErrorCodeJoinRoomUserForbidden = -1026,
    
    /**
     * 
     * @brief Subscription to audio & video stream failed, the total number of subscribed audio & video streams exceeded the upper limit. Receive message from rtcRoom:onStreamStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onStreamStateChanged:withUid:state:extraInfo:}. <br>
     *        In the game scenario, in order to ensure the performance and quality of audio & video calls, the server will limit the total number of audio & video streams subscribed by the user. When the total number of audio & video streams subscribed by the user has reached the maximum, continuing to subscribe to more streams will fail, and the user will receive this error notification.
     */
    ByteRTCErrorCodeOverStreamSubscribeLimit        = -1070,
    
    /**
     * 
     * @brief Publishing flow failed, the total number of publishing flows exceeds the upper limit. Receive message from rtcRoom:onStreamStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onStreamStateChanged:withUid:state:extraInfo:}. <br>
     *        RTC system limits the total number of streams published in a single room, including video streams, audio streams, and screen streams. Local users will fail to publish streams to the room when the maximum number of published streams in the room has been reached, and will receive this error notification.
     */
    ByteRTCErrorCodeOverStreamPublishLimit = -1080,
    
    /**
     * 
     * @deprecated since 3.52, use ByteRTCErrorCodeOverStreamPublishLimit-1080）instead
     * @brief The total number of published video streams exceeds the upper limit. <br>
     *        The RTC system limits the number of video streams posted in a single room. If the maximum number of video streams posted in the room has been reached, local users will fail to post video streams to the room again and will receive this error notification.
     */
    ByteRTCErrorCodeOverVideoPublishLimit = -1082,
    
    /**
     * 
     * @brief A/V synchronization failed. Receive message from tcRoom:onStreamStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onStreamStateChanged:withUid:state:extraInfo:}. <br>
     *        Current source audio ID has been set by other video publishers in the same room. <br>
     *        One single audio source cannot be synchronized with multiple video sources at the same time.
     */
    ByteRTCErrorCodInvalidAudioSyncUidRepeated = -1083,
    
    /**
     * 
     * @brief The user has been removed from the room due to the abnormal status of server. Receive message from rtcRoom:onRoomStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomStateChanged:withUid:state:extraInfo:}. <br>
     *        SDK  is disconnected with the signaling server. It will not reconnect automatically. Please contact technical support.
     */
    ByteRTCErrorCodeAbnormalServerStatus = -1084,
    
    /**
     * 
     * @hidden for internal use only
     * @brief In the scenario of one stream publish to multiple rooms, when at least two rooms are publishing the same stream, one of the rooms fails to unpublish. At this time, the business party needs to retry or notify the user to retry unpublish.
     */
    ByteRTCErrorCodeMultiRoomUnpublishFailed = -1085,
    
    /**
     * 
     * @hidden for internal use only
     * @brief The area codes are wrong when specifying service area.
     */
    ByteRTCErrorCodeWrongAreaCode = -1086,
    
    /**
     * 
     * @hidden for internal use only
     * @brief notify deadlock
     */
    ByteRTCErrorCodeDeadLockNotify = -1111,
};


/**
 * 
 * @type errorcode
 * @brief  Callback warning code. The warning code indicates that there is a problem within the SDK and is trying to recover. Warning codes are for notification only.
 */
typedef NS_ENUM(NSInteger, ByteRTCWarningCode) {
    
    /**
     * 
     * @deprecated since 3.45 and will be deleted in 3.51.
     */
    ByteRTCWarningCodeGetRoomFailed              = -2000,
    
    /**
     * 
     * @brief Failed to enter the room. Receive message from rtcRoom:onRoomStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomStateChanged:withUid:state:extraInfo:}. <br>
     *        When entering the room for the first time or when the network is disconnected and reconnected due to poor network conditions, entering the room failed due to a server error. The SDK automatically retries the room.
     */
    ByteRTCWarningCodeJoinRoomFailed             = -2001,
    
    /**
     * 
     * @brief Release audio & video stream failed. <br>
     *        When you publish audio & video streams in your room, the release fails due to a server error. The SDK automatically retries the release.
     */
    ByteRTCWarningCodePublishStreamFailed        = -2002,
    
    /**
     * 
     * @brief Subscription to audio & video stream failed. <br>
     *        The subscription failed because the audio & video stream for the subscription was not found in the current room. The SDK will automatically retry the subscription. If the subscription fails, it is recommended that you exit the retry.
     */
    ByteRTCWarningCodeSubscribeStreamFailed404  = -2003,
    
    /**
     * 
     * @brief Subscription to audio & video stream failed. <br>
     *        When you subscribe to audio & video streams in your room, the subscription fails due to a server error. The SDK automatically retries the subscription.
     */
    ByteRTCWarningCodeSubscribeStreamFailed5xx  = -2004,
    
    /**
     * 
     * @hidden currently not available
     * @brief  Function call order is wrong and is not used in the current code.
     */
    ByteRTCWarningCodeInvokeError = -2005,
    
    /**
     * 
     * @hidden for internal use only
     * @brief Scheduling exception, the media server address returned by the server is unavailable.
     */
    ByteRTCWarningCodeInvalidExpectMediaServerAddress = -2007,
    
    /**
     * 
     * @brief This warning is triggered when you call `setUserVisibility:`to set yourself unvisible to others before attempting to publish the flow.
     */
    ByteRTCWarningCodePublishStreamForbidden = -2009,
    
    /**
     * 
     * @deprecated since 3.45 and will be delted in 3.51.
     * @hidden
     * @brief When automatic subscription mode is not turned off, trying to turn on manual subscription mode will trigger this warning. <br>
     *        You need to turn off the automatic subscription mode before entering the room, and then call the subscribeStream:mediaStreamType:{@link #ByteRTCRoom#subscribeStream:mediaStreamType:} method to manually subscribe to the audio & video stream.
     */
    ByteRTCWarningCodeSubscribeStreamForbiden = -2010,
    
    /**
     * 
     * @brief Sending a custom broadcast message failed, you are not currently in the room.
     */
    ByteRTCWarningCodeSendCustomMessage = -2011,
    
    /**
     * 
     * @brief When the number of people in the room exceeds 500, stop sending `rtcEngine:onUserJoined:elapsed:` and `rtcEngine:onUserLeave:reason:` callbacks to existing users in the room, and prompt all users in the room via broadcast. Receive message from rtcRoom:onRoomStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomStateChanged:withUid:state:extraInfo:}.
     */
    ByteRTCWarningCodeCodeUserNotifyStop = -2013,
    
    /**
     * 
     * @brief User had published in other room.
     */
    ByteRTCWarningCodeUserInPublish = -2014,
    
    /**
     * 
     * @deprecated since 3.45 and will be delted in 3.51.
     * @brief there is a room with the same roomId
     */
    ByteRTCWarningCodeRoomAlreadyExist = -2015,

    
    /**
     * 
     * @brief A room with the same roomId already exists. The newly created room instance has replaced the old one. Receive message from rtcRoom:onRoomStateChanged:withUid:state:extraInfo:{@link #ByteRTCRoomDelegate#rtcRoom:onRoomStateChanged:withUid:state:extraInfo:}.
     */
    ByteRTCWarningCodeOldRoomBeenReplaced = -2016,

    
    /**
     * 
     * @brief this inteface has been banned for the engine is in echo testing mode
     */
    ByteRTCWarningCodeInEchoTestMode = -2017,
    
    /**
     * 
     * @brief The camera permission is abnormal, the current application does not get the camera permission
     */
    ByteRTCWarningCodeNoCameraPermission            = -5001,
    
    /**
     * 
     * @brief Deprecated since 3.45. Please use ByteRTCMediaDeviceError{@link #ByteRTCMediaDeviceError}.ByteRTCMediaDeviceErrorDeviceNoPermission instead. <br>
     *        The microphone permission is abnormal, the current application does not get microphone permission.
     * @deprecated since 3.45 and will be delted in 3.51, use ByteRTCMediaDeviceError{@link #ByteRTCMediaDeviceError}.ByteRTCMediaDeviceErrorDeviceNoPermission instead.
     */
    ByteRTCWarningCodeNoMicrophonePermission        = -5002,
    
    /**
     * 
     * @brief Deprecated since 3.45. Please use ByteRTCMediaDeviceError{@link #ByteRTCMediaDeviceError}.ByteRTCMediaDeviceErrorDeviceFailure instead. <br>
     *        The audio capture device failed to start. <br>
     *        Failed to start the audio capture device, the current device may be occupied by other applications.
     * @deprecated since 3.45 and will be delted in 3.51, use ByteRTCMediaDeviceError{@link #ByteRTCMediaDeviceError}.ByteRTCMediaDeviceErrorDeviceFailure instead.
     */
    ByteRTCWarningCodeAudioDeviceManagerRecordingStartFail     = -5003,
    
    /**
     * 
     * @brief Deprecated since 3.45. Please use ByteRTCMediaDeviceError{@link #ByteRTCMediaDeviceError}.ByteRTCMediaDeviceErrorDeviceFailure instead. <br>
     *        Audio playback device startup failure warning. <br>
     *        It may be due to insufficient system resources or wrong parameters.
     * @deprecated since 3.45 and will be delted in 3.51, use ByteRTCMediaDeviceError{@link #ByteRTCMediaDeviceError}.ByteRTCMediaDeviceErrorDeviceFailure instead.
     */
    ByteRTCWarningCodeAudioDeviceManagerPlayoutStartFail = -5004,
    
    /**
     * 
     * @brief Deprecated since 3.45. Please use ByteRTCMediaDeviceError{@link #ByteRTCMediaDeviceError}.ByteRTCMediaDeviceErrorDeviceNotFound instead. <br>
     *        No audio acquisition equipment available. <br>
     *        Failed to start the audio capture device, please insert the available audio capture device.
     * @deprecated since 3.45 and will be delted in 3.51, use ByteRTCMediaDeviceError{@link #ByteRTCMediaDeviceError}.ByteRTCMediaDeviceErrorDeviceNotFound instead.
     */
    ByteRTCWarningCodeNoRecordingDevice = -5005,
    
    /**
     * 
     * @brief Deprecated since 3.45. Please use ByteRTCMediaDeviceError{@link #ByteRTCMediaDeviceError}.ByteRTCMediaDeviceErrorDeviceNotFound instead. <br>
     *        No audio playback device available. <br>
     *        Failed to start the audio playback device, please insert the available audio playback device.
     * @deprecated since 3.45 and will be delted in 3.51, use ByteRTCMediaDeviceError{@link #ByteRTCMediaDeviceError}.ByteRTCMediaDeviceErrorDeviceNotFound instead.
     */
    ByteRTCWarningCodeNoPlayoutDevice = -5006,
    
    /**
     * 
     * @brief Deprecated since 3.45. Please use ByteRTCMediaDeviceWarning{@link #ByteRTCMediaDeviceWarning}.ByteRTCMediaDeviceWarningCaptureSilence instead. <br>
     *        The current audio equipment has not collected valid sound data, please check and replace the audio acquisition equipment.
     * @deprecated since 3.45 and will be delted in 3.51, use ByteRTCMediaDeviceWarning{@link #ByteRTCMediaDeviceWarning}.ByteRTCMediaDeviceWarningCaptureSilence instead.
     */
    ByteRTCWarningCodeRecordingSilence = -5007,
    
    /**
     * 
     * @brief Deprecated since 3.45. Please use ByteRTCMediaDeviceWarning{@link #ByteRTCMediaDeviceWarning}.ByteRTCMediaDeviceWarningOperationDenied instead. <br>
     *        Media device misoperation warning. <br>
     *        When using custom acquisition, the internal acquisition switch cannot be called, and this warning is triggered when called.
     * @deprecated since 3.45 and will be delted in 3.51, use ByteRTCMediaDeviceWarning{@link #ByteRTCMediaDeviceWarning}.ByteRTCMediaDeviceWarningOperationDenied instead.
     */
    ByteRTCWarningCodeMediaDeviceOperationDennied = -5008,
    
    /**
     * 
     * @brief Setting the screen audio capture type via `setScreenAudioSourceType` after `publishScreen` is not supported
     */
    ByteRTCWarningSetScreenAudioSourceTypeFailed = -5009,

    
    /**
     * 
     * @brief Setting the screen audio mix type via `setScreenAudioStreamIndex` after `publishScreen` is not supported
     */
    ByteRTCWarningSetScreenAudioStreamIndexFailed = -5010,
    
    /**
     * 
     * @brief Invalid pitch value setting
     */
    ByteRTCWarningInvalidVoicePitch = -5011,
    
    /**
     * 
     * @brief Mixed use of old and new interfaces for external audio sources
     */
    ByteRTCWarningInvalidCallForExtAudio = -5013,
    
    /**
     * 
     * @brief The specified internal rendering canvas handle is invalid. <br>
     *        An invalid canvas handle is specified when you call setLocalVideoCanvas:withCanvas:{@link #ByteRTCVideo#setLocalVideoCanvas:withCanvas:} or setRemoteVideoCanvas:withCanvas:{@link #ByteRTCVideo#setRemoteVideoCanvas:withCanvas:}, triggering this callback.
     */
    ByteRTCWarningCodeInvalidCanvasHandle = -6001,

    
    /**
     * 
     * @brief Authorization failure for [BytePlus Audio SDK](https:
     */
    ByteRTCWarningCodeInvaildSamiAppkeyORToken = -7002,

    
    /**
     * 
     * @brief Failure to get the resource for [BytePlus Audio SDK](https:
     */
    ByteRTCWarningCodeInvaildSamiResourcePath = -7003,

    
    /**
     * 
     * @brief Failure to load the library for [BytePlus Audio SDK](https:
     */
    ByteRTCWarningCodeLoadSamiLibraryFailed = -7004,

    
    /**
     * 
     * @brief The audio effect is not supported by [BytePlus Audio SDK](https:
     */
    ByteRTCWarningCodeInvaildSamiEffectType = -7005
};


 /**
 * 
 * @type keytype
 * @brief Stream publishing state
 */
typedef NS_ENUM(NSInteger, ByteRTCPublishState) {
    
    /**
     * 
     * @brief Successfully published.
     */
    ByteRTCPublishStatePublish = 0,
    
    /**
     * 
     * @brief Failed to publish.
     */
    ByteRTCPublishStateUnpublish = 1
};


 /**
 * 
 * @type keytype
 * @brief Stream subscription state
 */
typedef NS_ENUM(NSInteger, ByteRTCSubscribeState) {
    
    /**
     * 
     * @brief Successfully subscribed.
     */
    ByteRTCSubscribeStateSubscribe = 0,
    
    /**
     * 
     * @brief Failed to subscribe.
     */
    ByteRTCSubscribeStateUnsubscribe = 1
};



typedef NS_ENUM(NSInteger, ByteRTCPublishStateChangeReason) {
    
    /**
     * 
     * @brief Requested to publish.
     */
    ByteRTCPublishStateChangeReasonPublish = 0, 
    
    /**
     * 
     * @brief Requested to remove.
     */
    ByteRTCPublishStateChangeReasonUnpublish = 1, 
    
    /**
     * 
     * @brief The token the user used was not permitted to publish.
     */
    ByteRTCPublishStateChangeReasonNoPublishPermission = 2,  
    
    /**
     * 
     * @brief The number of streams the user has published has exceeded the limit.
     */
    ByteRTCPublishStateChangeReasonOverStreamPublishLimit = 3, 
    
    /**
     * 
     * @brief The stream failed to remove from a room when you are publishing the stream in two or more rooms.
     */
    ByteRTCPublishStateChangeReasonMultiRoomUnpublishFailed = 4, 
    
    /**
     * 
     * @brief Failed to publish due to the server error.
     */
    ByteRTCPublishStateChangeReasonPublishStreamFailed = 5, 
    
    /**
     * 
     * @brief The user who tried to publish a stream is not a host. Call setUserVisibility{@link #IRTCRoom#setUserVisibility} to change the user role.
     */
    ByteRTCPublishStateChangeReasonPublishStreamForbidden = 6,
    
    /**
     * 
     * @brief The user who tried to publish a stream has already published a stream in a room.
     */
    ByteRTCPublishStateChangeReasonUserInPublish = 7
};



typedef NS_ENUM(NSInteger, ByteRTCSubscribeStateChangeReason) {
    
    /**
     * 
     * @brief Requested to subscribe.
     */
    ByteRTCSubscribeStateChangeReasonSubscribe = 0, 
    
    /**
     * 
     * @brief Requested to unsubscribe.
     */
    ByteRTCSubscribeStateChangeReasonUnsubscribe = 1, 
    
    /**
     * 
     * @brief The remote user published a stream.
     */
    ByteRTCSubscribeStateChangeReasonRemotePublish = 2, 
    
    /**
     * 
     * @brief The remote user removed a stream.
     */
    ByteRTCSubscribeStateChangeReasonRemoteUnpublish = 3,
    
    /**
     * 
     * @brief Failed to subscribe due to the server error. The SDK will automatically retry.
     */
    ByteRTCSubscribeStateChangeReasonStreamFailed5xx = 4, 
    
    /**
     * 
     * @brief Failed to subscribe since the stream to be subscribe to was not found in the room. The SDK will automatically retry the subscription. If the subscription still fails, we recommend you exit and retry.
     */
    ByteRTCSubscribeStateChangeReasonStreamFailed404 = 5, 
    
    /**
     * 
     * @brief The number of streams the user has subscribed to has exceeded the limit.
     */
    ByteRTCSubscribeStateChangeReasonOverStreamSubscribeLimit = 6,
      
    /**
     * 
     * @brief The user was not permitted to subscribe to the stream.
     */  
    ByteRTCSubscribeStateChangeReasonNoSubscribePermission = 7
};


/**
 * 
 * @type keytype
 * @brief Reasons for performance-related alarms
 */
typedef NS_ENUM(NSInteger, ByteRTCPerformanceAlarmReason) {
    
    /**
     * 
     * @brief The poor network causes the transmission performance to fall back. This reason is only received when sending performance fallback is turned on.
     */
    ByteRTCPerformanceAlarmReasonBandwidthFallback = 0,
    
    /**
     * 
     * @brief Network performance recovery, transmission performance rollback recovery. This reason is only received when sending performance fallback is turned on.
     */
    ByteRTCPerformanceAlarmReasonBandwidthResumed = 1,
    
    /**
     * 
     * @brief If the send performance fallback is not turned on, when receiving this alarm, it means that the performance is insufficient; <br>
     *        If the send performance fallback is turned on, when receiving this alarm, it means that the performance is insufficient and the send performance fallback has occurred.
     */
    ByteRTCPerformanceAlarmReasonFallback = 2,
    
    /**
     * 
     * @brief If the send performance fallback is not turned on, when receiving this alarm, it means that the performance shortage has been restored; <br>
     *         If the send performance fallback is turned on, when receiving this alarm, it means that the performance shortage has been restored and the send performance fallback has occurred. Recovery.
     */
    ByteRTCPerformanceAlarmReasonResumed = 3,
};


/**
 * 
 * @type keytype
 * @brief  Mode of performance fallback
 */
typedef NS_ENUM(NSInteger, ByteRTCPerformanceAlarmMode) {
    
    /**
     * 
     * @brief Not enabled Release performance fallback
     */
    ByteRTCPerformanceAlarmModeNormal = 0,
    
    /**
     * 
     * @brief Open Release Performance Rollback
     */
    ByteRTCPerformanceAlarmModeSimulcast = 1,
};


/**
 * 
 * @hidden
 * @deprecated since 3.45 and will be deleted in 3.51.
 * @type keytype
 * @brief  Set engine working mode
 */
typedef NS_ENUM(NSUInteger, ByteRTCMode) {
    
    /**
     * 
     * @brief General mode, in which only voice calls in normal meeting mode can be made and automatic subscription publishing can be started.
     */
    ByteRTCModeGeneral = 0,
    
    /**
     * 
     * @brief The game voice mode, in which automatic subscription publishing is turned off, will actively publish subscription voice according to the strategy of the game business.
     */
    ByteRTCModeLocalAudio = 1,
};

/**
 * 
 * @type keytype
 * @brief Stream fallback options of publisher
 */
typedef NS_ENUM(NSUInteger, ByteRTCPublishFallbackOption) {
    
    /**
     * 
     * @brief Default setting. No fallback is allowed under limited network conditions.
     */
    ByteRTCPublishFallbackOptionDisabled = 0,
    
    /**
     * 
     * @brief Under limited network conditions, the video streams that you published will degrade sequentially from the highest-quality stream to the lowest-quality stream until it can match current network conditions.
     */
    ByteRTCPublishFallbackOptionSimulcast = 1,
};


/**
 * 
 * @hidden
 * @deprecated since 3.45 and will be deleted in 3.51, use RoomConfig in joinRoom API instead.
 * @type keytype
 * @brief  Subscription mode option.
 */
typedef NS_ENUM(NSUInteger, ByteRTCSubscribeMode) {
    
    /**
     * 
     * @brief Automatic subscription mode. The SDK  automatically subscribes to every stream in the room for you.
     */
    ByteRTCSubscribeModeAuto = 0,
    
    /**
     * 
     * @brief Manual subscription mode. The SDK  does not automatically subscribe to in-room audio & video streams. You should call the `subscribeStream` to manually subscribe to audio & video streams posted by other users as needed.
     */
    ByteRTCSubscribeModeManual = 1
};

/**
 * 
 * @type keytype
 * @brief Stream fallback options of subscriber
 */
typedef NS_ENUM(NSUInteger, ByteRTCSubscribeFallbackOption) {
    
    /**
     * 
     * @brief Default setting. No fallback is allowed under limited network conditions.
     */
    ByteRTCSubscribeFallbackOptionDisabled = 0,
    
    /**
     * 
     * @brief The resolution of currently subscribed video stream will be reduced under limited network conditions, see [Stream Fallback](70137) for details. <br>
     *        You can only select this setting after the stream publisher calls `enableSimulcastMode:` to enable the mode of publishing multiple streams, otherwise no fallback will occur.
     */
    ByteRTCSubscribeFallbackOptionVideoStreamLow = 1,
    
    /**
     * 
     * @brief The resolution of currently subscribed video stream will be reduced first under limited network conditions. When the network condition is not sufficient to receive the minimum resolution stream, the video is automatically cancelled and only the audio is received. <br>
     *        You can only select this setting after the stream publisher calls `enableSimulcastMode:` to enable the mode of publishing multiple streams, otherwise no fallback will occur.
     */
    ByteRTCSubscribeFallbackOptionAudioOnly = 2,
};


/**
 * 
 * @type keytype
 * @brief Priority of the publisher. When a user encounters performance insufficiency of either the network or the device, the media stream  will fall back in the ascending order of `RemoteUserPriority`.
 */
typedef NS_ENUM(NSUInteger, ByteRTCRemoteUserPriority) {
    
    /**
     * 
     * @brief Low, the default
     */
    ByteRTCRemoteUserPriorityLow = 0,
    
    /**
     * 
     * @brief Medium
     */
    ByteRTCRemoteUserPriorityMedium = 100,
    
    /**
     * 
     * @brief High
     */
    ByteRTCRemoteUserPriorityHigh = 200,
};


/**
 * 
 * @type keytype
 * @brief Reason of the Fallback or reverting from a Fallback of the subscribed stream or the publishing stream
 */
typedef NS_ENUM(NSInteger, ByteRTCFallbackOrRecoverReason) {
    
    /**
     * 
     * @brief The default: Fallback due to an unknown reason that is neither infufficienclt bandwidth of the network nor poor-performance of the device
     */
    ByteRTCFallbackOrRecoverReasonUnknown = -1,
    
    /**
     * 
     * @brief Fallback of the subscribed stream due to insufficient bandwidth of the network
     */
    ByteRTCFallbackOrRecoverReasonSubscribeFallbackByBandwidth = 0,
    
    /**
     * 
     * @brief Fallback of the subscribed stream for poor-performance of the device
     */
    ByteRTCFallbackOrRecoverReasonSubscribeFallbackByPerformance = 1,
    
    /**
     * 
     * @brief Reverting from a Fallback of the subscribed stream due to the recovery of the network bandwidth
     */
    ByteRTCFallbackOrRecoverReasonSubscribeRecoverByBandwidth = 2,
    
    /**
     * 
     * @brief Reverting from a Fallback of the subscribed stream due to the amelioration of the device performance
     */
    ByteRTCFallbackOrRecoverReasonSubscribeRecoverByPerformance = 3,
    
    /**
     * 
     * @brief Fallback of the publishing stream due to Insufficient bandwidth of the network
     */
    ByteRTCFallbackOrRecoverReasonPublishFallbackByBandwidth = 4,
    
    /**
     * 
     * @brief Fallback of the publishing stream due to poor-performance of the device
     */
    ByteRTCFallbackOrRecoverReasonPublishFallbackByPerformance = 5,
    
    /**
     * 
     * @brief Reverting from a Fallback of the publishing stream due to the recovery of the network bandwidth
     */
    ByteRTCFallbackOrRecoverReasonPublishRecoverByBandwidth = 6,
    
    /**
     * 
     * @brief Reverting from a Fallback of the publishing stream due to the amelioration of the device performance
     */
    ByteRTCFallbackOrRecoverReasonPublishRecoverByPerformance = 7,
};


/**
 * 
 * @type keytype
 * @brief  Local audio stream status.
 */
typedef NS_ENUM(NSInteger, ByteRTCLocalAudioStreamState) {
    
    /**
     * 
     * @brief The default initial state of the local audio. <br>
     *         Callback to this state when the microphone stops working, corresponding to the error code ByteRTCLocalAudioStreamError{@link #ByteRTCLocalAudioStreamError} in ByteRTCLocalAudioStreamErrorOk
     */
    ByteRTCLocalAudioStreamStateStopped = 0,
    
    /**
     * 
     * @brief The local audio recording device started successfully. <br>
     *         Callback to this state when the first audio frame is collected, corresponding to the error code ByteRTCLocalAudioStreamError{@link #ByteRTCLocalAudioStreamError} in ByteRTCLocalAudioStreamErrorOk
     */
    ByteRTCLocalAudioStreamStateRecording = 1,
    
    /**
     * 
     * @brief The first frame of the local audio was successfully encoded. <br>
     *         Callback to this state when the audio first frame encoding is successful, corresponding to the error code ByteRTCLocalAudioStreamError{@link #ByteRTCLocalAudioStreamError} in ByteRTCLocalAudioStreamErrorOk
     */
    ByteRTCLocalAudioStreamStateEncoding = 2,
    
    /**
     * 
     * @brief  The local audio startup failed, and the status is called back at the following times: <br>
     *        - The local recording device failed to start, corresponding to the error code ByteRTCLocalAudioStreamError{@link #ByteRTCLocalAudioStreamError} ByteRTCLocalAudioStreamErrorRecordFailure
     *        - No recording device permission was detected, corresponding to the error code ByteRTCLocalAudioStreamError{@link #ByteRTCLocalAudioStreamError} ByteRTCLocalAudioStreamErrorDeviceNoPermission
     *        - The audio encoding failed, corresponding to the error code ByteRTCLocalAudioStreamError{@link #ByteRTCLocalAudioStreamError} in ByteRTCLocalAudioStreamError
     */
    ByteRTCLocalAudioStreamStateFailed = 3,
};


/**
 * 
 * @type keytype
 * @brief Error code when the state of the local audio stream changes.
 */
typedef NS_ENUM(NSInteger, ByteRTCLocalAudioStreamError) {
    
    /**
     * 
     * @brief Local audio status is normal
     */
    ByteRTCLocalAudioStreamErrorOk = 0,
    
    /**
     * 
     * @brief Local audio error cause unknown
     */
    ByteRTCLocalAudioStreamErrorFailure = 1,
    
    /**
     * 
     * @brief No permission to start local audio recording device
     */
    ByteRTCLocalAudioStreamErrorDeviceNoPermission = 2,
    
    /**
     * 
     * @hidden currently not available
     * @brief The local audio recording device is already in use
     * @note The error code is not yet in use
     */
    ByteRTCLocalAudioStreamErrorDeviceBusy = 3,
    
    /**
     * 
     * @brief Local audio recording failed, it is recommended that you check whether the recording device is working properly
     */
    ByteRTCLocalAudioStreamErrorRecordFailure = 4,
    
    /**
     * 
     * @brief Local audio encoding failed
     */
    ByteRTCLocalAudioStreamErrorEncodeFailure = 5,
    
    /**
     * 
     * @brief No audio recording equipment available
     */
    ByteRTCLocalAudioStreamErrorNoRecordingDevice = 6
};


/**
 * 
 * @type keytype
 * @brief  Local video stream status
 */
typedef NS_ENUM(NSInteger, ByteRTCLocalVideoStreamState) {
    
    /**
     * 
     * @brief Local video default initial state <br>
     *         Callback the state when the camera stops working, corresponding to the error code ByteRTCLocalVideoStreamError{@link #ByteRTCLocalVideoStreamError} ByteRTCLocalVideoStreamErrorOk
     */
    ByteRTCLocalVideoStreamStateStopped = 0,
    
    /**
     * 
     * @brief The local video recording device starts successfully <br>
     *         Callback the state when the first frame of the video is collected, corresponding to the error code ByteRTCLocalVideoStreamError{@link #ByteRTCLocalVideoStreamError} ByteRTCLocalVideoStreamErrorOk
     */
    ByteRTCLocalVideoStreamStateRecording = 1,
    
    /**
     * 
     * @brief Local video first frame encoding success <br>
     *         Local video first frame encoding success callback to the state, corresponding to the error code ByteRTCLocalVideoStreamError{@link #ByteRTCLocalVideoStreamError} in ByteRTCLocalVideoStreamErrorOk
     */
    ByteRTCLocalVideoStreamStateEncoding = 2,
    
    /**
     * 
     * @brief  Local video startup failed,  the status is called back at the following times: <br>
     *        - The local acquisition device failed to start, corresponding to the error code ByteRTCLocalVideoStreamError{@link #ByteRTCLocalVideoStreamError} ByteRTCLocalVideoStreamErrorCaptureFailure
     *        - No camera permission was detected, corresponding to the error code ByteRTCLocalVideoStreamError{@link #ByteRTCLocalVideoStreamError} ByteRTCLocalVideoStreamErrorDeviceNoPermission
     *        - The video encoding failed, corresponding to the error code ByteRTCLocalVideoStreamError{@link #ByteRTCLocalVideoStreamError} in ByteRTCLocalVideoStreamErrorEncodeFailure
     */
    ByteRTCLocalVideoStreamStateFailed = 3,
};


/**
 * 
 * @type keytype
 * @brief  Error code when the local video state changes
 */
typedef NS_ENUM(NSInteger, ByteRTCLocalVideoStreamError) {
    
    /**
     * 
     * @brief Local video status is normal (the default return value when the local video status changes to normal)
     */
    ByteRTCLocalVideoStreamErrorOk = 0,
    
    /**
     * 
     * @brief Local video stream publishing failed
     */
    ByteRTCLocalVideoStreamErrorFailure = 1,
    
    /**
     * 
     * @brief No access to the local video capture device
     */
    ByteRTCLocalVideoStreamErrorDeviceNoPermission = 2,
    
    /**
     * 
     * @brief Local video capture equipment is occupied
     */
    ByteRTCLocalVideoStreamErrorDeviceBusy = 3,
    
    /**
     * 
     * @brief The local video capture device does not exist or has been removed
     */
    ByteRTCLocalVideoStreamErrorDeviceNotFound = 4,
    
    /**
     * 
     * @brief Local video capture failed, it is recommended to check whether the acquisition device is working properly
     */
    ByteRTCLocalVideoStreamErrorCaptureFailure = 5,
    
    /**
     * 
     * @brief Local video encoding failed
     */
    ByteRTCLocalVideoStreamErrorEncodeFailure = 6,
    
    /**
     * 
     * @brief The local video capture device is disconnected. It is occupied by other programs during the call.
     */
    ByteRTCLocalVideoStreamErrorDeviceDisconnected = 7,
};


/**
 * 
 * @type keytype
 * @brief  The remote audio stream state of the user subscription.
 */
typedef NS_ENUM(NSInteger, ByteRTCRemoteAudioState) {
    
    /**
     * 
     * @brief  The default initial state of the remote audio stream is called back at the following time: <br>
     *        - Local users stop receiving the remote audio stream, the corresponding reason is `ByteRTCRemoteAudioStateChangeReasonLocalMuted` in ByteRTCRemoteAudioStateChangeReason{@link #ByteRTCRemoteAudioStateChangeReason}
     *        - The remote user stopped sending the audio stream, the corresponding reason is `ByteRTCRemoteAudioStateChangeReasonRemoteMuted` in ByteRTCRemoteAudioStateChangeReason{@link #ByteRTCRemoteAudioStateChangeReason}
     *        - The remote user left the room, the corresponding reason is `ByteRTCRemoteAudioStateChangeReasonRemoteOffline` in ByteRTCRemoteAudioStateChangeReason{@link #ByteRTCRemoteAudioStateChangeReason}
     */
    ByteRTCRemoteAudioStateStopped = 0,
    
    /**
     * 
     * @brief Start receiving the remote audio stream header.
     */
    ByteRTCRemoteAudioStateStarting = 1,
    
    /**
     * 
     * @brief  The remote audio stream is decoding and playing normally. The state will be called back at the following time: <br>
     *        - The first frame of the remote audio is successfully decoded, and the corresponding reason is ByteRTCRemoteAudioStateChangeReason in ByteRTCRemoteAudioStateChangeReason{@link #ByteRTCRemoteAudioStateChangeReason}
     *        - The network returned to normal from blocking, and the corresponding reason is ByteRTCRemoteAudioStateChangeReason in ByteRTCRemoteAudioStateChangeReason{@link #ByteRTCRemoteAudioStateChangeReason}
     *        - Local users recover receiving remote audio streams due to ByteRTCRemoteAudioStateChangeReason in ByteRTCRemoteAudioStateChangeReason{@link #ByteRTCRemoteAudioStateChangeReason}
     *        - The remote user resumes sending audio streams, the corresponding reason is ByteRTCRemoteAudioStateChangeReason in ByteRTCRemoteAudioStateChangeReason{@link #ByteRTCRemoteAudioStateChangeReason}
     */
    ByteRTCRemoteAudioStateDecoding = 2,
    
    /**
     * 
     * @brief Remote audio streaming card.
     */
    ByteRTCRemoteAudioStateFrozen = 3,
    
    /**
     * 
     * @hidden currently not available
     * @brief  The remote audio stream failed to play
     * @note  The error code is not yet used
     */
    ByteRTCRemoteAudioStateFailed = 4,
};


/**
 * 
 * @type keytype
 * @brief  Receives the cause of the remote audio stream state change.
 */
typedef NS_ENUM(NSInteger, ByteRTCRemoteAudioStateChangeReason) {
    
    /**
     * 
     * @brief Internal reasons
     */
    ByteRTCRemoteAudioStateChangeReasonInternal = 0,
    
    /**
     * 
     * @brief Network blocking
     */
    ByteRTCRemoteAudioStateChangeReasonNetworkCongestion = 1,
    
    /**
     * 
     * @brief Network back to normal
     */
    ByteRTCRemoteAudioStateChangeReasonNetworkRecovery = 2,
    
    /**
     * 
     * @brief Local user stops receiving remote audio stream
     */
    ByteRTCRemoteAudioStateChangeReasonLocalMuted = 3,
    
    /**
     * 
     * @brief Local users resume receiving remote audio streams
     */
    ByteRTCRemoteAudioStateChangeReasonLocalUnmuted = 4,
    
    /**
     * 
     * @brief Remote user stops sending audio stream
     */
    ByteRTCRemoteAudioStateChangeReasonRemoteMuted = 5,
    
    /**
     * 
     * @brief Remote user resumes sending audio stream
     */
    ByteRTCRemoteAudioStateChangeReasonRemoteUnmuted = 6,
    
    /**
     * 
     * @brief Remote user leaves room
     */
    ByteRTCRemoteAudioStateChangeReasonRemoteOffline = 7,
};


/**
 * 
 * @type keytype
 * @brief  Remote video stream status
 */
typedef NS_ENUM(NSInteger, ByteRTCRemoteVideoState) {
    
    /**
     * 
     * @brief  The default initial state of the remote video stream,  callback the state at the following times: <br>
     *        - The local user stops receiving the remote video stream, corresponding to the error code ByteRTCRemoteVideoStateChangeReason{@link #ByteRTCRemoteVideoStateChangeReason} ByteRTCRemoteVideoStateChangeReasonLocalMuted
     *        - The remote user stops sending the video stream, corresponding to the error code ByteRTCRemoteVideoStateChangeReasonRemoteMuted
     *        - The remote user leaves the room, corresponding to Error code ByteRTCRemoteVideoStateChangeReason{@link #ByteRTCRemoteVideoStateChangeReason} in ByteRTCRemoteVideoStateChangeReasonRemoteOffline
     */
    ByteRTCRemoteVideoStateStopped = 0,
    
    /**
     * 
     * @brief Local users have received the remote video header package <br>
     *         Callback this state when the remote video header package is received, corresponding to the error code ByteRTCRemoteVideoStateChangeReason{@link #ByteRTCRemoteVideoStateChangeReason} ByteRTCRemoteVideoStateChangeReasonLocalUnmuted
     */
    ByteRTCRemoteVideoStateStarting = 1,
    
    /**
     * 
     * @brief  The remote video stream is decoding and playing normally,  callback the status at the following times: <br>
     *        - ByteRTCRemoteVideoStateChangeReason{@link #ByteRTCRemoteVideoStateChangeReason} ByteRTCRemoteVideoStateChangeReasonLocalUnmuted
     *        - The network returned to normal from blocking, corresponding to the error code ByteRTCRemoteVideoStateChangeReasonNetworkRecovery
     *        - The local user recovers the received remote video Stream, corresponding to the error code ByteRTCRemoteVideoStateChangeReason{@link #ByteRTCRemoteVideoStateChangeReason} ByteRTCRemoteVideoStateChangeReasonLocalUnmuted
     *        - The remote user resumes sending the video stream, corresponding to the error code in ByteRTCRemoteVideoStateChangeReason{@link #ByteRTCRemoteVideoStateChangeReason}
     */
    ByteRTCRemoteVideoStateDecoding = 2,
    
    /**
     * 
     * @brief Remote video streaming card <br>
     *         Network blocking, packet loss rate and other reasons will report the status of the video card stream, corresponding to the error code ByteRTCRemoteVideoStateChangeReason{@link #ByteRTCRemoteVideoStateChangeReason} ByteRTCRemoteVideoStateChangeReasonNetworkCongestion
     */
    ByteRTCRemoteVideoStateFrozen = 3,
     
     /**
      * 
      * @brief The remote video stream failed to play <br>
      *        If the internal processing of the remote video stream fails, the method will be called back,  corresponding to the error code ByteRTCRemoteVideoStateChangeReason{@link #ByteRTCRemoteVideoStateChangeReason} ByteRTCRemoteVideoStateChangeReasonInternal
      */
    ByteRTCRemoteVideoStateFailed = 4,
};


/**
 * 
 * @type keytype
 * @brief  Cause of remote video stream state change
 */
typedef NS_ENUM(NSInteger, ByteRTCRemoteVideoStateChangeReason) {
    
    /**
     * 
     * @brief Internal reasons
     */
    ByteRTCRemoteVideoStateChangeReasonInternal = 0,
    
    /**
     * 
     * @brief Network blocking
     */
    ByteRTCRemoteVideoStateChangeReasonNetworkCongestion = 1,
    
    /**
     * 
     * @brief Network back to normal
     */
    ByteRTCRemoteVideoStateChangeReasonNetworkRecovery = 2,
    
    /**
     * 
     * @brief Local user stops receiving remote video stream or local user disables video module
     */
    ByteRTCRemoteVideoStateChangeReasonLocalMuted = 3,
    
    /**
     * 
     * @brief Local user resumes receiving remote video streams or local user enables video modules
     */
    ByteRTCRemoteVideoStateChangeReasonLocalUnmuted = 4,
    
    /**
     * 
     * @brief The remote user stops sending the video stream or the remote user disables the video module
     */
    ByteRTCRemoteVideoStateChangeReasonRemoteMuted = 5,
    
    /**
     * 
     * @brief Remote user resumes sending video stream or remote user enables video module
     */
    ByteRTCRemoteVideoStateChangeReasonRemoteUnmuted = 6,
    
    /**
     * 
     * @brief Remote user leaves room
     */
    ByteRTCRemoteVideoStateChangeReasonRemoteOffline = 7,
};


/**
 * 
 * @type keytype
 * @brief Type of media device
 */
typedef NS_ENUM(NSInteger, ByteRTCMediaDeviceType) {
    
    /**
     * 
     * @brief Unknow device
     */
    ByteRTCMediaDeviceTypeAudioUnknown = -1,
    
    /**
     * 
     * @brief Screen audio recorder
     */
    ByteRTCMediaDeviceTypeAudioRenderDevice = 0,
    
    /**
     * 
     * @brief Microphone
     */
    ByteRTCMediaDeviceTypeAudioCaptureDevice = 1,
    
    /**
     * 
     *@hidden currently not available
     *@brief  Video rendering device type, this type is not used yet
     */
    ByteRTCMediaDeviceTypeVideoRenderDevice = 2,
    
    /**
     * 
     *@brief Video capture device
     */
    ByteRTCMediaDeviceTypeVideoCaptureDevice = 3,
    
    /**
     * 
     *@brief Screen video capture device
     */
    ByteRTCMediaDeviceTypeScreenVideoCaptureDevice = 4,
    
    /**
     * 
     *@brief Screen audio recorder
     */
    ByteRTCMediaDeviceTypeScreenAudioCaptureDevice = 5
};


/**
 * 
 * @type keytype
 * @brief Media device state <br>
 *        You will be informed of device state by `rtcEngine:onAudioDeviceStateChanged:device_type:device_state:device_error:` or `rtcEngine:onVideoDeviceStateChanged:device_type:device_state:device_error:`.
 */
typedef NS_ENUM(NSInteger, ByteRTCMediaDeviceState) {
    
    /**
     * 
     * @brief On
     */
    ByteRTCMediaDeviceStateStarted = 1,
    
    /**
     * 
     * @brief Off
     */
    ByteRTCMediaDeviceStateStopped = 2,
    
    /**
     * 
     * @brief Runtime error <br>
     *        For example, when the media device is expected to be working but no data is received.
     */
    ByteRTCMediaDeviceStateRuntimeError = 3,
    
    /**
     * 
     * @brief Added <br>
     * Call enumerate-device api to update the device list when you get this notification.
     */
    ByteRTCMediaDeviceStateAdded = 10,
    
    /**
     * 
     * @brief Removed <br>
     * Call enumerate-device api to update the device list when you get this notification.
     */
    ByteRTCMediaDeviceStateRemoved = 11,
    
    /**
     * 
     * @brief Phone calls, locking screen or the other Apps interrupted the RTC call. RTC call will resume once the call ends or the other Apps release the media devices.
     */
    ByteRTCMediaDeviceStateInterruptionBegan = 12,
    
    /**
     * 
     * @brief RTC call resumed from the interruption caused by the phone calls or the other Apps.
     */
    ByteRTCMediaDeviceStateInterruptionEnded = 13,
    
    /**
     * 
     * @hidden(iOS)
     * @brief Notification of receiving the device list after time-out. <br>
     * Call enumerate-device api to update the device list when you get this notification.
     */
    ByteRTCMediaDeviceListUpdated = 16,

};


/**
 * 
 * @type keytype
 * @brief  Media device error
 */
typedef NS_ENUM(NSInteger, ByteRTCMediaDeviceError) {
    
    /**
     * 
     *@brief Normal
     */
    ByteRTCMediaDeviceErrorOK = 0,
    
    /**
     * 
     *@brief No permission
     */
    ByteRTCMediaDeviceErrorDeviceNoPermission = 1,
    
    /**
     * 
     *@brief Occupied by the other application
     */
    ByteRTCMediaDeviceErrorDeviceBusy = 2,
    
    /**
     * 
     *@brief Error
     */
    ByteRTCMediaDeviceErrorDeviceFailure = 3,
    
    /**
     * 
     *@brief Not found
     */
    ByteRTCMediaDeviceErrorDeviceNotFound = 4,
    
    /**
     * 
     *@brief Disconnected
     */
    ByteRTCMediaDeviceErrorDeviceDisconnected = 5,
    
    /**
     * 
     * @brief No data callback from the capture devices. <br>
     *        RTC emits this error when the media device is expected to be working but no data is received.
     */
    ByteRTCMediaDeviceErrorDeviceNoCallback = 6,
    
    /**
     * 
     *@brief Not supported sample rate
     */
    ByteRTCMediaDeviceErrorUNSupportFormat = 7,
    
    /**
     * 
     * @hidden(macOS)
     * @brief iOS screen capture not find group id parameter
     */
    ByteRTCMediaDeviceErrorNotFindGroupId = 8,
   
   /**
    * 
    * @hidden(macOS)
    * @brief An interruption caused by the app being sent to the background as the user starts the system camera app.
    */
    ByteRTCMediaDeviceErrorNotAvailableInBackground = 9,
   
   /**
    * 
    * @hidden(macOS)
    * @brief An interruption caused by the video device temporarily being unavailable (for example, when used by another app).
    */
    ByteRTCMediaDeviceErrorVideoInUseByAnotherClient = 10,
   
   /**
    * 
    * @hidden(macOS)
    * @brief An interruption caused when your app is running in Slide Over, Split View, or Picture in Picture mode on iPad.
    */
    ByteRTCMediaDeviceErrorNotAvailableWithMultipleForegroundApps = 11,
   
   /**
    * 
    * @hidden(macOS)
    * @brief An interruption due to system pressure, such as overheating.
    */
    ByteRTCMediaDeviceErrorNotAvailableDueToSystemPressure = 12
};


/**
 * 
 * @type keytype
 * @brief Media device warning
 */
typedef NS_ENUM(NSInteger, ByteRTCMediaDeviceWarning) {
    
    /**
     * 
     * @brief No warning
     */
    ByteRTCMediaDeviceWarningOK = 0,
    
    /**
     * 
     * @brief Illegal device operation. Calls the API for internal device when using the external device.
     */
    ByteRTCMediaDeviceWarningOperationDenied = 1,
    
    /**
     * 
     * @brief The media device is capturing silent frames.
     */
    ByteRTCMediaDeviceWarningCaptureSilence = 2,
    
    
    /**
     * 
     * @hidden for internal use only
     * @brief The volume is too loud and exceeds the acquisition range of the device. Lower the microphone volume or lower the volume of the audio source.
     */
    ByteRTCMediaDeviceWarningDetectClipping = 10,
    
    /**
     * 
     * @brief Echos between mics and speakers are detected during a call. <br>
     *        `rtcEngine:onAudioDeviceWarning:deviceType:deviceWarning:` notifies you with this enum of echo issue. During a call, SDK will detect echo issue only when ByteRTCRoomProfile{@link #ByteRTCRoomProfile} is set to `ByteRTCRoomProfileMeeting` or `ByteRTCRoomProfileMeetingRoom` and AEC is disabled.
     */
    ByteRTCMediaDeviceWarningDetectLeakEcho = 11,
    
    /**
     * 
     * @hidden for internal use only
     * @brief Low SNR.
     */
    ByteRTCMediaDeviceWarningDetectLowSNR = 12,
    
    /**
     * 
     * @hidden for internal use only
     * @brief Silence inserted during capture.
     */
    ByteRTCMediaDeviceWarningDetectInsertSilence = 13,
    
    /**
     * 
     * @hidden for internal use only
     * @brief Silence during capture.
     */
    ByteRTCMediaDeviceWarningCaptureDetectSilence = 14,
    
    /**
     * 
     * @hidden for internal use only
     * @brief Silence disappears during capture.
     */
    ByteRTCMediaDeviceWarningCaptureDetectSilenceDisappear = 15,
    
    /**
     * 
     * @brief Howling detected. <br>
     *        You will receive this callback in the following scenarios: 1) Howling is detected under the room profiles that do not support howling suppression; 2) Detect howling that is not suppressed under the room profiles that support howling suppression. <br>
     *        You can only enable howling suppression by calling calling joinRoom:userInfo:roomConfig:{@link #ByteRTCRoom#joinRoom:userInfo:roomConfig:} to set your room profile as ByteRTCRoomProfileCommunication, ByteRTCRoomProfileMeeting, and ByteRTCRoomProfileMeetingRoom. <br>
     *        We recommend that you remind your users to adjust the physical distance between two devices or disable all unused devices except the connecting one.
     */
    ByteRTCMediaDeviceWarningCaptureDetectHowling = 16,
    
    /**
     * 
     * @hidden(macOS)
     * @brief Setting audio route failed because the audio route can not be changed in the current Audio Scenario.
     */
    ByteRTCMediaDeviceWarningSetAudioRouteInvalidScenario = 20,
    
    /**
     * 
     * @hidden(macOS)
     * @brief Setting audio route failed because the routing device did not exist.
     */
    ByteRTCMediaDeviceWarningSetAudioRouteNotExists = 21,
    
    /**
     * 
     * @hidden(macOS)
     * @brief Setting audio route failed because the audio route was occupied by the system or the other Apps.
     */
    ByteRTCMediaDeviceWarningSetAudioRouteFailedByPriority = 22,
    
    /**
     * 
     * @hidden(macOS)
     * @brief Setting audio route failed because the audio route can only be changed in ByteRTCAudioScenarioCommunication mode.
     */
    ByteRTCMediaDeviceWarningSetAudioRouteNotVoipMode = 23,
    
    /**
     * 
     * @hidden(macOS)
     * @brief Setting audio route failed because the audio route did not initiate.
     */
    ByteRTCMediaDeviceWarningSetAudioRouteDeviceNotStart = 24,
    
    /**
     * 
     * @hidden(macOS)
     * @brief The media volume is not set in all scenarios. You cannot change the Bluetooth profile until you set the media volume in all scenarios.
     */
    ByteRTCMediaDeviceWarningSetBluetoothModeScenarioUnsupport = 25,
    
     /**
     * 
     * @hidden(macOS)
     * @brief You cannot change the Bluetooth profile to HFP.
     */
    ByteRTCMediaDeviceWarningSetBluetoothModeUnsupport = 26
};


/**
 * 
 *  @type keytype
 *  @brief  Audio & video quality feedback problem type
 */
typedef NS_OPTIONS(uint64_t, ByteRTCProblemFeedbackOption) {
    
    /**
     * 
     * @brief No problem
     */
    ByteRTCProblemFeedbackOptionNone = 0,
    
    /**
     * 
     * @brief Other issues
     */
    ByteRTCProblemFeedbackOptionOtherMessage = (1ULL << 0),
    
    /**
     * 
     * @brief Connection failed
     */
    ByteRTCProblemFeedbackOptionDisconnected = (1ULL << 1),
    
    /**
     * 
     * @brief High latency for the ear monitor
     */
    ByteRTCProblemFeedbackOptionEarBackDelay = (1ULL << 2),
    
    /**
     * 
     * @brief Noise on the local end
     */
    ByteRTCProblemFeedbackOptionLocalNoise = (1ULL << 10),
    
    /**
     * 
     * @brief Audio stall on the local end
     */
    ByteRTCProblemFeedbackOptionLocalAudioLagging = (1ULL << 11),
    
    /**
     * 
     * @brief No sound on the local end
     */
    ByteRTCProblemFeedbackOptionLocalNoAudio = (1ULL << 12),
    
    /**
     * 
     * @brief Too little/loud sound on the local end
     */
    ByteRTCProblemFeedbackOptionLocalAudioStrength = (1ULL << 13),
    
    /**
     * 
     * @brief Echo noise on the local end
     */
    ByteRTCProblemFeedbackOptionLocalEcho = (1ULL << 14),
    
    /**
     * 
     * @brief Unclear video on the local end
     */
    ByteRTCProblemFeedbackOptionLocalVideoFuzzy = (1ULL << 24),
    
    /**
     * 
     * @brief Audio & video out of sync on the local end
     */
    ByteRTCProblemFeedbackOptionLocalNotSync = (1ULL << 25),
    
    /**
     * 
     * @brief Video stall on the local end
     */
    ByteRTCProblemFeedbackOptionLocalVideoLagging = (1ULL << 26),
    
    /**
     * 
     * @brief No picture on the local end
     */
    ByteRTCProblemFeedbackOptionLocalNoVideo = (1ULL << 27),
    
    /**
     * 
     * @brief Noise on the remote end
     */
    ByteRTCProblemFeedbackOptionRemoteNoise = (1ULL << 37),
    
    /**
     * 
     * @brief Audio stall on the remote end
     */
    ByteRTCProblemFeedbackOptionRemoteAudioLagging = (1ULL << 38),
    
    /**
     * 
     * @brief No sound on the remote end
     */
    ByteRTCProblemFeedbackOptionRemoteNoAudio = (1ULL << 39),
    
    /**
     * 
     * @brief Too little/loud sound on the remote end
     */
    ByteRTCProblemFeedbackOptionRemoteAudioStrength = (1ULL << 40),
    
    /**
     * 
     * @brief Echo noise on the remote end
     */
    ByteRTCProblemFeedbackOptionRemoteEcho = (1ULL << 41),
    
    /**
     * 
     * @brief Unclear video on the remote end
     */
    ByteRTCProblemFeedbackOptionRemoteVideoFuzzy = (1ULL << 51),
    
    /**
     * 
     * @brief Audio & video out of sync on the remote end
     */
    ByteRTCProblemFeedbackOptionRemoteNotSync = (1ULL << 52),
    
    /**
     * 
     * @brief Video stall on the remote end
     */
    ByteRTCProblemFeedbackOptionRemoteVideoLagging = (1ULL << 53),
    
    /**
     * 
     * @brief No picture on the remote end
     */
    ByteRTCProblemFeedbackOptionRemoteNoVideo = (1ULL << 54)
};


/**
 * 
 * @type keytype
 * @brief Video call quality feedback preset room infomation.
 */
BYTERTC_APPLE_EXPORT  @interface ByteRTCProblemFeedbackRoomInfo: NSObject
    
    /**
     * 
     * @brief Room ID.
     */
    @property(nonatomic, copy) NSString * _Nonnull roomId;

    
    /**
     * 
     * @brief User ID.
     */
    @property(nonatomic, copy) NSString * _Nonnull userId;
@end


/**
 * 
 * @type keytype
 * @brief Video call quality feedback preset infomation.
 */
BYTERTC_APPLE_EXPORT  @interface ByteRTCProblemFeedbackInfo: NSObject
    
    /**
     * 
     * @brief Text description corresponding to the feedback.
     */
    @property(nonatomic, copy) NSString * _Nonnull problemDesc;

    
    /**
     * 
     * @brief Text description corresponding to the feedback room information. See ByteRTCProblemFeedbackRoomInfo{@link #ByteRTCProblemFeedbackRoomInfo}.
     */
    @property(nonatomic, strong) NSArray<ByteRTCProblemFeedbackRoomInfo *> * _Nullable roomInfo;

@end


/**
 * 
 * @type keytype
 * @brief  First frame sending status
 */
typedef NS_ENUM(NSUInteger, ByteRTCFirstFrameSendState) {
    
    /**
     * 
     * @brief Sending
     */
    ByteRTCFirstFrameSendStateSending = 0,
    
    /**
     * 
     * @brief Sent successfully
     */
    ByteRTCFirstFrameSendStateSent = 1,
    
    /**
     * 
     * @brief Send failed
     */
    ByteRTCFirstFrameSendStateEnd = 2,
};


/**
 * 
 * @type keytype
 * @brief  First frame playback status
 */
typedef NS_ENUM(NSUInteger, ByteRTCFirstFramePlayState) {
    
    /**
     * 
     * @brief Playing
     */
    ByteRTCFirstFramePlayStatePlaying = 0,
    
    /**
     * 
     * @brief Play success
     */
    ByteRTCFirstFramePlayStatePlay = 1,
    
    /**
     * 
     * @brief Play failed
     */
    ByteRTCFirstFramePlayStateEnd = 2,
};


/**
 * 
 * @type keytype
 * @brief  Custom encryption type
 */
typedef NS_OPTIONS(NSUInteger, ByteRTCEncryptType) {
    
    /**
     * 
     * @brief Built-in encryption is not used. Default value.
     */
    ByteRTCEncryptTypeNone = 0,
    
    /**
     * 
     * @brief AES-128-CBC  encryption algorithm
     */
    ByteRTCEncryptTypeAES128CBC = 1,
    
    /**
     * 
     * @brief AES-256-CBC  encryption algorithm
     */
    ByteRTCEncryptTypeAES256CBC = 2,
    
    /**
     * 
     * @brief AES-128-ECB  encryption algorithm
     */
    ByteRTCEncryptTypeAES128ECB = 3,
    
    /**
     * 
     * @brief AES-256-ECB  encryption algorithm
     */
    ByteRTCEncryptTypeAES256ECB = 4
};


/**
 * 
 * @type keytype
 * @brief Video encoding type
 */
typedef NS_ENUM(NSInteger, ByteRTCVideoCodecType) {
    
    /**
     * 
     * @brief Unknown type
     */
    ByteRTCVideoCodecTypeUnknown = 0,
    
    /**
     * 
     * @brief H.264 format
     */
    ByteRTCVideoCodecTypeH264 = 1,
    
    /**
     * 
     * @brief ByteVC1 format
     */
    ByteRTCVideoCodecTypeByteVC1 = 2,
};


/**
 * 
 * @hidden not available
 * @type keytype
 * @brief Super-resolution mode.
 */
typedef NS_ENUM(NSInteger, ByteRTCVideoSuperResolutionMode) {
    
    /**
     * 
     * @brief Turn off super-resolution mode.
     */
    ByteRTCVideoSuperResolutionModeOff = 0,
    
    /**
     * 
     * @brief Turn on super-resolution mode.
     */
    ByteRTCVideoSuperResolutionModeOn = 1,
};


/**
 * 
 * @hidden not available
 * @type keytype
 * @brief Video noise reduction mode.
 */
typedef NS_ENUM(NSInteger, ByteRTCVideoDenoiseMode) {
    
    /**
     * 
     * @brief Video noise reduction turned off.
     */
    ByteRTCVideoDenoiseModeOff = 0,
    
    /**
     * 
     * @brief Video noise reduction turned on. The algorithm is configured by ByteRTC..
     */
    ByteRTCVideoDenoiseModeAuto = 1,
};


/**
 * 
 * @type keytype
 * @brief  Transmission/Playback state of the media stream
 */
typedef NS_ENUM(NSInteger, ByteRTCMuteState) {
    
    /**
     * 
     * @brief Enable
     */
    ByteRTCMuteStateOff = 0,
    
    /**
     * 
     * @brief Disable
     */
    ByteRTCMuteStateOn = 1,
};


/**
 * 
 * @type keytype
 * @brief State of the black frame video stream
 */
typedef NS_ENUM(NSInteger,  ByteRTCSEIStreamEventType) {
    
    /**
     * 
     * @brief A black frame video stream is published from the remote user. <br>
     *        In a voice call, when the remote user calls sendSEIMessage:andMessage:andRepeatCount:andCountPerFrame:{@link #ByteRTCVideo#sendSEIMessage:andMessage:andRepeatCount:andCountPerFrame:} to send SEI data, SDK will automatically publish a black frame video stream, and trigger this callback.
     */
    ByteRTCSEIStreamEventTypeStreamAdd = 0,
    
     /**
     * 
     * @brief The black frame video stream is removed. The timing this callback will be triggered is as following: <br>
     *        - The remote user turns on their camera, switching from a voice call to a video call.
     *        - No SEI data is sent within 1min after the remote user calls sendSEIMessage:andMessage:andRepeatCount:andCountPerFrame:{@link #ByteRTCVideo#sendSEIMessage:andMessage:andRepeatCount:andCountPerFrame:}.
     *        - The black frame video stream stops when the remote user calls setVideoSourceType:WithStreamIndex:{@link #ByteRTCVideo#setVideoSourceType:WithStreamIndex:} to switch to custom video capture.
     */
    ByteRTCSEIStreamEventTypeStreamRemove = 1,
};


/**
 * 
 * @type keytype
 * @brief Stream type
 */
typedef NS_ENUM(NSInteger, ByteRTCStreamIndex) {
    
    /**
     * 
     * @brief  Mainstream, including: <br>
     *       - Video/audio captured by the the camera/microphone using internal capturing;
     *       - Video/audio captured by custom method.
     */
    ByteRTCStreamIndexMain = 0,
    
    /**
     * 
     * @brief Screen-sharing stream. Video/Audio streams for screen sharing.
     */
    ByteRTCStreamIndexScreen = 1,
    
    /**
     * 
     * @hidden for internal use only
     */
    ByteRTCStreamIndex3rd,
    
    /**
     * 
     * @hidden for internal use only
     */
    ByteRTCStreamIndex4th,
    
    /**
     * 
     * @hidden for internal use only
     */
    ByteRTCStreamIndex5th,
    
    /**
     * 
     * @hidden for internal use only
     */
    ByteRTCStreamIndex6th,
    
    /**
     * 
     * @hidden for internal use only
     */
    ByteRTCStreamIndex7th,
    
    /**
     * 
     * @hidden for internal use only
     */
    ByteRTCStreamIndexMax,
};


/**
 * 
 *  @valid since 3.56
 *  @type keytype
 *  @brief stream aggregation strategy
 */

typedef NS_ENUM(NSInteger, ByteRTCAggregationOption) {
    
    /**
     * 
     * @brief Stream Aggregation with the lowest resolution.(Default Strategy)
     */
    ByteRTCAggregationOptionMin = 0,
    
    /**
     * 
     * @brief Stream Aggregation with the highest resolution.
     */
    ByteRTCAggregationOptionMax = 1,
    
    /**
     * 
     * @brief Stream Aggregation according to the proportions, and when the proportions are the same, it takes the lowest resolution.
     */
    ByteRTCAggregationOptionMajority = 2
};


/**
 * 
 * @type keytype
 * @brief  Stream type for media stream information synchronization
 */
typedef NS_ENUM(NSInteger, ByteRTCSyncInfoStreamType) {
    
    /**
     * 
     * @brief Audio stream
     */
    ByteRTCSyncInfoStreamTypeAudio = 0
};


/**
 * 
 * @type keytype
 * @brief ColorSpace
 */
typedef NS_ENUM(NSInteger, ByteRTCColorSpace) {
    
    /**
     *  <br>
     * Unknown color space, default kColorSpaceYCbCrBT601LimitedRange color space
     */
    ByteRTCColorSpaceUnknown = 0,
    
    /**
     * 
     * @brief BT.601 Digital Coding Standard, Color Space [16-235]
     */
    ByteRTCColorSpaceYCbCrBT601LimitedRange = 1,
    
    /**
     * 
     *  @brief BT.601 Digital Coding Standard, Color Space [0-255]
     */
    ByteRTCColorSpaceYCbCrBT601FullRange = 2,
    
    /**
     * 
     * @brief BT.7091 Digital Coding Standard, Color Space [16-235]
     */
    ByteRTCColorSpaceYCbCrBT709LimitedRange = 3,
    
    /**
     * 
     * @brief BT.7091 Digital Coding Standard, Color Space [0-255]
     */
    ByteRTCColorSpaceYCbCrBT709FullRange = 4
};


/**
 * 
 * @type keytype
 * @brief The state of the relaying for each room
 */
typedef NS_ENUM(NSInteger, ByteRTCForwardStreamState) {
    
    /**
     * 
     * @brief Idle <br>
     *        - States of all the rooms turns to idle after you call `stopForwardStreamToRooms`.
     *        - States of the rooms turns to idle that you call `updateForwardStreamToRooms` to remove.
     */
    ByteRTCForwardStreamStateIdle = 0,
    
    /**
     * 
     * @brief Start relaying. <br>
     *        - State of the rooms turn to this state after the relaying starts successfully by calling `startForwardStreamToRooms`.
     *        - State of the rooms added by calling `updateForwardStreamToRooms` turn to this state after the relaying start successfully.
     */
    ByteRTCForwardStreamStateSuccess = 1,
    
    /**
     * 
     * @brief Relay fails. Refer to ByteRTCForwardStreamError{@link #ByteRTCForwardStreamError} for more information for more information. <br>
     *        Once the relaying fails, state of the room turns to this state after calling `startForwardStreamToRooms` or `updateForwardStreamToRooms`.
     */
    ByteRTCForwardStreamStateFailure = 2,
};


/**
 * 
 * @type keytype
 * @brief Error codes during the relaying
 */
typedef NS_ENUM(NSInteger, ByteRTCForwardStreamError) {
    
    /**
     * 
     * @brief Normal
     */
    ByteRTCForwardStreamErrorOK = 0,
    
    /**
     * 
     * @brief Invalid argument
     */
    ByteRTCForwardStreamErrorInvalidArgument = 1201,
    
    /**
     * 
     * @brief Invalid token
     */
    ByteRTCForwardStreamErrorInvalidToken = 1202,
    
    /**
     * 
     * @brief Error returning from server
     */
    ByteRTCForwardStreamErrorResponse = 1203,
    
    /**
     * 
     * @brief Relaying aborts for the reason of that a User with the same user ID as that of the publisher joins.
     */
    ByteRTCForwardStreamErrorRemoteKicked = 1204,
    
    /**
     * 
     * @brief Server denies.
     */
    ByteRTCForwardStreamErrorNotSupport = 1205,
};


/**
 * 
 * @type keytype
 * @brief Events during the relaying
 */
typedef NS_ENUM(NSInteger, ByteRTCForwardStreamEvent) {
    
    /**
     * 
     * @brief Relaying pauses for the reason of network disconnecting.
     */
    ByteRTCForwardStreamEventDisconnected = 0,
    
    /**
     * 
     * @brief Relaying recovers from the disconnecting.
     */
    ByteRTCForwardStreamEventConnected = 1,
    
    /**
     * 
     * @brief Relaying aborts for the reason of that a User with the same user ID as that of the publisher joins.
     */
    ByteRTCForwardStreamEventInterrupt = 2,
    
    /**
     * 
     * @brief designated room list updates after you call `updateForwardStreamToRooms`.
     */
    ByteRTCForwardStreamEventDstRoomUpdated = 3,
    
    /**
     * 
     * @brief Wrong API-calling order. For example, call `updateForwardStreamToRooms` before calling `startForwardStreamToRooms`.
     */
    ByteRTCForwardStreamEventUnExpectAPICall = 4,
};


/**
 * 
 * @type keytype
 * @brief  Status of local recording
 */
typedef NS_ENUM(NSInteger, ByteRTCRecordingState) {
    
    /**
     * 
     * @brief Recording exception
     */
    ByteRTCRecordingStateError = 0,
    
    /**
     * 
     * @brief Recording in progress
     */
    ByteRTCRecordingStateProcessing = 1,
    
    /**
     * 
     * @brief If the recording file is saved successfully, call `stopFileRecording:` to end the recording before receiving the status code.
     */
    ByteRTCRecordingStateSuccess = 2,
};


/**
 * 
 * @type keytype
 * @brief  Local recording error code
 */
typedef NS_ENUM(NSInteger, ByteRTCRecordingErrorCode) {
    
    /**
     * 
     * @brief Recording normal
     */
    ByteRTCRecordingErrorCodeOk = 0,
    
    /**
     * 
     * @brief No file write permissions
     */
    ByteRTCRecordingErrorCodeNoPermission = -1,
    
    /**
     * 
     * @brief The current version SDK does not support local recording, please contact technical support
     */
    ByteRTCRecordingErrorCodeNotSupport = -2,
    
    /**
     * 
     * @brief Other anomalies
     */
    ByteRTCRecordingErrorCodeOther = -3,
};


/**
 * 
 * @type keytype
 * @brief  Storage format of locally recorded files
 */
typedef NS_ENUM(NSInteger, ByteRTCRecordingFileType) {
    
    /**
     * 
     * @brief Aac  format file
     */
    ByteRTCRecordingFileTypeAAC = 0,
    
    /**
     * 
     * @brief Mp4  format file
     */
    ByteRTCRecordingFileTypeMP4 = 1,
};


/**
 * 
 * @type keytype
 * @brief A/V synchronization states
 */
typedef NS_ENUM(NSInteger, ByteRTCAVSyncState) {
    
    /**
     * 
     * @brief A/V synchronization begins.
     */
    ByteRTCAVSyncStateAVStreamSyncBegin = 0,
    
    /**
     * 
     * @brief The publisher stops publishing audio stream during the synchronization, which does not affect the sync relationship.
     */
    ByteRTCAVSyncStateAudioStreamRemove = 1,
    
    /**
     * 
     * @brief The publisher stops publishing audio stream during the synchronization, which does not affect the sync relationship.
     */
    ByteRTCAVSyncStateVideoStreamRemove = 2,
    
    /**
     * 
     * @hidden for internal use only
     * @brief subscriber settings synchronization
     */
    ByteRTCAVSyncStateSetAVSyncStreamId = 3,
};

typedef NS_ENUM(NSInteger, ByteRTCAVSyncEvent) {
    ByteRTCAVSyncEventInvalidAudioSyncUidRepeated = 0,
};

/**
 * 
 * @type keytype
 * @brief Call test result
 */
typedef NS_ENUM(NSInteger, ByteRTCEchoTestResult) {
    
    /**
     * 
     * @brief The playback of captured audio/video is received, test succeeds.
     */
    ByteRTCEchoTestResultSuccess = 0,
    
    /**
     * 
     * @brief Test is not completed after 60 seconds and has been stopped automatically.
     */
    ByteRTCEchoTestResultTimeout = 1,
    
    /**
     * 
     * @brief Less than 5s between the end of the last test and the start of the next test.
     */
    ByteRTCEchoTestResultIntervalShort = 2,
    
    /**
     * 
     * @brief Audio capture error
     */
    ByteRTCEchoTestResultAudioDeviceError = 3,
    
    /**
     * 
     * @brief Video capture error
     */
    ByteRTCEchoTestResultVideoDeviceError = 4,
    
    /**
     * 
     * @brief Audio reception error
     */
    ByteRTCEchoTestResultAudioReceiveError = 5,
    
    /**
     * 
     * @brief Video reception error
     */
    ByteRTCEchoTestResultVideoReceiveError = 6,
    
    /**
     * 
     * @brief Unrecoverable internal error
     */
    ByteRTCEchoTestResultInternalError = 7
};


/**
 * 
 * @hidden currently not available
 * @type errorcode
 * @brief State and errors for publishing or subscribing public streams
 */
typedef NS_ENUM(NSInteger, ByteRTCPublicStreamErrorCode) {
    
    /**
     * 
     * @brief Published or subscribed successfully.
     */
    ByteRTCPublicStreamErrorCodeSuccess = 0,
    
    /**
     * 
     * @brief Invalid parameter(s). Please revise the paramter(s) and retry.
     */
    ByteRTCPublicStreamErrorCodePushParamError = 1191,
    
    /**
     * 
     * @brief Error for the task at the server side. The server will retry upon the failure.
     */
    ByteRTCPublicStreamErrorCodePushStatusError = 1192,
    
    /**
     * 
     * @brief Unrecoverable error of publishing the public stream. Please start the task again.
     */
    ByteRTCPublicStreamErrorCodePushInternalError = 1193,
    
    /**
     * 
     * @brief Failed to publish. The SDK will retry upon the failure. We recommend to keep listening to the publishing result.
     */
    ByteRTCPublicStreamErrorCodePushError = 1195,
    
    /**
     * 
     * @brief Failed to publish the public stream for time-out error. The SDK will retry 10 s after the timeout. The maximum number of retry attempts is 3.
     */
    ByteRTCPublicStreamErrorCodePushTimeOut = 1196,
    
    /**
     * 
     * @brief Failed to play a public stream because the publisher has not started publishing.
     */
    ByteRTCPublicStreamErrorCodePullNoPushStream = 1300,
};

/**
 * 
 * @type keytype
 * @brief The Bluetooth profiles.
 */
typedef NS_ENUM(NSInteger, ByteRTCBluetoothMode) {
     
     /**
      * 
      * @brief The default mode： <br>
      * <table>
      * <tr>
      *   <th> Scenario </th>
      *   <th> HFP </th>
      *   <th> A2DP </th>
      * </tr>
      * <tr>
      *   <th> The in-call volume is set in all scenarios. </th>
      *   <th> HFP is supported by your Bluetooth device. </th>
      *   <th> HFP is not supported by your Bluetooth device. </th>
      * </tr>
      * <tr>
      *   <th> The media volume is set in all scenarios.</th>
      *   <th> Audio is captured and played by your Bluetooth device. </th>
      *   <th> Audio is captured by your iOS device and played by your Bluetooth device. </th>
      * </tr>
      * </table>
      */
     ByteRTCBluetoothModeAuto = 0,

     
     /**
      * 
      * @brief Advanced Audio Distribution Profile(A2DP). This profile defines how high-quality audio (stereo or mono) can be streamed from one device to another over a Bluetooth connection. Audio is captured by your iOS device and played by your Bluetooth device.
      */
     ByteRTCBluetoothModeA2DP = 1,

    
    /**
     * 
     * @brief Hands-Free Profile(HFP). This profile defines how voice-quality, mono audio can be streamed from one device to another. Audio is captured and played by your Bluetooth device.
     */
     ByteRTCBluetoothModeHFP = 2
};

/**
 * 
 * @type keytype
 * @brief Video/audio call test configurations
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCEchoTestConfig : NSObject

/**
 * 
 * @brief View for rendering received video
 */
@property(strong, nonatomic) ByteRTCView* _Nullable view;

/**
 * 
 * @brief ID of the room that the tested user will join.
 */
@property(copy, nonatomic) NSString *_Nonnull roomId;

/**
 * 
 * @brief User ID for testing
 */
@property(copy, nonatomic) NSString *_Nonnull userId;

/**
 * 
 * @brief Token used for authenticating users when they enter the room.
 */
@property(copy, nonatomic) NSString *_Nonnull token;

/**
 * 
 * @brief Whether to test audio. The device to be tested is the default audio device. <br>
 *        - true: Yes
 *            - If you use internal capture, the device microphone will automatically turn on and `onLocalAudioPropertiesReport` will be triggered when the value of audioReportInterval is set to greater than 0, from which you can judge the working status of the microphone.
 *            - If you choose custom capture, you also need to call pushExternalAudioFrame:{@link #ByteRTCVideo#pushExternalAudioFrame:} to push the captured audio to the SDK.
 *        - false: No
 */
@property(assign, nonatomic) BOOL enableAudio;

/**
 * 
 * @brief Whether to test video. If you are using a desktop PC, the device to be tested is by default the first video device in the list. <br>
 *        - true: Yes
 *            - If you use internal capture, the device camera will automatically turn on.
 *            - If you choose custom capture, you also need to call pushExternalVideoFrame:{@link #ByteRTCVideo#pushExternalVideoFrame:} to push the captured video to the SDK.
 *        - false: No
 *        The video is published with fixed parameters: resolution 640px × 360px, frame rate 15fps.
 */
@property(assign, nonatomic) BOOL enableVideo;

/**
 * 
 * @brief Volume prompt interval in ms, the default value is 100. <br>
 *        - `<= 0`: Turn off prompt
 *        - `(0,100]` Invalid interval value, and will be automatically reset to 100ms.
 *        - `> 100`: the actual value of interval
 */
@property(assign, nonatomic) NSInteger audioReportInterval;
@end


/**
 * 
 * @type keytype
 * @brief  User information.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCUserInfo : NSObject

/**
 * 
 * @brief User ID. The string matches the regular expression: `[a-zA-Z0-9_@\-\.]{1,128}`.
 */
@property(copy, nonatomic) NSString *_Nonnull userId;

 /**
  * 
  * @brief Additional information of the user. The string is no more than 200 bytes. <br>
  *        The remote users will receive the info with `rtcEngine:onUserJoined:elapsed:`.
  */
@property(copy, nonatomic) NSString *_Nonnull extraInfo;
@end


/**
 * 
 * @type keytype
 * @brief Room call statistics, reference period is 2s. <br>
 *        After the user enters the room successfully, the SDK will periodically notify the user through `onRoomStats` callback statistics in the current room. This data structure is the type of parameter that is called back to the user.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCRoomStats : NSObject

/**
 * 
 * @brief The total time after the user enters the room and starts the call, in s, the cumulative value
 */
@property(assign, nonatomic) NSInteger duration;

/**
 * 
 * @brief The total number of bytes sent by the local user  (bytes), the cumulative value
 */
@property(assign, nonatomic) NSInteger txBytes;

/**
 * 
 * @brief The total number of bytes received by the local user  (bytes), the cumulative value
 */
@property(assign, nonatomic) NSInteger rxBytes;

/**
 * 
 * @brief The instantaneous value of Tx bitrate in kbps
 */
@property(assign, nonatomic) NSInteger txKbitrate;

/**
 * 
 * @brief The instantaneous value of Rx bitrate in kbps
 */
@property(assign, nonatomic) NSInteger rxKbitrate;

/**
 * 
 * @brief Local user's audio transmission bit rate  (kbps), instantaneous value
 */
@property(assign, nonatomic) NSInteger txAudioKBitrate;

/**
 * 
 * @brief Local user's audio receiving bit rate  (kbps), instantaneous value
 */
@property(assign, nonatomic) NSInteger rxAudioKBitrate;

/**
 * 
 * @brief Local user's video transmission bit rate  (kbps), instantaneous value
 */
@property(assign, nonatomic) NSInteger txVideoKBitrate;

/**
 * 
 * @brief Local user's video receiving bit rate  (kbps), instantaneous value
 */
@property(assign, nonatomic) NSInteger rxVideoKBitrate;

/**
 * 
 * @brief The instantaneous RX bitrate of screen-sharing video in Kbps
 */
@property(assign, nonatomic) NSInteger txScreenKBitrate;

/**
 * 
 * @brief The instantaneous TX bitrate of screen-sharing video in Kbps
 */
@property(assign, nonatomic) NSInteger rxScreenKBitrate;

/**
 * 
 * @brief Number of visible users in the current room, including local users themselves
 */
@property(assign, nonatomic) NSInteger userCount;

/**
 * 
 * @brief App  Current downlink packet loss rate
 */
@property(assign, nonatomic) float rxLostrate;

/**
 * 
 * @brief App  current uplink packet loss rate
 */
@property(assign, nonatomic) float txLostrate;

/**
 * 
 * @brief Client side round-trip time
 */
@property(assign, nonatomic) NSInteger rtt;

/**
 * 
 * @brief Current App CPU usage
 */


/**
 * 
 * @brief Total CPU usage of the current device
 */



/**
 * 
 * @hidden currently not available
 * @brief The system downlink network jitter(ms)
 */
@property(assign, nonatomic) NSInteger txJitter;

/**
 * 
 * @hidden currently not available
 * @brief The system downlink network jitter(ms)
 */
@property(assign, nonatomic) NSInteger rxJitter;

/**
 * 
 * @brief Cellular Link Send bit rate  (kbps), get the instantaneous value of the data
 */
@property(assign, nonatomic) NSInteger txCellularKBitrate;

/**
 * 
 * @brief Cellular Link Receive bit rate  (kbps), get the instantaneous value of the data
 */
@property(assign, nonatomic) NSInteger rxCellularKBitrate;
@end


/**
 * 
 * @type keytype
 * @brief Local video stream statistics, reference period 2s. <br>
 *        After the local user publishes the video stream successfully, the SDK will periodically notify the local user through `onLocalStreamStats` <br>
 *        The delivery status of the published video stream during this reference period. This data structure is the type of parameter that is called back to the local user.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCLocalVideoStats : NSObject

/**
 * 
 * @brief TX bitrate in Kbps of the video stream with the highest resolution within the reference period
 */
@property(assign, nonatomic) float sentKBitrate;

/**
 * 
 * @brief Sampling frame rate in fps of video capture during this reference period
 */
@property(assign, nonatomic) NSInteger inputFrameRate;

/**
 * 
 * @brief TX frame rate in fps of the video stream with the highest resolution within the reference period
 */
@property(assign, nonatomic) NSInteger sentFrameRate;

/**
 * 
 * @brief Encoder-output frame rate in fps of the video stream with the highest resolution within the reference period
 */
@property(assign, nonatomic) NSInteger encoderOutputFrameRate;

/**
 * 
 * @brief Local-rendering frame rate in fps during this reference period
 */
@property(assign, nonatomic) NSInteger rendererOutputFrameRate;

/**
 * 
 * @brief Reference period in ms. <br>
 *        This field is used to set the reference period for the callback, which is 2 s by default.
 */
@property(assign, nonatomic) NSInteger statsInterval;

/**
 * 
 * @brief Video packet loss rate. The video uplink packet loss rate in the reference period, the value range is  [0,1].
 */
@property(assign, nonatomic) float videoLossRate;

/**
 * 
 * @brief Round-trip time. The unit is ms.
 */
@property(assign, nonatomic) NSInteger rtt;

/**
 * 
 * @brief Video encoding bitrate in Kbps of the video stream with the highest resolution within the reference period.
 */
@property(assign, nonatomic) NSInteger encodedBitrate;

/**
 * 
 * @brief Video encoding width in px of the video stream with the highest resolution within the reference period
 */
@property(assign, nonatomic) NSInteger encodedFrameWidth;

/**
 * 
 * @brief Video encoding height in px of the video stream with the highest resolution within the reference period
 */
@property(assign, nonatomic) NSInteger encodedFrameHeight;

/**
 * 
 * @brief The total number of the video stream with the highest resolution within the reference period sent in the reference period.
 */
@property(assign, nonatomic) NSInteger encodedFrameCount;

/**
 * 
 * @brief Encoding type. See ByteRTCVideoCodecType{@link #ByteRTCVideoCodecType} type.
 */
@property(nonatomic) ByteRTCVideoCodecType codecType;

/**
 * 
 * @brief Whether the media stream belongs to the user is a screen stream. You can know whether the current statistics come from mainstream or screen stream.
 */
@property(assign, nonatomic) BOOL isScreen;

/**
 * 
 * @brief Video uplink network jitter in ms.
 */
@property(assign, nonatomic) NSInteger jitter;

/**
 * 
 * @hidden(macOS)
 * @brief Video noise reduction mode. Refer to ByteRTCVideoDenoiseMode{@link #ByteRTCVideoDenoiseMode} for more details.
 */
@property(assign, nonatomic) ByteRTCVideoDenoiseMode videoDenoiseMode;
@end


/**
 * 
 * @type keytype
 * @brief Remote video stream statistics, reference period 2s. <br>
 *         After the remote user subscribes to the remote video stream successfully, the SDK will periodically notify the remote user of the reception status of the subscribed remote video stream during this reference period through `onRemoteStreamStats` <br>
 *        . This data structure is the type of parameter that is called back to the local user.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCRemoteVideoStats : NSObject

/**
 * 
 * @brief Distal video width.
 */
@property(assign, nonatomic) NSInteger width;

/**
 * 
 * @brief Remote video height.
 */
@property(assign, nonatomic) NSInteger height;

/**
 * 
 * @brief Remote video packet loss rate. The video downlink packet loss rate in the reference period, the value range is  [0,1].
 */
@property(assign, nonatomic) float videoLossRate;

/**
 * 
 * @brief Receiving bit rate. Video reception rate within the reference period, in kbps.
 */
@property(assign, nonatomic) float receivedKBitrate;

/**
 * 
 * @brief Remote video receiving frame rate.
 */
@property(assign, nonatomic) NSInteger receivedFrameRate;

/**
 * 
 * @brief Remote video decoding output frame rate.
 */
@property(assign, nonatomic) NSInteger decoderOutputFrameRate;

/**
 * 
 * @brief Remote video rendering output frame rate.
 */
@property(assign, nonatomic) NSInteger renderOutputFrameRate;

/**
 * 
 * @brief The number of remote video cards.
 */
@property(assign, nonatomic) NSInteger stallCount;

/**
 * 
 * @brief Distal video lag duration, in ms.
 */
@property(assign, nonatomic) NSInteger stallDuration;

/**
 * 
 * @brief End-to-end latency at the user experience level. The delay from the completion of encoding at the transmitting end to the completion of decoding at the receiving end, in units of ms.
 */
@property(assign, nonatomic) NSInteger e2eDelay;

/**
 * 
 * @brief Whether the remote video stream is a screen share stream. You can know whether the current data comes from mainstream or screen stream.
 */
@property(assign, nonatomic) BOOL isScreen;

/**
 * 
 * @brief Statistical interval, the interval of this reference period, in ms. <br>
 *        This field is used to set the reference period for the callback, currently set to 2s.
 */
@property(assign, nonatomic) NSInteger statsInterval;

/**
 * 
 * @brief Round-trip time. The unit is ms.
 */
@property(assign, nonatomic) NSInteger rtt;

/**
 * 
 * @brief The cumulative duration of the video card of the remote user accounts for the percentage (%) of the total effective duration of the video after entering the room. The effective duration of the video refers to the duration of the video other than stopping sending the video stream and disabling the video module after the remote user enters the room to publish the video stream.
 */
@property(assign, nonatomic) NSInteger frozenRate;

/**
 * 
 * @brief For the encoding type of the video, please refer to ByteRTCVideoCodecType{@link #ByteRTCVideoCodecType}.
 */
@property(nonatomic) ByteRTCVideoCodecType codecType;

/**
 * 
 * @brief The resolution subscript of the SDK  subscribed remote video stream.
 */
@property(assign, nonatomic) NSInteger videoIndex;

/**
 * 
 * @brief Video downlink network jitter in ms.
 */
@property(assign, nonatomic) NSInteger jitter;

/**
 * 
 * @hidden(macOS)
 * @brief Super-resolution mode. See ByteRTCVideoSuperResolutionMode{@link #ByteRTCVideoSuperResolutionMode}.
 */
@property(assign, nonatomic) ByteRTCVideoSuperResolutionMode superResolutionMode;

/**
 * 
 * @brief End-to-end latency at the user experience level. The delay from the start of capturing at the sending end to the completion of rendering at the receiving end, in units of ms.
 */
@property(assign, nonatomic) NSInteger capToRenderDelay;

/**
 * 
 * @brief Audio/video synchronization diff in ms.
 */
@property(assign, nonatomic) NSInteger avSyncDiffMs;

/**
 * 
 * @brief Average time spent on video decoding in ms.
 */
@property(assign, nonatomic) NSInteger codecElapsePerFrame;

/**
 * 
 * @brief Whether the video stream is muted.
 */
@property(assign, nonatomic) BOOL isMuted;
@end


/**
 * 
 * @type keytype
 * @brief Local audio stream statistics, reference period 2s. <br>
 *        After the local user publishes the audio stream successfully, the SDK will periodically notify the local user through `onLocalStreamStats` <br>
 *        The sending status of the published audio stream during this reference period. This data structure is the type of parameter that is called back to the local user.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCLocalAudioStats : NSObject

/**
 * 
 * @brief Audio packet loss rate. The audio uplink packet loss rate in this reference period is in the range of  [0,1].
 */
@property(assign, nonatomic) float audioLossRate;

/**
 * 
 * @brief The bit rate of transmission. The audio transmission rate in the reference period is kbps.
 */
@property(assign, nonatomic) float sentKBitrate;

/**
 * 
 * @brief Acquisition sampling rate. Audio sampling rate information collected in the reference period, in units of Hz.
 */
@property(assign, nonatomic) NSInteger recordSampleRate;

/**
 * 
 * @brief Statistical interval. The interval of this reference period is in ms. <br>
 *        This field is used to set the reference period for the callback. The default setting is 2s.
 */
@property(assign, nonatomic) NSInteger statsInterval;

/**
 * 
 * @brief Round-trip time. The unit is ms.
 */
@property(assign, nonatomic) NSInteger rtt;

/**
 * 
 * @brief Number of audio channels.
 */
@property(assign, nonatomic) NSInteger numChannels;

/**
 * 
 * @brief Audio transmission sampling rate. Audio transmission sampling rate information in the reference period, in Hz.
 */
@property(assign, nonatomic) NSInteger sentSampleRate;

/**
 * 
 * @brief Audio uplink network jitter in ms.
 */
@property(assign, nonatomic) NSInteger jitter;

/** 
 * 
 * @brief Audio encode frame rate.
 */
@property(assign, nonatomic) double encodeFrameRate;

/**
 * 
 * @brief Whether the audio stream is muted.
 */
@property(assign, nonatomic) BOOL isMuted;

@end


/**
 * 
 * @type keytype
 * @brief Remote audio stream statistics, reference period 2s. <br>
 *         After the remote audio stream subscription is successful, the SDK will periodically notify the local user of the reception status of the subscribed audio stream during this reference period through `onRemoteStreamStats` <br>
 *        . This data structure is the type of parameter that is called back to the local user.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCRemoteAudioStats : NSObject

/**
 * 
 * @brief Audio packet loss rate. The audio downlink packet loss rate in the reference period, the value range is  [0,1].
 */
@property(assign, nonatomic) float audioLossRate;

/**
 * 
 * @brief Receiving bit rate. The audio reception rate in the reference period in kbps.
 */
@property(assign, nonatomic) float receivedKBitrate;

/**
 * 
 * @brief Number of audio cards. Number of cards in the reference period.
 */
@property(assign, nonatomic) NSInteger stallCount;

/**
 * 
 * @brief Audio Catton Duration. Catton duration in the reference period in ms.
 */
@property(assign, nonatomic) NSInteger stallDuration;

/**
 * 
 * @brief Play sample rate. Audio playback sample rate information within the reference period in Hz.
 */
@property(assign, nonatomic) NSInteger playoutSampleRate;

/**
 * 
 * @brief End-to-end latency at the user experience level. The delay from the completion of encoding at the transmitting end to the completion of decoding at the receiving end, in units of ms.
 */
@property(assign, nonatomic) NSInteger e2eDelay;

/**
 * 
 * @brief Statistical interval. The interval of this reference period is in ms.
 */
@property(assign, nonatomic) NSInteger statsInterval;

/**
 * 
 * @brief Round-trip time for client side to server level data transfer in ms.
 */
@property(assign, nonatomic) NSInteger rtt;

/**
 * 
 * @brief The sender-server level-the receiver-link data transmission round-trip time. The unit is ms.
 */
@property(assign, nonatomic) NSInteger totalRtt;

/**
 * 
 * @brief The quality of the audio stream sent by the remote user. Value meaning reference ByteRTCNetworkQuality{@link #ByteRTCNetworkQuality}.
 */
@property(assign, nonatomic) NSInteger quality;

/**
 * 
 * @brief The delay caused by the introduction of the jitter buffer mechanism. The unit is ms.
 */
@property(assign, nonatomic) NSInteger jitterBufferDelay;

/**
 * 
 * @brief Number of audio channels.
 */
@property(assign, nonatomic) NSInteger numChannels;

/**
 * 
 * @brief Audio reception sampling rate. Remote audio sample rate information received within the reference period, in Hz.
 */
@property(assign, nonatomic) NSInteger receivedSampleRate;

/**
 * 
 * @brief The accumulated length of the audio card occurs after the remote user joins the room as a percentage of the total effective length of the audio. The effective duration of audio refers to the duration of audio other than stopping sending audio streams and disabling audio modules after remote users enter the room to publish audio streams.
 */
@property(assign, nonatomic) NSInteger frozenRate;

/**
 * 
 * @brief Audio PLC Total number of sample points.
 */
@property(assign, nonatomic) NSInteger concealedSamples;

/**
 * 
 * @brief PLC  cumulative times.
 */
@property(assign, nonatomic) NSInteger concealmentEvent;

/**
 * 
 * @brief Audio decoding sample rate. Audio decoding sample rate information in the reference period in Hz.
 */
@property(assign, nonatomic) NSInteger decSampleRate;

/**
 * 
 * @brief Cumulative decoding time in seconds of the remote audio stream in this subscription.
 */
@property(assign, nonatomic) NSInteger decDuration;

/**
 * 
 * @brief Video downlink network jitter in ms.
 */
@property(assign, nonatomic) NSInteger jitter;

/**
 * 
 * @brief Audio decode frame rate.
 */
@property(assign, nonatomic) double decodeFrameRate;

/**
 * 
 * @brief Whether the audio stream is muted.
 */
@property(assign, nonatomic) BOOL isMuted;
@end


/**
 * 
 * @type keytype
 * @brief Local audio/video stream statistics and network status, the reference period is 2s. <br>
 *        After the local user publishes the audio/video stream successfully, the SDK will periodically notify the local user through `onLocalStreamStats` <br>
 *        The transmission status of the published audio/video stream during this reference period. This data structure is the type of parameter that is called back to the user.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCLocalStreamStats : NSObject

/**
 * 
 * @brief For statistics on audio streams sent by local devices. See ByteRTCLocalAudioStats{@link #ByteRTCLocalAudioStats}
 */
@property(strong, nonatomic) ByteRTCLocalAudioStats *_Nonnull audioStats;

/**
 * 
 * @brief For statistics on video streams sent by local devices. See ByteRTCLocalVideoStats{@link #ByteRTCLocalVideoStats}
 */
@property(strong, nonatomic) ByteRTCLocalVideoStats *_Nonnull videoStats;

/**
 * 
 * @brief For the uplink network quality of the media stream of the user you belong to. See ByteRTCNetworkQuality{@link #ByteRTCNetworkQuality}
 * @deprecated since 3.45 and will be deleted in 3.51, use rtcRoom:onNetworkQuality:remoteQualities:{@link #ByteRTCRoomDelegate#rtcRoom:onNetworkQuality:remoteQualities:} instead
 */
@property(assign, nonatomic) ByteRTCNetworkQuality txQuality;

/**
 * 
 * @brief The downlink network quality of the media stream belongs to the user. See ByteRTCNetworkQuality{@link #ByteRTCNetworkQuality}
 * @deprecated since 3.45 and will be deleted in 3.51, use rtcRoom:onNetworkQuality:remoteQualities:{@link #ByteRTCRoomDelegate#rtcRoom:onNetworkQuality:remoteQualities:} instead
 */
@property(assign, nonatomic) ByteRTCNetworkQuality rxQuality;

/**
 * 
 * @brief Whether the media stream belongs to the user is a screen stream. You can know whether the current statistics come from mainstream or screen stream.
 */
@property(nonatomic, assign) BOOL isScreen;
@end


/**
 * 
 * @type keytype
 * @brief The remote audio/video stream statistics and network status subscribed by the user, with a reference period of 2s. <br>
 *         After the remote user subscribed to successfully publish the audio/video stream, the SDK will periodically notify the remote user of the reception status of the subscribed audio/video stream during this reference period through `onRemoteStreamStats` <br>
 *        . This data structure is the type of parameter that is called back to the local user.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCRemoteStreamStats : NSObject

/**
 * 
 * @brief User ID. The user ID of the audio source.
 */
@property(copy, nonatomic) NSString *_Nonnull uid;

/**
 * 
 * @brief For statistics on remote audio streams. See ByteRTCRemoteAudioStats{@link #ByteRTCRemoteAudioStats}
 */
@property(strong, nonatomic) ByteRTCRemoteAudioStats *_Nonnull audioStats;

/**
 * 
 * @brief For statistics on remote video streams. See ByteRTCRemoteVideoStats{@link #ByteRTCRemoteVideoStats}
 */
@property(strong, nonatomic) ByteRTCRemoteVideoStats *_Nonnull videoStats;

/**
 * 
 * @hidden
 * @brief For the uplink network quality of the media stream of the user you belong to. See ByteRTCNetworkQuality{@link #ByteRTCNetworkQuality}
 * @deprecated since 3.45 and will be deleted in 3.51, use rtcRoom:onNetworkQuality:remoteQualities:{@link #ByteRTCRoomDelegate#rtcRoom:onNetworkQuality:remoteQualities:} instead
 */
@property(assign, nonatomic) ByteRTCNetworkQuality txQuality;

/**
 * 
 * @brief The downlink network quality of the media stream belongs to the user. See ByteRTCNetworkQuality{@link #ByteRTCNetworkQuality}
 * @deprecated since 3.45 and will be deleted in 3.51, use rtcRoom:onNetworkQuality:remoteQualities:{@link #ByteRTCRoomDelegate#rtcRoom:onNetworkQuality:remoteQualities:} instead
 */
@property(assign, nonatomic) ByteRTCNetworkQuality rxQuality;

/**
 * 
 * @brief Whether the media stream belongs to the user is a screen stream. You can know whether the current statistics come from mainstream or screen stream.
 */
@property(nonatomic, assign) BOOL isScreen;
@end


/**
 * 
 * @type keytype
 * @brief  User information
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCUser : NSObject

/**
 * 
 * @brief User ID
 */
@property(nonatomic, copy, nullable) NSString *userId;

/**
 * 
 * @brief Meta information
 */
@property(nonatomic, copy, nullable) NSString *metaData;
@end


/**
 * 
 * @type keytype
 * @brief Information about the remote stream
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCRemoteStreamKey : NSObject

/**
 * 
 * @brief The ID of the user who published the stream.
 */
@property(nonatomic, copy, nullable) NSString *userId;

/**
 * 
 * @brief The ID of the room from which the stream was published.
 */
@property(nonatomic, copy, nullable) NSString *roomId;

/**
 * 
 * @brief Stream type. See ByteRTCStreamIndex{@link #ByteRTCStreamIndex}
 */
@property(nonatomic, assign) ByteRTCStreamIndex streamIndex;
@end

#pragma mark - EncryptHandler

/**
 * 
 * @type callback
 * @region  encryption
 * @brief  Custom encryption interface <br>
 * Note: Callback functions are thrown synchronously in a non-UI thread within the SDK. Therefore, you must not perform any time-consuming operations or direct UI operations within the callback function, as this may cause the app to crash.
 */
@protocol ByteRTCEncryptHandler <NSObject>

@required

/**
 * 
 * @type api
 * @region Encryption
 * @brief Custom encryption. <br>
 *        Encrypts audio & video frame data before transmission using the custom encryption method set. <br>
 *        Encryption of the original audio and video frames is currently not available.
 * @param rawData Original audio & video frame data
 * @return Encrypted data <br>
 *         - Non-empty, indicating that the encrypted data
 *         - Is empty, indicating that the data has been discarded
 * @note
 *         - Before using this interface for custom encryption, you must first set the custom encryption method. See `setCustomizeEncryptHandler:`.
 *         - Use onDecryptData:{@link #ByteRTCEncryptHandler#onDecryptData:} to decrypt encrypted audio & video frame data.
 *         - The returned data size should be controlled within 90%~ 120% of the original data source, otherwise it will be discarded.
 */
- (NSData * _Nonnull) onEncryptData:(NSData * _Nonnull)rawData;

@required

/**
 * 
 * @type api
 * @region  encryption
 * @brief  Custom decryption. <br>
 *         Decrypts custom encrypted audio & video frame data. For custom encryption, see onEncryptData:{@link #ByteRTCEncryptHandler#onEncryptData:}.
 * @param rawData  Received encrypted audio & video frame data
 * @return  Decrypted data <br>
 *         - Non-empty, indicating that the decrypted data
 *         - Is empty, indicating that the frame is discarded
 * @note
 *         - Before using this interface to decrypt, you must first set the decryption method. See `setCustomizeEncryptHandler:`.
 *         - The returned data size should be controlled within 90%~ 120% of the original data source, otherwise it will be discarded.
 */
- (NSData * _Nonnull) onDecryptData:(NSData * _Nonnull)rawData;
@end

#pragma mark - FileRecording


/**
 * 
 * @type keytype
 * @brief  Local recording parameter configuration
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCRecordingConfig : NSObject

/**
 * 
 * @brief The absolute folder path to save the recording file.The filename will be generated by RTC. You need to ensure that you have read and write permissions to this path.
 */
@property(strong, nonatomic) NSString* _Nullable dirPath;

/**
 * 
 * @brief Record the stored file format. See ByteRTCRecordingFileType{@link #ByteRTCRecordingFileType}
 */
@property(assign, nonatomic) ByteRTCRecordingFileType recordingFileType;
@end


/**
 * 
 * @type keytype
 * @brief  Local recording progress
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCRecordingProgress : NSObject

/**
 * 
 * @brief The cumulative recording time of the current file, in milliseconds
 */
@property(assign, nonatomic) unsigned long long duration;

/**
 * 
 * @brief The size of the currently recorded file in bytes
 */
@property(assign, nonatomic) unsigned long long fileSize;
@end


/**
 * 
 * @type keytype
 * @brief  Details of local recording
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCRecordingInfo : NSObject

/**
 * 
 * @brief The absolute path of the recorded file, including the file name and file suffix
 */
@property(strong, nonatomic) NSString* _Nullable filePath;

/**
 * 
 * @brief For the video encoding type of the recorded file. See ByteRTCVideoCodecType{@link #ByteRTCVideoCodecType}
 */
@property(assign, nonatomic) ByteRTCVideoCodecType codecType;

/**
 * 
 * @brief The width of the recorded video, in pixels. Please ignore this field for audio-only recording
 */
@property(nonatomic, assign) NSInteger width;

/**
 * 
 * @brief The height of the recorded video, the unit: pixels. Please ignore this field for audio-only recording
 */
@property(nonatomic, assign) NSInteger height;
@end


/**
 * 
 * @type keytype
 * @brief  Configuration related to media stream information synchronization
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCStreamSycnInfoConfig : NSObject


/**
 * 
 * @brief Stream properties, mainstream or screen streams. See ByteRTCStreamIndex{@link #ByteRTCStreamIndex}.
 */
@property(assign, nonatomic) ByteRTCStreamIndex streamIndex;

/**
 * 
 * @brief The number of duplicates sent by the message, the value range is  [0,25], it is recommended to set it to [3,5].
 */
@property(assign, nonatomic) int repeatCount;

/**
 * 
 * @brief For the stream type for media stream information synchronization. See ByteRTCSyncInfoStreamType{@link #ByteRTCSyncInfoStreamType}.
 */
@property(assign, nonatomic) ByteRTCSyncInfoStreamType streamType;
@end


/**
 * 
 * @type keytype
 * @brief Information of the rooms where you want to relay the media stream to
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCForwardStreamConfiguration: NSObject
    
    /**
     * 
     * @brief ID of the room where the media stream aims to relay to
     */
@property(strong, nonatomic) NSString* _Nullable roomId;
    
    /**
     * 
     * @brief RoomId and UserId are required to generate the Token to forward media streams to the room. <br>
     *        During developing and testing, you can use temporary tokens generated on the console. At the production stage, Tokens are generated by the token generating application deployed on your server. <br>
     *        Forwarding will fail if the token is invalid.
     */
@property(strong, nonatomic) NSString* _Nullable token;
@end


/**
* 
* @type keytype
 * @brief State and error for each room during relaying
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCForwardStreamStateInfo: NSObject
    
    /**
     * 
     * @brief ID of the room where the media stream aims to relay to <br>
     *        An Empty string is for all rooms.
     */
@property(strong, nonatomic) NSString* _Nullable roomId;
    
    /**
     * 
     * @brief State of the room during relaying. Refer to ByteRTCForwardStreamState{@link #ByteRTCForwardStreamState} for more information.
     */
@property(assign, nonatomic) ByteRTCForwardStreamState state;
    
    /**
     * 
     * @brief Error code from the room during relaying. Refer to ByteRTCForwardStreamError{@link #ByteRTCForwardStreamError} for more information.
     */
@property(assign, nonatomic) ByteRTCForwardStreamError error;
@end


/**
 * 
 * @type keytype
 * @brief Event from each room during relaying
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCForwardStreamEventInfo: NSObject
    
    /**
     * 
     * @brief ID of the room where the media stream aims to relay to <br>
     *        An Empty string is for all rooms.
     */
@property(strong, nonatomic) NSString* _Nullable roomId;
    
    /**
     * 
     * @brief Event from the room during relaying. Refer to ByteRTCForwardStreamEvent{@link #ByteRTCForwardStreamEvent} for more information.
     */
@property(assign, nonatomic) ByteRTCForwardStreamEvent event;
@end


/**
 * 
 * @type keytype
 * @brief Tx/Rx network quality
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCNetworkQualityStats: NSObject

/**
 * 
 * @brief User ID
 */
@property(strong, nonatomic) NSString* _Nonnull uid;

/**
 * 
 * @brief Packet loss ratio of the local client, ranging [0.0,1.0] <br>
 *        For a local user, it is the sent-packet loss ratio. <br>
 *        For a remote user, it is the loss ratio of all the packets received.
 */
@property(assign, nonatomic) double lossRatio;

/**
 * 
 * @brief Round-trip time (RTT) from client to server. Effective for the local user. Unit: ms
 */
@property(assign, nonatomic) int rtt;

/**
 * 
 * @brief Average transmission rate of the media RTP packages in 2s. unit: bps <br>
 *        For a local user, it is the packet-sending speed. <br>
 *        For a more user, it is the speed of receiving all the subscribed medias.
 */
@property(assign, nonatomic) int totalBandwidth;

/**
 * 
 * @brief Tx network quality grade. Refer to ByteRTCNetworkQuality{@link #ByteRTCNetworkQuality} for details.
 */
@property(assign, nonatomic) ByteRTCNetworkQuality txQuality;

/**
 * 
 * @brief Rx network quality grade. Refer to ByteRTCNetworkQuality{@link #ByteRTCNetworkQuality} for details.
 */
@property(assign, nonatomic) ByteRTCNetworkQuality rxQuality;
@end


/**
 * 
 * @type keytype
 * @brief network time info
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCNetworkTimeInfo: NSObject

/**
 * 
 * @brief Network time. Unit: ms
 */
@property(assign, nonatomic) int64_t timestamp;
@end

#pragma mark - ByteRTCDeviceCollection

/**
 * 
 * @type api
 * @hidden(iOS)
 * @brief Media Device Info
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCDeviceCollection : NSObject

/**
 * 
 * @type api
 * @region engine management
 * @brief Get the number of media devices
 * @return Number of media devices
 */
- (int)getCount;

/**
 * 
 * @type api
 * @region Engine management
 * @brief Get the information of the specific device
 * @param  index Device index number, starting from 0. The index must be less than the return value of getCount{@link #ByteRTCDeviceCollection#getCount}.
 * @param  deviceName device name
 * @param  deviceID device ID
 * @return
 *         - 0: Success.
 *         - !0: failure
 */
- (int)getDevice:(int)index DeviceName:(NSString * _Nonnull * _Nonnull)deviceName DeviceID:(NSString * _Nonnull * _Nonnull) deviceID;
@end


/**
 * 
 * @type keytype
 * @brief  audio dump statue.
 */
typedef NS_ENUM(NSInteger, ByteRTCAudioDumpStatus){
    
    /**
     * 
     * @brief audio dump start failure
     */
    ByteRTCAudioDumpStartFailure = 0,
    
    /**
     * 
     * @brief audio dump start success
     */
    ByteRTCAudioDumpStartSuccess = 1,
    
    /**
     * 
     * @brief audio dump stop failure
     */
    ByteRTCAudioDumpStopFailure = 2,
    
    /**
     * 
     * @brief audio dump stop success
     */
    ByteRTCAudioDumpStopSuccess = 3,
    
    /**
     * 
     * @brief audio dump running failure
     */
    ByteRTCAudioDumpRunningFailure = 4,
    
    /**
     * 
     * @brief audio dump ruinning success
     */
    ByteRTCAudioDumpRunningSuccess = 5,
};



/**
 * 
 * @type keytype
 * @brief  Reason for stopping pre-call detection
 */
typedef NS_ENUM(NSUInteger, ByteRTCNetworkDetectionStopReason) {
    
    /**
     * 
     * @brief The user actively stops.
     */
    ByteRTCNetworkDetectionStopReasonUser = 0,
    
    /**
     * 
     * @brief Detection takes more than three minutes.
     */
    ByteRTCNetworkDetectionStopReasonTimeout = 1,
    
    /**
     * 
     * @brief Probe network connection disconnected.
     */
    ByteRTCNetworkDetectionStopReasonConnectionLost = 2,
    
    /**
     * 
     * @brief Begin push-pull flow and stop probing.
     */
    ByteRTCNetworkDetectionStopReasonStreaming = 3,
    
    /**
     * 
     * @brief Network probe failure, internal anomaly
     */
    ByteRTCNetworkDetectionStopReasonInnerErr = 4,
};


/**
 * 
 * @type errorcode
 * @brief  Return value to start probing
 */
typedef NS_ENUM(NSInteger, ByteRTCNetworkDetectionStartReturn) {
    
    /**
     * 
     * @brief Successfully initiated detection.
     */
    ByteRTCNetworkDetectionStartReturnSuccess = 0,
    
    /**
     * 
     * @brief Failed to start probing. Parameter error, both uplink and downlink probes are false, or the expected bandwidth exceeds the range [100,10000]
     */
    ByteRTCNetworkDetectionStartReturnParamErr = 1,
    
    /**
     * 
     * @brief Failed to start probing. Push-pull flow has begun
     */
    ByteRTCNetworkDetectionStartReturnStreaming = 2,
    
    /**
     * 
     * @brief Has begun to detect
     */
    ByteRTCNetworkDetectionStartReturnStarted = 3,
    
    /**
     * 
     * @brief Not Support
     */
    ByteRTCNNetworkDetectionStartReturnNotSupport = 4,
};


/**
 * 
 * @type keytype
 * @brief The type of probe link before the call.
 */
typedef NS_ENUM(NSUInteger, ByteRTCNetworkDetectionLinkType) {
    
    /**
     * 
     * @brief Uplink network probing.
     */
    ByteRTCNetworkDetectionLinkTypeUp = 0,
    
    /**
     * 
     * @brief Downlink network probing.
     */
    ByteRTCNetworkDetectionLinkTypeDown = 1,
};


/**
 * 
 * @type keytype
 * @brief Result of the detection inited before joining a room
 */
typedef NS_ENUM(NSUInteger, ByteRTCHardwareEchoDetectionResult) {
    
    /**
     * 
     * @brief Detection is stopped by the call of `stopHardwareEchoDetection` before the SDK reports the detection result.
     */
    ByteRTCHardwareEchoDetectionCanceled = 0,
    
    /**
     * 
     * @brief Unknown state <br>
     *        Contact us if you retry several times but keep failing.
     */
    ByteRTCHardwareEchoDetectionUnknown = 1,
    
    /**
     * 
     * @brief Excellent <br>
     *        No echo issue is detected.
     */
    ByteRTCHardwareEchoDetectionNormal = 2,
    
    /**
     * 
     * @brief Echo <br>
     *        Echo issue is detected. Recommend the user join the call with a headset through the interface.
     */
    ByteRTCHardwareEchoDetectionPoor = 3,
};


/**
 * 
 * @type keytype
 * @brief User priority in the audio selection
 */
typedef NS_ENUM(NSUInteger, ByteRTCAudioSelectionPriority) {
    
    /**
     * 
     * @brief Normal whether the stream can be subscribed is determined by the result of audio selection.
     */
    ByteRTCAudioSelectionPriorityNormal = 0,
    
    /**
     * 
     * @brief Hight priority with which the stream can skip the audio selection and always be subscribable.
     */
    ByteRTCAudioSelectionPriorityHigh = 1
};


/**
 * 
 * @type keytype
 * @brief Extra information setting result.
 */
typedef NS_ENUM(NSInteger,ByteRTCSetRoomExtraInfoResult) {
    
    /**
     * 
     * @brief Success.
     */
    ByteRTCSetRoomExtraInfoResultSuccess = 0,
    
    /**
     * 
     * @brief Failure. You are not in the room.
     */
    ByteRTCSetRoomExtraInfoResultNotJoinRoom = -1,
    
    /**
     * 
     * @brief Failure. The key pointer is null.
     */
    ByteRTCSetRoomExtraInfoResultKeyIsNull = -2,
    
    /**
     * 
     * @brief Failure. The value pointer is null.
     */
    ByteRTCSetRoomExtraInfoResultValueIsNull = -3,
    
    /**
     * 
     * @brief Failure. Unknown error.
     */
    ByteRTCSetRoomExtraInfoResultUnknow = -99,
    
    /**
     * 
     * @brief Failure. The key length is 0.
     */
    ByteRTCSetRoomExtraInfoResultKeyIsEmpty = -400,
    
    /**
     * 
     * @brief Failure. Excessively frequent setting. 10 times per second is preferable.
     */
    ByteRTCSetRoomExtraInfoResultTooOften = -406,
    
    /**
     * 
     * @brief Failure. Invisible users are not allowed to call `setRoomExtraInfo`.
     */
    ByteRTCSetRoomExtraInfoResultSilentUser = -412,
    
    /**
     * 
     * @brief Failure. Key length exceeds 10 bytes.
     */
    ByteRTCSetRoomExtraInfoResultKeyTooLong = -413,
    
    /**
     * 
     * @brief Failure. Value length exceeds 128 bytes.
     */
    ByteRTCSetRoomExtraInfoResultValueTooLong = -414,
    
    /**
     * 
     * @brief Failure. Server error.
     */
    ByteRTCSetRoomExtraInfoResultServerError = -500
};

/**
 * 
 * @type keytype
 * @hidden internal use only
 * @brief Effect error type.
 */
typedef NS_ENUM(NSInteger, ByteRTCEffectErrorType) {
    
    /**
     * 
     * @brief Failed to set virtual background.
     */
    ByteRTCEffectErrorVirtualBackgroundFailure = 1,
    
    /**
     * 
     * @hidden for internal use only
     * @brief Effect independent process crash.
     */
    ByteRTCEffectErrorChildProcTerminate = 2
};

#pragma mark - ByteRTCSubtitle

/**
 * 
 * @hidden currently not available
 * @type keytype
 * @brief The states of the subtitling task.
 */
typedef NS_ENUM(NSInteger, ByteRTCSubtitleState) {
    
    /**
     * 
     * @brief Subtitles are on.
     */
    ByteRTCSubtitleStateStarted = 0,
    
    /**
     * 
     * @brief Subtitles are off.
     */
    ByteRTCSubtitleStateStoped = 1,
    
    /**
     * 
     * @brief Errors occurred in the subtitling task.
     */
    ByteRTCSubtitleStateError = 2
};

/**
 * 
 * @hidden currently not available
 * @type keytype
 * @brief Subtitle modes.
 */
typedef NS_ENUM(NSInteger, ByteRTCSubtitleMode) {
    
    /**
     * 
     * @brief The recognition mode. In this mode, the speech of a users in the room will be recognized and converted into captions.
     */
    ByteRTCSubtitleModeRecognition = 0,
    
    /**
     * 
     * @brief The translation mode. In this mode, the speech of a users in the room will be converted into captions and then translated.
     */
    ByteRTCSubtitleModeTranslation = 1
};

/**
 * 
 * @hidden currently not available
 * @type errorcode
 * @brief Error codes of the subtitling task.
 */
typedef NS_ENUM(NSInteger, ByteRTCSubtitleErrorCode) {
    
    /**
     * 
     * @brief The client side failed to identity error codes sent by cloud media processing.
     */
    ByteRTCSubtitleErrorCodeUnknow = -1,
    
    /**
     * 
     * @brief Subtitles are turned on.
     */
    ByteRTCSubtitleErrorCodeSuccess = 0,
    
    /**
     * 
     * @brief Errors occurred concerning cloud media processing. Please contact the technical support.
     */
    ByteRTCSubtitleErrorCodePostProcessError = 1,
    
    /**
     * 
     * @brief Failed to connect to the third-party service. Please contact the technical support.
     */
    ByteRTCSubtitleErrorCodeASRConnectionError = 2,
    
    /**
     * 
     * @brief Errors occurred concerning the third-party service. Please contact the technical support.
     */
    ByteRTCSubtitleErrorCodeASRServiceError = 3,
    
    /**
     * 
     * @brief Failed to call `startSubtitle`. Please join the room first.
     */
    ByteRTCSubtitleErrorCodeBeforeJoinRoom = 4,
    
    /**
     * 
     * @brief Subtitles are already on. There is no need to call `startSubtitle` again.
     */
    ByteRTCSubtitleErrorCodeAlreadyOn = 5,
    
    /**
     * 
     * @brief The target language you chose is not Unsupported.
     */
    ByteRTCSubtitleErrorCodeUnsupportedLanguage = 6,
    
    /**
     * 
     * @brief Cloud media processing is timeout. Please contact the technical support.
     */
    ByteRTCSubtitleErrorCodePostProcessTimeout = 7
};

/**
 * 
 * @hidden currently not available
 * @type keytype
 * @brief Subtitle configurations.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCSubtitleConfig : NSObject

/**
 * 
 * @brief Subtitle mode. You can choose between the recognition and translation modes based on your needs. In the recognition mode, the speech of the speaker in the room will be recognized and converted into captions. In the translation mode, the transcribed text will be translated. Refer to ByteRTCSubtitleMode{@link #ByteRTCSubtitleMode} for more details.
 */
@property(assign, nonatomic) ByteRTCSubtitleMode mode;

/**
 * 
 * @brief Target language.
 */
@property(copy, nonatomic) NSString *_Nonnull targetLanguage;
@end

/**
 * 
 * @hidden currently not available
 * @type keytype
 * @brief Related information about subtitles.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCSubtitleMessage : NSObject

/**
 * 
 * @brief The speaker's ID.
 */
@property(copy, nonatomic) NSString *_Nonnull userId;

/**
 * 
 * @brief Transcribed or translated texts of the speaker's speech, encoded in UTF-8 format.
 */
@property(copy, nonatomic) NSString *_Nonnull text;

/**
 * 
 * @brief Subtitle language. The language is that responding to the original text or the translated text based on the subtitle mode.
 */
@property(copy, nonatomic) NSString *_Nonnull language;

/**
 * 
 * @brief The subtitle mode. Refer to ByteRTCSubtitleMode{@link #ByteRTCSubtitleMode} for more details.
 */
@property(assign, nonatomic) NSInteger mode;

/**
 * 
 * @brief Subtitle text sequence number. Complete and incomplete speeches of the same speaker will be sequentially numbered separately in increasing order.
 */
@property(assign, nonatomic) NSInteger sequence;

/**
 * 
 * @brief Whether transcribed texts are complete sentences. True means yes and False means no.
 */
@property(assign, nonatomic) BOOL definite;
@end


 /**
 * 
 * @hidden
 * @type keytype
 * @brief Thread block information, including the thread name and the number of times the thread is blocked.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCDeadLockMsg : NSObject

/**
 * 
 * @brief The thread name.
 */
@property (nonatomic, strong) NSString* _Nonnull threadName;


@property(nonatomic) NSInteger lastingTimes;
@end
