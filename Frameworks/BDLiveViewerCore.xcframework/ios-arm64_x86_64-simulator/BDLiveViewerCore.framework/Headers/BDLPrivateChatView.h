//
//  BDLPrivateChatView.h
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

#import "BDLCommentInputBaseView.h"
#import "BDLPrivateChatMessageModel.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 私聊 view。
 */
/**
 * @locale en
 * @hidden (iOS)
 * @brief Private chat view.
 */
@interface BDLPrivateChatView : BDLCommentInputBaseView

/**
 * @locale zh
 * @brief 竖屏直播间的菜单名称 label。不支持自定义 `text`。
 */
@property (nonatomic, strong, readonly) UILabel *nameLabel;
/**
 * @locale zh
 * @brief 竖屏直播间的关闭按钮。
 */
@property (nonatomic, strong, readonly) UIButton *closeButton;
/**
 * @locale zh
 * @brief 评论中的链接点击回调。
 * @param privateChatView 私聊 view。
 * @param privateChatMessage 私聊消息 Model。详见 [BDLPrivateChatMessageModel](1185544#BDLPrivateChatMessageModel)。
 * @param url 点击的链接。
 * @list 评论/私聊
 */
/**
 * @locale en
 * @brief Callback for link clicks in comments.
 * @param privateChatView Private chat view.
 * @param privateChatMessage Private chat message model. For details, see [BDLPrivateChatMessageModel](viewer-sdk-for-ios-type-definitions#BDLPrivateChatMessageModel).
 * @param url Click the link.
 */
@property (nonatomic, copy, nullable) void (^urlClickBlock)(__kindof BDLPrivateChatView *privateChatView, BDLPrivateChatMessageModel *privateChatMessage, NSURL *url);
/**
 * @locale zh
 * @brief 昵称点击回调。
 * @param privateChatView 私聊 view。
 * @param privateChatMessage 私聊消息 Model。详见 [BDLPrivateChatMessageModel](1185544#BDLPrivateChatMessageModel)。
 * @list 评论/私聊
 */
/**
 * @locale en
 * @brief Callback when the nickname is clicked.
 * @param privateChatView Direct message view.
 * @param privateChatMessage Private chat message model. For more details, see [BDLPrivateChatMessageModel](viewer-sdk-for-ios-type-definitions#BDLPrivateChatMessageModel).
 */
@property (nonatomic, copy, nullable) void (^nicknameClickBlock)(__kindof BDLPrivateChatView *privateChatView, BDLPrivateChatMessageModel *privateChatMessage);
/**
 * @locale zh
 * @brief 关闭按钮点击回调。
 * @param privateChatView 私聊 view。
 * @list 评论/私聊
 */
/**
 * @locale en
 * @list 
 */
@property (nonatomic, copy, nullable) void (^onCloseBlock)(BDLPrivateChatView *privateChatView);
@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
