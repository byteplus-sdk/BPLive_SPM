//
//  BDLBasePlayerView.h
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
#import "BDLPullStreamUrlService.h"
#import "BDLBasePlayerConfiguration.h"
#import "BDLForceOfflineInfo.h"

//#if BUILD_SPM
#if __has_include(<TTSDKPlayer/TTVideoEnginePlayerDefine.h>)
    #import <TTSDKPlayer/TTVideoEnginePlayerDefine.h>
#elif __has_include(<TTSDKFramework/TTSDKFramework.h>)
    #import <TTSDKFramework/TTVideoEnginePlayerDefine.h>
#elif __has_include(<TTSDK/TTSDKManager.h>)
    #import <TTSDK/TVLPlayerItem.h>
    #import <TTSDK/TTVideoEnginePlayerDefine.h>
#else
    #error "No TTSDK distribution found"
#endif

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

@class BDLBasePlayerView;
/**
 * @locale zh
 * @type callback
 * @brief 独立播放器 view 的代理方法。
 */
/**
 * @locale en
 * @type callback
 * @brief The delegate methods for the custom player view.
 */
@protocol BDLBasePlayerViewDelegate <NSObject>

@optional

/**
 * @locale zh
 * @brief 在直播封面即将显示时，SDK 调用该方法。
 * @param basePlayerView 独立播放器 view。详见 [BDLBasePlayerView](1185540#BDLBasePlayerView)。
 * @param coverImageView 直播封面 view。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the live cover is about to appear.
 * @param basePlayerView The custom player view. For more information, see [BDLBasePlayerView](docs-bdlliveengine#BDLBasePlayerView).
 * @param coverImageView The live cover view.
 */
- (void)basePlayerView:(BDLBasePlayerView *)basePlayerView coverImageViewWillAppear:(UIImageView *)coverImageView;
/**
 * @locale zh
 * @brief 在显示直播封面时，SDK 调用该方法。
 * @param basePlayerView 独立播放器 view。详见 [BDLBasePlayerView](1185540#BDLBasePlayerView)。
 * @param coverImageView 直播封面 view。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the live cover appears.
 * @param basePlayerView The custom player view. For more information, see [BDLBasePlayerView](docs-bdlliveengine#BDLBasePlayerView).
 * @param coverImageView The live cover view.
 */
- (void)basePlayerView:(BDLBasePlayerView *)basePlayerView coverImageViewDidAppear:(UIImageView *)coverImageView;
/**
 * @locale zh
 * @brief 在直播封面即将消失时，SDK 调用该方法。
 * @param basePlayerView 独立播放器 view。详见 [BDLBasePlayerView](1185540#BDLBasePlayerView)。
 * @param coverImageView 直播封面 view。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the live cover is about to disappear.
 * @param basePlayerView The custom player view. For more information, see [BDLBasePlayerView](docs-bdlliveengine#BDLBasePlayerView).
 * @param coverImageView The live cover view.
 */
- (void)basePlayerView:(BDLBasePlayerView *)basePlayerView coverImageViewWillDisappear:(UIImageView *)coverImageView;
/**
 * @locale zh
 * @brief 在直播封面消失时，SDK 调用该方法。
 * @param basePlayerView 独立播放器 view。详见 [BDLBasePlayerView](1185540#BDLBasePlayerView)。
 * @param coverImageView 直播封面 view。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the live cover disappears.
 * @param basePlayerView The custom player view. For more information, see [BDLBasePlayerView](docs-bdlliveengine#BDLBasePlayerView).
 * @param coverImageView The live cover view.
 */
- (void)basePlayerView:(BDLBasePlayerView *)basePlayerView coverImageViewDidDisappear:(UIImageView *)coverImageView;
/**
 * @locale zh
 * @brief 在直播封面改变时，SDK 调用该方法。
 * @param url 当前的直播封面图地址。
 * @param basePlayerView 独立播放器 view。详见 [BDLBasePlayerView](1185540#BDLBasePlayerView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the live cover changes.
 * @param basePlayerView The custom player view. For more information, see [BDLBasePlayerView](docs-bdlliveengine#BDLBasePlayerView).
 * @param url The URL of the current live cover image.
 */
