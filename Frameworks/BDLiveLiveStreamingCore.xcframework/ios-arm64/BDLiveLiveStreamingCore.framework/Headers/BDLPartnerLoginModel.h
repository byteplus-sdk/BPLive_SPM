//
//  BDLPartnerLoginModel.h
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
#import <BDLiveCommon/BDLActivityAccountFeatureModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface BDLPartnerLoginStsMsgModel : NSObject

@property (nonatomic, copy) NSString *AccessKeyId;
@property (nonatomic, copy) NSString *SecretAccessKey;
@property (nonatomic, copy) NSString *SessionToken;
@property (nonatomic, copy) NSString *ExpiredTime;

@end

@interface BDLPartnerLoginModel : NSObject

@property (nonatomic, strong) BDLPartnerLoginStsMsgModel *StsMsg;

@property (nonatomic, assign) BOOL LoginFlag;
@property (nonatomic, copy) NSString *AccountId;
@property (nonatomic, copy) NSString *AuthToken;
@property (nonatomic, strong) BDLActivityAccountFeatureModel *AccountFeatureAuth;

@end

NS_ASSUME_NONNULL_END
