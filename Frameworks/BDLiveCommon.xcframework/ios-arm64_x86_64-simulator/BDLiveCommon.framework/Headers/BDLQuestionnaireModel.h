//
//  BDLQuestionnaireModel.h
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
 * @brief 选项信息 Model。
 */
/**
 * @locale en
 * @brief The option information model.
 */
@interface BDLQuestionOptionModel : BDLBaseModel

/**
 * @locale zh
 * @brief 选项 ID。
 */
/**
 * @locale en
 * @brief The option ID.
 */
@property (nonatomic, strong) NSNumber *optionId;
/**
 * @locale zh
 * @brief 选项内容。
 */
/**
 * @locale en
 * @brief The option content.
 */
@property (nonatomic, copy) NSString *optionName;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 问卷问题类型。
 */
/**
 * @locale en
 * @type keytype
 * @brief The question types of questionnaires.
 */
typedef NS_ENUM(NSUInteger, BDLQuestionnaireQuestionType) {
    /**
     * @locale zh
     * @brief 未知类型。
     */
   /**
    * @locale en
    * @brief Unknown.
    */
    BDLQuestionnaireQuestionTypeUnknown,
    /**
     * @locale zh
     * @brief 单选题。
     */
   /**
    * @locale en
    * @brief Multiple choice > Choose one.
    */
    BDLQuestionnaireQuestionTypeRadio,
    /**
     * @locale zh
     * @brief 多选题。
     */
   /**
    * @locale en
    * @brief Multiple choice > Choose all that apply.
    */
    BDLQuestionnaireQuestionTypeCheckbox,
    /**
     * @locale zh
     * @brief 填空题。
     */
   /**
    * @locale en
    * @brief Fill-in-the-blank.
    */
    BDLQuestionnaireQuestionTypeText,
    /**
     * @locale zh
     * @brief 手机号。
     */
   /**
    * @locale en
    * @brief Phone number.
    */
    BDLQuestionnaireQuestionTypePhoneNumber,
    /**
     * @locale zh
     * @brief 邮箱。
     */
   /**
    * @locale en
    * @brief Email.
    */
    BDLQuestionnaireQuestionTypeEmail,
    /**
     * @locale zh
     * @brief 昵称。
     */
   /**
    * @locale en
    * @brief Nickname.
    */
    BDLQuestionnaireQuestionTypeNickname,
};

/**
 * @locale zh
 * @type keytype
 * @brief 问卷问题 Model。
 */
/**
 * @locale en
 * @type keytype
 * @brief The model of questionnaire questions.
 */
@interface BDLQuestionnaireQuestionModel : BDLBaseModel

/**
 * @locale zh
 * @brief 问题 ID。
 */
/**
 * @locale en
 * @brief The question ID.
 */
@property (nonatomic, strong) NSNumber *questionId;
/**
 * @locale zh
 * @brief 问题内容。
 */
/**
 * @locale en
 * @brief The question content.
 */
@property (nonatomic, copy) NSString *question;
/**
 * @locale zh
 * @brief 是否必填。<br>
 *        - `YES`：必填。
 *        - `NO`：非必填。
 */
/**
 * @locale en
 * @brief Whether the question is required.<br>
 *        - `YES`: Required.
 *        - `NO`: Not required.
 */
@property (nonatomic, assign) BOOL isRequire;
/**
 * @locale zh
 * @brief 问题类型。
 */
/**
 * @locale en
 * @brief The question type.
 */
@property (nonatomic, copy) NSString *questionTag;
/**
 * @locale zh
 * @brief 问题子类型。
 */
/**
 * @locale en
 * @brief The question subtype.
 */
@property (nonatomic, copy) NSString *questionSubTag;
/**
 * @locale zh
 * @brief 根据 `questionTag` 和 `questionSubTag` 的值转换为枚举类型的 `questionType`。详见 [BDLQuestionnaireQuestionType](#BDLQuestionnaireQuestionType)。非企业直播服务端返回数据。
 */
/**
 * @locale en
 * @brief The `questionType` enum, which is converted from the values of `questionTag` and `questionSubTag`. Not returned by the BytePlus Live server. For more information, see [BDLQuestionnaireQuestionType](#BDLQuestionnaireQuestionType).
 */
@property (nonatomic, assign) BDLQuestionnaireQuestionType questionType;

/**
 * @locale zh
 * @brief 选项内容。详见 [BDLQuestionOptionModel](1185540#BDLQuestionOptionModel)。<br>
 *         :::tip
 *        非选择题则该值为空。<br>
 *         :::
 */
/**
 * @locale en
 * @brief The option content. For more information, see [BDLQuestionOptionModel](docs-bdlliveengine#BDLQuestionOptionModel).
 *         :::tip
 *        This property has a value only when the question type is multiple choice.
 *         :::
 */
