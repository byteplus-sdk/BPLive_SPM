/*
 * Copyright (c) 2022 The BytePlusRTC project authors. All Rights Reserved.
 * @brief ByteRTCKTVPlayer
*/

#import <Foundation/Foundation.h>
#import "ByteRTCKTVDefines.h"
@class ByteRTCKTVPlayer;

NS_ASSUME_NONNULL_BEGIN

/**
 * 
 * @hidden currently not available
 * @type callback
 * @brief KTV player event handler. <br>
 * Note: Callback functions are thrown synchronously in a non-UI thread within the SDK. Therefore, you must not perform any time-consuming operations or direct UI operations within the callback function, as this may cause the app to crash.
 */
@protocol ByteRTCKTVPlayerDelegate <NSObject>


/**
 * 
 * @type callback
 * @brief Music playing progress callback.
 * @param ktvPlayer Current ktvPlayer. See ByteRTCKTVPlayer{@link #ByteRTCKTVPlayer}.
 * @param musicId Music ID.
 * @param progress Music playing progress in milliseconds.
 */
- (void)ktvPlayer:(ByteRTCKTVPlayer *)ktvPlayer onPlayProgress:(NSString *)musicId progress:(int64_t)progress;


/**
 * 
 * @type callback
 * @brief Music playing state changed callback.
 * @param ktvPlayer Current ktvPlayer. See ByteRTCKTVPlayer{@link #ByteRTCKTVPlayer}.
 * @param musicId Music ID.
 * @param state Music playing status. See ByteRTCPlayState{@link #ByteRTCPlayState}.
 * @param error Error code. See ByteRTCKTVPlayerErrorCode{@link #ByteRTCKTVPlayerErrorCode}.
 * @note
 *       You will receive this callback on following events. <br>
 *       - When you successfully start playing music by calling playMusic:audioTrackType:audioPlayType:{@link #ByteRTCKTVPlayer#playMusic:audioTrackType:audioPlayType:}, you will receive this callback with `ByteRTCPlayStatePlaying` playState. Otherwise the playState will be `ByteRTCPlayStateFailed`.
 *       - If the music with the same music ID is playing when you call playMusic:audioTrackType:audioPlayType:{@link #ByteRTCKTVPlayer#playMusic:audioTrackType:audioPlayType:} again, the music will restart from the starting position, and you will receive this callback with `ByteRTCPlayStatePlaying` playState to inform the latter music has started.
 *       - When you successfully pause the music by calling pauseMusic:{@link #ByteRTCKTVPlayer#pauseMusic:}, you will receive this callback with `ByteRTCPlayStatePaused` playState. Otherwise the playState will be `ByteRTCPlayStateFailed`.
 *       - When you successfully resume the music by calling resumeMusic:{@link #ByteRTCKTVPlayer#resumeMusic:}, you will receive this callback with `ByteRTCPlayStatePlaying` playState. Otherwise the playState will be `ByteRTCPlayStateFailed`.
 *       - When you successfully stop the music by calling stopMusic:{@link #ByteRTCKTVPlayer#stopMusic:}, you will receive this callback with `ByteRTCPlayStateStoped` playState. Otherwise the playState will be `ByteRTCPlayStateFailed`.
 *       - When the music ends, you will receive this callback with `ByteRTCPlayStateFinished` playState.
 */
- (void)ktvPlayer:(ByteRTCKTVPlayer *)ktvPlayer onPlayStateChanged:(NSString *)musicId state:(ByteRTCPlayState)state error:(ByteRTCKTVPlayerErrorCode)error;
@end


