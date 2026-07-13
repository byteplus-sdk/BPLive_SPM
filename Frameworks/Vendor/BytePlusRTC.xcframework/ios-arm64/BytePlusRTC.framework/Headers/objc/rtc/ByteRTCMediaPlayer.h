/*
 * Copyright (c) 2023 The BytePlusRTC project authors. All Rights Reserved.
 * @brief ByteRTCMediaPlayer
*/

#import <Foundation/Foundation.h>
#import "ByteRTCAudioDefines.h"

/**
 * 
 * @type callback
 * @brief observer for the audio frames during local audio file mixing.
 */
@protocol ByteRTCMediaPlayerAudioFrameObserver <NSObject>

/**
 * 
 * @type callback
 * @brief The callback for the audio frames during local audio file mixing.
 * @param playerId Player's ID
 * @param audioFrame See ByteRTCAudioFrame{@link #ByteRTCAudioFrame}.
 */
- (void)onFrame:(int)playerId audioFrame:(ByteRTCAudioFrame * _Nonnull)audioFrame;

@end

/**
 * 
 * @type callback
 * @brief Event handler for ByteRTCMediaPlayer{@link #ByteRTCMediaPlayer}. You must call setEventHandler:{@link #ByteRTCMediaPlayer#setEventHandler:} to set the corresponding event handler to get the events.
 */
@protocol ByteRTCMediaPlayerEventHandler <NSObject>

/**
* 
* @type callback
* @brief Callback for audio mixing status change.
* @param playerId The ID of ByteRTCMediaPlayer{@link #ByteRTCMediaPlayer}. Set by getMediaPlayer:{@link #ByteRTCVideo#getMediaPlayer:}.
* @param state See ByteRTCPlayerState{@link #ByteRTCPlayerState}.
* @param error See ByteRTCPlayerError{@link #ByteRTCPlayerError}.
*/
-(void)onMediaPlayerStateChanged:(int)playerId state:(ByteRTCPlayerState)state error:(ByteRTCPlayerError)error;

/**
* 
* @type callback
* @brief Periodic callback for audio mixing progress. The period is set by setProgressInterval:{@link #ByteRTCMediaPlayer#setProgressInterval:}.
* @param playerId The ID of ByteRTCMediaPlayer{@link #ByteRTCMediaPlayer}. Set by getMediaPlayer:{@link #ByteRTCVideo#getMediaPlayer:}.
* @param progress Mixing progress in ms.
*/
-(void)onMediaPlayerPlayingProgress:(int)playerId progress:(int64_t)progress;

@end

/**
 * 
 * @valid since 3.53
 * @type api
 * @brief Media player <br>
 *        Call setEventHandler:{@link #ByteRTCMediaPlayer#setEventHandler:} to set the callback handler to receive related callbacks.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCMediaPlayer :NSObject

/**
 * 
 * @type api
 * @brief Open the audio file. <br>
 *        You can only open one audio file with one player instance at the same time. For multiple audio files at the same time, create multiple player instances. <br>
 *        For audio file in PCM format, see openWithCustomSource:config:{@link #ByteRTCMediaPlayer#openWithCustomSource:config:}. `openWithCustomSource` and this API are mutually exclusive.
 * @param filePath Audio file paths. <br>
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
 * @param config See ByteRTCMediaPlayerConfig{@link #ByteRTCMediaPlayerConfig}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
 */
- (int)open:(NSString *_Nullable)filePath config:(ByteRTCMediaPlayerConfig *_Nullable)config;

/**
 * 
 * @type api
 * @brief Start playing the audio. Call this API when you call open:config:{@link #ByteRTCMediaPlayer#open:config:} and set `AutoPlay=False`.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
 * @note
 * - For audio file in PCM format, see openWithCustomSource:config:{@link #ByteRTCMediaPlayer#openWithCustomSource:config:}. `openWithCustomSource` and this API are mutually exclusive.
 * - After calling this API, call stop{@link #ByteRTCMediaPlayer#stop} to stop playing the audio file.
 */
- (int)start;

/**
 * 
 * @type api
 * @brief Enable audio mixing with audio raw data. <br>
 *        To open the audio file, see open:config:{@link #ByteRTCMediaPlayer#open:config:}. `open` and this API are mutually exclusive.
 * @param source See ByteRTCMediaPlayerCustomSource{@link #ByteRTCMediaPlayerCustomSource}.
 * @param config See ByteRTCMediaPlayerConfig{@link #ByteRTCMediaPlayerConfig}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
 * @note
 *       - After calling this API, you must call pushExternalAudioFrame:{@link #ByteRTCMediaPlayer#pushExternalAudioFrame:} to push audio data and start the audio mixing.
 *       - To stop the raw data audio mixing, call stop{@link #ByteRTCMediaPlayer#stop}.
 */
