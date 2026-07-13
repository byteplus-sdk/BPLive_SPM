//
//  BDLEnv.h
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

#import "BDLCustomEnvModel.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 环境配置类。
 */
/**
 * @locale en
 * @type api
 * @brief Environment configuration class.
 */
@interface BDLEnv : NSObject

/**
 * @locale zh
 * @type api
 * @brief 设置自定义环境。
 * @param model 自定义环境模型。详见 {BDLCustomEnvModel{@link #BDLCustomEnvModel}}。
 * @return 是否设置成功。
 *        - `YES`：设置成功。
 *        - `NO`：设置失败。
 */
/**
 * @locale en
 * @type api
 * @brief Sets the custom environment.
 * @param model The custom environment model. See {BDLCustomEnvModel{@link #BDLCustomEnvModel}} for details.
 * @return Whether the setting is successful.
 *        - `YES`: Success.
 *        - `NO`: Failure.
 */
+ (BOOL)setCustomEnvModel:(nullable BDLCustomEnvModel *)model;

/**
 * @locale zh
 * @type api
 * @brief 获取当前设置的自定义环境。
 * @return 自定义环境模型。详见 {BDLCustomEnvModel{@link #BDLCustomEnvModel}}。
 */
/**
 * @locale en
 * @type api
 * @brief Gets the currently set custom environment.
 * @return The custom environment model. See {BDLCustomEnvModel{@link #BDLCustomEnvModel}} for details.
 */
+ (nullable BDLCustomEnvModel*)customEnvModel;

/**
 * @locale zh
 * @type api
 * @brief 设置是否忽略 SSL 证书校验。
 * @param ignore 是否忽略 SSL 证书校验。默认值为 `NO`。取值如下：
 *        - `YES`：忽略。
 *        - `NO`：不忽略。
 */
/**
 * @locale en
 * @type api
 * @brief Sets whether to ignore SSL certificate verification.
 * @param ignore Whether to ignore SSL certificate verification. The default value is `NO`. Possible values:
 *        - `YES`: Ignore.
 *        - `NO`: Do not ignore.
 */
+ (void)setIgnoreSSLVerification:(BOOL)ignore;

/**
 * @locale zh
 * @type api
 * @brief 获取是否忽略 SSL 证书校验。
 * @return 是否忽略 SSL 证书校验。
 */
/**
 * @locale en
 * @type api
 * @brief Gets whether to ignore SSL certificate verification.
 * @return Whether to ignore SSL certificate verification.
 */
+ (BOOL)ignoreSSLVerification;

@end

NS_ASSUME_NONNULL_END
