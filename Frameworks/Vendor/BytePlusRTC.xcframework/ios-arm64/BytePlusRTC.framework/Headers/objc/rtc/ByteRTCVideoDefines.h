/*
 * Copyright (c) 2022 The BytePlusRTC project authors. All Rights Reserved.
 * @brief Objective-C BytePlusRTC Video Defines
*/

#import "ByteRTCAudioDefines.h"

/**
 * 
 * @deprecated since 3.52, use ByteRTCMixedStreamRenderMode{@link #ByteRTCMixedStreamRenderMode} instead.
 * @type keytype
 * @brief The render mode.
 */
typedef NS_ENUM(NSUInteger, ByteRTCRenderMode) {
    
    /**
     * 
     * @brief (Default) Fill and Crop. <br>
     *        The video frame is scaled with fixed aspect ratio, until it completely fills the canvas. The region of the video exceeding the canvas will be cropped.
     */
    ByteRTCRenderModeHidden = 1,
    
    /**
     * 
     * @brief Fit. <br>
     *        The video frame is scaled with fixed aspect ratio, until it fits just within the canvas. Other part of the canvas is filled with the background color.
     */
    ByteRTCRenderModeFit = 2,
    
    /**
     * 
     * @brief Fill the canvas. <br>
     *        The video frame is scaled to fill the canvas. During the process, the aspect ratio may change.
     */
    ByteRTCRenderModeFill = 3,
};


/**
 * 
 * @deprecated since 3.52, use ByteRTCMixedStreamMediaType{@link #ByteRTCMixedStreamMediaType} instead.
 * @type keytype
 * @brief Stream mixing content type
 */
typedef NS_ENUM(NSUInteger, ByteRTCTranscoderContentControlType) {
    
    /**
     * 
     * @brief The mixed stream contains audio and video.
     */
    ByteRTCTranscoderContentControlTypeHasAudioAndVideo = 0,
    
    /**
     * 
     * @brief The mixed stream only contains audio.
     */
    ByteRTCTranscoderContentControlTypeHasAudioOnly = 1,
    
    /**
     * 
     * @brief The mixed stream only contains video.
     */
    ByteRTCTranscoderContentControlTypeHasVideoOnly = 2,
};


/**
 * 
 * @deprecated since 3.52, use ByteRTCMixedStreamLayoutRegionType{@link #ByteRTCMixedStreamLayoutRegionType} instead.
 * @type keytype
 * @brief Stream mixing region type.
 */
typedef NS_ENUM(NSUInteger, ByteRTCTranscoderLayoutRegionType) {

    
    /**
     * 
     * @brief The region type is a video stream.
     */
    ByteRTCTranscoderLayoutRegionTypeVideoStream = 0,

    
    /**
     * 
     * @brief The region type is an image.
     */
    ByteRTCTranscoderLayoutRegionTypeImage = 1,
};



/**
 * 
 * @type keytype
 * @brief  Video Stream Type <br>
 *       Currently C++ SDK only supports ByteRTCVideoStreamTypeHigh type
 */
typedef NS_ENUM(NSInteger, ByteRTCVideoStreamType) {
    
    /**
     * 
     * @brief High Resolution Video Streaming
     */
    ByteRTCVideoStreamTypeHigh = 0,
    
    /**
     * 
     * @brief Low Resolution Video
     */
    ByteRTCVideoStreamTypeLow = 1,
};


/**
 * 
 * @type keytype
 * @brief  Sets the return state of the local video property.
 */
typedef NS_ENUM(NSInteger, ByteRTCVideoStreamState) {
    
   /**
     * 
     * @brief Set local video properties successfully
    */
    ByteRTCVideoStreamStateSuccess                 = 0,
    
   /**
     * 
     * @brief Local video attribute parameter is invalid
    */
    ByteRTCVideoStreamStateInvalid                 = -2,
};


/**
 * 
 * @type keytype
 * @brief  Video output direction mode
 */
typedef NS_ENUM(NSInteger, ByteRTCVideoOutputOrientationMode) {
    
    /**
     * 
     * @brief Self-adaptation layout
     */
    ByteRTCVideoOutputOrientationModeAdaptative = 0,
    
    /**
     * 
     * @brief Landscape layout
     */
    ByteRTCVideoOutputOrientationModeFixedLandscape = 1,
    
    /**
     * 
     * @brief Vertical screen layout
     */
    ByteRTCVideoOutputOrientationModeFixedPortrait = 2,
};


/**
 * 
 * @type keytype
 * @brief Orientation of the video frame.
 */
typedef NS_ENUM(NSUInteger, ByteRTCVideoOrientation) {
    
    /**
    * 
    * @brief (Default) The original orientation of the captured video frame.
    */
    ByteRTCVideoOrientationAdaptive = 0,
    
    /**
    * 
    * @brief Portrait mode. Adjust the captured video frame to vertical layout in RTC SDK.
    */
    ByteRTCVideoOrientationPortrait = 1,
    
    /**
    * 
    * @brief Landscape mode. Adjust the captured video frame to horizontal layout in RTC SDK.
    */
    ByteRTCVideoOrientationLandscape = 2
};


/**
 * 
 * @hidden
 * @type keytype
 * @deprecated since 3.45 and will be deleted in 3.51, use ByteRTCMirrorType{@link #ByteRTCMirrorType} instead.
 * @brief Whether to turn on mirror mode
 */
typedef NS_ENUM(NSUInteger, ByteRTCMirrorMode) {
    
    /**
     * 
     *  @brief Not open
     */
    ByteRTCMirrorModeOff = 0,
    
    /**
     * 
     *  @brief Open
     */
    ByteRTCMirrorModeOn = 1,
};


/**
 * 
 * @type keytype
 * @brief Mirror type
 */
typedef NS_ENUM(NSUInteger, ByteRTCMirrorType) {
    
    /**
     * 
     * @brief The preview and the published video stream are not mirrored.
     */
    ByteRTCMirrorTypeNone = 0,
    
    /**
     * 
     * @brief The preview is mirrored. The published video stream is not mirrored.
     */
    ByteRTCMirrorTypeRender = 1,
    
    /**
     * 
     * @brief The preview is mirrored. The published video stream is not mirrored.
     */
    ByteRTCMirrorTypeEncoder = 2,
    
    /**
     * 
     * @brief The preview and the published video stream are mirrored.
     */
    ByteRTCMirrorTypeRenderAndEncoder = 3,
};


/**
 * 
 * @type keytype
 * @brief Mirroring type for remote stream.
 */
typedef NS_ENUM(NSUInteger, ByteRTCRemoteMirrorType) {
    
    /**
     * 
     * @brief (Default) Disable mirroring effect for remote streams.
     */
    ByteRTCRemoteMirrorTypeNone = 0,
    
    /**
     * 
     * @brief Enable mirroring effect for remote streams.
     */
    ByteRTCRemoteMirrorTypeRender = 1,
};


/**
 * 
 * @type keytype
 * @brief Snapshot error codes
 */
typedef NS_ENUM(NSInteger, ByteRTCSnapshotErrorCode) {
    
    /**
     * 
     * @brief Success.
     */
    ByteRTCSnapshotErrorCodeOk = 0,
    
    /**
     * 
     * @brief Failure. Fails to generate the image data or encode RGBA.
     */
    ByteRTCSnapshotErrorCodeCreateFail = -1,
    
    /**
     * 
     * @brief Failure. The stream is invalid.
     */
    ByteRTCSnapshotErrorCodeStreamInvalid = -2,
    
    /**
     * 
     * @brief Failure. Snapshot timeout, with a default timeout of 1 second.
     */
    ByteRTCSnapshotErrorCodeTimeout = -3,
    
    /**
     * 
     * @brief Failure. Fails to save the image.
     */
    ByteRTCSnapshotErrorCodeFileSaveError = -4
};

/**
 * 
 * @type keytype
 * @brief Basic beauty effect.
 */
typedef NS_ENUM(NSUInteger, ByteRTCEffectBeautyMode) {
    
    /**
     * 
     * @brief Brightening.
     */
    ByteRTCEffectBeautyModeWhite = 0,
    
    /**
     * 
     * @brief Smoothing.
     */
    ByteRTCEffectBeautyModeSmooth = 1,
    
    /**
     * 
     * @brief Sharpening.
     */
    ByteRTCEffectBeautyModeSharpen = 2,
    
    /**
     * 
     * @valid since 3.55
     * @brief Clarity. Integrating Effects SDK v4.4.2+ is required for this sub-item.
     */ 
    ByteRTCEffectBeautyModeClear = 3,
};


/**
 * 
 * @type keytype
 * @brief Video frame rotation
 */
typedef NS_ENUM(NSInteger, ByteRTCVideoRotation) {
    
    /**
     * 
     * @brief Not to rotate.
     */
    ByteRTCVideoRotation0 = 0,
    
    /**
     * 
     * @brief Rotate 90 degrees clockwise.
     */
    ByteRTCVideoRotation90 = 90,
    
    /**
     * 
     * @brief Rotate 180 degrees clockwise.
     */
    ByteRTCVideoRotation180 = 180,
    
    /**
     * 
     * @brief Rotate 270 degrees clockwise.
     */
    ByteRTCVideoRotation270 = 270,
};


/**
 * 
 * @type keytype
 * @brief Video content type
 */
typedef NS_ENUM(NSInteger, ByteRTCVideoContentType) {
    
    /**
     * 
     * @brief Normal video
     */
    ByteRTCVideoContentTypeNormalFrame = 0,
    
    /**
     * 
     * @brief Black frame video
     */
    ByteRTCVideoContentTypeBlackFrame = 1,
};


/**
 * 
 * @type keytype
 * @brief Video frame scale mode
 */
typedef NS_ENUM(NSInteger, ByteRTCVideoStreamScaleMode) {
    
    /**
     * 
     * @brief Auto mode, default to ByteRTCVideoStreamScaleModeFitWithCropping.
     */
    ByteRTCVideoStreamScaleModeAuto            = 0,
    
    /**
     * 
     * @brief Stretch the video frame until the video frame and the window have the same resolution. The video frame's aspect ratio can be changed as it is automatically stretched to fill the window, but the whole image is visible.
     */
    ByteRTCVideoStreamScaleModeStretch         = 1,
    
    /**
     * 
     * @brief  Fit the window with cropping <br>
     *         Scale the video frame uniformly until the window is filled. If the video frame's aspect ratio is different from that of the window, the extra part of the video frame will be cropped. <br>
     *         After the scaling process is completed, the width or height of the video frame will be consistent with that of the window, and the other dimension will be greater than or equal to that of the window.
     */
    ByteRTCVideoStreamScaleModeFitWithCropping = 2,
    
    /**
     * 
     * @brief  Fit the window with filling <br>
     *         Scale the video frame uniformly until its width or height reaches the boundary of the window. If the video frame's aspect ratio is different from that of the window, the area that is not filled will be black. <br>
     *         After the scaling process is completed, the width or height of the video frame will be consistent with that of the window, and the other dimension will be less than or equal to that of the window.
     */
    ByteRTCVideoStreamScaleModeFitWithFilling  = 3,
};


/**
 * 
 * @hidden
 * @deprecated since 3.45 and will be deleted in 3.51.
 * @type keytype
 * @brief  Video encoding mode
 */
typedef NS_ENUM(NSInteger, ByteRTCVideoCodecMode) {
    
   /**
     * 
     * @brief Automatic selection
    */
    ByteRTCVideoCodecModeAuto     = 0,
    
   /**
     * 
     * @brief Hardcoding
    */
    ByteRTCVideoCodecModeHardware = 1,
    
   /**
     * 
     * @brief Softcoding
    */
    ByteRTCVideoCodecModeSoftware = 2
};


/**
 * 
 * @type keytype
 * @brief Video compression picture type
 */
typedef NS_ENUM(NSInteger, ByteRTCVideoPictureType) {
    
    /**
     * 
     * @brief Unknown type
     */
    ByteRTCVideoPictureTypeUnknown = 0,
    
    /**
     * 
     * @brief I-frames, key frames which are coded without reference to any other frame.
     */
    ByteRTCVideoPictureTypeI = 1,
    
    /**
     * 
     * @brief P-frames, forward-predicted frames which are coded by a forward predictive coding method.
     */
    ByteRTCVideoPictureTypeP = 2,
    
    /**
     * 
     * @brief B-frames, bi-directionally predicted frames which are coded by both forward and backward predictive coding method.
     */
    ByteRTCVideoPictureTypeB = 3,
};


/**
 * 
 * @type keytype
 * @brief Encoder preference.
 */
typedef NS_ENUM(NSInteger, ByteRTCVideoEncoderPreference) {
    
    /**
     * 
     * @brief No preference. The frame rate and the resolution will not be adjusted.
     */
    ByteRTCVideoEncoderPreferenceDisabled          = 0,
    
    /**
     * 
     * @brief (Default) Frame rate first. The resolution will not be changed.
     */
    ByteRTCVideoEncoderPreferenceMaintainFramerate = 1,
    
    /**
     * 
     * @brief Resolution first.
     */
    ByteRTCVideoEncoderPreferenceMaintainQuality   = 2,
    
    /**
     * 
     * @brief Balancing resolution and frame rate.
     */
    ByteRTCVideoEncoderPreferenceBalance           = 3,
};


/**
 * 
 * @type keytype
 * @brief The encoding modes for shared-screen streams. The default mode is the high-resolution mode.
 */
typedef NS_ENUM(NSInteger, ByteRTCScreenVideoEncoderPreference) {
    
    /**
     * 
     * @hidden(iOS)
     * @brief The automatic mode. The encoding mode is dynamically determined by RTC based on the content.
     */
    ByteRTCScreenVideoEncodePreferenceAuto   = 0,
    
    /**
     * 
     * @brief The high frame rate mode. Ensure the highest framerate possible under challenging network conditions. This mode is designed to share audiovisual content, including games and videos.
     */
    ByteRTCScreenVideoEncodePreferenceFramerate = 1,
    
    /**
     * 
     * @brief The high-resolution mode. Ensure the highest resolution possible under challenging network conditions. This mode is designed to share micro-detailed content, including slides, documents, images, illustrations, or graphics.
     */
    ByteRTCScreenVideoEncodePreferenceQuality   = 2,
};



/**
 * 
 * @hidden
 * @deprecated since 3.45 and will be deleted in 3.51, use ByteRTCVirtualBackgroundSourceType{@link #ByteRTCVirtualBackgroundSourceType} instead.
 * @type keytype
 * @brief Background mode setting.
 */
typedef NS_ENUM(NSUInteger, ByteRTCBackgroundMode) {
    
    /**
     * 
     * @brief No
     */
    ByteRTCBackgroundModeNone = 0,
    
    /**
     * 
     * @brief Virtualization
     */
    ByteRTCBackgroundModeBlur = 1,
    
    /**
     * 
     * @brief Background 1
     */
    ByteRTCBackgroundModeA = 2,
    
    /**
     * 
     * @brief Background 2
     */
    ByteRTCBackgroundModeB = 3,
};


/**
 * 
 * @hidden
 * @deprecated since 3.45 and will be deleted in 3.51.
 * @type keytype
 * @brief Split model settings.
 */
typedef NS_ENUM(NSUInteger, ByteRTCDivideModel) {
    
    /**
     * 
     * @brief Self-research
     */
    ByteRTCDivideModelDefault = 0,
    
    /**
    * 
    * @brief effect model used for the splitting of the background
    */
    ByteRTCDivideModelEffect = 1,
};


/**
 * 
 * @type keytype
 * @brief Data type
 */
typedef NS_ENUM(NSUInteger, ByteRTCDataFrameType) {
    
    /**
     * 
     * @brief SEI data
     */
    ByteRTCDataFrameTypeSei = 0,
    
    /**
     * 
     * @brief Facial recognition data
     */
    ByteRTCDataFrameTypeRoi = 1,
    
    /**
     * 
     * @brief Other data frame type
     */
    ByteRTCDataFrameTypeOther = 2,
};


/**
 * 
 * @type keytype
 * @brief  Video capture preference
 */
typedef NS_ENUM(NSInteger, ByteRTCVideoCapturePreference) {
   
   /**
    * 
    * @brief (Default) Video capture preference: auto <br>
    *        SDK determines the best video capture parameters referring to the camera output parameters and the encoder configuration.
    */
    ByteRTCVideoCapturePreferenceAuto = 0,
   
   /**
    * 
    * @brief Video capture preference: manual <br>
    *        Set the resolution and the frame rate manually.
    */
    ByteRTCVideoCapturePreferenceMannal = 1,
   
   /**
    * 
    * @brief Video capture preference: encoder configuration
    */
    ByteRTCVideoCapturePreferenceAutoPerformance = 2,
};


/**
 * 
 * @type keytype
 * @brief  Video frame type
 */
typedef NS_ENUM(NSInteger, ByteRTCVideoFrameType) {
    
    /**
     * 
     * @brief Video frame type: memory data
     */
    ByteRTCVideoFrameTypeRawMemory = 0,
    
    /**
     * 
     * @brief Video frame type: CVPixelBuffer
     */
    ByteRTCVideoFrameTypePixelBuffer,
};


/**
 * 
 * @type keytype
 * @brief Video frame format
 */
typedef NS_ENUM(NSInteger, ByteRTCVideoPixelFormat) {
    
    /**
     * 
     * @brief Unknown format
     */
    ByteRTCVideoPixelFormatUnknown = 0,
    
    /**
     * 
     * @brief I420
     */
    ByteRTCVideoPixelFormatI420 = 1,
    
    /**
     * 
     * @brief BGRA
     */
    ByteRTCVideoPixelFormatBGRA = 2,
    
    /**
     * 
     * @brief NV21
     */
    ByteRTCVideoPixelFormatNV21 = 3,
    
    /**
     * 
     * @brief RGBA
     */
    ByteRTCVideoPixelFormatRGBA = 4,
    
    /**
     * 
     * @brief IMC2
     */
    ByteRTCVideoPixelFormatIMC2 = 5,
    
    /**
     * 
     * @brief ARGB
     */
    ByteRTCVideoPixelFormatARGB = 7,
    
    /**
     * 
     * @brief NV12
     */
    ByteRTCVideoPixelFormatNV12 = 8,
    
    /**
     * 
     * @brief Opengl Texture2D
     */
    ByteRTCVideoPixelFormatGLTexture2D = 10,
    
    /**
     * 
     * @brief Opengl OES
     */
    ByteRTCVideoPixelFormatGLTextureOES = 11,
    
    /**
     * 
     * @brief CVPixelBuffer
     */
    ByteRTCVideoPixelFormatCVPixelBuffer = 12
};


/**
 * 
 * @type keytype
 * @brief The position of the local video frame.
 */
typedef NS_ENUM(NSInteger, ByteRTCLocalVideoRenderPosition) {
    
    /**
     * 
     * @brief After capturing.
     */
    ByteRTCLocalVideoRenderPositionAfterCapture = 0,
    
    /**
     * 
     * @brief (Default) After preprocessing.
     */
    ByteRTCLocalVideoRenderPositionAfterPreprocess = 1
};


/**
 * 
 * @type keytype
 * @brief The position of the remote video frame.
 */
typedef NS_ENUM(NSInteger, ByteRTCRemoteVideoRenderPosition) {
    
    /**
     * 
     * @brief After decoding.
     */
    ByteRTCRemoteVideoRenderPositionAfterDecoder = 0,
    
    /**
     * 
     * @brief (Default) After processing.
     */
    ByteRTCRemoteVideoRenderPositionAfterPostprocess = 1
};


/**
 * 
 * @type keytype
 * @brief Video frame encoding format
 */
typedef NS_ENUM(NSInteger, ByteRTCVideoSinkPixelFormat) {
    
    /**
     * 
     * @brief Original format
     */
    ByteRTCVideoSinkPixelFormatOriginal = 0,
    
    /**
     * 
     * @brief YUV I420
     */
    ByteRTCVideoSinkPixelFormatI420 = 1,
    
    /**
     * 
     * @brief BGRA
     */
    ByteRTCVideoSinkPixelFormatBGRA = 2,
    
    /**
     * 
     * @brief RGBA format
     */
    ByteRTCVideoSinkPixelFormatRGBA = 5,
    
    /**
     * 
     * @brief YUV NV12
     */
    ByteRTCVideoSinkPixelFormatNV12 = 8
};


/**
 * 
 * @type keytype
 * @brief Whether the video frame needs to be automatically rotate.
 */
typedef NS_ENUM(NSInteger, ByteRTCVideoApplyRotation) {
    
    /**
     * 
     * @brief (Default) No rotation.
     */
    ByteRTCVideoApplyRotationDefault = -1,
    
    /**
     * 
     * @brief Automatic rotation, which rotates video frames to 0 degree based on the rotation angle information.
     */
    ByteRTCVideoApplyRotation0 = 0
};


/**
 * 
 * @type keytype
 * @brief Whether the video frame needs to be mirrored.
 */
typedef NS_ENUM(NSInteger, ByteRTCVideoRenderMirrorType) {
    
    /**
     * 
     * @brief Enable mirroring effect.
     */
    ByteRTCVideoRenderMirrorTypeOn = 1,
    
    /**
     * 
     * @brief (Default) Disable mirroring effect.
     */
    ByteRTCVideoRenderMirrorTypeOff = 2,
};


/**
 * 
 * @hidden not available
 * @type keytype
 * @brief The reason for the change in super resolution mode.
 */
typedef NS_ENUM(NSInteger, ByteRTCVideoSuperResolutionModeChangedReason) {
    
    /**
     * 
     * @brief Successfully turned off the super resolution mode by calling setRemoteVideoSuperResolution:withMode:{@link #ByteRTCVideo#setRemoteVideoSuperResolution:withMode:}.
     */
    ByteRTCVideoSuperResolutionModeChangedReasonAPIOff = 0,
    
    /**
     * 
     * @brief Successfully turned on the super resolution mode by calling setRemoteVideoSuperResolution:withMode:{@link #ByteRTCVideo#setRemoteVideoSuperResolution:withMode:}.
     */
    ByteRTCVideoSuperResolutionModeChangedReasonAPIOn = 1,
    
    /**
     * 
     * @brief Failed to turn on super-resolution mode. The original resolution of the remote video stream should not exceed 640 × 360 pixels.
     */
    ByteRTCVideoSuperResolutionModeChangedReasonResolutionExceed = 2,
    
    /**
     * 
     * @brief Failed to turn on super-resolution mode. You can only turn on super-resolution mode for one stream.
     */
    ByteRTCVideoSuperResolutionModeChangedReasonOverUse = 3,
    
    /**
     * 
     * @brief Incompatible device for super resolution.
     */
    ByteRTCVideoSuperResolutionModeChangedReasonDeviceNotSupport = 4,
    
    /**
     * 
     * @brief the device performance is not enough, VideoSuperResolution is closed dynamically
     */
    ByteRTCVideoSuperResolutionModeChangedReasonDynamicClose = 5,
    
    /**
     * 
     * @brief The super-resolution mode is turned off for other reasons.
     */
    ByteRTCVideoSuperResolutionModeChangedReasonOtherSettingDisabled = 6,
    
    /**
     * 
     * @brief The super-resolution mode is turned on for other reasons.
     */
    ByteRTCVideoSuperResolutionModeChangedReasonOtherSettingEnabled = 7,
    
    /**
     * 
     * @brief The super-resolution mode is not compiled in the SDK.
     */
    ByteRTCVideoSuperResolutionModeChangedReasonNoComponent = 8,
    
    /**
     * 
     * @brief The remote stream does not exist. Reasons include invalid room ID, user ID, or the stream is not published.
     */
    ByteRTCVideoSuperResolutionModeChangedReasonStreamNotExist = 9,
};


/**
 * 
 * @hidden not available
 * @type keytype
 * @brief The reasons for the change in the video noise reduction mode.
 */
