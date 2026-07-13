//
//  BDLLivePullViewController.h
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
#import "BDLPageAdView.h"
#import "BDLBusinessAccountView.h"
#import "BDLCommentView.h"
#import "BDLMultiLanguageView.h"
#import "BDLPlayerView.h"
#import "BDLMenuBarView.h"
#import "BDLInteractiveToolView.h"
#import "BDLLiveDescriptionView.h"
#import "BDLMoreOptionsView.h"
#import "BDLLivePullViewControllerConfig.h"
#import "BDLGetShareInfoResponse.h"
#import "BDLGetInviteTokenResponse.h"
#import "BDLFloatingPlayer.h"
#import <BDLivePullBase/BDLPullBaseDefines.h>
#import "BDLForceOfflineInfo.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

@class BDLLiveEngine;
@class BDLLivePullViewController;

/**
 * @locale zh
 * @type keytype
 * @brief 多语言选中回调。
 * @param selectedLanguageType 选中的语言。详见 [BDLLanguageType](#BDLLanguageType)。
 */
/**
 * @locale en
 * @type keytype
 * @brief The callback is triggered when a language is selected.
 * @param selectedLanguageType The selected language. For more information, see [BDLLanguageType](#BDLLanguageType).
 */
typedef void (^BDLLanguageConfirmBlock)(BDLLanguageType selectedLanguageType);

/**
 * @locale zh
 * @type callback
 * @brief 完整直播间的事件提供者。
 */
/**
 * @locale en
 * @type callback
 * @brief The provider of full-featured live room events.
 */
@protocol BDLLivePullViewControllerActionProvider <NSObject>

/**
 * @locale zh
 * @brief 显示完整直播间。
 * @param livePullVC 需要显示的完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 */
/**
 * @locale en
 * @brief Displays the full-featured live room.
 * @param livePullVC The full-featured live room to display. For more information, see [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 */
- (void)showLivePullViewController:(BDLLivePullViewController *)livePullVC;

/**
 * @locale zh
 * @brief 隐藏完整直播间。
 * @param livePullVC 需要隐藏的完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 */
/**
 * @locale en
 * @brief Hides the full-featured live room.
 * @param livePullVC The full-featured live room to hide. For more information, see [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 */
- (void)hideLivePullViewController:(BDLLivePullViewController *)livePullVC;

@optional

/**
 * @locale zh
 * @brief 在观众点击完整直播间的关闭按钮时，SDK 调用该方法。
 * @param livePullVC 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param closeButton 关闭按钮。
 * @return 是否执行 [defaultCloseAction](1185540#BDLLivePullViewController(BDLDefaultAction)-defaultcloseaction)。
 *         - `YES`：执行。
 *         - `NO`：不执行。
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers tap the close button of the full-featured live room.
 * @param livePullVC The full-featured live room. For more information, see [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param closeButton The close button.
 * @return Whether to execute [defaultCloseAction](docs-bdlliveengine#BDLLivePullViewController(BDLDefaultAction)-defaultcloseaction).
 *         - `YES`: Execute.
 *         - `NO`: Do not execute.
 */
- (BOOL)livePullViewController:(BDLLivePullViewController *)livePullVC onCloseClick:(UIButton *)closeButton;

/**
 * @locale zh
 * @deprecated 该方法已废弃，请使用 [onFloatingPlayerCloseTapped](1185540#BDLLivePullViewController()-onfloatingplayerclosetapped) 方法。
 * @brief 在观众点击浮窗播放器关闭按钮时，SDK 调用该方法。
 * @param livePullVC 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param floatingPlayer 播放器 view。详见 [BDLPlayerView](1185540#BDLPlayerView)。
 * @return 是否执行 [defaultFloatingPlayerCloseAction](1185540#BDLLivePullViewController(BDLDefaultAction)-defaultfloatingplayercloseaction)。
 *         - `YES`：执行。
 *         - `NO`：不执行。
 */
/**
 * @locale en
 * @brief This method is called when the audience clicks the close button on the floating window player.
 * @param livePullVC Complete live room. See [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController) for details.
 * @param floatingPlayer Player view. Refer to [BDLPlayerView](docs-bdlliveengine#BDLPlayerView) for more details.
 * @hidden (iOS)
 */
- (BOOL)livePullViewController:(BDLLivePullViewController *)livePullVC onFloatingPlayerClose:(BDLPlayerView *)floatingPlayer DEPRECATED_MSG_ATTRIBUTE("use onFloatingPlayerCloseTapped Block instead");

