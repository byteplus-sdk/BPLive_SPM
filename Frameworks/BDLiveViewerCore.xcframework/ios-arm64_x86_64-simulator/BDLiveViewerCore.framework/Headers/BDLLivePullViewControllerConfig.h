//
//  BDLLivePullViewControllerConfig.h
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
#import "BDLPageAdView.h"
#import "BDLBusinessAccountView.h"
#import "BDLCommentView.h"
#import "BDLMultiLanguageView.h"
#import "BDLPlayerView.h"
#import "BDLMenuBarView.h"
#import "BDLInteractiveToolView.h"
#import "BDLLiveDescriptionView.h"
#import "BDLMoreOptionsView.h"
#import "BDLCountdownView.h"
#import "BDLRiskWarningView.h"
#import "BDLInteractiveToolController.h"
#import "BDLShoppingCardController.h"
#import "BDLFloatingController.h"
#import "BDLPopupTopCommentView.h"
#import "BDLPopupWebView.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

@class BDLLivePullViewController;

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type keytype
 * @brief 完整直播间配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The configuration of the full-featured live room.
 */
@interface BDLLivePullViewControllerConfig : NSObject
/**
 * @locale zh
 * @brief 设置点击评论中的链接后是否在直播间浮层展示跳转内容。默认值：`NO`。<br>
 *        - `YES`：在直播间浮层展示跳转内容，观众可以边看视频边看跳转内容。
 *        - `NO`：打开新的浏览器标签页展示跳转内容，观众无法边看视频边看跳转内容。
 * @return YES：在直播间浮层展示跳转内容 NO：跳转至 Safari
 */
/**
 * @locale en
 * @brief Whether the redirected content is displayed on a floating page in the live room after a URL in the comment is tapped. Default value: `NO`.
 *        - `YES`: The redirected content is displayed on a floating page in the live room. Viewers can watch the video and view the redirected content at the same time.
 *        - `NO`: The redirected content is displayed on a new browser tab. Viewers cannot watch the video and view the redirected content at the same time.
 */
@property (nonatomic, assign) BOOL commentUrlFloatingEnable;

/**
 * @locale zh
 * @brief 是否禁用竖屏直播间的清屏功能。默认值：`NO`。<br>
 *        - `YES`：禁用。
 *        - `NO`：不禁用，即支持清屏功能。观众可以右滑清屏或者点击更多（...）图标 > 清屏实现清屏效果。<br>:::tip
 *        仅竖屏直播间支持清屏功能。<br>:::
 */
/**
 * @locale en
 * @brief Whether to disable the clear screen feature in the live room in portrait mode. Default value: `NO`.
 *        - `YES`: Disable.
 *        - `NO`: Do not disable. Viewers can swipe right to clear the screen or tap the more (...) icon > **Clear screen** to achieve the clear screen effect.
 *        :::tip
 *        Only the portrait mode supports the clear screen feature.
 *        :::
 */
@property (nonatomic, assign) BOOL disableClearScreen;

/**
 * @locale zh
 * @brief 是否在 viewDidAppear 时（即完整直播间对应的 view 已经显示时）关闭正在显示的浮窗。默认值：`NO`。<br>
 *        - `YES`：关闭。
 *        - `NO`：不关闭。
 */
/**
 * @locale en
 * @brief Whether to close the currently displayed floating window when `viewDidAppear` is triggered, which happens when the full-featured live room view is displayed. Default value: `NO`.
 *        - `YES`: Close.
 *        - `NO`: Do not close.
 */
@property (nonatomic, assign) BOOL autoCloseFloatingPlayerWhenAppear;

/**
 * @locale zh
 * @brief 清屏期间是否显示关闭直播间按钮。默认值：`NO`。<br>
 *        - `YES`：显示。
 *        - `NO`：不显示。
 */
/**
 * @locale en
 * @brief Whether to display the button for closing the live room during screen clearing. Default value: `NO`.
 *        - `YES`: Display.
 *        - `NO`: Do not display.
 */
