//
//  BDNetworkManager.h
//  TTNetworkManager
//
//  The TTNetworkManager is licensed under the MIT License.
//  Copyright (c) 2023 Bytedance Inc.
//

#ifndef BDNetworkManager_h
#define BDNetworkManager_h

#import <Foundation/Foundation.h>
#import "TTNetworkDefine.h"
#import "TTHTTPRequestSerializerProtocol.h"
#import "TTHTTPResponseSerializerProtocol.h"
#import "TTHttpTask.h"
#import "TTNetworkQualityEstimator.h" //NQE

NS_ASSUME_NONNULL_BEGIN

@interface BDNetworkManager : NSObject

//防抓包功能开关，不打开默认关闭
@property(atomic, assign) BOOL enableOpaqueData;

@property(atomic, strong) NSMutableDictionary<NSString*, id> *moduleConfigMap;


+ (instancetype)shareInstance;
- (id)init __attribute__((unavailable("Use +shareInstance to get the BDNetworkManager singleton.")));
+ (instancetype)new __attribute__((unavailable("Use +shareInstance to get the BDNetworkManager singleton")));

- (void)initAndStart;

- (TTNetEffectiveConnectionType)getEffectiveConnectionType;

- (TTPacketLossMetrics*)getPacketLossMetrics:(TTPacketLossProtocol)protocol;

- (BOOL)addRequestFilterObject:(TTRequestFilterObject *)requestFilterObject;

- (void)setMonitorBlock:(Monitorblock)block;
                   
 /**
 *  通过URL和参数获取JSON，支持定制header，回调里面有Response
 *
 *  @param URL                请求的URL
 *  @param params             请求的参数
 *  @param method             请求的方法
 *  @param headerField        header dic
 *  @param requestSerializer  设置该接口该次请求的的序列化对象, 如果传nil，用默认值
 *  @param responseSerializer 设置该接口该次返回的的序列化对象, 如果传nil，用默认值
 *  @param autoResume         是否自动开始
 *  @param isCustomizedCookie 是否要使用自定义的cookie, 如果是No，则会默认携带系统cookie
 *  @param callback           回调结果
 *
 *  @return TTHttpTask
 */
- (nullable TTHttpTask *)requestForJSONWithResponse:(NSString *)URL
                                             params:(nullable NSDictionary *)params
                                             method:(NSString *)method
                                        headerField:(nullable NSDictionary *)headerField
                                  requestSerializer:(nullable Class<TTHTTPRequestSerializerProtocol>)requestSerializer
                                 responseSerializer:(nullable Class<TTJSONResponseSerializerProtocol>)responseSerializer
                                         autoResume:(BOOL)autoResume
                                 isCustomizedCookie:(BOOL)isCustomizedCookie
                                           callback:(nullable TTNetworkJSONFinishBlockWithResponse)callback;
                                  
                                  
                                  
/**
 *  通过URL和参数获取二进制数据， 回调里面有Response
 *
 *  @param URL                请求的URL
 *  @param params             请求的参数
 *  @param method             请求的方法
 *  @param headerField        自定义header
 *  @param autoResume         是否自动开始
 *  @param isCustomizedCookie 是否要使用自定义的cookie, 如果是No，则会默认携带系统cookie
 *  @param requestSerializer  请求的序列化对象, 如果传nil，用默认值
 *  @param responseSerializer 返回的序列化对象, 如果传nil，用默认值
 *  @param callback           请求返回回调
 *
 *  @return TTHttpTask
 */
- (nullable TTHttpTask *)requestForBinaryWithResponse:(NSString *)URL
                                               params:(nullable NSDictionary *)params
                                               method:(NSString *)method
                                          headerField:(nullable NSDictionary *)headerField
                                           autoResume:(BOOL)autoResume
                                   isCustomizedCookie:(BOOL)isCustomizedCookie
                                    requestSerializer:(nullable Class<TTHTTPRequestSerializerProtocol>)requestSerializer
                                   responseSerializer:(nullable Class<TTBinaryResponseSerializerProtocol>)responseSerializer
                                             callback:(nullable TTNetworkObjectFinishBlockWithResponse)callback;
                                    