typedef NS_ENUM(NSInteger, ByteRTCVideoDenoiseModeChangedReason) {
    
    /**
     * 
     * @brief Video noise reduction mode changed due to unknown reasons.
     */
    ByteRTCVideoDenoiseModeChangedReasonNull = -1,
    
    /**
     * 
     * @brief Successfully turned off video noise reduction by calling setVideoDenoiser:{@link #ByteRTCVideo#setVideoDenoiser:}.
     */
    ByteRTCVideoDenoiseModeChangedReasonApiOff = 0,
    
    /**
     * 
     * @brief Successfully turned on the video noise reduction mode by calling setVideoDenoiser:{@link #ByteRTCVideo#setVideoDenoiser:}.
     */
    ByteRTCVideoDenoiseModeChangedReasonApiOn = 1,
    
    /**
     * 
     * @brief Video noise reduction disabled by configuration.
     */
    ByteRTCVideoDenoiseModeChangedReasonConfigDisabled = 2,
    
    /**
     * 
     * @brief Video noise reduction enabled by configuration.
     */
    ByteRTCVideoDenoiseModeChangedReasonConfigEnabled = 3,
    
    /**
     * 
     * @brief Video noise reduction turned off due to internal exceptions.
     */
    ByteRTCVideoDenoiseModeChangedReasonInternalException = 4,
    
    /**
     * 
     * @brief Video noise reduction turned off due to hardware performance stress.
     */
    ByteRTCVideoDenoiseModeChangedReasonDynamicClose = 5,
    
    /**
     * 
     * @brief Device hardware capacity is sufficient, video noise reduction turned on.
     */
    ByteRTCVideoDenoiseModeChangedReasonDynamicOpen = 6,
    
    /**
     * 
     * @brief Video noise reduction mode changed due to video resolution. High resolution leads to high hardware utilization. Reduce the resolution to recover video noise reduction.
     */
    ByteRTCVideoDenoiseModeChangedReasonResolution = 7,
};


/**
 * 
 * @deprecated since 3.52, use ByteRTCMixedStreamType{@link #ByteRTCMixedStreamType} instead.
 * @type keytype
 * @brief Stream mixing type
 */
typedef NS_ENUM(NSUInteger, ByteRTCStreamMixingType) {
    
    /**
     * 
     * @brief Mix media streams on the server side.
     */
    ByteRTCStreamMixingTypeByServer = 0,
    
    /**
     * 
     * @brief Intelligent stream mixing. The SDK will intelligently decide that a stream mixing task would be done on the client or the server side.
     */
    ByteRTCStreamMixingTypeByClient = 1,
};

/**
 * 
 * @type keytype
 * @brief Events during pushing streams to CDN
 */
typedef NS_ENUM(NSUInteger, ByteRTCStreamMixingEvent) {
    
    /**
    * 
    * @hidden for internal use only
    */
    ByteRTCStreamMixingEventBase = 0,
    
    /**
     * 
     * @brief Request to start the task to push streams to CDN
     */
    ByteRTCStreamMixingEventStart = 1,
    
    /**
     * 
     * @brief The task to push streams to CDN started
     */
    ByteRTCStreamMixingEventStartSuccess = 2,
    
    /**
     * 
     * @brief Failed to start the task to push streams to CDN
     */
    ByteRTCStreamMixingEventStartFailed = 3,
    
    /**
     * 
     * @brief Request to update the configuration for the task to push streams to CDN
     */
    ByteRTCStreamMixingEventUpdate = 4,
    
    /**
     * 
     * @brief Successfully update the configuration for the task to push streams to CDN
     */
    ByteRTCStreamMixingEventUpdateSuccess = 5,
    
    /**
     * 
     * @brief Failed to update the configuration for the task to push streams to CDN
     */
    ByteRTCStreamMixingEventUpdateFailed = 6,
    
    /**
     * 
     * @brief Request to stop the task to push streams to CDN
     */
    ByteRTCStreamMixingEventStop = 7,
    
    /**
     * 
     * @brief The task to push streams to CDN stopped
     */
    ByteRTCStreamMixingEventStopSuccess = 8,
    
    /**
     * 
     * @brief Failed to stop the task to push streams to CDN
     */
    ByteRTCStreamMixingEventStopFailed = 9,
    
    /**
     * 
     * @brief Timeout for the request to update the configuration for the task to push streams to CDN.
     */
    ByteRTCStreamMixingEventChangeMixType = 10,
    
    /**
     * 
     * @brief Got the first frame of the mixed audio stream by client.
     */
    ByteRTCStreamMixingEventFirstAudioFrameByClientMixer = 11,
    
    /**
     * 
     * @brief Got the first frame of the mixed video stream by client.
     */
    ByteRTCStreamMixingEventFirstVideoFrameByClientMixer = 12,
    
    /**
     * 
     * @brief Timeout for the request to update the configuration for the task to push streams to CDN
     */
    ByteRTCStreamMixingEventUpdateTimeout = 13,
    
    /**
     * 
     * @brief Timeout for the request to start the task to push streams to CDN
     */
    ByteRTCStreamMixingEventStartTimeout = 14,
    
    /**
     * 
     * @brief Error in the parameters of the request for the task to push streams to CDN
     */
    ByteRTCStreamMixingEventRequestParamError = 15,
    
    /**
     * 
     * @brief Mixing image.
     */
    ByteRTCStreamMixingEventMixImage = 16,
    
    /**
     * 
     * @hidden internal use only
     * @brief Simplex chorus event
     */
    ByteRTCStreamMixingEventSingleWayChorus = 17,
};

/**
 * 
 * @type keytype
 * @brief Stream mixing type.(New)
 */
typedef NS_ENUM(NSUInteger, ByteRTCMixedStreamType) {
    
    /**
     * 
     * @brief Mix media streams on the server side.
     */
    ByteRTCMixedStreamByServer = 0,
    
    /**
     * 
     * @brief Intelligent stream mixing. The SDK will intelligently decide that a stream mixing task would be done on the client or the server side. <br>
     *        Before using the option, please contact the technical support. Otherwise, the option does not take effect.
     */
    ByteRTCMixedStreamByClient = 1,
};

/**
 * 
 * @type keytype
 * @brief The video format for client stream mixing callback.(New) <br>
 *        If the format you set is not adaptable to the system, the format will be set as the default value.
 */
typedef NS_ENUM(NSUInteger, ByteRTCMixedStreamClientMixVideoFormat) {
    
    /**
     * 
     * @brief YUV I420 format. The default format for Android and Windows. Supported system: Android, Windows.
     */
    ByteRTCMixedStreamClientMixVideoFormatI420 = 0,
    
    /**
     * 
     * @brief OpenGL GL_TEXTURE_2D format. Supported system: Android.
     */
    ByteRTCMixedStreamClientMixVideoFormatTexture2D = 1,
    
    /**
     * 
     * @brief CVPixelBuffer BGRA format. The default format for iOS. support system: iOS.
     */
    ByteRTCMixedStreamClientMixVideoFormatCVPixelBufferBGRA = 2,
    
    /**
     * 
     * @brief YUV NV12 format. The default format for macOS. Supported system: macOS.
     */
    ByteRTCMixedStreamClientMixVideoFormatNV12 = 3,
};


/**
 * 
 * @type keytype
 * @brief The video codec.(New)
 */
typedef NS_ENUM(NSUInteger, ByteRTCMixedStreamVideoCodecType) {
    
    /**
     * 
     * @brief (Default) H.264 format.
     */
    ByteRTCMixedStreamVideoCodecTypeH264 = 0,
    
    /**
     * 
     * @brief ByteVC1 format.
     */
    ByteRTCMixedStreamVideoCodecTypeByteVC1 = 1,
};

/**
 * 
 * @type keytype
 * @brief Stream mixing content type.(New)
 */
typedef NS_ENUM(NSUInteger, ByteRTCMixedStreamMediaType) {
    
    /**
     * 
     * @brief The mixed stream contains audio and video.
     */
    ByteRTCMixedStreamMediaTypeAudioAndVideo = 0,
    
    /**
     * 
     * @brief The mixed stream only contains audio.
     */
    ByteRTCMixedStreamMediaTypeAudioOnly = 1,
    
    /**
     * 
     * @brief The mixed stream only contains video.
     */
    ByteRTCMixedStreamMediaTypeVideoOnly = 2,
};

/**
 * 
 * @type keytype
 * @brief The render mode.(New)
 */
typedef NS_ENUM(NSUInteger, ByteRTCMixedStreamRenderMode) {
    
    /**
     * 
     * @brief (Default) Fill and Crop. <br>
     *        The video frame is scaled with fixed aspect ratio, until it completely fills the canvas. The region of the video exceeding the canvas will be cropped.
     */
    ByteRTCMixedStreamRenderModeHidden = 1,
    
    /**
     * 
     * @brief Fit. <br>
     *        The video frame is scaled with fixed aspect ratio, until it fits just within the canvas. Other part of the canvas is filled with the background color.
     */
    ByteRTCMixedStreamRenderModeFit = 2,
    
    /**
     * 
     * @brief Fill the canvas. <br>
     *        The video frame is scaled to fill the canvas. During the process, the aspect ratio may change.
     */
    ByteRTCMixedStreamRenderModeAdaptive = 3,
};

/**
 * 
 * @type keytype
 * @brief  Stream mixing region type.(New)
 */
typedef NS_ENUM(NSUInteger, ByteRTCMixedStreamLayoutRegionType) {

    
    /**
     * 
     * @brief The region type is a video stream.
     */
    ByteRTCMixedStreamLayoutRegionTypeVideoStream = 0,

    
    /**
     * 
     * @brief The region type is an image.
     */
    ByteRTCMixedStreamLayoutRegionTypeImage = 1,
};


/**
 * 
 * @type keytype
 * @brief Stream mixing sync strategy.
 */
typedef NS_ENUM(NSUInteger, ByteRTCMixedStreamSyncStrategy) {
    
    /**
     * 
     * @brief Stream mixing no sync strategy.
     */
    ByteRTCMixedStreamSyncStrategyNoSync = 0,
    
    /**
     * 
     * @brief Stream mixing use audio precise sync strategy.
     */
    ByteRTCMixedStreamSyncStrategyAudioPreciseSync = 1,
    
    /**
     * 
     * @brief Stream mixing use simplex mode sync strategy.
     */
    ByteRTCMixedStreamSyncStrategySimplexModeSync = 2,
};


/**
 * 
 * @type keytype
 * @brief Stream type in the region
 */
typedef NS_ENUM(NSUInteger, ByteRTCMixedStreamVideoType) {
    
    /**
     * 
     * @brief Mainstream, including: <br>
     *       - Video/audio captured by the the camera/microphone using internal capturing;
     *       - Video/audio captured by custom method.
     */
    ByteRTCMixedStreamVideoTypeMain = 0,

    
    /**
     * 
     * @brief Screen-sharing stream.
     */
    ByteRTCMixedStreamVideoTypeScreen = 1,
};

/**
 * 
 * @deprecated since 3.52, use ByteRTCMixedStreamClientMixVideoFormat{@link #ByteRTCMixedStreamClientMixVideoFormat} instead.
 * @type keytype
 * @brief The video format for client stream mixing callback. If the format you set is not adaptable to the system, the format will be set as the default value.
 */
typedef NS_ENUM(NSUInteger, ByteRTCClientMixVideoFormat) {
    
    /**
     * 
     * @brief YUV I420 format. The default format for Android and Windows. Supported system: Android, Windows.
     */
    ByteRTCClientMixVideoFormatI420 = 0,
    
    /**
     * 
     * @brief OpenGL GL_TEXTURE_2D format. Supported system: Android.
     */
    ByteRTCClientMixVideoFormatTexture2D = 1,
    
    /**
     * 
     * @brief CVPixelBuffer BGRA format. The default format for iOS. support system: iOS.
     */
    ByteRTCClientMixVideoFormatCVPixelBufferBGRA = 2,
    
    /**
     * 
     * @brief YUV NV12 format. The default format for macOS. Supported system: macOS.
     */
    ByteRTCClientMixVideoFormatNV12 = 3,
};


/**
 * 
 * @deprecated since 3.52, use ByteRTCMixedStreamVideoCodecType{@link #ByteRTCMixedStreamVideoCodecType} instead.
 * @type keytype
 * @brief The video codec.
 */
typedef NS_ENUM(NSUInteger, ByteRTCTranscodingVideoCodec) {
    
    /**
     * 
     * @brief (Default) H.264 format.
     */
    ByteRTCTranscodingVideoCodecH264 = 0,
    
    /**
     * 
     * @brief ByteVC1 format.
     */
    ByteRTCTranscodingVideoCodecH265 = 1,
};


/**
 * 
 * @type keytype
 * @brief Content of SEI sent while pushing mixed stream to CDN.
 */
typedef NS_ENUM(NSInteger, ByteRTCMixedStreamSEIContentMode) {
    
    /**
     * 
     * @brief The video stream contains all the SEI information. Default value.
     */
    ByteRTCMixedStreamSEIContentModeDefault = 0,
    
    /**
     * 
     * @brief The SEI data transmitted with non-key frames contains volume information only. <br>
     *        This parameter only takes effect after you set `ByteRTCMixedStreamServerControlConfig.enableVolumeIndication` to "True".
     */
    ByteRTCMixedStreamSEIContentModeEnableVolumeIndication = 1,
};


/**
 * 
 * @type keytype
 * @brief The initiation mode for pushing the stream mixed on the server side to CDN.
 */
typedef NS_ENUM(NSInteger, ByteRTCMixedStreamPushMode) {
    
    /**
     * 
     * @brief When no user publishes a media stream, a mixing-stream task can't be initiated. Default setting. <br>
     *        When a user publishes at least one media stream, mixing-stream task be initiated.
     */
    ByteRTCMixedStreamPushModeOnStream = 0,
    
    /**
     * 
     * @brief Even if no user is actively publishing media streams, it is still possible to initiate a stream mixing task using a placeholder image. <br>
     *        See alternateImageUrl{@link #ByteRTCMixedStreamLayoutRegionConfig#alternateImageUrl} and alternateImageFillMode{@link #ByteRTCMixedStreamLayoutRegionConfig#alternateImageFillMode} for setting a placeholder image.
     */
    ByteRTCMixedStreamPushModeOnStartRequest = 1,
};

/**
 * 
 * @type keytype
 * @brief The fill mode of the placeholder image.
 */
typedef NS_ENUM(NSInteger, ByteRTCMixedStreamAlternateImageFillMode) {
    
    /**
     * 
     * @brief The placeholder image is scaled with the same aspect ratio as the user's original video frame. Default setting.
     */
    ByteRTCMixedStreamAlternateImageFillModeFit = 0,
    
    /**
     * 
     * @brief The placeholder image is not scaled with the same aspect ratio as the user's original video frame. It maintains the original aspect ratio.
     */
    ByteRTCMixedStreamAlternateImageFillModeFill = 1,
};

/**
 * 
 * @type errorcode
 * @brief Errors occurring during pushing a single stream to CDN
 */
typedef NS_ENUM(NSUInteger, ByteRTCSingleStreamPushEvent) {
    
    /**
    * 
    * @hidden for internal use only
    */
    ByteRTCSingleStreamPushEventBase = 0,
    
   /**
    * 
    * @brief Starting pushing a single stream to CDN.
    */
    ByteRTCSingleStreamPushEventStart = 1,
    
   /**
    * 
    * @brief Successfully pushed a single stream to CDN.
    */
    ByteRTCSingleStreamPushEventStartSuccess = 2,
    
   /**
    * 
    * @brief Failed to push a single stream to CDN.
    */
    ByteRTCSingleStreamPushEventStartFailed = 3,
    
    /**
     * 
     * @brief Stop pushing a single stream to CDN.
     */
    ByteRTCSingleStreamPushEventStop = 4,
    
   /**
    * 
    * @brief Request timed out. Please check network status and retry.
    */
    ByteRTCSingleStreamPushEventTimeout = 5,
    
    /**
     * 
     * @brief Request failed due to invalid parameter.
     */
    ByteRTCSingleStreamPushEventParamError = 6,
};


/**
 * 
 * @type keytype
 * @brief Type of the media stream subscribed to
 */
typedef NS_ENUM(NSInteger, ByteRTCSubscribeMediaType) {
    
    /**
     * 
     * @brief Neither audio nor video
     */
    ByteRTCSubscribeMediaTypeNone = 0,
    
    /**
     * 
     * @brief Audio only
     */
    ByteRTCSubscribeMediaTypeAudioOnly = 1,
    
    /**
     * 
     * @brief Video only
     */
    ByteRTCSubscribeMediaTypeVideoOnly = 2,
    
    /**
     * 
     * @brief Both audio and video
     */
    ByteRTCSubscribeMediaTypeAudioAndVideo = 3,
};


/**
 * 
 * @type keytype
 * @brief Type of the stream to be paused/resumed
 */
typedef NS_ENUM(NSInteger, ByteRTCPauseResumControlMediaType) {
    
    /**
     * 
     * @brief Only control audio, not affect video
     */
    ByteRTCControlMediaTypeAudio = 0,
    
    /**
     * 
     * @brief Only control video, not affect audio
     */
    ByteRtcControlMediaTypeVideo = 1,
    
    /**
     * 
     * @brief Simultaneous control of audio and video
     */
    ByteRtcControlMediaTypeAudioAndVideo = 2,
};


/**
 * 
 * @hidden
 * @deprecated since 3.45 and will be deleted in 3.51.
 * @type keytype
 * @brief Video input type
 */
typedef NS_ENUM(NSInteger, ByteRTCMediaInputType) {
    
    /**
     * 
     * @brief Custom collection. <br>
     *         After setting, you can push video frames directly to the SDK.
     */
    ByteRTCMediaInputTypeExternal = 0,
    
    /**
     * 
     * @brief Internal SDK acquisition. <br>
     *         This setting only switches to internal collection. You need to continue to call startVideoCapture{@link #ByteRTCVideo#startVideoCapture} to open internal collection.
     */
    ByteRTCMediaInputTypeInternal = 1
};


/**
 * 
 * @type keytype
 * @brief Video source type
 */
typedef NS_ENUM(NSInteger, ByteRTCVideoSourceType) {
    
    /**
     * 
     * @brief Custom video source
     */
    ByteRTCVideoSourceTypeExternal = 0,
    
    /**
     * 
     * @brief Internal video capture
     */
    ByteRTCVideoSourceTypeInternal = 1,
    
    /**
     * 
     * @brief Custom encoded video source. <br>
     *         Push the encoded video stream with the largest resolution, and the SDK will automatically transcode to generate multiple lower-quality streams for Simulcast.
     */
    ByteRTCVideoSourceTypeEncodedAutoSimulcast = 2,
    
    /**
     * 
     * @brief Custom encoded video source. <br>
     *         The SDK does not automatically generate multiple streams for Simulcast, you need to generate and push streams of different qualities.
     */
    ByteRTCVideoSourceTypeEncodedManualSimulcast = 3
};


 /**
 * 
 * @type keytype
 * @brief The arrangement position of the Alpha channel relative to the RGB channel data.
 */
typedef NS_ENUM(NSInteger, ByteRTCAlphaLayout) {
    
    /**
     * 
     * @brief Alpha data is placed above the RGB data.
     */
    ByteRTCAlphaLayoutTop = 0,
    
    /**
     * 
     * @hidden currently not available
     * @brief Alpha data is placed under the RGB data.
     */
    ByteRTCAlphaLayoutBottom = 1,
    
    /**
     * 
     * @hidden currently not available
     * @brief The Alpha data is placed to the left of the RGB data.
     */
    ByteRTCAlphaLayoutLeft = 2,
    
     
    ByteRTCAlphaLayoutRight = 3,
};


/**
 * 
 * @type keytype
 * @brief Digital Zoom type
 */
typedef NS_ENUM(NSInteger, ByteRTCZoomConfigType) {
    
    /**
     * 
     * @brief set ZoomIn/ZoomOut config
     */
    ByteRTCZoomConfigTypeFocusOffset = 0,
    
    /**
     * 
     * @brief set move config
     */
    ByteRTCZoomConfigTypeMoveOffset = 1
};


/**
 * 
 * @type keytype
 * @brief Action of the digital zoom control
 */
typedef NS_ENUM(NSInteger, ByteRTCZoomDirectionType) {
    
    /**
     * 
     * @brief Move to the left.
     */
    ByteRTCZoomDirectionTypeMoveLeft = 0,
    
    /**
     * 
     * @brief Move to the right.
     */
    ByteRTCZoomDirectionTypeMoveRight = 1,
    
    /**
     * 
     * @brief Move upwards.
     */
    ByteRTCZoomDirectionTypeMoveUp = 2,
    
    /**
     * 
     * @brief Move downwards.
     */
    ByteRTCZoomDirectionTypeMoveDown = 3,
    
    /**
     * 
     * @brief Zoom out.
     */
    ByteRTCZoomDirectionTypeZoomOut = 4,
    
    /**
     * 
     * @brief Zoom in.
     */
    ByteRTCZoomDirectionTypeZoomIn = 5,
    
    /**
     * 
     * @brief Reset digital zoom.
     */
    ByteRTCZoomDirectionTypeReset = 6
};


/**
 * 
 * @type keytype
 * @brief  Video decoding method
 */
typedef NS_ENUM(NSInteger, ByteRTCVideoDecoderConfig) {
    
    /**
     * 
     * @brief Enable SDK internal decoding, only callback the decoded data
     */
    ByteRTCVideoDecoderConfigRaw = 0,
    
    /**
     * 
     * @brief Turn on custom decoding, only callback the data before decoding
     */
    ByteRTCVideoDecoderConfigEncode = 1,
    
    /**
     * 
     * @brief Enable SDK internal decoding, and call back the data before and after decoding at the same time
     */
    ByteRTCVideoDecoderConfigBoth = 2
};


/**
 * 
 * @type keytype
 * @brief Virtual background type.
 */
typedef NS_ENUM(NSInteger, ByteRTCVirtualBackgroundSourceType){
    
    /**
     * 
     * @brief Replace the original background with a solid color.
     */
    ByteRTCVirtualBackgroundSourceTypeColor = 0,
    
    /**
     * 
     * @brief Replace the original background with the specified image.
     */
    ByteRTCVirtualBackgroundSourceTypeImage = 1
};


/**
 * 
 * @type keytype
 * @brief Camera type
 */
typedef NS_ENUM(NSInteger, ByteRTCCameraID) {
    
    /**
     * 
     * @brief Front-facing camera
     */
    ByteRTCCameraIDFront = 0,
    
    /**
     * 
     * @brief Back-facing camera
     */
    ByteRTCCameraIDBack = 1,
    
    /**
     * 
     * @hidden currently not available
     * @brief External camera
     */
    ByteRTCCameraIDExternal = 2,
    
    /**
     * 
     * @brief Invalid value
     */
    ByteRTCCameraIDInvalid = 3,
};

/**
 * 
 * @type errorcode
 * @brief Errors occuring during pushing streams to CDN
 */
typedef NS_ENUM(NSInteger, ByteRtcTranscoderErrorCode) {
    
    /**
     * 
     * @brief Successfully pushed streams to target CDN.
     */
    ByteRtcTranscoderErrorCodeOK = 0,
    
    /**
     * 
     * @brief Undefined error
     */
    ByteRtcTranscoderErrorCodeBase = 1090,
    
    /**
     * 
     * @brief Invalid parameters detected by client SDK.
     */
    ByteRtcTranscoderErrorCodeInvalidParam = 1091,
    
    /**
     * 
     * @brief Program runs with an error, the state machine is in abnormal condition.
     */
    ByteRtcTranscoderErrorCodeInvalidState = 1092,
    
    /**
     * 
     * @brief Invalid operation
     */
    ByteRtcTranscoderErrorCodeInvalidOperator = 1093,
    
    /**
     * 
     * @brief Request timed out. Please check network status and retry.
     */
    ByteRtcTranscoderErrorCodeTimeOut = 1094,
    
    /**
     * 
     * @brief Invalid parameters detected by the server.
     */
    ByteRtcTranscoderErrorCodeInvalidParamByServer = 1095,
    
    /**
     * 
     * @brief Subscription to the stream has expired.
     */
    ByteRtcTranscoderErrorCodeSubTimeoutByServer = 1096,
    
    /**
     * 
     * @brief Internal server error.
     */
    ByteRtcTranscoderErrorCodeInvalidStateByServer = 1097,
    
    /**
     * 
     * @brief The server failed to push streams to CDN.
     */
    ByteRtcTranscoderErrorCodeAuthenticationByCDN = 1098,
    
    /**
     * 
     * @brief Signaling connection timeout error. Please check network status and retry.
     */
    ByteRtcTranscoderErrorCodeTimeoutBySignaling = 1099,
    
    /**
     * 
     * @brief Fail to mix image.
     */
    ByteRtcTranscoderErrorCodeMixImageFail = 1100,
    
    /**
     * 
     * @brief Unknown error from server.
     */
    ByteRtcTranscoderErrorCodeUnKnownErrorByServer = 1101,
    
    /**
     * 
     * @hidden internal use only
     * @brief The cache is not synchronized.
     */
    ByteRtcTranscoderErrorCodeCacheSyncWorse = 1102,
    
    ByteRTCTranscoderErrorCodeRemoteKicked = 1104,
    
    ByteRTCTranscoderErrorCodeJoinDestRoomFailed = 1105,
    
    ByteRTCTranscoderErrorCodeReceiveSrcStreamTimeout = 1106,
    
    ByteRTCTranscoderErrorCodeNotSurportCodec = 1107,
    
    /**
    * 
    * @hidden for internal use only
    */
    ByteRtcTranscoderErrorCodeMax = 1199,
};