@property (nonatomic, assign) BOOL showCloseButtonWhenClearingScreen;
/**
 * @locale zh
 * @brief 是否在竖屏直播间顶部显示渐变蒙层。默认值为 `YES`。<br/>
 *        - `YES`：显示。如果您的视频画面背景为白色，显示渐变蒙层可使直播间顶部的白色文字更明显。
 *        - `NO`：不显示。
 */
/**
 * @locale en
 * @brief Whether to display a gradient overlay at the top of the live room in portrait mode. Default value: `YES`.
 *        - `YES`: Display. If the background of your video is white, displaying the gradient overlay can make the white text at the top of the live room more visible.
 *        - `NO`: Do not display.
 */
@property (nonatomic, assign) BOOL showPortraitRoomTopShadow;

/**
 * @locale zh
 * @brief 是否显示 InApp 画中画，即浮窗播放器。
 * @param status 当前的直播状态。详见 [BDLActivityStatus](#BDLActivityStatus)。<br>
 *         仅在以下直播状态时，SDK 调用该方法：
 *        - 预告（且设置了预告片）。
 *        - 回放。
 *        - 直播。
 * @param isClose 是否为关闭当前页面。
 *        - `YES`：关闭当前页面，默认显示 InApp 画中画。
 *        - `NO`：打开新页面，默认不显示 InApp 画中画。
 * @param viewController 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @return - `YES`: 显示 InApp 画中画。
 *         - `NO`: 不显示 InApp 画中画。
 */
/**
 * @locale en
 * @brief Whether to display the in-app picture-in-picture (PiP), namely the floating player.
 * @param viewController The full-featured live room. For more information, see  [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param status The current live room status. For more information, see [BDLActivityStatus](#BDLActivityStatus).
 *        Call this method only when the live room is in any of the following statuses:
 *        - Preview (with a preview added).
 *        - Playback.
 *        - Live.
 * @param isClose Whether to close the current page.
 *        - `YES`: Close the current page, with in-app PiP displayed by default.
 *        - `NO`: Open a new page, with in-app PiP not displayed by default.
 * @return - `YES`: Display in-app PiP.
 *         - `NO`: Do not display in-app PiP.
 */
@property (nonatomic, copy, nullable) BOOL (^shouldShowInAppPipIfAvailable)(BDLLivePullViewController *viewController, BDLActivityStatus status, BOOL isClose);

/**
 * @locale zh
 * @brief 在 viewDidDisappear 时，如果 [shouldShowInAppPipIfAvailable](#BDLLivePullViewControllerConfig-shouldshowinapppipifavailable) 传入的 `isClose` 参数值不符合预期，可以使用该属性修正参数值。
 * @param viewController 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @return - `YES`：关闭当前页面。
 *         - `NO`：打开新页面。
 */
/**
 * @locale en
 * @brief When viewDidDisappear is triggered and the `isClose` parameter value passed through [shouldShowInAppPipIfAvailable](#BDLLivePullViewControllerConfig-shouldshowinapppipifavailable) does not meet expectations, use this property to adjust the parameter value.
 * @param viewController The full-featured live room. For more information, see  [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @return - `YES`: Close the current page.
 *         - `NO`: Open a new page.
 */
@property (nonatomic, copy, nullable) BOOL (^isCloseWhileDisappear)(BDLLivePullViewController *viewController);

/**
 * @locale zh
 * @brief 自定义背景图片 view。可自定义除 `image` 和 `hidden` 外的所有属性。如需更改 `image`，可在企业直播服务端设置。如需自定义 `frame`，可在 [customizeViewConstraints](#BDLLivePullViewControllerConfig-customizeviewconstraints) 中通过 `bdl_mas_remakeConstraints` 设置。
 * @param viewController 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param imageView 背景图片 view。
 * @return 背景图片 view。`nil` 则不显示。
 */
/**
 * @locale en
 * @brief The custom background image view. All properties except `image` and `hidden` can be customized. You can configure the `image` on the BytePlus Live server, or configure `frame` and size using `bdl_mas_remakeConstraints` within `customizeViewConstraints`.
 * @param viewController The full-featured live room. For more information, see [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param imageView The background image view.
 * @hidden (iOS)
 */
