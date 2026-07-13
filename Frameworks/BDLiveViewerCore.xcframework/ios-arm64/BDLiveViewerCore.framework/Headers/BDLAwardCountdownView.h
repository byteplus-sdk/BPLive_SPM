//
//  BDLAwardCountdownView.h
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


#import <UIKit/UIKit.h>

#import "BDLAwardNumberView.h"
#import <BDLiveCommon/BDLBasicModel.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 抽奖倒计时 view。
 */
/**
 * @locale en
 * @brief TThe lucky draw countdown view.
 */
@interface BDLAwardCountdownView : UIView

/**
 * @locale zh
 * @brief 数字 view 的数组。详见 [BDLAwardNumberView](#BDLAwardNumberView)。
 */
/**
 * @locale en
 * @brief An array of number views. For more information, see [BDLAwardNumberView](#BDLAwardNumberView).
 */
@property (nonatomic, copy) NSArray<BDLAwardNumberView *> *numberViews;
/**
 * @locale zh
 * @brief 冒号 label 的数组。
 */
/**
 * @locale en
 * @brief An array of colon labels.
 */
@property (nonatomic, copy) NSArray<UILabel *> *colons;
/**
 * @locale zh
 * @brief 更新界面。
 * @param countdown 倒计时剩余时间。单位：秒。
 */
/**
 * @locale en
 * @brief Updates the interface.
 * @param countdown The remaining countdown time. Unit: seconds.
 */
- (void)updateViewWithCountdown:(NSInteger)countdown;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
