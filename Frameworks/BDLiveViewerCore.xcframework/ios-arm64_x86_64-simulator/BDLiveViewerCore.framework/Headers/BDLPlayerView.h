//
//  BDLPlayerView.h
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
#import <BDLiveCommon/BDLLanguageService.h>
#import "BDLBasePlayerView.h"
#import "BDLPlayerMaskView.h"
#import "BDLPlayerControlView.h"
#import "BDLLoadingView.h"
#import "BDLNetworkNotReachableView.h"
#import "BDLNetworkViaWWANView.h"
#import "BDLPlayerReplayView.h"
#import "BDLContinuePlaybackToastView.h"
#import "BDLPlayerSpeedView.h"
#import "BDLCardExplainService.h"
#import "BDLForceOfflineInfo.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

@class BDLPlayerView;

/**
 * @locale zh
 * @type callback
 * @brief 播放器 view 的代理方法。
 */
/**
 * @locale en
 * @type callback
 * @brief The delegate methods for the player view.
 */
@protocol BDLPlayerViewDelegate <NSObject>
/**
 * @locale zh
 * @brief 在控制 view 显示或消失时，SDK 调用该方法。
 * @param isAppear 是否显示控制 view。
 *        - `YES`：显示。
 *        - `NO`：不显示。
 * @param playerView 播放器 view。详见 [BDLPlayerView](1185540#BDLPlayerView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the control view appears or disappears.
 * @param playerView The player view. For more information, see [BDLPlayerView](docs-bdlliveengine#BDLPlayerView).
 * @param isAppear Whether to display the control view.
 *        - `YES`: Display.
 *        - `NO`: Do not display.
 */
- (void)playerView:(BDLPlayerView *)playerView controlViewIsAppear:(BOOL)isAppear;
/**
 * @locale zh
 * @brief 在播放完成时，SDK 调用该方法。
 * @param isLive 是否为直播。
 *        - `YES`：直播。
 *        - `NO`：非直播。
 * @param playerView 播放器 view。详见 [BDLPlayerView](1185540#BDLPlayerView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the video finishes playing.
 * @param playerView The player view. For more information, see [BDLPlayerView](docs-bdlliveengine#BDLPlayerView).
 * @param isLive Whether it is a live stream.
 *        - `YES`: A live stream.
 *        - `NO`: Not a live stream.
 */
- (void)playerView:(BDLPlayerView *)playerView didFinishPlayingWithIsLive:(BOOL)isLive;

@optional

/**
 * @locale zh
 * @brief 在观众点击进入或退出全屏按钮时，SDK 调用该方法。
 * @param isSelected 观众是否点击了进入全屏按钮。
 *        - `YES`：点击了进入全屏按钮，即当前为全屏状态。
 *        - `NO`：点击了退出全屏按钮，即当前为非全屏状态。
 * @param playerView 播放器 view。详见 [BDLPlayerView](1185540#BDLPlayerView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers tap the button to enter or exit full-screen mode.
 * @param playerView The player view. For more information, see [BDLPlayerView](docs-bdlliveengine#BDLPlayerView).
 * @param isSelected Whether viewers tap the button to enter full-screen mode.
 *        - `YES`: Tap the button to enter full-screen mode.
 *        - `NO`: Tap the button to exit full-screen mode.
 */
- (void)playerView:(BDLPlayerView *)playerView fullScreenButtonDidTouch:(BOOL)isSelected;
/**
 * @locale zh
 * @brief 在视频尺寸发生改变时，SDK 调用该方法。
 * @param playerView 播放器 view。详见 [BDLPlayerView](1185540#BDLPlayerView)。
 * @param size 当前的视频尺寸。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the video size changes.
 * @param playerView The player view. For more information, see [BDLPlayerView](docs-bdlliveengine#BDLPlayerView).
 * @param size The current video size.
 */
- (void)playerView:(BDLPlayerView *)playerView videoSizeDidChange:(CGSize)size;
/**
 * @locale zh
 * @brief 在直播封面改变时，SDK 调用该方法。
 * @param image 当前的直播封面图。
 * @param error 错误信息。有值则新的直播封面图获取失败，继续使用之前的直播封面图。
 * @param playerView 播放器 view。详见 [BDLPlayerView](1185540#BDLPlayerView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the live cover changes.
 * @param playerView The player view. For more information, see [BDLPlayerView](docs-bdlliveengine#BDLPlayerView).
 * @param image The current live cover image.
 * @param error The error information. If this parameter has a value, it means that getting the new live cover image failed, and the previous cover image is used instead.
 */