/**
 * 
 * @type errorcode
 * @brief Errors occurring during pushing streams to CDN.(New)
 */
typedef NS_ENUM(NSInteger, ByteRTCStreamMixingErrorCode) {
    
    /**
     * 
     * @brief Successfully pushed streams to target CDN.
     */
    ByteRTCStreamMixingErrorCodeOK = 0,
    
    /**
     * 
     * @brief Undefined error
     */
    ByteRTCStreamMixingErrorCodeBase = 1090,
    
    /**
     * 
     * @brief Invalid parameters detected by client SDK.
     */
    ByteRTCStreamMixingErrorCodeInvalidParam = 1091,
    
    /**
     * 
     * @brief Program runs with an error, the state machine is in abnormal condition.
     */
    ByteRTCStreamMixingErrorCodeInvalidState = 1092,
    
    /**
     * 
     * @brief Invalid operation
     */
    ByteRTCStreamMixingErrorCodeInvalidOperator = 1093,
    
    /**
     * 
     * @brief Request timed out. Please check network status and retry.
     */
    ByteRTCStreamMixingErrorCodeTimeOut = 1094,
    
    /**
     * 
     * @brief Invalid parameters detected by the server.
     */
    ByteRTCStreamMixingErrorCodeInvalidParamByServer = 1095,
    
    /**
     * 
     * @brief Subscription to the stream has expired.
     */
    ByteRTCStreamMixingErrorCodeSubTimeoutByServer = 1096,
    
    /**
     * 
     * @brief Internal server error.
     */
    ByteRTCStreamMixingErrorCodeInvalidStateByServer = 1097,
    
    /**
     * 
     * @brief The server failed to push streams to CDN.
     */
    ByteRTCStreamMixingErrorCodeAuthenticationByCDN = 1098,
    
    /**
     * 
     * @brief Signaling connection timeout error. Please check network status and retry.
     */
    ByteRTCStreamMixingErrorCodeTimeoutBySignaling = 1099,
    
    /**
     * 
     * @brief Fail to mix image.
     */
    ByteRTCStreamMixingErrorCodeMixImageFail = 1100,
    
    /**
     * 
     * @brief Unknown error from server.
     */
    ByteRTCStreamMixingErrorCodeUnKnownErrorByServer = 1101,
    
    /**
     * 
     * @hidden currently not available
     * @brief The cache is not synchronize.
     */
    ByteRTCStreamMixingErrorCodeCacheSyncWorse = 1102,
    
    /**
    * 
    * @hidden for internal use only
    */
    ByteRTCStreamMixingErrorCodeMax = 1199,
};

/**
 * 
 * @type keytype
 * @brief Locally recorded media type
 */
typedef NS_ENUM(NSInteger, ByteRTCRecordingType) {
    
    /**
     * 
     * @brief Audio only
     */
    ByteRTCRecordingTypeAudioOnly = 0,
    
    /**
     * 
     * @brief Video only
     */
    ByteRTCRecordingTypeVideoOnly = 1,
    
    /**
     * 
     * @brief Record audio and video simultaneously
     */
    ByteRTCRecordingTypeVideoAndAudio = 2,
};


/**
 * 
 * @type keytype
 * @brief  Screen media type
 */
typedef NS_ENUM(NSInteger, ByteRTCScreenMediaType) {
    
    /**
     * 
     *@brief only capture video data
     */
    ByteRTCScreenMediaTypeVideoOnly = 0,
    
    /**
     * 
     *@brief only capture audio data
     */
    ByteRTCScreenMediaTypeAudioOnly = 1,
    
    /**
     * 
     *@brief capture video && audio data
     */
    ByteRTCScreenMediaTypeVideoAndAudio = 2
};


/**
 * 
 * @type keytype
 * @brief Type of the screen capture object
 */
typedef NS_ENUM(NSUInteger, ByteRTCScreenCaptureSourceType) {
    
    /**
     * 
     * @brief Type unknown
     */
    ByteRTCScreenCaptureSourceTypeUnknown = 0,
    
    /**
     * 
     * @brief Application window
     */
    ByteRTCScreenCaptureSourceTypeWindow = 1,
    
    /**
     * 
     * @brief Desktop
     */
    ByteRTCScreenCaptureSourceTypeScreen = 2
};

/**
 * 
 * @type keytype
 * @region Screen sharing
 * @brief Whether to capture the mouse cursor when capturing screen streams by RTC.
 */
typedef NS_ENUM(NSUInteger, ByteRTCMouseCursorCaptureState) {
    
    /**
     * 
     * @brief  Yes.
     */
    ByteRTCMouseCursorCaptureStateOn,
    
    /**
     * 
     * @brief No.
     */
    ByteRTCMouseCursorCaptureStateOff,
};

/**
 * 
 * @type keytype
 * @brief  Configure how a border is highlighted when you share your screen.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCHighlightConfig: NSObject

/**
 * 
 * @brief Whether to display a highlighted border. A border is highlighted by default.
 */
@property (assign, nonatomic) BOOL enableHighlight;

/**
 * 
 * @brief Color(ARGB format: 0xAARRGGBB).
 */
@property (assign, nonatomic) uint32_t borderColor;

/**
 * 
 * @brief Width(in pixel).
 */
@property (assign, nonatomic) int borderWidth;
@end


/**
 * 
 * @type keytype
 * @brief Torch status
 */
typedef NS_ENUM(NSInteger, ByteRTCTorchState) {
    
    /**
     * 
     * @brief Torch off
     */
    ByteRTCTorchStateOff = 0,
    
    /**
     * 
     * @brief Torch on
     */
    ByteRTCTorchStateOn = 1,
};


/**
 * 
 * @type keytype
 * @brief  Current audio device type
 */
typedef NS_ENUM(NSInteger, ByteRTCVideoDeviceType) {
    
    /**
     * 
     * @brief Unknow video device
     */
    ByteRTCVideoDeviceTypeUnknown = -1,
    
    /**
     * 
     * @brief Video Rendering Device Type
     */
    ByteRTCVideoDeviceTypeRenderDevice = 0,
    
    /**
     * 
     * @brief Video Acquisition Device Type
     */
    ByteRTCVideoDeviceTypeCaptureDevice = 1,
    
    /**
     * 
     *@brief Screen Capture Device Type
     */
    ByteRTCVideoDeviceTypeScreenCaptureDevice = 2
};


/**
 * 
 * @type keytype
 * @brief Media stream type
 */
typedef NS_OPTIONS(NSUInteger, ByteRTCMediaStreamType) {
    
    /**
     * 
     * @brief Controls audio only
     */
    ByteRTCMediaStreamTypeAudio = (1 << 0),
    
    /**
     * 
     * @brief Controls video only
     */
    ByteRTCMediaStreamTypeVideo = (1 << 1),
    
    /**
     * 
     * @brief Controls both audio and video
     */
    ByteRTCMediaStreamTypeBoth = ByteRTCMediaStreamTypeAudio | ByteRTCMediaStreamTypeVideo,
};


/**
 * 
 * @type keytype
 * @brief Ratio to the original video frame rate of the publisher
 */
typedef NS_ENUM(NSUInteger, ByteRTCFrameRateRatio) {
    
    /**
     * 
     * @brief 100%
     */
    ByteRTCFrameRateRatioOrigin = 0,
    
    /**
     * 
     * @brief 50%
     */
    ByteRTCFrameRateRatioHalf = 1,
    
    /**
     * 
     * @brief 25%
     */
    ByteRTCFrameRateRatioQuater = 2,
};


/**
 * 
 * @type keytype
 * @brief Video orientation
 */
typedef NS_ENUM(NSUInteger, ByteRTCVideoRotationMode) {
    
    /**
     * 
     * @brief The orientation of the App
     */
    ByteRTCVideoRotationModeFollowApp = 0,
    
    /**
     * 
     * @brief Gravity
     */
    ByteRTCVideoRotationModeFollowGSensor = 1,
};


/**
 * 
 * @type keytype
 * @brief  Low light adjusted type
 */
typedef NS_ENUM(NSUInteger, ByteRTCVideoEnhancementMode) {
    
    /**
     * 
     * @brief Turn off low light adaptation
     */
    ByteRTCVideoEnhancementModeDisabled = 0,

    
    /**
     * 
     * @brief Turn on low light adaptation auto
     */
    ByteRTCVideoEnhancementModeAuto = 1,
};


/**
 * 
 * @type keytype
 * @brief Expression detection configuration
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCExpressionDetectConfig : NSObject

/**
 * 
 * @brief Whether to enable age detection.
 */
@property (assign, nonatomic) BOOL enableAgeDetect;

/**
 * 
 * @brief Whether to enable gender detection.
 */
@property (assign, nonatomic) BOOL enableGenderDetect;

/**
 * 
 * @brief Whether to enable emotion detection.
 */
@property (assign, nonatomic) BOOL enableEmotionDetect;

/**
 * 
 * @brief Whether to enable attractiveness detection.
 */
@property (assign, nonatomic) BOOL enableAttractivenessDetect;

/**
 * 
 * @brief Whether to enable happiness detection.
 */
@property (assign, nonatomic) BOOL enableHappinessDetect;
@end


/**
 * 
 * @type keytype
 * @brief Expression detect information
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCExpressionDetectInfo : NSObject

/**
* 
* @brief The estimated age in range of (0, 100).
*/
@property (assign, nonatomic) float age;

/**
* 
* @brief The estimated probability of being a male in range of (0.0, 1.0).
*/
@property (assign, nonatomic) float boyProb;

/**
* 
* @brief The estimated attractiveness in range of (0, 100).
*/
@property (assign, nonatomic) float attractive;

/**
* 
* @brief The estimated happy score in range of (0, 100).
*/
@property (assign, nonatomic) float happyScore;

/**
* 
* @brief The estimated sad score in range of (0, 100).
*/
@property (assign, nonatomic) float sadScore;

/**
* 
* @brief The estimated angry score in range of (0, 100).
*/
@property (assign, nonatomic) float angryScore;

/**
* 
* @brief The estimated surprise score in range of (0, 100).
*/
@property (assign, nonatomic) float surpriseScore;

/**
* 
* @brief The estimated emotional arousal in range of (0, 100).
*/
@property (assign, nonatomic) float arousal;

/**
* 
* @brief The estimated emotional valence in range of (-100, 100).
*/
@property (assign, nonatomic) float valence;
@end


/**
 * 
 * @type keytype
 * @brief Expression Detection Result
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCExpressionDetectResult : NSObject

/**
 * 
 * @brief Expression detection result <br>
 *        - 0: Success
 *        - !0: Failure
 */
@property (assign, nonatomic) int detectResult;

/**
 * 
 * @brief The number of detected faces.
 */
@property (assign, nonatomic) int faceCount;


/**
 * 
 * @brief Expression detection information. The length of the array is the same as the number of detected faces. See ByteRTCExpressionDetectInfo{@link #ByteRTCExpressionDetectInfo}.
 */
@property (nonatomic, copy) NSArray<ByteRTCExpressionDetectInfo *> * _Nonnull detectInfo;

@end


/**
 * 
 * @type keytype
 * @brief  A rectangle that you can move around and re-size to share just the portion of the screen defined by that rectangle.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCRectangle : NSObject

/**
 * 
 * @brief The upper-left X coordinates of the rectangular.
 */
@property(assign, nonatomic) int x;

/**
 * 
 * @brief The upper-left Y coordinates of the rectangular.
 */
@property(assign, nonatomic) int y;

/**
 * 
 * @brief Width(in px).
 */
@property(assign, nonatomic) int width;

/**
 * 
 * @brief Height(in px).
 */
@property(assign, nonatomic) int height;
@end

/**
 * 
 * @type keytype
 * @brief Face Detection Result
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCFaceDetectionResult : NSObject

/**
 * 
 * @brief Face Detection Result <br>
 *        - 0: Success
 *        - !0: Failure. See [Error Code Table](https:
 */
@property(assign, nonatomic) int detectResult;

/**
 * 
 * @brief Width of the original image (px)
 */
@property(assign, nonatomic) int imageWidth;

/**
 * 
 * @brief Height of the original image (px)
 */
@property(assign, nonatomic) int imageHeight;

/**
 * 
 * @brief The face recognition rectangles. The length of the array is the same as the number of detected faces. See ByteRTCRectangle{@link #ByteRTCRectangle}.
 */
@property(nonatomic, copy) NSArray<ByteRTCRectangle *> * _Nullable faces;

/**
 * 
 * @brief The time stamp of the video frame using face detection.
 */
@property(assign, nonatomic) CMTime frameTimestamp;

@end

/**
 * 
 * @type keytype
 * @brief Video rendering mode
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCVideoCanvas : NSObject

/**
 * 
 * @brief Local view handle
 */
@property(strong, nonatomic) ByteRTCView* _Nullable view;

/**
 * 
 * @brief See ByteRTCRenderMode{@link #ByteRTCRenderMode}
 */
@property(assign, nonatomic) ByteRTCRenderMode renderMode;

/**
 * 
 * @brief Set the background color of the canvas which is not filled with video frame. The range is `[0x00000000, 0xFFFFFFFF]`. The default is `0x00000000`. The Alpha index is ignored.
 */
@property(assign, nonatomic) NSInteger backgroundColor;

/**
 * 
 * @brief Video frame rotation angle. See ByteRTCVideoRotation{@link #ByteRTCVideoRotation}. The default value is 0, which means no rotation is applied. <br>
 *        This parameter only applies to remote video and does not affect local video settings.
 */
@property(assign, nonatomic) ByteRTCVideoRotation renderRotation;
@end


/**
 * 
 * @type keytype
 * @brief Remote video rendering configuration.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCRemoteVideoRenderConfig : NSObject

/**
 * 
 * @brief See ByteRTCRenderMode{@link #ByteRTCRenderMode}
 */
@property(assign, nonatomic) ByteRTCRenderMode renderMode;

/**
 * 
 * @brief Set the background color of the canvas which is not filled with video frame. The range is `[0x00000000, 0xFFFFFFFF]`. The default is `0x00000000`. The Alpha index is ignored.
 */
@property(assign, nonatomic) NSInteger backgroundColor;

/**
 * 
 * @brief Video frame rotation angle. See ByteRTCVideoRotation{@link #ByteRTCVideoRotation}. The default value is 0, which means no rotation is applied.
 */
@property(assign, nonatomic) ByteRTCVideoRotation renderRotation;
@end



/**
 * 
 * @type keytype
 * @brief Attached data obtained after video decoding
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCFrameExtendedData : NSObject

/**
 * 
 * @brief Data type. See ByteRTCDataFrameType{@link #ByteRTCDataFrameType}.
 */
@property(assign, nonatomic) ByteRTCDataFrameType frameType;

/**
 * 
 * @brief Attached data
 */
@property(strong, nonatomic) NSData * _Nullable extendedData;

/**
 * 
 * @brief Data length
 */
@property(assign, nonatomic) NSInteger extendedDataLen;
@end

NS_ASSUME_NONNULL_BEGIN


/**
 * 
 * @type keytype
 * @brief  Video stream parameters
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCVideoSolution: NSObject

/**
 * 
 * @brief Video resolution
 */
@property(nonatomic, assign) CGSize videoSize;

/**
 * 
 * @brief Video frame rate
 */
@property(nonatomic, assign) NSInteger frameRate;

/**
 * 
 * @brief Maximum bitrate (kbps). You can use `-1` to use the self-adaptive bitrate based on the resolution and framerate.
 */
@property(nonatomic, assign) NSInteger maxKbps;

/**
 * 
 * @brief Minimum bitrate (kbps).
 */
@property(nonatomic, assign) NSInteger minKbps;

/**
 * 
 * @brief Encoder preference. See ByteRTCVideoEncoderPreference{@link #ByteRTCVideoEncoderPreference}
 */
@property(nonatomic, assign) ByteRTCVideoEncoderPreference encoderPreference;
@end


/**
 * 
 * @type keytype
 * @brief  Video acquisition parameters
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCVideoCaptureConfig: NSObject

/**
 * 
 * @brief Video capture preference. See ByteRTCVideoCapturePreference{@link #ByteRTCVideoCapturePreference}
 */
@property(nonatomic, assign) ByteRTCVideoCapturePreference preference;


/**
 * 
 * @brief Video capture resolution
 */
@property(nonatomic, assign) CGSize videoSize;

/**
 * 
 * @brief Video capture frame rate in fps.
 */
@property(nonatomic, assign) NSInteger frameRate;
@end


/**
 * 
 * @type keytype
 * @brief Flow property.
 */
BYTERTC_APPLE_EXPORT @protocol ByteRTCStream <NSObject>

/**
 * 
 * @brief The user ID that published this stream.
 */
@property(nonatomic, copy, readonly) NSString * userId;

/**
 * 
 * @brief Whether this stream is a shared screen stream.
 */
@property(nonatomic, assign, readonly) BOOL isScreen;

/**
 * 
 * @brief Whether this stream includes a video stream.
 */
@property(nonatomic, assign, readonly) BOOL hasVideo;

/**
 * 
 * @brief Whether the stream includes an audio stream.
 */
@property(nonatomic, assign, readonly) BOOL hasAudio;

/**
 * 
 * @brief Resolution information of the video stream. <br>
 *         When a remote user calls setVideoEncoderConfig:{@link #ByteRTCVideo#setVideoEncoderConfig:} method to publish multiple configured video streams, this will contain attribute information for all video streams published by the user. <br>
 *          See ByteRTCVideoSolution{@link #ByteRTCVideoSolution}.
 */
@property(nonatomic, copy, readonly) NSArray<ByteRTCVideoSolution *> * videoStreamDescriptions;

/**
 * 
 * @brief The maximum resolution of the video stream, the maximum publish resolution that can be supported by the callback publisher when multi-resolution publish subscription is enabled.
 */
@property(nonatomic, retain, readonly) ByteRTCVideoSolution *maxVideoStreamDescription;


@property(nonatomic, assign) ByteRTCStreamIndex index;
@end


/**
 * 
 * @type keytype
 * @brief Stream Information
 */
@interface ByteRTCStreamEx : NSObject <ByteRTCStream>

/**
 * 
 * @brief User ID
 */
@property(nonatomic, copy, nullable) NSString *userId;

/**
 * 
 * @brief Whether the stream is a shared screen stream.
 */
@property(nonatomic, assign) BOOL isScreen;

/**
 * 
 * @brief Does the path contain video
 */
@property(nonatomic, assign) BOOL hasVideo;

/**
 * 
 * @brief Does this stream contain audio?
 */
@property(nonatomic, assign) BOOL hasAudio;

/**
 * 
 * @brief For resolution information of the video stream. See ByteRTCVideoSolution{@link #ByteRTCVideoSolution} class. <br>
 *         Users can publish multiple different video resolutions in a stream by calling the setVideoEncoderConfig:{@link #ByteRTCVideo#setVideoEncoderConfig:} method. This parameter is information about all resolutions in the stream.
 */
@property(nonatomic, copy, nullable) NSArray<ByteRTCVideoSolution *> *videoStreamDescriptions;

/**
 * 
 * @brief The maximum resolution of the video stream, the maximum publish resolution that can be supported by the callback publisher when multi-resolution publish subscription is enabled.
 */
@property(nonatomic, retain, nullable) ByteRTCVideoSolution *maxVideoStreamDescription;

@property(nonatomic, assign) ByteRTCStreamIndex index;
@end


/**
 * 
 * @type keytype
 * @brief  The parameter configuration of the subscription flow. Subscription configuration parameters user manually subscribes to all the audio & video streams used. <br>
 *         When the user turns off the automatic subscription function, when using the manual subscription mode, he subscribes to the audio & video stream by calling the `subscribeStream`, and the incoming parameters are for this data type.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCSubscribeConfig: NSObject

/**
 * 
 * @brief Whether it is a screen stream. <br>
 *         By setting this parameter, the user subscribes to the screen share stream or non-screen share stream published by the remote user. YES is a subscription screen share flow, NO is a subscription non-screen share flow, the default value is YES.
 */
@property(nonatomic, assign) BOOL isScreen;

/**
 * 
 * @brief Whether to subscribe to videos. <br>
 *         The user selects whether to subscribe to videos in the remote stream by setting this parameter. YES is a subscription video, NO is a non-subscription video, the default value is YES.
 */
@property(nonatomic, assign) BOOL subscribeVideo;

/**
 * 
 * @brief Whether to subscribe to audio. <br>
 *         The user selects whether to subscribe to audio in the remote stream by setting this parameter. YES is subscribed audio, NO is not subscribed audio, the default value is YES.
 */
@property(nonatomic, assign) BOOL subscribeAudio;

/**
 * 
 * @brief Subscribed video stream resolution subscript. <br>
 *         Users can publish multiple videos streams of different resolutions by calling the setVideoEncoderConfig:{@link #ByteRTCVideo#setVideoEncoderConfig:} method. Therefore, when subscribing to a stream, you need to specify the specific resolution of the subscription. This parameter is used to specify the subscript of the resolution to be subscribed to, and the default value is 0.
 */
@property(nonatomic, assign) NSInteger videoIndex;

/**
 * 
 * @brief Time domain hierarchy of the subscribed video stream, default value is 0.
 */
@property(nonatomic, assign) NSInteger svcLayer;

/**
 * 
 * @brief The width in px of the subscription, the default value is 0.
 */
@property(nonatomic, assign) NSInteger width;

/**
 * 
 * @brief The height in px of the subscription, the default value is 0.
 */
@property(nonatomic, assign) NSInteger height;

/**
 * 
 * @hidden for internal use only
 */
@property(nonatomic, assign) NSInteger subVideoIndex;

/**
 * 
 * @brief Expected maximum frame rate of the subscribed stream in px. The default value is 0, values greater than 10 are valid. <br>
 *        If the frame rate of the stream published is higher than the value set by the subscriber, the subscriber receives the video of the frame rate set by this API; if the frame rate of the stream published is lower than the value set by the subscriber, the subscriber receives the video of the same frame rate of the video published. <br>
 *        Only valid if the stream is coded with SVC technique.
 */
@property (nonatomic, assign) NSInteger framerate;


@end

NS_ASSUME_NONNULL_END


/**
 * 
 * @type keytype
 * @brief Video data to be encoded by SDK
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCVideoFrame : NSObject

/**
 * 
 * @brief Video frame format, see ByteRTCVideoPixelFormat{@link #ByteRTCVideoPixelFormat}
 */
@property(assign, nonatomic) int format;

/**
 * 
 * @brief Gets video content type, see ByteRTCVideoContentType{@link #ByteRTCVideoContentType}.
 */
@property(assign, nonatomic) ByteRTCVideoContentType contentType;

/**
 * 
 * @brief The timestamp information of the current frame
 */
@property(assign, nonatomic) CMTime time;

/**
 * 
 * @deprecated since 3.45 and will be deleted in 3.51, use strideInPixels instead.
 */
@property(assign, nonatomic) int stride DEPRECATED_MSG_ATTRIBUTE("use strideInPixels instead");

/**
 * 
 * @brief Number of bytes per pixel line
 */
@property(assign, nonatomic) int strideInPixels;

/**
 * 
 * @brief Video frame width
 */
@property(assign, nonatomic) int width;

/**
 * 
 * @brief Video frame height
 */
@property(assign, nonatomic) int height;

/**
 * 
 * @brief Data of CVPixelBufferRef type, valid when format is kPixelFormatCVPixelBuffer
 */
@property(assign, nonatomic) CVPixelBufferRef _Nullable textureBuf;

/**
 * 
 * @brief The first address in video frame memory
 */
@property(strong, nonatomic) NSData * _Nullable dataBuf;

/**
 * 
 * @brief Video frame rotation angle, the value must be 0,  90, 180, or 270
 */
@property(assign, nonatomic) ByteRTCVideoRotation rotation;

/**
 * 
 * @hidden for internal use only
 * @brief Video mirroring information
 */
@property(assign, nonatomic) int flip;

