//
//  BDLPopupTopCommentView.h
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


#import <BDLiveCommon/BDLPopupBaseView.h>
#import <BDLiveCommon/BDLCommentModel.h>
#import "BDLPopupTopCommentViewConfiguration.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 置顶评论详情弹窗。
 */
/**
 * @locale en
 * @brief The pinned comment details dialog box.
 */
@interface BDLPopupTopCommentView : BDLPopupBottomShowBaseView

/**
 * @locale zh
 * @brief 置顶评论详情弹窗配置。详见 [BDLPopupTopCommentViewConfiguration](1185544#BDLPopupTopCommentViewConfiguration(Config))。
 */
/**
 * @locale en
 * @brief The configuration of the pinned comment details dialog box. For more information, see [BDLPopupTopCommentViewConfiguration](viewer-sdk-for-ios-type-definitions#BDLPopupTopCommentViewConfiguration(Config)).
 */
@property (nonatomic, strong, readonly) BDLPopupTopCommentViewConfiguration *config;
/**
 * @locale zh
 * @brief 返回按钮。可自定义除 `frame` 外的所有属性。
 */
/**
 * @locale en
 * @brief The back button. All properties except `frame` can be customized.
 */
@property (nonatomic, strong, readonly, nullable) UIButton *backButton;
/**
 * @locale zh
 * @brief 文本显示。可自定义除 `attributedText`、`font` 外的所有属性。如需自定义 `font`，可通过 [contentFont](1185544#BDLPopupTopCommentViewConfiguration(Config)-contentfont) 设置。
 */
/**
 * @locale en
 * @brief The text display. All properties except `attributedText` and `font` can be customized. You can customize the `font` by using [contentFont](viewer-sdk-for-ios-type-definitions#BDLPopupTopCommentViewConfiguration(Config)-contentfont).
 */
@property (nonatomic, strong, readonly, nullable) UITextView *textView;
/**
 * @locale zh
 * @brief 初始化。
 * @param comment 需要显示的评论。详见 [BDLCommentModel](1185544#BDLCommentModel)。
 * @param isPortrait 是否以竖屏直播间初始化。<br>
 *        - `YES`：以竖屏直播间初始化。
 *        - `NO`：以横屏直播间初始化。
 * @return 置顶评论详情弹窗实例。
 */
/**
 * @locale en
 * @brief Initializes the instance of the pinned comment details dialog box.
 * @param comment The comment to display. For more information, see [BDLCommentModel](viewer-sdk-for-ios-type-definitions#BDLCommentModel).
 * @param isPortrait Whether to initialize in portrait mode.
 *        - `YES`: Portrait mode.
 *        - `NO`: Landscape mode.
 * @return The instance of the pinned comment details dialog box.
 */
- (instancetype)initWithComment:(BDLCommentModel *)comment isPortrait:(BOOL)isPortrait;
/**
 * @locale zh
 * @brief 评论中 URL 点击回调。
 * @param url 点击的 URL。
 */
/**
 * @locale en
 * @brief The callback is triggered when the URL in a comment is tapped.
 * @param url The tapped URL.
 */
@property (nonatomic, copy, nullable) void (^urlClickBlock)(NSURL *url);
/**
 * @locale zh
 * @brief 评论昵称点击回调。
 * @param popupView 当前 BDLPopupTopCommentView 实例。
 * @param comment 评论 Model。详见 [BDLCommentModel](1185544#BDLCommentModel)。
 */
/**
 * @locale en
 * @brief The callback is triggered when a comment nickname is tapped.
 * @param popupView The current `BDLPopupTopCommentView` instance.
 * @param comment The comment model. For more information, see [BDLCommentModel](viewer-sdk-for-ios-type-definitions#BDLCommentModel).
 */
@property (nonatomic, copy, nullable) void (^commentNicknameClick)(BDLPopupTopCommentView *popupView, BDLCommentModel *comment);

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
