//
//  BDLPageAdViewConfiguration.h
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


#import "BDLRTBaseConfiguration.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type keytype
 * @brief 页中广告配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The in-page ad configuration.
 */
@interface BDLPageAdViewConfiguration : BDLRTBaseConfiguration

@end

/**
 * @locale zh
 * @type keytype
 * @brief 页中广告配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The in-page ad configuration.
 */
@interface BDLPageAdViewConfiguration (Config)

/**
 * @locale zh
 * @brief 设置页中广告的轮播时间间隔，即每隔多长时间向右滚动一次。单位：秒。默认值：3。取值需大于 0。
 */
/**
 * @locale en
 * @brief The carousel interval for in-page ads, namely how frequently the ad scrolls to the right. Unit: seconds. Default value: 3. The value must be greater than 0.
 */
@property (nonatomic, assign) NSTimeInterval scrollTimeInterval;

/**
 * @locale zh
 * @brief 圆角半径。默认值：4.0。
 */
/**
 * @locale en
 * @brief The corner radius. Default value: 4.0.
 */
@property (nonatomic, assign) CGFloat cornerRadius;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