/**
 * @locale zh
 * @deprecated 该方法已废弃，请使用 [onFloatingPlayerTapped](1185540#BDLLivePullViewController()-onfloatingplayertapped) 方法。
 * @brief 在观众点击浮窗播放器时，SDK 调用该方法。
 * @param livePullVC 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param floatingPlayer 播放器 view。详见 [BDLPlayerView](1185540#BDLPlayerView)。
 * @return 是否执行 [defaultFloatingPlayerTapAction](1185540#BDLLivePullViewController(BDLDefaultAction)-defaultfloatingplayertapaction)。
 *         - `YES`：执行。
 *         - `NO`：不执行。
 */
/**
 * @locale en
 * @param livePullVC Complete live streaming room. See [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController) for details.
 * @param floatingPlayer Player view. For more details, see [BDLPlayerView](docs-bdlliveengine#BDLPlayerView).
 * @hidden (iOS)
 */
- (BOOL)livePullViewController:(BDLLivePullViewController *)livePullVC onFloatingPlayerTap:(BDLPlayerView *)floatingPlayer DEPRECATED_MSG_ATTRIBUTE("use onFloatingPlayerTapped Block instead");

@end

/**
 * @locale zh
 * @type callback
 * @brief 完整直播间的代理方法。
 */
/**
 * @locale en
 * @type callback
 * @brief The delegate methods for the full-featured live room.
 */
@protocol BDLLivePullViewControllerDelegate <NSObject>

@optional
/**
 * @locale zh
 * @deprecated 该方法已废弃，请使用 [livePullViewController:onCloseClick:](#BDLLivePullViewControllerActionProvider-livepullviewcontroller-oncloseclick) 方法。
 * @brief 在观众点击完整直播间的关闭按钮时，SDK 调用该方法。
 * @param livePullVC 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param isFloating 是否正在浮窗展示。
 *        - `YES`：正在浮窗展示。
 *        - `NO`：未在浮窗展示。
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers tap the close button of the full-featured live room.
 * @param livePullVC The full-featured live room. For more information, see [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param isFloating Whether displayed in the floating window.
 *        - `YES`: Displayed.
 *        - `NO`: Not displayed.
 * @hidden (iOS)
 */
- (void)livePullViewControllerCloseButtonDidClick:(BDLLivePullViewController *)livePullVC isFloating:(BOOL)isFloating DEPRECATED_MSG_ATTRIBUTE("use BDLLivePullViewControllerActionProvider livePullViewController:onCloseClick: instead");

/**
 * @locale zh
 * @brief 在即将退出完整直播间时，SDK 调用该方法。您需要在该方法中释放完整直播间相关的引用。
 * @param livePullVC 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers are about to exit the full-featured live room. You need to release references related to the full-featured live room in this method.
 * @param livePullVC The full-featured live room. For more information, see [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 */
- (void)livePullViewControllerWillLeaveLiveRoom:(BDLLivePullViewController *)livePullVC;

/**
 * @locale zh
 * @brief 在完整直播间对应的 view 加载完成时，SDK 调用该方法，对应生命周期方法中的 viewDidLoad。
 * @param livePullVC 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the view corresponding to the full-featured live room finishes loading, corresponding to the viewDidLoad lifecycle method.
 * @param livePullVC The full-featured live room. For more information, see [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 */
- (void)livePullViewControllerDidLoad:(BDLLivePullViewController *)livePullVC;

/**
 * @locale zh
 * @brief 在完整直播间对应的 view 即将显示时，SDK 调用该方法，对应生命周期方法中的 viewWillAppear。
 * @param livePullVC 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the view corresponding to the full-featured live room is about to appear, corresponding to the viewWillAppear lifecycle method.
 * @param livePullVC The full-featured live room. For more information, see [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 */
- (void)livePullViewControllerWillAppear:(BDLLivePullViewController *)livePullVC;

/**
 * @locale zh
 * @brief 在完整直播间对应的 view 已经显示时，SDK 调用该方法，对应生命周期方法中的 viewDidAppear。
 * @param livePullVC 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the view corresponding to the full-featured live room appears, corresponding to the viewDidAppear lifecycle method.
 * @param livePullVC The full-featured live room. For more information, see [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 */
- (void)livePullViewControllerDidAppear:(BDLLivePullViewController *)livePullVC;

/**
 * @locale zh
 * @brief 在完整直播间对应的 view 即将消失时，SDK 调用该方法，对应生命周期方法中的 viewWillDisappear。
 * @param livePullVC 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the view corresponding to the full-featured live room is about to disappear, corresponding to the viewWillDisappear lifecycle method.
 * @param livePullVC The full-featured live room. For more information, see [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 */
- (void)livePullViewControllerWillDisappear:(BDLLivePullViewController *)livePullVC;
/**
 * @locale zh
 * @brief 在完整直播间对应的 view 已经消失时，SDK 调用该方法，对应生命周期方法中的 viewDidDisappear。
 * @param livePullVC 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the view corresponding to the full-featured live room disappears, corresponding to the viewDidDisappear lifecycle method.
 * @param livePullVC The full-featured live room. For more information, see [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 */
- (void)livePullViewControllerDidDisappear:(BDLLivePullViewController *)livePullVC;

/**
 * @locale zh
 * @brief 在完整直播间对应的 view 即将被销毁时，SDK 调用该方法，对应生命周期方法中的 dealloc。
 * @param livePullVC 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the view corresponding to the full-featured live room is about to be destroyed, corresponding to the dealloc lifecycle method.
 * @param livePullVC The full-featured live room. For more information, see [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 */
- (void)livePullViewControllerWillDestroy:(BDLLivePullViewController *)livePullVC;

/**
 * @locale zh
 * @brief 在播放器即将进入全屏状态时，SDK 调用该方法。
 * @param livePullVC 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the player is about to enter full-screen mode.
 * @param livePullVC The full-featured live room. For more information, see [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 */
- (void)livePullViewControllerEnterFullScreen:(BDLLivePullViewController *)livePullVC;

/**
 * @locale zh
 * @brief 在播放器即将退出全屏状态时，SDK 调用该方法。
 * @param livePullVC 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the player is about to exit full-screen mode.
 * @param livePullVC The full-featured live room. For more information, see [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 */
- (void)livePullViewControllerLeaveFullScreen:(BDLLivePullViewController *)livePullVC;

/**
 * @locale zh
 * @deprecated 该方法已废弃，请使用 [floatingPlayerViewWillAppear](1185540#BDLLivePullViewController()-floatingplayerviewwillappear) 方法。
 * @brief 在浮窗播放器即将显示时，SDK 调用该方法。
 * @param livePullVC 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param playerView 播放器 view。详见 [BDLPlayerView](1185540#BDLPlayerView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the floating player is about to appear.
 * @param livePullVC The full-featured live room. For more information, see [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param playerView The player view. For more information, see [BDLPlayerView](docs-bdlliveengine#BDLPlayerView).
 * @hidden (iOS)
 */
- (void)livePullViewController:(BDLLivePullViewController *)livePullVC floatingPlayerViewWillAppear:(BDLPlayerView *)playerView DEPRECATED_MSG_ATTRIBUTE("use floatingPlayerViewWillAppear Block instead");

/**
 * @locale zh
 * @deprecated 该方法已废弃，请使用 [floatingPlayerViewDidDisappear](1185540#BDLLivePullViewController()-floatingplayerviewdiddisappear) 方法。
 * @brief 在浮窗播放器消失时，SDK 调用该方法。
 * @param livePullVC 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param playerView 播放器 view。详见 [BDLPlayerView](1185540#BDLPlayerView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the floating player disappears.
 * @param livePullVC The full-featured live room. For more information, see [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param playerView The player view. For more information, see [BDLPlayerView](docs-bdlliveengine#BDLPlayerView).
 * @hidden (iOS)
 */
- (void)livePullViewController:(BDLLivePullViewController *)livePullVC floatingPlayerViewDidDisappear:(BDLPlayerView *)playerView DEPRECATED_MSG_ATTRIBUTE("use floatingPlayerViewDidDisappear Block instead");

/**
 * @locale zh
 * @deprecated 该方法已废弃，请使用 [onFloatingPlayerTapped](1185540#BDLLivePullViewController()-onfloatingplayertapped) 方法。
 * @brief 在观众点击浮窗播放器时，SDK 调用该方法。
 * @param livePullVC 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param playerView 播放器 view。详见 [BDLPlayerView](1185540#BDLPlayerView)。
 */
/**
 * @locale en
 * @param livePullVC full-featured live room. For more details, see [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param playerView Player view. For details, see [BDLPlayerView](docs-bdlliveengine#BDLPlayerView).
 * @hidden (iOS)
 */
- (void)livePullViewController:(BDLLivePullViewController *)livePullVC floatingPlayerViewDidTap:(BDLPlayerView *)playerView DEPRECATED_MSG_ATTRIBUTE("use onFloatingPlayerTapped instead");

/**
 * @locale zh
 * @deprecated 该方法已废弃，请使用 [floatingPlayerViewWillClose](1185540#BDLLivePullViewController()-onfloatingplayertapped) 方法。
 * @brief 在浮窗播放器即将关闭时，SDK 调用该方法。
 * @param livePullVC 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param playerView 播放器 view。详见 [BDLPlayerView](1185540#BDLPlayerView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the floating window player is about to close.
 * @param livePullVC full-featured live room. For details, see [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param playerView Player view. For more details, see [BDLPlayerView](docs-bdlliveengine#BDLPlayerView).
 * @hidden (iOS)
 */
- (void)livePullViewController:(BDLLivePullViewController *)livePullVC floatingPlayerViewWillClose:(BDLPlayerView *)playerView DEPRECATED_MSG_ATTRIBUTE("use floatingPlayerViewWillClose Block instead");

