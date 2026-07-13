/*
 * Copyright (c) 2020 The BytePlusRTC project authors. All Rights Reserved.
 * @brief BytePlusRTC
*/
#import <CoreMedia/CMTime.h>
#import "rtc/ByteRTCDefines.h"
#import "rtc/ByteRTCHttpClientProtocol.h"
#import "rtc/ByteRTCAudioMixingManager.h"
#import "rtc/ByteRTCAudioEffectPlayer.h"
#import "rtc/ByteRTCMediaPlayer.h"
#import "rtc/ByteRTCSingScoringManager.h"
@class ByteRTCVideo;
@class ByteRTCRoom;
@class ByteRTCKTVManager;

/**
 * 
 * @type api
 */
@protocol ByteRTCHttpClientProtocol;

#pragma mark - ByteRTCVideoDelagate


/**
 * 
 * @type callback
 * @brief ByteRTCVideoDelegate protocol contains the callback method provided by the SDK, which reports some run-time events to the application through a proxy <br>
 * Note: Callback functions are thrown synchronously in a non-UI thread within the SDK. Therefore, you must not perform any time-consuming operations or direct UI operations within the callback function, as this may cause the app to crash.
 */
@protocol ByteRTCVideoDelegate <NSObject>
@optional
#pragma mark - Core Delegate Methods


/**
 * 
 * @type callback
 * @region Warning code
 * @brief A warning occurred during the SDK runtime. The SDK usually recovers automatically and warnings can be ignored.
 * @param engine ByteRTCVideo object.
 * @param code Warning code. See ByteRTCWarningCode{@link #ByteRTCWarningCode}.
 * @list Engine Management
 * @order 5
 */
- (void)rtcEngine:(ByteRTCVideo *_Nonnull)engine onWarning:(ByteRTCWarningCode)code;

/**
 * 
 * @type callback
 * @region Error code
 * @brief Error callback occurred. This callback is triggered when a network or media-related error occurs during the <br>
 *        SDK runtime and cannot be automatically recovered and you may need to intervene.
 * @param engine ByteRTCVideo object.
 * @param errorCode  BigInt. See ByteRTCErrorCode{@link #ByteRTCErrorCode}.
 * @list Engine Management
 * @order 6
 */
- (void)rtcEngine:(ByteRTCVideo *_Nonnull)engine onError:(ByteRTCErrorCode)errorCode;



/**
 * 
 * @hidden internal use only
 * @type callback
 * @brief When an internal thread is blocked, this callback will be received.
 * @param engine ByteRTCVideo object.
 * @param deadlockMsg The name of the thread that is blocked and the number of block detections;
 */
- (void)rtcEngine:(ByteRTCVideo *_Nonnull)engine onDeadLockError:(ByteRTCDeadLockMsg *_Nonnull)deadlockMsg;

/**
 * 
* @valid since 3.52
* @type callback
* @brief Failed to access the extension. <br>
*        RTC SDK provides some features with extensions. Without implementing the extension, you cannot use the corresponding feature.
* @param engine ByteRTCVideo object.
* @param extensionName The name of extension.
* @param msg Error message.
*/
- (void)rtcEngine:(ByteRTCVideo *_Nonnull)engine onExtensionAccessError:(NSString * _Nonnull)extensionName msg:(NSString * _Nonnull)msg;

/**
 * 
 * @type callback
 * @region Engine Management
 * @brief Callback on create room failure.
 * @param engine ByteRTCVideo object.
 * @param roomId  Room ID.
 * @param errorCode Create room error code. See ByteRTCErrorCode{@link #ByteRTCErrorCode} for specific indications.
 * @list Room Management
 */
- (void)rtcEngine:(ByteRTCVideo *_Nonnull)engine onCreateRoomStateChanged:(NSString * _Nonnull)roomId errorCode:(NSInteger)errorCode;


/**
 * 
 * @type callback
 * @region  engine management
 * @brief SDK  connection state change callback with signaling server. Triggered when the connection state changes.
 * @param engine ByteRTCVideo object
 * @param state The current connection status between the SDK and the signaling server. See ByteRTCConnectionState{@link #ByteRTCConnectionState}.
 * @note Refer to [Getting Connection Status](https:
 */
- (void) rtcEngine:(ByteRTCVideo * _Nonnull)engine onConnectionStateChanged:(ByteRTCConnectionState) state;

/**
 * 
 * @type callback
 * @region  engine management
 * @brief SDK  current network connection type change callback.
 * @param engine ByteRTCVideo object
 * @param type SDK The current network connection type. See ByteRTCNetworkType{@link #ByteRTCNetworkType}
 */
- (void) rtcEngine:(ByteRTCVideo * _Nonnull)engine onNetworkTypeChanged:(ByteRTCNetworkType) type;
#pragma mark - Core Audio Delegate Methods



/**
 * 
 * @deprecated since 3.45 and will be deleted in 3.51, use rtcRoom:onUserPublishStream:type:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishStream:type:}, rtcRoom:onUserPublishScreen:type:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishScreen:type:}, rtcRoom:onUserUnpublishStream:type:reason:{@link #ByteRTCRoomDelegate#rtcRoom:onUserUnpublishStream:type:reason:} and rtcRoom:onUserUnpublishScreen:type:reason:{@link #ByteRTCRoomDelegate#rtcRoom:onUserUnpublishScreen:type:reason:} instead.
 * @type callback
 * @region Media Stream Management
 * @brief When a user in the room pauses or resumes sending the audio stream, other users in the room will receive this callback.
 * @param engine ByteRTCVideo instance
 * @param roomId Room ID.
 * @param uid The user who changes his/her transmission state of the audio streams
 * @param muteState Transmission state of the audio streams. Refer to ByteRTCMuteState{@link #ByteRTCMuteState} for more details.
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onUserMuteAudio:(NSString * _Nonnull)roomId
        uid:(NSString * _Nonnull)uid muteState:(ByteRTCMuteState)muteState __deprecated_msg("Will be removed in new version");


/**
 * 
 * @type callback
 * @region Audio event callback
 * @brief The remote clients in the room will be informed of the state change via this callback after the visible user starts audio capture by calling startAudioCapture{@link #ByteRTCVideo#startAudioCapture}.
 * @param engine ByteRTCVideo instance
 * @param roomId ID of the room where the user enables audio capture
 * @param userId The user who starts the internal audio capture
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onUserStartAudioCapture:(NSString* _Nonnull)roomId
              uid:(NSString *_Nonnull)userId;


/**
 * 
 * @type callback
 * @region Audio event callback
 * @brief The remote clients in the room will be informed of the state change via this callback after the visible user stops audio capture by calling stopAudioCapture{@link #ByteRTCVideo#stopAudioCapture}.
 * @param engine ByteRTCVideo instance
 * @param roomId ID of the room where the user disables audio capture
 * @param userId The user who stops the internal audio capture
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onUserStopAudioCapture:(NSString* _Nonnull)roomId
              uid:(NSString *_Nonnull)userId;

/**
 * 
 * @type callback
 * @region Audio event callback
 * @brief Report the event when the first frame of audio of the remote stream is received
 * @param engine ByteRTCVideo object
 * @param key Remote stream information. See ByteRTCRemoteStreamKey{@link #ByteRTCRemoteStreamKey}
 * @note The callback will be received when the user has just received each audio stream in the room.
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onFirstRemoteAudioFrame:(ByteRTCRemoteStreamKey * _Nonnull)key;
 
 /**
  * 
  * @type callback
  * @region Audio Management
  * @brief After calling enableAudioPropertiesReport:{@link #ByteRTCVideo#enableAudioPropertiesReport:}, you will periodically receive this callback for the information about local audio. <br>
  *        Local audio includes the microphone audio, the screen audio captured using RTC SDK internal mechanisms, and locally mixing audio.
  * @param engine ByteRTCVideo object
  * @param audioPropertiesInfos Information of the local audios. See ByteRTCLocalAudioPropertiesInfo{@link #ByteRTCLocalAudioPropertiesInfo}. On the macOS, you can set the volume of the local audio via `setAudioCaptureDeviceVolume:`.
  * @list Audio Management
  * @order 3
  */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onLocalAudioPropertiesReport:(NSArray<ByteRTCLocalAudioPropertiesInfo *> * _Nonnull)audioPropertiesInfos;
 
 /**
  * 
  * @hidden(iOS)
  * @type callback
  * @region Audio Device Management
  * @brief Notification on the playing volume during the test for the local audio devices.
  * @param engine ByteRTCVideo object
  * @param volume Playing volume during the test for the local audio devices. The range is [0,255].
  * @note Start an audio-device test by calling startAudioPlaybackDeviceTest:interval:{@link #ByteRTCAudioDeviceManager#startAudioPlaybackDeviceTest:interval:} or startAudioDeviceRecordTest:{@link #ByteRTCAudioDeviceManager#startAudioDeviceRecordTest:} will register this callback for regular notification on playing volume. You can set the time interval between each callback by passing a proper value when calling the API above.
  */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onAudioPlaybackDeviceTestVolume:(int)volume;

 
 /**
  * 
  * @hidden(iOS)
  * @type callback
  * @region device management
  * @brief Callback to notify you the volume of the audio device has been changed or when the device has been muted or unmuted. No need to activate the notification beforehand.
  * @param engine ByteRTCVideo object
  * @param deviceType Includes microphones and speakers. Refer to ByteRTCAudioDeviceType{@link #ByteRTCAudioDeviceType} for more details.
  * @param volume Volume ranging [0, 255]. When the volume turns to 0, muted turns to True.
  * @param muted Whether is muted. When a speaker is muted, muted turns True but volume remains unchanged.
  */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onAudioDeviceVolumeChanged:(ByteRTCAudioDeviceType)deviceType volume:(int)volume muted:(bool)muted;

 
 /**
  * 
  * @type callback
  * @region Audio Management
  * @brief After calling enableAudioPropertiesReport:{@link #ByteRTCVideo#enableAudioPropertiesReport:}, you will periodically receive this callback for the information about the subscribed remote audio streams. <br>
  *        The remote audio streams includes the microphone audio and screen audio collected using the RTC SDK internal mechanism/custom mechanism.
  * @param engine ByteRTCVideo object
  * @param audioPropertiesInfos See ByteRTCRemoteAudioPropertiesInfo{@link #ByteRTCRemoteAudioPropertiesInfo}.
  * @param totalRemoteVolume The total volume of all the subscribed remote streams. The range is [0,255]. <br>
  *        - [0,25] Is close to silent;
  *        - [25,75] Is low volume;
  *        - [76,204] Is medium volume;
  *        - [205,255] Is high volume.
  */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onRemoteAudioPropertiesReport:(NSArray<ByteRTCRemoteAudioPropertiesInfo *> * _Nonnull)audioPropertiesInfos totalRemoteVolume:(NSInteger)totalRemoteVolume;

/**
 * 
 * @type callback
 * @region Audio Management
 * @brief After calling enableAudioPropertiesReport:{@link #ByteRTCVideo#enableAudioPropertiesReport:}, you will periodically receive this callback for the active speaker information.
  * @param engine ByteRTCVideo object
 * @param roomId  Room ID.
 * @param uid The user ID of the active speaker.
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onActiveSpeaker:(NSString * _Nonnull)roomId uid:(NSString *_Nonnull)uid;
#pragma mark - Core Video Delegate Methods



/**
 * 
 * @deprecated since 3.45 and will be deleted in 3.51, use rtcRoom:onUserPublishStream:type:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishStream:type:}, rtcRoom:onUserPublishScreen:type:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishScreen:type:}, rtcRoom:onUserUnpublishStream:type:reason:{@link #ByteRTCRoomDelegate#rtcRoom:onUserUnpublishStream:type:reason:} and rtcRoom:onUserUnpublishScreen:type:reason:{@link #ByteRTCRoomDelegate#rtcRoom:onUserUnpublishScreen:type:reason:} instead.
 * @type callback
 * @region Video management
 * @brief Transmission state change of an video stream in the room triggers this callback.
 * @param engine ByteRTCVideo instance
 * @param roomId  Room ID.
 * @param uid The user who changes his/her transmission state of the video streams
 * @param muteState Transmission state of the video streams. Refer to ByteRTCMuteState{@link #ByteRTCMuteState} for more details.
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onUserMuteVideo:(NSString * _Nonnull)roomId
              uid:(NSString * _Nonnull)uid withMuteState:(ByteRTCMuteState)muteState 
              NS_SWIFT_NAME(rtcEngine(_:onUserMuteVideo:uid:withMuteState:)) __deprecated_msg("Will be removed in new version");

/**
 * 
 * @type callback
 * @region Video management
 * @brief The remote clients in the room will be informed of the state change via this callback after the visible user starts video capture by startVideoCapture{@link #ByteRTCVideo#startVideoCapture}.
 * @param engine ByteRTCVideo instance
 * @param roomId ID of the room where the remote user enables video capture
 * @param uid The user who starts the internal video capture
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onUserStartVideoCapture:(NSString * _Nonnull)roomId
              uid:(NSString * _Nonnull)uid;

/**
 * 
 * @type callback
 * @region Video management
 * @brief The remote clients in the room will be informed of the state change via  this callback after the visible user stops video capture by calling stopVideoCapture{@link #ByteRTCVideo#stopVideoCapture}. <br>
 *        If you don't start video capture before you publish video data, all visible user will receive this callback.
 * @param engine ByteRTCVideo instance
 * @param roomId ID of the room where the remote user disables video capture
 * @param uid The user who stops the internal video capture
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onUserStopVideoCapture:(NSString * _Nonnull)roomId
              uid:(NSString * _Nonnull)uid;

/**
 * 
 * @type callback
 * @region Video Management
 * @brief Receive this callback when the first locally captured video/screen share screen is rendered in the local view.
 * @param engine ByteRTCVideo object
 * @param streamIndex Stream property. See ByteRTCStreamIndex{@link #ByteRTCStreamIndex}
 * @param frameInfo Video frame information. See ByteRTCVideoFrameInfo{@link #ByteRTCVideoFrameInfo}
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onFirstLocalVideoFrameCaptured:(ByteRTCStreamIndex)streamIndex withFrameInfo:(ByteRTCVideoFrameInfo * _Nonnull)frameInfo NS_SWIFT_NAME(rtcEngine(_:onFirstLocalVideoFrameCaptured:withFrameInfo:));

/**
 * 
 * @type callback
 * @region Video Management
 * @brief Receive this callback after the first frame of remote video stream is locally rendered by SDK.
 * @param engine ByteRTCVideo object
 * @param streamKey  Remote stream information. See ByteRTCRemoteStreamKey{@link #ByteRTCRemoteStreamKey}
 * @param frameInfo  Video frame information. See ByteRTCVideoFrameInfo{@link #ByteRTCVideoFrameInfo}
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onFirstRemoteVideoFrameRendered:(ByteRTCRemoteStreamKey * _Nonnull)streamKey withFrameInfo:(ByteRTCVideoFrameInfo * _Nonnull)frameInfo NS_SWIFT_NAME(rtcEngine(_:onFirstRemoteVideoFrameRendered:withFrameInfo:));

/**
 * 
 * @type callback
 * @region Video Management
 * @brief Receive this callback after the first frame of remote video stream is received and decoded by SDK.
 * @param engine ByteRTCVideo object
 * @param streamKey  Remote stream information, see ByteRTCRemoteStreamKey {@link #ByteRTCRemoteStreamKey}
 * @param frameInfo  Video frame information, see ByteRTCVideoFrameInfo {@link #ByteRTCVideoFrameInfo}
 * @note
 *       - For main stream, after joining the room, the subscriber will receive this callback only when the publisher publishes video stream for the first time.
 *       - For screen-sharing stream, the subscriber will receive this callback every time the publisher publishes or republishes the screen video stream.
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onFirstRemoteVideoFrameDecoded:(ByteRTCRemoteStreamKey * _Nonnull)streamKey withFrameInfo:(ByteRTCVideoFrameInfo * _Nonnull)frameInfo NS_SWIFT_NAME(rtcEngine(_:onFirstRemoteVideoFrameDecoded:withFrameInfo:));

/**
 * 
 * @type callback
 * @region Video Management
 * @brief Users in the room who subscribe to this video stream receive this callback when the remote video size or rotation information changes.
 * @param engine ByteRTCVideo object
 * @param streamKey Stream property. See ByteRTCRemoteStreamKey{@link #ByteRTCRemoteStreamKey}
 * @param frameInfo Video frame information. See ByteRTCVideoFrameInfo{@link #ByteRTCVideoFrameInfo}
 */
- (void)rtcEngine:(ByteRTCVideo *_Nonnull)engine onRemoteVideoSizeChanged:(ByteRTCRemoteStreamKey *_Nonnull)streamKey withFrameInfo:(ByteRTCVideoFrameInfo *_Nonnull)frameInfo NS_SWIFT_NAME(rtcEngine(_:onRemoteVideoSizeChanged:withFrameInfo:));

/**
 * 
 * @type callback
 * @region video management
 * @brief Receive this callback when local video size or rotation information changes.
 * @param engine  ByteRTCVideo object
 * @param streamIndex Stream property. See ByteRTCStreamIndex{@link #ByteRTCStreamIndex}
 * @param frameInfo Frame information. See ByteRTCVideoFrameInfo{@link #ByteRTCVideoFrameInfo}
 */
- (void)rtcEngine:(ByteRTCVideo *_Nonnull)engine onLocalVideoSizeChanged:(ByteRTCStreamIndex)streamIndex withFrameInfo:(ByteRTCVideoFrameInfo *_Nonnull)frameInfo NS_SWIFT_NAME(rtcEngine(_:onLocalVideoSizeChanged:withFrameInfo:));

/**
 * 
 * @deprecated since 3.45 and will be deleted in 3.51, use rtcEngine:onAudioDeviceStateChanged:device_type:device_state:device_error:{@link #ByteRTCVideoDelegate#rtcEngine:onAudioDeviceStateChanged:device_type:device_state:device_error:} and rtcEngine:onVideoDeviceStateChanged:device_type:device_state:device_error:{@link #ByteRTCVideoDelegate#rtcEngine:onVideoDeviceStateChanged:device_type:device_state:device_error:} instead.
 * @type callback
 * @region Engine management
 * @brief Media device state callback, returns the state of four media devices: audio capture, audio playback, video capture, and screen capture.
 * @param engine ByteRTCVideo instance
 * @param deviceID Device ID
 * @param deviceType Device type. See ByteRTCMediaDeviceType{@link #ByteRTCMediaDeviceType}.
 * @param deviceState Device state. See ByteRTCMediaDeviceState{@link #ByteRTCMediaDeviceState}.
 * @param deviceError Device error. See ByteRTCMediaDeviceError{@link #ByteRTCMediaDeviceError}.
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onMediaDeviceStateChanged:(NSString*_Nonnull)deviceID
        device_type:(ByteRTCMediaDeviceType)deviceType
        device_state:(ByteRTCMediaDeviceState)deviceState
        device_error:(ByteRTCMediaDeviceError)deviceError
    __attribute((deprecated("Will be removed in new version")));

/**
 * 
 * @type callback
 * @region Engine management
 * @brief Audio device state callback, returns the state of audio capture and audio playback devices.
 * @param engine ByteRTCVideo instance
 * @param deviceID Device ID
 * @param deviceType Device type. See ByteRTCAudioDeviceType{@link #ByteRTCAudioDeviceType}.
 * @param deviceState Device state. See ByteRTCMediaDeviceState{@link #ByteRTCMediaDeviceState}.
 * @param deviceError Device error. See ByteRTCMediaDeviceError{@link #ByteRTCMediaDeviceError}.
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onAudioDeviceStateChanged:(NSString*_Nonnull)deviceID
      device_type:(ByteRTCAudioDeviceType)deviceType
     device_state:(ByteRTCMediaDeviceState)deviceState
     device_error:(ByteRTCMediaDeviceError)deviceError;

/**
 * 
 * @type callback
 * @region Engine management
 * @brief Video device state callback. It returns the state of media devices, including video capture and screen capture.
 * @param  deviceID Device ID
 * @param  deviceType Device type. Refer to ByteRTCVideoDeviceType{@link #ByteRTCVideoDeviceType} for more details.
 * @param  deviceState Device state. Refer to ByteRTCMediaDeviceState{@link #ByteRTCMediaDeviceState} for more details.
 * @param  deviceError Device error. Refer to ByteRTCMediaDeviceError{@link #ByteRTCMediaDeviceError} for more details.
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onVideoDeviceStateChanged:(NSString*_Nonnull)deviceID
      device_type:(ByteRTCVideoDeviceType)deviceType
     device_state:(ByteRTCMediaDeviceState)deviceState
     device_error:(ByteRTCMediaDeviceError)deviceError;

/**
 * 
 * @deprecated since 3.45 and will be deleted in 3.51, use rtcEngine:onAudioDeviceWarning:deviceType:deviceWarning:{@link #ByteRTCVideoDelegate#rtcEngine:onAudioDeviceWarning:deviceType:deviceWarning:} and rtcEngine:onVideoDeviceWarning:deviceType:deviceWarning:{@link #ByteRTCVideoDelegate#rtcEngine:onVideoDeviceWarning:deviceType:deviceWarning:} instead.
 * @type callback
 * @region Engine Management
 * @brief Media device warning callback. The media devices includes: audio capture devices, audio rendering devices, and video capture devices.
 * @param engine ByteRTCVideo object
 * @param deviceId Device ID
 * @param deviceType See ByteRTCMediaDeviceType{@link #ByteRTCMediaDeviceType}
 * @param deviceWarning See ByteRTCMediaDeviceWarning{@link #ByteRTCMediaDeviceWarning}
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onMediaDeviceWarning:(NSString*_Nonnull)deviceId
    deviceType:(ByteRTCMediaDeviceType)deviceType
    deviceWarning:(ByteRTCMediaDeviceWarning)deviceWarning
    __deprecated_msg("Will be removed in new version");

/**
 * 
 * @type callback
 * @region Engine Management
 * @brief Audio device warning callback. The audio devices includes audio capture devices and audio rendering devices.
 * @param engine ByteRTCVideo object
 * @param deviceId Device ID
 * @param deviceType See ByteRTCAudioDeviceType{@link #ByteRTCAudioDeviceType}
 * @param deviceWarning See ByteRTCMediaDeviceWarning{@link #ByteRTCMediaDeviceWarning}
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onAudioDeviceWarning:(NSString*_Nonnull)deviceId
    deviceType:(ByteRTCAudioDeviceType)deviceType
    deviceWarning:(ByteRTCMediaDeviceWarning)deviceWarning;

/**
 * 
 * @type callback
 * @region Engine Management
 * @brief Video device warning callback. The video devices includes video capture devices.
 * @param engine ByteRTCVideo object
 * @param deviceId Device ID
 * @param deviceType See ByteRTCVideoDeviceType{@link #ByteRTCVideoDeviceType}
 * @param deviceWarning See ByteRTCMediaDeviceWarning{@link #ByteRTCMediaDeviceWarning}
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onVideoDeviceWarning:(NSString*_Nonnull)deviceId
    deviceType:(ByteRTCVideoDeviceType)deviceType
    deviceWarning:(ByteRTCMediaDeviceWarning)deviceWarning;


/**
 * 
 * @type callback
 * @region Room Management
 * @brief Receive this callback when the sending state of the first audio frame changes.
 * @param engine ByteRTCVideo object
 * @param roomId ID of the room from which the audio is published
 * @param user Local user information. See ByteRTCUser{@link #ByteRTCUser}
 * @param state First frame sending status. See ByteRTCFirstFrameSendState{@link #ByteRTCFirstFrameSendState}
 */
- (void)rtcEngine:(ByteRTCVideo *_Nonnull)engine onAudioFrameSendStateChanged:(NSString * _Nonnull)roomId
              rtcUser:(ByteRTCUser *_Nonnull)user state:(ByteRTCFirstFrameSendState)state;


/**
 * 
 * @type callback
 * @region Room management
 * @brief Receive this callback when the video first frame sending state changes
 * @param engine ByteRTCVideo object
 * @param roomId ID of the room from which the video is published
 * @param user Local user information. See ByteRTCUser{@link #ByteRTCUser}
 * @param state First frame sending status. See ByteRTCFirstFrameSendState{@link #ByteRTCFirstFrameSendState}
 */
- (void)rtcEngine:(ByteRTCVideo *_Nonnull)engine onVideoFrameSendStateChanged:(NSString * _Nonnull)roomId
          rtcUser:(ByteRTCUser *_Nonnull)user state:(ByteRTCFirstFrameSendState)state;


/**
 * 
 * @type callback
 * @region Room Management
 * @brief You will receive this callback when the first video frame of the screen sharing is sent witha change in status.
 * @param engine ByteRTCVideo instance.
 * @param roomId ID of the room from which the screen stream is published
 * @param user Local user information. See ByteRTCUser{@link #ByteRTCUser}
 * @param state First frame sending status. See ByteRTCFirstFrameSendState{@link #ByteRTCFirstFrameSendState}
 */
- (void)rtcEngine:(ByteRTCVideo *_Nonnull)engine onScreenVideoFrameSendStateChanged:(NSString * _Nonnull)roomId
          rtcUser:(ByteRTCUser *_Nonnull)user state:(ByteRTCFirstFrameSendState)state;


/**
 * 
 * @type callback
 * @region Room Management
 * @brief Receive this callback when the audio first frame playback state changes
 * @param engine ByteRTCVideo instance.
 * @param roomId ID of the room from which the audio is published
 * @param user User information from the audio stream. See ByteRTCUser{@link #ByteRTCUser}
 * @param state First frame playback status. See ByteRTCFirstFramePlayState{@link #ByteRTCFirstFramePlayState}
 */
- (void)rtcEngine:(ByteRTCVideo *_Nonnull)engine onAudioFramePlayStateChanged:(NSString * _Nonnull)roomId
          rtcUser:(ByteRTCUser *_Nonnull)user state:(ByteRTCFirstFramePlayState)state;


/**
 * 
 * @type callback
 * @region Room Management
 * @brief Receive this callback when the video first frame playback state changes
 * @param engine ByteRTCVideo instance.
 * @param roomId ID of the room from which the video is published
 * @param user User information from the video stream source. See ByteRTCUser{@link #ByteRTCUser}
 * @param state First frame playback state. See ByteRTCFirstFramePlayState{@link #ByteRTCFirstFramePlayState}
 */
- (void)rtcEngine:(ByteRTCVideo *_Nonnull)engine onVideoFramePlayStateChanged:(NSString * _Nonnull)roomId
          rtcUser:(ByteRTCUser *_Nonnull)user state:(ByteRTCFirstFramePlayState)state;


/**
 * 
 * @type callback
 * @region Room Management
 * @brief You will receive this callback when the first frame playback state changes
 * @param engine ByteRTCVideo object.
 * @param roomId ID of the room from which the screen stream is published
 * @param user Screen sharing user information from the stream source. See ByteRTCUser{@link #ByteRTCUser}
 * @param state First frame playback status. See ByteRTCFirstFramePlayState{@link #ByteRTCFirstFramePlayState}
 */
- (void)rtcEngine:(ByteRTCVideo *_Nonnull)engine onScreenVideoFramePlayStateChanged:(NSString * _Nonnull)roomId rtcUser:(ByteRTCUser *_Nonnull)user state:(ByteRTCFirstFramePlayState)state;
#pragma mark - Media Stream Delegate Methods


/**
 * 
 *  @type callback
 *  @region Audio event callback
 *  @brief Receive the callback when publishing local audio stream.
 *  @param engine ByteRTCVideo object
 *  @param streamIndex  Audio stream properties. See ByteRTCStreamIndex{@link #ByteRTCStreamIndex}
 * @note If you publish audio stream without enabling local audio capture, SDK will push blank audio frames that you will also get this notification.
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onFirstLocalAudioFrame:(ByteRTCStreamIndex) streamIndex;
#pragma mark - Media Device Delegate Methods


/**
 * 
 * @hidden(macOS)
 * @deprecated since 3.45 and will be deleted in 3.51, use rtcEngine:onAudioRouteChanged:{@link #ByteRTCVideoDelegate#rtcEngine:onAudioRouteChanged:} instead.
 * @type callback
 * @region Audio event callback
 * @brief You will receive this callback when the audio playback device changes.
 * @param engine ByteRTCVideo instance.
 * @param device New audio playback device. See ByteRTCAudioPlaybackDevice{@link #ByteRTCAudioPlaybackDevice}
 * @note For the settings of audio playback device and audio routing, see setAudioPlaybackDevice:{@link #ByteRTCVideo#setAudioPlaybackDevice:}.
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onAudioPlaybackDeviceChanged:(ByteRTCAudioPlaybackDevice)device __deprecated_msg("Will be removed in new version");

/**
 * 
 * @hidden(macOS)
 * @type callback
 * @region Audio event callback
 * @brief RTC notifies the audio route changes via this callback.
 * @param engine ByteRTCVideo object
 * @param device Current audio playback device. Refer to ByteRTCAudioRoute{@link #ByteRTCAudioRoute} for more information.
 * @note Either of the following actions will lead to audio route switching. See [Set the Audio Route](https:
 * - Connecting/Disconnecting an audio device
 * - Designating the other audio device by calling setAudioRoute:{@link #ByteRTCVideo#setAudioRoute:}.
 */
- (void)rtcEngine:(ByteRTCVideo *_Nonnull)engine onAudioRouteChanged:(ByteRTCAudioRoute)device;
#pragma mark custom message Delegate Methods


/**
 * 
 * @type callback
 * @region Video management
 * @brief Receive this callback when you receive a video frame with a SEI message by calling sendSEIMessage:andMessage:andRepeatCount:andCountPerFrame:{@link #ByteRTCVideo#sendSEIMessage:andMessage:andRepeatCount:andCountPerFrame:}.
 * @param engine Current ByteRTCVideo instance
 * @param remoteStreamKey Contains the user name, room name and media stream of the SEI sender. See ByteRTCRemoteStreamKey{@link #ByteRTCRemoteStreamKey}
 * @param message Received SEI message content
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onSEIMessageReceived:(ByteRTCRemoteStreamKey* _Nonnull)remoteStreamKey andMessage:(NSData* _Nonnull)message;

/**
 * 
 * @type callback
 * @region Message
 * @brief Callback about publishing status of the black frame video stream. <br>
 *        In a voice call scenario, when the local user calls sendSEIMessage:andMessage:andRepeatCount:andCountPerFrame:{@link #ByteRTCVideo#sendSEIMessage:andMessage:andRepeatCount:andCountPerFrame:} to send SEI data with a black frame, the sending status of the stream is notified to the remote user through this callback. <br>
 *        You can tell from this callback that the video frame carrying SEI data is a black frame and thus not render that video frame.
 * @param engine Current ByteRTCVideo instance
 * @param remoteStreamKey Information about stream from the remote user, see ByteRTCRemoteStreamKey{@link #ByteRTCRemoteStreamKey}.
 * @param eventType State of the black frame video stream, see ByteRTCSEIStreamEventType{@link #ByteRTCSEIStreamEventType}.
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onSEIStreamUpdate:(ByteRTCRemoteStreamKey* _Nonnull)remoteStreamKey eventType:(ByteRTCSEIStreamEventType)eventType;

/**
 * 
 * @type callback
 * @region audio management
 * @brief Audio stream synchronization information callback. You can use this callback to receive audio stream synchronization information sent remotely after the remote user calls sendStreamSyncInfo:config:{@link #ByteRTCVideo#sendStreamSyncInfo:config:} to send an audio stream synchronization message.
 * @param engine  Current ByteRTCVideo instance.
 * @param remoteStreamKey  For remote stream information. See ByteRTCRemoteStreamKey{@link #ByteRTCRemoteStreamKey}.
 * @param streamType  Media stream type. See ByteRTCSyncInfoStreamType{@link #ByteRTCSyncInfoStreamType}.
 * @param data Message content.
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onStreamSyncInfoReceived:(ByteRTCRemoteStreamKey* _Nonnull)remoteStreamKey streamType:(ByteRTCSyncInfoStreamType)streamType data:(NSData* _Nonnull)data;
#pragma mark - Statistics Delegate Methods


/**
 * 
 * @type callback
 * @region Data statistics
 * @brief Report the current device CPU and memory usage, which is triggered every 2s.
 * @param engine ByteRTCVideo object
 * @param stats Cpu and memory usage information. See ByteRTCSysStats{@link #ByteRTCSysStats} data type
 * @list Engine Management
 * @order 2
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onSysStats:(const ByteRTCSysStats * _Nonnull)stats NS_SWIFT_NAME(rtcEngine(_:onSysStats:));

/**
 * 
 * @type callback
 * @region Audio event callback
 * @brief Receive this callback when the state of the local audio stream changes.
 * @param engine ByteRTCVideo object
 * @param state The current state of the local audio device. See ByteRTCLocalAudioStreamState{@link #ByteRTCLocalAudioStreamState}
 * @param error Error code when the state of the local audio stream changes. See ByteRTCLocalAudioStreamError{@link #ByteRTCLocalAudioStreamError}
 */
- (void)rtcEngine:(ByteRTCVideo *_Nonnull)engine onLocalAudioStateChanged:(ByteRTCLocalAudioStreamState)state
                     error:(ByteRTCLocalAudioStreamError)error;

/**
 * 
 *  @type callback
 *  @region Audio event callback
 *  @brief Receive this callback when the state of the remote audio stream subscribed to changes.
 *  @param engine ByteRTCVideo object
 *  @param key Remote stream information. See ByteRTCRemoteStreamKey{@link #ByteRTCRemoteStreamKey}
 *  @param state The current state of the remote audio stream. See ByteRTCRemoteAudioState{@link #ByteRTCRemoteAudioState}
 *  @param reason The reason for the change in the state of the remote audio stream. See ByteRTCRemoteAudioStateChangeReason{@link #ByteRTCRemoteAudioStateChangeReason}
 */
- (void)rtcEngine:(ByteRTCVideo *_Nonnull)engine onRemoteAudioStateChanged:(ByteRTCRemoteStreamKey * _Nonnull)key
                      state:(ByteRTCRemoteAudioState)state
                      reason:(ByteRTCRemoteAudioStateChangeReason)reason;

/**
 * 
 * @type callback
 * @region Video management
 * @brief Receive this event when the state of the local video stream changes.
 * @param engine ByteRTCVideo object
 * @param streamIndex Stream property. See ByteRTCStreamIndex{@link #ByteRTCStreamIndex}
 * @param state Current state of local video stream. See ByteRTCLocalVideoStreamState{@link #ByteRTCLocalVideoStreamState}
 * @param error Error code when local video state changes. See ByteRTCLocalVideoStreamError{@link #ByteRTCLocalVideoStreamError}
 */
- (void)rtcEngine:(ByteRTCVideo *_Nonnull)engine onLocalVideoStateChanged:(ByteRTCStreamIndex)streamIndex
             withStreamState:(ByteRTCLocalVideoStreamState)state
             withStreamError:(ByteRTCLocalVideoStreamError)error NS_SWIFT_NAME(rtcEngine(_:onLocalVideoStateChanged:withStreamState:withStreamError:));

