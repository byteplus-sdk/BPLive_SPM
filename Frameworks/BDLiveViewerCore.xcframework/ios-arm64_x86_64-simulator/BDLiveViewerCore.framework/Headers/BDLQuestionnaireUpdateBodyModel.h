//
//  BDLQuestionnaireUpdateBodyModel.h
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
#import <BDLiveCommon/BDLDefines.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @brief 提交问卷的观众信息 Model。
 */
/**
 * @locale en
 * @brief The information model of viewers who submit questionnaires.
 */
@interface BDLQuestionnaireUserInfoModel : BDLBaseModel

/**
 * @locale zh
 * @brief 用户 ID，观众在企业直播的唯一标识。<br>:::tip
 *        观众未输入昵称或未登录直播间时，取值为 `0`。<br>:::
 */
/**
 * @locale en
 * @brief The user ID, which is the unique identifier of the viewer in BytePlus Live.
 *        :::tip
 *        If the viewer does not enter a nickname or does not log in to the live room, the value is `0`.
 *        :::
 */
@property (nonatomic, copy) NSString *userId;
/**
 * @locale zh
 * @brief 观众在第三方平台的唯一标识。<br>:::tip
 *        仅在鉴权模式为自定义，且观众已登录直播间时有值。<br>:::
 */
/**
 * @locale en
 * @brief The unique identifier of the viewer on third-party platforms.
 *        :::tip
 *        This property has a value only when the authentication mode is custom and the viewer has logged in to the live room.
 *        :::
 */
@property (nonatomic, copy) NSString *externalId;
/**
 * @locale zh
 * @brief 鉴权模式。详见 [BDLActivityAuthMode](1185544#BDLActivityAuthMode)。
 */
/**
 * @locale en
 * @brief The authentication mode. For more information, see [BDLActivityAuthMode](viewer-sdk-for-ios-type-definitions#BDLActivityAuthMode).
 */
@property (nonatomic, assign) BDLActivityAuthMode registerType;
/**
 * @locale zh
 * @brief 观众昵称。
 */
/**
 * @locale en
 * @brief The viewer's nickname.
 */
@property (nonatomic, copy) NSString *nickname;

@end

/**
 * @locale zh
 * @brief 问卷 Model。
 */
/**
 * @locale en
 * @brief The questionnaire model.
 */
@interface BDLQuestionAnswerModel : BDLBaseModel

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
/// 如果是选择题, 这个在发送时会转换成answer, 不会通过请求发送至服务端
/**
 * @locale zh
 * @brief 提交的问卷数量。
 */
/**
 * @locale en
 * @brief The number of submitted questionnaires.
 */
@property (nonatomic, strong) NSMutableSet<NSNumber *> *answers;
/**
 * @locale zh
 * @brief 观众填写的问卷内容。
 */
/**
 * @locale en
 * @brief The questionnaire content filled out by the viewer.
 */
@property (nonatomic, copy) NSString *answer;
/**
 * @locale zh
 * @brief 问卷问题 Model。详见 [BDLQuestionnaireQuestionModel](1185544#BDLQuestionnaireQuestionModel)。
 */
/**
 * @locale en
 * @brief The question model of a questionnaire. For more information, see [BDLQuestionnaireQuestionModel](viewer-sdk-for-ios-type-definitions#BDLQuestionnaireQuestionModel).
 */
@property (nonatomic, strong) BDLQuestionnaireQuestionModel *questionModel;

/**
 * @locale zh
 * @param question 问卷问题 Model。详见 [BDLQuestionnaireQuestionModel](1185544#BDLQuestionnaireQuestionModel)。
 * @hidden (iOS)
 */
/**
 * @locale en
 * @hidden (iOS)
 * @param question Questionnaire question model. For more details, see [BDLQuestionnaireQuestionModel](viewer-sdk-for-ios-type-definitions#BDLQuestionnaireQuestionModel).
 */
+ (instancetype)questionAnswerWithQuestion:(BDLQuestionnaireQuestionModel *)question;

/**
 * @locale zh
 * @brief 观众填写的问卷内容是否有效。
 * @return - `YES`：有效。
 *         - `NO`：无效。
 */
/**
 * @locale en
 * @brief Whether the questionnaire content filled out by the viewer is valid.
 * @return - `YES`: Valid.
 *         - `NO`: Invalid.
 */
- (BOOL)isAnswerValid;

/**
 * @locale zh
 * @brief 是否需要显示错误提示。<br>
 *        - `YES`：需要。
 *        - `NO`：不需要。
 */
/**
 * @locale en
 * @brief Whether displaying the error message is needed.
 *        - `YES`: Needed.
 *        - `NO`: Not needed.
 */
@property (nonatomic, assign) BOOL needShowWarning;

@end

/**
 * @locale zh
 * @brief 观众填写的问卷 Model。
 */
/**
 * @locale en
 * @brief The model of questionnaires filled out by viewers.
 */
@interface BDLQuestionnaireAnswersModel : BDLBaseModel

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
 * @brief 观众填写的问卷内容。详见 [BDLQuestionAnswerModel](#BDLQuestionAnswerModel)。
 */
/**
 * @locale en
 * @brief The questionnaire content filled out by viewers. For more information, see [BDLQuestionAnswerModel](#BDLQuestionAnswerModel).
 */
@property (nonatomic, copy) NSArray<BDLQuestionAnswerModel *> *questionAnswers;

@end

/**
 * @locale zh
 * @brief 问卷 Model。
 */
/**
 * @locale en
 * @brief The questionnaire model.
 */
@interface BDLQuestionnaireUpdateBodyModel : BDLBaseModel

/**
 * @locale zh
 * @brief 直播间活动 ID。
 */
/**
 * @locale en
 * @brief The activity ID of the live room.
 */
@property (nonatomic, strong) NSNumber *activityId;
/**
 * @locale zh
 * @brief 观众信息。详见 [BDLQuestionnaireUserInfoModel](#BDLQuestionnaireUserInfoModel)。
 */
/**
 * @locale en
 * @brief The viewer information. For more information, see [BDLQuestionnaireUserInfoModel](#BDLQuestionnaireUserInfoModel).
 */
@property (nonatomic, strong) BDLQuestionnaireUserInfoModel *userInfo;
/**
 * @locale zh
 * @brief 观众填写的问卷内容。详见 [BDLQuestionnaireAnswersModel](#BDLQuestionnaireAnswersModel)。
 */
/**
 * @locale en
 * @brief The questionnaire content filled out by the viewer. For more information, see [BDLQuestionnaireAnswersModel](#BDLQuestionnaireAnswersModel).
 */
@property (nonatomic, strong) BDLQuestionnaireAnswersModel *questionnaireAnswer;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