/**
 * 
 * @brief Video frame colorspace
 */
@property(assign, nonatomic) ByteRTCColorSpace colorSpace;

/**
 * 
 * @brief the cameraId of the video frame, see ByteRTCCameraID{@link #ByteRTCCameraID}
 */
@property(assign, nonatomic) ByteRTCCameraID cameraId;

/**
 * 
 * @brief Data attached to the video frame
 */
@property(strong, nonatomic) NSData * _Nullable extendedData;


/**
 * 
 * @brief Video frame roi data
 */
@property(strong, nonatomic) NSData * _Nonnull supplementaryInfo;


/**
 * 
 * @brief Video frame color plane number. <br>
 *        YUV formats are categorized into planar format and packed format. <br>
 *        In a planar format, the Y, U, and V components are stored separately as three planes, while in a packed format, the Y, U, and V components are stored in a single array. <br>
 *        When textureBuf has a value, the value is meaningless
 */
@property (assign, nonatomic) int numberOfPlanes;


/**
 * 
 * @brief Gets plane data pointer, the length of array equals numberOfPlanes, and the type of element is NSData*
 * @param plane_index Plane data index; When textureBuf has a value, the value is meaningless
 */
@property (strong, nonatomic) NSArray * _Nullable planeDatas;


/**
 * 
 * @brief Gets the length of the data line in the plane
 * @param plane_index Plane data index, the length of array equals numberOfPlanes, and the type of element is NSNumber*; When textureBuf has a value, the value is meaningless
 */
@property (strong, nonatomic) NSArray * _Nullable planeStrides;

@end


/**
 * 
 * @type keytype
 * @brief Information about video frames
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCEncodedVideoFrame : NSObject

/**
 * 
 * @brief Video encoding type. See ByteRTCVideoCodecType{@link #ByteRTCVideoCodecType}
 */
@property(assign, nonatomic) ByteRTCVideoCodecType codecType;

/**
 * 
 * @brief Video compression picture type. See ByteRTCVideoPictureType{@link #ByteRTCVideoPictureType}
 */
@property(assign, nonatomic) ByteRTCVideoPictureType pictureType;

/**
 * 
 * @brief Video capture timestamp in microseconds
 */
@property(assign, nonatomic) SInt64 timestampUs;

/**
 * 
 * @brief Video encoding timestamp in microseconds
 */
@property(assign, nonatomic) SInt64 timestampDtsUs;

/**
 * 
 * @brief Video frame width in px
 */
@property(assign, nonatomic) int width;

/**
 * 
 * @brief Video frame height in px
 */
@property(assign, nonatomic) int height;

/**
 * 
 * @brief Video frame rotation angle. See ByteRTCVideoRotation{@link #ByteRTCVideoRotation}
 */
@property(nonatomic, assign) ByteRTCVideoRotation rotation;

/**
 * 
 * @brief The pointer to the video frame
 */
@property(strong, nonatomic) NSData * _Nonnull data;

@end

/**
 * 
 * @deprecated since 3.52, use ByteRTCMixedStreamLayoutRegionImageWaterMarkConfig{@link #ByteRTCMixedStreamLayoutRegionImageWaterMarkConfig} instead.
 * @type keytype
 * @brief Image parameters for stream mixing
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCTranscoderLayoutRegionDataParam : NSObject

/**
 * 
 * @brief Width of the original image in px.
 */
@property (assign, nonatomic) NSInteger imageWidth;

/**
 * 
 * @brief Height of the original image in px.
 */
@property (assign, nonatomic) NSInteger imageHeight;
@end


/**
 * 
 * @deprecated since 3.52, use ByteRTCMixedStreamLayoutRegionConfig{@link #ByteRTCMixedStreamLayoutRegionConfig} instead.
 * @type keytype
 * @brief Layout information for one of the video streams or image to be mixed. <br>
 *        After starting to push streams to CDN and mixing multiple video streams, you can set the layout information for each of them.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCVideoCompositingRegion : NSObject

/**
 * 
 * @brief The user ID of the user who publishes the video stream. Required.
 */
@property(copy, nonatomic) NSString * _Nonnull uid;

/**
 * 
 * @brief The room ID of the media stream. Required. <br>
 *        If the media stream is the stream forwarded by startForwardStreamToRooms:{@link #ByteRTCRoom#startForwardStreamToRooms:}, you must set the roomID to the room ID of the target room.
 */
@property(copy, nonatomic) NSString * _Nonnull roomId;

/**
 * 
 * @brief The normalized horizontal coordinate value of the top left end vertex of the user's view, ranging within [0.0, 1.0). The default value is 0.0.
 */
@property(assign, nonatomic) CGFloat x;

/**
 * 
 * @brief The normalized vertical coordinate value of the top left end vertex of the user's view, ranging within [0.0, 1.0). The default value is 0.0.
 */
@property(assign, nonatomic) CGFloat y;

/**
 * 
 * @brief The normalized width of the user's view, ranging within [0.0, 1.0]. The default value is 1.0.
 */
@property(assign, nonatomic) CGFloat width;

/**
 * 
 * @brief The normalized height of the user's view, ranging within [0.0, 1.0]. The default value is 1.0.
 */
@property(assign, nonatomic) CGFloat height;

/**
 * 
 * @brief The layer on which the video is rendered. The range is [0, 100]. 0 for the bottom layer, and 100 for the top layer. The default value is 0.
 */
@property(assign, nonatomic) NSInteger zOrder;

/**
 * 
 *  @brief Whether the source user of the stream is a local user.
 */
 @property(assign, nonatomic) BOOL localUser;

/**
 * 
 *  @brief (Only server-side stream mixing can set this parameter to YES.) Whether the stream comes from screen sharing, the default value is No.
 */
 @property(assign, nonatomic) BOOL screenStream;

/**
 * 
 * @brief (Only server-side stream mixing can set this parameter.) The opacity in range of (0.0, 1.0]. The lower value, the more transparent. The default value is 1.0.
 */
@property(assign, nonatomic) CGFloat alpha;

/**
 * 
 * @brief (Only server-side stream mixing can set this parameter.) The proportion of the radius to the width of the canvas. The default value is 0.0. <br>
 *        After you set the value, `width_px`, `height_px`, and `cornerRadius_px` are calculated based on `width`, `height`, `cornerRadius`, and the width of the canvas. If `cornerRadius_px < min(width_px/2, height_px/2)` is met, the value of `cornerRadius` is set valid; if not, `cornerRadius_px` is set to `min(width_px/2, height_px/2)`, and `cornerRadius` is set to the proportion of `cornerRadius_px` to the width of the canvas.
 */
@property(assign, nonatomic) CGFloat cornerRadius;

/**
 * 
 * @brief (Only server-side stream mixing can set this parameter.) The stream mixing content type. The default value is `ByteRTCTranscoderContentControlTypeHasAudioAndVideo`. See ByteRTCTranscoderContentControlType{@link #ByteRTCTranscoderContentControlType}.
 */
@property (assign, nonatomic) ByteRTCTranscoderContentControlType contentControl;

/**
 * 
 * @brief The render mode. See ByteRTCRenderMode{@link #ByteRTCRenderMode}. The default value is 1.
 */
@property(assign, nonatomic) ByteRTCRenderMode renderMode;

/**
 * 
 * @brief Stream mixing region type. See ByteRTCTranscoderLayoutRegionType{@link #ByteRTCTranscoderLayoutRegionType}.
 */
@property (assign, nonatomic) ByteRTCTranscoderLayoutRegionType type;

/**
 * 
 * @brief   The RGBA data of the mixing image. Put in null when mixing video streams.
 */
@property (strong, nonatomic) NSData * _Nullable data;

/**
 * 
 * @type keytype
 * @brief  Image parameters for stream mixing. See ByteRTCTranscoderLayoutRegionDataParam{@link #ByteRTCTranscoderLayoutRegionDataParam}. Put in null when mixing video streams.
 */
@property (strong, nonatomic) ByteRTCTranscoderLayoutRegionDataParam * _Nullable dataParam;

/**
 * 
 * @type keytype
 * @brief spatial position. See ByteRTCPosition{@link #ByteRTCPosition}.
 */
@property (strong, nonatomic) ByteRTCPosition * _Nullable spatialPosition;
 
/**
 * 
 * @type keytype
 * @brief Sets whether a user applies spatial audio effects: <br>
 *        - Yes: Yes (default setting)
 *        - No: No
 */
@property(assign, nonatomic) BOOL applySpatialAudio;

@end


/**
 * 
 * @deprecated since 3.52, use ByteRTCMixedStreamLayoutConfig{@link #ByteRTCMixedStreamLayoutConfig} instead.
 * @type keytype
 * @brief The overall video layout of the mixed stream. <br>
 *        After starting to push streams to CDN, you can set the layout of each video stream, the background information of the mixed stream, etc.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCVideoCompositingLayout : NSObject

/**
 * 
 * @brief Background-color of the mixed stream in hexadecimal values such as #FFFFFF and #000000. The default value is #000000 (black). <br>
 *        With invalid or empty input, the configurations will be set as the default values.
 */
@property(copy, nonatomic) NSString *_Nonnull backgroundColor;

/**
 * 
 * @brief List of user's video layout information. The specific layout of each stream is detailed in ByteRTCVideoCompositingRegion{@link #ByteRTCVideoCompositingRegion}. <br>
 *        With invalid or empty input, the configurations will be set as the default values.
 */
@property(copy, nonatomic) NSArray<ByteRTCVideoCompositingRegion *> * _Nonnull regions;

/**
 * 
 * @brief Data passed through from the App, up to 4KB in length.
 */
@property(copy, nonatomic) NSString *_Nonnull appData;
@end


/**
 * 
 * @deprecated since 3.52, use ByteRTCMixedStreamVideoConfig{@link #ByteRTCMixedStreamVideoConfig} instead.
 * @type keytype
 * @brief Video transcoding configurations. With invalid or empty input, the configurations will be set as the default values.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCTranscodingVideoConfig : NSObject

/**
 * 
 * @brief The video codec. See ByteRTCTranscodingVideoCodec{@link #ByteRTCTranscodingVideoCodec}. The default value is `0`. <br>
 *        These parameters cannot be updated while pushing stream to the CDN.
 */
@property(assign, nonatomic) ByteRTCTranscodingVideoCodec codec;

/**
 * 
 * @brief The width (pixels) to be set. The range is [2, 1920], and must be an even number. The default value is 640 pixels. <br>
 *        If an odd number is set, the width will be adjusted to the next larger even number.
 */
@property(assign, nonatomic) NSInteger width;

/**
 * 
 * @brief The height (pixels) to be set. The range is [2, 1920], and must be an even number. The default value is 360 pixels. <br>
 *        If an odd number is set, the height will be adjusted to the next larger even number.
 */
@property(assign, nonatomic) NSInteger height;

/**
 * 
 * @brief The frame rate (FPS) in range of [1, 60]. The default value is 15 FPS.
 */
@property(assign, nonatomic) NSInteger fps;

/**
 * 
 * @brief The time interval between I-frames (second) in range of [1, 5]. The default value is 2 seconds. <br>
 *        These parameters cannot be updated while pushing stream to the CDN.
 */
@property(assign, nonatomic) NSInteger gop;

/**
 * 
 * @brief The bitrate (Kbps) in range of [1, 10000]. The default value is self-adaptive.
 */
@property(assign, nonatomic) NSInteger kBitRate;

/**
 * 
 * @deprecated since 3.45 and will be deleted in 3.51.
 * @brief Whether to push streams with low latency.
 */
@property(assign, nonatomic) BOOL lowLatency;

/**
 * 
 * @brief Whether to push streams with B frame, only support by server mix.
 */
@property(assign, nonatomic) BOOL bFrame;
@end


/**
 * 
 * @deprecated since 3.52, use ByteRTCMixedStreamAudioConfig{@link #ByteRTCMixedStreamAudioConfig} instead.
 * @type keytype
 * @brief Audio transcoding configurations. With invalid or empty input, the configurations will be set as the default values. <br>
 *        These parameters cannot be updated while pushing stream to the CDN.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCTranscodingAudioConfig : NSObject

/**
 * 
 * @brief The audio codec.
 * @param codec The audio codec. See ByteRTCTranscodingAudioCodec{@link #ByteRTCTranscodingAudioCodec}. Defaults to `0`.
 */
@property(assign, nonatomic) ByteRTCTranscodingAudioCodec codec;

/**
 * 
 * @brief The sample rate (Hz). Supported sample rates: 32,000 Hz, 44,100 Hz, 48,000 Hz. Defaults to 48,000 Hz.
 */
@property(assign, nonatomic) NSInteger sampleRate;

/**
 * 
 * @brief The number of channels. Supported channels: 1 (single channel), 2 (dual channel).  Defaults to 2.
 */
@property(assign, nonatomic) NSInteger channels;

/**
 * 
 * @brief The bitrate (Kbps) in range of [32, 192]. Defaults to 64 Kbps.
 */
@property(assign, nonatomic) NSInteger kBitRate;

/**
 * 
 * @brief AAC profile. See ByteRTCAACProfile{@link #ByteRTCAACProfile}. Defaults to `0`.
 */
@property(assign, nonatomic) ByteRTCAACProfile profile;

/**
 * 
 * @deprecated since 3.45 and will be deleted in 3.51.
 */
+ (NSString* _Nonnull) toStringWithProfile:(ByteRTCAACProfile) aacProfile;
@end


/**
 * 
 * @deprecated since 3.52, use ByteRTCMixedStreamSpatialAudioConfig{@link #ByteRTCMixedStreamSpatialAudioConfig} instead.
 * @type keytype
 * @brief Spatial audio config when pushing to CDN.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCTranscodingSpatialConfig : NSObject

/**
 * 
 * @brief Whether to enable the spatial audio effect when pushing to CDN. <br>
 *        when you enable the feature, set the `spatialPosition` of each ByteRTCTranscodingSpatialConfig{@link #ByteRTCTranscodingSpatialConfig} for spatial audio effect.
 */
@property(assign, nonatomic) BOOL enableSpatialRender;

/**
 * 
 * @brief The spatial position of the audience. See ByteRTCPosition{@link #ByteRTCPosition}. <br>
 *        The audience is the users who receive the audio stream from CDN.
 */
@property (strong, nonatomic) ByteRTCPosition * _Nullable audienceSpatialPosition;

/**
 * 
 * @brief The orientation of the audience. See ByteRTCHumanOrientation{@link #ByteRTCHumanOrientation}. <br>
 *        The audience is the users who receive the audio stream from CDN.
 */
@property(strong, nonatomic) ByteRTCHumanOrientation * _Nullable audienceSpatialOrientation;

@end

/**
 * 
 * @deprecated since 3.52, use ByteRTCMixedStreamClientMixConfig{@link #ByteRTCMixedStreamClientMixConfig} instead.
 * @type keytype
 * @brief Configurations for mixing and pushing to CDN at client side.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCTranscodingClientMixParam : NSObject

/**
 * 
 * @brief Whether to use original video frames. False by default.
 */
@property(assign, nonatomic) BOOL clientMixUseOriginalFrame;

/**
 * 
 * @brief Whether to use audio mixing. True by default.
 */
@property(assign, nonatomic) BOOL clientMixUseAudioMixer;

/**
 * 
 * @brief The video format to be set. See ByteRTCClientMixVideoFormat{@link #ByteRTCClientMixVideoFormat}.
 */
@property(assign, nonatomic) ByteRTCClientMixVideoFormat clientMixVideoFormat;
@end

/**
 * 
 * @deprecated since 3.52, use ByteRTCMixedStreamSyncControlConfig instead.
 * @hidden internal use only
 * @valid since 3.50
 * @type keytype
 * @brief Parameters of simplex mode and synchronization when pushing to CDN.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCTranscodingSyncControlParam : NSObject

/**
 * 
 * @brief Whether to enable simplex mode during pushing to CDN. False(duplex mode) by default. <br>
 *        When simplex mode is enabled, RTC SDK synchronizes and transcodes the media streams from the local user and several remote users, and pushing the mixed stream to CDN. `syncBaseUser` does not play the streams from the remote users. You must set the following parameters. <br>
 *        When duplex mode is enabled, RTC SDK transcodes the media streams from the local user and several remote users without synchronization, and pushing the mixed stream to CDN. The following parameters are not effective.
 */
@property(assign, nonatomic) BOOL syncStream;

/**
 * 
 * @brief User ID of the base stream during syncing. Null by default.
 */
@property(copy, nonatomic) NSString * _Nullable syncBaseUser;

/**
 * 
 * @brief The max length of the cached stream in milliseconds. 0 by default. <br>
 *        Set the value based on the stall of the media streams. Higher the value, bigger the memory usage. The recommended value is `2000`.
 */
@property(assign, nonatomic) NSInteger syncQueueLengthMs;

/**
 * 
 * @brief Whether to use RTC SDK to push to CDN. True by default. <br>
 *        If `False`, you can get the media frames by onCacheSyncVideo:withDataFrame:withUids:taskId:{@link #LiveTranscodingDelegate#onCacheSyncVideo:withDataFrame:withUids:taskId:} and manually push them to CDN.
 */
@property(assign, nonatomic) BOOL syncClientVideoNeedMix;

/**
 * 
 * @brief Whether only send cache sync pts and not start sync and callback data. False by default. <br>
 *        In the simplex chorus scene of two people, the lead singer should set to False, and the sub-singer should set to True. <br>
 *        In the duplex chorus scene of two people, all the singers should set to False.
 */
@property(assign, nonatomic) BOOL syncOnlySendPts;
@end


/**
 * 
 * @deprecated since 3.52, use ByteRTCMixedStreamConfig{@link #ByteRTCMixedStreamConfig} instead.
 * @type keytype
 * @brief Configurations to be set when pushing media streams to CDN.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCLiveTranscoding : NSObject

/**
 * 
 * @brief Stream mixing type. See ByteRTCStreamMixingType{@link #ByteRTCStreamMixingType}. <br>
 * This parameter cannot be updated while pushing stream to the CDN.
 */
@property(assign, nonatomic) ByteRTCStreamMixingType expectedMixingType;

/**
 * 
 * @brief The overall video layout of the mixed stream. <br>
 *        After starting to push streams to CDN, you can set the layout of each video stream, the background information of the mixed stream, etc. See ByteRTCVideoCompositingLayout{@link #ByteRTCVideoCompositingLayout} for details.
 */
@property(strong, nonatomic) ByteRTCVideoCompositingLayout * _Nonnull layout;

/**
 * 
 * @brief Video transcoding related configurations. See ByteRTCTranscodingVideoConfig{@link #ByteRTCTranscodingVideoConfig}.
 */
@property(strong, nonatomic) ByteRTCTranscodingVideoConfig * _Nonnull video;

/**
 * 
 * @brief Audio transcoding related configurations. See ByteRTCTranscodingAudioConfig{@link #ByteRTCTranscodingAudioConfig} for data types.
 */
@property(strong, nonatomic) ByteRTCTranscodingAudioConfig * _Nonnull audio;

/**
 * 
 * @brief client mix param. See ByteRTCTranscodingClientMixParam{@link #ByteRTCTranscodingClientMixParam} for detail.
 */
@property(strong, nonatomic) ByteRTCTranscodingClientMixParam * _Nullable clientMixParam;

/**
 * 
 * @hidden for internal use only
 * @brief client mix param. See ByteRTCTranscodingSyncControlParam{@link #ByteRTCTranscodingSyncControlParam} for detail.
 */
@property(strong, nonatomic) ByteRTCTranscodingSyncControlParam * _Nullable syncControlParam;

/**
 * 
 * @hidden(macOS)
 * @brief The spatial audio config when pushing to CDN. See ByteRTCTranscodingSpatialConfig{@link #ByteRTCTranscodingSpatialConfig} for detail.
 */
@property(strong, nonatomic) ByteRTCTranscodingSpatialConfig * _Nonnull spatialConfig;


/**
 * 
 * @hidden for internal use only
 * @brief Custom parameter
 */
@property(strong, nonatomic) NSMutableDictionary *  _Nullable advancedConfig;

/**
 * 
 * @hidden for internal use only
 * @brief Authentication information passed through from the App
 */
@property(strong, nonatomic) NSMutableDictionary *  _Nullable authInfo;

/**
 * 
 * @brief The URL for live transcoding. Only supports live transcoding via RTMP. The URL should match the regular expression `/^rtmps?:\/\
 *        This parameter cannot be updated while pushing stream to the CDN.
 */
@property(copy, nonatomic) NSString * _Nullable url;

/**
 * 
 * @brief The room ID for live transcoding. The sum length of `roomId` and `userId` should not exceed 126 bytes. <br>
 *        This parameter cannot be updated while pushing stream to the CDN.
 */
@property(copy, nonatomic) NSString * _Nonnull roomId;

/**
 * 
 * @brief The user ID for live transcoding. The sum length of `roomId` and `userId` should not exceed 126 bytes. <br>
 *        This parameter cannot be updated while pushing stream to the CDN.
 */
@property(copy, nonatomic) NSString * _Nonnull userId;

/**
 * 
 * @brief Gets the default configurations for pushing streams to CDN.
 * @return Configurations for pushing streams to CDN. See ByteRTCLiveTranscoding{@link #ByteRTCLiveTranscoding}.
 */
+ (instancetype _Nonnull)defaultTranscoding;
@end

/**
 * 
 * @type keytype
 * @brief  Image parameters for stream mixing.(New)
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCMixedStreamLayoutRegionImageWaterMarkConfig : NSObject

/**
 * 
 * @brief Width of the original image in px.
 */
@property (assign, nonatomic) NSInteger imageWidth;

/**
 * 
 * @brief Height of the original image in px.
 */
@property (assign, nonatomic) NSInteger imageHeight;
@end


/**
 * 
 * @type keytype
 * @brief Layout information for one of the video streams to be mixed.(New) <br>
 *        After starting to push streams to CDN and mixing multiple video streams, you can set the layout information for each of them.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCMixedStreamLayoutRegionConfig : NSObject

/**
 * 
 * @brief The user ID of the user who publishes the video stream. It's recommended to be set.
 */
@property(copy, nonatomic) NSString * _Nonnull userID;

/**
 * 
 * @brief The room ID of the media stream. It's recommended to be set. <br>
 *        If the media stream is the stream forwarded by startForwardStreamToRooms:{@link #ByteRTCRoom#startForwardStreamToRooms:}, you must set the roomID to the room ID of the target room.
 */
@property(copy, nonatomic) NSString * _Nonnull roomID;

/**
 * 
 * @brief The X-coordinate in pixels of the upper-left corner of the user's frame in the entire canvas coordinate system, where the origin is at the upper-left corner of the canvas. It represents the horizontal displacement of the upper-left corner of the user's frame relative to the origin. <br>
 *        The value range is [0, the width of the canvas). The default value is 0.
 */
@property(assign, nonatomic) NSInteger locationX;

/**
 * 
 * @brief The Y-coordinate in pixels of the upper-left corner of the user's frame in the entire canvas coordinate system, where the origin is at the upper-left corner of the canvas. It represents the vertical displacement of the upper-left corner of the user's frame relative to the origin. <br>
 *        The value range is [0, the height of the canvas). The default value is 0.
 */
@property(assign, nonatomic) NSInteger locationY;

/**
 * 
 * @brief The width of the user's frame in pixels. The value range is [0, the width of the canvas]. The default value is 360.
 */
@property(assign, nonatomic) NSInteger width;

/**
 * 
 * @brief The heigh of the user's frame in pixels. The value range is [0, the height of the canvas]. The default value is 640.
 */
@property(assign, nonatomic) NSInteger height;

/**
 * 
 * @brief The layer on which the video is rendered. The range is [0, 100]. 0 for the bottom layer, and 100 for the top layer. The default value is 0. It's recommended to be set.
 */
@property(assign, nonatomic) NSInteger zOrder;

/**
 * 
 *  @brief Whether the source user of the stream is a local user.
 */
@property(assign, nonatomic) BOOL isLocalUser;

/**
 * 
 *  @brief The mixed stream type, the default value is Main.
 */
@property(assign, nonatomic) ByteRTCMixedStreamVideoType streamType;

/**
 * 
 * @brief The opacity in range of (0.0, 1.0]. The lower value, the more transparent. The default value is 1.0.
 */
@property(assign, nonatomic) CGFloat alpha;

