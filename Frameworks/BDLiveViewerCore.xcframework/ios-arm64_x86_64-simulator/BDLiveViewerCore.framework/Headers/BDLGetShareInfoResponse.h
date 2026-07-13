//
//  BDLGetShareInfoResponse.h
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
 * @brief 获取分享信息后的结果。
 */
/**
 * @locale en
 * @type keytype
 * @brief The result after getting the sharing information.
 */
@interface BDLGetShareInfoResult : BDLBaseModel

/**
 * @locale zh
 * @brief 是否开启直播分享。<br>
 *        - `2`：开启。
 *        - 其他值：未开启。
 */
/**
 * @locale en
 * @brief Whether to enable sharing.
 *        - `2`: Enable.
 *        - Other values: Disable.
 */
@property (nonatomic, assign) NSInteger canShare;
/**
 * @locale zh
 * @brief 是否开启邀请海报。<br>
 *        - `2`：开启。
 *        - 其他值：未开启。
 */
/**
 * @locale en
 * @brief Whether to enable the invitation poster.
 *        - `2`: Enable.
 *        - Other values: Disable.
 */
@property (nonatomic, assign) NSInteger canInvite;
/**
 * @locale zh
 * @brief 分享图标 URL。
 */
/**
 * @locale en
 * @brief The URL of the browser icon.
 */
@property (nonatomic, copy) NSString *coverImage;
/**
 * @locale zh
 * @brief 海报标题。
 */
/**
 * @locale en
 * @brief The poster title.
 */
@property (nonatomic, copy) NSString *title;
/**
 * @locale zh
 * @brief 主办方。
 */
/**
 * @locale en
 * @brief The organizer.
 */
@property (nonatomic, copy) NSString *sponsor;
/**
 * @locale zh
 * @brief 直播开始时间。Unix 时间戳，单位为秒。
 */
/**
 * @locale en
 * @brief The start time of the live stream in Unix timestamp format. Unit: seconds.
 */
@property (nonatomic, assign) long long liveStartTime;
/**
 * @locale zh
 * @brief 活动地点。
 */
/**
 * @locale en
 * @brief The event location.
 */
@property (nonatomic, copy) NSString *activityAddress;
/**
 * @locale zh
 * @brief 活动简介。
 */
/**
 * @locale en
 * @brief The event introduction.
 */
@property (nonatomic, copy) NSString *activityDesc;
/**
 * @locale zh
 * @brief 直播方式。<br>
 *        - `1`：竖屏直播。
 *        - `2`：横屏直播。
 */
/**
 * @locale en
 * @brief The live mode.<br>
 *        - `1`: Portrait mode.
 *        - `2`: Landscape mode.
 */
@property (nonatomic, assign) NSInteger liveType;
/**
 * @locale zh
 * @brief 分享地址。
 */
/**
 * @locale en
 * @brief The shared address.
 */
@property (nonatomic, copy) NSString *customAddress;

@end

/**
 * @locale zh
 * @brief 获取分享信息后企业直播服务端返回的结果。
 */
/**
 * @locale en
 * @brief The result after getting the sharing information, which is returned by the BytePlus Live server.
 */
@interface BDLGetShareInfoResponse : BDLBaseResponse

/**
 * @locale zh
 * @brief 获取分享信息后的结果。详见 [BDLGetShareInfoResult](1185544#BDLGetShareInfoResult)。
 */
/**
 * @locale en
 * @brief The result after getting the sharing information. For more information, see [BDLGetShareInfoResult](viewer-sdk-for-ios-type-definitions#BDLGetShareInfoResult).
 */
@property (nonatomic, strong) BDLGetShareInfoResult *result;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
