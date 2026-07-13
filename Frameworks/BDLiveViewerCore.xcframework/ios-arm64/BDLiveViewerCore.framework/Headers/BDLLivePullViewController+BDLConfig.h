//
//  BDLLivePullViewController+BDLConfig.h
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

#import "BDLLivePullViewController.h"
#import "BDLCommentAndNoticeView.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 完整直播间 controller。
 */
/**
 * @locale en
 * @type api
 * @brief The full-featured live room controller.
 */
@interface BDLLivePullViewController ()

/**
 * @locale zh
 * @brief 显示内容的 `ScrollView`。
 */
/**
 * @locale en
 * @brief The `ScrollView` that displays content.
 */
@property (nonatomic, strong, readonly, nullable) UIScrollView *contentScrollView;

/**
 * @locale zh
 * @brief 背景图 view。
 */
/**
 * @locale en
 * @brief The background image view.
 */
@property (nonatomic, strong, readonly, nullable) UIImageView *backgroundImageView;
/**
 * @locale zh
 * @brief 页头图 view。
 */
/**
 * @locale en
 * @brief The header image view.
 */
@property (nonatomic, strong, readonly, nullable) UIImageView *headerImageView;
/**
 * @locale zh
 * @brief 退出清屏按钮。
 */
/**
 * @locale en
 * @brief The button for exiting the screen clearing.
 */
@property (nonatomic, strong, readonly, nullable) UIButton *exitClearModeButton;
/**
 * @locale zh
 * @brief 浮窗播放器。详见 [BDLFloatingController](1185544#BDLFloatingController)。
 */
/**
 * @locale en
 * @brief The floating player. For more information, see [BDLFloatingController](viewer-sdk-for-ios-type-definitions#BDLFloatingController).
 */
@property (nonatomic, strong, readonly) BDLFloatingController *floatingController;

/**
 * @locale zh
 * @brief 主播账号 view。
 */
/**
 * @locale en
 * @brief The host account view.
 */
@property (nonatomic, strong, readonly, nullable) UIView *accountView;
/**
 * @locale zh
 * @brief 直播间关闭按钮。
 */
/**
 * @locale en
 * @brief The button for closing the live room.
 */
@property (nonatomic, strong, readonly, nullable) UIButton *closeButton;
/**
 * @locale zh
 * @brief 分享按钮。
 */
/**
 * @locale en
 * @brief The share button.
 */
@property (nonatomic, strong, readonly, nullable) UIButton *shareButton;
/**
 * @locale zh
 * @brief 标题 label。<br/>
 *        :::tip
 *        竖屏直播间中，仅在直播间未添加主播账号时，会显示直播标题。<br/>
 *        :::
 */
/**
 * @locale en
 * @brief The title label.
 *        :::tip
 *        For live rooms in portrait mode, the title is displayed only when no host account is added to the live room.
 *        :::
 */
@property (nonatomic, strong, readonly, nullable) UILabel *titleLabel;
/**
 * @locale zh
 * @brief 页中广告 view。
 */
/**
 * @locale en
 * @brief The in-page ad view.
 */
@property (nonatomic, strong, readonly, nullable) UIView *pageAdView;
/**
 * @locale zh
 * @brief 播放器 view。详见 [BDLPlayerView](#BDLPlayerView)。
 */
/**
 * @locale en
 * @brief The player view. For more information, see [BDLPlayerView](#BDLPlayerView).
 */
@property (nonatomic, strong, readonly, nullable) BDLPlayerView *playerView;
/**
 * @locale zh
 * @brief 播放器容器 view。
 */
/**
 * @locale en
 * @brief The container view of the player.
 */
@property (nonatomic, strong, readonly, nullable) UIView *playerContainerView;
/**
 * @locale zh
 * @brief 直播间倒计时 view。
 */
/**
 * @locale en
 * @brief The live room countdown view.
 */
@property (nonatomic, strong, readonly, nullable) UIView *countdownView;
/**
 * @locale zh
 * @brief 直播间倒计时容器 view。
 */
/**
 * @locale en
 * @brief The container view of the live room countdown.
 */
@property (nonatomic, strong, readonly, nonnull) UIView *countdownContainerView;
/**
 * @locale zh
 * @brief 直播描述 view。详见 [BDLLiveDescriptionView](#BDLLiveDescriptionView)。
 */
/**
 * @locale en
 * @brief The live room description view. For more information, see [BDLLiveDescriptionView](#BDLLiveDescriptionView).
 */
@property (nonatomic, strong, readonly, nullable) BDLLiveDescriptionView *liveDescriptionView;
/**
 * @locale zh
 * @brief 评论和通知 view。详见 [BDLCommentAndNoticeView](#BDLCommentAndNoticeView)。
 */
/**
 * @locale en
 * @brief The comment and notification view. For more information, see [BDLCommentAndNoticeView](#BDLCommentAndNoticeView).
 */
@property (nonatomic, strong, readonly, nullable) BDLCommentAndNoticeView *commentAndNoticeView;
/**
 * @locale zh
 * @brief 菜单栏 view。详见 [BDLMenuBarView](#BDLMenuBarView)。
 */
/**
 * @locale en
 * @brief The menu bar view. For more information, see [BDLMenuBarView](#BDLMenuBarView).
 */
@property (nonatomic, strong, readonly, nullable) BDLMenuBarView *menuBarView;
/**
 * @locale zh
 * @brief 竖屏直播间中，直播时移期间的浮窗商品卡片 view。详见 [BDLFloatingCardView](#BDLFloatingCardView)。
 */
/**
 * @locale en
 * @hidden (iOS)
 * @brief In the vertical live streaming room, the floating window product card view during live playback. See [BDLFloatingCardView](#BDLFloatingCardView) for details.
 */
@property (nonatomic, strong, readonly, nullable) BDLFloatingCardView *timeShiftFloatingCardView;
/**
 * @locale zh
 * @brief 竖屏直播间中，直播时移期间的购物车按钮。
 */
/**
 * @locale en
 * @hidden (iOS)
 * @brief The shopping cart button during live streaming time shift in a vertical screen live room.
 */
@property (nonatomic, strong, readonly, nullable) UIButton *timeShiftShoppingCardButton;
/**
 * @locale zh
 * @brief 多语言切换按钮。
 */
/**
 * @locale en
 * @brief The button for changing the viewing page language.
 */
@property (nonatomic, strong, readonly, nullable) UIButton *multiLangButton;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
