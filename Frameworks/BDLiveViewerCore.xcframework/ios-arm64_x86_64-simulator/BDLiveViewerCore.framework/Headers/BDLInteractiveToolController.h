//
//  BDLInteractiveToolController.h
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
#import "BDLInteractiveToolView.h"
#import "BDLFloatingInteractiveToolView.h"
#import "BDLAwardDetailsView.h"
#import "BDLAwardResultView.h"
#import "BDLAwardWinnersView.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 互动工具 controller。
 */
/**
 * @locale en
 * @brief The interaction tools controller.
 */
@interface BDLInteractiveToolController : NSObject

/**
 * @locale zh
 * @brief 显示弹窗的 view。当为 `nil` 时，则不显示相关弹窗。
 */
/**
 * @locale en
 * @brief The view that displays the dialog box. The related dialog box is not displayed if `nil`.
 */
@property (nonatomic, strong, nullable) UIView *popupSuperview;
/**
 * @locale zh
 * @brief 在观看页显示互动工具浮窗时，SDK 调用该方法。类型相同，`floatingView` 相同。默认为 [BDLFloatingInteractiveToolView](#BDLFloatingInteractiveToolView) 的类型，可以通过 [type](#BDLFloatingInteractiveToolView-type) 判断浮窗的类型。
 * @param interactiveToolController 互动工具 controller。
 * @param floatingView 显示的互动工具浮窗。
 * @param withoutCloseButtonView 显示的互动工具浮窗，但无关闭按钮。
 * @list 互动工具菜单
 */
/**
 * @locale en
 * @brief The SDK calls this method when the interaction tool floating window is displayed on the viewing page. If the type is the same, the `floatingView` will be the same. By default, use the type of [BDLFloatingInteractiveToolView](#BDLFloatingInteractiveToolView), and you can determine the type of the floating window through [type](#BDLFloatingInteractiveToolView-type).
 * @param interactiveToolController The interaction tools controller.
 * @param floatingView The displayed interaction tool floating window.
 * @param withoutCloseButtonView The displayed interaction tool floating window without a close button.
 */
@property (nonatomic, copy, nullable) void(^showFloatingViewBlock)(BDLInteractiveToolController *interactiveToolController, UIView *floatingView, UIView *withoutCloseButtonView);

/**
 * @locale zh
 * @brief 在观看页隐藏互动工具浮窗时，SDK 调用该方法。类型相同，`floatingView` 相同。默认为 [BDLFloatingInteractiveToolView](#BDLFloatingInteractiveToolView) 的类型，可以通过 [type](#BDLFloatingInteractiveToolView-type) 判断浮窗的类型。
 * @param interactiveToolController 互动工具 controller。
 * @param floatingView 隐藏的互动工具浮窗。
 * @param withoutCloseButtonView 隐藏的互动工具浮窗，但无关闭按钮。
 * @list 互动工具菜单
 */
/**
 * @locale en
 * @brief The SDK calls this method when the interaction tool floating window is hidden on the viewing page. If the type is the same, the `floatingView` will be the same. By default, use the type of [BDLFloatingInteractiveToolView](#BDLFloatingInteractiveToolView), and you can determine the type of the floating window through [type](#BDLFloatingInteractiveToolView-type).
 * @param interactiveToolController The interaction tools controller.
 * @param floatingView The hidden interaction tool floating window.
 * @param withoutCloseButtonView The hidden interaction tool floating window without a close button.
 */
@property (nonatomic, copy, nullable) void(^hideFloatingViewBlock)(BDLInteractiveToolController *interactiveToolController, UIView *floatingView, UIView *withoutCloseButtonView);

/**
 * @locale zh
 * @brief 在需要关闭直播间时，SDK 调用该方法。目前仅适用于强制关闭进入直播时问卷的场景。
 * @param interactiveToolController 互动工具 controller。
 * @list 互动工具菜单
 */
/**
 * @locale en
 * @brief The SDK calls this method when the live room needs to be closed. Currently, this method is only applicable to scenarios where the questionnaire sent when viewers join the live room needs to be forcibly closed.
 * @param interactiveToolController The interaction tools controller.
 */
@property (nonatomic, copy, nullable) void(^closeLiveRoomBlock)(BDLInteractiveToolController *interactiveToolController);

/**
 * @locale zh
 * @brief 自定义互动工具菜单。可自定义所有属性。
 * @param controller 互动工具 controller。
 * @param interactiveToolView 互动工具菜单 view。详见 [BDLInteractiveToolView](#BDLInteractiveToolView)。
 * @list 互动工具菜单
 * @return BDLBaseView 及其子类的实例。
 */
/**
 * @locale en
 * @brief Customizes the interaction tools menu. All properties can be customized.
 * @param controller The interaction tools controller.
 * @param interactiveToolView The interaction tools menu view. For more information, see [BDLInteractiveToolView](#BDLInteractiveToolView).
 * @return Instances of `BDLBaseView` and its subclasses.
 */