/**
 * @locale zh
 * @brief 在显示多语言选择的弹窗时，SDK 调用该方法。
 * @param livePullVC 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param languageTypes 当前所有支持的语言类型。
 * @param currentSelectedType 当前选中的语言。详见 [BDLLanguageType](1185544#BDLLanguageType)。
 * @param confirmBlock 多语言选中回调。详见 [BDLLanguageConfirmBlock](1185544#bdllanguageconfirmblock)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the language selection dialog box is displayed.
 * @param livePullVC The full-featured live room. For more information, see [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param languageTypes All the currently supported language types.
 * @param currentSelectedType The currently selected language. For more information, see [BDLLanguageType](viewer-sdk-for-ios-type-definitions#BDLLanguageType).
 * @param confirmBlock The callback triggered when a language is selected. For more information, see [BDLLanguageConfirmBlock](viewer-sdk-for-ios-type-definitions#bdllanguageconfirmblock).
 */
- (void)livePullViewController:(BDLLivePullViewController *)livePullVC showCustomLanguageSelectionView:(NSArray<NSNumber *> *)languageTypes currentSelectedType:(BDLLanguageType)currentSelectedType confirm:(BDLLanguageConfirmBlock)confirmBlock;

/**
 * @locale zh
 * @deprecated 该方法已废弃，请使用 [livePullViewController:showCustomShareView:shareInfo:inviteTokenModel:](#BDLLivePullViewControllerDelegate-livepullviewcontroller-showcustomshareview-shareinfo-invitetokenmodel) 方法。
 * @brief 在观众点击分享按钮时，SDK 调用该方法。
 * @param livePullVC 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param shareLink 分享地址。
 */
/**
 * @locale en
 * @param livePullVC full-featured live room. For more details, see [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param shareLink Share URL.
 * @hidden (iOS)
 */
- (void)livePullViewController:(BDLLivePullViewController *)livePullVC showCustomShareView:(NSString *)shareLink DEPRECATED_MSG_ATTRIBUTE("use livePullViewController:showCustomShareView:shareInfo:inviteTokenModel: instead");


/**
 * @locale zh
 * @brief 在观众点击分享按钮时，SDK 调用该方法。
 * @param livePullVC 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param shareLink 分享地址。
 * @param shareInfo 分享信息。详见 [BDLGetShareInfoResult](1185544#BDLGetShareInfoResult)。
 * @param inviteTokenModel 当前观众的专属邀请信息。详见 [BDLGetInviteTokenResult](1185544#BDLGetInviteTokenResult)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers tap the share button.
 * @param livePullVC The full-featured live room. For more information, see [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param shareLink The shared address.
 * @param shareInfo The sharing information. For more information, see [BDLGetShareInfoResult](viewer-sdk-for-ios-type-definitions#BDLGetShareInfoResult).
 * @param inviteTokenModel The exclusive invitation information of the current viewer. For more information, see [BDLGetInviteTokenResult](viewer-sdk-for-ios-type-definitions#BDLGetInviteTokenResult).
 */
- (void)livePullViewController:(BDLLivePullViewController *)livePullVC
           showCustomShareView:(NSString *)shareLink
                     shareInfo:(BDLGetShareInfoResult *)shareInfo
              inviteTokenModel:(nullable BDLGetInviteTokenResult *)inviteTokenModel;

/**
 * @locale zh
 * @brief 在观众点击页头广告时，SDK 调用该方法。
 * @param livePullVC 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param url 页头广告的跳转链接。
 * @param floatingEnable 是否开启浮层展示。
 *        - `YES`：开启。在直播间浮层展示广告，观众可以边看视频边看广告。
 *        - `NO`：不开启。打开新的浏览器标签页展示广告，观众无法边看视频边看广告。
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers tap the header ad.
 * @param livePullVC The full-featured live room. For more information, see [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param url The embedded link of the header ad.
 * @param floatingEnable Whether the ad is displayed on a floating page in the live room.
 *        - `YES`: The ad is displayed on a floating page in the live room. Viewers can watch the video and view the ad at the same time.
 *        - `NO`: The ad is displayed on a new browser tab. Viewers cannot watch the video and view the ad at the same time.
 */
- (void)livePullViewController:(BDLLivePullViewController *)livePullVC didClickHeaderAd:(NSString *)url floatingEnable:(BOOL)floatingEnable;

/**
 * @locale zh
 * @deprecated 该方法已废弃，请使用 [frameForFloatingPlayer](1185540#BDLLivePullViewController()-frameforfloatingplayer) 方法。
 * @brief 自定义浮窗播放器的初始位置。
 * @param livePullVC 完整直播间。详见 [BDLLivePullViewController](1185540#BDLLivePullViewController)。
 * @param playerView 播放器 view。详见 [BDLPlayerView](1185540#BDLPlayerView)。
 * @return 浮窗播放器的初始位置。
 */
