//
//  BDLCommentUserModel.h
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
 * @brief 用户信息 Model。
 */
/**
 * @locale en
 * @type keytype
 * @brief The model of user information.
 */
@interface BDLCommentUserModel : BDLBaseModel
/**
 * @locale zh
 * @brief 昵称。
 */
/**
 * @locale en
 * @brief The nickname.
 */
@property (nonatomic, copy) NSString *nickname;
/**
 * @locale zh
 * @brief 邮箱。
 */
/**
 * @locale en
 * @brief The email.
 */
@property (nonatomic, copy) NSString *email;
/**
 * @locale zh
 * @brief 观众在第三方平台的唯一标识。<br>:::tip
 *        仅在鉴权模式为自定义，且观众已登录直播间时有值。<br>:::
 */
/**
 * @locale en
 * @brief The unique identifier of the viewer on a third-party platform.
 *        :::tip
 *        This property has a value only when the authentication mode is custom and the viewer has logged in to the live room.
 *        :::
 */
@property (nonatomic, copy) NSString *externalId;
/**
 * @locale zh
 * @brief 头像 URL。
 */
/**
 * @locale en
 * @brief The avatar URL.
 */
@property (nonatomic, copy) NSString *avatarUrl;
/**
 * @locale zh
 * @brief 用户 ID，观众在企业直播的唯一标识。
 */
/**
 * @locale en
 * @brief The user ID, which is the unique identifier of the viewer in BytePlus Live.
 */
@property (nonatomic, strong) NSNumber *userId;

@end
NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop

