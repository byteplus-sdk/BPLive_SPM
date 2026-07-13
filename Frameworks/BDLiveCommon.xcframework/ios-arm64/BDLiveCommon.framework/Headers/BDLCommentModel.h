//
//  BDLCommentModel.h
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
#import <UIKit/UIKit.h>

#import <BDLiveBase/BDLBaseModel.h>
#import "BDLDefines.h"
#import "BDLCommentUserModel.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

/**
 * @locale zh
 * @type keytype
 * @brief 评论发送状态。
 */
/**
 * @locale en
 * @type keytype
 * @brief The sending status of comments.
 */
typedef NS_ENUM(NSInteger, BDLCommentSendState) {
/**
 * @locale zh
 * @brief 默认值，可认为是服务端获取到的数据。不需要显示 loading 或失败图标。
 */
   /**
    * @locale en
    * @brief The default value, considered as data returned by the BytePlus Live server. No need to display loading or failure icon.
    */
    BDLCommentSendStateDefault,
/**
 * @locale zh
 * @brief 正在发送中，显示 loading。
 */
   /**
    * @locale en
    * @brief The comment is being sent, with loading displayed.
    */
    BDLCommentSendStateIng,
/**
 * @locale zh
 * @brief 发送成功，不需要显示 loading。
 */
   /**
    * @locale en
    * @brief The comment is sent successfully, without the need to display loading.
    */
    BDLCommentSendStateSuccess,
/**
 * @locale zh
 * @brief 发送失败，显示失败的图标。
 */
   /**
    * @locale en
    * @brief Failed to send the comment, with the failure icon displayed.
    */
    BDLCommentSendStateFail,
/**
 * @locale zh
 * @brief 发送图片审核未通过，显示失败的图标。
 */
   /**
    * @locale en
    * @brief The image failed to be approved, with the failure icon displayed.
    * @hidden (iOS)
    */
    BDLCommentSendStateFailBySecurity,
};

/**
 * @locale zh
 * @type keytype
 * @brief 评论类型。
 */
/**
 * @locale en
 * @type keytype
 * @brief The comment type.
 */
typedef NS_ENUM(NSInteger, BDLCommentType) {
    /**
     * @locale zh
     * @brief 来自服务端的消息，默认值。
     */
   /**
    * @locale en
    * @brief The message from the server, which is the default value.
    */
    BDLCommentTypeMessage,
    /**
     * @locale zh
     * @brief 聊天欢迎语。
     */
   /**
    * @locale en
    * @brief The welcome message.
    */
    BDLCommentTypeWelcome,
    /**
     * @locale zh
     * @brief 直播间描述信息。
     */
   /**
    * @locale en
    * @brief The live room description.
    */
    BDLCommentTypeLiveDescription,
};

/**
 * @locale zh
 * @type keytype
 * @brief 评论公共信息 Model。
 */
/**
 * @locale en
 * @type keytype
 * @brief The model of public comment information.
 */
@interface BDLCommentCommonModel : BDLBaseModel

/**
 * @locale zh
 * @brief 评论 ID。
 */
/**
 * @locale en
 * @brief The comment ID.
 */
@property (nonatomic, strong) NSNumber *msgId;
/**
 * @locale zh
 * @brief 创建时间。Unix 秒级时间戳。
 */
/**
 * @locale en
 * @brief The creation time in Unix timestamp format. Unit: seconds.
 */
@property (nonatomic, assign) long createTime;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 评论额外信息 Model。
 */
/**
 * @locale en
 * @type keytype
 * @brief The additional information model of comments.
 */
@interface BDLCommentExtraModel: BDLBaseModel

/**
 * @locale zh
 * @brief 发送评论的用户。详见 [BDLCommentUserModel](#BDLCommentUserModel)。
 */
/**
 * @locale en
 * @brief The user who sent the comment. For more information, see [BDLCommentUserModel](#BDLCommentUserModel).
 */
@property (nonatomic, strong) BDLCommentUserModel *user;
/**
 * @locale zh
 * @brief 评论内容。如果为图片类型，则为图片的 URL。
 */
/**
 * @locale en
 * @brief The comment content.
 */
@property (nonatomic, copy) NSString *textContent;
/**
 * @locale zh
 * @brief 评论内容对应的中文。
 */
/**
 * @locale en
 * @brief The comment content in Chinese.
 */
@property (nonatomic, copy) NSString *textContentCn;
/**
 * @locale zh
 * @brief 评论内容对应的英文。
 */
/**
 * @locale en
 * @brief The comment content in English.
 */
@property (nonatomic, copy) NSString *textContentEn;
/**
 * @locale zh
 * @brief 评论内容对应的日文。
 */
/**
 * @locale en
 * @brief The comment content in Japanese.
 */
@property (nonatomic, copy) NSString *textContentJp;
/**
 * @locale zh
 * @brief 是否为主持人发送的评论。
 *        - `YES`：主持人发送的评论。
 *        - `NO`：非主持人发送的评论。
 */
