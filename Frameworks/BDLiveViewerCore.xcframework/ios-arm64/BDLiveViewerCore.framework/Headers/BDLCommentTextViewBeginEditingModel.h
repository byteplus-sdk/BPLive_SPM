//
//  BDLCommentTextViewBeginEditingModel.h
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
 * @brief 判断是否允许观众在评论输入框中输入内容所需的信息。可在 [textViewShouldBeginEditing](#BDLCommentViewConfiguration(Config)-textviewshouldbeginediting) 方法中使用。
 */
/**
 * @locale en
 * @type keytype
 * @brief Information required to determine whether to allow viewers to enter content in the comment text box. This can be used in the [textViewShouldBeginEditing](#BDLCommentViewConfiguration(Config)-textviewshouldbeginediting) method.
 */
@interface BDLCommentTextViewBeginEditingModel : BDLBaseModel

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
 * @brief 观众昵称。<br>:::tip
 *        观众未输入昵称或未登录直播间时，取值为空。<br>:::
 */
/**
 * @locale en
 * @brief The viewer's nickname.
 *        :::tip
 *        If the viewer does not enter a nickname or does not log in to the live room, the value is `nil`.
 *        :::
 */
@property (nonatomic, copy, nullable) NSString *nickname;
/**
 * @locale zh
 * @brief 观众在第三方平台的唯一标识。<br>:::tip
 *        仅在鉴权模式为自定义，且观众已登录直播间时有值。<br>:::
 */
/**
 * @locale en
 * @brief The unique identifier of the viewer on third-party platforms.<br>:::tip
 *        This property has a value only when the authentication mode is custom and the viewer has logged in to the live room.<br>:::
 */
@property (nonatomic, copy, nullable) NSString *externalUserId;
/**
 * @locale zh
 * @brief 用户 ID，观众在企业直播的唯一标识。<br>:::tip
 *        观众未输入昵称或未登录直播间时，取值为 `0`。<br>:::
 */
/**
 * @locale en
 * @brief The user ID, which is the unique identifier of the viewer in BytePlus Live.
 *        :::tip
 *        If the viewer does not enter a nickname or does not log in to the live room, the value is `0`.
 *        :::
 */
@property (nonatomic, strong, nullable) NSNumber *userId;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