- (void)playerView:(BDLPlayerView *)playerView coverImageDidChange:(nullable UIImage *)image error:(nullable NSError *)error;
/**
 * @locale zh
 * @brief 在观众单击播放器时，SDK 调用该方法。
 * @param playerView 播放器 view。详见 [BDLPlayerView](1185540#BDLPlayerView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers tap the player.
 * @param playerView The player view. For more information, see [BDLPlayerView](docs-bdlliveengine#BDLPlayerView).
 */
- (void)playerViewDidSingleTap:(BDLPlayerView *)playerView;
/**
 * @locale zh
 * @brief 在播放内容改变时，SDK 调用该方法。
 * @param isLive 是否为直播。
 *        - `YES`：直播。
 *        - `NO`：非直播。
 * @param willPlay 是否将要播放。
 *        - `YES`：将要播放。
 *        - `NO`：未将要播放。
 * @param playerView 播放器 view。详见 [BDLPlayerView](1185540#BDLPlayerView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the media content changes.
 * @param playerView The player view. For more information, see [BDLPlayerView](docs-bdlliveengine#BDLPlayerView).
 * @param isLive Whether it is a live stream.
 *        - `YES`: A live stream.
 *        - `NO`: Not a live stream.
 * @param willPlay Whether the content is about to play.
 *        - `YES`: About to play.
 *        - `NO`: Not about to play.
 */
- (void)playerViewPlayerItemDidChange:(BDLPlayerView *)playerView isLive:(BOOL)isLive willPlay:(BOOL)willPlay;
/**
 * @locale zh
 * @brief 在观众被强制退出直播间时，SDK 调用该方法。
 * @param playerView 播放器 view。详见 [BDLPlayerView](1185540#BDLPlayerView)。
 * @param info 观众被强制退出直播间的原因。详见 [BDLForceOfflineInfo](1185544#BDLForceOfflineInfo)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers are forcibly removed from the live room.
 * @param playerView The player view. For more information, see [BDLPlayerView](docs-bdlliveengine#BDLPlayerView).
 * @param info The reason for viewers being forcibly removed from the live room. For more information, see [BDLForceOfflineInfo](viewer-sdk-for-ios-type-definitions#BDLForceOfflineInfo).
 */
- (void)playerView:(BDLPlayerView *)playerView onUserForceOffline:(BDLForceOfflineInfo *)info;

@end

/**
 * @locale zh
 * @type api
 * @brief 播放器 view。
 */
/**
 * @locale en
 * @brief The player view.
 */
@interface BDLPlayerView : BDLBaseView <BDLBasicService, BDLLanguageService, BDLCardExplainService>

/**
 * @locale zh
 * @brief 初始化。
 * @param isPortrait 是否以竖屏直播间初始化。<br><br>
 *        - `YES`：以竖屏直播间初始化。源流画面宽高比不同，播放器画面区域与控制界面（播放按钮等互动按钮）的显示样式不同。
 *          - 源流画面宽度大于等于高度，即横屏视频：播放器画面区域宽度为播放器的宽度，高度为播放器宽度的 9/16，距离播放器顶部 120 px。控制界面在画面区域的底部。默认有全屏按钮。
 *          - 源流画面宽度小于高度，即竖屏视频：播放器画面区域为整个播放器。在播放点播视频时，控制界面在播放器底部，但直播期间播放器无控制界面。
 *        - `NO`：以横屏直播间初始化。无论源流画面宽高比如何，播放器画面区域为整个播放器, 控制界面在播放器的底部。
 * @list 播放器
 * @return 播放器 view 实例。
 */
