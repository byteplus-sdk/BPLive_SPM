//
//  BDLOpenTaskAwardResponse.h
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

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, BDLOpenTaskAwardStatus) {
    /**
     * @locale zh
     * @brief 开启失败，请稍后再试
     */
    BDLOpenTaskAwardStatusInit = -1,
    /**
     * @locale zh
     * @brief 开启失败，请稍后再试
     */
    BDLOpenTaskAwardStatusUnattended = 0,
    /**
     * @locale zh
     * @brief 中奖
     */
    BDLOpenTaskAwardStatusWin = 1,
    /**
     * @locale zh
     * @brief 未中奖
     */
    BDLOpenTaskAwardStatusLost = 2,
    /**
     * @locale zh
     * @brief 参加中
     */
    BDLOpenTaskAwardStatusAttending = 3,
};

@interface BDLOpenTaskAwardResult : NSObject

@property (nonatomic, copy) NSString *awardItemName;
@property (nonatomic, assign) NSInteger createTime;
@property (nonatomic, assign) BDLOpenTaskAwardStatus status;
@property (nonatomic, strong) NSNumber *taskAwardItemId;

@end

@interface BDLOpenTaskAwardResponse : BDLBaseResponse

@property (nonatomic, strong) BDLOpenTaskAwardResult *result;

@end

NS_ASSUME_NONNULL_END
