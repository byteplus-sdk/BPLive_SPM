//
//  BDLPopupInputViewConfiguration.h
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

#import "BDLRTBaseConfiguration.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

/**
 * @locale zh
 * @type keytype
 * @brief 昵称输入框配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The configuration of nickname text box.
 */
@interface BDLPopupInputViewConfiguration : BDLRTBaseConfiguration

@end

/**
 * @locale zh
 * @type keytype
 * @brief 昵称输入框配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The configuration of the nickname text box.
 */
@interface BDLPopupInputViewConfiguration (Config)

/**
 * @locale zh
 * @brief 输入框占位文字。
 */
/**
 * @locale en
 * @brief The placeholder text of the text box.
 */
@property (nonatomic, copy) NSString *inputPlaceholder;
/**
 * @locale zh
 * @brief 标题文字。
 */
/**
 * @locale en
 * @brief The title text.
 */
@property (nonatomic, copy) NSString *titleText;
/**
 * @locale zh
 * @brief 确认按钮文字。
 */
/**
 * @locale en
 * @brief The text of the confirm button.
 */
@property (nonatomic, copy) NSString *confirmTitle;

/**
 * @locale zh
 * @brief 标题字体和字号。
 */
/**
 * @locale en
 * @brief The font and font size of the title.
 */
@property (nonatomic, strong) UIFont *titleFont;
/**
 * @locale zh
 * @brief 输入框字体和字号。
 */
/**
 * @locale en
 * @brief The font and font size of the text box.
 */
@property (nonatomic, strong) UIFont *textFieldFont;
/**
 * @locale zh
 * @brief 确认按钮文字字体和字号。
 */
/**
 * @locale en
 * @brief The font and font size of the confirm button.
 */
@property (nonatomic, strong) UIFont *confirmFont;
/**
 * @locale zh
 * @brief 确认按钮背景颜色。
 */
/**
 * @locale en
 * @brief The background color of the confirm button.
 */
@property (nonatomic, strong) UIColor *confirmBackgroundColor;
/**
 * @locale zh
 * @brief 输入框占位文字字体和字号。
 */
/**
 * @locale en
 * @brief The font and font size for the placeholder text of the text box.
 */
@property (nonatomic, strong) UIFont *placeholderFont;

@end

#pragma clang diagnostic pop