/**
 * 
 * @brief The proportion of the radius to the width of the canvas. `0.0` by default. <br>
 *        After you set the value, `width_px`, `height_px`, and `cornerRadius_px` are calculated based on `width`, `height`, `cornerRadius`, and the width of the canvas. If `cornerRadius_px < min(width_px/2, height_px/2)` is met, the value of `cornerRadius` is set valid; if not, `cornerRadius_px` is set to `min(width_px/2, height_px/2)`, and `cornerRadius` is set to the proportion of `cornerRadius_px` to the width of the canvas.
 */
@property(assign, nonatomic) CGFloat cornerRadius;

/**
 * 
 * @brief The stream mixing content type. The default value is `ByteRTCTranscoderContentControlTypeHasAudioAndVideo`. See ByteRTCMixedStreamMediaType{@link #ByteRTCMixedStreamMediaType}.
 */
@property (assign, nonatomic) ByteRTCMixedStreamMediaType mediaType;

/**
 * 
 * @brief The render mode. See ByteRTCMixedStreamRenderMode{@link #ByteRTCMixedStreamRenderMode}. The default value is 1.
 */
@property(assign, nonatomic) ByteRTCMixedStreamRenderMode renderMode;

/**
 * 
 * @brief Stream mixing region type. See ByteRTCMixedStreamLayoutRegionType{@link #ByteRTCMixedStreamLayoutRegionType}. It's recommended to be set.
 */
@property (assign, nonatomic) ByteRTCMixedStreamLayoutRegionType regionContentType;

/**
 * 
 * @brief   The RGBA data of the mixing image. Put in null when mixing video streams.
 */
@property (strong, nonatomic) NSData * _Nullable imageWaterMark;

/**
 * 
 * @brief  Image parameters for stream mixing. See ByteRTCMixedStreamLayoutRegionImageWaterMarkConfig{@link #ByteRTCMixedStreamLayoutRegionImageWaterMarkConfig}. Put in null when mixing video streams.
 */
@property (strong, nonatomic) ByteRTCMixedStreamLayoutRegionImageWaterMarkConfig * _Nullable imageWaterMarkConfig;

/**
 * 
 * @brief spatial position. See ByteRTCPosition{@link #ByteRTCPosition}.
 */
@property (strong, nonatomic) ByteRTCPosition * _Nullable spatialPosition;
 
/**
 * 
 * @brief Sets whether a user applies spatial audio effects: <br>
 *        - Yes: Yes (default setting)
 *        - No: No
 */
@property(assign, nonatomic) BOOL applySpatialAudio;

/**
 * 
 * @valid since 3.57
 * @brief Sets the fill mode of the placeholder image. <br>
 *        This parameter is used to control the fill mode of the placeholder image after the user stops publishing video streams and the screen reverts to the placeholder image. See ByteRTCMixedStreamAlternateImageFillMode{@link #ByteRTCMixedStreamAlternateImageFillMode}.
 */
@property (assign, nonatomic)ByteRTCMixedStreamAlternateImageFillMode alternateImageFillMode;

/**
 * 
 * @valid since 3.57
 * @brief Sets the URL of the placeholder image, limited to a maximum of 1024 characters.
 */
@property(copy, nonatomic)NSString * alternateImageUrl;
@end


/**
 * 
 * @type keytype
 * @brief The overall video layout of the mixed stream.(New)
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCMixedStreamLayoutConfig : NSObject

/**
 * 
 * @brief Background-color of the mixed stream in hexadecimal values such as #FFFFFF and #000000. The default value is #000000 (black). It's recommended to be set. <br>
 *        With invalid or empty input, the configurations will be set as the default values.
 */
@property(copy, nonatomic) NSString *_Nonnull backgroundColor;

/**
 * 
 * @brief List of user's video layout information. The specific layout of each stream is detailed in ByteRTCMixedStreamLayoutRegionConfig{@link #ByteRTCMixedStreamLayoutRegionConfig}. It's recommended to be set. <br>
 *        With invalid or empty input, the configurations will be set as the default values.
 */
@property(copy, nonatomic) NSArray<ByteRTCMixedStreamLayoutRegionConfig *> * _Nonnull regions;

/**
 * 
 * @brief Info passed through from the user.
 */
@property(copy, nonatomic) NSString *_Nonnull userConfigExtraInfo;

/**
 * 
 * @valid since 3.57
 * @brief Sets the URL of the background image for the canvas that renders the mixed stream, with a maximum length of 1024 bytes. <br>
 *        You can input images in the following supported formats: JPG, JPEG, PNG. <br>
 *        If the width and height of the background image are different from the screen dimensions, the background image will be scaled to fill the screen.
 */
@property(copy, nonatomic) NSString *_Nonnull backgroundImageUrl;
@end


/**
 * 
 * @type keytype
 * @brief Video transcoding configurations.(New) <br>
 *        With invalid or empty input, the configurations will be set as the default values.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCMixedStreamVideoConfig : NSObject

/**
 * 
 * @brief The video codec. See ByteRTCMixedStreamVideoCodecType{@link #ByteRTCMixedStreamVideoCodecType}. The default value is `0`. It's recommended to be set. <br>
 *        These parameters cannot be updated while pushing stream to the CDN.
 */
@property(assign, nonatomic) ByteRTCMixedStreamVideoCodecType videoCodec;

/**
 * 
 * @brief The width (pixels) to be set. The range is [2, 1920], and must be an even number. The default value is 640 pixels. It's recommended to be set. <br>
 *        If an odd number is set, the width will be adjusted to the next larger even number.
 */
@property(assign, nonatomic) NSInteger width;

/**
 * 
 * @brief The height (pixels) to be set. The range is [2, 1920], and must be an even number. The default value is 360 pixels. It's recommended to be set. <br>
 *        If an odd number is set, the height will be adjusted to the next larger even number.
 */
@property(assign, nonatomic) NSInteger height;

/**
 * 
 * @brief The frame rate (FPS) in range of [1, 60]. The default value is 15 FPS. It's recommended to be set.
 */
@property(assign, nonatomic) NSInteger fps;

/**
 * 
 * @brief The time interval between I-frames (second) in range of [1, 5]. The default value is 2 seconds. It's recommended to be set. <br>
 *        These parameters cannot be updated while pushing stream to the CDN.
 */
@property(assign, nonatomic) NSInteger gop;

/**
 * 
 * @brief The bitrate (Kbps) in range of [1, 10000]. The default value is self-adaptive. It's recommended to be set.
 */
@property(assign, nonatomic) NSInteger bitrate;

/**
 * 
 * @brief Whether to push streams with B frame, only support by server mix.
 */
@property(assign, nonatomic) BOOL enableBFrame;
@end


/**
 * 
 * @type keytype
 * @brief Audio transcoding configurations.(New) <br>
 *        With invalid or empty input, the configurations will be set as the default values. <br>
 *        These parameters cannot be updated while pushing stream to the CDN.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCMixedStreamAudioConfig : NSObject

/**
 * 
 * @brief The audio codec.
 * @param codec The audio codec. See ByteRTCMixedStreamAudioCodecType{@link #ByteRTCMixedStreamAudioCodecType}. Defaults to `0`. It's recommended to be set.
 */
@property(assign, nonatomic) ByteRTCMixedStreamAudioCodecType audioCodec;

/**
 * 
 * @brief The sample rate (Hz). Supported sample rates: 32,000 Hz, 44,100 Hz, 48,000 Hz. Defaults to 48,000 Hz. It's recommended to be set.
 */
@property(assign, nonatomic) NSInteger sampleRate;

/**
 * 
 * @brief The number of channels. Supported channels: 1 (single channel), 2 (dual channel).  Defaults to 2. It's recommended to be set.
 */
@property(assign, nonatomic) NSInteger channels;

/**
 * 
 * @brief The bitrate (Kbps) in range of [32, 192]. Defaults to 64 Kbps. It's recommended to be set.
 */
@property(assign, nonatomic) NSInteger bitrate;

/**
 * 
 * @brief AAC profile. See ByteRTCMixedStreamAudioProfile{@link #ByteRTCMixedStreamAudioProfile}. Defaults to `0`. It's recommended to be set.
 */
@property(assign, nonatomic) ByteRTCMixedStreamAudioProfile audioProfile;

/**
 * 
 * @hidden
 * @deprecated
 */
+ (NSString* _Nonnull) toStringWithProfile:(ByteRTCMixedStreamAudioProfile) aacProfile;
@end


/**
 * 
 * @type keytype
 * @brief Spatial audio config when pushing to CDN.(New)
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCMixedStreamSpatialAudioConfig : NSObject

/**
 * 
 * @brief Whether to enable the spatial audio effect when pushing to CDN. <br>
 *        when you enable the feature, set the `spatialPosition` of each ByteRTCMixedStreamLayoutRegionConfig{@link #ByteRTCMixedStreamLayoutRegionConfig} for spatial audio effect.
 */
@property(assign, nonatomic) BOOL enableSpatialRender;

/**
 * 
 * @brief The spatial position of the audience. See ByteRTCPosition{@link #ByteRTCPosition}. <br>
 *        The audience is the users who receive the audio stream from CDN.
 */
@property (strong, nonatomic) ByteRTCPosition * _Nullable audienceSpatialPosition;

/**
 * 
 * @brief The orientation of the audience. See ByteRTCHumanOrientation{@link #ByteRTCHumanOrientation}. <br>
 *        The audience is the users who receive the audio stream from CDN.
 */
@property(strong, nonatomic) ByteRTCHumanOrientation * _Nullable audienceSpatialOrientation;

@end


/**
 * 
 * @type keytype
 * @brief Client mixing parameters.(New)
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCMixedStreamClientMixConfig : NSObject

/**
 * 
 * @brief Whether to use audio mixing. Default is true.
 */
@property(assign, nonatomic) BOOL useAudioMixer;

/**
 * 
 * @brief The video format to be set. See ByteRTCMixedStreamClientMixVideoFormat{@link #ByteRTCMixedStreamClientMixVideoFormat}.
 */
@property(assign, nonatomic) ByteRTCMixedStreamClientMixVideoFormat videoFormat;
@end


/**
 * 
 * @hidden internal use only
 * @valid since 3.52
 * @type keytype
 * @brief Mixed Stream sync control parameters.(New)
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCMixedStreamSyncControlConfig : NSObject

/**
 * 
 * @brief The sync strategy.
 */
@property(assign, nonatomic)ByteRTCMixedStreamSyncStrategy syncStrategy;

/**
 * 
 * @brief User ID of the base stream during syncing. Null by default.
 */
@property(copy, nonatomic) NSString * _Nullable baseUserID;

/**
 * 
 * @brief The max length of the cached stream in milliseconds. 2000 by default. <br>
 *        Set the value based on the stall of the media streams. Higher the value, bigger the memory usage. The recommended value is `2000`.
 */
@property(assign, nonatomic) NSInteger maxCacheTimeMs;

/**
 * 
 * @brief Whether to use RTC SDK to push to CDN. True by default. <br>
 *        If `False`, you can get the media frames by onCacheSyncVideo:withDataFrame:withUids:taskId:{@link #LiveTranscodingDelegate#onCacheSyncVideo:withDataFrame:withUids:taskId:} and manually push them to CDN.
 */
@property(assign, nonatomic) BOOL videoNeedSdkMix;
@end


/**
 * 
 * @type keytype
 * @brief Configurations to be set while mixing streams on the server side.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCMixedStreamServerControlConfig : NSObject

/**
 * 
 * @valid since 3.56
 * @brief Sets whether to enable the function of separately sending sound indication SEI: <br>
 *        - True: Enable.
 *        - False: Disable. Default setting.
 *        After setting this parameter to "true", you can choose whether to send sound indication SEI only through `ByteRTCMixedStreamServerControlConfig.seiContentMode`.
 */
@property(assign, nonatomic) BOOL enableVolumeIndication;

/**
 * 
 * @valid since 3.56
 * @brief Sound indication interval in s. The range is [0.3,+∞). The default value is 2. <br>
 *        If a decimal with two or more decimal places is passed in, it will be rounded to the value of the first decimal place. For example, if you pass in 0.36, it will be automatically adjusted to 0.4.
 */
@property(assign, nonatomic) CGFloat volumeIndicationInterval;

/**
 * 
 * @valid since 3.56
 * @brief Effective volume within the range of [0, 255]. The default value is 0. <br>
 *        If the value is set beyond the range, it will be automatically adjusted to the default value 0.
 */
@property(assign, nonatomic) NSInteger talkVolume;

/**
 * 
 * @valid since 3.56
 * @brief Sets whether volume value is contained in the sound indication SEI: <br>
 *        - True: Yes.
 *        - False: No. Default setting.
 */
@property(assign, nonatomic) BOOL isAddVolumeValue;

/**
 * 
 * @valid since 3.56
 * @brief Sets SEI content. See ByteRTCMixedStreamSEIContentMode{@link #ByteRTCMixedStreamSEIContentMode}.
 */
@property(assign, nonatomic) ByteRTCMixedStreamSEIContentMode seiContentMode;

/**
 * 
 * @valid since 3.56
 * @brief SEI payload type. <br>
 *        The default value is `100`, and the value supported is `5` and `100`. <br>
 *        During the process of pushing streams to CDN, you cannot change the parameter.
 */
@property(assign, nonatomic) NSInteger seiPayloadType;

/**
 * 
 * @valid since 3.56
 * @brief SEI payload UUID.
 * @note When PayloadType is `5`, you must set PayloadUUID, or you will receive a callback indicating parameter error. The error code is 1091. <br>
 *         When PayloadType is not `5`, it is not required to set PayloadUUID. If filled, it will be ignored by the backend. <br>
 *         The length of PayloadUUID should be 32 bits, or you will receive an error code of 1091. <br>
 *         Each character of the parameter should be within the range of [0, 9] [a, f] [A, F]. <br>
 *         The PayloadUUID should not contain `-`. If the automatically generated UUID contains `-`, you should delete it. <br>
 *         During the process of pushing streams to CDN, you cannot change the parameter.
 */
@property(copy, nonatomic) NSString *seiPayloadUUID;

/**
 * 
 * @valid since 3.57
 * @brief Sets the type of media stream pushed to CDN after being mixed. ByteRTCMixedStreamMediaType{@link #ByteRTCMixedStreamMediaType}. <br>
 *        The default value is 0，which means pushing both audio and video.
 */
@property(assign, nonatomic) ByteRTCMixedStreamMediaType mediaType;

/**
 * 
 * @valid since 3.57
 * @brief Sets whether to initiate a stream mixing task in the absence of any users publishing streams. See ByteRTCMixedStreamPushMode{@link #ByteRTCMixedStreamPushMode}. <br>
 *        Once the stream mixing task is initiated, this parameter can not be updated any more.
 */
@property(assign, nonatomic) ByteRTCMixedStreamPushMode pushStreamMode;
@end


/**
 * 
 * @type keytype
 * @brief Configurations to be set while pushing media streams to CDN.(New)
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCMixedStreamConfig : NSObject

/**
 * 
 * @brief Stream mixing type. See ByteRTCMixedStreamType{@link #ByteRTCMixedStreamType}. It's recommended to be set.
 */
@property(assign, nonatomic) ByteRTCMixedStreamType expectedMixingType;

/**
 * 
 * @brief The overall video layout of the mixed stream. <br>
 *        After starting to push streams to CDN, you can set the layout of each video stream, the background information of the mixed stream, etc. See ByteRTCMixedStreamLayoutConfig{@link #ByteRTCMixedStreamLayoutConfig} for details.
 */
@property(strong, nonatomic) ByteRTCMixedStreamLayoutConfig * _Nonnull layoutConfig;

/**
 * 
 * @brief Video transcoding related configurations. See ByteRTCMixedStreamVideoConfig{@link #ByteRTCMixedStreamVideoConfig}. It's recommended to be set.
 */
@property(strong, nonatomic) ByteRTCMixedStreamVideoConfig * _Nonnull videoConfig;

/**
 * 
 * @brief Audio mixed related configurations. See ByteRTCMixedStreamAudioConfig{@link #ByteRTCMixedStreamAudioConfig} for data types. It's recommended to be set.
 */
@property(strong, nonatomic) ByteRTCMixedStreamAudioConfig * _Nonnull audioConfig;

/**
 * 
 * @brief client mix param. See ByteRTCMixedStreamClientMixConfig{@link #ByteRTCMixedStreamClientMixConfig} for detail. It's recommended to be set.
 */
@property(strong, nonatomic) ByteRTCMixedStreamClientMixConfig * _Nullable clientMixConfig;

/**
 * 
 * @hidden for internal use only
 * @brief client mix param. See ByteRTCMixedStreamSyncControlConfig{@link #ByteRTCMixedStreamSyncControlConfig} for detail.
 */
@property(strong, nonatomic) ByteRTCMixedStreamSyncControlConfig * _Nullable syncControlConfig;

/**
 * 
 * @hidden(macOS)
 * @brief The spatial audio config when pushing to CDN. See ByteRTCMixedStreamSpatialAudioConfig{@link #ByteRTCMixedStreamSpatialAudioConfig} for detail.
 */
@property(strong, nonatomic) ByteRTCMixedStreamSpatialAudioConfig * _Nonnull spatialAudioConfig;

/**
 * 
 * @brief Server mix Control config. See ByteRTCMixedStreamServerControlConfig{@link #ByteRTCMixedStreamServerControlConfig} for detail.
 */
@property(strong, nonatomic) ByteRTCMixedStreamServerControlConfig * _Nonnull serverControlConfig;

/**
 * 
 * @hidden for internal use only
 * @brief Custom parameter
 */
@property(strong, nonatomic) NSMutableDictionary *  _Nullable advancedConfig;

/**
 * 
 * @hidden for internal use only
 * @brief Authentication information passed through from the App
 */
@property(strong, nonatomic) NSMutableDictionary *  _Nullable authInfo;

/**
 * 
 * @brief The URL for live transcoding. Only supports live transcoding via RTMP. The URL should match the regular expression `/^rtmps?:\/\
 *        This parameter cannot be updated while pushing stream to the CDN.
 */
@property(copy, nonatomic) NSString * _Nullable pushURL;

/**
 * 
 * @brief The room ID for live transcoding. The sum length of `roomID` and `userID` should not exceed 126 bytes. It's recommended to be set. <br>
 *        This parameter cannot be updated while pushing stream to the CDN.
 */
@property(copy, nonatomic) NSString * _Nonnull roomID;

/**
 * 
 * @brief The user ID for live transcoding. The sum length of `roomID` and `userID` should not exceed 126 bytes. It's recommended to be set. <br>
 *        This parameter cannot be updated while pushing stream to the CDN.
 */
@property(copy, nonatomic) NSString * _Nonnull userID;

/**
 * 
 * @brief Gets the default configurations for pushing streams to CDN.
 * @return Configurations for pushing streams to CDN. See ByteRTCMixedStreamConfig{@link #ByteRTCMixedStreamConfig}.
 */
+ (instancetype _Nonnull)defaultMixedStreamConfig;
@end

BYTERTC_APPLE_EXPORT  @interface DestInfo: NSObject
    
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


typedef NS_ENUM(NSUInteger, ByteRTCSingleStreamPushType) {
    ByteRTCSingleStreamPushToCDN = 1,
    ByteRTCSingleStreamPushToRTC = 2
};

/**
 * 
 * @type keytype
 * @brief Configurations for pushing a single media stream to CDN.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCPushSingleStreamParam : NSObject

/**
 * 
 * @brief The URL for live transcoding. Only supports live transcoding via RTMP. The URL should match the regular expression `/^rtmps?:\/\
 *        This parameter cannot be updated while pushing stream to the CDN.
 */
@property(copy, nonatomic) NSString * _Nullable url;

/**
 * 
 * @brief The room ID of the media stream
 */
@property(copy, nonatomic) NSString * _Nonnull roomId;

/**
 * 
 * @brief The user ID of the media stream
 */
@property(copy, nonatomic) NSString * _Nullable userId;

/**
 * 
 * @brief Whether the media stream is a screen-sharing stream.
 */
@property(nonatomic, assign) BOOL isScreen;

@property(nonatomic, strong) NSArray<DestInfo *> * _Nullable destInfo;

@property(assign, nonatomic) ByteRTCSingleStreamPushType pushType;
@end


/**
 * 
 * @type keytype
 * @brief  Video subscription configuration information
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCSubscribeVideoConfig : NSObject

/**
 * 
 * @brief Subscribed video stream resolution subscript. <br>
 *        Quality level of the video stream subscribed to. <br>
 *        In Simulcast mode, use a number to specify the expected quality of the video stream to be subscribed to.  In Simulcast mode, a video has a diversity of encoded qualities that ranking from 0 to 3. Call enableSimulcastMode:{@link #ByteRTCVideo#enableSimulcastMode:} to enable Simulcast mode on the publisher's clients. <br>
 *         Ranging from -1 to 3 <br>
 *         0 (Default): The best quality <br>
 *         -1: Use the previous settings.
 */
@property(assign, nonatomic) NSInteger videoIndex;

/**
 * 
 * @brief Remote user priority. See ByteRTCRemoteUserPriority{@link #ByteRTCRemoteUserPriority}, the default value is 0.
 */
@property(assign, nonatomic) NSInteger priority;
@end


/**
 * 
 * @type keytype
 * @brief  Performance fallback related data
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCSourceWantedData : NSObject

/**
 * 
 * @brief Recommended video input width
 */
@property(nonatomic, assign) NSInteger width;

/**
 * 
 * @brief Recommended video input high
 */
@property(nonatomic, assign) NSInteger height;

/**
 * 
 * @brief Recommended video input frame rate
 */
@property(nonatomic, assign) NSInteger frameRate;
@end


/**
 * 
 * @type keytype
 * @brief Information of stream switching due to a Fallback
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCRemoteStreamSwitchEvent : NSObject

/**
 * 
 * @brief User ID of the publisher of the subscribed media stream
 */
@property(nonatomic, copy) NSString * _Nonnull uid;

/**
 * 
 * @brief Whether it is a screen-sharing stream
 */
@property(nonatomic, assign) BOOL isScreen;

/**
 * 
 * @brief The quality index of the subscribed stream before the stream switching
 */
@property(nonatomic, assign) NSInteger beforeVideoIndex;

/**
 * 
 * @brief The quality index of the subscribed stream after the stream switching
 */
@property(nonatomic, assign) NSInteger afterVideoIndex;

/**
 * 
 * @brief Whether a video stream before the stream switching
 */
@property(nonatomic, assign) BOOL beforeVideoEnabled;

/**
 * 
 * @brief Whether a video stream after the stream switching
 */
@property(nonatomic, assign) BOOL afterVideoEnabled;

/**
 * 
 * @brief Refer to ByteRTCFallbackOrRecoverReason{@link #ByteRTCFallbackOrRecoverReason} for the reason of the Fallback or reverting from the Fallback of the subscribed stream.
 */
@property(nonatomic, assign) ByteRTCFallbackOrRecoverReason reason;
@end


/**
 * 
 * @hidden
 * @deprecated since 3.45 and will be deleted in 3.51, use ByteRTCVideoSinkDelegate{@link #ByteRTCVideoSinkDelegate} instead.
 * @type callback
 * @brief Custom video rendering
 */
DEPRECATED_MSG_ATTRIBUTE("Please use ByteRTCVideoSinkDelegate")
BYTERTC_APPLE_EXPORT @protocol ByteRTCVideoSinkProtocol <NSObject>
@required

/**
 * 
 * @type callback
 * @brief Initialize the renderer
 * @return
 *          - YES: Custom renderer initialization completed
 *          - NO: Custom renderer initialization failed, do not continue to run
 * @note Initialize the renderer when this method will be called back
 */
- (BOOL)shouldInitialize DEPRECATED_MSG_ATTRIBUTE("Please use ByteRTCVideoSinkDelegate");;


/**
 * 
 * @type callback
 * @brief Start the renderer
 * @note This method will be called back when the rendering function is turned on
 */
- (void)shouldStart DEPRECATED_MSG_ATTRIBUTE("Please use ByteRTCVideoSinkDelegate");


/**
 * 
 * @type callback
 * @brief Stop the renderer
 * @note This method will be called back when the rendering function is stopped
 */
- (void)shouldStop DEPRECATED_MSG_ATTRIBUTE("Please use ByteRTCVideoSinkDelegate");


/**
 * 
 * @type callback
 * @brief Release the renderer
 * @note This method will be called back when the renderer is about to be abandoned
 */
- (void)shouldDispose DEPRECATED_MSG_ATTRIBUTE("Please use ByteRTCVideoSinkDelegate");


