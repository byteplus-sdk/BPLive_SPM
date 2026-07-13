//
//  BDLAudienceLinkRemoteContainerView.h
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
#import "BDLAudienceLinkLayoutResult.h"


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 连麦画面容器 view，用于展示当前连麦观众和其他连麦参与者的画面。
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@interface BDLAudienceLinkRemoteContainerView : UIView

/**
 * @locale zh
 * @type api
 * @brief 连麦画面 view 的填充模式。默认值为 `UIViewContentModeScaleAspectFit`。取值如下：<br>
 *        - `UIViewContentModeScaleAspectFit`
 *        - `UIViewContentModeScaleAspectFill`<br>详见 [UIViewContentMode](https://developer.apple.com/documentation/uikit/uiviewcontentmode?language=objc)。
 */
@property (nonatomic, assign) UIViewContentMode contentMode;
/**
 * @locale zh
 * @brief 单个连麦参与者画面的点击回调。
 * @param containerView `BDLAudienceLinkRemoteContainerView` 实例。
 * @param user 画面被点击的连麦参与者信息。详见[BDLAudienceLinkLayoutUser](#BDLAudienceLinkLayoutUser)。
 * @param isSelf 是否点击了自己的画面。取值如下：<br>
 *        - `YES`：当前连麦观众自己的画面。
 *        - `NO`：其他连麦参与者的画面。
 * @list 连麦
 */
/**
 * @locale en
 * @list 
 */
@property (nonatomic, copy, nullable) void(^onUserVideoClickBlock)(BDLAudienceLinkRemoteContainerView *containerView, BDLAudienceLinkLayoutUser *user, BOOL isSelf);

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