/**
 * 
 * @type callback
 * @region Video management
 * @brief When the state of the remote video stream changes, users in the room who subscribe to this stream will receive the event.
 * @param engine ByteRTCVideo object
 * @param streamKey Remote video stream information, room, user ID, stream attributes, etc.. See ByteRTCRemoteStreamKey{@link #ByteRTCRemoteStreamKey}
 * @param state The current state of the remote video stream. See ByteRTCRemoteVideoState{@link #ByteRTCRemoteVideoState}
 * @param reason The reason for the change in the state of the remote video stream. See ByteRTCRemoteVideoStateChangeReason{@link #ByteRTCRemoteVideoStateChangeReason}
 * @note This callback is only applicable to the main stream and not applicable to the screen stream.
 */
- (void)rtcEngine:(ByteRTCVideo *_Nonnull)engine onRemoteVideoStateChanged:(ByteRTCRemoteStreamKey*_Nonnull)streamKey
                withVideoState:(ByteRTCRemoteVideoState)state
                withVideoStateReason:(ByteRTCRemoteVideoStateChangeReason)reason NS_SWIFT_NAME(rtcEngine(_:onRemoteVideoStateChanged:withVideoState:withVideoStateReason:));

/**
 * 
 * @hidden not available
 * @type callback
 * @region Audio & Video Processing
 * @brief When the super resolution mode of a remote video stream changes, users in the room who subscribe to this stream will receive this callback.
 * @param engine ByteRTCVideo object
 * @param streamKey Remote stream information that includes the room ID, user ID, and stream type. See ByteRTCRemoteStreamKey{@link #ByteRTCRemoteStreamKey}.
 * @param mode Super resolution mode. See ByteRTCVideoSuperResolutionMode{@link #ByteRTCVideoSuperResolutionMode}.
 * @param reason Remote video stream super resolution mode change reason. See ByteRTCVideoSuperResolutionModeChangedReason{@link #ByteRTCVideoSuperResolutionModeChangedReason}
 */
- (void)rtcEngine:(ByteRTCVideo *_Nonnull)engine onRemoteVideoSuperResolutionModeChanged:(ByteRTCRemoteStreamKey*_Nonnull)streamKey
                    withMode:(ByteRTCVideoSuperResolutionMode)mode
                    withReason:(ByteRTCVideoSuperResolutionModeChangedReason)reason NS_SWIFT_NAME(rtcEngine(_:onRemoteVideoSuperResolutionModeChanged:withMode:withReason:));


/**
 * 
 * @hidden not available
 * @type callback
 * @region Audio & Video Processing
 * @brief When the state of the video noise reduction mode changes, this callback will return the real state of the mode and the reasons for the changes.
 * @param engine ByteRTCVideo object
 * @param mode Video noise reduction mode. Refer to ByteRTCVideoDenoiseMode{@link #ByteRTCVideoDenoiseMode} for more details.
 * @param reason Video noise reduction mode change reason. Refer to ByteRTCVideoDenoiseModeChangedReason{@link #ByteRTCVideoDenoiseModeChangedReason} for more <br>
 * details.
 */
- (void)rtcEngine:(ByteRTCVideo *_Nonnull)engine
    onVideoDenoiseModeChanged:(ByteRTCVideoDenoiseMode)mode
                                 withReason:(ByteRTCVideoDenoiseModeChangedReason)reason NS_SWIFT_NAME(rtcEngine(_:onVideoDenoiseModeChanged:withReason:));

#pragma mark - Rtm

/**
 * 
 * @type callback
 * @region Real-time messaging
 * @brief Login result callback
 * @param engine ByteRTCVideo object
 * @param uid <br>
 *        Login user ID
 * @param errorCode <br>
 *        Login result <br>
 *        See ByteRTCLoginErrorCode{@link #ByteRTCLoginErrorCode}.
 * @param elapsed <br>
 *        The time it takes from calling the login:uid:{@link #ByteRTCVideo#login:uid:} interface to return the result. <br>
 *         Is in ms.
 * @note Receive this callback after calling login:uid:{@link #ByteRTCVideo#login:uid:}.
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onLoginResult:(NSString * _Nonnull)uid errorCode:(ByteRTCLoginErrorCode)errorCode elapsed:(NSInteger)elapsed;

/**
 * 
 * @type callback
 * @region Real-time messaging
 * @brief Callback of the logout result
 * @param engine ByteRTCVideo object
 * @param reason It describes the reason why users log out. See ByteRTCLogoutReason{@link #ByteRTCLogoutReason}
 * @note You will receive this callback when calling logout{@link #ByteRTCVideo#logout} or when the local user is kicked out because another user logs in with the same UserId.
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onLogout:(ByteRTCLogoutReason)reason;

/**
 * 
 * @type callback
 * @region Real-time messaging
 * @brief Set the return result of the application server parameter
 * @param engine ByteRTCVideo object
 * @param errorCode <br>
 *         - 200, set successfully
 *         - != 200: Failure. Refer to ByteRTCUserMessageSendResult{@link #ByteRTCUserMessageSendResult} for details.
 * @note Receive this callback after calling setServerParams:url:{@link #ByteRTCVideo#setServerParams:url:}.
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onServerParamsSetResult:(NSInteger)errorCode;

/**
 * 
 * @type callback
 * @region Real-time messaging
 * @brief Returns the result of querying the login status of the peer or local user
 * @param engine ByteRTCVideo object
 * @param peerUserId <br>
 *        User ID to query
 * @param status <br>
 *        User login status of the query <br>
 *        See ByteRTCUserOnlineStatus{@link #ByteRTCUserOnlineStatus}.
 * @note You must first call getPeerOnlineStatus:{@link #ByteRTCVideo#getPeerOnlineStatus:} to receive this callback.
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onGetPeerOnlineStatus:(NSString * _Nonnull)peerUserId status:(ByteRTCUserOnlineStatus)status;

/**
 * 
 * @type callback
 * @region Real-time messaging
 * @brief Receive this callback when you receive a text message from an out-of-room user calling sendUserMessageOutsideRoom:message:config:{@link #ByteRTCVideo#sendUserMessageOutsideRoom:message:config:}
 * @param engine ByteRTCVideo object
 * @param uid <br>
 *        User ID of the message sender
 * @param message <br>
 *        Received text message content
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onUserMessageReceivedOutsideRoom:(NSString * _Nonnull)uid message:(NSString * _Nonnull)message;

/**
 * 
 * @type callback
 * @region Real-time messaging
 * @brief Receive this callback when you receive a binary message from an out-of-room user call sendUserBinaryMessageOutsideRoom:message:config:{@link #ByteRTCVideo#sendUserBinaryMessageOutsideRoom:message:config:}.
 * @param engine ByteRTCVideo object
 * @param  uid <br>
 *          User ID of the message sender
 * @param  message <br>
 *          Binary message content received
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onUserBinaryMessageReceivedOutsideRoom:(NSString * _Nonnull)uid message:(NSData * _Nonnull)message;

/**
 * 
 * @type callback
 * @region Real-time messaging
 * @brief A callback that sends a message to a specified user outside the room
 * @param engine ByteRTCVideo object
 * @param msgid <br>
 *        The ID of this message <br>
 *        All P2P and P2Server messages share a single ID sequence.
 * @param error <br>
 *         Message sending result <br>
 *         See ByteRTCUserMessageSendResult{@link #ByteRTCUserMessageSendResult}.
 * @note Receive this callback when you send a message by calling sendUserMessageOutsideRoom:message:config:{@link #ByteRTCVideo#sendUserMessageOutsideRoom:message:config:} or sendUserBinaryMessageOutsideRoom:message:config:{@link #ByteRTCVideo#sendUserBinaryMessageOutsideRoom:message:config:}.
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onUserMessageSendResultOutsideRoom:(NSInteger)msgid error:(ByteRTCUserMessageSendResult)error;

/**
 * 
 * @type callback
 * @region Real-time messaging
 * @brief Callback to send a message to the application server.
 * @param engine ByteRTCVideo object.
 * @param msgid The ID of this message. All P2P and P2Server messages share a single ID sequence.
 * @param error Message sending result, see ByteRTCUserMessageSendResult{@link #ByteRTCUserMessageSendResult}.
 * @param message The message returned in ACK when the application server receives HTTP request. The message should not exceed 64 KB.
 * @note This callback is asynchronous. Receive this callback when a message is sent by calling the sendServerMessage:{@link #ByteRTCVideo#sendServerMessage:} or sendServerBinaryMessage:{@link #ByteRTCVideo#sendServerBinaryMessage:} interface.
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onServerMessageSendResult:(int64_t)msgid error:(ByteRTCUserMessageSendResult)error message:(NSData * _Nonnull)message;
#pragma mark - Network Probe Methods

/**
 * 
 * @type callback
 * @region Pre-call network detection
 * @brief Callback of pre-call network detection result. <br>
 *        After successfully calling startNetworkDetection:uplinkBandwidth:downlink:downlinkBandwidth:{@link #ByteRTCVideo#startNetworkDetection:uplinkBandwidth:downlink:downlinkBandwidth:}, you will receive this callback for the first time in 3s and every 2s thereafter.
 * @param engine ByteRTCVideo instance.
 * @param type Identifies the network type as uplink/downlink.
 * @param quality Network quality, see ByteRTCNetworkQuality{@link #ByteRTCNetworkQuality}.
 * @param rtt Network RTT in ms.
 * @param lostRate Packet loss rate.
 * @param bitrate Network bandwidth in kbps.
 * @param jitter Network jitter in ms
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onNetworkDetectionResult:(ByteRTCNetworkDetectionLinkType)type quality:(ByteRTCNetworkQuality)quality rtt:(int)rtt lostRate:(double)lostRate bitrate:(int)bitrate jitter:(int)jitter;

/**
 * 
 * @type callback
 * @region Pre-call network probing
 * @brief Pre-call network probing ends <br>
 *        The following will stop detection and receive this primary callback: <br>
 *        1. This callback is received once when the stopNetworkDetection{@link #ByteRTCVideo#stopNetworkDetection} interface is called to stop probing; <br>
 *        2. Stop detection when the first frame of remote/local audio is received; <br>
 *        3. Stop detecting when the detection exceeds 3 minutes; <br>
 *        4. When the probe link is disconnected for a certain period of time, the probe is stopped.
 * @param engine ByteRTCVideo object
 * @param errorCode <br>
 *        See ByteRTCNetworkDetectionStopReason{@link #ByteRTCNetworkDetectionStopReason} for reasons of stopping probing.
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onNetworkDetectionStopped:(ByteRTCNetworkDetectionStopReason)errorCode;
#pragma mark - Log Delegate Methods


/**
 * 
 * @deprecated since 3.45 and will be deleted in 3.51.
 * @type callback
 * @region Engine management
 * @brief SDK Internal log callbacks. <br>
 *        SDK internal runtime will call back the log to the business side to facilitate troubleshooting.
 * @param engine ByteRTCVideo object.
 * @param dict Log content.
 */
- (void)rtcEngine:(ByteRTCVideo* _Nonnull)engine log:(NSDictionary* _Nonnull)dict;
#pragma mark Audio Mix Delegate Methods


/**
 * 
 * @deprecated since 353. Use ByteRTCAudioEffectPlayerEventHandler{@link #ByteRTCAudioEffectPlayerEventHandler} and ByteRTCMediaPlayerEventHandler{@link #ByteRTCMediaPlayerEventHandler} instead.
 * @type callback
 * @region Audio Mixing
 * @brief Callback when audio mix file playback state changes
 * @param engine Current RTC SDK engine object
 * @param mixId <br>
 *        Mix ID <br>
 *        Unique ID passed in when using ByteRTCAudioMixingManager{@link #ByteRTCAudioMixingManager} related interface.
 * @param state <br>
 *        Mix status <br>
 *        The mix status can be referred to: ByteRTCAudioMixingState{@link #ByteRTCAudioMixingState}.
 * @param error <br>
 *         Error code <br>
 *         See ByteRTCAudioMixingError{@link #ByteRTCAudioMixingError}.
 * @note
 *        The timing of this callback will be triggered is summarized as follows: <br>
 *        - When startAudioMixing:filePath:config:{@link #ByteRTCAudioMixingManager#startAudioMixing:filePath:config:} method is successfully called, the callback with the state value ByteRTCAudioMixingStatePlaying will be triggered; otherwise, the callback with the state value ByteRTCAudioMixingStateFailed will be triggered.
 *        - When startAudioMixing:filePath:config:{@link #ByteRTCAudioMixingManager#startAudioMixing:filePath:config:} is repeatedly called with the same ID, the latter overrides the previous one, and this callback notifies the previous mix has stopped with ByteRTCAudioMixingStateStopped.
 *        - When the pauseAudioMixing:{@link #ByteRTCAudioMixingManager#pauseAudioMixing:} method pauses playback successfully, a callback with the state value ByteRTCAudioMixingStatePaused will be triggered; otherwise, a callback with the state value ByteRTCAudioMixingStateFailed will be triggered.
 *        - When calling the resumeAudioMixing:{@link #ByteRTCAudioMixingManager#resumeAudioMixing:} method to resume playback successfully, a callback with the state value ByteRTCAudioMixingStatePlaying will be triggered; otherwise, a callback with the state value ByteRTCAudioMixingStateFailed will be triggered.
 *        - When the stopAudioMixing:{@link #ByteRTCAudioMixingManager#stopAudioMixing:} method stops playing successfully, a callback with the state value ByteRTCAudioMixingStateStopped will be triggered; otherwise, a callback with the state value ByteRTCAudioMixingStateFailed will be triggered.
 *        - The end of playback triggers a callback with the state value ByteRTCAudioMixingStateFinished.
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onAudioMixingStateChanged:(NSInteger)mixId state:(ByteRTCAudioMixingState)state error:(ByteRTCAudioMixingError)error;

/**
 * 
 * @type callback
 * @region Audio Mixing
 * @brief Callback for playback progress of mixed audio files
 * @param engine Current RTC SDK object
 * @param mixId ID of the mixing task
 * @param progress The current playback progress (ms) of the mixed audio file
 * @note After calling setAudioMixingProgressInterval:interval:{@link #ByteRTCAudioMixingManager#setAudioMixingProgressInterval:interval:} to set the time interval to a value greater than 0, or calling startAudioMixing:filePath:config:{@link #ByteRTCAudioMixingManager#startAudioMixing:filePath:config:} to set the time interval in ByteRTCAudioMixingConfig{@link #ByteRTCAudioMixingConfig} to a value greater than 0, the SDK will trigger the callback according to the set time interval.
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onAudioMixingPlayingProgress:(NSInteger)mixId progress:(int64_t) progress;
#pragma mark Performance Delegate Methods


/**
 * 
 * @type callback
 * @region  audio & video fallback
 * @brief When the publish performance fallback setPublishFallbackOption:{@link #ByteRTCVideo#setPublishFallbackOption:} is not turned on locally, and when insufficient device performance is detected, this callback is received. <br>
 *        When the setPublishFallbackOption:{@link #ByteRTCVideo#setPublishFallbackOption:} is locally turned on, and when the publish performance fallback/recovery is caused due to device performance/network reasons, this callback is received.
 * @param engine ByteRTCVideo object
 * @param mode  Indicates whether the release fallback function is turned on locally. See ByteRTCPerformanceAlarmMode{@link #ByteRTCPerformanceAlarmMode} <br>
 *              - When the publisher does not turn on the release performance fallback, the mode value is ByteRTCPerformanceAlarmModeNormal.
 *              - When the publisher turns on the release performance fallback, the mode value is ByteRTCPerformanceAlarmModeSimulcast.
 * @param roomId <br>
 *                 - When the release performance fallback is not turned on, the roomId is empty
 *                 - When the release performance fallback is turned on, the roomId is the room ID affected by the alarm.
 * @param reason For alarm reasons. See ByteRTCPerformanceAlarmReason{@link #ByteRTCPerformanceAlarmReason}
 * @param data Performance fallback related data. See ByteRTCSourceWantedData{@link #ByteRTCSourceWantedData}.
 */
- (void)rtcEngine:(ByteRTCVideo *_Nonnull)engine onPerformanceAlarms:(ByteRTCPerformanceAlarmMode)mode
                         roomId:(NSString *_Nonnull)roomId
                         reason:(ByteRTCPerformanceAlarmReason)reason
               sourceWantedData:(ByteRTCSourceWantedData *_Nonnull)data;

/**
 * 
 * @type callback
 * @region audio & video rollback
 * @brief Once the fallback option is set, fallback or reverting from a Fallback of a media stream will trigger this callback.
 * @param engine Current ByteRTCVideo instance
 * @param event Information of stream switching. Refer to ByteRTCRemoteStreamSwitchEvent{@link #ByteRTCRemoteStreamSwitchEvent} for more details.
 */
- (void)rtcEngine:(ByteRTCVideo *_Nonnull)engine onSimulcastSubscribeFallback:(ByteRTCRemoteStreamSwitchEvent *_Nonnull)event;

#if BYTERTC_TARGET_MAC

/**
 * 
 * @hidden(iOS)
 * @type callback
 * @brief After calling setOriginalScreenVideoInfo:withOriginalCaptureHeight:{@link #ByteRTCVideo#setOriginalScreenVideoInfo:withOriginalCaptureHeight:} to set the original width and height of the external shared-screen stream and setting the encoding mode to the automatic mode, you will receive this callback to re-capture the stream based on the recommended pixel and framerate by RTC.
 * @param frameUpdateInfo The recommended pixel and framerate by RTC. See ByteRTCFrameUpdateInfo{@link #ByteRTCFrameUpdateInfo}.
 */
- (void)rtcEngine: (ByteRTCVideo* _Nonnull)engine onExternalScreenFrameUpdate: (ByteRTCFrameUpdateInfo* _Nullable)frameUpdateInfo;
#endif
#pragma mark Proxy Delegate Methods


/**
 * 
 * @type callback
 * @deprecated since 3.52, will be deleted at 3.57, use rtcEngine:onLocalProxyStateChanged:withProxyState:withProxyError:{@link #ByteRTCVideoDelegate#rtcEngine:onLocalProxyStateChanged:withProxyState:withProxyError:} instead
 * @region Network proxy
 * @brief This callback is triggered when the HTTP proxy connection status changes.
 * @param engine ByteRTCVideo object
 * @param state Current HTTP proxy connection status
 */
- (void)rtcEngine:(ByteRTCVideo *_Nonnull)engine onHttpProxyState:(NSInteger)state;

/**
 * 
 * @type callback
 * @deprecated since 3.52, will be deleted at 3.57, use rtcEngine:onLocalProxyStateChanged:withProxyState:withProxyError:{@link #ByteRTCVideoDelegate#rtcEngine:onLocalProxyStateChanged:withProxyState:withProxyError:} instead
 * @region Network proxy
 * @brief This callback is triggered when the HTTPS proxy connection status changes.
 * @param engine ByteRTCVideo object
 * @param state Current HTTPS proxy connection status
 */
- (void)rtcEngine:(ByteRTCVideo *_Nonnull)engine onHttpsProxyState:(NSInteger)state;

/**
 * 
 * @type callback
 * @deprecated since 3.52, will be deleted at 3.57, use rtcEngine:onLocalProxyStateChanged:withProxyState:withProxyError:{@link #ByteRTCVideoDelegate#rtcEngine:onLocalProxyStateChanged:withProxyState:withProxyError:} instead
 * @region Network proxy
 * @brief This callback is triggered when the Socks proxy connection status changes.
 * @param engine ByteRTCVideo object
 * @param state SOCKS5 proxy connection status
 * @param cmd Every step of the proxy connection operating command
 * @param proxyAddress Proxy address information
 * @param localAddress Local address used by the current connection
 * @param remoteAddress Remote connection address
 */
- (void)rtcEngine:(ByteRTCVideo *_Nonnull)engine onSocks5ProxyState:(NSInteger)state
                   cmd:(NSString *_Nonnull)cmd
         proxy_address:(NSString *_Nonnull)proxyAddress
         local_address:(NSString *_Nonnull)localAddress
        remote_address:(NSString *_Nonnull)remoteAddress;
#pragma mark FileRecording related callback

/**
 * 
 * @type callback
 * @region  local recording
 * @brief  Get local recording status callback. <br>
 *         The callback is triggered by either startFileRecording:withRecordingConfig:type:{@link #ByteRTCVideo#startFileRecording:withRecordingConfig:type:} or stopFileRecording:{@link #ByteRTCVideo#stopFileRecording:}.
 * @param engine ByteRTCVideo object
 * @param type Stream properties of the recorded stream. See ByteRTCStreamIndex{@link #ByteRTCStreamIndex}
 * @param state Recording status. See ByteRTCRecordingState{@link #ByteRTCRecordingState}
 * @param errorCode Recording error code. See ByteRTCRecordingErrorCode{@link #ByteRTCRecordingErrorCode}
 * @param recordingInfo Recording file details. See ByteRTCRecordingInfo{@link #ByteRTCRecordingInfo}
 */
- (void)rtcEngine:(ByteRTCVideo* _Nonnull)engine onRecordingStateUpdate:(ByteRTCStreamIndex)type
                         state:(ByteRTCRecordingState)state
                    error_code:(ByteRTCRecordingErrorCode)errorCode
                recording_info:(ByteRTCRecordingInfo* _Nonnull)recordingInfo;

/**
 * 
 * @type callback
 * @region  local recording
 * @brief  Local recording progress callback. <br>
 *        This callback is triggered by startFileRecording:withRecordingConfig:type:{@link #ByteRTCVideo#startFileRecording:withRecordingConfig:type:}. When the recording state is normal, the system will prompt the recording progress through this callback every second.
 * @param engine ByteRTCVideo object
 * @param type Stream properties of the recorded stream. See ByteRTCStreamIndex{@link #ByteRTCStreamIndex}
 * @param process Recording progress. See ByteRTCRecordingProgress{@link #ByteRTCRecordingProgress}
 * @param recordingInfo Details of the recorded file. See ByteRTCRecordingInfo{@link #ByteRTCRecordingInfo}
 */
- (void)rtcEngine:(ByteRTCVideo* _Nonnull)engine onRecordingProgressUpdate:(ByteRTCStreamIndex)type
                          process:(ByteRTCRecordingProgress* _Nonnull)process
                   recording_info:(ByteRTCRecordingInfo* _Nonnull)recordingInfo;

/**
* 
*  @type callback
*  @brief When calling startAudioRecording:{@link #ByteRTCVideo#startAudioRecording:} or stopAudioRecording{@link #ByteRTCVideo#stopAudioRecording} to change the recording status, receive the callback.
 * @param engine ByteRTCVideo object
*  @param state See ByteRTCAudioRecordingState{@link #ByteRTCAudioRecordingState}.
*  @param errorCode See ByteRTCAudioRecordingErrorCode{@link #ByteRTCAudioRecordingErrorCode}.
*/
- (void)rtcEngine:(ByteRTCVideo* _Nonnull)engine
        onAudioRecordingStateUpdate:(ByteRTCAudioRecordingState)state
                         error_code:(ByteRTCAudioRecordingErrorCode)errorCode;


/**
 * 
 * @hidden currently not available
 * @type callback
 * @brief Callback of the result of publishing the public stream <br>
 *        You will be informed of the result of publishing the public stream by this callback after calling startPushPublicStream:withLayout:{@link #ByteRTCVideo#startPushPublicStream:withLayout:}.
 * @param engine engine instance
 * @param roomId Room ID from which the public stream is published
 * @param streamId ID of the public stream
 * @param errorCode Result and status code of publishing the public stream. Refer to ByteRTCPublicStreamErrorCode{@link #ByteRTCPublicStreamErrorCode} for details.
 */
- (void)rtcEngine:(ByteRTCVideo *_Nonnull)engine onPushPublicStreamResult:(NSString *_Nonnull)roomId
        publicStreamId:(NSString *_Nonnull)streamId
        errorCode:(ByteRTCPublicStreamErrorCode)errorCode;


/**
 * 
 * @hidden currently not available
 * @type callback
 * @brief Callback of the result of subscribing to the public stream <br>
 *        You will be informed of the result of subscribing to the public stream by this callback after calling startPushPublicStream:withLayout:{@link #ByteRTCVideo#startPushPublicStream:withLayout:}.
 * @param engine engine instance
 * @param publicStreamId ID of the public stream
 * @param errorCode Result and status code of subscribing to the public stream. Refer to ByteRTCPublicStreamErrorCode{@link #ByteRTCPublicStreamErrorCode} for details.
 */
- (void)rtcEngine:(ByteRTCVideo *_Nonnull)engine onPlayPublicStreamResult:(NSString *_Nonnull)publicStreamId
        errorCode:(ByteRTCPublicStreamErrorCode)errorCode;

/**
 * 
 * @hidden currently not available
 * @type callback
 * @brief Callback on receiving the SEI message carried by the public video stream. <br>
 *        After calling startPlayPublicStream:{@link #ByteRTCVideo#startPlayPublicStream:}, you will receive this callback if the public stream has an SEI message.
 * @param engine The ByteRTCVideo instance.
 * @param publicStreamId The ID of the public stream.
 * @param message The SEI(supplemental enhancement information) message carried by the public video stream. <br>
 * The SEI you can get via this callback is inserted by calling `sendSEIMessage:andMessage:andRepeatCount:andCountPerFrame:` in the SDK. <br>
 * You receive SEI from all the video streams if the SEI messages do not have conflicts. However, if the SEI messages from different video streams have conflicts, you will receive only one of them.
 * @param sourceType SEI source type.  Since V3.52.1, the value is always `0`, for custom messages. Refer to ByteRTCDataMessageSourceType{@link #ByteRTCDataMessageSourceType}.
 * @note
 * You also need to listen to rtcEngine:onPublicStreamDataMessageReceived:andMessage:andSourceType:{@link #ByteRTCVideoDelegate#rtcEngine:onPublicStreamDataMessageReceived:andMessage:andSourceType:} to receive data messages inserted via Open API in the server.
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onPublicStreamSEIMessageReceived:(NSString* _Nonnull)publicStreamId andMessage:(NSData* _Nonnull)message andSourceType:(ByteRTCDataMessageSourceType)sourceType;

/**
  * 
  * @hidden currently not available
  * @type callback
  * @brief Callback on receiving the data message carried by the public video stream. <br>
  * After calling startPlayPublicStream:{@link #ByteRTCVideo#startPlayPublicStream:}, you can listen to this callback and retrieve SEI messages inserted by Open API calls or audio volume.
  * @param engine The ByteRTCVideo instance.
  * @param publicStreamId ID of the public stream
  * @param message The data messages carried by the public video stream. <br>
  * - Data inserted by calling the OpenAPI.
  * - Media volume in JSON, before you can receive which you need to enable it via calling the OpenAPI. Refer to the definition below to parse the JSON string.
  * { <br>
  * &nbsp;&nbsp;&nbsp;&nbsp;"Type"&nbsp;:&nbsp;"VolumeIndication", <br>
  * &nbsp;&nbsp;&nbsp;&nbsp;"VolumeInfos":[ <br>
  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{ <br>
  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"RoomId":"1000001", <br>
  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"UserId":"1000001", <br>
  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"StreamType":0,&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"LinearVolume":1 <br>
  * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;} <br>
  * &nbsp;&nbsp;&nbsp;&nbsp;] <br>
  * }
  * @param sourceType Message source. Refer to ByteRTCDataMessageSourceType{@link #ByteRTCDataMessageSourceType}.
  * @note You also need to listen to rtcEngine:onPublicStreamSEIMessageReceived:andMessage:andSourceType:{@link #ByteRTCVideoDelegate#rtcEngine:onPublicStreamSEIMessageReceived:andMessage:andSourceType:} to receive SEI inserted via API in the client SDK.
  */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onPublicStreamDataMessageReceived:(NSString* _Nonnull)publicStreamId andMessage:(NSData* _Nonnull)message andSourceType:(ByteRTCDataMessageSourceType)sourceType;

    
    /**
     * 
     * @valid since 3.56
     * @hidden for internal use only
     * @type callback
     * @brief Callback on receiving the SEI message carried by the public video stream. <br>
     *        After calling startPlayPublicStream:{@link #ByteRTCVideo#startPlayPublicStream:}, you will receive this callback if the public stream has an SEI message.
     * @param publicStreamId The ID of the public stream.
     * @param channelId SEI message channel ID. The value range is [0 - 255]. With this parameter, you can set different ChannelIDs for different recipients. In this way, different recipients can choose the SEI information  based on the ChannelID received in the callback.
     * @param message The SEI(supplemental enhancement information) message carried by the public video stream. <br>
     * The SEI you can get via this callback is inserted by calling `sendPublicStreamSEIMessage` in the SDK.
     */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onPublicStreamSEIMessageReceivedWithChannel:(NSString* _Nonnull)publicStreamId andChannelId:(int)channelId andMessage:(NSData* _Nonnull)message;

/**
 * 
 * @hidden currently not available
 * @type callback
 * @brief Callback of successfully decoding of the first video frame of the public stream <br>
 *        Refer to startPlayPublicStream:{@link #ByteRTCVideo#startPlayPublicStream:} for details about subscribing to a public stream.
 * @param engine ByteRTCVideo instance
 * @param publicStreamId ID of the public stream
 * @param frameInfo Information of the video stream. Refer to ByteRTCVideoFrameInfo{@link #ByteRTCVideoFrameInfo} for more details.
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onFirstPublicStreamVideoFrameDecoded:(NSString * _Nonnull)publicStreamId withFrameInfo:(ByteRTCVideoFrameInfo * _Nonnull)frameInfo NS_SWIFT_NAME(rtcEngine(_:onFirstPublicStreamVideoFrameDecoded:withFrameInfo:));

/**
 * 
 * @hidden currently not available
 * @type callback
 * @brief Callback of successfully decoding of the first audio frame of the public stream <br>
 *        Refer to startPlayPublicStream:{@link #ByteRTCVideo#startPlayPublicStream:} for details about subscribing to a public stream.
 * @param engine ByteRTCVideo instance
 * @param publicStreamId ID of the public stream
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onFirstPublicStreamAudioFrame:(NSString * _Nonnull)publicStreamId;

/**
 * 
 * @type callback
 * @brief Receives the callback when you call startCloudProxy:{@link #ByteRTCVideo#startCloudProxy:} to start cloud proxy, and the SDK connects the proxy server successfully.
 * @param engine ByteRTCVideo object
 * @param interval The interval in ms between starting cloud proxy and connects the cloud proxy server successfully.
 */
- (void)rtcEngine:(ByteRTCVideo *  _Nonnull)engine onCloudProxyConnected:(NSInteger)interval;

/**
 * 
 * @type callback
 * @region Network Management
 * @brief Callback about the call test result.
 * @param engine `ByteRTCVideo` instance
 * @param result Test result, see ByteRTCEchoTestResult{@link #ByteRTCEchoTestResult}.
 * @note The timing when this callback will be triggered is as follows: <br>
 *        - A device-related error occurred during the test；
 *        - After a successful test；
 *        - After stopping the test, provided that the audio/video playback was not received during the test due to non-device reasons.
 */
- (void)rtcEngine:(ByteRTCVideo *_Nonnull)engine onEchoTestResult:(ByteRTCEchoTestResult)result NS_SWIFT_NAME(rtcEngine(_:onEchoTestResult:));


/**
 * 
 * @hidden for internal use only
 * @type callback
 * @brief audio dump status change callback
 * @param engine ByteRTCVideo object
 * @param status audio dump status, see ByteRTCAudioDumpStatus{@link #ByteRTCAudioDumpStatus}.
 * @note This callback is used to internally troubleshoot sound quality related exceptions, which developers need not pay attention to.
 */
- (void)rtcEngine: (ByteRTCVideo* _Nonnull)engine onAudioDumpStateChanged: (ByteRTCAudioDumpStatus)status;

/**
 * 
 * @type callback
 * @brief After calling getNetworkTimeInfo{@link #ByteRTCVideo#getNetworkTimeInfo} for the first time, the SDK starts network time synchronization internally. This callback will be triggered when the synchronization is completed.
 * @param engine See ByteRTCVideo{@link #ByteRTCVideo}.
 */
- (void)rtcEngineOnNetworkTimeSynchronized:(ByteRTCVideo *_Nonnull)engine;


/**
 * 
 * @hidden internal use only
 * @type callabck
 * @brief License expiration time reminder
 * @param engine ByteRTCVideo{@link #ByteRTCVideo} object.
 * @param days Expiration time in days
 */
- (void)rtcEngine:(ByteRTCVideo *  _Nonnull)engine onLicenseWillExpire:(NSInteger)days;

/**
 * 
 * @hidden internal use
 * @valid since 3.52
 * @type callabck
 * @brief callback for experimental api
 * @param param result of callback in JSON string
 * @list Engine Management
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onInvokeExperimentalAPI:(NSString * _Nonnull) param;


/**
 * 
 * @type callback
 * @brief Callback that notifies you the result of the echo detection before a call
 * @param engine ByteRTCVideo{@link #ByteRTCVideo} object.
 * @param result Refer to ByteRTCHardwareEchoDetectionResult{@link #ByteRTCHardwareEchoDetectionResult} for more details.
 * @note
 *        - This callback notifies you the result of the echo detection by calling startHardwareEchoDetection:{@link #ByteRTCVideo#startHardwareEchoDetection:}.
 *        - We recommend to call stopHardwareEchoDetection{@link #ByteRTCVideo#stopHardwareEchoDetection} to stop the detection.
 *        - Listen to `ByteRTCMediaDeviceWarningDetectLeakEcho` in the callback of rtcEngine:onAudioDeviceWarning:deviceType:deviceWarning:{@link #ByteRTCVideoDelegate#rtcEngine:onAudioDeviceWarning:deviceType:deviceWarning:} for the echo issue during a call.
 */
- (void)rtcEngine:(ByteRTCVideo *_Nonnull)engine onHardwareEchoDetectionResult:(ByteRTCHardwareEchoDetectionResult)result NS_SWIFT_NAME(rtcEngine(_:onHardwareEchoDetectionResult:));

/**
 * 
 * @type callback
 * @region proxy
 * @brief Callback on local proxy connection. After calling setLocalProxy:{@link #ByteRTCVideo#setLocalProxy:} to set local proxies, you will receive this callback that informs you of the states of local proxy connection.
 * @param engine ByteRTCVideo{@link #ByteRTCVideo} object.
 * @param type The types of local proxies. Refer to ByteRTCLocalProxyType{@link #ByteRTCLocalProxyType} for details.
 * @param state The states of local proxy connection. Refer to ByteRTCLocalProxyState{@link #ByteRTCLocalProxyState} for details.
 * @param error The errors of local proxy connection. Refer to ByteRTCLocalProxyError{@link #ByteRTCLocalProxyError} for details.
 */
- (void)rtcEngine:(ByteRTCVideo * _Nonnull)engine onLocalProxyStateChanged:(ByteRTCLocalProxyType)type withProxyState:(ByteRTCLocalProxyState)state withProxyError:(ByteRTCLocalProxyError)error;

/**
 * 
 * @hidden internal use only
 * @type callback
 * @brief When effect settings fail, this callback is received.
 * @param engine ByteRTCVideo{@link #ByteRTCVideo} object.
 * @param error Type of effect error. See ByteRTCEffectErrorType{@link #ByteRTCEffectErrorType} for details.
 * @param msg Error message.
 */
- (void)rtcEngine:(ByteRTCVideo *_Nonnull)engine onEffectError:(ByteRTCEffectErrorType)error msg:(NSString * _Nonnull)msg;


