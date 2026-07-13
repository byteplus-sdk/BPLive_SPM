//
//  BDLTaskAwardConfigModel.h
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

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type keytype
 * @brief 累计观看抽奖状态。
 */
/**
 * @locale en
 * @type keytype
 * @brief The status of watch time-based lucky draws.
 */
typedef NS_ENUM(NSUInteger, BDLTaskAwardRuleState) {
    /**
     * @locale zh
     * @brief 未解锁。
     */
   /**
    * @locale en
    * @brief Locked.
    */
    BDLTaskAwardRuleStateLock,
    /**
     * @locale zh
     * @brief 进行中。
     */
   /**
    * @locale en
    * @brief In progress.
    */
    BDLTaskAwardRuleStateIng,
    /**
     * @locale zh
     * @brief 可以开奖。
     */
   /**
    * @locale en
    * @brief Ready to draw the prize.
    */
    BDLTaskAwardRuleStateCanOpen,
    /**
     * @locale zh
     * @brief 当前观众中奖了。
     */
   /**
    * @locale en
    * @brief The current viewer has won the prize.
    */
    BDLTaskAwardRuleStateWin,
    /**
     * @locale zh
     * @brief 当前观众未中奖。
     */
   /**
    * @locale en
    * @brief The current viewer does not win the prize.
    */
    BDLTaskAwardRuleStateLost,
};

/**
 * @locale zh
 * @type keytype
 * @brief 抽奖中奖人填写信息类型。
 */
/**
 * @locale en
 * @type keytype
 * @brief The type of information that prize winners must enter.
 */
typedef NS_OPTIONS(NSInteger, BDLAwardContactOptions) {
    /**
     * @locale zh
     * @brief 不需要填写任何信息。
     */
    /**
     * @locale en
     * @brief No information required.
     */
    BDLAwardContactOptionsNone = 0,
    /**
     * @locale zh
     * @brief 手机号。
     */
    /**
     * @locale en
     * @brief Phone number.
     */
    BDLAwardContactOptionsPhone = 1,
    /**
     * @locale zh
     * @brief 收货地址。
     */
    /**
     * @locale en
     * @brief Shipping address.
     */
    BDLAwardContactOptionsAddress = 1 << 1,
    /**
     * @locale zh
     * @brief 收件人。
     */
    /**
     * @locale en
     * @brief Recipient.
     */
    BDLAwardContactOptionsReceiver = 1 << 2,
#if BDL_CN
    /**
     * @locale zh
     * @brief 邮箱。
     */
    /**
     * @locale en
     * @hidden (iOS)
     * @brief Email.
     */
    BDLAwardContactOptionsEmail = 1 << 3,
#endif
};

/**
 * @locale zh
 * @type keytype
 * @brief 奖品类型。
 */
/**
 * @locale en
 * @type keytype
 * @brief The prize type.
 */
typedef NS_ENUM(NSUInteger, BDLTaskAwardRuleItemType) {
    /**
     * @locale zh
     * @brief 实物奖品。
     */
   /**
    * @locale en
    * @brief Physical prizes.
    */
    BDLTaskAwardRuleItemTypePhysical,
    /**
     * @locale zh
     * @brief 虚拟奖品。
     */
   /**
    * @locale en
    * @brief Virtual prizes.
    */
    BDLTaskAwardRuleItemTypeVirtual,
    /**
     * @locale zh
     * @brief 自定义奖品，即卡券奖品或积分奖品。
     */
   /**
    * @locale en
    * @brief Custom prizes.
    */
    BDLTaskAwardRuleItemTypeCustomize,
    /**
     * @locale zh
     * @brief 奖券奖品。
     */
   /**
    * @locale en
    * @brief Voucher prizes.
    */
    BDLTaskAwardRuleItemTypeTicket,
};

/**
 * @locale zh
 * @type keytype
 * @brief 累计观看抽奖规则 Model。
 */
/**
 * @locale en
 * @type keytype
 * @brief The model of watch time-based lucky draw rules.
 */
@interface BDLTaskAwardRule : BDLBaseModel

/**
 * @locale zh
 * @brief 抽奖规则 ID。
 */
/**
 * @locale en
 * @brief The lucky draw rule ID.
 */
@property (nonatomic, strong) NSNumber *taskAwardItemId;
/**
 * @locale zh
 * @brief 累计观看时长。单位：分钟。
 */
/**
 * @locale en
 * @brief The total watch time. Unit: minutes.
 */
