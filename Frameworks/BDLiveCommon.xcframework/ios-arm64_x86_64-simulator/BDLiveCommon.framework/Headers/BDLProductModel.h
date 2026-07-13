//
//  BDLProductModel.h
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
#import "BDLCardModel.h"

/**
 * @locale zh
 * @brief 商品模型。
 */
/**
 * @locale en
 * @brief Product model.
 */
@interface BDLProductModel : BDLBaseModel

/**
 * @locale zh
 * @brief 商品ID。
 */
/**
 * @locale en
 * @brief Product ID.
 */
@property (nonatomic, copy) NSString *productID;
/**
 * @locale zh
 * @brief 直达链接 开启后，支持配置特定环境下的卡片链接地址
 */
/**
 * @locale en
 * @brief Direct link. Enabling this feature allows you to configure specific card link addresses for different environments.
 */
@property (nonatomic, assign) BOOL enableUA;
/**
 * @locale zh
 * @brief 环境UA
 */
/**
 * @locale en
 * @brief UA address for different environments.
 */
@property (nonatomic, copy) NSString *UAAddress;
/**
 * @locale zh
 * @brief 浮层交互 开启后，跳转链接实现直播页内跳转
 */
/**
 * @locale en
 * @brief Enabling this feature allows you to jump to the live page within the app when clicking on the card link.
 */
@property (nonatomic, assign) BOOL enableFloating;
/**
 * @locale zh
 * @brief 商品卡片
 */
/**
 * @locale en
 * @brief Product cards.
 */
@property (nonatomic, copy) NSArray<BDLCardModel *> *cards;
/**
 * @locale zh
 * @brief 商品卡片 - 全局配置 - 显示菜单栏  (1: 显示)
 */
/**
 * @locale en
 * @brief Global configuration - Display menu bar (1: Display).
 */
@property (nonatomic, assign) NSInteger displayEnable;

@end
