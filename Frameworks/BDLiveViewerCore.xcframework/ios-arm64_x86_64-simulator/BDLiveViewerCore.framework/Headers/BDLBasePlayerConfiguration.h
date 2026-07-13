//
//  BDLBasePlayerConfiguration.h
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

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type keytype
 * @brief 独立播放器配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The custom player configuration.
 */
@interface BDLBasePlayerConfiguration : NSObject

/**
 * @locale zh
 * @brief 设置是否自动播放直播。默认值：`YES`。<br>
 *        - `YES`：自动播放。
 *        - `NO`：不自动播放。
 */
/**
 * @locale en
 * @brief Whether to autoplay the live stream. Default value: `YES`.
 *        - `YES`: Autoplay.
 *        - `NO`: Do not autoplay.
 */
@property (nonatomic, assign) BOOL liveAutoPlay;
/**
 * @locale zh
 * @brief 设置是否自动播放预告。默认值：`YES`。<br>
 *        - `YES`：自动播放。
 *        - `NO`：不自动播放。
 */
/**
 * @locale en
 * @brief Whether to autoplay the preview. Default value: `YES`.
 *        - `YES`: Autoplay.
 *        - `NO`: Do not autoplay.
 */
@property (nonatomic, assign) BOOL previewAutoPlay;
/**
 * @locale zh
 * @brief 设置是否自动播放回放。默认值：`YES`。<br>
 *        - `YES`：自动播放。
 *        - `NO`：不自动播放。
 */
/**
 * @locale en
 * @brief Whether to autoplay the playback. Default value: `YES`.
 *        - `YES`: Autoplay.
 *        - `NO`: Do not autoplay.
 */
@property (nonatomic, assign) BOOL playbackAutoPlay;
/**
 * @locale zh
 * @brief 设置预告结束后是否自动重播。默认值：`YES`。<br>
 *        - `YES`：自动重播。
 *        - `NO`：不自动重播。
 */
/**
 * @locale en
 * @brief Whether to automatically replay after the preview ends. Default value: `YES`.
 *        - `YES`: Automatically replay.
 *        - `NO`: Do not automatically replay.
 */
@property (nonatomic, assign) BOOL previewAutoReplay;
/**
 * @locale zh
 * @brief 设置回放结束后是否自动重播。默认值：`YES`。<br>
 *        - `YES`：自动重播。
 *        - `NO`：不自动重播。
 */
/**
 * @locale en
 * @brief Whether to automatically replay after the playback ends. Default value: `YES`.
 *        - `YES`: Automatically replay.
 *        - `NO`: Do not automatically replay.
 */
@property (nonatomic, assign) BOOL playbackAutoReplay;
/**
 * @locale zh
 * @brief 设置是否开启点播视频的自动断点续播。默认值：`YES`。<br>
 *        - `YES`：开启。
 *        - `NO`：不开启。
 */
/**
 * @locale en
 * @brief Whether to enable automatic breakpoint resumption for VOD videos. Default value: `YES`.
 *        - `YES`: Enable.
 *        - `NO`: Disable.
 */
@property (nonatomic, assign) BOOL vodAutoContinuePlayback;
/**
 * @locale zh
 * @brief 设置直播期间遇到卡顿时，是否支持自动降级或提供提示信息。默认值为 `YES`。
 *        - `YES`：
 *          - 当 [backupDowngradeWhenStall](#BDLBasePlayerConfiguration-backupdowngradewhenstall) 取值为 `YES` 时，直接切换主备流。
 *          - 当 [backupDowngradeWhenStall](#BDLBasePlayerConfiguration-backupdowngradewhenstall) 取值为 `NO` 时，智能档位下，自动降级到较低的清晰度，如果降到最低清晰度依然卡顿，则切换主备流。非智能档位下，提示观众是否切换到较低的清晰度，观众可按需自行选择是否切换，如果观众切换到最低清晰度依然卡顿，则切换主备流。
 *        - `NO`：智能档位下，不自动降级。非智能档位下，不提示观众切换到较低的清晰度。
 */
/**
 * @locale en
 * @brief Whether to support automatic downgrade or provide a prompt in case of stuttering during the live stream. Default value: `YES`.
 *        - `YES`:
 *          - If the value of [backupDowngradeWhenStall](#BDLBasePlayerConfiguration-backupdowngradewhenstall) is `YES`, directly switch between the primary and backup streams.
 *          - If the value of [backupDowngradeWhenStall](#BDLBasePlayerConfiguration-backupdowngradewhenstall) is `NO`, in smart mode, automatically downgrade to a lower resolution. If stuttering still occurs at the lowest resolution, switch between the primary and backup streams. In non-smart mode, provide a prompt to viewers asking whether to switch to a lower resolution, allowing them to choose as needed. If stuttering still occurs after viewers switch to the lowest resolution, switch between the primary and backup streams.
 *        - `NO`: In smart mode, do not automatically downgrade. In non-smart mode, do not notify viewers to switch to a lower resolution.
 */