/**
 * @locale en
 * @brief Specify the initial position of the custom floating window player.
 * @param livePullVC Complete live broadcast room. For details, see [BDLLivePullViewController](docs-bdlliveengine#BDLLivePullViewController).
 * @param playerView Player view. Refer to [BDLPlayerView](docs-bdlliveengine#BDLPlayerView) for more details.
 * @hidden (iOS)
 */
- (CGRect)livePullViewController:(BDLLivePullViewController *)livePullVC frameForFloatingPlayer:(BDLPlayerView *)playerView DEPRECATED_MSG_ATTRIBUTE("use frameForFloatingPlayer Block instead");

@end

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
@interface BDLLivePullViewController : UIViewController

/**
 * @locale zh
 * @brief 代理方法。详见 [BDLLivePullViewControllerDelegate](1185541#BDLLivePullViewControllerDelegate)。
 */
/**
 * @locale en
 * @brief The delegate method. For more information, see [BDLLivePullViewControllerDelegate](viewer-SDK-for-ios-callbacks#BDLLivePullViewControllerDelegate).
 */
@property (nonatomic, weak) id<BDLLivePullViewControllerDelegate> delegate;
/**
 * @locale zh
 * @brief 事件提供者，用于 SDK 外部响应某些事件。详见 [BDLLivePullViewControllerActionProvider](1185541#BDLLivePullViewControllerActionProvider)。
 */
/**
 * @locale en
 * @brief The event provider, which is used to respond to certain events outside of the SDK. For more information, see [BDLLivePullViewControllerActionProvider](viewer-SDK-for-ios-callbacks#BDLLivePullViewControllerActionProvider).
 */
@property (nonatomic, weak) id<BDLLivePullViewControllerActionProvider> actionProvider;
/**
 * @locale zh
 * @brief 是否为竖屏直播间。由初始化方法 [initWithActivityId:isPortrait:](#BDLLivePullViewController-initwithactivityid-isportrait-liveengine) 或 [initWithActivityId:isPortrait:basePlayerView:](#BDLLivePullViewController-initwithactivityid-isportrait-liveengine-baseplayerview) 传入。<br>
 *        - `YES`：竖屏直播间。
 *        - `NO`：横屏直播间。
 */
/**
 * @locale en
 * @brief Whether the live room is in portrait mode, which is passed in through the initialization method [initWithActivityId:isPortrait:](#BDLLivePullViewController-initwithactivityid-isportrait-liveengine) or [initWithActivityId:isPortrait:basePlayerView:](#BDLLivePullViewController-initwithactivityid-isportrait-liveengine-baseplayerview).
 *        - `YES`: Portrait mode.
 *        - `NO`: Landscape mode.
 */
@property (nonatomic, assign, readonly) BOOL isPortrait;
/**
 * @locale zh
 * @brief 是否正在浮窗播放。
 *        - `YES`：浮窗播放。
 *        - `NO`：非浮窗播放。
 */
/**
 * @locale en
 * @brief Whether playing the video in the floating player.
 *        - `YES`: In the floating player.
 *        - `NO`: Not in the floating player.
 */
@property (nonatomic, assign, readonly) BOOL isFloating;
/**
 * @locale zh
 * @brief 完整直播间的配置。详见 [BDLLivePullViewControllerConfig](1185544#BDLLivePullViewControllerConfig)。
 */
/**
 * @locale en
 * @brief The configuration of the full-featured live room. For more information, see [BDLLivePullViewControllerConfig](viewer-sdk-for-ios-type-definitions#BDLLivePullViewControllerConfig).
 */
@property (nonatomic, strong, readonly) BDLLivePullViewControllerConfig *config;
/**
 * @locale zh
 * @brief 初始化。
 * @param activityId 直播间活动 ID。可以通过调用 [ListActivityAPI](https://www.volcengine.com/docs/3019/100055) 接口获取。
 * @param isPortrait 是否以竖屏直播间初始化。
 *        - `YES`：以竖屏直播间初始化。
 *        - `NO`：以横屏直播间初始化。
 * @list 直播间
 * @param liveEngine 观播 SDK 入口类。详见 [BDLLiveEngine](#BDLLiveEngine)。
 * @return 完整直播间 controller 实例。
 */
/**
 * @locale en
 * @brief Initializes the instance of the full-featured live room controller.
 * @param activityId The activity ID of the live room. You can get the ID by calling [ListActivityAPI](https://docs.byteplus.com/en/docs/byteplus-livesaas/docs-listactivityapi).
 * @param isPortrait Whether to initialize in portrait mode.
 *        - `YES`: Portrait mode.
 *        - `NO`: Landscape mode.
 * @param liveEngine The entry class for the Viewer SDK. For more information, see [BDLLiveEngine](#BDLLiveEngine).
 * @return The instance of the full-featured live room controller.
 */
