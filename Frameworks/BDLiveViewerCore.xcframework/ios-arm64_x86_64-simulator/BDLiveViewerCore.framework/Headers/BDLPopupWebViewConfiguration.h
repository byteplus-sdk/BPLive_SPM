//
//  BDLPopupWebViewConfiguration.h
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
 * @brief WebView 弹窗配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The configuration of the WebView dialog box.
 */
@interface BDLPopupWebViewConfiguration : BDLRTBaseConfiguration

@end
/**
 * @locale zh
 * @type keytype
 * @brief WebView 弹窗配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The configuration of WebView dialog box.
 */
@interface BDLPopupWebViewConfiguration (Config)

/**
 * @locale zh
 * @brief 内容区域的高度。默认值：460。单位：point。
 */
/**
 * @locale en
 * @brief The height of the content area. Default value: 460. Unit: points.
 */
@property (nonatomic, assign) CGFloat viewHeight;

/**
 * @locale zh
 * @brief 颜色主题。参数值为 `custom` 或 `light` 时，内容区域的颜色为白色，其他情况为黑色（#20202A）。
 */
/**
 * @locale en
 * @brief The color theme. If the parameter value is `custom` or `light`, the color of the content area is white. Otherwise, the color is black (#20202A).
 */
@property (nonatomic, copy, nullable) NSString *colorTheme;

@end


NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