@property (nonatomic, assign) BOOL isNeedAutoDemote;
/**
 * @locale zh
 * @brief 设置直播期间遇到卡顿时，是否直接切换主备流。默认值为 `NO`。该属性仅在 [isNeedAutoDemote](#BDLBasePlayerConfiguration-isneedautodemote) 取值为 `YES` 时生效。
 *        - `YES`：直接切换主备流。
 *        - `NO`：智能档位下，自动降级到较低的清晰度，如果降到最低清晰度依然卡顿，则切换主备流。非智能档位下，提示观众是否切换到较低的清晰度，观众可按需自行选择是否切换，如果观众切换到最低清晰度依然卡顿，则切换主备流。
 */
/**
 * @locale en
 * @brief Whether to switch between the primary and backup streams directly in case of stuttering during the live stream. Default value: `NO`. This property takes effect only when the value of [isNeedAutoDemote](#BDLBasePlayerConfiguration-isneedautodemote) is `YES`.
 *        - `YES`: Directly switch between the primary and backup streams.
 *        - `NO`: In smart mode, automatically downgrade to a lower resolution. If stuttering still occurs at the lowest resolution, switch between the primary and backup streams. In non-smart mode, provide a prompt to viewers asking whether to switch to a lower resolution, allowing them to choose as needed. If stuttering still occurs after viewers switch to the lowest resolution, switch between the primary and backup streams.
 */
@property (nonatomic, assign) BOOL backupDowngradeWhenStall;
/**
 * @locale zh
 * @brief 在需要自定义系统媒体中心展示的信息时，SDK 调用该方法。通过调用该方法，您可以在播放器自动生成的媒体信息基础上进行修改，从而在系统媒体中心展示自定义信息。<br/>
 *        ![Image](https://p9-arcosite.byteimg.com/tos-cn-i-goo7wpa0wc/b4f963fc2bfa4d15a4a930af095ec49f~tplv-goo7wpa0wc-image.image =165x)
 * @param nowPlayingInfo 播放器自动生成的展示在系统媒体中心的信息。
 * @return 根据传入的 `nowPlayingInfo` 自定义修改后的信息，即系统媒体中心最终展示的信息。如不希望在系统媒体中心展示任何信息，可返回 `nil`。详见 [MPNowPlayingInfoCenter](https://developer.apple.com/documentation/mediaplayer/mpnowplayinginfocenter?language=objc)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when you need to customize the Now Playing information. By calling this method, you can modify the Now Playing information automatically generated by the player to display custom information.
 *        ![Image](https://p9-arcosite.byteimg.com/tos-cn-i-goo7wpa0wc/71c238a4a84348d3833ad3942d38ede2~tplv-goo7wpa0wc-image.image =238x)
 * @param nowPlayingInfo The Now Playing information automatically generated by the player.
 * @return The custom information modified based on the passed `nowPlayingInfo`, which is the final Now Playing information. If you do not want to display any information in the Now Playing information section, return `nil`. For more information, see [MPNowPlayingInfoCenter](https://developer.apple.com/documentation/mediaplayer/mpnowplayinginfocenter?language=objc).
 */
@property (nonatomic, copy, nullable) NSDictionary<NSString *, id> * _Nullable (^customizeNowPlayingInfoBlock)(NSDictionary<NSString *, id> *nowPlayingInfo);

/**
 * @locale zh
 * @brief 是否响应系统媒体中心的用户操作。<br/>
 *        ![Image](https://p9-arcosite.byteimg.com/tos-cn-i-goo7wpa0wc/b4f963fc2bfa4d15a4a930af095ec49f~tplv-goo7wpa0wc-image.image =165x)<br/>
 *        默认值为 `YES`。详见 [MPRemoteCommandCenter](https://developer.apple.com/documentation/mediaplayer/mpremotecommandcenter?language=objc)。<br/>
 *        - `YES`：响应。
 *        - `NO`：不响应。
 */
/**
 * @locale en
 * @brief Whether to respond to user actions in the Now Playing information section.
 *        Default value: `YES`. For more information, see [MPRemoteCommandCenter](https://developer.apple.com/documentation/mediaplayer/mpremotecommandcenter?language=objc).
 *        ![Image](https://p9-arcosite.byteimg.com/tos-cn-i-goo7wpa0wc/71c238a4a84348d3833ad3942d38ede2~tplv-goo7wpa0wc-image.image =238x)
 *        - `YES`: Respond.
 *        - `NO`: Do not respond.
 */
@property (nonatomic, assign) BOOL shouldHandleRemoteCommand;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
