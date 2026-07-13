//
//  BDQuicConfig.h
//  TTNetworkManager
//
//  The TTNetworkManager is licensed under the MIT License.
//  Copyright (c) 2023 Bytedance Inc.
//

#ifndef BDQuicConfig_h
#define BDQuicConfig_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @brief 使用此模块时，注入BDNetwork ModuleMap时用的Key
 */
extern NSString * const kBDQuicConfigKey;

/*!
 @brief 定义使用QUIC的域名和接口
 */
@interface BDQuicHint : NSObject

@property(atomic, copy) NSString* host;
@property(atomic, assign) int port;
@property(atomic, assign) int alternativePort;

@end


@interface BDQuicConfig : NSObject

/*!
 @brief 是否开启QUIC
 @discussion optional，默认NO
 */
@property (atomic, assign) BOOL enable;
/*!
 @brief 使用QUIC的域名列表
 @discussion optional，默认Array为空
 */
@property (atomic, copy) NSArray<BDQuicHint*>* quicHints;

@end

NS_ASSUME_NONNULL_END

#endif /* BDQuicConfig_h */
