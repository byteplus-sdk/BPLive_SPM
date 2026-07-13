//
//  BDLInteractiveToolModel.h
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
#import <BDLiveCommon/BDLQuestionnaireModel.h>
#import "BDLVoteQuizOptionModel.h"
#import <BDLiveCommon/BDLTaskAwardConfigModel.h>

#import <CoreGraphics/CoreGraphics.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

/**
 * @locale zh
 * @type keytype
 * @brief 互动工具抽奖开奖类型。
 */
/**
 * @locale en
 * @type keytype
 * @brief The draw type for the lucky draw.
 */
typedef NS_ENUM(NSInteger, BDLInteractiveAwardType) {
    /**
     * @locale zh
     * @brief 自动开奖。
     */
    /**
     * @locale en
     * @brief Automatic draw.
     */
    BDLInteractiveAwardTypeAuto = 1,
    /**
     * @locale zh
     * @brief 手动开奖。
     */
    /**
     * @locale en
     * @brief Manual draw.
     */
    BDLInteractiveAwardTypeManual,
};

/**
 * @locale zh
 * @type keytype
 * @brief 抽奖状态。
 */
/**
 * @locale en
 * @type keytype
 * @brief The lucky draw status.
 */
typedef NS_ENUM(NSInteger, BDLInteractiveAwardStatus) {
    /**
     * @locale zh
     * @brief 待开奖。
     */
    /**
     * @locale en
     * @brief Pending draw.
     */
    BDLInteractiveAwardStatusIng = 2,
    /**
     * @locale zh
     * @brief 已开奖。
     */
    /**
     * @locale en
     * @brief Prize drawn.
     */
    BDLInteractiveAwardStatusOpened = 4,
    /**
     * @locale zh
     * @brief 撤回。
     */
    /**
     * @locale en
     * @brief Withdrawn.
     */
    BDLInteractiveAwardStatusWithdraw = 7,
    /**
     * @locale zh
     * @brief 开奖中。
     */
    /**
     * @locale en
     * @brief Drawing in progress.
     */
    BDLInteractiveAwardStatusLottery = 8,
    /**
     * @locale zh
     * @brief 等待开奖。此时服务端已开奖，用于本地延时开奖。
     */
    /**
     * @locale en
     * @brief Waiting for the prize to be drawn, for local delayed drawing. The BytePlus Live server has already drawn the prize.
     */
    BDLInteractiveAwardStatusWaitingOpen = NSIntegerMax,
};
/**
 * @locale zh
 * @brief 抽奖奖品类型。
 */
/**
 * @locale en
 * @brief The prize type of lucky draws.
 */
typedef NS_ENUM(NSInteger, BDLInteractiveAwardItemType) {
    /**
     * @locale zh
     * @brief 实物奖品。
     */
    /**
     * @locale en
     * @brief Physical prizes.
     */
    BDLInteractiveAwardItemTypeInKind = 1,
    /**
     * @locale zh
     * @brief 虚拟奖品。
     */
    /**
     * @locale en
     * @brief Virtual prizes.
     */
    BDLInteractiveAwardItemTypeTheoretical = 2,
    /**
     * @locale zh
     * @brief 自定义奖品，即卡券奖品或积分奖品。
     */
    /**
     * @locale en
     * @brief Custom prizes.
     */
    BDLInteractiveAwardItemTypeCustom = 3,
    /**
     * @locale zh
     * @brief 奖券奖品。
     */
    /**
     * @locale en
     * @brief Voucher prizes.
     */
    BDLInteractiveAwardItemTypeMillions = 4,
};

/**
 * @locale zh
 * @brief 抽奖主题。
 */
/**
 * @locale en
 * @brief Lucky draw theme.
 * @hidden (iOS)
 */
typedef NS_ENUM(NSInteger, BDLAwardThemeType) {
    /**
     * @locale zh
     * @brief 默认黑白皮肤 + 大转盘开奖动画。
     */
    /**
     * @locale en
     * @brief Default black and white theme + big wheel lottery animation.
     */
    BDLAwardThemeTypeBigTurntable = 1,
    /**
     * @locale zh
     * @brief 亮暖色皮肤 + 拉霸机开奖动画。
     */
    /**
     * @locale en
     * @brief Bright warm skin + slot machine draw animation.
     */
    BDLAwardThemeTypeSlotMachine = 2,
    /**
     * @locale zh
     * @brief 暗紫色皮肤 + 开奖箱开奖动画。
     */
    /**
     * @locale en
     * @brief Dark purple skin + prize box opening animation.
     */
    BDLAwardThemeTypeLotteryBox = 3,
    /**
     * @locale zh
     * @brief 默认黑白皮肤 + 无开奖动画。
     */
    /**
     * @locale en
     * @brief Default black and white theme + no prize draw animations.
     */
    BDLAwardThemeTypeNoAnimation = 4,
};

/**
 * @locale zh
 * @type keytype
 * @brief 签到状态。
 * @hidden (Windows,Linux,macOS,iOS,Android)
 */
/**
 * @locale en
 * @type keytype
 * @hidden (Windows,Linux,macOS,iOS,Android)
 */
