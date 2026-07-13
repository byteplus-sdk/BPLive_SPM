//
//  BDLBaseDefines.h
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

#ifndef BDLBaseDefines_h
#define BDLBaseDefines_h

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

FOUNDATION_EXPORT NSString *const BDLErrorDomain;
FOUNDATION_EXPORT NSString *const BDLServerErrorDomain;

/**
 * @locale zh
 * @type keytype
 * @brief 语言类型。
 */
/**
 * @locale en
 * @type keytype
 * @brief The language type.
 */
typedef NS_ENUM(NSInteger, BDLLanguageType) {
    /**
     * @locale zh
     * @brief 未知。
     */
    /**
     * @locale en
     * @brief Unknown.
     */
    BDLLanguageTypeUnknown = -1,
    /**
     * @locale zh
     * @hidden
     * @brief 语言类型的最小值。
     */
    /**
     * @locale en
     * @hidden
     * @brief The minimum value of the language type.
     */
    BDLLanguageTypeMin = 0,
    /**
     * @locale zh
     * @brief 简体中文。
     */
    /**
     * @locale en
     * @brief Simplified Chinese.
     */
    BDLLanguageTypeChinese = 0,
    /**
     * @locale zh
     * @brief 英文。
     */
    /**
     * @locale en
     * @brief English.
     */
    BDLLanguageTypeEnglish = 1,
    /**
     * @locale zh
     * @brief 日文。
     */
    /**
     * @locale en
     * @brief Japanese.
     */
    BDLLanguageTypeJapanese = 2,
    /**
     * @locale zh
     * @brief 繁体中文。
     */
    /**
     * @locale en
     * @brief Traditional Chinese.
     */
    BDLLanguageTypeTraditional = 3,
    /**
     * @locale zh
     * @brief 韩语。
     */
    /**
     * @locale en
     * @brief Korean.
     */
    BDLLanguageTypeKorean = 4,
    /**
     * @locale zh
     * @hidden
     * @brief 泰语。
     */
    /**
     * @locale en
     * @brief Thai.
     */
    BDLLanguageTypeThai = 5,
    /**
     * @locale zh
     * @hidden
     * @brief 越南语。
     */
    /**
     * @locale en
     * @brief Vietnamese.
     */
    BDLLanguageTypeVietnamese = 6,
    /**
     * @locale zh
     * @hidden
     * @brief 阿拉伯语。
     */
    /**
     * @locale en
     * @brief Arabic.
     */
    BDLLanguageTypeArabic = 7,
    /**
     * @locale zh
     * @hidden
     * @brief 土耳其语。
     */
    /**
     * @locale en
     * @brief Turkish.
     */
    BDLLanguageTypeTurkish = 8,
    /**
     * @locale zh
     * @hidden
     * @brief 西班牙语。
     */
    /**
     * @locale en
     * @brief Spanish.
     */
    BDLLanguageTypeSpanish = 9,
    /**
     * @locale zh
     * @hidden
     * @brief 印尼语。
     */
    /**
     * @locale en
     * @brief Indonesian.
     */
    BDLLanguageTypeIndonesian = 10,
    /**
     * @locale zh
     * @hidden
     * @brief 葡萄牙语。
     */
    /**
     * @locale en
     * @brief Portuguese.
     */
    BDLLanguageTypePortuguese = 11,
    /**
     * @locale zh
     * @hidden
     * @brief 俄语。
     */
    /**
     * @locale en
     * @brief Russian.
     */
    BDLLanguageTypeRussian = 12,
    /**
     * @locale zh
     * @hidden
     * @brief 他家禄语。
     */
    /**
     * @locale en
     * @brief Tagalog.
     */
    BDLLanguageTypeTagalog = 13,
    /**
     * @locale zh
     * @hidden
     * @brief 高棉语。
     */
    /**
     * @locale en
     * @brief Khmer.
     */
    BDLLanguageTypeKhmer = 14,
    /**
     * @locale zh
     * @hidden
     * @brief 老挝语。
     */
    /**
     * @locale en
     * @brief Lao.
     */
    BDLLanguageTypeLao = 15,
    /**
     * @locale zh
     * @hidden
     * @brief 缅甸语。
     */
    /**
     * @locale en
     * @brief Burmese.
     */
    BDLLanguageTypeBurmese = 16,
    /**
     * @locale zh
     * @hidden
     * @brief 马来语。
     */
    /**
     * @locale en
     * @brief Malay.
     */
    BDLLanguageTypeMalay = 17,
    /**
     * @locale zh
     * @hidden
     * @brief 印地语。
     */
    /**
     * @locale en
     * @brief Hindi.
     */
    BDLLanguageTypeHindi = 18,
    /**
     * @locale zh
     * @hidden
     * @brief 法语。
     */
    /**
     * @locale en
     * @brief French.
     */
    BDLLanguageTypeFrench = 19,
    /**
     * @locale zh
     * @hidden
     * @brief 德语。
     */
    /**
     * @locale en
     * @brief German.
     */
    BDLLanguageTypeGerman = 20,
    /**
     * @locale zh
     * @hidden
     * @brief 意大利语。
     */
    /**
     * @locale en
     * @brief Italian.
     */
    BDLLanguageTypeItalian = 21,
#if BDL_CN
    /**
     * @locale zh
     * @hidden
     * @brief 语言类型的最大值。
     */
    /**
     * @locale en
     * @hidden
     * @brief The maximum value of the language type.
     */
    BDLLanguageTypeMax = BDLLanguageTypeKorean,
#else
    /**
     * @locale zh
     * @hidden
     * @brief 语言类型的最大值。
     */
    /**
     * @locale en
     * @hidden
     * @brief The maximum value of the language type.
     */
    BDLLanguageTypeMax = BDLLanguageTypeItalian,
#endif
};

/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
typedef NS_ENUM(NSUInteger, BDLChannelType) {
    BDLChannelTypeClientApp = 1,
    BDLChannelTypeVolc = 2,
    BDLChannelTypeBPL = 3,
    BDLChannelTypeFlutter = 4,
    BDLChannelTypeRN = 5,
};

#endif /* BDLBaseDefines_h */

#pragma clang diagnostic pop