- (int)openWithCustomSource:(ByteRTCMediaPlayerCustomSource *_Nullable)source config:(ByteRTCMediaPlayerConfig *_Nullable)config;

/**
 * 
 * @type api
 * @brief After calling open:config:{@link #ByteRTCMediaPlayer#open:config:}, start{@link #ByteRTCMediaPlayer#start}, or openWithCustomSource:config:{@link #ByteRTCMediaPlayer#openWithCustomSource:config:} to start audio mixing, call this method to stop audio mixing.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
 */
- (int)stop;

/**
 * 
 * @type api
 * @brief After calling open:config:{@link #ByteRTCMediaPlayer#open:config:}, or start{@link #ByteRTCMediaPlayer#start} to start audio mixing, call this API to pause audio mixing.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
 * @note
 * - After calling this API to pause audio mixing, call resume{@link #ByteRTCMediaPlayer#resume} to resume audio mixing.
 * - The API is valid for audio file, not PCM data.
 */
- (int)pause;

/**
 * 
 * @type api
 * @brief After calling pause{@link #ByteRTCMediaPlayer#pause} to pause audio mixing, call this API to resume audio mixing.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
 * @note
 *        The API is valid for audio file, not PCM data.
 */
- (int)resume;

 /**
 * 
 * @type api
 * @brief Adjusts the volume of the specified audio mixing, including media file mixing and PCM mixing.
 * @param volume The ratio of the volume to the original volume in % with overflow protection. The range is `[0, 400]` and the recommended range is `[0, 100]`.
 * @param type See ByteRTCAudioMixingType{@link #ByteRTCAudioMixingType}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
 * @note Call this API only when audio is mixing.
 */
- (int)setVolume:(int)volume type:(ByteRTCAudioMixingType)type;

/**
 * 
 * @type api
 * @brief Gets the current volume.
 * @param type See ByteRTCAudioMixingType{@link #ByteRTCAudioMixingType}.
 * @return
 *        - >0: Success, the current volume.
 *        - < 0: Failed.
 * @note Call this API only when audio is mixing, including media file mixing and PCM mixing.
 */
- (int)getVolume:(ByteRTCAudioMixingType)type;

/**
 * 
 * @type api
 * @brief Gets the duration of the media file.
 * @return
 *        - >0: Success, the duration of the media file in milliseconds.
 *        - < 0: Failed.
 * @note
 *        - Call this API only when audio is mixing.
 *        - The API is valid for audio file, not PCM data.
 */
- (int)getTotalDuration;

/**
 * 
 * @type api
 * @brief Gets the actual playback duration of the mixed media file, in milliseconds.
 * @return
 *        - >0: Success, the actual playback time.
 *        - < 0: Failed.
 * @note
 *        - The actual playback time refers to the playback time of the song without being affected by stop, jump, double speed, and freeze. For example, if the song stops playing for 30 seconds at 1:30 or skips to 2:00, and then continues to play normally for 2 minutes, the actual playing time is 3 minutes and 30 seconds.
 *        - Call this API only when audio is mixing and the interval set by setProgressInterval:{@link #ByteRTCMediaPlayer#setProgressInterval:} is above `0`.
 *        - The API is valid for audio file, not PCM data.
 */
- (int)getPlaybackDuration;

/**
 * 
 * @type api
 * @brief Gets the playback progress of the media file.
 * @return
 *        - >0: Success, the playback progress of media file in ms.
 *        - < 0: Failed.
 * @note
 *        - Call this API only when audio is mixing.
 *        - The API is valid for audio file, not PCM data.
 */
- (int)getPosition;

/**
 * 
 * @type api
 * @brief Set the pitch of the local audio file mixing. Usually used in karaoke scenes.
 * @param pitch The increase or decrease value compared with the original pitch of the music file. The range is `[-12, 12]`. The default value is 0. The pitch distance between two adjacent values is half a step. A positive value indicates a rising pitch, and a negative value indicates a falling pitch.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
 * @note
 *        - Call this API only when audio is mixing.
 *        - Support audio file only and not PCM data.
 */
- (int)setAudioPitch:(int)pitch;

/**
 * 
 * @type api
 * @brief Sets the starting playback position of the media file.
 * @param position The starting position of the media file in milliseconds. <br>
 *        You can get the total duration of the media file through getTotalDuration{@link #ByteRTCMediaPlayer#getTotalDuration}. The value of position should be less than the total duration of the media file.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
 * @note
 *        - The API is valid for audio file, not PCM data.
 *        - When playing online files, calling this API may cause playback delay.
 */
- (int)setPosition:(int)position;

/**
 * 
 * @type api
 * @brief Sets the channel mode of the mixing of the media file.
 * @param mode The mode of channel. The default channel mode is the same as the source file. See ByteRTCAudioMixingDualMonoMode{@link #ByteRTCAudioMixingDualMonoMode}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
 * @note
 *       - Call this API only when audio is mixing.
 *       - Audio file is supported, but not PCM data.
 */
