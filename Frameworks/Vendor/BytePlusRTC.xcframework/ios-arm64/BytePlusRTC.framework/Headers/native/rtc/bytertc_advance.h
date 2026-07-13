/*
 * Copyright (c) 2020 The BytePlusRTC project authors. All Rights Reserved.
 * @brief BytePlusRTC Advance API
*/

#pragma once

#include "../bytertc_video.h"

#include <stdint.h>
#ifdef __ANDROID__
#include "jni.h"
#endif


#ifdef __GNUC__
#    define attribute_deprecated __attribute__((deprecated))
#elif defined(_MSC_VER)
#    define attribute_deprecated __declspec(deprecated)
#else
#    define attribute_deprecated
#endif

namespace bytertc {


/**
 * 
 * @hidden for internal use only
 * @type
 * @brief RTC Audio Dump node configuration. <br>
 * Be consistent with the AudioSampleType enumeration and AudioSampleConfigure in the bae_audio_sample_interface <br>
 * .
 */
struct RTCAudioSampleConfigure {
    bool aec_near_in_enable = false;
    bool aec_far_in_enable = false;
    bool aec_far_in_ref_enable = false;
    bool aec_out_enable = false;
    bool agc_out_enable = false;
    bool ns_out_enable = false;
    bool ainr_out_enable = false;
    bool mix_out_enable = false;
    bool send2encoder_enable = false;
    bool audio_share_in_enable = false;
    bool audio_share_win_ref_enable = false;
    bool audio_share_out_enable = false;
    bool external_audio_in_enable = false;
    bool pitchfilter_out_enable = false;
    bool decoder_out_enable = false;
    bool front_aec_near_ref_enable = false;
    bool postprocess_out_enable = false;
    bool remotefilter_out_enable = false;
    bool push_audio_frame_in_enable = false;
    bool loopback_device_in_enable = false;
    bool audio_share_reference_in_enable = false;
    void reset() {
        aec_near_in_enable = false;
        aec_far_in_enable = false;
        aec_far_in_ref_enable = false;
        aec_out_enable = false;
        agc_out_enable = false;
        ns_out_enable = false;
        ainr_out_enable = false;
        mix_out_enable = false;
        send2encoder_enable = false;
        audio_share_in_enable = false;
        audio_share_win_ref_enable = false;
        audio_share_out_enable = false;
        external_audio_in_enable = false;
        pitchfilter_out_enable = false;
        decoder_out_enable = false;
        front_aec_near_ref_enable = false;
        postprocess_out_enable = false;
        remotefilter_out_enable = false;
        push_audio_frame_in_enable = false;
        loopback_device_in_enable = false;
        audio_share_reference_in_enable = false;

    }
    void normalMode() {
        aec_near_in_enable = true;
        aec_far_in_ref_enable = true;
        mix_out_enable = true;
    }
    void allMode() {
        aec_near_in_enable = true;
        aec_far_in_enable = true;
        aec_far_in_ref_enable = true;
        aec_out_enable = true;
        agc_out_enable = true;
        ns_out_enable = true;
        ainr_out_enable = true;
        mix_out_enable = true;
        send2encoder_enable = true;
        audio_share_in_enable = true;
        audio_share_win_ref_enable = true;
        audio_share_out_enable = true;
        external_audio_in_enable = true;
        pitchfilter_out_enable = true;
        decoder_out_enable = true;
        front_aec_near_ref_enable = true;
        postprocess_out_enable = true;
        remotefilter_out_enable = true;
        push_audio_frame_in_enable = true;
        loopback_device_in_enable = true;
        audio_share_reference_in_enable = true;
    }
};


/**
 * 
 * @hidden for internal use only
 * @type keytype
 * @brief SDK  server environment.
 */
enum Env {
    
    /**
     * 
     * @brief  Online environment.
     */
    kEnvProduct = 0,
    
    /**
     * 
     * @brief BOE  environment.
     */
    kEnvBOE,
    
