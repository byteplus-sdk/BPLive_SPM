//
//  BDLFloatingPlayer.h
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

#import "BDLBasePlayerView.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

@class BDLFloatingPlayer;
/**
 * @locale zh
 * @type callback
 * @brief 浮窗播放器（InApp 画中画）的代理方法。
 */
/**
 * @locale en
 * @type callback
 * @brief The delegate methods for the floating player (namely the in-app PiP).
 */
@protocol BDLFloatingPlayerDelegate <NSObject>

@optional
/**
 * @locale zh
 * @brief 在即将显示播放器时，SDK 调用该方法。
 * @param floatingPlayer 浮窗播放器。详见 [BDLFloatingPlayer](1185540#BDLFloatingPlayer)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the player is about to appear.
 * @param floatingPlayer The floating player. For more information, see [BDLFloatingPlayer](docs-bdlliveengine#BDLFloatingPlayer).
 */
- (void)floatingPlayerWillAppear:(BDLFloatingPlayer *)floatingPlayer;
/**
 * @locale zh
 * @brief 在播放器消失时，SDK 调用该方法。
 * @param floatingPlayer 浮窗播放器。详见 [BDLFloatingPlayer](1185540#BDLFloatingPlayer)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the player disappears.
 * @param floatingPlayer The floating player. For more information, see [BDLFloatingPlayer](docs-bdlliveengine#BDLFloatingPlayer).
 */
- (void)floatingPlayerDidDisappear:(BDLFloatingPlayer *)floatingPlayer;
/**
 * @locale zh
 * @brief 在观众单击播放器时，SDK 调用该方法。
 * @param floatingPlayer 浮窗播放器。详见 [BDLFloatingPlayer](1185540#BDLFloatingPlayer)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers tap the player.
 * @param floatingPlayer The floating player. For more information, see [BDLFloatingPlayer](docs-bdlliveengine#BDLFloatingPlayer).
 */
- (void)floatingPlayerDidSingleTap:(BDLFloatingPlayer *)floatingPlayer;
/**
 * @locale zh
 * @brief 在观众双击播放器时，SDK 调用该方法。
 * @param floatingPlayer 浮窗播放器。详见 [BDLFloatingPlayer](1185540#BDLFloatingPlayer)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers double-tap the player.
 * @param floatingPlayer The floating player. For more information, see [BDLFloatingPlayer](docs-bdlliveengine#BDLFloatingPlayer).
 */
- (void)floatingPlayerDidDoubleTap:(BDLFloatingPlayer *)floatingPlayer;
/**
 * @locale zh
 * @brief 在播放器即将关闭时，SDK 调用该方法。
 * @param floatingPlayer 浮窗播放器。详见 [BDLFloatingPlayer](1185540#BDLFloatingPlayer)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the player is about to close.
 * @param floatingPlayer The floating player. For more information, see [BDLFloatingPlayer](docs-bdlliveengine#BDLFloatingPlayer).
 */
- (void)floatingPlayerWillClose:(BDLFloatingPlayer *)floatingPlayer;
/**
 * @locale zh
 * @brief 在点播断点续播时，SDK 调用该方法。
 * @param playbackTime 断点续播时间，即上次播放结束的时间点。单位：秒。
 * @param floatingPlayer 浮窗播放器。详见 [BDLFloatingPlayer](1185540#BDLFloatingPlayer)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when a VOD video automatically resumes playing from the point where it stopped.
 * @param floatingPlayer The floating player. For more information, see [BDLFloatingPlayer](docs-bdlliveengine#BDLFloatingPlayer).
 * @param playbackTime The position to which the video seeks after automatically resuming from where it stopped. Unit: seconds.
 */
- (void)floatingPlayer:(BDLFloatingPlayer *)floatingPlayer onVodAutoContinuePlayback:(NSTimeInterval)playbackTime;
/**
 * @locale zh
 * @brief 在点击关闭浮窗播放器时，SDK 调用该方法。
 * @param floatingPlayer 浮窗播放器。详见 [BDLFloatingPlayer](1185540#BDLFloatingPlayer)。
 * @return 是否执行默认点击逻辑，即关闭浮窗播放器。
 *         - `YES`：执行。
 *         - `NO`：不执行。
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers tap to close the floating player.
 * @param floatingPlayer The floating player. For more information, see [BDLFloatingPlayer](docs-bdlliveengine#BDLFloatingPlayer).
 * @return Whether to execute the default tap logic, which is to close the floating player.
 *         - `YES`: Execute.
 *         - `NO`: Do not execute.
 */
- (BOOL)floatingPlayerDidClickClose:(BDLFloatingPlayer *)floatingPlayer;

