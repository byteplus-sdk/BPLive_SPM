//
//  BDLPlayerControlView.h
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
#import <BDLiveCommon/BDLDefines.h>
#import "BDLBasicService.h"
#import <BDLiveCommon/BDLLanguageService.h>
#import "BDLPlayerSliderView.h"
#import "BDLPlayerSpeedView.h"
#import "BDLMultiLanguageView.h"
#import "BDLPlayerResolutionView.h"
#import "BDLPlayerConfiguration.h"
#import "BDLPullStreamUrlService.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

@class BDLPlayerControlView;

/**
 * @locale zh
 * @type callback
 * @brief 播放器控制 view 的代理方法。
 */
/**
 * @locale en
 * @type callback
 * @brief The delegate methods for the player control view.
 */
@protocol BDLPlayerControlViewDelegate <NSObject>

/**
 * @locale zh
 * @brief 在观众点击播放按钮时，SDK 调用该方法。
 * @param isSelected 播放按钮是否为选中状态。<br>
 *        - `YES`：选中状态，即播放。
 *        - `NO`：未选中状态，即暂停。
 * @param controlView 播放器控制 view。详见 [BDLPlayerControlView](1185540#BDLPlayerControlView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers tap the play button.
 * @param controlView The player control view. For more information, see [BDLPlayerControlView](docs-bdlliveengine#BDLPlayerControlView).
 * @param isSelected Whether the play button is selected.
 *        - `YES`: Selected, meaning the video is playing.
 *        - `NO`: Not selected, meaning the video is paused.
 */
- (void)controlView:(BDLPlayerControlView *)controlView playButtonDidTouch:(BOOL)isSelected;
/**
 * @locale zh
 * @brief 在观众开始拖动进度条时，SDK 调用该方法。
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers start dragging the progress bar.
 */
- (void)controlViewSliderBeganDrag;
/**
 * @locale zh
 * @brief 在观众停止拖动进度条时，SDK 调用该方法。
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers stop dragging the progress bar.
 */
- (void)controlViewSliderEndDrag;
/**
 * @locale zh
 * @brief 在观众点击进度条时，SDK 调用该方法。
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers tap the progress bar.
 */
- (void)controlViewSliderViewDidTap;
/**
 * @locale zh
 * @brief 在播放进度改变时，SDK 调用该方法。
 * @param progress 当前播放进度。取值范围：[0,1]。
 * @param controlView 播放器控制 view。详见 [BDLPlayerControlView](1185540#BDLPlayerControlView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the playback progress changes.
 * @param controlView The player control view. For more information, see [BDLPlayerControlView](docs-bdlliveengine#BDLPlayerControlView).
 * @param progress The current playback progress. Value range: [0,1].
 */
- (void)controlView:(BDLPlayerControlView *)controlView progressDidChange:(CGFloat)progress;

@optional

/**
 * @locale zh
 * @brief 在观众点击礼物按钮时，SDK 调用该方法。
 * @param controlView 播放器控制 view。详见 [BDLPlayerControlView](1185540#BDLPlayerControlView)。
 * @hidden (iOS)
 */
/**
 * @locale en
 * @param controlView Player control view. For more details, see [BDLPlayerControlView](docs-bdlliveengine#BDLPlayerControlView).
 * @hidden (iOS)
 */
- (void)controlViewGiftButtonDidTouch:(BDLPlayerControlView *)controlView;
/**
 * @locale zh
 * @brief 在直播期间观众点击刷新按钮时，SDK 调用该方法。
 * @param controlView 播放器控制 view。详见 [BDLPlayerControlView](1185540#BDLPlayerControlView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers tap the refresh button during the live stream.
 * @param controlView The player control view. For more information, see [BDLPlayerControlView](docs-bdlliveengine#BDLPlayerControlView).
 */
- (void)controlViewRefreshButtonDidTouch:(BDLPlayerControlView *)controlView;
/**
 * @locale zh
 * @brief 在观众点击清晰度按钮时，SDK 调用该方法。
 * @param controlView 播放器控制 view。详见 [BDLPlayerControlView](1185540#BDLPlayerControlView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers tap the resolution button.
 * @param controlView The player control view. For more information, see [BDLPlayerControlView](docs-bdlliveengine#BDLPlayerControlView).
 */
