//
//  BDLAwardUserResponse.h
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
 * @brief 观众参与抽奖的状态。
 */
/**
 * @locale en
 * @type keytype
 * @brief The status of viewer participation in the lucky draw.
 */
typedef NS_ENUM(NSInteger, BDLAwardUserStatus) {
    /**
     * @locale zh
     * @brief 未参与。
     */
   /**
    * @locale en
    * @brief Not participated.
    */
    BDLAwardUserStatusNotParticipate = 1,
    /**
     * @locale zh
     * @brief 已参与。
     */
   /**
    * @locale en
    * @brief Already participated.
    */
    BDLAwardUserStatusParticipated = 2,
    /**
     * @locale zh
     * @brief 中奖。
     */
   /**
    * @locale en
    * @brief Won.
    */
    BDLAwardUserStatusWin = 4,
    /**
     * @locale zh
     * @brief 未中奖。
     */
   /**
    * @locale en
    * @brief Not won.
    */
    BDLAwardUserStatusUnWin = 5,
};

/**
 * @locale zh
 * @type keytype
 * @brief 抽奖相关的观众信息 Model。
 */
/**
 * @locale en
 * @type keytype
 * @brief The model of lucky draw-related viewer information.
 */
@interface BDLAwardUserModel : BDLBaseModel

/**
 * @locale zh
 * @brief 观众参与抽奖的状态。详见 [BDLAwardUserStatus](#BDLAwardUserStatus)。
 */
/**
 * @locale en
 * @brief The lucky draw participation status of the viewer. For more information, see [BDLAwardUserStatus](#BDLAwardUserStatus).
 */
@property (nonatomic, assign) BDLAwardUserStatus status;
/**
 * @locale zh
 * @brief 中奖观众的收货地址。
 */
/**
 * @locale en
 * @brief The shipping address of the winner.
 */
@property (nonatomic, copy) NSString *address;
/**
 * @locale zh
 * @brief 中奖观众的手机号。
 */
/**
 * @locale en
 * @brief The phone number of the winner.
 */
@property (nonatomic, copy) NSString *telephone;
/**
 * @locale zh
 * @brief 中奖观众的收件人名称。
 */
/**
 * @locale en
 * @hidden (Windows,Linux,macOS,Android)
 * @brief The recipient name of the winner.
 */
@property (nonatomic, copy) NSString *receiverName;

#if BDL_CN
/**
 * @locale zh
 * @brief 中奖观众的邮箱。
 */
/**
 * @locale en
 * @hidden (iOS)
 * @brief The email number of the winner.
 */
@property (nonatomic, copy) NSString *awardEmail;
/**
 * @locale zh
 * @brief 奖券奖品领奖链接。
 */
/**
 * @locale en
 * @hidden (Windows,Linux,macOS,Android)
 * @brief The claim link of the voucher prize.
 */
@property (nonatomic, copy) NSString *awardLotteryTicketAddr;
/**
 * @locale zh
 * @brief 奖品 ID。
 */
/**
 * @locale en
 * @hidden (Windows,Linux,macOS,Android)
 * @brief The prize ID.
 */
@property (nonatomic, strong) NSNumber *awardItemId;
#endif

@end

/**
 * @locale zh
 * @brief 企业直播服务端返回的抽奖观众信息。
 */
/**
 * @locale en
 * @brief The lucky draw viewer information, which is returned by the BytePlus Live server.
 */
@interface BDLAwardUserResponse : BDLBaseResponse

/**
 * @locale zh
 * @brief 抽奖相关的观众信息 Model。详见 [BDLAwardUserModel](1185544#BDLAwardUserModel)。
 */
/**
 * @locale en
 * @brief The model of lucky draw-related viewer information. For more information, see [BDLAwardUserModel](viewer-sdk-for-ios-type-definitions#BDLAwardUserModel).
 */
@property (nonatomic, strong) BDLAwardUserModel *result;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
