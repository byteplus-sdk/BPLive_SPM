//
//  BDLGetPageWatchDataModel.h
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

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BDLGetPageClicksModel : NSObject

@property (nonatomic, copy) NSString *PV;
@property (nonatomic, copy) NSString *UV;

/// 总时长（分钟）
@property (nonatomic, assign) NSInteger TotalTime;
/// 人均观看时长
@property (nonatomic, assign) NSInteger AvgTime;
/// 人均观看次数
@property (nonatomic, assign) NSInteger AvgNumber;

@end

@interface BDLGetPageWatchDataModel : NSObject

/// 活动直播id
@property (nonatomic, assign) NSInteger ActivityId;

@property (nonatomic, strong) BDLGetPageClicksModel *PageClicks;

//=============================== 拓展字段 ==================================
/// 人数峰值
@property (nonatomic, assign) NSInteger maxAudienceNum;
/// 消息互动数
@property (nonatomic, assign) NSInteger interactInfoCount;
/// 开始时间
@property (nonatomic, assign) NSTimeInterval startTime;
/// 结束时间
@property (nonatomic, assign) NSTimeInterval endTime;

@end

NS_ASSUME_NONNULL_END