/**
 * @locale en
 * @brief Initializes the instance of the player view.
 * @param isPortrait Whether to initialize in portrait mode.
 *        - `YES`: Portrait mode. The aspect ratios of source stream videos are different, resulting in different display styles for the video and the control interface (interaction buttons such as the play button). <br>
 *          - When the width of the source stream video is greater than or equal to its height: The video width is equal to the player width, and the video height is 9/16 of the player width, with the video positioned 120 px from the top of the player. The control interface is located at the bottom of the video, with a full-screen button included by default.
 *          - When the width of the source stream video is less than its height: The video occupies the entire player. When playing VOD videos, the control interface is at the bottom of the player, but the player does not have the control interface during a live stream.
 *        - `NO`: Landscape mode. Regardless of the aspect ratio of the source stream video, the video occupies the entire player, with the control interface located at the bottom of the player.
 * @return The instance of the player view.
 */
- (instancetype)initWithPortrait:(BOOL)isPortrait;
/**
 * @locale zh
 * @brief 初始化。
 * @param isPortrait 是否以竖屏直播间初始化。<br><br>
 *        - `YES`：以竖屏直播间初始化。源流画面宽高比不同，播放器画面区域与控制界面（播放按钮等互动按钮）的显示样式不同。
 *          - 源流画面宽度大于等于高度，即横屏视频：播放器画面区域宽度为播放器的宽度，高度为播放器宽度的 9/16，距离播放器顶部 120 px。控制界面在画面区域的底部。默认有全屏按钮。
 *          - 源流画面宽度小于高度，即竖屏视频：播放器画面区域为整个播放器。在播放点播视频时，控制界面在播放器底部，但直播期间播放器无控制界面。
 *        - `NO`：以横屏直播间初始化。无论源流画面宽高比如何，播放器画面区域为整个播放器, 控制界面在播放器的底部。
 * @param basePlayerView 已经开始播放的独立播放器。详见 [BDLBasePlayerView](#BDLBasePlayerView)。
 * @list 播放器
 * @return 播放器 view 实例。
 */
/**
 * @locale en
 * @brief Initializes the instance of the player view.
 * @param isPortrait Whether to initialize in portrait mode.
 *        - `YES`: Portrait mode. The aspect ratios of source stream videos are different, resulting in different display styles for the video and the control interface (interaction buttons such as the play button). <br>
 *          - When the width of the source stream video is greater than or equal to its height: The video width is equal to the player width, and the video height is 9/16 of the player width, with the video positioned 120 px from the top of the player. The control interface is located at the bottom of the video, with a full-screen button included by default. <br>
 *          - When the width of the source stream video is less than its height: The video occupies the entire player. When playing VOD videos, the control interface is at the bottom of the player, but the player does not have the control interface during a live stream.
 *        - `NO`: Landscape mode. Regardless of the aspect ratio of the source stream video, the video occupies the entire player, with the control interface located at the bottom of the player.
 * @param basePlayerView The custom player that has already started playing. For more information, see [BDLBasePlayerView](#BDLBasePlayerView).
 * @return The instance of the player view.
 */
- (instancetype)initWithPortrait:(BOOL)isPortrait basePlayerView:(nullable BDLBasePlayerView *)basePlayerView;
/**
 * @locale zh
 * @brief 弹窗显示的父 view。SDK 内部默认实现了倍速、清晰度等弹窗效果，弹窗会加到 `popupSuperView` 上面。
 */
/**
 * @locale en
 * @brief The parent view for displaying the dialog box. The SDK has a default implementation for dialog boxes such as the playback speed and resolution. The dialog box will be added on top of `popupSuperView`.
 */
@property (nonatomic, weak) UIView *popupSuperView;
/**
 * @locale zh
 * @brief 代理方法。详见 [BDLPlayerViewDelegate](1185541#BDLPlayerViewDelegate)。
 */
/**
 * @locale en
 * @brief The delegate method. For more information, see [BDLPlayerViewDelegate](viewer-SDK-for-ios-callbacks#BDLPlayerViewDelegate).
 */
@property (nonatomic, weak) id<BDLPlayerViewDelegate> delegate;
/**
 * @locale zh
 * @brief 独立播放器 view。`playerView` 持有一个 `basePlayerView` 并添加了控制的逻辑。详见 [BDLBasePlayerView](#BDLBasePlayerView)。
 */
/**
 * @locale en
 * @brief The custom player view. `playerView` holds a `basePlayerView` and adds the control logic. For more information, see [BDLBasePlayerView](#BDLBasePlayerView).
 */
