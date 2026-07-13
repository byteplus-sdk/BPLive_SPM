/*
 * Copyright (c) 2022 The BytePlusRTC project authors. All Rights Reserved.
 * @brief Objective-C BytePlusRTC Audio Defines
*/

#import "ByteRTCMediaDefines.h"


/**
 * 
 * @hidden(macOS)
 * @type keytype
 * @brief  Audio scenarios <br>
 *        After selecting the audio scenario, SDK will automatically select the call/media volume, according to the client-side audio device and status. <br>
 *        If the following audio scenarios cannot meet your business needs, please contact our technical support team for customization.
 */
typedef NS_ENUM(NSInteger, ByteRTCAudioScenarioType) {
    
    /**
     * 
     * @brief (Default) Music scenario. <br>
     *        This scenario is suitable for scenes that require musical expression, such as music live. <br>
     *         For different audio device and status, the selected volume type is as follows: <br>
     *         <table>
     *            <tr><th></th><th>Mic Off</th><th>Mic On</th><th>Remarks</th><tr>
     *            <tr><td>Build-in microphone and speaker</td><td>Media volume</td><td>Call volume</td><td>/</td></tr>
     *            <tr><td>Earpiece</td><td>Media volume</td><td>Call volume</td><td>/</td></tr>
     *            <tr><td>Wired headset/ USB headset/ external sound card</td><td>Media volume</td><td> Media Volume</td><td>/</td></tr>
     *            <tr><td>Bluetooth Headset</td><td>Media Volume</td><td>Media Volume</td><td>Even if the Bluetooth headset has a microphone, you can only use the build-in microphone for local audio capture.</td></tr>
     *         </table>
     */
    ByteRTCAudioScenarioMusic = 0,
    
    /**
     * 
     * @brief High-quality communication scenario <br>
     *        This scenario is suitable for scenes that require musical expression, but also want to use the microphone on the bluetooth headphones for audio capturing. <br>
     *        Media volume is perferred in this scenario. The preference may introduce switch of volume type when you switch on/off the microphone. To avoid the switch, use `ByteRTCAudioScenarioHighqualityChat`. <br>
     *        This scenario can provide decent audio performance using the speaker/bluetooth earphones. It can also avoid sudden changes of volume type when switching to bluetooth earphones. <br>
     *        For different audio device and status, the selected volume type is as follows: <br>
     *         <table>
     *            <tr><th></th><th>Mic Off</th><th>Mic On</th><th>Remarks</th><tr>
     *            <tr><td>Build-in microphone and speaker</td><td> Media volume </td><td> call volume </td><td>/</td></tr>
     *            <tr><td>Earpiece</td><td> Media volume </td><td> call volume </td><td>/</td></tr>
     *            <tr><td>Wired headset/ USB headset/ external sound card</td><td> Media volume </td><td> Media Volume </td><td>/</td></tr>
     *            <tr><td>Bluetooth Headset </td><td> Call Volume </td><td> Call Volume </td><td> Ability to use the microphone included in the Bluetooth headset for audio capture. </td></tr>
     *         </table>
     */
    ByteRTCAudioScenarioHighqualityCommunication = 1,
    
    /**
     * 
     * @brief  Call volume scenario. <br>
     *         This scenario uses the call volume regardless of the client-side audio device or status. <br>
     *         This scenario is suitable for calls or meetings that require turning on and off the microphone frequently. <br>
     *         Call volume is used the whole time and there will not be sudden changes in volume. <br>
     *         This scenario maximizes the elimination of echoes and has optimal call clarity. <br>
     *         You can use the microphone on the bluetooth earphones for audio capturing. <br>
     *         However, the volume of other audio played using media volume will be lowered, and the audio quality is worse.
     */
    ByteRTCAudioScenarioCommunication = 2,
    
    /**
     * 
     * @brief Media volume scenario. <br>
     *        This scenario uses the media volume regardless of the client-side audio device or status. <br>
     *        If the audio quality is unsatisfactory when you put on speaker, please contact our technical support team.
     */
    ByteRTCAudioScenarioMedia = 3,
    
    /**
     * 
     * @brief Game media scene. Only suitable for game scenes. <br>
     *        If the audio quality is unsatisfactory when you put on speaker, please contact our technical support team. <br>
     *        For different audio device and status, the selected volume type is as follows: <br>
     *         <table>
     *            <tr><th></th><th>Mic Off</th><th>Mic On</th><th>Remarks</th><tr>
     *            <tr><td>Build-in microphone and speaker</td><td> Media volume </td><td> Media volume </td><td>/</td></tr>
     *            <tr><td>Earpiece</td><td> Media volume </td><td> Media volume </td><td>/</td></tr>
     *            <tr><td>Wired headset/ USB headset/ external sound card</td><td> Media volume </td><td> Media Volume </td><td>/</td></tr>
     *            <tr><td> Bluetooth Headset </td><td> Call Volume </td><td> Call Volume </td><td> Ability to use the microphone included in the Bluetooth headset for audio capture. </td></tr>
     *         </table>
     */
    ByteRTCAudioScenarioGameStreaming = 4,
    
    /**
     * 
     * @brief High-quality chatting scenario <br>
     *        This scenario is the same as `ByteRTCAudioScenarioHighqualityCommunication`, but in one case: in this scenario, switching on/off the microphone does not change the volume type. When you talk with the built-in microphone and speaker/earpiece, the call volume is used all the time. <br>
     *        For different audio device and status, the selected volume type is as follows: <br>
     *         <table>
     *            <tr><th></th><th>Mic Off</th><th>Mic On</th><th>Remarks</th><tr>
     *            <tr><td>Build-in microphone and speaker</td><td> Call volume </td><td> call volume </td><td>/</td></tr>
     *            <tr><td>Earpiece</td><td> Call volume </td><td> call volume </td><td>/</td></tr>
     *            <tr><td>Wired headset/ USB headset/ external sound card</td><td> Media volume </td><td> Media Volume </td><td>/</td></tr>
     *            <tr><td> Bluetooth Headset </td><td> Call Volume </td><td> Call Volume </td><td> Ability to use the microphone included in the Bluetooth headset for audio capture. </td></tr>
     *         </table>
     */
    ByteRTCAudioScenarioHighqualityChat = 5,
};
   
   /**
    * 
    * @hidden internal use only
    * @type keytype
    * @brief If the following audio scenarios cannot meet your business needs, please contact our technical support team.
    */
typedef NS_ENUM(NSInteger, ByteRTCAudioSceneType) {

/**
    * 
    * @brief Default scenario. <br>
    *        This scenario is suitable for scenes that require musical expression, such as music live. <br>
    *        For different audio device and status, the selected volume type is as follows: <br>
             <table>
     *          <tr><th></th><th>Mic Off</th><th>Mic On</th><th>Remarks</th><tr>
     *          <tr><td>Build-in microphone and speaker</td><td>Media volume</td><td>Call volume</td><td>/</td></tr>
     *          <tr><td>Build-in earpiece</td><td>Media volume</td><td>Media volume</td><td>/</td></tr>
     *          <tr><td>Wired headset/ USB headset/ external sound card</td><td>Media volume</td><td> Media Volume</td><td>/</td></tr>
     *          <tr><td>Bluetooth Headset</td><td>Media Volume</td><td>Media Volume</td><td>Even if the Bluetooth headset has a microphone, you can only use the build-in microphone for local audio capture.</td></tr>
     *       </table>
*/  
    ByteRTCAudioSceneDefault = 0,

/**
     * 
     * @brief Chat scenario <br>
     *        This scenario uses the call volume regardless of the client-side audio device or status. <br>
     *        This scenario is suitable for calls or meetings that require turning on and off the microphone frequently. <br>
     *        Call volume is used the whole time and there will not be sudden changes in volume. <br>
     *        This scenario maximizes the elimination of echoes and has optimal call clarity. <br>
     *        You can use the microphone on the bluetooth earphones for audio capturing. <br>
     *        However, the volume of other audio played using media volume will be lowered, and the audio quality is worse.
*/
    ByteRTCAudioSceneChatRoom = 1,

/**
     * 
     * @brief High-quality chat scenarios <br>
     *        This scenario uses the media volume regardless of the client-side audio device or status. <br>
     *        If the audio quality is unsatisfactory when you put on speaker, please contact the technical support.
*/
    ByteRTCAudioSceneHighQualityChatRoom = 2,
 
/**
     * 
     * @brief low-latency scenarios <br>
     *        This scenario is suitable for low-latency scenarios such as Karaoke. <br>
     *        This scenario uses the media volume regardless of the client-side audio device or status.
*/     
    ByteRTCAudioSceneLowLatency = 3,
};


/**
 * 
 * @type keytype
 * @brief Change sound effect type. For more types, contact the technical supporters.
 */
typedef NS_ENUM(NSInteger, ByteRTCVoiceChangerType) {
    
    /**
     * 
     * @brief Acoustic, no special effects
     */
    ByteRTCVoiceChangerOriginal = 0,
    
    /**
     * 
     * @brief Giant
     */
    ByteRTCVoiceChangerGiant = 1,
    
    /**
     * 
     * @brief Chipmunk
     */
    ByteRTCVoiceChangerChipmunk = 2,
    
    /**
     * 
     * @brief Little yellow man
     */
    ByteRTCVoiceChangerMinionst = 3,
    
    /**
     * 
     * @brief Trill
     */
    ByteRTCVoiceChangerVibrato = 4,
    
    /**
     * 
     * @brief Robot
     */
    ByteRTCVoiceChangerRobot = 5,
    
    /**
     * 
     * @brief Extra Terrestrial
     */
    ByteRTCVoiceChangerExtraTerrestrial = 6,
    
    /**
     * 
     * @brief Baritone
     */
    ByteRTCVoiceChangerBaritone = 7,
    
    /**
     * 
     * @brief Battery Drain
     */
    ByteRTCVoiceChangerBatteryDrain = 8,
    
    /**
     * 
     * @brief Devil
     */
    ByteRTCVoiceChangerDevil = 9,
    
    /**
     * 
     * @brief Little Fox
     */
    ByteRTCVoiceChangerLittleFox = 10,
    
    /**
     * 
     * @brief Megaphone
     */
    ByteRTCVoiceChangerMegaphone = 11,
    
    /**
     * 
     * @brief Mic
     */
    ByteRTCVoiceChangerMic = 12,
    
    /**
     * 
     * @brief Space Robot
     */
    ByteRTCVoiceChangerSpaceRobot = 13,
    
    /**
     * 
     * @brief Squirrel
     */
    ByteRTCVoiceChangerSquirrel = 14,
    
    /**
     * 
     * @brief Sweet Girl
     */
    ByteRTCVoiceChangerSweetGirl = 15,
    
    /**
     * 
     * @brief MrMystery
     */
    ByteRTCVoiceChangerMrMystery = 16,
};


/**
 * 
 * @type keytype
 * @brief  Reverb effect type
 */
