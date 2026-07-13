//
//  BDLShoppingCardView.h
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
#import <BDLiveCommon/BDLMenuBarModel.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 商品卡片 view。
 */
/**
 * @locale en
 * @brief The product card view.
 */
@interface BDLShoppingCardView : BDLBaseView

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
 * @brief “共 x 件商品”文案 label。可自定义除 `text`、`frame` 外的所有属性。
 */
/**
 * @locale en
 * @brief The text label of "x products in total". All properties except `text` and `frame` can be customized.
 */
@property (nonatomic, strong, readonly) UILabel *totalCountLabel;
/**
 * @locale zh
 * @brief 菜单栏标题区域可滑动的 scrollView。可自定义除 `contentSize` 外的所有属性。
 */
/**
 * @locale en
 * @brief The scrollable `scrollView` in the menu bar title area. All properties except `contentSize` can be customized.
 */
@property (nonatomic, strong, readonly) UIScrollView *titleScrollView;
/**
 * @locale zh
 * @brief 菜单栏标题下方内容区域可滑动的 scrollView。可自定义除 `contentSize` 外的所有属性。
 */
/**
 * @locale en
 * @brief The scrollable `scrollView` in the content area under the menu bar title. All properties except `contentSize` can be customized.
 */
@property (nonatomic, strong, readonly) UIScrollView *contentScrollView;
/**
 * @locale zh
 * @brief 商品卡片搜索回调。
 * @param shoppingCardView 商品卡片 view。
 * @param menus 菜单栏信息 Model。详见 [BDLMenuModel](1185544#BDLMenuModel)。
 * @list 商品卡片
 */
/**
 * @locale en
 * @brief The callback is triggered when the product card is searched.
 * @param shoppingCardView The product card view.
 * @param menus The model of menu bar information. For more information, see [BDLMenuModel](viewer-sdk-for-ios-type-definitions#BDLMenuModel).
 */
@property (nonatomic, copy, nullable) void (^onCardSearchClickBlock)(BDLShoppingCardView *shoppingCardView, NSArray <BDLMenuModel *> *menus);
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