/**
 *  通过URL和参数获取二进制数据， 回调里面有Response
 *
 *  @param URL                请求的URL
 *  @param params             请求的参数
 *  @param method             请求的方法
 *  @param headerField        自定义header
 *  @param enableHttpCache        是否要使用cache
 *  @param requestSerializer  请求的序列化对象, 如果传nil，用默认值
 *  @param responseSerializer 返回的序列化对象, 如果传nil，用默认值
 *  @param autoResume         是否自动开始
 *  @param headerCallback         Response Header回调
 *  @param dataCallback           Response Body 回调
 *  @param callbackWithResponse   请求结果回调
 *
 *  @return TTHttpTask
 */
- (nullable TTHttpTask *)requestForChunkedBinaryWithResponse:(NSString *)URL
                                                      params:(id _Nullable)params
                                                      method:(NSString *)method
                                            needCommonParams:(BOOL)needCommonParams
                                                 headerField:(nullable NSDictionary *)headerField
                                             enableHttpCache:(BOOL)enableHttpCache
                                           requestSerializer:(nullable Class<TTHTTPRequestSerializerProtocol>)requestSerializer
                                          responseSerializer:(nullable Class<TTBinaryResponseSerializerProtocol>)responseSerializer
                                                  autoResume:(BOOL)autoResume
                                              headerCallback:(nullable TTNetworkChunkedDataHeaderBlock)headerCallback
                                                dataCallback:(nullable TTNetworkChunkedDataReadBlock)dataCallback
                                        callbackWithResponse:(nullable TTNetworkObjectFinishBlockWithResponse)callbackWithResponse;

/**
*  通过NSURLRequest发送请求，回调里面有Response
*
*  @param request                NSURLRequest
*  @param autoResume             是否自动开始
*  @param enableHttpCache        是否要使用cache
*  @param headerCallback         Response Header回调
*  @param dataCallback           Response Body 回调
*  @param callbackWithResponse   请求结果回调
*
*  @return TTHttpTask
*/
- (nullable TTHttpTask *)requestForWebview:(NSURLRequest *)request
                                autoResume:(BOOL)autoResume
                           enableHttpCache:(BOOL)enableHttpCache
                            headerCallback:(nullable TTNetworkChunkedDataHeaderBlock)headerCallback
                              dataCallback:(nullable TTNetworkChunkedDataReadBlock)dataCallback
                      callbackWithResponse:(nullable TTNetworkObjectFinishBlockWithResponse)callbackWithResponse;
                                    
                                    
/**
 *  根据URL和参数下载文件，可以通过KVO观察进度
 *
 *  @param URL                URL
 *  @param parameters         请求的参数
 *  @param headerField        HTTP header信息
 *  @param requestSerializer  请求的序列化对象, 如果传nil，用默认值
 *  @param progress           NSProgress形式的进度
 *  @param destination        文件存储位置,NSURL形式的本地file地址
 *  @param autoResume         是否自动开始
 *  @param completionHandler  完成后回调
 *  @return TTHttpTask
 */
- (nullable TTHttpTask *)downloadTaskWithRequest:(NSString *)URL
                                      parameters:(nullable NSDictionary *)parameters
                                     headerField:(nullable NSDictionary *)headerField
                               requestSerializer:(nullable Class<TTHTTPRequestSerializerProtocol>)requestSerializer
                                        progress:(NSProgress * _Nullable __autoreleasing * _Nullable)progress
                                     destination:(NSURL *)destination
                                      autoResume:(BOOL)autoResume
                               completionHandler:(nullable DownloadCompletionHandler)completionHandler;
                      
                      
                      
/**
 *  上传无格式数据，BINARY responseSerializer， callback 有response
 *
 *  @param URLString          上传URL
 *  @param method             HTTP 方法: POST或PUT
 *  @param headerField        HTTP 请求头部
 *  @param bodyField          HTTP 请求体，无格式处理
 *  @param progress           进度
 *  @param requestSerializer  自定义请求序列化对象, 如果传nil，用默认值
 *  @param responseSerializer 自定义返回的序列化对象, 如果传nil，用默认值
 *  @param autoResume         是否自动开始
 *  @param callback           回调
 *  @param timeout            超时时间，单位s
 *
 *  @return TTHttpTask
 */
