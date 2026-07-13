//
//  BDLCommentViewCell.h
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
#import <BDLiveCommon/BDLDefines.h>
#import "BDLCommentViewConfiguration.h"
#import "BDLPrivateChatMessageModel.h"
#import "BDLPrivateChatConfiguration.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

@class BDLCommentViewCell;
@class BDLEmojiManager;

/**
 * @locale zh
 * @brief 评论 cell 的代理方法。
 */
/**
 * @locale en
 * @brief The delegate methods for the comment cell.
 */
@protocol BDLCommentViewCellDelegate <NSObject>

@optional
/**
 * @locale zh
 * @param cell 评论 cell。详见 [BDLCommentViewCell](#BDLCommentViewCell)。
 * @param comment 评论 Model。详见 [BDLCommentModel](1185544#BDLCommentModel)。
 * @brief 在观众点击评论点赞按钮时，SDK 调用该方法。
 * @list 评论/私聊
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers tap the button for liking comments.
 * @param cell The comment cell. For more information, see [BDLCommentViewCell](#BDLCommentViewCell).
 * @param comment The comment model. For more information, see [BDLCommentModel](viewer-sdk-for-ios-type-definitions#BDLCommentModel).
 */
- (void)commentViewCell:(BDLCommentViewCell *)cell didClickLikeWithComment:(BDLCommentModel *)comment;


/**
 * @locale zh
 * @param cell 评论 cell。详见 [BDLCommentViewCell](#BDLCommentViewCell)。
 * @param URL 点击的 URL。
 * @brief 在观众点击评论中的 URL 时，SDK 调用该方法。
 * @list 评论/私聊
 * @return SDK 是否响应该 URL。<br>
 *         - `YES`：响应。
 *         - `NO`：不响应。
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers tap the URL in a comment.
 * @param cell The comment cell. For more information, see [BDLCommentViewCell](#BDLCommentViewCell).
 * @param URL The tapped URL.
 * @return Whether the SDK responds to the URL.
 *         - `YES`: Respond.
 *         - `NO`: Do not respond.
 */
- (BOOL)commentViewCell:(BDLCommentViewCell *)cell shouldInteractWithURL:(NSURL *)URL;

/**
 * @locale zh
 * @param cell 评论 cell。详见 [BDLCommentViewCell](#BDLCommentViewCell)。
 * @param model 评论 Model 或私聊消息 Model。详见 [BDLCommentModel](1185544#BDLCommentModel) 或 [BDLPrivateChatMessageModel](1185544#BDLPrivateChatMessageModel)。
 * @brief 在观众点击评论用户昵称或头像时，SDK 调用该方法。
 * @list 评论/私聊
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers tap the nickname or avatar of a user who sent the comment.
 * @param cell The comment cell. For more information, see [BDLCommentViewCell](#BDLCommentViewCell).
 * @param model The comment model. For more information, see [BDLCommentModel](viewer-sdk-for-ios-type-definitions#BDLCommentModel).
 */
- (void)commentViewCell:(BDLCommentViewCell *)cell didClickNicknameWithModel:(id)model;

/**
 * @locale zh
 * @param cell 评论 cell。详见 [BDLCommentViewCell](#BDLCommentViewCell)。
 * @param model 评论 Model 或私聊消息 Model。详见 [BDLCommentModel](1185544#BDLCommentModel) 或 [BDLPrivateChatMessageModel](1185544#BDLPrivateChatMessageModel)。
 * @brief 在观众点击文字评论时，SDK 调用该方法。
 * @list 评论/私聊
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers tap the text comment.
 * @param cell The comment cell. For more information, see [BDLCommentViewCell](#BDLCommentViewCell).
 * @param model The comment model. For more information, see [BDLCommentModel](viewer-sdk-for-ios-type-definitions#BDLCommentModel).
 */
- (void)commentViewCell:(BDLCommentViewCell *)cell didClickTextContentWithModel:(id)model;

