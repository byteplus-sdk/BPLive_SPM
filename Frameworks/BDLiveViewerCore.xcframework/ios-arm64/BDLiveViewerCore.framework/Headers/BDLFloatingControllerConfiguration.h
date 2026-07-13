//
//  BDLFloatingControllerConfiguration.h
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
 * @brief 浮窗 controller 配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The configuration of the floating window controller.
 */
@interface BDLFloatingControllerConfiguration : BDLRTBaseConfiguration

/**
 * @locale zh
 * @brief 是否在弹出键盘时自动隐藏所有浮窗控件，例如浮窗商品卡片、浮标广告、互动工具浮窗等。默认值：`NO`。取值如下：
 *        - `YES`：自动隐藏。
 *        - `NO`：不自动隐藏。
 */
/**
 * @locale en
 * @brief Whether to automatically hide all the floating window controls, such as the floating product card, the floating ad, and interaction tool floating windows, when the keyboard pops up. Default value: `NO`. Valid values:
 *        - `YES`: Automatically hide.
 *        - `NO`: Do not automatically hide.
 */
@property (nonatomic, assign) BOOL hideFloatingViewsWhenKeyboardShow;

/**
 * @locale zh
 * @brief 是否隐藏竖屏直播间顶部区域，顶部区域包括：关闭按钮，账号信息，人气值，多线路按钮。默认值：`NO`。取值如下：
 *        - `YES`：隐藏。
 *        - `NO`：不隐藏。
 */
/**
 * @locale en
 * @brief Whether to hide the top area of the portrait room, which includes: the close button, account information, popularity value, and multi-line button. Default value: `NO`. Valid values:
 *        - `YES`: Hide.
 *        - `NO`: Do not hide.
 */
@property (nonatomic, assign) BOOL hidePortraitRoomTopArea;

/**
 * @locale zh
 * @brief 竖屏直播间浮窗控件容器中，右上角子View距离顶部的间距。默认值：`70`。
 */
/**
 * @locale en
 * @brief The margin between the top of the floating window container and the top of the right-top child views. Default value: `70`.
 */
@property (nonatomic, assign) CGFloat topMarginForRightTopChildViews;

/**
 * @locale zh
 * @brief 竖屏直播间浮窗控件容器中，左上角子View距离顶部的间距。默认值：`70`。
 */
/**
 * @locale en
 * @brief The margin between the top of the floating window container and the top of the left-top child views. Default value: `70`.
 */
@property (nonatomic, assign) CGFloat topMarginForLeftTopChildViews;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
