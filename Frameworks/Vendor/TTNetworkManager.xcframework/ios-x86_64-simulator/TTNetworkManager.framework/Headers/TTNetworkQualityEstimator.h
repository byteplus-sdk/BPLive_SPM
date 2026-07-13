//
//  TTNetworkQualityEstimator.h
//  TTNetworkManager
//
//  The TTNetworkManager is licensed under the MIT License.
//  Copyright (c) 2023 Bytedance Inc.
//

#ifndef TTNetworkQualityEstimator_h
#define TTNetworkQualityEstimator_h

#define INVALID_RTT_OR_THROUGHPUT_VALUE -1
#define INVALID_PACKET_LOSS_RATE_OR_VARIANCE_VALUE -1.0

typedef NS_ENUM(NSInteger, TTPacketLossProtocol) {
  PACKET_LOSS_PROTOCOL_INVALID = -1,
  PACKET_LOSS_PROTOCOL_TCP = 0,
  PACKET_LOSS_PROTOCOL_QUIC,
  PACKET_LOSS_PROTOCOL_LAST
};

typedef NS_ENUM(NSInteger, TTNetEffectiveConnectionType) {
  // Effective connection type reported when the network is fake network.
  EFFECTIVE_CONNECTION_TYPE_FAKE_NETWORK = -1,

  // Unknown network quality.
  EFFECTIVE_CONNECTION_TYPE_UNKNOWN = 0,

  // Unreachable, the device does not have a connection or the connection is too slow to be usable.
  EFFECTIVE_CONNECTION_TYPE_OFFLINE,
    
  // Poor 2G connection.
  EFFECTIVE_CONNECTION_TYPE_SLOW_2G,

  // Faster 2G connection.
  EFFECTIVE_CONNECTION_TYPE_2G,

  // 3G connection.
  EFFECTIVE_CONNECTION_TYPE_3G,

  //For bytedance network quality estimation
  // doc/doccnpEekZvelthGFc7IqylvvEa
  // Effective connection type reported when the network has the quality of a 4G
  // connection.
  //EFFECTIVE_CONNECTION_TYPE_4G,

  // Effective connection type reported when the network has the quality of a SLOW_4G
  // connection.
  EFFECTIVE_CONNECTION_TYPE_SLOW_4G,

  // Effective connection type reported when the network has the quality of a MODERATE_4G
  // connection.
  EFFECTIVE_CONNECTION_TYPE_MODERATE_4G,

  // Effective connection type reported when the network has the quality of a GOOD_4G
  // connection.
  EFFECTIVE_CONNECTION_TYPE_GOOD_4G,

  // Effective connection type reported when the network has the quality of a EXCELLENT_4G
  // connection.
  EFFECTIVE_CONNECTION_TYPE_EXCELLENT_4G,

  // Last value of the effective connection type. This value is unused.
  EFFECTIVE_CONNECTION_TYPE_LAST,
};

@interface TTNetworkQuality : NSObject

@property(nonatomic, assign) NSInteger httpRttMs;

@property(nonatomic, assign) NSInteger transportRttMs;

@property(nonatomic, assign) NSInteger downstreamThroughputKbps;

@end

@interface TTNetworkQualityV2 : NSObject
@property(nonatomic, assign) int level;

@property(nonatomic, assign) int effectivHttpRttMs;

@property(nonatomic, assign) int effectiveTransportRttMs;

@property(nonatomic, assign) int effectiveRxThroughputKbps;
@end

@interface TTPacketLossMetrics : NSObject

@property(nonatomic, assign) TTPacketLossProtocol protocol;

@property(nonatomic, assign) double upstreamLossRate;

@property(nonatomic, assign) double upstreamLossRateVariance;

@property(nonatomic, assign) double downstreamLossRate;

@property(nonatomic, assign) double downstreamLossRateVariance;

@end

#endif /* TTNetworkQualityEstimator_h */