/**
 * 
 * @type callback
 * @brief  Gets the PixelFormat format
 * @return Buffer  type, {@link #ByteRTCVideoSinkPixelFormat}
 * @note  Tells SDK the format of PixelFormat through the return value of this method
 */
- (ByteRTCVideoPixelFormat)pixelFormat DEPRECATED_MSG_ATTRIBUTE("Please use ByteRTCVideoSinkDelegate");


/**
 * 
 * @type callback
 * @brief Output video PixelBuffer
 * @param pixelBuffer Video PixelBuffer
 * @param rotation Video rotation angle, {@link #ByteRTCVideoRotation}
 * @param cameraId Video camera id, {@link #ByteRTCCameraID}
 * @param extendedData Video frame additional data, additional data obtained after video decoding
 * @note Get video PixelBuffer through this method
 */
- (void)renderPixelBuffer:(CVPixelBufferRef _Nonnull)pixelBuffer
                 rotation:(ByteRTCVideoRotation)rotation
                 cameraId:(ByteRTCCameraID) cameraId
             extendedData:(NSData * _Nullable)extendedData DEPRECATED_MSG_ATTRIBUTE("Please use ByteRTCVideoSinkDelegate");


/**
 * 
 * @hidden constructor/destructor
 */
- (int)getRenderElapse;
@end


/**
 * 
 * @type keytype
 * @brief Custom video renderer
 */
BYTERTC_APPLE_EXPORT @protocol ByteRTCVideoSinkDelegate <NSObject>
@optional

/**
 * 
 * @deprecated since 3.54, use onFrame: instead
 * @type api
 * @brief Outputs video PixelBuffer
 * @param pixelBuffer Video PixelBuffer
 * @param rotation Video rotation angle. See ByteRTCVideoRotation{@link #ByteRTCVideoRotation}
 * @param contentType Video content type. See ByteRTCVideoContentType{@link #ByteRTCVideoContentType}
 * @param extendedData Additional data obtained after video is decoded.
 */
- (void)renderPixelBuffer:(CVPixelBufferRef _Nonnull)pixelBuffer
                 rotation:(ByteRTCVideoRotation)rotation
                 contentType:(ByteRTCVideoContentType)contentType
             extendedData:(NSData * _Nullable)extendedData;

/**
 * 
 * @hidden for internal use only
 */
- (int)getRenderElapse;

@required

/**
 * 
 * @type api
 * @brief Outputs video PixelBuffer
 * @param videoFrame video frame
 */
- (void)onFrame:(ByteRTCVideoFrame * _Nonnull)videoFrame;

@end


/**
 * 
 * @hidden for internal use only
 * @type callback
 * @brief Consumption interface for external rendering data
 */
@protocol ByteRTCVideoFrameConsumerObserver <NSObject>

/**
 * 
 * @brief Output yuv420 data
 * @param ocFrame  Data Buffer
 * @param width  Video width
 * @param rotation  Video rotation angle
 * @param timestamp  Timestamp
 */
- (void)consumeYUV420Buffer:(CVPixelBufferRef _Nullable)ocFrame
    width:(NSInteger)width rotation:(NSInteger)rotation timestamp:(long)timestamp;

/**
 * 
 * @brief Output RGBA data
 * @param ocFrame Data Buffer
 * @param width Video width
 * @param rotation Video rotation angle
 * @param timestamp Timestamp
 */
- (void)consumeRGBABuffer:(CVPixelBufferRef _Nullable)ocFrame width:(NSInteger)width
    rotation:(NSInteger)rotation timestamp:(long)timestamp;
@end


/**
 * 
 * @hidden
 * @deprecated
 * @type callback
 * @region  Video Management
 */
BYTERTC_APPLE_EXPORT @protocol ByteRTCVideoFrameObserver <NSObject>

/**
 * 
 * @brief Callback of video frame data for local screen stream
 * @param frame Local screen video frame data, reference: ByteRTCVideoFrame{@link #ByteRTCVideoFrame}
 */
- (void)onLocalScreenFrame:(ByteRTCVideoFrame * _Nonnull)frame;

/**
 * 
 * @brief Callback of video frame data for local video stream
 * @param frame Video frame data for local video stream, reference: ByteRTCVideoFrame{@link #ByteRTCVideoFrame}
 */
- (void)onLocalVideoFrame:(ByteRTCVideoFrame * _Nonnull)frame;


/**
 * 
 * @brief Video frame data callback for the remote screen stream
 * @param frame Video frame data for the remote screen, reference: ByteRTCVideoFrame{@link #ByteRTCVideoFrame}
 * @param uid Remote screen sharing user ID
 * @param room Room id for the corresponding stream
 */
- (void)onRemoteScreenFrame:(ByteRTCVideoFrame * _Nonnull)frame user:(NSString * _Nullable)uid
    room:(NSString * _Nullable)room;

/**
 * 
 * @brief Callback of video frame data of remote video stream
 * @param frame Video frame data of remote video stream, reference: ByteRTCVideoFrame{@link #ByteRTCVideoFrame}
 * @param uid Remote screen sharing user ID
 * @param room Room id of corresponding stream
 */
- (void)onRemoteVideoFrame:(ByteRTCVideoFrame * _Nonnull)frame user:(NSString * _Nullable)uid
    room:(NSString * _Nullable)room;



/**
 * 
 * @hidden for internal use only
 */
- (void)OnMergeFrame:(ByteRTCVideoFrame * _Nonnull)frame user:(NSString * _Nullable)uid room:(NSString * _Nullable)room;

@end


/**
 * 
 * @type keytype
 * @brief Local video frame callback config.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCLocalVideoSinkConfig : NSObject

/**
 * 
 * @brief The position of the local video frame. See ByteRTCLocalVideoRenderPosition{@link #ByteRTCLocalVideoRenderPosition}.
 */
@property(nonatomic, assign) ByteRTCLocalVideoRenderPosition position;

/**
 * 
 * @brief The pixel format of the local video frame. See ByteRTCVideoSinkPixelFormat{@link #ByteRTCVideoSinkPixelFormat}. The default value is 0.
 */
@property(nonatomic, assign) ByteRTCVideoSinkPixelFormat requiredPixelFormat;

@end


/**
 * 
 * @type keytype
 * @brief Remote video frame callback configurations.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCRemoteVideoSinkConfig : NSObject

/**
 * 
 * @brief The position of the remote video frame. See ByteRTCLocalVideoRenderPosition{@link #ByteRTCLocalVideoRenderPosition}. The default position is after processing.
 */
@property(nonatomic, assign) ByteRTCRemoteVideoRenderPosition position;

/**
 * 
 * @brief The pixel format of the remote video frame. See ByteRTCVideoSinkPixelFormat{@link #ByteRTCVideoSinkPixelFormat}. The default value is 0.
 */
@property(nonatomic, assign) ByteRTCVideoSinkPixelFormat requiredPixelFormat;

/**
 * 
 * @brief Whether the video frame needs to be automatically rotate. See ByteRTCVideoApplyRotation{@link #ByteRTCVideoApplyRotation}. The default value is no rotate.
 */
@property(nonatomic, assign) ByteRTCVideoApplyRotation applyRotation;

/**
 * 
 * @brief Whether the video frame needs to be mirrored. See ByteRTCVideoRenderMirrorType{@link #ByteRTCVideoRenderMirrorType}. The default value is no mirroring effect. <br>
 *        This setting is independent of setRemoteVideoMirrorType:withMirrorType:{@link #ByteRTCVideo#setRemoteVideoMirrorType:withMirrorType:} (which is applicable for internal rendering).
 */
@property(nonatomic, assign) ByteRTCVideoRenderMirrorType mirrorType;

@end


/**
 * 
 * @type keytype
 * @brief Video processing configuration parameters
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCVideoPreprocessorConfig : NSObject

/**
 * 
 * @brief For the pixel format of the video frame. See ByteRTCVideoPixelFormat{@link #ByteRTCVideoPixelFormat}. <br>
 *        Only `ByteRTCVideoPixelFormatI420` and `ByteRTCVideoPixelFormatUnknown` are supported.
 */
@property(nonatomic, assign) ByteRTCVideoPixelFormat requiredPixelFormat;

@end


 /**
  * 
  * @type callback
  * @region  video processing
  * @brief video processing callback interface <br>
  * Note: Callback functions are thrown synchronously in a non-UI thread within the SDK. Therefore, you must not perform any time-consuming operations or direct UI operations within the callback function, as this may cause the app to crash.
  */
BYTERTC_APPLE_EXPORT @protocol ByteRTCVideoProcessorDelegate <NSObject>


/**
 * 
 * @type api
 * @region  video processing
 * @brief  Get RTC SDK acquired video frames, according to registerLocalVideoProcessor:withConfig:{@link #ByteRTCVideo#registerLocalVideoProcessor:withConfig:} set the video preprocessor, video preprocessing, and finally the processed video frames to the RTC SDK for encoding transmission.
 * @param srcFrame RTC SDK captured video frames, reference: ByteRTCVideoFrame{@link #ByteRTCVideoFrame}
 * @return  After video preprocessing video frames, returned to the RTC SDK for encoding and transmission, reference: ByteRTCVideoFrame{@link #ByteRTCVideoFrame}
 * @note  If you need to cancel the video preprocessing, you can set the video preprocessor to nullptr.
 */
- (ByteRTCVideoFrame* _Nullable)processVideoFrame:(ByteRTCVideoFrame* _Nonnull)srcFrame;

@end

/**
 * 
 * @hidden(iOS)
 * @type keytype
 * @brief Screen capture settings
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCScreenCaptureParam : NSObject

/**
 * 
 * @brief The maximum width of the captured screen, measured in pixel.
 */
@property(nonatomic, assign) NSInteger width;

/**
 * 
 * @brief The maximum height of the captured screen, measured in pixel.
 */
@property(nonatomic, assign) NSInteger height;

/**
 * 
 * @brief Screen capture frame rate in fps
 */
@property(nonatomic, assign) NSInteger frameRate;

/**
 * 
 * @brief Screen capture bitrate rate in kbps
 */
@property(nonatomic, assign) NSInteger bitrate;

/**
 * 
 * @brief Minimum video encoding bitrate in kbps. The encoding bitrate will not be lower than the `minBitrate`. <br>
 *        It defaults to `0`. <br>
 *        It ranges within [0, bitrate). When `bitrate` < `minBitrate`, the bitrate is self-adpapted. <br>
 *        In the following circumstance, the assignment to this variable has no effect: <br>
 *        - When `bitrate` = `0`, the video encoding is disabled.
 *        - When `bitrate` < `0`, the bitrate is self-adapted.
 */
@property(nonatomic, assign) NSInteger minBitrate;

/**
 * 
 * @brief Screen capture area.
 */
@property(nonatomic, assign) CGRect regionRect;

/**
 * 
 * @brief Whether to capture the mouse
 */
@property(nonatomic, assign) ByteRTCMouseCursorCaptureState mouseCursorCaptureState;

/**
 * 
 * @brief The list of excluded windows.
 */
@property (strong, nonatomic) NSArray<NSNumber *> * _Nullable excludedWindowList;

/**
 * 
 * @brief Settings for highlighting borders of the sharing region. See ByteRTCHighlightConfig{@link #ByteRTCHighlightConfig}.
 */
@property (strong, nonatomic) ByteRTCHighlightConfig * _Nonnull highlightConfig;
@end

/**
 * 
 * @type keytype
 * @brief Screen capture object information
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCScreenCaptureSourceInfo : NSObject

/**
 * 
 * @brief The type of the sharing screen. See ByteRTCScreenCaptureSourceType{@link #ByteRTCScreenCaptureSourceType}.
 */
@property (assign, nonatomic) ByteRTCScreenCaptureSourceType sourceType;

/**
 * 
 * @brief ID of the sharing object
 */
@property (assign, nonatomic) intptr_t sourceId;

/**
 * 
 * @brief Name of the sharing screen
 */
@property (copy, nonatomic) NSString * _Nullable sourceName;

/**
 * 
 * @brief The title of the application to be shared. <br>
 *        Only available if the sharing object is an application widnows.
 */
@property (copy, nonatomic) NSString * _Nullable application;

 /**
 * 
 * @brief Process pid of the application to be shared. <br>
 *        Only available if the sharing object is an application windows.
 */
@property (assign, nonatomic) int pid;

 /**
 * 
 * @brief Tag for the screen to be shared identifying whether it is the primary screen <br>
 *        Only available when the screen-sharing object is a screen.
 */
@property (assign, nonatomic) BOOL primaryMonitor;

/**
 * 
 * @brief Coordinate of the screen-sharing object. (0, 0), the origin is the top left on the main screen for clients with multiple screens.
 */
@property (assign, nonatomic) CGRect regionRect;

@end


/**
 * 
 * @type keytype
 * @region  video management
 * @brief  Screen capture setting parameters
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCScreenParam : NSObject

/**
 * 
 * @brief Encoded frame rate in fps
 */
@property(nonatomic, assign) NSInteger frameRate;

/**
 * 
 * @brief Encoding rate, when less than 0, the SDK will be based on the high and wide self-adaptation rate, in kbps
 */
@property(nonatomic, assign) NSInteger bitrate;
@end


/**
 * 
 * @type keytype
 * @brief Virtual background object
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCVirtualBackgroundSource: NSObject

/**
 * 
 * @brief See ByteRTCVirtualBackgroundSourceType{@link #ByteRTCVirtualBackgroundSourceType} 。
 */
@property(nonatomic, assign) ByteRTCVirtualBackgroundSourceType sourceType;

/**
 * 
 * @brief The solid color of the background. <br>
 *        The format is 0xAARRGGBB.
 */
@property int sourceColor;

/**
 * 
 * @brief The absolute path of the specified image. <br>
 *       - You can upload a .JPG, .PNG, or .JPEG file.
 *       - The image with a resolution higher than 1080p(Full HD) will be rescaled proportionally to fit in the video.
 *       - If the image's aspect ratio matches the video's, the image will be rescaled proportionally to fit in the video.
 *       - If the image’s aspect ratio doesn't match the video's, the shortest side (either height or width) of the image will be stretched proportionally to match the video. Then the image will be cropped to fill in the video.
 *       - The transparent area in the image will be filled with black.
 */
@property(nonatomic) NSString* _Nullable sourcePath;
@end


/**
 * 
 * @type callback
 * @region Video Data Callback
 * @brief Local video frame observer <br>
 * Note: Callback functions are thrown synchronously in a non-UI thread within the SDK. Therefore, you must not perform any time-consuming operations or direct UI operations within the callback function, as this may cause the app to crash.
 */
BYTERTC_APPLE_EXPORT @protocol ByteRTCLocalEncodedVideoFrameObserver<NSObject>
 @optional

/**
 * 
 * @type callback
 * @region Video Data Callback
 * @brief After calling registerLocalEncodedVideoFrameObserver:{@link #ByteRTCVideo#registerLocalEncodedVideoFrameObserver:}, SDK will trigger this callback when it receives local video frames.
 * @param streamIndex Type of the local video frame. See ByteRTCStreamIndex{@link #ByteRTCStreamIndex}.
 * @param frame Information about the local video frame. See ByteRTCEncodedVideoFrame{@link #ByteRTCEncodedVideoFrame}.
 */
- (void)onLocalEncodedVideoFrame:(ByteRTCStreamIndex) streamIndex
    Frame:(ByteRTCEncodedVideoFrame * _Null_unspecified)frame;
@end

#pragma mark - ByteRTCEngineExternalVideoEncoderEventHandler


/**
 * 
 * @type callback
 * @brief  Custom coded frame callback class. <br>
 * Note: Callback functions are thrown synchronously in a non-UI thread within the SDK. Therefore, you must not perform any time-consuming operations or direct UI operations within the callback function, as this may cause the app to crash.
 */
BYTERTC_APPLE_EXPORT @protocol ByteRTCExternalVideoEncoderEventHandler<NSObject>
@required

/**
 * 
 * @type callback
 * @region Video management
 * @brief Prompt custom encoded frames to start pushing callbacks. <br>
 *         After receiving this callback, you can call pushExternalEncodedVideoFrame:withVideoIndex:withEncodedVideoFrame:{@link #ByteRTCVideo#pushExternalEncodedVideoFrame:withVideoIndex:withEncodedVideoFrame:} Push custom encoded video frames to the SDK
 * @param streamIndex  Properties of the encoded stream that can be pushed. See ByteRTCStreamIndex{@link #ByteRTCStreamIndex}
 */
- (void)onStart:(ByteRTCStreamIndex)streamIndex;
@required

/**
 * 
 * @type callback
 * @region Video management
 * @brief When receiving the callback, you need to stop pushing custom encoded video frames to the SDK
 * @param streamIndex The properties of the encoded stream that need to stop pushing. See ByteRTCStreamIndex{@link #ByteRTCStreamIndex}
 */
- (void)onStop:(ByteRTCStreamIndex)streamIndex;
@required

/**
 * 
 * @type callback
 * @region Video management
 * @brief When the frame rate or bit rate of a custom encoded stream changes, the callback is triggered
 * @param streamIndex The properties of the changed encoded stream. See ByteRTCStreamIndex{@link #ByteRTCStreamIndex}
 * @param videoIndex Corresponding to the subscript of the encoded stream
 * @param fps Changed frame rate, unit: fps
 * @param bitRateKps Changed bit rate, unit: kbps
 */
- (void)onRateUpdate:(ByteRTCStreamIndex)streamIndex
      withVideoIndex:(NSInteger)videoIndex
             withFps:(NSInteger)fps
         withBitRate:(NSInteger)bitRateKps;
@required

/**
 * 
 * @type callback
 * @region Video management
 * @brief This callback is used to inform the stream publisher that a keyframe needs to be regenerated.
 * @param streamIndex Properties of the remote encoded stream. See ByteRTCStreamIndex{@link #ByteRTCStreamIndex}
 * @param videoIndex The subscript of the corresponding encoded stream
 */
- (void)onRequestKeyFrame:(ByteRTCStreamIndex)streamIndex
           withVideoIndex:(NSInteger)videoIndex;
@required

/**
 * 
 * @valid since 3.56
 * @type callback
 * @brief As the sender of a external encoded video stream, you will receive this callback at certain moments. <br>
 *        Based on the hints of this callback, you can selectively encode the video stream that is ready for transmission, in order to reduce the performance impact of video encoding on the local device. This callback is triggered based on a combination of factors, including  the performance of the local device, the local network, and whether the stream is subscribed by the remote user.
 * @param streamIndex See ByteRTCStreamIndex{@link #ByteRTCStreamIndex}.
 * @param videoIndex Subscript of the corresponding encoded stream.
 * @param active The active state of the corresponding encoded stream.
 * @note To receive the callback, call setVideoSourceType:WithStreamIndex:{@link #ByteRTCVideo#setVideoSourceType:WithStreamIndex:} to set the input video source to custom encoded video and call setExternalVideoEncoderEventHandler:{@link #ByteRTCVideo#setExternalVideoEncoderEventHandler:} to set the callback handler.
 */
- (void)onActiveVideoLayer:(ByteRTCStreamIndex)streamIndex
            withVideoIndex:(NSInteger)videoIndex
                withActive:(BOOL)active;
@end

#pragma mark - ByteRTCEngineRemoteEncodedVideoFrameObserver


/**
 * 
 * @type callback
 * @region  video management
 * @brief  Custom coded frame callback class. <br>
 * Note: Callback functions are thrown synchronously in a non-UI thread within the SDK. Therefore, you must not perform any time-consuming operations or direct UI operations within the callback function, as this may cause the app to crash.
 */
BYTERTC_APPLE_EXPORT @protocol ByteRTCRemoteEncodedVideoFrameObserver<NSObject>
@required

/**
 * 
 * @type callback
 * @region Video data callback
 * @brief Call registerRemoteEncodedVideoFrameObserver:{@link #ByteRTCVideo#registerRemoteEncodedVideoFrameObserver:} After the SDK detects the remote encoded video data, the callback is triggered
 * @param streamKey Received remote stream information. See ByteRTCRemoteStreamKey{@link #ByteRTCRemoteStreamKey}
 * @param videoFrame Received remote video frame information. See ByteRTCEncodedVideoFrame{@link #ByteRTCEncodedVideoFrame}
 */
- (void)onRemoteEncodedVideoFrame:(ByteRTCRemoteStreamKey * _Nonnull)streamKey
                   withEncodedVideoFrame:(ByteRTCEncodedVideoFrame* _Nonnull)videoFrame;
@end


/**
 * 
 * @type keytype
 * @brief  Video frame basic information
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCVideoFrameInfo : NSObject

/**
 * 
 * @brief Width of video frame (pixels)
 */
@property(nonatomic, assign) NSInteger width;

/**
 * 
 * @brief Height of video frame (pixels)
 */
@property(nonatomic, assign) NSInteger height;

/**
 * 
 * @brief Video frame clockwise rotation angle. See ByteRTCVideoRotation{@link #ByteRTCVideoRotation}.
 */
@property(nonatomic, assign) ByteRTCVideoRotation rotation;
@end

#pragma mark - LiveTranscodingDelegate


/**
 * 
 * @deprecated since 3.52, use ByteRTCMixedStreamObserver{@link #ByteRTCMixedStreamObserver} instead.
 * @type callback
 * @region Push to CDN
 * @brief Register this observer to receive stream mixing related callbacks from the SDK. <br>
 * Note: Callback functions are thrown synchronously in a non-UI thread within the SDK. Therefore, you must not perform any time-consuming operations or direct UI operations within the callback function, as this may cause the app to crash.
 */
@protocol LiveTranscodingDelegate <NSObject>

/**
 * 
 * @type callback
 * @region Push to CDN
 * @brief Whether your App has the ability to push streams to CDN: <br>
 *        - true: Yes
 *        - false: No (default value)
 * @note If you need to use the function of intelligently pushing streams to CDN, you should ensure that your App contains librtmp and has the ability to push streams out. If so, set the callback to True.
 */
 - (BOOL)isSupportClientPushStream;

/**
 * 
 * @type callback
 * @region Push to CDN
 * @brief Used for reporting events during pushing streams to CDN
 * @param event Stream mixing and pushing status, see ByteRTCStreamMixingEvent{@link #ByteRTCStreamMixingEvent}.
 * @param taskId Task ID.
 * @param Code Errors occuring during the pushing process. See ByteRtcTranscoderErrorCode{@link #ByteRtcTranscoderErrorCode}.
 * @param mixType Stream mixing and pushing type. See ByteRTCStreamMixingType{@link #ByteRTCStreamMixingType}.
 */
 - (void)onStreamMixingEvent:(ByteRTCStreamMixingEvent)event
                  taskId:(NSString *_Nonnull)taskId
                      error:(ByteRtcTranscoderErrorCode)Code
                    mixType:(ByteRTCStreamMixingType)mixType;

@optional

/**
 * 
 * @type callback
 * @region Push to CDN
 * @brief Callback with audio data in PCM after intelligent stream mixing.
 * @param audioFrame Audio data frame in PCM. See ByteRTCAudioFrame{@link #ByteRTCAudioFrame}.
 * @param timeStamp The timeStamp in ms.
 * @param taskId Task ID.
 * @note You will receive the callback every 10 milliseconds. Each callback carries data collected in the last 10 milliseconds.
 */
- (void)onMixingAudioFrame:(ByteRTCAudioFrame *_Nonnull)audioFrame timestamp:(int64_t)timeStamp taskId:(NSString *_Nonnull)taskId;


/**
 * 
 * @type callback
 * @region Push to CDN
 * @brief Callback with video data in YUV after intelligent stream mixing.
 * @param videoFrame Video data frame in YUV, see ByteRTCVideoFrame{@link #ByteRTCVideoFrame}.
 * @param taskId Task ID.
 * @note The interval between callbacks is the same with that between video frames.
 */
- (void)onMixingVideoFrame:(ByteRTCVideoFrame *_Nonnull)videoFrame taskId:(NSString *_Nonnull)taskId;

/**
 * 
 * @type callback
 * @region Push to CDN
 * @brief This callback carries SEI data
 * @param dataFrame SEI Data. See ByteRTCFrameExtendedData{@link #ByteRTCFrameExtendedData}
 * @param taskId Task ID.
 */
- (void)onMixingDataFrame:(ByteRTCFrameExtendedData *_Nonnull)dataFrame taskId:(NSString *_Nonnull)taskId;

