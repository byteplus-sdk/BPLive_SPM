//
//  BDLShoppingCardService.h
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

#import <BDLiveCommon/BDLCardModel.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @brief 商品卡片服务回调。
 */
/**
 * @locale en
 * @brief Shopping cart service callback.
 */
@protocol BDLShoppingCardService <NSObject>

@optional
/**
 * @locale zh
 * @brief 商品卡片服务回调：浮窗卡片变化。
 * @param floatingCardArray 浮窗卡片数组。
 */
/**
 * @locale en
 * @brief Shopping cart service callback: Floating card change.
 * @param floatingCardArray The array of floating cards.
 */
- (void)shoppingCardServiceFloatingCardDidChange:(nullable NSArray <BDLCardModel *>*)floatingCardArray;

@optional
/**
 * @locale zh
 * @brief 商品卡片服务回调：全量商品卡片列表变化。
 * @param allCardsArray 全量商品卡片列表。
 */
/**
 * @locale en
 * @brief Shopping cart service callback: All cards array change.
 * @param allCardsArray All cards array.
 */
- (void)shoppingCardServiceAllCardsArrayDidChange:(nullable NSArray <BDLCardModel *>*)allCardsArray;

@end



/**
 * @locale zh
 * @brief 商品卡片服务回调：提供当前正在浮窗展示的card。
 */
/**
 * @locale en
 * @brief Shopping cart service callback: Provides the current floating cards.
 */
@protocol BDLShoppingCardProvider <NSObject>


/**
 * @locale zh
 * @brief 当前的全量商品列表
 */
/**
 * @locale en
 * @brief Current all cards array.
 */
- (NSArray <BDLCardModel *> *)currentAllCardsArray;


/**
 * @locale zh
 * @brief 当前正在浮窗展示的card
 */
/**
 * @locale en
 * @brief Current floating cards.
 */
- (NSArray <BDLCardModel *> *)currentFloatingCards;

/**
 * @locale zh
 * @brief 是否为浮窗卡片。
 * @param cardModel 商品卡片模型。
 * @return 是否为浮窗卡片。
 */
/**
 * @locale en
 * @brief Whether the card is a floating card.
 * @param cardModel The product card model.
 * @return Whether the card is a floating card.
 */
- (BOOL)isFloatingCard:(BDLCardModel *)cardModel;

@end

NS_ASSUME_NONNULL_END