typedef NS_ENUM(NSInteger, ByteRTCVoiceReverbType) {
    
    /**
     * 
     * @brief Acoustic, no special effects
     */
    ByteRTCVoiceReverbOriginal = 0,
    
    /**
     * 
     * @brief Echo
     */
    ByteRTCVoiceReverbEcho = 1,
    
    /**
     * 
     * @brief Concert
     */
    ByteRTCVoiceReverbConcert = 2,
    
    /**
     * 
     * @brief Ethereal
     */
    ByteRTCVoiceReverbEthereal = 3,
    
    /**
     * 
     * @brief Karaoke
     */
    ByteRTCVoiceReverbKTV = 4,
    
    /**
     * 
     * @brief Recording studio
     */
    ByteRTCVoiceReverbStudio = 5,
    
    /**
     * 
     * @brief Virtual Stereo
     */
    ByteRTCVoiceReverbVirtualStereo = 6,
    
    /**
     * 
     * @brief Spacious
     */
    ByteRTCVoiceReverbSpacious = 7,
    
    /**
     * 
     * @brief 3D vocal
     */
    ByteRTCVoiceReverb3D = 8,
    
    /**
     * 
     * @hidden internal use
     * @brief Pop
     */
    ByteRTCVoiceReverbPop = 9,
    
    /**
     * 
     * @hidden internal use
     * @brief Disco
     */
    ByteRTCVoiceReverbDisco = 10,
    
    /**
     * 
     * @hidden internal use
     * @brief Old Record
     */
    ByteRTCVoiceReverbOldRecord = 11,
    
    /**
     * 
     * @hidden internal use
     * @brief Harmony
     */
    ByteRTCVoiceReverbHarmony = 12,
    
    /**
     * 
     * @hidden internal use
     * @brief Rock
     */
    ByteRTCVoiceReverbRock = 13,
    
    /**
     * 
     * @hidden internal use
     * @brief Blues
     */
    ByteRTCVoiceReverbBlues = 14,
    
    /**
     * 
     * @hidden internal use
     * @brief Jazz
     */
    ByteRTCVoiceReverbJazz = 15,
    
    /**
     * 
     * @hidden internal use
     * @brief Electronic
     */
    ByteRTCVoiceReverbElectronic = 16,
    
    /**
     * 
     * @hidden internal use
     * @brief Vinyl
     */
    ByteRTCVoiceReverbVinyl = 17,
    
    /**
     * 
     * @hidden internal use
     * @brief Chamber
     */
    ByteRTCVoiceReverbChamber = 18,

    
    /**
     * 
     * @hidden internal use
     * @brief Enhance Original
     */
    ByteRTCVoiceReverbEnhanceOriginal = 19,

    
    /**
     * 
     * @hidden internal use
     * @brief Bathroom
     */
    ByteRTCVoiceReverbBathroom = 20,

    
    /**
     * 
     * @hidden internal use
     * @brief Natural
     */
    ByteRTCVoiceReverbNatural = 21,

    
    /**
     * 
     * @hidden internal use
     * @brief Hallway
     */
    ByteRTCVoiceReverbHallway = 22,
};

/**
 * 
 * @type keytype
 * @brief Audio Equalization effect.
 */
typedef NS_ENUM(NSInteger, ByteRTCBandFrequency) {
    
    /**
     * 
     * @brief The frequency band with a center frequency of 31Hz.
     */
    ByteRTCBandFrequency31 = 0,
    
    /**
     * 
     * @brief The frequency band with a center frequency of 62Hz.
     */
    ByteRTCBandFrequency62 = 1,
    
    /**
     * 
     * @brief The frequency band with a center frequency of 125Hz.
     */
    ByteRTCBandFrequency125 = 2,
    
    /**
     * 
     * @brief The frequency band with a center frequency of 250Hz.
     */
    ByteRTCBandFrequency250 = 3,
    
    /**
     * 
     * @brief The frequency band with a center frequency of 500Hz.
     */
    ByteRTCBandFrequency500 = 4,
    
    /**
     * 
     * @brief The frequency band with a center frequency of 1kHz.
     */
    ByteRTCBandFrequency1k = 5,
    
    /**
     * 
     * @brief The frequency band with a center frequency of 2kHz.
     */
    ByteRTCBandFrequency2k = 6,
    
    /**
     * 
     * @brief The frequency band with a center frequency of 4kHz.
     */
    ByteRTCBandFrequency4k = 7,
    
    /**
     * 
     * @brief The frequency band with a center frequency of 8kHz.
     */
    ByteRTCBandFrequency8k = 8,
    
    /**
     * 
     * @brief The frequency band with a center frequency of 16kHz.
     */
    ByteRTCBandFrequency16k = 9,
};

/**
 * 
 * @type keytype
 * @brief Voice equalization effect.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCVoiceEqualizationConfig : NSObject

/**
 * 
 * @brief Frequency band. See ByteRTCBandFrequency{@link #ByteRTCBandFrequency}.
 */
@property(assign, nonatomic) ByteRTCBandFrequency frequency;

/**
 * 
 * @brief Gain of the frequency band in dB. The range is `[-15, 15]`.
 */
@property(assign, nonatomic) int gain;
@end


/**
 * 
 * @type keytype
 * @brief Voice reverb effect.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCVoiceReverbConfig : NSObject

/**
 * 
 * @brief The room size for reverb simulation. The range is `[0.0, 100.0]`. The default value is `50.0f`. The larger the room, the stronger the reverberation.
 */
@property(assign, nonatomic) float roomSize;

/**
 * 
 * @brief The decay time of the reverb effect. The range is `[0.0, 100.0]`. The default value is `50.0f`.
 */
@property(assign, nonatomic) float decayTime;

/**
 * 
 * @brief The damping index of the reverb effect. The range is `[0.0, 100.0]`. The default value is `50.0f`.
 */
@property(assign, nonatomic) float damping;

/**
 * 
 * @brief The Intensity of the wet signal in dB. The range is `[-20.0, 10.0]`. The default value is `0.0f`.
 */
@property(assign, nonatomic) float wetGain;

/**
 * 
 * @brief The Intensity of the dry signal in dB. The range is `[-20.0, 10.0]`. The default value is `0.0f`.
 */
@property(assign, nonatomic) float dryGain;

/**
 * 
 * @brief The delay of the wet signal in ms. The range is `[0.0, 200.0]`. The default value is `0.0f`.
 */
@property(assign, nonatomic) float preDelay;
@end


/**
 * 
 * @type keytype
 * @brief Sound quality
 */
typedef NS_ENUM(NSInteger, ByteRTCAudioProfileType) {
    
    /**
     * 
     * @brief Default sound quality <br>
     *        The sound quality configuration of ByteRTCRoomProfile{@link #ByteRTCRoomProfile} set by the server or client.
     */
    ByteRTCAudioProfileDefault = 0,
    
    /**
     * 
     * @brief Fluent <br>
     *        Sample rate: 16 KHz <br>
     *        Mono-channel <br>
     *        Encoding bitrate: 32 Kpbs <br>
     *        Low resource consumption, and small network packets guarantees a smooth call. It is suitable for most game scenarios, such as team-wide voice chat, group-wide voice chat, nation-wide voice chat.
     */
    ByteRTCAudioProfileFluent = 1,
    
    /**
     * 
     * @brief Mono-channel standard <br>
     *        Sample rate: 24 KHz <br>
     *        Encoding bitrate: 48 Kpbs <br>
     *        For scenarios requiring distinct voice, you can choose this mode, which achieves balanced latency, consumption, and network packets. It is suitable for educational Apps and the online Mafia Games.
     */
    ByteRTCAudioProfileStandard = 2,
    
    /**
     * 
     * @brief Dual-channel music <br>
     *        Sample rate: 48 KHz <br>
     *        Encoding bitrate: 128 Kpbs <br>
     *        This mode provides high-resolution audio at a cost of high latency, consumption, and large network packets. It is suitable for music Apps such as co-hosting and online talent contests. <br>
     *        Not recommended for game Apps.
     */
    ByteRTCAudioProfileHD = 3,
    
    /**
     * 
     * @brief Dual-channel standard <br>
     *        Sample rate: 48 KHz <br>
     *        Encoding bitrate: 80 Kpbs
     */
    ByteRTCAudioProfileStandardStereo = 4,
    
    /**
     * 
     * @brief Mono-channel music <br>
     *        Sample rate: 48 KHz <br>
     *        Encoding bitrate: 64 Kpbs
     */
    ByteRTCAudioProfileHDMono = 5,
};


/**
 * 
 * @type keytype
 * @brief ANC modes. The ANC algorithm is determined by the room profile you set when calling joinRoom:userInfo:roomConfig:{@link #ByteRTCRoom#joinRoom:userInfo:roomConfig:}.
 */
typedef NS_ENUM(NSInteger, ByteRTCAnsMode) {
    
    /**
     * 
     * @brief Disable ANC.
     */
    ByteRTCAnsModeDisable = 0,
   
    /**
     * 
     * @brief Cancel subtle background noise.
     */
    ByteRTCAnsModeLow = 1,
    
    /**
     * 
     * @brief Cancel medium-level, continuous noise, such as the sound of fans or air conditioners.
     */
    ByteRTCAnsModeMedium = 2,
     
    /**
     * 
     * @brief Cancel loud, impulsive, and intermittent noise, such as keyboard clicking noise, a crash/clash, a bark, and chair scraping noise.
     */
    ByteRTCAnsModeHigh = 3,
    
    /**
     * 
     * @brief Enable automatic ANC. The ANC algorithm is dynamically determined by RTC.
     */
    ByteRTCAnsModeAutomatic = 4,
};


/**
 * 
 * @hidden
 * @deprecated since 3.45 and will be deleted in 3.51.
 * @type keytype
 * @brief Voice call mode, use this interface to set your own sending mode in team voice
 */
typedef NS_ENUM(NSUInteger, ByteRTCRangeAudioMode) {
    
    /**
     * 
     * @brief Default mode
     */
    ByteRTCRangeAudioModeUndefined = 0,
    
    /**
     * 
     * @brief Squad mode
     */
    ByteRTCRangeAudioModeTeam = 1,
    
    /**
     * 
     * @brief World mode
     */
    ByteRTCRangeAudioModeWorld = 2,
};


/**
 * 
 * @type keytype
 * @brief Type of audio device
 */
typedef NS_ENUM(NSInteger, ByteRTCAudioDeviceType) {
    
    /**
     * 
     * @brief Unknown device
     */
    ByteRTCAudioDeviceTypeUnknown = -1,
    
    /**
     * 
     * @brief Screen audio recorder
     */
    ByteRTCAudioDeviceTypeRenderDevice = 0,
    
    /**
     * 
     * @brief Microphone
     */
    ByteRTCAudioDeviceTypeCaptureDevice = 1,
    
    /**
     * 
     *@brief Screen audio recorder
     */
    ByteRTCAudioDeviceTypeScreenCaptureDevice = 2
};

/**
 * 
 * @type keytype
 * @brief Audio sample rate in Hz.
 */
typedef NS_ENUM(NSInteger, ByteRTCAudioSampleRate) {
    
    /**
     * 
     * @brief Default value. 48000Hz.
     */
    ByteRTCAudioSampleRateAuto = -1,
    
    /**
     * 
     * @brief 8000Hz
     */
    ByteRTCAudioSampleRate8000 = 8000,
    
    /**
     * 
     * @brief 16000Hz
     */
    ByteRTCAudioSampleRate16000 = 16000,
    
    /**
     * 
     * @brief 32000Hz
     */
    ByteRTCAudioSampleRate32000 = 32000,
    
    /**
     * 
     * @brief 44100Hz
     */
    ByteRTCAudioSampleRate44100 = 44100,
    
    /**
     * 
     * @brief 48000Hz
     */
    ByteRTCAudioSampleRate48000 = 48000
};

/**
 * 
 * @type keytype
 * @brief Audio channel
 */
typedef NS_ENUM(NSInteger, ByteRTCAudioChannel) {
    
    /**
     * 
     * @brief Default value. `2` by default.
     */
    ByteRTCAudioChannelAuto = -1,
    
    /**
     * 
     * @brief Mono channel.
     */
    ByteRTCAudioChannelMono = 1,
    
    /**
     * 
     * @brief Dual channels.
     */
    ByteRTCAudioChannelStereo = 2,
};


/**
 * 
 * @deprecated since 3.52, use ByteRTCMixedStreamAudioCodecType{@link #ByteRTCMixedStreamAudioCodecType} instead.
 * @type keytype
 * @brief The audio codec.
 */
typedef NS_ENUM(NSInteger, ByteRTCTranscodingAudioCodec) {
    
    /**
     * 
     * @type keytype
     * @brief AAC format.
     */
    ByteRTCTranscodingAudioCodecAAC = 0,
};


/**
 * 
 * @type keytype
 * @brief The audio codec.(New)
 */
typedef NS_ENUM(NSInteger, ByteRTCMixedStreamAudioCodecType) {
    
    /**
     * 
     * @type keytype
     * @brief AAC format.
     */
    ByteRTCMixedStreamAudioCodecTypeAAC = 0,
};


/**
 * 
 * @type keytype
 * @brief Advanced Audio Coding (AAC) profile.
 */