/**
 * @locale en
 * @brief Whether the comment is sent by the host.
 *        - `YES`: The host.
 *        - `NO`: Not the host.
 */
@property (nonatomic, assign) BOOL isPresenter;
/**
 * @locale zh
 * @brief 评论内容类型。详见 [BDLMessageContentType](#BDLMessageContentType)。
 */
/**
 * @locale en
 * @brief The type of comment content. For more information, see [BDLMessageContentType](#BDLMessageContentType).
 */
@property (nonatomic, assign) BDLMessageContentType contentType;
/**
 * @locale zh
 * @brief 图片评论的缩略图地址。
 */
/**
 * @locale en
 * @hidden (iOS)
 * @brief Thumbnail URL for the image comment.
 */
@property (nonatomic, copy) NSArray<NSString *> *textContentExtra;
/**
 * @locale zh
 * @brief 评论 ID。非企业直播服务端返回数据。
 */
/**
 * @locale en
 * @brief The comment ID. Not returned by the BytePlus Live server.
 */
@property (nonatomic, copy) NSString *localId;
/**
 * @locale zh
 * @brief 评论是否已删除。
 *        - `YES`：已删除。
 *        - `NO`：未删除。
 */
/**
 * @locale en
 * @brief Whether the comment is deleted.
 *        - `YES`: Deleted.
 *        - `NO`: Not deleted.
 */
@property (nonatomic, assign) BOOL isDeleted;
/**
 * @locale zh
 * @brief 自己是否点赞了该评论。
 *        - `YES`：点赞了。
 *        - `NO`：未点赞。
 */
/**
 * @locale en
 * @brief Whether the comment is liked by the user themselves.
 *        - `YES`: Liked.
 *        - `NO`: Not liked.
 */
@property (nonatomic, assign) BOOL isSelfLiked;
/**
 * @locale zh
 * @brief 该评论的点赞数。
 */
/**
 * @locale en
 * @brief The number of likes for the comment.
 */
@property (nonatomic, assign) NSInteger likeCount;

// MARK: - 本地数据
/**
 * @locale zh
 * @brief 用户发送图片评论的图片。非企业直播服务端返回数据。
 */
/**
 * @locale en
 * @hidden (iOS)
 * @brief The image sent as a comment by the user. Data not returned by the enterprise live server.
 */
@property (nonatomic, strong) UIImage *localImage;
/**
 * @locale zh
 * @brief 评论发送状态。详见 [BDLCommentSendState](#BDLCommentSendState)。非企业直播服务端返回数据。
 */
/**
 * @locale en
 * @brief The comment sending status. Not returned by the BytePlus Live server. For more information, see [BDLCommentSendState](#BDLCommentSendState).
 */
@property (nonatomic, assign) BDLCommentSendState localSendState;

/**
 * @locale zh
 * @brief 根据语言类型获取对应的评论内容。
 * @param type 语言类型。详见 [BDLLanguageType](#BDLLanguageType)。
 * @return 对应语言的评论内容。
 */
/**
 * @locale en
 * @brief Gets the corresponding comment content according to the language type.
 * @param type The language type. For more information, see [BDLLanguageType](#BDLLanguageType).
 * @return The comment content in the corresponding language.
 */
- (NSString *)textContentForType:(BDLLanguageType)type;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 评论 Model。
 */
/**
 * @locale en
 * @type keytype
 * @brief The comment model.
 */
@interface BDLCommentModel: BDLBaseModel

/**
 * @locale zh
 * @brief 评论类型。非企业直播服务端返回数据。
 */
/**
 * @locale en
 * @brief The comment type. Not returned by the BytePlus Live server.
 */
@property (nonatomic, assign) BDLCommentType localCommentType;
/**
 * @locale zh
 * @brief 评论公共信息 Model。详见 [BDLCommentCommonModel](#BDLCommentCommonModel)。
 */
/**
 * @locale en
 * @brief The model of public comment information. For more information, see [BDLCommentCommonModel](#BDLCommentCommonModel).
 */
@property (nonatomic, strong) BDLCommentCommonModel *common;
/**
 * @locale zh
 * @brief 评论额外信息 Model。详见 [BDLCommentExtraModel](#BDLCommentExtraModel)。
 */
/**
 * @locale en
 * @brief The model of additional comment information. For more information, see [BDLCommentExtraModel](#BDLCommentExtraModel).
 */
@property (nonatomic, strong) BDLCommentExtraModel *extra;

/**
 * @locale zh
 * @brief 缓存的需要显示的富文本。非企业直播服务端返回数据。
 */
/**
 * @locale en
 * @brief The cached rich text to be displayed. Not returned by the BytePlus Live server.
 */
@property (nonatomic, copy) NSAttributedString *localShowAttributedString;
/**
 * @locale zh
 * @brief 缓存的可点击区域。非企业直播服务端返回数据。
 */
/**
 * @locale en
 * @brief The cached clickable area. Not returned by the BytePlus Live server.
 */
@property (nonatomic, copy) NSArray *localClickableRanges;

@end

#pragma clang diagnostic pop
