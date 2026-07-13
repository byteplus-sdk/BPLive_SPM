//
//  BDLCustomIMService.h
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
 * @type callback
 * @brief 收到自定义的 IM（长链接消息）信令。<br>IM 信令消息目前适用于发送自定义消息的场景，您可以通过监听自定义消息实现自己的业务逻辑。
 */
/**
 * @locale en
 * @type callback
 * @hidden (iOS)
 * @brief Received custom IM (Instant Messaging) signaling.<br>You can trigger your interface logic via the SDK channel during the live broadcast, such as instant animations, custom lottery implementations, etc.
 */
@protocol BDLCustomIMService <NSObject>

@optional
/**
 * @locale zh
 * @brief 自定义的 IM 信令收到回调。
 * @param string 通过 [SendCustomSystemMessageAPI](https://www.volcengine.com/docs/3019/126052) 接口发送的自定义的 IM 信令。
 */
/**
 * @locale en
 * @brief Custom IM signaling received callback.
 * @param string Custom IM signaling sent through the [SendCustomSystemMessageAPI](https://www.volcengine.com/docs/3019/126052) interface.
 */
- (void)onReceiveIMString:(NSString * _Nullable)string;

/**
 * @locale zh
 * @brief IM 建立连接成功回调。
 */
/**
 * @locale en
 * @brief IM connection established callback.
 */
- (void)onConnected;

/**
 * @locale zh
 * @brief IM 建立连接失败回调。
 */
/**
 * @locale en
 * @brief IM connection establishment failure callback.
 */
- (void)onConnectFailed;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop

