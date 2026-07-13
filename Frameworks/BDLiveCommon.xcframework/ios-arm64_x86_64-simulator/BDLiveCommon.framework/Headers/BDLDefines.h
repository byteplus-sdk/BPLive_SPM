//
//  BDLDefines.h
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
#import <Foundation/Foundation.h>
#import <BDLiveBase/BDLBaseDefines.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

/**
 * @locale zh
 * @type keytype
 * @brief 直播间的鉴权模式。
 */
/**
 * @locale en
 * @type keytype
 * @brief The authentication mode of the live room.
 */
typedef NS_ENUM(NSInteger, BDLActivityAuthMode) {
    /**
     * @locale zh
     * @brief 未知模式。默认值。
     */
    /**
     * @locale en
     * @brief Unknown mode, which is the default value.
     */
    BDLActivityAuthModeUnknown = 0,
    /**
     * @locale zh
     * @brief 公开模式。昵称由观众输入或者由 [setNickname:complete:](#BDLUserInfoConfiguration-setnickname-complete) 方法的 `nickname` 参数传入。
     */
    /**
     * @locale en
     * @brief Public mode. The nickname is entered by the viewer or passed through the `nickname` parameter of the [setNickname:complete:](#BDLUserInfoConfiguration-setnickname-complete) method.
     */
    BDLActivityAuthModePublic = 1,
    /**
     * @locale zh
     * @brief 自定义模式。观众通过登录您的自有账号系统进入直播间。昵称从自有账号系统同步至直播间，无需观众输入。
     */
    /**
     * @locale en
     * @brief Custom mode. Viewers join the live room by logging in to your own account system. Nicknames are synchronized from your own account system to the live room, without requiring viewers to enter.
     */
    BDLActivityAuthModeCustom = 2,
};

/**
 * @locale zh
 * @type keytype
 * @brief 直播状态。
 */
/**
 * @locale en
 * @type keytype
 * @brief The live room status.
 */
typedef NS_ENUM(NSInteger, BDLActivityStatus) {
    /**
     * @locale zh
     * @brief 未知。
     */
    /**
     * @locale en
     * @brief Unknown.
     */
    BDLActivityStatusUnknown = 0,
    /**
     * @locale zh
     * @brief 直播中。
     */
    /**
     * @locale en
     * @brief Live.
     */
    BDLActivityStatusLive = 1,
    /**
     * @locale zh
     * @brief 预告。
     */
    /**
     * @locale en
     * @brief Preview.
     */
    BDLActivityStatusPreview = 2,
    /**
     * @locale zh
     * @brief 回放。
     */
    /**
     * @locale en
     * @brief Playback.
     */
    BDLActivityStatusReplay = 3,
    /**
     * @locale zh
     * @brief 已结束。
     */
    /**
     * @locale en
     * @brief Over.
     */
    BDLActivityStatusEnd = 4,
};

/**
 * @locale zh
 * @type keytype
 * @brief 播放器加载状态。
 */
/**
 * @locale en
 * @type keytype
 * @brief The loading status of the player.
 */
typedef NS_ENUM(NSInteger, BDLPlayerLoadState) {
    /**
     * @locale zh
     * @brief 未知。
     */
    /**
     * @locale en
     * @brief Unknown.
     */
    BDLPlayerLoadStateUnknown,
    /**
     * @locale zh
     * @brief 卡顿。
     */
    /**
     * @locale en
     * @brief Stuttering.
     */
    BDLPlayerLoadStateStalled,
    /**
     * @locale zh
     * @brief 可以播放，即卡顿停止。
     */
    /**
     * @locale en
     * @brief Playable, without stuttering.
     */
    BDLPlayerLoadStatePlayable,
    /**
     * @locale zh
     * @brief 加载遇到错误。
     */
    /**
     * @locale en
     * @brief An error occurred while loading.
     */
    BDLPlayerLoadStateError,
};

/**
 * @locale zh
 * @type keytype
 * @brief 播放器状态。
 */
/**
 * @locale en
 * @type keytype
 * @brief The player status.
 */