@property (nonatomic, copy, nullable) __kindof UIImageView * _Nullable (^customizeBackgroundImageView)(BDLLivePullViewController *viewController, UIImageView *imageView);
/**
 * @locale zh
 * @brief 自定义横屏直播间的移动端页头图片 view。可自定义除 `image` 和 `hidden` 外的所有属性。如需更改 `image`，可在企业直播服务端设置。如需自定义 `frame`，可在 [customizeViewConstraints](#BDLLivePullViewControllerConfig-customizeviewconstraints) 中通过` bdl_mas_remakeConstraints` 设置。
 * @param viewController 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param imageView 移动端页头图片 view。
 * @return 移动端页头图片 view。`nil` 则不显示。
 */
/**
 * @locale en
 * @brief The custom header image view for mobile devices. All properties except `image` and `hidden` can be customized. You can configure the `image` on the BytePlus Live server, or configure `frame` and size using `bdl_mas_remakeConstraints` within `customizeViewConstraints`.
 * @param viewController Full live room. For more details, see [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param imageView Mobile header image view.
 * @hidden (iOS)
 */
@property (nonatomic, copy, nullable) __kindof UIImageView * _Nullable (^customizeHeaderImageView)(BDLLivePullViewController *viewController, UIImageView *imageView);
/**
 * @locale zh
 * @brief 自定义横屏直播间的多语言按钮（竖屏直播间的多语言按钮可通过 [BDLMoreOptionsViewConfiguration](#BDLMoreOptionsViewConfiguration) 自定义）。可自定义除 `hidden` 外的所有属性。如需自定义 `frame`，可在 [customizeViewConstraints](#BDLLivePullViewControllerConfig-customizeviewconstraints) 中通过 `bdl_mas_remakeConstraints` 设置。
 * @param viewController 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param button 多语言按钮。
 * @return 多语言按钮。`nil` 则不显示。
 */
/**
 * @locale en
 * @param viewController
 * @param button
 * @hidden (iOS)
 */
@property (nonatomic, copy, nullable) __kindof UIButton * _Nullable (^customizeMultiLanguageButton)(BDLLivePullViewController *viewController, UIButton *button);
/**
 * @locale zh
 * @brief 自定义主播账号 view。可自定义除 `hidden` 外的所有属性。如需自定义 `frame`，可在 [customizeViewConstraints](#BDLLivePullViewControllerConfig-customizeviewconstraints) 中通过 `bdl_mas_remakeConstraints` 设置。
 * @param viewController 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param view 主播账号 view。详见 [BDLBusinessAccountView](1185540#BDLBusinessAccountView)。
 * @return 主播账号 view。`nil` 则不显示。
 */
/**
 * @locale en
 * @brief Customizes the host account view. All properties except `hidden` can be customized. If you need to customize the `frame`, you can set it in [customizeViewConstraints](#BDLLivePullViewControllerConfig-customizeviewconstraints) using `bdl_mas_remakeConstraints`.
 * @param viewController The full-featured live room. For more information, see  [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param view The host account view. For more information, see [BDLBusinessAccountView](docs-bdlliveengine#BDLBusinessAccountView).
 * @return The host account view. Not displayed if `nil`.
 */
@property (nonatomic, copy, nullable) __kindof BDLBaseView * _Nullable (^customizeAccountView)(BDLLivePullViewController *viewController, BDLBusinessAccountView *view);
/**
 * @locale zh
 * @brief 自定义直播间关闭按钮。可自定义所有属性。如需自定义 `frame`，可在 [customizeViewConstraints](#BDLLivePullViewControllerConfig-customizeviewconstraints) 中通过 `bdl_mas_remakeConstraints` 设置。
 * @param viewController 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param button 直播间关闭按钮。
 * @return 直播间关闭按钮。`nil` 则不显示。
 */
/**
 * @locale en
 * @brief Customize the live room close button. All properties can be customized. To customize the `frame` or size, set the `frame` and size using `bdl_mas_remakeConstraints` in `customizeViewConstraints`.
 * @param viewController Complete live stream room. For more details, see [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param button Close Button for Live Streaming Room.
 * @hidden (iOS)
 */