- (instancetype)initWithActivityId:(NSNumber *)activityId isPortrait:(BOOL)isPortrait liveEngine:(BDLLiveEngine *)liveEngine;
/**
 * @locale zh
 * @brief 初始化。
 * @param activityId 直播间活动 ID。可以通过调用 [ListActivityAPI](https://www.volcengine.com/docs/3019/100055) 接口获取。
 * @param isPortrait 是否以竖屏直播间初始化。
 *        - `YES`：以竖屏直播间初始化。
 *        - `NO`：以横屏直播间初始化。
 * @param basePlayerView 已经开始播放的独立播放器。详见 [BDLBasePlayerView](#BDLBasePlayerView)。
 * @list 直播间
 * @param liveEngine 观播 SDK 入口类。详见 [BDLLiveEngine](#BDLLiveEngine)。
 * @return 完整直播间 controller 实例。
 */
/**
 * @locale en
 * @brief Initializes the instance of the full-featured live room controller.
 * @param activityId The activity ID of the live room. You can get the ID by calling [ListActivityAPI](https://docs.byteplus.com/en/docs/byteplus-livesaas/docs-listactivityapi).
 * @param isPortrait Whether to initialize in portrait mode.
 *        - `YES`: Portrait mode.
 *        - `NO`: Landscape mode.
 * @param liveEngine The entry class for the Viewer SDK. For more information, see [BDLLiveEngine](#BDLLiveEngine).
 * @param basePlayerView The custom player that has already started playing. For more information, see [BDLBasePlayerView](#BDLBasePlayerView).
 * @return The instance of the full-featured live room controller.
 */
- (instancetype)initWithActivityId:(NSNumber *)activityId
                        isPortrait:(BOOL)isPortrait
                        liveEngine:(BDLLiveEngine *)liveEngine
                    basePlayerView:(nullable BDLBasePlayerView *)basePlayerView;
/**
 * @locale zh
 * @brief 将 `basePlayerView` 传入 `BDLLivePullViewController`。
 * @param basePlayerView 已经开始播放的独立播放器。详见 [BDLBasePlayerView](#BDLBasePlayerView)。
 * @list 直播间
 */
/**
 * @locale en
 * @brief Passes `basePlayerView` to `BDLLivePullViewController`.
 * @param basePlayerView The custom player that has already started playing. For more information, see [BDLBasePlayerView](#BDLBasePlayerView).
 */
- (void)addBasePlayerView:(BDLBasePlayerView *)basePlayerView;
/**
 * @locale zh
 * @brief 关闭完整直播间。<br>:::tip
 *        如果用户正在连麦中，调用该方法会显示退出连麦弹窗。如果想直接退出，可以调用 [cancelAudienceLinkIfNeededAndClose](#BDLLivePullViewController(BDLAudienceLink)-cancelaudiencelinkifneededandclose) 方法。<br>:::
 * @param showFloatingPlayerIfAvailable 在可以显示浮窗播放器时，是否显示浮窗播放器。
 *        - `YES`：显示。
 *        - `NO`：不显示。
 * @list 直播间
 */
/**
 * @locale en
 * @brief Closes the full-featured live room.
 * @param showFloatingPlayerIfAvailable Whether to display the floating player when it can be displayed.
 *        - `YES`: Display.
 *        - `NO`: Do not display.
 */
- (void)close:(BOOL)showFloatingPlayerIfAvailable;
/**
 * @locale zh
 * @brief 在可以显示浮窗播放器时，显示浮窗播放器。
 * @param close 是否关闭完整直播间。
 *        - `YES`：关闭。如果浮窗播放器显示失败，则不会关闭完整直播间。
 *        - `NO`：不关闭。
 * @return 浮窗播放器是否显示成功。
 *         - `YES`：显示成功。
 *         - `NO`：显示失败。
 * @list 直播间
 */
/**
 * @locale en
 * @brief Displays the floating player when it can be displayed.
 * @param close Whether to close the full-featured live room.
 *        - `YES`: Close. However, do not close the full-featured live room if the floating player fails to display.
 *        - `NO`: Do not close.
 * @return Whether the floating player is displayed successfully.<br>
 *         - `YES`: Successful.
 *         - `NO`: Failed.
 */
- (BOOL)showFloatingPlayerIfAvailable:(BOOL)close;
/**
 * @locale zh
 * @brief 隐藏浮窗播放器。
 * @param show 是否显示完整直播间。<br>
 *        - `YES`：关闭浮窗播放器，显示完整直播间。
 *        - `NO`：关闭浮窗播放器，不显示完整直播间。
 * @list 直播间
 */
/**
 * @locale en
 * @brief Hides the floating player.
 * @param show Whether to display the full-featured live room.
 *        - `YES`: Close the floating player and display the full-featured live room.
 *        - `NO`: Close the floating player and do not display the full-featured live room.
 */