    /**
     * 
     * @brief  Test environment.
     */
    kEnvTest
};

attribute_deprecated

/**
 * 
 * @hidden for internal use only
 * @deprecated
 * @type api
 * @region Engine management
 * @brief Set the environment currently used by the SDK.
 * @param env The environment parameters used by the SDK are detailed in: Env{@link #Env}.
 * @return
 *        0: Setup succeeded <br>
 *        -1: Setup failed
 * @note
 *        1. This function is optional function, the default use of official environment; <br>
 *        2. This function must be called before creating the RTCVideo instance createRTCVideo{@link #createRTCVideo}.
 */
BYTERTC_API BYTERTC_DEPRECATED int setEnv(Env env);

attribute_deprecated

/**
 * 
 * @hidden for internal use only
 * @deprecated
 * @brief  Set the device ID
 * @param device_id App to generate a unique device id based on the current software and hardware environment
 */
BYTERTC_API BYTERTC_DEPRECATED void setDeviceId(const char* device_id);

/**
 * 
 * @hidden for internal use only
 * @brief  Set the state of the application
 * @param engine <br>
 *        Engine to notify
 * @param app_state Application state string
 */
BYTERTC_API void setAppState(void* engine, const char* app_state);

attribute_deprecated

/**
 * 
 * @hidden for internal use only
 * @deprecated
 * @type api
 * @region room management
 * @brief Private interface
 * @param parameters JSON string
 */
BYTERTC_API int setParameters(const char* parameters);

#ifdef __ANDROID__

/**
 * 
 * @hidden(iOS,macOS,Windows,Linux) for internal use only
 * @type api
 * @region Engine management
 * @brief Used to set the ApplicationContext for Android to use by Engine, <br>
 * If Android uses a pure C++ interface, this method must be set before the engine is created
 * @param j_egl_context <br>
 *      Passing in Java android.content. Context type EGLContext
 */
BYTERTC_API void setApplicationContext(jobject j_application_context);
#endif


/**
 * 
 * @region video management
 * @type keytype
 * @brief  Hardware acceleration device type
 */
enum HWDeviceType {
    
    /**
     * 
     * @brief Unknown device type
     */
    kHWDeviceTypeNone,

    
    /**
     * 
     * @brief Direct3d 11 Video acceleration device
     */
    kHWDeviceTypeD3D11,

    
    /**
     * 
     * @brief Cuda  hardware acceleration device
     * @note Cuda  is a hardware acceleration device under the nvidia platform
     */
    kHWDeviceTypeCuda,

    
    /**
     * 
     * @brief Qsv acceleration device under intel  platform
     */
    kHWDeviceTypeQsv,

    
    /**
     * 
     * @brief Windows  platform dx hardware acceleration device
     */
    kHWDeviceTypeDxva2,

    
    /**
     * 
     * @brief Hardware acceleration device mediacodec under Android  platform
     */
    kHWDeviceTypeMediaCodec,

    
    /**
     * 
     * @brief IOS, MACOS  platform hardware acceleration device VideoToolbox
     */
    kHWDeviceTypeVideoToolbox,
     
    /**
     * 
     * @brief Android, linux  platform hardware acceleration device egl context
     */
    kHWDeviceTypeEglContext,

    
    /**
     * 
     * @brief Linux, windows  platform hardware acceleration device va context
     */
    kHWDeviceTypeVaapi,
};


/**
 * 
 * @hidden for internal use only
 * @type keytype
 * @brief  Hardcoding device context
 */
enum HWDeviceContextKey {
    
    /**
     * 
     * @brief cuda context
     */     
    kHWDeviceContextKeyCudaContext,
    
    /**
     * 
     * @brief Derict3D11  device
     */
    kHWDeviceContextKeyD3D11Device,
    
    /**
     * 
     * @brief Derict3D11  device context
     */
    kHWDeviceContextKeyD3D11DeviceContext,
    
    /**
     * 
     * @brief Egl  device context
     */
    kHWDeviceContextKeyEglContext,
    
    /**
     * 
     * @brief Vadisplay  device context
     */
    kHWDeviceContextKeyVADisplay,
};


/**
 * 
 * @type keytype
 * @brief Hardware acceleration device context
 */
class IHWDeviceContext {
public:
    virtual ~IHWDeviceContext() = default;
    
    /**
     * 
     * @brief Get the hardware acceleration device context type
     * @return  Hardware acceleration device type. See HWDeviceType{@link #HWDeviceType}
     */
    virtual HWDeviceType deviceType() const = 0;
    
    /**
     * 
     * @brief Set property
     * @param key Hardware acceleration device context type. See ByteRTCHWDeviceContextKey:{@link #ByteRTCHWDeviceContextKey}
     * @param value Pointer to the hardware acceleration device context address
     */
    virtual void setProperty(HWDeviceContextKey key, void* value) = 0;
    
