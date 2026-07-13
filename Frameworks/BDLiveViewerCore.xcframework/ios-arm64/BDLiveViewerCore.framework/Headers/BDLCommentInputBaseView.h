//
//  BDLCommentInputBaseView.h
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

#import "BDLCommentBaseView.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 聊天互动评论区和私聊互动评论区共同的父控件。
 */
/**
 * @locale en
 * @brief The parent control of the comment area under the menu for chat interaction.
 */
@interface BDLCommentInputBaseView : BDLCommentBaseView <
UINavigationControllerDelegate,
UIImagePickerControllerDelegate
>

/**
 * @locale zh
 * @brief 弹窗显示的父 view。SDK 内部默认实现了昵称输入框等弹窗效果，弹窗会加到 `popupSuperView` 上面。
 */
/**
 * @locale en
 * @brief The parent view for displaying the dialog box. The SDK has a default implementation for dialog boxes such as the nickname text box. The dialog box will be added on top of `popupSuperView`.
 */
@property (nonatomic, weak) UIView *popupSuperView;
/**
 * @locale zh
 * @brief 新消息提示 view。可自定义除 `hidden`、`frame` 外的所有属性。
 */
/**
 * @locale en
 * @brief The new comment prompt view. All properties except `hidden` and `frame` can be customized.
 */
@property (nonatomic, strong, readonly) UIView *commentPromptView;
/**
 * @locale zh
 * @brief 新消息提示 label。可自定义除 `hidden`、`frame` 外的所有属性。
 */
/**
 * @locale en
 * @brief The new comment notification label. All properties except `hidden` and `frame` can be customized.
 */
@property (nonatomic, strong, readonly) UILabel *commentPromptLabel;
/**
 * @locale zh
 * @brief 重置评论输入框。
 * @param willEdit 是否为编辑状态。
 *        - `YES`：编辑状态。
 *        - `NO`：非编辑状态。
 * @list 评论/私聊
 */
/**
 * @locale en
 * @brief Resets the comment text box.
 * @param willEdit Whether in edit mode.<br>
 *        - `YES`: In edit mode.
 *        - `NO`: Not in edit mode.
 */
- (void)resetTextView:(BOOL)willEdit;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
