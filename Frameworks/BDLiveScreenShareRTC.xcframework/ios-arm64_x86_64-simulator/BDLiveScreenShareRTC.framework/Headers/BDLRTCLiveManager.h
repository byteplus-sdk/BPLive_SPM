//
//  BDLRTCLiveManager.h
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

#import <BDLiveLiveStreamingCore/BDLLiveManager.h>

NS_ASSUME_NONNULL_BEGIN

@class BDLRTCLiveManager;
@protocol BDLRTCLiveManagerDelegate <BDLLiveManagerDelegate>

@optional
/// 开始了屏幕共享（收到屏幕流的数据），即将推流到CDN
- (void)RTCLiveManagerDidStartScreenShare:(BDLRTCLiveManager *)manager;
/// 结束了屏幕共享，即将停止推流到CDN
- (void)RTCLiveManagerDidEndScreenShare:(BDLRTCLiveManager *)manager;

@end

@interface BDLRTCLiveManager : BDLLiveManager

@property (nonatomic, weak) id<BDLRTCLiveManagerDelegate> delegate;

- (void)setAudioMute:(BOOL)mute;

- (void)startScreenShare API_AVAILABLE(ios(12.0));
- (void)stopScreenShare API_AVAILABLE(ios(12.0));

- (void)destroyRTCVideo;

@end

NS_ASSUME_NONNULL_END
