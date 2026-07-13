//
//  BDLInteractiveToolService.h
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
#import "BDLInteractiveToolModel.h"
#import "BDLAwardUserResponse.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, BDLInteractiveToolAwardChangeType) {
    BDLInteractiveToolAwardChangeTypeNone,          ///< 没有变化，默认值
    BDLInteractiveToolAwardChangeTypeInit,          ///< 初始化的时候会调用
    BDLInteractiveToolAwardChangeTypeNewAward,      ///< 新建抽奖
    BDLInteractiveToolAwardChangeTypeStatus,        ///< 状态改变
    BDLInteractiveToolAwardChangeTypeParticipated,  ///< 参与状态改变
    BDLInteractiveToolAwardChangeTypeTotalCount,    ///< 参与人数变化
    BDLInteractiveToolAwardChangeTypeCountdown,     ///< 倒计时变化
};

typedef NS_ENUM(NSInteger, BDLInteractiveToolCheckInChangeType) {
    BDLInteractiveToolCheckInChangeTypeNone,          ///< 没有变化，默认值
    BDLInteractiveToolCheckInChangeTypeStatus,        ///< 签到状态改变
    BDLInteractiveToolCheckInChangeTypeCountdown,     ///< 签到倒计时改变
    BDLInteractiveToolCheckInChangeTypeCheckOrNot,    ///< 签到是否签到改变
};

@protocol BDLInteractiveToolService <NSObject>

@optional
/// 互动工具数据变化
/// @param interactiveTools 改变后的所有数据
- (void)interactiveToolDidChange:(NSArray<BDLInteractiveToolModel *> *)interactiveTools;

/// 抽奖变化
/// @param award 变化的抽奖，如果为空，则变化在ongoingAwards里面
/// @param changeType 变化类型，具体见 BDLInteractiveToolAwardChangeType
/// @param ongoingAwards 当前所有待开奖的抽奖, 最新发布的在最后面
- (void)interactiveToolAwardDidChange:(nullable BDLInteractiveAwardModel *)award
                           changeType:(BDLInteractiveToolAwardChangeType)changeType
                        ongoingAwards:(NSArray<BDLInteractiveAwardModel *> *)ongoingAwards;

///长连接收到新的公告
- (void)interactiveToolNewInteractiveAnnouncement:(BDLInteractiveToolModel *)interactiveToolModel announcementModel:(BDLInteractiveAnnouncementModel *)announcementModel;

///长连接收到新的投票
- (void)interactiveToolNewInteractiveVote:(BDLInteractiveToolModel *)interactiveToolModel voteModel:(BDLInteractiveVoteModel *)voteModel;

///长连接收到新的答题
- (void)interactiveToolNewInteractiveQuiz:(BDLInteractiveToolModel *)interactiveToolModel quizModel:(BDLInteractiveQuizModel *)quizModel;
/// 长连接收到签到
- (void)interactiveToolNewCheckIn:(BDLInteractiveToolModel *)interactiveToolModel checkInModel:(BDLInteractiveCheckInModel *)checkInModel;
/// 长连接收到问卷
- (void)interactiveToolNewQuestionnaire:(BDLInteractiveToolModel *)interactiveToolModel questionnaireModel:(BDLQuestionnaireModel *)questionnaireModel;

/// 答题倒计时改变了
- (void)interactiveToolQuizCountdownDidChange:(BDLInteractiveQuizModel *)quizModel;
/// 显示互动工具的答案
- (void)interactiveToolQuizShowResult:(BDLInteractiveQuizModel *)quizModel;
/**
 * @locale zh
 * @brief 签到数据发生了变化
 * @param checkInModel 倒计时变化的签到数据
 * @param changeType 改变类型，详见BDLInteractiveToolCheckInChangeType{@link BDLInteractiveToolCheckInChangeType}
 */
- (void)interactiveToolCheckInDidChange:(BDLInteractiveCheckInModel *)checkInModel changeType:(BDLInteractiveToolCheckInChangeType)changeType;

@end

NS_ASSUME_NONNULL_END