@property (nonatomic, copy, nullable) __kindof UIButton * _Nullable (^customizeCloseButton)(BDLLivePullViewController *viewController, UIButton *button);
/**
 * @locale zh
 * @brief 自定义横屏直播间的分享按钮（竖屏直播间的分享按钮可通过 [BDLCommentView](1185540#BDLCommentView) 自定义）。可自定义除 `hidden` 外的所有属性。
 * @param viewController 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param button 分享按钮。
 * @return 分享按钮。`nil` 则不显示。
 */
/**
 * @locale en
 * @param viewController
 * @param button
 * @hidden (iOS)
 */
@property (nonatomic, copy, nullable) __kindof UIButton * _Nullable (^customizeShareButton)(BDLLivePullViewController *viewController, UIButton *button);
/**
 * @locale zh
 * @brief 自定义顶部直播标题。可自定义除 `text` 外的属性。如需自定义 `frame`，可在 [customizeViewConstraints](#BDLLivePullViewControllerConfig-customizeviewconstraints) 中通过 `bdl_mas_remakeConstraints` 设置。<br/>
 *        :::tip
 *        竖屏直播间中，仅在直播间未添加主播账号时，会显示直播标题。<br/>
 *        :::
 * @param viewController 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param label 直播标题 label。
 * @return 直播标题 label。`nil` 则不显示。
 */
/**
 * @locale en
 * @brief Custom top live title in landscape mode. Attributes other than `text` can be customized. To customize `frame` or size, use `bdl_mas_remakeConstraints` in `customizeViewConstraints` to set the `frame` and size.
 * @param viewController Full live room. For details, refer to [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param label The live broadcast title label.
 * @hidden (iOS)
 */
@property (nonatomic, copy, nullable) __kindof UILabel * _Nullable (^customizeTitleLabel)(BDLLivePullViewController *viewController, UILabel *label);
/**
 * @locale zh
 * @brief 自定义页中广告 view。可自定义除 `hidden` 外的所有属性。<br/>
 *        如需自定义 `frame`，横屏直播间需要在 [customizeViewConstraints](#BDLLivePullViewControllerConfig-customizeviewconstraints) 中通过 `bdl_mas_remakeConstraints` 设置。竖屏直播间可直接修改 `frame`，但 `frame.origin` 会被忽略，即只支持修改 `frame.size`。<br/>
 *        :::tip
 *        竖屏直播间的页头广告和页中广告共用该 view。<br/>
 *        :::
 * @param viewController 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param view 页中广告 view。详见 [BDLPageAdView](1185540#BDLPageAdView)。
 * @return 页中广告 view，需要遵守 [BDLPageAdViewProtocol](#BDLPageAdViewProtocol) 协议。`nil` 则不显示。
 */
/**
 * @locale en
 * @brief Customizes the in-page ad view. All properties except `hidden` can be customized.
 *        If you need to customize the `frame`,
 *        - For live rooms in landscape mode, you can set it in [customizeViewConstraints](#BDLLivePullViewControllerConfig-customizeviewconstraints) using `bdl_mas_remakeConstraints`.
 *        - For live rooms in portrait mode, you can directly modify the `frame`, but `frame.origin` will be ignored, meaning only `frame.size` can be modified.
 *        :::tip
 *        For live rooms in portrait mode, the header ad and in-page ads share this view.
 *        :::
 * @param viewController The full-featured live room. For more information, see  [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param view The in-page ad view. For more information, see [BDLPageAdView](docs-bdlliveengine#BDLPageAdView).
 * @return The in-page ad view, which needs to conform to the [BDLPageAdViewProtocol](#BDLPageAdViewProtocol) protocol. Not displayed if `nil`.
 */
@property (nonatomic, copy, nullable) UIView<BDLPageAdViewProtocol> * _Nullable (^customizePageAdView)(BDLLivePullViewController *viewController, BDLPageAdView *view);
/**
 * @locale zh
 * @brief 自定义播放器。可自定义除 `frame` 外的所有属性。
 * @param viewController 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param view 播放器 view。详见 [BDLPlayerView](1185540#BDLPlayerView)。
 */
