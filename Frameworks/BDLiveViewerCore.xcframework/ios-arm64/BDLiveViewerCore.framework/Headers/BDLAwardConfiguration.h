//
//  BDLAwardConfiguration.h
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
 * @brief 抽奖配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The lucky draw configuration.
 */
@interface BDLAwardConfiguration : BDLRTBaseConfiguration

@end

/**
 * @locale zh
 * @type keytype
 * @brief 抽奖配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The lucky draw configuration.
 */
@interface BDLAwardConfiguration (Config)

/**
 * @locale zh
 * @brief 是否需要完善中奖信息。默认值：`YES`。<br>
 *        - `YES`：需要。
 *        - `NO`：不需要。
 */
/**
 * @locale en
 * @brief Whether personal information is required after winning a prize. Default value: `YES`.
 *        - `YES`: Required.
 *        - `NO`: Not required.
 */
@property (nonatomic, assign) BOOL needAwardContact;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
