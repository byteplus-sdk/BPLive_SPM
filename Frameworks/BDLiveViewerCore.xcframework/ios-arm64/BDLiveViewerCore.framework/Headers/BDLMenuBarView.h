//
//  BDLMenuBarView.h
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
#import "BDLMenuView.h"
#import "BDLImageTextView.h"
#import "BDLHotCommentView.h"
#import "BDLInteractiveToolView.h"
#import "BDLProductService.h"
#import <BDLiveCommon/BDLLanguageService.h>
#import "BDLMenuService.h"
#import "BDLRichTextService.h"
#import "BDLBasicService.h"
#import "BDLCommentConfigService.h"
#import "BDLMenuBarConfiguration.h"
#import "BDLPrivateChatView.h"
#import "BDLCommentAndNoticeView.h"

#import <WebKit/WebKit.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type keytype
 * @brief 菜单过滤选项。
 */
/**
 * @locale en
 * @type keytype
 * @brief The menu filter options.
 */
typedef NS_OPTIONS(NSUInteger, BDLMenuFilterOption) {
/**
 * @locale zh
 * @brief 聊天互动菜单。
 */
   /**
    * @locale en
    * @brief The menu for chat interaction.
    */
    BDLMenuFilterOptionComment = 1 << 0,
/**
 * @locale zh
 * @brief 热门评论菜单。
 */
   /**
    * @locale en
    * @brief The menu for top comments.
    */
    BDLMenuFilterOptionHotComment = 1 << 1,
/**
 * @locale zh
 * @brief 图文介绍菜单。
 */
   /**
    * @locale en
    * @brief The menu for graphics.
    */
    BDLMenuFilterOptionImageText = 1 << 2,
/**
 * @locale zh
 * @brief 商品卡片菜单。
 */
   /**
    * @locale en
    * @brief The menu for product cards.
    */
    BDLMenuFilterOptionCard = 1 << 3,
/**
 * @locale zh
 * @brief 互动工具菜单。
 */
   /**
    * @locale en
    * @brief The menu for interaction tools.
    */
    BDLMenuFilterOptionInteractiveTool = 1 << 4,
/**
 * @locale zh
 * @brief 私聊互动菜单。
 */
/**
 * @locale en
 * @hidden (iOS)
 * @brief Private Chat Interaction Menu.
 */
    BDLMenuFilterOptionPrivateChat = 1 << 5,
/**
 * @locale zh
 * @brief 内嵌链接菜单。
 */
   /**
    * @locale en
    * @brief The menu for embedded link.
    */
    BDLMenuFilterOptionEmbeddedUrl = BDLMenuFilterOptionPrivateChat << 1,
/**
 * @locale zh
 * @brief 所有的菜单项。
 */
   /**
    * @locale en
    * @brief All menu options.
    */
    BDLMenuFilterOptionAll = NSUIntegerMax,
};

/**
 * @locale zh
 * @type api
 * @brief 菜单栏 view。
 */
/**
 * @locale en
 * @brief The menu bar view.
 */
@interface BDLMenuBarView : BDLBaseView <
BDLProductService
, BDLLanguageService
, BDLMenuService
, BDLRichTextService
, BDLBasicService
, BDLCommentConfigService
>
/**
 * @locale zh
 * @brief 菜单栏配置。详见 [BDLMenuBarConfiguration](1185544#BDLMenuBarConfiguration)。
 */
/**
 * @locale en
 * @brief The configuration of the menu bar. For more information, see [BDLMenuBarConfiguration](viewer-sdk-for-ios-type-definitions#BDLMenuBarConfiguration).
 */
@property (nonatomic, strong, readonly) BDLMenuBarConfiguration *config;
/**
 * @locale zh
 * @brief 菜单栏容器 view，用于实现菜单栏的左右滑动和切换。详见 [BDLMenuView](#BDLMenuView)。
 */
