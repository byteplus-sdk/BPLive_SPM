//
//  BDLMultiLanguageConfiguration.h
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
#import <BDLiveCommon/BDLDefines.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type keytype
 * @brief 多语言自定义配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The custom configuration for multiple languages.
 */
@interface BDLMultiLanguageConfiguration : BDLRTBaseConfiguration

/**
 * @locale zh
 * @brief 观看页面优先展示的语言。支持的语言详见 [BDLLanguageType](#BDLLanguageType)。默认跟随系统语言。
 * 
 * 
 *        :::tip
 *        只有在[企业直播控制台](https://console.volcengine.com/Livesaas/LiveManagement/)中已为直播间启用的语言，才能设置为优先语言。
 *        :::
 */
/**
 * @locale en
 * @brief The preferred language for the watch page. Supported languages are listed in [BDLLanguageType](#BDLLanguageType). The default setting follows the system language. After setting, you need to restart the relevant interface to take effect.
 * 
 *        :::tip
 *        Only the languages enabled for the live room in the [BytePlus Live console](https://console.byteplus.com/livesaas/liveManagement/) can be set as preferred languages.
 *        :::
 */
@property (nonatomic, assign) BDLLanguageType preferLanguage;

/**
 * @locale zh
 * @brief 在显示系统文案时触发该回调，用于自定义系统文案。
 * @param language 当前选中的语言。详见 [BDLLanguageType](#BDLLanguageType)。
 * @param key 系统文案的 key。
 * @param originString 默认的系统文案。
 * @list 多语言
 * @return 自定义的系统文案。
 */
/**
 * @locale en
 * @brief The callback is triggered when the system text is displayed, and is used to customize the system text.
 * @param language The currently selected language. For more information, see [BDLLanguageType](#BDLLanguageType).
 * @param key The key of the system text.
 * @param originString The default system text.
 * @return The custom system text.
 */
@property (nonatomic, copy, nullable) NSString *(^customLanguageString)(BDLLanguageType language, NSString *key, NSString *originString);

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