/**
 * 
 * @hidden currently not available
 * @type api
 * @brief KTV player interfaces.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCKTVPlayer : NSObject

@property(nonatomic, weak) id<ByteRTCKTVPlayerDelegate> delegate;

#pragma mark - Core Methods

/**
 * 
 * @type api
 * @brief Plays the music.
 * @param musicId Music ID. <br>
 *        If the song with the same musicId is playing when you call this API, the music will restart from the starting position. An error will be triggered if the audio file corresponding to musicId does not exist.
 * @param trackType Audio track type of the KTV player. See ByteRTCAudioTrackType{@link #ByteRTCAudioTrackType}.
 * @param playType Audio play type. See ByteRTCAudioPlayType{@link #ByteRTCAudioPlayType}.
 * @note
 *       - After calling this API, you will receive the music play state through ktvPlayer:onPlayStateChanged:state:error:{@link #ByteRTCKTVPlayerDelegate#ktvPlayer:onPlayStateChanged:state:error:} callback.
 *       - If the music ID is invalid, you will receive the ktvPlayer:onPlayStateChanged:state:error:{@link #ByteRTCKTVPlayerDelegate#ktvPlayer:onPlayStateChanged:state:error:} callback, with an errorCode of -3023 and a playState of 4.
 *       - If you didn't join the room, you will receive the ktvPlayer:onPlayStateChanged:state:error:{@link #ByteRTCKTVPlayerDelegate#ktvPlayer:onPlayStateChanged:state:error:} callback, with an errorCode of -3022 and a playState of 4.
 *       - If the music file does not exist, you will receive the ktvPlayer:onPlayStateChanged:state:error:{@link #ByteRTCKTVPlayerDelegate#ktvPlayer:onPlayStateChanged:state:error:} callback, with an errorCode of -3020 and a playState of 4.
 */
- (void)playMusic:(NSString * _Nonnull)musicId audioTrackType:(ByteRTCAudioTrackType)trackType audioPlayType:(ByteRTCAudioPlayType)playType;


/**
 * 
 * @type api
 * @brief Pauses the music.
 * @param musicId Music ID.
 * @note
 *       - After calling this API, you will receive the music play state through ktvPlayer:onPlayStateChanged:state:error:{@link #ByteRTCKTVPlayerDelegate#ktvPlayer:onPlayStateChanged:state:error:} callback.
 *       - If the music ID is invalid, you will receive the ktvPlayer:onPlayStateChanged:state:error:{@link #ByteRTCKTVPlayerDelegate#ktvPlayer:onPlayStateChanged:state:error:} callback, with an errorCode of -3023 and a playState of 4.
 *       - If you didn't join the room, you will receive the ktvPlayer:onPlayStateChanged:state:error:{@link #ByteRTCKTVPlayerDelegate#ktvPlayer:onPlayStateChanged:state:error:} callback, with an errorCode of -3022 and a playState of 4.
 */
- (void)pauseMusic:(NSString * _Nonnull)musicId;


/**
 * 
 * @type api
 * @brief Resumes playing the music.
 * @param musicId Music ID.
 * @note
 *       - After calling this API, you will receive the music play state through ktvPlayer:onPlayStateChanged:state:error:{@link #ByteRTCKTVPlayerDelegate#ktvPlayer:onPlayStateChanged:state:error:} callback.
 *       - If the music ID is invalid, you will receive the ktvPlayer:onPlayStateChanged:state:error:{@link #ByteRTCKTVPlayerDelegate#ktvPlayer:onPlayStateChanged:state:error:} callback, with an errorCode of -3023 and a playState of 4.
 *       - If you didn't join the room, you will receive the ktvPlayer:onPlayStateChanged:state:error:{@link #ByteRTCKTVPlayerDelegate#ktvPlayer:onPlayStateChanged:state:error:} callback, with an errorCode of -3022 and a playState of 4.
 */
- (void)resumeMusic:(NSString * _Nonnull)musicId;


/**
 * 
 * @type api
 * @brief Stops playing the music.
 * @param musicId Music ID.
 * @note
 *       - After calling this API, you will receive the music play state through ktvPlayer:onPlayStateChanged:state:error:{@link #ByteRTCKTVPlayerDelegate#ktvPlayer:onPlayStateChanged:state:error:} callback.
 *       - If the music ID is invalid, you will receive the ktvPlayer:onPlayStateChanged:state:error:{@link #ByteRTCKTVPlayerDelegate#ktvPlayer:onPlayStateChanged:state:error:} callback, with an errorCode of -3023 and a playState of 4.
 *       - If you didn't join the room, you will receive the ktvPlayer:onPlayStateChanged:state:error:{@link #ByteRTCKTVPlayerDelegate#ktvPlayer:onPlayStateChanged:state:error:} callback, with an errorCode of -3022 and a playState of 4.
 */
