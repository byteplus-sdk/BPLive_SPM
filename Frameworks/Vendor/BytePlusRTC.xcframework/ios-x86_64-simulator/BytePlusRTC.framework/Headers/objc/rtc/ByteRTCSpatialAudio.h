/*
 *  Copyright (c) 2022 The BytePlusRTC project authors. All Rights Reserved.
 *  @company ByteDance.Inc
 *  @brief spatial audio interface
 */

#pragma once

#import <Foundation/Foundation.h>
#import "ByteRTCAudioDefines.h"


/**
 * 
 * @type api
 * @brief Spatial audio instance
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCSpatialAudio : NSObject

/**
 * 
 * @type api
 * @region Spatial Audio
 * @brief Enables/disables spatial audio function.
 * @param enable Whether to enable spatial audio function: <br>
 *        - YES: Enable
 *        - NO: Disable(Default setting)
 * @note You need to call updatePosition:{@link #ByteRTCSpatialAudio#updatePosition:} as well to really enjoy the spatial audio effect.
 */
- (void)enableSpatialAudio:(BOOL)enable;

/**
 * 
 * @deprecated since 3.52, will be deleted in 3.58, use updateSelfPosition:{@link #ByteRTCSpatialAudio#updateSelfPosition:} instead
 * @type api
 * @brief Updates the coordinate of the local user's position as a sound source in the rectangular coordinate system in the current room. <br>
 *        Without setting the position as a listener by calling updateListenerPosition:{@link #ByteRTCSpatialAudio#updateListenerPosition:}, the position as a listener is the same as the position as a sound source.
 * @param pos 3D coordinate values, the default value is [0, 0, 0], see ByteRTCPosition{@link #ByteRTCPosition}.
 * @return API call result: <br>
 *        - 0: Success
 *        - !0: Failure
 * @note Before calling this API, you should call enableSpatialAudio:{@link #ByteRTCSpatialAudio#enableSpatialAudio:} first to enable spatial audio function.
 */
-(int)updatePosition:(ByteRTCPosition* _Nonnull) pos
__deprecated_msg("deprecated since 352, use updateSelfPosition instead");


/**
 * 
 * @deprecated since 3.52, will be deleted in 3.58, use updateSelfPosition:{@link #ByteRTCSpatialAudio#updateSelfPosition:} instead
 * @type api
 * @region Audio management
 * @brief After the local user joins the room, call this API to update the orientation of the local user as a sound source in the 3D coordinates for the spatial audio. <br>
 *        Without setting the orientation as a listener by calling updateListenerOrientation:{@link #ByteRTCSpatialAudio#updateListenerOrientation:}, the orientation as a listener is the same as the orientation as a sound source.
 * @param orientation Refer to ByteRTCHumanOrientation{@link #ByteRTCHumanOrientation} for more information.
 * @return API call result: <br>
 *        - 0: Success
 *        - !0: Failure
 * @note
 *        -  Before calling this API, you should call enableSpatialAudio:{@link #ByteRTCSpatialAudio#enableSpatialAudio:} first to enable spatial audio function, and then call UpdatePosition:{@link #ByteRTCSpatialAudio#updatePosition:} to update the position of the local user.
 *        -  Call disableRemoteOrientation{@link #ByteRTCSpatialAudio#disableRemoteOrientation} to disable the orientation effect as the sound source.
 */
-(int)updateSelfOrientation:(ByteRTCHumanOrientation* _Nonnull) orientation
__deprecated_msg("deprecated since 352, use updateSelfPosition instead");


/**
 * 
 * @type api
 * @region Audio management
 * @brief Turn off the effect of the orientation of the local user as the sound source. <br>
 *        After the effect is off, all the other users in the room listen to the local user as if the local user is in right front of each of them.
 * @note
 *        - After the orientation effect as the sound source is disabled, you cannot enable it during the lifetime of the `SpatialAudio` instance.
 *        - Calling this API does not affect the orientation effect of the local user as a listener. See updateSelfPosition:{@link #ByteRTCSpatialAudio#updateSelfPosition:} and updateRemotePosition:positionInfo:{@link #ByteRTCSpatialAudio#updateRemotePosition:positionInfo:}.
 */
-(void)disableRemoteOrientation;