/**
 * 
 * @type callback
 * @brief Triggered after calling takeSnapshotToFile:filePath:{@link #ByteRTCVideo#takeSnapshotToFile:filePath:} to report whether the snapshot is taken successfully and provide details of the snapshot image.
 * @param streamKey Information of the snapshotted video stream. See ByteRTCRemoteStreamKey{@link #ByteRTCRemoteStreamKey}.
 * @param filePath The path where the snapshot file is saved.
 * @param width The width (px) of the snapshot image.
 * @param height The height (px) of the snapshot image.
 * @param errorCode The error code for the snapshot task. See ByteRTCSnapshotErrorCode{@link #ByteRTCSnapshotErrorCode} for specific indications.
 * @param taskId The index of the snapshot task, which matches the return value of takeSnapshotToFile:filePath:{@link #ByteRTCVideo#takeSnapshotToFile:filePath:}.
 * @list Advanced Features
 */
- (void)rtcEngine:(ByteRTCVideo *_Nonnull)engine onSnapshotTakenToFile:(ByteRTCRemoteStreamKey*)streamKey filePath:(NSString * _Nonnull)filePath width:(NSInteger)width height:(NSInteger)height errorCode:(ByteRTCSnapshotErrorCode)errorCode taskId:(NSInteger)taskId;
@end
#pragma mark - RTCVideo

/**
 * 
 * @type api
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCVideo : NSObject

/**
 * 
 * @type callback
 */
@property (nonatomic, weak) id<ByteRTCVideoDelegate> _Nullable delegate;

/**
 * 
 * @hidden
 * @deprecated
 */
@property (nonatomic, weak) id<ByteRTCMonitorDelegate> _Nullable monitorDelegate
    __deprecated_msg("Will be removed in new version");

#pragma mark Core Methods

/**
 * 
 * @hidden for internal use only
 */
+ (void)setDeviceId:(NSString* _Nonnull) deviceID;



/**
 * 
 * @type api
 * @region Engine Management
 * @brief Creates an engine instance. <br>
 *        This is the very first API that you must call if you want to use all the RTC capabilities. <br>
 *        If there is no engine instance in current process, calling this API will create one. If an engine instance has been created, calling this API again will have the created engine instance returned.
 * @param appId A unique identifier for each App, randomly generated by the RTC console. Engine instances created with different AppIds cannot communicate with each other.
 * @param delegate Delegate sent from SDK to App. See ByteRTCVideoDelegate{@link #ByteRTCVideoDelegate}
 * @param parameters Reserved parameters. Please contact technical support fellow if needed.
 * @return A ByteRTCVideo{@link #ByteRTCVideo} instance
 * @list Engine Management
 * @order 1
 */
+ (ByteRTCVideo * _Nullable) createRTCVideo:(NSString * _Nonnull)appId
                                      delegate:(id<ByteRTCVideoDelegate> _Nullable)delegate
                                    parameters:(NSDictionary * _Nonnull)parameters;


/**
 * 
 * @hidden internal use only
 * @type api
 * @region Engine Management
 * @brief Creates an engine instance for multi-engine senario. <br>
 *        This is the very first API that you must call if you want to use all the RTC capabilities. <br>
 *        If there is no engine instance in current process, calling this API will create one. If an engine instance has been created, calling this API again will have a new created engine instance returned.
 * @param context Android application context
 * @param appId A unique identifier for each App, randomly generated by the RTC console. Engine instances created with different AppIds cannot communicate with each other.
 * @param handler Handler sent from SDK to App. See IRTCVideoEventHandler{@link #IRTCVideoEventHandler}
 * @param eglContext If you need SDK to support custom texture hardcoding, you must import the eglContext in a JObject.
 * @param parameters Reserved parameters. Please contact technical support fellow if needed.
 * @return
 *         - RTCVideo: A successfully created engine instance.
 *         - Null: Failed to load the .so file. No instance is returned.
 * @note The lifecycle of the handler must be longer than that of the RTCVideo, i.e. the handler must be created before calling createRTCVideo:delegate:parameters:{@link #RTCVideo#createRTCVideo:delegate:parameters:} and destroyed after calling destroyRTCVideo{@link #ByteRTCVideo#destroyRTCVideo}.
 */
+ (ByteRTCVideo * _Nullable) createRTCVideoMulti:(NSString * _Nonnull)appId
                               delegate:(id<ByteRTCVideoDelegate> _Nullable)delegate
                                      parameters:(NSDictionary * _Nonnull)parameters;


/**
 * 
 * @type api
 * @region Engine Management
 * @brief Destroy the engine instance created by createRTCVideo:delegate:parameters:{@link #ByteRTCVideo#createRTCVideo:delegate:parameters:}, and release all related resources.
 * @note
 *       - Call this API after all business scenarios related to the engine instance are destroyed.
 *       - When the API is called, RTC SDK destroys all memory associated with the engine instance and stops any interaction with the media server.
 *       - Calling this API will start the SDK exit logic. The engine thread is held until the exit logic is complete. The engine thread is retained until the exit logic is complete. Therefore, do not call this API directly in the callback thread, or it will cause a deadlock. This function takes a long time to execute, so it's not recommended to call this API in the main thread, or the main thread may be blocked.
 *       - You can enable ARC for Objective-C, to automatically trigger the destruction logic when the dealloc method is called.
 * @list Engine Management
 * @order 2
 */
+ (void)destroyRTCVideo NS_SWIFT_NAME(destroyRTCVideo());

/**
 * 
 * @hidden internal use only
 * @type api
 * @region Engine Management
 * @brief Destroy the engine instance created by createRTCVideoMulti:delegate:parameters:{@link #ByteRTCVideo#createRTCVideoMulti:delegate:parameters:}, and release all related resources.
 * @note
 *       - Call this API after all business scenarios related to the ByteRTCVideo{@link #ByteRTCVideo} instance are destroyed.
 *       - When the API is called, RTC SDK destroys all memory associated with the ByteRTCVideo{@link #ByteRTCVideo} instance and stops any interaction with the media server.
 *       - Calling this API will start the SDK exit logic. The engine thread is held until the exit logic is complete. The engine thread is retained until the exit logic is complete. Therefore, do not call this API directly in the callback thread, or it will cause a deadlock. This function takes a long time to execute, so it's not recommended to call this API in the main thread, or the main thread may be blocked.
 *       - You can enable ARC for Objective-C, to automatically trigger the destruction logic when the dealloc method is called.
 */
+ (void)destroyRTCVideoMulti:(ByteRTCVideo*)engine;


/**
 * 
 * @type api
 * @region  engine management
 * @brief  Gets the current version number of the SDK.
 * @return SDK  The current version number.
 * @list Engine Management
 * @order 5
 */
+ (NSString * _Nonnull)getSDKVersion;


/**
 * 
 * @type api
 * @region Engine Management
 * @brief Configures the local log parameters of RTC SDK, including the logging level, directory, the limits for total log file size, and the prefix of log file name.
 * @param logConfig Local log parameters. See ByteRTCLogConfig{@link #ByteRTCLogConfig}.
 * @return
 *        - 0: Success.
 *        - –1: Failure. This API must be called before creating engine.
 *        - –2: Failure. Invalid parameters.
 * @note This API must be called before createRTCVideo:delegate:parameters:{@link #ByteRTCVideo#createRTCVideo:delegate:parameters:}.
 * @list Engine Management
 * @order 30
 */
+ (int) setLogConfig:(ByteRTCLogConfig *_Nonnull) logConfig;


/**
 * 
 * @type api
 * @region  engine management
 * @brief Gets the description text of different error codes and warning codes in the SDK.
 * @param code <br>
 *        The value obtained by rtcEngine:onWarning:{@link #ByteRTCVideoDelegate#rtcEngine:onWarning:} and rtcEngine:onError:{@link #ByteRTCVideoDelegate#rtcEngine:onError:} callbacks, <br>
 *        For details, please refer to ByteRTCWarningCode{@link #ByteRTCWarningCode} and ByteRTCErrorCode{@link #ByteRTCErrorCode}.
 * @return  Description text.
 * @list Engine Management
 * @order 15
 */
+ (NSString * _Nonnull)getErrorDescription:(NSInteger)code;
#pragma mark Core Audio Methods


/**
 * 
 * @type api
 * @region Custom Audio Capture and Rendering
 * @brief Switches the audio capture type.
 * @param type Audio input source type. See ByteRTCAudioSourceType{@link #ByteRTCAudioSourceType} <br>
 *            Use internal audio capture by default. The audio capture type and the audio render type may be different from each other.
 * @return  Method call result: <br>
 *         - >0: Success.
 *         - -1: Failure.
 * @note
 *       - You can call this API before or after joining the room.
 *       - If you call this API to switch from internal audio capture to custom capture, the internal audio capture is automatically disabled. You must call pushExternalAudioFrame:{@link #ByteRTCVideo#pushExternalAudioFrame:} to push custom captured audio data to RTC SDK for transmission.
 *       - If you call this API to switch from custom capture to internal capture, you must then call startAudioCapture{@link #ByteRTCVideo#startAudioCapture} to enable internal capture.
 */
- (int)setAudioSourceType:(ByteRTCAudioSourceType) type;

/**
 * 
 * @type api
 * @region Custom Audio Capture and Rendering
 * @brief Switches the audio render type.
 * @param type Audio output source type. See ByteRTCAudioRenderType{@link #ByteRTCAudioRenderType}. <br>
 *             Use internal audio render by default. The audio capture type and the audio render type may be different from each other.
 * @return   Method call result: <br>
 *         - >0: Success.
 *         - -1: Failure.
 * @note
 *       - You can call this API before or after joining the room.
 *       - After calling this API to enable custom audio rendering, call pullExternalAudioFrame:{@link #ByteRTCVideo#pullExternalAudioFrame:} for audio data.
 */
- (int)setAudioRenderType:(ByteRTCAudioRenderType) type;

/**
 * 
 * @type api
 * @region Audio management
 * @brief Starts internal audio capturing. The default is off. <br>
 *        Internal capture refers to audio capture using the built-in capture module of the SDK. <br>
 *        After this API is called, the local user will receive rtcEngine:onAudioDeviceStateChanged:device_type:device_state:device_error:{@link #ByteRTCVideoDelegate#rtcEngine:onAudioDeviceStateChanged:device_type:device_state:device_error:}. <br>
 *        The remote clients in the room will be informed of the state change via rtcEngine:onUserStartAudioCapture:uid:{@link #ByteRTCVideoDelegate#rtcEngine:onUserStartAudioCapture:uid:} after the visible user starts audio capture by calling this API.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *        - Calling this API without obtaining permission to use the microphone of the current device will trigger rtcEngine:onWarning:{@link #ByteRTCEngineDelegate#rtcEngine:onWarning:}.
 *        - Call stopAudioCapture{@link #ByteRTCEngine#stopAudioCapture} to stop the internal audio capture. Otherwise, the internal audio capture will sustain until you destroy the engine instance.
 *        - To mute and unmute microphones, we recommend using publishStreamAudio:{@link #ByteRTCRoom#publishStreamAudio:}, other than stopAudioCapture{@link #ByteRTCEngine#stopAudioCapture} and this API. Because starting and stopping capture devices often need some time waiting for the response of the device, that may lead to a short silence during the communication.
 *        - Once you create the engine instance, you can start internal audio capture regardless of the audio publishing state. The audio stream will start publishing only after the audio capture starts.
 *        - To switch from custom to internal audio capture, stop publishing before disabling the custom audio capture module by calling setAudioSourceType:{@link #ByteRTCVideo#setAudioSourceType:} and then call this API to enable the internal audio capture.
 * @list Audio Management
 * @order 8
 */
- (int)startAudioCapture;
 
 /**
  * 
  * @type api
  * @region audio management
  * @brief Stops internal audio capturing. The default is off. <br>
  *        Internal audio capture refers to: capturing audio using the built-in module. <br>
  *        The local client will be informed via rtcEngine:onAudioDeviceStateChanged:device_type:device_state:device_error:{@link #ByteRTCVideoDelegate#rtcEngine:onAudioDeviceStateChanged:device_type:device_state:device_error:} after stopping audio capture by calling this API. <br>
  *         The remote clients in the room will be informed of the state change via rtcEngine:onUserStopAudioCapture:uid:{@link #ByteRTCVideoDelegate#rtcEngine:onUserStopAudioCapture:uid:} after the visible client stops audio capture by calling this API.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
  * @note
  *        - Call startAudioCapture{@link #ByteRTCVideo#startAudioCapture} to enable the internal audio capture.
  *        - Without calling this API the internal audio capture will sustain until you destroy the engine instance.
  */
- (int)stopAudioCapture;

/**
 * 
 * @hidden(macOS)
 * @type api
 * @region Audio management
 * @brief Sets the audio scenarios. <br>
 *        You can choose the appropriate audio scenario according to your application. <br>
 *        After selecting the audio scenario, SDK will automatically select the call/media volume  according to the client-side audio device and status, and synchronously change the corresponding audio-related algorithm configurations and capture configurations.
 * @param audioScenario  Audio scenarios. See ByteRTCAudioScenarioType{@link #ByteRTCAudioScenarioType}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *         - It is recommended to call this API before joining the room and calling other audio related interfaces. If this API is called afterwards, audio lag may be introduced.
 *         - Call volume is more suitable for calls, meetings and other scenarios that demand information accuracy. Call volume will activate the system hardware signal processor, making the sound clearer. The volume cannot be reduced to 0.
 *         - Media volume is more suitable for entertainment scenarios, which require musical expression. The volume can be reduced to 0.
 */
- (int)setAudioScenario:(ByteRTCAudioScenarioType)audioScenario;

/**
 * 
 * @valid since 3.55
 * @hidden internal use only
 * @type api
 * @brief Sets the audio scenarios. <br>
 *        After selecting the audio scenario, SDK will automatically switch to the proper volume modes (the call/media volume) according to the scenarios and the best audio configurations under such scenarios. This API is different with `setAudioScenario` in that `audioScenario` will only change the volume mode and will not change the algorithm related to audio. <br>
 *        This API should not be used at the same time with the old one.
 * @param audioScene Audio scenarios. See ByteRTCAudioSceneType{@link #ByteRTCAudioSceneType}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *        - You can use this API both before and after joining the room.
 *        - Call volume is more suitable for calls, meetings and other scenarios that demand information accuracy. Call volume will activate the system hardware signal processor, making the sound clearer. The volume cannot be reduced to 0.
 *        - Media volume is more suitable for entertainment scenarios, which require musical expression. The volume can be reduced to 0.
 */
- (int)setAudioScene:(ByteRTCAudioSceneType)audioScene;


/**
 * 
 * @type api
 * @region audio management
 * @brief Sets the sound quality. You should choose the appropriate sound quality according to the needs of the business scenario.
 * @param audioProfile  Sound quality. See ByteRTCAudioProfileType{@link #ByteRTCAudioProfileType}
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *         - This method can be called before and after entering the room;
 *         - Support dynamic switching of sound quality during a call.
 */
- (int)setAudioProfile:(ByteRTCAudioProfileType)audioProfile;

/**
 * 
 * @type api
 * @region audio management
 * @brief Set the Active Noise Cancellation(ANC) mode during audio and video communications.
 * @param ansMode ANC modes. See ByteRTCAnsMode{@link #ByteRTCAnsMode}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note  - You can call this API before or after entering a room. When you repeatedly call it, only the last call takes effect.
 *        In versions prior to V3.57.1, the AI noise cancellation can be enabled by calling this interface only in the following ByteRTCRoomProfile{@link #ByteRTCRoomProfile} scenarios. <br>
 *                - Game Voice: `ByteRTCRoomProfileGame`
 *                - High-Quality Game: `ByteRTCRoomProfileGameHD`
 *                - Cloud Gaming: `ByteRTCRoomProfileCloudGame`
 *                - 1 vs 1 Audio and Video Call: `ByteRTCRoomProfileChat`
 *                - Multi-End Synchronized Audio and Video Playback: `ByteRTCRoomProfileLwTogether`
 *                - Personal Device in Cloud Meeting: `ByteRTCRoomProfileMeeting`
 *                - Classroom Interaction: `ByteRTCRoomProfileClassroom`
 *                - Conference Room Terminals in Cloud Meetings: `ByteRTCRoomProfileMeetingRoom`
 */
- (int)setAnsMode:(ByteRTCAnsMode)ansMode;

#if BYTERTC_TARGET_MAC

/**
 * 
 * @hidden(iOS)
 * @valid since 3.51
 * @type api
 * @region Audio device Management
 * @brief  Turns on/ off AGC(Analog Automatic Gain Control). <br>
 *         After AGC is enabled, SDK can automatically adjust mircrophone pickup volume to keep the output volume at a steady level.
 * @param enable whether to turn on AGC. <br>
 *        - true: AGC is turned on.
 *        - false: AGC is turned off,with DAGC(Digtal Automatic Gain Control) still on.
 * @return
 *         - 0: Success.
 *         - -1: Failure.
 * @note
 *         You can call this method before and after joining the room. To turn on AGC before joining the room, you need to contact the technical support to get a private parameter to set ByteRTCRoomProfile{@link #ByteRTCRoomProfile}. <br>
 *         To enable AGC after joining the room, you must set ByteRTCRoomProfile{@link #ByteRTCRoomProfile} to `ByteRTCRoomProfileMeeting`, `ByteRTCRoomProfileMeetingRoom`  or `ByteRTCRoomProfileClassroom`. <br>
 *         It is not recommended to call `setAudioCaptureDeviceVolume:` to adjust mircrophone pickup volume with AGC on.
 */
- (int)enableAGC:(BOOL)enable;
#endif


/**
 * 
 * @type api
 * @valid since 3.32
 * @brief Sets the type of voice change effect.
 * @param voiceChanger The sound change effect type. See ByteRTCVoiceChangerType{@link #ByteRTCVoiceChangerType}.
 * @return API call result: <br>
 *        - 0: Success.
 *        - <0: Failure. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for specific reasons.
 * @note
 *         - To use this feature, you need to integrate the SAMI dynamic library. See [Integrate Plugins on Demand](docs-1108726).
 *         - You can call it before and after entering the room.
 *         - Effective for both internal and external audio source.
 *         - Only valid for mono-channel audio.
 *         - Mutually exclusive with setVoiceReverbType:{@link #ByteRTCVideo#setVoiceReverbType:}, and the effects set later will override the effects set first.
 */
- (int)setVoiceChangerType:(ByteRTCVoiceChangerType)voiceChanger;

/**
 * 
 * @type api
 * @valid since 3.32
 * @region Bel Sound Effect Management
 * @brief Sets the reverb effect type
 * @param voiceReverb Reverb effect type. See ByteRTCVoiceReverbType{@link #ByteRTCVoiceReverbType}.
 * @return API call result: <br>
 *        - 0: Success.
 *        - <0: Failure. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for specific reasons.
 * @note
 *         - You can call it before and after entering the room.
 *         - Effective for both internal and external audio source.
 *         - Only valid for mono-channel audio.
 *         - Mutually exclusive with setVoiceChangerType:{@link #ByteRTCVideo#setVoiceChangerType:}, and the effects set later will override the effects set first.
 */
- (int)setVoiceReverbType:(ByteRTCVoiceReverbType)voiceReverb;

/**
 * 
 * @type api
 * @brief Set the equalization effect for the local captured audio. The audio includes both internal captured audio and external captured voice, but not the mixing audio file.
 * @param config See ByteRTCVoiceEqualizationConfig{@link #ByteRTCVoiceEqualizationConfig}.
 * @return
 *         - 0: Success.
 *         - < 0: Failure.
 * @note According to the Nyquist acquisition rate, the audio acquisition rate must be greater than twice the set center frequency. Otherwise, the setting will not be effective.
 */
-(int)setLocalVoiceEqualization:(ByteRTCVoiceEqualizationConfig* _Nonnull)config;

/**
 * 
 * @type api
 * @brief Set the reverb effect for the local captured audio. The audio includes both internal captured audio and external captured voice, but not the mixing audio file.
 * @param param See ByteRTCVoiceReverbConfig{@link #ByteRTCVoiceReverbConfig}.
 * @return
 *         - 0: Success.
 *         - < 0: Failure.
 * @note Call enableLocalVoiceReverb:{@link #ByteRTCVideo#enableLocalVoiceReverb:} to enable the reverb effect.
 */
 -(int)setLocalVoiceReverbParam:(ByteRTCVoiceReverbConfig* _Nonnull)param;

/**
 * 
 * @type api
 * @brief Enable the reverb effect for the local captured voice.
 * @param enable
 * @return
 *         - 0: Success.
 *         - < 0: Failure.
 * @note Call setLocalVoiceReverbParam:{@link #ByteRTCVideo#setLocalVoiceReverbParam:} to set the reverb effect.
 */
-(int)enableLocalVoiceReverb:(bool)enable;

/**
 * 
 * @valid since 3.58.1
 * @type api
 * @region Volume management
 * @brief Set whether to mute the recording signal (without changing the local hardware).
 * @param index Stream index, specifying the main stream or screen stream volume adjustment. See ByteRTCStreamIndex{@link #ByteRTCStreamIndex}.
 * @param mute Whether to mute audio capture. <br>
 *        - True: Mute (disable microphone)
 *        - False: (Default) Enable microphone
 * @return
 *        - 0: Success.
 *        - < 0 : Failure. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
 * @note
          + Calling this API does not affect the status of SDK audio stream publishing.
          + Adjusting the volume by calling setCaptureVolume:volume:{@link #ByteRTCVideo#setCaptureVolume:volume:} after muting will not cancel the mute state. The volume state will be retained until unmuted.
          + You can use this interface to set the capture volume before or after calling startAudioCapture{@link #ByteRTCVideo#startAudioCapture} to enable audio capture.
 */
- (int)muteAudioCapture:(ByteRTCStreamIndex)index mute:(bool)mute;

/**
 * 
 * @type api
 * @region Audio Management
 * @brief Adjusts the audio capture volume.
 * @param index Index of the stream, whose volume needs to be adjusted. Refer to ByteRTCStreamIndex{@link #ByteRTCStreamIndex} for more details.
 * @param volume Ratio of capture volume to original volume. Ranging: [0,400]. Unit: % <br>
 *        - 0: Mute
 *        - 100: Original volume. To ensure the audio quality, we recommend [0, 100].
 *        - 400: Four times the original volume with signal-clipping protection.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note  Call this API to set the volume of the audio capture before or during the audio capture.
 */
- (int)setCaptureVolume:(ByteRTCStreamIndex)index volume:(int)volume;

/**
 * 
 * @type api
 * @region volume management
 * @brief Adjusts the playback volume of the mixed remote audio.  You can call this API before or during the playback.
 * @param volume Ratio(%) of playback volume to original volume, in the range [0, 400], with overflow protection. <br>
 *        To ensure the audio quality, we recommend setting the volume to `100`. <br>
 *        - 0: mute
 *        - 100: original volume
 *        - 400: Four times the original volume with signal-clipping protection.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note Suppose a remote user A is always within the range of the target user whose playback volume will be adjusted, if you use both this method and setRemoteAudioPlaybackVolume:remoteUid:playVolume:{@link #ByteRTCVideo#setRemoteAudioPlaybackVolume:remoteUid:playVolume:}/setRemoteRoomAudioPlaybackVolume:{@link #ByteRTCRoom#setRemoteRoomAudioPlaybackVolume:}, the volume that the local user hears from user A is the overlay of both settings.
 */
- (int)setPlaybackVolume:(NSInteger)volume;

/**
 * 
 * @type api
 * @region Audio management
 * @brief Enables audio information prompts. After that, you will receive rtcEngine:onLocalAudioPropertiesReport:{@link #ByteRTCVideoDelegate#rtcEngine:onLocalAudioPropertiesReport:}, rtcEngine:onRemoteAudioPropertiesReport:totalRemoteVolume:{@link #ByteRTCVideoDelegate#rtcEngine:onRemoteAudioPropertiesReport:totalRemoteVolume:}, and rtcEngine:onActiveSpeaker:uid:{@link #ByteRTCVideoDelegate#rtcEngine:onActiveSpeaker:uid:}.
 * @param config See ByteRTCAudioPropertiesConfig{@link #ByteRTCAudioPropertiesConfig}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 */
- (int)enableAudioPropertiesReport:(ByteRTCAudioPropertiesConfig* _Nonnull)config;

/**
 * 
 * @type api
 * @region  multi-room
 * @brief Adjusts the audio playback volume from the specified remote user.
 * @param roomID ID of the room from which the remote audio source is published.
 * @param userID The remote user ID of the audio source
 * @param volume Ratio(%) of playback volume to original volume, in the range [0, 400], with overflow protection. <br>
 *               To ensure the audio quality, we recommend setting the volume within `100`. <br>
 *               - 0: mute
 *               - 100: original volume. Default value.
 *               - 400: Up to 4 times the original volume (with overflow protection)
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note Suppose a remote user A is always within the range of the target user whose playback volume will be adjusted, <br>
 *        - If you use both this method and setRemoteRoomAudioPlaybackVolume:{@link #ByteRTCRoom#setRemoteRoomAudioPlaybackVolume:}, the volume that the local user hears from user A is the volume set by the method called later.
 *        - If you use both this method and setPlaybackVolume:{@link #ByteRTCVideo#setPlaybackVolume:}, the volume that the local user hears from user A is the overlay of both settings.
 */
- (int)setRemoteAudioPlaybackVolume:(NSString *_Nonnull)roomID
                           remoteUid:(NSString *_Nonnull)userID
                          playVolume:(NSInteger)volume;

/**
 * 
 * @type api
 * @region Audio management
 * @brief Enables/Disables in-ear monitoring.
 * @param mode Whether or not in-ear monitoring is enabled. See ByteRTCEarMonitorMode{@link #ByteRTCEarMonitorMode}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *         - In-ear monitoring is effective for audios captured by the RTC SDK.
 *         - We recommend that you use wired earbuds/headphones for a low-latency, high-resolution audio experience.
 *         - For iOS, you can only use SDK-level in-ear monitoring.
 *         - For macOS, you can use ear monitoring feature when the earpiece is directly connected to the device by 3.5mm interface, USB interface, or BlueTooth. You cannot use ear monitoring feature when the earpiece is connected to a monitor via the HDMI or USB-C interface, and then connected to the device, or connected to an OTG external sound card, and then connected to the device.
 */
- (int)setEarMonitorMode:(ByteRTCEarMonitorMode)mode;

/**
 * 
 * @type api
 * @region Audio Management
 * @brief Sets the in-ear monitoring volume.
 * @param volume The monitoring volume with the adjustment range between 0% and 100%.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
 * @note Call setEarMonitorMode:{@link #ByteRTCVideo#setEarMonitorMode:} before setting the volume.
 */
- (int)setEarMonitorVolume:(NSInteger)volume;

/**
 * 
 * @hidden(macOS)
 * @type api
 * @region Audio Management
 * @brief  On iOS, you can change the Bluetooth profile when the media volume is set in all scenarios.
 * @param mode The Bluetooth profiles. See ByteRTCBluetoothMode{@link #ByteRTCBluetoothMode}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note You will receive rtcEngine:onAudioDeviceWarning:deviceType:deviceWarning:{@link #ByteRTCVideoDelegate#rtcEngine:onAudioDeviceWarning:deviceType:deviceWarning:} in the following scenarios: 1) You cannot change the Bluetooth profile to HFP.;2) The media volume is not set in all scenarios. We suggest that you call setAudioScenario:{@link #ByteRTCVideosetaudioscenario:} to set the media volume scenario before calling this API.
 */
- (int)setBluetoothMode:(ByteRTCBluetoothMode) mode;

/**
 * 
 * @type api
 * @region Audio Mixing
 * @brief Changes local voice to a different key, mostly used in Karaoke scenarios. <br>
 *        You can adjust the pitch of local voice such as ascending or descending with this method.
 * @param pitch The value that is higher or lower than the original local voice within a range from -12 to 12. The default value is 0, i.e. no adjustment is made. <br>
 *        The difference in pitch between two adjacent values within the value range is a semitone, with positive values indicating an ascending tone and negative values indicating a descending tone, and the larger the absolute value set, the more the pitch is raised or lowered. <br>
 *        Out of the value range, the setting fails and triggers rtcEngine:onWarning:{@link #ByteRTCVideoDelegate#rtcEngine:onWarning:} callback, indicating `WARNING_CODE_SET_SCREEN_STREAM_INVALID_VOICE_PITCH` for invalid value setting with ByteRTCWarningCode{@link #ByteRTCWarningCode}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 */
- (int)setLocalVoicePitch:(NSInteger)pitch;

/**
 * 
 * @type api
 * @region Audio Management
 * @brief Enables/disables the loudness equalization function. <br>
 *        If you call this API with the parameter set to True, the loudness of user's voice will be adjusted to -16lufs. If then you also call setAudioMixingLoudness:loudness:{@link #ByteRTCAudioMixingManager#setAudioMixingLoudness:loudness:} and import the original loudness of the audio data used in audio mixing, the loudness will be adjusted to -20lufs when the audio data starts to play.
 * @param enable Whether to enable loudness equalization function: <br>
 *        - true: Yes
 *        - false: No
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note You must call this API before starting to play the audio file with startAudioMixing:filePath:config:{@link #ByteRTCAudioMixingManager#startAudioMixing:filePath:config:}.
 */
- (int)enableVocalInstrumentBalance:(BOOL)enable;

/**
 * 
 * @type api
 * @region Audio Management
 * @brief Enables/disables the playback ducking function. This function is usually used in scenarios where short videos or music will be played simultaneously during RTC calls. <br>
 *        With the function on, if remote voice is detected, the local media volume will be lowered to ensure the clarity of the remote voice. If remote voice disappears, the local media volume restores.
 * @param enable Whether to enable playback ducking: <br>
 *        - YES: Yes
 *        - NO: No
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 */
- (int)enablePlaybackDucking:(BOOL)enable;
#pragma mark Core Video Methods


/**
 * 
 * @type api
 * @deprecated since 3.57, use setLocalVideoRender:withSink:withLocalRenderConfig:{@link #ByteRTCVideo#setLocalVideoRender:withSink:withLocalRenderConfig:} instead.
 * @region Custom Video Capturing & Rendering
 * @brief Binds the local video stream to a custom renderer.
 * @param index Video stream type. See ByteRTCStreamIndex{@link #ByteRTCStreamIndex}.
 * @param videoSink Custom video renderer. See ByteRTCVideoSinkDelegate{@link #ByteRTCVideoSinkDelegate}.
 * @param requiredFormat Video frame encoding format that applys to custom rendering. See ByteRTCVideoSinkPixelFormat{@link #ByteRTCVideoSinkPixelFormat}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *        - RTC SDK uses its own renderer (internal renderer) for video rendering by default.
 *        - If you need to unbind the video stream from the custom render, you must set videoSink to `null`. The binding status will be cleared when you leave room.
 *        - You should call this API before joining the room, and after receiving rtcEngine:onFirstLocalVideoFrameCaptured:withFrameInfo:{@link #ByteRTCVideoDelegate#rtcEngine:onFirstLocalVideoFrameCaptured:withFrameInfo:} which reports that the first local video frame has been successfully captured.
 *        - This method gets video frames that have undergone preprocessing. If you need to obtain video frames from other positions, such as after-captured, you should call setLocalVideoRender:withSink:withLocalRenderConfig:{@link #ByteRTCVideo#setLocalVideoRender:withSink:withLocalRenderConfig:} instead.
 */
- (int)setLocalVideoSink:(ByteRTCStreamIndex)index
                withSink:(id<ByteRTCVideoSinkDelegate> _Nullable)videoSink
         withPixelFormat:(ByteRTCVideoSinkPixelFormat)requiredFormat NS_SWIFT_NAME(setLocalVideoSink(_:withSink:withPixelFormat:));


/**
 * 
 * @valid since 3.57
 * @type api
 * @region Custom Video Frame Callback
 * @brief Binds the local video stream with a custom renderer. You can set parameters to return video frame data at a specified location and format.
 * @param index The attribute of the video stream. The captured video stream/screen video stream, see ByteRTCStreamIndex{@link #ByteRTCStreamIndex}.
 * @param videoSink The custom video renderer, see IVideoSink {@link #IVideoSink}.
 * @param config Configuration for the local video frame callback, see LocalVideoSinkConfig {@link #LocalVideoSinkConfig}.
 * @return
 *        - 0: Success.
 *        - < 0: Failure. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more error details.
 * @note
 *        - The RTC SDK uses its own renderer (internal renderer) for video rendering by default.
 *        - The binding state will be cleared when leaving the room.
 *        - If you need to unbind, you must set video_sink to null.
 *        - Generally, after receiving the rtcEngine:onFirstLocalVideoFrameCaptured:withFrameInfo:{@link #ByteRTCVideoDelegate#rtcEngine:onFirstLocalVideoFrameCaptured:withFrameInfo:} callback notification that the first local video frame has been captured, you should call this method to bind a custom renderer to the video stream; then join the room.
 * @list Custom Stream Processing
 * @order 2
  */
- (int)setLocalVideoRender:(ByteRTCStreamIndex)index
                withSink:(id<ByteRTCVideoSinkDelegate> _Nullable)videoSink
         withLocalRenderConfig:(ByteRTCLocalVideoSinkConfig*)config NS_SWIFT_NAME(setLocalVideoRender(_:withSink:withLocalRenderConfig:));


/**
 * 
 * @type api
 * @deprecated since 3.57, use setRemoteVideoRender:withSink:withRemoteRenderConfig:{@link #ByteRTCVideo#setRemoteVideoRender:withSink:withRemoteRenderConfig:} instead.
 * @region Custom Video Capturing & Rendering
 * @brief Binds the remote video stream to a custom renderer.
 * @param streamKey Remote stream information which specifys the source and type of the video stream to be rendered. See ByteRTCRemoteStreamKey{@link #ByteRTCRemoteStreamKey}
 * @param videoSink Custom video renderer. See ByteRTCVideoSinkDelegate{@link #ByteRTCVideoSinkDelegate}.
 * @param requiredFormat Encoding format that applys to the custom renderer. See ByteRTCVideoSinkPixelFormat{@link #ByteRTCVideoSinkPixelFormat}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *        - RTC SDK uses its own renderer (internal renderer) for video rendering by default.
 *        - Joining or leaving the room will not affect the binding state.
 *        - This API can be called before and after entering the room. To call before entering the room, you need to get the remote stream information before joining the room; if you cannot get the remote stream information in advance, you can call the API after joining the room and getting the remote stream information through rtcRoom:onUserPublishStreamVideo:uid:isPublish:type:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishStreamVideo:uid:isPublish:type:}.
 *        - If you need to unbind the remote stream from the renderer, you must set videoSink to null.
 *        - This method gets video frames that have undergone proprocessing. If you need to obtain video frames from other positions, such as after decoded, you should call setRemoteVideoRender:withSink:withRemoteRenderConfig:{@link #ByteRTCVideo#setRemoteVideoRender:withSink:withRemoteRenderConfig:} instead.
 */
- (int)setRemoteVideoSink:(ByteRTCRemoteStreamKey* _Nonnull)streamKey
                withSink:(id<ByteRTCVideoSinkDelegate> _Nullable)videoSink
         withPixelFormat:(ByteRTCVideoSinkPixelFormat)requiredFormat NS_SWIFT_NAME(setRemoteVideoSink(_:withSink:withPixelFormat:));