/**
 * @locale zh
 * @brief 在观众被强制退出直播间时，SDK 调用该方法。
 * @param floatingPlayer 浮窗播放器。详见 [BDLFloatingPlayer](1185540#BDLFloatingPlayer)。
 * @param info 观众被强制退出直播间的原因。详见 [BDLForceOfflineInfo](1185544#BDLForceOfflineInfo)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers are forcibly removed from the live room.
 * @param floatingPlayer The floating player. For more information, see [BDLFloatingPlayer](docs-bdlliveengine#BDLFloatingPlayer).
 * @param info The reason for viewers being forcibly removed from the live room. For more information, see [BDLForceOfflineInfo](viewer-sdk-for-ios-type-definitions#BDLForceOfflineInfo).
 */
- (void)floatingPlayer:(BDLFloatingPlayer *)floatingPlayer onUserForceOffline:(BDLForceOfflineInfo *)info;

@end

/**
 * @locale zh
 * @type api
 * @brief 浮窗播放器。
 */
/**
 * @locale en
 * @brief The floating player.
 */
@interface BDLFloatingPlayer : NSObject

/**
 * @locale zh
 * @brief 代理方法。详见 [BDLFloatingPlayerDelegate](1185541#BDLFloatingPlayerDelegate)。
 */
/**
 * @locale en
 * @brief The delegate method. For more information, see [BDLFloatingPlayerDelegate](viewer-SDK-for-ios-callbacks#BDLFloatingPlayerDelegate).
 */
@property (nonatomic, weak) id<BDLFloatingPlayerDelegate> delegate;
/**
 * @locale zh
 * @brief 独立播放器 view。详见 [BDLBasePlayerView](#BDLBasePlayerView)。
 */
/**
 * @locale en
 * @brief The custom player view. For more information, see [BDLBasePlayerView](#BDLBasePlayerView).
 */
@property (nonatomic, strong, readonly) BDLBasePlayerView *basePlayerView;
/**
 * @locale zh
 * @brief 容器 view。
 */
/**
 * @locale en
 * @brief The container view.
 */
@property (nonatomic, strong, readonly) UIView *containerView;

/**
 * @locale zh
 * @brief 初始化。
 * @param isPortrait 是否以竖屏直播间初始化。
 *        - `YES`：以竖屏直播间初始化。从 [loadingImage](1185544#BDLPlayerBaseConfiguration-loadingimage) 获取浮窗播放器加载中图片，从 [loadingImageSize](1185544#BDLPlayerBaseConfiguration-loadingimagesize) 获取浮窗播放器加载中图片的大小。
 *        - `NO`：以横屏直播间初始化。从 [loadingImage](1185544#BDLPlayerBaseConfiguration-loadingimage) 获取浮窗播放器加载中图片，从 [loadingImageSize](1185544#BDLPlayerBaseConfiguration-loadingimagesize) 获取浮窗播放器加载中图片的大小。
 * @list 播放器
 * @return 浮窗播放器实例。
 */
/**
 * @locale en
 * @brief Initializes the floating player instance.
 * @param isPortrait Whether to initialize in portrait mode.
 *        - `YES`: Portrait mode. Get the loading image of the floating player by using [loadingImage](viewer-sdk-for-ios-type-definitions#BDLPlayerBaseConfiguration-loadingimage) and the loading image size by using [loadingImageSize](viewer-sdk-for-ios-type-definitions#BDLPlayerBaseConfiguration-loadingimagesize).
 *        - `NO`: Landscape mode. Get the loading image of the floating player by using [loadingImage](viewer-sdk-for-ios-type-definitions#BDLPlayerBaseConfiguration-loadingimage) and the loading image size by using [loadingImageSize](viewer-sdk-for-ios-type-definitions#BDLPlayerBaseConfiguration-loadingimagesize).
 * @return The floating player instance.
 */
- (instancetype)initWithPortrait:(BOOL)isPortrait;
/**
 * @locale zh
 * @brief 初始化。
 * @param isPortrait 是否以竖屏直播间初始化。<br>
 *        - `YES`：以竖屏直播间初始化。从 [loadingImage](1185544#BDLPlayerBaseConfiguration-loadingimage) 获取浮窗播放器加载中图片，从 [loadingImageSize](1185544#BDLPlayerBaseConfiguration-loadingimagesize) 获取浮窗播放器加载中图片的大小。
 *        - `NO`：以横屏直播间初始化。从 [loadingImage](1185544#BDLPlayerBaseConfiguration-loadingimage) 获取浮窗播放器加载中图片，从 [loadingImageSize](1185544#BDLPlayerBaseConfiguration-loadingimagesize) 获取浮窗播放器加载中图片的大小。
 * @param basePlayerView 已经开始播放的独立播放器。详见 [BDLBasePlayerView](#BDLBasePlayerView)。
 * @list 播放器
 * @return 浮窗播放器实例。
 */