- (void)basePlayerView:(BDLBasePlayerView *)basePlayerView coverImageUrlDidChange:(nullable NSString *)url;
/**
 * @locale zh
 * @brief 在直播封面改变时，SDK 调用该方法。
 * @param image 当前的直播封面图。
 * @param error 错误信息。有值则新的直播封面图获取失败，继续使用之前的直播封面图。
 * @param basePlayerView 独立播放器 view。详见 [BDLBasePlayerView](1185540#BDLBasePlayerView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the live cover changes.
 * @param basePlayerView The custom player view. For more information, see [BDLBasePlayerView](docs-bdlliveengine#BDLBasePlayerView).
 * @param image The current live cover image.
 * @param error The error information. If this parameter has a value, it means that getting the new live cover image failed, and the previous cover image is used instead.
 */
- (void)basePlayerView:(BDLBasePlayerView *)basePlayerView coverImageDidChange:(nullable UIImage *)image error:(nullable NSError *)error;
/**
 * @locale zh
 * @brief 在播放内容改变时，SDK 调用该方法。
 * @param isLive 是否为直播。
 *        - `YES`：直播。
 *        - `NO`：非直播。
 * @param willPlay 是否将要播放。
 *        - `YES`：将要播放。
 *        - `NO`：未将要播放。
 * @param basePlayerView 独立播放器 view。详见 [BDLBasePlayerView](1185540#BDLBasePlayerView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the media content changes.
 * @param basePlayerView The custom player view. For more information, see [BDLBasePlayerView](docs-bdlliveengine#BDLBasePlayerView).
 * @param isLive Whether it is a live stream.
 *        - `YES`: A live stream.
 *        - `NO`: Not a live stream.
 * @param willPlay Whether the content is about to play.
 *        - `YES`: About to play.
 *        - `NO`: Not about to play.
 */
- (void)basePlayerViewPlayerItemDidChange:(BDLBasePlayerView *)basePlayerView isLive:(BOOL)isLive willPlay:(BOOL)willPlay;
/**
 * @locale zh
 * @brief 在播放器即将显示时，SDK 调用该方法。
 * @param videoView 播放器 view。
 * @param isLive 是否为直播。
 *        - `YES`：直播。
 *        - `NO`：非直播。
 * @param basePlayerView 独立播放器 view。详见 [BDLBasePlayerView](1185540#BDLBasePlayerView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the player is about to display.
 * @param basePlayerView The custom player view. For more information, see [BDLBasePlayerView](docs-bdlliveengine#BDLBasePlayerView).
 * @param videoView The player view.
 * @param isLive Whether it is a live stream.
 *        - `YES`: A live stream.
 *        - `NO`: Not a live stream.
 */
- (void)basePlayerView:(BDLBasePlayerView *)basePlayerView videoViewWillAppear:(UIView *)videoView isLive:(BOOL)isLive;
/**
 * @locale zh
 * @brief 在显示播放器时，SDK 调用该方法。
 * @param videoView 播放器 view。
 * @param isLive 是否为直播。
 *        - `YES`：直播。
 *        - `NO`：非直播。
 * @param basePlayerView 独立播放器 view。详见 [BDLBasePlayerView](1185540#BDLBasePlayerView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the player appears.
 * @param basePlayerView The custom player view. For more information, see [BDLBasePlayerView](docs-bdlliveengine#BDLBasePlayerView).
 * @param videoView The player view.
 * @param isLive Whether it is a live stream.
 *        - `YES`: A live stream.
 *        - `NO`: Not a live stream.
 */
- (void)basePlayerView:(BDLBasePlayerView *)basePlayerView videoViewDidAppear:(UIView *)videoView isLive:(BOOL)isLive;
/**
 * @locale zh
 * @brief 在播放器即将消失时，SDK 调用该方法。
 * @param videoView 播放器 view。
 * @param basePlayerView 独立播放器 view。详见 [BDLBasePlayerView](1185540#BDLBasePlayerView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the player is about to disappear.
 * @param basePlayerView The custom player view. For more information, see [BDLBasePlayerView](docs-bdlliveengine#BDLBasePlayerView).
 * @param videoView The player view.
 */
- (void)basePlayerView:(BDLBasePlayerView *)basePlayerView videoViewWillDisappear:(UIView *)videoView;
/**
 * @locale zh
 * @brief 在播放器消失时，SDK 调用该方法。
 * @param videoView 播放器 view。
 * @param basePlayerView 独立播放器 view。详见 [BDLBasePlayerView](1185540#BDLBasePlayerView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the player disappears.
 * @param basePlayerView The custom player view. For more information, see [BDLBasePlayerView](docs-bdlliveengine#BDLBasePlayerView).
 * @param videoView The player view.
 */