/**
 * @locale en
 * @brief Customizes the player. All properties except `frame` can be customized.
 * @param viewController The full-featured live room. For more information, see  [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param view The player view. For more information, see [BDLPlayerView](docs-bdlliveengine#BDLPlayerView).
 */
@property (nonatomic, copy, nullable) void (^customizePlayerView)(BDLLivePullViewController *viewController, BDLPlayerView *view);
/**
 * @locale zh
 * @brief 自定义播放器容器 view。可自定义除 `frame` 外的所有属性。
 * @param viewController 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param view 播放器容器 view。
 * @return 播放器容器 view。`nil` 则不显示。
 */
/**
 * @locale en
 * @brief Customizes the player container view. All properties except `frame` can be customized.
 * @param viewController The full-featured live room. For more information, see  [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param view The player container view.
 * @return The player container view. Not displayed if `nil`.
 */
@property (nonatomic, copy, nullable) __kindof UIView * _Nullable (^customizePlayerContainerView)(BDLLivePullViewController *viewController, UIView *view);
/**
 * @locale zh
 * @brief 自定义直播描述。可自定义除 `text`、`textColor`、`hidden` 外的所有属性。可通过 [customizeViewConstraints](#BDLLivePullViewControllerConfig-customizeviewconstraints) 修改整体的布局，不支持自定义单个属性的布局。
 * @param viewController 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param describeView 直播描述 view。详见 [BDLLiveDescriptionView](1185540#BDLLiveDescriptionView)。
 */
/**
 * @locale en
 * @brief Customizes the live room description. All properties except `text`, `textColor`, and `hidden` can be customized. You can modify the overall layout using [customizeViewConstraints](#BDLLivePullViewControllerConfig-customizeviewconstraints), but customizing the layout of individual properties is not supported.
 * @param viewController The full-featured live room. For more information, see  [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param describeView The live room description view. For more information, see [BDLLiveDescriptionView](docs-bdlliveengine#BDLLiveDescriptionView).
 */
@property (nonatomic, copy, nullable) void (^customizeLiveDescriptionView)(BDLLivePullViewController *viewController, BDLLiveDescriptionView *describeView);
/**
 * @locale zh
 * @brief 自定义竖屏直播间的评论和通知 view。可自定义除 `hidden` 外的所有属性。可通过 [customizeViewConstraints](#BDLLivePullViewControllerConfig-customizeviewconstraints) 修改整体的布局，不支持自定义单个属性的布局。
 * @param viewController 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param view 评论和通知 view。详见 [BDLCommentAndNoticeView](#BDLCommentAndNoticeView)。
 */
/**
 * @locale en
 * @brief Customizes the comment and notification view for live rooms in portrait mode. All properties except `hidden` can be customized. You can modify the overall layout using [customizeViewConstraints](#BDLLivePullViewControllerConfig-customizeviewconstraints), but customizing the layout of individual properties is not supported.
 * @param viewController The full-featured live room. For more information, see  [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param view The comment and notification view. For more information, see [BDLCommentAndNoticeView](#BDLCommentAndNoticeView).
 */
@property (nonatomic, copy, nullable) void (^customizeCommentAndNoticeView)(BDLLivePullViewController *viewController, BDLCommentAndNoticeView *view);
/**
 * @locale zh
 * @brief 自定义直播间背景颜色。如果企业直播服务端返回了移动端背景图，则背景图会覆盖此方法设置的背景颜色。不能设置为 `clearColor`。
 * @param viewController 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @return 直播间背景颜色。`nil` 则显示企业直播服务端返回的配置颜色。
 */
/**
 * @locale en
 * @brief Customizes the background color of the live room. If the BytePlus Live server returns the background image for mobile devices, the background image will override the background color set by this method. The background color cannot be set to `clearColor`.
 * @param viewController The full-featured live room. For more information, see  [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @return The background color of the live room. If `nil`, the configured color returned by the BytePlus Live server will be displayed.
 */
