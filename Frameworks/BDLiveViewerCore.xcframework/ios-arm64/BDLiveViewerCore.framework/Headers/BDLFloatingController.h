//
//  BDLFloatingController.h
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

#import "BDLAllFloatingInteractiveToolView.h"
#import <BDLiveCommon/UIView+BDLDraggable.h>
#import "BDLUpperAdView.h"
#import "BDLFloatingCardView.h"
#import "BDLMenuService.h"
#import <BDLiveCommon/BDLDefines.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type keytype
 * @brief 浮窗 view 类型。
 */
/**
 * @locale en
 * @brief Type of the floating window view.
 * @type keytype
 */
typedef NS_ENUM(NSInteger, BDLFloatingControllerViewTag) {
    /**
     * @locale zh
     * @brief 互动工具容器 view。
     */
   /**
    * @locale en
    * @brief The container view of the interaction tool.
    */
    BDLFloatingControllerViewTagInteractiveToolContainer = 0,
    /**
     * @locale zh
     * @brief 浮标广告 view。
     */
   /**
    * @locale en
    * @brief The floating ad view.
    */
    BDLFloatingControllerViewTagUpperAd = 100,
    /**
     * @locale zh
     * @brief 第一个商品卡片 view。
     */
   /**
    * @locale en
    * @brief The view of the first product card.
    */
    BDLFloatingControllerViewTagCardFirst = 300,
    /**
     * @locale zh
     * @brief 第二个商品卡片 view。
     */
   /**
    * @locale en
    * @brief The view of the second product card.
    */
    BDLFloatingControllerViewTagCardSecond = 310,
    /**
     * @locale zh
     * @brief 第三个商品卡片  view。
     */
   /**
    * @locale en
    * @brief The view of the third product card.
    */
    BDLFloatingControllerViewTagCardThird = 320,
};

/**
 * @locale zh
 * @type keytype
 * @brief 自定义悬浮 view 插入直播间的位置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The position to insert the custom floating view into the live room.
 */
typedef NS_ENUM(NSInteger, BDLFloatingControllerInsertPosition) {
    /**
     * @locale zh
     * @brief 不参与 view 的展示顺序重新排列，展示位置由 view 的配置决定。
     */
    /**
     * @locale en
     * @brief Do not participate in rearranging the display order of the view. The display position is determined by the view's configuration.
     */
    BDLFloatingControllerInsertPositionNone,
    /**
     * @locale zh
     * @brief 在直播间左上方显示，与竖屏直播间的互动工具浮窗进行位置联动。根据 `view.tag` 重新排列 view 的展示顺序，`tag` 值越小，展示位置越靠上。<br/>
     *        :::tip
     *        在竖屏直播间中，右上方显示的内容（自定义悬浮 view 和页中、页头广告）整体与左上方显示的内容（自定义悬浮 view 和互动工具浮窗）整体，顶部高度一致。<br/>
     *        :::
     */
    /**
     * @locale en
     * @brief Displayed in the upper-left corner of the live room, in conjunction with the interaction tool floating window in portrait mode. The display order of the views is rearranged based on their `view.tag` values. The smaller the `tag` value, the higher the display position.
     *        :::tip
     *        In the live room in portrait mode, the content displayed in the upper-right corner (custom floating view, in-page ads, and header ad) aligns in height at the top with the content displayed in the upper-left corner (custom floating view and interaction tool floating window).
     *        :::
     */
    BDLFloatingControllerInsertPositionLeftTop,
    /**
     * @locale zh
     * @brief 在直播间右下方显示，与浮窗商品卡片、浮标广告，以及横屏直播间的互动工具浮窗进行位置联动。根据 `view.tag` 重新排列 view 的展示顺序，`tag` 值越小，展示位置越靠上。
     */
    /**
     * @locale en
     * @brief Displayed in the lower-right corner of the live room, in conjunction with the interaction tool floating window in landscape mode, floating product cards, and floating ads. The display order of the views is rearranged based on their `view.tag` values. The smaller the `tag` value, the higher the display position.
     */
    BDLFloatingControllerInsertPositionRightBottom,
    /**
     * @locale zh
     * @brief 在直播间右上方显示，与竖屏直播间的页中和页头广告进行位置联动。根据 `view.tag` 重新排列 view 的展示顺序，`tag` 值越小，展示位置越靠上。<br/>
     *        :::tip
     *        在竖屏直播间中，右上方显示的内容（自定义悬浮 view 和页中、页头广告）整体与左上方显示的内容（自定义悬浮 view 和互动工具浮窗）整体，顶部高度一致。<br/>
     *        :::
     */
    /**
     * @locale en
     * @brief Displayed in the upper-right corner of the live room, in conjunction with the in-page ads and header ad in portrait mode. The display order of the views is rearranged based on their `view.tag` values. The smaller the `tag` value, the higher the display position.
     *        :::tip
     *        In the live room in portrait mode, the content displayed in the upper-right corner (custom floating view, in-page ads, and header ad) aligns in height at the top with the content displayed in the upper-left corner (custom floating view and interaction tool floating window).
     *        :::
     */
    BDLFloatingControllerInsertPositionRightTop,
};