- (void)controlViewResolutionButtonDidTouch:(BDLPlayerControlView *)controlView;
/**
 * @locale zh
 * @brief 在观众点击倍速按钮时，SDK 调用该方法。
 * @param controlView 播放器控制 view。详见 [BDLPlayerControlView](1185540#BDLPlayerControlView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers tap the playback speed button.
 * @param controlView The player control view. For more information, see [BDLPlayerControlView](docs-bdlliveengine#BDLPlayerControlView).
 */
- (void)controlViewSpeedButtonDidTouch:(BDLPlayerControlView *)controlView;
/**
 * @locale zh
 * @brief 在观众点击进入或退出全屏按钮时，SDK 调用该方法。
 * @param isSelected 观众是否点击了进入全屏按钮。<br>
 *        - `YES`：点击了进入全屏按钮。
 *        - `NO`：点击了退出全屏按钮。
 * @param controlView 播放器控制 view。详见 [BDLPlayerControlView](1185540#BDLPlayerControlView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers tap the button to enter or exit full-screen mode.
 * @param controlView The player control view. For more information, see [BDLPlayerControlView](docs-bdlliveengine#BDLPlayerControlView).
 * @param isSelected Whether viewers tap the button to enter full-screen mode.
 *        - `YES`: Tap the button to enter full-screen mode.
 *        - `NO`: Tap the button to exit full-screen mode.
 */
- (void)controlView:(BDLPlayerControlView *)controlView fullScreenButtonDidTouch:(BOOL)isSelected;
/**
 * @locale zh
 * @brief 在清晰度改变时，SDK 调用该方法。
 * @param resolution 当前使用的清晰度。详见 [BDLVideoResolution](1185544#BDLVideoResolution)。
 * @param controlView 播放器控制 view。详见 [BDLPlayerControlView](1185540#BDLPlayerControlView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the resolution changes.
 * @param controlView The player control view. For more information, see [BDLPlayerControlView](docs-bdlliveengine#BDLPlayerControlView).
 * @param resolution The currently used resolution. For more information, see [BDLVideoResolution](viewer-sdk-for-ios-type-definitions#BDLVideoResolution).
 */
- (void)controlView:(BDLPlayerControlView *)controlView resolutionDidChange:(BDLVideoResolution)resolution;

@end

/**
 * @locale zh
 * @brief 播放器控制 view，包含播放按钮、暂停按钮、进度条、刷新按钮、全屏按钮、时间文本等。
 */
/**
 * @locale en
 * @brief The player control view, including the play button, pause button, progress bar, refresh button, full-screen button, and time text.
 */
@interface BDLPlayerControlView : BDLBaseView <BDLBasicService, BDLLanguageService, BDLPullStreamUrlService>

/**
 * @locale zh
 * @brief 代理方法。详见 [BDLPlayerControlViewDelegate](1185541#BDLPlayerControlViewDelegate)。
 */
/**
 * @locale en
 * @brief The delegate method. For more information, see [BDLPlayerControlViewDelegate](viewer-SDK-for-ios-callbacks#BDLPlayerControlViewDelegate).
 */
@property (nonatomic, weak) id<BDLPlayerControlViewDelegate> delegate;
/**
 * @locale zh
 * @brief 功能元素（播放按钮、暂停按钮、进度条、刷新按钮、全屏按钮、时间文本等）的父控件。
 */
/**
 * @locale en
 * @brief The parent control of feature elements such as play button, pause button, progress bar, refresh button, full-screen button, and time text.
 */
@property (nonatomic, strong) UIView *controlBarView;
/**
 * @locale zh
 * @brief 播放或暂停按钮。
 *        - `selected` 为 `YES` 表示当前正在播放，显示暂停按钮。
 *        - `selected` 为 `NO` 表示当前不在播放，显示播放按钮。
 */
