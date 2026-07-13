//
//  TTHttpResponse.h
//  TTNetworkManager
//
//  The TTNetworkManager is licensed under the MIT License.
//  Copyright (c) 2023 Bytedance Inc.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN
@interface TTCaseInsenstiveDictionary<__covariant KeyType, __covariant ObjectType> : NSMutableDictionary<KeyType, ObjectType> {
    NSMutableDictionary<KeyType, ObjectType> *inner_dict;
}

@end

@interface TTHttpResponseTimingInfo : NSObject

@property (nullable, nonatomic, strong, readonly) NSDate *start;
@property (nonatomic, assign, readonly) int64_t proxy;
@property (nonatomic, assign, readonly) int64_t dns;
@property (nonatomic, assign, readonly) int64_t connect;
@property (nonatomic, assign, readonly) int64_t ssl;
@property (nonatomic, assign, readonly) int64_t send;
@property (nonatomic, assign, readonly) int64_t wait;
@property (nonatomic, assign, readonly) int64_t receive;
@property (nonatomic, assign, readonly) int64_t total;
// The number of bytes in the raw response body (before response filters are
// applied, to decompress it, for instance).
@property (nonatomic, assign, readonly) int64_t receivedResponseContentLength;
// The number of bytes received over the network during the processing of this
// request. This includes redirect headers, but not redirect bodies. It also
// excludes SSL and proxy handshakes.
@property (nonatomic, assign, readonly) int64_t totalReceivedBytes;

@property (nonatomic, assign, readonly) BOOL isSocketReused;
@property (nonatomic, assign, readonly) BOOL isCached;
@property (nonatomic, assign, readonly) BOOL isFromProxy;
@property (nonatomic, assign, readonly) int8_t cacheStatus;
@property (nullable, nonatomic, copy, readonly) NSString *remoteIP;
@property (nonatomic, assign, readonly) uint16_t remotePort;

@end

// Request retry from response header for bdturing-retry and user-set header case
@interface BDTuringCallbackInfo : NSObject
// Set to 1 in retry request
@property (nonatomic, assign, readonly) int8_t bdTuringRetry;
// The time cost of verfiy callback
@property (nonatomic, assign, readonly) NSTimeInterval bdTuringCallbackDuration;
// The request was blocked by which header.
@property (nullable, nonatomic, copy, readonly) NSString* retryByHeaderFilterKey;

- (instancetype)initWithTuringRetry:(int8_t)turingRetry
                   callbackDuration:(NSTimeInterval)callbackDuration
             retryByHeaderFilterKey:(nullable NSString *)retryByHeaderFilterKey;

@end

//record additional time info in user's callback, like modelization, antispam, completion block etc in DMT
@interface TTHttpResponseAdditionalTimeInfo : NSObject

@property (nonatomic, strong) NSMutableDictionary<NSString *, NSNumber*> *completionBlockTime;

- (instancetype)initWithCompletionBlockTime:(NSMutableDictionary<NSString *, NSNumber*> *)completionBlockTime;

@end

@interface TTHttpResponse : NSObject

/*!
 @property statusCode
 @abstract Returns the HTTP status code of the receiver.
 @result The HTTP status code of the receiver.
 */
@property (readonly) NSInteger statusCode;

/*!
 @property allHeaderFields
 @abstract Returns a dictionary containing all the HTTP header fields
 of the receiver.
 @discussion By examining this header dictionary, clients can see
 the "raw" header information which was reported to the protocol
 implementation by the HTTP server. This may be of use to
 sophisticated or special-purpose HTTP clients.
 @result A dictionary containing all the HTTP header fields of the
 receiver.
 */
@property (nullable, readonly, copy) TTCaseInsenstiveDictionary *allHeaderFields;

@property (nullable, readonly, strong) NSMutableDictionary<NSString *, NSNumber *> *filterObjectsTimeInfo;

@property (readonly, strong) NSMutableDictionary<NSString *, NSNumber *> *serializerTimeInfo;
//modelization, antispam etc in completion block
@property (nullable, readonly, strong) TTHttpResponseAdditionalTimeInfo *additionalTimeInfo;
//initialized in TTNet, upper layer inserts their infos and TTNet sends it to slardar
@property (nonnull, readonly, strong) NSMutableDictionary *extraBizInfo;

//TTNet's response metrics
@property (nullable, readonly, strong) NSMutableDictionary *responseInfo;

/*!
 @property URL
 @abstract Returns the URL that user passed to TTNet
 @result The URL of the receiver.
 */
@property (nullable, readonly, strong) NSURL *URL;

/**
 * Returns the URL that sent by TTNet
 * it could be different from the URL above when the request matched with dispatch actions in TNC
 * otherwise it will be the same with the URL above
 */
@property (nullable, readonly, strong) NSURL *finalURL;

/**
  @brief MIME type of the response
 */
@property (nullable, readonly, copy) NSString *MIMEType;

@property (readonly, assign) BOOL isInternalRedirect;

@property (nullable, readonly, strong) TTHttpResponseTimingInfo *timinginfo;

@property (nullable, readonly, strong) BDTuringCallbackInfo *turingCallbackinfo;

//record detail concurrent request info
@property (nullable, strong) NSMutableDictionary *concurrentRequestLogInfo;

@property (atomic, readonly, assign) BOOL isCallbackExecutedOnMainThread;

- (NSString *)getRequestLog;

@end
NS_ASSUME_NONNULL_END