- (void)basePlayerView:(BDLBasePlayerView *)basePlayerView videoViewDidDisappear:(UIView *)videoView;
/**
 * @locale zh
 * @brief 在视频大小改变时，SDK 调用该方法。
 * @param videoSize 当前的视频大小。
 * @param basePlayerView 独立播放器 view。详见 [BDLBasePlayerView](1185540#BDLBasePlayerView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the video size changes.
 * @param basePlayerView The custom player view. For more information, see [BDLBasePlayerView](docs-bdlliveengine#BDLBasePlayerView).
 * @param videoSize The current video size.
 */
- (void)basePlayerView:(BDLBasePlayerView *)basePlayerView videoSizeDidChange:(CGSize)videoSize;
/**
 * @locale zh
 * @brief 在视频首帧图片渲染后调用该方法。
 * @param basePlayerView 独立播放器 view。详见 [BDLBasePlayerView](1185540#BDLBasePlayerView)。
 */
/**
 * @locale en
 * @brief Call this method after the first frame of the video is rendered.
 * @param basePlayerView The custom player view. For more information, see [BDLBasePlayerView](docs-bdlliveengine#BDLBasePlayerView).
 */
- (void)basePlayerViewOnFirstVideoFrameRendered:(BDLBasePlayerView *)basePlayerView;
/**
 * @locale zh
 * @brief 在视频支持的清晰度发生改变时，SDK 调用该方法。
 * @param supportedVideoResolutions 当前视频支持的清晰度。
 * @param currentVideoResolution 当前使用的清晰度。详见 [BDLVideoResolution](1185544#BDLVideoResolution)。
 * @param basePlayerView 独立播放器 view。详见 [BDLBasePlayerView](1185540#BDLBasePlayerView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the supported video resolutions change.
 * @param basePlayerView The custom player view. For more information, see [BDLBasePlayerView](docs-bdlliveengine#BDLBasePlayerView).
 * @param supportedVideoResolutions The currently supported video resolutions.
 * @param currentVideoResolution The currently used resolution. For more information, see [BDLVideoResolution](viewer-sdk-for-ios-type-definitions#BDLVideoResolution).
 */
- (void)basePlayerView:(BDLBasePlayerView *)basePlayerView supportedVideoResolutionsDidChange:(NSArray<NSNumber *> *)supportedVideoResolutions currentVideoResolution:(BDLVideoResolution)currentVideoResolution;
/**
 * @locale zh
 * @brief 在视频开始卡顿时，SDK 调用该方法。
 * @param basePlayerView 独立播放器 view。详见 [BDLBasePlayerView](1185540#BDLBasePlayerView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the video starts stuttering.
 * @param basePlayerView The custom player view. For more information, see [BDLBasePlayerView](docs-bdlliveengine#BDLBasePlayerView).
 */
- (void)basePlayerViewStallStart:(BDLBasePlayerView *)basePlayerView;
/**
 * @locale zh
 * @brief 在视频卡顿结束时，SDK 调用该方法。
 * @param basePlayerView 独立播放器 view。详见 [BDLBasePlayerView](1185540#BDLBasePlayerView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the video stuttering ends.
 * @param basePlayerView The custom player view. For more information, see [BDLBasePlayerView](docs-bdlliveengine#BDLBasePlayerView).
 */
- (void)basePlayerViewStallEnd:(BDLBasePlayerView *)basePlayerView;
/**
 * @locale zh
 * @brief 在观众单击播放器时，SDK 调用该方法。
 * @param basePlayerView 独立播放器 view。详见 [BDLBasePlayerView](1185540#BDLBasePlayerView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers tap the player.
 * @param basePlayerView The custom player view. For more information, see [BDLBasePlayerView](docs-bdlliveengine#BDLBasePlayerView).
 */
- (void)basePlayerViewDidSingleTap:(BDLBasePlayerView *)basePlayerView;
/**
 * @locale zh
 * @brief 在观众双击播放器时，SDK 调用该方法。
 * @param basePlayerView 独立播放器 view。详见 [BDLBasePlayerView](1185540#BDLBasePlayerView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers double-tap the player.
 * @param basePlayerView The custom player view. For more information, see [BDLBasePlayerView](docs-bdlliveengine#BDLBasePlayerView).
 */
- (void)basePlayerViewDidDoubleTap:(BDLBasePlayerView *)basePlayerView;
/**
 * @locale zh
 * @brief 在即将开启系统画中画时，SDK 调用该方法。
 * @param basePlayerView 独立播放器 view。详见 [BDLBasePlayerView](1185540#BDLBasePlayerView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the system picture-in-picture (PiP) mode is about to start.
 * @param basePlayerView The custom player view. For more information, see [BDLBasePlayerView](docs-bdlliveengine#BDLBasePlayerView).
 */