typedef NS_ENUM(NSInteger, ByteRTCMixedStreamAudioProfile) {
    
    /**
     * 
     * @brief (Default) AAC Low-Complexity profile (AAC-LC).
     */
    ByteRTCMixedStreamAudioProfileLC   = 0,
    
    /**
     * 
     * @brief HE-AAC v1 profile (AAC LC with SBR).
     */
    ByteRTCMixedStreamAudioProfileHEv1 = 1,
    
    /**
     * 
     * @brief HE-AAC v2 profile (AAC LC with SBR and Parametric Stereo).
     */
    ByteRTCMixedStreamAudioProfileHEv2 = 2,
};


/**
 * 
 * @deprecated since 3.52, use ByteRTCMixedStreamAudioProfile{@link #ByteRTCMixedStreamAudioProfile} instead.
 * @type keytype
 * @brief Advanced Audio Coding (AAC) profile.
 */
typedef NS_ENUM(NSInteger, ByteRTCAACProfile) {
    
    /**
     * 
     * @brief (Default) AAC Low-Complexity profile (AAC-LC).
     */
    ByteRTCAACProfileLC   = 0,
    
    /**
     * 
     * @brief HE-AAC v1 profile (AAC LC with SBR).
     */
    ByteRTCAACProfileHEv1 = 1,
    
    /**
     * 
     * @brief HE-AAC v2 profile (AAC LC with SBR and Parametric Stereo).
     */
    ByteRTCAACProfileHEv2 = 2,
};

/**
 * 
 * @type keytype
 * @brief Audio playback device
 */
typedef NS_ENUM(NSInteger, ByteRTCAudioRoute) {
    
    /**
     * 
     * @brief The audio route set by `setDefaultAudioRoute:`, or the AirPlay device.
     */
    ByteRTCAudioRouteDefault = -1,
    
    /**
     * 
     * @brief Wired earphones
     */
    ByteRTCAudioRouteHeadset = 1,
    
    /**
     * 
     * @brief Earpiece. Built-in device for calling
     */
    ByteRTCAudioRouteEarpiece = 2,
    
    /**
     * 
     * @brief Speaker. Built-in device for hands-free audio playing
     */
    ByteRTCAudioRouteSpeakerphone = 3,
    
    /**
     * 
     * @brief Bluetooth earphones
     */
    ByteRTCAudioRouteHeadsetBluetooth = 4,
    
    /**
     * 
     * @hidden(macOS)
     * @brief USB Device or 3.5mm earphones connected by Lightning adapter. <br>
     *        Only available on iOS 16 and above.
     */
    ByteRTCAudioRouteHeadsetUSB = 5,
};


/**
 * 
 * @type keytype
 * @brief  Audio playback device <br>
 *        When the audio playback device changes, you will receive the `rtcEngine:onAudioPlaybackDeviceChanged:` callback.
 */
typedef NS_ENUM(NSInteger, ByteRTCAudioPlaybackDevice) {
    
    /**
     * 
     * @brief Wired earphones
     */
    ByteRTCAudioPlaybackDeviceHeadset = 1,
    
    /**
     * 
     * @brief Earpiece
     */
    ByteRTCAudioPlaybackDeviceEarpiece = 2,
    
    /**
     * 
     * @brief Speaker
     */
    ByteRTCAudioPlaybackDeviceSpeakerphone = 3,
    
    /**
     * 
     * @brief Bluetooth earphones
     */
    ByteRTCAudioPlaybackDeviceHeadsetBluetooth = 4,
    
    /**
     * 
     * @brief USB Device
     */
    ByteRTCAudioPlaybackDeviceHeadsetUSB = 5,
};


/**
 * 
 * @type keytype
 * @brief Speech recognition service authentication method, please consult the speech recognition service related classmates for details
 */
typedef NS_ENUM(NSInteger, ByteRTCASRAuthorizationType) {
    
    /**
     * 
     *  @brief Use token without setting the encrypted form.
     */
    ByteRTCASRAuthorizationTypeToken = 0,
    
    /**
     * 
     *  @brief With token additional use of signature encryption, this form of encryption requires additional pass secret token.
     */
    ByteRTCASRAuthorizationTypeSignature = 1,
};


/**
 * 
 * @type keytype
 * @brief Speech recognition service error code. <br>
 *        Except for errors caused by network reasons, the speech recognition service will retry itself, other errors will stop the service. At this time, it is recommended to call `startASR:handler:` to restart the speech recognition function.
 */
typedef NS_ENUM(NSInteger, ByteRTCASRErrorCode) {
    
    /**
     * 
     * @brief The network connection is broken, the service is unavailable, and internal reconnection will be carried out
     */
    ByteRTCASRErrorNetworkInterrupted = -1,
    
    /**
     * 
     * @brief The user has called `startASR:handler:`. <br>
     *         After starting the speech recognition service, you need to call `stopASR` to stop the speech recognition service before starting the service again.
     */
    ByteRTCASRErrorAlreadyStarted = -2,
    
    /**
     * 
     * @brief The token required by the speech recognition service is empty
     */
    ByteRTCASRErrorTokenEmpty = -3,
    
    /**
     * 
     * @brief Signature  The secretKey is empty in authentication mode
     */
    ByteRTCErrorSignatureKeyEmpty = -4,
    
    /**
     * 
     * @brief User ID is empty
     */
    ByteRTCASRErrorUserIdNull = -5,
    
    /**
     * 
     * @brief Application ID is empty
     */
    ByteRTCASRErrorAPPIDNull = -6,
    
    /**
     * 
     * @brief Speech recognition service cluster is empty
     */
    ByteRTCASRErrorClusterNull = -7,
    
    /**
     * 
     * @brief The speech recognition service connection failed, this version does not have speech recognition function, please contact RTC technical support.
     */
    ByteRTCASRErrorOperationDenied = -8
};


/**
 * 
 * @type keytype
 * @brief Mixing type
 */
typedef NS_ENUM(NSInteger, ByteRTCAudioMixingType) {
    
    /**
     * 
     * @brief Played at the local device only
     */
    ByteRTCAudioMixingTypePlayout = 0,
    
    /**
     * 
     * @brief Sent to the remote devices only
     */
    ByteRTCAudioMixingTypePublish = 1,
    
    /**
     * 
     * @brief Played at the local device and sent to the remote devices.
     */
    ByteRTCAudioMixingTypePlayoutAndPublish = 2
};


/**
 * 
 * @type keytype
 * @brief  Mix playback channel type
 */
typedef NS_ENUM(NSInteger, ByteRTCAudioMixingDualMonoMode) {
    
    /**
     * 
     * @brief Consistent with audio files
     */
    ByteRTCAudioMixingDualMonoModeAuto = 0,
    
    /**
     * 
     * @brief Only the left channel audio in the audio file can be heard
     */
    ByteRTCAudioMixingDualMonoModeL = 1,
    
    /**
     * 
     * @brief Only the right channel audio in the audio file can be heard
     */
    ByteRTCAudioMixingDualMonoModeR = 2,
    
    /**
     * 
     * @brief Both the left and right channel audio in the file can be heard at the same time
     */
    ByteRTCAudioMixingDualMonoModeMix = 3
};


/**
 * 
 * @type keytype
 * @brief  Audio mix file playback status.
 */
typedef NS_ENUM(NSInteger, ByteRTCAudioMixingState) {
    
    /**
     * 
     * @brief Mix loaded
     */
    ByteRTCAudioMixingStatePreloaded = 0,
    
    /**
     * 
     * @brief Mix is playing
     */
    ByteRTCAudioMixingStatePlaying,
    
    /**
     * 
     * @brief Mix Pause
     */
    ByteRTCAudioMixingStatePaused,
    
    /**
     * 
     * @brief Mixing stopped
     */
    ByteRTCAudioMixingStateStopped,
    
    /**
     * 
     * @brief Mix playback failed
     */
    ByteRTCAudioMixingStateFailed,
    
    /**
     * 
     * @brief End of mixing
     */
    ByteRTCAudioMixingStateFinished,
    
    /**
     * 
     * @brief PCM mixing enabled
     */
    ByteRTCAudioMixingStatePCMEnabled,
    
    /**
     * 
     * @brief PCM mixing disabled
     */
    ByteRTCAudioMixingStatePCMDisabled,
};

/**
 * 
 * @type keytype
 * @brief Error code for audio mixing
 */
typedef NS_ENUM(NSInteger, ByteRTCAudioMixingError) {
    
    /**
     * 
     * @brief OK
     */
    ByteRTCAudioMixingErrorOk = 0,
    
    /**
     * 
     * @brief Preload failed. Invalid path or the length exceeds 20s.
     */
    ByteRTCAudioMixingErrorPreloadFailed,
    
    /**
     * 
     * @brief Mixing failed. Invalid path or fail to open the file.
     */
    ByteRTCAudioMixingErrorStartFailed,
    
    /**
     * 
     * @brief Invalid mixID
     */
    ByteRTCAudioMixingErrorIdNotFound,
    
    /**
     * 
     * @brief Invalid position
     */
    ByteRTCAudioMixingErrorSetPositionFailed,
    
    /**
     * 
     * @brief Invalid volume. The range is [0, 400].
     */
    ByteRTCAudioMixingErrorInValidVolume,
    
    /**
     * 
     * @brief Another file was preloaded for mixing. Call unloadAudioMixing:{@link #ByteRTCAudioMixingManager#unloadAudioMixing:} first.
     */
    ByteRTCAudioMixingErrorLoadConflict,
    
    /**
     * 
     * @brief Invalid mix type.
     */
    ByteRTCAudioMixingErrorIdTypeNotMatch,
    
    /**
     * 
     * @brief Invalid pitch value.
     */
    ByteRTCAudioMixingErrorInValidPitch,
    
    /**
     * 
     * @brief Invalid audio track.
     */
    ByteRTCAudioMixingErrorInValidAudioTrack,
    
    /**
     * 
     * @brief Mixing starting.
     */
    ByteRTCAudioMixingErrorIsStarting,
    
    /**
     * 
     * @brief Invalid playback speed
     */
    ByteRTCAudioMixingErrorInValidPlaybackSpeed,
};

/**
 * 
 * @type keytype
 * @brief Custom audio source mode
 */
typedef NS_ENUM(NSInteger, ByteRTCMediaPlayerCustomSourceMode) {
    
    /**
     * 
     * @brief When you use the local PCM data, use this mode.
     */
    ByteRTCMediaPlayerCustomSourceModePush = 0,
    
    /**
     * 
     * @brief When you use the audio data from local memory, use this mode.
     */
    ByteRTCMediaPlayerCustomSourceModePull,
};

/**
 * 
 * @type keytype
 * @brief Custom audio source stream type
 */
typedef NS_ENUM(NSInteger, ByteRTCMediaPlayerCustomSourceStreamType) {
    
    /**
     * 
     * @brief When you use the local PCM data, use this type.
     */
    ByteRTCMediaPlayerCustomSourceStreamTypeRaw = 0,
    
    /**
     * 
     * @brief When you use the audio data from local memory, use this type.
     */
    ByteRTCMediaPlayerCustomSourceStreamTypeEncoded,
};

/**
 * 
 * @type keytype
 * @brief The starting position where audio data seeking begins.
 */
typedef NS_ENUM(NSInteger, ByteRTCMediaPlayerCustomSourceSeekWhence) {
    
    /**
     * 
     * @brief Seeks from the head of the audio data and the position of actual data offset after seeking is offset.
     */
    ByteRTCMediaPlayerCustomSourceSeekWhenceSet = 0,
    
    /**
     * 
     * @brief Seeks from a specific position of the audio data stream, and the actual data offset after seeking is the current position plus offset.
     */
    ByteRTCMediaPlayerCustomSourceSeekWhenceCur = 1,
    
    /**
     * 
     * @brief Seeks from the end of the audio data, and the actual data offset after seeking is the whole data length plus offset.
     */
    ByteRTCMediaPlayerCustomSourceSeekWhenceEnd = 2,
    
    /**
     * 
     * @brief Returns the size of audio data.
     */
    ByteRTCMediaPlayerCustomSourceSeekWhenceSize = 3,
};

/**
 * 
 * @type keytype
 * @brief Player state.
 */
