//
//  BDLLiveStreamingBaseController.h
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

#import "BDLLiveStreamingController.h"

NS_ASSUME_NONNULL_BEGIN

///  直播推流的baseVC
@interface BDLLiveStreamingBaseController : BDLLiveStreamingController

// MARK: - Inner

@property (nonatomic, strong) NSPointerArray *delegateArray;

/// 向delegate发送消息,第一参数默认带上self
- (void)sendMsgToDelegate:(SEL)sel;

/// 向delegate发送消息,第一个参数为self
/// @param value 第二个参数, BOOL 类型
- (void)sendMsgToDelegate:(SEL)sel withBoolValue:(BOOL)value;

/// 向delegate发送消息,第一个参数为self
/// @param value 第二个参数, NSInteger 类型
- (void)sendMsgToDelegate:(SEL)sel withIntegerlValue:(NSInteger)value;

/// 向delegate发送消息,第一个参数为self
/// @param value 第二个参数, OC 对象
- (void)sendMsgToDelegate:(SEL)sel withObject:(nullable id)value;

@end

NS_ASSUME_NONNULL_END