@property (nonatomic, strong, readonly, nullable) BDLBasePlayerView *basePlayerView;
/**
 * @locale zh
 * @brief 播放器遮罩 view，包含直播状态、水印、人气 view 等。详见 [BDLPlayerMaskView](#BDLPlayerMaskView)。
 */
/**
 * @locale en
 * @brief The player mask view, including the live room status, watermark, and popularity view. For more information, see [BDLPlayerMaskView](#BDLPlayerMaskView).
 */
@property (nonatomic, strong) BDLPlayerMaskView *playerMaskView;
/**
 * @locale zh
 * @brief 播放器控制 view，包含播放按钮、暂停按钮、进度条、刷新按钮、全屏按钮、时间文本等。详见 [BDLPlayerControlView](#BDLPlayerControlView)。
 */
/**
 * @locale en
 * @brief The player control view, including the play button, pause button, progress bar, refresh button, full-screen button, and time text. For more information, see [BDLPlayerControlView](#BDLPlayerControlView).
 */
@property (nonatomic, strong) BDLPlayerControlView *controlView;
/**
 * @locale zh
 * @brief 清晰度选择 view。详见 [BDLPlayerResolutionView](#BDLPlayerResolutionView)。
 */
/**
 * @locale en
 * @brief The resolution selection view. For more information, see [BDLPlayerResolutionView](#BDLPlayerResolutionView).`
 */
@property (nonatomic, strong, nullable) BDLPlayerResolutionView *resolutionView;
/**
 * @locale zh
 * @brief 倍速选择 view。详见 [BDLPlayerSpeedView](#BDLPlayerSpeedView)。
 */
/**
 * @locale en
 * @brief The playback speed selection view. For more information, see [BDLPlayerSpeedView](#BDLPlayerSpeedView).
 */
@property (nonatomic, strong, nullable) BDLPlayerSpeedView *speedView;
/**
 * @locale zh
 * @brief 加载 view。详见 [BDLLoadingView](#BDLLoadingView)。
 */
/**
 * @locale en
 * @brief The loading view. For more information, see [BDLLoadingView](#BDLLoadingView).
 */
@property (nonatomic, strong, nullable) BDLLoadingView *loadingView;
/**
 * @locale zh
 * @brief 断网提示 view。详见 [BDLNetworkNotReachableView](#BDLNetworkNotReachableView)。
 */
/**
 * @locale en
 * @brief The network disconnection prompt view. For more information, see [BDLNetworkNotReachableView](#BDLNetworkNotReachableView).
 */
@property (nonatomic, strong, nullable) BDLNetworkNotReachableView *networkNotReachableView;
/**
 * @locale zh
 * @brief 流量访问提示 view。详见 [BDLNetworkViaWWANView](#BDLNetworkViaWWANView)。
 */
/**
 * @locale en
 * @brief The mobile data access prompt view. For more information, see [BDLNetworkViaWWANView](#BDLNetworkViaWWANView).
 */
@property (nonatomic, strong, nullable) BDLNetworkViaWWANView *networkViaWWANView;
/**
 * @locale zh
 * @brief 重播 view。详见 [BDLPlayerReplayView](#BDLPlayerReplayView)。
 */
/**
 * @locale en
 * @brief The replay view. For more information, see [BDLPlayerReplayView](#BDLPlayerReplayView).
 */
@property (nonatomic, strong, nullable) BDLPlayerReplayView *replayView;
/**
 * @locale zh
 * @brief 断点续播提示 view。详见 [BDLContinuePlaybackToastView](#BDLContinuePlaybackToastView)。
 */
/**
 * @locale en
 * @brief The breakpoint resumption prompt view. For more information, see [BDLContinuePlaybackToastView](#BDLContinuePlaybackToastView).
 */
@property (nonatomic, strong, nullable) BDLContinuePlaybackToastView *continuePlaybackToastView;
/**
 * @locale zh
 * @brief 播放器配置。详见 [BDLPlayerConfiguration](1185544#BDLPlayerConfiguration)。
 */
/**
 * @locale en
 * @brief The player configuration. For more information, see [BDLPlayerConfiguration](viewer-sdk-for-ios-type-definitions#BDLPlayerConfiguration).
 */