typedef NS_ENUM(NSInteger, ByteRTCPlayerState) {
    
    /**
     * 
     * @brief Not started.
     */
    ByteRTCPlayerStateIdle = 0,
    
    /**
     * 
     * @brief Preloaded.
     */
    ByteRTCPlayerStatePreloaded,
    
    /**
     * 
     * @brief Opened.
     */
    ByteRTCPlayerStateOpened,
    
    /**
     * 
     * @brief Playing.
     */
    ByteRTCPlayerStatePlaying,
    
    /**
     * 
     * @brief Paused.
     */
    ByteRTCPlayerStatePaused,
    
    /**
     * 
     * @brief Stopped.
     */
    ByteRTCPlayerStateStopped,
    
    /**
     * 
     * @brief Failed.
     */
    ByteRTCPlayerStateFailed,
    
    /**
     * 
     * @brief Finished.
     */
    ByteRTCPlayerStateFinished,
};

/**
 * 
 * @type keytype
 * @brief Error code for audio playout.
 */
typedef NS_ENUM(NSInteger, ByteRTCPlayerError) {
    
    /**
     * 
     * @brief OK
     */
    ByteRTCPlayerErrorOK = 0,
    
    /**
     * 
     * @brief Format not supported.
     */
    ByteRTCPlayerErrorFormatNotSupport,
    
    /**
     * 
     * @brief Invalid file path.
     */
    ByteRTCPlayerErrorInvalidPath,
    
    /**
     * 
     * @brief The prerequisite is not met. Check the specific API doc.
     */
    ByteRTCPlayerErrorInvalidState,
    
    /**
     * 
     * @brief Invalid position.
     */
    ByteRTCPlayerErrorInvalidPosition,
    
    /**
     * 
     * @brief Invalid volume.
     */
    ByteRTCPlayerErrorInvalidVolume,
    
    /**
     * 
     * @brief Invalid pitch value.
     */
    ByteRTCPlayerErrorInvalidPitch,
    
    /**
     * 
     * @brief Invalid audio track.
     */
    ByteRTCPlayerErrorInvalidAudioTrackIndex,
    
    /**
     * 
     * @brief Invalid playback speed.
     */
    ByteRTCPlayerErrorInvalidPlaybackSpeed,
    
    /**
     * 
     * @brief Invalid effect ID. Receive this error code when you call other APIs before the audio file is preloaded or opened.
     */
    ByteRTCPlayerErrorInvalidEffectId,
};


/**
 * 
 * @type keytype
 * @brief  Audio input source type
 */
typedef NS_ENUM(NSInteger, ByteRTCAudioSourceType) {
    
    /**
     * 
     * @brief Custom Capture Audio Source
     */
    ByteRTCAudioSourceTypeExternal = 0,
    
    /**
     * 
     * @brief RTC SDK internal acquisition audio source
     */
    ByteRTCAudioSourceTypeInternal,
};


/**
 * 
 * @type keytype
 * @brief  Audio output type
 */
typedef NS_ENUM(NSInteger, ByteRTCAudioRenderType) {
    
    /**
     * 
     * @brief Custom render Audio
     */
    ByteRTCAudioRenderTypeExternal = 0,
    
    /**
     * 
     * @brief RTC SDK internal render audio
     */
    ByteRTCAudioRenderTypeInternal,
};


/**
 * 
 * @type keytype
 * @brief Enables/disables in-ear monitoring.
 */
typedef NS_ENUM(NSInteger, ByteRTCEarMonitorMode) {
    
    /**
     * 
     * @brief Disable in-ear monitoring.
     */
    ByteRTCEarMonitorModeOff = 0,
    
    /**
     * 
     * @brief Enable in-ear monitoring.
     */
    ByteRTCEarMonitorModeOn = 1,
};


/**
 * 
 * @type keytype
 * @brief Audio data callback method
 */
typedef NS_ENUM(NSInteger, ByteRTCAudioFrameCallbackMethod) {
    
    /**
     * 
     * @brief The callback of the audio data recorded by local microphone.
     */
    ByteRTCAudioFrameCallbackRecord = 0,
    
    /**
     * 
     * @brief The callback of the mixed audio data of all remote users subscribed by the local user.
     */
    ByteRTCAudioFrameCallbackPlayback = 1,
    
    /**
     * 
     * @brief The callback of the mixed audio data including the data recorded by local microphone and that of all remote users subscribed by the local user.
     */
    ByteRTCAudioFrameCallbackMixed = 2,
    
    /**
     * 
     * @brief The callback of the audio data before mixing of each remote user subscribed by the local user.
     */
    ByteRTCAudioFrameCallbackRemoteUser = 3,
    
    /**
     * 
     * @brief The callback of the audio data recorded by local microphone and the audio data playback local.
     */
    ByteRTCAudioFrameCallbackCaptureMixed = 5
};

/**
 * 
 * @type keytype
 * @brief The audio input for the audio processor.
 */
typedef NS_ENUM(NSInteger, ByteRTCAudioFrameMethod) {
    
    /**
     * 
     * @brief Locally captured audio frame.
     */
    ByteRTCAudioFrameProcessorRecord = 0,
    
    /**
     * 
     * @brief The mixed remote audio.
     */
    ByteRTCAudioFrameProcessorPlayback = 1,
    
    /**
     * 
     * @brief The audio streams from remote users.
     */
    ByteRTCAudioFrameProcessorRemoteUser = 2,
    
    /**
     * 
     * @hidden(macOS)
     * @brief The SDK-level in-ear monitoring.
     */
    ByteRTCAudioFrameProcessorEarMonitor = 3,
     
    /**
     * 
     * @brief The shared-screen audio.
     */
    ByteRTCAudioFrameProcessorScreen = 4,
};


/**
 * 
 * @type keytype
 * @brief The volume callback modes.
 */
typedef NS_ENUM(NSInteger, ByteRTCAudioReportMode) {
     
    /**
     * 
     * @brief Always-on(Default).
     */
    ByteRTCAudioReportModeNormal = 0,
   
    /**
     * 
     * @brief After visibly joining a room and unpublish your streams, disable the volume callback.
     */
    ByteRTCAudioReportModeDisconnect = 1,
     
    /**
     * 
     * @brief After visibly joining a room and unpublish your streams, enable the volume callback. The volume is reset to 0.
     */
    ByteRTCAudioReportModeReset = 2,
};


/**
 * 
 * @type keytype
 * @brief The audio info included in rtcEngine:onLocalAudioPropertiesReport:{@link #ByteRTCVideoDelegate#rtcEngine:onLocalAudioPropertiesReport:}.
 */
typedef NS_ENUM(NSInteger, ByteRTCAudioPropertiesMode) {
    
    /**
     * 
     * @brief Only locally captured microphone audio info and locally captured screen audio info are included.
     */
    ByteRTCAudioPropertiesModeMicrohone = 0,
    
    /**
     * 
     * @brief The following information are included: <br>
     *        - Locally captured microphone audio info and locally captured screen audio info;
     *        - Locally audio mixing info.
     */
    ByteRTCAudioPropertiesModeAudioMixing = 1
};


/**
 * 
 * @type keytype
 * @brief User ID of the source of the audio stream, and the corresponding volume.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCAudioVolumeInfo : NSObject

/**
 * 
 * @brief User of the audio stream source ID
 */
@property(copy, nonatomic) NSString * _Nonnull uid;

/**
 * 
 * @brief LinearVolume, range: [0,255]
 */
@property(assign, nonatomic) NSUInteger linearVolume;

/**
 * 
 * @brief NonlinearVolume, range: [-127,0]
 */
@property(assign, nonatomic) NSUInteger nonlinearVolume;
@end


/**
 * 
 * @type keytype
 * @brief Audio parameters format
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCAudioFormat : NSObject

/**
 * 
 * @brief Audio sampling rate. See ByteRTCAudioSampleRate{@link #ByteRTCAudioSampleRate}
 */
@property(nonatomic, assign) ByteRTCAudioSampleRate sampleRate;

/**
 * 
 * @brief For audio channels. See ByteRTCAudioChannel{@link #ByteRTCAudioChannel}
 */
@property(nonatomic, assign) ByteRTCAudioChannel channel;

/**
 * 
 * @brief Samples per audio frame returned by callback. `0` by default. The default samples per callback is the minimum value. <br>
 *        The minimum value is `sampleRate * channel * 0.01s`, the value when the callback interval is 0.01s. <br>
 *        The maximum value is `2048`. If the value is invalid, the samples per callback uses the default value. <br>
 *        This parameter only takes effect when setting the read-write callback. It does not take effect when calling enableAudioFrameCallback:format:{@link #ByteRTCVideo#enableAudioFrameCallback:format:} to enable read-only callback.
 */
@property(nonatomic, assign) int samplesPerCall;
@end


/**
 * 
 * @type keytype
 * @brief Audio frame in PCM
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCAudioFrame : NSObject

/**
 * 
 * @brief PCM data
 */
@property(strong, nonatomic) NSData * _Nonnull buffer;

/**
 * 
 * @brief Total sampling number
 */
@property(assign, nonatomic) int samples;

/**
 * 
 * @brief Audio channel. See ByteRTCAudioChannel{@link #ByteRTCAudioChannel}. <br>
 *        For dual channels, the audio frames are interleaved.
 */
@property(assign, nonatomic) ByteRTCAudioChannel channel;

/**
 * 
 * @brief Sample rate. See ByteRTCAudioSampleRate{@link #ByteRTCAudioSampleRate}.
 */
@property(assign, nonatomic) ByteRTCAudioSampleRate sampleRate;
@end


/**
 * 
 *  @type callback
 *  @brief Audio data callback observer <br>
 * Note: Callback functions are thrown synchronously in a non-UI thread within the SDK. Therefore, you must not perform any time-consuming operations or direct UI operations within the callback function, as this may cause the app to crash. <br>
 * The time interval for all callback functions in this interface is 20 ms.
 */
@protocol ByteRTCAudioFrameObserver <NSObject>

/**
 * 
 * @type callback
 * @region Audio Data Callback
 * @brief Returns audio data recorded by microphone
 * @param audioFrame Audio data recorded by microphone, see ByteRTCAudioFrame{@link #ByteRTCAudioFrame}
 */
- (void)onRecordAudioFrame:(ByteRTCAudioFrame * _Nonnull)audioFrame;

/**
 * 
 * @type callback
 * @region Audio Data Callback
 * @brief Returns the mixed audio data of all subscribed remote users
 * @param audioFrame Mixed audio data, see ByteRTCAudioFrame{@link #ByteRTCAudioFrame}
 */
- (void)onPlaybackAudioFrame:(ByteRTCAudioFrame * _Nonnull)audioFrame;

/**
 * 
 * @type callback
 * @region Audio Data Callback
 * @brief Returns the audio data of one remote user.
 * @param streamKey Remote stream information. See ByteRTCRemoteStreamKey{@link #ByteRTCRemoteStreamKey}.
 * @param audioFrame Audio data. See ByteRTCAudioFrame{@link #ByteRTCAudioFrame}.
 * @note This callback works on the playback thread. Don't do anything time-consuming in this callback, or it may affect the entire audio playback chain.
 */
- (void)onRemoteUserAudioFrame:(ByteRTCRemoteStreamKey * _Nonnull)streamKey
                    audioFrame:(ByteRTCAudioFrame * _Nonnull)audioFrame;

/**
 * 
 * @type callback
 * @region Audio Data Callback
 * @brief Returns mixed audio data including both data recorded by the local microphone and data from all subscribed remote users
 * @param audioFrame Mixed audio data, see ByteRTCAudioFrame{@link #ByteRTCAudioFrame}
 */
- (void)onMixedAudioFrame:(ByteRTCAudioFrame * _Nonnull)audioFrame;

- (void)onCaptureMixedAudioFrame:(ByteRTCAudioFrame * _Nonnull)audioFrame;
@end


/**
 * 
 * @type callback
 * @brief  Custom audio processor <br>
 * Note: Callback functions are thrown synchronously in a non-UI thread within the SDK. Therefore, you must not perform any time-consuming operations or direct UI operations within the callback function, as this may cause the app to crash.
 */
@protocol ByteRTCAudioFrameProcessor <NSObject>