typedef NS_ENUM(NSInteger, BDLInteractiveCheckInStatus) {
    /**
     * @locale zh
     * @brief 未知。
     */
    BDLInteractiveCheckInStatusUnknown = 0,
    /**
     * @locale zh
     * @brief 签到中。
     */
    BDLInteractiveCheckInStatusIng,
    /**
     * @locale zh
     * @brief 已截止。
     */
    BDLInteractiveCheckInStatusTerminate,
    /**
     * @locale zh
     * @brief 已删除。
     */
    BDLInteractiveCheckInStatusDeleted,
    /**
     * @locale zh
     * @brief 已撤回。
     */
    BDLInteractiveCheckInStatusWithdraw,
};

/**
 * @locale zh
 * @brief 抽奖配置。
 */
/**
 * @locale en
 * @brief The lucky draw configuration.
 */
@interface BDLAwardItemConfig : BDLBaseModel

/**
 * @locale zh
 * @brief 抽奖 ID。
 */
/**
 * @locale en
 * @brief The lucky draw ID.
 */
@property (nonatomic, strong) NSNumber *awardId;
/**
 * @locale zh
 * @brief 抽奖名称。
 */
/**
 * @locale en
 * @brief The lucky draw name.
 */
@property (nonatomic, copy) NSString *awardItemName;
/**
 * @locale zh
 * @brief 奖品数量。
 */
/**
 * @locale en
 * @brief The number of prizes.
 */
@property (nonatomic, assign) int awardItemCount;
/**
 * @locale zh
 * @brief 奖品类型。详见 [BDLInteractiveAwardItemType](#BDLInteractiveAwardItemType)。
 */
/**
 * @locale en
 * @brief The prize type. For more information, see [BDLInteractiveAwardItemType](#BDLInteractiveAwardItemType).
 */
@property (nonatomic, assign) BDLInteractiveAwardItemType awardItemType;
/**
 * @locale zh
 * @brief 抽奖图标。
 */
/**
 * @locale en
 * @brief The lucky draw icon.
 */
@property (nonatomic, copy) NSString *awardItemIcon;
/**
 * @locale zh
 * @brief 奖券奖品的领奖链接。
 * @hidden (iOS)
 */
/**
 * @locale en
 * @hidden (iOS)
 * @brief The prize collection link for the lottery rewards.
 */
@property (nonatomic, copy) NSString *awardLotteryTicketAddr;
/**
 * @locale zh
 * @hidden (iOS)
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@property (nonatomic, assign) int awardItemAmounts;
/**
 * @locale zh
 * @hidden (iOS)
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@property (nonatomic, copy) NSString *awardItemNum;
/**
 * @locale zh
 * @brief 开奖方式。
 * @hidden (iOS)
 */
/**
 * @locale en
 * @hidden (iOS)
 * @brief Drawing method.
 */
@property (nonatomic, assign) NSString *deliveryMethod;
/**
 * @locale zh
 * @brief 抽奖中奖人填写信息类型。详见 [BDLAwardContactOptions](1185544#BDLAwardContactOptions)。
 */
/**
 * @locale en
 * @brief The information type that winners must enter. For more information, see [BDLAwardContactOptions](viewer-sdk-for-ios-type-definitions#BDLAwardContactOptions).
 */
@property (nonatomic, assign) BDLAwardContactOptions contactOptions;

@end

/**
 * @locale zh
 * @brief 抽奖参与条件。
 */
/**
 * @locale en
 * @brief The conditions for participating in lucky draws.
 */
@interface BDLAwardCondition : BDLBaseModel
/**
 * @locale zh
 * @brief 签到条件，包含提交全部签到和至少提交签到个数。
 */
/**
 * @locale en
 * @brief The check-in condition, including submitting all check-ins and submitting at least the specified number of check-ins.
 */
@property (nonatomic, copy) NSString *checkIn;
/**
 * @locale zh
 * @brief 问卷条件，包含提交全部问卷和至少提交问卷个数。
 */
/**
 * @locale en
 * @brief The questionnaire condition, including submitting all questionnaires and submitting at least the specified number of questionnaires.
 */
@property (nonatomic, copy) NSString *questionnaire;
/**
 * @locale zh
 * @brief 提交答题条件，包含提交全部答题和至少提交答题个数。
 */
/**
 * @locale en
 * @brief The quiz condition, including submitting all quizzes and submitting at least the specified number of quizzes.
 */
@property (nonatomic, copy) NSString *quiz;
/**
 * @locale zh
 * @brief 答对答题条件，包含答对全部答题和至少答对答题个数。
 */
/**
 * @locale en
 * @brief The quiz condition, including correctly answering all quizzes and correctly answering at least the specified number of quizzes.
 */
@property (nonatomic, copy) NSString *rightQuiz;
/**
 * @locale zh
 * @brief 投票条件，包含提交全部投票和至少提交投票个数。
 */
/**
 * @locale en
 * @brief The vote condition, including submitting all votes and submitting at least the specified number of votes.
 */
@property (nonatomic, copy) NSString *vote;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 带倒计时的互动工具 Model 的父类。
 */
