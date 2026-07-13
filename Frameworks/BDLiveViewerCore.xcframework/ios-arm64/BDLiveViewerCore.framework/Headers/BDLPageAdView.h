//
//  BDLPageAdView.h
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
#import "BDLMarketService.h"
#import "BDLBasicService.h"
#import "BDLPageAdViewConfiguration.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type keytype
 * @brief 页中广告协议，自定义页中广告返回的 view（例如 [BDLPageAdView](1185540#BDLPageAdView)）需要遵守该协议。
 */
/**
 * @locale en
 * @type keytype
 * @brief The protocol for in-page ads, which must be followed by views returned by custom in-page ads, such as [BDLPageAdView](docs-bdlliveengine#BDLPageAdView).
 */
@protocol BDLPageAdViewProtocol

/**
 * @locale zh
 * @brief 对于自定义页中广告 view，需要实现该方法，同时在隐藏页中广告时调用 block。
 * @param block 需要调用的 block。
 */
/**
 * @locale en
 * @brief For the custom in-page ad view, this method needs to be implemented. Additionally, the block needs to be called when hiding the in-page ad.
 * @param block The block that needs to be called when hiding the in-page ad.
 */
- (void)setShowOrHideBlock:(void (^)(UIView *view))block;

@end
/**
 * @locale zh
 * @type api
 * @brief 页中广告 view。
 */
/**
 * @locale en
 * @brief The in-page ad view.
 */
@interface BDLPageAdView : BDLBaseView <BDLPageAdViewProtocol, BDLMarketService, BDLBasicService>
/**
 * @locale zh
 * @brief 初始化。
 * @param isPortrait 是否以竖屏直播间初始化。
 *        - `YES`：以竖屏直播间初始化。
 *        - `NO`：以横屏直播间初始化。
 * @list 页中广告
 * @return 页中广告 view 实例。
 */
/**
 * @locale en
 * @brief Initializes the instance of the in-page ad view.
 * @param isPortrait Whether to initialize in portrait mode.
 *        - `YES`: Portrait mode.
 *        - `NO`: Landscape mode.
 * @return The instance of the in-page ad view.
 */
- (instancetype)initWithPortrait:(BOOL)isPortrait;
/**
 * @locale zh
 * @brief 当前正在显示的广告 Model。详见 [BDLAdvertisementModel](1185544#BDLAdvertisementModel)。
 */
/**
 * @locale en
 * @brief The model of currently displayed ad. For more information, see [BDLAdvertisementModel](viewer-sdk-for-ios-type-definitions#BDLAdvertisementModel).
 */
@property (nonatomic, copy, readonly) NSArray<BDLAdvertisementModel *> *showingPageAdModels;
/**
 * @locale zh
 * @brief 当前页中广告所持有的配置。详见 [BDLPageAdViewConfiguration](1185544#BDLPageAdViewConfiguration)。
 */
/**
 * @locale en
 * @brief The configuration of the current in-page ad. For more information, see [BDLPageAdViewConfiguration](viewer-sdk-for-ios-type-definitions#BDLPageAdViewConfiguration).
 */
@property (nonatomic, strong, readonly) BDLPageAdViewConfiguration *config;
/**
 * @locale zh
 * @brief 页中广告的轮播基于 `collectionView` 实现。
 */
/**
 * @locale en
 * @brief The in-page ad carousel is implemented based on the `collectionView`.
 */
@property (nonatomic, strong) UICollectionView *collectionView;

/**
 * @locale zh
 * @brief 页中广告点击回调。
 * @param view 页中广告 view。
 * @param ad 企业直播服务端返回的广告信息。详见 [BDLAdvertisementModel](1185544#BDLAdvertisementModel) 。
 * @param isFloatingEnable 是否开启浮层展示。<br>
 *        - `YES`：开启。观众点击广告后，在当前观看页以浮层形式展示广告内容。观众可以边看视频边看广告。
 *        - `NO`：未开启。观众点击广告后，页面自动跳转至新的浏览器标签页展示广告内容，观众无法边看视频边看广告。
 * @list 页中广告
 */
/**
 * @locale en
 * @brief The callback is triggered when the in-page ad is tapped.
 * @param view The in-page ad view.
 * @param ad The ad information, which is returned by the BytePlus Live server. For more information, see [BDLAdvertisementModel](viewer-sdk-for-ios-type-definitions#BDLAdvertisementModel).
 * @param isFloatingEnable Whether the ad details page is displayed on a floating page in the live room.
 *        - `YES`: The ad details page is displayed on a floating page in the live room after viewers tap the in-page ad. Viewers can watch the video and view the ad details page at the same time.
 *        - `NO`: The ad details page is displayed on a new browser tab after viewers tap the in-page ad. Viewers cannot watch the video and view the ad details page at the same time.
 */
@property (nonatomic, copy, nullable) void (^viewTappedBlock)(BDLPageAdView *view, BDLAdvertisementModel *ad, BOOL isFloatingEnable);
/**
 * @locale zh
 * @brief 关闭按钮点击回调。
 * @list 页中广告
 */
/**
 * @locale en
 * @brief The callback is triggered when the close button is tapped.
 */
@property (nonatomic, copy, nullable) void (^closeButtonClickedBlock)(void);

/**
 * @locale zh
 * @brief 竖屏模式配置页中或页头广告时或者横屏模式配置页中广告时触发该方法。
 * @param adView 页中广告 view。
 * @param type 广告类型。详见 [BDLPageAdvertisementType](1185544#BDLPageAdvertisementType)。
 * @list 页中广告
 * @return 是否显示广告。默认值：`YES`。<br>
 *         - `YES`：显示广告。
 *         - `NO`：不显示广告。
 */
/**
 * @locale en
 * @brief The callback is triggered when the in-page or header ad is configured for live rooms in portrait mode or when the in-page ad is configured for live rooms in landscape mode.
 * @param adView The in-page ad view.
 * @param type The ad type. For more information, see [BDLPageAdvertisementType](viewer-sdk-for-ios-type-definitions#BDLPageAdvertisementType).
 * @return Whether to display the ad. Default value: `YES`.
 *         - `YES`: Display.
 *         - `NO`: Do not display.
 */
@property (nonatomic, copy, nullable) BOOL (^shouldShowAdBlock)(BDLPageAdView *adView, BDLPageAdvertisementType type);

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