/**
 * 
 * @valid since 3.57
 * @type api
 * @region Custom Video Frame Callback
 * @brief Binds the remote video stream with a custom renderer. You can set parameters to return video frame data at a specified location and format.
 * @param streamKey Information about the remote stream, used to specify the source and attributes  of the video stream for rendering, see ByteRTCRemoteStreamKey{@link #ByteRTCRemoteStreamKey}.
 * @param videoSink The custom video renderer, see ByteRTCVideoSinkDelegate{@link #ByteRTCVideoSinkDelegate}.
 * @param config Configuration for the remote video frame callback, see ByteRTCRemoteVideoSinkConfig{@link #ByteRTCRemoteVideoSinkConfig}.
 * @return
 *        - 0: Success.
 *        - < 0: Failure. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more error details.
 * @note
 *        - RTC SDK uses its own renderer (internal renderer) for video rendering by default.
 *        - This method can be called both before and after entering the room. If you want to call it before entering the room, you need to obtain the remote stream's information before joining the room; if you cannot obtain the remote stream's information in advance, you can call this method after joining the room and obtaining the remote stream information through the rtcRoom:onUserPublishStream:type:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishStream:type:} callback.
 *        - The binding state will be cleared when leaving the room.
 *        - If you need to unbind, you must set video_sink to null.
 * @list Custom Stream Processing
 * @order 3
 */
- (int)setRemoteVideoRender:(ByteRTCRemoteStreamKey* _Nonnull)streamKey
                 withSink:(id<ByteRTCVideoSinkDelegate> _Nullable)videoSink
          withRemoteRenderConfig:(ByteRTCRemoteVideoSinkConfig*)config NS_SWIFT_NAME(setRemoteVideoRender(_:withSink:withRemoteRenderConfig:));


/**
 * 
 * @hidden not available
 * @type api
 * @region Audio & Video Processing
 * @brief Sets the super resolution mode for remote video stream.
 * @param streamKey Remote stream information that specifies the source and type of the video stream. See ByteRTCRemoteStreamKey{@link #ByteRTCRemoteStreamKey}.
 * @param mode Super resolution mode. See ByteRTCVideoSuperResolutionMode{@link #ByteRTCVideoSuperResolutionMode}.
 * @return. <br>
 *        - 0: ByteRTCReturnStatusSuccess. It does not indicate the actual status of the super resolution mode, you should refer to rtcEngine:onRemoteVideoSuperResolutionModeChanged:withMode:withReason:{@link #ByteRTCVideoDelegate#rtcEngine:onRemoteVideoSuperResolutionModeChanged:withMode:withReason:} callback.
 *        - -1: ByteRTCReturnStatusNativeInValid. Native library is not loaded.
 *        - -2: ByteRTCReturnStatusParameterErr. Invalid parameter.
 *        - -9: ByteRTCReturnStatusScreenNotSupport. Failure. Screen stream is not supported.
 *        See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more return value indications.
 * @note
 *        - Call this API after joining room.
 *        - The original resolution of the remote video stream should not exceed 640 × 360 pixels.
 *        - You can only turn on super-resolution mode for one stream.
 */
- (int)setRemoteVideoSuperResolution:(ByteRTCRemoteStreamKey* _Nonnull)streamKey
                                            withMode:(ByteRTCVideoSuperResolutionMode)mode;


/**
 * 
 * @hidden not available
 * @type api
 * @region Audio & Video Processing
 * @brief Sets the video noise reduction mode.
 * @param mode Video noise reduction mode. Refer to ByteRTCVideoDenoiseMode{@link #ByteRTCVideoDenoiseMode} for more details.
 * @return
 *        - 0: Success. Please refer to rtcEngine:onVideoDenoiseModeChanged:withReason:{@link #ByteRTCVideoDelegate#rtcEngine:onVideoDenoiseModeChanged:withReason:} callback for the actual state of video noise reduction mode.
 *        - < 0: Failure.
 */
- (int)setVideoDenoiser:(ByteRTCVideoDenoiseMode)mode;


/**
 * 
 * @valid since 3.57
 * @hidden(iOS)
 * @type api
 * @region Audio & Video Processing
 * @brief Sets the video lowlight enhancement mode. <br>
 *        It can significantly improve image quality in scenarios with insufficient light, contrast lighting, or backlit situations.
 * @param mode It defaults to Disable. Refer to ByteRTCVideoEnhancementMode{@link #ByteRTCVideoEnhancementMode} for more details.
 * @return
 *        - 0: Success. After you call this method, it will take action immediately. But it may require some time for downloads and detection processes before you can see the enhancement.
 *        - < 0: Failure. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
 * @note
 *        - Turning on this mode will impact device performance. This feature should be activated only when required and the device performance is adequate.
 *        - Functionality applies to videos captured by the internal module as well as those from custom collections.
 */
- (int)setLowLightAdjusted:(ByteRTCVideoEnhancementMode)mode;


/**
 * 
 * @deprecated since 3.45 and will be deleted in 3.51, use setVideoEncoderConfig:{@link #ByteRTCVideo#setVideoEncoderConfig:} instead.
 * @type api
 * @region Video management
 * @brief  Sets the video encoder configuration of each individual stream for simulcasting, including resolution, frame rate, bitrate, scale mode, fallback strategy under poor network conditions, etc.
 * @param  Stream type. See ByteRTCStreamIndex{@link #ByteRTCStreamIndex}.
 * @param videoSolutions Video parameters of each individual stream for simulcasting. See ByteRTCVideoSolution{@link #ByteRTCVideoSolution}. <br>
 *                        The length of `videoSolutions` is no more than 4. The resolutions must be in descending sort. <br>
 *                        The maximum resolution is 4096px × 4096px. If the resolution exceeds the limit or the video cannot be encoded, the simulcasting will fail.
 * @return
 *         - 0: Success
 *         +! 0: Failure
 * @note
 *        - When using the internal capture, the resolution and frame rate will be adapted to the maximum resolution and frame rate for encoding.
 *        - The video streams are encoded by default with resolution of 640px × 360px and frame rate of 15fps.
 *        - When you call this API, it will take effect immediately, which may cause the camera to restart.
 *        - The screen stream takes the first set of parameters.
 */
- (int)setVideoEncoderConfig:(ByteRTCStreamIndex)streamIndex config:(NSArray <ByteRTCVideoSolution *> * _Nullable)videoSolutions __deprecated_msg("Will be removed in new version");

/**
 * 
 * @type api
 * @brief Set the rotation of the video images captured from the local device. <br>
 *        Call this API to rotate the videos when the camera is fixed upside down or tilted. For rotating videos on a phone, we recommend to use setVideoRotationMode:{@link #ByteRTCVideo#setVideoRotationMode:}.
 * @param rotation It defaults to `ByteRTCVideoRotation0`, which means not to rotate. Refer to ByteRTCVideoRotation{@link #ByteRTCVideoRotation}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *        - For the videos captured by the internal module, the rotation will be combined with that set by calling setVideoRotationMode:{@link #ByteRTCVideo#setVideoRotationMode:}.
 *        - Calling this interface will also take effect on external capturing video frames, superimposing the rotation set this time on the original rotation angle.
 *        - video sticker effects or virtual backgrounds added by calling enableVirtualBackground {@link #IVideoEffect#enableVirtualBackground} enableVirtualBackground{@link #ByteRTCVideoEffect#enableVirtualBackground:withSource:} will also rotate following the settings of this interface.
 *        - Both the locally rendered video and the video sent to the remote end will rotate accordingly, but the settings by this interface will not apply to pushing sing-stream to CDN. If you want to apply rotation to the video stream in pushing single-stream to CDN, call setVideoOrientation:{@link #ByteRTCVideo#setVideoOrientation:}.
 */
- (int)setVideoCaptureRotation:(ByteRTCVideoRotation)rotation;

/**
 * 
 * @type api
 * @region Video Management
 * @brief Enables/Disables the mode of publishing multiple video streams with different encoding configuration.
 * @param enabled Whether to enable the mode of publishing multiple video streams: <br>
 *        - YES: Yes
 *        - NO: No(Default setting)
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *        - You should call this API
 *            - before entering the room, or
 *            - after entering the room but before publishing streams
 *        - When the simulcast mode is turned on, it cannot be turned off dynamically, nor can the parameters for video encoding be updated.
 *        - After setting this API to "True", you can call setVideoEncoderConfig:{@link #ByteRTCVideo#setVideoEncoderConfig:} to set encoding configuration for each stream before you publish stream.
 *        - If this function is off, or if this function is on but you don't set the configuration of any stream, only one stream will be sent with a resolution of 640px × 360px and a frame rate of 15fps.
 */
- (int) enableSimulcastMode:(BOOL) enabled;

/**
 * 
 * @type api
 * @region Video Management
 * @brief Video publisher call this API to set the parameters of the maximum resolution video stream that is expected to be published, including resolution, frame rate, bitrate, and fallback strategy in poor network conditions. <br>
 *        You can only set configuration for one stream with this API. If you want to set configuration for multiple streams, Call setVideoEncoderConfig:{@link #ByteRTCVideo#setVideoEncoderConfig:}.
 * @param encoderConfig The maximum video encoding parameter. See ByteRTCVideoEncoderConfig{@link #ByteRTCVideoEncoderConfig}.
 * @return  API call result: <br>
 *        - 0: Success
 *        - ! 0: Failure
 * @note
 *        - You can use enableSimulcastMode:{@link #ByteRTCVideo#enableSimulcastMode:} simultaneously to publish streams with different resolutions. Specifically, if you want to publish multiple streams with different resolutions, you need to call this method and enable the simulcast mode with enableSimulcastMode:{@link #ByteRTCVideo#enableSimulcastMode:} before publishing your streams. The SDK will intelligently adjust the number of streams to be published (up to 4) and their parameters based on the settings of the subscribing end. The resolution set by calling this method will be the maximum resolution among the streams. For specific rules, please refer to [Simulcasting](https:
 *        - Without calling this API, SDK will only publish one stream for you with a resolution of 640px × 360px and a frame rate of 15fps.
 *        - In custom capturing, you must call this API to set the encoding parameters to ensure the integrity of the picture received by remote users.
 *        - This API is applicable to the video stream captured by the camera, see setScreenVideoEncoderConfig:{@link #ByteRTCVideo#setScreenVideoEncoderConfig:} for setting parameters for screen sharing video stream.
 */
- (int)setMaxVideoEncoderConfig:(ByteRTCVideoEncoderConfig * _Nullable) encoderConfig;

/**
 * 
 * @hidden currently not available
 */
- (int)setVideoEncoderConfig:(ByteRTCVideoEncoderConfig * _Nullable) encoderConfig withParameters:(NSDictionary * _Nullable) parameters;

/**
 * 
 * @type api
 * @region Video Management
 * @brief Video publisher call this API to set the configurations of each stream published, including resolution, frame rate, bitrate, and fallback strategy in poor network conditions.
 * @param encoderConfig List of configurations for multiple streams. You can set parameters for up to 3 streams, SDK will always take the value of the first 3 streams when parameters for more streams are set. <br>
 *        The resolution you set is the maximum resolution of each stream, and must be arranged in descending order. The frame rates must be arranged in descending order. See ByteRTCVideoEncoderConfig{@link #ByteRTCVideoEncoderConfig}.
 * @return  API call result: <br>
 *        - 0: Success
 *        - ! 0: Failure
 * @note
 *        - If you call this API after enabling the mode of publishing multiple streams with enableSimulcastMode:{@link #ByteRTCVideo#enableSimulcastMode:}, SDK will publish streams as you set, otherwise the SDK by default publishes the first stream that you have set.
 *        - If you want to publish multiple streams with different resolutions, you need to call this method and enableSimulcastMode:{@link #ByteRTCVideo#enableSimulcastMode:}.
 *        - When the simulcast mode is turned on, it cannot be turned off dynamically, nor can the parameters for video encoding be updated.
 *        - Without calling this API to set parameters for multiple video streams, the SDK only publishes one video stream with a resolution of 640px × 360px and a frame rate of 15fps.
 *        - After setting parameters for multiple video streams, SDK will automatically match the streams to be published based on the desired subscription parameters set by subscribers.
 *        - This API is applicable to the video stream captured by the camera, see setScreenVideoEncoderConfig:{@link #ByteRTCVideo#setScreenVideoEncoderConfig:} for setting parameters for screen sharing video stream.
 */
-(int)setVideoEncoderConfig:(NSArray <ByteRTCVideoEncoderConfig *> * _Nullable) encoderConfigs;


/**
 * 
 * @type api
 * @region Screen Sharing
 * @brief Set the encoding configuration for shared-screen streams, including the resolution, frame rate, bitrate, and fallback strategies under challenging network conditions.
 * @param encoderConfig The encoding configuration for shared-screen streams. See ByteRTCScreenVideoEncoderConfig{@link #ByteRTCScreenVideoEncoderConfig}.
 * @return
 *        - 0: Success.
 *        - ! 0: Failure.
 * @note
 *      - Call this API before publishing screen sharing stream with publishScreenVideo:{@link #ByteRTCRoom#publishScreenVideo:}.
 *      - We recommend that you set the encoding configuration before video capture. Otherwise, the streams will be captured based on the default configuration(1080p@15fps).
 */
-(int)setScreenVideoEncoderConfig:(ByteRTCScreenVideoEncoderConfig * _Nullable) encoderConfig;


/**
 * 
 * @hidden(macOS)
 * @valid since 3.58
 * @type api
 * @region Video Management
 * @brief Enables the Alpha channel encoding feature for custom capture video frames. <br>
 *        Suitable for scenarios where the video subject needs to be separated from the background at the push-streaming end, and the background can be custom rendered at the receive-streaming end.
 * @param streamIndex The type of video stream for which this feature needs to be enabled. Currently, only ByteRTCStreamIndex.ByteRTCStreamIndexMain, is supported.
 * @param alphaLayout The arrangement position of the separated Alpha channel relative to the RGB channel information. Currently, only ByteRTCAlphaLayout.ByteRTCAlphaLayoutTop is supported, which is positioned above the RGB channel information.
 * @return - 0: Success;
 *         - !0: Failure.
 * @note
 *        - This API only applies to custom capture video frames that use ByteRTCVideoPixelFormat.ByteRTCVideoPixelFormatCVPixelBuffer.
 *        - This API must be called before publishing the video stream.
 *        - After enabling Alpha channel encoding with this API, you need to call pushExternalVideoFrame:{@link #ByteRTCVideo#pushExternalVideoFrame:} to push custom captured video frames to the RTC SDK. If a video frame format that is not supported is pushed, the call to pushExternalVideoFrame:{@link #ByteRTCVideo#pushExternalVideoFrame:} will return the error code ByteRTCReturnStatus.ByteRTCReturnStatusParameterErr.
 */
-(int)enableAlphaChannelVideoEncode:(ByteRTCStreamIndex)streamIndex withAlphaLayout:(ByteRTCAlphaLayout)alphaLayout;


/**
 * 
 * @hidden(macOS)
 * @valid since 3.58
 * @type api
 * @region Video Management
 * @brief Disables the Alpha channel encoding feature for custom captured video frames.
 * @param streamIndex The type of video stream for which this feature needs to be disabled. Currently, it can be set to ByteRTCStreamIndex.ByteRTCStreamIndexMain only.
 * @return - 0: Success;
 *         - !0: Failure.
 * @note This interface must be called after stopping publishing the video stream.
 */
-(int)disableAlphaChannelVideoEncode:(ByteRTCStreamIndex)streamIndex;

#if BYTERTC_TARGET_MAC

/**
 * 
 * @hidden(iOS)
 * @type api
 * @region screen sharing
 * @brief  When the resolution of the external shared-screen stream changes, you can call this API to set the original pixel and framerate to help RTC(in the automatic mode) recommend these configurations.
 * @param originalCaptureWidth The original width of shared-screen streams.
 * @param originalCaptureHeight The original height of shared-screen streams.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *        - Before calling this API，you are advised to call setScreenVideoEncoderConfig:{@link #ByteRTCVideo#setScreenVideoEncoderConfig:} to set the encoding configuration: set the encoding mode to the automatic mode, the width and height to 0, the maximum bitrate to -1, and the minimum bitrate to 0.
 *        - After calling this API，you will receive rtcEngine:onExternalScreenFrameUpdate:{@link #ByteRTCVideoDelegate#rtcEngine:onExternalScreenFrameUpdate:} to re-capture the stream based on the recommended pixel and framerate by RTC.
 */
-(int)setOriginalScreenVideoInfo:(int) originalCaptureWidth
        withOriginalCaptureHeight:(int)originalCaptureHeight;

#endif

/**
 * 
 * @type api
 * @region  Video Management
 * @brief Sets the video capture parameters for internal capture of the RTC SDK. <br>
 *        If your project uses the SDK internal capture module, you can specify the video capture parameters including preference, resolution and frame rate through this interface.
 * @param captureConfig  Video capture parameters. See: ByteRTCVideoCaptureConfig{@link #ByteRTCVideoCaptureConfig}.
 * @return
 *         - 0: Success;
 *         - < 0: Failure;
 * @note
 *  - This interface can be called after the engine is created and takes effect immediately after being called. It is recommended to call this method before startVideoCapture{@link #ByteRTCVideo#startVideoCapture}.
 *  - It is recommended that different Engines on the same device use the same video capture parameters.
 *  - If you use the internal module to start video capture before calling this interface, the capture parameters default to Auto.
 */
- (int)setVideoCaptureConfig:(ByteRTCVideoCaptureConfig * _Nullable)captureConfig;

/**
 * 
 * @type api
 * @region Video Management
 * @brief Sets the view to be used for local video rendering and the rendering mode.
 * @param streamIndex Video stream type. See ByteRTCStreamIndex{@link #ByteRTCStreamIndex}.
 * @param canvas View information and rendering mode. See ByteRTCVideoCanvas{@link #ByteRTCVideoCanvas}.
 * @return
 *         - 0: Success
 *         - -1: Failure
 * @note
 *       - You should bind your stream to a view before joining the room. This setting will remain in effect after you leave the room.
 *       - If you need to unbind the local video stream from the current view, you can call this API and set the videoCanvas to `null`.
 */
- (int)setLocalVideoCanvas:(ByteRTCStreamIndex)streamIndex
                withCanvas:(ByteRTCVideoCanvas * _Nullable)canvas NS_SWIFT_NAME(setLocalVideoCanvas(_:withCanvas:));

/**
 * 
 * @type api
 * @region  video management
 * @brief Update the render mode and background color of local video rendering.
 * @param streamIndex See ByteRTCStreamIndex{@link #ByteRTCStreamIndex}.
 * @param renderMode See ByteRTCRenderMode{@link #ByteRTCRenderMode}.
 * @param backgroundColor See ByteRTCVideoCanvas{@link #ByteRTCVideoCanvas}.backgroundColor.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note Calling this API during local video rendering will be effective immediately.
 */
- (int)updateLocalVideoCanvas:(ByteRTCStreamIndex)streamIndex
                withRenderMode:(ByteRTCRenderMode)renderMode
          withBackgroundColor:(NSUInteger)backgroundColor NS_SWIFT_NAME(updateLocalVideoCanvas(_:withRenderMode:withBackgroundColor:));

/**
 * 
 * @type api
 * @region Custom Video Capturing & Rendering
 * @brief Sets the view and rendering mode to use when rendering a video stream from a specified remote user uid. <br>
 *         If you need to unbind the video view, set canvas to empty.
 * @param key Remote stream information. See ByteRTCRemoteStreamKey{@link #ByteRTCRemoteStreamKey}.
 * @param canvas View information and rendering mode. See ByteRTCVideoCanvas{@link #ByteRTCVideoCanvas}. Starting from version 3.56, you can set the rotation angle of the remote video rendering using `renderRotation`.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note When the local user leaves the room, the setting will be invalid. The remote user leaving the room does not affect the setting.
 */
- (int)setRemoteVideoCanvas:(ByteRTCRemoteStreamKey * _Nonnull)key
             withCanvas:(ByteRTCVideoCanvas * _Nullable)canvas NS_SWIFT_NAME(setRemoteVideoCanvas(_:withCanvas:));


/**
 * 
 * @deprecated since 3.56 on iOS, and will be deleted in 3.62. Use updateRemoteStreamVideoCanvas:withRemoteVideoRenderConfig:{@link #ByteRTCVideo#updateRemoteStreamVideoCanvas:withRemoteVideoRenderConfig:} instead.
 * @type api
 * @region Video management
 * @brief Modifies remote video frame rendering settings, including render mode and background color.
 * @param key Remote stream information to the remote. See ByteRTCRemoteStreamKey{@link #ByteRTCRemoteStreamKey}.
 * @param renderMode See ByteRTCRenderMode{@link #ByteRTCRenderMode}.
 * @param backgroundColor See ByteRTCVideoCanvas{@link #ByteRTCVideoCanvas}.backgroundColor.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note Calling this API during remote video rendering will be effective immediately.
 */
- (int)updateRemoteStreamVideoCanvas:(ByteRTCRemoteStreamKey * _Nonnull)key
                withRenderMode:(ByteRTCRenderMode)renderMode
                withBackgroundColor:(NSUInteger)backgroundColor NS_SWIFT_NAME(updateRemoteStreamVideoCanvas(_:withRenderMode:withBackgroundColor:));


/**
 * 
 * @hidden(macOS)
 * @valid since 3.56
 * @type api
 * @region Video management
 * @brief Modifies remote video frame rendering settings, including render mode, background color, and rotation angle, while using the internal rendering of the SDK.
 * @param key Information about the remote stream. See ByteRTCRemoteStreamKey{@link #ByteRTCRemoteStreamKey}.
 * @param remoteVideoRenderConfig Video rendering settings. See ByteRTCRemoteVideoRenderConfig{@link #ByteRTCRemoteVideoRenderConfig}.
 * @return
 *        - 0: Success.
 *        - < 0 : Failure. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *        - After setting the rendering configuration for the remote video frame with setRemoteVideoCanvas:withCanvas:{@link #ByteRTCVideo#setRemoteVideoCanvas:withCanvas:}, you can call this API to update settings including render mode, background color, and rotation angle.
 *        - Calling this API during remote video rendering will be effective immediately.
 */
- (int)updateRemoteStreamVideoCanvas:(ByteRTCRemoteStreamKey * _Nonnull)key
         withRemoteVideoRenderConfig:(ByteRTCRemoteVideoRenderConfig * _Nonnull)remoteVideoRenderConfig
            NS_SWIFT_NAME(updateRemoteStreamVideoCanvas(_:withRemoteVideoRenderConfig:));

 
 /**
  * 
  * @type api
  * @region Video Management
  * @brief Enables internal video capture immediately. The default setting is off. <br>
  *        Internal video capture refers to: capturing video using the built-in module. <br>
  *        The local client will be informed via rtcEngine:onVideoDeviceStateChanged:device_type:device_state:device_error:{@link #ByteRTCVideoDelegate#rtcEngine:onVideoDeviceStateChanged:device_type:device_state:device_error:} after starting video capture by calling this API. <br>
  *        The remote clients in the room will be informed of the state change via rtcEngine:onUserStartVideoCapture:uid:{@link #ByteRTCVideoDelegate#rtcEngine:onUserStartVideoCapture:uid:} after the visible client starts video capture by calling this API.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
  * @note
  *        - Call stopVideoCapture{@link #ByteRTCVideo#stopVideoCapture} to stop the internal video capture. Otherwise, the internal video capture will sustain until you destroy the engine instance.
  *        - Once you create the engine instance, you can start internal video capture regardless of the video publishing state. The video stream will start publishing only after the video capture starts.
  *        - To switch from custom to internal video capture, stop publishing before disabling the custom video capture module and then call this API to enable the internal video capture.
  *        - Call switchCamera:{@link #ByteRTCVideo#switchCamera:} to switch the camera used by the internal video capture module. You cannot switch camera on macOS.
  *        - Since the upgrade in v3.37.0, to start capture by calling this API, you need to request the capture permission in your App.
  */
- (int)startVideoCapture NS_SWIFT_NAME(startVideoCapture());
 
 /**
  * 
  * @type api
  * @region Video Management
  * @brief Disables internal video capture immediately. The default is off. <br>
  *        Internal video capture refers to: use the RTC SDK built-in video capture module to capture. <br>
  *        The local client will be informed via rtcEngine:onVideoDeviceStateChanged:device_type:device_state:device_error:{@link #ByteRTCVideoDelegate#rtcEngine:onVideoDeviceStateChanged:device_type:device_state:device_error:} after stopping video capture by calling this API. <br>
  *        The remote clients in the room will be informed of the state change via rtcEngine:onUserStopVideoCapture:uid:{@link #ByteRTCVideoDelegate#rtcEngine:onUserStopVideoCapture:uid:} after the visible client stops video capture by calling this API.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
  * @note
  *        - A call startVideoCapture{@link #ByteRTCVideo#startVideoCapture} to enable the internal video capture.
  *        - Without calling this API the internal video capture will sustain until you destroy the engine instance.
  */
- (int)stopVideoCapture NS_SWIFT_NAME(stopVideoCapture());

/**
 * 
 * @type api
 * @region Video management
 * @brief Sets the mirror mode for the captured video stream.
 * @param mirrorType Mirror type. See ByteRTCMirrorType{@link #ByteRTCMirrorType}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *         - Switching video streams does not affect the settings of the mirror type.
 *         - This API is not applicable to screen-sharing streams.
 *         - When using an external renderer, you can set `mirrorType` to `0` and `3`, but you cannot set it to `1`.
 *         - Before you call this API, the initial states of each video stream are as follows:
 *         <table>
 *            <tr><th></th><th>Front-facing camera</th><th>Back-facing camera</th><th>Custom capturing</th><th>Built-in camera</th></tr>
 *            <tr><td>Mobile device</td><td>The preview is mirrored. The published video stream is not mirrored.</td><td>The preview and the published video stream are not mirrored.</td><td>The preview and the published video stream are not mirrored.</td><td>/</td></tr>
 *            <tr><td>PC</td><td>/</td><td>/</td><td>The preview and the published video stream are not mirrored.</td><td>The preview is mirrored. The published video stream is not mirrored.</td></tr>
 *         </table>
 */
- (int)setLocalVideoMirrorType:(ByteRTCMirrorType) mirrorType;


/**
  * 
  * @type api
  * @valid since 3.57
  * @region Video Management
  * @brief When using internal rendering, enable mirroring for the remote stream.
  * @param key Information about the remote stream, used to specify the source and attributes of the video stream that need to be mirrored, see ByteRTCRemoteStreamKey{@link #ByteRTCRemoteStreamKey}.
  * @param mirrorType The mirror type for the remote stream, see ByteRTCRemoteMirrorType{@link #ByteRTCRemoteMirrorType}.
  * @return
  *        - 0: Success.
  *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
  * @list Video Processing
  * @order 3
  */
- (int)setRemoteVideoMirrorType:(ByteRTCRemoteStreamKey*)key withMirrorType:(ByteRTCRemoteMirrorType)mirrorType;


/**
 * 
 * @hidden(macOS)
 * @type api
 * @brief Sets the orientation of the video capture. By default, the App direction is used as the orientation reference. <br>
 *        During rendering, the receiving client rotates the video in the same way as the sending client does.
 * @param rotationMode Rotation reference can be the orientation of the App or gravity. Refer to ByteRTCVideoRotationMode{@link #ByteRTCVideoRotationMode} for details.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *        - The orientation setting is effective for internal video capture only. That is, the orientation setting is not effective to the custom video source or the screen-sharing stream.
 *        - If the video capture is on, the setting will be effective once you call this API. If the video capture is off, the setting will be effective on when capture starts.
 */
- (int)setVideoRotationMode:(ByteRTCVideoRotationMode) rotationMode;


/**
 * 
 * @hidden(macOS)
 * @type api
 * @region Audio & Video Processing
 * @brief Sets the orientation of the video frame before custom video processing and encoding. The default value is `Adaptive`. <br>
 *        You should set the orientation to `Portrait` when using video effects or custom processing. <br>
 *        You should set the orientation to `Portrait` or `Landscape` when pushing a single stream to the CDN.
 * @param orientation Orientation of the video frame. See ByteRTCVideoOrientation{@link #ByteRTCVideoOrientation}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *        - The orientation setting is only applicable to internal captured video sources. For custom captured video sources, setting the video frame orientation may result in errors, such as swapping width and height. Screen sources do not support video frame orientation setting.
 *        - We recommend setting the orientation before joining room. The updates of encoding configurations and the orientation are asynchronous, therefore can cause a brief malfunction in preview if you change the orientation after joining room.
 */
- (int)setVideoOrientation:(ByteRTCVideoOrientation) orientation;

/**
 * 
 * @hidden(macOS)
 * @type api
 * @region Video Management
 * @brief Switches to the front-facing/back-facing camera used in the internal video capture <br>
 *        The local client will be informed via rtcEngine:onVideoDeviceStateChanged:device_type:device_state:device_error:{@link #ByteRTCVideoDelegate#rtcEngine:onVideoDeviceStateChanged:device_type:device_state:device_error:} after calling this API.
 * @param cameraId Camera type. Refer to ByteRTCCameraID{@link #ByteRTCCameraID} for more details.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *         - Front-facing camera is the default camera.
 *         - If the internal video capturing is on, the switch is effective once you call this API. If the internal video capturing is off, the setting will be effective when capture starts.
 */
- (int)switchCamera:(ByteRTCCameraID) cameraId;


/**
 * 
 * @type api
 * @region Audio & Video Processing
 * @brief Gets video effect interfaces.
 * @return Video effect interfaces. See ByteRTCVideoEffect{@link #ByteRTCVideoEffect}.
 */
- (ByteRTCVideoEffect* _Null_unspecified)getVideoEffectInterface NS_SWIFT_NAME(getVideoEffectInterface());

#if BYTERTC_TARGET_MAC

/**
 * 
 * @type api
 * @deprecated since 3.50 and will be deleted in 3.55, use getAuthMessage:{@link #ByteRTCVideoEffect#getAuthMessage:} instead.
 * @hidden(iOS)
 * @region Video Effects
 * @brief Get authorization messages from the Effect SDK for the online license.
 * @param ppmsg Authorization message string address
 * @return
 *      - 0: Success.
 *      - –1000: The Effects SDK is not integrated.
 *      - –1001: This API is unavailable for your Effects SDK.
 *      - –1002: Your Effects SDK's version is incompatible.
 *      - < 0: Other error. See [Error Code Table](https:
 * @note
 *         - You must get an online license for the Effect SDK before using the CV functions.
 *         - After getting authorization messages with this API, implement the code of getting the online license with [Online License Guide](https:
 */
- (int)getAuthMessage:(NSString *_Nullable*_Nullable)ppmsg;
#endif


/**
 * 
 * @deprecated since 3.50 and will be deleted in 3.55, use initCVResource:withAlgoModelDir:{@link #ByteRTCVideoEffect#initCVResource:withAlgoModelDir:} instead.
 * @type api
 * @region Video Effects
 * @brief Video effects license check
 * @param licenseFile Absolute path of license file
 * @return
 *      - 0: Success
 *      - 1000: The Effect SDK is not integrated.
 *      - 1001: This API is not available for your Effect SDK.
 *      - <0: Other errors. See [Error Code Table](https:
 * @note enableVideoEffect{@link #ByteRTCVideoEffect#enableVideoEffect} Before you start using video effects, you need to call this method for license verification
 */
- (int)checkVideoEffectLicense:(NSString * _Nonnull)licenseFile NS_SWIFT_NAME(checkVideoEffectLicense(_:)) __deprecated_msg("Will be removed in new version");


/**
 * 
 * @deprecated since 3.50 and will be deleted in 3.55, use initCVResource:withAlgoModelDir:{@link #ByteRTCVideoEffect#initCVResource:withAlgoModelDir:} instead.
 * @type api
 * @region Video Effects
 * @brief Sets the video effects algorithm model path
 * @param modelPath <br>
 *         Model path
 */
- (void)setVideoEffectAlgoModelPath:(NSString * _Nonnull)modelPath __deprecated_msg("Will be removed in new version");


/**
 * 
 * @hidden for internal use only
 * @deprecated since 3.50 and will be deleted in 3.55, use ByteRTCVideoEffect.setAlgoModelResourceFinder instead.
 * @type api
 * @region Video Effects
 * @brief  Sets the video effects resource finder path and initializes video effects.
 * @param finder ResourceFinder path
 * @param deteter ResourceDeleter path
 * @return
 *      - 0: Success
 *      - 1000: The Effect SDK is not integrated.
 *      - 1001: This API is not available for your Effect SDK.
 *      - <0: Other errors. See [Error Code Table](https:
 */
- (int)setVideoEffectAlgoModelResourceFinder:(void *_Nonnull)finder deleter:(void *_Nonnull)deteter __deprecated_msg("Will be removed in new version");


/**
 * 
 * @deprecated since 3.50 and will be deleted in 3.55, use enableVideoEffect{@link #ByteRTCVideoEffect#enableVideoEffect} instead.
 * @type api
 * @region Video Effects
 * @brief  Create/destroy video effects engine
 * @param enabled Whether to create video effects engine <br>
 *        - YES: create
 *        - NO: destroy
 * @return
 *      - 0: Success
 *      - 1000: The Effect SDK is not integrated.
 *      - 1001: This API is not available for your Effect SDK.
 *      - <0: Other errors. See [Error Code Table](https:
 * @note
 *        - This method must be called after calling initCVResource:withAlgoModelDir:{@link #ByteRTCVideoEffect#initCVResource:withAlgoModelDir:} and setVideoEffectAlgoModelPath:{@link #ByteRTCVideo#setVideoEffectAlgoModelPath:}.
 *        - This method does not directly turn on/off video effects. After calling this method, you must call setVideoEffectNodes:{@link #ByteRTCVideo#setVideoEffectNodes:} to turn on video effects.
 *        - In a common scenario, the special effects engine will be destroyed with the destruction of the RTC engine. When you have high performance requirements, you can call false in this method to destroy the special effects engine separately when the special effects related functions are not used.
 */
- (int)enableVideoEffect:(BOOL)enabled NS_SWIFT_NAME(enableVideoEffect(_:)) __deprecated_msg("Will be removed in new version");


/**
 * 
 * @deprecated since 3.50 and will be deleted in 3.55, use setEffectNodes:{@link #ByteRTCVideoEffect#setEffectNodes:} instead.
 * @type api
 * @region Video Effects
 * @brief Sets video effects material package.
* @param effectNodePaths Array of effect material package paths. <br>
*        To remove the current video effect, set it to null.
 * @return
 *      - 0: Success
 *      - 1000: The Effect SDK is not integrated.
 *      - 1001: This API is not available for your Effect SDK.
 *      - <0: Other errors. See [Error Code Table](https:
 * @note Before calling this method, you must first call enableVideoEffect{@link #ByteRTCVideoEffect#enableVideoEffect}.
 */
- (int) setVideoEffectNodes:(NSArray <NSString *> *_Nonnull)effectNodePaths __deprecated_msg("Will be removed in new version");


