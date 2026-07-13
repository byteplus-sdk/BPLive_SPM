/*
 * Copyright (c) 2021 The BytePlusRTC project authors. All Rights Reserved.
 * @brief ByteRTCAudioMixingManager
*/

#import <Foundation/Foundation.h>
#import "ByteRTCAudioDefines.h"

/**
 * 
 * @type callback
 * @brief Karaoke scoring event handler. <br>
 * Note: Callback functions are thrown synchronously in a non-UI thread within the SDK. Therefore, you must not perform any time-consuming operations or direct UI operations within the callback function, as this may cause the app to crash.
 */
BYTERTC_APPLE_EXPORT @protocol ByteRTCSingScoringDelegate<NSObject>
@required

/**
 * 
 * @type callback
 * @brief The callback for real-time scoring data. This callback is triggered after startSingScoring:scoringInfoInterval:{@link #ByteRTCSingScoringManager#startSingScoring:scoringInfoInterval:} is called.
 * @param info Real-time scoring data. See ByteRTCSingScoringRealtimeInfo{@link #ByteRTCSingScoringRealtimeInfo}.
 * @list online KTV
 * @order 9
 */
- (void)onCurrentScoringInfo:(ByteRTCSingScoringRealtimeInfo * _Nullable)info;
@end

/**
 * 
 * @type api
 * @brief Karaoke scoring management interface.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCSingScoringManager :NSObject

/**
 * 
 * @type api
 * @brief Initialize karaoke scoring feature.
 * @param singScoringAppkey The key for karaoke scoring, used to authenticate whether the karaoke scoring is enabled.
 * @param singScoringToken The key for karaoke scoring, used to authenticate whether the karaoke scoring is enabled.
 * @param delegate Karaoke scoring event handler，see ByteRTCSingScoringDelegate{@link #ByteRTCSingScoringDelegate}.
 * @note Enter two keys to enable karaoke scoring. Authentication is done offline, bind the Appkey and Token according to the package name (bundleID). Please contact technical support to apply for the key.
 * @return
 *        - 0：Success.
 *        - -1：Interface call failed.
 *        - -2： Karaoke scoring module not integrated.
 *        - >0： Other error. For details, see[Error code].
 * @list online KTV
 * @order 21
 */
-(int)initSingScoring:(NSString * _Nullable)singScoringAppkey
     singScoringToken:(NSString * _Nullable)singScoringToken
             delegate:(id<ByteRTCSingScoringDelegate> _Nullable)delegate;

/**
 * 
 * @type api
 * @brief Set the configuration of karaoke scoring.
 * @param config The parameters of karaoke scoring. See ByteRTCSingScoringConfig{@link #ByteRTCSingScoringConfig}.
 * @return
 *        - 0：Success.
 *        - -1：Interface call failed.
 *        - -2： Karaoke scoring module not integrated.
 *        - >0： Other error. For details, see[Error code].
 * @list online KTV
 * @order 22
 */
-(int)setSingScoringConfig:(ByteRTCSingScoringConfig * _Nullable)config;

/**
 * 
 * @type api
 * @brief Get standard pitch.
 * @param midiFilepath Midi file path of the song.
 * @return ByteRTCStandardPitchInfo{@link #ByteRTCStandardPitchInfo} Standard pitch data array.
 * @note
 *        - Please make sure the same midi file path is passed in this API and setSingScoringConfig:{@link #ByteRTCSingScoringManager#setSingScoringConfig:}.
 * @list online KTV
 * @order 23
 */
-(NSArray<ByteRTCStandardPitchInfo* > * _Nullable)getStandardPitchInfo:(NSString* _Nullable)midiFilepath;

/**
 * 
 * @type api
 * @brief Start karaoke scoring.
 * @param position You can get the playback position where you start karaoke scoring. Unit: ms.
 * @param scoringInfoInterval Time interval between two real-time callbacks. Unit: ms; Default interval: 50 ms. Minimum interval: 20 ms.
 * @return
 *        - 0：Success.
 *        - -1：Interface call failed.
 *        - -2： Karaoke scoring module not integrated.
 *        - >0： Other error. For details, see[Error code].
 * @note
 *        - You can call this API after calling initSingScoring:singScoringToken:delegate:{@link #ByteRTCSingScoringManager#initSingScoring:singScoringToken:delegate:} to initialize karaoke scoring.
 *        - After this interface is called, you will receive the scoring result onCurrentScoringInfo:{@link #ByteRTCSingScoringDelegate#onCurrentScoringInfo:} at set interval.
 *        - If you call the startAudioMixing:filePath:config:{@link #ByteRTCAudioMixingManager#startAudioMixing:filePath:config:} to play an audio file, call this interface after you receive rtcEngine:onAudioMixingStateChanged:state:error:{@link #ByteRTCVideoDelegate#rtcEngine:onAudioMixingStateChanged:state:error:}(ByteRTCAudioMixingStatePlaying).
 * @list online KTV
 * @order 24
 */
-(int)startSingScoring:(int)position
   scoringInfoInterval:(int)scoringInfoInterval;

/**
 * 
 * @type api
 * @brief Stop karaoke scoring.
 * @return
 *        - 0：Success.
 *        - <0：Failure.
 * @list online KTV
 * @order 25
 */
-(int)stopSingScoring;

/**
 * 
 * @type api
 * @brief Get the score for the previous lyric. You can call this API after startSingScoring:scoringInfoInterval:{@link #ByteRTCSingScoringManager#startSingScoring:scoringInfoInterval:} is called.
 * @return
 *        - <0：Failed to get the score for the previous lyric.
 *        - >=0：The score for the previous lyric.
 * @list online KTV
 * @order 26
 */
-(int)getLastSentenceScore;

/**
 * 
 * @type api
 * @brief Get the total score for the user's current performance. You can call this API after startSingScoring:scoringInfoInterval:{@link #ByteRTCSingScoringManager#startSingScoring:scoringInfoInterval:} is called.
 * @return
 *        - <0：Failed to get the total score.
 *        - >=0：The current total score.
 * @list online KTV
 * @order 27
 */
-(int)getTotalScore;

/**
 * 
 * @type api
 * @brief Get the average score for the user's current performance.
 * @return
 *        - <0：Failed to get the average score.
 *        - >=0：The average score.
 * @list online KTV
 * @order 28
 */
-(int)getAverageScore;
@end