/**
 * @locale zh
 * @type keytype
 * @brief 浮窗 controller。
 */
/**
 * @locale en
 * @type keytype
 * @brief The floating window controller.
 */
@interface BDLFloatingController : NSObject <
BDLPageUpperAdService
, BDLMenuService
, BDLDraggingDelegate
>

/**
 * @locale zh
 * @brief 显示浮窗的 view。
 */
/**
 * @locale en
 * @brief The view that displays the floating window.
 */
@property (nonatomic, strong, readonly) UIView *superview;

/**
 * @locale zh
 * @brief 隐藏所有浮窗。
 *        - `YES`：隐藏所有浮窗。
 *        - `NO`：显示所有应显示的浮窗。
 */
/**
 * @locale en
 * @brief Whether to hide all the floating windows.
 *        - `YES`: Hide all the floating windows.
 *        - `NO`: Display all the floating windows that should be displayed.
 */
@property (nonatomic, assign, readonly) BOOL hideAllFloatingView;
/**
 * @locale zh
 * @brief 浮标广告 view。
 */
/**
 * @locale en
 * @brief The floating ad view.
 */
@property (nonatomic, strong, readonly) UIView *upperAdView;
/**
 * @locale zh
 * @brief 互动工具浮窗 view 的容器 view。
 */
/**
 * @locale en
 * @brief The container view of the interaction tool floating window view.
 */
@property (nonatomic, strong, readonly) UIStackView *floatingInteractiveToolContainerView;
/**
 * @locale zh
 * @brief 浮窗广告需要打开 URL 时调用该 block。
 * @param url 需要打开的 URL。
 * @param isFloatingEnable 是否开启浮层展示。<br>
 *        - `YES`：开启。在直播间浮层展示跳转内容，观众可以边看视频边看跳转内容。
 *        - `NO`：未开启。打开新的浏览器标签页展示跳转内容，观众无法边看视频边看跳转内容。
 * @param floatingController 浮窗 controller。
 */
/**
 * @locale en
 * @brief The block is called when the floating window needs to open a URL.
 * @param floatingController The floating window controller.
 * @param url The URL that needs to be opened.
 * @param isFloatingEnable Whether the redirected content is displayed on a floating page in the live room.
 *        - `YES`: The redirected content is displayed on a floating page in the live room. Viewers can watch the video and view the redirected content at the same time.
 *        - `NO`: The redirected content is displayed on a new browser tab. Viewers cannot watch the video and view the redirected content at the same time.
 */
@property (nonatomic, copy, nullable) void(^openUrlBlock)(BDLFloatingController *floatingController, NSURL *url, BOOL isFloatingEnable);
/**
 * @locale zh
 * @brief 插入自定义悬浮 view。
 * @param view 自定义的悬浮 view，可插入直播间的指定位置。按照 `view.tag` 依次从上到下排列（tag 值越小，展示位置越靠上），不会影响 view 的层级结构。现有 View 的类型（tag）参见 [BDLFloatingControllerViewTag](#BDLFloatingControllerViewTag)。
 * @param position 插入直播间的位置。详见 [BDLFloatingControllerInsertPosition](#BDLFloatingControllerInsertPosition)。
 * @param dragMode 拖拽模式。详见 [BDLDraggingMode](#BDLDraggingMode) 。
 */
/**
 * @locale en
 * @brief Inserts a custom floating view.
 * @param view The custom floating view, which can be inserted into a specific position in the live room. The views are arranged from top to bottom according to their `view.tag` values (the smaller the tag value, the higher the position), without affecting the views' hierarchy structure. For tags of the existing view, see [BDLFloatingControllerViewTag](#BDLFloatingControllerViewTag).
 * @param position The position to insert in the live room. For more information, see [BDLFloatingControllerInsertPosition](#BDLFloatingControllerInsertPosition).
 * @param dragMode The dragging mode. For more information, see [BDLDraggingMode](#BDLDraggingMode).
 */
- (void)insertFloatingView:(UIView *)view
                  position:(BDLFloatingControllerInsertPosition)position
                  dragMode:(BDLDraggingMode)dragMode;
/**
 * @locale zh
 * @brief 移除插入的自定义悬浮 view。
 * @param view 需要移除的 view。
 */
/**
 * @locale en
 * @brief Removes the inserted custom floating view.
 * @param view The view that needs to be removed.
 */
- (void)removeInsertedFloatingView:(UIView *)view;
/**
 * @locale zh
 * @brief 设置浮窗商品卡片是否支持拖动。
 * @param floatShoppingCardMovable 浮窗商品卡片是否支持拖动。默认值为 `NO`。取值如下：<br>
 *        - `YES`：支持拖动。
 *        - `NO`：不支持拖动。
 */
/**
 * @locale en
 * @brief Whether the floating product card can be dragged.
 * @param floatShoppingCardMovable Whether the floating product card can be dragged. Default value: `NO`. Valid values:
 *        - `YES`: Can be dragged.
 *        - `NO`: Cannot be dragged.
 */
- (void)setFloatShoppingCardMovable:(BOOL)floatShoppingCardMovable;
/**
 * @locale zh
 * @brief 设置浮标广告是否支持拖动。
 * @param floatAdMovable 浮标广告是否支持拖动。默认值为 `NO`。取值如下：<br>
 *        - `YES`：支持拖动。
 *        - `NO`：不支持拖动。
 */
/**
 * @locale en
 * @brief Whether the floating ad can be dragged.
 * @param floatAdMovable Whether the floating ad can be dragged. Default value: `NO`. Valid values:
 *        - `YES`: Can be dragged.
 *        - `NO`: Cannot be dragged.
 */
- (void)setFloatAdMovable:(BOOL)floatAdMovable;
/**
 * @locale zh
 * @brief 自定义浮标广告 view。`BDLUpperAdView` 涉及拖动，请设置 `view.frame` 调整其位置，而非自动布局，但 `BDLUpperAdView` 内部和子 view 则采用自动布局。
 * @param floatingController 浮窗 controller。
 * @param view 浮标广告 view。详见 [BDLUpperAdView](1185540#BDLUpperAdView)。
 * @return `BDLBaseView` 及其子类的实例。
 */
/**
 * @locale en
 * @brief Customizes the floating ad view. The `BDLUpperAdView` involves dragging, so set the `view.frame` to adjust its position instead of using auto layout. However, the interior and subviews of `BDLUpperAdView` use the auto layout.
 * @param floatingController The floating window controller.
 * @param view The floating ad view. For more information, see [BDLUpperAdView](docs-bdlliveengine#BDLUpperAdView).
 * @return Instances of `BDLBaseView` and its subclasses.
 */
@property (nonatomic, copy, nullable) __kindof BDLBaseView * _Nullable (^customizeUpperAdView)(BDLFloatingController *floatingController, BDLUpperAdView *view);
/**
 * @locale zh
 * @brief 自定义浮窗商品卡片 view。不支持设置大小。
 * @param floatingController 浮窗 controller。
 * @param view 浮窗商品卡片 view。详见 [BDLFloatingCardView](1185540#BDLFloatingCardView)。
 * @return 是否显示浮窗商品卡片 view。
 *        - `YES`：显示浮窗商品卡片 view。
 *        - `NO`：隐藏浮窗商品卡片 view。
 */
/**
 * @locale en
 * @brief Customizes the floating product card view. Size setting is not supported.
 * @param floatingController The floating window controller.
 * @param view The floating product card view. For more information, see [BDLFloatingCardView](docs-bdlliveengine#BDLFloatingCardView).
 * @return Whether to display the floating window product card view.
 *
 *         - `YES`: Displays the floating window product card view.
 *         - `NO`: Hides the floating window product card view.
 */
@property (nonatomic, copy, nullable) BOOL (^customizeFloatingCardView)(BDLFloatingController *floatingController, BDLFloatingCardView *view);
/**
 * @locale zh
 * @brief 自定义互动工具浮窗 view 的容器 view。`interactiveToolContainerView` 涉及拖动，请设置 `view.frame` 调整其位置，而非自动布局，但 `interactiveToolContainerView` 内部和子 view 则采用自动布局。
 * @param floatingController 浮窗 controller。
 * @param view 互动工具浮窗 view 的容器 view。
 * @return `UIStackView` 及其子类的实例。
 */
/**
 * @locale en
 * @brief Customizes the container view of the interaction tool floating window view. `interactiveToolContainerView` involves dragging, so set the `view.frame` to adjust its position instead of using auto layout. However, the interior and subviews of `interactiveToolContainerView` use the auto layout.
 * @param floatingController The floating window controller.
 * @param view The container view of the interaction tool floating window view.
 * @return Instances of `UIStackView` and its subclasses.
 */
@property (nonatomic, copy, nullable) __kindof UIStackView * _Nullable (^customizeInteractiveToolContainerView)(BDLFloatingController *floatingController, UIStackView *view);

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
