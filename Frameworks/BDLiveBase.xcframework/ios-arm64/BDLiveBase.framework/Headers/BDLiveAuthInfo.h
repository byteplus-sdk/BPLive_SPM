//
//  BDLiveAuthInfo.h
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

#import "BDLBaseModel.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN


/**
 * @locale zh
 * @type keytype
 * @brief 企业直播 SDK 的业务类型。
 */
/**
 * @locale en
 * @type keytype
 * @brief The business type for BytePlus Live SDK.
 */
typedef NS_OPTIONS(NSUInteger, BDLiveBizType) {
    /**
     * @locale zh
     * @brief 空，默认值。
     */
    /**
     * @locale en
     * @brief None, which is the default value.
     */
    BDLiveBizTypeNone = 0,
    /**
     * @locale zh
     * @brief 点播播放器。
     * @hidden (iOS)
     */
    /**
     * @locale en
     * @hidden (iOS)
     */
    BDLiveBizTypeVodPlayer = 1 << 0,
    /**
     * @locale zh
     * @brief 观播 SDK。
     */
    /**
     * @locale en
     * @brief Viewer SDK.
     */
    BDLiveBizTypeViewer = 1 << 1,
    /**
     * @locale zh
     * @brief 开播 SDK。
     */
    /**
     * @locale en
     * @brief Live Streaming SDK.
     */
    BDLiveBizTypeLiveStreaming = 1 << 2,
    /**
     * @locale zh
     * @brief 除 `BDLiveBizTypeNone` 外的所有业务类型。
     */
    /**
     * @locale en
     * @brief All business types except for `BDLiveBizTypeNone`.
     */
    BDLiveBizTypeAll = NSUIntegerMax,
};

/**
 * @locale zh
 * @type keytype
 * @brief CV License 授权方式。
 */
/**
 * @locale en
 * @type keytype
 * @brief The authorization method of the CV license.
 */
typedef NS_ENUM(NSInteger, BDLiveEffectAuthType) {
    /**
     * @locale zh
     * @brief 无授权，即不使用美颜、滤镜和道具贴纸功能。默认值。
     */
    /**
     * @locale en
     * @brief No authorization, meaning the beauty AR, filters, and stickers features are not used. This is the default value.
     */
    BDLiveEffectAuthTypeNone,
    /**
     * @locale zh
     * @brief 在线授权。您必须同时设置 [key](#BDLiveEffectAuthInfo-key) 和 [secret](#BDLiveEffectAuthInfo-secret)。
     */
    /**
     * @locale en
     * @brief Online authorization. You must set both [key](#BDLiveEffectAuthInfo-key) and [secret](#BDLiveEffectAuthInfo-secret).
     */
    BDLiveEffectAuthTypeOnLine,
    /**
     * @locale zh
     * @brief 离线授权。您必须设置 [licenseFilePath](#BDLiveEffectAuthInfo-licensefilepath)。
     */
    /**
     * @locale en
     * @brief Offline authorization. You must set the [licenseFilePath](#BDLiveEffectAuthInfo-licensefilepath).
     */
    BDLiveEffectAuthTypeOffLine,
};

/**
 * @locale zh
 * @type keytype
 * @brief CV License 授权信息。
 */
/**
 * @locale en
 * @type keytype
 * @brief The authorization information of the CV license.
 */
@interface BDLiveEffectAuthInfo : BDLBaseModel

/**
 * @locale zh
 * @brief 授权方式。详见 [BDLiveEffectAuthType](#BDLiveEffectAuthType)。
 */
/**
 * @locale en
 * @brief Authorization method. For more information, see [BDLiveEffectAuthType](#BDLiveEffectAuthType).
 */
@property (nonatomic, assign) BDLiveEffectAuthType authType;
/**
 * @locale zh
 * @brief 离线授权时，License 文件的路径。联系技术支持获取 CV License。
 *        :::tip
 *        该属性仅在 [authType](#BDLiveEffectAuthInfo-authtype) 取值为 `BDLiveEffectAuthTypeOffLine` 时生效。
 *        :::
 */
/**
 * @locale en
 * @brief The path of the license file for offline authorization. Contact BytePlus Live technical support to get the CV license.
 *        :::tip
 *        This property takes effect only when the value of [authType](#BDLiveEffectAuthInfo-authtype) is `BDLiveEffectAuthTypeOffLine`.
 *        :::
 */
@property (nonatomic, copy) NSString *licenseFilePath;
/**
 * @locale zh
 * @brief 在线授权时的业务标识。请联系技术支持获取。
 *        :::tip
 *        该属性仅在 [authType](#BDLiveEffectAuthInfo-authtype) 取值为 `BDLiveEffectAuthTypeOnLine` 时生效。
 *        :::
 */
/**
 * @locale en
 * @brief The business identifier for online authorization. Contact BytePlus Live technical support to get the business identifier.
 *        :::tip
 *        This property takes effect only when the value of [authType](#BDLiveEffectAuthInfo-authtype) is `BDLiveEffectAuthTypeOnLine`.
 *        :::
 */
@property (nonatomic, copy) NSString *key;
/**
 * @locale zh
 * @brief 在线授权时的业务密钥。业务密钥可在创建业务时同业务标识一起获得。请联系技术支持获取。
 *        :::tip
 *        该属性仅在 [authType](#BDLiveEffectAuthInfo-authtype) 取值为 `BDLiveEffectAuthTypeOnLine` 时生效。
 *        :::
 */
