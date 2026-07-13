//
//  BDLMarketingPromotionModel.h
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
#import "BDLBusinessAccountModel.h"
#import "BDLAdvertisementModel.h"
#import "BDLGuidePageModel.h"

// 营销推广
@interface BDLMarketingPromotionModel : BDLBaseModel

// 是否开启企业账号
@property (nonatomic, assign) BOOL isBusinessAccountEnable;

// 企业账号
@property (nonatomic, strong) BDLBusinessAccountModel *businessAccount;

// 是否开启引导页
@property (nonatomic, assign) BOOL isGuidePageEnable;

// 引导页
@property (nonatomic, strong) BDLGuidePageModel *guidePage;

// 广告
@property (nonatomic, copy) NSArray<BDLAdvertisementModel *>* advertisements;

// 是否开启页头广告
@property (nonatomic, assign) BOOL isPageHeaderAdvertisementEnable;

// 是否开启页头广告浮层
@property (nonatomic, assign) BOOL isPageHeaderAdFloatingEnable;

// 是否开启页中广告
@property (nonatomic, assign) BOOL isPageAdvertisementEnable;

// 是否开启页中广告浮层
@property (nonatomic, assign) BOOL isPageAdFloatingEnable;

// 是否开启浮标广告
@property (nonatomic, assign) BOOL isPageUpperAdvertisementEnable;

// 是否开启浮标广告浮层
@property (nonatomic, assign) BOOL isPageUpperAdFloatingEnable;

// 关闭限制：开启后，直播画面中观众将无法关闭浮标广告
@property (nonatomic, assign) BOOL isPageUpperAdvertisementCloseEnable;

// 企业账号
- (BOOL)isBusinessAccountEqual:(BDLMarketingPromotionModel *)object;

// 引导页
- (BOOL)isGuidePageEqual:(BDLMarketingPromotionModel *)object;

// 页头广告
- (BOOL)isPageHeaderAdEqual:(BDLMarketingPromotionModel *)object;
- (BDLAdvertisementModel *)getPageHeaderAd;

// 页中广告
- (BOOL)isPageAdEqual:(BDLMarketingPromotionModel *)object;
- (NSArray<BDLAdvertisementModel *> *)getPageAd;

// 浮标广告
- (BOOL)isPageUpperAdEqual:(BDLMarketingPromotionModel *)object;
- (BDLAdvertisementModel *)getPageUpperAd;

// 卡片广告
- (BDLAdvertisementModel *)getCardAd;

// 广告
- (BOOL)isAdvertisementsEqual:(BDLMarketingPromotionModel *)object;

@end
