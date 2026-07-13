/*
 * Copyright (c) 2020 The BytePlusRTC project authors. All Rights Reserved.
 * @brief BytePlusRTC HTTP Client Protocol
*/

#import <Foundation/Foundation.h>


/**
 * 
 * @hidden for internal use only
 * @type api
 * @region Engine Management
 */
@protocol ByteRTCHttpClientProtocol <NSObject>

@required


/**
 * 
 * @type api
 * @region Engine Management
 * @brief The HTTP asynchronous GET interface to be implemented
 * @param url GET request address
 * @param timeout Timeout period
 * @param callback GET request result callback function
 */
- (void)getAsync:(NSString * _Nonnull)url timeoutMillisecond:(int)timeout
    withCallback:(void(^ _Nullable)(int code, NSString* _Nullable data))callback;


/**
 * 
 * @type api
 * @region Engine Management
 * @brief The HTTP asynchronous POST interface to be implemented
 * @param url POST request address
 * @param content The content of the POST request
 * @param timeout Timeout period
 * @param callback POST request result callback function
 */
- (void)postAsync:(NSString * _Nonnull)url content:(NSString * _Nullable)content timeoutMillisecond:(int)timeout
    withCallback:(void(^ _Nullable)(int code, NSString* _Nullable data))callback;
@end