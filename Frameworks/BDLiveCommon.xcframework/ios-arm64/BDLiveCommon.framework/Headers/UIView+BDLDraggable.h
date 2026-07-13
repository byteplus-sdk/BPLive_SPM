//
//  UIView+BDLDraggable.h
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
#import "BDLDefines.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

/**
 * @locale zh
 * @type callback
 * @brief 拖拽事件的代理方法。
 */
/**
 * @locale en
 * @type callback
 * @brief The delegate methods for dragging events.
 */
@protocol BDLDraggingDelegate <NSObject>

@optional
/**
 * @locale zh
 * @brief 在开始拖拽时，SDK 调用该方法。
 * @param view 当前被拖拽的 view。
 */
/**
 * @locale en
 * @brief The SDK calls this method when dragging begins.
 * @param view The view that is currently being dragged.
 */
- (void)draggingDidBegan:(UIView *)view;
/**
 * @locale zh
 * @brief 在被拖拽的 view 位置发生改变时，SDK 调用该方法。
 * @param view 当前被拖拽的 view。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the position of the view being dragged changes.
 * @param view The view that is currently being dragged.
 */
- (void)draggingDidChanged:(UIView *)view;
/**
 * @locale zh
 * @brief 在结束拖拽时，SDK 调用该方法。
 * @param view 当前被拖拽的 view。
 */
/**
 * @locale en
 * @brief The SDK calls this method when dragging ends.
 * @param view The view that is currently being dragged.
 */
- (void)draggingDidEnded:(UIView *)view;

@end

/**
 * @locale zh
 * @brief 企业直播对 UIView 的拖动相关分类。
 */
/**
 * @locale en
 * @brief The related classification of BytePlus Live for UIView dragging.
 */
@interface UIView (BDLDraggable) <UIGestureRecognizerDelegate>

/**
 * @locale zh
 * @brief 拖拽事件委托，可监听拖拽的开始、变化以及结束事件。 详见 [BDLDraggingDelegate](1185541#BDLDraggingDelegate)。
 */
/**
 * @locale en
 * @brief The drag event delegate, which can listen to the start, change, and end of drag events. For more information, see [BDLDraggingDelegate](viewer-SDK-for-ios-callbacks#BDLDraggingDelegate).
 */
@property (nonatomic, weak) id<BDLDraggingDelegate> bdl_delegate;
/**
 * @locale zh
 * @brief 拖拽模式。默认值：`BDLDraggingModeDisabled`。详见 [BDLDraggingMode](1185544#BDLDraggingMode)。
 */
/**
 * @locale en
 * @brief The dragging mode. Default value: `BDLDraggingModeDisabled`. For more information, see [BDLDraggingMode](viewer-sdk-for-ios-type-definitions#BDLDraggingMode).
 */
@property (nonatomic, assign) BDLDraggingMode bdl_draggingMode;
/**
 * @locale zh
 * @brief 是否可仅在 `superview` 范围内拖动。默认值：`YES`。<br>
 *        - `YES`：可仅在 `superview` 范围内拖动。
 *        - `NO`：可在 `superview` 范围外拖动。超出 `superview` 范围的部分无法再次响应拖拽。
 */
/**
 * @locale en
 * @brief Whether dragging is limited to the `superview` bounds. Default value: `YES`.<br>
 *        - `YES`: Dragging is limited to the `superview` bounds.
 *        - `NO`: Dragging is allowed outside the `superview` bounds. The part outside the `superview` bounds cannot respond to drag actions again.
 */
@property (nonatomic, assign) BOOL bdl_draggingInBounds;
/**
 * @locale zh
 * @brief 不可拖拽的边框区域。默认值：`0`。不支持 `BDLDraggingModeAdsorb`。
 */
/**
 * @locale en
 * @brief The non-draggable border area. Default value: `0`. Not supported for `BDLDraggingModeAdsorb`.
 */
@property (nonatomic, assign) UIEdgeInsets bdl_edgeInsets;
/**
 * @locale zh
 * @brief 主动靠边并吸附。
 * @param animated 是否需要动画。<br>
 *        - `YES`：需要动画。
 *        - `NO`：不需要动画。
 * @list 浮窗
 */
/**
 * @locale en
 * @brief Automatically snaps to and adheres to the edge.
 * @param animated Whether animation is needed.<br>
 *        - `YES`: Needed.
 *        - `NO`: Not needed.
 */
- (void)bdl_adsorbingAnimated:(BOOL)animated;
/**
 * @locale zh
 * @brief 主动靠边。
 * @param animated 是否需要动画。<br>
 *        - `YES`：需要动画。
 *        - `NO`：不需要动画。
 * @list 浮窗
 */
/**
 * @locale en
 * @brief Automatically snaps to the edge.
 * @param animated Whether animation is needed.<br>
 *        - `YES`: Needed.
 *        - `NO`: Not needed.
 */
- (void)bdl_pullOverAnimated:(BOOL)animated;
/**
 * @locale zh
 * @brief 主动还原位置。
 * @param animated 是否需要动画。<br>
 *        - `YES`：需要动画。
 *        - `NO`：不需要动画。
 * @list 浮窗
 */
/**
 * @locale en
 * @brief Automatically reverts to the original position.
 * @param animated Whether animation is needed.<br>
 *        - `YES`: Needed.
 *        - `NO`: Not needed.
 */
- (void)bdl_revertAnimated:(BOOL)animated;

@end

#pragma clang diagnostic pop