typedef NS_ENUM(NSInteger, BDLPlayerState) {
    /**
     * @locale zh
     * @brief 未知状态。
     */
    /**
     * @locale en
     * @brief Unknown.
     */
    BDLPlayerStateUnknown,
    /**
     * @locale zh
     * @brief 播放器准备完成，等待渲染。
     */
    /**
     * @locale en
     * @brief The player is ready, waiting for rendering.
     */
    BDLPlayerStatePrepared,
    /**
     * @locale zh
     * @brief 播放停止。
     */
    /**
     * @locale en
     * @brief Stop playing.
     */
    BDLPlayerStateStopped,
    /**
     * @locale zh
     * @brief 正在播放。
     */
    /**
     * @locale en
     * @brief Playing.
     */
    BDLPlayerStatePlaying,
    /**
     * @locale zh
     * @brief 播放暂停。
     */
    /**
     * @locale en
     * @brief Paused.
     */
    BDLPlayerStatePaused,
    /**
     * @locale zh
     * @brief 播放出错。
     */
    BDLPlayerStateError
    /**
     * @locale en
     * @brief Error.
     */
};

/**
 * @locale zh
 * @type keytype
 * @brief 视频画面的填充模式。
 */
/**
 * @locale en
 * @type keytype
 * @brief The video scaling mode.
 */
typedef NS_ENUM(NSInteger, BDLPlayerScalingMode) {
    /**
     * @locale zh
     * @brief 保持视频原有宽高比例填充播放器，视频的宽高会填满播放器的宽高。如果视频宽高比与播放器宽高比不同，视频会缩放显示。
     */
    /**
     * @locale en
     * @brief Fill the player and keep the video's aspect ratio. The width or height of the video fills the width or height of the player. If the aspect ratio of the video is different from that of the player, the video is scaled to fit, with no content cropping.
     */
    BDLPlayerScalingModeAspectFit,
    /**
     * @locale zh
     * @brief 保持视频原有宽高比例填充播放器，视频的宽高会填满播放器的宽高。如果视频宽高比与播放器宽高比不同，会有部分视频内容被裁剪掉。
     */
    /**
     * @locale en
     * @brief Fill the player and keep the video's aspect ratio. The width of the video fills the width of the player, and the height of the video fills the height of the player. If the aspect ratio of the video is different from that of the player, the video is cropped to fit.
     */
    BDLPlayerScalingModeAspectFill,
    /**
     * @locale zh
     * @brief 视频内容完全填充播放器，但视频宽高比可能发生变化。
     */
    /**
     * @locale en
     * @brief Fill the player with the video. The aspect ratio of the video may be changed.
     */
    BDLPlayerScalingModeFill,
};

/**
 * @locale zh
 * @type keytype
 * @brief 清晰度。
 */
/**
 * @locale en
 * @type keytype
 * @brief The video resolution.
 */
typedef NS_ENUM(NSInteger, BDLVideoResolution) {
    /**
     * @locale zh
     * @brief 未知。
     */
    BDLVideoResolutionUnknown,
    /**
     * @locale zh
     * @brief 流畅。
     */
    /**
     * @locale en
     * @brief Smooth.
     */
    BDLVideoResolutionLD,
    /**
     * @locale zh
     * @brief 标清。
     */
    /**
     * @locale en
     * @brief Standard Definition.
     */
    BDLVideoResolutionSD,
    /**
     * @locale zh
     * @brief 高清。
     */
    /**
     * @locale en
     * @brief High Definition.
     */
    BDLVideoResolutionHD,
    /**
     * @locale zh
     * @brief 超清。
     */
    /**
     * @locale en
     * @brief Ultra-High Definition.
     */
    BDLVideoResolutionUHD,
    /**
     * @locale zh
     * @brief 蓝光。
     */
    /**
     * @locale en
     * @brief Blu-ray.
     */
    BDLVideoResolutionBD,
    /**
     * @locale zh
     * @brief 原画。
     */
    /**
     * @locale en
     * @brief Original resolution.
     */
    BDLVideoResolutionOrigin,
    /**
     * @locale zh
     * @brief 智能。
     */
    /**
     * @locale en
     * @brief Smart.
     */
    BDLVideoResolutionAuto,
};

/**
 * @locale zh
 * @type keytype
 * @brief 注册状态。
 */
/**
 * @locale en
 * @type keytype
 * @brief The registration status.
 */
typedef NS_ENUM(NSInteger, BDLRegisterStatus) {
    /**
     * @locale zh
     * @brief 未注册。
     */
    /**
     * @locale en
     * @brief Unregistered.
     */
    BDLRegisterStatusUnregistered,
    /**
     * @locale zh
     * @brief 注册中。
     */
    /**
     * @locale en
     * @brief Registering.
     */
    BDLRegisterStatusRegistering,
    /**
     * @locale zh
     * @brief 已注册。
     */
    /**
     * @locale en
     * @brief Registered.
     */
    BDLRegisterStatusRegistered,
};

