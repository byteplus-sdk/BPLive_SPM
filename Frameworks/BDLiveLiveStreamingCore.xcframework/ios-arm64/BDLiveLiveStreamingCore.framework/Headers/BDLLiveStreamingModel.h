//
//  BDLLiveStreamingModel.h
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

#import <Foundation/Foundation.h>
#import "BDLEffectConfig.h"
#import "BDLLiveStreamingUIConfig.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 进入直播间所需参数
 * @hidden (iOS)
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@interface BDLLiveStreamingModel : NSObject

 /**
  * @locale zh
  * @brief 活动ID
  * @hidden (iOS)
  */
@property (nonatomic, strong) NSNumber *activityId;
 /**
  * @locale zh
  * @brief 直播秘钥
  * @hidden (iOS)
  */
@property (nonatomic, copy) NSString *secretKey;

// MARK: - 美颜

 /**
  * @locale zh
  * @brief 美颜配置， 为空则不包含美颜
  * @hidden (iOS)
  */
@property (nonatomic, strong, nullable) BDLEffectConfig *effectConfig;

// MARK: - UI

/**
 * @locale zh
 * @hidden (iOS)
 */
@property (nonatomic, strong, nullable) BDLLiveStreamingUIConfig *uiConfig;

// MARK: - 录屏直播需要的信息
 /**
  * @locale zh
  * @brief 应用配置的groupId
  * @hidden (iOS)
  */
@property (nonatomic, copy, nullable) NSString *groupId API_AVAILABLE(ios(12.0));
 /**
  * @locale zh
  * @brief upload extension的bundleId
  * @hidden (iOS)
  */
@property (nonatomic, copy, nullable) NSString *extensionBundleId API_AVAILABLE(ios(12.0));

@end

NS_ASSUME_NONNULL_END
