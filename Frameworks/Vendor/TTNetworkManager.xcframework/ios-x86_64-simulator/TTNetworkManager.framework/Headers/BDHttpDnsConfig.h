//
//  BDHttpDnsConfig.h
//  TTNetworkManager
//
//  The TTNetworkManager is licensed under the MIT License.
//  Copyright (c) 2023 Bytedance Inc.
//

#ifndef BDHttpDnsConfig_h
#define BDHttpDnsConfig_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @brief 使用此模块时，注入BDNetwork ModuleMap时用的Key
 */
extern NSString * const kBDHttpDnsConfigKey;

@interface BDHttpDnsConfig : NSObject

/*!
 @brief httpdns 开关
 */
@property(atomic, assign)BOOL enable;

/*!
 @brief httpdns 账户
 */
@property(atomic, copy, nullable)NSString* authId;

/*!
 @brief httpdns 密钥
 */
@property(atomic, copy, nullable)NSString* authKey;

/*!
 @brief httpdns 请求域名，一般不需要修改
 */
@property(atomic, copy, nullable)NSString* domain;

/*!
 @brief httpdns 优先开关，默认为 true
 */
@property(atomic, assign)BOOL httpdnsPrefer;

/*!
 @brief  httpdns 超时时间，默认 5s
 */
@property(atomic, assign)int httpdnsTimeout;

/*!
 @brief localdns 超时时间，默认 60s
 */
@property(atomic, assign)int localdnsTimeout;

/*!
 @brief localdns 优先时，优先走 httpdns 的域名正则表示
 */
@property(atomic, copy, nullable)NSArray<NSString*>* httpdnsWhiteListRegex;

/*!
 @brief localdns 优先时，优先走 httpdns 的域名列表
 */
@property(atomic, copy, nullable)NSArray<NSString*>* httpdnsWhiteListDomain;

/*!
 @brief 异步 dns 解析开关，默认开。当 dns 过期域名达到 3 个或首个过期的 dns 域名超过 180s，主动刷新一次dns。详细介绍：/docs/doccnvU9Y8SW6kh2DjhNEffoI0g
 */
@property(atomic, assign)BOOL enableAsyncHttpdns;

/*!
 @brief dns 过期缓存竞速，默认开。在特定时间内可以直接使用过期缓存，同时发起 dns 解析进行竞速。详细介绍：/docx/doxcnpWDDeElCXD8yssPLkQFiXf
 */
@property(atomic, assign)BOOL enableRaceDnsStaleCache;

/*!
 @brief dns 缓存持久化，开关，默认关。详细介绍：/docx/doxcnvwKpkoyWr5orVoK30M7yJh
 */
@property(atomic, assign)BOOL enablePersistentHostCache;

/*!
 @brief dns 缓存持久化，域名个数上限
 */
@property(atomic, assign)int persistentHostCacheCountLimit;

/*!
 @brief dns 缓存持久化，域名列表
 */
@property(atomic, copy, nullable)NSArray<NSString*>* persistentHostCacheWildCharHosts;

/*!
 @brief dns 预解析域名列表
 */
@property(atomic, copy, nullable)NSArray<NSString*>* preloadBatchHosts;

/*!
 @brief httpdns 优先时，优先 localdns，失败后 fallback 到 httpdns
 */
@property(atomic, copy, nullable)NSArray<NSString*>* httpdnsForbiddenWildcharHosts;

/*!
 @brief httpdns 优先时，bypass httpdns，只走 localdns，失败后不兜底到 httpdns
 */
@property(atomic, copy, nullable)NSArray<NSString*>* httpdnsBypassStrDomains;

@end

NS_ASSUME_NONNULL_END


#endif /* BDHttpDnsConfig_h */
