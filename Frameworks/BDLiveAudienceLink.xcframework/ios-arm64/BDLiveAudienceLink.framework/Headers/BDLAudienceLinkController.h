//
//  BDLAudienceLinkController.h
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

#import <BDLiveViewerCore/BDLActivity.h>
#import "BDLAudienceLinkPreviewView.h"
#import "BDLAudienceLinkRemoteContainerView.h"
#import "BDLAudienceLinkEntranceView.h"
#import "BDLAudienceLinkDefines.h"
#import "BDLAudienceLinkLayoutResult.h"

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 连麦 controller。
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@interface BDLAudienceLinkController : NSObject

/**
 * @locale zh
 * @brief 弹窗显示的父 view。SDK 内部默认实现了申请连麦、等待上麦、连麦中操作界面以及退出连麦提示弹窗，弹窗会加到 `popupSuperView` 上面。
 */
@property (nonatomic, weak) UIView *popupSuperView;
/**
 * @locale zh
 * @brief 是否在连麦画面 view 中显示当前连麦观众的画面。默认值为 `NO`。<br>:::tip
 *        连麦画面 view 即展示当前连麦观众和其他连麦参与者画面的 view。<br>:::
 *        - `YES`: 在连麦画面 view 中显示。
 *        - `NO`: 在连麦本地画面预览 view 中显示。
 */
@property (nonatomic, assign) BOOL showSelfVideoInRemoteView;
/**
 * @locale zh
 * @brief 连麦用户布局信息。详见 [BDLAudienceLinkLayoutResult](1185544#BDLAudienceLinkLayoutResult)。
 */
@property (nonatomic, strong, readonly) BDLAudienceLinkLayoutResult *layout;
/**
 * @locale zh
 * @brief 新布局获取回调。
 * @param audienceLinkController `BDLAudienceLinkController` 实例。
 * @param layout 连麦布局信息。详见 [BDLAudienceLinkLayoutResult](1185544#BDLAudienceLinkLayoutResult)。
 */
@property (nonatomic, copy) void(^onNewLayout)(BDLAudienceLinkController *audienceLinkController, BDLAudienceLinkLayoutResult *layout);
/**
 * @locale zh
 * @brief 连麦入口 view，用于展示申请连麦按钮。详见 [BDLAudienceLinkEntranceView](#BDLAudienceLinkEntranceView)。
 */
@property (nonatomic, strong, readonly) BDLAudienceLinkEntranceView *entranceView;
/**
 * @locale zh
 * @brief 连麦本地画面预览 view，用于展示当前连麦观众的本地视频画面。详见 [BDLAudienceLinkPreviewView](#BDLAudienceLinkPreviewView)。
 */
@property (nonatomic, strong, readonly) BDLAudienceLinkPreviewView *previewView;
/**
 * @locale zh
 * @brief 连麦画面容器 view，用于展示当前连麦观众和其他连麦参与者的画面。详见 [BDLAudienceLinkRemoteContainerView](#BDLAudienceLinkRemoteContainerView)。
 */
@property (nonatomic, strong, readonly) BDLAudienceLinkRemoteContainerView *remoteContainerView;

/**
 * @locale zh
 * @brief 获取当前连麦状态。
 * @return 当前连麦状态。详见 [BDLAudienceLinkState](1185544#BDLAudienceLinkState)。
 */
- (BDLAudienceLinkState)getCurrentAudienceLinkState;
/**
 * @locale zh
 * @brief 本地连麦状态变化回调。
 * @param audienceLinkController `BDLAudienceLinkController` 实例。
 * @param state 当前的连麦状态。详见 [BDLAudienceLinkState](1185544#BDLAudienceLinkState)。
 */
@property (nonatomic, copy) void(^onAudienceLinkStateChangeBlock)(BDLAudienceLinkController *audienceLinkController, BDLAudienceLinkState state);
/**
 * @locale zh
 * @brief 连麦入口 view 显示回调。
 * @param audienceLinkController `BDLAudienceLinkController` 实例。
 * @param view 连麦入口 view。详见 [BDLAudienceLinkEntranceView](#BDLAudienceLinkEntranceView)。
 * @param isFromEnableChange 是否由企业直播服务端返回数据变化触发。<br>
 *        - `YES`: 是。
 *        - `NO`: 否，由用户断开连麦触发。
 */
@property (nonatomic, copy) void(^showEntranceViewBlock)(BDLAudienceLinkController *audienceLinkController, BDLAudienceLinkEntranceView *view, BOOL isFromEnableChange);
/**
 * @locale zh
 * @brief 连麦入口 view 隐藏回调。
 * @param audienceLinkController `BDLAudienceLinkController` 实例。
 * @param view 连麦入口 view，详见 [BDLAudienceLinkEntranceView](#BDLAudienceLinkEntranceView)。
 */