- (nullable TTHttpTask *)uploadRawDataWithResponse:(NSString *)URLString
                                            method:(NSString *)method
                                       headerField:(nullable NSDictionary *)headerField
                                         bodyField:(NSData *)bodyField
                                          progress:(NSProgress * _Nullable __autoreleasing * _Nullable)progress
                                 requestSerializer:(nullable Class<TTHTTPRequestSerializerProtocol>)requestSerializer
                                responseSerializer:(nullable Class<TTBinaryResponseSerializerProtocol>)responseSerializer
                                        autoResume:(BOOL)autoResume
                                          callback:(nullable TTNetworkObjectFinishBlockWithResponse)callback
                                           timeout:(NSTimeInterval)timeout;
                                  
                                  
                                  
/**
 *  上传数据，BINARY responseSerializer， callback 有response
 *
 *  @param URLString          上传URL
 *  @param parameters         参数
 *  @param headerField        HTTP 请求头部
 *  @param bodyBlock          multipart/form-data body体
 *  @param progress           进度
 *  @param requestSerializer  自定义请求序列化对象, 如果传nil，用默认值
 *  @param responseSerializer 自定义返回的序列化对象, 如果传nil，用默认值
 *  @param autoResume         是否自动开始
 *  @param callback           回调
 *  @param timeout            超时时间，单位s
 *
 *  @return TTHttpTask
 */
- (nullable TTHttpTask *)uploadWithResponse:(NSString *)URLString
                                 parameters:(nullable NSDictionary *)parameters
                                headerField:(nullable NSDictionary *)headerField
                  constructingBodyWithBlock:(TTConstructingBodyBlock)bodyBlock
                                   progress:(NSProgress * _Nullable __autoreleasing * _Nullable)progress
                          requestSerializer:(nullable Class<TTHTTPRequestSerializerProtocol>)requestSerializer
                         responseSerializer:(nullable Class<TTBinaryResponseSerializerProtocol>)responseSerializer
                                 autoResume:(BOOL)autoResume
                                   callback:(nullable TTNetworkObjectFinishBlockWithResponse)callback
                                    timeout:(NSTimeInterval)timeout;
                           
                           
                           
/**
 *  上传文件数据，无格式，BINARY responseSerializer， callback 有response
 *
 *  @param URLString          上传URL
 *  @param method             HTTP 方法: POST或PUT
 *  @param headerField        HTTP 请求头部
 *  @param filePath           上传文件路径
 *  @param progress           进度
 *  @param requestSerializer  自定义请求序列化对象, 如果传nil，用默认值
 *  @param responseSerializer 自定义返回的序列化对象, 如果传nil，用默认值
 *  @param autoResume         是否自动开始
 *  @param callback           回调
 *  @param timeout           超时时间，单位s
 *
 *  @return TTHttpTask
 */
- (nullable TTHttpTask *)uploadRawFileWithResponse:(NSString *)URLString
                                            method:(NSString *)method
                                       headerField:(nullable NSDictionary *)headerField
                                          filePath:(NSString *)filePath
                                          progress:(NSProgress * _Nullable __autoreleasing * _Nullable)progress
                                 requestSerializer:(nullable Class<TTHTTPRequestSerializerProtocol>)requestSerializer
                                responseSerializer:(nullable Class<TTBinaryResponseSerializerProtocol>)responseSerializer
                                        autoResume:(BOOL)autoResume
                                          callback:(nullable TTNetworkObjectFinishBlockWithResponse)callback
                                           timeout:(NSTimeInterval)timeout;


//建议不要使用
@property(atomic, copy, nullable) NSString* getDomainDefaultJSON DEPRECATED_MSG_ATTRIBUTE("do NOT call this function unless you really know it");

@end
NS_ASSUME_NONNULL_END

#endif /* BDNetworkManager_h */
