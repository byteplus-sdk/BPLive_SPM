//
//  BDLPeopleCountConfiguration.h
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


#import "BDLRTBaseConfiguration.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @brief 人气配置。
 */
/**
 * @locale en
 * @brief The popularity configuration.
 */
@interface BDLPeopleCountConfiguration : BDLRTBaseConfiguration

@end

/**
 * @locale zh
 * @brief 人气配置。
 */
/**
 * @locale en
 * @brief The popularity configuration.
 */
@interface BDLPeopleCountConfiguration (Config)

/**
 * @locale zh
 * @brief 人气标签文字的字体和字号。字号单位为 point。
 */
/**
 * @locale en
 * @brief The font and font size of the popularity tag text (font size unit: points).
 */
@property (nonatomic, strong) UIFont *textFont;

/**
 * @locale zh
 * @brief 人气标签文字的颜色。
 */
/**
 * @locale en
 * @brief The color of the popularity tag text.
 */
@property (nonatomic, strong) UIColor *textColor;

/**
 * @locale zh
 * @brief 人气图标。
 */
/**
 * @locale en
 * @brief The popularity icon.
 */
@property (nonatomic, strong) UIImage *iconImage;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
