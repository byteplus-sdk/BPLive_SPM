//
//  BDLFloatingCardView.h
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


#import <BDLiveCommon/BDLBaseView.h>
#import "BDLProductService.h"
#import "BDLFloatingCardConfiguration.h"
#import <BDLiveCommon/BDLLanguageService.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 浮窗商品卡片 view。
 */
/**
 * @locale en
 * @brief The floating product card view.
 */
@interface BDLFloatingCardView : BDLBaseView

/**
 * @locale zh
 * @brief 浮窗商品卡片配置。详见 [BDLFloatingCardConfiguration](1185544#BDLFloatingCardConfiguration(Config))。
 */
/**
 * @locale en
 * @brief The configuration of the floating product card. For more information, see [BDLFloatingCardConfiguration](viewer-sdk-for-ios-type-definitions#BDLFloatingCardConfiguration(Config)).
 */
@property (nonatomic, strong, readonly) BDLFloatingCardConfiguration *config;
/**
 * @locale zh
 * @brief 关闭按钮点击回调。
 * @list 浮窗商品卡片
 */
/**
 * @locale en
 * @brief The callback is triggered when the close button is tapped.
 */
@property (nonatomic, copy, nullable) void (^closeButtonClickedBlock)(void);

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
