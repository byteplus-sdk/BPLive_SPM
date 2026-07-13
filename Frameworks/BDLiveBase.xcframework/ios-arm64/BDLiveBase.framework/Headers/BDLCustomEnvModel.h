//
//  BDLCustomEnvModel.h
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

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 自定义环境模型。
 */
/**
 * @locale en
 * @type api
 * @brief Custom environment model.
 */
@interface BDLCustomEnvModel : NSObject

/**
 * @locale zh
 * @brief 直播客户端 URL。
 */
/**
 * @locale en
 * @brief Live client URL.
 */
@property (nonatomic, copy) NSString *liveClientURL;

/**
 * @locale zh
 * @brief Top 网关 URL。
 */
/**
 * @locale en
 * @brief Top gateway URL.
 */
@property (nonatomic, copy) NSString *topGatewayURL;

/**
 * @locale zh
 * @brief RTC App ID。
 */
/**
 * @locale en
 * @brief RTC App ID.
 */
@property (nonatomic, copy) NSString *rtcAppId;

/**
 * @locale zh
 * @brief RTC get access URL。
 */
/**
 * @locale en
 * @brief RTC get access URL.
 */
@property (nonatomic, copy) NSString *rtcGetAccessURL;

/**
 * @locale zh
 * @brief RTC web log URL。
 */
/**
 * @locale en
 * @brief RTC web log URL.
 */
@property (nonatomic, copy) NSString *rtcWebLogURL;

/**
 * @locale zh
 * @brief Frontier URL。
 */
/**
 * @locale en
 * @brief Frontier URL.
 */
@property (nonatomic, copy) NSString *frontierURL;

/**
 * @locale zh
 * @return 是否有效。取值如下：
 *        - `YES`：有效。
 *        - `NO`：无效。
 */
/**
 * @locale en
 * @return Whether it is valid.
 *        - `YES`: Valid.
 *        - `NO`: Invalid.
 */
- (BOOL)isValid;

@end

NS_ASSUME_NONNULL_END
