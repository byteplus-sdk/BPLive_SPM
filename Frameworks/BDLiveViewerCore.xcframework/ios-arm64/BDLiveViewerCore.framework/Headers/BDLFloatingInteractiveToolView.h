//
//  BDLFloatingInteractiveToolView.h
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
#import "BDLInteractiveToolModel.h"
#import "BDLFloatingInteractiveToolViewType.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 互动工具浮窗 view。
 */
/**
 * @locale en
 * @brief The interaction tool floating window view.
 */
@interface BDLFloatingInteractiveToolView : BDLBaseView

/**
 * @locale zh
 * @brief 初始化。
 * @param type 互动工具浮窗 view 的类型。详见 [BDLFloatingInteractiveToolViewType](1185544#BDLFloatingInteractiveToolViewType)。
 * @param isPortrait 是否以竖屏直播间初始化。
 *        - `YES`：以竖屏直播间初始化。
 *        - `NO`：以横屏直播间初始化。
 * @return 互动工具浮窗 view 实例。
 */
/**
 * @locale en
 * @brief Initializes the instance of the interaction tool floating window view.
 * @param type The type of the interaction tool floating window view. For more information, see [BDLFloatingInteractiveToolViewType](viewer-sdk-for-ios-type-definitions#BDLFloatingInteractiveToolViewType).
 * @param isPortrait Whether to initialize in portrait mode.
 *        - `YES`: Portrait mode.
 *        - `NO`: Landscape mode.
 * @return The instance of the interaction tool floating window view.
 */
- (instancetype)initWithType:(BDLFloatingInteractiveToolViewType)type isPortrait:(BOOL)isPortrait;

/**
 * @locale zh
 * @brief 当前 view 对应的互动工具 Model。`type` 不同，Model 的类型也不同。
 */
/**
 * @locale en
 * @brief The interaction tool model corresponding to the current view. The model type varies depending on the `type`.
 */
@property (nonatomic, strong) id model;

/**
 * @locale zh
 * @brief 互动工具浮窗 view 的类型，由初始化方法 [initWithType:isPortrait:](#BDLFloatingInteractiveToolView-initwithtype-isportrait) 传入。
 */
/**
 * @locale en
 * @brief The type of the interaction tool floating window view, which is passed in through the initialization method [initWithType:isPortrait:](#BDLFloatingInteractiveToolView-initwithtype-isportrait).
 */
@property (nonatomic, assign, readonly) BDLFloatingInteractiveToolViewType type;

/**
 * @locale zh
 * @brief 显示图标的 imageView。 如需自定义图片，通过 [customizeFloatingViewImageViewImage](#BDLInteractiveToolConfiguration-customizeFloatingViewImageViewImage) 设置。
 */
/**
 * @locale en
 * @brief The imageView that displays the icon. To customize the image, use [customizeFloatingViewImageViewImage](#BDLInteractiveToolConfiguration-customizeFloatingViewImageViewImage).
 */
@property (nonatomic, strong, readonly) UIImageView *imageView;

/**
 * @locale zh
 * @brief 底部文字 label。可自定义除 `text` 外的所有属性。
 */
/**
 * @locale en
 * @brief The bottom text label. All properties except `text` can be customized.
 */
@property (nonatomic, strong, readonly) UILabel *label;

/**
 * @locale zh
 * @brief 关闭按钮。支持自定义。
 */
/**
 * @locale en
 * @brief The close button. Customization is supported.
 */
@property (nonatomic, strong, readonly) UIButton *closeButton;

/**
 * @locale zh
 * @brief 当前 view 点击回调。
 * @param view 互动工具浮窗 view。
 */
/**
 * @locale en
 * @brief The callback is triggered when the current view is tapped.
 * @param view The interaction tool floating window view.
 */
@property (nonatomic, copy) void(^clickBlock)(BDLFloatingInteractiveToolView *view);

/**
 * @locale zh
 * @brief 关闭按钮点击回调。
 * @param view 互动工具浮窗 view。
 * @param button 关闭按钮。
 */
/**
 * @locale en
 * @brief The callback is triggered when the close button is tapped.
 * @param view The interaction tool floating window view.
 * @param button The close button.
 */
@property (nonatomic, copy) void(^closeButtonClickBlock)(BDLFloatingInteractiveToolView *view, UIButton *button);

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
