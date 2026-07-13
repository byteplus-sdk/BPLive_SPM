//
//  TTNetworkDefine.h
//  TTNetworkManager
//
//  The TTNetworkManager is licensed under the MIT License.
//  Copyright (c) 2023 Bytedance Inc.
//
//  TTNetworkDefine contains the error description and the define of callback block.

#import "TTResponseModelProtocol.h"
#import "TTHttpMultipartFormData.h"
@class TTHttpRequest;
@class TTHttpResponse;
@class TTDnsResult;

#ifndef TTNetworkManager_TTNetworkDefine_h
#define TTNetworkManager_TTNetworkDefine_h

//autoreleasepool
#define TTNetAutoReleasePoolBegin @autoreleasepool {
#define TTNetAutoReleasePoolEnd }


#pragma mark -- callback block
#pragma mark -- response block

/**
 *  JSON response callback
 *
 *  @param error  -- callback error
 *  @param jsonObj -- callback response
 */
typedef void (^TTNetworkJSONFinishBlock)(NSError * _Nullable error, id _Nullable jsonObj);

typedef void (^TTNetworkJSONFinishBlockWithResponse)(NSError * _Nullable error, id _Nullable obj, TTHttpResponse * _Nullable response);

/**
 *  Binary response callback
 *
 *  @param error -- callback error
 *  @param obj -- callback response
 */
typedef void (^TTNetworkObjectFinishBlock)(NSError * _Nullable error, id _Nullable obj);

typedef void (^TTNetworkObjectFinishBlockWithResponse)(NSError * _Nullable error, id _Nullable obj, TTHttpResponse * _Nullable response);

typedef void (^TTNetworkChunkedDataHeaderBlock)(TTHttpResponse * _Nonnull response);

typedef void (^TTNetworkChunkedDataReadBlock)(NSData* _Nonnull obj);

typedef void (^TTNetworkURLRedirectBlock)(NSString * _Nonnull new_location, TTHttpResponse * _Nonnull old_repsonse);

typedef void (^DownloadCompletionHandler)(TTHttpResponse * _Nullable response, NSURL * _Nullable filePath, NSError * _Nullable error);

typedef void (^ProgressCallbackBlock)(int64_t current, int64_t total);

#pragma mark -- callback block
#pragma mark -- Download progress callback block
/**
 *  progress 0 - 100
 *
 *  @param progress -- download progress
 */
typedef void (^TTNetObjectProgressBlock)(int progress);

#pragma mark -- rqeuest block block

/**
 *
 *  if the request body contains file, this block will be called.
 *
 *  @param formData used to build request body which contains file.
 */
typedef void (^TTConstructingBodyBlock)(id<TTMultipartFormData> _Nonnull formData);

typedef void (^Monitorblock)(NSDictionary* _Nonnull, NSString* _Nonnull);
/**
 * execute after request serializer， before request start
 */
typedef void (^RequestFilterBlock)(TTHttpRequest * _Nonnull request);
#pragma mark - new request filter object
/**
 * new request filter object
 * requestFilterName must be unique
 */
@interface TTRequestFilterObject : NSObject
//request filter name, user should pass a unique name
@property(nonatomic, copy, nonnull) NSString* requestFilterName;
//request filter block
@property(nonatomic, copy, nonnull) RequestFilterBlock requestFilterBlock;
- (nonnull instancetype)initWithName:(NSString * _Nonnull)requestFilterName
                  requestFilterBlock:(nonnull RequestFilterBlock)requestFilterBlock;
@end

#pragma mark -- error

#define kTTNetworkCustomErrorKey @"kTTNetworkCustomErrorKey"
#define kTTNetworkErrorDomain @"kTTNetworkErrorDomain"
#define kTTNetworkUserinfoTipKey @"kTTNetworkUserinfoTipKey"

#define kTTNetworkErrorTipNoNetwork @"No Network"
#define kTTNetworkErrorTipNetworkError @"Network Error"
#define kTTNetworkErrorTipServerError @"Server Error"
#define kTTNetworkErrorTipParseJSONError @"ParseJSON Error"
#define kTTNetworkErrorTipNetworkHijacked  @"Network Hijacked"

// Define user scene.
#define IDFA_AUTH_SCENE @"idfa_auth"

typedef NS_ENUM(NSUInteger, TTNetworkManagerApiType){
    
    TTNetworkManagerApiModel = 0,
    
    TTNetworkManagerApiJSON,
    
    TTNetworkManagerApiBinary,
    
    TTNetworkManagerApiMemoryUpload,
    
    TTNetworkManagerApiFileUpload,
    
    TTNetworkManagerApiDownload,
    
    TTNetworkManagerApiWebview
    
};

/**
 * Error code description.
 */