/**
 * @locale zh
 * @param cell 评论 cell。详见 [BDLCommentViewCell](#BDLCommentViewCell)。
 * @param model 评论 Model 或私聊消息 Model。详见 [BDLCommentModel](1185544#BDLCommentModel) 或 [BDLPrivateChatMessageModel](1185544#BDLPrivateChatMessageModel)。
 * @brief 在观众点击评论气泡时，SDK 调用该方法。
 * @list 评论/私聊
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers tap the comment bubble.
 * @param cell The comment cell. For more information, see [BDLCommentViewCell](#BDLCommentViewCell).
 * @param model The comment model. For more information, see [BDLCommentModel](viewer-sdk-for-ios-type-definitions#BDLCommentModel).
 */
- (void)commentViewCell:(BDLCommentViewCell *)cell didClickBackgroundViewWithModel:(id)model;

/**
 * @locale zh
 * @param cell 评论 cell。详见 [BDLCommentViewCell](#BDLCommentViewCell)。
 * @param model 评论 Model 或私聊消息 Model。详见 [BDLCommentModel](1185544#BDLCommentModel) 或 [BDLPrivateChatMessageModel](1185544#BDLPrivateChatMessageModel)。
 * @brief 在观众点击图片评论时，SDK 调用该方法。
 * @list 评论/私聊
 */
/**
 * @locale en
 * @param cell The comment cell. For more information, see [BDLCommentViewCell](#BDLCommentViewCell).
 * @param model The comment model. For more information, see [BDLCommentModel](viewer-sdk-for-ios-type-definitions#BDLCommentModel).
 * @hidden (iOS)
 */
- (void)commentViewCell:(BDLCommentViewCell *)cell didClickImage:(id)model;

@end

/**
 * @locale zh
 * @brief 评论 cell。
 */
/**
 * @locale en
 * @brief The comment cell.
 */
@interface BDLCommentViewCell : UITableViewCell

/**
 * @locale zh
 * @brief 代理方法。详见 [BDLCommentViewCellDelegate](#BDLCommentViewCellDelegate)。
 */
/**
 * @locale en
 * @brief The delegate method. For more information, see [BDLCommentViewCellDelegate](#BDLCommentViewCellDelegate).
 */
@property (nonatomic, weak) id<BDLCommentViewCellDelegate> delegate;
/**
 * @locale zh
 * @brief 评论 Model。详见 [BDLCommentModel](1185544#BDLCommentModel)。
 */
/**
 * @locale en
 * @brief The comment model. For more information, see [BDLCommentModel](viewer-sdk-for-ios-type-definitions#BDLCommentModel).
 */
@property (nonatomic, weak, readonly) BDLCommentModel *comment;
/**
 * @locale zh
 * @brief 私聊消息 Model。详见 [BDLPrivateChatMessageModel](1185544#BDLPrivateChatMessageModel)。
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@property (nonatomic, weak, readonly) BDLPrivateChatMessageModel *privateChatMessage;
// 子类用
/**
 * @locale zh
 * @brief 背景 view。
 */
/**
 * @locale en
 * @brief The background view.
 */
@property (nonatomic, strong, readonly) UIView *bgView;
/**
 * @locale zh
 * @brief 文字内容 view。
 */
/**
 * @locale en
 * @brief The text content view.
 */
@property (nonatomic, strong, readonly) UITextView *textView;
/**
 * @locale zh
 * @brief 评论点赞按钮。
 */
/**
 * @locale en
 * @brief The icon for liking comments.
 */
@property (nonatomic, strong, readonly) UIButton *likeButton;
/**
 * @locale zh
 * @brief 用户头像按钮。
 */
/**
 * @locale en
 * @brief The user avatar button.
 */
@property (nonatomic, strong) UIButton *avatarButton;