/**
 * 
 * @hidden for internal use only
 * @type callback
 * @valid since 3.50
 * @brief Synchronized video frame callback. Receive this callback when you enable simplex chorus mode by setting ByteRTCTranscodingSyncControlParam{@link #ByteRTCTranscodingSyncControlParam} and `syncClientVideoNeedMix=False`.
 * @param videoFrame Array of synchronized video frames. See ByteRTCVideoFrame{@link #ByteRTCVideoFrame}.
 * @param dataFrame SEI data. See ByteRTCFrameExtendedData{@link #ByteRTCFrameExtendedData}.
 * @param uids Array of uids corresponding to the video frames.
 * @param taskID Task ID.
 */
- (void)onCacheSyncVideo:(NSArray<ByteRTCVideoFrame *> *_Nonnull)videoFrames
           withDataFrame:(NSArray<ByteRTCFrameExtendedData*> *_Nonnull)dataFrames
                withUids:(NSArray<NSString*>*_Nonnull)uids
                  taskId:(NSString *_Nonnull)taskID;
@end

#pragma mark - ByteRTCPushMixedStreamToCDNObserver


/**
 * 
 * @type callback
 * @region Push to CDN
 * @brief Register this observer to receive stream mixing related callbacks from the SDK. (Valid from 352.1) <br>
 * Note: Callback functions are thrown synchronously in a non-UI thread within the SDK. Therefore, you must not perform any time-consuming operations or direct UI operations within the callback function, as this may cause the app to crash.
 */
@protocol ByteRTCMixedStreamObserver <NSObject>

/**
 * 
 * @type callback
 * @region Push to CDN
 * @brief Whether your App has the ability to push streams to CDN: <br>
 *        - True: Yes
 *        - False: No (default value)
 * @note
 *          - If you need to use the function of intelligently pushing streams to CDN, you should ensure that your App contains librtmp and has the ability to push streams out. If so, set the callback to True.
 */
 - (BOOL)isSupportClientPushStream;

/**
 * 
 * @type callback
 * @region Push to CDN
 * @brief Used for reporting events during pushing streams to CDN
 * @param event Stream mixing and pushing status, see ByteRTCStreamMixingEvent{@link #ByteRTCStreamMixingEvent}.
 * @param taskId Task ID.
 * @param errorCode Errors occuring during the pushing process. See ByteRTCStreamMixingErrorCode{@link #ByteRTCStreamMixingErrorCode} and ByteRTCStreamMixingErrorCode{@link #ByteRTCStreamMixingErrorCode}.
 * @param mixType Stream mixing and pushing type. See ByteRTCMixedStreamType{@link #ByteRTCMixedStreamType}.
 */
 - (void)onMixingEvent:(ByteRTCStreamMixingEvent)event
                  taskId:(NSString *_Nonnull)taskId
                      error:(ByteRTCStreamMixingErrorCode)errorCode
                    mixType:(ByteRTCMixedStreamType)mixType;

@optional

/**
 * 
 * @type callback
 * @region Push to CDN
 * @brief Callback with audio data in PCM after intelligent stream mixing.
 * @param audioFrame Audio data frame in PCM. See ByteRTCAudioFrame{@link #ByteRTCAudioFrame}.
 * @param timeStamp The timeStamp in ms.
 * @param taskId Task ID.
 * @note You will receive the callback every 10 milliseconds. Each callback carries data collected in the last 10 milliseconds.
 */
- (void)onMixingAudioFrame:(ByteRTCAudioFrame *_Nonnull)audioFrame timestamp:(int64_t)timeStamp taskId:(NSString *_Nonnull)taskId;


/**
 * 
 * @type callback
 * @region Push to CDN
 * @brief Callback with video data in YUV after intelligent stream mixing.
 * @param videoFrame Video data frame in YUV, see ByteRTCVideoFrame{@link #ByteRTCVideoFrame}.
 * @param taskId Task ID.
 * @note The interval between callbacks is the same with that between video frames.
 */
- (void)onMixingVideoFrame:(ByteRTCVideoFrame *_Nonnull)videoFrame taskId:(NSString *_Nonnull)taskId;

/**
 * 
 * @type callback
 * @region Push to CDN
 * @brief This callback carries SEI data
 * @param dataFrame SEI Data. See ByteRTCFrameExtendedData{@link #ByteRTCFrameExtendedData}
 * @param taskId Task ID.
 */
- (void)onMixingDataFrame:(ByteRTCFrameExtendedData *_Nonnull)dataFrame taskId:(NSString *_Nonnull)taskId;


/**
 * 
 * @hidden for internal use only
 * @type callback
 * @region Push to CDN
 * @brief Synchronized video frame callback.
 * @param videoFrame Array of synchronized video frames corresponding to uids.
 * @param dataFrame SEI data.
 * @param uids Array of synchronized video frames corresponding to uids.
 * @param task_id Task ID.
 */
- (void)onCacheSyncVideo:(NSArray<ByteRTCVideoFrame *> *_Nonnull)videoFrames withDataFrame:(NSArray<ByteRTCFrameExtendedData*> *_Nonnull)dataFrames
                 withUids:(NSArray<NSString*>*_Nonnull)uids taskId:(NSString *_Nonnull)task_id;
@end

/**
 * 
 * @type callback
 * @region Push to CDN
 * @brief Register this observer to receive the callbacks about pushing a single stream to CDN. <br>
 * Note: Callback functions are thrown synchronously in a non-UI thread within the SDK. Therefore, you must not perform any time-consuming operations or direct UI operations within the callback function, as this may cause the app to crash.
 */
@protocol ByteRTCPushSingleStreamToCDNObserver <NSObject>

/**
 * 
 * @type callback
 * @region Push to CDN
 * @brief Used for reporting events during pushing a single stream to CDN.
 * @param event Task status, see ByteRTCSingleStreamPushEvent{@link #ByteRTCSingleStreamPushEvent}.
 * @param taskID Task ID
 * @param errorCode Errors occurring during the pushing process. See ByteRtcTranscoderErrorCode{@link #ByteRtcTranscoderErrorCode}.
 */
 - (void)onStreamPushEvent:(ByteRTCSingleStreamPushEvent)event
                  taskId:(NSString *_Nonnull)taskID
                      error:(NSInteger)errorCode;

@end


/**
 * 
 * @type callback
 * @region Video Effect
 * @brief Face detection observer <br>
 * Note: Callback functions are thrown synchronously in a non-UI thread within the SDK. Therefore, you must not perform any time-consuming operations or direct UI operations within the callback function, as this may cause the app to crash.
 */
@protocol ByteRTCFaceDetectionObserver <NSObject>

/**
 * 
 * @type callback
 * @region Video Effect
 * @brief Callback of the result of face detection with Effect SDK. <br>
 *        After calling enableFaceDetection:withInterval:withModelPath:{@link #ByteRTCVideoEffect#enableFaceDetection:withInterval:withModelPath:} and using the Effect SDK integrated in the RTC SDK, you will receive this callback.
 * @param result Face detection result. See ByteRTCFaceDetectionResult{@link #ByteRTCFaceDetectionResult}.
*/
- (void)onFaceDetectResult:(ByteRTCFaceDetectionResult * _Nonnull)result;

/**
 * 
 * @hidden for intrnal use only
 * @type callback
 * @region Video Effect
 * @brief Callback of the result of face detection with Effect SDK. <br>
 *        After calling registerFaceDetectionObserver:withInterval:{@link #ByteRTCVideoEffect#registerFaceDetectionObserver:withInterval:} and setVideoEffectExpressionDetect:{@link #ByteRTCVideo#setVideoEffectExpressionDetect:}, you will receive this callback.
 * @param result Expression detection result. See ExpressionDetectResult{@link #ExpressionDetectResult}.
*/
- (void)onExpressionDetectResult:(ByteRTCExpressionDetectResult * _Nonnull)result;
@end

#pragma mark - ByteRTCEngineMediaMetadataObserver


/**
 * 
 * @hidden
 * @deprecated since 3.45 and will be deleted in 3.51, use sendSEIMessage:andMessage:andRepeatCount:andCountPerFrame:{@link #ByteRTCVideo#sendSEIMessage:andMessage:andRepeatCount:andCountPerFrame:} instead.
 * @type callback
 * @brief Configure and obtain additional data interfaces when using internal source video capture
 */
BYTERTC_APPLE_EXPORT @protocol ByteRTCMediaMetadataObserver <NSObject>
@required

/**
 * 
 * @type callback
 * @region Video data callback
 * @brief When the SDK is ready to send a video frame, the interface will be called back to determine whether metadata
 * @param timestamp The timestamp of the metadata video frame to be added, in microseconds
 * @return The data to be sent cannot exceed the size 1024bytes
 * @note
 *        - Returning null means that no metadata needs to be added
 *        - Long-term logical processing cannot be done in the callback to avoid affecting the video card
 */
- (NSData *_Nullable)videoFrameMediaMetaDataAtTime:(NSTimeInterval)timestamp;

@optional

/**
 * 
 * @type callback
 * @region Video data callback
 * @brief When the video frame received by the SDK contains medatada, the interface will be called back
 * @param uid The user ID to which the current frame belongs
 * @param extendedData Metadata
 * @param timestamp The timestamp containing the metadata video frame is in microseconds
 * @note Long-term logical processing cannot be done in the callback to avoid affecting the video card
 */
- (void)receiveVideoFrameFromUID:(NSString * _Nonnull)uid
    withExtendedData:(NSData* _Nullable)extendedData atTimestamp:(NSTimeInterval)timestamp;
@end

/**
 * 
 * @type keytype
 * @brief  Video encoding configuration. Refer to [Setting Video Encoder Configuration](https:
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCVideoEncoderConfig: NSObject

/**
 * 
 * @brief Width of the video frame in px
 */
@property(nonatomic, assign) NSInteger width;

/**
 * 
 * @brief Height of the video frame in px
 */
@property(nonatomic, assign) NSInteger height;

/**
 * 
 * @brief Video frame rate in fps
 */
@property(nonatomic, assign) NSInteger frameRate;

/**
 * 
 * @brief Maximum bit rate in kbps. Optional for internal capturing while mandatory for custom capturing. <br>
 *        If you set this value to -1, SDK will automatically calculate the applicable bit rate based on the input resolution and frame rate. <br>
 *        No stream will be encoded and published if you set this value to 0. <br>
 *        In 344 and later versions, the default value is -1 for internal capturing, but no default value in versions earlier than 344.
 */
@property(nonatomic, assign) NSInteger maxBitrate;

/**
 * 
 * @brief Minimum video encoding bitrate in kbps. The encoding bitrate will not be lower than the `minBitrate`. <br>
 *        It defaults to `0`. <br>
 *        It ranges within [0, maxBitrate). When `maxBitrate` < `minBitrate`, the bitrate is self-adpapted. <br>
 *        In the following circumstance, the assignment to this variable has no effect: <br>
 *        - When `maxBitrate` = `0`, the video encoding is disabled.
 *        - When `maxBitrate` < `0`, the bitrate is self-adapted.
 */
@property(nonatomic, assign) NSInteger minBitrate;

/**
 * 
 * @brief Encoding preference. The default value is ByteRTCVideoEncoderPreferenceMaintainFramerate(1). See ByteRTCVideoEncoderPreference{@link #ByteRTCVideoEncoderPreference}.
 */
@property(nonatomic, assign) ByteRTCVideoEncoderPreference encoderPreference;
@end


/**
 * 
 * @type keytype
 * @brief  The encoding configuration for shared-screen streams. <br>
 * For recommended settings on macOS, refer to [Screen sharing on a PC](https:
 * For recommended settings on iOS, refer to [Screen sharing on iOS](https:
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCScreenVideoEncoderConfig: NSObject

/**
 * 
 * @brief The maximum width of the captured screen, measured in pixel.
 */
@property(nonatomic, assign) NSInteger width;

/**
 * 
 * @brief The maximum height of the captured screen, measured in pixel.
 */
@property(nonatomic, assign) NSInteger height;

/**
 * 
 * @brief The frame rate of the screen capture, measured in fps. <br>
 * For macOS, we recommend set this value to the same as the capture frame rate. <br>
 * For iOS, the frame rate applies to both the screen capture and the encoding.
 */
@property(nonatomic, assign) NSInteger frameRate;

/**
 * 
 * @brief The maximum bitrate(in kbps). Optional for internal capture while mandatory for custom capture. <br>
 *        If you set this value to -1, RTC will automatically recommend the bitrate based on the input resolution and frame rate. <br>
 *        If you set this value to 0, the streams will not be encoded and published. <br>
 *        On Version 3.44 or later, the default value for internal capture is -1. On versions earlier than 3.44, you must set the maximum bit rate because there is no default value.
 */
@property(nonatomic, assign) NSInteger maxBitrate;

/**
 * 
 * @brief The minimum bitrate(in kbps).Optional for internal capture while mandatory for custom capture. <br>
 *        The minimum bitrate must be set lower than the maximum bitrate. Otherwise, the streams will not be encoded and published.
 */
@property(nonatomic, assign) NSInteger minBitrate;

/**
 * 
 * @brief The preference for encoding screen-sharing streams. <br>
 * See ByteRTCScreenVideoEncoderPreference{@link #ByteRTCScreenVideoEncoderPreference}.
 */
@property(nonatomic, assign) ByteRTCScreenVideoEncoderPreference encoderPreference;
@end


/**
 * 
 * @type keytype
 * @brief Information on remote video frame
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCRemoteVideoConfig : NSObject

/**
 * 
 * @brief Expected maximum frame rate of the subscribed stream in px. The default value is 0, which represents full-frame-rate, values greater than 0 are valid. <br>
 *        If the frame rate of the stream published is higher than the value set by the subscriber, the subscriber receives the video of the frame rate set by this API; if the frame rate of the stream published is lower than the value set by the subscriber, the subscriber receives the video of the same frame rate of the video published. <br>
 *        Only valid if the stream is coded with SVC technique.
 */
@property (nonatomic, assign) int framerate;

/**
 * 
 * @brief Width of the video frame in px
 */
@property(nonatomic, assign) int  width;

/**
 * 
 * @brief Height of the video frame in px
 */
@property(nonatomic, assign) int   height;
@end

/**
 * 
 * @type keytype
 * @brief  Room configuration
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCRoomConfig : NSObject

/**
 * 
 * @brief Room profile. See ByteRTCRoomProfile{@link #ByteRTCRoomProfile}. The default is `ByteRTCRoomProfileCommunication`. The setting cannot be changed after joining the room.
 */
@property(nonatomic) ByteRTCRoomProfile profile;
    
    /**
     * 
     * @brief Whether to automatically subscribe to the audio stream. The default is automatic subscription.
     *        + Changing the user role to audience via `setUserVisibility` will void this setting. 
     *        + You can publish streams in only one of the rooms you have participated. If you have joined multiple rooms with the automatically publishing setting, the stream will be added into the first room you have joined only.
     */
@property(assign, nonatomic) BOOL isPublishAudio;
    
    /**
     * 
     * @brief Whether to publish media streams automatically. The default is automatic publishing. 
     *        + Changing the user role to audience via setUserVisibility:{@link #ByteRTCRoom#setUserVisibility:} will void this setting. 
     *        + You can publish streams in only one of the rooms you have participated. If you have joined multiple rooms with the automatically publishing setting, the stream will be added into the first room you have joined only.
     */
@property(assign, nonatomic) BOOL isPublishVideo;

/**
 * 
 * @brief Whether to automatically subscribe to the audio stream. The default is automatic subscription. <br>
 *        This setting affects both the main stream and the screen-sharing stream.
 */
@property(assign, nonatomic) BOOL isAutoSubscribeAudio;

/**
 * 
 * @brief Whether to automatically subscribe to the video stream. The default is automatic subscription. <br>
 *        This setting affects both the main stream and the screen-sharing stream.
 */
@property(assign, nonatomic) BOOL isAutoSubscribeVideo;

/**
 * 
 * @brief Expected configuration of remote video stream, see ByteRTCRemoteVideoConfig{@link #ByteRTCRemoteVideoConfig}.
 */
@property(nonatomic, strong) ByteRTCRemoteVideoConfig * _Nonnull remoteVideoConfig;
@end

/**
 * 
 * @type keytype
 * @brief Crop configuration of the public stream
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCSourceCropInfo : NSObject

/**
 * 
 * @brief The normalized scale of the upper-left corner of the cropped video frame relative to the overall frame before cropping, in the range [0.0, 1.0)
 */
@property(assign, nonatomic) CGFloat locationX;

/**
 * 
 * @brief The normalized scale of the upper-left corner of the cropped video frame relative to the overall frame before cropping, in the range [0.0, 1.0)
 */
@property(assign, nonatomic) CGFloat locationY;

/**
 * 
 * @brief The normalized ratio of the width of the video frame obtained after cropping to the overall frame before cropping, in the range (0.0, 1.0]
 */
@property(assign, nonatomic) CGFloat widthProportion;

/**
 * 
 * @brief The normalized ratio of the height of the obtained video frame after cropping to the overall frame before cropping, in the range (0.0, 1.0]
 */
@property(assign, nonatomic) CGFloat heightProportion;
@end

/**
 * 
 * @type keytype
 * @brief Layout of each stream to be mixed into the public stream
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCPublicStreamRegion : NSObject

/**
 * 
 * @brief User ID. Required. <br>
*         The server will identify the stream per the userId and roomId. <br>

 */
@property(copy, nonatomic) NSString * _Nonnull userId;

/**
 * 
 * @brief Room ID. Required. <br>
*         The server will identify the stream per the userId and roomId.
 */
@property(copy, nonatomic) NSString * _Nonnull roomId;

/**
 * 
 * @brief Address of the background picture
 */
@property(copy, nonatomic) NSString * _Nonnull alternateImage;

/**
 * 
 * @brief Offset of the user video layout relative to the left side of the canvas, relative value. Range [0.0 - 1.0]
 */
@property(assign, nonatomic) CGFloat x;

/**
 * 
 * @brief Offset of the user video layout relative to the top of the canvas, relative value. Range [0.0 - 1.0]
 */
@property(assign, nonatomic) CGFloat y;

/**
 * 
 * @brief The ratio of the user video width relative to the user's original video width, relative value. Range [0.0 - 1.0]
 */
@property(assign, nonatomic) CGFloat width;

/**
 * 
 * @brief The ratio of the user video height relative to the user's original video height, relative value. Range [0.0 - 1.0].
 */
@property(assign, nonatomic) CGFloat height;

/**
 * 
 * @brief The level of the user video layout in the canvas, 0 is the bottom level, the larger the value the higher the level. Range [0 - 100]
 */
@property(assign, nonatomic) NSInteger zOrder;

/**
 * 
 * @brief Required. Transparency, the range is [0.0, 1.0]
 */
@property(assign, nonatomic) CGFloat alpha;

/**
 * 
 * @brief Push stream content control. Default value is 0. <br>
 *      0: The output mix contains audio and video <br>
 *      1: Audio only <br>
 *      2: Video only
 */
@property(assign, nonatomic) NSInteger mediaType;

/**
 * 
 * @brief Media type of pushes stream <br>
 *        0：Media stream captured by camera/microphone <br>
 *        1: Screen sharing media stream
 */
@property(assign, nonatomic) NSInteger streamType;

/**
 * 
 * @brief Video rendering mode. See ByteRTCRenderMode{@link #ByteRTCRenderMode} for data types.
 */
@property(assign, nonatomic) ByteRTCRenderMode renderMode;

/**
 * 
 * @brief Video cropping information. Refer to ByteRTCSourceCropInfo{@link #ByteRTCSourceCropInfo} for details.
 */
@property(strong, nonatomic) ByteRTCSourceCropInfo * _Nonnull sourceCrop;
@end


/**
 * 
 * @type keytype
 * @brief Required. Layout of streams mixed in the public stream
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCPublicStreamLayout : NSObject

/**
 * 
 * @brief Layout mode. The optional values: <br>
 *        - `0`: Auto layout. The default value.
 *        - `2`: Custom mode.
 */
@property(assign, nonatomic) NSInteger layoutMode;

/**
 * 
 * @brief Interpolation mode <br>
 *         - `0`: Insert with the last frame
 *         - `1`: Insert with the background image. RTC will insert frames of black if no background image has been set.
 */
@property(assign, nonatomic) NSInteger interpolationMode;

/**
 * 
 * @brief Background color of the canvas,in RGB hex value. For example, #FFB6C1 represents light pink. The default value is #000000 (black).
 */
@property(copy, nonatomic) NSString *_Nonnull backgroundColor;

/**
 * 
 * @brief Address of the background picture
 */
@property(copy, nonatomic) NSString *_Nonnull backgroundImage;

/**
 * 
 * @brief User layout information list.
 */
@property(copy, nonatomic) NSArray<ByteRTCPublicStreamRegion *> * _Nonnull regions;
@end


/**
 * 
 * @type keytype
 * @brief Encoding properties of the public video stream
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCPublicStreamVideoConfig : NSObject

/**
 * 
 * @brief Required. Width of the video frame. Unit: px. Range: [16, 1920], even value is effective.
 */
@property(assign, nonatomic) NSInteger width;

/**
 * 
 * @brief Required. Width of the video frame. Unit: px. Range: [16, 1280], even value is effective.
 */
@property(assign, nonatomic) NSInteger height;

/**
 * 
 * @brief Required. Frame rate in fps <br>
 *        Range: [1, 60]
 */
@property(assign, nonatomic) NSInteger fps;

/**
 * 
 * @brief Required. Bitrate in bps <br>
 *          Range: [1,10000000]
 */
@property(assign, nonatomic) NSInteger bitrate;
@end


/**
 * 
 * @hidden currently not available
 * @type keytype
 * @brief Encoding properties of the public audio stream
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCPublicStreamAudioConfig : NSObject

/**
 * 
 * @brief Required. Audio sample rate in Hz. Options: 16000, 32000, 44100, or 48000
 */
@property(assign, nonatomic) NSInteger sampleRate;

/**
 * 
 * @brief Required. Number of the audio channels. <br>
 * - 1: Mono
 * - 2: Dual
 */
@property(assign, nonatomic) NSInteger channels;

/**
 * 
 * @brief Required. Audio bitrate in kbps. <br>
 * Positive integer in kbps. Options: 16, 32, or 64
 */
@property(assign, nonatomic) NSInteger bitrate;
@end


/**
 * 
 * @type keytype
 * @brief  Watermark's scaled coordinates and size, relative to the video stream.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCVideoByteWatermark: NSObject

/**
 * 
 * @brief The watermark's horizontal offset from the upper left corner of the video stream to the video stream's width in range of [0,1).
 */
@property(assign, nonatomic) float x;

/**
 * 
 * @brief The watermark's vertical offset from the upper left corner of the video stream to the video stream's height in range of [0,1).
 */
@property(assign, nonatomic) float y;

/**
 * 
 * @brief The watermark's width to the video stream's width in range of [0,1).
 */
@property(assign, nonatomic) float width;

/**
 * 
 * @brief The watermark height to the video stream's height in range of [0,1).
 */
@property(assign, nonatomic) float height;
@end


/**
 * 
 * @type keytype
 * @brief  Watermark configurations
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCVideoWatermarkConfig: NSObject

/**
 * 
 * @brief Whether the watermark is visible in preview. Its default value is `true`.
 */
@property(nonatomic, assign) BOOL visibleInPreview;

/**
 * 
 * @brief Watermark's coordinates and size in landscape mode. See ByteRTCVideoByteWatermark{@link #ByteRTCVideoByteWatermark}.
 */
@property(strong, nonatomic) ByteRTCVideoByteWatermark * _Nonnull positionInLandscapeMode;

/**
 * 
 * @brief Watermark's coordinates and size in portrait mode. See ByteRTCVideoByteWatermark{@link #ByteRTCVideoByteWatermark}.
 */
@property(strong, nonatomic) ByteRTCVideoByteWatermark * _Nonnull positionInPortraitMode;
@end


/**
 * 
 * @type keytype
 * @brief Properties of the public stream
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCPublicStreaming : NSObject

/**
 * 
 * @brief Required. Layout configuration of the public stream. Refer to ByteRTCPublicStreamLayout{@link #ByteRTCPublicStreamLayout} for details.
 */
@property(strong, nonatomic) ByteRTCPublicStreamLayout * _Nonnull layout;

/**
 * 
 * @brief Encoding properties of the public video stream. Refer to ByteRTCPublicStreamVideoConfig{@link #ByteRTCPublicStreamVideoConfig} for details.
 */
@property(strong, nonatomic) ByteRTCPublicStreamVideoConfig * _Nonnull video;