- (void)basePlayerViewWillStartPictureInPicture:(BDLBasePlayerView *)basePlayerView;
/**
 * @locale zh
 * @brief 在开启系统画中画时，SDK 调用该方法。
 * @param basePlayerView 独立播放器 view。详见 [BDLBasePlayerView](1185540#BDLBasePlayerView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the system PiP mode starts.
 * @param basePlayerView The custom player view. For more information, see [BDLBasePlayerView](docs-bdlliveengine#BDLBasePlayerView).
 */
- (void)basePlayerViewDidStartPictureInPicture:(BDLBasePlayerView *)basePlayerView;
/**
 * @locale zh
 * @brief 在开启系统画中画失败时，SDK 调用该方法。
 * @param error 失败信息。
 * @param basePlayerView 独立播放器 view。详见 [BDLBasePlayerView](1185540#BDLBasePlayerView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the system PiP mode fails to start.
 * @param basePlayerView The custom player view. For more information, see [BDLBasePlayerView](docs-bdlliveengine#BDLBasePlayerView).
 * @param error The error information.
 */
- (void)basePlayerView:(BDLBasePlayerView *)basePlayerView failedToStartPictureInPictureWithError:(NSError *)error;
/**
 * @locale zh
 * @brief 在即将停止系统画中画时，SDK 调用该方法。
 * @param basePlayerView 独立播放器 view。详见 [BDLBasePlayerView](1185540#BDLBasePlayerView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the system PiP mode is about to stop.
 * @param basePlayerView The custom player view. For more information, see [BDLBasePlayerView](docs-bdlliveengine#BDLBasePlayerView).
 */
- (void)basePlayerViewWillStopPictureInPicture:(BDLBasePlayerView *)basePlayerView;
/**
 * @locale zh
 * @brief 在结束系统画中画时，SDK 调用该方法。
 * @param basePlayerView 独立播放器 view。详见 [BDLBasePlayerView](1185540#BDLBasePlayerView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the system PiP mode stops.
 * @param basePlayerView The custom player view. For more information, see [BDLBasePlayerView](docs-bdlliveengine#BDLBasePlayerView).
 */
- (void)basePlayerViewDidStopPictureInPicture:(BDLBasePlayerView *)basePlayerView;
/**
 * @locale zh
 * @brief 在直播加载状态发生改变时，SDK 调用该方法。
 * @param basePlayerView 独立播放器 view。详见 [BDLBasePlayerView](1185540#BDLBasePlayerView)。
 * @param loadState 当前的播放器加载状态。详见 [BDLPlayerLoadState](1185544#BDLPlayerLoadState)。<br>
 *        当取值为 `BDLPlayerLoadStateError` 时，您可通过 [liveError](1185540#BDLBasePlayerView-liveerror) 获取具体的错误信息。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the live stream loading status changes.
 * @param basePlayerView The custom player view. For more information, see [BDLBasePlayerView](docs-bdlliveengine#BDLBasePlayerView).
 * @param loadState The current loading status of the player. For more information, see [BDLPlayerLoadState](viewer-sdk-for-ios-type-definitions#BDLPlayerLoadState).
 *        If the value is `BDLPlayerLoadStateError`, you can get specific error information through [liveError](docs-bdlliveengine#BDLBasePlayerView-liveerror).
 */
- (void)basePlayerView:(BDLBasePlayerView *)basePlayerView liveLoadStateDidChange:(BDLPlayerLoadState)loadState;

/**
 * @locale zh
 * @brief 在直播播放状态发生改变时，SDK 调用该方法。
 * @param basePlayerView 独立播放器 view。详见 [BDLBasePlayerView](1185540#BDLBasePlayerView)。
 * @param playbackState 当前的直播播放状态。详见 [BDLPlayerState](1185544#BDLPlayerState)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the live player status changes.
 * @param basePlayerView The custom player view. For more information, see [BDLBasePlayerView](docs-bdlliveengine#BDLBasePlayerView).
 * @param playbackState The current live player status. For more information, see [BDLPlayerState](viewer-sdk-for-ios-type-definitions#BDLPlayerState).
 */
- (void)basePlayerView:(BDLBasePlayerView *)basePlayerView livePlaybackStateDidChange:(BDLPlayerState)playbackState;
/**
 * @locale zh
 * @brief 在即将获取点播的 URL 时，SDK 调用该方法。
 * @param basePlayerView 独立播放器 view。详见 [BDLBasePlayerView](1185540#BDLBasePlayerView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the Video-on-Demand (VOD) video URL is about to be obtained.
 * @param basePlayerView The custom player view. For more information, see [BDLBasePlayerView](docs-bdlliveengine#BDLBasePlayerView).
 */
