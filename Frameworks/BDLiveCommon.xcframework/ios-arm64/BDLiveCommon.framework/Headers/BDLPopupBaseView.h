//
//  BDLPopupBaseView.h
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

#import "BDLBaseView.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type keytype
 * @brief 弹窗显示方向。
 */
/**
 * @locale en
 * @type keytype
 * @brief The display direction of the dialog box.
 */
typedef NS_ENUM(NSInteger, BDLPopupBaseViewShowDirection) {
/**
 * @locale zh
 * @brief 底部显示。
 */
   /**
    * @locale en
    * @brief At the bottom.
    */
    BDLPopupBaseViewShowDirectionBottom,
/**
 * @locale zh
 * @brief 中间显示。
 */
   /**
    * @locale en
    * @brief In the center.
    */
    BDLPopupBaseViewShowDirectionCenter,
/**
 * @locale zh
 * @brief 右侧显示。
 */
   /**
    * @locale en
    * @brief On the right.
    */
    BDLPopupBaseViewShowDirectionRight,
   /**
    * @locale zh
    * @brief 顶部显示。
    */
   /**
    * @locale en
    * @brief At the top.
    */
    BDLPopupBaseViewShowDirectionTop,
};

@class BDLPopupBaseView;

/**
 * @locale zh
 * @type keytype
 * @brief 弹窗基类 view 的协议。
 */
/**
 * @locale en
 * @type keytype
 * @brief The protocol for the base view of the dialog box.
 */
@protocol BDLPopupBaseViewProtocol <NSObject>

/**
 * @locale zh
 * @brief 设置显示弹窗的动画时长。`BDLPopupBaseView` 的实现时长为 0.3 秒。
 * @param duration 动画时长。单位：秒。
 */
/**
 * @locale en
 * @brief Sets the animation duration for displaying the dialog box. The duration implemented by `BDLPopupBaseView` is 0.3 seconds.
 * @param duration The animation duration. Unit: seconds.
 */
- (void)setShowAnimationDuration:(NSTimeInterval)duration;

/**
 * @locale zh
 * @brief 设置隐藏弹窗的动画时长。`BDLPopupBaseView` 的实现时长为 0.3 秒。
 * @param hideDuration 动画时长。单位：秒。
 */
/**
 * @locale en
 * @brief Sets the animation duration for hiding the dialog box. The duration implemented by `BDLPopupBaseView` is 0.3 seconds.
 * @param hideDuration The animation duration. Unit: seconds.
 */
- (void)setHideAnimationDuration:(NSTimeInterval)hideDuration;
/**
 * @locale zh
 * @brief 设置圆角。默认竖屏底部弹窗的左上角和右上角为圆角。
 * @param corner 圆角。
 */
/**
 * @locale en
 * @brief Sets rounded corners. By default, the upper-left and upper-right corners of the dialog box displayed at the bottom of the live room in portrait mode are rounded.
 * @param corner The rounded corner.
 */
- (void)setContentViewCorners:(UIRectCorner)corner;
/**
 * @locale zh
 * @brief 设置弹窗的圆角半径。
 * @param cornerRadii 圆角半径。默认值为 `12`。
 */
/**
 * @locale en
 * @brief Sets the corner radius of the dialog box.
 * @param cornerRadii The corner radius. Default value: `12`.
 */
- (void)setContentViewCornerRadii:(CGFloat)cornerRadii;
/**
 * @locale zh
 * @brief 隐藏弹窗。
 * @param completion 弹窗隐藏后触发该回调。
 */
/**
 * @locale en
 * @brief Hides the dialog box.
 * @param completion The callback triggered after the dialog box is hidden.
 */
- (void)hideWithCompletion:(nullable void (^)(BDLPopupBaseView *view))completion;
/**
 * @locale zh
 * @brief 隐藏弹窗。
 * @param animation 隐藏弹窗时需要额外执行的自定义动画。
 * @param completion 弹窗隐藏后触发该回调。
 */
/**
 * @locale en
 * @brief Hides the dialog box.
 * @param animation The additional custom animations to execute when hiding the dialog box.
 * @param completion The callback triggered after the dialog box is hidden.
 */
- (void)hideWithAnimation:(nullable void (^)(void))animation completion:(nullable void (^)(BDLPopupBaseView *view))completion;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 底部显示弹窗的协议。
 */
/**
 * @locale en
 * @type keytype
 * @brief The protocol for displaying the dialog box at the bottom.
 */
@protocol BDLPopupBottomShowViewProtocol <BDLPopupBaseViewProtocol>