/**
 * @locale en
 * @type keytype
 * @brief The parent class of the model for interaction tools with countdown.
 */
@interface BDLInteractiveCountdownBaseModel : BDLBaseModel

/**
 * @locale zh
 * @brief 截止时间。单位：秒。
 */
/**
 * @locale en
 * @brief The deadline. Unit: seconds.
 */
@property (nonatomic, assign) NSInteger deadline;
/**
 * @locale zh
 * @brief 发送时间。Unix 秒级时间戳。
 */
/**
 * @locale en
 * @brief The send time in Unix timestamp format. Unit: seconds.
 */
@property (nonatomic, assign) NSInteger sendTime;
/**
 * @locale zh
 * @brief 倒计时剩余时长。单位：秒。非企业直播服务端返回数据。
 */
/**
 * @locale en
 * @brief The remaining countdown time. Unit: seconds. Not returned by the BytePlus Live server.
 */
@property (nonatomic, assign) NSInteger countdown;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 实时抽奖 Model。
 */
/**
 * @locale en
 * @type keytype
 * @brief The model of real-time lucky draws.
 */
@interface BDLInteractiveAwardModel : BDLInteractiveCountdownBaseModel

/**
 * @locale zh
 * @brief 奖品名称。
 */
/**
 * @locale en
 * @brief The prize name.
 */
@property (nonatomic, copy) NSString *name;
/**
 * @locale zh
 * @brief 开奖类型。详见 [BDLInteractiveAwardType](#BDLInteractiveAwardType)。
 */
/**
 * @locale en
 * @brief The draw method. For more information, see [BDLInteractiveAwardType](#BDLInteractiveAwardType).
 */
@property (nonatomic, assign) BDLInteractiveAwardType awardType;
/**
 * @locale zh
 * @brief 弹幕口令。部分抽奖参与时会自动发送弹幕。
 */
/**
 * @locale en
 * @brief The bullet comment, which is automatically sent by viewers when they participate in some lucky draws.
 */
@property (nonatomic, copy) NSString *barragePwd;
/**
 * @locale zh
 * @brief 抽奖 ID。
 */
/**
 * @locale en
 * @brief The lucky draw ID.
 */
@property (nonatomic, strong) NSNumber *awardId;
/**
 * @locale zh
 * @brief 参与人数。
 */
/**
 * @locale en
 * @brief The number of participants.
 */
@property (nonatomic, assign) NSInteger totalCount;
/**
 * @locale zh
 * @brief 抽奖状态。详见 [BDLInteractiveAwardStatus](#BDLInteractiveAwardStatus)。
 */
/**
 * @locale en
 * @brief The lucky draw status. For more information, see [BDLInteractiveAwardStatus](#BDLInteractiveAwardStatus).
 */
@property (nonatomic, assign) BDLInteractiveAwardStatus status;
/**
 * @locale zh
 * @brief 是否显示参与人数。<br>
 *        - `YES`：显示。
 *        - `NO`：未显示。
 */
/**
 * @locale en
 * @brief Whether to display the number of participants.
 *        - `YES`: Display.
 *        - `NO`: Do not display.
 */
@property (nonatomic, assign) BOOL showPeopleNumber;
/**
 * @locale zh
 * @brief 奖品数量。
 */
/**
 * @locale en
 * @brief The number of prizes.
 */
@property (nonatomic, assign) NSInteger awardNum;
/**
 * @locale zh
 * @brief 中奖人填写信息类型。详见 [BDLAwardContactOptions](#BDLAwardContactOptions)。
 */
/**
 * @locale en
 * @brief The type of information that winners must enter. For more information, see [BDLAwardContactOptions](#BDLAwardContactOptions).
 */
@property (nonatomic, assign) BDLAwardContactOptions contactOptions;

/**
 * @locale zh
 * @brief 抽奖图标。
 */
/**
 * @locale en
 * @brief The lucky draw icon.
 */
@property (nonatomic, copy) NSString *awardIcon;
/**
 * @locale zh
 * @brief 奖品类型。详见 [BDLInteractiveAwardItemType](1185540#BDLInteractiveAwardItemType)。
 */
/**
 * @locale en
 * @brief The prize type. For more information, see [BDLInteractiveAwardItemType](docs-bdlliveengine#BDLInteractiveAwardItemType).
 */
@property (nonatomic, assign) BDLInteractiveAwardItemType awardItemType;
/**
 * @locale zh
 * @brief 抽奖参与条件。详见 [BDLAwardCondition](1185540#BDLAwardCondition)。
 */
/**
 * @locale en
 * @brief The conditions for participating in the lucyky draw. For more information, see [BDLAwardCondition](docs-bdlliveengine#BDLAwardCondition).
 */
@property (nonatomic, strong) BDLAwardCondition *awardCondition;
/**
 * @locale zh
 * @brief 是否隐藏每个奖品的数量。<br>
 *        - `YES`：隐藏。
 *        - `NO`：未隐藏。
 */
/**
 * @locale en
 * @brief Whether to hide the number of each prize.
 *        - `YES`: Hide.
 *        - `NO`: Do not hide.
 */