- (void)basePlayerViewWillFetchVodUrl:(BDLBasePlayerView *)basePlayerView;
/**
 * @locale zh
 * @brief 在已经获取到点播的 URL 时，SDK 调用该方法。
 * @param error 错误信息，有值则获取失败。
 * @param basePlayerView 独立播放器 view。详见 [BDLBasePlayerView](1185540#BDLBasePlayerView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the VOD video URL is obtained.
 * @param basePlayerView The custom player view. For more information, see [BDLBasePlayerView](docs-bdlliveengine#BDLBasePlayerView).
 * @param error The error information. If this parameter has a value, it means that getting the URL failed.
 */
- (void)basePlayerViewDidFetchVodUrl:(BDLBasePlayerView *)basePlayerView error:(nullable NSError *)error;
/**
 * @locale zh
 * @brief 在点播播放结束时，SDK 调用该方法。
 * @param error 错误信息，有值则播放失败。
 * @param basePlayerView 独立播放器 view。详见 [BDLBasePlayerView](1185540#BDLBasePlayerView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the VOD video finishes playing.
 * @param basePlayerView The custom player view. For more information, see [BDLBasePlayerView](docs-bdlliveengine#BDLBasePlayerView).
 * @param error The error information.  If this parameter has a value, it means that the playing failed.
 */
- (void)basePlayerView:(BDLBasePlayerView *)basePlayerView vodDidFinishWithError:(nullable NSError *)error;
/**
 * @locale zh
 * @brief 在点播加载状态发生改变时，SDK 调用该方法。
 * @param basePlayerView 独立播放器 view。详见 [BDLBasePlayerView](1185540#BDLBasePlayerView)。
 * @param loadState 当前的点播加载状态。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the VOD loading status changes.
 * @param basePlayerView The custom player view. For more information, see [BDLBasePlayerView](docs-bdlliveengine#BDLBasePlayerView).
 * @param loadState The current VOD loading status.
 */
- (void)basePlayerView:(BDLBasePlayerView *)basePlayerView vodLoadStateDidChange:(TTVideoEngineLoadState)loadState;
/**
 * @locale zh
 * @brief 在点播播放状态发生改变时，SDK 调用该方法。
 * @param basePlayerView 独立播放器 view。详见 [BDLBasePlayerView](1185540#BDLBasePlayerView)。
 * @param playbackState 当前的点播播放状态。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the VOD playback status changes.
 * @param basePlayerView The custom player view. For more information, see [BDLBasePlayerView](docs-bdlliveengine#BDLBasePlayerView).
 * @param playbackState The current VOD playback status.
 */
- (void)basePlayerView:(BDLBasePlayerView *)basePlayerView vodPlaybackStateDidChange:(TTVideoEnginePlaybackState)playbackState;
/**
 * @locale zh
 * @brief 在点播播放失败，即将重试时，SDK 调用该方法。
 * @param basePlayerView 独立播放器 view。详见 [BDLBasePlayerView](1185540#BDLBasePlayerView)。
 * @param error 错误信息。
 */
/**
 * @locale en
 * @brief The SDK calls this method when VOD playback failed and a retry is about to occur.
 * @param basePlayerView The custom player view. For more information, see [BDLBasePlayerView](docs-bdlliveengine#BDLBasePlayerView).
 * @param error The error information.
 */
- (void)basePlayerView:(BDLBasePlayerView *)basePlayerView vodRetryForError:(NSError *)error;
/**
 * @locale zh
 * @brief 在点播断点续播时，SDK 调用该方法。
 * @param playbackTime 断点续播时间，即上次播放结束的时间点。单位：秒。
 * @param basePlayerView 独立播放器 view。详见 [BDLBasePlayerView](1185540#BDLBasePlayerView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when a VOD video automatically resumes playing from the point where it stopped.
 * @param basePlayerView The custom player view. For more information, see [BDLBasePlayerView](docs-bdlliveengine#BDLBasePlayerView).
 * @param playbackTime The position to which the video seeks after automatically resuming from where it stopped. Unit: seconds.
 */