typedef NS_ENUM(NSInteger, TTNetworkErrorCode){
    //The task was cancelled by the user
    TTNetworkErrorCodeUserCancelled = -999,
    // The task was cancelled by the user while pending in dispatcher.
    TTNetworkErrorCodeUserCancelledWhilePending = -998,
    // The json data returned by server is not dict format.
    TTNetworkErrorCodeNetworkJsonResultNotDictionary = -99,
    // The request has been dropped when user set drop header (cli_need_drop_request:1)
    TTNetworkErrorCodeDropClientRequest = -98,

    // The self-defined error code starts with -10.
    /**
     *  if Task.request.followRedirect = NO, this error code is set in calback
     */
    TTNetworkErrorCodeStopOnRedirect = -10,

    /**
     *  CDN cache error.
     */
    TTNetworkErrorCodeCdnCache = -9,

    /**
     * when enableApiHttpIntercept is set, |api http| in api_http_host_list has been intercepted and
     * report monitor log.
     */
    TTNetworkErrorCodeApiHttpIntercepted = -8,

    /**
     * State is error in client side (such as not initialization)
     */
    TTNetworkErrorCodeIllegalClientState = -7,
    
    /**
     * invalid request url
     */
    TTNetworkErrorCodeBadURLRequest = -6,
    
    /**
     * network has been hijacked.
     */
    TTNetworkErrorCodeNetworkHijacked = -5,
    /**
     *  json parsed failed.
     */
    TTNetworkErrorCodeParseJSONError = -4,
    /**
     * Sever has some errors.
     */
    TTNetworkErrorCodeServerError = -3,
    /**
     * Connection errors.
     */
    TTNetworkErrorCodeNetworkError = -2,
    /**
     * Network is not available.
     */
    TTNetworkErrorCodeNoNetwork = -1,
    /**
     * No error. Success.
     */
    TTNetworkErrorCodeSuccess = 0,

    // The following error codes start with 1 are same with Android's.
    
    TTNetworkErrorCodeUnknown = 1,
    TTNetworkErrorCodeConnectTimeOut = 2,
    TTNetworkErrorCodeSocketTimeOut = 3,
    TTNetworkErrorCodeIOException = 4,
    TTNetworkErrorCodeSocketException = 5,
    TTNetworkErrorCodeResetByPeer = 6,
    TTNetworkErrorCodeBindException = 7,
    TTNetworkErrorCodeConnectExceptioin = 8,
    TTNetworkErrorCodeNoReouteToHost = 9,
    TTNetworkErrorCodeProtUnreachable = 10,
    TTNetworkErrorCodeUnknonwHost = 11,
    
    //errno
    TTNetworkErrorCodeECONNRESET = 12,
    TTNetworkErrorCodeECONNREFUSED = 13,
    TTNetworkErrorCodeEHOSTUNREACH = 14,
    TTNetworkErrorCodeENETUNREACH = 15,
    TTNetworkErrorCodeEADDRNOTAVAIL = 16,
    TTNetworkErrorCodeEADDRINUSE = 17,
    
    TTNetworkErrorCodeNoHttpResponse = 18,
    TTNetworkErrorCodeClientProtocolException = 19,
    TTNetworkErrorCodeFileTooLarge = 20,
    TTNetworkErrorCodeTooManyRedirect = 21,
    
    TTNetworkErrorCodeUnknowClientError = 31,
    TTNetworkErrorCodeNoSpace = 32,
    
    // errno
    TTNetworkErrorCodeENOENT = 33, //no such file or directory
    TTNetworkErrorCodeEDQUOT = 34, //exceed disk quota
    TTNetworkErrorCodeEROFS = 35,
    TTNetworkErrorCodeEACCES = 36, //permission denyed
    TTNetworkErrorCodeEIO = 37,
    TTNetworkErrorCodeEImproperImage = 38 //improper Image in webview
};

typedef NS_ENUM(NSInteger, TTMultiNetworkState) {
    STATE_STOPPED = -1,
    STATE_NO_NETWORK = 0,
    STATE_DEFAULT_CELLULAR,
    STATE_DEFAULT_WIFI_WITH_CELLULAR_DOWN,
    STATE_DEFAULT_WIFI_WITH_CELLULAR_UP,
    STATE_WAIT_CELLULAR_ALWAYS_UP,
    STATE_WAIT_USER_ENABLE,
    STATE_WIFI_WITH_CELLULAR_TRANS_DATA,
    STATE_EVALUATE_CELLULAR,
    STATE_COUNT
};

typedef NS_ENUM(int, TTNetworkAppSecurityLevel) {
    // Default app security level.
    TTNetworkAppSecurityLevelUnspecified = 0,
    // Restrictions caused by not accepting the app privacy policy.
    TTNetworkAppSecurityLevelUserPrivacyRestriction = 1 << 0,
    // Restrictions caused by oversea TTP policy.
    TTNetworkAppSecurityLevelTTPRestriction = 1 << 1
};

#define CPPSTR(str) str == nil ? "" : str.UTF8String

#define kTTNetSubErrorCode @"error_num"

#define kTTNetRequestType @"x-ttnet-request-api-type"

#pragma mark -- some builtin keys
#define kUserAgentHeaderKey @"User-Agent"
#define kTTRequestTimeHeaderKey @"tt-request-time"
#define kUpperCaseCookieHeaderKey @"Cookie"
#define kLowerCaseCookieHeaderKey @"cookie"
#define kXSSCookieHeaderKey @"X-SS-Cookie"
#define kXSSQueriesHeaderKey @"X-SS-QUERIES"
#define kContentTypeHeaderKey @"Content-Type"
#define kAcceptHeaderKey @"Accept"
#define kContentDispositionHeaderKey @"Content-Disposition"


#endif
