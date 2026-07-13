//
//  BDLCommentBaseConfiguration.h
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

#import "BDLRTBaseConfiguration.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type keytype
 * @brief 评论、热门评论和私聊的基类配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The base class configuration for comments and top comments.
 */
@interface BDLCommentBaseConfiguration : BDLRTBaseConfiguration

@end

/**
 * @locale zh
 * @type keytype
 * @brief 评论、热门评论和私聊的基类配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The base configuration for comments and top comments.
 */
@interface BDLCommentBaseConfiguration (Config)
/**
 * @locale zh
 * @brief 在横屏直播间中，是否显示头像。默认值：`YES`。<br>
 *        - `YES`：显示头像。
 *        - `NO`：不显示头像。
 */
/**
 * @locale en
 * @brief Whether to display the avatar for the live room in landscape mode. Default value: `YES`.
 *        - `YES`: Display.
 *        - `NO`: Do not display.
 */
@property (nonatomic, assign) BOOL landscapeShouldShowAvatar;
/**
 * @locale zh
 * @brief 在竖屏直播间中，是否显示头像。默认值：`NO`。<br>
 *        - `YES`：显示头像。
 *        - `NO`：不显示头像。
 */
/**
 * @locale en
 * @brief Whether to display the avatar for the live room in portrait mode. Default value: `NO`.
 *        - `YES`: Display.
 *        - `NO`: Do not display.
 */
@property (nonatomic, assign) BOOL portraitShouldShowAvatar;
/**
 * @locale zh
 * @brief 非主持人的默认头像。
 */
/**
 * @locale en
 * @brief The default avatar for non-hosts.
 */
@property (nonatomic, strong) UIImage *defaultAvatar;
/**
 * @locale zh
 * @brief 主持人的默认头像。
 */
/**
 * @locale en
 * @brief The default avatar for the host.
 */
@property (nonatomic, strong) UIImage *defaultHostAvatar;
/**
 * @locale zh
 * @brief 最短发言间隔。单位：秒。默认值：`3`。
 */
/**
 * @locale en
 * @brief The minimum interval between comments. Unit: seconds. Default value: `3`.
 */
@property (nonatomic, assign) NSTimeInterval voiceInterval;
/**
 * @locale zh
 * @brief 非主持人评论的字体、字号等。详见 [UIFont](https://developer.apple.com/documentation/uikit/uifont?language=objc)。
 */
/**
 * @locale en
 * @brief The font, font size, and other properties of non-hosts' comments. For more information, see [UIFont](https://developer.apple.com/documentation/uikit/uifont?language=objc).
 */
@property (nonatomic, strong) UIFont *commentFont;
/**
 * @locale zh
 * @brief 非主持人昵称的字体、字号等。详见 [UIFont](https://developer.apple.com/documentation/uikit/uifont?language=objc)。
 */
/**
 * @locale en
 * @brief The font, font size, and other properties of non-hosts' nicknames. For more information, see [UIFont](https://developer.apple.com/documentation/uikit/uifont?language=objc).
 */
@property (nonatomic, strong) UIFont *nickNameFont;
/**
 * @locale zh
 * @brief 主持人评论的字体、字号等。详见 [UIFont](https://developer.apple.com/documentation/uikit/uifont?language=objc)。
 */
/**
 * @locale en
 * @brief The font, font size, and other properties of the host's comments. For more information, see [UIFont](https://developer.apple.com/documentation/uikit/uifont?language=objc).
 */
 @property (nonatomic, strong) UIFont *hostCommentFont;
/**
 * @locale zh
 * @brief 主持人的评论文字颜色。
 */
/**
 * @locale en
 * @brief The text color of the host's comments.
 */
@property (nonatomic, strong) UIColor *hostCommentColor;
/**
 * @locale zh
 * @brief 主持人标签的字体、字号等。详见 [UIFont](https://developer.apple.com/documentation/uikit/uifont?language=objc)。
 */
/**
 * @locale en
 * @brief The font, font size, and other properties of the host tag. For more information, see [UIFont](https://developer.apple.com/documentation/uikit/uifont?language=objc).
 */
@property (nonatomic, strong) UIFont *hostTagFont;
/**
 * @locale zh
 * @brief 主持人标签的颜色。
 */
/**
 * @locale en
 * @brief The color of the host tag.
 */
 @property (nonatomic, strong) UIColor *hostTagColor;
/**
 * @locale zh
 * @brief 非主持人的昵称文字颜色。
 */
/**
 * @locale en
 * @brief The text color of non-hosts' nicknames.
 */
@property (nonatomic, strong) UIColor *nickNameColor;
/**
 * @locale zh
 * @brief 非主持人的评论文字颜色。
 */
/**
 * @locale en
 * @brief The text color of non-hosts' comments.
 */
@property (nonatomic, strong) UIColor *commentColor;
/**
 * @locale zh
 * @brief 评论中可交互链接的颜色。
 */
/**
 * @locale en
 * @brief The color of clickable URLs in comments.
 */
@property (nonatomic, strong) UIColor *linkColor;
/**
 * @locale zh
 * @brief 主持人的评论底色。
 */
/**
 * @locale en
 * @brief The background color of the host's comments.
 */
@property (nonatomic, strong) UIColor *hostCommentBackgroundColor;
/**
 * @locale zh
 * @brief 聊天欢迎语、进场消息以及非主持人的评论底色。
 */
