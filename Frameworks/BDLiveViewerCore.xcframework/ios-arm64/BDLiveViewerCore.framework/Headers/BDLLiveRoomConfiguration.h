//
//  BDLLiveRoomConfiguration.h
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


#import <Foundation/Foundation.h>

#import "BDLPopupTopCommentViewConfiguration.h"
#import "BDLPopupWebViewConfiguration.h"
#import "BDLPopupInputViewConfiguration.h"
#import "BDLCommentViewConfiguration.h"
#import "BDLCardConfiguration.h"
#import "BDLPlayerConfiguration.h"
#import "BDLBasePlayerConfiguration.h"
#import "BDLImageTextViewConfiguration.h"
#import "BDLInteractiveToolConfiguration.h"
#import "BDLMenuBarConfiguration.h"
#import "BDLMenuViewConfiguration.h"
#import "BDLFloatingCardConfiguration.h"
#import "BDLPageAdViewConfiguration.h"
#import "BDLMoreOptionsViewConfiguration.h"
#import "BDLAwardConfiguration.h"
#import "BDLPrivateChatConfiguration.h"
#import "BDLMultiLanguageConfiguration.h"
#import "BDLUserInfoConfiguration.h"
#import "BDLPeopleCountConfiguration.h"
#import "BDLCommentAndNoticeViewConfiguration.h"
#import "BDLBusinessAccountConfiguration.h"
#import "BDLFloatingControllerConfiguration.h"
#import "BDLExternalReportConfiguration.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type keytype
 * @brief 直播间配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The live room configuration.
 */
@interface BDLLiveRoomConfiguration : NSObject
/**
 * @locale zh
 * @brief 置顶评论详情弹窗配置。详见 [BDLPopupTopCommentViewConfiguration(Config)](#BDLPopupTopCommentViewConfiguration(Config))。
 */
/**
 * @locale en
 * @brief The configuration of the pinned comment details dialog box. For more information, see [BDLPopupTopCommentViewConfiguration(Config)](#BDLPopupTopCommentViewConfiguration(Config)).
 */
@property (nonatomic, strong) BDLPopupTopCommentViewConfiguration *popupTopCommentViewConfig;
/**
 * @locale zh
 * @brief WebView 弹窗配置。详见 [BDLPopupWebViewConfiguration(Config)](#BDLPopupWebViewConfiguration(Config))。
 */
/**
 * @locale en
 * @brief The WebView dialog box configuration. For more information, see [BDLPopupWebViewConfiguration(Config)](#BDLPopupWebViewConfiguration(Config)).
 */
@property (nonatomic, strong) BDLPopupWebViewConfiguration *popupWebViewConfig;
/**
 * @locale zh
 * @brief 昵称输入框配置。详见 [BDLPopupInputViewConfiguration](#BDLPopupInputViewConfiguration)。
 */
/**
 * @locale en
 * @brief The configuration of the nickname text box. For more information, see [BDLPopupInputViewConfiguration](#BDLPopupInputViewConfiguration).
 */
@property (nonatomic, strong) BDLPopupInputViewConfiguration *popupInputViewConfig;
/**
 * @locale zh
 * @brief 评论区和热门评论配置。详见 [BDLCommentViewConfiguration](#BDLCommentViewConfiguration)。
 */
/**
 * @locale en
 * @brief The configuration of the comment area and top comments. For more information, see [BDLCommentViewConfiguration](#BDLCommentViewConfiguration).
 */
@property (nonatomic, strong) BDLCommentViewConfiguration *commentViewConfig;
/**
 * @locale zh
 * @brief 私聊配置。详见 [BDLPrivateChatConfiguration](#BDLPrivateChatConfiguration)。
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@property (nonatomic, strong) BDLPrivateChatConfiguration *privateChatConfig;
/**
 * @locale zh
 * @brief 商品卡片配置。详见 [BDLCardConfiguration](#BDLCardConfiguration(Config))。
 */
/**
 * @locale en
 * @brief The product card configuration. For more information, see [BDLCardConfiguration](#BDLCardConfiguration(Config)).
 */
@property (nonatomic, strong) BDLCardConfiguration *cardConfig;
/**
 * @locale zh
 * @brief 播放器配置。详见 [BDLPlayerConfiguration](#BDLPlayerConfiguration)。
 */
/**
 * @locale en
 * @brief The player configuration. For more information, see [BDLPlayerConfiguration](#BDLPlayerConfiguration).
 */
@property (nonatomic, strong) BDLPlayerConfiguration *playerConfig;
/**
 * @locale zh
 * @brief 独立播放器配置。详见 [BDLBasePlayerConfiguration](#BDLBasePlayerConfiguration)。
 */
/**
 * @locale en
 * @brief The custom player configuration. For more information, see [BDLBasePlayerConfiguration](#BDLBasePlayerConfiguration).
 */
@property (nonatomic, strong) BDLBasePlayerConfiguration *basePlayerConfig;
/**
 * @locale zh
 * @brief 图文介绍菜单配置。详见 [BDLImageTextViewConfiguration](#BDLImageTextViewConfiguration)。
 */
/**
 * @locale en
 * @brief The configuration of the menu for graphics. For more information, see [BDLImageTextViewConfiguration](#BDLImageTextViewConfiguration).
 */
@property (nonatomic, strong) BDLImageTextViewConfiguration *imageTextViewConfig;
/**
 * @locale zh
 * @brief 互动工具菜单配置。详见 [BDLInteractiveToolConfiguration](#BDLInteractiveToolConfiguration)。
 */
/**
 * @locale en
 * @brief The configuration of the menu for interaction tools. For more information, see [BDLInteractiveToolConfiguration](#BDLInteractiveToolConfiguration).
 */
