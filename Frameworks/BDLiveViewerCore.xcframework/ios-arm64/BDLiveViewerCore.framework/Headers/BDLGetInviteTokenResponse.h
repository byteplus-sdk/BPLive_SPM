//
//  BDLGetInviteTokenResponse.h
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

#import <BDLiveBase/BDLBaseResponse.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type keytype
 * @brief 获取邀请信息后的结果。
 */
/**
 * @locale en
 * @type keytype
 * @brief The result after getting the invitation information.
 */
@interface BDLGetInviteTokenResult : BDLBaseModel

/**
 * @locale zh
 * @brief 分享人昵称。
 */
/**
 * @locale en
 * @brief The sharer's nickname.
 */
@property (nonatomic, copy) NSString *inviterName;
/**
 * @locale zh
 * @brief 分享人的邀请 Token。
 */
/**
 * @locale en
 * @brief The sharer's invitation token.
 */
@property (nonatomic, copy) NSString *inviterToken;

@end

/**
 * @locale zh
 * @brief 获取邀请信息后企业直播服务端返回的结果。
 */
/**
 * @locale en
 * @brief The result after getting the invitation information, which is returned by the BytePlus Live server.
 */
@interface BDLGetInviteTokenResponse : BDLBaseResponse

/**
 * @locale zh
 * @brief 获取邀请信息后的结果。详见 [BDLGetInviteTokenResult](1185544#BDLGetInviteTokenResult)。
 * @list 其他
 */
/**
 * @locale en
 * @brief The result after getting the invitation information. For more information, see [BDLGetInviteTokenResult](viewer-sdk-for-ios-type-definitions#BDLGetInviteTokenResult).
 */
@property (nonatomic, strong) BDLGetInviteTokenResult *result;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