@property (nonatomic, copy, nullable) UIColor * _Nullable (^customizeBackgroundColor)(BDLLivePullViewController *viewController);
/**
 * @locale zh
 * @brief 自定义菜单栏。可自定义除 `hidden` 外的所有属性。可通过 [customizeViewConstraints](#BDLLivePullViewControllerConfig-customizeviewconstraints) 修改整体的布局，不支持自定义单个属性的布局。
 * @param viewController 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param view 菜单栏 view。详见 [BDLMenuBarView](1185540#BDLMenuBarView)。
 */
/**
 * @locale en
 * @brief Customizes the menu bar. All properties except `hidden` can be customized. You can modify the overall layout using [customizeViewConstraints](#BDLLivePullViewControllerConfig-customizeviewconstraints), but customizing the layout of individual properties is not supported.
 * @param viewController The full-featured live room. For more information, see  [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param view The menu bar view. For more information, see [BDLMenuBarView](docs-bdlliveengine#BDLMenuBarView).
 */
@property (nonatomic, copy, nullable) void (^customizeMenuBarView)(BDLLivePullViewController *viewController, BDLMenuBarView *view);
/**
 * @locale zh
 * @brief 自定义多语言选择弹窗 view。可自定义除 `frame` 外的所有属性。
 * @param viewController 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param view 多语言选择弹窗 view。详见 [BDLMultiLanguageView](1185540#BDLMultiLanguageView)。
 */
/**
 * @locale en
 * @brief Customizes the language selection dialog box view. All properties except `frame` can be customized.
 * @param viewController The full-featured live room. For more information, see  [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param view The language selection dialog box view. For more information, see [BDLMultiLanguageView](docs-bdlliveengine#BDLMultiLanguageView).
 */
@property (nonatomic, copy, nullable) void (^customizeMultiLanguageView)(BDLLivePullViewController *viewController, BDLMultiLanguageView *view);
/**
 * @locale zh
 * @brief 自定义竖屏直播间的更多选项弹窗 view（竖屏直播间点击右下角 … 图标后出现的弹窗）。可自定义除 `frame` 外的所有属性。
 * @param viewController 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param view 更多选项弹窗 view。详见 [BDLMoreOptionsView](1185540#BDLMoreOptionsView)。
 * @return 更多选项弹窗 view。`nil` 则不显示。
 */
/**
 * @locale en
 * @brief Customizes the more options dialog box view for the live room in portrait mode. All properties except `frame` can be customized. The more options dialog box is displayed after viewers tap the more (...) icon in the lower-right corner of the live room in portrait mode.
 * @param viewController The full-featured live room. For more information, see  [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param view The more options dialog box view. For more information, see [BDLMoreOptionsView](docs-bdlliveengine#BDLMoreOptionsView).
 * @return The more options dialog box view. Not displayed if `nil`.
 */
@property (nonatomic, copy, nullable) __kindof BDLBaseView * _Nullable (^customizeMoreOptionsView)(BDLLivePullViewController *viewController, BDLMoreOptionsView *view);
/**
 * @locale zh
 * @brief 自定义退出清屏按钮。可自定义除 `hidden` 外的所有属性。可通过 [customizeViewConstraints](#BDLLivePullViewControllerConfig-customizeviewconstraints) 修改整体的布局。<br>:::tip
 *        在竖屏直播间开启清屏模式后，会出现退出清屏按钮。<br>:::
 * @param viewController 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param button 退出清屏按钮。
 * @return 退出清屏按钮。`nil` 则不显示。
 */
/**
 * @locale en
 * @brief Customize the clear screen exit button. All properties except `hidden` can be customized. The overall layout can be modified through `customizeViewConstraints`.<br>:::tip
 *        The clear screen exit button will appear after enabling clear screen mode in the vertical live room.<br>:::
 * @param viewController The full-featured live room. For more information, see [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param button Exit and Clear Screen button.
 * @hidden (iOS)
 */
@property (nonatomic, copy, nullable) __kindof UIButton * _Nullable (^customizeExitClearModeButton)(BDLLivePullViewController *viewController, UIButton *button);
/**
 * @locale zh
 * @brief 自定义置顶评论详情弹窗 view。
 * @param viewController 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param popupTopCommentView 置顶评论详情弹窗 view。详见 [BDLPopupTopCommentView](1185540#BDLPopupTopCommentView)。
 * @return 置顶评论详情弹窗 view。`nil` 则不显示。
 */
/**
 * @locale en
 * @brief Customizes the pinned comment details dialog box view.
 * @param viewController The full-featured live room. For more information, see  [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param popupTopCommentView The pinned comment details dialog box view. For more information, see  [BDLPopupTopCommentView](docs-bdlliveengine#BDLPopupTopCommentView).
 * @return The pinned comment details dialog box view. Not displayed if `nil`.
 */
@property (nonatomic, copy, nullable) __kindof UIView<BDLPopupBottomShowViewProtocol> * (^customizePopupTopCommentView)(BDLLivePullViewController *viewController, BDLPopupTopCommentView *popupTopCommentView);
/**
 * @locale zh
 * @brief 自定义 WebView 弹窗，可自定义所有属性。
 * @param viewController 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param popupWebView WebView 弹窗。详见 [BDLPopupWebView](1185540#BDLPopupWebView)。
 * @return WebView 弹窗。`nil` 则不显示。
 */
/**
 * @locale en
 * @brief Customizes the WebView dialog box. All properties can be customized.
 * @param viewController The full-featured live room. For more information, see  [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param popupWebView The WebView dialog box. For more information, see [BDLPopupWebView](docs-bdlliveengine#BDLPopupWebView).
 * @return The WebView dialog box. Not displayed if `nil`.
 */
@property (nonatomic, copy, nullable) __kindof UIView<BDLPopupBottomShowViewProtocol> * (^customizePopupWebView)(BDLLivePullViewController *viewController, BDLPopupWebView *popupWebView);
/**
 * @locale zh
 * @brief 自定义风险提示 view。
 * @param viewController 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param view 风险提示 view。详见 [BDLRiskWarningView](1185540#BDLRiskWarningView)。
 * @return 风险提示 view，需要遵守 [BDLPopupCenterShowViewProtocol](#BDLPopupCenterShowViewProtocol) 协议。`nil` 则不显示。
 */
/**
 * @locale en
 * @brief Customizes the reminder view.
 * @param viewController The full-featured live room. For more information, see  [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param view The reminder view. For more information, see [BDLRiskWarningView](docs-bdlliveengine#BDLRiskWarningView).
 * @return The reminder view, which needs to conform to the [BDLPopupCenterShowViewProtocol](#BDLPopupCenterShowViewProtocol) protocol. Not displayed if `nil`.
 */
@property (nonatomic, copy, nullable) __kindof UIView<BDLPopupCenterShowViewProtocol> * _Nullable (^customizeRiskWarningView)(BDLLivePullViewController *viewController, BDLRiskWarningView *view);
/**
 * @locale zh
 * @brief 自定义倒计时 view。
 * @param viewController 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param view 直播间倒计时 view。详见 [BDLCountdownView](1185540#BDLCountdownView)。
 * @return 直播间倒计时 view。`nil` 则不显示。
 */
/**
 * @locale en
 * @brief Customizes the countdown view.
 * @param viewController The full-featured live room. For more information, see  [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param view The countdown view of the live room. For more information, see [BDLCountdownView](docs-bdlliveengine#BDLCountdownView).
 * @return The countdown view of the live room. Not displayed if `nil`.
 */
@property (nonatomic, copy, nullable) __kindof UIView * _Nullable (^customizeCountdownView)(BDLLivePullViewController *viewController, BDLCountdownView *view);
/**
 * @locale zh
 * @brief 自定义倒计时 view 的布局。<br>:::tip
 *        是否开启预约会影响倒计时页面的位置。<br>:::
 * @param viewController 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param view 倒计时 view。
 */
/**
 * @locale en
 * @brief Customizes the layout of the countdown view.<br>:::tip
 *        Whether the booking feature is enabled affects the position of the countdown on the page.<br>:::
 * @param viewController The full-featured live room. For more information, see  [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param view The countdown view.
 */
@property (nonatomic, copy, nullable) void (^customizeCountdownViewConstrains)(BDLLivePullViewController *viewController, UIView *view);

