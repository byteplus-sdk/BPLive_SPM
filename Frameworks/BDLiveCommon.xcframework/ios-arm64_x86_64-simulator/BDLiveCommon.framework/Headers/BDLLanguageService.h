//
//  BDLLanguageService.h
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
#import "BDLDefines.h"

NS_ASSUME_NONNULL_BEGIN

@protocol BDLLanguageService <NSObject>

@optional
/// 多语言状态改变
/// @param isLanguageEnabled 是否开启页面语言
/// @param langTypes 所选的页面语言数组, 含义见 BDLLanguageType
/// @param isMultiLanguageEnabled 是否支持多语言
- (void)languageDidChangeEnable:(BOOL)isLanguageEnabled
                      langTypes:(NSArray<NSNumber *> *)langTypes
            multiLanguageEnable:(BOOL)isMultiLanguageEnabled;

/**
 * @param langType 当前语言
 */

/// 当前选中的语言类型改变了
/// @param langType 改变后的语言
- (void)languageTypeDidChange:(BDLLanguageType)langType;

@end

NS_ASSUME_NONNULL_END
