//
//  BDLPlayerConfiguration.h
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


#import <BDLiveCommon/BDLDefines.h>
#import "BDLBasePlayerConfiguration.h"
#import <UIKit/UIKit.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type keytype
 * @brief 播放器控件风格。
 */
/**
 * @locale en
 * @type keytype
 * @brief The player control style.
 */
typedef NS_ENUM(NSInteger, BDLPlayerControlViewMode) {
/**
 * @locale zh
 * @brief 默认。
 */
   /**
    * @locale en
    * @brief Default.
    */
    BDLPlayerControlViewModeDefault,
/**
 * @locale zh
 * @brief 紧凑型。
 */
   /**
    * @locale en
    * @brief Compact.
    */
    BDLPlayerControlViewModeCompact,
};

/**
 * @locale zh
 * @type keytype
 * @brief 播放器公用配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The common configuration of the player.
 */
@interface BDLPlayerCommonConfiguration : NSObject

/**
 * @locale zh
 * @brief 播放按钮图片。
 */
/**
 * @locale en
 * @brief The image of the play button.
 */
@property (nonatomic, strong) UIImage *playButtonNormalImage;
/**
 * @locale zh
 * @brief 播放按钮选中的图片，即暂停按钮图片。
 */
/**
 * @locale en
 * @brief The image of the selected play button, namely the image of the pause button.
 */
@property (nonatomic, strong) UIImage *playButtonSelectedImage;
/**
 * @locale zh
 * @brief 播放器中间的播放按钮图片。
 */
/**
 * @locale en
 * @brief The image of the play button displayed in the center of the player.
 */
@property (nonatomic, strong) UIImage *centerPlayButtonNormalImage;
/**
 * @locale zh
 * @brief 刷新按钮图片。
 */
/**
 * @locale en
 * @brief The image of the refresh button.
 */
@property (nonatomic, strong) UIImage *refreshButtonNormalImage;
/**
 * @locale zh
 * @brief 刷新按钮是否居左。默认值：`NO`。
 *        - `YES`：居左。
 *        - `NO`：不居左。
 */
/**
 * @locale en
 * @brief Whether the refresh button is left-aligned. Default value: `NO`.
 *        - `YES`: Left-aligned.
 *        - `NO`: Not left-aligned.
 */
@property (nonatomic, assign) BOOL refreshButtonLocation;
/**
 * @locale zh
 * @brief 全屏按钮图片。
 */
/**
 * @locale en
 * @brief The image of the full-screen button.
 */
@property (nonatomic, strong) UIImage *fullScreenButtonNormalImage;
/**
 * @locale zh
 * @brief 全屏按钮选中的图片。
 */
/**
 * @locale en
 * @brief The image of the selected full-screen button.
 */
@property (nonatomic, strong) UIImage *fullScreenButtonSelectedImage;
/**
 * @locale zh
 * @brief 是否支持进入全屏模式。默认值：`YES`。
 *        - `YES`：支持，播放器内显示全屏按钮。全屏按钮可在竖屏直播间的直播或点播源流画面宽大于高时以及横屏直播间内显示。
 *        - `NO`：不支持，播放器内不显示全屏按钮。
 */
/**
 * @locale en
 * @brief Whether to enable full-screen mode. Default value: `YES`.
 *        - `YES`: Enable. The full-screen button is displayed in the player. The full-screen button appears in:
 *          - live rooms in landscape mode.
 *          - live rooms in portrait mode when the width of the source video stream is greater than the height.
 *        - `NO`: Disable. The full-screen button is not displayed in the player.
 */
@property (nonatomic, assign) BOOL enterFullScreenEnable;
/**
 * @locale zh
 * @brief 退出全屏按钮图片。
 */
/**
 * @locale en
 * @brief The image of the exit full-screen button.
 */
@property (nonatomic, strong) UIImage *exitFullScreenButtonNormalImage;