/**
 * 
 * @type callback
 * @brief Returns the address of the locally captured audio frame for custom processing.
 * @param audioFrame The address of the audio frame. See ByteRTCAudioFrame{@link #ByteRTCAudioFrame}.
 * @note
 *        - After custom processing, SDK will encode the processed audio frames and transmit to the remote user. The processing does not affect the SDK-level ear-monitoring audio.
 *        - To enable this callback, call `enableAudioProcessor`. You will receive this callback every 10 ms.
 * @return
 *        - 0: Success.
 *        - <0: Failure.
 */
- (int)onProcessRecordAudioFrame:(ByteRTCAudioFrame * _Nonnull)audioFrame;

/**
* 
* @type callback
* @brief Returns the address of the locally captured audio frame for custom processing.
* @param audioFrame The address of the audio frame. See ByteRTCAudioFrame{@link #ByteRTCAudioFrame}
* @note After calling `enableAudioProcessor` with mixed remote audio, you will receive this callback every 10 ms.
*/
- (int)onProcessPlayBackAudioFrame:(ByteRTCAudioFrame * _Nonnull)audioFrame;

/**
* 
* @type callback
* @brief Returns the address of the locally captured audio frame for custom processing.
* @param streamKey Information of the audio stream. See ByteRTCRemoteStreamKey{@link #ByteRTCRemoteStreamKey}
* @param audioFrame The address of the audio frame. See ByteRTCAudioFrame{@link #ByteRTCAudioFrame}
* @note After calling `enableAudioProcessor`, with audio streams of the remote users, you will receive this callback every 10 ms.
*/
- (int)onProcessRemoteUserAudioFrame:(ByteRTCRemoteStreamKey * _Nonnull)streamKey  audioFrame:(ByteRTCAudioFrame * _Nonnull)audioFrame;

/**
 * 
 * @valid since 3.50
 * @hidden(macOS)
 * @type callback
 * @brief You will receive the address of SDK-level in-ear monitoring audio frames for custom processing. <br>
 *        The audio effects set by `setVoiceReverbType:` and `setVoiceChangerType:` are included.
 * @param  audioFrame The address of the in-ear monitoring audio frames. See ByteRTCAudioFrame{@link #ByteRTCAudioFrame}.
 * @note
 *        - Modifying the data affects only SDK-level in-ear monitoring audio.
 *        - To enable this callback, call enableAudioProcessor:audioFormat:{@link #ByteRTCVideo#enableAudioProcessor:audioFormat:}. You will receive this callback every 10 ms.
 * @return
 *        - 0: Success.
 *        - <0: Failure.
 */
- (int)onProcessEarMonitorAudioFrame:(ByteRTCAudioFrame * _Nonnull)audioFrame;


/**
 * 
 * @type callback
 * @brief Returns the address of the shared-screen audio frames for custom processing.
 * @param audioFrame The address of audio frames. See ByteRTCAudioFrame{@link #ByteRTCAudioFrame}.
 * @note After calling `enableAudioProcessor:` to set the audio input to the shared-screen audio, you will receive this callback every 10 ms.
 */
- (int)onProcessScreenAudioFrame:(ByteRTCAudioFrame * _Nonnull)audioFrame;
@end

#pragma mark - AudioDeviceManager


/**
 * 
 * @hidden for internal use only
 * @type callback
 * @region audio management
 * @brief Audio device event callback
 */
BYTERTC_APPLE_EXPORT @protocol ByteRTCAudioDeviceEventHandler<NSObject>

/**
 * 
 * @type callback
 * @region audio management
 * @brief Get microphone volume
 * @param volume Volume size
 */
- (void)onRecordingAudioVolumeIndication:(int)volume;
@end


/**
 * 
 * @type api
 * @hidden(iOS)
 * @brief Audio Device Management
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCAudioDeviceManager : NSObject

/**
 * 
 * @hidden
 * @type api
 */
- (instancetype _Nonnull )initDeviceManager:(id<ByteRTCAudioDeviceEventHandler> _Nonnull)handler;

/**
 * 
 * @type api
 * @region  Audio device management
 * @brief  Gets the list of the audio playback devices.
 * @return  The list of all audio playback devices. See ByteRTCDeviceCollection{@link #ByteRTCDeviceCollection}. <br>
 * If a time-out occurs, it returns an empty list. By default, the time-out duration is set to 10 seconds. We recommend to call this API once you get notification of `ByteRTCMediaDeviceListUpdated` via rtcEngine:onAudioDeviceStateChanged:device_type:device_state:device_error:{@link #ByteRTCVideoDelegate#rtcEngine:onAudioDeviceStateChanged:device_type:device_state:device_error:}.
 * @note When receiving rtcEngine:onAudioDeviceStateChanged:device_type:device_state:device_error:{@link #ByteRTCVideoDelegate#rtcEngine:onAudioDeviceStateChanged:device_type:device_state:device_error:} for audio playback device change, you can call this API to get the latest list of audio playback devices. <br>

 */
- (ByteRTCDeviceCollection * _Nonnull)enumerateAudioPlaybackDevices;

/**
 * 
 * @type api
 * @region  Audio Device Management
 * @brief  Get the list of audio capture devices.
 * @return The list of audio capture devices.. See ByteRTCDeviceCollection{@link #ByteRTCDeviceCollection}. <br>
 * If a time-out occurs, it returns an empty list. By default, the time-out duration is set to 10 seconds. We recommend to call this API once you get notification of `ByteRTCMediaDeviceListUpdated` via rtcEngine:onAudioDeviceStateChanged:device_type:device_state:device_error:{@link #ByteRTCVideoDelegate#rtcEngine:onAudioDeviceStateChanged:device_type:device_state:device_error:}.
 * @note When receiving rtcEngine:onAudioDeviceStateChanged:device_type:device_state:device_error:{@link #ByteRTCVideoDelegate#rtcEngine:onAudioDeviceStateChanged:device_type:device_state:device_error:} for device change, you can call this API to get the latest list of audio playback devices.
 */
- (ByteRTCDeviceCollection * _Nonnull)enumerateAudioCaptureDevices;

/**
 * 
 * @type api
 * @region Audio Facility Management
 * @brief Set the audio capture device to follow the OS default setting or not.
 * @param followed <br>
 *        - true: follow the OS setting. You can not call setAudioCaptureDevice:{@link #ByteRTCAudioDeviceManager#setAudioCaptureDevice:} at the same time. The default value.
 *        - false: do not follow the OS setting. You can call setAudioCaptureDevice:{@link #ByteRTCAudioDeviceManager#setAudioCaptureDevice:} to set the audio capture device.
 */
- (void)followSystemCaptureDevice:(BOOL)followed;

/**
 * 
 * @type api
 * @region Audio Facility Management
 * @brief Set the audio playback device to follow the OS default setting or not.
 * @param followed <br>
 *        - true: follow the OS setting. You can not call setAudioPlaybackDevice:{@link #ByteRTCAudioDeviceManager#setAudioPlaybackDevice:} at the same time. The default value.
 *        - false: do not follow the OS setting. You can call setAudioPlaybackDevice:{@link #ByteRTCAudioDeviceManager#setAudioPlaybackDevice:} to set the audio playback device.
 */
- (void)followSystemPlaybackDevice:(BOOL)followed;

/**
 * 
 * @type api
 * @region Audio device management
 * @brief Sets the audio playback device.
 * @param  deviceID Device ID. You can get the ID by calling EnumerateAudioPlaybackDevices{@link #ByteRTCAudioDeviceManager#EnumerateAudioPlaybackDevices}.
 * @return
 *         - 0: Success
 *         - < 0: Failure
 * @note After you call followSystemPlaybackDevice:{@link #ByteRTCAudioDeviceManager#followSystemPlaybackDevice:} to set the audio playback device to follow the system setting, you cannot call this API to set the audio playback device.
 */
- (int)setAudioPlaybackDevice:(NSString * _Nonnull)deviceID;

/**
 * 
 * @type api
 * @region Audio Device Management
 * @brief Gets the current audio playback device.
 * @param  deviceID audio playback device ID
 * @return   Method call result <br>
 *         - 0: Success.
 *         - < 0: failure
 */
- (int)getAudioPlaybackDevice:(NSString * _Nonnull * _Nonnull) deviceID;

/**
 * 
 * @type api
 * @region Audio Device Management
 * @brief Set the audio capture devices.
 * @param  deviceID Audio capture device ID. You can get the device list by calling enumerateAudioCaptureDevices{@link #ByteRTCAudioDeviceManager#EnumerateAudioCaptureDevices}.
 * @return   Method call result <br>
 *         - 0: Success.
 *         - < 0: failure
 * @note After you call followSystemCaptureDevice:{@link #ByteRTCAudioDeviceManager#followSystemCaptureDevice:} to set the audio playback device to follow the system setting, you cannot call this API to set the audio capture device.
 */
- (int)setAudioCaptureDevice:(NSString * _Nonnull)deviceID;

/**
 * 
 * @type api
 * @region Audio Device Management
 * @brief Gets the current audio capture device.
 * @param deviceID audio capture device ID.
 * @return  Method call result <br>
 *         - 0: Success.
 *         - < 0: failure
 */
- (int)getAudioCaptureDevice:(NSString *_Nonnull * _Nonnull) deviceID;

/**
 * 
 * @type api
 * @region Audio Device Management
 * @brief Set the mute state of the current audio capture device. It's not mute by default.
 * @param  mute <br>
 *        - true: Mute
 *        - false: Speaking
 * @return   Method call result <br>
 *         - 0: Success.
 *         - < 0: failure
 */
- (int) setAudioCaptureDeviceMute:(bool)mute;

/**
 * 
 * @type api
 * @region Audio Device Management
 * @brief Gets information about the mute state of the current audio capture device.
 * @param  mute <br>
 *        - true: Mute
 *        - false: Speaking
 * @return   Method call result <br>
 *         - 0: Success.
 *         - < 0: failure
 */
- (int) getAudioCaptureDeviceMute:(bool * _Nonnull)mute;

/**
 * 
 * @type api
 * @region Audio Device Management
 * @brief Set the mute state of the current audio playback device. It's not mute by default.
 * @param  mute <br>
 *        - true: Mute
 *        - false: Speaking
 * @return   Method call result <br>
 *         - 0: Success.
 *         - < 0: failure
 */
- (int) setAudioPlaybackDeviceMute:(bool)mute;

/**
 * 
 * @type api
 * @region Audio Device Management
 * @brief Get the mute state of the current audio playback device.
 * @param  mute <br>
 *        - true: Mute
 *        - false: Speaking
 * @return   Method call result <br>
 *         - 0: Success.
 *         - < 0: failure
 */
- (int) getAudioPlaybackDeviceMute:(bool * _Nonnull)mute;

/**
 * 
 * @type api
 * @region  Audio Device Management
 * @brief Set the current audio capture device volume
 * @param  volume Audio capture device volume. The range is [0,255]. <br>
 *        - [0,25]: nearly silent;
 *        - [25,75]: low volume;
 *        - [76,204]: medium volume;
 *        - [205,255]: high volume.
 * @return   Method call result <br>
 *         - 0: Success. The volume information returned by rtcEngine:onLocalAudioPropertiesReport:{@link #ByteRTCVideoDelegate#rtcEngine:onLocalAudioPropertiesReport:} will be changed according to this value.
 *         - < 0: failure
 */
- (int) setAudioCaptureDeviceVolume:(unsigned int)volume;

/**
 * 
 * @type api
 * @region Audio Device Management
 * @brief Get the current audio capture device volume.
 * @param  volume Audio capture device volume. The range is [0,255]. <br>
 *        - [0,25]: nearly silent;
 *        - [25,75]: low volume;
 *        - [76,204]: medium volume;
 *        - [205,255]: high volume.
 * @return   Method call result <br>
 *         - 0: Success.
 *         - < 0: failure
 */
- (int) getAudioCaptureDeviceVolume:(unsigned int * _Nonnull)volume;

/**
 * 
 * @type api
 * @region Audio Device Management
 * @brief Set the current audio playback device volume.
 * @param  volume Audio playback device volume. The range is [0,255]. <br>
 *        - [0,25]: nearly silent;
 *        - [25,75]: low volume;
 *        - [76,204]: medium volume;
 *        - [205,255]: high volume.
 * @return   Method call result <br>
 *         - 0: Success.
 *         - < 0: failure
 */
