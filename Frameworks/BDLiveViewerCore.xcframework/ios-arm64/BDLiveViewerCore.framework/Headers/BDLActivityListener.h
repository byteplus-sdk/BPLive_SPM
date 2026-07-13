//
//  BDLActivityListener.h
//
//  BPLive SDK License
//
//  Copyright 2022 Byteplus Pte. Ltd. All Rights Reserved.
//
//  The BPLive SDK was developed by Byteplus Pte. Ltd. (hereinafter “Byteplus”).
//  Any copyright or patent right is owned by and proprietary material of the Byteplus.
//
//  BPLive SDK is available under the Byteplus product and licensed under the commercial license.
//  Customers can contact via https://www.byteplus.com/en/contact for commercial licensing options.
//  Here is also a link to Service Level Agreement: https://docs.byteplus.com/en/byteplus-livesaas/docs/byteplus-live-service-level-agreement
//
//  Without Byteplus's prior written permission, any use of BPLive SDK, in particular any use for commercial purposes, is prohibited.
//  This includes, without limitation, incorporation in a commercial product, use in a commercial service, or production of other artefacts for commercial purposes.
//
//  Without Byteplus's prior written permission, the BPLive SDK may not be reproduced, modified and/or made available in any form to any third party.
#import <BDLiveCommon/BDLDefines.h>
#import "BDLActivity.h"
#import <BDLiveCommon/BDLNetworkService.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type callback
 * @brief 直播间的监听器。
 */
/**
 * @locale en
 * @type callback
 * @brief The listener for the live room.
 */
@protocol BDLActivityListener <NSObject>

@optional

/**
 * @locale zh
 * @brief 直播间网络状态变化回调。
 * @param activity 由 [joinLiveRoomWithActivity:success:failure:](1185540#BDLLiveEngine-joinliveroomwithactivity-success-failure) 方法传入的直播间信息。详见 [BDLActivity](1185540#BDLActivity)。
 * @param networkStatus 当前网络状态。详见 [BDLNetworkStatus](1185544#BDLNetworkStatus)。
 */
/**
 * @locale en
 * @brief The callback is triggered when the network status of the live room changes.
 * @param activity The live room information, which is passed in through the [joinLiveRoomWithActivity:success:failure:](docs-bdlliveengine#BDLLiveEngine-joinliveroomwithactivity-success-failure) method. For more information, see [BDLActivity](docs-bdlliveengine#BDLActivity).
 * @param networkStatus The current network status. For more information, see [BDLNetworkStatus](viewer-sdk-for-ios-type-definitions#BDLNetworkStatus).
 */
- (void)activity:(BDLActivity *)activity networkStatusDidChange:(BDLNetworkStatus)networkStatus;

/**
 * @locale zh
 * @brief 直播状态变化回调。
 * @param activity 由 [joinLiveRoomWithActivity:success:failure:](1185540#BDLLiveEngine-joinliveroomwithactivity-success-failure) 方法传入的直播间信息。详见 [BDLActivity](1185540#BDLActivity)。
 * @param activityStatus 当前直播状态。详见 [BDLActivityStatus](1185544#BDLActivityStatus)。
 */
/**
 * @locale en
 * @brief The callback is triggered when the live room status changes.
 * @param activity The live room information, which is passed in through the [joinLiveRoomWithActivity:success:failure:](docs-bdlliveengine#BDLLiveEngine-joinliveroomwithactivity-success-failure) method. For more information, see [BDLActivity](docs-bdlliveengine#BDLActivity).
 * @param activityStatus The current live room status. For more information, see [BDLActivityStatus](viewer-sdk-for-ios-type-definitions#BDLActivityStatus).
 */
- (void)activity:(BDLActivity *)activity activityStatusDidChange:(BDLActivityStatus)activityStatus;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