    /**
     * 
     * @brief Get the property
     * @param key Hardware acceleration device context type. See ByteRTCHWDeviceContextKey:{@link #ByteRTCHWDeviceContextKey}
     * @return  Return a pointer to the hardware acceleration device context address
     */
    virtual void* getProperty(HWDeviceContextKey key) = 0;
    
    /**
     * 
     * @brief Internal context is owned by the instance
     * @return
     *         - True: hardware device context is owned by the instance object
     *         - False: hardware device context is not owned by the instance object
     */
    virtual bool ownContext() const = 0;
    
    /**
     * 
     * @brief Sets whether context is owned by the instance object
     * @param own_context <br>
     *        - True: context is owned by the instance object
     *        - False: context is not owned by the instance object
     */
    virtual void setOwnContext(bool own_context) = 0;
    
    /**
     * 
     * @brief Transfer hardware device context,
     * @return  Pointer to hardware device context
     */
    virtual IHWDeviceContext* moveContext() = 0;
    
    /**
     * 
     * @brief Release instance object
     */
    virtual void release() = 0;
};


 /**
 * 
 * @hidden for internal use only
 * @brief create a hardware device context with specified deviceType
 */

BYTERTC_API IHWDeviceContext* createHwDeviceContext(HWDeviceType device_type);


/**
 * 
 * @hidden for internal use only
 * @brief  Set the device context information of the video source
 * @param engine <br>
 *        The engine to be set, see: IRTCVideo{@link #IRTCVideo}
 * @param hw_context <br>
 *        Set the video frame, see: IHWDeviceContext{@link #IHWDeviceContext}
 * @note Used when hardware encoding is passed in GPU memory
 */
BYTERTC_API void setVideoSourceHWDeviceContext(void* engine, IHWDeviceContext* hw_context);


/**
 * 
 * @hidden for internal use only
 * @type api
 * @region  video management
 * @brief  Send external source video data
 * @param engine <br>
 *        The engine to be set up. See IRTCVideo{@link #IRTCVideo}
 * @param frame <br>
 *         Input video frame. See IVideoFrame{@link #IVideoFrame}
 * @note
 *      1. Support YUV420P, NV12, D3D texture, Cuda memory, OpenGL texture and other formats of video frames. <br>
 *      2. This function runs in the user calling thread
 */
BYTERTC_API bool pushExternalVideoFrame(void* engine, const IVideoFrame* frame);



/**
 * 
 * @hidden for internal use only
 * @type keytype
 * @brief  Audio frame information
 */
class IEncodedAudioFrame {
public:
    virtual ~IEncodedAudioFrame() {
    }
    virtual AudioCodecType codecType() const = 0;
    virtual void setCodecType(AudioCodecType codec_type) = 0;
    virtual int sampleRate() const = 0;
    virtual void setSampleRate(int sample_rate) = 0;
    virtual int channelsNum() const = 0;
    virtual void setChannelsNum(int channels_num) = 0;
    virtual int64_t timestampUs() const = 0;
    virtual void setTimestampUs(int64_t timestamp_us) = 0;
    virtual int64_t timestampPts() const = 0;
    virtual void setTimestampPts(int64_t timestamp_pts) = 0;
    virtual int timebaseNum() const = 0;
    virtual void setTimestampNum(int timebase_num) = 0;
    virtual int timebaseDen() const = 0;
    virtual void setTimestampDen(int timebase_den) = 0;
    virtual void setStreamMemory(const ManagedMemory& memory) = 0;
    virtual uint8_t* data() const = 0;
    virtual int dataSize() const = 0;
    virtual int frameLength() const = 0;
};


 /**
 * 
 * @hidden for internal use only
 */

BYTERTC_API IEncodedAudioFrame* createEncodedAudioFrame();


/**
 * 
 * @hidden for internal use only
 * @type callback
 * @region audio data callback
 * @brief Local audio frame monitor
 */
class ILocalEncodedAudioFrameObserver  {
public:
    virtual ~ILocalEncodedAudioFrameObserver() {
    }
    
    /**
     * 
     * @type callback
     * @region Audio data callback
     * @brief Call RegisterLocalEncodedAudioFrameObserver{@link #RegisterLocalEncodedAudioFrameObserver}, when the SDK receives local audio frame information, callback the event
     * @param type Local audio frame type. See StreamIndex{@link #StreamIndex}
     * @param audio_stream Local audio frame information. See IEncodedAudioFrame{@link #IEncodedAudioFrame}
     */
    virtual void onLocalEncodedAudioFrame(StreamIndex type, const IEncodedAudioFrame& audio_stream) = 0;
};


/**
 * 
 * @hidden for internal use only
 * @type callback
 * @region audio data callback
 * @brief Remote audio frame monitor
 */
class IRemoteEncodedAudioFrameObserver  {
public:
    virtual ~IRemoteEncodedAudioFrameObserver () {
    }
    
