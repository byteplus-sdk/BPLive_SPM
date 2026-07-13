//
//  BDLShoppingCardController.h
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
#import "BDLShoppingCardView.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 商品卡片 controller。
 */
/**
 * @locale en
 * @brief The product card controller.
 */
@interface BDLShoppingCardController : NSObject

/**
 * @locale zh
 * @brief 显示弹窗的 view。当为 `nil` 时，则不显示相关弹窗。
 */
/**
 * @locale en
 * @brief The view that displays the dialog box. The related dialog box is not displayed if `nil`.
 */
@property (nonatomic, strong, nullable) UIView *popupSuperview;
/**
 * @locale zh
 * @brief 自定义商品卡片菜单。可自定义所有属性。
 * @param controller 商品卡片 controller。
 * @param shoppingCardView 商品卡片 view。详见 [BDLShoppingCardView](BDLShoppingCardView)。
 * @list 商品卡片菜单
 * @return `BDLBaseView` 及其子类的实例。
 */
/**
 * @locale en
 * @brief Customizes the product card menu. All properties can be customized.
 * @param controller The product card controller.
 * @param shoppingCardView The product card view. For more information, see [BDLShoppingCardView](#BDLShoppingCardView).
 * @return Instances of `BDLBaseView` and its subclasses.
 */
@property (nonatomic, copy, nullable) __kindof BDLBaseView * _Nullable (^customizeShoppingCardView)(BDLShoppingCardController *controller, BDLShoppingCardView *shoppingCardView);
/**
 * @locale zh
 * @brief 商品卡片点击回调。
 * @param controller 商品卡片 controller。
 * @param url 商品卡片 URL。
 * @param isFloatingEnable 企业直播服务端返回的交互展示，即是否开启浮层展示。取值如下：
 *        - `YES`：开启。观众点击商品卡片后，在当前观看页以浮层形式展示商品卡片详情。观众可以边看视频边查看商品详情。
 *        - `NO`：未开启。观众点击商品卡片后，页面自动跳转至新的浏览器标签页展示商品卡片详情。观众无法边看视频边查看商品详情。
 * @param cardModel 商品卡片 Model。详见 [BDLCardModel](1185544#BDLCardModel)。
 * @param clickPosition 商品卡片点击位置。详见 [BDLShoppingCardClickPosition](1185544#BDLShoppingCardClickPosition)。
 */
/**
 * @locale en
 * @brief The callback is triggered when the product card is tapped.
 * @param controller The product card controller.
 * @param url The URL of the product card.
 * @param isFloatingEnable Whether the product details page is displayed on a floating page in the live room, which is returned from the BytePlus Live server. Valid values:
 *        - `YES`: The product details page is displayed on a floating page in the live room after viewers tap the product card. Viewers can watch the video and view the product details page at the same time.
 *        - `NO`: The product details page is displayed on a new browser tab after viewers tap the product card. Viewers cannot watch the video and view the product details page at the same time.
 * @param cardModel The product card model. For more information, see [BDLCardModel](viewer-sdk-for-ios-type-definitions#BDLCardModel).
 * @param clickPosition The product card tap source. For more information, see [BDLShoppingCardClickPosition](1185544#BDLShoppingCardClickPosition).
 */
@property (nonatomic, copy, nullable) void(^onCardClickBlock)(BDLShoppingCardController *controller, NSURL *url, BOOL isFloatingEnable, BDLCardModel *cardModel, BDLShoppingCardClickPosition clickPosition);

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
