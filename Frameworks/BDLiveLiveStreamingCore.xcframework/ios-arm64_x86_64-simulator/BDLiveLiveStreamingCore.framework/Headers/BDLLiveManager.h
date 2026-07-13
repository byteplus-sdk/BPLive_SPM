//
//  BDLLiveManager.h
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
#import <BDLiveCommon/BDLDefines.h>
#import <BDLiveBase/BDLMacros.h>
#import "BDLLiveStreamUtils.h"
#import "BDLStreamingService.h"
#import <MBProgressHUD/MBProgressHUD.h>
#import <BDLiveCommon/BDLDefines.h>

NS_ASSUME_NONNULL_BEGIN

@class BDLLiveManager;
@protocol BDLLiveManagerDelegate <NSObject>

@optional
/// 点击了没有权限弹窗的取消
- (void)liveManagerDidClickNoPermissionAlertCancel:(BDLLiveManager *)manager;
/// 推流成功
- (void)liveManagerDidStartLive:(BDLLiveManager *)manager;
/// 直播结束了（停止推流成功）
- (void)liveManagerDidStopLive:(BDLLiveManager *)manager;
/// 推流错误了
- (void)liveManager:(BDLLiveManager *)manager pushFailed:(nullable BDLLiveStreamingPushFailReason)reason errorCode:(NSString *)errorCode;
/// 网络状态变化
- (void)liveManager:(BDLLiveManager *)manager networkQualityDidChange:(BDLNetworkQuality)networkQuality;

@end

@interface BDLLiveManager : NSObject

@property (nonatomic, weak) id<BDLStreamingService> svc;

@property (nonatomic, weak) id <BDLLiveManagerDelegate> delegate;

#pragma mark - device auth check

/// 检测是否有访问相机硬件的权限，如果没权限则弹窗
/// @param completion 拥有相机硬件访问权限的回调block
- (void)checkVideoPermissionAndShowAlertIfNoGranted:(void(^)(void))completion;

/// 检测是否有访问麦克风硬件的权限，如果没权限则弹窗
/// @param completion 拥有麦克风硬件访问权限的回调block
- (void)checkAudioPermissionAndShowAlertIfNoGranted:(void(^)(void))completion;

@end

NS_ASSUME_NONNULL_END
