//
//  BDLAttentionDetectionConfigModel.h
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

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, BDLAttentionDetectionConfigType) {
    BDLAttentionDetectionConfigTypeBeforeWatch = 1, ///< 观看前提示
    BDLAttentionDetectionConfigTypeShiftScreen, ///< 切屏检测
    BDLAttentionDetectionConfigTypeMutePause,    ///< 静音、暂停
    BDLAttentionDetectionConfigTypeNoInteraction, ///< 无互动
};

@interface BDLAttentionDetectionConfigRulleModel : BDLBaseModel

@property (nonatomic, assign) NSInteger minTime;

@end

@interface BDLAttentionDetectionConfigModel : BDLBaseModel

@property (nonatomic, assign) BDLAttentionDetectionConfigType type;
/// 1 开  2 关
@property (nonatomic, assign) int isOpen;
@property (nonatomic, copy) NSString *reminderCopy;
@property (nonatomic, strong) BDLAttentionDetectionConfigRulleModel *detectionRule;

@end

NS_ASSUME_NONNULL_END
