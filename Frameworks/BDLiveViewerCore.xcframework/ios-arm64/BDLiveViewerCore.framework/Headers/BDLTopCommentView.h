//
//  BDLTopCommentView.h
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
#import <BDLiveCommon/BDLLanguageService.h>
#import "BDLCommentViewConfiguration.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

@class BDLCommentModel;
@class BDLTopCommentView;

/**
 * @locale zh
 * @type callback
 * @brief 置顶评论 view 的代理方法。
 */
/**
 * @locale en
 * @type callback
 * @brief The delegate methods for the pinned comment view.
 */
@protocol BDLTopCommentViewDelegate <NSObject>

@optional
/**
 * @locale zh
 * @brief 在观众点击评论昵称时，SDK 调用该方法。
 * @param view 置顶评论 view。详见 [BDLTopCommentView](1185540#BDLTopCommentView)。
 * @param comment 评论 Model。详见 [BDLCommentModel](1185544#BDLCommentModel)。
 * @list 评论/私聊
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers tap the comment's nickname.
 * @param view The pinned comment view. For more information, see [BDLTopCommentView](docs-bdlliveengine#BDLTopCommentView).
 * @param comment The comment model. For more information, see [BDLCommentModel](viewer-sdk-for-ios-type-definitions#BDLCommentModel).
 */
- (void)topCommentView:(BDLTopCommentView *)view didClickNicknameWithComment:(BDLCommentModel *)comment;
/**
 * @locale zh
 * @brief 在观众点击图片评论时，SDK 调用该方法。
 * @param view 置顶评论 view。详见 [BDLTopCommentView](1185540#BDLTopCommentView)。
 * @param comment 评论 Model。详见 [BDLCommentModel](1185544#BDLCommentModel)。
 * @list 评论/私聊
 */
/**
 * @locale en
 * @param view
 * @param comment
 * @hidden (iOS)
 */
- (void)topCommentView:(BDLTopCommentView *)view didClickImage:(BDLCommentModel *)comment;
/**
 * @locale zh
 * @brief 在观众点击文字评论或空白区域时，SDK 调用该方法。
 * @param view 置顶评论 view。详见 [BDLTopCommentView](1185540#BDLTopCommentView)。
 * @param comment 评论 Model。详见 [BDLCommentModel](1185544#BDLCommentModel)。
 * @list 评论/私聊
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers tap the text comment or the blank area in the comment.
 * @param view The pinned comment view. For more information, see [BDLTopCommentView](docs-bdlliveengine#BDLTopCommentView).
 * @param comment The comment model. For more information, see [BDLCommentModel](viewer-sdk-for-ios-type-definitions#BDLCommentModel).
 */
- (void)topCommentView:(BDLTopCommentView *)view didClickComment:(BDLCommentModel *)comment;

@end

/**
 * @locale zh
 * @type api
 * @brief 置顶评论 view。
 */
/**
 * @locale en
 * @brief The pinned comment view.
 */
@interface BDLTopCommentView : UIView
/**
 * @locale zh
 * @brief 代理方法。详见 [BDLTopCommentViewDelegate](1185541#BDLTopCommentViewDelegate)。
 */
/**
 * @locale en
 * @brief The delegate method. For more information, see [BDLTopCommentViewDelegate](viewer-SDK-for-ios-callbacks#BDLTopCommentViewDelegate).
 */
@property (nonatomic, weak) id<BDLTopCommentViewDelegate> delegate;
/**
 * @locale zh
 * @brief 当前 view 对应的评论。详见 [BDLCommentModel](1185544#BDLCommentModel)。
 */
/**
 * @locale en
 * @brief The comment corresponding to the current view. For more information, see [BDLCommentModel](viewer-sdk-for-ios-type-definitions#BDLCommentModel).
 */
@property (nonatomic, weak, readonly) BDLCommentModel *comment;
/**
 * @locale zh
 * @brief 根据 comment 更新 view。
 * @param comment 需要显示的评论。详见 [BDLCommentModel](1185544#BDLCommentModel)。
 * @param config 评论的配置。详见 [BDLCommentViewConfiguration](1185544#BDLCommentViewConfiguration)。
 * @param isPortrait 是否为竖屏直播间。<br>
 *        - `YES`：竖屏直播间。
 *        - `NO`：横屏直播间。
 * @param isCommentTranslateEnable 是否开启评论翻译。<br>
 *        - `YES`：开启。
 *        - `NO`：未开启。
 * @param langType 当前的语言类型。详见 [BDLLanguageType](1185544#BDLLanguageType)。
 * @param langTypes 当前所有支持的语言类型。
 * @list 评论/私聊
 */
/**
 * @locale en
 * @brief Updates the view based on the comment.
 * @param comment The comment to display. For more information, see [BDLCommentModel](viewer-sdk-for-ios-type-definitions#BDLCommentModel).
 * @param config The comment configuration. For more information, see [BDLCommentViewConfiguration](viewer-sdk-for-ios-type-definitions#BDLCommentViewConfiguration).
 * @param isPortrait Whether the live room is in portrait mode.<br>
 *        - `YES`: Portrait mode.
 *        - `NO`: Landscape mode.
 * @param isCommentTranslateEnable Whether to enable the comment translation.
 *        - `YES`: Enable.
 *        - `NO`: Disable.
 * @param langType The current language type. For more information, see [BDLLanguageType](viewer-sdk-for-ios-type-definitions#BDLLanguageType).
 * @param langTypes All the currently supported language types.
 */
- (void)updateViewWithComment:(BDLCommentModel *)comment
                       config:(BDLCommentViewConfiguration *)config
                   isPortrait:(BOOL)isPortrait
     isCommentTranslateEnable:(BOOL)isCommentTranslateEnable
                     langType:(BDLLanguageType)langType
                    langTypes:(NSArray *)langTypes;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