- (void)basePlayerView:(BDLBasePlayerView *)basePlayerView onVodAutoContinuePlayback:(NSTimeInterval)playbackTime;
/**
 * @locale zh
 * @brief 在观众被强制退出直播间时，SDK 调用该方法。
 * @param basePlayerView 独立播放器 view。详见 [BDLBasePlayerView](1185540#BDLBasePlayerView)。
 * @param info 观众被强制退出直播间的原因。详见 [BDLForceOfflineInfo](1185544#BDLForceOfflineInfo)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers are forcibly removed from the live room.
 * @param basePlayerView The custom player view. For more information, see [BDLBasePlayerView](docs-bdlliveengine#BDLBasePlayerView).
 * @param info The reason for viewers being forcibly removed from the live room. For more information, see [BDLForceOfflineInfo](viewer-sdk-for-ios-type-definitions#BDLForceOfflineInfo).
 */
- (void)basePlayerView:(BDLBasePlayerView *)basePlayerView onUserForceOffline:(BDLForceOfflineInfo *)info;

@end

/**
 * @locale zh
 * @type keytype
 * @brief seek 操作完成后回调。
 * @param success seek 操作是否成功。seek 操作指跳转至视频指定时间点。
 *        - `YES`：操作成功。
 *        - `NO`：操作失败。
 */
/**
 * @locale en
 * @type keytype
 * @brief The callback is triggered after the seek operation is completed.
 * @param success Whether the seek operation is successful. The seek operation refers to jumping to a specific time point in the video.<br>
 *        - `YES`: Successful.
 *        - `NO`: Failed.
 */
typedef void(^BDLBasePlayerViewSeekCompletionBlock)(BOOL success);

/**
 * @locale zh
 * @type api
 * @brief 独立播放器 view。播放器内部实现了对直播状态的监听，支持根据直播状态播放对应状态的点播或直播视频。
 */
/**
 * @locale en
 * @brief The custom player view. The player internally listens to the live room status and supports playing the corresponding VOD or live video based on the live room status.
 */
@interface BDLBasePlayerView : BDLBaseView <BDLBasicService, BDLPullStreamUrlService>

/**
 * @locale zh
 * @brief 代理方法。详见 [BDLBasePlayerViewDelegate](1185541#BDLBasePlayerViewDelegate)。
 */
/**
 * @locale en
 * @brief The delegate method. For more information, see [BDLBasePlayerViewDelegate](viewer-SDK-for-ios-callbacks#BDLBasePlayerViewDelegate).
 */
@property (nonatomic, weak) id<BDLBasePlayerViewDelegate> delegate;
/**
 * @locale zh
 * @brief 直播封面 imageView。
 */
/**
 * @locale en
 * @brief The live cover imageView.
 */
@property (nonatomic, strong, readonly) UIImageView *coverImageView;
/**
 * @locale zh
 * @brief 水印 view。
 */
/**
 * @locale en
 * @brief The watermark view.
 */
@property (nonatomic, strong, readonly) UIView *watermarkView;
/**
 * @locale zh
 * @brief 播放器 view。
 */
/**
 * @locale en
 * @brief The player view.
 */
@property (nonatomic, strong, readonly, nullable) UIView *videoView;
/**
 * @locale zh
 * @brief 视频画面的填充模式。详见 [BDLPlayerScalingMode](1185544#BDLPlayerScalingMode)。
 */
/**
 * @locale en
 * @brief The video scaling mode. For more information, see [BDLPlayerScalingMode](viewer-sdk-for-ios-type-definitions#BDLPlayerScalingMode).
 */
@property (nonatomic, assign) BDLPlayerScalingMode scalingMode;
/**
 * @locale zh
 * @brief 是否静音。
 *        - `YES`：静音。
 *        - `NO`：未静音。
 */
/**
 * @locale en
 * @brief Whether to mute the video.
 *        - `YES`: Mute.
 *        - `NO`: Do not mute.
 */
@property (nonatomic, assign) BOOL muted;
/**
 * @locale zh
 * @brief 是否禁止播放。
 *        - `YES`：禁止播放。
 *        - `NO`：未禁止播放。
 */
/**
 * @locale en
 * @brief Whether to prohibit playing the video.
 *        - `YES`: Prohibit.
 *        - `NO`: Do not prohibit.
 */
@property (nonatomic, assign) BOOL forbidPlay;
/**
 * @locale zh
 * @brief 是否开启系统画中画。
 *        - `YES`：开启系统画中画。
 *        - `NO`：未开启系统画中画。
 */
/**
 * @locale en
 * @brief Whether to enable system PiP.
 *        - `YES`: Enable.
 *        - `NO`: Disable.
 */
@property (nonatomic, assign) BOOL enablePictureInPicture API_AVAILABLE(ios(14.0));
/**
 * @locale zh
 * @brief 是否为直播。
 *        - `YES`：直播。
 *        - `NO`：非直播。
 */