- (int) setAudioPlaybackDeviceVolume:(unsigned int)volume;

/**
 * 
 * @type api
 * @region Audio Device Management
 * @brief Get the current audio playback device volume.
 * @param  volume Audio playback device volume. The range is [0,255]. <br>
 *        - [0,25]: nearly silent;
 *        - [25,75]: low volume;
 *        - [76,204]: medium volume;
 *        - [205,255]: high volume.
 * @return   Method call result <br>
 *         - 0: Success.
 *         - < 0: failure
 */
- (int) getAudioPlaybackDeviceVolume:(unsigned int * _Nonnull)volume;

/**
 * 
 * @type api
 * @region Audio Device Management
 * @brief Start the audio playback device test. <br>
 *        This method tests whether the playback device works properly. The SDK plays the specified audio file. If the tester can hear the sound, the playback device can work normally.
 * @param  testAudioFilePath The absolute path of the audio file. The path string uses UTF-8 encoding format and supports the following audio formats: mp3, aac, m4a, 3gp, wav.
 * @param  interval playback device test volume callback interval
 * @return  Method call result <br>
 *         - 0: Success.
 *         - < 0: failure
 * @note
 *        - This method must be called before joining the room and cannot be applied at the same time as other audio device testing functions.
 *        - Call stopAudioPlaybackDeviceTest{@link #ByteRTCAudioDeviceManager#stopAudioPlaybackDeviceTest} to stop the test.
 */
- (int)startAudioPlaybackDeviceTest:(NSString *_Nonnull)testAudioFilePath interval:(int)interval;

/**
 * 
 * @type api
 * @region Audio Device Management
 * @brief Stop audio playback device testing.
 * @return  Method call result <br>
 *         - 0: Success.
 *         - < 0: failure
 * @note  After calling startAudioPlaybackDeviceTest:interval:{@link #ByteRTCAudioDeviceManager#startAudioPlaybackDeviceTest:interval:}, call this method to stop the test.
 */
- (int)stopAudioPlaybackDeviceTest;

/**
 * 
 * @hidden(iOS)
 * @type api
 * @region Audio Facility Management
 * @brief Start the capture and playback test for local audio devices.
 * @param interval During the test, you'll receive `rtcEngine:onLocalAudioPropertiesReport:` periodically. Set the period in ms with this parameter. Recommended value is 200 ms; the minimal value is 10 ms.
 * @return  result <br>
 *         - 0: success
 *         - < 0: failure
 * @note
 *       - The audio capturing stops in 30s after calling this API and begins to play the recording audio. Before that, you can call stopAudioDeviceRecordAndPlayTest{@link #ByteRTCAudioDeviceManager#stopAudioDeviceRecordAndPlayTest} to stop audio capturing and start playing the recording audio.
 *       - Call stopAudioDevicePlayTest{@link #ByteRTCAudioDeviceManager#stopAudioDevicePlayTest} to stop the test, including capturing and playing the recording.
 *       - You must stop the test before starting another test for audio devices.
 *       - You must stop the test before calling `enableAudioPropertiesReport:`.
 *       - This test performs locally and does not involve network connection testing.
 */
- (int)startAudioDeviceRecordTest:(int)interval;

/**
 * 
 * @hidden(iOS)
 * @type api
 * @region Audio Facility Management
 * @brief Call this API to stop recording in the test and start to play the recording in 30 s after calling startAudioDeviceRecordTest:{@link #ByteRTCAudioDeviceManager#startAudioDeviceRecordTest:}.
 * @return result <br>
 *         - 0: success
 *         - < 0: failure
 * @note
 *         - This method do rely on rtcEngine, this method only will be Effective when ByteRTCAudioDeviceManager created by getAudioDeviceManager{@link #ByteRTCVideo#getAudioDeviceManager}
 *         - After calling this API, the recording starts playing during which you can call stopAudioDevicePlayTest{@link #ByteRTCAudioDeviceManager#stopAudioDevicePlayTest} to stop playing.
 */
- (int)stopAudioDeviceRecordAndPlayTest;

/**
 * 
 * @hidden(iOS)
 * @type api
 * @region Audio Facility Management
 * @brief Stop the capture and playback test for local audio devices which is started by calling startAudioDeviceRecordTest:{@link #ByteRTCAudioDeviceManager#startAudioDeviceRecordTest:}. <br>
 * Before the test ends by itself, you can call this API to stop the recording or playing.
 * @return
 *         - 0: success
 *         - < 0: failure
 * @note
 *         - This method do rely on rtcEngine, this method only will be Effective when ByteRTCAudioDeviceManager created by getAudioDeviceManager{@link #ByteRTCVideo#getAudioDeviceManager}
 */
- (int)stopAudioDevicePlayTest;

/**
 * 
 * @type api
 * @region Audio Device Management
 * @brief Try to initialize the audio playback device for device test.
 * @param deviceID Device ID
 * @return Device status error code: <br>
 *         - 0: Status normal.
 *         - -1: Test not executed.
 *         - -2: Init failed due to lack of permission.
 *         - -3: The device does not exist. No device or device removed.
 *         - -4: The audio format is not supported.
 *         - -5: Error for other reasons
 * @note
 *        - Call this API before the user joins the room.
 *        - You may still fail to enable the device even you passed the test. Occupation by other application or shortage of CPU / memory may cause the failure.
 */
- (int)initAudioPlaybackDeviceForTest:(NSString * _Nonnull)deviceID;

/**
 * 
 * @type api
 * @region Audio Device Management
 * @brief Try to initialize the audio capture device for device test.
 * @param deviceID device ID
 * @return Device status error code: <br>
 *         - 0: Status normal.
 *         - -1: Test not executed.
 *         - -2: Init failed due to lack of permission.
 *         - -3: The device does not exist. No device or device removed.
 *         - -4: The audio format is not supported.
 *         - -5: Error for other reasons
 * @note
 *        - Call this API before joining the room;
 *        - You may still fail to enable the device even you passed the test. Occupation by other application or shortage of CPU / memory may cause the failure.
 */
- (int)initAudioCaptureDeviceForTest:(NSString * _Nonnull)deviceID;

/**
 * 
 * @type api
 * @deprecated since 3.45 and will be deleted in 3.51.
 * @region Audio Device Management
 * @brief Switch audio playback device to the speaker or the earpiece. The default playback device is the speaker.
 * @param  enable <br>
 *        - true: switch to the speaker
 *        - false: switch to the earpiece
 * @note This method is only valid on mobile devices.
 */
- (void)setEnableSpeakerphone:(bool)enable;


/**
 * 
 * @type api
 * @region Audio Device Management
 * @brief Start the audio capture device test. <br>
 *        This method tests whether the audio capture device can work properly. After starting the test, you will receive the volume information reported by rtcEngine:onLocalAudioPropertiesReport:{@link #ByteRTCVideoDelegate#rtcEngine:onLocalAudioPropertiesReport:}.
 * @param  indicationInterval The interval of receiving callbacks. It is recommended to set to no less than 200 ms. The minimum is 10 ms.
 * @return  Method call result <br>
 *         - 0: Success.
 *         - < 0: failure
 * @note
 *        - This method do not rely on rtcEngine
 *        - This method must be called before joining the room and cannot be applied at the same time as other audio device testing functions.
 *        - You need to call stopAudioRecordingDeviceTest{@link #ByteRTCAudioDeviceManager#stopAudioRecordingDeviceTest} to stop the test.
 */
- (int)startAudioRecordingDeviceTest:(unsigned int)indicationInterval;

/**
 * 
 * @type api
 * @region Audio Device Management
 * @brief Stop audio capture device testing.
 * @return  Method call result <br>
 *         - 0: Success.
 *         - < 0: failure
 * @note
 *         - This method do not rely on rtcEngine
 *         +After calling startAudioRecordingDeviceTest:{@link #ByteRTCAudioDeviceManager#startAudioRecordingDeviceTest:}, you must call this method to stop the test.
 */
- (int)stopAudioRecordingDeviceTest;

/**
 * 
 * @type api
 * @region Audio Device Management
 * @brief Begins audio device loop testing. <br>
 *        This method tests whether the audio capture device and the audio playback device can work normally. Once the test starts, the audio capture device will capture the local sound <br>
 *         And play it out through the audio playback device, and the user App will receive the volume information reported by the `OnLocalAudioPropertiesReport` callback.
 * @param  indicationInterval The time interval of receiving callbacks in ms. It is recommended to set to no less than 200 ms. The minimum is 10 ms.
 * @return   Method call result <br>
 *         - 0: Success.
 *         - < 0: failure
 * @note
 *        - This method do not rely on rtcEngine
 *        - This method must be called before joining the room. And cannot be applied at the same time as other audio equipment test functions.
 *        - You need to call stopAudioDeviceLoopbackTest{@link #ByteRTCAudioDeviceManager#stopAudioDeviceLoopbackTest} to stop the test.
 *        - This method only tests audio equipment locally and does not involve network connection.
 */
- (int)startAudioDeviceLoopbackTest:(unsigned int)indicationInterval;

/**
 * 
 * @type api
 * @region Audio Device Management
 * @brief Stop audio device loop testing.
 * @return  Method call result <br>
 *         - 0: Success.
 *         - < 0: failure
 * @note
 *         - This method do not rely on rtcEngine
 *         - After calling startAudioDeviceLoopbackTest:{@link #ByteRTCAudioDeviceManager#startAudioDeviceLoopbackTest:}, you need to call this method to stop the test.
 */
- (int)stopAudioDeviceLoopbackTest;
@end


/**
 * 
 * @type keytype
 * @brief Verification information required to use automatic speech recognition services
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCASRConfig : NSObject

/**
 * 
 *  @brief Application ID
 */
@property(copy, nonatomic) NSString *_Nonnull appId;

/**
 * 
 *  @brief User ID
 */
@property(copy, nonatomic) NSString *_Nonnull userId;

/**
 * 
 *  @brief Access token
 */
@property(copy, nonatomic) NSString *_Nonnull accessToken;

/**
 * 
 * @brief Private key. Signature  cannot be empty in authentication mode, and it is empty in token authentication mode. See [Authentication Method](https:
 */
@property(copy, nonatomic) NSString *_Nonnull secretKey;

/**
 * 
 *  @brief For scenario information. See Business Clusters (https:
 */
@property(copy, nonatomic) NSString *_Nonnull cluster;

/**
 * 
 *  @brief Authentication mode. See ByteRTCASRAuthorizationType{@link #ByteRTCASRAuthorizationType}
 */
@property(assign, nonatomic) ByteRTCASRAuthorizationType authorizationType;
@end

#pragma mark - ByteASREventHandler


/**
 * 
 * @hidden currently not available
 * @type callback
 * @brief Speech recognition service usage status callback <br>
 * Note: Callback functions are thrown synchronously in a non-UI thread within the SDK. Therefore, you must not perform any time-consuming operations or direct UI operations within the callback function, as this may cause the app to crash.
 */
BYTERTC_APPLE_EXPORT @protocol ByteRTCASREngineEventHandler<NSObject>
@required

/**
 * 
 * @type callback
 * @brief  Speech recognition service starts successful callback
 */
- (void)onSuccess;
@required

/**
 * 
 * @type callback
 * @brief The voice-to-text callback is successful, and the callback returns the full amount of messages after recognition.
 * @param message Text message obtained after the recognition is completed
 * @note If the network connection is interrupted during the recognition process, the callback information after reconnection contains only the text message recognized after reconnection, and no longer contains the message recognized after the last connection.
 */
- (void)onMessage:(NSString *_Nonnull)message;
@required

/**
 * 
 * @type callback
 * @brief This callback is triggered when an error event occurs within the speech recognition service.
 * @param errorCode Error code <br>
 *         - < 0: Parameter error or API call order error. See ByteRTCASRErrorCode{@link #ByteRTCASRErrorCode};
 *         - > 0: See [speech recognition service error code](https:
 * @param errorMessage Error reason description
 */
- (void)onError:(NSInteger)errorCode withErrorMessage:(NSString *_Nonnull)errorMessage;
@end


