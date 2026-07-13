//
//  BDLCardConfiguration.h
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
 * @brief 商品卡片配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The product card configuration.
 */
@interface BDLCardConfiguration : BDLRTBaseConfiguration

/**
 * @locale zh
 * @brief 商品名称颜色。
 */
/**
 * @locale en
 * @brief The color of the product name.
 */
@property (nonatomic, strong) UIColor *cardTitleColor;
/**
 * @locale zh
 * @brief 参考价颜色。
 */
/**
 * @locale en
 * @brief The color of the list price.
 */
@property (nonatomic, strong) UIColor *strikeThroughTextColor;
/**
 * @locale zh
 * @brief 售卖价颜色。
 */
/**
 * @locale en
 * @brief The color of the retail price.
 */
@property (nonatomic, strong) UIColor *cardHighLightColor;
/**
 * @locale zh
 * @brief cell 颜色。
 */
/**
 * @locale en
 * @brief The color of the cell.
 */
@property (nonatomic, strong) UIColor *cardCellColor;
/**
 * @locale en
 * @brief Whether to display the strikethrough on the list price. Default value: `NO`. Valid values:
 *        - `YES`: Display.
 *        - `NO`: Do not display.
 */
/**
 * @locale zh
 * @brief 是否显示商品参考价的删除线。默认值：`NO`。取值如下：
 *        - `YES`：显示。
 *        - `NO`：不显示。
 */
@property (nonatomic, assign) BOOL productOriginalPriceShowStrikethrough;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 商品卡片配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The product card configuration.
 */
@interface BDLCardConfiguration (Config)
/**
 * @locale zh
 * @brief 商品名称字体和字号。
 */
/**
 * @locale en
 * @brief The font and font size of the product name.
 */
@property (nonatomic, strong) UIFont *cardTitleFont;
/**
 * @locale zh
 * @brief 参考价字体和字号。
 */
/**
 * @locale en
 * @brief The font and font size of the list price.
 */
@property (nonatomic, strong) UIFont *strikeThroughFont;
/**
 * @locale zh
 * @brief 售卖价字体和字号。
 */
/**
 * @locale en
 * @brief The font and font size of the retail price.
 */
@property (nonatomic, strong) UIFont *cardHighLightFont;
/**
 * @locale zh
 * @brief 是否显示商品卡片序号。默认值：`YES`。<br>
 *        - `YES`：显示。
 *        - `NO`：不显示。
 */
/**
 * @locale en
 * @brief Whether to display the serial number of product cards. Default value: `YES`.
 *        - `YES`: Display.
 *        - `NO`: Do not display.
 */
@property (nonatomic, assign) BOOL itemIndexEnable;
/**
 * @locale zh
 * @brief 是否开启商品直达链接。默认值：`NO`。<br>
 *        - `YES`：如果企业直播服务端返回了直达链接，则优先读取直达链接。如未返回直达链接，则读取跳转链接。
 *        - `NO`：无论企业直播服务端是否返回了直达链接，均读取跳转链接。
 */
/**
 * @locale en
 * @brief Whether the direct URL feature is enabled. Default value: `NO`.
 *        - `YES`: If the BytePlus Live server returns a direct URL, read the direct URL first. If no direct URL is returned, read the product URL.
 *        - `NO`: Regardless of whether the BytePlus Live server returns a direct URL, read the product URL.
 */
@property (nonatomic, assign) BOOL enableDirectUrl;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
