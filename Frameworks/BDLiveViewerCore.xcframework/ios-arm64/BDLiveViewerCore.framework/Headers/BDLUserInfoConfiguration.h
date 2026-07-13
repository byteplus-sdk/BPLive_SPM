//
//  BDLUserInfoConfiguration.h
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

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale en
 * @type keytype
 * @brief The user information configuration.
 */
/**
 * @locale zh
 * @type keytype
 * @brief 用户信息配置。
 */
@interface BDLUserInfoConfiguration : NSObject

/**
 * @locale zh
 * @brief 设置直播间鉴权模式（[authMode](1185540#BDLActivity-authmode)）为公开（`BDLActivityAuthModePublic`）时的用户昵称。
 *        您必须在观众进入直播间前调用该方法。在观众成功进入直播间时，SDK 会使用 `nickname` 的取值完成昵称注册。
 * @param nickname 昵称。为空则不做任何处理。
 * @param complete 昵称注册完成回调。
 *        传入参数：
 *        - `success`：昵称注册是否成功。
 *          - `YES`：成功。
 *          - `NO`：失败。在下次触发昵称注册时，例如观众点击评论输入框时，SDK 会使用 `nickname` 的取值完成昵称注册，同时触发该回调。如果依然失败，则会在下次触发昵称注册时继续，直至成功。
 *        - `error`： 错误信息。
 */
/**
 * @locale en
 * @param nickname The nickname. No action is taken if `nil`.
 * @param complete The callback triggered when the nickname registration is completed.
 *        Input parameters:
 *        - `success`: Whether the nickname registration is successful.
 *          - `YES`: Successful.
 *          - `NO`: Failed. Upon the next nickname registration attempt, for example, when viewers tap the comment text box, SDK uses the value of `nickname` to complete the nickname registration, and this callback is triggered. If the nickname registration still fails, the process continues on the next nickname registration attempt until it succeeds.
 *        - `error`: The error information.
 * @brief Sets the user nickname when the authentication mode ([authMode](docs-bdlliveengine#BDLActivity-authmode)) of the live room is set to public (`BDLActivityAuthModePublic`).
 *        You must call this method before viewers join the live room. When viewers join the live room successfully, SDK uses the value of `nickname` to complete the nickname registration.
 */
- (void)setNickname:(NSString *)nickname complete:(void (^)(BOOL success,  NSError * _Nullable error))complete;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
