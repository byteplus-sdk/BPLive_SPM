//
//  BDLPlayerSpeedView.h
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

/**
 * @locale zh
 * @type keytype
 * @brief 播放速度。
 */
/**
 * @locale en
 * @type keytype
 * @brief The playback speed.
 */
typedef NS_ENUM(NSUInteger, BDLPlayerSpeed) {
/**
 * @locale zh
 * @brief 2 倍速。
 */
   /**
    * @locale en
    * @brief 2x speed.
    */
    BDLPlayerSpeed200X,
/**
 * @locale zh
 * @brief 1.5 倍速。
 */
   /**
    * @locale en
    * @brief 1.5x speed.
    */
    BDLPlayerSpeed150X,
/**
 * @locale zh
 * @brief 1.25 倍速。
 */
   /**
    * @locale en
    * @brief 1.25x speed.
    */
    BDLPlayerSpeed125X,
/**
 * @locale zh
 * @brief 正常播放。
 */
   /**
    * @locale en
    * @brief Normal speed.
    */
    BDLPlayerSpeed100X,
/**
 * @locale zh
 * @brief 0.75 倍速。
 */
   /**
    * @locale en
    * @brief 0.75x speed.
    */
    BDLPlayerSpeed075X,
/**
 * @locale zh
 * @brief 0.5 倍速。
 */
   /**
    * @locale en
    * @brief 0.5x speed.
    */
    BDLPlayerSpeed050X,
};

@class BDLPlayerSpeedView;

/**
 * @locale zh
 * @type callback
 * @brief 倍速选择 view 的代理方法。
 */
/**
 * @locale en
 * @type callback
 * @brief The delegate methods for the playback speed selection view.
 */
@protocol BDLPlayerSpeedViewDelegate <NSObject>
/**
 * @locale zh
 * @brief 在倍速改变时，SDK 调用该方法。
 * @param speedView 倍速选择 view。详见 [BDLPlayerSpeedView](1185540#BDLPlayerSpeedView)。
 * @param speed 当前的倍速。详见 [BDLPlayerSpeed](1185544#BDLPlayerSpeed)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the playback speed changes.
 * @param speedView The playback speed selection view. For more information, see [BDLPlayerSpeedView](docs-bdlliveengine#BDLPlayerSpeedView).
 * @param speed The current playback speed. For more information, see [BDLPlayerSpeed](viewer-sdk-for-ios-type-definitions#BDLPlayerSpeed).
 */
- (void)speedView:(BDLPlayerSpeedView *)speedView speedDidChange:(BDLPlayerSpeed)speed;

@end

/**
 * @locale zh
 * @type api
 * @brief 倍速选择 view。
 */
/**
 * @locale en
 * @brief The playback speed selection view.
 */
@interface BDLPlayerSpeedView : BDLPopupBottomOrRightShowBaseView <BDLLanguageService>
/**
 * @locale zh
 * @brief 自定义倍速按钮。
 * @param buttons 倍速按钮数组。
 * @param selectedIndex 当前选中的数组下标。
 */
/**
 * @locale en
 * @brief Customizes the playback speed button.
 * @param buttons An array of playback speed buttons.
 * @param selectedIndex The currently selected array index.
 */
@property (nonatomic, copy, nullable) void (^customizeSpeedButtons)(NSArray<UIButton *> * buttons, NSUInteger selectedIndex);

/**
 * @locale zh
 * @brief 代理方法。详见 [BDLPlayerSpeedViewDelegate](1185541#BDLPlayerSpeedViewDelegate)。
 */
/**
 * @locale en
 * @brief The delegate method. For more information, see [BDLPlayerSpeedViewDelegate](viewer-SDK-for-ios-callbacks#BDLPlayerSpeedViewDelegate).
 */
@property (nonatomic, weak) id<BDLPlayerSpeedViewDelegate> delegate;
/**
 * @locale zh
 * @brief 初始化。
 * @param isPortrait 是否以竖屏直播间初始化。<br>
 *        - `YES`：以竖屏直播间初始化。
 *        - `NO`：以横屏直播间初始化。
 * @param config 配置。详见 [BDLPlayerConfiguration](1185544#BDLPlayerConfiguration)。
 * @return 倍速选择 view 实例。
 */
/**
 * @locale en
 * @brief Initializes the instance of the playback speed selection view.
 * @param isPortrait Whether to initialize in portrait mode.
 *        - `YES`: Portrait mode.
 *        - `NO`: Landscape mode.
 * @param config The configuration. For more information, see [BDLPlayerConfiguration](viewer-sdk-for-ios-type-definitions#BDLPlayerConfiguration).
 * @return The instance of the playback speed selection view.
 */
- (instancetype)initWithPortrait:(BOOL)isPortrait config:(BDLPlayerConfiguration *)config;
/**
 * @locale zh
 * @brief 当前是否为全屏。
 *        - `YES`：全屏。
 *        - `NO`：非全屏。
 */
/**
 * @locale en
 * @brief Whether currently is in full-screen mode.
 *        - `YES`: In full-screen mode.
 *        - `NO`: Not in full-screen mode.
 */
@property (nonatomic, assign) BOOL fullScreen;
/**
 * @locale zh
 * @brief 当前播放速度。详见 [BDLPlayerSpeed](1185544#BDLPlayerSpeed)。
 */
/**
 * @locale en
 * @brief The current playback speed. For more information, see [BDLPlayerSpeed](viewer-sdk-for-ios-type-definitions#BDLPlayerSpeed).
 */
@property (nonatomic, assign) BDLPlayerSpeed speed;
/**
 * @locale zh
 * @brief 根据枚举值切换倍速的值。
 * @param speed 播放速度。详见 [BDLPlayerSpeed](1185544#BDLPlayerSpeed)。
 * @return 播放速度。
 */
/**
 * @locale en
 * @brief Changes the playback speed based on the enumeration value.
 * @param speed The playback speed. For more information, see [BDLPlayerSpeed](viewer-sdk-for-ios-type-definitions#BDLPlayerSpeed).
 * @return The playback speed.
 */
+ (CGFloat)valueFromSpeed:(BDLPlayerSpeed)speed;
/**
 * @locale zh
 * @brief 根据配置更新 view。
 * @param config 配置。详见 [BDLPlayerConfiguration](1185544#BDLPlayerConfiguration)。
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
