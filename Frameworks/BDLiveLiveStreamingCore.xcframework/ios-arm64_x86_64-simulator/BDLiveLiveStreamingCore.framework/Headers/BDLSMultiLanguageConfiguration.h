//
//  BDLSMultiLanguageConfiguration.h
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

#import <BDLiveBase/BDLBaseDefines.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type keytype
 * @brief 开播多语言自定义配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief Live streaming multi-language custom configuration.
 */
@interface BDLSMultiLanguageConfiguration : NSObject

/**
 * @locale zh
 * @brief 设置直播客户端界面显示的语言类型
 * @note 该属性用于控制开播端所有UI元素的本地化语言显示。设置后需要重启相关界面才能生效。默认跟随系统语言，详见 [BDLLanguageType](#BDLLanguageType)。
 */
/**
 * @locale en
 * @brief Set the language type displayed on the live client interface
 * @note This property is used to control the localization language display of all UI elements on the live client. After setting, you need to restart the relevant interface to take effect. The default follows the system language, see [BDLLanguageType](#BDLLanguageType).
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
@property (nonatomic, copy) NSString *(^customLanguageString)(BDLLanguageType language, NSString *key, NSString *originString);

@end

NS_ASSUME_NONNULL_END