/**
 * @locale zh
 * @brief 主题色，即已播放进度条的背景颜色。
 */
/**
 * @locale en
 * @brief The theme color, which is the background color of the played progress bar.
 */
@property (nonatomic, strong) UIColor *themeColor;
/**
 * @locale zh
 * @brief 当前时间标签颜色。
 */
/**
 * @locale en
 * @brief The color of the current time label.
 */
@property (nonatomic, strong) UIColor *currentTimeColor;
/**
 * @locale zh
 * @brief 总时间标签颜色。
 */
/**
 * @locale en
 * @brief The color of the total time label.
 */
@property (nonatomic, strong) UIColor *totalTimeColor;

/**
 * @locale zh
 * @brief 预告或直播已结束的 toast 字体和字号。
 */
/**
 * @locale en
 * @brief The font and font size of the toast indicating the preview or live stream has ended.
 */
@property (nonatomic, assign) UIFont *toastFont;
/**
 * @locale zh
 * @brief 预告或直播已结束的 toast 圆角半径。
 */
/**
 * @locale en
 * @brief The corner radius of the toast indicating the preview or live stream has ended.
 */
@property (nonatomic, assign) CGFloat toastCornerRadius;
/**
 * @locale zh
 * @brief 预告或直播已结束的 toast 左右边距。
 */
/**
 * @locale en
 * @brief The left and right margins for the toast indicating the preview or live stream has ended.
 */
@property (nonatomic, assign) CGFloat toastHorizontalEdge;
/**
 * @locale zh
 * @brief 预告或直播已结束的 toast 上下边距。
 */
/**
 * @locale en
 * @brief The top and bottom margins for the toast indicating the preview or live stream has ended.
 */
@property (nonatomic, assign) CGFloat toastVerticalEdge;
/**
 * @locale zh
 * @brief 预告或直播已结束的 toast 位置。
 */
/**
 * @locale en
 * @brief The position of the toast indicating the preview or live stream has ended.
 */
@property (nonatomic, assign) CGFloat toastCenterYOffset;
/**
 * @locale zh
 * @brief 提示频率。
 *        - `-1`：每次都提示。
 *        - `0`：永不提示。
 *        - 大于 `0` 的值：提示次数。默认值：`1`。
 */
/**
 * @locale en
 * @brief The prompt frequency.<br>
 *        - `-1`: Always prompt.
 *        - `0`: Never prompt.
 *        - Greater than `0`: Number of prompts. Default value: `1`.
 */
@property (nonatomic, assign) NSInteger wwanPromptCount;
/**
 * @locale zh
 * @brief 流量访问提示文案。
 */
/**
 * @locale en
 * @brief The text of the mobile data access prompt.
 */
@property (nonatomic, copy) NSString *viaWWANText;

/**
 * @locale zh
 * @brief 断网提示文案。
 */
/**
 * @locale en
 * @brief The text of the offline prompt.
 */
@property (nonatomic, copy) NSString *networkNotReachableText;
/**
 * @locale zh
 * @brief 提示文案文字颜色。
 */
/**
 * @locale en
 * @brief The text color of the prompt.
 */
@property (nonatomic, strong) UIColor *promptTextColor;

/**
 * @locale zh
 * @brief 是否开启音频抢占管理。默认值：`YES`。<br>
 *        - `YES`：切换至后台期间，暂停播放未开启后台音频播放以及系统画中画的视频。重新切换至前台后，自动播放开启了自动播放的视频。
 *        - `NO`：如果视频正在播放且开启了后台音频播放，切换至后台后会继续播放音频，如果视频暂停时被切换至后台，则仍然暂停播放。重新切换至前台后，播放状态与后台期间保持一致，后台播放音频则切换至前台后继续播放视频，后台暂停播放则切换至前台仍然暂停播放。
 */
