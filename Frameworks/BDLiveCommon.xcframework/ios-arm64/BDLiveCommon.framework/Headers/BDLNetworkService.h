//
//  BDLNetworkService.h
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
 * @type keytype
 * @brief 网络状态。
 */
/**
 * @locale en
 * @type keytype
 * @brief The network status.
 */
typedef NS_ENUM(NSInteger, BDLNetworkStatus) {
    /**
     * @locale zh
     * @brief 未知。
     */
   /**
    * @locale en
    * @brief Unknown.
    */
    BDLNetworkStatusUnknown,
    /**
     * @locale zh
     * @brief 网络不可达，即没有网络。
     */
   /**
    * @locale en
    * @brief Network unreachable, namely no network.
    */
    BDLNetworkStatusNotReachable,
    /**
     * @locale zh
     * @brief 无线广域网（WWAN）。
     */
   /**
    * @locale en
    * @brief Wireless Wide Area Network (WWAN).
    */
    BDLNetworkStatusReachableViaWWAN,
    /**
     * @locale zh
     * @brief WiFi。
     */
   /**
    * @locale en
    * @brief WiFi.
    */
    BDLNetworkStatusReachableViaWiFi,
};

FOUNDATION_EXPORT NSString * const BDLNetworkDidChangeNotification;
FOUNDATION_EXPORT NSString * const BDLNetworkNotificationStatusKey;

/**
 * @locale zh
 * @type keytype
 * @brief 网络相关 service。
 */
/**
 * @locale en
 * @type keytype
 * @brief The network-related service.
 */
@protocol BDLNetworkService <NSObject>

/**
 * @locale zh
 * @brief 获取当前网络状态。
 * @return 当前网络状态。详见 [BDLNetworkStatus](#BDLNetworkStatus)。
 */
/**
 * @locale en
 * @brief Gets the current network status.
 * @return The current network status. For more information, see [BDLNetworkStatus](#BDLNetworkStatus).
 */
- (BDLNetworkStatus)networkStatus;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop

