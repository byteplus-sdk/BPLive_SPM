//
//  BDLExternalReportConfiguration.h
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
 * @type keytype
 * @brief 数据上报配置。
 */
/**
 * @locale en
 * @brief Data reporting configuration.
 * @type keytype
 */
@interface BDLExternalReportConfiguration : BDLRTBaseConfiguration

/**
 * @locale zh
 * @type keytype
 * @brief 是否开启数据上报功能。默认值为 `NO`。取值如下：
 *        - `YES`: 开启。SDK 会在以下时机将数据上报至 [url](#BDLExternalReportConfiguration-url)。
 *            - 观众成功进入直播间时。
 *            - 观众在直播间内，每间隔 [repeatInterval](#BDLExternalReportConfiguration-repeatinterval) 上报一次数据。
 *            - 观众离开直播间时。
 *        - `NO`: 不开启。
 */
/**
 * @locale en
 * @brief Whether to enable the data reporting feature. Default value: `NO`. Valid values:
 *        - `YES`: Enable. The SDK will report data to the [url](#BDLExternalReportConfiguration-url) at the following timing:
 *            - When a viewer joins the live room successfully.
 *            - While a viewer is in the live room, data is reported at intervals specified by [repeatInterval](#BDLExternalReportConfiguration-repeatinterval).
 *            - When a viewer leaves the live room.
 *        - `NO`: Disable.
 */
@property (nonatomic, assign) BOOL enable;
/**
 * @locale zh
 * @brief 通过 [enable](#BDLExternalReportConfiguration-enable) 开启数据上报功能后，SDK 会在指定时机将数据以 `POST` 方式上报至该 URL。
 */
/**
 * @locale en
 * @brief After enabling the data reporting feature through [enable](#BDLExternalReportConfiguration-enable), the SDK will send a `POST` request to this URL at specific timing for data reporting.
 */
@property (nonatomic, copy) NSString *url;
/**
 * @locale zh
 * @brief 数据上报的时间间隔。单位为秒，默认值为 `30`。
 */
/**
 * @locale en
 * @brief The time interval for reporting data. Unit: seconds. Default value: `30`.
 */
@property (nonatomic, assign) CGFloat repeatInterval;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
