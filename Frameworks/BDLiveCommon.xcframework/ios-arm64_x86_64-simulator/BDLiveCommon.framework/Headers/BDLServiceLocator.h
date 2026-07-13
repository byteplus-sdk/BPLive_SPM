//
//  BDLServiceLocator.h
//
//  BPLive SDK License
//
//  Copyright 2022 Byteplus Pte. Ltd. All Rights Reserved.
//
//  The BPLive SDK was developed by Byteplus Pte. Ltd. (hereinafter “Byteplus”).
//  Any copyright or patent right is owned by and proprietary material of the Byteplus.
//
//  BPLive SDK is available under the Byteplus product and licensed under the commercial license.
//  Customers can contact via https://www.byteplus.com/en/contact for commercial licensing options.
//  Here is also a link to Service Level Agreement: https://docs.byteplus.com/en/byteplus-livesaas/docs/byteplus-live-service-level-agreement
//
//  Without Byteplus's prior written permission, any use of BPLive SDK, in particular any use for commercial purposes, is prohibited.
//  This includes, without limitation, incorporation in a commercial product, use in a commercial service, or production of other artefacts for commercial purposes.
//
//  Without Byteplus's prior written permission, the BPLive SDK may not be reproduced, modified and/or made available in any form to any third party.
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class BDLServiceLocator;
typedef id _Nullable (^BDLServiceProvider)(BDLServiceLocator *serviceLocator);

@interface BDLServiceLocator : NSObject

+ (instancetype)sharedInstance;

- (BOOL)registerService:(id)service;
- (BOOL)unregisterService:(id)service;
- (BOOL)registerService:(id)service forProtocol:(Protocol *)protocol;
- (BOOL)unregisterService:(id)service forProtocol:(Protocol *)protocol;
- (BOOL)registerClass:(Class)cls forProtocol:(Protocol *)protocol;
- (BOOL)unregisterClass:(Class)cls forProtocol:(Protocol *)protocol;
- (BOOL)registerProvider:(BDLServiceProvider)provider forProtocol:(Protocol *)protocol;
- (BOOL)unregisterProvider:(BDLServiceProvider)provider forProtocol:(Protocol *)protocol;

- (nullable NSArray *)servicesWithProtocol:(Protocol *)protocol;

- (NSUInteger)count;
- (void)clear;
- (void)dump;

@end

#define bdl_autowired(svc, proto) [[BDLServiceLocator sharedInstance] registerService:svc forProtocol:@protocol(proto)]
#define bdl_unwired(svc, proto) [[BDLServiceLocator sharedInstance] unregisterService:svc forProtocol:@protocol(proto)]
#define bdl_service(svc, proto) id<proto> svc = (id<proto>)[[BDLServiceLocator sharedInstance] servicesWithProtocol:@protocol(proto)].firstObject
#define bdl_multiservice(svcs, proto) NSArray<id<proto>> *svcs = [[BDLServiceLocator sharedInstance] servicesWithProtocol:@protocol(proto)]

NS_ASSUME_NONNULL_END