/**
 * @locale en
 * @brief The container view of the menu bar, which is used to implement the left and right sliding and switching of the menu bar. For more information, see [BDLMenuView](#BDLMenuView).
 */
@property (nonatomic, strong) BDLMenuView *menuView;
/**
 * @locale zh
 * @brief 横屏直播间的评论和通知 view。详见 [BDLCommentAndNoticeView](#BDLCommentAndNoticeView)。
 */
/**
 * @locale en
 * @brief The comment and notification view for live rooms in landscape mode. For more information, see [BDLCommentAndNoticeView](#BDLCommentAndNoticeView).
 */
@property (nonatomic, strong, nullable) BDLCommentAndNoticeView *commentAndNoticeView;
/**
 * @locale zh
 * @brief 横屏直播间的热门评论 view。详见 [BDLHotCommentView](#BDLHotCommentView)。
 */
/**
 * @locale en
 * @brief The top comment view for live rooms in landscape mode. For more information, see [BDLHotCommentView](#BDLHotCommentView).
 */
@property (nonatomic, strong, nullable) BDLHotCommentView *hotCommentView;
/**
 * @locale zh
 * @brief 私聊 view。 详见 [BDLPrivateChatView](#BDLPrivateChatView)。
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@property (nonatomic, strong, nullable) BDLPrivateChatView *privateChatView;
/**
 * @locale zh
 * @brief 自定义横屏直播间的评论和通知 view。可自定义除 `hidden`、`frame` 外的所有属性。
 * @param view 菜单栏 view。
 * @param commentAndNoticeView 评论和通知 view。详见 [BDLCommentAndNoticeView](#BDLCommentAndNoticeView)。
 * @list 菜单栏
 */
/**
 * @locale en
 * @brief Customizes the comment and notification view for live rooms in landscape mode. All properties except `hidden` and `frame` can be customized.
 * @param view The menu bar view.
 * @param commentView The comment area view. For more information, see [BDLCommentAndNoticeView](#BDLCommentAndNoticeView).
 * @param commentAndNoticeView The comment and notification view. For more information, see [BDLCommentAndNoticeView](#BDLCommentAndNoticeView).
 */
@property (nonatomic, copy, nullable) void (^customizeCommentAndNoticeView)(BDLMenuBarView *view, BDLCommentAndNoticeView *commentAndNoticeView);
/**
 * @locale zh
 * @brief 自定义横屏直播间的热门评论 view。可自定义除 `hidden`、`frame` 外的所有属性。 如果您隐藏了 `commentView`，则热门评论 view 也不会显示。
 * @param view 菜单栏 view。
 * @param hotCommentView 热门评论 view。详见 [BDLHotCommentView](#BDLHotCommentView)。
 * @list 菜单栏
 * @return `BDLBaseView` 及其子类的实例。
 */
/**
 * @locale en
 * @brief Customizes the top comment view for live rooms in landscape mode. All properties except `hidden` and `frame` can be customized. If you hide the `commentView`, the top comment view is not displayed.
 * @param view The menu bar view.
 * @param hotCommentView The top comment view. For more information, see [BDLHotCommentView](#BDLHotCommentView).
 * @return Instances of `BDLBaseView` and its subclasses.
 */
@property (nonatomic, copy, nullable) __kindof BDLBaseView * _Nullable (^customizeHotCommentView)(BDLMenuBarView *view, BDLHotCommentView *hotCommentView);
/**
 * @locale zh
 * @brief 自定义横屏直播间的图文介绍菜单 view。可自定义除 `hidden`、`frame` 外的所有属性。
 * @param view 菜单栏 view。
 * @param imageTextView 图文介绍菜单 view。详见 [BDLImageTextView](#BDLImageTextView)。
 * @list 菜单栏
 * @return `BDLBaseView` 及其子类的实例。
 */