/**
 * @locale zh
 * @type keytype
 * @brief 连麦视频流类型。
 */
/**
 * @locale en
 * @type keytype
 * @brief Type of co-streaming video stream.
 * @hidden (iOS)
 */
typedef NS_ENUM(NSInteger, BDLAudienceLinkStreamType) {
    /**
     * @locale zh
     * @brief 摄像头。
     */
    /**
     * @locale en
     * @brief Camera.
     */
    BDLAudienceLinkStreamTypeCamera = 0,
    /**
     * @locale zh
     * @brief 屏幕。
     */
    /**
    * @locale en
    * @brief Screen.
    */
    BDLAudienceLinkStreamTypeScreen
};

/**
 * @locale zh
 * @type keytype
 * @brief 评论举报类型。
 */
/**
 * @locale en
 * @type keytype
 * @brief The comment report type.
 */
typedef NS_ENUM(NSUInteger, BDLCommentTipOffType) {
    /**
     * @locale zh
     * @brief 低俗色情。
     */
    /**
     * @locale en
     * @brief Sexual.
     */
    BDLCommentTipOffTypeVulgar = 1,
    /**
     * @locale zh
     * @brief 违法违规。
     */
    /**
     * @locale en
     * @brief Law and rule violations.
     */
    BDLCommentTipOffTypeLaws,
    /**
     * @locale zh
     * @brief 广告宣传。
     */
    /**
     * @locale en
     * @brief Advertising campaign.
     */
    BDLCommentTipOffTypeAdvertising,
    /**
     * @locale zh
     * @brief 涉嫌欺诈。
     */
    /**
     * @locale en
     * @brief Scams.
     */
    BDLCommentTipOffTypeFraud,
    /**
     * @locale zh
     * @brief 辱骂我或他人。
     */
    /**
     * @locale en
     * @brief Abusive.
     */
    BDLCommentTipOffTypeCruse,
    /**
     * @locale zh
     * @brief 教唆自杀。
     */
    /**
     * @locale en
     * @brief Suicide and self-harm.
     */
    BDLCommentTipOffTypeAbetSuicide,
    /**
     * @locale zh
     * @brief 其他。
     */
    /**
     * @locale en
     * @brief Others.
     */
    BDLCommentTipOffTypeOther = 10,
};

/**
 * @locale zh
 * @type keytype
 * @brief 消息内容类型。
 */
/**
 * @locale en
 * @type keytype
 * @brief The message content type.
 */
typedef NS_OPTIONS(NSUInteger, BDLMessageContentType) {
    /**
     * @locale zh
     * @brief 文本。
     */
    /**
     * @locale en
     * @brief Text.
     */
    BDLMessageContentTypeText = 0,
    /**
     * @locale zh
     * @brief 图片。
     */
    /**
     * @locale en
     * @brief Image.
     */
    BDLMessageContentTypeImage = 1,
};

/**
 * @locale zh
 * @type keytype
 * @brief 网络质量。
 */
/**
 * @locale en
 * @type keytype
 * @brief Network quality.
 */
typedef NS_ENUM(NSInteger, BDLNetworkQuality) {
    /**
     * @locale zh
     * @brief 未知。
     */
    /**
     * @locale en
     * @brief Unknown.
     */
    BDLNetworkQualityUnknown,
    /**
     * @locale zh
     * @brief 很好。
     */
    /**
     * @locale en
     * @brief Excellent.
     */
    BDLNetworkQualityExcellent,
    /**
     * @locale zh
     * @brief 一般。
     */
    /**
     * @locale en
     * @brief Moderate.
     */
    BDLNetworkQualityPoor,
    /**
     * @locale zh
     * @brief 差。
     */
    /**
     * @locale en
     * @brief Poor.
     */
    BDLNetworkQualityBad,
    /**
     * @locale zh
     * @brief 离线。
     */
    /**
     * @locale en
     * @brief Offline.
     */
    BDLNetworkQualityOffLine = NSIntegerMax,
};

/**
 * @locale zh
 * @type keytype
 * @brief 拖拽模式。
 */
/**
 * @locale en
 * @type keytype
 * @brief The dragging mode.
 */
