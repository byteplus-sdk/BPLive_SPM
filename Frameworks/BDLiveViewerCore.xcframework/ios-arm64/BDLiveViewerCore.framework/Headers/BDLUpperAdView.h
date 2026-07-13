//
//  BDLUpperAdView.h
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
#import "BDLPageUpperAdService.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 浮标广告 view。
 */
/**
 * @locale en
 * @brief The floating ad view.
 */
@interface BDLUpperAdView : BDLBaseView <BDLPageUpperAdService>

/**
 * @locale zh
 * @brief 关闭按钮。可自定义除 `frame` 、`hidden` 外的所有属性。
 */
/**
 * @locale en
 * @brief The close button. All properties except `frame` and `hidden` can be customized.
 */
@property (nonatomic, strong) UIButton* closeButton;
/**
 * @locale zh
 * @brief 广告图片。可自定义除 `frame` 、`hidden` 外的所有属性。
 */
/**
 * @locale en
 * @brief The ad image. All properties except `frame` and `hidden` can be customized.
 */
@property (nonatomic, strong) UIImageView* imageView;
/**
 * @locale zh
 * @brief 浮标广告点击回调。
 * @param urlStr 企业直播服务端返回的跳转链接。
 * @param enableFloating 是否开启浮层展示。<br>
 *        - `YES`：开启。观众点击浮标广告后，在当前观看页以浮层形式展示浮标广告详情。观众可以边看视频边查看浮标广告。
 *        - `NO`：未开启。观众点击浮标广告后，页面自动跳转至新的浏览器标签页展示浮标广告详情。观众无法边看视频边查看浮标广告。
 * @list 浮窗广告
 */
/**
 * @locale en
 * @brief The callback is triggered when the floating ad is tapped.
 * @param urlStr The embedded link returned by the BytePlus Live server.
 * @param enableFloating Whether the ad details page is displayed on a floating page in the live room.
 *        - `YES`: The ad details page is displayed on a floating page in the live room after viewers tap the floating ad. Viewers can watch the video and view the ad details page at the same time.
 *        - `NO`: The ad details page is displayed on a new browser tab after viewers tap the floating ad. Viewers cannot watch the video and view the ad details page at the same time.
 */
@property (nonatomic, copy, nullable) void (^viewTappedBlock)(NSString * _Nullable urlStr, BOOL enableFloating);
/**
 * @locale zh
 * @brief 关闭按钮点击回调。
 * @list 浮窗广告
 */
/**
 * @locale en
 * @brief The callback is triggered when the close button is tapped.
 */
@property (nonatomic, copy, nullable) void (^closeButtonClickedBlock)(void);

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
