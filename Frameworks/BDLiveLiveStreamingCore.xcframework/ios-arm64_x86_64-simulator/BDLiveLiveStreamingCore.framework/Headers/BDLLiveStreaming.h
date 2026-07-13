//
//  BDLLiveStreaming.h
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

#import "BDLLiveStreamingController.h"
#import "BDLLiveStreamingModel.h"
#import "BDLLiveStreamingConfiguration.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 企业直播开播 SDK 入口类。
 */
@interface BDLLiveStreaming : NSObject

/**
 * @locale zh
 * @brief 直播间配置信息。详见 [BDLLiveStreamingConfiguration](#BDLLiveStreamingConfiguration)。
 */
@property (nonatomic, strong) BDLLiveStreamingConfiguration *liveStreamingConfiguration;

/// 获取单利对象
+ (instancetype)sharedInstance;

/// 获取SDK版本号
+ (NSString *)sdkVersion;

/// 用户唯一id, 反馈问题时需要带上这个id
+ (NSString *)userUniqueId;

/// 加入直播间
/// @param model 进入直播间需要的信息，见 BDLLiveStreamingModel
/// @param success 初始化成功时回调
/// @param failure 初始化失败时回调，返回错误码及信息
- (void)joinLiveStreamingWithModel:(BDLLiveStreamingModel *)model
                           success:(void (^)(void))success
                           failure:(void (^)(NSError *error))failure;

/// 获取推流VC, 需要在joinLiveStreamingWithActivityId 成功后调用
- (BDLLiveStreamingController *)getLiveStreamingController;

/// 离开直播间
- (void)leaveLiveStreaming;

@end

NS_ASSUME_NONNULL_END
