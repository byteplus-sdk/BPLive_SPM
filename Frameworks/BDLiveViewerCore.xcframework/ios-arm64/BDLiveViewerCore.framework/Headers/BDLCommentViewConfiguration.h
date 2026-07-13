//
//  BDLCommentViewConfiguration.h
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


#import "BDLCommentBaseConfiguration.h"
#import "BDLThemeIconModel.h"
#import <BDLiveCommon/BDLCommentModel.h>
#import "BDLCommentTextViewBeginEditingModel.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @brief 评论区底部按钮的 type。
 */
/**
 * @locale en
 * @brief The type of the buttons at the bottom of the comment area.
 */
typedef NS_ENUM(NSInteger, BDLMenuItemType) {
    /**
     * @locale zh
     * @brief 更多选项按钮。
     */
    /**
     * @locale en
     * @brief The more options button.
     */
    BDLMenuItemTypeMoreOptions = 100,
    /**
     * @locale zh
     * @brief 购物车按钮。
     */
    /**
     * @locale en
     * @brief The shopping cart button.
     */
    BDLMenuItemTypeShoppingCard = 200,
    /**
     * @locale zh
     * @brief 礼物按钮。
     */
    /**
     * @locale en
     * @brief The gift button.
     */
    BDLMenuItemTypeGiftReward = 300,
    /**
     * @locale zh
     * @brief 直播间点赞按钮。
     */
    /**
     * @locale en
     * @brief The like button for the live room.
     */
    BDLMenuItemTypeLike = 400,
    /**
     * @locale zh
     * @brief 互动按钮。
     */
    /**
     * @locale en
     * @brief The interactive button.
     */
    BDLMenuItemTypeInteractive = 500,
    /**
     * @locale zh
     * @brief 私聊按钮。
     */
    /**
     * @locale en
     * @brief The private chat button.
     */
    BDLMenuItemTypePrivateChat = 600,
    /**
     * @locale zh
     * @brief 图文按钮。
     */
    /**
     * @locale en
     * @brief The image-text button.
     */
    BDLMenuItemTypeImageText = 700,
    /**
     * @locale zh
     * @brief 嵌入式链接按钮。
     */
    /**
     * @locale en
     * @brief The embedded URL button.
     */
    BDLMenuItemTypeEmbeddedUrl = 800,
    /**
     * @locale zh
     * @brief 分享按钮。
     */
    /**
     * @locale en
     * @brief The share button.
     */
    BDLMenuItemTypeShare = 900,
    
    
    /**
     * @locale zh
     * @brief 自定义添加的按钮
     */
    /**
     * @locale en
     * @brief The custom insert button.
     */
    BDLMenuItemTypeCustom = 0,
    
    BDLMenuItemTypeMax = NSIntegerMax,
};

@class BDLCommentViewCell, BDLCommentView;

/**
 * @locale zh
 * @type keytype
 * @brief 评论区和热门评论配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The configuration of the comment area and top comments.
 */
@interface BDLCommentViewConfiguration : BDLCommentBaseConfiguration

/**
 * @locale zh
 * @brief 评论未点赞状态的点赞按钮。
 */
/**
 * @locale en
 * @brief The like icon when the comment is not liked.
 */
@property (nonatomic, strong, readonly) BDLThemeIconModel *commentLikeIcon;
/**
 * @locale zh
 * @brief 评论已点赞状态的点赞按钮。
 */
/**
 * @locale en
 * @brief The like icon when the comment is liked.
 */
@property (nonatomic, strong, readonly) BDLThemeIconModel *commentLikedIcon;
/**
 * @locale zh
 * @brief 自定义评论 cell。
 * @param view 评论区 view。详见 [BDLCommentView](1185540#BDLCommentView)。
 * @param commentViewCell 评论 cell。详见 [BDLCommentViewCell](1185540#BDLCommentViewCell)。
 * @param comment 评论 Model。详见 [BDLCommentModel](#BDLCommentModel)。
 * @param isPortrait 是否为竖屏直播间。由初始化方法 [initWithActivityId:isPortrait:](1185540#BDLLivePullViewController-initwithactivityid-isportrait-liveengine) 或 [initWithActivityId:isPortrait:basePlayerView:](1185540#BDLLivePullViewController-initwithactivityid-isportrait-liveengine-baseplayerview) 传入。<br>
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
 * @param langType 当前的语言类型。详见 [BDLLanguageType](#BDLLanguageType)。
 * @param langTypes 当前所有支持的语言类型。
 */
