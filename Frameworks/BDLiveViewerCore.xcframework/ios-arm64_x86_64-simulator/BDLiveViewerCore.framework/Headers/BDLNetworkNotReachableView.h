//
//  BDLNetworkNotReachableView.h
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
#import <BDLiveCommon/BDLLanguageService.h>
#import "BDLPlayerConfiguration.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

@class BDLNetworkNotReachableView;

/**
 * @locale zh
 * @type callback
 * @brief 断网提示 view 的代理方法。
 */
/**
 * @locale en
 * @type callback
 * @brief The delegate methods for the network disconnection prompt view.
 */
@protocol BDLNetworkNotReachableViewDelegate <NSObject>

/**
 * @locale zh
 * @brief 在观众点击重试按钮时，SDK 调用该方法。
 * @param notReachableview 断网提示 view。详见 [BDLNetworkNotReachableView](1185540#BDLNetworkNotReachableView)。
 * @param button 重试按钮。
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers tap the retry button.
 * @param notReachableview The network disconnection prompt view. For more information, see [BDLNetworkNotReachableView](docs-bdlliveengine#BDLNetworkNotReachableView).
 * @param button The retry button.
 */
- (void)networkNotReachableView:(BDLNetworkNotReachableView *)notReachableview retryButtonDidTouch:(UIButton *)button;

@end

/**
 * @locale zh
 * @type api
 * @brief 断网提示 view。
 */
/**
 * @locale en
 * @brief The network disconnection prompt view.
 */
@interface BDLNetworkNotReachableView : BDLBaseView <BDLLanguageService>

/**
 * @locale zh
 * @brief 代理方法。详见 [BDLNetworkNotReachableViewDelegate](1185541#BDLNetworkNotReachableViewDelegate)。
 */
/**
 * @locale en
 * @brief The delegate method. For more information, see [BDLNetworkNotReachableViewDelegate](viewer-SDK-for-ios-callbacks#BDLNetworkNotReachableViewDelegate).
 */
@property (nonatomic, weak) id<BDLNetworkNotReachableViewDelegate> delegate;
/**
 * @locale zh
 * @brief 提示 label。可通过 [networkNotReachableText](1185544#BDLPlayerCommonConfiguration-networknotreachabletext) 和 [promptTextColor](1185544#BDLPlayerCommonConfiguration-prompttextcolor) 自定义提示文案和提示文案文字颜色。
 */
/**
 * @locale en
 * @brief The prompt label. You can customize the text and text color of the prompt by using [networkNotReachableText](viewer-sdk-for-ios-type-definitions#BDLPlayerCommonConfiguration-networknotreachabletext) and [promptTextColor](viewer-sdk-for-ios-type-definitions#BDLPlayerCommonConfiguration-prompttextcolor).
 */
@property (nonatomic, strong) UILabel *promptLabel;
/**
 * @locale zh
 * @brief 重试按钮。可通过 `config.landscape` 或 `config.portrait` 的 [retryButtonBackgroundColor](1185544#BDLPlayerBaseConfiguration-retrybuttonbackgroundcolor)、[retryButtonTitle](1185544#BDLPlayerBaseConfiguration-retrybuttontitle)、[retryButtonCornerRadius](1185544#BDLPlayerBaseConfiguration-retrybuttoncornerradius) 自定义横竖屏直播间的背景颜色、文字、圆角。
 */
/**
 * @locale en
 * @brief The retry button. You can customize the background color, text, and rounded corners for live rooms in landscape or portrait mode by using [retryButtonBackgroundColor](viewer-sdk-for-ios-type-definitions#BDLPlayerBaseConfiguration-retrybuttonbackgroundcolor), [retryButtonTitle](viewer-sdk-for-ios-type-definitions#BDLPlayerBaseConfiguration-retrybuttontitle), and [retryButtonCornerRadius](viewer-sdk-for-ios-type-definitions#BDLPlayerBaseConfiguration-retrybuttoncornerradius) of `config.landscape` or `config.portrait`.
 */
@property (nonatomic, strong) UIButton *retryButton;

/**
 * @locale zh
 * @brief 初始化。
 * @param isPortrait 是否以竖屏直播间初始化。<br>
 *        - `YES`：以竖屏直播间初始化。
 *        - `NO`：以横屏直播间初始化。
 * @param config 配置。详见 [BDLPlayerConfiguration](1185544#BDLPlayerConfiguration)。
 * @return 断网提示 view 实例。
 */
/**
 * @locale en
 * @brief Initializes the instance of the network disconnection prompt view.
 * @param isPortrait Whether to initialize in portrait mode.
 *        - `YES`: Portrait mode.
 *        - `NO`: Landscape mode.
 * @param config The configuration. For more information, see [BDLPlayerConfiguration](viewer-sdk-for-ios-type-definitions#BDLPlayerConfiguration).
 * @return The instance of the network disconnection prompt view.
 */
- (instancetype)initWithPortrait:(BOOL)isPortrait config:(BDLPlayerConfiguration *)config;
/**
 * @locale zh
 * @brief 根据配置更新 view。
 * @param config 配置。详见 [BDLPlayerConfiguration](1185544#BDLPlayerConfiguration)。
 */
/**
 * @locale en
 * @brief Updates the view based on the configuration.
 * @param config The configuration. For more information, see [BDLPlayerConfiguration](viewer-sdk-for-ios-type-definitions#BDLPlayerConfiguration).
 */
- (void)updateWithConfig:(BDLPlayerConfiguration *)config;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
