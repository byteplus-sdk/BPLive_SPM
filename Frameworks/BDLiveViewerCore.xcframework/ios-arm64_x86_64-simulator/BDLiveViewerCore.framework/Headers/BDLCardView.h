//
//  BDLCardView.h
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
#import "BDLCardConfiguration.h"
#import <BDLiveCommon/BDLLanguageService.h>
#import <BDLiveCommon/BDLProductModel.h>
#import "BDLPullStreamUrlService.h"
#import "BDLBasicService.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 商品卡片内容 view。
 */
/**
 * @locale en
 * @brief The content view of the product card.
 */
@interface BDLCardView : BDLBaseView <BDLLanguageService, BDLPullStreamUrlService, BDLBasicService>

/**
 * @locale zh
 * @brief 是否为竖屏直播间。<br>
 *        - `YES`：竖屏直播间。
 *        - `NO`：横屏直播间。
 */
/**
 * @locale en
 * @brief Whether the live room is in portrait mode.
 *        - `YES`: Portrait mode.
 *        - `NO`: Landscape mode.
 */
@property (nonatomic, assign, readonly) BOOL isPortrait;
/**
 * @locale zh
 * @brief 商品卡片配置。详见 [BDLCardConfiguration](1185544#BDLCardConfiguration(Config))。
 */
/**
 * @locale en
 * @brief The configuration of the product card. For more information, see [BDLCardConfiguration](viewer-sdk-for-ios-type-definitions#BDLCardConfiguration(Config)).
 */
@property (nonatomic, strong, readonly) BDLCardConfiguration *config;
/**
 * @locale zh
 * @brief 商品显示的容器 tableView。可自定义除 `frame` 外的所有属性。
 */
/**
 * @locale en
 * @brief The container tableView to display products. All properties except `frame` can be customized.
 */
@property (nonatomic, strong, readonly) UITableView *tableView;
/**
 * @locale zh
 * @brief 初始化。
 * @param isPortrait 是否以竖屏直播间初始化。<br>
 *        - `YES`：以竖屏直播间初始化。
 *        - `NO`：以横屏直播间初始化。
 * @list 商品卡片
 * @return 商品卡片 view 实例。
 */
/**
 * @locale en
 * @brief Initializes the instance of the product card view.
 * @param isPortrait Whether to initialize in portrait mode.
 *        - `YES`: Portrait mode.
 *        - `NO`: Landscape mode.
 * @return The instance of the product card view.
 */
- (instancetype)initWithPortrait:(BOOL)isPortrait;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