/**
 * @locale zh
 * @brief 更新聊天互动评论。
 * @param comment 评论 Model。详见 [BDLCommentModel](1185544#BDLCommentModel)。
 * @param config 评论配置。详见 [BDLCommentViewConfiguration](1185544#BDLCommentViewConfiguration(Config))。
 * @param isPortrait 是否为竖屏直播间。<br>
 *        - `YES`：竖屏直播间。
 *        - `NO`：横屏直播间。
 * @param isCommentTranslateEnable 是否开启评论翻译。<br/>
 *        - `YES`：开启。
 *        - `NO`：未开启。
 * @param isLikeEnable 是否开启评论点赞。<br>
 *        - `YES`：开启。
 *        - `NO`：未开启。
 * @param isDarkTheme 是否为暗黑模式主题。<br>
 *        - `YES`：暗黑模式。
 *        - `NO`：非暗黑模式。
 * @param langType 当前的语言类型。详见 [BDLLanguageType](1185544#BDLLanguageType)。
 * @param langTypes 当前所有支持的语言类型。
 */
/**
 * @locale en
 * @brief Updates the comment under the menu for chat interaction.
 * @param comment The comment model. For more information, see [BDLCommentModel](viewer-sdk-for-ios-type-definitions#BDLCommentModel).
 * @param config The comment configuration. For more information, see [BDLCommentViewConfiguration](viewer-sdk-for-ios-type-definitions#BDLCommentViewConfiguration(Config)).
 * @param isPortrait Whether the live room is in portrait mode.
 *        - `YES`: Portrait mode.
 *        - `NO`: Landscape mode.
 * @param isCommentTranslateEnable Whether to enable the comment translation.
 *        - `YES`: Enable.
 *        - `NO`: Disable.
 * @param isLikeEnable Whether to enable the feature of liking comments.
 *        - `YES`: Enable.
 *        - `NO`: Disable.
 * @param isDarkTheme Whether the theme is dark mode.
 *        - `YES`: Dark mode.
 *        - `NO`: Not dark mode.
 * @param langType The current language type. For more information, see [BDLLanguageType](viewer-sdk-for-ios-type-definitions#BDLLanguageType).
 * @param langTypes All the currently supported language types.
 */
- (void)updateWithComment:(BDLCommentModel *)comment
                   config:(BDLCommentViewConfiguration *)config
               isPortrait:(BOOL)isPortrait
 isCommentTranslateEnable:(BOOL)isCommentTranslateEnable
             isLikeEnable:(BOOL)isLikeEnable
              isDarkTheme:(BOOL)isDarkTheme
                 langType:(BDLLanguageType)langType
                langTypes:(NSArray *)langTypes;


/**
 * @locale zh
 * @brief 更新私聊消息。
 * @param privateChatMessage 私聊消息 Model。详见 [BDLPrivateChatMessageModel](1185544#BDLPrivateChatMessageModel)。
 * @param config 私聊配置。详见 [BDLPrivateChatConfiguration](1185544#BDLPrivateChatConfiguration)。
 * @param isPortrait 是否为竖屏直播间。<br>
 *        - `YES`：竖屏直播间。
 *        - `NO`：横屏直播间。
 * @param langType 当前的语言类型。详见 [BDLLanguageType](1185544#BDLLanguageType)。
 * @param langTypes 当前所有支持的语言类型。
 */
/**
 * @locale en
 * @brief Update private chat message.
 * @param privateChatMessage Private chat message Model. See [BDLPrivateChatMessageModel](viewer-sdk-for-ios-type-definitions#BDLPrivateChatMessageModel) for details.
 * @param config Private chat configuration. For details, see [BDLPrivateChatConfiguration](viewer-sdk-for-ios-type-definitions#BDLPrivateChatConfiguration).
 * @param isPortrait Is it in portrait mode?<br>
 *        - `YES`: Portrait mode.
 *        - `NO`: Landscape mode.
 * @param langType The current language type. See [BDLLanguageType](viewer-sdk-for-ios-type-definitions#BDLLanguageType) for details.
 * @param langTypes All the currently supported language types.
 * @hidden (iOS)
 */
- (void)updateWithPrivateChatMessage:(BDLPrivateChatMessageModel *)privateChatMessage
                              config:(BDLPrivateChatConfiguration *)config
                          isPortrait:(BOOL)isPortrait
                            langType:(BDLLanguageType)langType
                           langTypes:(NSArray *)langTypes;
@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
