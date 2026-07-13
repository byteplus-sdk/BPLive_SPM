//
//  BDLActivity.h
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
#import <BDLiveCommon/BDLDefines.h>
#import <BDLiveBase/BDLBaseModel.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 进入直播间所需的信息。
 */
/**
 * @locale en
 * @brief The information required to join the live room.
 */
@interface BDLActivity : BDLBaseModel

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
 * @brief 进入直播间所需的授权 Token。
 */
/**
 * @locale en
 * @brief The authorization token required to join the live room.
 */
@property (nonatomic, copy) NSString *token;
/**
 * @locale zh
 * @brief 直播间的鉴权模式。详见 [BDLActivityAuthMode](1185544#BDLActivityAuthMode)。
 */
/**
 * @locale en
 * @brief The authentication mode of the live room. For more information, see [BDLActivityAuthMode](viewer-sdk-for-ios-type-definitions#BDLActivityAuthMode).
 */
@property (nonatomic, assign) BDLActivityAuthMode authMode;
/**
 * @locale zh
 * @brief 是否为竖屏直播间。<br>
 *        - `YES`：竖屏直播间。
 *        - `NO`：横屏直播间。
 */
/**
 * @locale en
 * @brief Whether the live room is in portrait mode.<br>
 *        - `YES`: Portrait mode.
 *        - `NO`: Landscape mode.
 */
@property (nonatomic, assign) BOOL isPortrait;

/**
 * @locale zh
 * @brief 验证直播间信息是否有效。
 * @list 直播间
 * @return - `YES`：有效。[activityId](#BDLActivity-activityid) 和 [token](#BDLActivity-token) 均非空值。
 *         - `NO`：无效。[activityId](#BDLActivity-activityid) 和 [token](#BDLActivity-token) 有一个为空值或二者皆为空值。
 */
/**
 * @locale en
 * @brief Verifies whether the live room information is valid.
 * @return - `YES`: Valid. Neither [activityId](#BDLActivity-activityid) nor [token](#BDLActivity-token) is 'nil'.
 *         - `NO`: Invalid. Either [activityId](#BDLActivity-activityid) or [token](#BDLActivity-token) is 'nil', or both are 'nil'.
 */
- (BOOL)isValid;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