/**
 * @locale en
 * @brief Whether to enable audio preemption management. Default value: `YES`.
 *        - `YES`: After switching to the background, pause the video that has background audio playback and system PiP disabled. When switching back to the foreground, automatically play the video that has autoplay enabled.
 *        - `NO`: If the video is playing and background audio playback is enabled, the audio will continue playing when switching to the background. If the video is paused when switching to the background, it will remain paused. When switching back to the foreground, the playback status will remain consistent with that in the background. If audio is playing in the background, the video will resume playing when switching to the foreground. If the video is paused in the background, it will remain paused when switching to the foreground.
 */
@property (nonatomic, assign) BOOL enableAudioPreemption;
/**
 * @locale zh
 * @brief 是否开启后台音频播放。默认值：`YES`。<br>
 *        - `YES`：开启。
 *        - `NO`：不开启。
 */
/**
 * @locale en
 * @brief Whether to enable the background audio playback. Default value: `YES`.
 *        - `YES`: Enable.
 *        - `NO`: Disable.
 */
@property (nonatomic, assign) BOOL enableBackgroundAudio;

/**
 * @locale zh
 * @brief 是否开启直播视频的系统画中画。默认值：`YES`。<br>
 *        - `YES`：开启。
 *        - `NO`：不开启。
 */
/**
 * @locale en
 * @brief Whether to enable the system PiP for live videos. Default value: `YES`.
 *        - `YES`: Enable.
 *        - `NO`: Disable.
 */
@property (nonatomic, assign) BOOL enableLivePiP API_AVAILABLE(ios(14.0));
/**
 * @locale zh
 * @brief 是否开启点播视频的系统画中画。默认值：`YES`。<br>
 *        - `YES`：开启。
 *        - `NO`：不开启。
 */
/**
 * @locale en
 * @brief Whether to enable the system PiP for Video-on-Demand (VOD) videos. Default value: `YES`.
 *        - `YES`: Enable.
 *        - `NO`: Disable.
 */
@property (nonatomic, assign) BOOL enableVodPiP API_AVAILABLE(ios(14.0));
/**
 * @locale zh
 * @brief 关闭浮窗图标。
 */
/**
 * @locale en
 * @brief The icon for closing the floating window.
 */
@property (nonatomic, strong) UIImage *floatingCloseImage;
/**
 * @locale zh
 * @brief 关闭浮窗图标大小。
 */
/**
 * @locale en
 * @brief The size of the icon for closing the floating window.
 */
@property (nonatomic, assign) CGSize floatingCloseImageSize;
/**
 * @locale zh
 * @brief 浮窗边框宽度。
 */
/**
 * @locale en
 * @brief The border width of the floating window.
 */
@property (nonatomic, assign) CGFloat floatingViewBorderWidth;
/**
 * @locale zh
 * @brief 浮窗边框颜色。
 */
/**
 * @locale en
 * @brief The border color of the floating window.
 */
@property (nonatomic, strong) UIColor *floatingViewBorderColor;
/**
 * @locale zh
 * @brief 浮窗的圆角半径。
 */
/**
 * @locale en
 * @brief The corner radius of the floating window.
 */
@property (nonatomic, assign) CGFloat floatingViewCornerRadius;

/**
 * @locale zh
 * @brief 切换清晰度后是否立即关闭清晰度选择界面。默认值：`YES`。<br>
 *        - `YES`：立即关闭。
 *        - `NO`：不立即关闭。
 */
/**
 * @locale en
 * @brief Whether to immediately close the resolution selection dialog box after switching the resolution. Default value: `YES`.
 *        - `YES`: Close immediately.
 *        - `NO`: Do not close immediately.
 */
@property (nonatomic, assign) BOOL closeResolutionViewAtOnce;
/**
 * @locale zh
 * @brief 切换倍速后是否立即关闭倍速选择界面。默认值：`YES`。<br>
 *        - `YES`：立即关闭。
 *        - `NO`：不立即关闭。
 */
