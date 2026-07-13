//
//  BDLMacros.h
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
#ifndef BDLMacros_h
#define BDLMacros_h

#import <Foundation/Foundation.h>

#define BDL_MULTI_LANGUAGE_HAS_CHECKED

#ifndef bdl_keywordify
    #if DEBUG
        #define bdl_keywordify autoreleasepool {}
    #else
        #define bdl_keywordify try {} @catch (...) {}
    #endif
#endif

#ifndef bdl_weakify
    #if __has_feature(objc_arc)
        #define bdl_weakify(object) bdl_keywordify __weak __typeof__(object) weak##_##object = object
    #else
        #define bdl_weakify(object) bdl_keywordify __block __typeof__(object) block##_##object = object
    #endif
#endif

#ifndef bdl_strongify
    #if __has_feature(objc_arc)
        #define bdl_strongify(object) bdl_keywordify __typeof__(object) object = weak##_##object
    #else
        #define bdl_strongify(object) bdl_keywordify __typeof__(object) object = block##_##object
    #endif
#endif

#define bdl_return_if_nil(self) if (nil == self) return

#define bdl_assert_main_thread()  NSAssert([NSThread isMainThread], @"This method must be called on the main thread")
#define bdl_cassert_main_thread() NSCAssert([NSThread isMainThread], @"This method must be called on the main thread")
#define bdl_assert_main_queue(q)  NSAssert(q == dispatch_get_main_queue(), @"q must be the main queue")
#define bdl_cassert_main_queue(q) NSCAssert(q == dispatch_get_main_queue(), @"q must be the main queue")

#define BDL_FLT_EPSILON  0.000001

#ifdef DEBUG
    //#define BDLLog(fmt, ...) NSLog((@" %.1f " fmt), [[NSDate date] timeIntervalSince1970], ##__VA_ARGS__);
    #define BDLLog(fmt, ...) NSLog(fmt, ##__VA_ARGS__);
#else
    #define BDLLog(fmt, ...) 
#endif

#if BDL_CN
    #define BDL_FEATURE_MULTI_AWARD 1
    #define BDL_FEATURE_LANDSCAPE_CART_ICON_SHOW  1
#elif BDL_SG
    #define BDL_FEATURE_MULTI_AWARD 0
#endif

#endif
