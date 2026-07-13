//
//  BDLMoreOptionsController.h
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
#import "BDLMoreOptionsModel.h"
#import <BDLiveCommon/BDLLanguageService.h>
#import "BDLBasicService.h"
#import "BDLMoreOptionsView.h"
#import "BDLMoreOptionsProvider.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN
/**
 * @locale zh
 * @type keytype
 * @brief 更多选项弹窗 controller，实现了更多选项弹窗内多语言切换、清屏、分享、清晰度选择按钮的显示与隐藏逻辑。<br>:::tip
 *        在竖屏直播间内点击右下方的更多（...）图标后，即可弹出更多选项弹窗。<br>:::
 */
/**
 * @locale en
 * @type keytype
 * @brief The more options dialog box controller, which implements the show and hide logic for the buttons of language switching, screen clearing, sharing, and resolution selection in the more options dialog box.
 *        :::tip
 *        The more options dialog box is displayed after viewers tap the more (...) icon in the lower-right corner of the live room in portrait mode.
 *        :::
 */
@interface BDLMoreOptionsController : NSObject <BDLLanguageService, BDLBasicService, BDLMoreOptionsProvider>

/**
 * @locale zh
 * @brief 多语言切换按钮点击回调。详见 [BDLMoreOptionsViewBlock](#bdlmoreoptionsviewblock)。
 */
/**
 * @locale en
 * @brief The callback is triggered when the switch language button is tapped. For more information, see [BDLMoreOptionsViewBlock](#bdlmoreoptionsviewblock).
 */
@property (nonatomic, copy, nullable) BDLMoreOptionsViewBlock multiLanguageClickBlock;
/**
 * @locale zh
 * @brief 清屏按钮点击回调。详见 [BDLMoreOptionsViewBlock](#bdlmoreoptionsviewblock)。
 */
/**
 * @locale en
 * @brief The callback is triggered when the clear screen button is tapped. For more information, see [BDLMoreOptionsViewBlock](#bdlmoreoptionsviewblock).
 */
@property (nonatomic, copy, nullable) BDLMoreOptionsViewBlock clearScreenClickBlock;
/**
 * @locale zh
 * @brief 清晰度选择按钮点击回调。详见 [BDLMoreOptionsViewBlock](#bdlmoreoptionsviewblock)。
 */
/**
 * @locale en
 * @brief The callback is triggered when the select resolution button is tapped. For more information, see [BDLMoreOptionsViewBlock](#bdlmoreoptionsviewblock).
 */
@property (nonatomic, copy, nullable) BDLMoreOptionsViewBlock resolutionClickBlock;
/**
 * @locale zh
 * @brief 礼物效果点击回调
 * @hidden (Windows,Linux,macOS,Android,iOS)
 */
/**
 * @locale en
 * @brief Gift Effect Click Callback
 * @hidden (iOS)
 */
@property (nonatomic, copy, nullable) BDLMoreOptionsViewBlock giftRewardEffectChangeBlock;

/**
 * @locale zh
 * @brief 多语言变化回调。
 * @param controller 更多选项弹窗 controller。
 */
/**
 * @locale en
 * @brief The callback is triggered when the language of the viewing page is changed.
 * @param controller The more options dialog box controller.
 */
@property (nonatomic, copy, nullable) void(^ multiLanguageChangeBlock)(BDLMoreOptionsController *controller);
/**
 * @locale zh
 * @brief 多语言切换、清屏、分享或清晰度选择按钮显示状态变化回调。
 * @param controller 更多选项弹窗 controller。
 */
/**
 * @locale en
 * @brief The callback is triggered when the display status of the buttons for language switching, screen clearing, sharing, or resolution selection is changed.
 * @param controller The controller of the more options dialog box.
 */
@property (nonatomic, copy, nullable) void(^ modelsChangeBlock)(BDLMoreOptionsController *controller);
/**
 * @locale zh
 * @brief 初始化。
 * @param isPortrait 是否以竖屏直播间初始化。<br>
 *        - `YES`：以竖屏直播间初始化。
 *        - `NO`：以横屏直播间初始化。
 * @return 更多选项弹窗 controller 实例。
 */
/**
 * @locale en
 * @brief Initializes the instance of the more options dialog box controller.
 * @param isPortrait Whether to initialize in portrait mode.
 *        - `YES`: Portrait mode.
 *        - `NO`: Landscape mode.
 * @return The instance of the more options dialog box controller.
 */
- (instancetype)initWithPortrait:(BOOL)isPortrait;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
