//
//  BDLRiskWarningView.h
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
#import "BDLBasicService.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 风险提示 view。
 */
/**
 * @locale en
 * @brief The reminder view.
 */
@interface BDLRiskWarningView : BDLPopupCenterShowBaseView

/**
 * @locale zh
 * @brief 当前的语言类型。详见 [BDLLanguageType](1185544#BDLLanguageType)。
 */
/**
 * @locale en
 * @brief The current language type. For more information, see [BDLLanguageType](viewer-sdk-for-ios-type-definitions#BDLLanguageType).
 */
@property (nonatomic, assign, readonly) BDLLanguageType languageType;
/**
 * @locale zh
 * @brief 当前所有支持的语言类型。
 */
/**
 * @locale en
 * @brief All the currently supported language types.
 */
@property (nonatomic, copy, readonly) NSArray *languageTypeArray;
/**
 * @locale zh
 * @brief 顶部的背景图 view。支持自定义。
 */
/**
 * @locale en
 * @brief The top background image view. Customization is supported.
 */
@property (nonatomic, strong, readonly) UIImageView *topBackgroundImageView;
/**
 * @locale zh
 * @brief 标题 label。不支持自定义 `text`。您可以通过企业直播服务端自定义标题。
 */
/**
 * @locale en
 * @brief The title label. All properties except `text` can be customized. You can customize the title on the BytePlus Live server.
 */
@property (nonatomic, strong, readonly) UILabel *titleLabel;
/**
 * @locale zh
 * @brief 内容 label。不支持自定义 `text`。您可以通过企业直播服务端自定义内容。
 */
/**
 * @locale en
 * @brief The content label. All properties except `text` can be customized. You can customize the content on the BytePlus Live server.
 */
@property (nonatomic, strong, readonly) UILabel *contentLabel;
/**
 * @locale zh
 * @brief 需滚动查看底部内容时，内容底部的半透明 view。不支持自定义 `hidden`。
 */
/**
 * @locale en
 * @brief The semi-transparent view at the bottom of the content that appears when scrolling to the bottom. All properties except `hidden` can be customized.
 */
@property (nonatomic, strong, readonly) UIView *bottomMaskView;
/**
 * @locale zh
 * @brief 确认按钮。支持自定义除 `title`（按钮文字）外的所有属性。
 */
/**
 * @locale en
 * @brief The confirm button. All properties except `title` (button text) can be customized.
 */
@property (nonatomic, strong, readonly) UIButton *confirmButton;

/**
 * @locale zh
 * @brief 确认按钮点击回调。
 * @param view 风险提示 view。
 * @list 其他
 */
/**
 * @locale en
 * @brief The callback is triggered when the confirm button is tapped.
 * @param view The reminder view.
 */
@property (nonatomic, copy) void(^onConfirmButtonClickBlock)(BDLRiskWarningView *view);

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
