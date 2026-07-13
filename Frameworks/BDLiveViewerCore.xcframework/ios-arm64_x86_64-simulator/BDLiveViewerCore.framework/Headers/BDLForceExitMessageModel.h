//
//  BDLForceExitMessageModel.h
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

typedef NS_ENUM(NSUInteger, BDLForceExitStatus) {
    BDLForceExitStatusNone = 0,
    // 硬踢出
    BDLForceExitStatusForce = 1,
    // 软踢出
    BDLForceExitStatusSoft = 2,
    // 这个是后端兼容历史ip封禁的状态
    BDLForceExitStatusIPBand = 3,
    // 重复登录
    BDLForceExitStatusMultiLogin
};

typedef NS_ENUM(NSUInteger, BDLForceExitType) {
    // 无需踢出
    BDLForceExitTypeNone = 0,
    // 强制踢出
    BDLForceExitTypeForce = 1,
    // 软踢出
    BDLForceExitTypeSoft = 2,
};

@interface BDLForceExitMessageModel : BDLBaseModel

@property (nonatomic, copy) NSString *exitTip;
@property (nonatomic, assign) BDLForceExitStatus exitStatus;
@property (nonatomic, assign) BDLForceExitType exitType;
@property (nonatomic, assign) NSInteger exitTime;

@end

/// 长连接返回的Model, 其中包含 UID 和 DID
@interface BDLForceExitMessageNetConnectionModel : BDLForceExitMessageModel

@property (nonatomic, strong) NSNumber *userId;
@property (nonatomic, strong) NSNumber *deviceId;

@end

NS_ASSUME_NONNULL_END
