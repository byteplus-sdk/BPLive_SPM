//
//  BDLPageAdService.h
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
#import <BDLiveCommon/BDLAdvertisementModel.h>
#import "BDLActivityModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol BDLPageAdService <NSObject>

/// 页中广告改变
/// @param ad 广告数据
/// @param isEnabled 是否开启
/// @param isFloatingEnabled 是否开启页中广告浮层（YES: 点击广告位后，将在当前直播页面展开广告浮层，观众可在看直播的同时查看广告，仅移动端生效）
- (void)pageAdDidChange:(NSArray<BDLAdvertisementModel *> *)ad
              isEnabled:(BOOL)isEnabled
      isFloatingEnabled:(BOOL)isFloatingEnabled;

@end

NS_ASSUME_NONNULL_END
