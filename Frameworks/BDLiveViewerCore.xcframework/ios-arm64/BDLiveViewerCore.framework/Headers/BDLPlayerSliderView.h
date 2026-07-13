//
//  BDLPlayerSliderView.h
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


#import <UIKit/UIKit.h>
#import "BDLPlayerConfiguration.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

@class BDLPlayerSliderView;

/**
 * @locale zh
 * @type callback
 * @brief 播放器进度条 view 的代理方法。
 */
/**
 * @locale en
 * @type callback
 * @brief The delegate methods for the player progress bar view.
 */
@protocol BDLPlayerSliderViewDelegate <NSObject>
/**
 * @locale zh
 * @brief 在观众开始拖动进度条时，SDK 调用该方法。
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers start dragging the progress bar.
 */
- (void)sliderViewBeganDrag;
/**
 * @locale zh
 * @brief 在观众停止拖动进度条时，SDK 调用该方法。
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers stop dragging the progress bar.
 */
- (void)sliderViewEndDrag;
/**
 * @locale zh
 * @brief 在观众点击进度条 view 时，SDK 调用该方法。
 * @param sliderView 播放器进度条 view。详见 [BDLPlayerSliderView](1185540#BDLPlayerSliderView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers tap the progress bar view.
 * @param sliderView The player progress bar view. For more information, see [BDLPlayerSliderView](docs-bdlliveengine#BDLPlayerSliderView).
 */
- (void)sliderViewDidTap:(BDLPlayerSliderView *)sliderView;
/**
 * @locale zh
 * @brief 在进度条进度改变时，SDK 调用该方法。
 * @param progress 当前进度。取值范围：[0,1]。
 * @param sliderView 播放器进度条 view。详见 [BDLPlayerSliderView](1185540#BDLPlayerSliderView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the progress of the progress bar changes.
 * @param sliderView The player progress bar view. For more information, see [BDLPlayerSliderView](docs-bdlliveengine#BDLPlayerSliderView).
 * @param progress The current progress. Value range: [0,1].
 */
- (void)sliderView:(BDLPlayerSliderView *)sliderView progressDidChange:(CGFloat)progress;

@end

/**
 * @locale zh
 * @type api
 * @brief 播放器进度条 view。
 */
/**
 * @locale en
 * @brief The player progress bar view.
 */
@interface BDLPlayerSliderView : UIView

/**
 * @locale zh
 * @brief 当前位置的小圆点。支持自定义除 `frame` 外的所有属性。
 */
/**
 * @locale en
 * @brief The small dot of the current position. All properties except `frame` can be customized.
 */
@property (nonatomic, strong) UIView *thumbView;
/**
 * @locale zh
 * @brief 背景 view。支持自定义除 `frame` 外的所有属性。
 */
/**
 * @locale en
 * @brief The background view. All properties except `frame` can be customized.
 */
@property (nonatomic, strong) UIView *backgroundView;
/**
 * @locale zh
 * @brief 当前进度 view。可通过 [themeColor](1185544#BDLPlayerCommonConfiguration-themecolor) 自定义背景颜色。
 */
/**
 * @locale en
 * @brief The current progress view. You can customize the background color by using [themeColor](viewer-sdk-for-ios-type-definitions#BDLPlayerCommonConfiguration-themecolor).
 */
@property (nonatomic, strong) UIView *trackProgressView;
/**
 * @locale zh
 * @brief 缓存进度 view。
 */
/**
 * @locale en
 * @brief The cache progress view.
 */
@property (nonatomic, strong) UIView *cacheProgressView;

/**
 * @locale zh
 * @brief 代理方法。详见 [BDLPlayerSliderViewDelegate](1185541#BDLPlayerSliderViewDelegate)。
 */
/**
 * @locale en
 * @brief The delegate method. For more information, see [BDLPlayerSliderViewDelegate](viewer-SDK-for-ios-callbacks#BDLPlayerSliderViewDelegate).
 */
@property (nonatomic, weak) id<BDLPlayerSliderViewDelegate> delegate;
/**
 * @locale zh
 * @brief 当前进度。取值范围：[0,1]。
 */
/**
 * @locale en
 * @brief The current progress. Value range: [0,1].
 */
@property (nonatomic, assign, readonly) CGFloat progress;
/**
 * @locale zh
 * @brief 缓存进度。取值范围：[0,1]。
 */
/**
 * @locale en
 * @brief The cache progress. Value range: [0,1].
 */
@property (nonatomic, assign, readonly) CGFloat cacheProgress;
/**
 * @locale zh
 * @brief 是否正在拖动。
 *        - `YES`：正在拖动。
 *        - `NO`：未在拖动。
 */
/**
 * @locale en
 * @brief Whether being dragged.
 *        - `YES`: Being dragged.
 *        - `NO`: Not being dragged.
 */
@property (nonatomic, assign, readonly, getter=isSliding) BOOL sliding;

/**
 * @locale zh
 * @brief 初始化。
 * @param config 配置。详见 [BDLPlayerConfiguration](1185544#BDLPlayerConfiguration)。
 * @list 播放器
 * @return 播放器进度条 view 实例。
 */
/**
 * @locale en
 * @brief Initializes the instance of the player progress bar view.
 * @param config The configuration. For more information, see [BDLPlayerConfiguration](viewer-sdk-for-ios-type-definitions#BDLPlayerConfiguration).
 * @return The instance of the player progress bar view.
 */
- (instancetype)initWithConfig:(BDLPlayerConfiguration *)config;
/**
 * @locale zh
 * @brief 设置当前的播放进度。
 * @param animated 是否需要动画。<br>
 *        - `YES`：需要动画。
 *        - `NO`：不需要动画。
 * @param progress 当前的播放进度。取值范围：[0,1]。
 */
/**
 * @locale en
 * @brief Sets the current playback progress.
 * @param progress The current playback progress. Value range: [0,1].
 * @param animated Whether animation is needed.
 *        - `YES`: Needed.
 *        - `NO`: Not needed.
 */
- (void)setProgress:(CGFloat)progress animated:(BOOL)animated;
/**
 * @locale zh
 * @brief 设置缓存进度。
 * @param animated 是否需要动画。<br>
 *        - `YES`：需要动画。
 *        - `NO`：不需要动画。
 * @param progress 缓存进度。取值范围：[0,1]。
 * @list 播放器
 */
/**
 * @locale en
 * @brief Sets the cache progress.
 * @param progress The cache progress. Value range: [0,1].
 * @param animated Whether animation is needed.
 *        - `YES`: Needed.
 *        - `NO`: Not needed.
 */
- (void)setCacheProgress:(CGFloat)progress animated:(BOOL)animated;

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
