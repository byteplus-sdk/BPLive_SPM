//
//  BDLMenuView.h
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
#import "BDLMenuViewConfiguration.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 菜单栏容器 view，用于实现菜单栏的左右滑动和切换。
 */
/**
 * @locale en
 * @brief The menu bar container view, which is used to implement the left and right sliding and switching of the menu bar.
 */
@interface BDLMenuView : BDLBaseView

/**
 * @locale zh
 * @brief 初始化。
 * @param portrait 是否以竖屏直播间初始化。<br>
 *        - `YES`：以竖屏直播间初始化。
 *        - `NO`：以横屏直播间初始化。
 * @list 菜单栏
 * @return 菜单栏容器 view 实例。
 */
/**
 * @locale en
 * @brief Initializes the instance of the menu bar container view.
 * @param portrait Whether to initialize in portrait mode.
 *        - `YES`: Portrait mode.
 *        - `NO`: Landscape mode.
 * @return The instance of the menu bar container view.
 */
- (instancetype)initWithPortrait:(BOOL)portrait;

/**
 * @locale zh
 * @brief 菜单栏容器 view 配置。详见 [BDLMenuViewConfiguration](1185544#BDLMenuViewConfiguration)。
 */
/**
 * @locale en
 * @brief The configuration of the menu bar container view. For more information, see [BDLMenuViewConfiguration](viewer-sdk-for-ios-type-definitions#BDLMenuViewConfiguration).
 */
@property (nonatomic, strong, readonly) BDLMenuViewConfiguration *config;
/**
 * @locale zh
 * @brief 菜单栏标题区域的背景 view。可自定义所有属性。
 */
/**
 * @locale en
 * @brief The background view of the menu bar title area. All properties can be customized.
 */
@property (nonatomic, strong, readonly) UIView *titleBackgroundView;
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
 * @brief 当前选中标题底部的指示线。可自定义除 `frame` 外的所有属性。
 */
/**
 * @locale en
 * @brief The indicator line at the bottom of the currently selected title. All properties except `frame` can be customized.
 */
@property (nonatomic, strong, readonly) UIView *titleBottomLine;
/**
 * @locale zh
 * @brief 菜单栏标题下方内容区域可滑动的 scrollView。可自定义除 `contentSize` 外的所有属性。
 */
/**
 * @locale en
 * @brief The scrollable `scrollView` in the content area under the menu bar title. All properties except `contentSize` can be customized.
 */
@property (nonatomic, strong, readonly) UIScrollView *contentScrollView;
/**
 * @locale zh
 * @brief 菜单栏容器 view 距离屏幕右侧的距离。单位：point。默认值：如果有直播频道选择入口或回放视频列表入口，默认为 120，否则默认为 0。
 */
/**
 * @locale en
 * @brief The distance between the menu bar container view and the right side of the screen. Unit: points. If the live room has the live source selection entry or playback video list entry, the default value is 120. Otherwise, the default value is 0.
 */
@property (nonatomic, assign) CGFloat titleRightMargin;
/**
 * @locale zh
 * @brief 更新方法。
 * @param titleArray 标题的数组。
 * @param contentViewArray 标题下方内容 view 的数组。
 * @param normalColor 标题默认颜色。
 * @param selectedColor 标题选中的颜色。
 * @param selectIndex 默认选中的数组下标。
 * @list 菜单栏
 */
/**
 * @locale en
 * @brief The update method.
 * @param titleArray An array of titles.
 * @param contentViewArray An array of content views under the title.
 * @param normalColor The default color of the title.
 * @param selectedColor The color of the selected title.
 * @param selectIndex The default selected array index.
 */
- (void)updateWithTitleArray:(NSArray *)titleArray
            contentViewArray:(NSArray<__kindof UIView *> *)contentViewArray
                 normalColor:(UIColor *)normalColor
               selectedColor:(UIColor *)selectedColor
                 selectIndex:(NSInteger)selectIndex;
/**
 * @locale zh
 * @brief 当前选中数组下标变化回调。
 * @param view 菜单栏容器 view。
 * @param index 当前选中的数组下标。
 * @list 菜单栏
 */
/**
 * @locale en
 * @brief The callback is triggered when the currently selected array index changes.
 * @param view The menu bar container view.
 * @param index The currently selected array index.
 */
@property (nonatomic, copy, nullable) void(^indexDidChangeBlock)(BDLMenuView *view, NSUInteger index);
/**
 * @locale zh
 * @brief 获取显示的内容 view 的下标。
 * @list 菜单栏
 * @return 显示的内容 view 的下标。
 */
/**
 * @locale en
 * @brief Gets the index of the displayed content view.
 * @return The index of the displayed content view.
 */
- (NSUInteger)currentIndex;
/**
 * @locale zh
 * @brief 获取当前显示的内容 view。
 * @list 菜单栏
 * @return 当前显示的内容 view。
 */
/**
 * @locale en
 * @brief Gets the currently displayed content view.
 * @return The currently displayed content view.
 */
- (UIView *)currentContentView;
/**
 * @locale zh
 * @brief 在旋转屏幕时调用该方法，用于修正 [contentScrollView](#BDLMenuView-contentscrollview) 的 `contentOffSet` 值。
 * @list 菜单栏
 */
/**
 * @locale en
 * @brief Call this method when the screen is rotating, which is used to adjust the `contentOffset` value of the [contentScrollView](#BDLMenuView-contentscrollview).
 */
- (void)willRotate;
/**
 * @locale zh
 * @brief 在屏幕已经旋转完成后调用该方法。
 * @list 菜单栏
 */
/**
 * @locale en
 * @brief Call this method after the screen rotation is complete.
 */
- (void)didRotate;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
