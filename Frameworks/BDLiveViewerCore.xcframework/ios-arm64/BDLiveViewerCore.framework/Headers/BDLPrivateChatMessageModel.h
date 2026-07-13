//
//  BDLPrivateChatMessageModel.h
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

#import <BDLiveBase/BDLBaseModel.h>
#import <BDLiveCommon/BDLDefines.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type keytype
 * @brief 私聊消息 Model。
 */
/**
 * @locale en
 * @type keytype
 * @hidden (iOS)
 * @brief Direct Message Model.
 */
@interface BDLPrivateChatMessageModel : BDLBaseModel
/**
 * @locale zh
 * @brief ID。
 */
/**
 * @locale en
 * @brief ID.
 */
@property (nonatomic, assign) NSInteger Id;
/**
 * @locale zh
 * @brief 消息 ID。
 */
/**
 * @locale en
 * @brief Message ID.
 */
@property (nonatomic, assign) NSInteger msgId;
/**
 * @locale zh
 * @brief 消息内容。
 */
/**
 * @locale en
 * @brief Message content.
 */
@property (nonatomic, copy) NSString *textContent;
/**
 * @locale zh
 * @brief 发送消息的 UserID。
 */
/**
 * @locale en
 * @brief The UserID of the sender.
 */
@property (nonatomic, strong) NSNumber *from;
/**
 * @locale zh
 * @brief 接受消息的 UserID。
 */
/**
 * @locale en
 * @brief UserID of the recipient.
 */
@property (nonatomic, strong) NSNumber *to;
/**
 * @locale zh
 * @brief 消息内容类型。详见 [BDLMessageContentType](#BDLMessageContentType)。
 */
/**
 * @locale en
 * @brief Message content type. See [BDLMessageContentType](#BDLMessageContentType) for details.
 */
@property (nonatomic, assign) BDLMessageContentType contentType;

// MARK: - 以下字段为 接口返回数据特有
/**
 * @locale zh
 * @brief 昵称。
 */
/**
 * @locale en
 * @brief Nickname.
 */
@property (nonatomic, copy) NSString *nickname;
/**
 * @locale zh
 * @brief 创建时间。Unix 秒级时间戳。
 */
/**
 * @locale en
 * @brief Creation time. Unix timestamp in seconds.
 */
@property (nonatomic, assign) long long createTime;

// MARK: - 以下字段为长连接来的消息特有
/**
 * @locale zh
 * @brief 昵称。
 */
/**
 * @locale en
 * @brief Nickname.
 */
@property (nonatomic, copy) NSString *msgNickname;
/**
 * @locale zh
 * @brief 消息所在直播间的活动 ID。
 */
/**
 * @locale en
 * @brief The activity ID of the live room where the message is located.
 */
@property (nonatomic, strong) NSNumber *activityId;
/**
 * @locale zh
 * @brief 消息对应的 sessionId。
 */
/**
 * @locale en
 * @brief The sessionId corresponding to the message.
 */
@property (nonatomic, strong) NSNumber *sessionId;

// MARK: - 本地的数据
/**
 * @locale zh
 * @brief 是否为自己发送的消息。
 *        - `YES`：自己发送的消息。
 *        - `NO`：其他人发送的消息。
 */
/**
 * @locale en
 * @brief Indicates whether the message was sent by yourself.
 *        - `YES`: Message sent by yourself.
 *        - `NO`: Message sent by others.
 */
@property (nonatomic, assign) BOOL isSelfSend;
/**
 * @locale zh
 * @brief 头像 URL。
 */
/**
 * @locale en
 * @brief Avatar URL.
 */
@property (nonatomic, copy) NSString *avatarUrl;
/**
 * @locale zh
 * @brief 缓存的需要显示的富文本。非企业直播服务端返回数据。
 */
/**
 * @locale en
 * @brief Cached rich text content that needs to be displayed. Not returned by the enterprise live-streaming server.
 */
@property (nonatomic, copy, nullable) NSAttributedString *localShowAttributedString;
/**
 * @locale zh
 * @brief 缓存的消息的可点击区域。非企业直播服务端返回数据。
 */
/**
 * @locale en
 * @brief The clickable area of the cached message. Not returned by the enterprise live streaming server.
 */
@property (nonatomic, copy) NSArray *localClickableRanges;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