/**
 * @locale en
 * @brief Customizes the graphics menu view for live rooms in landscape mode. All properties except `hidden` and `frame` can be customized.
 * @param view The menu bar view.
 * @param imageTextView The graphics menu view. For more information, see [BDLImageTextView](#BDLImageTextView).
 * @return Instances of `BDLBaseView` and its subclasses.
 */
@property (nonatomic, copy, nullable) __kindof BDLBaseView * _Nullable (^customizeImageTextView)(BDLMenuBarView *view, BDLImageTextView *imageTextView);
/**
 * @locale zh
 * @brief 自定义私聊 view。可自定义除 `hidden`、`frame` 外的所有属性。
 * @param view 菜单栏 view。
 * @param privateChatView 私聊 view。详见 [BDLPrivateChatView](#BDLPrivateChatView)。
 * @list 菜单栏
 */
/**
 * @locale en
 * @hidden (iOS)
 * @param view Menu bar view.
 * @param privateChatView Private chat view. See [BDLPrivateChatView](#BDLPrivateChatView) for details.
 */
@property (nonatomic, copy, nullable) void (^customizePrivateChatView)(BDLMenuBarView *view, BDLPrivateChatView *privateChatView);
/**
 * @locale zh
 * @brief 自定义内嵌链接 view。可自定义除 `hidden`、`frame` 外的所有属性。
 * @param view 菜单栏 view。
 * @param webView 显示内容的 WebView。
 * @list 菜单栏
 * @return `UIView` 及其子类的实例。
 */
/**
 * @locale en
 * @brief Customizes the embedded link view. All properties except `hidden` and `frame` can be customized.
 * @param view The menu bar view.
 * @param webView The WebView that displays content.
 * @return Instances of `UIView` and its subclasses.
 */
@property (nonatomic, copy, nullable) __kindof UIView * _Nullable (^customizeEmbeddedUrlWebView)(BDLMenuBarView *view, WKWebView *webView);
/**
 * @locale zh
 * @brief 初始化。
 * @param isPortrait 是否以竖屏直播间初始化。<br>
 *        - `YES`：以竖屏直播间初始化。
 *        - `NO`：以横屏直播间初始化。
 * @param filterOption 菜单过滤选项，只显示包含的菜单类型。详见 [BDLMenuFilterOption](1185544#BDLMenuFilterOption)。
 * @list 菜单栏
 * @return 菜单栏 view 实例。
 */
/**
 * @locale en
 * @brief Initializes the instance of the menu bar view.
 * @param isPortrait Whether to initialize in portrait mode.
 *        - `YES`: Portrait mode.
 *        - `NO`: Landscape mode.
 * @param filterOption The menu filter options, displaying only the included menu types. For more information, see [BDLMenuFilterOption](viewer-sdk-for-ios-type-definitions#BDLMenuFilterOption).
 * @return The instance of the menu bar view.
 */
- (instancetype)initWithPortrait:(BOOL)isPortrait filterOption:(BDLMenuFilterOption)filterOption;

/**
 * @locale zh
 * @brief 菜单过滤选项。由初始化方法 [initWithPortrait:filterOption:](#BDLMenuBarView-initwithportrait-filteroption) 传入。
 */
/**
 * @locale en
 * @brief The menu filter options, which is passed in through the initialization method [initWithPortrait:filterOption:](#BDLMenuBarView-initwithportrait-filteroption).
 */
@property (nonatomic, assign, readonly) BDLMenuFilterOption filterOption;

/**
 * @locale zh
 * @brief 在选中的菜单发生变化时，SDK 调用该方法。
 * @param view 菜单栏 view。
 * @param index 当前选中菜单的数组下标，index 从 0 开始计数。
 * @list 菜单栏
 */
/**
 * @locale en
 * @brief The SDK calls this method when the selected menu changes.
 * @param view The menu bar view.
 * @param index The array index of the currently selected menu, with the index starting from 0.
 */
@property (nonatomic, copy, nullable) void(^indexDidChangeBlock)(BDLMenuBarView *view, NSUInteger index);

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
