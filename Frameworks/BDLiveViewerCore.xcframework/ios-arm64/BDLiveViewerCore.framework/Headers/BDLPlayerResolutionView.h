//
//  BDLPlayerResolutionView.h
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


#import <BDLiveCommon/BDLPopupBaseView.h>
#import <BDLiveCommon/BDLLanguageService.h>
#import "BDLPlayerConfiguration.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

@class BDLPlayerResolutionView;

/**
 * @locale zh
 * @type callback
 * @brief 清晰度选择 view 的代理方法。
 */
/**
 * @locale en
 * @type callback
 * @brief The delegate methods for the resolution selection view.
 */
@protocol BDLPlayerResolutionViewDelegate <NSObject>
/**
 * @locale zh
 * @brief 在清晰度改变时，SDK 调用该方法。
 * @param resolution 当前使用的清晰度。详见 [BDLVideoResolution](1185544#BDLVideoResolution)。
 * @param resolutionView 清晰度选择 view。详见 [BDLPlayerResolutionView](1185540#BDLPlayerResolutionView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the resolution changes.
 * @param resolutionView The resolution selection view. For more information, see [BDLPlayerResolutionView](docs-bdlliveengine#BDLPlayerResolutionView).
 * @param resolution The currently used resolution. For more information, see [BDLVideoResolution](viewer-sdk-for-ios-type-definitions#BDLVideoResolution).
 */
- (void)resolutionView:(BDLPlayerResolutionView *)resolutionView resolutionDidChange:(BDLVideoResolution)resolution;

@end

/**
 * @locale zh
 * @type api
 * @brief 清晰度选择 view。
 */
/**
 * @locale en
 * @brief The resolution selection view.
 */
@interface BDLPlayerResolutionView : BDLPopupBottomOrRightShowBaseView <BDLLanguageService>

/**
 * @locale zh
 * @brief 代理方法。详见 [BDLPlayerResolutionViewDelegate](1185541#BDLPlayerResolutionViewDelegate)。
 */
/**
 * @locale en
 * @brief The delegate method. For more information, see [BDLPlayerResolutionViewDelegate](viewer-SDK-for-ios-callbacks#BDLPlayerResolutionViewDelegate).
 */
@property (nonatomic, weak) id<BDLPlayerResolutionViewDelegate> delegate;

/**
 * @locale zh
 * @brief 当前是否全屏。<br>
 *        - `YES`：全屏。
 *        - `NO`：非全屏。
 */
/**
 * @locale en
 * @brief Whether in full-screen mode.
 *        - `YES`: In full-screen mode.
 *        - `NO`: Not in full-screen mode.
 */
@property (nonatomic, assign) BOOL fullScreen;

/**
 * @locale zh
 * @brief 更新清晰度。
 * @param resolutions 所有支持的清晰度。
 * @param currentResolution 当前选中的清晰度。详见 [BDLVideoResolution](1185544#BDLVideoResolution)。
 * @list 播放器
 */
/**
 * @locale en
 * @brief Updates the resolution.
 * @param resolutions All the supported resolutions.
 * @param currentResolution The currently selected resolution. For more information, see [BDLVideoResolution](viewer-sdk-for-ios-type-definitions#BDLVideoResolution).
 */
- (void)updateWithResolutions:(NSArray<NSNumber *> *)resolutions currentResolution:(BDLVideoResolution)currentResolution;
/**
 * @locale zh
 * @brief 修改清晰度，用于同步清晰度按钮的显示。
 * @param success 清晰度是否修改成功。
 *        - `YES`：成功。
 *        - `NO`：失败。
 * @param completeResolution 最终的清晰度。详见 [BDLVideoResolution](1185544#BDLVideoResolution)。
 * @list 播放器
 */
/**
 * @locale en
 * @brief Changes the resolution to synchronize the display of the resolution button.
 * @param success Whether the resolution change is successful.
 *        - `YES`: Successful.
 *        - `NO`: Failed.
 * @param completeResolution The final resolution. For more information, see [BDLVideoResolution](viewer-sdk-for-ios-type-definitions#BDLVideoResolution).
 */
- (void)changeResolutionSuccess:(BOOL)success completeResolution:(BDLVideoResolution)completeResolution;

/**
 * @locale zh
 * @brief 根据配置更新 view。
 * @param config 配置。详见 [BDLPlayerConfiguration](1185544#BDLPlayerConfiguration)。
 * @list 播放器
 */
/**
 * @locale en
 * @brief Updates the view based on the configuration.
 * @param config The configuration. For more information, see [BDLPlayerConfiguration](viewer-sdk-for-ios-type-definitions#BDLPlayerConfiguration).
 */
- (void)updateWithConfig:(BDLPlayerConfiguration *)config;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