/**
 * 
 * @hidden for internal use only
 * @deprecated since 3.50 and will be deleted in 3.55, use appendEffectNodes:{@link #ByteRTCVideoEffect#appendEffectNodes:} instead.
 * @type api
 * @region Video Effects
 * @brief  Appends video effects material package.
 * @param effectNodePaths Array of effect material package paths.
 * @return
 *      - 0: Success
 *      - 1000: The Effect SDK is not integrated.
 *      - 1001: This API is not available for your Effect SDK.
 *      - <0: Other errors. See [Error Code Table](https:
 * @note  This API adds new video effect to the video effect you set with setVideoEffectNodes:{@link #ByteRTCVideo#setVideoEffectNodes:}.
 */
- (int) appendVideoEffectNodes:(NSArray <NSString *> *_Nonnull)effectNodePaths NS_SWIFT_NAME(appendVideoEffectNodes(_:)) __deprecated_msg("Will be removed in new version");


/**
 * 
 * @hidden for internal use only
 * @deprecated since 3.50 and will be deleted in 3.55, use removeEffectNodes:{@link #ByteRTCVideoEffect#removeEffectNodes:} instead.
 * @type api
 * @region Video Effects
 * @brief Removes the designated video effects material package.
 * @param effectNodes Array of effect material package paths.
 * @return
 *      - 0: Success
 *      - 1000: The Effect SDK is not integrated.
 *      - 1001: This API is not available for your Effect SDK.
 *      - <0: Other errors. See [Error Code Table](https:
 * @note Removes the designated video effects in setVideoEffectNodes:{@link #ByteRTCVideo#setVideoEffectNodes:} or appendVideoEffectNodes:{@link #ByteRTCVideo#appendVideoEffectNodes:}.
 */
- (int) removeVideoEffectNodes:(NSArray <NSString *> *_Nonnull)effectNodePaths NS_SWIFT_NAME(removeVideoEffectNodes(_:)) __deprecated_msg("Will be removed in new version");


/**
 * 
 * @deprecated since 3.50 and will be deleted in 3.55, use updateEffectNode:key:value:{@link #ByteRTCVideoEffect#updateEffectNode:key:value:} instead.
 * @type api
 * @region Video Effects
 * @brief Sets effect intensity
 * @param nodePath  Effect material package path.
 * @param nodeKey  The name of the material key to be set. See [Material key correspondence instructions](http:
 * @param nodeValue The intensity value to be set. The value range is [0,1], and the setting beyond this range is invalid.
 * @return
 *      - 0: Success
 *      - 1000: The Effect SDK is not integrated.
 *      - 1001: This API is not available for your Effect SDK.
 *      - <0: Other errors. See [Error Code Table](https:
 * @note This interface is only applicable to special effects resources that contain the above three parameters at the same time. For special effects that do not have strength parameters, such as most stickers, this interface call is invalid.
 */
- (int) updateVideoEffectNode:(NSString * _Nonnull)nodePath nodeKey:(NSString * _Nonnull)nodeKey  nodeValue:(float) nodeValue NS_SWIFT_NAME(updateVideoEffectNode(_:nodeKey:nodeValue:)) __deprecated_msg("Will be removed in new version");


/**
 * 
 * @deprecated since 3.50 and will be deleted in 3.55, use setColorFilter:{@link #ByteRTCVideoEffect#setColorFilter:} instead.
 * @type api
 * @region Video Effects
 * @brief Sets color filter
 * @param resPath <br>
 *        Filter effect package absolute path
 * @return
 *      - 0: Success
 *      - 1000: The Effect SDK is not integrated.
 *      - 1001: This API is not available for your Effect SDK.
 *      - <0: Other errors. See [Error Code Table](https:
 */
- (int) setVideoEffectColorFilter:(NSString * _Nonnull)resPath __deprecated_msg("Will be removed in new version");


/**
 * 
 * @deprecated since 3.50 and will be deleted in 3.55, use setColorFilterIntensity:{@link #ByteRTCVideoEffect#setColorFilterIntensity:} instead.
 * @type api
 * @region Video Effects
 * @brief Sets the color filter intensity
 * @param intensity Filter intensity that is enabled. The value range [0,1] is invalid when the range is exceeded
 * @return
 *      - 0: Success
 *      - 1000: The Effect SDK is not integrated.
 *      - 1001: This API is not available for your Effect SDK.
 *      - <0: Other errors. See [Error Code Table](https:
 */
- (int) setVideoEffectColorFilterIntensity:(float) intensity __deprecated_msg("Will be removed in new version");


/**
 * 
 * @deprecated since 3.50 and will be deleted in 3.55, use enableVirtualBackground:withSource:{@link #ByteRTCVideoEffect#enableVirtualBackground:withSource:} instead.
 * @type api
 * @region Video Effects
 * @brief Set the original background to a specified image or a solid color. <br>
 *        To disable this effect, set the modelPath parameter to null.
 * @param modelPath Set the path of virtual background effects.
 * @param source Set the local path of background images. See ByteRTCVirtualBackgroundSource{@link #ByteRTCVirtualBackgroundSource}.
 * @return
 *        - 0：Success.
 *        - 1000：The BytePlus Effects SDK is not integrated.
 *        - 1001：This feature is not supported in the BytePlus Effects SDK.
 *        - < 0：Other errors. See [Error Code Table](https:
 * @note
 *        Before calling this method, you should call initCVResource:withAlgoModelDir:{@link #ByteRTCVideoEffect#initCVResource:withAlgoModelDir:}、setVideoEffectAlgoModelPath:{@link #ByteRTCVideo#setVideoEffectAlgoModelPath:}, and enableVideoEffect{@link #ByteRTCVideoEffect#enableVideoEffect} in order.
 */
- (int) setBackgroundSticker:(NSString* _Nullable)modelPath source:(ByteRTCVirtualBackgroundSource* _Nonnull)source __deprecated_msg("Will be removed in new version");


/**
 * 
 * @hidden for internal use only
 * @deprecated since 3.50 and will be deleted in 3.55, use setVideoEffectExpressionDetect:{@link #ByteRTCVideo#setVideoEffectExpressionDetect:} instead.
 * @type api
 * @region Video Effects
 * @brief  Sets the configuration for video effects expression detection.
 * @param config Expression detection configuration. See ByteRTCExpressionDetectConfig{@link #ByteRTCExpressionDetectConfig}.
 * @return
 *      - 0: Success
 *      - 1000: The Effect SDK is not integrated.
 *      - 1001: This API is not available for your Effect SDK.
 *      - <0: Other errors. See [Error Code Table](https:
 */
- (int)setVideoEffectExpressionDetect:(ByteRTCExpressionDetectConfig *_Nonnull)config __deprecated_msg("Will be removed in new version");


/**
 * 
 * @deprecated since 3.50 and will be deleted in 3.55, use registerFaceDetectionObserver:withInterval:{@link #ByteRTCVideoEffect#registerFaceDetectionObserver:withInterval:} instead.
 * @type api
 * @region Video Effects
 * @brief  Register the observer for the result of face detection. <br>
 *        With this observer, you will receive onFaceDetectResult:{@link #ByteRTCFaceDetectionObserver#onFaceDetectResult:} periodically.
 * @param faceDetectionObserver See ByteRTCFaceDetectionObserver{@link #ByteRTCFaceDetectionObserver}.
 * @param interval Time interval in ms. The value should be greater than 0. The actual time interval of receiving callbacks is between `interval` and `interval + the time slot of a captured video frame`.
 * @return
 *       - 0: Success
 *       - <0: Failure
 */
- (int) registerFaceDetectionObserver:(_Nullable id<ByteRTCFaceDetectionObserver>)faceDetectionObserver
                  withInterval:(NSInteger)interval NS_SWIFT_NAME(registerFaceDetectionObserver(_:withInterval:)) __deprecated_msg("Will be removed in new version");


/**
 * 
 * @type api
 * @region Audio & Video Processing
 * @brief Enables/Disables basic beauty effects.
 * @param enable Whether to enable basic beauty effects. <br>
 *        - YES: Enables basic beauty effects.
 *        - NO: (Default) Disables basic beauty effects.
 * @return
 *        - 0: Success.
 *        - –1000: The Effect SDK is not integrated.
 *        - –1001: This API is not available for your current RTC SDK.
 *        - –1002: This API is not available for your current Effect SDK. You can upgrade your Effect SDK to v4.4.2+.
 *        - –1003: Contact our technical support team for further instructions.
 *        - –1004: Downloading related resources. The beauty effects will take effect after downloading.
 *        - –1007: Invalid basic beauty path, you need to ensure that the basic_beauty folder exists in effect-sdk.framework, or ensure that the RTCBasicBeauty.bundle resource exists in the main bundle.
 *        - <0: Failure. Effect SDK internal error. For specific error code, see [Error Code Table](https:
 * @note
 *        - You cannot use the basic beauty effects and the advanced effect features at the same time. See [how to use advanced effect features](https:
 *        - You need to integrate Effect SDK before calling this API. Effect SDK v4.4.2+ is recommended.
 *        - Call setBeautyIntensity:withIntensity:{@link #ByteRTCVideo#setBeautyIntensity:withIntensity:} to set the beauty effect intensity. If you do not set the intensity before calling this API, the default intensity will be enabled. The default values for the intensity of each beauty mode are as follows: 0.7 for brightning, 0.8 for smoothing, 0.5 for sharpening, and 0.7 for clarity.
 *        - This API is not applicable to screen capturing.
 */
- (int) enableEffectBeauty:(BOOL)enable;


/**
 * 
 * @type api
 * @region Audio & Video Processing
 * @brief Sets the beauty effect intensity.
 * @param beautyMode Basic beauty effect. See ByteRTCEffectBeautyMode{@link #ByteRTCEffectBeautyMode}.
 * @param intensity Beauty effect intensity in range of [0,1]. When you set it to 0, the beauty effect will be turned off. <br>
 *                  The default values for the intensity of each beauty mode are as follows: 0.7 for brightning, 0.8 for smoothing, 0.5 for sharpening, and 0.7 for clarity.
 * @return
 *        - 0: Success.
 *        - –1000: The Effect SDK is not integrated.
 *        - –1001: This API is not available for your current RTC SDK.
 *        - <0: Failure. Effect SDK internal error. For specific error code, see [Error Code Table](https:
 * @note
 *        - If you call this API before calling enableVideoEffect{@link #ByteRTCVideoEffect#enableVideoEffect}, the default settings of beauty effect intensity will adjust accordingly.
 *        - If you destroy the engine, the beauty effect settings will be invalid.
 */
- (int) setBeautyIntensity:(ByteRTCEffectBeautyMode) beautyMode
            withIntensity:(float)intensity;

#pragma mark - ICameraControl

/**
 * 
 * @hidden(macOS)
 * @type api
 * @region  video management
 * @brief Sets the zoom magnification of the currently used camera (front/rear).
 * @param zoomRatio Camera zoom parameters. 1.0 means scaling to the original image, the maximum value that can be set is obtained through the getCameraZoomMaxRatio{@link #ByteRTCVideo#getCameraZoomMaxRatio} method
 * @return
 *       - 0: Success
 *       - -1: Failure
 * @note
 *         - The camera zoom factor can only be set when startVideoCapture{@link #ByteRTCVideo#startVideoCapture} is called for video capture using the SDK internal capture module.
 *         - The setting result fails after calling stopVideoCapture{@link #ByteRTCVideo#stopVideoCapture} to turn off internal collection.
 *         - Call setVideoDigitalZoomConfig:size:{@link #ByteRTCVideo#setVideoDigitalZoomConfig:size:} to set digital zoom. Call setVideoDigitalZoomControl:{@link #ByteRTCVideo#setVideoDigitalZoomControl:} to perform digital zoom.
 */
- (int) setCameraZoomRatio: (float) zoomRatio;

/**
 * 
 * @hidden(macOS)
 * @type api
 * @region  video management
 * @brief Gets the maximum zoom magnification of the currently used camera (front/rear).
 * @return  The maximum zoom parameters that can be set
 */
- (float) getCameraZoomMaxRatio;

/**
 * 
 * @hidden(macOS)
 * @type api
 * @region  video management
 * @brief Detects whether the currently used camera supports zoom (digital/optical zoom).
 * @return
 *       - true: supports scaling
 *       - false: does not support scaling
 */
- (bool) isCameraZoomSupported;

/**
 * 
 * @hidden(macOS)
 * @type api
 * @region  video management
 * @brief Detects whether the currently used camera supports flash.
 * @return
 *       - true: support fill light
 *       - false: not support fill light
 */
- (bool) isCameraTorchSupported;

/**
 * 
 * @hidden(macOS)
 * @type api
 * @region  video management
 * @brief Turns on/off the flash of the currently used camera.
 * @param torchState <br>
 *          Fill light status. See ByteRTCTorchState{@link #ByteRTCTorchState}
 * @return
 *       - 0: Success
 *       - -1: Failure
 */
- (int) setCameraTorch: (ByteRTCTorchState)torchState;

/**
 * 
 * @hidden(macOS)
 * @type api
 * @region Video Management
 * @brief Checks if manual focus is available for the currently used camera.
 * @return
 *        - true: Available.
 *        - false: Unavailable.
 * @note You must call startVideoCapture{@link #ByteRTCVideo#startVideoCapture} to start SDK internal video capturing before calling this API.
 */
- (bool)isCameraFocusPositionSupported;

/**
 * 
 * @hidden(macOS)
 * @type api
 * @region Video Management
 * @brief Sets the manual focus position for the currently used camera.
 * @param position The position of the focus point. Setting the upper-left corner of the canvas as the origin, the `x` in `position` means the x-coordinate of the focus point in range of [0, 1], and the `y` in `position` means the y-coordinate of the focus point in range of [0, 1].
 * @return
 *        - 0: Success.
 *        - < 0: Failure.
 * @note
 *        - You must call startVideoCapture{@link #ByteRTCVideo#startVideoCapture} to start SDK internal video capturing, and use SDK internal rendering before calling this API.
 *        - When you set the focus point at the center of the canvas, the focus point setting will be canceled.
 *        - The camera focus point setting will be invalid after calling stopVideoCapture{@link #ByteRTCVideo#stopVideoCapture} to stop internal capturing.
 */
- (int)setCameraFocusPosition:(CGPoint)position;

/**
 * 
 * @hidden(macOS)
 * @type api
 * @region Video Management
 * @brief Checks if manual exposure setting is available for the currently used camera.
 * @return
 *        - true: Available.
 *        - false: Unavailable.
 * @note You must call startVideoCapture{@link #ByteRTCVideo#startVideoCapture} to start SDK internal video capturing before calling this API.
 */
- (bool)isCameraExposurePositionSupported;

/**
 * 
 * @hidden(macOS)
 * @type api
 * @region Video Management
 * @brief Sets the manual exposure position for the currently used camera.
 * @param position The position of the exposure point. Setting the upper-left corner of the canvas as the origin, the `x` in `position` means the x-coordinate of the exposure point in range of [0, 1], and the `y` in `position` means the y-coordinate of the exposure point in range of [0, 1].
 * @return
 *        - 0: Success.
 *        - < 0: Failure.
 * @note
 *        - You must call startVideoCapture{@link #ByteRTCVideo#startVideoCapture} to start SDK internal video capturing, and use SDK internal rendering before calling this API.
 *        - When you set the exposure point at the center of the canvas, the exposure point setting will be canceled.
 *        - The camera exposure point setting will be invalid after calling stopVideoCapture{@link #ByteRTCVideo#stopVideoCapture} to stop internal capturing.
 */
- (int)setCameraExposurePosition:(CGPoint)position;


/**
 * 
 * @hidden(macOS)
 * @type api
 * @region Video Management
 * @brief Sets the exposure compensation for the currently used camera.
 * @param val Exposure compensation in range of [-1, 1]. Default to 0, which means no exposure compensation.
 * @return
 *        - 0: Success.
 *        - < 0: Failure.
 * @note
 *        - You must call startVideoCapture{@link #ByteRTCVideo#startVideoCapture} to start SDK internal video capturing, and use SDK internal rendering before calling this API.
 *        - The camera exposure compensation setting will be invalid after calling stopVideoCapture{@link #ByteRTCVideo#stopVideoCapture} to stop internal capturing.
 */
- (int)setCameraExposureCompensation:(float)val;


/**
 * 
 * @type api
 * @hidden(macOS, Windows, Linux)
 * @valid since 353
 * @brief Enable or disable face auto exposure mode during internal video capture. This mode fixes the problem that the face is too dark under strong backlight; but it will also cause the problem of too bright/too dark in the area outside the ROI region.
 * @param enable Whether to enable the mode. True by default.
 * @return
 *        - 0: Success.
 *        - !0: Failure.
 * @note Calling this API takes effect immediately whether before or after internal video capturing.
 */
- (int)enableCameraAutoExposureFaceMode:(bool)enable;


/**
 * 
 * @hidden(macOS)
 * @type api
 * @valid since 353
 * @brief Set the minimum frame rate of of the dynamic framerate mode during internal video capture.
 * @param framerate The minimum value in fps. The default value is 7. <br>
 *                  The maximum value of the dynamic framerate mode is set by calling setVideoCaptureConfig:{@link #ByteRTCVideo#setVideoCaptureConfig:}. When minimum value exceeds the maximum value, the frame rate is set to a fixed value as the maximum value; otherwise, dynamic framerate mode is enabled.
 * @return
 *        - 0: Success.
 *        - !0: Failure.
 * @note
 *        - You must call this API before calling startVideoCapture{@link #ByteRTCVideo#startVideoCapture} to enable internal capture to make the setting valid.
 *        - If the maximum frame rate changes due to performance degradation, static adaptation, etc., the set minimum frame rate value will be re-compared with the new maximum value. Changes in comparison results may cause switch between fixed and dynamic frame rate modes.
 */
- (int)setCameraAdaptiveMinimumFrameRate:(int)framerate;

#pragma mark - MediaMetadataData InnerVideoSource

/**
 * 
 * @deprecated since 3.50 and will be deleted in 3.55, use sendSEIMessage:andMessage:andRepeatCount:andCountPerFrame:{@link #ByteRTCVideo#sendSEIMessage:andMessage:andRepeatCount:andCountPerFrame:} instead.
 * @type api
 * @region Message
 * @brief Sends SEI data. <br>
 *        In a video call scenario, SEI is sent with the video frame, while in a voice call scenario, SDK will automatically publish a black frame with a resolution of 16px × 16px to carry SEI data.
 * @param streamIndex Specifys the type of media stream that carries SEI data. See ByteRTCStreamIndex{@link #ByteRTCStreamIndex}. <br>
 *        In a voice call, you should set this parameter to `ByteRTCStreamIndexMain`, otherwise the SEI data is discarded and cannot be sent to the remote user.
 * @param message SEI data up to 4KB in length.
 * @param repeatCount Number of times a message is sent repeatedly. The value range is [0,30]. <br>
 *                    After calling this API, the SEI data will be added to a consecutive `repeatCount+1` number of video frames starting from the current frame.
 * @return
 *         - `>=0`: The number of SEIs to be added to the video frame
 *         - `<0`: Failure
 * @note
 *         - In a voice call scenario, this API can be called to send SEI data only in internal capture mode and with a frequency of 15/repeat_count FPS.
 *         - Each video frame carrys only the SEI data received within 2s before and after. In a voice call scenario, if no SEI data is sent within 1min after calling this API, SDK will automatically cancel publishing black frames.
 *         - After the message is sent successfully, the remote user who subscribed your video stream will receive rtcEngine:onSEIMessageReceived:andMessage:{@link #ByteRTCVideoDelegate#rtcEngine:onSEIMessageReceived:andMessage:}.
 *         - When you switch from a voice call to a video call, SEI data will automatically start to be sent with normally captured video frames instead of black frames.
 */
- (int)sendSEIMessage:(ByteRTCStreamIndex)streamIndex andMessage:(NSData* _Nonnull)message andRepeatCount:(int)repeatCount __deprecated_msg("Will be removed in new version");

/**
 * 
 * @type api
 * @region Message
 * @brief Sends SEI data. <br>
 *        In a video call scenario, SEI is sent with the video frame, while in a voice call scenario, SDK will automatically publish a black frame with a resolution of 16 × 16 pixels to carry SEI data.
 * @param streamIndex Specifys the type of media stream that carries SEI data. See ByteRTCStreamIndex{@link #ByteRTCStreamIndex}. <br>
 *        In a voice call, you should set this parameter to `ByteRTCStreamIndexMain`, otherwise the SEI data is discarded and cannot be sent to the remote user.
 * @param message SEI data. No more than 4 KB SEI data per frame is recommended.
 * @param repeatCount Number of times a message is sent repeatedly. The value range is [0, max{29, %{video frame rate}-1}]. Recommended range: [2,4]. <br>
 *                    After calling this API, the SEI data will be added to a consecutive `repeatCount+1` number of video frames starting from the current frame.
 * @param mode SEI sending mode. See ByteRTCSEICountPerFrame{@link #ByteRTCSEICountPerFrame}.
 * @return
 *         - >= 0: The number of SEIs to be added to the video frame
 *         - < 0: Failure
 * @note
 *         - We recommend the number of SEI messages per second should not exceed the current video frame rate. In a voice call, the blank-frame rate is 15 fps.
 *         - In a voice call, this API can be called to send SEI data only in internal capture mode.
 *         - In a video call, the custom captured video frame can also be used for sending SEI data if the original video frame contains no SEI data, otherwise calling this method will not take effect.
 *         - Each video frame carrys only the SEI data received within 2s before and after. In a voice call scenario, if no SEI data is sent within 1min after calling this API, SDK will automatically cancel publishing black frames.
 *         - After the message is sent successfully, the remote user who subscribed your video stream will receive rtcEngine:onSEIMessageReceived:andMessage:{@link #ByteRTCVideoDelegate#rtcEngine:onSEIMessageReceived:andMessage:}.
 *         - When you switch from a voice call to a video call, SEI data will automatically start to be sent with normally captured video frames instead of black frames.
 */
- (int)sendSEIMessage:(ByteRTCStreamIndex)streamIndex andMessage:(NSData* _Nonnull)message andRepeatCount:(int)repeatCount andCountPerFrame:(ByteRTCSEICountPerFrame) mode;
    
    /**
     * 
     * @valid since 3.56
     * @hidden for internal use only
     * @type api
     * @region Message
     * @brief <span id="IRTCVideo-sendseimessage-2"></span> Public stream sends SEI data.
     * @param streamIndex Specifys the type of media stream that carries SEI data. See ByteRTCStreamIndex{@link #ByteRTCStreamIndex}.
     * @param channelId SEI message channel id. The value range is [0 - 255]. With this parameter, you can set different ChannelIDs for different recipients. In this way, different recipients can choose the SEI information  based on the ChannelID received in the callback.
     * @param message SEI data.
     * @param repeatCount Number of times a message is sent repeatedly. The value range is [0, max{29, %{video frame rate}-1}]. Recommended range: [2,4]. <br>
     *                    After calling this API, the SEI data will be added to a consecutive `repeat_count+1` number of video frames starting from the current frame.
     * @param mode SEI sending mode. See ByteRTCSEICountPerFrame{@link #ByteRTCSEICountPerFrame}.
     * @return
     *        - < 0: Failure
     *        - = 0: The current sending queue is full and SEI cannot be sent.
     *        - > 0: Success. The number of SEI data sent.
     * @note
     *         - We recommend the number of SEI messages per second should not exceed the current video frame rate.
     *         - In a video call, the custom captured video frame can also be used for sending SEI data if the original video frame contains no SEI data, otherwise calling this method will not take effect.
     *         - Each video frame carrys only the SEI data received within 2s before and after. In a voice call scenario, if no SEI data is sent within 1min after calling this API, SDK will automatically cancel publishing black frames.
     *         - After the message is sent successfully, the remote user who subscribed your video stream will receive rtcEngine:onPublicStreamSEIMessageReceivedWithChannel:andChannelId:andMessage:{@link #ByteRTCVideoDelegate#rtcEngine:onPublicStreamSEIMessageReceivedWithChannel:andChannelId:andMessage:}.
     *         - When the call fails, neither the local nor the remote side will receive a callback.
     */
- (int)sendPublicStreamSEIMessage:(ByteRTCStreamIndex)streamIndex andChannelId:(int)channelId andMessage:(NSData* _Nonnull)message andRepeatCount:(int)repeatCount andCountPerFrame:(ByteRTCSEICountPerFrame)mode;
#pragma mark - VideoFrameObserver InnerVideoSource

/**
 * 
 * @type api
 * @valid since 3.51
 * @brief Set the step size for each digital zooming control to the local videos.
 * @param type Required. Identifying which type the `size` is referring to. Refer to ByteRTCZoomConfigType{@link #ByteRTCZoomConfigType}.
 * @param size Required. Reserved to three decimal places. It defaults to `0`. <br>
 *                  The meaning and range vary from different `type`s. If the scale or moving distance exceeds the range, the limit is taken as the result. <br>
 *                  - `ByteRTCZoomConfigTypeFocusOffset`: Increasement or decrease to the scaling factor. Range: [0, 7]. For example, when it is set to 0.5 and setVideoDigitalZoomControl:{@link #ByteRTCVideo#setVideoDigitalZoomControl:} is called to zoom in, the scale will increase `0.5`. The scale ranges [1，8] and defaults to `1`, which means an original size.
 *                  - `ByteRTCZoomConfigTypeMoveOffset`：Ratio of the distance to the border of video images. It ranges [0, 0.5] and defaults to `0`, which means no offset. When you call setVideoDigitalZoomControl:{@link #ByteRTCVideo#setVideoDigitalZoomControl:} and choose `CAMERA_MOVE_LEFT`, the moving distance is size x original width. While for the `CAMERA_MOVE_UP`, the moving distance is size x original height. Suppose that a video spans 1080 px and the `size` is set to `0.5` so that the distance would be 0.5 x 1080 px = 540 px.
 * @return
 *        - 0: Success.
 *        - ! 0: Failure.
 * @note
 *        - Only one size can be set for a single call. You must call this API to pass values respectively if you intend to set multiple `size`s.
 *        - As the default `size` is `0`, you must call this API before performing any digital zoom control by calling setVideoDigitalZoomControl:{@link #ByteRTCVideo#setVideoDigitalZoomControl:} or startVideoDigitalZoomControl:{@link #ByteRTCVideo#startVideoDigitalZoomControl:}.
 */
- (int)setVideoDigitalZoomConfig:(ByteRTCZoomConfigType)type size:(float)size;

/**
 * 
 * @type api
 * @brief Digital zoom or move the local video image once. This action affects both the video preview locally and the stream published.
 * @param direction Action of the digital zoom control. Refer to ByteRTCZoomDirectionType{@link #ByteRTCZoomDirectionType}.
 * @return
 *        - 0: Success.
 *        - ! 0: Failure.
 * @note
 *        - As the default offset is `0`, you must call setVideoDigitalZoomConfig:size:{@link #ByteRTCVideo#setVideoDigitalZoomConfig:size:} before this API.
 *        - You can only move video images after they are magnified via this API or startVideoDigitalZoomControl:{@link #ByteRTCVideo#startVideoDigitalZoomControl:}.
 *        - When you request an out-of-range scale or movement, SDK will execute it with the limits. For example, when the image has been moved to the border, the image cannot be zoomed out, or has been magnified to 8x.
 *        - Call startVideoDigitalZoomControl:{@link #ByteRTCVideo#startVideoDigitalZoomControl:} to have a continuous and repeatedly digital zoom control.
 *        - Mobile devices can control the optical zoom of the camera, see setCameraZoomRatio:{@link #ByteRTCVideo#setCameraZoomRatio:}.
 */
- (int)setVideoDigitalZoomControl:(ByteRTCZoomDirectionType) direction;

/**
 * 
 * @type api
 * @valid since 3.51
 * @brief Continuous and repeatedly digital zoom control. This action effect both the video preview locally and the stream published.
 * @param direction Action of the digital zoom control. Refer to ByteRTCZoomDirectionType{@link #ByteRTCZoomDirectionType}.
 * @return
 *        - 0: Success.
 *        - ! 0: Failure.
 * @note
 *        - As the default offset is `0`, you must call setVideoDigitalZoomConfig:size:{@link #ByteRTCVideo#setVideoDigitalZoomConfig:size:} before this API.
 *        - You can only move video images after they are magnified via this API or setVideoDigitalZoomControl:{@link #ByteRTCVideo#setVideoDigitalZoomControl:}.
 *        - The control process stops when the scale reaches the limit, or the images have been moved to the border. if the next action exceeds the scale or movement range, SDK will execute it with the limits.
 *        - Call stopVideoDigitalZoomControl{@link #ByteRTCVideo#stopVideoDigitalZoomControl} to stop the ongoing zoom control.
 *        - Call setVideoDigitalZoomControl:{@link #ByteRTCVideo#setVideoDigitalZoomControl:} to have a one-time digital zoom control.
 *        - Refer to setCameraZoomRatio:{@link #ByteRTCVideo#setCameraZoomRatio:} if you intend to have an optical zoom control to the camera. For iOS only.
 */
- (int)startVideoDigitalZoomControl:(ByteRTCZoomDirectionType)direction;

/**
 * 
 * @type api
 * @brief Stop the ongoing digital zoom control instantly.
 * @return
 *        - 0: Success.
 *        - ! 0: Failure.
 * @note Refer to startVideoDigitalZoomControl:{@link #ByteRTCVideo#startVideoDigitalZoomControl:} for starting digital zooming.
 */
- (int)stopVideoDigitalZoomControl;

/**
 * 
 * @type api
 * @region  Video Processing
 * @brief  Set up a custom video preprocessor. <br>
 *         Using this video preprocessor, you can call processVideoFrame:{@link #ByteRTCVideoProcessorDelegate#processVideoFrame:} to preprocess the video frames captured by the RTC SDK and use the processed video frames for RTC audio & video communication.
 * @param processor Custom video processor. See ByteRTCVideoProcessorDelegate{@link #ByteRTCVideoProcessorDelegate}. If null is passed in, the video frames captured by the RTC SDK are not preprocessed. <br>
 *        SDK only holds weak references to the processor, you should guarantee its Life Time. <br>
 *         When designing the'processor ', the video frame data should be obtained from the'textureBuf' field of ByteRTCVideoFrame{@link #ByteRTCVideoFrame}; <br>
 *         The video frame data returned after processing should be in the format of'ByteRTCVideoPixelFormat 'in ByteRTCVideoPixelFormat{@link #ByteRTCVideoPixelFormat}, and must be stored in the'textureBuf' field that returns the frame data.
 * @param config Customize the settings applicable to the video preprocessor. See ByteRTCVideoPreprocessorConfig{@link #ByteRTCVideoPreprocessorConfig}. <br>
 *                Currently, the 'required_pixel_format 'in'config' only supports: 'ByteRTCVideoPixelFormatI420' and'ByteRTCVideoPixelFormatUnknown ': <br>
 *                - When set to'Unknown', the RTC SDK gives the format of the video frame for processing by the processor, that is, the format of the acquisition.
 *                - When set to'ByteRTCVideoPixelFormatI420 ', the RTC SDK will convert the captured video into the corresponding format for pre-processing. This method call fails when
 *                - Is set to another value.
 * @return
 *          - 0: Success.
 *          +! 0: failure
 * @note
 *         - When this interface is called repeatedly, only the last call takes effect. The effects do not stack.
 *         - For iOS platforms, setting the requiredPixelFormat in ByteRTCVideoPreprocessorConfig{@link #ByteRTCVideoPreprocessorConfig} to'kVideoPixelFormatUnknown 'brings some performance optimization by avoiding format conversion.
 */
- (int)registerLocalVideoProcessor:(_Nullable id<ByteRTCVideoProcessorDelegate>) processor
                  withConfig:(ByteRTCVideoPreprocessorConfig* _Nullable)config NS_SWIFT_NAME(registerLocalVideoProcessor(_:withConfig:));
#pragma mark - LocalEncodedVideoFrameObserver

/**
 * 
 * @type api
 * @region Video Data Callback
 * @brief Register a local video frame observer. <br>
 *        This method applys to both internal capturing and custom capturing. <br>
 *        After calling this API, SDK triggers onLocalEncodedVideoFrame:Frame:{@link #ByteRTCLocalEncodedVideoFrameObserver#onLocalEncodedVideoFrame:Frame:} whenever a video frame is captured.
 * @param frameObserver Local video frame observer. See ByteRTCLocalEncodedVideoFrameObserver{@link #ByteRTCLocalEncodedVideoFrameObserver}. You can cancel the registration by setting it to `nullptr`.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note You can call this API before or after entering the RTC room. Calling this API before entering the room ensures that video frames are monitored and callbacks are triggered as early as possible.
 */
- (int)registerLocalEncodedVideoFrameObserver:(_Nullable id<ByteRTCLocalEncodedVideoFrameObserver>) frameObserver NS_SWIFT_NAME(registerLocalEncodedVideoFrameObserver(_:));
#pragma mark Audio Routing Controller


/**
 * 
 * @hidden(macOS)
 * @deprecated since 3.45 and will be deleted in 3.51, use setDefaultAudioRoute:{@link #ByteRTCVideo#setDefaultAudioRoute:} instead.
 * @type api
 * @region Audio management
 * @brief  Sets the speaker or the earpiece as the audio playback device. The audio playback device defaults to the speaker. <br>
 *         When the audio playback device changes, you will receive the rtcEngine:onAudioPlaybackDeviceChanged:{@link #ByteRTCVideoDelegate#rtcEngine:onAudioPlaybackDeviceChanged:} callback.
 * @param audioPlaybackDevice  Audio playback device (speaker or earpiece). See ByteRTCAudioPlaybackDevice{@link #ByteRTCAudioPlaybackDevice}.
 * @return
 *         - 0: Success
 *         - < 0: failure
 * @note
 *        - This API is applicable for mobile devices such as mobile phones.
 *        - The earpiece and the speaker are mobile devices' built-in audio playback devices. The earpiece is usually used for calling and the speaker is usually used for playing out loud.
 *        - After connecting to a wired or bluetooth audio playback device, the audio route will switch to them. For the selected volume type in different audio scenarios, see ByteRTCAudioScenarioType{@link #ByteRTCAudioScenarioType}.
 *        - You can call this API before or after joining room.
 */
- (int)setAudioPlaybackDevice:(ByteRTCAudioPlaybackDevice)audioPlaybackDevice __deprecated_msg("Will be removed in new version");

/**
 * 
 * @hidden(macOS)
 * @type api
 * @brief Set the current audio playback route. The default device is set via setDefaultAudioRoute:{@link #ByteRTCVideo#setDefaultAudioRoute:}. <br>
 *         When the audio playback route changes, you will receive rtcEngine:onAudioRouteChanged:{@link #ByteRTCVideoDelegate#rtcEngine:onAudioRouteChanged:}.
 * @param audioRoute Audio route. Refer to ByteRTCAudioRoute{@link #ByteRTCAudioRoute}. You can only use the build-in speaker or the default route.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *      - You can implement most scenarios by calling setDefaultAudioRoute:{@link #ByteRTCVideo#setDefaultAudioRoute:} and the default audio route switching strategy of the RTC SDK. For details about the strategy, see [Set the Audio Route](https:
 *      - This interface is only supported in the `ByteRTCAudioScenarioCommunication` audio scenario. Call setAudioScenario:{@link #ByteRTCVideo#setAudioScenario:} to switch between different audio scenarios.
 *      - For the volume type in different audio scenarios, refer to ByteRTCAudioScenarioType{@link #ByteRTCAudioScenarioType}.
 */