- (void)stopMusic:(NSString * _Nonnull)musicId;


/**
 * 
 * @type api
 * @brief Sets the starting position of the music file.
 * @param musicId Music ID.
 * @param position The starting position of the music file in milliseconds. The value must be less than the total length of the music.
 * @note
 *       - The music must be playing when you call this API.
 *       - After calling this API, you will receive the music play state through ktvPlayer:onPlayStateChanged:state:error:{@link #ByteRTCKTVPlayerDelegate#ktvPlayer:onPlayStateChanged:state:error:} callback.
 *       - If the music ID is invalid, you will receive the ktvPlayer:onPlayStateChanged:state:error:{@link #ByteRTCKTVPlayerDelegate#ktvPlayer:onPlayStateChanged:state:error:} callback, with an errorCode of -3023 and a playState of 4.
 *       - If you didn't join the room, you will receive the ktvPlayer:onPlayStateChanged:state:error:{@link #ByteRTCKTVPlayerDelegate#ktvPlayer:onPlayStateChanged:state:error:} callback, with an errorCode of -3022 and a playState of 4.
 */
- (void)seekMusic:(NSString * _Nonnull)musicId position:(int)position;


/**
 * 
 * @type api
 * @brief Sets the volume of the playing music. The music must be playing when you set the volume.
 * @param musicId Music ID.
 * @param volume Volume. Adjustment range: [0,400]. <br>
 *         - 0: Mute.
 *         - 100: Original volume.
 *         - 400: 4 times the original volume (with overflow protection).
 * @note
 *       - The music must be playing when you call this API.
 *       - If the set volume is greater than 400, it will be adjusted by the maximum value of 400; if the set volume is less than 0, it will be adjusted by the minimum value of 0.
 *       - If the music ID is invalid, you will receive the ktvPlayer:onPlayStateChanged:state:error:{@link #ByteRTCKTVPlayerDelegate#ktvPlayer:onPlayStateChanged:state:error:} callback, with an errorCode of -3023 and a playState of 4.
 *       - If you didn't join the room, you will receive the ktvPlayer:onPlayStateChanged:state:error:{@link #ByteRTCKTVPlayerDelegate#ktvPlayer:onPlayStateChanged:state:error:} callback, with an errorCode of -3022 and a playState of 4.
 */
- (void)setMusicVolume:(NSString * _Nonnull)musicId volume:(int)volume;


/**
 * 
 * @type api
 * @brief Switches the audio track type between the original track and the instrumental track.
 * @param musicId Music ID.
 * @note The music must be playing when you call this API.
 */
- (void)switchAudioTrackType:(NSString * _Nonnull)musicId;


/**
 * 
 * @type api
 * @brief Transposes up/down the music being played.
 * @param musicId Music ID.
 * @param pitch The pitch up/down value relative to the original pitch, in the range of [-12, 12], with the default value of 0. <br>
 *              The difference in pitch between two adjacent values is a semitone. A positive value indicates an increase in pitch, and a negative value indicates a decrease in pitch. A larger absolute value means more pitch increase or decrease.
 * @note
 *       - The music must be in the playing when you call this API.
 *       - If the set pitch is greater than 12, it will be adjusted by the maximum value of 12; if the set pitch is less than –12, it will be adjusted by the minimum value of –12.
 *       - If the music ID is invalid, you will receive the ktvPlayer:onPlayStateChanged:state:error:{@link #ByteRTCKTVPlayerDelegate#ktvPlayer:onPlayStateChanged:state:error:} callback, with an errorCode of -3023 and a playState of 4.
 *       - If you didn't join the room, you will receive the ktvPlayer:onPlayStateChanged:state:error:{@link #ByteRTCKTVPlayerDelegate#ktvPlayer:onPlayStateChanged:state:error:} callback, with an errorCode of -3022 and a playState of 4.
 */
- (void)setMusicPitch:(NSString * _Nonnull)musicId pitch:(int)pitch;

@end

NS_ASSUME_NONNULL_END