//
//  BDLRichTextWebView.h
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

#import <WebKit/WebKit.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type keytype
 * @brief 显示富文本的 WebView。
 */
/**
 * @locale en
 * @type keytype
 * @brief The WebView to display the rich text.
 */
@interface BDLRichTextWebView : WKWebView

/**
 * @locale zh
 * @brief 是否调用了 [webView:didFinishNavigation:](https://developer.apple.com/documentation/webkit/wknavigationdelegate/1455629-webview?language=objc)。<br>
 *        - YES：调用了。
 *        - NO：未调用。
 */
/**
 * @locale en
 * @brief Whether [webView:didFinishNavigation:](https://developer.apple.com/documentation/webkit/wknavigationdelegate/1455629-webview?language=objc) is called.
 *        - `YES`: Called.
 *        - `NO`: Not called.
 */
@property (nonatomic, assign) BOOL finishedNavigation;

/**
 * @locale zh
 * @brief 更新内容。
 * @param richText 需要显示的富文本。
 * @param color 内容颜色。<br>为空则使用 `richText` 的颜色。
 */
/**
 * @locale en
 * @brief Updates the content.
 * @param richText The rich text that needs to be displayed.
 * @param color The content color.<br>
 *        If `nil`, the color of `richText` is used.
 */
- (void)updateWithRichText:(NSString *)richText color:(nullable UIColor *)color;
/**
 * @locale zh
 * @brief 更新内容。
 * @param richText 需要显示的富文本。
 * @param colorStr 内容颜色的 RGB 值。<br>为空则使用 `richText` 的颜色。
 */
/**
 * @locale en
 * @brief Updates the content.
 * @param richText The rich text that needs to be displayed.
 * @param colorStr The RGB value of the content color.<br>
 *        If `nil`, the color of `richText` is used.
 */
- (void)updateWithRichText:(NSString *)richText colorStr:(nullable NSString *)colorStr;
/**
 * @locale zh
 * @brief 更新内容。
 * @param title 标题，SDK 内部会和 `content` 拼接在一起显示。
 * @param content 需要显示的内容。
 * @param colorStr 内容颜色的 RGB 值。<br>为空则使用 `content` 的颜色。
 */
/**
 * @locale en
 * @brief Updates the content.
 * @param title The title, which is concatenated with `content` and displayed within the SDK.
 * @param content The content that needs to be displayed.
 * @param colorStr The RGB value of the content color.<br>
 *        If `nil`, the color of `content` is used.
 */
- (void)updateWithTitle:(NSString *)title richText:(NSString *)content colorStr:(nullable NSString *)colorStr;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