/**
 * 
 * @type keytype
 * @brief Mixing configuration
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCAudioMixingConfig : NSObject

/**
 * 
 * @type keytype
 * @brief Mix playback type. See ByteRTCAudioMixingType{@link #ByteRTCAudioMixingType}
 */
@property(assign, nonatomic) ByteRTCAudioMixingType type;

/**
 * 
 * @brief Mix playback times <br>
 *        - Play_count < = 0: Infinite loop
 *        - Play_count == 1: Play once (default)
 *        - Play_count > 1: Play play_count times
 */
@property(assign, nonatomic) NSInteger playCount;

/**
 * 
 * @brief The position of the audio file playback progress bar during audio mixing, the parameter should be an integer, in milliseconds.
 */
@property(assign, nonatomic) NSInteger position;

/**
 * 
 * @brief Set the time interval (ms) for the audio file playing progress callback. The `rtcEngine:onAudioMixingPlayingProgress:progress:` callback then will be triggered according to the set value, no callback by default. <br>
 *       - The value of interval is a multiple of 10 greater than 0. When the value set is not divisible by 10, the default is rounded up by 10. For example, if the value is set to 52ms, it will be automatically adjusted to 60ms.
 *       - If the value is less than or equals to 0, the callback will not be triggered.
 */
@property(assign, nonatomic) NSInteger callbackOnProgressInterval;

/**
 * 
 * @brief Attach the process information of local audio file mixing to the captured audio data. Enable the function to enhance the synchronicity of the remote audio mixing. <br>
 *        - The function is effective when mixing a single audio file.
 *        - Use `true` for enabling the function and `false` for disable the function. The default is `false`.
 */
@property(assign, nonatomic) BOOL syncProgressToRecordFrame;
@end

/**
 * 
 * @type keytype
 * @brief Mixing configuration
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCAudioEffectPlayerConfig : NSObject
 
/**
 * 
 * @type keytype
 * @brief Mixing playback types. See ByteRTCAudioMixingType{@link #ByteRTCAudioMixingType}
 */
@property(assign, nonatomic) ByteRTCAudioMixingType type;

/**
 * 
 * @brief The increase or decrease value compared with the original pitch of the music file. The range is `[-12, 12]`. The default value is 0. The pitch distance between two adjacent values is half a step. A positive value indicates a rising pitch, and a negative value indicates a falling pitch.
*/
@property(assign, nonatomic) NSInteger pitch;

/**
 * 
 * @brief Mix playback times <br>
 *        - Play_count < = 0: Infinite loop
 *        - Play_count == 1: Play once (default)
 *        - Play_count > 1: Play play_count times
 */
@property(assign, nonatomic) NSInteger playCount;

/**
 * 
 * @brief The starting position in ms. 0 by default.
 */
@property(assign, nonatomic) NSInteger startPos;
@end

/**
 * 
 * @type keytype
 * @brief Mixing configuration
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCMediaPlayerConfig : NSObject

/**
 * 
 * @brief For mixing playback types. See ByteRTCAudioMixingType{@link #ByteRTCAudioMixingType}
 */
@property(assign, nonatomic) ByteRTCAudioMixingType type;

/**
 * 
 * @brief Mix playback times <br>
 *        - Play_count < = 0: Infinite loop
 *        - Play_count == 1: Play once (default)
 *        - Play_count > 1: Play play_count times
 */
@property(assign, nonatomic) NSInteger playCount;

/**
 * 
 * @brief The starting position in ms. 0 by default.
 */
@property(assign, nonatomic) NSInteger startPos;

 /**
 * 
 * @brief Set the interval of the periodic callback onMediaPlayerPlayingProgress:progress:{@link #ByteRTCMediaPlayerEventHandler#onMediaPlayerPlayingProgress:progress:} during audio mixing in ms. <br>
 *       - interval > 0: The callback is enabled. The actual interval is a multiple of 10. If the input value is not divisible by 10, it will be automatically rounded up. For example, if 52 is entered, the actual interval is 60 ms.
 *       - interval <= 0: The callback is disabled.
 */
@property(assign, nonatomic) NSInteger callbackOnProgressInterval;

/**
 * 
 * @brief Attach the process information of local audio file mixing to the captured audio data. Enable the function to enhance the synchronicity of the remote audio mixing. <br>
 *        - The function is effective when mixing a single audio file.
 *        - Use `true` for enabling the function and `false` for disable the function. The default is `false`.
 */
@property(assign, nonatomic) BOOL syncProgressToRecordFrame;

/**
* 
* @brief Play the audio automatically. If not, call start{@link #ByteRTCMediaPlayer#start} to play the audio. True by default.
*/
@property(assign, nonatomic) BOOL autoPlay;
@end

/**
 * 
 * @type callback
 * @brief  In-memory audio data playing callback interface
 */
BYTERTC_APPLE_EXPORT @protocol ByteRTCMediaPlayerCustomSourceProvider <NSObject>

/**
 * 
 * @valid since 3.53
 * @type callback
 * @region Music player
 * @brief Callback of getting the path and size of the audio data you input. <br>
 *         When you call openWithCustomSource:config:{@link #ByteRTCMediaPlayer#openWithCustomSource:config:} API to play the in-memory audio data you input, this callback will be triggered and you need to enter the path and size of the audio data.
 * @param buffer The path of the audio data you input. The size of audio data should be equal to or less than the value of bufferSize. The supported formats are: mp3, aac, m4a, 3gp, wav.
 * @param bufferSize  The size of the audio data, in bytes. If you want to stop audio playing, you can enter a figure less than or equal to zero into bufferSize and then SDK will stop calling this callback.
 * @return Returns the size of the audio data that are actually read.
 * @note If calling openWithCustomSource:config:{@link #ByteRTCMediaPlayer#openWithCustomSource:config:} API failed, please enter 0 into buffer and bufferSize. In this situation, SDK will stop calling this callback.
 */
-(int)onReadData:(uint8_t*_Nonnull) buffer bufferSize:(int)bufferSize;

/**
 * 
 * @valid since 3.53
 * @type callback
 * @region Music player
 * @brief Seeking the audio data based on the set starting position and offset to help SDK read and analyze data. <br>
 *        When you call openWithCustomSource:config:{@link #ByteRTCMediaPlayer#openWithCustomSource:config:} API to play the in-memory audio data you input, or when you call setPosition:position:{@link #ByteRTCAudioEffectPlayer#setPosition:position:} to set the starting position of audio playing, this callback will be trigerred and you need to seek the audio data accorring to the value of offset and whence.
 * @param offset The offset of the target position relative to the starting position, in bytes. The value can be positive or negative.
 * @param whence The starting position of the seeking.  Refer to ByteRTCMediaPlayerCustomSourceSeekWhence{@link #ByteRTCMediaPlayerCustomSourceSeekWhence} for more details.
 * @return
 *         If the seeking succeeded, the information on the final adjusted play position after seeking or the size of the audio data will be returned. <br>
 *         If the seeking failed, -1 will be returned.
 */
-(int64_t)onSeek:(int64_t)offset whence:(ByteRTCMediaPlayerCustomSourceSeekWhence)whence;
@end

/**
 * 
 * @type keytype
 * @brief The audio source for media player.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCMediaPlayerCustomSource : NSObject

/**
 * 
 * @type keytype
 * @brief Specify the ByteRTCMediaPlayerCustomSourceProvider{@link #ByteRTCMediaPlayerCustomSourceProvider} instance when you want to play the audio data in memory.
 */
@property(weak, nonatomic) id<ByteRTCMediaPlayerCustomSourceProvider> _Nullable provider;

/**
 * 
 * @type keytype
 * @brief See ByteRTCMediaPlayerCustomSourceMode{@link #ByteRTCMediaPlayerCustomSourceMode}. `push` by default.
 */
@property(assign, nonatomic) ByteRTCMediaPlayerCustomSourceMode mode;

/**
 * 
 * @type keytype
 * @brief See ByteRTCMediaPlayerCustomSourceStreamType{@link #ByteRTCMediaPlayerCustomSourceStreamType}. `raw` by default.
 */
@property(assign, nonatomic) ByteRTCMediaPlayerCustomSourceStreamType type;

@end

/**
 * 
 * @type keytype
 * @brief Configuration related to audio attribute information prompt.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCAudioPropertiesConfig : NSObject

/**
 * 
 * @brief Prompt interval in ms <br>
 *        - `<= 0`: Turn off prompt
 *        - `(0,100]`: Invalid interval value, and will be automatically reset to 100ms.
 *        - `> 100`: the actual value of interval
 */
@property(assign, nonatomic) NSInteger interval;

/**
 * 
 * @brief Whether to enable audio spectrum detection.
 */
@property(assign, nonatomic) BOOL enableSpectrum;

/**
 * 
 * @brief Whether to enable Voice Activity Detection.
 */
@property(assign, nonatomic) BOOL enableVad;

/**
 * 
 * @brief The volume callback modes. See ByteRTCAudioReportMode{@link #ByteRTCAudioReportMode}.
  */
@property(assign, nonatomic) ByteRTCAudioReportMode localMainReportMode;

/**
 * 
 * @brief The smoothing coefficient for audio attribute information prompt. The range is `(0.0, 1.0]`. <br>
 *        The default value is `1.0`, which means the smoothing effect is off by default. Smaller the value, smoother the audio volume prompt. If you want to enable the smooth effect, the recommended value is `0.3`.
 */
@property(nonatomic, assign) float smooth;


/**
 * 
 * @brief The audio info included in rtcEngine:onLocalAudioPropertiesReport:{@link #ByteRTCVideoDelegate#rtcEngine:onLocalAudioPropertiesReport:}. See ByteRTCAudioPropertiesMode{@link #ByteRTCAudioPropertiesMode}. <br>
 *        Locally captured microphone audio info and locally captured screen audio info are included by default.
 */
@property(assign, nonatomic) ByteRTCAudioPropertiesMode audioReportMode;


/**
 * 
 * @brief Sets whether to return the vocal pitch of the local user.
 */
@property(assign, nonatomic) BOOL enableVoicePitch;

/**
 * 
 * @hidden for internal use only
 * @brief Whether to return the device playback delay.
 */
@property(assign, nonatomic) BOOL enableDeviceLoopDelay;
@end


/**
 * 
 * @type keytype
 * @brief Audio properties
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCAudioPropertiesInfo : NSObject

/**
 * 
 * @brief linear volume. The value is in linear relation to the original volume. The higher the value, the higher the volume. The range is [0,255]. <br>
 *        - [0, 25]: Silence
 *        - [26, 75]: Low volume
 *        - [76, 204]: Medium volume
 *        - [205, 255]: High volume
 */
@property(assign, nonatomic) NSInteger linearVolume;

/**
 * 
 * @brief non-linear volume in dB. The value is in proportion to the log value of the original volume. You can use the value to recognize the Active Speaker in the room. The range is [-127, 0]. <br>
 *        - [-127, -60]: Silence
 *        - [-59, -40]: Low volume
 *        - [-39, -20]: Medium volume
 *        - [-19, 0]: High volume
 */
@property(assign, nonatomic) NSInteger nonlinearVolume;

/**
 * 
 * @brief Voice Activity Detection (VAD) result <br>
 *        - 1: Voice activity detected.
 *        - 0: No voice activity detected.
 *        - -1: VAD not activated.
 */
@property(assign, nonatomic) NSInteger vad;

/**
 * 
 * @brief Spectrum array. The default length is 257.
 */
@property(copy, nonatomic) NSArray<NSNumber*> * _Nonnull spectrum;

/**
 * 
 * @brief The vocal pitch of the local user, in Hertz. <br>
 *        When the following two conditions are met at the same time, the vocal pitch of the local user will be returned: <br>
 *      - Calls enableAudioPropertiesReport{@link #ByteRTCVideo#enableAudioPropertiesReport}, and sets the value of enableVoicePitch to `true`.
 *      - The local user's voice is included in the locally captured audio data.
 *        In other situations, `0` will be returned.
 */    
@property(assign, nonatomic) NSInteger voicePitch;

/**
 * 
 * @hidden internal use only
 * @brief Device record and playback delay, in milliseconds. <br>
 *        - -1: Disabled.
 *        - >0: Playback delay。
 */
