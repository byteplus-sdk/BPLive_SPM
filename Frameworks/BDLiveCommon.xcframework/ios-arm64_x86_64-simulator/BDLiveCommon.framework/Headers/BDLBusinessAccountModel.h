//
//  BDLBusinessAccountModel.h
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

// 企业账号
@interface BDLBusinessAccountModel : BDLBaseModel

// 账号名称
@property (nonatomic, copy) NSString* accountName;

// 账号头像图片
@property (nonatomic, copy) NSString* accountHeadImage;

// 跳转链接
@property (nonatomic, copy) NSString* accountHeadRedirectUrl;

// The external platform ID, which only contains uppercase and lowercase letters and numbers, and does not exceed 128 characters in length.
@property (nonatomic, copy) NSString* externalPlatformId;

// The extra information associated with the brand account.
@property (nonatomic, copy) NSString* extraInfo;

@property (nonatomic, assign) BOOL isFollowEnable;

@property (nonatomic, assign) int followNumber;

@property (nonatomic, strong) NSNumber *hostAccountId;

- (BOOL)isAccountNameAndAvatarValid;

@end