/**
 * @locale zh
 * @brief 设置弹窗的内容 view 与弹窗底部的间距。
 * @param offset 间距。单位：point。默认值：`0`。
 */
/**
 * @locale en
 * @brief Sets the offset between the content view of the dialog box and the bottom of the dialog box.
 * @param offset The offset. Unit: points. Default value: `0`.
 */
- (void)setVerticalOffset:(CGFloat)offset;

/**
 * @locale zh
 * @brief 底部显示弹窗。
 * @param superview 弹窗会作为 superview 的子 view 去显示。
 * @param completion 弹窗显示后触发该回调。
 */
/**
 * @locale en
 * @brief Displays the dialog box at the bottom.
 * @param superview The dialog box will be displayed as a subview of the superview.
 * @param completion The callback triggered after the dialog box is displayed.
 */
- (void)bottomShowInView:(UIView *)superview completion:(nullable void (^)(BDLPopupBaseView *view))completion;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 右侧显示弹窗的协议。
 */
/**
 * @locale en
 * @type keytype
 * @brief The protocol for displaying the dialog box on the right.
 */
@protocol BDLPopupRightShowViewProtocol <BDLPopupBaseViewProtocol>

/**
 * @locale zh
 * @brief 右侧显示弹窗。
 * @param superview 弹窗会作为 superview 的子 view 显示。
 * @param completion 弹窗显示后触发该回调。
 */
/**
 * @locale en
 * @brief Displays the dialog box on the right.
 * @param superview The dialog box will be displayed as a subview of the superview.
 * @param completion The callback triggered after the dialog box is displayed.
 */
- (void)rightShowInView:(UIView *)superview completion:(nullable void (^)(BDLPopupBaseView *view))completion;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 中间显示弹窗的协议。
 */
/**
 * @locale en
 * @type keytype
 * @brief The protocol for displaying the dialog box in the middle.
 */
@protocol BDLPopupCenterShowViewProtocol <BDLPopupBaseViewProtocol>

/**
 * @locale zh
 * @brief 弹窗的内容 view 与 `self.center.y` 的间距。
 * @param offset 间距。单位：point。默认值：`0`。
 */
/**
 * @locale en
 * @brief Sets the offset between the content view of the dialog box and `self.center.y`.
 * @param offset The offset. Unit: points. Default value: `0`.
 */
- (void)setVerticalOffset:(CGFloat)offset;
/**
 * @locale zh
 * @brief 中间显示弹窗。
 * @param superview 弹窗会作为 superview 的子 view 去显示。
 * @param completion 弹窗显示后触发该回调。
 */
/**
 * @locale en
 * @brief Displays the dialog box in the middle.
 * @param superview The dialog box will be displayed as a subview of the superview.
 * @param completion The callback triggered after the dialog box is displayed.
 */
- (void)centerShowInView:(UIView *)superview completion:(nullable void (^)(BDLPopupBaseView *view))completion;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 底部或者右侧显示弹窗的协议。
 */
/**
 * @locale en
 * @type keytype
 * @brief The protocol for displaying the dialog box at the bottom or on the right.
 */
@protocol BDLPopupBottomOrRightShowViewProtocol <BDLPopupBottomShowViewProtocol, BDLPopupRightShowViewProtocol>

@end

/**
 * @locale zh
 * @type keytype
 * @brief 顶部显示弹窗的协议。
 */
/**
 * @locale en
 * @type keytype
 * @brief The protocol for displaying the dialog box on the top.
 */
@protocol BDLPopupTopShowViewProtocol <BDLPopupBaseViewProtocol>

/**
 * @locale zh
 * @brief 设置弹窗的内容 view 与弹窗顶部的间距。
 * @param offset 间距。默认值：`0`。单位：point。
 */
/**
 * @locale en
 * @brief Sets the offset between the content view of the dialog box and the top of the dialog box.
 * @param offset The offset. Unit: points. Default value: `0`.
 */
- (void)setVerticalOffset:(CGFloat)offset;

/**
 * @locale zh
 * @brief 在顶部显示弹窗。
 * @param superview 显示 self 实例的 view。
 * @param completion 弹窗显示完成回调。回调入参 `view`：self 实例，即 [BDLPopupBaseView](#BDLPopupBaseView) 实例或其子类的实例。
 */
/**
 * @locale en
 * @brief Displays the dialog box on the top.
 * @param superview The view to display the self instance.
 * @param completion The callback triggered when the dialog box is displayed. The callback parameter `view` refers to the self instance, which is the instance of [BDLPopupBaseView](#BDLPopupBaseView) or its subclass.
 */