/**
 * @locale zh
 * @brief 自定义布局。默认实现是通过 Masonry 进行布局，这里您可以通过 `bdl_mas_remakeConstraints` 修改整体的布局。
 * @param viewController 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 */
/**
 * @locale en
 * @brief Customizes the layout. The default implementation uses Masonry for layout. Here, `bdl_mas_remakeConstraints` can be used to modify the overall layout.
 * @param viewController The full-featured live room. For more information, see  [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 */
@property (nonatomic, copy, nullable) void (^customizeViewConstraints)(BDLLivePullViewController *viewController);

/**
 * @locale zh
 * @brief 自定义播放器容器的布局。
 * @param viewController 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param view 播放器容器 view。
 */
/**
 * @locale en
 * @brief Customizes the layout of the player container.
 * @param viewController The full-featured live room. For more information, see  [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param view The player container view.
 */
@property (nonatomic, copy, nullable) void (^customizePlayerContainerViewConstraints)(BDLLivePullViewController *viewController, UIView *view);
/**
 * @locale zh
 * @brief 自定义页中广告的位置。
 * @param viewController 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param view 页中广告 view。
 */
/**
 * @locale en
 * @brief Customizes the position of in-page ads.
 * @param viewController The full-featured live room. For more information, see  [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param view The in-page ad view.
 */
@property (nonatomic, copy, nullable) void (^customizePageAdViewConstraints)(BDLLivePullViewController *viewController, UIView *view);
/**
 * @locale zh
 * @brief 自定义昵称输入界面。
 * @param viewController 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param view 昵称输入框 view。详见 [BDLPopupInputView](1185540#BDLPopupInputView)。
 * @return 昵称输入框 view。`nil` 则不显示。
 */
/**
 * @locale en
 * @brief Customizes the nickname input interface.
 * @param viewController The full-featured live room. For more information, see  [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param view The nickname text box view. For more information, see [BDLPopupInputView](docs-bdlliveengine#BDLPopupInputView).
 * @return The nickname text box view. Not displayed if `nil`.
 */
@property (nonatomic, copy, nullable) __kindof BDLBaseView * (^customizedNickNameInputView)(BDLLivePullViewController *viewController, BDLPopupInputView *view);

/**
 * @locale zh
 * @brief 自定义互动工具相关 controller。
 * @param viewController 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param interactiveToolController 互动工具 controller。详见 [BDLInteractiveToolController](1185540#BDLInteractiveToolController)。
 */
/**
 * @locale en
 * @brief Customizes the interaction tool-related controller.
 * @param viewController The full-featured live room. For more information, see  [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param interactiveToolController The interaction tools controller. For more information, see [BDLInteractiveToolController](docs-bdlliveengine#BDLInteractiveToolController).
 */
@property (nonatomic, copy, nullable) void (^customInteractiveToolController)(BDLLivePullViewController *viewController, BDLInteractiveToolController *interactiveToolController);

/**
 * @locale zh
 * @brief 自定义商品卡片相关 controller。
 * @param viewController 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param shoppingCardController 商品卡片 controller。详见 [BDLShoppingCardController](1185540#BDLShoppingCardController)。
 */
/**
 * @locale en
 * @brief Customizes the product card-related controller.
 * @param viewController The full-featured live room. For more information, see  [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param shoppingCardController The product card controller. For more information, see [BDLShoppingCardController](docs-bdlliveengine#BDLShoppingCardController).
 */
@property (nonatomic, copy, nullable) void (^customShoppingCardController)(BDLLivePullViewController *viewController, BDLShoppingCardController *shoppingCardController);

/**
 * @locale zh
 * @brief 自定义浮窗相关 controller。
 * @param viewController 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param floatingController 浮窗 controller。详见 [BDLFloatingController](#BDLFloatingController)。
 */
/**
 * @locale en
 * @brief Customizes the floating window-related controller.
 * @param viewController The full-featured live room. For more information, see  [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param floatingController The floating window controller. For more information, see [BDLFloatingController](#BDLFloatingController).
 */
@property (nonatomic, copy, nullable) void (^customFloatingController)(BDLLivePullViewController *viewController, BDLFloatingController *floatingController);

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