/**
 * @locale en
 * @brief The business secret key for online authorization, which can be obtained together with the business identifier when you create the business. Contact BytePlus Live technical support to get the business secret key.
 *        :::tip
 *        This property takes effect only when the value of [authType](#BDLiveEffectAuthInfo-authtype) is `BDLiveEffectAuthTypeOnLine`.
 *        :::
 */
@property (nonatomic, copy) NSString *secret;

@end


/**
 * @locale zh
 * @type keytype
 * @brief 企业直播 SDK 授权信息 Model。
 */
/**
 * @locale en
 * @type keytype
 * @brief The authorization information model for BytePlus Live SDK.
 */
@interface BDLiveAuthInfo : BDLBaseModel

/**
 * @locale zh
 * @brief 业务类型。详见 [BDLiveBizType](#BDLiveBizType)。
 */
/**
 * @locale en
 * @brief The business type. For more information, see [BDLiveBizType](#BDLiveBizType).
 */
@property (nonatomic, assign) BDLiveBizType bizType;

/**
 * @locale zh
 * @brief SDK 应用创建后生成的 App ID。有关如何获取 App ID，详见[获取 License](https://www.volcengine.com/docs/3019/1139518)。
 */
/**
 * @locale en
 * @brief The app ID returned after the successful license application. Contact BytePlus Live technical support to get the app ID.
 */
@property (nonatomic, copy) NSString *appId;
/**
 * @locale zh
 * @brief 创建 SDK 应用时填写的 App 名称。默认为`应用名字`。有关如何获取 App 名称，详见[获取 License](https://www.volcengine.com/docs/3019/1139518)。
 */
/**
 * @locale en
 * @brief The app name used to apply for the license. By default, the bundle display name is used. Contact BytePlus Live technical support to get the app name.
 */
@property (nonatomic, copy, nullable) NSString *appName;
/**
 * @locale zh
 * @brief App 的渠道名称。默认为 `App Store`。
 */
/**
 * @locale en
 * @brief The name of the channel through which to download the app. Default value: `App Store`.
 */
@property (nonatomic, copy, nullable) NSString *channel;
/**
 * @locale zh
 * @brief 点播 License 文件路径。有关如何获取点播 License 文件，详见[获取 License](https://www.volcengine.com/docs/3019/1139518)。
 *        :::tip
 *        - 该属性仅在业务类型（[bizType](#BDLiveAuthInfo-biztype)）包含观播 SDK（`BDLiveBizTypeViewer`）时生效。
 *        - 如果点播 License 文件和直播 License 文件是同一文件，`vodLicensePath` 的取值和 [liveLicensePath](#BDLiveAuthInfo-livelicensepath) 的取值一致即可。
 *        :::
 */
/**
 * @locale en
 * @brief The path of the VOD license file. Contact BytePlus Live technical support to get the VOD license.
 *        :::tip
 *        - This property takes effect only when the business type ([bizType](#BDLiveAuthInfo-biztype)) includes Viewer SDK (`BDLiveBizTypeViewer`).
 *        - If the VOD license file and the live streaming license file are the same file, set the value of `vodLicensePath` to be the same as [liveLicensePath](#BDLiveAuthInfo-livelicensepath).
 *        :::
 */
@property (nonatomic, copy, nullable) NSString *vodLicensePath;
/**
 * @locale zh
 * @brief 直播 License 文件路径。有关如何获取直播 License 文件，详见[获取 License](https://www.volcengine.com/docs/3019/1139518)。
 *        :::tip
 *        如果直播 License 文件和点播 License 文件是同一文件，`liveLicensePath` 的取值和 [vodLicensePath](#BDLiveAuthInfo-vodlicensepath) 的取值一致即可。
 *        :::
 */
/**
 * @locale en
 * @brief The path of the live streaming license file. Contact BytePlus Live technical support to get the live streaming license.
 *        :::tip
 *        If the live streaming license file and the VOD license file are the same file, set the value of `liveLicensePath` to be the same as [vodLicensePath](#BDLiveAuthInfo-vodlicensepath).
 *        :::
 */
@property (nonatomic, copy, nullable) NSString *liveLicensePath;

/**
 * @locale zh
 * @brief CV License 授权信息。适用于需要使用美颜、滤镜和道具贴纸功能的场景。详见 [BDLiveEffectAuthInfo](#BDLiveEffectAuthInfo)。
 *        :::tip
 *        该属性仅在业务类型（[bizType](#BDLiveAuthInfo-biztype)）包含开播 SDK（`BDLiveBizTypeLiveStreaming`）时生效。
 *        :::
 */
/**
 * @locale en
 * @brief The CV license authorization information. Applicable to scenarios requiring beauty AR, filters, and stickers features. For more information, see [BDLiveEffectAuthInfo](#BDLiveEffectAuthInfo).
 *        :::tip
 *        This property takes effect only when the business type ([bizType](#BDLiveAuthInfo-biztype)) includes Live Streaming SDK (`BDLiveBizTypeLiveStreaming`).
 *        :::
 */
@property (nonatomic, strong) BDLiveEffectAuthInfo *effectAuthInfo;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
