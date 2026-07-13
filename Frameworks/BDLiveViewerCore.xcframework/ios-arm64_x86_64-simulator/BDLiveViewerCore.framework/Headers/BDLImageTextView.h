//
//  BDLImageTextView.h
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

#import <BDLiveCommon/BDLBaseView.h>
#import "BDLImageTextViewConfiguration.h"
#import "BDLBasicService.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

@class BDLRichTextWebView;

/**
 * @locale zh
 * @type api
 * @brief 图文介绍菜单 view。
 */
/**
 * @locale en
 * @brief The graphics menu view.
 */
@interface BDLImageTextView : BDLBaseView

/**
 * @locale zh
 * @brief 图文介绍菜单配置。详见 [BDLImageTextViewConfiguration](1185544#BDLImageTextViewConfiguration)。
 */
/**
 * @locale en
 * @brief The configuration of the graphics menu. For more information, see [BDLImageTextViewConfiguration](viewer-sdk-for-ios-type-definitions#BDLImageTextViewConfiguration).
 */
@property (nonatomic, strong, readonly) BDLImageTextViewConfiguration *config;
/**
 * @locale zh
 * @brief 显示图文的 WebView。详见 [BDLRichTextWebView](1185544#BDLRichTextWebView)。可自定义除 `frame` 外的所有属性。
 */
/**
 * @locale en
 * @brief The WebView that displays text and images. For more information, see [BDLRichTextWebView](viewer-sdk-for-ios-type-definitions#BDLRichTextWebView). All properties except `frame` can be customized.
 */
@property (nonatomic, strong) BDLRichTextWebView *webView;
/**
 * @locale zh
 * @brief 通过富文本进行更新。
 * @param richText HTML5 代码。
 * @param defaultColor 默认颜色。<br>如果 [imageTextTextColor](1185544#BDLImageTextViewConfiguration(Config)-imagetexttextcolor) 为空，则使用该颜色。如果该颜色也为空，则使用 `richText` 的颜色。
 * @list 图文菜单
 */
/**
 * @locale en
 * @brief Updates based on rich text.
 * @param richText HTML5 code.
 * @param defaultColor The default color.<br>
 *        If [imageTextTextColor](viewer-sdk-for-ios-type-definitions#BDLImageTextViewConfiguration(Config)-imagetexttextcolor) is `nil`, this color is used. If this color is also `nil`, the color of `richText` is used.
 */
- (void)updateWithImageText:(NSString *)richText defaultColor:(nullable UIColor *)defaultColor;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
