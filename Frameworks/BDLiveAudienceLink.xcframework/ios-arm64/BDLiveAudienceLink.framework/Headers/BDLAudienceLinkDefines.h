//
//  BDLAudienceLinkDefines.h
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

/**
 * @locale zh
 * @brief 本地的观众连麦状态。
 * @type keytype
 */
/**
 * @locale en
 * @type keytype
 * @hidden (iOS)
 */
typedef NS_ENUM(NSInteger, BDLAudienceLinkState) {
    /**
     * @locale zh
     * @brief 未知。该状态仅在从未从企业直播服务端进行过同步时出现。
     */
    BDLAudienceLinkStateUnknown,
    /**
     * @locale zh
     * @brief 未连麦。
     */
    BDLAudienceLinkStateUnlinked,
    /**
     * @locale zh
     * @brief 正在申请连麦中。
     */
    BDLAudienceLinkStateRinging,
    /**
     * @locale zh
     * @brief 连麦申请已通过，正在连麦中。
     */
    BDLAudienceLinkStateLinking,
    /**
     * @locale zh
     * @brief 已加入连麦。
     */
    BDLAudienceLinkStateLinked,
};
