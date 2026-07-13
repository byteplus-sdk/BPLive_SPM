//
//  BDNqeConfig.h
//  TTNetworkManager
//
//  The TTNetworkManager is licensed under the MIT License.
//  Copyright (c) 2023 Bytedance Inc.
//

#ifndef BDNqeConfig_h
#define BDNqeConfig_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @brief 使用此模块时，注入BDNetwork ModuleMap时用的Key
 */
extern NSString * const kBDNqeConfigKey;

/*!
 @brief 网络质量结果的多维度定义
 */
@interface BDNetworkQuality : NSObject

/*!
 @brief HTTP RTT
 */
@property(atomic, assign, readonly) NSInteger effectiveHttpRttMs;
/*!
 @brief TCP/QUIC RTT
 */
@property(atomic, assign, readonly) NSInteger effectiveTransportRttMs;
/*!
 @brief 下行吞吐
 */
@property(atomic, assign, readonly) NSInteger effectiveRxThroughputKbps;

- (instancetype)initWithEffectiveHttpRttMs:(NSInteger)httpRtt
                andEffectiveTransportRttMs:(NSInteger)tcpRtt
              andEffectiveRxThroughputKbps:(NSInteger)kbps;
@end

/*!
 @brief QUIC丢包率相关功能
 */
@interface BDPacketLossEstimator : NSObject

/*!
 @brief 是否开启丢包率统计
 @discussion optional，默认YES
 */
@property(atomic, assign) BOOL enable;

/*!
 @brief 采样周期，单位ms
 @discussion optional，默认值1000
 */
@property(atomic, assign) NSUInteger lossRateSamplingPeriodMs;

/*!
 @brief 采样时间窗口，单位ms
 @discussion optional，默认值15000
 */
@property(atomic, assign) NSUInteger lossRateSampleWindowMs;

/*!
 @brief 包存在乱序接收的情况，最大记录多少个疑似丢失的包
 @discussion optional，默认值1000
 */
@property(atomic, assign) NSUInteger mostLossPacketsPreserved;

/*!
 @brief 丢包窗口最大采样个数
 @discussion optional，默认值1000
 */
@property(atomic, assign) NSUInteger mostLossWindowsPreserved;

@end



/*!
 @brief Nqe 结果回调定义
 */
typedef void (^BDGetNqeResultBlock)(NSInteger httpRtt, NSInteger transportRtt, NSInteger downstreamThroughputKbps);

/*!
 @brief 网络类型变化回调定义，
 @discussion changeInfo可以取到 "connection_type"
 */
typedef void (^ConnectionTypeChangedBlock)(NSDictionary* changeInfo);


@interface BDNqeConfig : NSObject

/*!
 @brief 是否开启假网探测
 @discussion optional，默认NO
 */
@property(atomic, assign) BOOL enableFakeNetworkDetect;
/*!
 @brief 用于假网探测的域名列表
 @discussion optional，默认Array为空列表
 */
@property(atomic, copy) NSArray<NSString*>* fakeNetworkDetectHosts;
/*!
 @brief NQE 结果回调
 @discussion optional，MNet网络线程执行，默认nil
 */
@property(atomic, copy, nullable) BDGetNqeResultBlock nqeBlock;
/*!
 @brief 网络类型变化回调
 @discussion optional，MNet网络线程执行，默认nil
 */
@property(atomic, copy, nullable) ConnectionTypeChangedBlock typeChangeBlock;

/*!
 @brief QUIC丢包率相关参数配置
 @discussion 有默认值，不为空，无特别理由无需单独设置。
 */
@property(atomic, strong) BDPacketLossEstimator *packetLossEstimator;

/*!
 @brief 主动获取网络质量
 @return 网络质量结果，定义见类说明
 */
+ (BDNetworkQuality*)getNetworkQuality;

@end

NS_ASSUME_NONNULL_END

#endif /* BDNqeConfig_h */