@property (nonatomic, strong) BDLInteractiveToolConfiguration *interactiveToolConfig;
/**
 * @locale zh
 * @brief 菜单栏配置。详见 [BDLMenuBarConfiguration](#BDLMenuBarConfiguration)。
 */
/**
 * @locale en
 * @brief The menu bar configuration. For more information, see [BDLMenuBarConfiguration](#BDLMenuBarConfiguration).
 */
@property (nonatomic, strong) BDLMenuBarConfiguration *menuBarConfig;
/**
 * @locale zh
 * @brief 菜单栏容器 view 配置。详见 [BDLMenuViewConfiguration](#BDLMenuViewConfiguration)。
 */
/**
 * @locale en
 * @brief The configuration of the menu bar container view. For more information, see [BDLMenuViewConfiguration](#BDLMenuViewConfiguration).
 */
@property (nonatomic, strong) BDLMenuViewConfiguration *menuViewConfig;
/**
 * @locale zh
 * @brief 浮窗商品卡片配置。详见 [BDLFloatingCardConfiguration](#BDLFloatingCardConfiguration(Config))。
 */
/**
 * @locale en
 * @brief The floating product card configuration. For more information, see [BDLFloatingCardConfiguration](#BDLFloatingCardConfiguration(Config)).
 */
@property (nonatomic, strong) BDLFloatingCardConfiguration *floatingCardConfig;
/**
 * @locale zh
 * @brief 页中广告配置。详见 [BDLPageAdViewConfiguration](#BDLPageAdViewConfiguration)。
 */
/**
 * @locale en
 * @brief The in-page ad configuration. For more information, see [BDLPageAdViewConfiguration](#BDLPageAdViewConfiguration).
 */
@property (nonatomic, strong) BDLPageAdViewConfiguration *pageAdViewConfig;
/**
 * @locale zh
 * @brief 更多选项弹窗配置。详见 [BDLMoreOptionsViewConfiguration](#BDLMoreOptionsViewConfiguration)。
 */
/**
 * @locale en
 * @brief The configuration of the more options dialog box. For more information, see [BDLMoreOptionsViewConfiguration](#BDLMoreOptionsViewConfiguration).
 */
@property (nonatomic, strong) BDLMoreOptionsViewConfiguration *moreOptionsViewConfig;
/**
 * @locale zh
 * @brief 抽奖配置。详见 [BDLAwardConfiguration](#BDLAwardConfiguration)。
 */
/**
 * @locale en
 * @brief The lucky draw configuration. For more information, see [BDLAwardConfiguration](#BDLAwardConfiguration).
 */
@property (nonatomic, strong) BDLAwardConfiguration *awardConfig;
/**
 * @locale zh
 * @brief 多语言自定义配置。详见 [BDLMultiLanguageConfiguration](#BDLMultiLanguageConfiguration)。
 */
/**
 * @locale en
 * @brief The configuration of multi-language customization. For more information, see [BDLMultiLanguageConfiguration](#BDLMultiLanguageConfiguration).
 */
@property (nonatomic, strong) BDLMultiLanguageConfiguration *multiLanguageConfig;

/**
 * @locale zh
 * @brief 用户信息配置。详见 [BDLUserInfoConfiguration](#BDLUserInfoConfiguration)。
 */
/**
 * @locale en
 * @brief The user information configuration. For more information, see [BDLUserInfoConfiguration](#BDLUserInfoConfiguration).
 */
@property (nonatomic, strong) BDLUserInfoConfiguration *userInfoConfig;

/**
 * @locale zh
 * @brief 人气配置。详见 [BDLPeopleCountConfiguration](1185540#BDLPeopleCountConfiguration(Config))。
 */
/**
 * @locale en
 * @brief The popularity configuration. For more information, see [BDLPeopleCountConfiguration](docs-bdlliveengine#BDLPeopleCountConfiguration(Config)).
 */
@property (nonatomic, strong) BDLPeopleCountConfiguration *peopleCountConfig;
/**
 * @locale zh
 * @brief 主播账号配置。详见 [BDLBusinessAccountConfiguration](#BDLBusinessAccountConfiguration(Config))。
 */
/**
 * @locale en
 * @brief The host account configuration. For more information, see [BDLBusinessAccountConfiguration](#BDLBusinessAccountConfiguration(Config)).
 */
@property (nonatomic, strong) BDLBusinessAccountConfiguration *businessAccountConfig;
/**
 * @locale zh
 * @brief 评论和通知 view 配置。详见 [BDLCommentAndNoticeViewConfiguration](1185540#BDLCommentAndNoticeViewConfiguration)。
 */
 /**
 * @locale en
 * @brief The configuration of the comment and notification view. For more information, see [BDLCommentAndNoticeViewConfiguration](docs-bdlliveengine#BDLCommentAndNoticeViewConfiguration).
 */
@property (nonatomic, strong) BDLCommentAndNoticeViewConfiguration *commentAndNoticeViewConfig;
/**
 * @locale zh
 * @brief 浮窗 controller 配置。详见 [BDLFloatingControllerConfiguration](#BDLFloatingControllerConfiguration)。
 */
/**
 * @locale en
 * @brief The configuration of the floating window controller. For more information, see [BDLFloatingControllerConfiguration](#BDLFloatingControllerConfiguration).
 */
@property (nonatomic, strong) BDLFloatingControllerConfiguration *floatingControllerConfig;

/**
 * @locale zh
 * @brief 数据上报配置。详见 [BDLExternalReportConfiguration](#BDLExternalReportConfiguration)。
 */
/**
 * @locale en
 * @brief Data reporting configuration. For more information, see [BDLExternalReportConfiguration](#BDLExternalReportConfiguration).
 */
@property (nonatomic, strong) BDLExternalReportConfiguration *externalReportConfig;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
