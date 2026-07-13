//
//  BDNetDetectConfig.h
//  TTNetworkManager
//
//  The TTNetworkManager is licensed under the MIT License.
//  Copyright (c) 2023 Bytedance Inc.
//

#ifndef BDNetDetectConfig_h
#define BDNetDetectConfig_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @brief 使用此模块时，注入BDNetwork ModuleMap时用的Key
 */
extern NSString * const kBDNetDetectConfigKey;


/*!
 @brief 拨测结果回调，拨测结果较复杂，详细定义见文档。
 */
typedef void (^NetDetectCallback)(NSString * _Nonnull netDetectInfo);

@interface BDNetDetectConfig : NSObject

/*!
 @brief optional，拨测结果回调
 @discussion optional，MNet网络线程执行，默认nil
 */
@property(atomic, copy, nullable) NetDetectCallback callback;

/*!
 @brief optional，用户反馈触发探测开关
 @discussion optional，默认false
 */
@property(atomic, assign) BOOL enableFeedback;
/*!
 @brief optional，轮训探测开关
 @discussion optional，默认false
 */
@property(atomic, assign) BOOL enablePolling;
/*!
 @brief optional，请求异常触发探测开关
 @discussion optional， 默认false
 */
@property(atomic, assign) BOOL enableException;

/*!
 @brief optional，拨测地址列表
 @discussion optional，必须为完整的URL（包含scheme），默认Array为空
 */
@property(atomic, copy) NSArray<NSString*>* detectUrls;

/*!
 @brief 探测方式，取值范围：
 ACTION_HTTP_GET  = 1;
 ACTION_ICMP_PING = 2;
 ACTION_TRCEROUTE = 4;
 ACTION_DNS_LOCAL = 8;
 ACTION_DNS_HTTP  = 16;
 ACTION_DNS_SERVER = 32；（获取clientip及dnsserver探测）
 ACTION_UDP_PING = 64;
 actions == 0： 全部探测; actions > 0:   与action执行&判定是否执行。
 @discussion optional，默认1.
 */
@property(atomic, assign) int actions;

/*!
 @brief 探测间隔，单位s
 @discussion optional，默认值1800
 */
@property(atomic, assign) int interval;

/*!
 @brief 轮询探测间隔，单位s，必须大于探测间隔
 @discussion optional，默认值3600
 */
@property(atomic, assign) int pollingInterval;

/*!
 @brief polling探测最大次数
 @discussion optional，默认值20
 */
@property(atomic, assign) int pollingMax;

/*!
 @brief 轮询探测延迟启动时间，单位s
 @discussion optional，默认值60
 */
@property(atomic, assign) int pollingStartDelay;

/*!
 @brief 主动发起探测的接口
 @param urls 主动探测的url列表
 @param timeout 拨测超时时间，单位s，要求小于180s
 @param actions 探测方式，详细定义见上面actions
 */
+ (void)tryStartNetDetect:(NSArray<NSString*>*)urls
                  timeout:(NSInteger)timeout
                  actions:(NSInteger)actions;

@end

NS_ASSUME_NONNULL_END

#endif /* BDNetDetectConfig_h */