/**
 * @locale en
 * @brief Customizes the comment cell.
 * @param view The comment area view. For more information, see [BDLCommentView](docs-bdlliveengine#BDLCommentView).
 * @param commentViewCell The comment cell. For more information, see [BDLCommentViewCell](docs-bdlliveengine#BDLCommentViewCell).
 * @param comment The comment model. For more information, see [BDLCommentModel](#BDLCommentModel).
 * @param isPortrait Whether the live room is in portrait mode. The value is passed in by the initialization method [initWithActivityId:isPortrait:](docs-bdlliveengine#BDLLivePullViewController-initwithactivityid-isportrait-liveengine) or [initWithActivityId:isPortrait:basePlayerView:](docs-bdlliveengine#BDLLivePullViewController-initwithactivityid-isportrait-liveengine-baseplayerview).
 *        - `YES`: Portrait mode.
 *        - `NO`: Landscape mode.
 * @param isCommentTranslateEnable Whether to enable comment translation.
 *        - `YES`: Enable.
 *        - `NO`: Disable.
 * @param isLikeEnable Whether to enable comment liking.
 *        - `YES`: Enable.
 *        - `NO`: Disable.
 * @param isDarkTheme Whether the theme is the dark mode.<br>
 *        - `YES`: The dark mode.
 *        - `NO`: Not the dark mode.
 * @param langType The current language type. For more information, see [BDLLanguageType](#BDLLanguageType).
 * @param langTypes All the currently supported language types.
 */
@property (nonatomic, copy, nullable) void (^customizeCommentCell)(BDLCommentView *view,
                                                                   BDLCommentViewCell *commentViewCell,
                                                                   BDLCommentModel *comment,
                                                                   BOOL isPortrait,
                                                                   BOOL isCommentTranslateEnable,
                                                                   BOOL isLikeEnable,
                                                                   BOOL isDarkTheme,
                                                                   BDLLanguageType langType,
                                                                   NSArray *langTypes);
/**
 * @locale zh
 * @brief 禁用的评论区底部按钮的 type。详见 [BDLMenuItemType](#BDLMenuItemType)。
 */
/**
 * @locale en
 * @brief The types of the disabled buttons at the bottom of the comment area. For more information, see [BDLMenuItemType](#BDLMenuItemType).
 */
@property (nonatomic, copy, nullable) NSArray<NSNumber *> *forbidMenuItemTypes;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 评论区和热门评论配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The configuration of the comment area and top comments.
 */
@interface BDLCommentViewConfiguration (Config)
/**
 * @locale zh
 * @brief 购物车按钮图片。
 */
/**
 * @locale en
 * @brief The image of the shopping cart button.
 */
@property (nonatomic, strong) UIImage *shoppingCardButtonImage;
/**
 * @locale zh
 * @brief 礼物打赏按钮图片。
 */
/**
 * @locale en
 * @brief The image of the gift button.
 */
@property (nonatomic, strong) UIImage *giftIcon;
/**
 * @locale zh
 * @brief 竖屏直播间的互动工具按钮图片。
 */
/**
 * @locale en
 * @brief The image of the interaction tools menu button for the live room in portrait mode.
 */
@property (nonatomic, strong) UIImage *interactiveButtonImage;
/**
 * @locale zh
 * @brief 竖屏直播间的私聊互动按钮图片。
 */
/**
 * @locale en
 * @brief The private chat interaction button image in portrait mode.
 * @hidden (iOS)
 */
@property (nonatomic, strong) UIImage *privateChatButtonImage;
/**
 * @locale zh
 * @brief 竖屏直播间的图文介绍按钮图片。
 */
/**
 * @locale en
 * @brief The image of the graphics menu button for the live room in portrait mode.
 */
