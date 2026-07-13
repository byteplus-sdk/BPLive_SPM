//
//  TTHTTPRequestSerializerProtocol.h
//  TTNetworkManager
//
//  The TTNetworkManager is licensed under the MIT License.
//  Copyright (c) 2023 Bytedance Inc.
//

/// Moved from TTHTTPRequestSerializerBase.h

#import "TTRequestModel.h"
#import "TTNetworkDefine.h"

//TTHttpRequest Encapsulate the request of the network library
#import "TTHttpRequest.h"
NS_ASSUME_NONNULL_BEGIN
@protocol TTHTTPRequestSerializerProtocol <NSObject>

/**
 *  Instantiated object
 *
 *  @return Instantiated serializer object
 */
+ (NSObject<TTHTTPRequestSerializerProtocol> *)serializer;

/**
 *  Factory function to create TTHttpRequest via TTRequestModel
 *
 *  @param requestModel         RequestModel to generate URLRequest
 *  @param commonParam          common parameters
 *
 *  @return URLRequest generated
 */
- (nullable TTHttpRequest *)URLRequestWithRequestModel:(TTRequestModel *)requestModel
                                          commonParams:(nullable NSDictionary *)commonParam;

/**
 *  Factory function to create TTHttpRequest via URL and params
 *
 *  @param URL                request URL
 *  @param params             request parameters
 *  @param method             request method
 *  @param bodyBlock         need multipart form request body
 *  @param commonParam        common parameters
 *
 *  @return URLRequest generated
 */
- (nullable TTHttpRequest *)URLRequestWithURL:(NSString *)URL
                                       params:(id _Nullable)params
                                       method:(NSString *)method
                        constructingBodyBlock:(nullable TTConstructingBodyBlock)bodyBlock
                                 commonParams:(nullable NSDictionary *)commonParam;
/**
 *  Factory function to create TTHttpRequest via URL and params
 *
 *  @param URL                request URL
 *  @param headField          HTTP head
 *  @param params             request parameters
 *  @param method             request method
 *  @param bodyBlock          need multipart form request body
 *  @param commonParam        common parameters
 *
 *  @return URLRequest generated
 */

- (nullable TTHttpRequest *)URLRequestWithURL:(NSString *)URL
                                  headerField:(nullable NSDictionary *)headField
                                       params:(id _Nullable)params
                                       method:(NSString *)method
                        constructingBodyBlock:(nullable TTConstructingBodyBlock)bodyBlock
                                 commonParams:(nullable NSDictionary *)commonParam;

/**
 *  set User-Agent
 *
 *  @return User-Agent
 */
- (nullable NSString *)userAgentString;


@end
NS_ASSUME_NONNULL_END