@property(assign, nonatomic) NSInteger deviceLoopDelay;
@end


/**
 * 
 * @type keytype
 * @brief Local audio properties
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCLocalAudioPropertiesInfo : NSObject


/**
 * 
 * @brief See ByteRTCStreamIndex{@link #ByteRTCStreamIndex}
 */
@property(assign, nonatomic) ByteRTCStreamIndex streamIndex;

/**
 * 
 * @type keytype
 * @brief See ByteRTCAudioPropertiesInfo{@link #ByteRTCAudioPropertiesInfo}
 */
@property(strong, nonatomic) ByteRTCAudioPropertiesInfo *_Nonnull audioPropertiesInfo;
@end


/**
 * 
 * @type keytype
 * @brief Remote audio properties
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCRemoteAudioPropertiesInfo : NSObject

/**
 * 
 * @type keytype
 * @brief See ByteRTCRemoteStreamKey{@link #ByteRTCRemoteStreamKey}
 */
@property(strong, nonatomic) ByteRTCRemoteStreamKey *_Nonnull streamKey;

/**
 * 
 * @type keytype
 * @brief See ByteRTCAudioPropertiesInfo{@link #ByteRTCAudioPropertiesInfo}
 */
@property(strong, nonatomic) ByteRTCAudioPropertiesInfo *_Nonnull audioPropertiesInfo;
@end


/**
 * 
 * @type keytype
 * @brief Coordinate value of the local user's position in the rectangular coordinate system in the RTC room.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCPosition : NSObject

/**
 * 
 * @brief X-coordinate
 */
@property(nonatomic, assign) float x;

/**
 * 
 * @brief Y-coordinate
 */
@property(nonatomic, assign) float y;

/**
 * 
 * @brief Z-coordinate
 */
@property(nonatomic, assign) float z;
@end


/**
 * 
 * @type keytype
 * @brief Direction Orientation Information
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCOrientation : NSObject

/**
 * 
 * @brief X-coordinate
 */
@property(nonatomic, assign) float x;

/**
 * 
 * @brief Y-coordinate
 */
@property(nonatomic, assign) float y;

/**
 * 
 * @brief Z-coordinate
 */
@property(nonatomic, assign) float z;
@end


/**
 * 
 * @type keytype
 * @brief Three-dimensional orientation information, each pair of vectors need to be perpendicular. See ByteRTCOrientation{@link #ByteRTCOrientation}.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCHumanOrientation : NSObject

/**
 * 
 * @brief Forward orientation, the default value is {1,0,0}, i.e., the forward orientation is in the positive direction of x-axis.
 */
@property(nonatomic, strong) ByteRTCOrientation* _Nonnull forward;

/**
 * 
 * @brief Rightward orientation, the default value is {0,1,0}, i.e., the rightward orientation is in the positive direction of y-axis.
 */
@property(nonatomic, strong) ByteRTCOrientation* _Nonnull right;

/**
 * 
 * @brief Upward orientation, the default value is {0,0,1}, i.e., the upward orientation is in the positive direction of z-axis.
 */
@property(nonatomic, strong) ByteRTCOrientation* _Nonnull up;
@end


/**
 * 
 * @type keytype
 * @brief Karaoke scoring mode.
 */
typedef NS_ENUM(NSInteger, ByteRTCMulDimSingScoringMode) {
    
    /**
     * 
     * @brief The score is provided based on the pitch.
     */
    ByteRTCMulDimSingScoringModeNote = 0
};

/**
 * 
 * @type keytype
 * @brief The alignment mode of remote audio streams
 */
typedef NS_ENUM(NSInteger, ByteRTCAudioAlignmentMode) {
    
    /**
     * 
     * @brief Disabled
     */
    ByteRTCAudioAlignmentModeOff = 0,
    
    /**
     * 
     * @brief All subscribed audio streams are aligned based on the process of the background music.
     */
    ByteRTCAudioAlignmentModeAudioMixing = 1,
};


/**
 * 
 * @type keytype
 * @brief Real-time scoring data.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCSingScoringRealtimeInfo : NSObject
 
 /**
  * 
  * @brief Current playback position.
  */
@property(nonatomic, assign) int currentPosition;
 
 /**
  * 
  * @brief The user's pitch.
  */
@property(nonatomic, assign) int userPitch;
 
 /**
  * 
  * @brief Standard pitch.
  */
@property(nonatomic, assign) int standardPitch;
 
 /**
  * 
  * @brief Lyric index.
  */
@property(nonatomic, assign) int sentenceIndex;
 
 /**
  * 
  * @brief The score for the previous lyric.
  */
@property(nonatomic, assign) int sentenceScore;
 
 /**
  * 
  * @brief The total score for the user's current performance.
  */
@property(nonatomic, assign) int totalScore;
 
 /**
  * 
  * @brief The average score for the user's current performance.
  */
@property(nonatomic, assign) int averageScore;
@end


/**
 * 
 * @type keytype
 * @brief Standard Pitch Data.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCStandardPitchInfo : NSObject
 
 /**
  * 
  * @brief Starting time, unit: ms.
  */
@property(nonatomic, assign) int startTime;
 
 /**
  * 
  * @brief Duration, unit: ms.
  */
@property(nonatomic, assign) int duration;
 
 /**
  * 
  * @brief pitch.
  */
@property(nonatomic, assign) int pitch;
@end


/**
 * 
 * @type keytype
 * @brief The configuration of the karaoke scoring feature.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCSingScoringConfig : NSObject
 
 /**
  * 
  * @brief Scoring mode, see ByteRTCMulDimSingScoringMode{@link #ByteRTCMulDimSingScoringMode}.
  */
@property(nonatomic, assign) ByteRTCMulDimSingScoringMode mode;
 
 /**
  * 
  * @brief Sampling rate. Only 44,100 Hz and 48,000 Hz are supported.
  */
@property(nonatomic, assign) ByteRTCAudioSampleRate sampleRate;
 
 /**
  * 
  * @brief The file path of the lyrics. The scoring feature only supports KRC lyrics file.
  */
@property(nonatomic, copy) NSString *_Nonnull lyricsFilepath;
 
 /**
  * 
  * @brief The path of the midi file.
  */
@property(nonatomic, copy) NSString *_Nonnull midiFilepath;
@end


/**
 * 
 * @type keytype
 * @brief Audio file recording source type
 */
typedef NS_ENUM(NSInteger, ByteRTCAudioFrameSource) {
    
    /**
     * 
     * @brief The audio captured by the local microphone.
     */
    ByteRTCAudioFrameSourceTypeMic = 0,
    
    /**
     * 
     * @brief The audio got by mixing all remote user's audio.
     */
    ByteRTCAudioFrameSourceTypePlayback = 1,
    
    /**
     * 
     * @brief The audio got by mixing the local captured audio and all remote user's audio.
     */
    ByteRTCAudioFrameSourceTypeMixed = 2,
};

/**
 * 
 * @type keytype
 * @brief Audio quality
 */
typedef NS_ENUM(NSInteger, ByteRTCAudioQuality) {
    
    /**
     * 
     * @brief low quality
     */
    ByteRTCAudioQualityLow = 0,
    
    /**
     * 
     * @brief medium quality
     */
    ByteRTCAudioQualityMedium = 1,
    
    /**
     * 
     * @brief high quality
     */
    ByteRTCAudioQualityHigh = 2,
    
    /**
     * 
     * @brief ultra high quality
     */
    ByteRTCAudioQualityUltraHigh = 3,
};

/**
 * 
 * @type keytype
 * @brief Audio recording configuration
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCAudioRecordingConfig : NSObject

/**
 * 
 * @brief Absolute path of the recorded file, file name included. The App must have the write and read permission of the path.
 * @note The files format is restricted to .aac and .wav.
 */
@property(nonatomic, copy) NSString* _Nonnull absoluteFileName;

/**
 * 
 * @brief The source of the recording. See ByteRTCAudioFrameSource{@link #ByteRTCAudioFrameSource}. <br>
 * It is ByteRTCAudioFrameSourceTypeMixed = 2 by default.
 */
@property(nonatomic, assign) ByteRTCAudioFrameSource frameSource;

/**
 * 
 * @brief See ByteRTCAudioSampleRate{@link #ByteRTCAudioSampleRate}.
 */
@property(nonatomic, assign) ByteRTCAudioSampleRate sampleRate;

/**
 * 
 * @brief Number of audio channels. See ByteRTCAudioChannel{@link #ByteRTCAudioChannel}. <br>
 *        If number of audio channels of recording is different than that of audio capture, the behavior is: <br>
 *        - If the number of capture is 1, and the number of recording is 2, the recorded audio is two-channel data after copying mono-channel data.
 *        - If the number of capture is 2, and the number of recording is 1, the recorded audio is recorded by mixing the audio of the two channels.
 */
@property(nonatomic, assign) ByteRTCAudioChannel channel;

/**
 * 
 * @brief Recording quality. Only valid for .aac file. See ByteRTCAudioQuality{@link #ByteRTCAudioQuality}. <br>
 * When the sample rate is 32kHz, the file (10min) size for different qualities are: <br>
 *        - low: 1.2MB;
 *        - [By Default] medium: 2MB;
 *        - high: 3.75MB;
 *        - ultra high: 7.5MB.
 */
@property(nonatomic, assign) ByteRTCAudioQuality quality;
@end


/**
 * 
 * @type keytype
 * @brief Audio recording config
 */
typedef NS_ENUM(NSInteger, ByteRTCAudioRecordingState) {
    
    /**
     * 
     * @brief Recording exception
     */
    ByteRTCAudioRecordingStateError = 0,
    
    /**
     * 
     * @brief Recording in progress
     */
    ByteRTCAudioRecordingStateProcessing = 1,
    
    /**
     * 
     * @brief The recording task ends, and the file is saved.
     */
    ByteRTCAudioRecordingStateSuccess = 2,
};

/**
 * 
 * @type errorcode
 * @brief Error code for audio recording.
 */
typedef NS_ENUM(NSInteger, ByteRTCAudioRecordingErrorCode) {
    
    /**
     * 
     * @brief OK
     */
    ByteRTCAudioRecordingErrorCodeOk = 0,
    
    /**
     * 
     * @brief No file write permissions.
     */
    ByteRTCAudioRecordingErrorCodeNoPermission = -1,
    
    /**
     * 
     * @brief Not in the room.
     */
    ByteRTCAudioRecordingErrorNotInRoom = -2,
    
    /**
     * 
     * @brief Started.
     */
    ByteRTCAudioRecordingAlreadyStarted = -3,
    
    /**
     * 
     * @brief Not started.
     */
    ByteRTCAudioRecordingNotStarted = -4,
        
    /**
     * 
     * @brief Failure. Invalid file format.
     */
    ByteRTCAudioRecordingErrorCodeNotSupport = -5,
    
    /**
     * 
     * @brief Other error.
     */
    ByteRTCAudioRecordingErrorCodeOther = -6,
};

/**
 * 
 * @type keytype
 * @brief Media type for cellular assisted Enhancement
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCAudioEnhancementConfig: NSObject

/**
 * 
 * @brief Apply to signaling or not. Not by default.
 */
@property (assign, nonatomic) BOOL enhanceSignaling;

/**
 * 
 * @brief Apply to audio stream or not. Not by default.
 */
@property (assign, nonatomic) BOOL enhanceAudio;
@end

/**
 * 
 * @type keytype
 * @brief Information on the user's position in the rectangular coordinate system for the spatial audio.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCPositionInfo : NSObject

/**
 * 
 * @brief 3D coordinate values of the user's position in the rectangular coordinate system for the spatial audio. You need to build your own rectangular coordinate system. Refer to ByteRTCPosition{@link #ByteRTCPosition} for details.
 */
@property(strong, nonatomic) ByteRTCPosition *_Nonnull position;

/**
 * 
 * @brief Information on the three-dimensional orientation of the user in the rectangular coordinate system for the spatial audio. Any two of the 3D coordinate vectors of the user's position need to be perpendicular to each other. Refer to ByteRTCHumanOrientation{@link #ByteRTCHumanOrientation} for details.
 */
@property(strong, nonatomic) ByteRTCHumanOrientation *_Nonnull orientation;
@end