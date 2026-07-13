//
//  BDLSendActivityMessageResponse.h
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
#import <BDLiveBase/BDLBaseResponse.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

/**
 * @locale zh
 * @type keytype
 * @brief 发送评论后的状态。
 */
/**
 * @locale en
 * @type keytype
 * @brief The status after sending a comment.
 */
typedef NS_ENUM(NSInteger, BDLSendMessageResultStatus) {
    /**
     * @locale zh
     * @brief 发送成功。
     */
   /**
    * @locale en
    * @brief Sent successfully.
    */
    BDLSendMessageResultStatusSuccess = 1,
    /**
     * @locale zh
     * @brief 图片资源 URL 校验错误，即图片不存在或图片不属于当前账号。
     */
   /**
    * @locale en
    * @brief The image resource URL validation error occurred, meaning the image does not exist or does not belong to the current account.
    */
    BDLSendMessageResultStatusImgUriError,
    /**
     * @locale zh
     * @brief 安全审核接口报错，可重试。
     */
   /**
    * @locale en
    * @brief Security review API error. Retry.
    */
    BDLSendMessageResultStatusSecurityAuditError,
    /**
     * @locale zh
     * @brief 未通过安全审核。
     */
   /**
    * @locale en
    * @brief Failed to pass the security review.
    */
    BDLSendMessageResultStatusSecurityAuditNotSafe,
};

/**
 * @locale zh
 * @type keytype
 * @brief 评论发送成功后的结果。
 */
/**
 * @locale en
 * @type keytype
 * @brief The result after comments are successfully sent.
 */
@interface BDLSendActivityMessageResult : BDLBaseModel

/**
 * @locale zh
 * @brief 评论 ID。
 */
/**
 * @locale en
 * @brief The comment ID.
 */
@property (nonatomic, copy) NSString *H5MsgId;
/**
 * @locale zh
 * @brief 发送评论的用户昵称。
 */
/**
 * @locale en
 * @brief The nickname of the user who sent the comment.
 */
@property (nonatomic, copy) NSString *nickname;
/**
 * @locale zh
 * @brief 发送评论后企业直播服务端返回的状态。详见 [BDLSendMessageResultStatus](#BDLSendMessageResultStatus)。
 */
/**
 * @locale en
 * @brief The status after comments are sent, which is returned by the BytePlus Live server. For more information, see [BDLSendMessageResultStatus](#BDLSendMessageResultStatus).
 */
@property (nonatomic, assign) BDLSendMessageResultStatus status;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 发送评论后企业直播服务端返回的结果。
 */
/**
 * @locale en
 * @type keytype
 * @brief The result after comments are sent, which is returned by the BytePlus Live server.
 */
@interface BDLSendActivityMessageResponse : BDLBaseResponse

/**
 * @locale zh
 * @brief 发送评论的结果。详见 [BDLSendActivityMessageResult](#BDLSendActivityMessageResult)。
 */
/**
 * @locale en
 * @brief The result of sending comments. For more information, see [BDLSendActivityMessageResult](#BDLSendActivityMessageResult).
 */
@property (nonatomic, strong) BDLSendActivityMessageResult *result;

@end

#pragma clang diagnostic pop

