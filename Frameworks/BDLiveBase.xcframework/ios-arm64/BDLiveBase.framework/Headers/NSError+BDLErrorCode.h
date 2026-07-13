//
//  NSError+BDLErrorCode.h
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

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type keytype
 * @brief 企业直播对 NSError 的分类。
 * @hidden (iOS)
 */
/**
 * @locale en
 * @type keytype
 * @hidden (iOS)
 */
@interface NSError (BDLErrorCode)

/**
 * @locale zh
 * @brief 后端返回的字符串类型的 errorCode.
 */
@property (nonatomic, copy) NSString *bdl_errorCodeStr;


/**
 * @locale zh
 * @brief 拼接了 NSError 的原始 description 和后端返回的字符串类型的 errorCode.
 */
- (NSString *)bdl_description;

/**
 * @locale zh
 * @brief 是否为“错误的直播间模板ID”错误。暂时只有开播使用。
 */
/**
 * @locale en
 */
- (BOOL)bdl_isInvalidTemplateId;

@end

NS_ASSUME_NONNULL_END
