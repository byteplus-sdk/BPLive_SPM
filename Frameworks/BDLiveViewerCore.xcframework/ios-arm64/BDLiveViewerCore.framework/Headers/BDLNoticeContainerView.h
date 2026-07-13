//
//  BDLNoticeContainerView.h
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
#import "BDLNoticeService.h"
#import "BDLInteractiveToolService.h"
#import "BDLAwardNoticeView.h"
#import "BDLCustomNoticeView.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 通知的容器 view。
 */
/**
 * @locale en
 * @type api 
 * @brief The container view of notifications.
 */
@interface BDLNoticeContainerView : BDLBaseView <BDLNoticeService, BDLInteractiveToolService>

/**
 * @locale zh
 * @brief 自定义抽奖通知 view。
 * @param view 通知的容器 view。
 * @param noticeView 抽奖通知 view。详见 [BDLAwardNoticeView](#BDLAwardNoticeView)。
 * @param award 抽奖信息。详见 [BDLInteractiveAwardModel](1185544#BDLInteractiveAwardModel)。
 * @list 其他
 * @return `UIView` 及其子类的实例。
 */
/**
 * @locale en
 * @brief Customizes the lucky draw notification view.
 * @param view The container view of notifications.
 * @param noticeView The lucky draw notification view. For more information, see [BDLAwardNoticeView](#BDLAwardNoticeView).
 * @param award The lucky draw information. For more information, see [BDLInteractiveAwardModel](viewer-sdk-for-ios-type-definitions#BDLInteractiveAwardModel).
 * @return Instances of `UIView` and its subclasses.
 */
@property (nonatomic, copy) __kindof UIView * (^customizeAwardNoticeView)(BDLNoticeContainerView *view, BDLAwardNoticeView *noticeView, BDLInteractiveAwardModel *award);
/**
 * @locale zh
 * @brief 自定义自定义消息通知 view。
 * @param view 通知的容器 view。
 * @param noticeView 自定义消息通知 view。详见 [BDLCustomNoticeView](#BDLCustomNoticeView)。
 * @param notice 自定义消息。详见 [BDLCustomNotice](1185544#BDLCustomNotice)。
 * @list 其他
 * @return `UIView` 及其子类的实例。
 */
/**
 * @locale en
 * @hidden (iOS)
 * @brief Customizes the custom message notification view.
 * @param view The container view for notifications.
 * @param noticeView Custom notification view. See [BDLCustomNoticeView](#BDLCustomNoticeView) for details.
 * @param notice Custom message. For details, see [BDLCustomNotice](viewer-sdk-for-ios-type-definitions#BDLCustomNotice).
 */
@property (nonatomic, copy) __kindof UIView * (^customizeCustomNoticeView)(BDLNoticeContainerView *view, BDLCustomNoticeView *noticeView, BDLCustomNotice *notice);
/**
 * @locale zh
 * @brief 隐藏正在显示的通知 view。
 * @list 其他
 * @param finish 隐藏完成回调。
 */
/**
 * @locale en
 * @brief Hides the currently displayed notification view.
 * @param finish The callback triggered when the notification view is hidden.
 */
- (void)hideShowingNoticeViewWithFinish:(void (^ _Nullable )(void))finish;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