- (int)setAudioRoute:(ByteRTCAudioRoute)audioRoute;

/**
 * 
 * @hidden(macOS)
 * @type api
 * @region Audio management
 * @brief Gets the information of currently-using playback route.
 * @return See ByteRTCAudioRoute{@link #ByteRTCAudioRoute}.
 * @note To set the audio playback route, see setAudioRoute:{@link #ByteRTCVideo#setAudioRoute:}. For mobile only.
 */
- (ByteRTCAudioRoute)getAudioRoute;

/**
 * 
 * @type api
 * @brief Enables the audio process mode for external sound card.
 * @param enable <br>
 *        - true: enable
 *        - false: disable (by default)
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *         - When you use external sound card for audio capture, enable this mode for better audio quality.
 *         - When using the mode, you can only use earphones. If you need to use internal or external speaker, disable this mode.
 */
- (int)enableExternalSoundCard:(bool)enable;
 
/**
 * 
 * @hidden(macOS)
 * @type api
 * @brief Set the speaker or earpiece as the default audio playback device.
 * @param audioRoute Audio playback device. Refer to ByteRTCAudioRoute{@link #ByteRTCAudioRoute}. You can only use earpiece and speakerphone.
 * @return
 *         - 0: Success.
 *         - < 0: failure. It fails when the device designated is neither a speaker nor an earpiece.
 * @note For the default audio route switching strategy of the RTC SDK, see [Set the Audio Route](https:
 */
- (int)setDefaultAudioRoute:(ByteRTCAudioRoute)audioRoute;
#pragma mark Push mixed or signle stream to CDN

/**
 * 
 * @deprecated since 3.52, will be deleted in 3.58, use startPushMixedStreamToCDN:mixedConfig:observer:{@link #ByteRTCVideo#startPushMixedStreamToCDN:mixedConfig:observer:} instead.
 * @type api
 * @region Push to CDN
 * @brief Creates a new task of pushing media streams to CDN and sets the relevant configurations. <br>
 *        When pushing more than one live streams in the same task, SDK will first mix those streams into one single stream and then push it to CDN.
 * @param taskID Task ID. The length should not exceed 126 bytes. <br>
 *        You may want to push more than one mixed stream to CDN from the same room. When you do that, use different ID for corresponding tasks; if you will start only one task, use an empty string.
 * @param transcoding Configurations to be set when pushing streams to CDN. See ByteRTCLiveTranscoding{@link #ByteRTCLiveTranscoding}
 * @param observer Register this observer to receive callbacks from the SDK. See LiveTranscodingDelegate{@link #LiveTranscodingDelegate}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *       - Before calling this API，you need to enable Push to CDN on the [console](https:
 *        - After this API is called, the local user will receive onStreamMixingEvent:taskId:error:mixType:{@link #LiveTranscodingDelegate#onStreamMixingEvent:taskId:error:mixType:} about the result and errors during the pushing process.
 *        - Call stopLiveTranscoding:{@link #ByteRTCVideo#stopLiveTranscoding:} to stop pushing streams to CDN.
 */
- (int)startLiveTranscoding:(NSString * _Nonnull)taskID transcoding:(ByteRTCLiveTranscoding *_Nullable)transcoding observer:(id<LiveTranscodingDelegate> _Nullable)observer __deprecated_msg("deprecated since 352, will be deleted in 358, use startPushMixedStreamToCDN instead");

/**
 * 
 * @deprecated since 3.52, will be deleted in 3.58, use stopPushStreamToCDN:{@link #ByteRTCVideo#stopPushStreamToCDN:} instead.
 * @type api
 * @region Push to CDN
 * @brief Stops pushing media streams to CDN.  You will be informed of the change via the onStreamMixingEvent:taskId:error:mixType:{@link #LiveTranscodingDelegate#onStreamMixingEvent:taskId:error:mixType:} callback. <br>
 *        For starting pushing media streams to CDN, see startLiveTranscoding:transcoding:observer:{@link #ByteRTCVideo#startLiveTranscoding:transcoding:observer:}.
 * @param taskID Task ID. Specifys which pushing task you want to stop.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 */
- (int)stopLiveTranscoding:(NSString *_Nonnull)taskID __deprecated_msg("deprecated since 352, will be deleted in 358, use stopPushStreamToCDN instead");

/**
 * 
 * @deprecated since 3.52, will be deleted in 3.58, use updatePushMixedStreamToCDN:mixedConfig:{@link #ByteRTCVideo#updatePushMixedStreamToCDN:mixedConfig:} instead.
 * @type api
 * @region Multi-room
 * @brief Updates parameters needed when pushing media streams to CDN.  The local user will be informed of the change via the onStreamMixingEvent:taskId:error:mixType:{@link #LiveTranscodingDelegate#onStreamMixingEvent:taskId:error:mixType:} callback. <br>
 *        After enabling the function of pushing streams to CDN, you can call this API to update the relevant configurations.
 * @param taskID Task ID. Specifys of which pushing task you want to update the parameters.
 * @param Transcoding Configurations that you want to update. See ByteRTCLiveTranscoding{@link #ByteRTCLiveTranscoding} for specific indications. You can update any property for the task unless it is specified as unavailable for updates. <br>
 *                   If you left some properties blank, you can expect these properties to be set to their default values.
 * @return  API call result. <br>
 *          - 0: Success
 *          - < 0: failure
 */
- (int)updateLiveTranscoding:(NSString *_Nonnull)taskID transcoding:(ByteRTCLiveTranscoding *_Nonnull)transcoding __deprecated_msg("deprecated since 352, will be deleted in 358, use updatePushMixedStreamToCDN instead");

/**
 * 
 * @valid since 3.52
 * @type api
 * @region Push to CDN
 * @brief Creates a new task of pushing mixed media streams to CDN and sets the relevant configurations. <br>
 *        When pushing more than one live streams in the same task, SDK will first mix those streams into one single stream and then push it to CDN.
 * @param taskID Task ID. The length should not exceed 126 bytes. <br>
 *        You may want to push more than one mixed stream to CDN from the same room. When you do that, use different ID for corresponding tasks; if you will start only one task, use an empty string.
 * @param config Configurations to be set when pushing streams to CDN. See ByteRTCMixedStreamConfig{@link #ByteRTCMixedStreamConfig}
 * @param observer Invalid parameter. Please ignore it.
 * @return  API call result. <br>
 *            - 0: Success
 *            - <0: Failure
 * @note
 *        - Before calling this API，you need to enable Push to CDN on the [console](https:
 *        - After this API is called, the local user will receive onMixingEvent:taskId:error:mixType:{@link #ByteRTCMixedStreamObserver#onMixingEvent:taskId:error:mixType:} about the result and errors during the pushing process.
 *       - If you have subscribed to the push-to-CDN server callback in the [console](https:
 *        - Call stopPushStreamToCDN:{@link #ByteRTCVideo#stopPushStreamToCDN:} to stop pushing streams to CDN.
 */
- (int)startPushMixedStreamToCDN:(NSString * _Nonnull)taskID mixedConfig:(ByteRTCMixedStreamConfig *_Nullable)config observer:(id<ByteRTCMixedStreamObserver> _Nullable)observer;

/**
 * 
 * @valid since 3.52
 * @type api
 * @region Multi-room
 * @brief Updates parameters needed when pushing mixed media streams to CDN.  The local user will be informed of the change via the onMixingEvent:taskId:error:mixType:{@link #ByteRTCMixedStreamObserver#onMixingEvent:taskId:error:mixType:} callback. <br>
 *        After enabling the function of pushing streams to CDN, you can call this API to update the relevant configurations.
 * @param taskID Task ID. Specifys of which pushing task you want to update the parameters.
 * @param config Configurations that you want to update. Some of the configurations cannot be updated. See ByteRTCMixedStreamConfig{@link #ByteRTCMixedStreamConfig} for specific indications.
 * @return  API call result. <br>
 *          - 0: Success
 *          - <0: Failure
 */
- (int)updatePushMixedStreamToCDN:(NSString *_Nonnull)taskID mixedConfig:(ByteRTCMixedStreamConfig *_Nonnull)config;


/**
 * 
 * @type api
 * @region Push to CDN
 * @brief Creates a new task of pushing a single media stream to CDN.
 * @param taskID Task ID. <br>
 *        You may want to start more than one task to push streams to CDN. When you do that, use different IDs for corresponding tasks; if you will start only one task, use an empty string.
 * @param singleStream Configurations for pushing a single stream to CDN. See PushByteRTCPushSingleStreamParam{@link #ByteRTCPushSingleStreamParam}.
 * @param observer Register this observer to receive callbacks from the SDK. See ByteRTCPushSingleStreamToCDNObserver{@link #ByteRTCPushSingleStreamToCDNObserver}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *       - Before calling this API，you need to enable Push to CDN on the [console](https:
 *       - After calling this API, you will be informed of the result and errors during the pushing process with onStreamPushEvent:taskId:error:{@link #ByteRTCPushSingleStreamToCDNObserver#onStreamPushEvent:taskId:error:}.
 *       - Call stopPushStreamToCDN:{@link #ByteRTCVideo#stopPushStreamToCDN:} to stop the task.
 *       - Since this API does not perform encoding and decoding, the video stream pushed to RTMP will change according to the resolution, encoding method, and turning off the camera of the end of pushing streams.
 */
- (int)startPushSingleStreamToCDN:(NSString *_Nonnull)taskID singleStream:(ByteRTCPushSingleStreamParam *_Nonnull)singleStream observer:(id<ByteRTCPushSingleStreamToCDNObserver>_Nullable)observer NS_SWIFT_NAME(startPushSingleStreamToCDN(_:singleStream:observer:));

- (int)startPushSingleStream:(NSString *_Nonnull)taskID singleStream:(ByteRTCPushSingleStreamParam *_Nonnull)singleStream observer:(id<ByteRTCPushSingleStreamToCDNObserver>_Nullable)observer NS_SWIFT_NAME(startPushSingleStream(_:singleStream:observer:));

/**
 * 
 * @type api
 * @region Push to CDN
 * @brief Stops the task to push a single media stream to CDN. <br>
 *        This API can be used to stop both pushing single and mixed stream to CDN. You need to distinguish the tasks to be stopped by different "taskId".
 * @param taskID Task ID. Specifys the task you want to stop.
 * @return
 *        - 0: Success
 *        - < 0 : Failure. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
 *        - To start pushing single stream to CDN, see startPushSingleStreamToCDN:singleStream:observer:{@link #ByteRTCVideo#startPushSingleStreamToCDN:singleStream:observer:}.
 *        - To start pushing mixed stream to CDN, see startPushMixedStreamToCDN:mixedConfig:observer:{@link #ByteRTCVideo#startPushMixedStreamToCDN:mixedConfig:observer:}.
 */
- (int)stopPushStreamToCDN:(NSString *_Nonnull)taskID NS_SWIFT_NAME(stopPushStreamToCDN(_:));
- (int)stopPushSingleStream:(NSString *_Nonnull)taskID NS_SWIFT_NAME(stopPushSingleStream(_:));
 
 /**
  * 
  * @hidden internal use only
  * @type api
  * @brief Start aligning RTC data by cache. Received RTC data from different sources will be cached, and aligned based on the included timestamps. This feature compromizes the real-time nature of RTC data consumption.
  * @param config See ChorusCacheSyncConfig{@link #ChorusCacheSyncConfig}.
  * @param observer Event and data observer. See IChorusCacheSyncObserver{@link #IChorusCacheSyncObserver}.
  * @return See ByteRTCReturnStatus{@link #ByteRTCReturnStatus}.
  * @note To disable the feature, call stopChorusCacheSync{@link #ByteRTCVideo#stopChorusCacheSync}.
  */
- (int)startChorusCacheSync:(ByteRTCChorusCacheSyncConfig* _Nullable)config observer:(id<ByteRTCChorusCacheSyncObserver> _Nullable)observer;
 
 /**
  * 
  * @hidden internal use only
  * @type api
  * @brief Stop aligning RTC data by cache.
  * @return See ByteRTCReturnStatus{@link #ByteRTCReturnStatus}.
  */
-(int)stopChorusCacheSync;

#pragma mark public streaming

/**
 * 
 * @hidden currently not available
 * @type api
 * @brief Starts publishing a public media stream. <br>
 *        Users within the same `appID` can call startPlayPublicStream:{@link #ByteRTCVideo#startPlayPublicStream:} to subscribe to the public stream regardless the user has joined which room or has not joined any room.
 * @param publicStreamId ID of the public stream.
 * @param publicStream Properties of the public stream. Refer to ByteRTCPublicStreaming{@link #ByteRTCPublicStreaming} for more details. <br>
 *              A public stream can include a bundle of media streams and appears as the designated layout.
 * @return
 *        - 0: Success. And you will be informed by rtcEngine:onPushPublicStreamResult:publicStreamId:errorCode:{@link #ByteRTCVideoDelegate#rtcEngine:onPushPublicStreamResult:publicStreamId:errorCode:}.
 *        - !0: Failure because of invalid parameter or empty parameters.
 * @note
 *        - Call updatePublicStreamParam:withLayout:{@link #ByteRTCVideo#updatePublicStreamParam:withLayout:} to update the properties of the public stream which is published by the same user. Calling this API with the same stream ID repeatedly by the same user can not update the existing public stream.
 *        - If Users with different userID call this API with the same stream ID, the public stream will be updated with the parameters passed in the latest call.
 *        - To publish multiple public streams, call this API with different stream ID respectively.
 *        - To stop publishing the public stream, call stopPushPublicStream:{@link #ByteRTCVideo#stopPushPublicStream:}.
 *        - Please contact ts to enable this function before using it.
 */
- (int)startPushPublicStream:(NSString * _Nonnull)publicStreamId withLayout:(ByteRTCPublicStreaming *_Nullable)publicStream;

/**
 * 
 * @hidden currently not available.
 * @type api
 * @brief Stops the public stream published by the current user. <br>
 *        Refer to startPushPublicStream:withLayout:{@link #ByteRTCVideo#startPushPublicStream:withLayout:} for details about starting publishing a public stream.
 * @param publicStreamId ID of the public stream <br>
 *                  The public stream must be published by the current user.
 * @return
 *        - 0: Success
 *        - !0: Failure
 */
- (int)stopPushPublicStream:(NSString * _Nonnull)publicStreamId;


/**
 * 
 * @hidden currently not available.
 * @type api
 * @brief Updates the properties of the public stream published by the current user. <br>
 *        Refer to startPushPublicStream:withLayout:{@link #ByteRTCVideo#startPushPublicStream:withLayout:} for details about starting publishing a public stream.
 * @param publicStreamId ID of the public stream <br>
 *              The stream to be updated must be published by the current user.
 * @param publicStream Properties of the public stream. Refer to ByteRTCPublicStreaming{@link #ByteRTCPublicStreaming} for more details.current user.
 * @return
 *        - 0: Success
 *        - !0: Failure
 * @note Make sure the public stream has started successfully via rtcEngine:onPushPublicStreamResult:publicStreamId:errorCode:{@link #ByteRTCVideoDelegate#rtcEngine:onPushPublicStreamResult:publicStreamId:errorCode:} before calling this API.
 */
- (int)updatePublicStreamParam:(NSString * _Nonnull)publicStreamId withLayout:(ByteRTCPublicStreaming *_Nullable)publicStream;

/**
 * 
 * @hidden currently not available.
 * @type api
 * @brief Subscribes to specified public stream. <br>
 *        This API can be called to get and play the specified public stream regardless of whether the user is in the room or not.
 * @param publicStreamId ID of the public stream. If the stream has not been published then, the local client will receive the public stream once it starts publishing.
 * @return
 *        - 0: Success. You will also be informed by rtcEngine:onPlayPublicStreamResult:errorCode:{@link #ByteRTCVideoDelegate#rtcEngine:onPlayPublicStreamResult:errorCode:}.
 *        - !0: Failure because of invalid parameter or empty parameters.
 * @note
 *        - We recommend you bind a view for the public stream before calling this API.
 *              - Internal renderer: By calling setPublicStreamVideoCanvas:withCanvas:{@link #ByteRTCVideo#setPublicStreamVideoCanvas:withCanvas:}.
 *              - Custom renderer: By calling setPublicStreamVideoSink:withSink:withPixelFormat:{@link #ByteRTCVideo#setPublicStreamVideoSink:withSink:withPixelFormat:}.
 *        - After calling this API, the local user will be informed once the first frame has been decoded successfully by rtcEngine:onFirstPublicStreamVideoFrameDecoded:withFrameInfo:{@link #ByteRTCVideoDelegate#rtcEngine:onFirstPublicStreamVideoFrameDecoded:withFrameInfo:} and rtcEngine:onFirstPublicStreamAudioFrame:{@link #ByteRTCVideoDelegate#rtcEngine:onFirstPublicStreamAudioFrame:}.
 *        - If the public stream contains SEI information, the local user will be informed by rtcEngine:onPublicStreamSEIMessageReceived:andMessage:andSourceType:{@link #ByteRTCVideoDelegate#rtcEngine:onPublicStreamSEIMessageReceived:andMessage:andSourceType:}.
 *        - Call stopPlayPublicStream:{@link #ByteRTCVideo#stopPlayPublicStream:} to cancel subscribing the public stream.
 *        - After subscribing to a public stream, you can cancel the subscription by calling the stopPlayPublicStream:{@link #ByteRTCVideo#stopPlayPublicStream:} interface.
     */
- (int)startPlayPublicStream:(NSString * _Nonnull)publicStreamId;

/**
 * 
 * @hidden currently not available.
 * @type api
 * @brief Cancel subscribing the public stream. <br>
 *        Call this method to cancel subscribing to the public stream by calling startPlayPublicStream:{@link #ByteRTCVideo#startPlayPublicStream:}.
 * @param publicStreamId ID of the public stream
 * @return
 *        - 0: Success
 *        - !0: Failure
 */
- (int)stopPlayPublicStream:(NSString * _Nonnull)publicStreamId;


/**
 * 
 * @hidden currently not available.
 * @type api
 * @brief Assign a internal render view to the public stream
 * @param publicStreamId ID of the public stream
 * @param canvas Internal render view. Set to be a blank view if you want to unbind. Refer to ByteRTCVideoCanvas{@link #ByteRTCVideoCanvas} for more details.
 * @return
 *        - 0: Success
 *        - !0: Failure
 */
- (int)setPublicStreamVideoCanvas:(NSString *_Nonnull)publicStreamId withCanvas:(ByteRTCVideoCanvas * _Nullable)canvas NS_SWIFT_NAME(setPublicStreamVideoCanvas(_:withCanvas:));


/**
 * 
 * @hidden currently not available.
 * @type api
 * @brief Assign a custom renderer to the public stream
 * @param publicStreamId ID of the public stream
 * @param videoSink Custom renderer. Set to be `null` when you want to release the renderer. Refer to ByteRTCVideoSinkDelegate{@link #ByteRTCVideoSinkDelegate} for more details.
 * @param requiredFormat Format of the video frames required by the external video renderer. Refer to  ByteRTCVideoSinkPixelFormat{@link #ByteRTCVideoSinkPixelFormat} for more details.
 * @return
 *        - 0: Success
 *        - !0: Failure
 */
- (int)setPublicStreamVideoSink:(NSString *_Nonnull)publicStreamId
                       withSink:(id<ByteRTCVideoSinkDelegate> _Nullable)videoSink
                withPixelFormat:(ByteRTCVideoSinkPixelFormat)requiredFormat NS_SWIFT_NAME(setPublicStreamVideoSink(_:withSink:withPixelFormat:));


/**
 * 
 * @type api
 * @valid since 3.51
 * @brief Set the audio playback volume of the public stream.
 * @param publicStreamId ID of the public stream.
 * @param volume Ratio(%) of the audio playback volume to the original volume, in the range `[0, 400]`, with overflow protection. The default volume is 100. <br>
 *               To ensure the audio quality, the recommended range is `[0, 100]`.
 * @return
 *         - 0: Success.
 *         - -2: Wrong parameter.
 */
- (int)setPublicStreamAudioPlaybackVolume:(NSString *_Nonnull)publicStreamId volume:(NSInteger)volume;

#pragma mark External Video Data


/**
 * 
 * @type api
 * @region Custom video capture rendering
 * @brief Pushes external video frames, encapsulated with ByteRTCVideoFrame.
 * @param frame This video frame contains video data to be encoded by the SDK. Refer to ByteRTCVideoFrame{@link #ByteRTCVideoFrame}.
 * @return API call result: <br>
 *        - 0: Success.
 *        - <0: Failure. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for specific reasons.
 * @note Before pushing an external video frame, you must call setVideoSourceType:WithStreamIndex:{@link #ByteRTCVideo#setVideoSourceType:WithStreamIndex:} Turn on external video source capture.
 */
- (int)pushExternalVideoFrame:(ByteRTCVideoFrame * _Nonnull)frame;

#pragma mark External Audio Data

/**
 * 
 * @type api
 * @region Audio Data Callback
 * @brief Enable audio frames callback and set the format for the specified type of audio frames.
 * @param method Audio data callback method. See ByteRTCAudioFrameCallbackMethod{@link #ByteRTCAudioFrameCallbackMethod}. <br>
 *               If `method` is set as `0`, `1`, or `2`, set `format` to the accurate value listed in the audio parameters format. <br>
 *               If `method` is set as `3`, set `format` to `auto`.
 * @param format Audio parameters format. See ByteRTCAudioFormat{@link #ByteRTCAudioFormat}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note After calling this API and registerAudioFrameObserver:{@link #ByteRTCVideo#registerAudioFrameObserver:}, ByteRTCAudioFrameObserver{@link #ByteRTCAudioFrameObserver} will receive the corresponding audio data callback. However, these two APIs are independent of each other and the calling order is not restricted.
 */
- (int)enableAudioFrameCallback:(ByteRTCAudioFrameCallbackMethod) method format:(ByteRTCAudioFormat* _Nullable)format;

/**
 * 
 * @type api
 * @region Audio Data Callback
 * @brief Disables audio data callback.
 * @param method Audio data callback method. See ByteRTCAudioFrameCallbackMethod{@link #ByteRTCAudioFrameCallbackMethod}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note Call this API after calling enableAudioFrameCallback:format:{@link #ByteRTCVideo#enableAudioFrameCallback:format:}.
 */
- (int)disableAudioFrameCallback:(ByteRTCAudioFrameCallbackMethod) method;

/**
 * 
 * @type api
 * @region Audio Data Callback
 * @brief Register an audio frame observer.
 * @param audioFrameObserver Audio data callback observer. See ByteRTCAudioFrameObserver{@link #ByteRTCAudioFrameObserver}. Use `null` to cancel the registration.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note After calling this API and enableAudioFrameCallback:format:{@link #ByteRTCVideo#enableAudioFrameCallback:format:}, ByteRTCAudioFrameObserver{@link #ByteRTCAudioFrameObserver} receives the corresponding audio data callback. You can retrieve the audio data and perform processing on it without affecting the audio that RTC SDK uses to encode or render.
 */
- (int)registerAudioFrameObserver:(_Nullable id<ByteRTCAudioFrameObserver>) audioFrameObserver NS_SWIFT_NAME(registerAudioFrameObserver(_:));

/**
* 
* @type api
* @brief  Register a custom audio preprocessor. <br>
*         After that, you can call enableAudioProcessor:audioFormat:{@link #ByteRTCVideo#enableAudioProcessor:audioFormat:} to process the audio streams that either captured locally or received from the remote side. RTC SDK then encodes or renders the processed data.
* @param processor Custom audio processor. See ByteRTCAudioFrameProcessor{@link #ByteRTCAudioFrameProcessor}。 <br>
*        SDK only holds weak references to the processor, you should guarantee its Life Time. To cancel registration, set the parameter to nullptr.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
* @note
* - When this interface is repeatedly called, only the last call takes effect.
* - Refer to [Custom Audio Processing](https:
*/
- (int)registerAudioProcessor:(_Nullable id<ByteRTCAudioFrameProcessor>)processor;

/**
 * 
 * @type api
 * @brief Enable audio frames callback for custom processing and set the format for the specified type of audio frames.
 * @param  method The types of audio frames. See ByteRTCAudioFrameMethod{@link #ByteRTCAudioFrameMethod}. Set this parameter to process multiple types of audio. <br>
 *        With different values, you will receive the corresponding callback: <br>
 *        - For locally captured audio, you will receive onProcessRecordAudioFrame:{@link #ByteRTCAudioFrameProcessor#onProcessRecordAudioFrame:}.
 *        - For mixed remote audio, you will receive onProcessPlayBackAudioFrame:{@link #ByteRTCAudioFrameProcessor#onProcessPlayBackAudioFrame:}.
 *        - For audio from remote users, you will receive onProcessRemoteUserAudioFrame:audioFrame:{@link #ByteRTCAudioFrameProcessor#onProcessRemoteUserAudioFrame:audioFrame:}.
 *        - For SDK-level in-ear monitoring audio, you will receive onProcessEarMonitorAudioFrame:{@link #ByteRTCAudioFrameProcessor#onProcessEarMonitorAudioFrame:} (Only on iOS).
 *        - For shared-screen audio, you will receive onProcessScreenAudioFrame:{@link #ByteRTCAudioFrameProcessor#onProcessScreenAudioFrame:}.
 * @param  format The format of the returned audio frame. See ByteRTCAudioFormat{@link #ByteRTCAudioFormat}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *        - Before calling this API, call registerAudioProcessor:{@link #ByteRTCVideo#registerAudioProcessor:} to register a processor.
 *        - To disable custom audio processing, call disableAudioProcessor:{@link #ByteRTCVideo#disableAudioProcessor:}.
 */
- (int)enableAudioProcessor:(ByteRTCAudioFrameMethod)method
                 audioFormat:(ByteRTCAudioFormat *_Nullable)format;

/**
* 
* @type api
* @brief Disable custom audio processing.
* @param method Audio Frame type. See ByteRTCAudioFrameMethod{@link #ByteRTCAudioFrameMethod}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
*/
- (int)disableAudioProcessor:(ByteRTCAudioFrameMethod)method;

 /**
  * 
  * @type api
  * @region Custom Audio Capture and Rendering
  * @brief Push custom captured audio data to the RTC SDK.
  * @param audioFrame Audio data frame. See ByteRTCAudioFrame{@link #ByteRTCAudioFrame}. <br>
  *        - The audio sampling format must be S16. The data format within the audio buffer must be PCM, and its capacity should be audioFrame.samples × audioFrame.channel × 2.
  *        - A specific sample rate and the number of channels must be specified; it is not supported to set them to automatic.
  * @return
  *         - 0: Success
  *         - < 0: Failure
  * @note
  *        - Before pushing external audio data, you must call setAudioSourceType:{@link #ByteRTCVideo#setAudioSourceType:} to enable custom audio capture.
  *        - You must push custom captured audio data every 10 milliseconds. The samples (number of audio sampling points) of a single push should be `audioFrame.sample Rate/100`. For example, when the sampling rate is set to 48000, data of 480 sampling points should be pushed each time.
  */
- (int)pushExternalAudioFrame:(ByteRTCAudioFrame * _Nonnull) audioFrame;

 /**
  * 
  * @type api
  * @region Custom audio capture and rendering
  * @brief Pull remote audio data. You can use the data for audio processing or custom rendering. <br>
  *         After calling this method, the SDK will actively pull the audio data that is ready to be played, including the decoded and mixed audio data from remote end for external playback.
  * @param audioFrame Audio data frame. See ByteRTCAudioFrame{@link #ByteRTCAudioFrame}
  * @return
  *           - 0: Success
  *           - < 0: Failure
  * @note
  *        - Before pulling custom audio data, you must call setAudioRenderType:{@link #ByteRTCVideo#setAudioRenderType:} to enable custom audio capture and rendering.
  *        - You should pull audio data every 10 milliseconds since the duration of a RTC SDK audio frame is 10 milliseconds. Samples x call frequency = audioFrame's sample rate. Assume that the sampling rate is set to 48000, call this API every 10 ms, so that 480 sampling points should be pulled each time.
  *        - The audio sampling format is S16. The data format in the audio buffer is PCM, and its capacity size is `audioFrame.samples × audioFrame.channel × 2`.
  */
- (int)pullExternalAudioFrame:(ByteRTCAudioFrame * _Nonnull) audioFrame;

/**
 * 
 * @type api
 * @region Custom Audio AEC Reference
 * @brief Push custom aec reference audio data to the RTC SDK.
 * @param audioFrame Audio data frame. See ByteRTCAudioFrame{@link #ByteRTCAudioFrame}
 * @return  Method call result   <br>
 *         + 0: Success <br>
 *        + <-1: Failure  <br>
 *        + <-302：Failure. The configuration delivers an invalid aec scene. <br>
 *        + <-303：Warning. The configuration delivers an invalid aec type. <br>
 * @notes   <br>
 *        + Before calling this API, you must call setAudioRenderType{@link #ByteRTCVideo#setAudioRenderType} to enable custom audio render. <br>
 *        + You should send audio data every 10 milliseconds since the duration of a RTC SDK audio frame is 10 milliseconds. Samples x call frequency = audioFrame's sample rate. Assume that the sampling rate is set to 48000, call this API every 10 ms, so that 480 sampling points should be pulled each time. <br>
 *        + The audio sampling format is S16. The data format in the audio buffer is PCM data, and its capacity size is audioFrame.samples × audioFrame.channel × 2. <br>
 */
- (int)pushReferenceAudioPCMData:(ByteRTCAudioFrame * _Nonnull) audioFrame;

/**
 * 
 * @type api
 * @region Engine management
 * @brief Sets the business ID <br>
 *        You can use businessId to distinguish different business scenarios. You can customize your businessId to serve as a sub AppId, which can share and refine the function of the AppId, but it does not need authentication.
 * @param businessId <br>
 *        Your customized businessId <br>
 *        BusinessId is a tag, and you can customize its granularity.
 * @return
 *         - 0: Success
 *         - < 0: Failure
 *         - -6001: The user is already in the room.
 *         - -6002: The input is invalid. Legal characters include all lowercase letters, uppercase letters, numbers, and four other symbols, including '.', '-','_', and '@'.
 * @note
 *         - You must call this API before the joinRoom:userInfo:roomConfig:{@link #ByteRTCRoom#joinRoom:userInfo:roomConfig:} API, otherwise it will be invalid.
 * @list Engine Management
 * @order 20
 */
- (int)setBusinessId:(NSString* _Nullable)businessId;

/**
 * 
 * @type api
 * @region Engine management
 * @brief The call ends and the user feedback problem is reported to RTC
 * @param types The list of preset problems. See ByteRTCProblemFeedbackOption{@link #ByteRTCProblemFeedbackOption}
 * @param info Specific description of other problems other than the preset problem, and room's information. See ByteRTCProblemFeedbackInfo{@link #ByteRTCProblemFeedbackInfo}
 * @return
 *          - 0: Report successfully
 *          - -1: Failed to report, haven't joined the room yet
 *          - -2: Failed to report, data analysis error
 *          - -3: Failed to report, missing fields
 * @note If the user is in the room when reporting, the report leads to the room / rooms where the user is currently located; <br>
 *        If the user is not in the room when reporting, the report leads to the previously exited Room.
 * @list Engine Management
 * @order 10
 */
- (int)feedback:(ByteRTCProblemFeedbackOption)types info:(ByteRTCProblemFeedbackInfo* _Nullable)info;


/**
 * 
 * @type api
 * @brief Get [IRTCVideo](https:
 * @return
 *         - >0：Success. Return the address of `IRTCVideo` in C++ layer.
 *         - NULL：Failure.
 * @note In some scenarios, getting and working with `IRTCVideo` in C++ layer has much higher execution efficiency than through the OC encapsulation layer. Typical scenarios include: custom processing of video/audio frames, encryption of audio and video calls, etc.
 */
- (void * _Nullable) getNativeHandle;

#pragma mark Fallback Related

/**
 * 
 * @type api
 * @region Audio & Video Fallback
 * @brief Sets the fallback option for published audio & video streams. <br>
 *        You can call this API to set whether to automatically lower the resolution you set of the published streams under limited network conditions.
 * @param option Fallback option, see ByteRTCPublishFallbackOption{@link #ByteRTCPublishFallbackOption}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *         - This API only works after you call enableSimulcastMode:{@link #ByteRTCVideo#enableSimulcastMode:} to enable the mode of publishing multiple streams.
 *         - You must call this API before the user enters the room.
 *         - After calling this method, if there is a fallback or recovery in the publishing performance due to poor performance or network conditions, this end will receive an alarm in advance through the rtcEngine:onPerformanceAlarms:roomId:reason:sourceWantedData:{@link #ByteRTCVideoDelegate#rtcEngine:onPerformanceAlarms:roomId:reason:sourceWantedData:} callback, allowing the capture device to make adjustments accordingly.
 *         - After the fallback is set, when the locally published audio and video streams experience a fallback or recovery, the remote end will receive a callback through rtcEngine:onSimulcastSubscribeFallback:{@link #ByteRTCVideoDelegate#rtcEngine:onSimulcastSubscribeFallback:} to notify of this situation.
 *         - You can alternatively set fallback options in the console, which is of higher priority.
 */
- (int)setPublishFallbackOption:(ByteRTCPublishFallbackOption)option;

/**
 * 
 * @type api
 * @region Audio & Video Fallback
 * @brief Sets the fallback option for subscribed RTC streams. <br>
 *        You can call this API to set whether to lower the resolution of currently subscribed stream under limited network conditions.
 * @param option Fallback option, see ByteRTCSubscribeFallbackOption{@link #ByteRTCSubscribeFallbackOption} for more details.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *         - You must call this API before enterting the room.
 *         - When the fallback option is set, the local user will receive rtcEngine:onSimulcastSubscribeFallback:{@link #ByteRTCVideoDelegate#rtcEngine:onSimulcastSubscribeFallback:} and rtcEngine:onRemoteVideoSizeChanged:withFrameInfo:{@link #ByteRTCVideoDelegate#rtcEngine:onRemoteVideoSizeChanged:withFrameInfo:} when the subscribed audio/video stream falls back or resumes from a fallback.
 *         - You can alternatively set fallback options in the console, which is of higher priority.
 */
- (int)setSubscribeFallbackOption:(ByteRTCSubscribeFallbackOption)option;


/**
 * 
 * @type api
 * @region  audio & video fallback
 * @brief Sets user priority
 * @param priority Priority of remote user. See enumeration type ByteRTCRemoteUserPriority{@link #ByteRTCRemoteUserPriority}
 * @param roomId Room ID
 * @param uid ID of remote user
 * @return  + 0: Success.
 *          - < 0: failure
 * @note
 *         - This method is used with setSubscribeFallbackOption:{@link #ByteRTCVideo#setSubscribeFallbackOption:}.
 *         - If the subscription flow fallback option is turned on, weak connections or insufficient performance will give priority to ensuring the quality of the flow received by high-priority users.
 *         - This method can be used before and after entering the room, and the priority of the remote user can be modified.
 */
- (int)setRemoteUserPriority:(ByteRTCRemoteUserPriority)priority
                         InRoomId:(NSString *_Nonnull)roomId
                         uid:(NSString *_Nonnull)uid NS_SWIFT_NAME(setRemoteUserPriority(_:InRoomId:uid:));
