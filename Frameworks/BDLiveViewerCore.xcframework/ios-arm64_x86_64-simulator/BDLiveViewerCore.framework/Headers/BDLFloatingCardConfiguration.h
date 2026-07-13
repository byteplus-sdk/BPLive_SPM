//
//  BDLFloatingCardConfiguration.h
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
 * @brief 浮窗商品卡片配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The configuration of the floating product card.
 */
@interface BDLFloatingCardConfiguration : BDLRTBaseConfiguration

@end

/**
 * @locale zh
 * @type keytype
 * @brief 浮窗商品卡片配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The floating product card configuration.
 */
@interface BDLFloatingCardConfiguration (Config)

/**
 * @locale zh
 * @brief 是否开启商品直达链接。默认值：`NO`。<br>
 *        - `YES`：如果企业直播服务端返回了直达链接，则优先读取直达链接。如未返回直达链接，则读取跳转链接。
 *        - `NO`：无论企业直播服务端是否返回了直达链接，均读取跳转链接。
 */
/**
 * @locale en
 * @brief Whether the direct URL feature is enabled. Default value: `NO`.
 *        - `YES`: If the BytePlus Live server returns a direct URL, read the direct URL first. If no direct URL is returned, read the product URL.
 *        - `NO`: Regardless of whether the BytePlus Live server returns a direct URL, read the product URL.
 */
@property (nonatomic, assign) BOOL enableDirectUrl;


/**
 * @locale zh
 * @brief 是否禁止显示浮窗商品卡片。默认值：`NO`。<br>
 *        - `YES`：禁止显示浮窗商品卡片。
 *        - `NO`：允许显示浮窗商品卡片。
 */
/**
 * @locale en
 * @brief Whether to disable the display of the floating product card. Default value: `NO`.
 *        - `YES`: Disable the display of the floating product card.
 *        - `NO`: Allow the display of the floating product card.
 */
@property (nonatomic, assign) BOOL disableShowFloatingCard;



/**
 * @locale zh
 * @brief 售卖价。不支持多语言。
 */
/**
 * @locale en
 * @brief The retail price.
 */
@property (nonatomic, copy, nullable) NSString *highLightString;

/**
 * @locale zh
 * @brief 浮窗商品卡片背景的圆角。单位：point。默认值：`5`。
 */
/**
 * @locale en
 * @brief The background rounded corners of the floating product card. Unit: points. Default value: `5`.
 */
@property (nonatomic, assign) CGFloat cornerRadius;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
