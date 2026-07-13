//
//  BDLImageTextViewConfiguration.h
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
 * @brief 图文介绍菜单配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The configuration of the menu for graphics.
 */
@interface BDLImageTextViewConfiguration : BDLRTBaseConfiguration

@end

/**
 * @locale zh
 * @type keytype
 * @brief 图文介绍菜单配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The configuration of the menu for graphics.
 */
@interface BDLImageTextViewConfiguration (Config)

/**
 * @locale zh
 * @brief 显示图文的 WebView 相对于父控件 [BDLImageTextView](1185540#BDLImageTextView) 的间距。
 */
/**
 * @locale en
 * @brief The margin of the WebView displaying the text and images relative to its parent control [BDLImageTextView](docs-bdlliveengine#BDLImageTextView).
 */
@property (nonatomic, assign) CGFloat viewMargin;
/**
 * @locale zh
 * @brief 图文介绍菜单下的文字颜色。为空则使用服务端返回的文字颜色。
 */
/**
 * @locale en
 * @brief The text color under the menu for graphics. If `nil`, the text color returned by the BytePlus Live server is used.
 */
@property (nonatomic, strong) UIColor *imageTextTextColor;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
