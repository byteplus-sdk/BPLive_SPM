//
//  BDLForceOfflineInfo.h
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
 * @brief 观众被强制退出直播间的原因。
 */
/**
 * @locale en
 * @type keytype
 * @brief Reasons for viewers being forcibly removed from the live room.
 */
typedef NS_ENUM(NSInteger, BDLForceOfflineReason) {
    /**
     * @locale zh
     * @brief 在开启禁止重复登录功能后，同一观众在多端同时登录同一直播间。
     */
   /**
    * @locale en
    * @brief After the repeated login prevention feature is enabled, the same viewer logs in to the same live room on multiple devices simultaneously.
    */
    BDLForceOfflineReasonMultiLogin = 0,
    /**
     * @locale zh
     * @brief 超时未签到。
     */
   /**
    * @locale en
    * @brief Timeout due to not checking in.
    */
    BDLForceOfflineReasonCheckInTimeout,
    /**
     * @locale zh
     * @brief IP 被封禁。
     */
   /**
    * @locale en
    * @brief IP address banned.
    */
    BDLForceOfflineReasonIPBanned,
    /**
     * @locale zh
     * @brief 被封禁。
     */
   /**
    * @locale en
    * @brief Kicked out.
    */
    BDLForceOfflineReasonKickOut,
};

/**
 * @locale zh
 * @type keytype
 * @brief 观众被强制退出直播间的信息 Model。
 */
/**
 * @locale en
 * @brief The information model for viewers being forcibly removed from the live room.
 * @type keytype
 */
@interface BDLForceOfflineInfo : BDLBaseModel

/**
 * @locale zh
 * @brief 观众被强制退出直播间的原因。详见 [BDLForceOfflineReason](#BDLForceOfflineReason)。
 */
/**
 * @locale en
 * @brief The reason for viewers being forcibly removed from the live room. For more information, see [BDLForceOfflineReason](#BDLForceOfflineReason).
 */
@property (nonatomic, assign) BDLForceOfflineReason reason;
/**
 * @locale zh
 * @brief 观众被强制退出直播间的提示信息。
 */
/**
 * @locale en
 * @brief The prompt text for viewers being forcibly removed from the live room.
 */
@property (nonatomic, copy, nullable) NSString *prompt;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