@property (nonatomic, strong, readonly) BDLPlayerConfiguration *config;
/**
 * @locale zh
 * @brief 是否已进入系统画中画。
 *        - `YES`：已进入。
 *        - `NO`：未进入。
 */
/**
 * @locale en
 * @brief Whether the system PiP mode is started.
 *        - `YES`: Started.
 *        - `NO`: Not started.
 */
@property (nonatomic, assign, readonly) BOOL isPiPStarted;
/**
 * @locale zh
 * @brief 是否为全屏。<br>
 *        - `YES`：全屏。
 *        - `NO`：非全屏。
 */
/**
 * @locale en
 * @brief Whether in full-screen mode.
 *        - `YES`: In full-screen mode.
 *        - `NO`: Not in full-screen mode.
 */
@property (nonatomic, assign, readonly) BOOL isFullScreen;
/**
 * @locale zh
 * @brief 播放器是否全屏。<br>
 *        - `YES`：全屏。
 *        - `NO`：非全屏。
 */
/**
 * @locale en
 * @brief Whether the player is in full-screen mode.
 *        - `YES`: In full-screen mode.
 *        - `NO`: Not in full-screen mode.
 */
@property (nonatomic, assign) BOOL isPlayerFullSuper;
/**
 * @locale zh
 * @brief 是否为竖屏视频。
 *        - `YES`：竖屏视频。
 *        - `NO`：横屏视频。
 */
/**
 * @locale en
 * @brief Whether the video height is greater than the width.
 *        - `YES`: Height is greater than the width.
 *        - `NO`: Height is less than the width.
 */
@property (nonatomic, assign) BOOL isPortraitVideo;
/**
 * @locale zh
 * @brief 自定义断点续播提示 view。
 * @param view 播放器 view。
 * @param toastView 断点续播提示 view。详见 [BDLContinuePlaybackToastView](#BDLContinuePlaybackToastView)。
 * @param currentPlaybackTime 当前播放时间。单位：秒。
 * @list 播放器
 * @return `UIView` 及其子类的实例。
 */
/**
 * @locale en
 * @brief Customizes the breakpoint resumption prompt view.
 * @param view The player view.
 * @param toastView The breakpoint resumption prompt view. For more information, see [BDLContinuePlaybackToastView](#BDLContinuePlaybackToastView).
 * @param currentPlaybackTime The current playback time. Unit: seconds.
 * @return Instances of `UIView` and its subclasses.
 */
@property (nonatomic, copy) __kindof UIView * (^customizeVodContinuePlaybackToastView)(BDLPlayerView *view, BDLContinuePlaybackToastView *toastView, NSTimeInterval currentPlaybackTime);
/**
 * @locale zh
 * @brief 自定义倍速选择界面。
 * @param playerView 播放器 view。
 * @param speedView 倍速选择 view。详见 [BDLPlayerSpeedView](#BDLPlayerSpeedView)。
 * @list 播放器
 */
/**
 * @locale en
 * @brief Customizes the playback speed selection interface.
 * @param playerView The player view.
 * @param speedView The playback speed selection view. For more information, see [BDLPlayerSpeedView](#BDLPlayerSpeedView).
 */
@property (nonatomic, copy) void (^customizeSpeedView)(BDLPlayerView *playerView, BDLPlayerSpeedView *speedView);
/**
 * @locale zh
 * @brief 显示 [controlView](#BDLPlayerView-controlview)。
 * @param autoHide 是否自动隐藏。<br>
 *        - `YES`：自动隐藏。
 *        - `NO`：非自动隐藏。
 * @list 播放器
 */
/**
 * @locale en
 * @brief Displays the [controlView](#BDLPlayerView-controlview).
 * @param autoHide Whether to hide automatically.<br>
 *        - `YES`: Hide automatically.
 *        - `NO`: Do not hide automatically.
 */
- (void)showControlViewIfNeededWithAutoHide:(BOOL)autoHide;
/**
 * @locale zh
 * @brief 隐藏 [controlView](#BDLPlayerView-controlview)。
 * @list 播放器
 */
/**
 * @locale en
 * @brief Hides the [controlView](#BDLPlayerView-controlview).
 */
