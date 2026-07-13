//
//  BDLFeatureMacros.h
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
#ifndef BDLFeatureMacros_h
#define BDLFeatureMacros_h

#import <Foundation/Foundation.h>

#ifdef BDL_CN
    #define BDL_FEATURE_STREAMING_ACCOUNT  0
    #define BDL_FEATURE_PORTRAIT_COVER_IMAGE  0
    #define BDL_FEATURE_STREAMING_LINE_IN_USE  1
    #define BDL_FEATURE_CHANGE_TOKEN_NEW_API 1
    #define BDL_FEATURE_VERTICAL_COVER_IMAGE 0
    #define BDL_FEATURE_PRODUCT_CARD_MULTI_LANG 0
    #define BDL_FEATURE_STREAMING_LIVE_AUDIT 1
    #define BDL_TTSDK_1_46_2 0
    #define BDL_AWARD_CONTACT_EMAIL 1 ///< 中奖支持email
#elif BDL_SG
    /// 开播account相关
    #define BDL_FEATURE_STREAMING_ACCOUNT  1
    #define BDL_FEATURE_PORTRAIT_COVER_IMAGE  1
    /// 开播占用，直播间断流时间相关
    #define BDL_FEATURE_STREAMING_LINE_IN_USE  0
    #define BDL_FEATURE_CHANGE_TOKEN_NEW_API 0
    #define BDL_FEATURE_VERTICAL_COVER_IMAGE 1 ///< 竖屏封面
    #define BDL_FEATURE_PRODUCT_CARD_MULTI_LANG 1
    #define BDL_FEATURE_STREAMING_LIVE_AUDIT 0
    #define BDL_TTSDK_1_46_2 0
    #define BDL_AWARD_CONTACT_EMAIL 0
#endif

#endif