/**
 * 
 * @hidden currently not available
 * @brief Encoding properties of the public audio stream. Refer to ByteRTCPublicStreamAudioConfig{@link #ByteRTCPublicStreamAudioConfig} for details.
 */
@property(strong, nonatomic) ByteRTCPublicStreamAudioConfig * _Nonnull audio;

/**
 * 
 * @hidden currently not available
 * @brief Required. The server will identify the stream per the userId and roomId.
 */
@property(copy, nonatomic) NSString * _Nullable roomId;

/**
 * 
 * @brief Get the default setting of a public stream.
 * @return ByteRTCPublicStreaming{@link #ByteRTCPublicStreaming} struct with default values.
 */
+ (instancetype _Nonnull)defaultPublicStreaming;
@end

/**
 * 
 * @type api
 * @hidden(iOS)
 * @region Video Device Management
 * @brief Mainly used to enumerate and set up video capture devices
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCVideoDeviceManager : NSObject

/**
 * 
 * @type api
 * @region  Video Device Management
 * @brief  Get the list of video capture devices.
 * @return Contains a list of all video capture devices in the system. See ByteRTCDeviceCollection{@link #ByteRTCDeviceCollection}. <br>
 * If a time-out occurs, it returns an empty list. By default, the time-out duration is set to 10 seconds. We recommend to call this API once you get notification of `ByteRTCMediaDeviceListUpdated` via rtcEngine:onVideoDeviceStateChanged:device_type:device_state:device_error:{@link #ByteRTCVideoDelegate#rtcEngine:onVideoDeviceStateChanged:device_type:device_state:device_error:}.
 * @note When receiving rtcEngine:onVideoDeviceStateChanged:device_type:device_state:device_error:{@link #ByteRTCVideoDelegate#rtcEngine:onVideoDeviceStateChanged:device_type:device_state:device_error:} for device change, you can call this API to get the latest list of audio playback devices.
 */
- (ByteRTCDeviceCollection * _Nonnull)enumerateVideoCaptureDevices;

/**
 * 
 * @type api
 * @region Video Device Management
 * @brief Get the currently-using video capture device
 * @param  deviceID video device ID
 * @return
 *         - 0: Success.
 *         +! 0: failure
 */
- (int)getVideoCaptureDevice:(NSString * _Nonnull * _Nonnull) deviceID;

/**
 * 
 * @type api
 * @region  Video Device Management
 * @brief  Set the current video capture device
 * @param  deviceID Video device ID. Get all video devices by calling  which can be obtained through enumerateVideoCaptureDevices{@link #ByteRTCVideoDeviceManager#enumerateVideoCaptureDevices}
 * @return
 *         - 0: Success.
 *         +! 0: failure
 */
- (int)setVideoCaptureDevice:(NSString* _Nonnull)deviceID;
@end

/**
 * 
 * @type callback
 * @brief  Screenshot-taking callback class. <br>
 * Note: Callback functions are thrown synchronously in a non-UI thread within the SDK. Therefore, you must not perform any time-consuming operations or direct UI operations within the callback function, as this may cause the app to crash.
 */
BYTERTC_APPLE_EXPORT @protocol ByteRTCVideoSnapshotCallbackDelegate <NSObject>
@required

/**
 * 
 * @type callback
 * @brief Receives the callback after calling takeLocalSnapshot:callback:{@link #ByteRTCVideo#takeLocalSnapshot:callback:}.
 * @param taskId The index for the snapshot, the same as the return value of takeLocalSnapshot:callback:{@link #ByteRTCVideo#takeLocalSnapshot:callback:}.
 * @param streamIndex See ByteRTCStreamIndex{@link #ByteRTCStreamIndex}.
 * @param image The snapshot image. If the snapshot task fails, the value is `null`.
 * @param errorCode Error code: <br>
 *        - 0: Success.
 *        - -1: Failure. Fails to generate the image.
 *        - -2: Failure. The stream is invalid.
 *        - -3: Failure. snapshot timeout, default 1s.
 */
- (void)onTakeLocalSnapshotResult:(NSInteger) taskId
                      streamIndex:(ByteRTCStreamIndex)streamIndex
                            image:(ByteRTCImage * _Nullable)image
                        errorCode:(NSInteger)errorCode;

/**
 * 
 * @type callback
 * @brief Receives the callback after calling takeRemoteSnapshot:callback:{@link #ByteRTCVideo#takeRemoteSnapshot:callback:}.
 * @param taskId The index for the remote snapshot, the same as the return value of takeRemoteSnapshot:callback:{@link #ByteRTCVideo#takeRemoteSnapshot:callback:}.
 * @param streamKey See ByteRTCRemoteStreamKey{@link #ByteRTCRemoteStreamKey}.
 * @param image The snapshot image. If the snapshot task fails, the value is `null`.
 * @param errorCode Error code: <br>
 *        - 0: Success.
 *        - -1: Failure. Fails to generate the image.
 *        - -2: Failure. The stream is invalid.
 *        - -3: Failure. snapshot timeout, default 1s.
 */
- (void)onTakeRemoteSnapshotResult:(NSInteger)taskId
                         streamKey:(ByteRTCRemoteStreamKey * _Nonnull)streamKey
                             image:(ByteRTCImage * _Nullable)image
                         errorCode:(NSInteger)errorCode;
@end


/**
 * 
 * @type api
 * @region Audio & Video Processing
 * @brief Advanced video effects. See [integration guide](https:
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCVideoEffect : NSObject


/**
 * 
 * @hidden for internal use only
 * @type api
 * @brief  Sets the video effects resource finder path and initializes video effects.
 * @param finder ResourceFinder path
 * @param deleter ResourceDeleter path
 * @return
 *      - 0: Success.
 *      - –1000: The Effects SDK is not integrated.
 *      - –1001: This API is unavailable for your Effects SDK.
 *      - –1002: Your Effects SDK's version is incompatible.
 *      - < 0: Other error. See [error code table](https:
 */
- (int) setAlgoModelResourceFinder:(void*_Nonnull)finder deleter:(void*_Nonnull)deteter;

#if BYTERTC_TARGET_MAC

/**
 * 
 * @type api
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
 * @type api
 * @brief Checks video effect license, sets the video effect resource model path, and initializes video effect.
 * @param licenseFile The absolute path of the license file for authorization.
 * @param algoModelDir The absolute path of the Effects SDK's models file.
 * @return
 *      - 0: Success.
 *      - –1000: The Effects SDK is not integrated.
 *      - –1002: Your Effects SDK's version is incompatible.
 *      - < 0: Other error. See [error code table](https:
 */
- (int) initCVResource:(NSString* _Nonnull)licenseFile
            withAlgoModelDir: (NSString* _Nonnull)algoModelDir;


/**
 * 
 * @type api
 * @brief Enables video effects including beauty and color filters.
 * @return
 *      - 0: Success.
 *      - –1000: The Effects SDK is not integrated.
 *      - –1001: This API is unavailable for your Effects SDK.
 *      - –1002: Your Effects SDK's version is incompatible.
 *      - < 0: Other error. See [error code table](https:
 * @note
 *      - You must call initCVResource:withAlgoModelDir:{@link #ByteRTCVideoEffect#initCVResource:withAlgoModelDir:} before calling this API.
 *      - This API does not turn on video effects directly, you must call setEffectNodes:{@link #ByteRTCVideoEffect#setEffectNodes:} or setColorFilter:{@link #ByteRTCVideoEffect#setColorFilter:} next.
 *      - Call disableVideoEffect{@link #ByteRTCVideoEffect#disableVideoEffect} to turn off video effects.
 */
- (int) enableVideoEffect;


/**
 * 
 * @type api
 * @brief Disables video effects.
 * @return
 *      - 0: Success.
 *      - –1000: The Effects SDK is not integrated.
 *      - –1001: This API is unavailable for your Effects SDK.
 *      - –1002: Your Effects SDK's version is incompatible.
 *      - < 0: Other error. See [error code table](https:
 * @note Call enableVideoEffect{@link #ByteRTCVideoEffect#enableVideoEffect} to enable video effects.
 */
- (int) disableVideoEffect;


/**
 * 
 * @hidden for internal use only
 * @type api
 * @region Video Effects
 * @brief Return video effect handle. Private method
 */
- (void* _Nullable)getVideoEffectHandle;


/**
 * 
 * @hidden for internal use only
 * @type api
 * @region Video Effects
 * @brief Private method <br>
 * Set video effects material package.
 * @param stickerPath effect material package path. <br>
 *        To remove the current video effect, set it to null.
 * @return
 *      - 0: Success
 *      - 1000: The Effect SDK is not integrated.
 *      - 1001: This API is not available for your Effect SDK.
 *      - <0: Other errors. See [Error Code Table](https:
 * @note Before calling this method, you must first call enableVideoEffect:{@link #ByteRTCVideoEffect#enableVideoEffect:}.
 */
- (int) applyStickerEffect:(NSString* _Nullable)stickerPath;


/**
 * 
 * @type api
 * @brief Sets the video effects material package.
 * @param effectNodes Array of effect material package paths. <br>
 *        To remove the current video effect, set it to null.
 * @return
 *      - 0: Success.
 *      - –1000: The Effects SDK is not integrated.
 *      - –1001: This API is unavailable for your Effects SDK.
 *      - –1002: Your Effects SDK's version is incompatible.
 *      - < 0: Other error. See [error code table](https:
 * @note You must call enableVideoEffect{@link #ByteRTCVideoEffect#enableVideoEffect} before calling this API.
 */
- (int) setEffectNodes:(NSArray<NSString*>*_Nonnull)effectNodes;


/**
 * 
 * @hidden for internal use only
 * @type api
 * @brief  Appends video effects material package.
 * @param effectNodes Array of effect material package paths.
 * @return
 *      - 0: Success.
 *      - –1000: The Effects SDK is not integrated.
 *      - –1001: This API is unavailable for your Effects SDK.
 *      - –1002: Your Effects SDK's version is incompatible.
 *      - < 0: Other error. See [error code table](https:
 * @note This API adds new video effect to the video effect you set with setEffectNodes:{@link #ByteRTCVideoEffect#setEffectNodes:}.
 */
- (int) appendEffectNodes:(NSArray<NSString*>*_Nonnull)effectNodes;


/**
 * 
 * @hidden for internal use only
 * @type api
 * @brief  Removes the designated video effects material package.
 * @param effectNodes Array of effect material package paths.
 * @return
 *      - 0: Success.
 *      - –1000: The Effects SDK is not integrated.
 *      - –1001: This API is unavailable for your Effects SDK.
 *      - –1002: Your Effects SDK's version is incompatible.
 *      - < 0: Other error. See [error code table](https:
 * @note Removes the designated video effects in setEffectNodes:{@link #ByteRTCVideoEffect#setEffectNodes:} or appendEffectNodes:{@link #ByteRTCVideoEffect#appendEffectNodes:}.
 */
- (int) removeEffectNodes:(NSArray<NSString*>*_Nonnull)effectNodes;


/**
 * 
 * @type api
 * @brief Sets the intensity of video effects.
 * @param node The absolute path of the effects resource package, see [Resource Package Structure](https:
 * @param key The name of the material key to be set, see [Functions of Resource Keys](https:
 * @param value The intensity value that needs to be set, the value range [0,1], and the setting is invalid when it exceeds the range.
 * @return
 *      - 0: Success.
 *      - –1000: The Effects SDK is not integrated.
 *      - –1001: This API is unavailable for your Effects SDK.
 *      - –1002: Your Effects SDK's version is incompatible.
 *      - < 0: Other error. See [error code table](https:
 */
- (int) updateEffectNode:(NSString* _Nonnull)node
                key:(NSString* _Nonnull)key value:(float) value;


/**
 * 
 * @type api
 * @brief Sets the color filter.
 * @param filterRes Filter effects package absolute path.
 * @return
 *      - 0: Success.
 *      - –1000: The Effects SDK is not integrated.
 *      - –1001: This API is unavailable for your Effects SDK.
 *      - –1002: Your Effects SDK's version is incompatible.
 *      - < 0: Other error. See [error code table](https:
 * @note Call setColorFilterIntensity:{@link #ByteRTCVideoEffect#setColorFilterIntensity:} to set the intensity of the color filter enabled. Set the intensity to 0 to turn off color filter.
 */
- (int) setColorFilter:(NSString* _Nonnull)filterRes;


/**
 * 
 * @type api
 * @brief Sets the intensity of the color filter enabled.
 * @param intensity Filter intensity. The value range [0,1] is set to be invalid when the range is exceeded. <br>
 *                  Set the intensity to 0 to turn off color filter.
 * @return
 *      - 0: Success.
 *      - –1000: The Effects SDK is not integrated.
 *      - –1001: This API is unavailable for your Effects SDK.
 *      - –1002: Your Effects SDK's version is incompatible.
 *      - < 0: Other error. See [error code table](https:
 */
- (int) setColorFilterIntensity:(float) intensity;


/**
 * 
 * @type api
 * @brief Sets the original background to a specified image or a solid color.
 * @param backgroundStickerPath The absolute path of virtual background effects.
 * @param source Virtual background source. See ByteRTCVirtualBackgroundSource{@link #ByteRTCVirtualBackgroundSource}.
 * @return
 *      - 0: Success.
 *      - –1000: The Effects SDK is not integrated.
 *      - –1001: This API is unavailable for your Effects SDK.
 *      - –1002: Your Effects SDK's version is incompatible.
 *      - < 0: Other error. See [error code table](https:
 * @note
 *      - You must call initCVResource:withAlgoModelDir:{@link #ByteRTCVideoEffect#initCVResource:withAlgoModelDir:} before calling this API.
 *      - Call disableVirtualBackground{@link #ByteRTCVideoEffect#disableVirtualBackground} to turn off the virtual background.
 */
- (int) enableVirtualBackground:(NSString* _Nonnull)backgroundStickerPath
                withSource:(ByteRTCVirtualBackgroundSource* _Nonnull)source;


/**
 * 
 * @type api
 * @brief Turns off the virtual background.
 * @return
 *      - 0: Success.
 *      - –1000: The Effects SDK is not integrated.
 *      - –1001: This API is unavailable for your Effects SDK.
 *      - –1002: Your Effects SDK's version is incompatible.
 *      - < 0: Other error. See [error code table](https:
 * @note After calling enableVirtualBackground:withSource:{@link #ByteRTCVideoEffect#enableVirtualBackground:withSource:} to enable the virtual background function, you can call this API to turn it off.
 */
- (int) disableVirtualBackground;


/**
 * 
 * @hidden for internal use only
 * @type api
 * @brief  Sets the configuration for video effects expression detection.
 * @param config Expression detection configuration. See ByteRTCExpressionDetectConfig{@link #ByteRTCExpressionDetectConfig}.
 * @return
 *      - 0: Success.
 *      - –1000: The Effects SDK is not integrated.
 *      - –1001: This API is unavailable for your Effects SDK.
 *      - –1002: Your Effects SDK's version is incompatible.
 *      - < 0: Other error. See [error code table](https:
 */
- (int) setVideoEffectExpressionDetect:(ByteRTCExpressionDetectConfig* _Nonnull)config;


/**
 * 
 * @deprecated since 3.50 and will be deleted in 3.55, use enableFaceDetection:withInterval:withModelPath:{@link #ByteRTCVideoEffect#enableFaceDetection:withInterval:withModelPath:} and disableFaceDetection{@link #ByteRTCVideoEffect#disableFaceDetection} instead.
 * @type api
 * @brief  Register the observer for the result of face detection. <br>
 *        With this observer, you will receive onFaceDetectResult:{@link #ByteRTCFaceDetectionObserver#onFaceDetectResult:} periodically.
 * @param observer See ByteRTCFaceDetectionObserver{@link #ByteRTCFaceDetectionObserver}.
 * @param interval Time interval in ms. The value should be greater than 0. The actual time interval of receiving callbacks is between `interval` and `interval+the time slot of a captured video frame`.
 * @return
 *      - 0: Success.
 *      - –1000: The Effects SDK is not integrated.
 *      - –1001: This API is unavailable for your Effects SDK.
 *      - –1002: Your Effects SDK's version is incompatible.
 *      - < 0: Other error. See [error code table](https:
 */
- (int) registerFaceDetectionObserver:(_Nullable id<ByteRTCFaceDetectionObserver>) observer
                withInterval:(NSInteger)interval __deprecated_msg("Will be removed in new version");


/**
 * 
 * @type api
 * @brief Starts face detection and registers the observer for the result. <br>
 *        With this observer, you will receive onFaceDetectResult:{@link #ByteRTCFaceDetectionObserver#onFaceDetectResult:} periodically.
 * @param observer See ByteRTCFaceDetectionObserver{@link #ByteRTCFaceDetectionObserver}.
 * @param interval The minimum time interval between two callbacks in milliseconds. The value should be greater than 0. The actual time interval is between interval and interval+the time slot of a captured video frame.
 * @param path The absolute path of the face detection algorithm file. Typically it is the tt_face_vXXX.model file in the ttfacemodel folder.
 * @return
 *      - 0: Success.
 *      - –1000: The Effects SDK is not integrated.
 *      - –1001: This API is unavailable for your Effects SDK.
 *      - –1002: Your Effects SDK's version is incompatible.
 *      - -1004: Initializing. This function will be available when the initialization is completed.
 *      - < 0: Other error. See [error code table](https:
 */
- (int) enableFaceDetection:(_Nullable id<ByteRTCFaceDetectionObserver>) observer
               withInterval:(NSUInteger)interval
              withModelPath:(NSString* _Nonnull)path;


/**
 * 
 * @type api
 * @brief Stops face detection.
 * @return
 *      - 0: Success.
 *      - –1000: The Effects SDK is not integrated.
 *      - –1001: This API is unavailable for your Effects SDK.
 *      - –1002: Your Effects SDK's version is incompatible.
 *      - < 0: Other error. See [error code table](https:
 */
- (int) disableFaceDetection;
@end



/**
 * 
 * @type keytype
 * @brief  The recommended pixel and framerate by RTC.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCFrameUpdateInfo : NSObject

/**
 * 
 * @brief Pixel (width * height).
 */
@property(assign, nonatomic) int pixel;

/**
 * 
 * @brief The frame rate.
 */
@property(assign, nonatomic) int framerate;
@end

/**
 * 
 * @hidden(macOS)
 * @type keytype
 * @brief Media type for cellular assisted Enhancement
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCMediaTypeEnhancementConfig: NSObject

/**
 * 
 * @brief Apply to signaling or not. Not by default.
 */
@property (assign, nonatomic) BOOL enhanceSignaling;

/**
 * 
 * @brief Apply to audio stream (Screen-sharing audio not included) or not. Not by default.
 */
@property (assign, nonatomic) BOOL enhanceAudio;

/**
 * 
 * @brief Apply to video (Screen-sharing video not included) or not. Not by default.
 */
@property (assign, nonatomic) BOOL enhanceVideo;

/**
 * 
 * @brief Apply to screen sharing audio or not. Not by default.
 */
@property (assign, nonatomic) BOOL enhanceScreenAudio;

/**
 * 
 * @brief Apply to screen sharing video or not. Not by default.
 */
@property (assign, nonatomic) BOOL enhanceScreenVideo;
@end


/**
* 
* @hidden internal use only
* @type keytype
*/
typedef NS_ENUM(NSUInteger, ByteRTCChorusCacheSyncMode) {
    
    /**
     * 
     * @brief Under chorus scenarios, the lead singer uses the mode to send the media data with timestamp attached.
     */
    ByteRTCChorusCacheSyncModeProducer= 0,
    
    /**
     * 
     * @brief Under chorus scenarios, the sub singer uses the mode. <br>
     *        In this mode, the sub singer receives the media data from the lead singer with timestamp attached. The sub singer sends the media data with the lead singer's timestamp attached.
     */
    ByteRTCChorusCacheSyncModeRetransmitter= 1,
    
    /**
     * 
     * @brief Under chorus scenarios, the audience uses the mode. <br>
     *        In this mode, the audience receives the lead singer's timestamp. The audience aligns and renders the media data from lead and sub singers, and gets good chorus experience.
     */
    ByteRTCChorusCacheSyncModeConsumer = 2
};


/**
 * 
 * @type keytype
 * @hidden for internal use
 * @brief Chorus cache synchronization event.
 */
typedef NS_ENUM(NSUInteger, ByteRTCChorusCacheSyncEvent) {
    
   /**
    * 
    * @brief Success.
    */
    ByteRTCChorusCacheSyncEventStartSuccess = 0,
    
   /**
    * 
    * @brief Failed.
    */
    ByteRTCChorusCacheSyncEventStartFailed = 1,
};


/**
 * 
 * @hidden for internal use only
 * @type errorcode
 * @brief Chorus cache synchronization error.
 */  
typedef NS_ENUM(NSUInteger, ByteRTCChorusCacheSyncError) {
    
    /**
     * 
     * @brief OK
     */
    ByteRTCChorusCacheSyncErrorOK = 0,
    
    /**
     * 
     * @type Failure. Check if the config of pushing mixed streams to CDN is as follows: <br>
     *        - `IMixedStreamConfig.MixedStreamSyncControlConfig.enable_sync = true`；
     *        - `IMixedStreamConfig.MixedStreamSyncControlConfig.base_user_id = {uid of producer}`。
     */
    ByteRTCChorusCacheSyncErrorWrongState = 1,
    
    /**
     * 
     * @type Already running. Do not enable the feature repeatedly.
     */
    ByteRTCChorusCacheSyncErrorAlreadyRunning = 2
};


/**
 * 
 * @hidden for internal use only
 * @type keytype
 * @brief Chorus cache synchronization configuration.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCChorusCacheSyncConfig: NSObject

/**
 * 
 * @brief Maximum duration of media data cached in ms. <br>
 *        `2000` by default. The range is `[500, 2500]`. <br>
 *        Use higher value for better syncing effect. If the time difference between media streams in cache synchronization exceeds this value, frame loss will occur.
 */
@property(assign, nonatomic) int maxCacheTimeMs;

/**
 * 
 * @brief Mode. See ByteRTCChorusCacheSyncMode{@link #ByteRTCChorusCacheSyncMode}. `retransmitter` by default.
 */
@property (assign, nonatomic) ByteRTCChorusCacheSyncMode mode;

/**
 * 
 * @brief The frequency of receiving onSyncedVideoFrames:withUids:{@link #ByteRTCChorusCacheSyncObserver#onSyncedVideoFrames:withUids:}. <br>
 *        `15` by default. The value is smaller than that of the original video fps usually; if the value is bagger than that, you may receive duplicated video frame.
 */
@property(assign, nonatomic) int videoFps;
@end


/**
 * 
 * @hidden for internal use only
 * @type callback
 * @brief Chorus cache synchronization observer.
 */
@protocol ByteRTCChorusCacheSyncObserver <NSObject>

/**
 * 
 * @type callback
 * @brief The user who calls startChorusCacheSync{@link #RTCVideo#startChorusCacheSync} as `consumer` receives the callback with synced video frames. The interval of receiving the callback is set by `fps`.
 * @param count length of `uids`
 * @param uids The list of participants as `producer` and `retransmitter`. The participants not sending media data are excluded.
 * @param videoFrames Video data frame corresponding to `uids`. See ByteRTCVideoFrame{@link #ByteRTCVideoFrame}.
 */
- (void)onSyncedVideoFrames:(NSArray<ByteRTCVideoFrame*>*)videoFrames withUids:(NSArray<NSString*>*)uids;

/**
 * 
 * @type callback
 * @brief Receives the callback when the `producer` or `retransmitter` changes.
 * @param uids Current list of the participants
 * @note You may receive the callback is the following cases: <br>
 *        - The user calls startChorusCacheSync:observer:{@link #ByteRTCVideo#startChorusCacheSync:observer:} or stopChorusCacheSync{@link #ByteRTCVideo#stopChorusCacheSync};
 *        - The cache syncing participant quits abnormally.
 */
- (void)onSyncedUsersChanged:(NSArray<NSString*>*)uids;

/**
 * 
 * @type callback
 * @brief Chorus cache sync event callback
 * @param event See ByteRTCChorusCacheSyncEvent{@link #ByteRTCChorusCacheSyncEvent}.
 * @param error See ByteRTCChorusCacheSyncError{@link #ByteRTCChorusCacheSyncError}.
 */
- (void)onSyncEvent:(ByteRTCChorusCacheSyncEvent)event withError:(ByteRTCChorusCacheSyncError)error;
@end