@property (nonatomic, strong) UIImage *imageTextButtonImage;
/**
 * @locale zh
 * @brief 竖屏直播间的内嵌链接按钮图片。
 */
/**
 * @locale en
 * @brief The image of the embedded link menu button for the live room in portrait mode.
 */
@property (nonatomic, strong) UIImage *embeddedUrlButtonImage;
/**
 * @locale zh
 * @brief 竖屏直播间的更多选项按钮图片。
 */
/**
 * @locale en
 * @brief The image of the more options button for the live room in portrait mode.
 */
@property (nonatomic, strong) UIImage *moreOptionsButtonImage;
/**
 * @locale zh
 * @brief 竖屏直播间的分享按钮图片。
 */
/**
 * @locale en
 * @brief The image of the share button for the live room in portrait mode.
 */
@property (nonatomic, strong) UIImage *shareImage;
/**
 * @locale zh
 * @brief 欢迎语文字颜色。
 *        :::warning
 *        该属性自 1.53.0 版本开始已废弃，替代属性为 [systemCommentColor](#BDLCommentViewConfiguration(Config)-systemcommentcolor)。
 *        :::
 */
/**
 * @locale en
 * @brief The text color of the welcome message.
 *        :::warning
 *        This property is deprecated since version 1.53.0. Use [systemCommentColor](#BDLCommentViewConfiguration(Config)-systemcommentcolor) instead.
 *        :::
 */
@property (nonatomic, strong) UIColor *welcomeTextColor DEPRECATED_MSG_ATTRIBUTE("This property is deprecated since SDK version 1.53.0, use systemCommentColor instead.");
/**
 * @locale zh
 * @brief 置顶评论中，昵称左侧竖线的颜色。
 */
/**
 * @locale en
 * @brief The color of the vertical line to the left of the nickname in the pinned comment.
 */
@property (nonatomic, strong) UIColor *topCommentTagColor;
/**
 * @locale zh
 * @brief 置顶评论左侧是否需要间距。默认值：`YES`。
 *        - `YES`：需要间距。
 *        - `NO`：不需要间距。
 */
/**
 * @locale en
 * @brief Whether a margin is needed on the left side of the pinned comment. Default value: `YES`.
 *        - `YES`: Needed.
 *        - `NO`: Not needed.
 */
@property (nonatomic, assign) BOOL topCommentNeedMargin;
/**
 * @locale zh
 * @brief 置顶评论展示行数。如果评论超出配置的展示行数，则需点击查看完整内容。默认值：`1`。取值为 `0` 表示无论评论有多少行，均会展示完整评论内容。
 */
/**
 * @locale en
 * @brief The number of lines displayed for the pinned comment. If the comment exceeds the configured number of display lines, viewers must tap to view the full content. Default value: `1`. The
 *        value `0` means that the full content of the comment is displayed regardless of the number of lines.
 */
@property (nonatomic, assign) NSUInteger rowsOfTopComment;
/**
 * @locale zh
 * @brief 置顶评论背景的宽度是否跟随内容宽度变化。默认值：`NO`。
 *
 *        * `YES`：置顶评论背景的宽度跟随内容宽度变化。
 *        * `NO`：置顶评论背景的宽度固定。
 */
/**
 * @locale en
 * @brief Whether the width of the pinned comment background adjusts with the content width. Default value: `NO`.
 *
 *        * `YES`: The width of the pinned comment background adjusts with the content width.
 *        * `NO`: The width of the pinned comment background is fixed.
 */
@property (nonatomic, assign) BOOL topCommentBackgroundWidthFitContent;
/**
 * @locale zh
 * @brief 置顶评论的背景颜色。
 */
/**
 * @locale en
 * @brief The background color of the pinned comment.
 */
@property (nonatomic, strong) UIColor *topCommentBackgroundColor;
/**
 * @locale zh
 * @brief 置顶评论背景的圆角半径。默认值：`8`。单位：point。
 */
/**
 * @locale en
 * @brief The corner radius of the pinned comment‘s background. Default value: `8`. Unit: point.
 */
@property (nonatomic, assign) CGFloat topCommentViewCornerRadius;
/**
 * @locale zh
 * @brief 置顶评论昵称的字体和字号。详见 [UIFont](https://developer.apple.com/documentation/uikit/uifont?language=objc)。
 */