/**
 * 
 * @deprecated since 3.52, will be deleted in 3.58, use updateRemotePosition:positionInfo:{@link #ByteRTCSpatialAudio#updateRemotePosition:positionInfo:} instead
 * @type api
 * @brief Updates the local user's position as a listener in the RTC room. <br>
 *        By calling this API, you can set the position of the local user as a listener different from the position as a sound source.
 * @param pos 3D coordinate values. See ByteRTCPosition{@link #ByteRTCPosition}. <br>
 *                 If the API is not called, the position as a listener is the same as that set by calling updatePosition:{@link #ByteRTCSpatialAudio#updatePosition:}.
 * @return
 *        - 0: Success
 *        - !0: Failure
 * @note Before calling this API, you should call enableSpatialAudio:{@link #ByteRTCSpatialAudio#enableSpatialAudio:} first to enable the spatial audio function.
 */
-(int)updateListenerPosition:(ByteRTCPosition* _Nonnull) pos
__deprecated_msg("deprecated since 352, use updateRemotePosition instead");

/**
 * 
 * @deprecated since 3.52, will be deleted in 3.58, use updateRemotePosition:positionInfo:{@link #ByteRTCSpatialAudio#updateRemotePosition:positionInfo:} instead
 * @type api
 * @brief Updates the local user's orientation as a listener in the RTC room. <br>
 *        By calling this API, you can set the orientation of the local user as a listener different from the orientation as a sound source.
 * @param orientation See ByteRTCHumanOrientation{@link #ByteRTCHumanOrientation}. <br>
 *                    If the API is not called, the orientation as a listener is the same as that set by calling updateSelfOrientation:{@link #ByteRTCSpatialAudio#updateSelfOrientation:}.
 * @return API call result: <br>
 *        - 0: Success
 *        - !0: Failure
 * @note Before calling this API, you should call enableSpatialAudio:{@link #ByteRTCSpatialAudio#enableSpatialAudio:} first to enable spatial audio function, and then call UpdatePosition:{@link #ByteRTCSpatialAudio#updatePosition:} to update the position of the local user.
 */
-(int)updateListenerOrientation:(ByteRTCHumanOrientation* _Nonnull)orientation
__deprecated_msg("deprecated since 352, use updateRemotePosition instead");

/**
 * 
 * @valid since 3.52
 * @type api
 * @region Audio management
 * @brief Sets the coordinate and orientation of the local user as a listener in the rectangular coordinate system the local user built to achieve expected spatial audio effects.
 * @param positionInfo  Information on the local user's position. Refer to  ByteRTCPositionInfo{@link #ByteRTCPositionInfo} for details.
 * @return
 *        - 0: Success.
 *        - <0: Failure.
 *        - -2: Failure. The reason is that any two of the 3D coordinate vectors of your position are not perpendicular to each other.
 * @note
 *        - You need to call this API after joining the room.
 *        - Before calling this API, you should call enableSpatialAudio:{@link #ByteRTCSpatialAudio#enableSpatialAudio:} first to enable the spatial audio function.
 *        - The settings made locally will not influence other users' spatial audio experience.
 */
-(int)updateSelfPosition:(ByteRTCPositionInfo* _Nonnull)positionInfo;

/**
 * 
 * @valid since 3.52
 * @type api
 * @region Audio management
 * @brief Sets the coordinate and orientation of the remote user as a speaker in the rectangular coordinate system of the local user. In this case, the local user hears from the remote user with the expected spatial audio effects.
 * @param uid User ID
 * @param positionInfo Information on the remote user's position. Refer to ByteRTCPositionInfo{@link #ByteRTCPositionInfo} for details.
 * @return
 *        - 0: Success.
 *        - <0: Failure.
 *        - -2: Failure. The reason is that any two of the 3D coordinate vectors of the position of the remote user are not perpendicular to each other.
 * @note
 *        You must call this API after creating the room. <br>
 *        The settings made locally will not influence other users' spatial audio experience.
 */
-(int)updateRemotePosition:(NSString * _Nonnull)uid
                         positionInfo:(ByteRTCPositionInfo* _Nonnull)positionInfo;

/**
 * 
 * @valid since 3.52
 * @type api
 * @region Audio management
 * @brief Disables all spatial audio effects set by calling updateRemotePosition:positionInfo:{@link #ByteRTCSpatialAudio#updateRemotePosition:positionInfo:} for a certain remote user.
 * @param uid User ID of the remote user.
 * @return
 *        - 0: Success.
 *        - <0: Failure.
 */
-(int)removeRemotePosition:(NSString * _Nonnull)uid;

/**
 * 
 * @valid since 3.52
 * @type api
 * @region Audio management
 * @brief Disables all spatial audio effects set by calling updateRemotePosition:positionInfo:{@link #ByteRTCSpatialAudio#updateRemotePosition:positionInfo:} for all remote users.
 * @return
 *        - 0: Success.
 *        - <0: Failure.
 */
-(int)removeAllRemotePosition;
@end