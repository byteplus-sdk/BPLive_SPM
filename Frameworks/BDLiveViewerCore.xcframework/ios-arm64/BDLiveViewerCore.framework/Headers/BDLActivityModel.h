//
//  BDLActivityModel.h
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
#import <BDLiveBase/BDLBaseModel.h>
#import <BDLiveCommon/BDLBasicModel.h>
#import <BDLiveCommon/BDLMenuBarModel.h>
#import <BDLiveCommon/BDLCommentConfigModel.h>
#import "BDLPullStreamUrlModel.h"
#import <BDLiveCommon/BDLThumbUpConfigModel.h>
#import <BDLiveCommon/BDLMessageSwitchModel.h>
#import <BDLiveCommon/BDLQuestionnaireModel.h>
#import <BDLiveCommon/BDLTaskAwardConfigModel.h>
#import "BDLForceExitMessageModel.h"

/**
 * @locale zh
 * @type keytype
 * @brief 连麦状态的定义
 */
typedef NS_ENUM(NSInteger, BDLAudienceLinkEnableStatus) {
    BDLAudienceLinkEnableStatusSame = 0,
    BDLAudienceLinkEnableStatusEnable = 1,
    BDLAudienceLinkEnableStatusDisable = 2,
};

@interface BDLActivityModel : BDLBaseModel

// 活动ID
@property (nonatomic, strong) NSNumber *activityId;

// 轮询间隔 单位为秒，TTL最小为 3 秒
@property (nonatomic, assign) NSInteger TTL;

// 人数
@property (nonatomic, strong) NSNumber *virtualPeopleCount;

// 拉流地址
@property (nonatomic, copy) NSArray<BDLPullStreamUrlModel *> *pullStreamUrls;

// 基本配置
@property (nonatomic, strong) BDLBasicModel *basic;

// 点赞的配置
@property (nonatomic, strong) BDLThumbUpConfigModel *thumbUpConfig;

// 菜单栏、营销推广
@property (nonatomic, strong) BDLMenuBarModel *menuBar;

// 评论
@property (nonatomic, strong) BDLCommentConfigModel *commentConfig;
@property (nonatomic, strong) BDLMessageSwitchModel *messageSwitch;

@property (nonatomic, strong) BDLQuestionnaireModel *questionnaire;

///是否开启观众连麦(内部对后端的数据进行了处理,转成了BOOL类型)
@property (nonatomic, assign) BOOL isAudienceLinkEnable;
/// 开启观众连麦状态
@property (nonatomic, assign) BDLAudienceLinkEnableStatus audienceLinkEnableState;

/// 累计抽奖
@property (nonatomic, strong) BDLTaskAwardConfigModel *taskAwardConfig;
@property (nonatomic, assign) BOOL downgradeFlag;

/// 强制踢出相关信息
@property (nonatomic, strong) BDLForceExitMessageModel *forceExitMessage;

- (BOOL)isPullStreamUrlsEqual:(BDLActivityModel *)object;

@end
