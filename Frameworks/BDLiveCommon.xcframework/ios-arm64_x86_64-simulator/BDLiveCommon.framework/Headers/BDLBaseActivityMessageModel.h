//
//  BDLBaseActivityMessageModel.h
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
#import <BDLiveBase/BDLBaseModel.h>
#import "BDLCommentModel.h"
#import "BDLGiftRewardResultModel.h"

// 活动消息 包含评论、互动工具等类型
@interface BDLBaseActivityMessageModel : BDLBaseModel

// 评论数据
@property (nonatomic, strong) NSArray<BDLCommentModel *> *comments;

// 热门评论数据
@property (nonatomic, strong) NSArray<BDLCommentModel *> *hotComments;

// 置顶评论
@property (nonatomic, strong) NSArray<BDLCommentModel *> *topComments;

// 已删除评论
@property (nonatomic, strong) NSArray<NSString *> *deletedCommentIds;

@property (nonatomic, assign) BOOL downgradeFlag;

// 打赏消息
@property (nonatomic, strong) NSArray<BDLGiftRewardResultModel *> *giftRewards;

+ (BOOL)isComments:(NSArray<BDLCommentModel *> *)lhs equalWith:(NSArray<BDLCommentModel *> *)rhs;

- (BOOL)isCommentsEqual:(BDLBaseActivityMessageModel *)object;
- (BOOL)isHotCommentsEqual:(BDLBaseActivityMessageModel *)object;
- (BOOL)isTopCommentsEqual:(BDLBaseActivityMessageModel *)object;
- (BOOL)isDeletedCommentIdsEqual:(BDLBaseActivityMessageModel *)object;
- (BOOL)isDeletedIds:(NSArray<NSString *> *)lhs equalWith:(NSArray<NSString *> *)rhs;

@end