    /**
     * 
     * @type callback
     * @region Audio data callback
     * @brief Call RegisterRemoteEncodedAudioFrameObserver{@link #RegisterRemoteEncodedAudioFrameObserver}, when the SDK receives the remote audio frame information, callback the event
     * @param stream_id The ID of the received remote audio stream
     * @param audio_stream The remote audio frame information. See IEncodedAudioFrame{@link #IEncodedAudioFrame}
     * @param stream_info Information about the received remote audio stream. See RemoteStreamKey{@link #RemoteStreamKey}
     */
    virtual void onRemoteEncodedAudioFrame(
            const char* stream_id, const IEncodedAudioFrame& audio_stream, const RemoteStreamKey& stream_info) = 0;
};



/**
 * 
 * @hidden for internal use only
 * @type api
 * @region Audio data callback
 * @brief Register the remote audio frame monitor. <br>
 *         After calling this method, every time the SDK detects a remote audio frame, it will call back the audio frame information to the user through onRemoteEncodedAudioFrame{@link #IRemoteEncodedAudioFrameObserver#onRemoteEncodedAudioFrame}
 * @param engine The engine to be set up. See IRTCVideo{@link #IRTCVideo}
 * @param observer Remote AudioFrame Monitor. See IRemoteEncodedAudioFrameObserver{@link #IRemoteEncodedAudioFrameObserver}
 * @note
 *        - This method is recommended to be called before entering the room.
 *        - Setting the parameter to nullptr cancels registration.
 */
BYTERTC_API void registerRemoteEncodedAudioFrameObserver(void* engine, IRemoteEncodedAudioFrameObserver* observer);


/**
 * 
 * @hidden for internal use only
 * @type api
 * @region Audio data callback
 * @brief Register a local audio frame monitor. <br>
 *         After calling this method, every time the SDK detects a local audio frame, it will call back the audio frame information to the user through onLocalEncodedAudioFrame{@link #ILocalEncodedAudioFrameObserver#onLocalEncodedAudioFrame}
 * @param engine The engine to be set up. See IRTCVideo{@link #IRTCVideo}
 * @param observer Local AudioFrame Monitor. See ILocalEncodedAudioFrameObserver{@link #ILocalEncodedAudioFrameObserver}
 * @note
 *        - This method is recommended to be called before entering the room.
 *        - Setting the parameter to nullptr cancels registration.
 */
BYTERTC_API void registerLocalEncodedAudioFrameObserver(void* engine, ILocalEncodedAudioFrameObserver* observer);



 /**
 * 
 * @hidden for internal use only
 */

BYTERTC_API bool pushExternalEncodedAudioFrame(void* engine, const IEncodedAudioFrame* audio_stream);


 /**
 * 
 * @hidden for internal use only
 * @type api
 */
struct MediaIoOption {
    bool enable_audio_encoding = true;
    bool enable_video_encoding = true;
    bool enable_audio_decoding = true;
    bool enable_video_decoding = true;
};


 /**
 * 
 * @hidden for internal use only
 * @type api
 */
BYTERTC_API void setupEngineMediaIo(void* engine, const MediaIoOption& option);


/**
 * 
 * @hidden for internal use only
 * @type keytype
 * @region  video data callback
 * @brief Metadata  maximum data size
 */
const int MAX_METADATA_LENGTH = 1024;



/**
 * 
 * @hidden for internal use only
 * @type callback
 * @brief  Audio device event callback
 */
class IAudioDeviceEventHandler {
public:
    
    /**
     * 
     * @type callback
     * @brief  Get microphone volume
     * @param volume <br>
     *        Volume size
     */
    virtual void onRecordingAudioVolumeIndication(int volume) = 0;

    
    /**
     * 
     * @type callback
     * @brief  Get Loopback volume
     * @param volume <br>
     *        Volume size
     */
    virtual void onLoopbackAudioVolumeIndication(int volume) = 0;
};


 /**
 * 
 * @type api
 * @region Audio Device Management
 * @brief Audio device management class Ex
 */

class IAudioDeviceManagerEx : public IAudioDeviceManager {
public:
    