/**
 * @locale en
 * @brief The background color for the welcome message, entrance message, and non-hosts' comments.
 */
@property (nonatomic, strong) UIColor *backgroundColor;
/**
 * @locale zh
 * @brief 评论输入框非编辑状态（未弹出键盘时）的提示文字。支持在观众进入直播间之前或之后修改。
 */
/**
 * @locale en
 * @brief The placeholder text of the comment text box in non-editing status, namely when the keyboard is not popped up. You can modify this property before or after viewers join the live room.
 */
@property (nonatomic, copy, nullable) NSString *inputBoxPrompt;
/**
 * @locale zh
 * @brief 评论输入框未弹出时的文字颜色。
 */
/**
 * @locale en
 * @brief The color of the text entered in the comment text box.
 */
@property (nonatomic, strong) UIColor *inputBoxTextColor;
/**
 * @locale zh
 * @brief 评论输入框编辑状态（弹出键盘时）输入的文字颜色。支持在观众进入直播间之前或之后修改。
 */
/**
 * @locale en
 * @brief The entered text color for the comment text box in editing status, namely when the keyboard is popped up. You can modify this property before or after viewers join the live room.
 */
@property (nonatomic, strong) UIColor *popupInputBoxTextColor;
/**
 * @locale zh
 * @brief 发送频繁的提示文字。
 */
/**
 * @locale en
 * @brief The prompt text for sending too frequently.
 */
@property (nonatomic, copy) NSString *justSendPrompt;
/**
 * @locale zh
 * @brief 发送频繁提示的字体和字号。
 */
/**
 * @locale en
 * @brief The font and font size of the prompt text for sending too frequently.
 */
@property (nonatomic, strong) UIFont *justSendFont;
/**
 * @locale zh
 * @brief 无评论时的提示图片。
 */
/**
 * @locale en
 * @brief The image displayed when no comments are under the menu.
 */
@property (nonatomic, strong) UIImage *noCommentImage;
/**
 * @locale zh
 * @brief 是否允许点击非主持人评论中的链接。默认值：`NO`。
 *        - `YES`：允许点击。
 *        - `NO`：不允许点击。
 */
/**
 * @locale en
 * @brief Whether URLs in non-hosts' comments are clickable. Default value: `NO`.
 *        - `YES`: Clickable.
 *        - `NO`: Not clickable.
 */
@property (nonatomic, assign) BOOL enableAudienceURLTap;
/**
 * @locale zh
 * @brief 评论展示行数。如果评论超出配置的展示行数，则无法展示完整评论内容。默认值 `0` 表示无论评论有多少行，均会展示完整评论内容。
 */
/**
 * @locale en
 * @brief The number of lines displayed for comments. If a comment exceeds the configured number of display lines, the full content of the comment cannot be displayed. The default value `0` means that the full content of the comment is displayed regardless of the number of lines.
 */
@property (nonatomic, assign) NSUInteger rowsOfComment;
/**
 * @locale zh
 * @brief 评论内容的行间距。单位为 point。
 *
 *        * 当取值小于等于 `0` 时，使用默认的 [[NSParagraphStyle defaultParagraphStyle].lineSpacing](https://developer.apple.com/documentation/uikit/nsparagraphstyle/linespacing?language=objc)。
 *        * 当取值大于 `0` 时，则赋值给[[NSParagraphStyle defaultParagraphStyle].lineSpacing](https://developer.apple.com/documentation/uikit/nsparagraphstyle/linespacing?language=objc)。
 *
 *        :::tip
 *        该属性仅在 [rowsOfComment](#BDLCommentBaseConfiguration(Config)-rowsofcomment) 的取值为 `0` 或大于 `1` 时生效。
 *        :::
 */
/**
 * @locale en
 * @brief Line spacing for the comment content. Unit: point.
 *
 *        * If the value is less than or equal to `0`, the default [[NSParagraphStyle defaultParagraphStyle].lineSpacing](https://developer.apple.com/documentation/uikit/nsparagraphstyle/linespacing?language=objc) is used.
 *        * For values greater than `0`, assign it to [[NSParagraphStyle defaultParagraphStyle].lineSpacing](https://developer.apple.com/documentation/uikit/nsparagraphstyle/linespacing?language=objc).
 *
 *        :::tip
 *        This property is valid only when the value of [rowsOfComment](#BDLCommentBaseConfiguration(Config)-rowsofcomment) is `0` or greater than`1`.
 *        :::
 */
@property (nonatomic, assign) CGFloat commentContentLineSpacingExtra;
/**
 * @locale zh
 * @brief 每次拉取的评论条数。默认值：`20`。
 */
/**
 * @locale en
 * @brief The number of comments to pull each time. Default value: `20`.
 */
@property (nonatomic, assign) NSUInteger singlePullCount;
/**
 * @locale zh
 * @brief 最大拉取的评论条数。默认值：`10,000`。
 */
/**
 * @locale en
 * @brief The maximum number of comments to pull. Default value: `10,000`.
 */
@property (nonatomic, assign) NSUInteger pullMaxNumber;
/**
 * @locale zh
 * @brief 评论输入框内的最大字符数限制。默认值：`200`。
 */
/**
 * @locale en
 * @brief The maximum number of characters allowed in the comment text box. Default value: `200`.
 */
@property (nonatomic, assign) NSUInteger commentInputCountLimit;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