/**
 * @locale en
 * @brief The play or pause button.<br>
 *        - `selected` being `YES` indicates the video is playing, with the pause button displayed.
 *        - `selected` being `NO` indicates the video is not playing, with the play button displayed.
 */
@property (nonatomic, strong) UIButton *playButton;
/**
 * @locale zh
 * @brief 播放器中间的播放按钮。仅在暂停时显示。
 */
/**
 * @locale en
 * @brief The play button in the middle of the player, which is displayed only when the video is paused.
 */
@property (nonatomic, strong, readonly) UIButton *centerPlayButton;
/**
 * @locale zh
 * @brief 刷新按钮。仅在直播时显示。
 */
/**
 * @locale en
 * @brief The refresh button, which is displayed only during a live stream.
 */
@property (nonatomic, strong, readonly) UIButton *refreshButton;
/**
 * @locale zh
 * @brief 全屏按钮。仅在横屏直播间中以及竖屏直播间的横屏视频中显示。可通过 [fullScreenButtonNormalImage](1185544#BDLPlayerCommonConfiguration-fullscreenbuttonnormalimage) 和 [fullScreenButtonSelectedImage](1185544#BDLPlayerCommonConfiguration-fullscreenbuttonselectedimage) 自定义图片。
 */
/**
 * @locale en
 * @brief The full-screen button, which is displayed only in the live room in landscape mode and when the width of the video is greater than the height in the live room in portrait mode. You can customize the image by using [fullScreenButtonNormalImage](viewer-sdk-for-ios-type-definitions#BDLPlayerCommonConfiguration-fullscreenbuttonnormalimage) and [fullScreenButtonSelectedImage](viewer-sdk-for-ios-type-definitions#BDLPlayerCommonConfiguration-fullscreenbuttonselectedimage).
 */
@property (nonatomic, strong, readonly) UIButton *fullScreenButton;
/**
 * @locale zh
 * @brief 退出全屏按钮。仅在横屏直播间中以及竖屏直播间的横屏视频中显示。可通过 [exitFullScreenButtonNormalImage](1185544#BDLPlayerCommonConfiguration-exitfullscreenbuttonnormalimage) 自定义图片。
 */
/**
 * @locale en
 * @brief The exit ful- screen button, which is displayed only in the live room in landscape mode and when the width of the video is greater than the height in the live room in portrait mode. You can customize the image by using [exitFullScreenButtonNormalImage](viewer-sdk-for-ios-type-definitions#BDLPlayerCommonConfiguration-exitfullscreenbuttonnormalimage).
 */
@property (nonatomic, strong, readonly) UIButton *backButton;
/**
 * @locale zh
 * @brief 是否需要全屏按钮。默认值：`YES`。<br>
 *        - `YES`：需要全屏按钮。
 *        - `NO`：不需要全屏按钮。
 */
/**
 * @locale en
 * @brief Whether the full-screen button is needed. Default value: `YES`.
 *        - `YES`: Needed.
 *        - `NO`: Not needed.
 */
@property (nonatomic, assign) BOOL needFullScreenButton;
/**
 * @locale zh
 * @brief 当前播放时间 label。仅在点播时显示。可通过 [currentTimeColor](1185544#BDLPlayerCommonConfiguration-currenttimecolor) 自定义颜色。
 */
/**
 * @locale en
 * @brief The current playback time label, which is displayed only when the VOD video is playing. You can customize the color by using [currentTimeColor](viewer-sdk-for-ios-type-definitions#BDLPlayerCommonConfiguration-currenttimecolor).
 */
@property (nonatomic, strong) UILabel *currentTimeLabel;
/**
 * @locale zh
 * @brief 总时长 label。仅在点播时显示。可通过 [totalTimeColor](1185544#BDLPlayerCommonConfiguration-totaltimecolor) 自定义颜色。
 */
/**
 * @locale en
 * @brief The total duration label, which is displayed only when the VOD video is playing. You can customize the color by using [totalTimeColor](viewer-sdk-for-ios-type-definitions#BDLPlayerCommonConfiguration-totaltimecolor).
 */
@property (nonatomic, strong) UILabel *durationLabel;
/**
 * @locale zh
 * @brief 总时长。直播时为 `0`。单位：秒。
 */
/**
 * @locale en
 * @brief The total duration. Unit: seconds. The value is `0` during a live stream.
 */
@property (nonatomic, assign) NSTimeInterval duration;
/**
 * @locale zh
 * @brief 当前时长。直播时为 0。单位：秒。
 */
/**
 * @locale en
 * @brief The current duration. Unit: seconds. The value is `0` during a live stream.
 */
@property (nonatomic, assign) NSTimeInterval currentTime;
/**
 * @locale zh
 * @brief 进度条 view。仅在点播时显示。详见 [BDLPlayerSliderView](#BDLPlayerSliderView)。
 */
/**
 * @locale en
 * @brief The progress bar view, which is displayed only when the VOD video is playing. For more information, see [BDLPlayerSliderView](#BDLPlayerSliderView).
 */
@property (nonatomic, strong) BDLPlayerSliderView *sliderView;
/**
 * @locale zh
 * @brief 是否正在拖动进度条。
 *        - `YES`：正在拖动进度条。
 *        - `NO`：未在拖动进度条。
 */
/**
 * @locale en
 * @brief Whether the progress bar is being dragged.<br>
 *        - `YES`: Being dragged.
 *        - `NO`: Not being dragged.
 */
@property (nonatomic, readonly, getter=isSliding) BOOL sliding;
/**
 * @locale zh
 * @brief 倍速按钮。不支持自定义文字。
 */
/**
 * @locale en
 * @brief The playback speed button. All properties except `text` can be customized.
 */
@property (nonatomic, strong) UIButton *speedButton;
/**
 * @locale zh
 * @brief 当前播放速度。详见 [BDLPlayerSpeed](1185544#BDLPlayerSpeed)。
 */
/**
 * @locale en
 * @brief The current playback speed. For more information, see [BDLPlayerSpeed](viewer-sdk-for-ios-type-definitions#BDLPlayerSpeed).
 */
@property (nonatomic, assign) BDLPlayerSpeed speed;
/**
 * @locale zh
 * @brief 清晰度按钮。
 */
/**
 * @locale en
 * @brief The resolution button.
 */
@property (nonatomic, strong, nullable) UIButton *resolutionButton;
/**
 * @locale zh
 * @brief 礼物按钮。
 * @hidden (Windows,Linux,macOS,Android,iOS)
 */
/**
 * @locale en
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@property (nonatomic, strong, readonly) UIButton *giftButton;
/**
 * @locale zh
 * @brief 初始化。
 * @param isPortrait 是否以竖屏直播间初始化。<br>
 *        - `YES`：以竖屏直播间初始化。
 *        - `NO`：以横屏直播间初始化。
 * @param config 配置。详见 [BDLPlayerConfiguration](1185544#BDLPlayerConfiguration)。
 * @list 播放器
 * @return 播放器控制 view 实例。
 */
/**
 * @locale en
 * @brief Initializes the instance of the player control view.
 * @param isPortrait Whether to initialize in portrait mode.
 *        - `YES`: Portrait mode.
 *        - `NO`: Landscape mode.
 * @param config The configuration. For more information, see [BDLPlayerConfiguration](viewer-sdk-for-ios-type-definitions#BDLPlayerConfiguration).
 * @return The instance of the player control view.
 */
- (instancetype)initWithPortrait:(BOOL)isPortrait config:(BDLPlayerConfiguration *)config;
/**
 * @locale zh
 * @brief 播放。
 * @list 播放器
 */
/**
 * @locale en
 * @brief Plays the video.
 */
- (void)play;
/**
 * @locale zh
 * @brief 暂停播放。
 * @list 播放器
 */
/**
 * @locale en
 * @brief Pauses the video.
 */
- (void)pause;
/**
 * @locale zh
 * @brief 根据播放状态同步播放按钮的状态。
 * @param isPlaying 是否正在播放。
 *        - `YES`：正在播放。显示暂停按钮。
 *        - `NO`：未在播放。显示播放按钮。
 * @list 播放器
 */