- (int)setAudioDualMonoMode:(ByteRTCAudioMixingDualMonoMode)mode;

/**
 * 
 * @type api
 * @brief Gets the track count of the current media file.
 * @return + >= 0：Success. Return the track count of the current media file.
 *         - < 0：Failed.
 * @note
 *       - Call this API only when audio is mixing.
 *       - This API is valid for audio file, not PCM data.
 */
- (int)getAudioTrackCount;

/**
 * 
 * @type api
 * @brief Specifies the playback track of the current media file.
 * @param index The specified playback audio track, starting from 0, and the range is `[0, getAudioTrackCount()-1]`. The value must be less than the return value of getAudioTrackCount{@link #ByteRTCMediaPlayer#getAudioTrackCount}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
 * @note
 *       - Call this API only when audio is mixing.
 *       - This API is valid for audio file, not PCM data.
 */
- (int)selectAudioTrack:(int)index;

/**
 * 
 * @type api
 * @brief Set the playback speed of the audio file.
 * @param speed The ratio of the actual playback speed than that of the original speed of the audio file in %. The range is `[50,200]`. The default value is 100.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
 * @note
 *       - Call this API only when audio is mixing.
 *       - The API is valid for audio file and not PCM data.
 */
- (int)setPlaybackSpeed:(int)speed;

 /**
 * 
 * @type api
 * @brief Set the interval of the periodic callback onMediaPlayerPlayingProgress:progress:{@link #ByteRTCMediaPlayerEventHandler#onMediaPlayerPlayingProgress:progress:} during audio mixing.
 * @param interval interval in ms. <br>
 *       - interval > 0: The callback is enabled. The actual interval is a multiple of 10. If the input value is not divisible by 10, it will be automatically rounded up. For example, if the input is `52`, the actual interval will be 60 milliseconds.
 *       - interval <= 0: The callback is disabled.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
 * @note
 *       - Call this API only when audio is mixing.
 *       - This API is valid for audio file, not PCM data.
 */
- (int)setProgressInterval:(int64_t)interval;

/**
 * 
 * @type api
 * @brief To call enableVocalInstrumentBalance:{@link #ByteRTCVideo#enableVocalInstrumentBalance:} to adjust the volume of the mixed media file or the PCM audio data, you must pass in its original loudness through this API.
 * @param loudness Original loudness in lufs. The range is `[-70.0, 0.0]`. <br>
 *       When the value is less than -70.0lufs, it will be adjusted to -70.0lufs by default, and if it is more than 0.0lufs, the loudness will not be equalized. The default value is 1.0lufs, which means no processing.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
 * @note
 *       - Call this API only when audio is mixing.
 *       - The API is valid for audio file and PCM data.
 */
- (int)setLoudness:(float)loudness;

/**
 * 
 * @type api
 * @brief Register an observer to receive related callbacks when the local media file is mixing.
 * @param observer See ByteRTCMediaPlayerAudioFrameObserver{@link #ByteRTCMediaPlayerAudioFrameObserver}.
 * @return
 *        - 0: Success.
 *        - < 0 : Fail. See ByteRTCReturnStatus{@link #ByteRTCReturnStatus} for more details.
 * @note
 *        The API is valid for audio file, not PCM data.
 */
- (int)registerAudioFrameObserver:(_Nullable id<ByteRTCMediaPlayerAudioFrameObserver>)observer;

/**
 * 
 * @type api
 * @brief Push PCM audio frame data for mixing.
 * @param audioFrame See ByteRTCAudioFrame{@link #ByteRTCAudioFrame}. <br>
 *        - The audio sampling format must be S16. The data format within the audio buffer must be PCM, and its capacity should be `audioFrame.samples × audioFrame.channel × 2`.
 *        - A specific sample rate and the number of channels must be specified; it is not supported to set them to automatic.
 * @return
 *       - 0: Success.
 *       - < 0: Failed.
 * @note
 *      - Before calling this method, the raw audio data mixing must be enabled through openWithCustomSource:config:{@link #ByteRTCMediaPlayer#openWithCustomSource:config:}.
 *      - Suggestions: Before pushing data for the first time, please cache a certain amount of data (like 200 ms) on the application side, and then push it at once. Schedule subsequent push operation every 10 ms with audio data of 10 ms.
 *      - To pause the playback, just pause the push.
 */
- (int)pushExternalAudioFrame:(ByteRTCAudioFrame *_Nullable)audioFrame;

/**
 * 
 * @type api
 * @brief Set the event handler.
 * @param handler See ByteRTCMediaPlayerEventHandler{@link #ByteRTCMediaPlayerEventHandler}.
 * @return
 *        - 0: Success.
 *        - < 0: Failed.
 */
- (int)setEventHandler:(_Nullable id<ByteRTCMediaPlayerEventHandler>)handler;
@end