- (void)hideFloatingPlayerIfAvailable:(BOOL)show;
/**
 * @locale zh
 * @brief 浮窗播放器的方向。
 */
/**
 * @locale en
 * @brief The orientation of the floating player.
 */
@property (nonatomic, assign) UIInterfaceOrientation floatingPlayerOrientation;

@end

/**
 * @locale zh
 * @type api
 * @brief 完整直播间事件的默认实现。
 */
/**
 * @locale en
 * @brief The default implementation of full-featured live room events.
 */
@interface BDLLivePullViewController (BDLDefaultAction)

/**
 * @locale zh
 * @brief 完整直播间关闭事件的默认实现，即退出完整直播间。如正在播放直播或点播视频且开启了浮窗（即 InApp 画中画），则会在退出完整直播间的同时展示浮窗播放器。
 * @list 直播间
 */
/**
 * @locale en
 * @brief The default implementation of the full-featured live room close event, which is exiting the full-featured live room. If a live or Video-on-Demand (VOD) video is playing and the floating player (in-app picture-in-picture (PiP)) is enabled, the floating player is displayed while exiting the full-featured live room.
 */
- (void)defaultCloseAction;
/**
 * @locale zh
 * @brief 浮窗播放器点击事件的默认实现，即关闭浮窗播放器并返回完整直播间。
 * @list 直播间
 */
/**
 * @locale en
 * @brief The default implementation of the floating player tap event, which is closing the floating player and returning to the full-featured live room.
 */
- (void)defaultFloatingPlayerTapAction;
/**
 * @locale zh
 * @brief 浮窗播放器关闭事件的默认实现，即关闭浮窗播放器。
 * @list 直播间
 */
/**
 * @locale en
 * @brief The default implementation of the floating player close event, which is closing the floating player.
 */
- (void)defaultFloatingPlayerCloseAction;
/**
 * @locale zh
 * @brief 获取默认的浮窗播放器展示位置。
 * @return 浮窗播放器的默认位置。
 * @list 直播间
 */
/**
 * @locale en
 * @brief Gets the default position of the floating player.
 * @return The default position of the floating player.
 */
- (CGRect)defaultFloatingPlayerFrame;

/**
 * @locale zh
 * @brief 配置了跳转链接的商品卡片和广告（页头广告、页中广告、浮标广告）点击事件的默认实现，即加载配置的跳转链接。
 * @param urlStr 需要加载的跳转链接。
 * @param enableFloating 是否在观看页浮层展示内容。<br>
 *        - `YES`：在观看页浮层展示内容，即在完整直播间的页面中弹出 WebView 弹窗展示跳转链接的内容。
 *        - `NO`：在新页面展示内容，即通过 App 的 DeepLink 机制寻找符合条件的页面展示跳转链接的内容。
 * @list 直播间
 */
/**
 * @locale en
 * @brief The default implementation of the tap event for product cards and ads (header ads, in-page ads, and floating ads) with configured URLs, which is loading the configured URL.
 * @param urlStr The URL to load.
 * @param enableFloating Whether to display content on a floating page in the live room.
 *        - `YES`: Display content on a floating page, which means opening a WebView window on the full-featured live room page to display the content from the URL.
 *        - `NO`: Display content on a new page, which means using the app's DeepLink mechanism to find an appropriate page to display the content from the URL.
 */
- (void)defaultOpenURLAction:(NSString *)urlStr enableFloating:(BOOL)enableFloating;

@end

/**
 * @locale zh
 * @type api
 * @brief 完整直播间回调的分类。
 */
@interface BDLLivePullViewController ()

/**
 * @locale zh
 * @brief 在浮窗播放器即将显示时，SDK 调用该方法。
 * @param viewController 完整直播间。
 * @param floatingPlayer 浮窗播放器。详见 [BDLFloatingPlayer](#BDLFloatingPlayer)。
 * @list 直播间
 */
/**
 * @locale en
 * @brief The SDK calls this method when the floating player is about to appear.
 * @param viewController The full-featured live room.
 * @param floatingPlayer The floating player. For more information, see [BDLFloatingPlayer](#BDLFloatingPlayer).
 */
@property (nonatomic, copy, nullable) void (^floatingPlayerViewWillAppear)(BDLLivePullViewController *viewController, BDLFloatingPlayer *floatingPlayer);
/**
 * @locale zh
 * @brief 在浮窗播放器消失时，SDK 调用该方法。
 * @param viewController 完整直播间。
 * @param floatingPlayer 浮窗播放器。详见 [BDLFloatingPlayer](#BDLFloatingPlayer)。
 * @list 直播间
 */
/**
 * @locale en
 * @brief The SDK calls this method when the floating player disappears.
 * @param viewController The full-featured live room.
 * @param floatingPlayer The floating player. For more information, see [BDLFloatingPlayer](#BDLFloatingPlayer).
 */