/**
 * @locale en
 * @brief The font and font size of the pinned comment's nickname. For more information, see [UIFont](https://developer.apple.com/documentation/uikit/uifont?language=objc).
 */
@property (nonatomic, strong) UIFont *topCommentNicknameFont;
/**
 * @locale zh
 * @brief 置顶评论昵称的颜色。
 */
/**
 * @locale en
 * @brief The color of the pinned comment's nickname.
 */
@property (nonatomic, strong) UIColor *topCommentNicknameColor;
/**
 * @locale zh
 * @brief 置顶评论内容的行间距。单位为 point。
 *
 *        * 当取值小于等于 `0` 时，使用默认的 [[NSParagraphStyle defaultParagraphStyle].lineSpacing](https://developer.apple.com/documentation/uikit/nsparagraphstyle/linespacing?language=objc)。
 *        * 当取值大于 `0` 时，则赋值给[[NSParagraphStyle defaultParagraphStyle].lineSpacing](https://developer.apple.com/documentation/uikit/nsparagraphstyle/linespacing?language=objc)。
 *
 *        :::tip
 *        该属性仅在 [rowsOfTopComment](#BDLCommentViewConfiguration(Config)-rowsoftopcomment) 的取值为 `0` 或大于 `1` 时生效。
 *        :::
 */
/**
 * @locale en
 * @brief Line spacing for the content of the pinned comment. Unit: point.
 *
 *        * If the value is less than or equal to `0`, the default [[NSParagraphStyle defaultParagraphStyle].lineSpacing](https://developer.apple.com/documentation/uikit/nsparagraphstyle/linespacing?language=objc) is used.
 *        * For values greater than `0`, assign it to [[NSParagraphStyle defaultParagraphStyle].lineSpacing](https://developer.apple.com/documentation/uikit/nsparagraphstyle/linespacing?language=objc).
 *
 *        :::tip
 *        This property is valid only when the value of [rowsOfTopComment](#BDLCommentViewConfiguration(Config)-rowsoftopcomment) is `0` or greater than`1`.
 *        :::
 */
@property (nonatomic, assign) CGFloat topCommentContentLineSpacingExtra;
/**
 * @locale zh
 * @brief 置顶评论字体和字号。
 */
/**
 * @locale en
 * @brief The font and font size of the pinned comment.
 */
@property (nonatomic, strong) UIFont *topCommentFont;
/**
 * @locale zh
 * @brief 置顶评论内容的文字颜色。
 */
/**
 * @locale en
 * @brief The text color for the content of the pinned comment.
 */
@property (nonatomic, strong) UIColor *topCommentFontColor;
/**
 * @locale zh
 * @brief 是否允许观众发送评论。
 *        - `YES`：允许。
 *        - `NO`：不允许。
 */
/**
 * @locale en
 * @brief Whether to allow viewers to send comments.
 *        - `YES`: Allow.
 *        - `NO`: Do not allow.
 */
@property (nonatomic, assign) BOOL isSendCommentEnable;
/**
 * @locale zh
 * @brief 直播间点赞按钮图片。
 */
/**
 * @locale en
 * @brief The image of the button for liking the live room.
 */
@property (nonatomic, strong, nullable) UIImage *thumbUpButtonImage;
/**
 * @locale zh
 * @brief 直播间点赞按钮被点击时的漂浮动画图片。
 */
/**
 * @locale en
 * @brief The floating animation images appeared when the button for liking the live room is tapped.
 */
@property (nonatomic, strong, nullable) NSArray<UIImage *> *thumbUpImages;
/**
 * @locale zh
 * @brief 是否显示评论输入框及其右侧的交互按钮。默认值：`YES`。<br>
 *        - `YES`：显示。
 *        - `NO`：隐藏。
 */
/**
 * @locale en
 * @brief Whether to display the comment text box and the interaction buttons on its right. Default value: `YES`.
 *        - `YES`: Display.
 *        - `NO`: Hide.
 */
@property (nonatomic, assign) BOOL showCommentBottomBar;
/**
 * @locale zh
 * @brief 进场消息中昵称的文字颜色。
 */
