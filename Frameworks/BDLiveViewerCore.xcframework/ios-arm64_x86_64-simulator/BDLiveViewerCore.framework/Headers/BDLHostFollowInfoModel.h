//
//  BDLHostFollowInfoModel.h
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
 * @brief 关注主播所需的信息。
 */
/**
 * @locale en
 * @brief The information required to follow the host.
 * @type keytype
 */
@interface BDLHostFollowInfoModel : BDLBaseModel

/**
 * @locale zh
 * @type api
 * @brief 关联用户 ID，即观众在第三方平台的唯一标识。关联用户 ID 的取值为调用 [GetSDKTokenAPI](https://www.volcengine.com/docs/3019/105049) 接口时传入的 `UserIdStr`（观众 ID）。
 */
/**
 * @locale en
 * @brief The external user ID, which is the unique identifier for viewers on third-party platforms. This ID is the `UserIdStr` parameter passed when calling [GetSDKTokenAPI](https://docs.byteplus.com/en/docs/byteplus-livesaas/docs-getsdktokenapi).
 */
@property (nonatomic, copy) NSString *externalId;
/**
 * @locale zh
 * @type api
 * @brief 观众昵称，即调用 [GetSDKTokenAPI](https://www.volcengine.com/docs/3019/105049) 接口时传入的 `Nickname`。
 */
/**
 * @locale en
 * @brief The viewer's nickname, which is the `Nickname` parameter passed when calling [GetSDKTokenAPI](https://docs.byteplus.com/en/docs/byteplus-livesaas/docs-getsdktokenapi).
 */
@property (nonatomic, copy) NSString *externalName;
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
 * @brief 主播账号 ID。
 */
/**
 * @locale en
 * @brief The host account ID.
 */
@property (nonatomic, strong) NSNumber *hostAccountId;
/**
 * @locale zh
 * @brief 主播账号名称。
 */
/**
 * @locale en
 * @brief The host account name.
 */
@property (nonatomic, copy) NSString *hostAccountName;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
