//
//  BDLError.h
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
 * @locale zh
 * @type errorcode
 * @brief 开播端的错误码。
 * @hidden (iOS)
 */
/**
 * @locale en
 * @type errorcode
 * @hidden (iOS)
 * @brief Error codes for the streaming end.
 */
typedef NS_ENUM(NSInteger, BDLErrorCode) {
/**
 * @locale zh
 * @brief 网络返回的 `response` 的类型错误。
 */
   /**
    * @locale en
    * @brief The type error of the network returned `response`.
    */
    BDLErrorCodeResponseTypeError,
/**
 * @locale zh
 * @brief `response.meta.error` 不为空。
 */
   /**
    * @locale en
    */
    BDLErrorCodeResponseError,
/**
 * @locale zh
 * @brief 网络返回的 `statusCode` 不为 `200`。
 */
   /**
    * @locale en
    * @brief The `statusCode` returned by the network is not `200`.
    */
    BDLErrorCodeStatusCodeError,
/**
 * @locale zh
 * @brief JSON 解析失败。
 */
   /**
    * @locale en
    * @brief JSON parsing failed.
    */
    BDLErrorCodeJsonParseError,
};

/**
 * @locale zh
 * @type errorcode
 * @brief 观播端的错误码。
 */
/**
 * @locale en
 * @type errorcode
 * @brief The error codes.
 */
typedef NS_ENUM(NSUInteger, BDLError) {
/**
 * @locale zh
 * @brief 未知错误。
 */
   /**
    * @locale en
    * @brief Unknown error.
    */
    BDLErrorUnknown = 0,
/**
 * @locale zh
 * @brief 获取直播间数据失败。
 */
   /**
    * @locale en
    * @brief Failed to get the live room data.
    */
    BDLErrorGetActivityFailed,
/**
 * @locale zh
 * @brief 不允许通过 SDK 拉流。
 */
   /**
    * @locale en
    * @brief Pulling streams by using the SDK is not allowed.
    */
    BDLErrorPullDisallowed,
/**
 * @locale zh
 * @brief 调用 `changeToken` 接口失败。
 */
   /**
    * @locale en
    * @brief Failed to call the `changeToken` API.
    */
    BDLErrorChangeTokenFailed,
/**
 * @locale zh
 * @brief 根据 vid 获取播放地址失败。
 */
   /**
    * @locale en
    * @brief Failed to get the playback URL based on the video ID.
    */
    BDLErrorVodUrlFailed,
    /**
     * @locale zh
     * @brief [loginWithActivity:completion:](1185541#BDLLoginProvider-loginwithactivity-completion) 的 `completion` 回调传入的 `token` 参数为以下任一情况：<br>
     *        - `nil`
     *        - 非 `NSString` 类型
     *        - 长度为 0
     */
   /**
    * @locale en
    * @brief The `token` parameter passed in through the `completion` callback of [loginWithActivity:completion:](viewer-SDK-for-ios-callbacks#BDLLoginProvider-loginwithactivity-completion) is in any of the following conditions:
    *        - `nil`
    *        - Not of `NSString` type
    *        - Length is 0
    */
    BDLErrorCustomLoginTokenInvalid,
/**
 * @locale zh
 * @brief ImageX 的 token 无效。
 */
   /**
    * @locale en
    * @brief The ImageX token is invalid.
    * @hidden (iOS)
    */
    BDLErrorImageXTokenInvalid,
/**
 * @locale zh
 * @brief 获取 RTC token 失败。
 */
   /**
    * @locale en
    * @brief Failed to get the RTC token.
    */
    BDLErrorGetRTCTokenFailed,
/**
 * @locale zh
 * @brief 进入 RTC 房间失败。
 */
   /**
    * @locale en
    * @brief Failed to join the RTC room.
    */
    BDLErrorJoinRTCRoomFailed,
/**
 * @locale zh
 * @brief 当前功能版本不支持，请联系企业直播技术支持。
 */
   /**
    * @locale en
    * @brief Not supported by the current feature version. Contact BytePlus Live technical support.
    */
    BDLErrorProductVersionDisallowed,
    /**
     * @locale zh
     * @brief 评论发送过于频繁。
     */
   /**
    * @locale en
    * @brief Comments are sent too frequently.
    */
    BDLErrorFrequencyLimitError,
    /**
     * @locale zh
     * @brief 调用 [setNickname:complete:](1185544#BDLUserInfoConfiguration-setnickname-complete) 方法设置用户昵称失败。请在观众进入直播间前调用该方法。
     */
   /**
    * @locale en
    * @brief Failed to set the user nickname by calling the [setNickname:complete:](viewer-sdk-for-ios-type-definitions#BDLUserInfoConfiguration-setnickname-complete) method. You must call this method before viewers join the live room.
    */
    BDLErrorCodeUserHasJoinLiveRoom,
    /**
     * @locale zh
     * @brief 当前观众已被封禁，因此无法进入直播间。如需让该观众进入直播间，可联系主持人解禁该观众。
     */
   /**
    * @locale en
    * @brief The current viewer has been blocked and cannot join the live room. To allow the viewer to join, contact the host to unblock them.
    */
    BDLErrorCodeForceOffline,
};

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