/**
 * @locale en
 * @brief Whether to immediately close the playback speed selection dialog box after switching the speed. Default value: `YES`.
 *        - `YES`: Close immediately.
 *        - `NO`: Do not close immediately.
 */
@property (nonatomic, assign) BOOL closeSpeedViewAtOnce;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 播放器基类配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The base class configuration of the player.
 */
@interface BDLPlayerBaseConfiguration : NSObject

/**
 * @locale zh
 * @brief 视频画面的填充模式。<br>
 *         竖屏直播间默认为 `BDLPlayerScalingModeAspectFill`，横屏直播间默认为 `BDLPlayerScalingModeAspectFit`。详见 [BDLPlayerScalingMode](#BDLPlayerScalingMode)。
 */
/**
 * @locale en
 * @brief The video scaling mode.
 *        The default value for the live room in portrait mode is `BDLPlayerScalingModeAspectFill` and that for the live room in landscape mode is `BDLPlayerScalingModeAspectFit`. For more information, see [BDLPlayerScalingMode](#BDLPlayerScalingMode).
 */
@property (nonatomic, assign) BDLPlayerScalingMode scalingMode;
/**
 * @locale zh
 * @brief 直播从后台切回前台是否自动播放。默认值：`YES`。<br>
 *        - `YES`：自动播放。
 *        - `NO`：不自动播放。
 */
/**
 * @locale en
 * @brief Whether to automatically play the live stream when switching from the background to the foreground. Default value: `YES`.
 *        - `YES`: Automatically play.
 *        - `NO`: Do not automatically play.
 */
@property (nonatomic, assign) BOOL liveEnterForegroundAutoPlay;
/**
 * @locale zh
 * @brief 预告从后台切回前台是否自动播放。默认值：`NO`。<br>
 *        - `YES`：自动播放。
 *        - `NO`：不自动播放。
 */
/**
 * @locale en
 * @brief Whether to automatically play the preview when switching from the background to the foreground. Default value: `NO`.
 *        - `YES`: Automatically play.
 *        - `NO`: Do not automatically play.
 */
@property (nonatomic, assign) BOOL previewEnterForegroundAutoPlay;
/**
 * @locale zh
 * @brief 回放从后台切回前台是否自动播放。默认值：`NO`。<br>
 *        - `YES`：自动播放。
 *        - `NO`：不自动播放。
 */
/**
 * @locale en
 * @brief Whether to automatically play the playback when switching from the background to the foreground. Default value: `NO`.
 *        - `YES`: Automatically play.
 *        - `NO`: Do not automatically play.
 */
@property (nonatomic, assign) BOOL playbackEnterForegroundAutoPlay;

/**
 * @locale zh
 * @brief 重试按钮文字。
 */
/**
 * @locale en
 * @brief The text of the retry button.
 */
@property (nonatomic, copy) NSString *retryButtonTitle;
/**
 * @locale zh
 * @brief 重试按钮的圆角半径。
 */
/**
 * @locale en
 * @brief The corner radius of the retry button.
 */
@property (nonatomic, assign) CGFloat retryButtonCornerRadius;
/**
 * @locale zh
 * @brief 重试按钮背景颜色。
 */
/**
 * @locale en
 * @brief The background color of the retry button.
 */
@property (nonatomic, strong) UIColor *retryButtonBackgroundColor;

/**
 * @locale zh
 * @brief 重播提示文案。
 */
/**
 * @locale en
 * @brief The replay prompt text.
 */
@property (nonatomic, copy) NSString *replayText;
/**
 * @locale zh
 * @brief 重播提示文案文字颜色。
 */
/**
 * @locale en
 * @brief The text color of the replay prompt.
 */
@property (nonatomic, strong) UIColor *replayTextColor;
/**
 * @locale zh
 * @brief 重播按钮图片。
 */
/**
 * @locale en
 * @brief The image of the replay button.
 */