/**
 * @locale en
 * @brief Whether it is a live stream.
 *        - `YES`: A live stream.
 *        - `NO`: Not a live stream.
 */
@property (nonatomic, assign, readonly) BOOL isLive;
/**
 * @locale zh
 * @brief 是否为点播。
 *        - `YES`：点播。
 *        - `NO`：非点播。
 */
/**
 * @locale en
 * @brief Whether it is a VOD video.
 *        - `YES`: A VOD video.
 *        - `NO`: Not a VOD video.
 */
@property (nonatomic, assign, readonly) BOOL isVod;
/**
 * @locale zh
 * @brief 是否正在播放。
 *        - `YES`：正在播放。
 *        - `NO`：未在播放。
 */
/**
 * @locale en
 * @brief Whether a video is playing.
 *        - `YES`: Playing.
 *        - `NO`: Not playing.
 */
@property (nonatomic, assign, readonly) BOOL isPlaying;
/**
 * @locale zh
 * @brief 播放器状态。详见 [BDLPlayerState](1185544#BDLPlayerState)。
 */
/**
 * @locale en
 * @brief The player status. For more information, see [BDLPlayerState](viewer-sdk-for-ios-type-definitions#BDLPlayerState).
 */
@property (nonatomic, assign, readonly) BDLPlayerState playerState;
/**
 * @locale zh
 * @brief 是否正在卡顿。
 *        - `YES`：正在卡顿。
 *        - `NO`：未在卡顿。
 */
/**
 * @locale en
 * @brief Whether the video is stuttering.
 *        - `YES`: Stuttering.
 *        - `NO`: Not stuttering.
 */
@property (nonatomic, assign, readonly) BOOL isStalling;
/**
 * @locale zh
 * @brief 是否已渲染视频首帧。
 *        - `YES`：已渲染。
 *        - `NO`：未渲染。
 */
/**
 * @locale en
 * @brief Whether the first frame of the video is rendered.
 *        - `YES`: Rendered.
 *        - `NO`: Not rendered.
 */
@property (nonatomic, assign, readonly) BOOL isFirstVideoFrameRendered;
/**
 * @locale zh
 * @brief 视频 size。
 */
/**
 * @locale en
 * @brief The video size.
 */
@property (nonatomic, assign, readonly) CGSize videoSize;
/**
 * @locale zh
 * @brief 当前支持的清晰度。
 */
/**
 * @locale en
 * @brief The currently supported resolutions.
 */
@property (nonatomic, copy, readonly, nullable) NSArray<NSNumber *> *supportedVideoResolutions;
/**
 * @locale zh
 * @brief 当前使用的清晰度。详见 [BDLVideoResolution](1185544#BDLVideoResolution)。
 */
/**
 * @locale en
 * @brief The currently used resolution. For more information, see [BDLVideoResolution](viewer-sdk-for-ios-type-definitions#BDLVideoResolution).
 */
@property (nonatomic, assign) BDLVideoResolution currentVideoResolution;
/**
 * @locale zh
 * @brief 播放器配置。详见 [BDLBasePlayerConfiguration](1185544#BDLBasePlayerConfiguration)。
 */
/**
 * @locale en
 * @brief The player configuration. For more information, see [BDLBasePlayerConfiguration](viewer-sdk-for-ios-type-definitions#BDLBasePlayerConfiguration).
 */
@property (nonatomic, strong, readonly) BDLBasePlayerConfiguration *config;
/**
 * @locale zh
 * @brief 直播错误信息。
 */
/**
 * @locale en
 * @brief The live error information.
 */
@property (nonatomic, strong, readonly) NSError *liveError;
/**
 * @locale zh
 * @brief 设置点播开始播放的时间。
 * @param startTime 点播开始播放的时间。单位：秒。
 * @list 播放器
 */
/**
 * @locale en
 * @brief Sets the time from which to start playing the VOD video.
 * @param startTime The time from which to start playing the VOD video. Unit: seconds.
 */
- (void)setVodStartTime:(NSTimeInterval)startTime;
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
 * @brief 停止播放。
 * @list 播放器
 */
/**
 * @locale en
 * @brief Stops playing the video.
 */
- (void)stop;
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
 * @brief 点播视频的总时长。单位：秒。
 */
/**
 * @locale en
 * @brief The total duration of the VOD video. Unit: seconds.
 */
@property (nonatomic, assign, readonly) NSTimeInterval duration;
/**
 * @locale zh
 * @brief 当前可播放的时长，即已缓存的时长。单位：秒。
 */
/**
 * @locale en
 * @brief The current playable duration, namely the cached duration. Unit: seconds.
 */