@property (nonatomic, copy, nullable) __kindof BDLBaseView * _Nullable (^customizeInteractiveToolView)(BDLInteractiveToolController *controller, BDLInteractiveToolView *interactiveToolView);
/**
 * @locale zh
 * @brief 自定义悬浮 view。
 * @param controller 互动工具 controller。
 * @param floatingView 互动工具浮窗 view。详见 [BDLFloatingInteractiveToolView](#BDLFloatingInteractiveToolView)。
 * @list 互动工具菜单
 * @return 浮窗 view。
 */
/**
 * @locale en
 * @brief Customizes the floating window view.
 * @param controller The interaction tools controller.
 * @param floatingView The interaction tool floating window view. For more information, see [BDLFloatingInteractiveToolView](#BDLFloatingInteractiveToolView).
 * @return The floating window view.
 */
@property (nonatomic, copy, nullable) __kindof UIView * _Nullable (^customizeFloatingView)(BDLInteractiveToolController *controller, BDLFloatingInteractiveToolView *floatingView);

/**
 * @locale zh
 * @brief 自定义抽奖详情 view。
 * @param controller 互动工具 controller。
 * @param view 抽奖详情 view。详见 [BDLAwardDetailsView](#BDLAwardDetailsView)。
 * @list 互动工具菜单
 * @return 抽奖详情 view，需要遵守 [BDLPopupBottomShowViewProtocol](1185544#BDLPopupBottomShowViewProtocol) 协议。
 */
/**
 * @locale en
 * @brief Customizes the lucky draw details view.
 * @param controller The interaction tools controller.
 * @param view The lucky draw details view. For more information, see [BDLAwardDetailsView](#BDLAwardDetailsView).
 * @return The lucky draw details view, which needs to conform to the [BDLPopupBottomShowViewProtocol](viewer-sdk-for-ios-type-definitions#BDLPopupBottomShowViewProtocol) protocol.
 */
@property (nonatomic, copy, nullable) __kindof UIView<BDLPopupBottomShowViewProtocol> * _Nullable (^customizeAwardDetailsView)(BDLInteractiveToolController *controller, BDLAwardDetailsView *view);
/**
 * @locale zh
 * @brief 自定义中奖名单 view。
 * @param controller 互动工具 controller。
 * @param view 中奖名单 view。详见 [BDLAwardWinnersView](#BDLAwardWinnersView)。
 * @list 互动工具菜单
 * @return 中奖名单 view，需要遵守 [BDLPopupCenterShowViewProtocol](1185544#BDLPopupCenterShowViewProtocol) 协议。
 */
/**
 * @locale en
 * @brief Customizes the prize winner list view.
 * @param controller The interaction tools controller.
 * @param view The prize winner list view. For more information, see [BDLAwardWinnersView](#BDLAwardWinnersView).
 * @return The prize winner list view, which needs to conform to the [BDLPopupCenterShowViewProtocol](viewer-sdk-for-ios-type-definitions#BDLPopupCenterShowViewProtocol) protocol.
 */
@property (nonatomic, copy, nullable) __kindof UIView<BDLPopupCenterShowViewProtocol> * _Nullable (^customizeAwardWinnersView)(BDLInteractiveToolController *controller, BDLAwardWinnersView *view);
/**
 * @locale zh
 * @brief 自定义抽奖结果 view。
 * @param controller 互动工具 controller。
 * @param view 抽奖结果 view。详见 [BDLAwardResultView](#BDLAwardResultView)。
 * @list 互动工具菜单
 * @return 抽奖结果 view，需要遵守 [BDLPopupCenterShowViewProtocol](1185544#BDLPopupCenterShowViewProtocol) 协议。
 */
/**
 * @locale en
 * @brief Customizes the lucky draw results view.
 * @param controller The interaction tools controller.
 * @param view The lucky draw results view. For more information, see [BDLAwardResultView](#BDLAwardResultView).
 * @return The lucky draw results view, which needs to conform to the [BDLPopupCenterShowViewProtocol](viewer-sdk-for-ios-type-definitions#BDLPopupCenterShowViewProtocol) protocol.
 */
@property (nonatomic, copy, nullable) __kindof UIView<BDLPopupCenterShowViewProtocol> * _Nullable (^customizeAwardResultView)(BDLInteractiveToolController *controller, BDLAwardResultView *view);
/**
 * @locale zh
 * @brief 在观众点击互动消息中的 URL 时，SDK 调用该方法。
 * @param url 点击的 URL。
 * @param enableFloating 是否开启浮层展示。<br>
 *        - `YES`：开启。在直播间浮层展示跳转内容，观众可以边看视频边看跳转内容。
 *        - `NO`：不开启。打开新的浏览器标签页展示跳转内容，观众无法边看视频边看跳转内容。
 * @list 互动工具菜单
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers tap the URL in the interaction tool message.
 * @param url The tapped URL.
 * @param enableFloating Whether the redirected content is displayed on a floating page in the live room.
 *        - `YES`: The redirected content is displayed on a floating page in the live room. Viewers can watch the video and view the redirected content at the same time.
 *        - `NO`: The redirected content is displayed on a new browser tab. Viewers cannot watch the video and view the redirected content at the same time.
 */
@property (nonatomic, copy, nullable) void (^interactiveToolViewURLTappedBlock)(NSURL * _Nullable url, BOOL enableFloating);

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
