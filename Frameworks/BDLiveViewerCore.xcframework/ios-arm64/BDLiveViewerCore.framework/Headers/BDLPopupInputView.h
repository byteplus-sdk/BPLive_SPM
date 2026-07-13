//
//  BDLPopupInputView.h
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
#import <BDLiveCommon/BDLBaseView.h>
#import <BDLiveCommon/BDLLanguageService.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 昵称输入框 view。
 */
/**
 * @locale en
 * @brief The nickname text box view.
 */
@interface BDLPopupInputView : BDLBaseView

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
 * @brief 输入框。可自定义除 `attributedPlaceholder`、`backgroundColor`、`textColor`、`font` 外的所有属性。
 */
/**
 * @locale en
 * @brief The text box. All properties except `attributedPlaceholder`, `backgroundColor`, `textColor`, and `font` can be customized.
 */
@property (nonatomic, strong, readonly) UITextField *inputTextField;

/**
 * @locale zh
 * @brief 确认按钮点击回调。
 * @param text 输入的昵称。
 */
/**
 * @locale en
 * @brief The callback is triggered when the confirm button is tapped.
 * @param text The entered nickname.
 */
@property (nonatomic, copy, nullable) void (^confirmBlock)(NSString *__nullable text);
/**
 * @locale zh
 * @brief 关闭按钮点击回调。
 */
/**
 * @locale en
 * @brief The callback is triggered when the close button is tapped.
 */
@property (nonatomic, copy, nullable) void (^closeBlock)(void);

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