#pragma mark AES Related

/**
 * 
 * @type api
 * @region Encryption
 * @brief Sets the way to use built-in encryption when transmitting.
 * @param encrypt_type Built-in encryption algorithm. See ByteRTCEncryptType{@link #ByteRTCEncryptType}
 * @param key Encryption key, limited to 36 bits in length, beyond which it will be truncated
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *        - Use this method when using built-in encryption when transmitting; if you need to use transmission See onEncryptData:{@link #ByteRTCEncryptHandler#onEncryptData:}.
 *         Built-in encryption and custom encryption mutex, determine the scheme of transmission encryption according to the last called method. <br>
 *        - This method must be called before entering the room, and can be called repeatedly, taking the last called parameter as the effective parameter.
 */
- (int)setEncryptInfo:(ByteRTCEncryptType)encrypt_type key:(NSString * _Nonnull)key;

/**
 * 
 * @type api
 * @region  encryption
 * @brief Sets custom encryption and decryption methods.
 * @param handler Custom encryption handler, which needs to implement the encryption and decryption method. See ByteRTCEncryptHandler{@link #ByteRTCEncryptHandler}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *        - The method and setEncryptInfo:key:{@link #setEncryptInfo:key:} are mutually exclusive relationships, that is, according to the call order, the last call method takes effect version.
 *        - This method must be called before calling joinRoom:userInfo:roomConfig:{@link #ByteRTCRoom#joinRoom:userInfo:roomConfig:}, which can be called repeatedly, taking the last called parameter as the effective parameter.
 *        - Whether encrypted or decrypted, the length of the modified data needs to be controlled under 180%. That is, if the input data is 100 bytes, the processed data must be less than 180 bytes. If the encryption or decryption result exceeds the limit, the audio & video frame may be discarded.
 *        - Data encryption/decryption is performed serially, so depending on the implementation The method may affect the final rendering efficiency. Whether to use this method needs to be carefully evaluated by the user.
 */
- (int)setCustomizeEncryptHandler:(id<ByteRTCEncryptHandler> _Nullable)handler NS_SWIFT_NAME(setCustomizeEncryptHandler(_:));

#pragma mark - Extention Methods

/**
 * 
 * @type api
 * @region Room Management
 * @brief Create a room instance. <br>
 *        This API only returns a room instance. You still need to call joinRoom:userInfo:roomConfig:{@link #ByteRTCRoom#joinRoom:userInfo:roomConfig:} to actually create/join the room. <br>
 *        Each call of this API creates one ByteRTCRoom{@link #ByteRTCRoom} instance. Call this API as many times as the number of rooms you need, and then call joinRoom:userInfo:roomConfig:{@link #ByteRTCRoom#joinRoom:userInfo:roomConfig:} of each RTCRoom instance to join multiple rooms at the same time. <br>
 *        In multi-room mode, a user can subscribe to media streams in the joined rooms at the same time.
 * @param roomId The string matches the regular expression: `[a-zA-Z0-9_@\-\.]{1,128}`.
 * @return ByteRTCRoom{@link #ByteRTCRoom} instance.
 * @note
 *       - If the room that you wish to join already exists, you still need to call this API first to create the ByteRTCRoom instance, and then call joinRoom:userInfo:roomConfig:{@link #ByteRTCRoom#joinRoom:userInfo:roomConfig:}.
 *       - Do not create multiple rooms with the same roomId, otherwise the newly created room instance will replace the old one.
 *       - To forward streams to the other rooms, call startForwardStreamToRooms:{@link #ByteRTCRoom#startForwardStreamToRooms:} instead of enabling Multi-room mode.
 * @list Room Management
 */
- ( ByteRTCRoom * _Nullable)createRTCRoom:(NSString * _Nonnull)roomId;
#pragma mark - ScreenCapture

/**
 * 
 * @type api
 * @region  screen sharing
 * @brief  Push external screen acquisition frame
 * @param frame  The video frame contains the video data to be encoded by the SDK <br>
 *               Supported video pixel format: NV12, BGRA, ARGB.
 * @param pts  Timestamp of each frame, the rotation angle of the unit ms
 * @param rotation  Frame contains: 0, 90, 180, 270
 * @return API call result: <br>
 *        - 0: Success.
 *        - <0: Failure. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for specific reasons.
 * @note  Screen acquisition is divided into internal acquisition and external acquisition, this method belongs to external acquisition.
 */
- (int)pushScreenVideoFrame:(CVPixelBufferRef _Nonnull )frame time:(CMTime)pts rotation:(int)rotation;

/**
 * 
 * @hidden(macOS)
 * @type api
 * @region  Screen Sharing
 * @brief  Set Extension configuration. It should be set before capturing screen internally.
 * @param groupId  Your app and Extension should belong to the same App Group. You need to put in their Group ID here.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note You must call this API immediately after calling createRTCVideo:delegate:parameters:{@link #ByteRTCVideo#createRTCVideo:delegate:parameters:}. You only need to call this API once in the life cycle of the engine instance.
 */
- (int)setExtensionConfig:(NSString *_Nullable)groupId;

/**
 * 
 * @type api
 * @hidden(macOS)
 * @region Screen Sharing
 * @brief Starts capturing the screen audio and/or video stream with the RTC SDK internal module.
 * @param type Media type. See ByteRTCScreenMediaType{@link #ByteRTCScreenMediaType}.
 * @param bundleId The bundle ID of the Extension, which is used to only display your Extension in your app.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *      - The call of this API takes effects only when you are using RTC SDK to record screen. You will get a warning by rtcEngine:onVideoDeviceWarning:deviceType:deviceWarning:{@link #ByteRTCVideoDelegate#rtcEngine:onVideoDeviceWarning:deviceType:deviceWarning:} or rtcEngine:onAudioDeviceWarning:deviceType:deviceWarning:{@link #ByteRTCVideoDelegate#rtcEngine:onAudioDeviceWarning:deviceType:deviceWarning:} after calling this API when the source is set to an external recorder.
 *      - If you start the Extension from the iOS control center, this API do not need to be called.
 *      - After the streams are captured, you need to call publishScreenVideo:{@link #ByteRTCRoom#publishScreenVideo:} and/or publishScreenAudio:{@link #ByteRTCRoom#publishScreenAudio:} to push the streams to the remote end.
 *      - You will receive rtcEngine:onVideoDeviceStateChanged:device_type:device_state:device_error:{@link #ByteRTCEngineDelegate#rtcEngine:onVideoDeviceStateChanged:device_type:device_state:device_error:} and rtcEngine:onAudioDeviceStateChanged:device_type:device_state:device_error:{@link #ByteRTCEngineDelegate#rtcEngine:onAudioDeviceStateChanged:device_type:device_state:device_error:} when the capturing is started.
 */
- (int)startScreenCapture:(ByteRTCScreenMediaType) type bundleId:(NSString *_Nullable)bundleId;

/**
 * 
 * @hidden(macOS)
 * @type api
 * @region Screen Sharing
 * @brief Updates the media type of the internal screen capture.
 * @param type Media type. See ByteRTCScreenMediaType{@link #ByteRTCScreenMediaType}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *      - Call this API after starting screen capture.
 *      - You will receive rtcEngine:onVideoDeviceStateChanged:device_type:device_state:device_error:{@link #ByteRTCVideoDelegate#rtcEngine:onVideoDeviceStateChanged:device_type:device_state:device_error:} or rtcEngine:onAudioDeviceStateChanged:device_type:device_state:device_error:{@link #ByteRTCVideoDelegate#rtcEngine:onAudioDeviceStateChanged:device_type:device_state:device_error:}.
 */
- (int)updateScreenCapture:(ByteRTCScreenMediaType) type;

/**
 * 
 * @hidden(macOS)
 * @type api
 * @region Screen Sharing
 * @brief Stop internal screen capture.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *      - The call of this API takes effects only when you are using RTC SDK to record screen. You will get a warning by rtcEngine:onVideoDeviceWarning:deviceType:deviceWarning:{@link #ByteRTCVideoDelegate#rtcEngine:onVideoDeviceWarning:deviceType:deviceWarning:} or rtcEngine:onAudioDeviceWarning:deviceType:deviceWarning:{@link #ByteRTCVideoDelegate#rtcEngine:onAudioDeviceWarning:deviceType:deviceWarning:} after calling this API when the source is set to an external recorder.
 *      - Calling this API changes the capturing status without affecting the publishing status.
 *      - You will receive rtcEngine:onVideoDeviceStateChanged:device_type:device_state:device_error:{@link #ByteRTCVideoDelegate#rtcEngine:onVideoDeviceStateChanged:device_type:device_state:device_error:} and rtcEngine:onAudioDeviceStateChanged:device_type:device_state:device_error:{@link #ByteRTCVideoDelegate#rtcEngine:onAudioDeviceStateChanged:device_type:device_state:device_error:}.
 */
- (int)stopScreenCapture;

/**
 * 
 * @hidden(macOS)
 * @type api
 * @region  Screen Sharing
 * @brief Sends message to screen capture Extension
 * @param messsage  Message sent to the Extension
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *       - Call this API after calling startScreenCapture:bundleId:{@link #ByteRTCVideo#startScreenCapture:bundleId:}.
 *       - The extension will receive onReceiveMessageFromApp:{@link #ByteRtcScreenCapturerExtDelegate#onReceiveMessageFromApp:} when the message is sent.
 */
- (int)sendScreenCaptureExtensionMessage:(NSData *_Nonnull) messsage;

/**
 * 
 * @hidden for internal use only
 * @type api
 * @brief Audio Facility Management interface is created, this interface does not depend on the engine, and is mainly used for audio Facility Management without an engine
 * @param handler Audio device event callback, see ByteRTCAudioDeviceEventHandler{@link #ByteRTCAudioDeviceEventHandler}.
 * @return API of audio device management
 */
+ (ByteRTCAudioDeviceManager *_Null_unspecified)createAudioDeviceManager:(id<ByteRTCAudioDeviceEventHandler> _Nonnull)handler;

/**
 * 
 * @type api
 * @brief Sets runtime parameters
 * @param parameters Reserved parameters
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note Call this API before joinRoom:userInfo:roomConfig:{@link #ByteRTCRoom#joinRoom:userInfo:roomConfig:} and startAudioCapture{@link #ByteRTCVideo#startAudioCapture}.
 * @list Engine Management
 * @order 25
 */
- (int)setRuntimeParameters:(NSDictionary * _Nullable)parameters;


/**
 * 
 * @type api
 * @region Engine management
 * @brief get runtime parameters
 * @param key_string some key string to get
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details     * @note Call this API after create videoengine.
 * @list Engine Management
 * @order 25
 */
- (NSString * _Nonnull)getParameters:(NSString * _Nonnull)key_string;


#if BYTERTC_TARGET_MAC

/**
 * 
 * @type api
 * @hidden(iOS)
 * @region screen sharing
 * @brief  Get the list of shared objects (application windows and screens).
 * @return The list of shared objects. See ByteRTCScreenCaptureSourceInfo{@link #ByteRTCScreenCaptureSourceInfo}。 <br>
 *         The enumerated value can be used for startScreenVideoCapture:captureParameters:{@link #ByteRTCVideo#startScreenVideoCapture:captureParameters:}.
 * @note Only valid for PC and macOS.
 */
- (NSArray<ByteRTCScreenCaptureSourceInfo *> *_Nonnull)getScreenCaptureSourceList;

/**
 * 
 * @type api
 * @hidden(iOS)
 * @region screen sharing
 * @brief Capture screen video stream for sharing. Screen video stream includes: content displayed on the screen, or content in the application window.
 * @param sourceInfo Screen capture source information. See ByteRTCScreenCaptureSourceInfo{@link #ByteRTCScreenCaptureSourceInfo}. <br>
 *                    Call getScreenCaptureSourceList{@link #ByteRTCVideo#getScreenCaptureSourceList} to get all the screen sources that can be shared.
 * @param captureParameters Screen capture parameters. See ByteRTCScreenCaptureParam{@link #ByteRTCScreenCaptureParam}.
 * @return
 *         - 0: Success;
 *         - -1: Failure;
 * @note
 *        - The call of this API takes effects only when you are using RTC SDK to record screen. You will get a warning by rtcEngine:onVideoDeviceWarning:deviceType:deviceWarning:{@link #ByteRTCEngineDelegate#rtcEngine:onVideoDeviceWarning:deviceType:deviceWarning:} after calling this API when the video source is set to an external recorder.
 *        - This API only starts screen capturing but does not publish the captured video. Call publishScreenVideo:{@link #ByteRTCRoom#publishScreenVideo:} to publish the captured video.
 *        - To turn off screen video capture, call stopScreenVideoCapture{@link #ByteRTCEngine#stopScreenVideoCapture}.
 *        - Local users will receive rtcEngine:onVideoDeviceStateChanged:device_type:device_state:device_error:{@link #ByteRTCEngineDelegate#rtcEngine:onVideoDeviceStateChanged:device_type:device_state:device_error:} on the state of screen capturing such as start, pause, resume, and error.
 *        - After successfully calling this API, local users will receive rtcEngine:onFirstLocalVideoFrameCaptured:withFrameInfo:{@link #ByteRTCEngineDelegate#rtcEngine:onFirstLocalVideoFrameCaptured:withFrameInfo:}.
 *        - Before calling this API, you can call setScreenVideoEncoderConfig:{@link #ByteRTCEngine#setScreenVideoEncoderConfig:} to set the frame rate and encoding resolution of the screen video stream.
 *        - After receiving rtcEngine:onFirstLocalVideoFrameCaptured:withFrameInfo:{@link #ByteRTCEngineDelegate#rtcEngine:onFirstLocalVideoFrameCaptured:withFrameInfo:}, you can set the local screen sharing view by calling setLocalVideoCanvas:withCanvas:{@link #ByteRTCEngine#setLocalVideoCanvas:withCanvas:} or setLocalVideoSink:withSink:withPixelFormat:{@link #ByteRTCEngine#setLocalVideoSink:withSink:withPixelFormat:}.
 *        - After you start capturing screen video stream for sharing，you can call updateScreenCaptureHighlightConfig:{@link #ByteRTCEngine#updateScreenCaptureHighlightConfig:} to update border highlighting settings, updateScreenCaptureMouseCursor:{@link #ByteRTCEngine#updateScreenCaptureMouseCursor:} to update the processing settings for the mouse, and updateScreenCaptureFilterConfig:{@link #ByteRTCEngine#updateScreenCaptureFilterConfig:} to set the window that needs to be filtered on PC clinets.
 */
- (int)startScreenVideoCapture:(ByteRTCScreenCaptureSourceInfo *_Nonnull)sourceInfo captureParameters:(ByteRTCScreenCaptureParam *_Nonnull)captureParameters NS_SWIFT_NAME(startScreenVideoCapture(_:captureParameters:));

/**
 * 
 * @hidden(iOS)
 * @type api
 * @region screen sharing
 * @brief Stops capturing screen video stream.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *        - The call of this API takes effects only when you are using RTC SDK to record screen. You will get a warning by rtcEngine:onVideoDeviceWarning:deviceType:deviceWarning:{@link #ByteRTCVideoDelegate#rtcEngine:onVideoDeviceWarning:deviceType:deviceWarning:} after calling this API when the video source is set to an external recorder.
 *        - To enable screen video stream capture, calling startScreenVideoCapture:captureParameters:{@link #ByteRTCVideo#startScreenVideoCapture:captureParameters:}.
 *        - You will receive rtcEngine:onVideoDeviceStateChanged:device_type:device_state:device_error:{@link #ByteRTCVideoDelegate#rtcEngine:onVideoDeviceStateChanged:device_type:device_state:device_error:} after calling this API.
 *        - This API has no effect on screen video stream publishing.
 */
- (int)stopScreenVideoCapture;

/**
 * 
 * @type api
 * @hidden(iOS)
 * @region Screen sharing
 * @brief Update the capture area when capturing screen video streams through the internal capture module .
 * @param regionRect The relative capture area to the area set by startScreenVideoCapture:captureParameters:{@link #ByteRTCVideo#startScreenVideoCapture:captureParameters:}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note Before calling this API, you must call startScreenVideoCapture:captureParameters:{@link #ByteRTCVideo#startScreenVideoCapture:captureParameters:} to start internal screen stream capture.
 */
- (int)updateScreenCaptureRegion:(CGRect)regionRect;

/**
 * 
 * @type api
 * @hidden(iOS)
 * @region Screen sharing
 * @brief Update border highlighting settings when capturing screen video streams through the internal capture module. The border is shown by default.
 * @param config Border highlighting settings. See ByteRTCHighlightConfig{@link #ByteRTCHighlightConfig}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note  Before calling this API, you must have turned on internal screen capture by calling startScreenVideoCapture:captureParameters:{@link #ByteRTCVideo#startScreenVideoCapture:captureParameters:}.
 */
- (int)updateScreenCaptureHighlightConfig:(ByteRTCHighlightConfig *_Nonnull)config NS_SWIFT_NAME(updateScreenCaptureHighlightConfig(_:));

/**
 * 
 * @hidden(iOS)
 * @type api
 * @region Screen sharing
 * @brief Update the processing settings for the mouse when capturing screen video streams through the capture module provided by the RTC SDK. The mouse is shown by default.
 * @param mouseCursorCaptureState See ByteRTCMouseCursorCaptureState{@link #ByteRTCMouseCursorCaptureState}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note  Before calling this API, you must have turned on internal screen capture by calling startScreenVideoCapture:captureParameters:{@link #ByteRTCVideo#startScreenVideoCapture:captureParameters:}.
 */
- (int)updateScreenCaptureMouseCursor:(ByteRTCMouseCursorCaptureState)mouseCursorCaptureState;

/**
 * 
 * @type api
 * @hidden(iOS)
 * @region Screen sharing
 * @brief When capturing screen video streams through the capture module provided by the RTC SDK, set the windows to be filtered out.
 * @param excludedWindowList The windows to be filtered out.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *        - Before calling this API, you must have turned on internal screen capture by calling startScreenVideoCapture:captureParameters:{@link #ByteRTCVideo#startScreenVideoCapture:captureParameters:}.
 *        - This function only works when the screen source is a screen rather than an application window. See: ByteRTCScreenCaptureSourceType{@link #ByteRTCScreenCaptureSourceType}.
 *        - When you call this API to exclude specific windows, the frame rate of the shared-screen stream will be lower than 30fps。
 */
- (int)updateScreenCaptureFilterConfig:(NSArray<NSNumber *> * _Nullable) excludedWindowList;

/**
 * 
 * @type api
 * @hidden(iOS)
 * @region  screen share
 * @brief  Get the thumbnail of the screen
 * @param sourceType Type of the screen capture object. See ByteRTCScreenCaptureSourceType{@link #ByteRTCScreenCaptureSourceType}.
 * @param sourceId ID of the screen-shared object. You can get the ID from `ByteRTCScreenCaptureSourceInfo` returned by calling getScreenCaptureSourceList{@link #ByteRTCVideo#getScreenCaptureSourceList}.
 * @param maxWidth Maximum width. RTC will scale the thumbnail to fit the given size while maintaining the original aspect ratio. If the aspect ratio of the given size does not match the sharing object, the thumbnail will have blank borders.
 * @param maxHeight Maximum height. Refer to the note for `maxWidth`.
 * @return The thumbnail of the sharing object. <br>
 *         The thumbnail is of the same width-height ratio of the object. The size of the trumbnail is no larger than the specified size.
 */
- (ByteRTCImage *_Nonnull)getThumbnail:(ByteRTCScreenCaptureSourceType)sourceType sourceId:(intptr_t)sourceId maxWidth:(int)maxWidth maxHeight:(int)maxHeight;

/**
 * 
 * @hidden(iOS)
 * @brief Gets application window preview thumbnail for screen sharing.
 * @region Screen Sharing
 * @param sourceId ID of the screen-sharing object. You can get the ID from `ByteRTCScreenCaptureSourceInfo` returned by calling getScreenCaptureSourceList{@link #ByteRTCVideo#getScreenCaptureSourceList}.
 * @param width Maximum width of the App icon. The width is always equal to the height. SDK will set the height and width to the smaller value if the given values are unequal. RTC will return `nullptr` if you set the value with a number out of the valid range, [32, 256]. The default size is 100 x 100.
 * @param height Maximum height of the app icon. Refer to the note for `width`.
 * @return Application icon thumbnail. You can call this API when the item to be shared is an application. If not, the return value will be `nullptr`.
 */
- (ByteRTCImage *_Nonnull)getWindowAppIcon:(intptr_t)sourceId width:(int)width height:(int)height;
#endif

/**
 * 
 * @type api
 * @hidden(iOS)
 * @region audio management
 * @brief Get ByteRTCAudioDeviceManager{@link #ByteRTCAudioDeviceManager}
 * @return ByteRTCAudioDeviceManager{@link #ByteRTCAudioDeviceManager}
 */
- (ByteRTCAudioDeviceManager *_Null_unspecified)getAudioDeviceManager;

/**
 * 
 * @type api
 * @hidden(iOS)
 * @region Video Device Management
 * @brief Get ByteRTCVideoDeviceManager{@link #ByteRTCVideoDeviceManager}
 * @return ByteRTCVideoDeviceManager{@link #ByteRTCVideoDeviceManager}
 */
- (ByteRTCVideoDeviceManager * _Null_unspecified)getVideoDeviceManager NS_SWIFT_NAME(getVideoDeviceManager());

#pragma mark - ASR

/**
 * 
 * @hidden currently not available
 * @type api
 * @region speech recognition service
 * @brief Enables automatic speech recognition service. This method converts the recognized user's voice into text and calls it back to the user via the onMessage:{@link #ByteRTCASREngineEventHandler#onMessage:} event.
 * @param handler The speech recognition service uses a status callback. See ByteRTCASREngineEventHandler{@link #ByteRTCASREngineEventHandler}
 * @param asrConfig Check information. See ByteRTCASRConfig{@link #ByteRTCASRConfig}
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 */
- (int)startASR:(ByteRTCASRConfig *_Nonnull)asrConfig handler:(id<ByteRTCASREngineEventHandler> _Nonnull)handler ;

/**
 * 
 * @hidden currently not available
 * @type api
 * @region speech recognition service
 * @brief Turn off speech recognition service
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 */
- (int)stopASR;
#pragma mark - FileRecording

/**
 * 
 * @type api
 * @region Local recording
 * @brief This method records the audio & video data during the call to a local file.
 * @param streamIndex Stream property, specify whether to record mainstream or screen stream. See ByteRTCStreamIndex{@link #ByteRTCStreamIndex}
 * @param recordingConfig Local recording parameter configuration. See ByteRTCRecordingConfig{@link #ByteRTCRecordingConfig}
 * @param recordingType Locally recorded media type, see ByteRTCRecordingType{@link #ByteRTCRecordingType}
 * @return
 *         - 0: normal
 *         - -1: Parameter setting exception
 *         - -2: The current version of the SDK does not support this feature, please contact technical support
 * @note
 *         - After this API is called, the local user will receive rtcEngine:onRecordingStateUpdate:state:error_code:recording_info:{@link #ByteRTCVideoDelegate#rtcEngine:onRecordingStateUpdate:state:error_code:recording_info:} callback.
 *         - If the recording is normal, the system will report the recording progress through rtcEngine:onRecordingProgressUpdate:process:recording_info:{@link #ByteRTCVideoDelegate#rtcEngine:onRecordingProgressUpdate:process:recording_info:} callback every second.
 */
- (int)startFileRecording:(ByteRTCStreamIndex)streamIndex
      withRecordingConfig:(ByteRTCRecordingConfig* _Nonnull)recordingConfig type:(ByteRTCRecordingType)recordingType NS_SWIFT_NAME(startFileRecording(_:withRecordingConfig:type:));

/**
 * 
 * @type api
 * @region Local recording
 * @brief Stops local recording
 * @param streamIndex Stream property, specify to stop mainstream or screen stream recording. See ByteRTCStreamIndex{@link #ByteRTCStreamIndex}
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *         - After calling startFileRecording:withRecordingConfig:type:{@link #ByteRTCVideo#startFileRecording:withRecordingConfig:type:} to start local recording, you must call this method to stop recording.
 *         - The recording result will be called back through rtcEngine:onRecordingStateUpdate:state:error_code:recording_info:{@link #ByteRTCVideoDelegate#rtcEngine:onRecordingStateUpdate:state:error_code:recording_info:}.
 */
- (int)stopFileRecording:(ByteRTCStreamIndex)streamIndex;

/**
 * 
 * @type api
 * @brief Starts recording audio communication, and generate the local file. <br>
 *        If you call this API before or after joining the room without internal audio capture, then the recording task can still begin but the data will not be recorded in the local files. Only when you call startAudioCapture{@link #ByteRTCVideo#startAudioCapture} to enable internal audio capture, the data will be recorded in the local files.
 * @param recordingConfig See ByteRTCAudioRecordingConfig{@link #ByteRTCAudioRecordingConfig}.
 * @return
 *        - 0: Success
 *        - -2: Invalid parameters
 *        - -3: Not valid in this SDK. Please contact the technical support.
 * @note
 *        - All audio effects are valid in the file. Mixed audio file is not included in the file.
 *        - Call stopAudioRecording{@link #ByteRTCVideo#stopAudioRecording} to stop recording.
 *        - You can call this API before and after joining the room. If this API is called before you join the room, you need to call stopAudioRecording{@link #ByteRTCVideo#stopAudioRecording} to stop recording. If this API is called after you join the room, the recording task ends automatically. If you join multiple rooms, audio from all rooms are recorded in one file.
 *        - After calling the API, you'll receive rtcEngine:onAudioRecordingStateUpdate:error_code:{@link #ByteRTCVideoDelegate#rtcEngine:onAudioRecordingStateUpdate:error_code:}.
 */
- (int)startAudioRecording:(ByteRTCAudioRecordingConfig* _Nonnull) recordingConfig;

 /**
 * 
 * @type api
 * @brief Stop audio recording.
 * @return
 *         - 0: Success
 *         - <0: Failure
 * @note Call startAudioRecording:{@link #ByteRTCVideo#startAudioRecording:} to start the recording task.
 */
- (int)stopAudioRecording;
 
 /**
  * 
  * @type api
  * @deprecated since 353.1, will be deleted in 359, use getAudioEffectPlayer{@link #ByteRTCVideo#getAudioEffectPlayer} or getMediaPlayer:{@link #ByteRTCVideo#getMediaPlayer:} instead
  * @region  mixing
  * @brief Mixing management interface creation
  * @return  Mixing management instance. See ByteRTCAudioMixingManager{@link #ByteRTCAudioMixingManager}
  */
- (ByteRTCAudioMixingManager *_Nullable)getAudioMixingManager __deprecated_msg("deprecated since 353.1, will be deleted in 359, use getAudioEffectPlayer and getMediaPlayer instead");
 
/**
 * 
 * @type api
 * @valid since 3.53
 * @brief Create an instance for audio effect player.
 * @return See ByteRTCAudioEffectPlayer{@link #ByteRTCAudioEffectPlayer}.
 */
- (ByteRTCAudioEffectPlayer *_Nullable)getAudioEffectPlayer;
 
/**
 * 
 * @type api
 * @valid since 3.53
 * @brief Create a media player instance.
 * @param playerId Media player id. The range is `[0, 3]`. You can create up to 4 instances at the same time. If it exceeds the range, nullptr will be returned.
 * @return Media player instance. See ByteRTCMediaPlayer{@link #ByteRTCMediaPlayer}.
 */
- (ByteRTCMediaPlayer *_Nullable)getMediaPlayer:(int)playerId;

#pragma mark - Rtm

/**
 * 
 * @type api
 * @region Real-time messaging
 * @brief Log in to RTS server. <br>
 *        You can call sendUserMessageOutsideRoom:message:config:{@link #ByteRTCVideo#sendUserMessageOutsideRoom:message:config:} and sendServerMessage:{@link #ByteRTCVideo#sendServerMessage:} to send P2P messages or send messages to a server without joining the RTC room. <br>
 *        To log out, call logout{@link #ByteRTCVideo#logout}.
 * @param token Token is required during login for authentication. <br>
 *        This Token is different from that required by calling joinRoom. You can assign any value even null to `roomId` to generate a login token. During developing and testing, you can use temporary tokens generated on the console. Deploy the token generating application on your server.
 * @param uid User ID which need to be unique within one appid.
 * @return
 *        - 0: Success.
 *        - <0: Failure. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for specific reasons.
 * @note The local user will receive rtcEngine:onLoginResult:errorCode:elapsed:{@link #ByteRTCVideoDelegate#rtcEngine:onLoginResult:errorCode:elapsed:} after this API is called successfully. But remote users will not receive notification about that.
 */
- (int)login:(NSString * _Nonnull)token uid:(NSString * _Nonnull)uid;

/**
 * 
 * @type After api
 * @region  real-time messaging
 * @brief Log out of RTS server. <br>
 *        Calls this interface to log out, it is impossible to call methods related to out-of-room messages and end-to-server messages or receive related callbacks.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *        - Before calling this interface to log out, login:uid:{@link #ByteRTCVideo#login:uid:} Login
 *        - After local users call this method to log out, they will receive rtcEngine:onLogout:{@link #ByteRTCVideoDelegate#rtcEngine:onLogout:} callback notification results, and remote users will not receive notifications.
 */
- (int)logout;

/**
 * 
 * @type api
 * @region Real-time messaging
 * @brief Updates the Token used by the user to log in. <br>
 *        Token used by the user to log in has a certain valid period. When the Token expires, you need to call this method to update the login Token information. <br>
 *        If login:uid:{@link #ByteRTCVideo#login:uid:}  is called with an expired Token, the login fails and the local user will receive rtcEngine:onLoginResult:errorCode:elapsed:{@link #ByteRTCVideoDelegate#rtcEngine:onLoginResult:errorCode:elapsed:} about corresponding error code. You need to reacquire a Token and update it with this method.
 * @param token <br>
 *        Updated dynamic key
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *        - If the token is invalid and the login fails, call this method to update the token, and the SDK will automatically log in again. The user does not need to call the login:uid:{@link #ByteRTCVideo#login:uid:} method.
 *        - Token expires, if you have successfully logged in, it will not be affected. An expired Token error will be notified to the user the next time you log in with an expired Token, or when you log in again due to a disconnection due to poor local network conditions.
 */
- (int)updateLoginToken:(NSString * _Nonnull)token;

/**
 * 
 * @type api
 * @region Real-time messaging
 * @brief Sets application server parameters <br>
 *        Client side calls sendServerMessage:{@link #ByteRTCVideo#sendServerMessage:} or sendServerBinaryMessage:{@link #ByteRTCVideo#sendServerBinaryMessage:} Before sending a message to the application server, you must set a valid signature and application server address.
 * @param signature Dynamic signature. The App server may use the signature to verify the source of messages. <br>
 *        You need to define the signature yourself. It can be any non-empty string. It is recommended to encode information such as UID into the signature. <br>
 *        The signature will be sent to the address set through the "url" parameter in the form of a POST request.
 * @param url Address of the application server
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *        - The user must call login:uid:{@link #ByteRTCVideo#login:uid:} before logging in to call this interface.
 *        - After calling this interface, the SDK will use rtcEngine:onServerParamsSetResult:{@link #ByteRTCVideoDelegate#rtcEngine:onServerParamsSetResult:} to return the corresponding result.
 */
- (int)setServerParams:(NSString * _Nonnull)signature url:(NSString * _Nonnull)url;

/**
 * 
 * @type api
 * @region Real-time messaging
 * @brief Query the login status of the opposite or local user
 * @param peerUserId <br>
 *        User ID to query
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *        - You must call login:uid:{@link #ByteRTCVideo#login:uid:} After logging in, you can call this interface.
 *        - After calling this interface, the SDK will use rtcEngine:onGetPeerOnlineStatus:status:{@link #ByteRTCVideoDelegate#rtcEngine:onGetPeerOnlineStatus:status:} callback to notify the query result.
 *        - Before sending an out-of-room message, the user can know whether the peer user is logged in through this interface to decide whether to send a message. You can also check your login status through this interface.
 */
- (int)getPeerOnlineStatus:(NSString * _Nonnull)peerUserId;

/**
 * 
 * @type api
 * @region Real-time messaging
 * @brief Sends a text message (P2P) to a specified user outside the room
 * @param userId <br>
 *        Message Receives the user's ID
 * @param messageStr <br>
 *        Text message content sent <br>
 *        Message does not exceed 64 KB.
 * @param config Message type, see ByteRTCMessageConfig{@link #ByteRTCMessageConfig}.
 * @return
 *         - > 0: Sent successfully, return the number of the sent message, increment from 1
 *         - -1: Sent failed, ByteRTCVideo instance not created
 *         - -2: Sent failed, userId is empty
 * @note
 *        - Before sending an out-of-room text message, you should call login:uid:{@link #ByteRTCVideo#login:uid:} to complete login.
 *        - After the user calls this interface to send a text message, he will receive an rtcEngine:onUserMessageSendResultOutsideRoom:error:{@link #ByteRTCVideoDelegate#rtcEngine:onUserMessageSendResultOutsideRoom:error:} callback to know whether the message was sent successfully;
 *        - If the text message is sent successfully, the user specified by the userId will receive the message through rtcEngine:onUserMessageReceivedOutsideRoom:message:{@link #ByteRTCVideoDelegate#rtcEngine:onUserMessageReceivedOutsideRoom:message:} callback.
 */
- (NSInteger)sendUserMessageOutsideRoom:(NSString * _Nonnull)userId message:(NSString * _Nonnull)messageStr config:(ByteRTCMessageConfig)config;

/**
 * 
 * @type api
 * @region Real-time messaging
 * @brief Send binary messages (P2P) to the specified user outside the room
 * @param userId <br>
 *        Message receiving user's ID
 * @param messageStr <br>
 *        Binary message content sent <br>
 *        Message does not exceed 46KB.
 * @param config Message type, see ByteRTCMessageConfig{@link #ByteRTCMessageConfig}.
 * @return
 *         - > 0: Sent successfully, return the number of the sent message, increment from 1
 *         - -1: Sent failed, ByteRTCVideo instance not created
 *         - -2: Sent failed, userId is empty
 * @note
 *        - Before sending out-of-room binary messages, you must call login:uid:{@link #ByteRTCVideo#login:uid:} to complete login.
 *        - After the user calls this interface to send a binary message, he will receive an rtcEngine:onUserMessageSendResultOutsideRoom:error:{@link #ByteRTCVideoDelegate#rtcEngine:onUserMessageSendResultOutsideRoom:error:} callback to notify whether the message was sent successfully;
 *        - If the binary message is sent successfully, the user specified by the userId will use rtcEngine:onUserBinaryMessageReceivedOutsideRoom:message:{@link #ByteRTCVideoDelegate#rtcEngine:onUserBinaryMessageReceivedOutsideRoom:message:} callback Receive the message.
 */
- (NSInteger)sendUserBinaryMessageOutsideRoom:(NSString * _Nonnull)userId message:(NSData * _Nonnull)messageStr config:(ByteRTCMessageConfig)config;