@property (nonatomic, assign) NSInteger watchTime;
/**
 * @locale zh
 * @brief 参与人数上限。
 */
/**
 * @locale en
 * @brief The maximum number of participants.
 */
@property (nonatomic, assign) NSUInteger awardParticipantLimit;
/**
 * @locale zh
 * @brief 奖品名称。
 */
/**
 * @locale en
 * @brief The prize name.
 */
@property (nonatomic, copy) NSString *awardItemName;
/**
 * @locale zh
 * @brief 奖品图片 URL。
 */
/**
 * @locale en
 * @brief The URL of the prize image.
 */
@property (nonatomic, copy) NSString *awardItemIcon;
/**
 * @locale zh
 * @brief 奖品类型。
 */
/**
 * @locale en
 * @brief The prize type.
 */
@property (nonatomic, copy) NSString *awardItemType;
/**
 * @locale zh
 * @brief 奖品数量。
 */
/**
 * @locale en
 * @brief The number of prizes.
 */
@property (nonatomic, assign) NSUInteger awardCount;
/**
 * @locale zh
 * @brief 奖券奖品领奖链接。
 */
/**
 * @locale en
 * @brief The claim link for voucher prizes.
 */
@property (nonatomic, copy) NSString *awardLotteryTicketAddress;

// MARK: - Local

/**
 * @locale zh
 * @brief 抽奖状态。详见 [BDLTaskAwardRuleState](#BDLTaskAwardRuleState)。非企业直播服务端返回数据。
 */
/**
 * @locale en
 * @brief The lucky draw status. Not returned by the BytePlus Live server. For more information, see [BDLTaskAwardRuleState](#BDLTaskAwardRuleState).
 */
@property (nonatomic, assign) BDLTaskAwardRuleState localState;
/**
 * @locale zh
 * @brief 解锁宝箱的时间。单位：秒。非企业直播服务端返回数据。
 */
/**
 * @locale en
 * @brief The time to unlock the treasure box. Unit: seconds. Not returned by the BytePlus Live server.
 */
@property (nonatomic, assign) NSInteger localEachPrizeWatchTime;
/**
 * @locale zh
 * @brief 中奖观众联系信息。详见 [BDLAwardContactOptions](#BDLAwardContactOptions)。非企业直播服务端返回数据。
 */
/**
 * @locale en
 * @brief The contact information of winners. Not returned by the BytePlus Live server. For more information, see [BDLAwardContactOptions](#BDLAwardContactOptions).
 */
@property (nonatomic, assign) BDLAwardContactOptions localContactOptions;
/**
 * @locale zh
 * @brief 奖品类型。详见 [BDLTaskAwardRuleItemType](#BDLTaskAwardRuleItemType)。非企业直播服务端返回数据。
 */
/**
 * @locale en
 * @brief The prize type. Not returned by the BytePlus Live server. For more information, see [BDLTaskAwardRuleItemType](#BDLTaskAwardRuleItemType).
 */
@property (nonatomic, assign) BDLTaskAwardRuleItemType localAwardItemType;
/**
 * @locale zh
 * @brief 当前倒计时时间。单位：秒。非企业直播服务端返回数据。
 */
/**
 * @locale en
 * @brief The current countdown time. Unit: seconds. Not returned by the BytePlus Live server.
 */
@property (nonatomic, assign) NSUInteger localCountdown;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 累计观看抽奖状态。
 */
/**
 * @locale en
 * @type keytype
 * @brief The status of the watch time-based lucky draws.
 */
typedef NS_ENUM(NSUInteger, BDLTaskAwardStatus) {
    /**
     * @locale zh
     * @brief 初始化。
     */
   /**
    * @locale en
    * @brief Initializing.
    */
    BDLTaskAwardStatusInit,
    /**
     * @locale zh
     * @brief 已开始。
     */
   /**
    * @locale en
    * @brief Started.
    */
    BDLTaskAwardStatusStart,
    /**
     * @locale zh
     * @brief 已结束。
     */
   /**
    * @locale en
    * @brief Ended.
    */
    BDLTaskAwardStatusEnd,
    /**
     * @locale zh
     * @brief 已关闭。
     */
   /**
    * @locale en
    * @brief Closed.
    */
    BDLTaskAwardStatusClose,
};

/**
 * @locale zh
 * @type keytype
 * @brief 累计观看抽奖配置 Model。
 */