/**
 * @locale en
 * @brief Synchronizes the play button's status according to the playback status.
 * @param isPlaying Whether the video is playing.<br>
 *        - `YES`: Playing. The pause button is displayed.
 *        - `NO`: Not playing. The play button is displayed.
 */
- (void)updatePlayButton:(BOOL)isPlaying;
/**
 * @locale zh
 * @brief 设置当前的播放进度。
 * @param progress 当前的播放进度。取值范围：[0,1]。
 * @param animated 是否需要动画。
 *        - `YES`：需要动画。
 *        - `NO`：不需要动画。
 * @list 播放器
 */
/**
 * @locale en
 * @brief Sets the current playback progress.
 * @param progress The current playback progress. Value range: [0,1].
 * @param animated Whether animation is needed.<br>
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
 * @param animated Whether animation is needed.<br>
 *        - `YES`: Needed.
 *        - `NO`: Not needed.
 */
- (void)setCacheProgress:(CGFloat)progress animated:(BOOL)animated;
/**
 * @locale zh
 * @brief 显示控制 view。SDK 内部会判断是否可以显示。
 * @list 播放器
 * @return - `YES`: 显示。
 *         - `NO`: 不显示。
 */
/**
 * @locale en
 * @brief Displays the control view. The SDK internally determines whether the view can be displayed.
 * @return - `YES`: Display.
 *         - `NO`: Do not display.
 */
- (BOOL)showIfNeeded;
/**
 * @locale zh
 * @brief 隐藏控制 view。
 * @list 播放器
 */
/**
 * @locale en
 * @brief Hides the control view.
 */
- (void)hide;
/**
 * @locale zh
 * @brief 当前是否正在播放。
 * @list 播放器
 * @return - `YES`：正在播放。
 *         - `NO`：未在播放。
 */
/**
 * @locale en
 * @brief Whether the video is playing.
 * @return - `YES`: Playing.
 *         - `NO`: Not playing.
 */
- (BOOL)isPlaying;
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
 * @param config 配置。详见 [BDLPlayerConfiguration](1185544#BDLPlayerConfiguration)。
 * @list 播放器
 */
/**
 * @locale en
 * @brief Updates the view based on the configuration.
 * @param config The configuration. For more information, see [BDLPlayerConfiguration](viewer-sdk-for-ios-type-definitions#BDLPlayerConfiguration).
 */
- (void)updateWithConfig:(BDLPlayerConfiguration *)config;

/**
 * @locale zh
 * @brief 更新清晰度。
 * @param resolutions 所有支持的清晰度。
 * @param resolution 当前选中的清晰度。详见 [BDLVideoResolution](1185544#BDLVideoResolution)。
 * @list 播放器
 */
/**
 * @locale en
 * @brief Updates the resolution.
 * @param resolutions All the supported resolutions.
 * @param resolution The currently selected resolution. For more information, see [BDLVideoResolution](viewer-sdk-for-ios-type-definitions#BDLVideoResolution).
 */
- (void)updateResolutionButtonWithResolutions:(NSArray<NSNumber *> *)resolutions currentResolution:(BDLVideoResolution)resolution;
/**
 * @locale zh
 * @brief 修改清晰度，用于同步清晰度按钮的显示。
 * @param success 清晰度是否修改成功。
 *        - `YES`：成功。
 *        - `NO`：失败。
 * @param completeResolution 最终的清晰度。详见 [BDLVideoResolution](1185544#BDLVideoResolution)。
 * @list 播放器
 */
/**
 * @locale en
 * @brief Changes the resolution to synchronize the display of the resolution button.
 * @param success Whether the resolution is changed successfully.<br>
 *        - `YES`: Successful.
 *        - `NO`: Failed.
 * @param completeResolution The final resolution. For more information, see [BDLVideoResolution](viewer-sdk-for-ios-type-definitions#BDLVideoResolution).
 */
- (void)changeResolutionSuccess:(BOOL)success completeResolution:(BDLVideoResolution)completeResolution;

/**
 * @locale zh
 * @brief 进入或退出全屏。
 * @list 播放器
 */
/**
 * @locale en
 * @brief Enters or exits full-screen mode.
 */
- (void)onFullScreen;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
