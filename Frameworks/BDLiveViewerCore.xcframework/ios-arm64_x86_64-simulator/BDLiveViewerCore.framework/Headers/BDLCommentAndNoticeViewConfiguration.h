//
//  BDLCommentAndNoticeViewConfiguration.h
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


#import "BDLRTBaseConfiguration.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

@class BDLCommentAndNoticeView, BDLCommentView, BDLNoticeContainerView;

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale en
 * @brief The configuration of the comment and notification view.
 */
/**
 * @locale zh
 * @brief 评论和通知 view 配置。
 */
@interface BDLCommentAndNoticeViewConfiguration : BDLRTBaseConfiguration

/**
 * @locale zh
 * @brief 自定义竖屏直播间评论区（包含输入框）的高度。单位：point。默认值：`241`。
 * @param commentAndNoticeView 评论和通知 view。详见 [BDLCommentAndNoticeView](#BDLCommentAndNoticeView)。
 * @return 评论区高度。单位：point。如果返回值小于 `0`，则使用默认配置，即 241 pt。
 */
/**
 * @locale en
 * @brief Customizes the height of the comment area (including the text box) for live rooms in portrait mode. Unit: points. Default value: `241`.
 * @param commentAndNoticeView The comment and notification view. For more information, see [BDLCommentAndNoticeView](#BDLCommentAndNoticeView).
 * @return The height of the comment area. Unit: points. If the return value is less than `0`, the default configuration is used, which is 241 pt.
 */
@property (nonatomic, copy, nullable) CGFloat (^customizePortraitCommentViewHeight)(BDLCommentAndNoticeView *commentAndNoticeView);
/**
 * @locale zh
 * @brief 自定义竖屏直播间的评论 view。可自定义除 `hidden` 外的所有属性。可通过 [customizeViewConstraints](1185544#BDLLivePullViewControllerConfig-customizeviewconstraints) 修改整体的布局，不支持自定义单个属性的布局。
 * @param commentAndNoticeView 评论和通知 view。详见 [BDLCommentAndNoticeView](#BDLCommentAndNoticeView)。
 * @param view 评论区 view。详见 [BDLCommentView](#BDLCommentView)。
 */
/**
 * @locale en
 * @brief Customizes the comment view for live rooms in portrait mode. All properties except `hidden` can be customized. You can modify the overall layout using [customizeViewConstraints](viewer-sdk-for-ios-type-definitions#BDLLivePullViewControllerConfig-customizeviewconstraints), but customizing the layout of individual properties is not supported.
 * @param commentAndNoticeView The comment and notification view. For more information, see [BDLCommentAndNoticeView](#BDLCommentAndNoticeView).
 * @param view The comment area view. For more information, see [BDLCommentView](#BDLCommentView).
 */
@property (nonatomic, copy, nullable) void (^customizeCommentView)(BDLCommentAndNoticeView *commentAndNoticeView, BDLCommentView *view);
/**
 * @locale zh
 * @brief 自定义通知的容器 view。可通过该 view 自定义系统消息（抽奖通知和自定义消息）。
 * @param commentAndNoticeView 评论和通知 view。详见 [BDLCommentAndNoticeView](#BDLCommentAndNoticeView)。
 * @param view 通知的容器 view。详见 [BDLNoticeContainerView](1185540#BDLNoticeContainerView)。
 */
/**
 * @locale en
 * @brief Customizes the container view of notifications. You can use this view to customize system notifications, such as lucky draw notifications.
 * @param commentAndNoticeView The comment and notification view. For more information, see [BDLCommentAndNoticeView](#BDLCommentAndNoticeView).
 * @param view The container view of notifications. For more information, see [BDLNoticeContainerView](docs-bdlliveengine#BDLNoticeContainerView).
 */
@property (nonatomic, copy, nullable) void (^customizeNoticeContainerView)(BDLCommentAndNoticeView *commentAndNoticeView, BDLNoticeContainerView *view);

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