- (void)topShowInView:(UIView *)superview completion:(nullable void (^)(BDLPopupBaseView *view))completion;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 弹窗基类 view。
 */
/**
 * @locale en
 * @type keytype
 * @brief The base view of the dialog box.
 */
@interface BDLPopupBaseView : BDLBaseView <BDLPopupBaseViewProtocol, UIGestureRecognizerDelegate>

/**
 * @locale zh
 * @brief 背景点击回调。如果为空，则点击背景无效。
 * @param view 弹窗基类 view。
 */
/**
 * @locale en
 * @brief The callback is triggered when the background is tapped. If `nil`, tapping the background has no effect.
 * @param view The base view of the dialog box.
 */
@property (nonatomic, copy, nullable) void (^onBackgroundTapCallback)(BDLPopupBaseView *view);
/**
 * @locale zh
 * @brief 弹窗内容 view。`frame` 由子类决定。
 */
/**
 * @locale en
 * @brief The content view of the dialog box. The `frame` is determined by the subclass.
 */
@property (nonatomic, strong, readonly) UIView *contentView;

/**
 * @locale zh
 * @brief self 实例（BDLPopupBaseView 实例或其子类的实例）相对 superView（显示 self 实例的 view）的偏移量。
 */
/**
 * @locale en
 * @brief The offset of the self instance (an instance of `BDLPopupBaseView` or its subclasses) relative to the superView (the view that displays the self instance).
 */
@property (nonatomic) UIEdgeInsets edgeInsets;

/**
 * @locale zh
 * @brief superview 中显示在最上面的 `BDLPopupBaseView` 实例，即最后显示的弹窗。
 * @param superview 需要查找的 view。
 * @return `BDLPopupBaseView` 及其子类的实例。
 */
/**
 * @locale en
 * @brief The `BDLPopupBaseView` instance that appears at the top in the superview, which is the most recently displayed dialog box.
 * @param superview The view to be searched for.
 * @return Instances of `BDLPopupBaseView` and its subclasses.
 */
- (BDLPopupBaseView *)topPopupViewInView:(UIView *)superview;
/**
 * @locale zh
 * @brief superView 中与 self 相邻的 `BDLPopupBaseView` 实例，即当前弹窗的前一个弹窗。
 * @param superview 需要查找的 view。
 * @return `BDLPopupBaseView` 及其子类的实例。
 */
/**
 * @locale en
 * @brief The `BDLPopupBaseView` instance adjacent to self in the superView, which is the previous dialog box of the current dialog box.
 * @param superview The view to be searched for.
 * @return Instances of `BDLPopupBaseView` and its subclasses.
 */
- (BDLPopupBaseView *)neighborPopupViewInView:(UIView *)superview;

@end

/**
 * @locale zh
 * @type api
 * @brief 底部弹窗 view 的基类 view。
 */
/**
 * @locale en
 * @brief The base view of the bottom dialog box view.
 */
@interface BDLPopupBottomShowBaseView : BDLPopupBaseView <BDLPopupBottomShowViewProtocol>

@end

/**
 * @locale zh
 * @type api
 * @brief 右侧弹窗 view 的基类 view。
 */
/**
 * @locale en
 * @brief The base view for the right-side dialog box view.
 */
@interface BDLPopupRightShowBaseView : BDLPopupBaseView <BDLPopupRightShowViewProtocol>

@end

/**
 * @locale zh
 * @type api
 * @brief 中间弹窗 view 的基类 view。
 */
/**
 * @locale en
 * @brief The base view of the center dialog box view.
 */
@interface BDLPopupCenterShowBaseView : BDLPopupBaseView <BDLPopupCenterShowViewProtocol>

@end

/**
 * @locale zh
 * @type api
 * @brief 底部或者右侧弹窗 view 的基类 view。
 */
/**
 * @locale en
 * @brief The base view for bottom or right-side dialog box view.
 */
@interface BDLPopupBottomOrRightShowBaseView : BDLPopupBaseView <BDLPopupBottomOrRightShowViewProtocol>

@end

/**
 * @locale en
 * @type keytype
 * @brief The base view for the top dialog box view.
 */
/**
 * @locale zh
 * @brief 顶部弹窗 view 的基类 view。
 * @type keytype
 */
@interface BDLPopupTopShowBaseView : BDLPopupBaseView <BDLPopupTopShowViewProtocol>

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop

