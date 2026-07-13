/*
 *  Copyright (c) 2022 The BytePlusRTC project authors. All Rights Reserved.
 *  @company ByteDance.Inc
 *  @brief range audio interface
 */

#pragma once

#import <Foundation/Foundation.h>
#import "ByteRTCAudioDefines.h"


 /**
 * 
 * @type keytype
 * @brief Volume Roll-off modes that a sound has in an audio source
 */
typedef NS_ENUM(NSInteger, ByteRTCAttenuationType) {
    
    /**
     * 
     * @brief Disable Volume Attenuation
     */
    ByteRTCAttenuationTypeNone = 0,
    
    /**
     * 
     * @brief Linear roll-off mode which lowers the volume of the sound over the distance
     */
    ByteRTCAttenuationTypeLinear = 1,
    
    /**
     * 
     * @brief Exponential roll-off mode which exponentially decreases the volume of the sound with the distance raising
     */
    ByteRTCAttenuationTypeExponential = 2
};


/**
 * 
 * @type keytype
 * @brief The range where local user can hear audio with attenuation effect.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCReceiveRange : NSObject

/**
 * 
 * @brief The minimum distance at which the local user can hear the attenuated audio from remote users. <br>
 *        The value must be ≥ 0, but ≤ max. <br>
 *        No attenuation effect for audio from distances less than this value you set.
 */
@property(nonatomic, assign) int min;

/**
 * 
 * @brief The maximum distance at which the local user can hear audio from remote users. <br>
 *        The value must be ≥ min, and > 0. <br>
 *        Audio from distances larger than the value you set cannot be heard.
 */
@property(nonatomic, assign) int max;
@end



/**
 * 
 * @type api
 * @brief Range audio instance
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCRangeAudio :NSObject

/**
 * 
 * @type api
 * @region Range Audio
 * @brief Enables/disables the range audio function. <br>
 *        Range audio means that within a certain range in a same RTC room, the audio volume of the remote user received by the local user will be amplified/attenuated as the remote user moves closer/away. The audio coming from out of the range cannot be heard. See updateReceiveRange:{@link #ByteRTCRangeAudio#updateReceiveRange:} to set audio receiving range.
 * @param enable Whether to enable audio range function： <br>
 *        - YES: Enable
 *        - NO: Disable（Defaulting setting）
 * @note You can call this API anytime before or after entering a room. To ensure a smooth switch to the range audio mode after entering the room, you need to call updatePosition:{@link #ByteRTCRangeAudio#updatePosition:} before this API to set your own position coordinates, and then enable the range audio function.
 */
- (void)enableRangeAudio:(BOOL)enable;

/**
 * 
 * @type api
 * @region Range Audio
 * @brief Updates the audio receiving range for the local user.
 * @param range Audio receiving range, see ByteRTCReceiveRange{@link #ByteRTCReceiveRange}.
 * @return API call result: <br>
 *        - 0: Success
 *        - !0: Failure
 */
- (int)updateReceiveRange:(ByteRTCReceiveRange* _Nonnull) range;

/**
 * 
 * @type api
 * @region Range Audio
 * @brief Updates the coordinate of the local user's position in the rectangular coordinate system in the current room.
 * @param pos 3D coordinate values, the default value is [0, 0, 0], see [ByteRTCPosition](70088#position-2).
 * @return API call result: <br>
 *        - 0: Success
 *        - !0: Failure
 * @note After calling this API, you should call enableRangeAudio:{@link #ByteRTCRangeAudio#enableRangeAudio:} to enable range audio function to actually enjoy the range audio effect.
 */
- (int)updatePosition:(ByteRTCPosition* _Nonnull) pos;


/**
 * 
 * @type api
 * @region Range Audio
 * @brief Set the volume attenuation mode of the range audio.
 * @param type Volume roll-off mode. It is linear roll-off mode by default. Refer to ByteRTCAttenuationType{@link #ByteRTCAttenuationType} for more details.
 * @param coefficient Coefficient for the exponential roll-off mode. The default value is 1. It ranges [0.1,100]. We recommended to set it to `50`. The volume roll-off speed gets faster as this value increases.
 * @return Result of the call <br>
 *         - `0`: Success
 *         - `-1`: Failure because of calling this API before the user has joined a room or before enabling the Range Audio feature by calling enableRangeAudio:{@link #ByteRTCRangeAudio#enableRangeAudio:}.
 * @note Call updateReceiveRange:{@link #ByteRTCRangeAudio#updateReceiveRange:} to set the range outside which the volume of the sound does not attenuate.
 */
- (int)setAttenuationModel:(ByteRTCAttenuationType) type coefficient:(float)coefficient;


/**
 * 
 * @type api
 * @region Range Audio
 * @brief Set the flags to mark the user groups, within which the users talk without attenuation. <br>
 *        In the RTC room, if the flags of the users intersects with each other, the users talk without attenuation. <br>
 *        For example, the user is a member of multiple teams, and teammates of the same team talks without attentuation. You can set the flag for each team, and includes the flags of the user's teams in the user's flags.
 * @param flags Array of flags.
 */
- (void) setNoAttenuationFlags:(NSArray <NSString *> *_Nonnull)flags;

@end