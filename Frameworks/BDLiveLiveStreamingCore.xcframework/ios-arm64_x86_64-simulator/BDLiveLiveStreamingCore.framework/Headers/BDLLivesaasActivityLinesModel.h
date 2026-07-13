//
//  BDLLivesaasActivityLinesModel.h
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
#import <BDLiveBase/BDLBaseModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface BDLMainPushInfoModel : BDLBaseModel

/// 推流URL
@property (nonatomic, copy) NSString *PushPath;
@property (nonatomic, copy) NSString *PushUrl;
/// 推流码
@property (nonatomic, assign) NSString *StreamingCode;

@end

@interface BDLForwardInfoModel : BDLBaseModel

/// 拉流直播拉流地址
@property (nonatomic, copy) NSString *PullStreamUrl;
/// 拉流直播拉流状态 0未操作，1开始拉流，2结束拉流
@property (nonatomic, assign) NSInteger PullStreamStatus;
/// 拉流直播检测状态 0 检测中,1 源流未推流，2正常拉流 , 3拉流结束, 4异常
@property (nonatomic, assign) NSInteger PullStreamCheckStatus;

@end

@interface BDLLivesaasActivityLinesModel : BDLBaseModel

/// 线路ID
@property (nonatomic, assign) NSInteger LineId;
/// 线路名称
@property (nonatomic, copy) NSString *LineName;

/// 推流模型
@property (nonatomic, strong) BDLMainPushInfoModel *MainPushInfo;
/// 拉流模型
@property (nonatomic, strong) BDLForwardInfoModel *ForwardInfo;

/// 推流码过期时间
@property (nonatomic, assign) NSTimeInterval ExpireTime;

@end

@interface BDLLivesaasActivityLinesListModel : BDLBaseModel

/// 线路信息数据
@property (nonatomic, copy) NSArray <BDLLivesaasActivityLinesModel *> *LineDetails;

@end

NS_ASSUME_NONNULL_END
