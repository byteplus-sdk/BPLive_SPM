
//
//  TTPushMessageBaseObject.h
//  TTPushManager
//
//  The TTNetworkManager is licensed under the MIT License.
//  Copyright (c) 2023 Bytedance Inc.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@interface PushMessageBaseObject : NSObject

@property (nonatomic, assign) uint64_t sequenceId;
@property (nonatomic, assign) uint64_t logId;
@property (nonatomic, assign) int32_t method;
@property (nonatomic, assign) int32_t service;
@property (nonatomic, copy) NSData *payload;
@property (nullable, nonatomic, copy) NSString *payloadType;
@property (nullable, nonatomic, copy) NSString *payloadEncoding;
@property (nullable, nonatomic, copy) NSDictionary<NSString *, NSString *> *headers;

@end
NS_ASSUME_NONNULL_END