/**
 * 
 * @type api
 * @region Real-time messaging
 * @brief Client side sends a text message to the application server (P2Server)
 * @param messageStr <br>
 *        The content of the text message sent <br>
 *        The message does not exceed 64 KB.
 * @return
 *         - > 0: Sent successfully, return the number of the sent message, increment from 1
 *         - -1: Sent failed, ByteRTCVideo instance not created
 * @note
 *        - Before sending a text message to the application server, you must first call login:uid:{@link #ByteRTCVideo#login:uid:} to complete the login, and then call setServerParams:url:{@link #ByteRTCVideo#setServerParams:url:} Set up the application server.
 *        - After calling this interface, you will receive an rtcEngine:onServerMessageSendResult:error:message:{@link #ByteRTCVideoDelegate#rtcEngine:onServerMessageSendResult:error:message:} callback to inform the message sender whether the message was sent successfully.
 *        - If the text message is sent successfully, the application server that previously called setServerParams:url:{@link #ByteRTCVideo#setServerParams:url:} will receive the message.
 */
- (NSInteger)sendServerMessage:(NSString * _Nonnull)messageStr;

/**
 * 
 * @type api
 * @region Real-time messaging
 * @brief Client side sends binary messages to the application server (P2Server)
 * @param messageStr <br>
 *        Binary message content sent <br>
 *        Message does not exceed 46KB.
 * @return
 *         - > 0: Send successfully, return the number of the sent message, increment from 1
 *         - -1: Send failed, ByteRTCVideo instance not created
 * @note
 *        - Before sending a binary message to the application server, call login:uid:{@link #ByteRTCVideo#login:uid:} to complete the login, then call setServerParams:url:{@link #ByteRTCVideo#setServerParams:url:} Set up the application server.
 *        - After calling this interface, you will receive an rtcEngine:onServerMessageSendResult:error:message:{@link #ByteRTCVideoDelegate#rtcEngine:onServerMessageSendResult:error:message:} callback to inform the message sender that the sending succeeded or failed;
 *        - If the binary message is sent successfully, the application server that previously called setServerParams:url:{@link #ByteRTCVideo#setServerParams:url:} will receive the message.
 */
- (NSInteger)sendServerBinaryMessage:(NSData * _Nonnull)messageStr;

/**
 * 
 * @type api
 * @region Pre-call network detection
 * @brief Pre-call network detection
 * @param isTestUplink Whether to detect uplink bandwidth
 * @param expectedUplinkBitrate Expected uplink bandwidth, unit: kbps<br>Range: {0, [100-10000]}, `0`: Auto, that RTC will set the highest bite rate.
 * @param isTestDownlink Whether to detect downlink bandwidth
 * @param expectedDownlinkBitrate Expected downlink bandwidth, unit: kbps<br>Range: {0, [100-10000]}, `0`: Auto, that RTC will set the highest bite rate.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *        - After calling this interface, you will receive rtcEngine:onNetworkDetectionResult:quality:rtt:lostRate:bitrate:jitter:{@link #ByteRTCVideoDelegate#rtcEngine:onNetworkDetectionResult:quality:rtt:lostRate:bitrate:jitter:} within 3s and every 2s thereafter notifying the probe result;
 *        - If the probe stops, you will receive rtcEngine:onNetworkDetectionStopped:{@link #ByteRTCVideoDelegate#rtcEngine:onNetworkDetectionStopped:} Notify probe to stop.
 */
- (int)startNetworkDetection:(bool)isTestUplink uplinkBandwidth:(int)expectedUplinkBitrate downlink:(bool)isTestDownlink downlinkBandwidth:(int)expectedDownlinkBitrate;

/**
 * 
 * @type api
 * @region Pre-call network probe
 * @brief Stop pre-call network probe
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *        - After calling this interface, you will receive an rtcEngine:onNetworkDetectionStopped:{@link #ByteRTCVideoDelegate#rtcEngine:onNetworkDetectionStopped:} notification to stop the probe.
 */
- (int)stopNetworkDetection;
#pragma mark  ScreenAudio

/**
 * 
 * @type api
 * @region Screen Sharing
 * @brief Sets the screen audio source type. (internal capture/custom capture)
 * @param sourceType Screen audio source type. See ByteRTCAudioSourceType{@link #ByteRTCAudioSourceType}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *       - The default screen audio source type is RTC SDK internal capture.
 *       - You should call this API before calling publishScreenAudio:{@link #ByteRTCRoom#publishScreenAudio:}. Otherwise, you will receive rtcEngine:onWarning:{@link #ByteRTCEngineDelegate#rtcEngine:onWarning:} with 'ByteRTCWarningSetScreenAudioSourceTypeFailed'.
 *       - When using internal capture, you need to restart screen capture.
 *       - When using custom capture, you need to call pushScreenAudioFrame:{@link #ByteRTCEngine#pushScreenAudioFrame:} to push the audio stream to the RTC SDK.
 *       - Whether you use internal capture or custom capture, you must call publishScreenAudio:{@link #ByteRTCRoom#publishScreenAudio:} to publish the captured screen audio stream.
 */
- (int)setScreenAudioSourceType:(ByteRTCAudioSourceType)sourceType;

/**
 * 
 * @type api
 * @region Screen sharing
 * @brief Sets the mix mode of the screen audio stream and the audio stream collected by the microphone when the screen is shared
 * @param index Mix mode. See ByteRTCStreamIndex{@link #ByteRTCStreamIndex} <br>
 *         - 'ByteRTCStreamIndexMain': Mix the audio stream collected by the screen audio stream and the microphone
 *         - 'ByteRTCStreamIndexScreen': By default, it divides the screen audio stream and the audio stream collected by the microphone into two audio streams
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note You should call this method before publishScreenAudio:{@link #ByteRTCRoom#publishScreenAudio:}. Otherwise, you will receive 'ByteRTCWarningSetScreenAudioStreamIndexFailed' from rtcEngine:onWarning:{@link #ByteRTCEngineDelegate#rtcEngine:onWarning:}
 */
- (int)setScreenAudioStreamIndex:(ByteRTCStreamIndex) index;

/**
 * 
 * @type api
 * @region Screen Sharing
 * @brief Using a custom capture method, when capturing screen audio during screen sharing, push the audio frame to the RTC SDK for encoding and other processing.
 * @param audioFrame Audio data frame. See ByteRTCAudioFrame{@link #ByteRTCAudioFrame} <br>
 *              - The audio sampling format is S16. The data format within the audio buffer must be PCM data, and its capacity should be samples × frame.channel × 2.
 *              - A specific sample rate and the number of channels must be specified; it is not supported to set them to automatic.
 * @return Method call result <br>
 *         - 0: Setup succeeded
 *         - < 0: Setup failed
 * @note
 *         - You must call this API after calling setScreenAudioSourceType:{@link #ByteRTCVideo#setScreenAudioSourceType:} to enable custom capture of the screen audio.
 *         - You should call this method every 10 milliseconds to push a custom captured audio frame. A push audio frame should contain frame.sample _rate/100 audio sample points. For example, if the sampling rate is 48000Hz, 480 sampling points should be pushed each time.
 *         - After calling this interface to push the custom captured audio frame to the RTC SDK, you must call publishScreenAudio:{@link #ByteRTCRoom#publishScreenAudio:} to push the captured screen audio to the remote end. Audio frame information pushed to the RTC SDK is lost before calling publishScreenAudio:{@link #ByteRTCRoom#publishScreenAudio:}.
 */
- (int) pushScreenAudioFrame:(ByteRTCAudioFrame* _Nonnull)audioFrame;

#if BYTERTC_TARGET_MAC

/**
 * 
 * @hidden(iOS)
 * @type api
 * @region screen sharing
 * @brief Starts using RTC SDK internal capture to capture screen audio during screen sharing.
 * @param deviceId ID of the virtual device
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *         - The call of this API takes effects only when you are using RTC SDK to record screen. You will get a warning by rtcEngine:onAudioDeviceWarning:deviceType:deviceWarning:{@link #ByteRTCEngineDelegate#rtcEngine:onAudioDeviceWarning:deviceType:deviceWarning:} after calling this API when the video source is set to an external recorder.
 *         - You also need to call publishScreenAudio:{@link #ByteRTCRoom#publishScreenAudio:} to publish the captured screen audio.
 *         - To disable screen audio internal capture, call stopScreenAudioCapture{@link #ByteRTCEngine#stopScreenAudioCapture}.
 */
- (int)startScreenAudioCapture:(NSString *_Nonnull)deviceId;

/**
 * 
 * @hidden(iOS)
 * @type api
 * @region Screen sharing
 * @brief Stops using RTC SDK internal capture to capture screen audio during screen sharing.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *        - The call of this API takes effects only when you are using RTC SDK to record screen. You will get a warning by rtcEngine:onAudioDeviceWarning:deviceType:deviceWarning:{@link #ByteRTCVideoDelegate#rtcEngine:onAudioDeviceWarning:deviceType:deviceWarning:} after calling this API when the video source is set to an external recorder.
 *        - This API can only stop the screen capture by the RTC SDK. If the video source has been set to external recorder, the call of this API will fail with a warning message. You need to stop it in the external recorder.
 *        - To enable the screen audio internal capture, call startScreenAudioCapture:{@link #ByteRTCVideo#startScreenAudioCapture:}.
 */
- (int)stopScreenAudioCapture;

/**
 * 
 * @hidden(iOS)
 * @type api
 * @region Screen sharing
 * @brief Set the audio channel of the screen-sharing audio stream
 * @param channel The number of Audio channels. See ByteRTCAudioChannel{@link #ByteRTCAudioChannel}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note When you call setScreenAudioStreamIndex:{@link #ByteRTCVideo#setScreenAudioStreamIndex:} to mix the microphone audio stream and the screen-sharing audio stream, the audio channel is set by setAudioProfile:{@link #ByteRTCVideo#setAudioProfile:} rather than this API.
 */
- (int)setScreenAudioChannel:(ByteRTCAudioChannel) channel;

#endif

#pragma mark EncodedVideo


/**
 * 
 * @type api
 * @region Video Management
 * @brief Set the video source, including the screen recordings. <br>
 *        The internal video capture is the default, which refers to capturing video using the built-in module.
 * @param type Video source type. Refer to ByteRTCVideoSourceType{@link #ByteRTCVideoSourceType} for more details.
 * @param streamIndex Stream index. Refer to ByteRTCStreamIndex{@link #ByteRTCStreamIndex} for more details.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *         - You can call this API whether the user is in a room or not.
 *         - Calling this API to switch to the custom video source will stop the enabled internal video capture.
 *         - To switch to internal video capture, call this API to stop custom capture and then call startVideoCapture{@link #ByteRTCVideo#startVideoCapture} to enable internal video capture.
 *         - To push custom encoded video frames to the SDK, call this API to switch `ByteRTCVideoSourceType` to `ByteRTCVideoSourceTypeEncodedManualSimulcast` or `ByteRTCVideoSourceTypeEncodedAutoSimulcast`.
 */
- (int)setVideoSourceType:(ByteRTCVideoSourceType)type WithStreamIndex:(ByteRTCStreamIndex)streamIndex NS_SWIFT_NAME(setVideoSourceType(_:WithStreamIndex:));

/**
 * 
 * @type api
 * @region Video management
 * @brief Register custom encoded frame push event callback
 * @param handler Custom encoded frame callback class. See ByteRTCExternalVideoEncoderEventHandler{@link #ByteRTCExternalVideoEncoderEventHandler}
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *        - This method needs to be called before entering the room.
 *        - The engine needs to be unregistered before it is destroyed. Call this method to set the parameter to nullptr.
 */
- (int)setExternalVideoEncoderEventHandler:(id<ByteRTCExternalVideoEncoderEventHandler> _Nullable)handler;

/**
 * 
 * @type api
 * @region Video management
 * @brief Push custom encoded video stream
 * @param streamIndex The properties of the encoded stream that need to be pushed. See ByteRTCStreamIndex{@link #ByteRTCStreamIndex}
 * @param videoIndex The corresponding encoded stream subscript, starting from 0, if you call setVideoEncoderConfig:{@link #ByteRTCVideo#setVideoEncoderConfig:} The number of multiple streams must be consistent here
 * @param videoFrame Encoding For streaming video frame information. See ByteRTCEncodedVideoFrame{@link #ByteRTCEncodedVideoFrame}.
 * @return API call result: <br>
 *        - 0: Success.
 *        - <0: Failure. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for specific reasons.
 * @note
 *        - Currently, only video frames in H264 and ByteVC1 formats are supported, and the video stream protocol must be in an Annex B format.
 *        - This function runs within the user calling thread
 *        - Before pushing a custom encoded video frame, you must call setVideoSourceType:WithStreamIndex:{@link #ByteRTCVideo#setVideoSourceType:WithStreamIndex:} to switch the video input source to the custom encoded video source.
 */
- (int)pushExternalEncodedVideoFrame:(ByteRTCStreamIndex)streamIndex
                       withVideoIndex:(NSInteger)videoIndex
                withEncodedVideoFrame:(ByteRTCEncodedVideoFrame* _Nonnull)videoFrame NS_SWIFT_NAME(pushExternalEncodedVideoFrame(_:withVideoIndex:withEncodedVideoFrame:));

/**
 * 
 * @type api
 * @region Video Management
 * @brief Before subscribing to the remote video stream, set the remote video data decoding method
 * @param key The remote stream information specifies which video stream to decode. See ByteRTCRemoteStreamKey{@link #ByteRTCRemoteStreamKey}.
 * @param config  Video decoding method. See ByteRTCVideoDecoderConfig{@link #ByteRTCVideoDecoderConfig}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *         - When you want to custom decode a remote stream, you need to call registerRemoteEncodedVideoFrameObserver:{@link #ByteRTCVideo#registerRemoteEncodedVideoFrameObserver:} Register the remote video stream monitor, and then call the interface to set the decoding method to custom decoding. The monitored video data is called back through onRemoteEncodedVideoFrame:withEncodedVideoFrame:{@link #ByteRTCRemoteEncodedVideoFrameObserver#onRemoteEncodedVideoFrame:withEncodedVideoFrame:}.
 *        - Since version 3.56, for automatic subscription, you can set the `RoomId` and `UserId` of `key` as `nullptr`. In this case, the decoding settings set by calling the API applies to all remote main streams or screen sharing streams based on the `StreamIndex` value of `key`.
 */
- (int)setVideoDecoderConfig:(ByteRTCRemoteStreamKey * _Nonnull)key
       withVideoDecoderConfig:(ByteRTCVideoDecoderConfig)config NS_SWIFT_NAME(setVideoDecoderConfig(_:withVideoDecoderConfig:));

/**
 * 
 * @type api
 * @region Video Management
 * @brief After subscribing to the remote video stream, request the keyframe
 * @param key Remote stream information to the remote. See ByteRTCRemoteStreamKey{@link #ByteRTCRemoteStreamKey}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *         - This method is only suitable for manual subscription mode and is used after successful subscription to the remote flow.
 *         - This method is suitable for calling setVideoDecoderConfig:withVideoDecoderConfig:{@link #ByteRTCVideo#setVideoDecoderConfig:withVideoDecoderConfig:} After the custom decoding function is turned on, and the custom decoding fails
 */
- (int)requestRemoteVideoKeyFrame:(ByteRTCRemoteStreamKey * _Nonnull)key;

/**
 * 
 * @type api
 * @region  video management
 * @brief  Video data callback after registering remote encoding. <br>
 *         After registration, when the SDK detects a remote encoded video frame, onRemoteEncodedVideoFrame:withEncodedVideoFrame:{@link #ByteRTCRemoteEncodedVideoFrameObserver#onRemoteEncodedVideoFrame:withEncodedVideoFrame:} callback
 * @param observer Remote encoded video data monitor. See ByteRTCRemoteEncodedVideoFrameObserver{@link #ByteRTCRemoteEncodedVideoFrameObserver}
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *        - See [Custom Video Encoding and Decoding](https:
 *        - This method applys to manual subscription mode and can be called either before or after entering the Room. It is recommended to call it before entering the room.
 *        - The engine needs to be unregistered before it is destroyed. Call this method to set the parameter to nullptr.
 */
- (int)registerRemoteEncodedVideoFrameObserver:(id<ByteRTCRemoteEncodedVideoFrameObserver> _Nullable)observer NS_SWIFT_NAME(registerRemoteEncodedVideoFrameObserver(_:));
#pragma mark StreamSyncInfo

/**
 * 
 * @type api
 * @region Audio management
 * @brief Sends audio stream synchronization information. The message is sent to the remote end through the audio stream and synchronized with the audio stream. After the interface is successfully called, the remote user will receive rtcEngine:onStreamSyncInfoReceived:streamType:data:{@link #ByteRTCVideoDelegate#rtcEngine:onStreamSyncInfoReceived:streamType:data:}.
 * @param data Message content.
 * @param config  For configuration of media stream information synchronization. See ByteRTCStreamSycnInfoConfig{@link #ByteRTCStreamSycnInfoConfig}.
 * @return
 *         - > = 0: Message sent successfully. Returns the number of successful sends.
 *         - -1: Message sending failed. Message length greater than 16 bytes.
 *         - -2: Message sending failed. The content of the incoming message is empty.
 *         - -3: Message sending failed. This screen stream was not published when the message was synchronized through the screen stream.
 *         - -4: Message sending failed. This audio stream is not yet published when you synchronize messages with an audio stream captured by a microphone or custom device, as described in the error code ByteRTCErrorCode{@link #ByteRTCErrorCode}.
 * @note
 * - Regarding the frequency, we recommend no more than 50 calls per second.
 * - When using `ByteRTCRoomProfileInteractivePodcast` as room profile, the data will be delivered. For other coom profiles, the data may be lost when the local user is muted.
 */
- (int)sendStreamSyncInfo:(NSData* _Nonnull)data config:(ByteRTCStreamSycnInfoConfig * _Nonnull)config;

/**
 * 
 * @deprecated since 3.45 and will be deleted in 3.51, use setPlaybackVolume:{@link #ByteRTCVideo#setPlaybackVolume:} instead.
 * @type api
 * @region Media stream management
 * @brief Plays/Stops playing the local audio stream.
 * @param muteState Playinging status to identify whether to play the local audio stream, see: ByteRTCMuteState{@link #ByteRTCMuteState}
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note This method only controls the local audio The playinging state of the stream but does not affect the local audio playback device.
 */
- (int)muteAudioPlayback:(ByteRTCMuteState)muteState __deprecated_msg("Will be removed in new version");

/**
 * 
 * @type api
 * @region Network Management
 * @brief Starts a call test. <br>
 *        Before entering the room, you can call this API to test whether your local audio/video equipment as well as the upstream and downstream networks are working correctly. <br>
 *        Once the test starts, SDK will record your sound or video. If you receive the playback within the delay range you set, the test is considered normal.
 * @param echoConfig Test configurations, see ByteRTCEchoTestConfig{@link #ByteRTCEchoTestConfig}.
 * @param delayTime Delayed audio/video playback time specifying how long you expect to receive the playback after starting the. The range of the value is [2,10] in seconds and the default value is 2.
 * @return API call result: <br>
 *        - 0: Success
 *        - -1: Failure, testing in progress
 *        - -2: Failure, the user us already in the room
 *        - -3: Failure, neither video nor audio is captured
 *        - -4: Failure, parameter exception
 *        - -5: Failure, the roomID is already used
 * @note
 *        - Once you start the test, you can either call stopEchoTest{@link #ByteRTCVideo#stopEchoTest} or wait until the test stops automatically after 60s, to start the next test or enter the room.
 *        - All APIs related to device control and stream control called before this API are invalidated during the test and are restored after the test.
 *        - All APIs related to device control, stream control, and room entry called during the test do not take effect, and you will receive rtcEngine:onWarning:{@link #ByteRTCVideoDelegate#rtcEngine:onWarning:} with the warning code `ByteRTCWarningCodeInEchoTestMode`.
 *        - You will receive the test result from rtcEngine:onEchoTestResult:{@link #ByteRTCVideoDelegate#rtcEngine:onEchoTestResult:}.
 */
- (int)startEchoTest:(ByteRTCEchoTestConfig *_Nullable)echoConfig playDelay:(NSInteger)delayTime;

/**
 * 
 * @type api
 * @region Network Management
 * @brief Stops the current call test. <br>
 *        After calling startEchoTest:playDelay:{@link #ByteRTCVideo#startEchoTest:playDelay:}, you must call this API to stop the test.
 * @return API call result: <br>
 *        - 0: Success
 *        - -1: Failure, no test is in progress
 * @note After stopping the test with this API, all the system devices and streams are restored to the state they were in before the test.
 */
- (int)stopEchoTest;


/**
 * 
 * @type api
 * @region  Audio & Video Processing
 * @brief Adds watermark to designated video stream.
 * @param streamIndex Targeting stream index of the watermark. See ByteRTCStreamIndex{@link #ByteRTCStreamIndex}.
 * @param imagePath The absolute path of the watermark image. The path should be less than 512 bytes. <br>
 *        The watermark image should be in PNG or JPG format.
 * @param rtcWatermarkConfig Watermark configurations. See ByteRTCVideoWatermarkConfig{@link #ByteRTCVideoWatermarkConfig}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *        - Call clearVideoWatermark{@link #ByteRTCVideo#clearVideoWatermark:} to remove the watermark on the designated video stream.
 *        - You can only add one watermark to one video stream. The newly added watermark replaces the previous one. You can call this API multiple times to add watermarks to different streams.
 *        - You can call this API before and after joining room.
 *        - If you mirror the preview, or the preview and the published stream, the watermark will also be mirrored locally, but the published watermark will not be mirrored.
 *        - When you enable simulcast mode, the watermark will be added to all video streams, and it will scale down to smaller encoding configurations accordingly.
 */
- (int)setVideoWatermark:(ByteRTCStreamIndex)streamIndex
            withImagePath:(NSString * _Nullable)imagePath
   withRtcWatermarkConfig:(ByteRTCVideoWatermarkConfig* _Nonnull)rtcWatermarkConfig;

/**
 * 
 * @type api
 * @region  Audio & Video Processing
 * @brief Removes video watermark from designated video stream.
 * @param streamIndex Targeting stream index of the watermark. See ByteRTCStreamIndex{@link #ByteRTCStreamIndex}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 */
- (int)clearVideoWatermark:(ByteRTCStreamIndex)streamIndex NS_SWIFT_NAME(clearVideoWatermark(_:));

/**
 * 
 * @type api
 * @brief Take a snapshot of the local video.
 * @param streamIndex See ByteRTCStreamIndex{@link #ByteRTCStreamIndex}.
 * @param callback See ByteRTCVideoSnapshotCallbackDelegate{@link #ByteRTCVideoSnapshotCallbackDelegate}.
 * @return The index of the local snapshot task, starting from `1`.
 * @note
 *        - The snapshot is taken with all video effects on, like rotation, and mirroring.
 *        - You can take the snapshot either using SDK internal video capture or customized capture.
 */
- (NSInteger)takeLocalSnapshot:(ByteRTCStreamIndex)streamIndex callback:(id<ByteRTCVideoSnapshotCallbackDelegate> _Nullable)callback;

/**
 * 
 * @type api
 * @brief Take a snapshot of the remote video.
 * @param streamKey See ByteRTCRemoteStreamKey{@link #ByteRTCRemoteStreamKey}.
 * @param callback See ByteRTCVideoSnapshotCallbackDelegate{@link #ByteRTCVideoSnapshotCallbackDelegate}.
 * @return The index of the remote snapshot task, starting from `1`.
 */
- (NSInteger)takeRemoteSnapshot:(ByteRTCRemoteStreamKey* _Nonnull)streamKey callback:(id<ByteRTCVideoSnapshotCallbackDelegate> _Nullable)callback;


/**
 * 
 * @type api
 * @brief Take a snapshot of the local/remote video stream and save it as a JPG file at the specified local path. <br>
 *        After calling this method, the SDK triggers onSnapshotTakenToFile:filePath:width:height:errorCode:taskId:{@link #ByteRTCVideoDelegate#onSnapshotTakenToFile:filePath:width:height:errorCode:taskId:} to report whether the snapshot is taken successfully and provide details of the snapshot.
 * @param streamKey Specifies the video stream to take a snapshot from. See ByteRTCRemoteStreamKey{@link #ByteRTCRemoteStreamKey}.<br>
*                   If both `roomId` and `userId` are empty strings, it indicates capturing the local video stream.
 * @param filePath The absolute file path where the snapshot JPG file will be saved. The file extension must be `.jpg`. Ensure that the directory exists and is writable. Example: `/Users/YourName/Pictures/snapshot.jpg`.
 * @return The index of the remote snapshot task, starting from `1`. The index can be used to track the task status or perform other management operations.
 * @list Advanced Features
 */
- (NSInteger)takeSnapshotToFile:(ByteRTCRemoteStreamKey* _Nonnull)streamKey filePath:(NSString * _Nonnull)filePath;


/**
 * 
 * @type api
 * @region  cloud proxy
 * @brief Starts cloud proxy
 * @param  cloudProxiesInfo cloud proxy informarion list. See ByteRTCCloudProxyInfo{@link #ByteRTCCloudProxyInfo}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *         - Call this API before joining the room.
 *         - Start pre-call network detection after starting cloud proxy.
 *         - After starting cloud proxy and connects the cloud proxy server successfully, receives rtcEngine:onCloudProxyConnected:{@link #ByteRTCVideoDelegate#rtcEngine:onCloudProxyConnected:}.
 *         - To stop cloud proxy, call stopCloudProxy{@link #ByteRTCVideo#stopCloudProxy}.
 */
- (int)startCloudProxy:(NSArray <ByteRTCCloudProxyInfo *> * _Nullable)cloudProxiesInfo;

/**
 * 
 * @type api
 * @region  cloud proxy
 * @brief  Stop cloud proxy
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note To start cloud proxy, call startCloudProxy:{@link #ByteRTCVideo#startCloudProxy:}.
 */
- (int)stopCloudProxy;

/**
 * 
 * @type api
 * @brief Create a karaoke scoring management interface.
 * @return Karaoke scoring management interface, see ByteRTCSingScoringManager{@link #ByteRTCSingScoringManager}.
  * @note To use the karaoke scoring feature, i.e., to call this method and all methods in the `ByteRTCSingScoringManager` class, you need to intergrate SAMI dynamic library. For details, see [Integrate Plugins on Demand](docs-1108726).
 */
- (ByteRTCSingScoringManager *_Nullable)getSingScoringManager;


/**
 * 
 * @hidden(macOS)
 * @type api
 * @region Audio & Video Transport
 * @brief Set an alternative image when the local internal video capture is not enabled. <br>
 *        When you call `stopVideoCapture`, an alternative image will be pushed. You can set the path to null or open the camera to stop publishing the image. <br>
 *        You can repeatedly call this API to update the image.
 * @param filePath Set the path of the static image. <br>
 *        You can use the absolute path (file:
 *        You can upload a .JPG, .JPEG, .PNG, or .BMP file. <br>
 *        When the aspect ratio of the image is inconsistent with the video encoder configuration, the image will be proportionally resized, with the remaining pixels rendered black. The framerate and the bitrate are consistent with the video encoder configuration.
 * @return
 *        - 0: Success.
 *        - -1: Failure.
 * @note
 *        - The API is only effective when publishing an internally captured video.
 *        - You cannot locally preview the image.
 *        - You can call this API before and after joining an RTC room. In the multi-room mode, the image can be only displayed in the room you publish the stream.
 *        - You cannot apply effects like filters and mirroring to the image, while you can watermark the image.
 *        - The image is not effective for a screen-sharing stream.
 *        - When you enable the simulcast mode, the image will be added to all video streams, and it will be proportionally scaled down to smaller encoding configurations.
 */
- (int)setDummyCaptureImagePath:(NSString * _Nonnull)filePath;

/**
 * 
 * @type api
 * @brief Obtain the synchronization network time information.
 * @return See ByteRTCNetworkTimeInfo{@link #ByteRTCNetworkTimeInfo}.
 * @note
 *        - When you call this API for the first time, you starts synchornizing the network time information and receive the return value `0`. After the synchonization finishes, you will receive rtcEngineOnNetworkTimeSynchronized:{@link #ByteRTCVideoDelegate#rtcEngineOnNetworkTimeSynchronized:}. After that, calling this API will get you the correct network time.
 *        - Under chorus scenario, participants shall start audio mixing at the same network time.
 */
- (ByteRTCNetworkTimeInfo *_Nonnull)getNetworkTimeInfo;

/**
 * 
 * @type api
 * @hidden internal use only
 * @brief On the listener side, set all subscribed audio streams precisely timely aligned.
 * @param streamKey The remote audio stream used as the benchmark during time alignment. See ByteRTCRemoteStreamKey{@link #ByteRTCRemoteStreamKey}. <br>
 *                  You are recommended to use the audio stream from the lead singer. <br>
 *                  You must call this API after receiving rtcRoom:onUserPublishStream:type:{@link #ByteRTCRoomDelegate#rtcRoom:onUserPublishStream:type:}.
 * @param mode Whether to enable the alignment. Disabled by default. See ByteRTCAudioAlignmentMode{@link #ByteRTCAudioAlignmentMode}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details
 * @note
 *        - You must use the function when all participants set ByteRTCRoomProfile{@link #ByteRTCRoomProfile} to `ByteRTCRoomProfileChorus` when joining the room.
 *        - All remote participants must call startAudioMixing:filePath:config:{@link #ByteRTCAudioMixingManager#startAudioMixing:filePath:config:} to play background music and set `syncProgressToRecordFrame` of ByteRTCAudioMixingConfig{@link #ByteRTCAudioMixingConfig} to `true`.
 *        - If the subscribed audio stream is delayed too much, it may not be precisely aligned.
 *        - The chorus participants must not enable the alignment. If you wish to change the role from listener to participant, you should disable the alignment.
 */
- (int)setAudioAlignmentProperty:(ByteRTCRemoteStreamKey * _Nonnull)streamKey
           withMode:(ByteRTCAudioAlignmentMode)mode;


/**
 * 
 * @hidden internal use
 * @valid since 3.52
 * @type api
 * @brief invoke experimental API. <br>
 *        You may receive rtcEngine:onInvokeExperimentalAPI:{@link #ByteRTCVideoDelegate#rtcEngine:onInvokeExperimentalAPI:}.
 * @note param JSON string like: <br>
 * ```{
 *   "api_name":"startPublish",
 *   "params":{
 *     "streamID":"",
 *     "observer":"",
 *     "uri":"",
 *     "option":""
 *   }
 * }```
 * @return
 *        - 0: Success.
 *        - < 0: Failure.
 * @list Engine Management
 */
- (int)invokeExperimentalAPI:(NSString * _Nonnull)param;


#pragma mark - KTV

/**
 * 
 * @hidden currently not available
 * @type api
 * @brief Creates the KTV manager interfaces.
 * @return KTV manager interfaces. See ByteRTCKTVManager{@link #ByteRTCKTVManager}.
 */
- (ByteRTCKTVManager * _Nullable)getKTVManager;



/**
 * 
 * @type api
 * @region Audio Management
 * @brief Start echo detection before joining a room.
 * @param testAudioFilePath Absolute path of the music file for the detection. It is expected to encode with UTF-8. The following files are supported: mp3, aac, m4a, 3gp, wav. <br>
 *        We recommend to assign a music file whose duration is between 10 to 20 seconds. <br>
 *        Do not pass a Silent file.
 * @return Method call result: <br>
 *         - 0: Success.
 *        - -1: Failure due to the onging process of the previous detection. Call stopHardwareEchoDetection{@link #ByteRTCVideo#stopHardwareEchoDetection} to stop it before calling this API again.
 *        - -2: Failure due to an invalid file path or file format.
 * @note
 *        - You can use this feature only when ByteRTCRoomProfile{@link #ByteRTCRoomProfile} is set to `ByteRTCRoomProfileMeeting` or `ByteRTCRoomProfileMeetingRoom`.
 *        - Before calling this API, ask the user for the permissions to access the local audio devices.
 *        - Before calling this api, make sure the audio devices are activate and keep the capture volume and the playback volume within a reasonable range.
 *        - The detection result is passed as the argument of rtcEngine:onHardwareEchoDetectionResult:{@link #ByteRTCVideoDelegate#rtcEngine:onHardwareEchoDetectionResult:}.
 *        - During the detection, the SDK is not able to response to the other testing APIs, such as startEchoTest:playDelay:{@link #ByteRTCVideo#startEchoTest:playDelay:}, startAudioDeviceRecordTest:{@link #ByteRTCAudioDeviceManager#startAudioDeviceRecordTest:} or startAudioPlaybackDeviceTest:interval:{@link #ByteRTCAudioDeviceManager#startAudioPlaybackDeviceTest:interval:}.
 *        - Call  stopHardwareEchoDetection{@link #ByteRTCVideo#stopHardwareEchoDetection} to stop the detection and release the audio devices.
 */
- (int)startHardwareEchoDetection:(NSString * _Nonnull)testAudioFilePath;

/**
 * 
 * @type api
 * @region Audio Management
 * @brief Stop the echo detection before joining a room.
 * @return Method call result: <br>
 *        - 0: Success.
 *        - -1: Failure.
 * @note
 *        - Refer to startHardwareEchoDetection:{@link #ByteRTCVideo#startHardwareEchoDetection:} for information on how to start a echo detection.
 *        - We recommend calling this API to stop the detection once getting the detection result from rtcEngine:onHardwareEchoDetectionResult:{@link #ByteRTCVideoDelegate#rtcEngine:onHardwareEchoDetectionResult:}.
 *        - You must stop the echo detection to release the audio devices before the user joins a room. Otherwise, the detection may interfere with the call.
 */
- (int)stopHardwareEchoDetection;


/**
 * 
 * @hidden(macOS)
 * @type api
 * @brief Enable cellular network assisted communication to improve call quality.
 * @param config See ByteRTCMediaTypeEnhancementConfig{@link #ByteRTCMediaTypeEnhancementConfig}.
 * @return Method call result: <br>
 *        - 0: Success.
 *        - -1: Failure, internal error.
 *        - -2: Failure, invalid parameters.
 * @note The function is off by default.
 */
- (int)setCellularEnhancement:(ByteRTCMediaTypeEnhancementConfig * _Nonnull)config;

 
 /**
  * 
  * @type api
  * @region proxy
  * @brief Sets local proxy.
  * @param configurations Local proxy configurations. Refer to ByteRTCLocalProxyInfo{@link #ByteRTCLocalProxyInfo} for details. <br>
  *         You can set both Http tunnel and Socks5 as your local proxies, or only set one of them based on your needs. If you set both Http tunnel and Socks5 as your local proxies, then media traffic and signaling are routed through Socks5 proxy and Http requests through Http tunnel proxy. If you set either Http tunnel or Socks5 as your local proxy, then media traffic, signaling and Http requests are all routed through the proxy you chose. <br>
  *         If you want to remove the existing local proxy configurations, you can call this API with the parameter set to null.
  * @note
  *       - You must call this API before joining the room.
  *       - After calling this API, you will receive rtcEngine:onLocalProxyStateChanged:withProxyState:withProxyError:{@link #ByteRTCVideoDelegate#rtcEngine:onLocalProxyStateChanged:withProxyState:withProxyError:} callback that informs you of the states of local proxy connection.
  */
- (int)setLocalProxy:(NSArray <ByteRTCLocalProxyInfo *> * _Nonnull)configurations;
@end