@property (nonatomic, assign) BOOL isHideAwardNum;
/**
 * @locale zh
 * @brief 抽奖配置。详见 [BDLAwardItemConfig](1185540#BDLAwardItemConfig)。
 */
/**
 * @locale en
 * @brief The lucky draw configuration. For more information, see [BDLAwardItemConfig](docs-bdlliveengine#BDLAwardItemConfig).
 */
@property (nonatomic, strong) NSArray<BDLAwardItemConfig *> *awardItemConfigs;
/**
 * @locale zh
 * @brief 抽奖主题。详见 [BDLAwardThemeType](1185540#BDLAwardThemeType)。
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@property (nonatomic, assign) BDLAwardThemeType awardThemeUrl;
/**
 * @locale zh
 * @brief 奖券奖品领奖链接。
 */
/**
 * @locale en
 * @brief The claim link for voucher prizes.
 */
@property (nonatomic, strong) NSString *awardLotteryTicketAddr;

/**
 * @locale zh
 * @brief 是否参与了抽奖。
 *        - `YES`：参与了。
 *        - `NO`：未参与。
 */
/**
 * @locale en
 * @brief Whether the viewer participated in the lucky draw.<br>
 *        - `YES`: Participated.
 *        - `NO`: Not participated.
 */
@property (nonatomic, assign) BOOL participated;
/**
 * @locale zh
 * @brief 抽奖倒计时时间。单位为秒。
 */
/**
 * @locale en
 * @brief The countdown time of the lucky draw. Unit: seconds.
 */
@property (nonatomic, assign) NSInteger deadlineSecond;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 互动工具公告 Model。
 */
/**
 * @locale en
 * @type keytype
 * @brief The announcement model.
 */
@interface BDLInteractiveAnnouncementModel : BDLBaseModel
/**
 * @locale zh
 * @brief 公告 ID。
 */
/**
 * @locale en
 * @brief The announcement ID.
 */
@property (nonatomic, assign) NSInteger announcementId;
/**
 * @locale zh
 * @brief 公告标题。
 */
/**
 * @locale en
 * @brief The announcement title.
 */
@property (nonatomic, copy) NSString *title;
/**
 * @locale zh
 * @brief 公告内容。
 */
/**
 * @locale en
 * @brief The announcement content.
 */
@property (nonatomic, copy) NSString *content;
/**
 * @locale zh
 * @brief 发送时间。Unix 秒级时间戳。
 */
/**
 * @locale en
 * @brief The send time in Unix timestamp format. Unit: seconds.
 */
@property (nonatomic, assign) NSInteger sendTime;
/**
 * @locale zh
 * @brief 互动工具菜单下展示的 `content` 的纯文字内容。非企业直播服务端返回数据。
 */
/**
 * @locale en
 * @brief The text of the `content` displayed under the menu for interaction tools. Not returned by the BytePlus Live server.
 */
@property (nonatomic, copy) NSString *contentString;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 互动工具投票 Model。
 */
/**
 * @locale en
 * @type keytype
 * @brief The vote model.
 */
@interface BDLInteractiveVoteModel : BDLBaseModel
/**
 * @locale zh
 * @brief 投票截止时间。Unix 秒级时间戳。
 */
/**
 * @locale en
 * @brief The voting deadline in Unix timestamp format. Unit: seconds.
 */
@property (nonatomic, assign) NSInteger deadline;
/**
 * @locale zh
 * @brief 投票标题。
 */
/**
 * @locale en
 * @brief The vote title.
 */
@property (nonatomic, copy) NSString *title;
/**
 * @locale zh
 * @brief 投票 ID。
 */
/**
 * @locale en
 * @brief The vote ID.
 */
@property (nonatomic, copy) NSString *voteId;
/**
 * @locale zh
 * @brief 当前观众是否已经投票。
 *        - `YES`：已投票。
 *        - `NO`：未投票。
 */
/**
 * @locale en
 * @brief Whether the current viewer has submitted the vote.
 *        - `YES`: Submitted.
 *        - `NO`: Not submitted.
 */
@property (nonatomic, assign) BOOL userVotedStatus;

@end

/**
 * @locale zh
 * @brief 观众签到状态。
 * @hidden (Windows,Linux,macOS,Android,iOS)
 */
/**
 * @locale en
 * @hidden (iOS)
 */
typedef NS_ENUM(NSInteger, BDLInteractiveCheckInCheckStatus) {
    /**
     * @locale zh
     * @brief 未知。SDK 获取到签到 Model 但未获取到观众签到状态。
     */
    BDLInteractiveCheckInCheckStatusUnknown = 0,
    /**
     * @locale zh
     * @brief SDK 正在获取观众签到状态。
     */
    BDLInteractiveCheckInCheckStatusGetting,
    /**
     * @locale zh
     * @brief 已签到。
     */
    BDLInteractiveCheckInCheckStatusChecked,
    /**
     * @locale zh
     * @brief 未签到。
     */
    BDLInteractiveCheckInCheckStatusUnchecked,
};
/**
 * @locale zh
 * @type keytype
 * @brief 互动工具签到 Model。
 * @hidden (Windows,Linux,macOS,iOS,Android)
 */
