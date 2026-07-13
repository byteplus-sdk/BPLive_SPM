//
//  BDLHotCommentView.h
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
#import "BDLCommentView.h"
#import "BDLCommentViewConfiguration.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 热门评论 view。继承自 [BDLCommentBaseView](#BDLCommentBaseView)。
 */
/**
 * @locale en
 * @brief The top comment view, which is inherited from [BDLCommentBaseView](#BDLCommentBaseView).
 */
@interface BDLHotCommentView : BDLCommentBaseView

/**
 * @locale zh
 * @brief 评论中的链接点击回调。
 * @param commentView 评论、热门评论以及私聊共同的基类。详见 [BDLCommentBaseView](#BDLCommentBaseView)。
 * @param comment 评论 Model。详见 [BDLCommentModel](1185544#BDLCommentModel)。
 * @param url 点击的链接。
 * @list 评论/私聊
 */
/**
 * @locale en
 * @brief The callback is triggered when the URL in a comment is tapped.
 * @param commentView The common base class for comments and top comments. For more information, see [BDLCommentBaseView](#BDLCommentBaseView).
 * @param comment The comment model. For more information, see [BDLCommentModel](viewer-sdk-for-ios-type-definitions#BDLCommentModel).
 * @param url The tapped URL.
 */
@property (nonatomic, copy, nullable) void (^urlClickBlock)(__kindof BDLCommentBaseView *commentView, BDLCommentModel *comment, NSURL *url);
/**
 * @locale zh
 * @brief 昵称点击回调。
 * @param commentView 评论、热门评论以及私聊共同的基类。详见 [BDLCommentBaseView](#BDLCommentBaseView)。
 * @param comment 评论 Model。详见 [BDLCommentModel](1185544#BDLCommentModel)。
 * @list 评论/私聊
 */
/**
 * @locale en
 * @brief The callback is triggered when the nickname is tapped.
 * @param commentView The common base class for comments and top comments. For more information, see [BDLCommentBaseView](#BDLCommentBaseView).
 * @param comment The comment model. For more information, see [BDLCommentModel](viewer-sdk-for-ios-type-definitions#BDLCommentModel).
 */
@property (nonatomic, copy, nullable) void (^nicknameClickBlock)(__kindof BDLCommentBaseView *commentView, BDLCommentModel *comment);
/**
 * @locale zh
 * @brief 图片评论点击回调。
 * @param commentView 评论、热门评论以及私聊共同的基类。详见 [BDLCommentBaseView](#BDLCommentBaseView)。
 * @param comment 评论 Model。详见 [BDLCommentModel](1185544#BDLCommentModel)。
 * @list 评论/私聊
 */
/**
 * @locale en
 * @brief The callback is triggered when the image comment is tapped.
 * @param commentView The common base class for comments and top comments. For more information, see [BDLCommentBaseView](#BDLCommentBaseView).
 * @param comment The comment model. For more information, see [BDLCommentModel](viewer-sdk-for-ios-type-definitions#BDLCommentModel).
 * @hidden (iOS)
 */
@property (nonatomic, copy, nullable) void (^commentImageClickBlock)(__kindof BDLCommentBaseView *commentView, BDLCommentModel *comment);

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