- (void)hideControlView;
/**
 * @locale zh
 * @brief 自动隐藏 [controlView](#BDLPlayerView-controlview)。
 * @list 播放器
 */
/**
 * @locale en
 * @brief Automatically hides the [controlView](#BDLPlayerView-controlview).
 */
- (void)autoHideControlView;
/**
 * @locale zh
 * @brief 当前是否可以浮窗播放。
 * @list 播放器
 * @return - `YES`：可以浮窗播放。
 *         - `NO`：不可以浮窗播放。
 */
/**
 * @locale en
 * @brief Whether the video can play in the floating player.
 * @return - `YES`: Can play in the floating player.
 *         - `NO`: Cannot play in the floating player.
 */
- (BOOL)canFloating;
/**
 * @locale zh
 * @brief 进入全屏。外部实现全屏逻辑后调用该方法，更改 [controlView](#BDLPlayerView-controlview) 全屏按钮的状态。
 * @list 播放器
 */
/**
 * @locale en
 * @brief Enters full-screen mode. Call this method after implementing the full-screen logic externally to change the status of the [controlView](#BDLPlayerView-controlview)'s full-screen button.
 */
- (void)enterFullScreen;
/**
 * @locale zh
 * @brief 离开全屏。
 * @list 播放器
 */
/**
 * @locale en
 * @brief Exits full-screen mode.
 */
- (void)leaveFullScreen;
/**
 * @locale zh
 * @brief 获取浮窗关闭按钮的图片。
 * @list 播放器
 * @return 浮窗关闭按钮的图片。
 */
/**
 * @locale en
 * @brief Gets the image of the floating player's close button.
 * @return The image of the floating player's close button.
 */
- (UIImage *)getFloatingCloseImage;
/**
 * @locale zh
 * @brief 获取浮窗关闭按钮图片的大小。
 * @list 播放器
 * @return 浮窗关闭按钮图片的大小。
 */
/**
 * @locale en
 * @brief Gets the image size of the floating player's close button.
 * @return The image size of the floating player's close button.
 */
- (CGSize)getFloatingCloseImageSize;
/**
 * @locale zh
 * @brief 获取当前正在显示的媒体文件(图片/视频)的大小。
 * @list 播放器
 * @return 当前正在显示的媒体文件(图片/视频)的大小。
 */
/**
 * @locale en
 * @brief Gets the size of the currently displayed media file (image or video).
 * @return The size of the currently displayed media file (image or video).
 */
- (CGSize)getCurrentShowingMediaSize;
/**
 * @locale zh
 * @brief 退出全屏时更新播放器。
 * @list 播放器
 */
/**
 * @locale en
 * @brief Updates the player when exiting full-screen mode.
 */
- (void)updatePlayerWhenLeaveFullScreen;
/**
 * @locale zh
 * @brief 添加 `basePlayerView`。
 * @param basePlayerView 独立播放器。详见 [BDLBasePlayerView](#BDLBasePlayerView)。
 * @list 播放器
 */
/**
 * @locale en
 * @brief Adds `basePlayerView`.
 * @param basePlayerView The custom player. For more information, see [BDLBasePlayerView](#BDLBasePlayerView).
 */
- (void)addBasePlayerView:(BDLBasePlayerView *)basePlayerView;
/**
 * @locale zh
 * @brief removeFromSuperview，即从 [BDLPlayerView](#BDLPlayerView) 中移除 `basePlayerView`，使其不再显示在界面上，但属性 `self.basePlayerView` 不会为空，[BDLPlayerView](#BDLPlayerView) 会保留对 `basePlayerView` 的引用。
 * @list 播放器
 * @return 移除的 `basePlayerView`。
 */
/**
 * @locale en
 * @brief Removes `basePlayerView` from [BDLPlayerView](#BDLPlayerView) to not have `basePlayerView` displayed on the interface, while the property `self.basePlayerView` is not 'nil', and `BDLPlayerView` retains a reference to `basePlayerView`.
 * @return The removed `basePlayerView`.
 */
- (BDLBasePlayerView *)removeBasePlayerViewFromSuperview;

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
 * @brief 停止播放。
 * @list 播放器
 */
/**
 * @locale en
 * @brief Stops playing the video.
 */
- (void)stop;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