/**
 * @locale en
 * @type keytype
 * @hidden (Windows,Linux,macOS,iOS,Android)
 */
@interface BDLInteractiveCheckInModel : BDLInteractiveCountdownBaseModel

/**
 * @locale zh
 * @brief 签到 ID。
 */
@property (nonatomic, copy) NSString *checkInId;
/**
 * @locale zh
 * @brief 签到标题。
 */
@property (nonatomic, copy) NSString *checkInName;
/**
 * @locale zh
 * @brief 签到状态。详见 [BDLInteractiveCheckInStatus](#BDLInteractiveCheckInStatus)。<br>
 *         :::tip
 *        服务端返回的 String 类型转换为枚举值。<br>
 *         :::
 */
@property (nonatomic, assign) BDLInteractiveCheckInStatus status;
/**
 * @locale zh
 * @brief 签到所属的直播间活动 ID。
 */
@property (nonatomic, strong) NSNumber *activityId;
/**
 * @locale zh
 * @brief 是否需要填写签到信息。取值如下：<br>
 *        - `YES`：需要。
 *        - `NO`：不需要。
 */
@property (nonatomic, assign) BOOL needPersonInfo;
/**
 * @locale zh
 * @brief 签到信息的提示文案。
 */
@property (nonatomic, copy) NSString *checkInInfo;
/**
 * @locale zh
 * @brief 签到开始时间。Unix 时间戳，单位为秒。
 */
@property (nonatomic, assign) NSInteger startTime;
/**
 * @locale zh
 * @brief 签到倒计时时间。单位为秒。
 */
@property (nonatomic, assign) NSInteger deadlineSecond;
/**
 * @locale zh
 * @brief 签到后是否发送评论。取值如下：<br>
 *        - `YES`：发送。
 *        - `NO`：不发送。
 */
@property (nonatomic, assign) BOOL isSendComment;
/**
 * @locale zh
 * @brief 签到后发送评论的发送文案。
 */
@property (nonatomic, copy) NSString *commentContent;
/**
 * @locale zh
 * @brief 如果观众未按时完成签到，是否会被直接踢出直播间。取值如下：<br>
 *        - `YES`：观众会被直接踢出直播间，无法继续观看。
 *        - `NO`：观众不会被踢出直播间，可继续观看。
 */
@property (nonatomic, assign) BOOL cannotWatchLiveWhenNotCheckIn;
/**
 * @locale zh
 * @brief 踢出提示。不支持多语言。
 */
/**
 * @locale en
 * @brief Kick out prompt.
 * @hidden (iOS)
 */
@property (nonatomic, copy) NSString *cannotWatchLivePrompt;
/**
 * @locale zh
 * @brief 观众签到状态。详见 [BDLInteractiveCheckInCheckStatus](1185540#BDLInteractiveCheckInCheckStatus)。非企业直播服务端返回数据。
 */
@property (nonatomic, assign) BDLInteractiveCheckInCheckStatus localCheckInStatus;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 答题状态。
 */
/**
 * @locale en
 * @type keytype
 * @brief The quiz status.
 */
typedef NS_ENUM(NSInteger, BDLInteractiveQuizStatus) {
    /**
     * @locale zh
     * @brief 初始化。
     */
    /**
     * @locale en
     * @brief Initializing.
     */
    BDLInteractiveQuizStatusInit = 0,
    /**
     * @locale zh
     * @brief 发送。
     */
    /**
     * @locale en
     * @brief Sent.
     */
    BDLInteractiveQuizStatusSend,
    /**
     * @locale zh
     * @brief 手动公布答案。
     */
    /**
     * @locale en
     * @brief Answer manually announced.
     */
    BDLInteractiveQuizStatusManual,
    /**
     * @locale zh
     * @brief 结束。
     */
    /**
     * @locale en
     * @brief Ended.
     */
    BDLInteractiveQuizStatusEnd,
    /**
     * @locale zh
     * @brief 删除。
     */
    /**
     * @locale en
     * @brief Deleted.
     */
    BDLInteractiveQuizStatusDelete,
    /**
     * @locale zh
     * @brief 撤回。
     */
    /**
     * @locale en
     * @brief Withdrawn.
     */
    BDLInteractiveQuizStatusRevoke,
};

/**
 * @locale zh
 * @type keytype
 * @brief 答题公布答案时机。
 */
/**
 * @locale en
 * @type keytype
 * @brief The timing for announcing the quiz answer.
 */
typedef NS_ENUM(NSInteger, BDLInteractiveQuizResultType) {
    /**
     * @locale zh
     * @brief 提交后自动公布答案。
     */
    /**
     * @locale en
     * @brief The answer is announced automatically after submission.
     */
    BDLInteractiveQuizResultTypeSubmit = 0,
    /**
     * @locale zh
     * @brief 答题时间结束自动公布答案。
     */
    /**
     * @locale en
     * @brief The answer is announced automatically when the time limit ends.
     */
    BDLInteractiveQuizResultTypeDeadline,
    /**
     * @locale zh
     * @brief 手动公布答案。
     */
    /**
     * @locale en
     * @brief The answer is announced manually.
     */
    BDLInteractiveQuizResultTypeManual,
};