@property (nonatomic, copy, nullable) NSArray<BDLQuestionOptionModel *> *options;

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

/**
 * @locale zh
 * @type keytype
 * @brief 问卷发送时机。
 */
/**
 * @locale en
 * @type keytype
 * @brief The send time of the questionnaire.
 */
typedef NS_ENUM(NSUInteger, BDLQuestionnaireTrigger) {
    /**
     * @locale zh
     * @brief 未知。
     */
   /**
    * @locale en
    * @brief Unknown.
    */
    BDLQuestionnaireTriggerUnknown,
    /**
     * @locale zh
     * @brief 手动发送。
     */
   /**
    * @locale en
    * @brief Send manually.
    */
    BDLQuestionnaireTriggerManual,
    /**
     * @locale zh
     * @brief 进入直播时。
     */
   /**
    * @locale en
    * @brief When viewers join the live room.
    */
    BDLQuestionnaireTriggerLivePageIn,
    /**
     * @locale zh
     * @brief 结束直播时。
     */
   /**
    * @locale en
    * @brief When the live stream ends.
    */
    BDLQuestionnaireTriggerLiveEnd,
};

/**
 * @locale zh
 * @type keytype
 * @brief 问卷发布状态。
 */
/**
 * @locale en
 * @type keytype
 * @brief The publish status of questionnaires.
 */
typedef NS_ENUM(NSUInteger, BDLQuestionnairePublishStatus) {
    /**
     * @locale zh
     * @brief 未知。
     */
   /**
    * @locale en
    * @brief Unknown.
    */
    BDLQuestionnairePublishStatusUnknown,
    /**
     * @locale zh
     * @brief 已发布。
     */
   /**
    * @locale en
    * @brief Published.
    */
    BDLQuestionnairePublishStatusPublish,
};

/**
 * @locale zh
 * @type keytype
 * @brief 问卷信息 Model。
 */
/**
 * @locale en
 * @type keytype
 * @brief The model of questionnaire information.
 */
@interface BDLQuestionnaireModel : BDLBaseModel

/**
 * @locale zh
 * @brief 问卷 ID。
 */
/**
 * @locale en
 * @brief The questionnaire ID.
 */
@property (nonatomic, strong) NSNumber *questionnaireId;
/**
 * @locale zh
 * @brief 问卷标题。
 */
/**
 * @locale en
 * @brief The questionnaire title.
 */
@property (nonatomic, copy) NSString *title;
/**
 * @locale zh
 * @brief 问卷描述。
 */
/**
 * @locale en
 * @brief The questionnaire description.
 */
@property (nonatomic, copy) NSString *questionDescription;
/**
 * @locale zh
 * @brief 发送时机。详见 [BDLQuestionnaireTrigger](#BDLQuestionnaireTrigger)。<br>
 *         :::tip
 *        服务端返回的 String 类型转换为枚举值。<br>
 *         :::
 */
/**
 * @locale en
 * @brief The send time. For more information, see [BDLQuestionnaireTrigger](#BDLQuestionnaireTrigger).
 *        :::tip
 *        The string type returned by the server is converted to an enumeration value.
 *        :::
 */
@property (nonatomic, assign) BDLQuestionnaireTrigger triggerTime;
/**
 * @locale zh
 * @brief 发布状态。详见 [BDLQuestionnairePublishStatus](#BDLQuestionnairePublishStatus)。
 */
/**
 * @locale en
 * @brief The published status. For more information, see [BDLQuestionnairePublishStatus](#BDLQuestionnairePublishStatus).
 */
@property (nonatomic, assign) BDLQuestionnairePublishStatus publishStatus;
/**
 * @locale zh
 * @brief 是否为实名问卷。<br>
 *        - `YES`：实名问卷。
 *        - `NO`：匿名问卷。
 */
/**
 * @locale en
 * @brief Whether the questionnaire is non-anonymous.
 *        - `YES`: Non-anonymous.
 *        - `NO`: Anonymous.
 */
@property (nonatomic, assign) BOOL isRealNameEnable;
/**
 * @locale zh
 * @brief 观众是否已填写过该问卷。<br>
 *        - `YES`：已填写过。
 *        - `NO`：未填写过。
 */
/**
 * @locale en
 * @brief Whether the questionnaire is submitted by the viewer.
 *        - `YES`: Submitted.
 *        - `NO`: Not submitted.
 */
@property (nonatomic, assign) BOOL isUserFilled;
/**
 * @locale zh
 * @brief 问卷的问题列表。详见 [BDLQuestionnaireQuestionModel](#BDLQuestionnaireQuestionModel)。
 */
/**
 * @locale en
 * @brief The question list of the questionnaire. For more information, see [BDLQuestionnaireQuestionModel](#BDLQuestionnaireQuestionModel).
 */
@property (nonatomic, copy) NSArray<BDLQuestionnaireQuestionModel *> *questions;
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

