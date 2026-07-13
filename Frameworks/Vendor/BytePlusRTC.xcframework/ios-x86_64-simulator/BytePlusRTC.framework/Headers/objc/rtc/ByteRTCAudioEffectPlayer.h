/*
 * Copyright (c) 2023 The BytePlusRTC project authors. All Rights Reserved.
 * @brief ByteRTCAudioEffectPlayer
*/

#import <Foundation/Foundation.h>
#import "ByteRTCAudioDefines.h"

/**
 * 
 * @type callback
 * @brief Event handler for ByteRTCAudioEffectPlayer{@link #ByteRTCAudioEffectPlayer}. You must call setEventHandler:{@link #ByteRTCAudioEffectPlayer#setEventHandler:} to set the corresponding event handler to get the events.
 */  
@protocol ByteRTCAudioEffectPlayerEventHandler <NSObject>

/**
* 
* @type callback
* @brief Callback for audio mixing status change.
* @param effectId The ID of ByteRTCAudioEffectPlayer{@link #ByteRTCAudioEffectPlayer}. Set by getAudioEffectPlayer{@link #ByteRTCVideo#getAudioEffectPlayer}.
* @param state See ByteRTCPlayerState{@link #ByteRTCPlayerState}.
* @param error See ByteRTCPlayerError{@link #ByteRTCPlayerError}.
*/
-(void)onAudioEffectPlayerStateChanged:(int)effectId state:(ByteRTCPlayerState)state error:(ByteRTCPlayerError)error;

@end

/**
 * 
 * @valid since 3.53
 * @type api
 * @brief Audio effect player <br>
 * Notes: <br>
 *      - Call setEventHandler:{@link #ByteRTCAudioEffectPlayer#setEventHandler:} to set the callback handler to receive related callbacks.
 *      - When using `ByteRTCAudioEffectPlayer`, you must call [setActive:withOptions:error:](https:
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCAudioEffectPlayer :NSObject

/**
 * 
 * @type api
 * @brief Starts to play the audio effect file. <br>
 *        This API can be called multiple times with different IDs and filepaths for multiple effects at the same time.
 * @param effectId Audio effect ID. Used for identifying the audio effect, please ensure that the audio effect ID is unique. <br>
 *        If this API is called repeatedly with the same ID, the previous effect will stop and the next effect will start, and you'll receive onAudioEffectPlayerStateChanged:state:error:{@link #ByteRTCAudioEffectPlayerEventHandler#onAudioEffectPlayerStateChanged:state:error:}.
 * @param filePath Audio effect file paths. <br>
 *        URL of online file, URI of local file, or full path to local file are supported. For URL of online file, only the https protocol is supported. <br>
 *        Recommended sample rate for audio effect files: 8KHz、16KHz、22.05KHz、44.1KHz、48KHz. <br>
 *        Local audio effect file formats supported by different platforms: <br>
 *        <table>
 *           <tr><th></th><th>mp3</th><th>mp4</th><th>aac</th><th>m4a</th><th>3gp</th><th>wav</th><th>ogg</th><th>ts</th><th>wma</th></tr>
 *           <tr><td>Android</td><td>Y</td><td>Y</td><td>Y</td><td>Y</td><td>Y</td><td>Y</td><td>Y</td><td></td><td></td></tr>
 *           <tr><td>iOS/macOS</td><td>Y</td><td>Y</td><td>Y</td><td>Y</td><td>Y</td><td>Y</td><td></td><td></td><td></td></tr>
 *           <tr><td>Windows</td><td>Y</td><td>Y</td><td>Y</td><td>Y</td><td>Y</td><td>Y</td><td></td><td>Y</td><td>Y</td></tr>
 *        </table>
 *        Online audio effect file formats supported by different platforms. <br>
 *        <table>
 *           <tr><th></th><th>mp3</th><th>mp4</th><th>aac</th><th>m4a</th><th>3gp</th><th>wav</th><th>ogg</th><th>ts</th><th>wma</th></tr>
 *           <tr><td>Android</td><td>Y</td><td></td><td>Y</td><td>Y</td><td>Y</td><td>Y</td><td></td><td></td><td></td></tr>
 *           <tr><td>iOS/macOS</td><td>Y</td><td></td><td>Y</td><td>Y</td><td></td><td>Y</td><td></td><td></td><td></td></tr>
 *           <tr><td>Windows</td><td>Y</td><td></td><td>Y</td><td>Y</td><td>Y</td><td>Y</td><td></td><td>Y</td><td>Y</td></tr>
 *        </table>
 * @param config See ByteRTCAudioEffectPlayerConfig{@link #ByteRTCAudioEffectPlayerConfig}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
 * @note
 *       - If the file has been loaded into memory via preload:filePath:{@link #ByteRTCAudioEffectPlayer#preload:filePath:}, make sure that the ID here is the same as the ID set by `preload`.
 *       - After starting to play an audio effect file, you can call the stop:{@link #ByteRTCAudioEffectPlayer#stop:} API to stop playing the audio effect file.
 */
-(int)start:(int)effectId filePath:(NSString * _Nullable)filePath config:(ByteRTCAudioEffectPlayerConfig * _Nullable)config;

/**
 * 
 * @type api
 * @brief Stops the playback of audio effect files.
 * @param effectId Audio effect ID
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
 * @note
 *       - After calling the start:filePath:config:{@link #ByteRTCAudioEffectPlayer#start:filePath:config:} API to start playing the audio effect file, you can call this API to stop playing the audio effect file.
 *       - After calling this API to stop playing an audio effect file, the audio effect file will be unloaded automatically.
 */
-(int)stop:(int)effectId;

/**
 * 
 * @type api
 * @brief Stops playback of all audio effect files.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
 * @note
 *       - After calling start:filePath:config:{@link #ByteRTCAudioEffectPlayer#start:filePath:config:} to start playing audio effect files, you can call this API to stop playing all audio effect files.
 *       - After calling this API to stop playing all audio effect files, the audio effect files will be unloaded automatically.
 */
-(int)stopAll;

/**
 * 
 * @type api
 * @brief Preloads specified music files into memory to avoid repeated loading when playing the same file frequently and reduce CPU usage.
 * @param effectId Audio effect ID。Used for identifying the audio effect. Please ensure that the audio effect ID is unique. <br>
 *        If this API is called repeatedly with the same ID, the later one will overwrite the previous one. <br>
 *        If you call start:filePath:config:{@link #ByteRTCAudioEffectPlayer#start:filePath:config:} first and then call this API with the same ID, the SDK will stop the previous effect and then load the next one, and you will receive onAudioEffectPlayerStateChanged:state:error:{@link #ByteRTCAudioEffectPlayerEventHandler#onAudioEffectPlayerStateChanged:state:error:}. <br>
 *        After calling this API to preload A.mp3, if you need to call start:filePath:config:{@link #ByteRTCAudioEffectPlayer#start:filePath:config:} to play B.mp3 with the same ID, please call unload:{@link #ByteRTCAudioEffectPlayer#unload:} to unload A.mp3 first, otherwise SDK will report an error AUDIO_MIXING_ERROR_LOAD_CONFLICT.
 * @param filePath The filepath of effect file. URI or absolute path of a local file. <br>
 *        The length of the pre-loaded file must not exceed 20s. <br>
 *        Audio effect file formats supported are the same as start:filePath:config:{@link #ByteRTCAudioEffectPlayer#start:filePath:config:}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
 * @note
 *       - This API just preloads the specified audio effect file, and only calls the start:filePath:config:{@link #ByteRTCAudioEffectPlayer#start:filePath:config:} API to start playing the specified audio effect file.
 *       - The specified audio effect file preloaded by calling this API can be unloaded by unload:{@link #ByteRTCAudioEffectPlayer#unload:}.
 */
-(int)preload:(int)effectId filePath:(NSString * _Nullable)filePath;

/**
 * 
 * @type api
 * @region Audio effect player
 * @brief Unloads the specified audio effect file.
 * @param effectId Audio effect ID.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
 * @note After calling this method, regarding the current mixing state, if setEventHandler:{@link #ByteRTCAudioEffectPlayer#setEventHandler:} is set, you will receive the `onAudioEffectPlayerStateChanged` callback.
 */
-(int)unload:(int)effectId;

/**
 * 
 * @type api
 * @region Audio effect player
 * @brief Unloads all audio effect files.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
 * @note After calling this method, regarding the current mixing state, if setEventHandler:{@link #ByteRTCAudioEffectPlayer#setEventHandler:} is set, you will receive the `onAudioEffectPlayerStateChanged` callback.
 */
-(int)unloadAll;

/**
 * 
 * @type api
 * @brief Pauses the playback of audio effect files.
 * @param effectId Audio effect ID
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
 * @note
 *       - After calling start:filePath:config:{@link #ByteRTCAudioEffectPlayer#start:filePath:config:} to start playing the audio effect file, you can pause the audio effect file by calling this API.
 *       - After calling this API to pause the audio effect file, you can call the resume:{@link #ByteRTCAudioEffectPlayer#resume:} API to resume playback.
 */
-(int)pause:(int)effectId;

/**
 * 
 * @type api
 * @brief Pauses the Playback of all audio effect files.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
 * @note
 *       - After calling the start:filePath:config:{@link #ByteRTCAudioEffectPlayer#start:filePath:config:} API to start playing audio effect files, you can pause playing all audio effect files by calling this API.
 *       - After calling this API to pause the playback of all audio effect files, you can call the resumeAll{@link #ByteRTCAudioEffectPlayer#resumeAll} API to resume all playback.
 */
-(int)pauseAll;

/**
 * 
 * @type api
 * @brief Resumes the playback of audio effect files.
 * @param effectId Audio effect ID
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
 * @note After calling the pause:{@link #ByteRTCAudioEffectPlayer#pause:} API to pause the audio effect file, you can resume playback by calling this API.
 */
-(int)resume:(int)effectId;

/**
 * 
 * @type api
 * @brief Resumes the playback of all audio effect files.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
 * @note After calling the pauseAll{@link #ByteRTCAudioEffectPlayer#pauseAll} API to pause all the audio effect files being played, you can resume playback by calling this API.
 */
-(int)resumeAll;

/**
 * 
 * @type api
 * @brief Sets the start position of the audio effect file.
 * @param effectId Audio effect ID
 * @param position The starting playback position of the audio effect file in milliseconds. <br>
 *        You can get the total duration of the audio effect file by calling getDuration:{@link #ByteRTCAudioEffectPlayer#getDuration:}, the value of position should be less than the total duration of the audio effect file.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
 * @note
 *        - When playing online files, calling this API may cause a delay in playback.
 *        - Call this API after start:filePath:config:{@link #ByteRTCAudioEffectPlayer#start:filePath:config:}.
 */
-(int)setPosition:(int)effectId position:(int)position;

/**
 * 
 * @type api
 * @brief Gets the current position of audio effect file playback.
 * @param effectId  Audio effect ID
 * @return
 *        - >0: Success, the current progress of audio effect file playback in milliseconds.
 *        - < 0: Failure.
 * @note
 *        - When playing online files, calling this API may cause a delay in playback.
 *        - Call this API after start:filePath:config:{@link #ByteRTCAudioEffectPlayer#start:filePath:config:}.
 */
-(int)getPosition:(int)effectId;

/**
 * 
 * @type api
 * @brief Adjusts the volume level of a specified audio effect, including audio effect file and PCM effect.
 * @param effectId Audio effect ID
 * @param volume The ratio of the volume to the original volume in % with overflow protection. The range is `[0, 400]` and the recommended range is `[0, 100]`.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
 * @note Call this API after start:filePath:config:{@link #ByteRTCAudioEffectPlayer#start:filePath:config:}.
 */
-(int)setVolume:(int)effectId volume:(int)volume;

/**
 * 
 * @type api
 * @brief Sets the volume of all audio effect, including audio effect files and PCM effects.
 * @param volume The ratio of the volume to the original volume in % with overflow protection. The range is `[0, 400]` and the recommended range is `[0, 100]`.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
 * @note This API has a lower priority than setVolume:volume:{@link #ByteRTCAudioEffectPlayer#setVolume:volume:}, i.e. the volume of the audio effect set by `setVolume` is not affected by this API.
 */
-(int)setVolumeAll:(int)volume;

/**
 * 
 * @type api
 * @brief Gets the current volume.
 * @param effectId  Audio effect ID
 * @return
 *        - >0: Success, the current volume value.
 *        - < 0: Failed.
 * @note Call this API after start:filePath:config:{@link #ByteRTCAudioEffectPlayer#start:filePath:config:}.
 */
-(int)getVolume:(int)effectId;

/**
 * 
 * @type api
 * @brief Get the duration of the audio effect file.
 * @param effectId  Audio effect ID
 * @return
 *        - >0: Success, the duration of the audio effect file in milliseconds.
 *        - < 0: failed.
 * @note Call this API after start:filePath:config:{@link #ByteRTCAudioEffectPlayer#start:filePath:config:}.
 */
-(int)getDuration:(int)effectId;

/**
 * 
 * @type api
 * @brief Set the event handler.
 * @param handler See ByteRTCAudioEffectPlayerEventHandler{@link #ByteRTCAudioEffectPlayerEventHandler}.
 * @return
 *        - 0: Success.
 *        - < 0: Failed.
 */
-(int)setEventHandler:(_Nullable id<ByteRTCAudioEffectPlayerEventHandler>)handler;
@end