/**
 * @locale zh
 * @type keytype
 * @brief 答题题目类型。
 */
/**
 * @locale en
 * @type keytype
 * @brief The quiz type.
 */
typedef NS_ENUM(NSInteger, BDLInteractiveQuizTitleType) {
    /**
     * @locale zh
     * @brief 单选。
     */
    /**
     * @locale en
     * @brief Choose one.
     */
    BDLInteractiveQuizTitleTypeSingle = 0,
    /**
     * @locale zh
     * @brief 多选。
     */
    /**
     * @locale en
     * @brief Choose all that apply.
     */
    BDLInteractiveQuizTitleTypeMultiple,
};

/**
 * @locale zh
 * @type keytype
 * @brief 答题 Model。
 */
/**
 * @locale en
 * @type keytype
 * @brief The quiz model.
 */
@interface BDLInteractiveQuizModel : BDLInteractiveCountdownBaseModel

/**
 * @locale zh
 * @brief 答题标题。
 */
/**
 * @locale en
 * @brief The quiz title.
 */
@property (nonatomic, copy) NSString *quizTitle;
/**
 * @locale zh
 * @brief 答题 ID。
 */
/**
 * @locale en
 * @brief The quiz ID.
 */
@property (nonatomic, strong) NSNumber *quizID;
/**
 * @locale zh
 * @brief 答题对应的直播间活动 ID。
 */
/**
 * @locale en
 * @brief The activity ID of the live room corresponding to the quiz.
 */
@property (nonatomic, strong) NSNumber *activityID;
/**
 * @locale zh
 * @brief 答题公布答案时机。详见 [BDLInteractiveQuizResultType](#BDLInteractiveQuizResultType)。
 */
/**
 * @locale en
 * @brief The timing for announcing the answer. For more information, see [BDLInteractiveQuizResultType](#BDLInteractiveQuizResultType).
 */
@property (nonatomic, assign) BDLInteractiveQuizResultType quizResultType;
/**
 * @locale zh
 * @brief 答题题目类型。详见 [BDLInteractiveQuizTitleType](#BDLInteractiveQuizTitleType)。
 */
/**
 * @locale en
 * @brief The quiz type. For more information, see [BDLInteractiveQuizTitleType](#BDLInteractiveQuizTitleType).
 */
@property (nonatomic, assign) BDLInteractiveQuizTitleType quizTitleType;
/**
 * @locale zh
 * @brief 答题状态。详见 [BDLInteractiveQuizStatus](#BDLInteractiveQuizStatus)。
 */
/**
 * @locale en
 * @brief The quiz status. For more information, see [BDLInteractiveQuizStatus](#BDLInteractiveQuizStatus).
 */
@property (nonatomic, assign) BDLInteractiveQuizStatus quizStatus;
/**
 * @locale zh
 * @brief 答题选项。详见 [BDLVoteQuizOptionModel](#BDLVoteQuizOptionModel)。
 */
/**
 * @locale en
 * @brief The options. For more information, see [BDLVoteQuizOptionModel](#BDLVoteQuizOptionModel).
 */
@property (nonatomic, copy) NSArray<BDLVoteQuizOptionModel *> *quizOptions;

/**
 * @locale zh
 * @brief 答题正确答案，对应 [optionsite](#BDLVoteQuizOptionModel-optionsite)。
 */
/**
 * @locale en
 * @brief The correct answer, which corresponds to the [optionsite](#BDLVoteQuizOptionModel-optionsite).
 */
@property (nonatomic, copy) NSArray<NSString *> *rightOptions;
/**
 * @locale zh
 * @brief 是否答题正确。
 *        - `YES`：正确。
 *        - `NO`：错误。
 */
/**
 * @locale en
 * @brief Whether the answer is correct.<br>
 *        - `YES`: Correct.
 *        - `NO`: Incorrect.
 */
@property (nonatomic, assign) BOOL isRight;
/**
 * @locale zh
 * @brief 当前观众选择的选项。
 */
/**
 * @locale en
 * @brief The option selected by the viewer.
 */
@property (nonatomic, copy) NSArray<NSString *> *submitOptions;
/**
 * @locale zh
 * @brief 答案解析。
 */
/**
 * @locale en
 * @brief The answer explanation.
 */
@property (nonatomic, copy) NSString *quizAnalysis;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 互动工具内容类型。
 */
/**
 * @locale en
 * @type keytype
 * @brief The content type of interaction tools.
 */