/**
 * @locale en
 * @type keytype
 * @brief The model of watch time-based lucky draw configuration.
 */
@interface BDLTaskAwardConfigModel : BDLBaseModel

/**
 * @locale zh
 * @brief 抽奖 ID。
 */
/**
 * @locale en
 * @brief The lucky draw ID.
 */
@property (nonatomic, strong) NSNumber *taskAwardId;
/**
 * @locale zh
 * @brief 抽奖规则。详见 [BDLTaskAwardRule](#BDLTaskAwardRule)。
 */
/**
 * @locale en
 * @brief The lucky draw rules. For more information, see [BDLTaskAwardRule](#BDLTaskAwardRule).
 */
@property (nonatomic, copy) NSArray<BDLTaskAwardRule *> *taskAwardRule;
/**
 * @locale zh
 * @brief 定制抽奖图标 URL。
 */
/**
 * @locale en
 * @brief The URL of the custom lucky draw icon.
 */
@property (nonatomic, copy) NSString *taskAwardIcon;
/**
 * @locale zh
 * @brief 活动说明文案。
 */
/**
 * @locale en
 * @brief The event descripion.
 */
@property (nonatomic, copy) NSString *taskAwardInstructions;
/**
 * @locale zh
 * @brief 抽奖开始时间。Unix 秒级时间戳。
 */
/**
 * @locale en
 * @brief The start time of the lucky draw in Unix timestamp format. Unit: seconds.
 */
@property (nonatomic, assign) NSInteger taskAwardStartTime;
/**
 * @locale zh
 * @brief 抽奖结束时间。Unix 秒级时间戳。
 */
/**
 * @locale en
 * @brief The end time of the lucky draw in Unix timestamp format. Unit: seconds.
 */
@property (nonatomic, assign) NSInteger taskAwardEndTime;
/**
 * @locale zh
 * @brief 抽奖状态。详见 [BDLTaskAwardStatus](#BDLTaskAwardStatus)。
 */
/**
 * @locale en
 * @brief The lucky draw status. For more information, see [BDLTaskAwardStatus](#BDLTaskAwardStatus).
 */
@property (nonatomic, assign) BDLTaskAwardStatus taskAwardStatus;
/**
 * @locale zh
 * @brief 是否使用默认抽奖图标。<br>
 *        - `YES`：使用默认抽奖图标，`taskAwardIcon` 的值不生效。
 *        - `NO`：使用定制抽奖图标，`taskAwardIcon` 的值生效。
 */
/**
 * @locale en
 * @brief Whether to use the default lucky draw icon.
 *        - `YES`: Use the default lucky draw icon. The value of `taskAwardIcon` does not take effect.
 *        - `NO`: Use a custom lucky draw icon. The value of `taskAwardIcon` takes effect.
 */
@property (nonatomic, assign) BOOL isInitIcon;

// MARK: - Local

/// 非后端返回, 方便本地逻辑实现的属性

/**
 * @locale zh
 * @brief 当前进行的规则。非企业直播服务端返回数据。详见 [BDLTaskAwardRule](#BDLTaskAwardRule)。
 */
/**
 * @locale en
 * @brief The ongoing rule. Not returned by the BytePlus Live server. For more information, see [BDLTaskAwardRule](#BDLTaskAwardRule).
 */
@property (nonatomic, strong, nullable) BDLTaskAwardRule *localCurrentRule;
/**
 * @locale zh
 * @brief 可用规则数量。
 */
/**
 * @locale en
 * @brief The number of available rules.
 */
@property (nonatomic, assign) NSUInteger localAvailableRuleCount;
/**
 * @locale zh
 * @brief 抽奖开始时间。非企业直播服务端返回数据。
 */
/**
 * @locale en
 * @brief The start time of the lucky draw. Not returned by the BytePlus Live server.
 */
@property (nonatomic, strong) NSDate *localTaskAwardStartTime;
/**
 * @locale zh
 * @brief 抽奖结束时间。非企业直播服务端返回数据。
 */
/**
 * @locale en
 * @brief The end time of the lucky draw. Not returned by the BytePlus Live server.
 */
@property (nonatomic, strong) NSDate *localTaskAwardEndTime;

/**
 * @locale zh
 * @brief 是否可用。
 * @return - `YES`：可用。
 *         - `NO`：不可用。
 */
/**
 * @locale en
 * @brief Whether valid.
 * @return - `YES`: Valid.
 *         - `NO`: Invalid.
 */
- (BOOL)isValid;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop

