//
//  TTHTTPRequestSerializerBase.h
//  TTNetworkManager
//
//  The TTNetworkManager is licensed under the MIT License.
//  Copyright (c) 2023 Bytedance Inc.
//
//  Interface and base class for network request serialization

#import "TTHTTPRequestSerializerProtocol.h"
NS_ASSUME_NONNULL_BEGIN
@interface TTHTTPRequestSerializerBase : NSObject<TTHTTPRequestSerializerProtocol>

+ (TTHttpRequest *)hashRequest:(TTHttpRequest *)request body:(NSData *)body;
NS_ASSUME_NONNULL_END
@end