@property (nonatomic, strong) UIImage *replayButtonNormalImage;
/**
 * @locale zh
 * @brief 重播按钮图片大小。
 */
/**
 * @locale en
 * @brief The image size of the replay button.
 */
@property (nonatomic, assign) CGSize replayButtonNormalImageSize;
/**
 * @locale zh
 * @brief 重播按钮的圆角半径。
 */
/**
 * @locale en
 * @brief The corner radius of the replay button.
 */
@property (nonatomic, assign) CGFloat replayButtonCornerRadius;

/**
 * @locale zh
 * @brief 加载中图片。
 */
/**
 * @locale en
 * @brief The loading image.
 */
@property (nonatomic, strong) UIImage *loadingImage;
/**
 * @locale zh
 * @brief 加载中图片大小。
 */
/**
 * @locale en
 * @brief The size of the loading image.
 */
@property (nonatomic, assign) CGSize loadingImageSize;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 竖屏播放器配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The configuration of the player in portrait mode.
 */
@interface BDLPlayerPortraitConfiguration : BDLPlayerBaseConfiguration

/**
 * @locale zh
 * @brief 重播按钮背景颜色。
 */
/**
 * @locale en
 * @brief The background color of the replay button.
 */
@property (nonatomic, strong) UIColor *replayButtonBackgroundColor;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 横屏播放器配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The player configuration for the live room in landscape mode.
 */
@interface BDLPlayerLandscapeConfiguration : BDLPlayerBaseConfiguration

/**
 * @locale zh
 * @brief 播放器控件风格。详见 [BDLPlayerControlViewMode](#BDLPlayerControlViewMode)。
 */
/**
 * @locale en
 * @brief The player control style. For more information, see [BDLPlayerControlViewMode](#BDLPlayerControlViewMode).
 */
@property (nonatomic, assign) BDLPlayerControlViewMode controlViewMode;

/**
 * @locale zh
 * @brief 重播界面背景颜色。
 */
/**
 * @locale en
 * @brief The background color of the replay interface.
 */
@property (nonatomic, strong) UIColor *replayViewBackgroundColor;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 播放器配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The player configuration.
 */
@interface BDLPlayerConfiguration : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 * @locale zh
 * @brief 播放器公用配置。详见 [BDLPlayerCommonConfiguration](#BDLPlayerCommonConfiguration)。
 */
/**
 * @locale en
 * @brief The common configuration of the player. For more information, see [BDLPlayerCommonConfiguration](#BDLPlayerCommonConfiguration).
 */
@property (nonatomic, strong) BDLPlayerCommonConfiguration *common;
/**
 * @locale zh
 * @brief 独立播放器配置。详见 [BDLBasePlayerConfiguration](#BDLBasePlayerConfiguration)。
 */
/**
 * @locale en
 * @brief The configuration of the custom player. For more information, see [BDLBasePlayerConfiguration](#BDLBasePlayerConfiguration).
 */
@property (nonatomic, strong) BDLBasePlayerConfiguration *basePlayerConfig;

/**
 * @locale zh
 * @brief 竖屏播放器配置。详见 [BDLPlayerPortraitConfiguration](#BDLPlayerPortraitConfiguration)。
 */
/**
 * @locale en
 * @brief The configuration of the player in portrait mode. For more information, see [BDLPlayerPortraitConfiguration](#BDLPlayerPortraitConfiguration).
 */
@property (nonatomic, strong) BDLPlayerPortraitConfiguration *portrait;
/**
 * @locale zh
 * @brief 横屏播放器配置。详见 [BDLPlayerLandscapeConfiguration](#BDLPlayerLandscapeConfiguration)。
 */
/**
 * @locale en
 * @brief The configuration of the player in landscape mode. For more information, see [BDLPlayerLandscapeConfiguration](#BDLPlayerLandscapeConfiguration).
 */
@property (nonatomic, strong) BDLPlayerLandscapeConfiguration *landscape;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
