//
//  BDLPopupWebView.h
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

#import <BDLiveCommon/BDLPopupBaseView.h>
#import "BDLPopupWebViewConfiguration.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief WebView 弹窗。
 */
/**
 * @locale en
 * @brief The WebView dialog box.
 */
@interface BDLPopupWebView : BDLPopupBottomShowBaseView

/**
 * @locale zh
 * @brief WebView 弹窗配置。详见 [BDLPopupWebViewConfiguration](1185544#BDLPopupWebViewConfiguration(Config))。
 */
/**
 * @locale en
 * @brief The WebView dialog box configuration. For more information, see [BDLPopupWebViewConfiguration](viewer-sdk-for-ios-type-definitions#BDLPopupWebViewConfiguration(Config)).
 */
@property (nonatomic, strong, readonly) BDLPopupWebViewConfiguration *config;
/**
 * @locale zh
 * @brief 显示内容的 WebView。
 */
/**
 * @locale en
 * @brief The WebView that displays the content.
 */
@property (nonatomic, strong, readonly, nullable) WKWebView *webView;
/**
 * @locale zh
 * @brief 初始化。
 * @param redirectUrl 需要加载的 URL。
 * @return WebView 弹窗实例。
 */
/**
 * @locale en
 * @brief Initializes the instance of the WebView dialog box.
 * @param redirectUrl The URL to load.
 * @return The instance of the WebView dialog box.
 */
- (instancetype)initWithRedirectUrl:(NSString *)redirectUrl;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
