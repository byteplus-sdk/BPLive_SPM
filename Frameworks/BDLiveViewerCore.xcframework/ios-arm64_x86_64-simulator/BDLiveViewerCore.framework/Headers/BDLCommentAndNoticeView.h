//
//  BDLCommentAndNoticeView.h
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
#import "BDLCommentView.h"
#import "BDLNoticeContainerView.h"
#import "BDLGiftRewardNoticeContainerView.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 评论和通知 view。
 */
/**
 * @locale en
 * @brief The comment and notification view.
 */
@interface BDLCommentAndNoticeView : BDLBaseView
/**
 * @locale zh
 * @type api
 * @brief 通知的容器 view。详见 [BDLNoticeContainerView](#BDLNoticeContainerView)。
 */
/**
 * @locale en
 * @brief The container view of notifications. For more information, see [BDLNoticeContainerView](#BDLNoticeContainerView).
 */
@property (nonatomic, strong, readonly) BDLNoticeContainerView *noticeContainerView;
/**
 * @locale zh
 * @brief 评论区 view。详见 [BDLCommentView](#BDLCommentView)。
 */
/**
 * @locale en
 * @brief The comment area view. For more information, see [BDLCommentView](#BDLCommentView).
 */
@property (nonatomic, strong, readonly) BDLCommentView *commentView;
/**
 * @locale zh
 * @brief 置顶文字评论点击回调。
 * @param view 评论和通知 view。
 * @param comment 点击的评论。详见 [BDLCommentModel](1185544#BDLCommentModel)。
 * @list 评论/私聊
 */
/**
 * @locale en
 * @brief The callback is triggered when the pinned text comment is tapped.
 * @param view The comment and notification view.
 * @param comment The tapped comment. For more information, see [BDLCommentModel](viewer-sdk-for-ios-type-definitions#BDLCommentModel).
 */
@property (nonatomic, copy, nullable) void (^topCommentClickBlock)(BDLCommentAndNoticeView *view, BDLCommentModel *comment);
/**
 * @locale zh
 * @brief 置顶评论昵称点击回调。
 * @param view 评论和通知 view。
 * @param comment 评论 Model。详见 [BDLCommentModel](1185544#BDLCommentModel)。
 * @list 评论/私聊
 */
/**
 * @locale en
 * @brief The callback is triggered when the nickname of the pinned comment is tapped.
 * @param view The comment and notification view.
 * @param comment The comment model. For more information, see [BDLCommentModel](viewer-sdk-for-ios-type-definitions#BDLCommentModel).
 */
@property (nonatomic, copy, nullable) void (^topCommentNicknameClickBlock)(BDLCommentAndNoticeView *view, BDLCommentModel *comment);
/**
 * @locale zh
 * @brief 置顶图片评论点击回调。
 * @param view 评论和通知 view。
 * @param comment 评论 Model。详见 [BDLCommentModel](1185544#BDLCommentModel)。
 * @list 评论/私聊
 */
/**
 * @locale en
 * @param view
 * @param comment
 * @hidden (iOS)
 */
@property (nonatomic, copy, nullable) void (^topCommentImageClickBlock)(BDLCommentAndNoticeView *view, BDLCommentModel *comment);

/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
- (instancetype)initWithPortrait:(BOOL)isPortrait
                  popupSuperView:(UIView *)popupSuperView;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
