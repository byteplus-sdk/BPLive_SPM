//
//  BDLInteractiveToolConfiguration.h
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
#import "BDLRTBaseConfiguration.h"
#import "BDLFloatingInteractiveToolViewType.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

#define BDL_INTERACTIVE_TOOL_MARGIN 12.0

/**
 * @locale zh
 * @type keytype
 * @brief 互动工具菜单配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The configuration of the menu for interation tools.
 */
@interface BDLInteractiveToolConfiguration : BDLRTBaseConfiguration

/**
 * @locale zh
 * @brief 自定义浮窗图标中的图片 view。
 * @param imageView 浮窗图标的 imageView。
 * @param type 互动工具浮窗 view 的类型。详见 [BDLFloatingInteractiveToolViewType](1185544#BDLFloatingInteractiveToolViewType)。
 */
/**
 * @locale en
 * @brief Customizes the floating window image view.
 * @param imageView The floating window image view.
 * @param type The type of interaction tool floating window view. For details, see [BDLFloatingInteractiveToolViewType](viewer-sdk-for-ios-type-definitions#bdlfloatinginteractivetoolviewtype).
 */
@property (nonatomic, copy, nullable) void(^customizeFloatingViewImageViewImage)(UIImageView *imageView, BDLFloatingInteractiveToolViewType type);

@end

/**
 * @locale zh
 * @type keytype
 * @brief 互动工具菜单配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The configuration of the menu for interaction tools.
 */
@interface BDLInteractiveToolConfiguration (Config)
/**
 * @locale zh
 * @brief 是否显示参与投票人数。默认值：`YES`。
 *        - `YES`：显示。
 *        - `NO`：不显示。
 */
/**
 * @locale en
 * @brief Whether to display the number of viewers who participate in the vote. Default value: `YES`.
 *        - `YES`: Display.
 *        - `NO`: Do not display.
 */
@property (nonatomic, assign) BOOL showPeopleCount;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