/**
 * @locale en
 * @brief The text color of the nickname in the entrance message.
 */
@property (nonatomic, strong) UIColor *joinRoomMsgNicknameColor;
/**
 * @locale zh
 * @brief 进场消息中内容的文字颜色。
 */
/**
 * @locale en
 * @brief The text color of the content in the entrance message.
 */
@property (nonatomic, strong) UIColor *joinRoomMsgContentColor;
/**
 * @locale zh
 * @brief 评论输入框非编辑状态（未弹出键盘时）的底色。支持在观众进入直播间之前或之后修改。
 */
/**
 * @locale en
 * @brief The background color of the comment text box in non-editing status, namely when the keyboard is not popped up. You can modify this property before or after viewers join the live room.
 */
@property (nonatomic, strong) UIColor *inputBoxBackgroundColor;
/**
 * @locale zh
 * @brief 评论输入框非编辑状态（未弹出键盘时）的圆角半径。默认值：`18`。单位：point。支持在观众进入直播间之前或之后修改。
 */
/**
 * @locale en
 * @brief The corner radius of the comment text box in non-editing status, namely when the keyboard is not popped up. Default value: `18`. Unit: point. You can modify this property before or after viewers join the live room.
 */
@property (nonatomic, assign) CGFloat inputBoxCornerRadius;
/**
 * @locale zh
 * @brief 评论输入框非编辑状态（未弹出键盘时）的边框宽度。默认值：`0`。单位：point。支持在观众进入直播间之前或之后修改。
 */
/**
 * @locale en
 * @brief The border width of the comment text box in non-editing status, namely when the keyboard is not popped up. Default value: `0`. Unit: point. You can modify this property before or after viewers join the live room.
 */
@property (nonatomic, assign) CGFloat inputBoxBorderWidth;
/**
 * @locale zh
 * @brief 评论输入框非编辑状态（未弹出键盘时）的边框颜色。支持在观众进入直播间之前或之后修改。
 */
/**
 * @locale en
 * @brief The border color of the comment text box in non-editing status, namely when the keyboard is not popped up. You can modify this property before or after viewers join the live room.
 */
@property (nonatomic, strong) UIColor *inputBoxBorderColor;
/**
 * @locale zh
 * @brief 评论输入框非编辑状态（未弹出键盘时）的提示文字颜色。支持在观众进入直播间之前或之后修改。
 *        ::: tip
 *        该属性自 1.61.0 版本起已废弃，请使用替代属性 [inputBoxPromptTextColor](#BDLCommentViewConfiguration(Config)-inputboxprompttextcolor)。
 *        :::
 */
/**
 * @locale en
 * @brief The placeholder text color of the comment text box in non-editing status, namely when the keyboard is not popped up. You can modify this property before or after viewers join the live room.
 *        :::tip
 *        This property is deprecated since version 1.61.0. Use [inputBoxPromptTextColor](#BDLCommentViewConfiguration(Config)-inputboxprompttextcolor) instead.
 *        :::
 */
@property (nonatomic, strong) UIColor *inputBoxPromptColor DEPRECATED_MSG_ATTRIBUTE("use inputBoxPromptTextColor instead");
/**
 * @locale zh
 * @brief 评论输入框非编辑状态（未弹出键盘时）的提示文字颜色。支持在观众进入直播间之前或之后修改。
 */
/**
 * @locale en
 * @brief The placeholder text color of the comment text box in non-editing status, namely when the keyboard is not popped up. You can modify this property before or after viewers join the live room.
 */
@property (nonatomic, strong) UIColor *inputBoxPromptTextColor;
/**
 * @locale zh
 * @brief 评论输入框编辑状态（弹出键盘时）的提示文字颜色。支持在观众进入直播间之前或之后修改。
 */
/**
 * @locale en
 * @brief The placeholder text color of the comment text box in editing status, namely when the keyboard is popped up. You can modify this property before or after viewers join the live room.
 */
@property (nonatomic, strong) UIColor *popupInputBoxPromptTextColor;

