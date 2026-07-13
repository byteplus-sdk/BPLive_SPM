//
//  BDLAudienceLinkUser.h
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
#import <BDLiveCommon/BDLDefines.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * @locale zh
 * @type keytype
 * @brief 连麦流信息。
 */
/**
 * @locale en
 * @type keytype
 * @hidden (iOS)
 */
@interface BDLAudienceLinkStreamInfo : BDLBaseModel

/**
 * @locale zh
 * @brief 连麦流类型。详见[BDLAudienceLinkStreamType](#BDLAudienceLinkStreamType)。
 */
@property (nonatomic, assign) BDLAudienceLinkStreamType streamType;
/**
 * @locale zh
 * @brief 是否已开启摄像头。<br>
 *        - `YES`: 已开启。
 *        - `NO`: 未开启。
 */
@property (nonatomic, assign) BOOL enableVideo;
/**
 * @locale zh
 * @brief 是否已开启麦克凤。<br>
 *        - `YES`: 已开启。
 *        - `NO`: 未开启。
 */
@property (nonatomic, assign) BOOL enableAudio;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 连麦用户身份。
 */
/**
 * @locale en
 * @type keytype
 * @hidden (iOS)
 */
typedef NS_ENUM(NSInteger, BDLAudienceLinkUserIdentity) {
    /**
     * @locale zh
     * @brief 主持人。
     */
    BDLAudienceLinkUserIdentityHost = 1,
    /**
     * @locale zh
     * @brief 嘉宾。
     */
    BDLAudienceLinkUserIdentityGuest,
    /**
     * @locale zh
     * @brief 观众。
     */
    BDLAudienceLinkUserIdentityAudience,
};

/**
 * @locale zh
 * @type keytype
 * @brief 连麦用户 Model。
 */
/**
 * @locale en
 * @type keytype
 * @hidden (iOS)
 */
@interface BDLAudienceLinkUser : BDLBaseModel
/**
 * @locale zh
 * @brief 用户 ID。
 */
@property (nonatomic, copy) NSString *userId;
/**
 * @locale zh
 * @brief 昵称。
 */
@property (nonatomic, copy) NSString *nickname;
/**
 * @locale zh
 * @brief 用户对应的连麦流信息。详见 [BDLAudienceLinkStreamInfo](#BDLAudienceLinkStreamInfo)。
 */
@property (nonatomic, copy) NSArray<BDLAudienceLinkStreamInfo *> *streamInfo;
/**
 * @locale zh
 * @brief 用户身份。详见 [BDLAudienceLinkUserIdentity](#BDLAudienceLinkUserIdentity)。
 */
/**
 * @locale en
 */
@property (nonatomic, assign) BDLAudienceLinkUserIdentity identity;
/**
 * @locale zh
 * @brief 是否为主讲人。<br>
 *        - `YES`: 主讲人。
 *        - `NO`: 非主讲人。
 */
@property (nonatomic, assign) BOOL isPresenter;
 /**
  * @locale zh
  * @brief 远端用户版本。 等于 0 从rtc获取媒体状态，等于 1 从服务端获取媒体状态。
  * @hidden (iOS)
  */
/**
 * @locale en
 */
@property (nonatomic, assign) NSInteger linkVersion;

/**
 * @locale zh
 * @brief 根据连麦流类型获取流信息。
 * @param type 连麦流类型。详见 [BDLAudienceLinkStreamType](#BDLAudienceLinkStreamType)。
 * @return 指定连麦流类型对应的流信息。详见 [BDLAudienceLinkStreamInfo](#BDLAudienceLinkStreamInfo)。
 */
- (nullable BDLAudienceLinkStreamInfo *)streamInfoWithType:(BDLAudienceLinkStreamType)type;

@end

NS_ASSUME_NONNULL_END
