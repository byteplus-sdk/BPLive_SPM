//
//  BDLiveManager.h
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
#import "BDLiveAuthInfo.h"
#import "BDLBaseDefines.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type keytype
 * @brief SDK 初始化完成回调。
 * @param allSuccess 传入的 License 是否均授权成功。取值如下：
 *        - `YES`：全部授权成功。
 *        - `NO`：未全部授权成功。
 * @param warningInfo 警告信息，用于提示 License 信息与业务类型（[bizType](#BDLiveAuthInfo-biztype)）不匹配、缺失必要的 License 等问题。
 * @param errors 错误信息。`error.domain` 为 `BDLSDKAuthErrorDomain`，`error.code` 为 [BDLSDKAuthErrorCode](#BDLSDKAuthErrorCode)。
 */
/**
 * @locale en
 * @type keytype
 * @brief The callback is triggered when the SDK initialization is complete.
 * @param allSuccess Whether the licenses passed in are all successfully authorized. Valid values:
 *        - `YES`: All licenses are successfully authorized.
 *        - `NO`: Not all licenses are successfully authorized.
 * @param warningInfo Warning message used to indicate issues such as license information mismatched with business type ([bizType](#BDLiveAuthInfo-biztype)), or missing necessary licenses.
 * @param errors Error message. `error.domain` is `BDLSDKAuthErrorDomain`, and `error.code` is [BDLSDKAuthErrorCode](#BDLSDKAuthErrorCode).
 */
typedef void(^BDLiveManagerCompleteBlock)(BOOL allSuccess, NSString * _Nullable warningInfo, NSArray<NSError *>  * _Nullable errors);

FOUNDATION_EXPORT NSErrorDomain const BDLSDKAuthErrorDomain;

/**
 * @locale zh
 * @type keytype
 * @brief SDK 初始化失败错误码。
 */
/**
 * @locale en
 * @type keytype
 * @brief Error codes for SDK initialization failure.
 */
typedef NS_ENUM(NSInteger, BDLSDKAuthErrorCode) {
    /**
     * @locale zh
     * @brief 上次调用的 [startWithAuthInfo:complete:](1185540#BDLiveManager-startwithauthinfo-complete) 方法还未执行完毕。在触发 SDK 初始化完成回调（`complete`）后，才能重新调用 `startWithAuthInfo:complete:` 方法。
     */
   /**
    * @locale en
    * @brief The previously called [startWithAuthInfo:complete:](docs-bdlliveengine#BDLiveManager-startwithauthinfo-complete) method has not yet been completed. The `startWithAuthInfo:complete:` method can only be called again after the SDK initialization completion callback (`complete`) is triggered.
    */
    BDLSDKAuthErrorCodeProcessing = 1,
    /**
     * @locale zh
     * @brief [bizType](#BDLiveAuthInfo-biztype) 不可用，请确保取值并非 `BDLiveBizTypeNone`。
     */
   /**
    * @locale en
    * @brief [bizType](#BDLiveAuthInfo-biztype) is not available. Make sure the value is not `BDLiveBizTypeNone`.
    */
    BDLSDKAuthErrorCodeInvalidBizType,
    /**
     * @locale zh
     * @brief [appId](#BDLiveAuthInfo-appid) 不可用，请确保取值非空。
     */
   /**
    * @locale en
    * @brief [appId](#BDLiveAuthInfo-appid) is not available. Make sure the value is not `nil`.
    */
    BDLSDKAuthErrorCodeInvalidAppId,
    /**
     * @locale zh
     * @brief 点播授权失败。请检查点播 License，例如 License 文件是否过期，或者申请点播 License 时的 Bundle ID 是否与项目配置的 BundleID 一致。
     */
   /**
    * @locale en
    * @brief VOD authorization failed. Check the VOD license, such as whether the license file has expired, or whether the bundle ID used when applying for the VOD license matches the bundle ID configured in the project.
    */
    BDLSDKAuthErrorCodeVodAuthFail,
    /**
     * @locale zh
     * @brief 直播拉流授权失败。请检查直播 License，例如 License 文件是否过期，或者申请直播 License 时的 Bundle ID 是否与项目配置的 BundleID 一致。
     */
   /**
    * @locale en
    * @brief Pull streaming authorization failed. Check the live streaming license, such as whether the license file has expired, or whether the bundle ID used when applying for the live streaming license matches the bundle ID configured in the project.
    */
    BDLSDKAuthErrorCodeLivePullAuthFail,
    /**
     * @locale zh
     * @brief 直播推流授权失败。请检查直播 License，例如 License 文件是否过期，或者申请直播 License 时的 Bundle ID 是否与项目配置的 BundleID 一致。
     */
   /**
    * @locale en
    * @brief Push streaming authorization failed. Check the live streaming license, such as whether the license file has expired, or whether the bundle ID used when applying for the live streaming license matches the bundle ID configured in the project.
    */
    BDLSDKAuthErrorCodeLivePushAuthFail,
    /**
     * @locale zh
     * @brief CV License 授权失败。请检查 CV License 授权信息是否有误，例如申请 CV License 时的 Bundle ID 是否与项目配置的 BundleID 一致。
     */
   /**
    * @locale en
    * @brief CV license authorization failed. Check whether the CV license authorization information is correct, such as whether the bundle ID used when applying for the CV license matches the bundle ID configured in the project.
    */
    BDLSDKAuthErrorCodeEffectAuthFail,
};

/**
 * @locale zh
 * @type api
 * @brief 企业直播 SDK 入口类。
 */
/**
 * @locale en
 * @brief The entry class of BytePlus Live SDK.
 */
@interface BDLiveManager : NSObject
/**
 * @locale zh
 * @type keytype
 * @brief 获取 `BDLiveManager` 实例。
 * @return `BDLiveManager` 实例。
 */
/**
 * @locale en
 * @brief Gets the `BDLiveManager` instance.
 * @return The `BDLiveManager` instance.
 */
+ (instancetype)sharedInstance;
/**
 * @locale zh
 * @brief 初始化 SDK。请在连接网络后调用该方法。
 * @param authInfo 授权信息。详见 [BDLiveAuthInfo](1185544#BDLiveAuthInfo)。
 * @param complete SDK 初始化完成回调。详见 [BDLiveManagerCompleteBlock](1185544#bdlivemanagercompleteblock)。
 */
/**
 * @locale en
 * @brief Initializes the SDK. You must call this method after connecting to the network.
 * @param authInfo Authorization information. For more information, see [BDLiveAuthInfo](viewer-sdk-for-ios-type-definitions#BDLiveAuthInfo).
 * @param complete The callback triggered when the SDK initialization is complete. For more information, see [BDLiveManagerCompleteBlock](viewer-sdk-for-ios-type-definitions#bdlivemanagercompleteblock).
 */
- (void)startWithAuthInfo:(BDLiveAuthInfo *)authInfo
                 complete:(BDLiveManagerCompleteBlock)complete;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
