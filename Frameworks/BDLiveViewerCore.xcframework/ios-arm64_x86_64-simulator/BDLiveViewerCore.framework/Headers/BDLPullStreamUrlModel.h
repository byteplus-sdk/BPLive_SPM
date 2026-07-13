//
//  BDLPullStreamUrlModel.h
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
#import <BDLiveCommon/BDLPullStreamUrlMainModel.h>
#import <BDLiveCommon/BDLDefines.h>

NS_ASSUME_NONNULL_BEGIN

@interface BDLPullStreamUrlModel : BDLBaseModel

@property (nonatomic, copy) NSString *lineName;
@property (nonatomic, strong) NSNumber *lineId;
// auto,ld,hd,sd,origin,uhd
@property (nonatomic, copy) NSString *allowedSize;

@property (nonatomic, copy) NSString *coverImage;
// sd
@property (nonatomic, copy) NSString *mainDefaultSize;
/// 是否为低延迟的流
@property (nonatomic, assign) BOOL isLls;
/// 是否为时移流
@property (nonatomic, assign) BOOL isTimeShift;

@property (nonatomic, copy) NSArray<BDLPullStreamUrlMainModel *> *main;

- (BOOL)isEqualToPullStreamUrlModel:(BDLPullStreamUrlModel *)object;

/// 获取需要显示的分辨率数组，为 BDLVideoResolution
- (NSArray<NSNumber *> *)getShowResolutionArray;
/// 根据resolution获取播放信息
- (nullable BDLPullStreamUrlMainModel *)getPullStreamUrlMainModelWithResolution:(BDLVideoResolution)BDLVideoResolution;

@end

NS_ASSUME_NONNULL_END
