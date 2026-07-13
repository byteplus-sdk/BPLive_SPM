//
//  BDLNoticeModel.h
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
 * @brief 通知类型。
 */
/**
 * @locale en
 * @type keytype
 * @brief The notification type.
 */
typedef NS_ENUM(NSInteger, BDLNoticeType) {
    /**
     * @locale zh
     * @brief 进场消息。
     */
   /**
    * @locale en
    * @brief Entrance message.
    */
    BDLNoticeTypeJoinRoom = 1,
    /**
     * @locale zh
     * @brief 送礼消息。
     */
   /**
    * @locale en
    * @brief Gift message.
    */
    BDLNoticeTypeGiftReward = 2,
    /**
     * @locale zh
     * @brief 抽奖通知。
     */
   /**
    * @locale en
    * @brief Lucky draw notification.
    */
    BDLNoticeTypeAward = 3,
    /**
     * @locale zh
     * @brief 红包消息（暂不支持）
     * @hidden (iOS)
     */
   /**
    * @locale en
    * @hidden (iOS)
    * @brief Red Packet Message (Not Supported Yet)
    */
    BDLNoticeTypeRedPacket = 4,
    /**
     * @locale zh
     * @brief 自定义消息。
     */
   /**
    * @locale en
    * @hidden (iOS)
    * @brief Custom Message.
    */
    BDLNoticeTypeCustom = 6,
};

/**
 * @locale zh
 * @type keytype
 * @brief 消息通知 model。
 */
/**
 * @locale en
 * @type keytype
 * @brief The notification model.
 */
@interface BDLNoticeModel : BDLBaseModel
/**
 * @locale zh
 * @brief 通知内容。
 */
/**
 * @locale en
 * @brief The notification content.
 */
@property (nonatomic, copy) NSString *msg;
/**
 * @locale zh
 * @brief 发送时间。
 */
/**
 * @locale en
 * @brief The send time.
 */
@property (nonatomic, strong) NSDate *sendTime;
/**
 * @locale zh
 * @brief 通知类型。详见 [BDLNoticeType](#BDLNoticeType)。
 */
/**
 * @locale en
 * @brief The notification type. For more information, see [BDLNoticeType](#BDLNoticeType).
 */
@property (nonatomic, assign) BDLNoticeType type;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 自定义消息 Model。
 */
/**
 * @locale en
 * @type keytype
 * @hidden (iOS)
 * @brief Custom Message Model.
 */
@interface BDLCustomNotice : BDLBaseModel

/**
 * @locale zh
 * @brief 内容 ID。
 */
/**
 * @locale en
 * @brief Content ID.
 */
@property (nonatomic, assign) NSInteger contentID;
/**
 * @locale zh
 * @brief 内容。
 */
/**
 * @locale en
 * @brief Content.
 */
@property (nonatomic, copy) NSString *content;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