@property (nonatomic, copy) void(^hideEntranceViewBlock)(BDLAudienceLinkController *audienceLinkController, BDLAudienceLinkEntranceView *view);
/**
 * @locale zh
 * @brief 连麦画面容器 view 显示回调。
 * @param audienceLinkController `BDLAudienceLinkController` 实例。
 * @param remoteContainerView 连麦画面容器 view。详见[BDLAudienceLinkRemoteContainerView](#BDLAudienceLinkRemoteContainerView)。 <br>
 */
@property (nonatomic, copy) void(^showRemoteContainerViewBlock)(BDLAudienceLinkController *audienceLinkController, BDLAudienceLinkRemoteContainerView *remoteContainerView);
/**
 * @locale zh
 * @brief 连麦画面容器 view 隐藏回调。
 * @param audienceLinkController `BDLAudienceLinkController` 实例。
 * @param remoteContainerView 连麦画面容器 view。详见[BDLAudienceLinkRemoteContainerView](#BDLAudienceLinkRemoteContainerView)。
 */
@property (nonatomic, copy) void(^hideRemoteContainerViewBlock)(BDLAudienceLinkController *audienceLinkController, BDLAudienceLinkRemoteContainerView *remoteContainerView);
/**
 * @locale zh
 * @brief 连麦本地画面预览 view 显示回调。
 * @param audienceLinkController `BDLAudienceLinkController` 实例。
 * @param previewView 连麦本地画面预览 view。详见 [BDLAudienceLinkPreviewView](#BDLAudienceLinkPreviewView)。
 * @param aspectRatio 采集视频的宽高比。
 */
@property (nonatomic, copy) void(^showPreviewViewBlock)(BDLAudienceLinkController *audienceLinkController, BDLAudienceLinkPreviewView *previewView, double aspectRatio);
/**
 * @locale zh
 * @brief 连麦本地画面预览 view 隐藏回调。
 * @param audienceLinkController `BDLAudienceLinkController` 实例。
 * @param previewView 连麦本地画面预览 view。详见 [BDLAudienceLinkPreviewView](#BDLAudienceLinkPreviewView)。
 */
@property (nonatomic, copy) void(^hidePreviewViewBlock)(BDLAudienceLinkController *audienceLinkController, BDLAudienceLinkPreviewView *previewView);
/**
 * @locale zh
 * @brief 音频第一帧获取回调。
 * @param audienceLinkController `BDLAudienceLinkController` 实例。
 * @param userId 音频数据对应的连麦参与者用户 ID。
 */
@property (nonatomic, copy) void(^onFirstRemoteAudioFrameBlock)(BDLAudienceLinkController *audienceLinkController, NSString *userId);
/**
 * @locale zh
 * @brief 视频第一帧获取回调。
 * @param audienceLinkController `BDLAudienceLinkController` 实例。
 * @param userId 视频数据对应的连麦参与者用户 ID。
 */
@property (nonatomic, copy) void(^onFirstRemoteVideoFrameBlock)(BDLAudienceLinkController *audienceLinkController, NSString *userId);
/**
 * @locale zh
 * @brief 申请连麦。
 * @param enableAudio 是否开启麦克风。<br>
 *        - `YES`: 开启。
 *        - `NO`: 未开启。
 * @param enableVideo 是否开启摄像头。<br>
 *        - `YES`: 开启。默认使用前置摄像头。如需使用后置摄像头，可在调用该方法后将 [isBackCamera](#BDLAudienceLinkController-isbackcamera) 设置为 `YES`。
 *        - `NO`: 未开启。
 * @param complete 申请连麦完成回调。如成功，则 [getCurrentAudienceLinkState](#BDLAudienceLinkController-getcurrentaudiencelinkstate) 方法的返回值为 `BDLAudienceLinkStateRinging`。
 */
- (void)applyAudienceLink:(BOOL)enableAudio enableVideo:(BOOL)enableVideo complete:(void(^)(BOOL success, NSError *error))complete;
/**
 * @locale zh
 * @brief 断开连麦。
 * @param complete 断开连麦完成回调。
 */
- (void)cancelAudienceLink:(nonnull void (^)(void))complete;
/**
 * @locale zh
 * @brief 当前麦克风是否已开启。<br>
 *        - `YES`: 已开启。
 *        - `NO`: 未开启。
 */
@property (nonatomic, assign) BOOL isAudioEnable;
/**
 * @locale zh
 * @brief 当前摄像头是否已开启。<br>
 *        - `YES`: 已开启。
 *        - `NO`: 未开启。
 */
@property (nonatomic, assign) BOOL isVideoEnable;
/**
 * @locale zh
 * @brief 当前是否为后置摄像头。<br>
 *        - `YES`: 后置摄像头。
 *        - `NO`: 非后置摄像头。
 */
@property (nonatomic, assign) BOOL isBackCamera;

@end

NS_ASSUME_NONNULL_END
