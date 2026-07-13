//
//  BDLPlayerMaskView.h
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
#import "BDLBasicService.h"
#import "BDLPlayerConfiguration.h"
#import <BDLiveCommon/BDLLanguageService.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

@class BDLPlayerMaskView;

/**
 * @locale zh
 * @type api
 * @brief 遮罩 view，包含直播状态（预告或结束）、水印、人气 view 等。
 */
/**
 * @locale en
 * @brief The mask view, including the live room status (Preview or Over), watermark, and popularity view.
 */
@interface BDLPlayerMaskView : BDLBaseView <BDLBasicService, BDLLanguageService>

/**
 * @locale zh
 * @brief 初始化。
 * @param isPortrait 是否以竖屏直播间初始化。<br>
 *        - `YES`：以竖屏直播间初始化。
 *        - `NO`：以横屏模式初始化。
 * @param config 配置。详见 [BDLPlayerConfiguration](1185544#BDLPlayerConfiguration)。
 * @list 播放器
 * @return 遮罩 view 实例。
 */
/**
 * @locale en
 * @brief Initializes the instance of the mask view.
 * @param isPortrait Whether to initialize in portrait mode.
 *        - `YES`: Portrait mode.
 *        - `NO`: Landscape mode.
 * @param config The configuration. For more information, see [BDLPlayerConfiguration](viewer-sdk-for-ios-type-definitions#BDLPlayerConfiguration).
 * @return The instance of the mask view.
 */
- (instancetype)initWithPortrait:(BOOL)isPortrait config:(BDLPlayerConfiguration *)config;
/**
 * @locale zh
 * @brief 预告或直播已结束 toast 的 label。不支持自定义 `text`、`hidden`。可通过 [toastFont](1185544#BDLPlayerCommonConfiguration-toastfont) 自定义字体和字号。
 */
/**
 * @locale en
 * @brief The label of the toast indicating the preview or live stream has ended. All properties except `text` and `hidden` can be customized. You can customize the font and font size by using [toastFont](viewer-sdk-for-ios-type-definitions#BDLPlayerCommonConfiguration-toastfont).
 */
@property (nonatomic, strong) UILabel *promptLabel;
/**
 * @locale zh
 * @brief 预告或直播已结束 toast 的容器 view。不支持自定义 `hidden`。可通过 [toastCornerRadius](1185544#BDLPlayerCommonConfiguration-toastcornerradius) 自定义圆角。
 */
/**
 * @locale en
 * @brief The container view of the toast indicating the preview or live stream has ended. All properties except `hidden` can be customized. You can customize the rounded corner by using [toastCornerRadius](viewer-sdk-for-ios-type-definitions#BDLPlayerCommonConfiguration-toastcornerradius).
 */
@property (nonatomic, strong) UIView *promptContainerView;
/**
 * @locale zh
 * @brief 水印的 imageView。仅在横屏直播间中显示。不支持自定义 `image`。
 */
/**
 * @locale en
 * @brief The watermark's imageView, which is displayed only in the live room in landscape mode. All properties except `image` can be customized.
 */
@property (nonatomic, strong, nullable) UIImageView *watermarkImageView;
/**
 * @locale zh
 * @brief 预告或结束状态的 label。不支持自定义 `hidden`、`text`。
 */
/**
 * @locale en
 * @brief The label of the Preview or Over status. All properties except `text` and `hidden` can be customized.
 */
@property (nonatomic, strong, nullable) UILabel *tagLabel;
/**
 * @locale zh
 * @brief 开始浮窗（InApp 画中画）播放。SDK 内部会有一些逻辑来控制浮窗播放时部分控件的显示和隐藏。
 * @list 播放器
 * @return - `YES`：开始浮窗播放成功。
 *         - `NO`：开始浮窗播放失败。
 */
/**
 * @locale en
 * @brief Starts playing in the floating player (in-app PiP). The SDK contains internal logic to control the visibility of certain controls while playing in the floating player.
 * @return Whether the video has started playing in the floating player successfully.<br>
 *         - `YES`: Successful.
 *         - `NO`: Failed.
 */
- (BOOL)startFloating;
/**
 * @locale zh
 * @brief 停止浮窗（InApp 画中画）播放。
 * @list 播放器
 */
/**
 * @locale en
 * @brief Stops playing in the floating player (in-app PiP).
 */
- (void)stopFloating;
/**
 * @locale zh
 * @brief 根据配置更新 view。
 * @param config 配置。详见 [BDLPlayerConfiguration](1185544#BDLPlayerConfiguration)。
 * @list 播放器
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
