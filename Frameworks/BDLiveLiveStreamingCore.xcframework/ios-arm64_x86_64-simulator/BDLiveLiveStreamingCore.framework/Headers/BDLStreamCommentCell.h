//
//  BDLStreamCommentCell.h
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

#import <BDLiveCommon/BDLCommentModel.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 评论区 cell。
 */
@interface BDLStreamCommentCell : UITableViewCell
/**
 * @locale zh
 * @brief 展示评论的Label。
 */
@property (nonatomic, strong, readonly) UITextView *textView;
/**
 * @locale zh
 * @brief 更新cell 内容的方法。
 * @param model 评论Model
 * @param isCommentTranslateEnable 是否开启评论翻译
 */
- (void)updateCellWithModel:(BDLCommentModel *)model
   isCommentTranslateEnable:(BOOL)isCommentTranslateEnable
                  langTypes:(NSArray<NSNumber *> *)langTypes;

@end

NS_ASSUME_NONNULL_END