/**
 * @locale en
 * @brief Initializes the floating player instance.
 * @param isPortrait Whether to initialize in portrait mode.
 *        - `YES`: Portrait mode. Get the loading image of the floating player by using [loadingImage](viewer-sdk-for-ios-type-definitions#BDLPlayerBaseConfiguration-loadingimage) and the loading image size by using [loadingImageSize](viewer-sdk-for-ios-type-definitions#BDLPlayerBaseConfiguration-loadingimagesize).
 *        - `NO`: Landscape mode. Get the loading image of the floating player by using [loadingImage](viewer-sdk-for-ios-type-definitions#BDLPlayerBaseConfiguration-loadingimage) and the loading image size by using [loadingImageSize](viewer-sdk-for-ios-type-definitions#BDLPlayerBaseConfiguration-loadingimagesize).
 * @param basePlayerView The custom player that has already started playing. For more information, see [BDLBasePlayerView](#BDLBasePlayerView).
 * @return The floating player instance.
 */
- (instancetype)initWithPortrait:(BOOL)isPortrait basePlayerView:(BDLBasePlayerView *)basePlayerView;
/**
 * @locale zh
 * @brief 移除已经开始播放的独立播放器。
 * @list 播放器
 * @return 移除的独立播放器。
 */
/**
 * @locale en
 * @brief Removes the custom player that has already started playing.
 * @return The removed custom player.
 */
- (BDLBasePlayerView *)removeBasePlayerView;
/**
 * @locale zh
 * @brief 设置播放器方向。
 * @param orientation 播放器方向。
 * @list 播放器
 */
/**
 * @locale en
 * @brief Sets the player orientation.
 * @param orientation The player orientation.
 */
- (void)setUIOrientation:(UIInterfaceOrientation)orientation;
/**
 * @locale zh
 * @brief 显示播放器。播放器会以 16:9 的比例显示在右下方。如果已经有视频 size，则会根据视频 size 决定是 16:9 还是 9:16。
 * @param haveCloseButton 是否显示浮窗右上方的关闭按钮。<br>
 *        - `YES`：显示。
 *        - `NO`：不显示。
 * @list 播放器
 * @return - `YES`：显示成功。
 *         - `NO`：正在显示浮窗播放器。
 */
/**
 * @locale en
 * @brief Displays the player. The player is displayed in the lower-right corner with a 16:9 aspect ratio. If a video size is already specified, the aspect ratio is either 16:9 or 9:16 based on the video size.
 * @param haveCloseButton Whether to display the close button in the upper-right corner of the floating player.
 *        - `YES`: Display.
 *        - `NO`: Do not display.
 * @return 
 *         - `YES`: Displayed successfully.
 *         - `NO`: The floating player is being displayed.
 */
- (BOOL)showWithCloseButton:(BOOL)haveCloseButton;
/**
 * @locale zh
 * @brief 在指定位置显示播放器。
 * @param haveCloseButton 是否需要关闭按钮。<br>
 *        - `YES`：需要。
 *        - `NO`：不需要。
 * @param frame 显示位置。
 * @list 播放器
 * @return - `YES`：显示成功。
 *         - `NO`：正在显示浮窗播放器。
 */
/**
 * @locale en
 * @brief Displays the player at the specified position.
 * @param frame The display position.
 * @param haveCloseButton Whether the close button is needed.<br>
 *        - `YES`: Needed.
 *        - `NO`: Not needed.
 * @return - `YES`: Displayed successfully.
 *         - `NO`: The floating player is being displayed.
 */
- (BOOL)showWithFrame:(CGRect)frame closeButton:(BOOL)haveCloseButton;
/**
 * @locale zh
 * @brief 隐藏播放器。
 * @list 播放器
 */
/**
 * @locale en
 * @brief Hides the player.
 */
- (void)hide;
/**
 * @locale zh
 * @brief 关闭播放器。效果同 [hide](#BDLFloatingPlayer-hide)，但比 `hide` 多了 [floatingPlayerWillClose](1185541#BDLFloatingPlayerDelegate-floatingplayerwillclose) 回调。
 * @list 播放器
 */
/**
 * @locale en
 * @brief Closes the player. This has the same effect as [hide](#BDLFloatingPlayer-hide), but additionally triggers the [floatingPlayerWillClose](viewer-SDK-for-ios-callbacks#BDLFloatingPlayerDelegate-floatingplayerwillclose) callback.
 */
- (void)close;
/**
 * @locale zh
 * @brief 播放器是否处于悬浮状态。
 * @list 播放器
 * @return - `YES`：播放器处于悬浮状态。
 *         - `NO`：播放器不处于悬浮状态。
 */
/**
 * @locale en
 * @brief Whether the player is in the floating mode.
 * @return - `YES`: In the floating mode.
 *         - `NO`: Not in the floating mode.
 */
- (BOOL)isFloating;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
