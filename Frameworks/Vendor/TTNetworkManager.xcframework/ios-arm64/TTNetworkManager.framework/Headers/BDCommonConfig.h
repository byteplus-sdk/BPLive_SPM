//
//  BDCommonConfig.h
//  TTNetworkManager
//
//  The TTNetworkManager is licensed under the MIT License.
//  Copyright (c) 2023 Bytedance Inc.
//

#ifndef BDCommonConfig_h
#define BDCommonConfig_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @brief 使用此模块时，注入BDNetwork ModuleMap时用的Key
 */
extern NSString * const kBDCommonConfigKey;

#pragma mark - BDSocketPoolParams
/*!
 @brief socket连接池相关配置
 */
@interface BDSocketPoolParams : NSObject
/*!
 @brief 未使用过的socket连接保存时间，单位s
 @discussion optional，默认值10
 */
@property(atomic, assign) NSUInteger unusedIdleSocketTimeout;

/*!
 @brief 单组最大socket连接数量
 @discussion optional，默认值6
 */
@property(atomic, assign) NSUInteger maxSocketsPerGroup;

/*!
 @brief 使用过的socket连接保存时间，单位s
 @discussion optional，默认值300
 */
@property(atomic, assign) NSUInteger usedIdleSocketTimeout;
@end


#pragma mark - BDRedirectParams
/*!
 @brief 重定向相关配置
 */
@interface BDRedirectParams : NSObject
/*!
 @brief 需要被管控的敏感请求头key列表
 @discussion optional
 */
@property(atomic, copy, nullable) NSArray<NSString*>* scyHeaders;

/*!
 @brief 允许重定向后携带敏感请求头的host白名单
 @discussion optional，白名单优先级高于黑名单，若域名命中白名单，则不再会命中黑名单
 */
@property(atomic, copy, nullable) NSArray<NSString*>* scyRectWl;

/*!
 @brief 若重定向后域名不在host白名单内，是否删除敏感请求头
 @discussion 默认不删除
 */
@property(atomic, assign) BOOL rmInScyOutWl;

/*!
 @brief 重定向后携带敏感请求头host黑名单
 @discussion optional，当重定向后域名在此列表内，且请求包含敏感请求头，删除敏感请求头
 */
@property(atomic, copy, nullable) NSArray<NSString*>* scyRectBl;

@end


#pragma mark - BDCommonConfig
@interface BDCommonConfig: NSObject

/*!
 @brief socket连接池相关配置
 @discussion 有默认值，不为空，无特别理由无需单独设置。
 */
@property(atomic, strong) BDSocketPoolParams *socketPoolParams;

@property(atomic, strong) BDRedirectParams *redirectConfig;

@end

NS_ASSUME_NONNULL_END

#endif /* BDCommonConfig_h */
