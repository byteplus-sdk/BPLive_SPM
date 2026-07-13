//
//  BDLStreamingService.h
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
#import <BDLiveCommon/BDLSendActivityMessageResponse.h>
#import <BDLiveCommon/BDLCommentModel.h>
#import <BDLiveCommon/BDLBasicModel.h>
#import <BDLiveCommon/BDLSendMessageAtUserModel.h>
#import "BDLLiveStreamingModel.h"
#import "BDLPartnerLoginModel.h"
#import "BDLLivesaasActivityLinesModel.h"
#import <BDLiveCommon/BDLEmptyUserMessageResponse.h>
#import "BDLEmptyUserMessageRequest.h"
#import "BDLActTagListModel.h"
#import <BDLiveCommon/BDLFeatureMacros.h>
#import <BDLiveCommon/BDLCommentConfigModel.h>
#import <BDLiveBase/NSError+BDLErrorCode.h>
#if BDL_FEATURE_STREAMING_LIVE_AUDIT
#import "BDLLiveAuditResult.h"
#endif

#if BDL_SG
#import <BDLiveCommon/BDLBusinessAccountModel.h>
#endif

NS_ASSUME_NONNULL_BEGIN

@protocol BDLStreamingService <NSObject>

/// 进入直播间传进来的model
- (BDLLiveStreamingModel *)getLiveStreamingModel;
/// 直播间的信息model
- (BDLBasicModel *)getBasicModel;
#if BDL_SG
/// 用户的信息model
- (BDLBusinessAccountModel *)getAccountModel;
#endif

- (BDLCommentConfigModel *)getCommentConfigModel;

/// 获取登录信息
- (BDLPartnerLoginModel *)getPartnerLoginModel;

- (BOOL)startPollingTimerWithInterval:(NSTimeInterval)interval pullCount:(NSUInteger)pullCount;

- (void)stopPollingTimer;

/// 获取当前直播间线路信息
- (void)getActivityLineInfo:(void(^)(NSError *_Nullable error, BDLLivesaasActivityLinesModel *_Nullable lineModel))complete;

/// 搜索获取历史消息
/// @param success 成功的回调, 数据靠 BDLSCommentService 的 commentsDidChange 给出, 这个回调用于处理UI
- (void)searchMessageWithCount:(NSInteger)count
                       success:(void(^)(void))success
                       failure:(void (^)(NSError *error))failure;

// 发送消息
- (void)sendMessage:(NSString *)msg
        atUserArray:(nullable NSArray<BDLSendMessageAtUserModel *> *)atUserArray
            success:(void (^)(BDLSendActivityMessageResponse *response))success
            failure:(void (^)(NSError *error))failure;

/// 上报使用挂件
- (void)reportUsePendent;

- (void)deleteAllCommentsWithSuccess:(nullable void (^)(BDLEmptyUserMessageResult *result))success
                             failure:(nullable void (^)(NSError *error))failure;

/// 更新直播间标题/封面
- (BOOL)updateLiveName:(NSString *)name complete:(void(^)(BOOL success, NSString *errorCode))complete;
/// 更新直播间封面
- (BOOL)updateLiveCoverImage:(NSString *)imageKey complete:(void(^)(BOOL success, NSString *errorCode))complete;
- (BOOL)updateLiveVerticalCoverImage:(NSString *)imageKey complete:(void(^)(BOOL success, NSString *errorCode))complete;
/// 更新直播间描述/开关
- (BOOL)updateLiveAnnouncementEnable:(NSNumber *)isAnnouncementEnable announcement:(NSString *)announcement complete:(void(^)(BOOL success, NSString *errorCode))complete;
/// 更新直播间描述/开关
- (BOOL)updateLiveSiteTags:(NSArray<BDLActTagModel *> *)siteTags complete:(void(^)(BOOL success, NSString *errorCode))complete;

/// 更新用户信息
- (void)updateBusinessAccountInfo:(nullable NSString *)accountName
                 accountHeadImage:(nullable NSString *)accountHeadImage
           accountHeadRedirectUrl:(nullable NSString *)accountHeadRedirectUrl
               externalPlatformId:(nullable NSString *)externalPlatformId
                        extraInfo:(nullable NSString *)extraInfo
                         complete:(void (^)(BOOL success, NSString *errorCode))complete;

/// 上传图片
/// @param complete 上传完成的回调
- (void)uploadImageDatas:(NSArray<NSData *> *)imageData
                complete:(void(^)(BOOL allSuccess, NSArray<NSString *> *keyArray))complete;

- (NSArray<BDLCommentModel *> *)getCurrentCommentArray;

#if BDL_SG
/// 获取账号下的所有标签
- (void)getListSiteTag:(void(^)(NSError * _Nullable error, NSArray<BDLActTagListModel *> * _Nullable listSiteTag))complete;
#endif

#if BDL_FEATURE_STREAMING_LIVE_AUDIT

- (BDLLiveAuditModel *)popFirstLiveAuditModel;

- (NSArray<BDLLiveAuditModel *> *)liveAuditModels;

- (void)startLiveAuditTimer;

- (void)stopLiveAuditTimer;

#endif

@end

NS_ASSUME_NONNULL_END
