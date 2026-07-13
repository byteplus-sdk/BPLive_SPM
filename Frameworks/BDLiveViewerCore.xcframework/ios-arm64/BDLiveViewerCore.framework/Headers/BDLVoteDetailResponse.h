//
//  BDLVoteDetailResponse.h
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

#import <BDLiveBase/BDLBaseResponse.h>
#import "BDLVoteQuizOptionModel.h"
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString* BDLVoteChoiceType;
UIKIT_EXTERN BDLVoteChoiceType BDLVoteChoiceTypeSingle; ///< 单选
UIKIT_EXTERN BDLVoteChoiceType BDLVoteChoiceTypeMultiple;  ///< 多选

typedef NSString* BDLVoteResultView;
UIKIT_EXTERN BDLVoteResultView BDLVoteResultViewAfter; ///< 结果提交后可见
UIKIT_EXTERN BDLVoteResultView BDLVoteResultViewBefore;  ///< 结果提交前可见

typedef NSString* BDLVoteStatus;
UIKIT_EXTERN BDLVoteStatus BDLVoteStatusInit; ///< 新建
UIKIT_EXTERN BDLVoteStatus BDLVoteStatusExport;  ///< 发布（不能编辑）
UIKIT_EXTERN BDLVoteStatus BDLVoteStatusDeadline; ///< 截止
UIKIT_EXTERN BDLVoteStatus BDLVoteStatusDelete;  ///< 删除

@interface BDLVoteDetailModel : BDLBaseModel

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) BDLVoteResultView resultView;
@property (nonatomic, copy) BDLVoteStatus status;
@property (nonatomic, copy) NSArray<NSString *> *userChose;
@property (nonatomic, copy) BDLVoteChoiceType choiceType;
@property (nonatomic, copy) NSArray<BDLVoteQuizOptionModel *> *options;
@property (nonatomic, assign) NSInteger totalCount;
@property (nonatomic, assign) NSInteger deadline;

@end

@interface BDLVoteDetailResponse : BDLBaseResponse

@property (nonatomic, strong) BDLVoteDetailModel *result;

@end

NS_ASSUME_NONNULL_END