/**
 * @locale zh
 * @brief 是否允许观众在评论输入框中输入内容。
 * @param model 判断是否允许观众在评论输入框中输入内容所需的信息。详见 [BDLCommentTextViewBeginEditingModel](#BDLCommentTextViewBeginEditingModel)。
 * @return - `YES`：允许。
 *         - `NO`：不允许。
 */
/**
 * @locale en
 * @brief Whether to allow viewers to enter content in the comment text box.
 * @param model Information required to determine whether to allow viewers to enter content in the comment text box. For more information, see [BDLCommentTextViewBeginEditingModel](#BDLCommentTextViewBeginEditingModel).
 * @return - `YES`: Allow.
 *         - `NO`: Do not allow.
 */
@property (nonatomic, copy, nullable) BOOL (^textViewShouldBeginEditing)(BDLCommentTextViewBeginEditingModel *model);

/**
 * @locale zh
 * @brief 聊天欢迎语和竖屏模式下直播描述的标签字体、字号等。详见 [UIFont](https://developer.apple.com/documentation/uikit/uifont?language=objc)。
 */
/**
 * @locale en
 * @brief The font, font size, and other properties of the tag for the live room description in portrait mode and welcome message. For more information, see [UIFont](https://developer.apple.com/documentation/uikit/uifont?language=objc).
 */
@property (nonatomic, strong) UIFont *systemTagFont;

/**
 * @locale zh
 * @brief 聊天欢迎语和竖屏模式下直播描述的标签颜色。
 */
/**
 * @locale en
 * @brief The tag color for the live room description in portrait mode and welcome message.
 */
@property (nonatomic, strong) UIColor *systemTagColor;

/**
 * @locale zh
 * @brief 聊天欢迎语和竖屏模式下直播描述的正文字体、字号等。详见 [UIFont](https://developer.apple.com/documentation/uikit/uifont?language=objc)。
 */
/**
 * @locale en
 * @brief The font, font size, and other properties of the body for the live room description in portrait mode and welcome message. For more information, see [UIFont](https://developer.apple.com/documentation/uikit/uifont?language=objc).
 */
@property (nonatomic, strong) UIFont *systemCommentFont;

/**
 * @locale zh
 * @brief 聊天欢迎语和竖屏模式下直播描述的正文颜色。
 */
/**
 * @locale en
 * @brief The body text color for the live room description in portrait mode and welcome message.
 */
@property (nonatomic, strong) UIColor *systemCommentColor;

/**
 * @locale zh
 * @brief 相邻评论单元格之间的间距。默认值：`8`。单位：point。
 */
/**
 * @locale en
 * @brief The spacing between adjacent comment cells. Default value: `8`. Unit: points.
 */
@property (nonatomic, assign) CGFloat distanceBetweenCell;
/**
 * @locale zh
 * @brief 评论 cell 的圆角半径。默认值：`12`。单位：point。
 */
/**
 * @locale en
 * @brief The corner radius of the comment cell. Default value: `12`. Unit: point.
 */
@property (nonatomic, assign) CGFloat commentCellCornerRadius;

/**
 * @locale zh
 * @brief 评论列表底部与评论输入框顶部的间距。默认值：`8`。单位：point。
 */
/**
 * @locale en
 * @brief The spacing between the bottom of the comment list and the top of the comment text box. Default value: `8`. Unit: points.
 */
@property (nonatomic, assign) CGFloat commentListViewBottomMargin;

/**
 * @locale zh
 * @brief 下拉刷新组件内容的颜色，例如 `↓ 下拉加载更多评论`。
 */
/**
 * @locale en
 * @brief The content color of the pull-down refresh component, such as `↓ Pull to load more comments`.
 */
@property (nonatomic, strong) UIColor *commentListPullToRefreshColor;

/**
 * @locale zh
 * @brief 直播间右下角功能入口按钮（例如购物车、互动工具按钮）的圆角半径。默认值：`18`。单位：point。
 */
/**
 * @locale en
 * @brief The corner radius of the functional entry buttons located in the lower-right corner of the live room, such as the shopping cart and interaction tool buttons. Default value: `18`. Unit: point.
 */
@property (nonatomic, assign) CGFloat functionEntranceButtonCornerRadius;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