typedef NS_ENUM(NSInteger, BDLInteractiveContextType) {
    /**
     * @locale zh
     * @brief 文字。
     */
    /**
     * @locale en
     * @brief Text.
     */
    BDLInteractiveContextTypeText = 1,
    /**
     * @locale zh
     * @brief 图片。
     */
    /**
     * @locale en
     * @brief Image.
     */
    BDLInteractiveContextTypeImage,
    /**
     * @locale zh
     * @brief 问卷。
     */
    /**
     * @locale en
     * @brief Questionnaire.
     */
    BDLInteractiveContextTypeQuestionnaire,
    /**
     * @locale zh
     * @brief 文件。
     * @hidden (iOS)
     */
    /**
     * @locale en
     * @brief Document.
     * @hidden (iOS)
     */
    BDLInteractiveContextTypeFile,
    /**
     * @locale zh
     * @brief 投票。
     */
    /**
     * @locale en
     * @brief Vote.
     */
    BDLInteractiveContextTypeVote,
    /**
     * @locale zh
     * @brief 实时抽奖。
     */
    /**
     * @locale en
     * @brief Real-time lucky draw.
     */
    BDLInteractiveContextTypeAward = 6,
    /**
     * @locale zh
     * @brief 红包。
     */
    /**
     * @locale en
     * @brief Red Packet.
     * @hidden (iOS)
     */
    BDLInteractiveContextTypeRedPacket,
    /**
     * @locale zh
     * @brief 签到。
     */
    /**
     * @locale en
     * @brief Check-in.
     */
    BDLInteractiveContextTypeCheckIn,
    /**
     * @locale zh
     * @brief 累计观看抽奖。
     */
    /**
     * @locale en
     * @brief Watch time-based lucky draw.
     */
    BDLInteractiveContextTypeTaskAward,
    /**
     * @locale zh
     * @brief 答题。
     */
    /**
     * @locale en
     * @brief Quiz.
     */
    BDLInteractiveContextTypeQuiz = 10,
    /**
     * @locale zh
     * @brief 公告。
     */
    /**
     * @locale en
     * @brief Announcement.
     */
    BDLInteractiveContextTypeAnnouncement,
};

/**
 * @locale zh
 * @brief 互动工具内容 Model。
 */
/**
 * @locale en
 * @brief The interaction tool content model.
 */
@interface BDLInteractiveContextModel : BDLBaseModel

/**
 * @locale zh
 * @brief 互动工具内容类型。详见 [BDLInteractiveContextType](1185544#BDLInteractiveContextType)。
 */
/**
 * @locale en
 * @brief The type of interaction tool content. For more information, see [BDLInteractiveContextType](viewer-sdk-for-ios-type-definitions#BDLInteractiveContextType).
 */
@property (nonatomic, assign) BDLInteractiveContextType type;
/**
 * @locale zh
 * @brief 图文的内容。
 */
/**
 * @locale en
 * @brief The content of the text and image.
 */
@property (nonatomic, copy) NSString *imageTextContext;
/**
 * @locale zh
 * @brief 实时抽奖的内容。详见 [BDLInteractiveAwardModel](1185544#BDLInteractiveAwardModel)。
 */
/**
 * @locale en
 * @brief The content of real-time lucky draws. For more information, see [BDLInteractiveAwardModel](viewer-sdk-for-ios-type-definitions#BDLInteractiveAwardModel).
 */
@property (nonatomic, strong) BDLInteractiveAwardModel *awardContext;
/**
 * @locale zh
 * @brief 问卷的内容。详见 [BDLQuestionnaireModel](1185544#BDLQuestionnaireModel)。
 */
/**
 * @locale en
 * @brief The questionnaire content. For more information, see [BDLQuestionnaireModel](viewer-sdk-for-ios-type-definitions#BDLQuestionnaireModel).
 */
@property (nonatomic, strong) BDLQuestionnaireModel *questionnaireContext;
/**
 * @locale zh
 * @brief 公告的内容。详见 [BDLInteractiveAnnouncementModel](1185544#BDLInteractiveAnnouncementModel)。
 */
/**
 * @locale en
 * @brief The announcement content. For more information, see [BDLInteractiveAnnouncementModel](viewer-sdk-for-ios-type-definitions#BDLInteractiveAnnouncementModel).
 */
@property (nonatomic, strong) BDLInteractiveAnnouncementModel *announcementContext;
/**
 * @locale zh
 * @brief 投票的内容。详见 [BDLInteractiveVoteModel](1185544#BDLInteractiveVoteModel)。
 */
/**
 * @locale en
 * @brief The vote content. For more information, see [BDLInteractiveVoteModel](viewer-sdk-for-ios-type-definitions#BDLInteractiveVoteModel).
 */
@property (nonatomic, strong) BDLInteractiveVoteModel *voteContext;
/**
 * @locale zh
 * @brief 答题的内容。详见 [BDLInteractiveQuizModel](1185544#BDLInteractiveQuizModel)。
 */
/**
 * @locale en
 * @brief The quiz content. For more information, see [BDLInteractiveQuizModel](viewer-sdk-for-ios-type-definitions#BDLInteractiveQuizModel).
 */
@property (nonatomic, strong) BDLInteractiveQuizModel *quizContext;
/**
 * @locale zh
 * @brief 累计观看抽奖的内容。详见 [BDLTaskAwardConfigModel](1185544#BDLTaskAwardConfigModel)。
 */
/**
 * @locale en
 * @brief The content of watch time-based lucky draws. For more information, see [BDLTaskAwardConfigModel](viewer-sdk-for-ios-type-definitions#BDLTaskAwardConfigModel).
 */