    /**
     * 
     * @region Audio Facility Management
     * @brief Constructor
     */
    IAudioDeviceManagerEx() = default;

    
    /**
     * 
     * @type api
     * @region Audio Facility Management
     * @brief Destruct the current object and free memory
     * @note This function should be called when the structure is not needed to free resources related to audio operations
     */
    virtual void release() = 0;

    
    /**
     * 
     * @type api
     * @region Audio Facility Management
     * @brief Switch audio to the speaker or earpiece, the default playback device is the speaker
     * @param enable <br>
     *        - True: switch to the speaker
     *        - False: switch to the earpiece
     * @note This method is only valid on mobile devices
     */
    virtual void setEnableSpeakerphone(bool enable) = 0;

    
    /**
     * 
     * @type api
     * @region Audio Facility Management
     * @brief Start the audio capture device test. <br>
     *        This method tests whether the audio acquisition device can work properly. After starting the test, you will receive the volume information reported by the `onLocalAudioPropertiesReport` callback.
     * @param indication_interval The interval(ms) in `onLocalAudioPropertiesReport` callback. It is recommended to set to greater than 200 milliseconds. The minimum shall not be less than 10 milliseconds. Less than 10 milliseconds behavior is not defined.
     * @return  Method call result <br>
     *         - 0: Success.
     *         - < 0: failure
     * @note
     *        - This method must be called before joining the room and cannot be applied at the same time as other audio device testing functions.
     *        - You need to call stopAudioCaptureDeviceTest{@link #IAudioDeviceManagerEx#stopAudioCaptureDeviceTest} to stop the test.
     */
    virtual int startAudioCaptureDeviceTest(int indication_interval) = 0;

    
    /**
     * 
     * @type api
     * @region Audio Facility Management
     * @brief Stop audio capture device testing.
     * @return  Method call result <br>
     *         - 0: Success.
     *         - < 0: failure
     * @note  After calling startAudioCaptureDeviceTest{@link #IAudioDeviceManagerEx#startAudioCaptureDeviceTest}, you need to call this method to stop the test.
     */
    virtual int stopAudioCaptureDeviceTest() = 0;

    
    /**
     * 
     * @type api
     * @region Audio Facility Management
     * @brief Begins audio device loop testing. <br>
     *        This method tests whether the audio acquisition device and the audio playback device can work normally. Once the test starts, the audio capture device will capture the local sound <br>
     *         And play it out through the audio playback device, and the user App will receive the volume information reported by the `onLocalAudioPropertiesReport` callback.
     * @param indication_interval The time interval(ms) in `onLocalAudioPropertiesReport`. It is recommended to set to greater than 200 milliseconds. The minimum shall not be less than 10 milliseconds. Less than 10 milliseconds behavior is not defined.
     * @return   Method call result <br>
     *         - 0: Success.
     *         - < 0: failure
     * @note
     *        - This method must be called before joining the room. And cannot be applied at the same time as other audio equipment test functions.
     *        - You need to call stopAudioDeviceLoopbackTest{@link #IAudioDeviceManagerEx#stopAudioDeviceLoopbackTest} to stop the test.
     *        - This method only tests audio equipment locally and does not involve network connection.
     */
    virtual int startAudioDeviceLoopbackTest(int indication_interval) = 0;

    
    /**
     * 
     * @type api
     * @region Audio Facility Management
     * @brief Stop audio device loop testing.
     * @return  Method call result <br>
     *         - 0: Success.
     *         - < 0: failure
     * @note After calling startAudioDeviceLoopbackTest{@link #IAudioDeviceManagerEx#startAudioDeviceLoopbackTest}, you need to call this method to stop the test.
     */
    virtual int stopAudioDeviceLoopbackTest() = 0;

protected:
    
    /**
     * 
     * @hidden constructor/destructor
     * @brief Destructor
     */
    virtual ~IAudioDeviceManagerEx() = default;
};


/**
 * 
 * @deprecated since 3.51 and will be deleted in 3.53, use getAudioDeviceManager{@link #IRTCVideo#getAudioDeviceManager} instead
 * @hidden for internal use only
 * @type api
 * @brief Audio Facility Management interface is created, this interface does not depend on the engine, and is mainly used for audio Facility Management without an engine
 * @param handler <br>
 *       Audio device event callback
 * @return Audio Facility Management interface
 */
BYTERTC_API IAudioDeviceManagerEx* createAudioDeviceManager(IAudioDeviceEventHandler* handler);

}  