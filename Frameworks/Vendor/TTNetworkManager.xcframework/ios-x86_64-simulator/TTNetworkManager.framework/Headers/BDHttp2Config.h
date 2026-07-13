//
//  BDHttp2Config.h
//  TTNetworkManager
//
//  The TTNetworkManager is licensed under the MIT License.
//  Copyright (c) 2023 Bytedance Inc.
//

#ifndef BDHttp2Config_h
#define BDHttp2Config_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @brief 使用此模块时，注入BDNetwork ModuleMap时用的Key
 */
extern NSString * const kBDHttp2ConfigKey;

@interface BDHttp2Config : NSObject

/*!
 @brief ping保活的开关
 */
@property(atomic, assign)BOOL pingKeepAliveEnabled;

/*!
 @brief ping保活的间隔
 */
@property(atomic, assign)int pingKeepAliveInterval;

/*!
 @brief ping保活域名列表，含端口
 */
@property(atomic, copy, nullable)NSArray<NSString*>* pingKeepAliveHosts;

/*!
 @brief ping保活的超时时间
 */
@property(atomic, assign)int pingProbeTimeout;

/*!
 @brief session check的开关
 */
@property(atomic, assign)BOOL sessionCheckEnabled;

/*!
 @brief session check的间隔
 */
@property(atomic, assign)int sessionCheckInterval;

/*!
 @brief session check的域名
 */
@property(atomic, copy, nullable)NSArray<NSString*>* sessionCheckHosts;

/*!
 @brief 预链接url
 */
@property(atomic, copy, nullable)NSDictionary<NSString*, NSNumber*>* preconnectUrls;

@end

NS_ASSUME_NONNULL_END


#endif /* BDHttp2Config_h */
