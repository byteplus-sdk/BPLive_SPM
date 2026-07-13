//
//  BDLLoginProvider.h
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

#import "BDLActivity.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type callback
 * @brief 自定义登录直播间代理。适用于将鉴权模式从公开切换为自定义的场景，详见[自定义登录](https://www.volcengine.com/docs/3019/1215506#%E8%87%AA%E5%AE%9A%E4%B9%89%E7%99%BB%E5%BD%95)。<br>
 *         :::tip
 *        如果 [authMode](1185540#BDLActivity-authmode) 的值为 `BDLActivityAuthModePublic`，即直播间的鉴权模式为公开，且 [setNickname:complete:](1185544#BDLUserInfoConfiguration-setnickname-complete) 方法的 `nickname` 参数值非空，则不会触发该代理的任何方法。<br>
 *         :::
 */
/**
 * @locale en
 * @type callback
 * @brief The live room delegate for custom login. Suitable for scenarios where the authentication mode is changed from public to custom. For more information, see [Custom authentication login](https://docs.byteplus.com/en/docs/byteplus-livesaas/docs-applying-advanced-viewing-restrictions).
 *        :::tip
 *        If the value of [authMode](docs-bdlliveengine#BDLActivity-authmode) is `BDLActivityAuthModePublic`, which means the authentication mode of the live room is public, and the `nickname` parameter value of the [setNickname:complete:](viewer-sdk-for-ios-type-definitions#BDLUserInfoConfiguration-setnickname-complete) method is not `nil`, then none of the delegate methods will be triggered.
 *        :::
 */
@protocol BDLLoginProvider <NSObject>

/**
 * @locale zh
 * @brief 自定义登录直播间，即允许观众通过您的自有账号系统登录直播间。
 * @param completion 自定义登录直播间完成后触发的回调，无返回值，传入 `token` 参数用于验证登录用户的身份。
 * @param activity 由 [joinLiveRoomWithActivity:success:failure:](1185540#BDLLiveEngine-joinliveroomwithactivity-success-failure) 方法传入的直播间信息。
 */
/**
 * @locale en
 * @brief Logs in to the live room in custom mode, allowing viewers to log in to the live room using your own account system.
 * @param activity The live room information, which is passed in through the [joinLiveRoomWithActivity:success:failure:](docs-bdlliveengine#BDLLiveEngine-joinliveroomwithactivity-success-failure) method.
 * @param completion The callback triggered after the custom login to the live room is complete, with no return value. Pass the `token` parameter for login user identity verification.
 */
- (void)loginWithActivity:(BDLActivity *)activity completion:(void (^)(NSString * _Nullable token))completion;

/**
 * @locale zh
 * @brief 自定义登录结果的回调。
 * @param error 错误信息。有值则自定义登录失败。
 * @param activity 由 [joinLiveRoomWithActivity:success:failure:](1185540#BDLLiveEngine-joinliveroomwithactivity-success-failure) 方法传入的直播间信息。
 */
/**
 * @locale en
 * @brief The callback for custom login results.
 * @param activity The live room information, which is passed in through the [joinLiveRoomWithActivity:success:failure:](docs-bdlliveengine#BDLLiveEngine-joinliveroomwithactivity-success-failure) method.
 * @param error The error information. If this parameter has a value, it means that the custom login failed.
 */
- (void)loginComplete:(BDLActivity *)activity error:(NSError *)error;

@optional
/**
 * @locale zh
 * @brief 取消自定义登录直播间。
 * @param activity 由 [joinLiveRoomWithActivity:success:failure:](1185540#BDLLiveEngine-joinliveroomwithactivity-success-failure) 方法传入的直播间信息。
 */
/**
 * @locale en
 * @brief Cancels the custom login to the live room.
 * @param activity The live room information, which is passed in through the [joinLiveRoomWithActivity:success:failure:](docs-bdlliveengine#BDLLiveEngine-joinliveroomwithactivity-success-failure) method.
 */
- (void)cancelLoginWithActivity:(BDLActivity *)activity;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