@property (nonatomic, assign, readonly) NSTimeInterval playableDuration;
/**
 * @locale zh
 * @brief 当前播放时间。单位：秒。
 */
/**
 * @locale en
 * @brief The current playback time. Unit: seconds.
 */
@property (nonatomic, assign, readonly) NSTimeInterval currentPlaybackTime;
/**
 * @locale zh
 * @brief 是否正在 seek（跳转）。
 *        - `YES`：正在 seek。
 *        - `NO`：未在 seek。
 */
/**
 * @locale en
 * @brief Whether the player is seeking to a specific time point of the video.
 *        - `YES`: Seeking.
 *        - `NO`: Not seeking.
 */
@property (nonatomic, assign, readonly) BOOL isSeeking;
/**
 * @locale zh
 * @brief 是否循环播放。
 *        - `YES`：循环播放。
 *        - `NO`：未循环播放。
 */
/**
 * @locale en
 * @brief Whether to play in a loop.
 *        - `YES`: In a loop.
 *        - `NO`: Not in a loop.
 */
@property (nonatomic, assign) BOOL looping;
/**
 * @locale zh
 * @brief 播放速度。
 */
/**
 * @locale en
 * @brief The playback speed.
 */
@property (nonatomic, assign) CGFloat playbackSpeed;
/**
 * @locale zh
 * @brief 跳转至预告或回放视频的指定时间点。
 * @param playbackTime 跳转至的时间点。单位：秒。
 * @param completion seek 操作完成后触发该回调。详见 [BDLBasePlayerViewSeekCompletionBlock](1185544#bdlbaseplayerviewseekcompletionblock)。
 * @list 播放器
 */
/**
 * @locale en
 * @brief Seeks to the specific time point of the preview or playback.
 * @param playbackTime The time point to seek to. Unit: seconds.
 * @param completion The callback triggered after the seek operation is complete. For more information, see [BDLBasePlayerViewSeekCompletionBlock](viewer-sdk-for-ios-type-definitions#bdlbaseplayerviewseekcompletionblock).
 */
- (void)seek:(NSTimeInterval)playbackTime completion:(BDLBasePlayerViewSeekCompletionBlock _Nullable)completion;
/**
 * @locale zh
 * @brief 添加周期性事件，用于定期从播放器获取数据。
 * @param interval 时间间隔。单位：秒。
 * @param queue 执行操作的目标队列。
 * @param block 需要做的周期性工作。
 * @list 播放器
 */
/**
 * @locale en
 * @brief Adds a periodic event to regularly get data from the player.
 * @param interval The time interval. Unit: seconds.
 * @param queue The target queue for executing operations.
 * @param block The periodic task to perform.
 */
- (void)addPeriodicObserverWithInterval:(NSTimeInterval)interval queue:(dispatch_queue_t)queue usingBlock:(void (^)(void))block;
/**
 * @locale zh
 * @brief 移除周期性事件。
 * @list 播放器
 */
/**
 * @locale en
 * @brief Removes the periodic event.
 */
- (void)removePeriodicObserver;
/**
 * @locale zh
 * @brief 重置当前视频的断点续播记录。
 * @list 播放器
 * @return - `YES`：重置成功。
 *         - `NO`：重置失败。
 */
/**
 * @locale en
 * @brief Resets the resume playback record for the current video.
 * @return - `YES`: Reset successfully.
 *         - `NO`: Failed to reset.
 */
- (BOOL)resetCurrentContinuePlaybackTime;

/**
 * @locale zh
 * @brief 播放器是否可见。默认值：`YES`。<br><br>
 *        - `YES`：播放器可见。播放器不可见时暂停播放的直播或点播视频会自动恢复播放。如果开启了系统画中画，在 App 切换至后台后会显示系统画中画。
 *        - `NO`：播放器不可见。即使开启了系统画中画，在 App 切换至后台后也不会显示系统画中画。同时会暂停正在播放的直播或点播视频，即使开启了自动播放，在直播状态发生变化时也不会自动播放视频。
 */
/**
 * @locale en
 * @brief Whether the player is visible. Default value: `YES`.
 *        - `YES`: Visible. When the player is invisible, the paused live or VOD video automatically resumes playing. If system PiP is enabled, the system PiP is displayed when the app switches to the background.
 *        - `NO`: Invisible. When the app switches to the background, the system PiP is not displayed even if it is enabled, and the playing live or VOD video is paused. Additionally, the video does not automatically play when the live room status changes, even if autoplay is enabled.
 */
@property (nonatomic, assign) BOOL visible;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
