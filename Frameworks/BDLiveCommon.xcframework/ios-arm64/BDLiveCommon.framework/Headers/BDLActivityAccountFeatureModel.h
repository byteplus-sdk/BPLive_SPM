//
//  BDLActivityAccountFeatureModel.h
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

@interface BDLActivityAccountFeatureModel : BDLBaseModel

///是否能使用观播SDK(内部对后端的数据进行了处理,转成了BOOL类型)
@property (nonatomic, assign) BOOL isSeniorWatchNativeSDK;

///是否能使用开播SDK(内部对后端的数据进行了处理,转成了BOOL类型)
@property (nonatomic, assign) BOOL isSeniorMobileLiveSDK;

///Volclive app 活动ID登录 能否开播(内部对后端的数据进行了处理,转成了BOOL类型)
@property (nonatomic, assign) BOOL isSeniorMobileLoginActivity;

///Volclive app 账号登录 能否开播(内部对后端的数据进行了处理,转成了BOOL类型)
@property (nonatomic, assign) BOOL isSeniorVolcPasswordLogin;

///开播美颜能否使用 (内部对后端的数据进行了处理,转成了BOOL类型)
@property (nonatomic, assign) BOOL isSeniorMobileBeauty;

@end

NS_ASSUME_NONNULL_END