@property (nonatomic, strong) BDLTaskAwardConfigModel *taskAward;
/**
 * @locale zh
 * @brief 签到的内容。
 * @hidden (Windows,Linux,macOS,Android,iOS)
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@property (nonatomic, strong) BDLInteractiveCheckInModel *checkInContext;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 互动工具 Model。
 */
/**
 * @locale en
 * @type keytype
 * @brief The model of interaction tools.
 */
@interface BDLInteractiveToolModel : BDLBaseModel

/**
 * @locale zh
 * @brief 互动工具 ID。
 */
/**
 * @locale en
 * @brief The interaction tool ID.
 */
@property (nonatomic, strong) NSNumber *interactiveToolId;
/**
 * @locale zh
 * @brief 创建时间。
 */
/**
 * @locale en
 * @brief The creation time.
 */
@property (nonatomic, strong) NSDate *createTime;
/**
 * @locale zh
 * @brief 是否被删除。
 *        - `YES`：被删除。
 *        - `NO`：未被删除。
 */
/**
 * @locale en
 * @brief Whether deleted.
 *        - `YES`: Deleted.
 *        - `NO`: Not deleted.
 */
@property (nonatomic, assign) BOOL isDeleted;
/**
 * @locale zh
 * @brief 互动工具内容。详见 [BDLInteractiveContextModel](1185540#BDLInteractiveContextModel)。
 */
/**
 * @locale en
 * @brief The content of interaction tools. For more information, see [BDLInteractiveContextModel](docs-bdlliveengine#BDLInteractiveContextModel).
 */
@property (nonatomic, strong) NSArray<BDLInteractiveContextModel *> *context;
/**
 * @locale zh
 * @brief 文字内容高度。单位：point。
 */
/**
 * @locale en
 * @brief The height of the text content. Unit: points.
 */
@property (nonatomic, assign) CGFloat textHeight;
/**
 * @locale zh
 * @brief 图片内容高度。单位：point。
 */
/**
 * @locale en
 * @brief The height of the image content. Unit: points.
 */
@property (nonatomic, assign) CGFloat imageHeight;
/**
 * @locale zh
 * @brief 总高度。单位：point。
 */
/**
 * @locale en
 * @brief The total height. Unit: points.
 */
@property (nonatomic, assign) CGFloat totalHeight;
/**
 * @locale zh
 * @brief 是否包含指定互动工具类型的内容。
 * @param type 互动工具类型。详见 [BDLInteractiveContextType](#BDLInteractiveContextType)。
 * @return - `YES`：包含。
 *         - `NO`：未包含。
 */
/**
 * @locale en
 * @brief Whether to contain the content of specific interaction tool type.
 * @param type The interaction tool type. For more information, see [BDLInteractiveContextType](#BDLInteractiveContextType).
 * @return - `YES`: Contain.
 *         - `NO`: Do not contain.
 */
- (BOOL)contextContain:(BDLInteractiveContextType)type;

/**
 * @locale zh
 * @brief 根据互动工具类型获取对应的内容。
 * @param type 互动工具类型。详见 [BDLInteractiveContextType](#BDLInteractiveContextType)。
 * @return 互动工具内容。详见 [BDLInteractiveContextModel](1185540#BDLInteractiveContextModel)。
 */
/**
 * @locale en
 * @brief Gets the corresponding content based on the interaction tool type.
 * @param type The interaction tool type. For more information, see [BDLInteractiveContextType](#BDLInteractiveContextType).
 * @return The content of interaction tools. For more information, see [BDLInteractiveContextModel](docs-bdlliveengine#BDLInteractiveContextModel).
 */
- (BDLInteractiveContextModel *)contextWithType:(BDLInteractiveContextType)type;

/**
 * @locale zh
 * @brief 获取图片内容。
 * @return 互动工具内容。详见 [BDLInteractiveContextModel](1185540#BDLInteractiveContextModel)。
 */
/**
 * @locale en
 * @brief Gets the image content.
 * @return The content of interaction tools. For more information, see [BDLInteractiveContextModel](docs-bdlliveengine#BDLInteractiveContextModel).
 */
- (NSArray<BDLInteractiveContextModel *> *)getImageContext;

/**
 * @locale zh
 * @brief 只保留支持的互动工具类型的内容。
 * @param supportedContextTypes 需要保留的互动工具类型的数组。详见 [BDLInteractiveContextType](#BDLInteractiveContextType)。
 */
/**
 * @locale en
 * @brief Only keeps the content of supported interaction tool types.
 * @param supportedContextTypes The array of interaction tool types that need to be kept. For more information, see [BDLInteractiveContextType](#BDLInteractiveContextType).
 */
- (void)keepSupportedContexts:(NSArray<NSNumber *> *)supportedContextTypes;
/**
 * @locale zh
 * @brief 是否为有效的互动工具。
 * @return - `YES`：有效。
 *         - `NO`：无效。
 */
/**
 * @locale en
 * @brief Whether the interaction tool is valid.
 * @return - `YES`: Valid.
 *         - `NO`: Invalid.
 */
- (BOOL)isValid;

@end

#pragma clang diagnostic pop