@property (nonatomic, copy, nullable) void (^floatingPlayerViewDidDisappear)(BDLLivePullViewController *viewController, BDLFloatingPlayer *floatingPlayer);
/**
 * @locale zh
 * @brief 在浮窗播放器即将关闭时，SDK 调用该方法。
 * @param viewController 完整直播间。
 * @param floatingPlayer 浮窗播放器。详见 [BDLFloatingPlayer](#BDLFloatingPlayer)。
 * @list 直播间
 */
/**
 * @locale en
 * @brief The SDK calls this method when the floating player is about to close.
 * @param viewController The full-featured live room.
 * @param floatingPlayer The floating player. For more information, see [BDLFloatingPlayer](#BDLFloatingPlayer).
 */
@property (nonatomic, copy, nullable) void (^floatingPlayerViewWillClose)(BDLLivePullViewController *viewController, BDLFloatingPlayer *floatingPlayer);
/**
 * @locale zh
 * @brief 自定义浮窗播放器的初始位置。
 * @param viewController 完整直播间。
 * @param floatingPlayer 浮窗播放器。详见 [BDLFloatingPlayer](#BDLFloatingPlayer)。
 * @list 直播间
 * @return 浮窗播放器的初始位置。
 */
/**
 * @locale en
 * @brief Customizes the initial position of the floating player.
 * @param viewController The full-featured live room.
 * @param floatingPlayer The floating player. For more information, see [BDLFloatingPlayer](#BDLFloatingPlayer).
 * @return The initial position of the floating player.
 */
@property (nonatomic, copy, nullable) CGRect (^frameForFloatingPlayer)(BDLLivePullViewController *viewController, BDLFloatingPlayer *floatingPlayer);
/**
 * @locale zh
 * @brief 在观众点击浮窗播放器时，SDK 调用该方法。
 * @param viewController 完整直播间。
 * @param floatingPlayer 浮窗播放器。详见 [BDLFloatingPlayer](#BDLFloatingPlayer)。
 * @list 直播间
 * @return 是否执行 [defaultFloatingPlayerTapAction](#BDLLivePullViewController(BDLDefaultAction)-defaultfloatingplayertapaction)。<br>
 *         - `YES`：执行。
 *         - `NO`：不执行。
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers tap the floating player.
 * @param viewController The full-featured live room.
 * @param floatingPlayer The floating player. For more information, see [BDLFloatingPlayer](#BDLFloatingPlayer).
 * @return Whether to execute [defaultFloatingPlayerTapAction](#BDLLivePullViewController(BDLDefaultAction)-defaultfloatingplayertapaction).
 *         - `YES`: Execute.
 *         - `NO`: Do not execute.
 */
@property (nonatomic, copy, nullable) BOOL (^onFloatingPlayerTapped)(BDLLivePullViewController *viewController, BDLFloatingPlayer *floatingPlayer);
/**
 * @locale zh
 * @brief 在观众点击浮窗播放器关闭按钮时，SDK 调用该方法。
 * @param viewController 完整直播间。
 * @param floatingPlayer 浮窗播放器。详见 [BDLFloatingPlayer](#BDLFloatingPlayer)。
 * @list 直播间
 * @return 是否执行 [defaultFloatingPlayerCloseAction](#BDLLivePullViewController(BDLDefaultAction)-defaultfloatingplayercloseaction)。<br>
 *         - `YES`：执行。
 *         - `NO`：不执行。
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers tap the close button of the floating player.
 * @param viewController The full-featured live room.
 * @param floatingPlayer The floating player. For more information, see [BDLFloatingPlayer](#BDLFloatingPlayer).
 * @return Whether to execute [defaultFloatingPlayerCloseAction](#BDLLivePullViewController(BDLDefaultAction)-defaultfloatingplayercloseaction).
 *         - `YES`: Execute.
 *         - `NO`: Do not execute.
 */
@property (nonatomic, copy, nullable) BOOL (^onFloatingPlayerCloseTapped)(BDLLivePullViewController *viewController, BDLFloatingPlayer *floatingPlayer);
/**
 * @locale zh
 * @brief 在观众被强制退出直播间时，SDK 调用该方法。
 * @param viewController 完整直播间。
 * @param info 观众被强制退出直播间的原因。详见 [BDLForceOfflineInfo](1185544#BDLForceOfflineInfo)。
 * @list 直播间
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers are forcibly removed from the live room.
 * @param viewController The full-featured live room.
 * @param info The reason for viewers being forcibly removed from the live room. For more information, see [BDLForceOfflineInfo](viewer-sdk-for-ios-type-definitions#BDLForceOfflineInfo).
 */
@property (nonatomic, copy, nullable) void (^onUserForceOfflineBlock)(BDLLivePullViewController *viewController, BDLForceOfflineInfo *info);

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