typedef NS_ENUM(NSUInteger, BDLDraggingMode) {
    /**
     * @locale zh
     * @brief 不能拖拽。
     */
    /**
     * @locale en
     * @brief Cannot drag.
     */
    BDLDraggingModeDisabled,
    /**
     * @locale zh
     * @brief 正常拖拽。
     */
    /**
     * @locale en
     * @brief Free drag.
     */
    BDLDraggingModeNormal,
    /**
     * @locale zh
     * @brief 释放后还原。
     */
    /**
     * @locale en
     * @brief Restore position after release.
     */
    BDLDraggingModeRevert,
    /**
     * @locale zh
     * @brief 自动靠边。只会靠左右两边。
     */
    /**
     * @locale en
     * @brief Automatically aligns to the edges, but only to the left or right edges.
     */
    BDLDraggingModePullOver,
    /**
     * @locale zh
     * @brief 靠边时自动吸附边缘，可吸附四周。
     */
    /**
     * @locale en
     * @brief Automatically snap to the edges when aligned, and can snap to all four edges.
     */
    BDLDraggingModeAdsorb,
};

/**
 * @locale zh
 * @brief 礼物特效模式。
 * @hidden (iOS)
 */
/**
 * @locale en
 * @hidden (iOS)
 * @brief Gift display mode.
 */
typedef NS_ENUM(NSUInteger, BDLGiftShowMode) {
    /**
     * @locale zh
     * @brief 非高亮模式。
     */
    /**
     * @locale en
     * @brief Non-highlight mode.
     */
    BDLGiftShowModeNormal, ///< 打赏默认展示
    /**
     * @locale zh
     * @brief 高亮模式。
     */
    /**
     * @locale en
     * @brief Highlight mode.
     */
    BDLGiftShowModeHighlight, ///< 打赏高亮展示
};

/**
 * @locale zh
 * @brief 商品提醒类型。
 */
/**
 * @locale en
 * @hidden (iOS)
 */
typedef NS_ENUM(NSUInteger, BDLCardReminderType) {
    /**
     * @locale zh
     * @brief 无提醒。
     */
    BDLCardReminderTypeNone,
    /**
     * @locale zh
     * @brief 商品热卖提醒。
     */
    BDLCardReminderTypeHotSale,
    /**
     * @locale zh
     * @brief 商品库存提醒。
     */
    BDLCardReminderTypeStock,
};

/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
typedef NS_ENUM(NSUInteger, BDLColorThemeType) {
    BDLColorThemeTypeDark, // 暗黑
    BDLColorThemeTypeLight, // 清爽
    BDLColorThemeTypeCold, // 经典
    BDLColorThemeTypeHoliday, // 传统节庆
    BDLColorThemeTypeUnknown, // 未知
};

/**
 * @locale zh
 * @type keytype
 * @brief 直播视频流类型定义
 */
typedef NSString *BDLLiveStreamingVideoSource;
/**
 * @locale zh
 * @brief 前置摄像头
 */
OBJC_EXTERN BDLLiveStreamingVideoSource BDLLiveStreamingVideoSourceFrontCamera;
/**
 * @locale zh
 * @brief 后置摄像头
 */
OBJC_EXTERN BDLLiveStreamingVideoSource BDLLiveStreamingVideoSourceBackCamera;
/**
 * @locale zh
 * @brief 屏幕
 */
OBJC_EXTERN BDLLiveStreamingVideoSource BDLLiveStreamingVideoSourceScreen;
/**
 * @locale zh
 * @brief 外置视频数据（暂时没有）
 */
OBJC_EXTERN BDLLiveStreamingVideoSource BDLLiveStreamingVideoSourceExternal;

/**
 * @locale zh
 * @type keytype
 * @brief 推流失败原因，开播端用
 */
typedef NSString *BDLLiveStreamingPushFailReason;
/**
 * @locale zh
 * @brief 获取RTC token失败
 */
OBJC_EXTERN BDLLiveStreamingPushFailReason BDLLiveStreamingPushFailReasonGetRTCTokenFailed;
/**
 * @locale zh
 * @brief 获取推流地址失败
 */
OBJC_EXTERN BDLLiveStreamingPushFailReason BDLLiveStreamingPushFailReasonGetPushUrlFailed;
/**
 * @locale zh
 * @brief RTC进房失败
 */
OBJC_EXTERN BDLLiveStreamingPushFailReason BDLLiveStreamingPushFailReasonJoinRTCRoomFailed;
/**
 * @locale zh
 * @brief 转推失败
 */
OBJC_EXTERN BDLLiveStreamingPushFailReason BDLLiveStreamingPushFailReasonLiveTranscodingFailed;

#pragma clang diagnostic pop
