//
//  BDLPlayerReplayView.h
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

@class BDLPlayerReplayView;

/**
 * @locale zh
 * @type callback
 * @brief 重播 view 的代理方法。
 */
/**
 * @locale en
 * @type callback
 * @brief The delegate methods for the replay view.
 */
@protocol BDLPlayerReplayViewDelegate <NSObject>
/**
 * @locale zh
 * @brief 在竖屏直播间中，观众点击重播界面时，SDK 调用该方法。
 * @param replayView 重播 view。详见 [BDLPlayerReplayView](1185540#BDLPlayerReplayView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers tap the replay interface in the live room in portrait mode.
 * @param replayView The replay view. For more information, see [BDLPlayerReplayView](docs-bdlliveengine#BDLPlayerReplayView).
 */
- (void)replayViewDidTouch:(BDLPlayerReplayView *)replayView;
/**
 * @locale zh
 * @brief 在横屏直播间中，观众点击重播按钮时，SDK 调用该方法。
 * @param button 重播按钮。
 * @param replayView 重播 view。详见 [BDLPlayerReplayView](1185540#BDLPlayerReplayView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers tap the replay button in the live room in landscape mode.
 * @param replayView The replay view. For more information, see [BDLPlayerReplayView](docs-bdlliveengine#BDLPlayerReplayView).
 * @param button The replay button.
 */
- (void)playerReplayView:(BDLPlayerReplayView *)replayView replayButtonDidTouch:(UIButton *)button;

@end

/**
 * @locale zh
 * @type api
 * @brief 重播 view。
 */
/**
 * @locale en
 * @brief The replay view.
 */
@interface BDLPlayerReplayView : BDLBaseView <BDLLanguageService>
/**
 * @locale zh
 * @brief 代理方法。详见 [BDLPlayerReplayViewDelegate](1185541#BDLPlayerReplayViewDelegate)。
 */
/**
 * @locale en
 * @brief The delegate method. For more information, see [BDLPlayerReplayViewDelegate](viewer-SDK-for-ios-callbacks#BDLPlayerReplayViewDelegate).
 */
@property (nonatomic, weak) id<BDLPlayerReplayViewDelegate> delegate;
/**
 * @locale zh
 * @brief 初始化。
 * @param isPortrait 是否以竖屏直播间初始化。
 *        - `YES`：以竖屏直播间初始化。
 *        - `NO`：以横屏直播间初始化。
 * @param config 配置。详见 [BDLPlayerConfiguration](1185544#BDLPlayerConfiguration)。
 * @list 播放器
 * @return 重播 view 实例。
 */
/**
 * @locale en
 * @brief Initializes the instance of the replay view.
 * @param isPortrait Whether to initialize in portrait mode.
 *        - `YES`: Portrait mode.
 *        - `NO`: Landscape mode.
 * @param config The configuration. For more information, see [BDLPlayerConfiguration](viewer-sdk-for-ios-type-definitions#BDLPlayerConfiguration).
 * @return The instance of the replay view.
 */
- (instancetype)initWithPortrait:(BOOL)isPortrait config:(BDLPlayerConfiguration *)config;
/**
 * @locale zh
 * @brief 根据配置更新 view。
 * @param config 配置。详见 [BDLPlayerConfiguration](1185544#BDLPlayerConfiguration)。
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
