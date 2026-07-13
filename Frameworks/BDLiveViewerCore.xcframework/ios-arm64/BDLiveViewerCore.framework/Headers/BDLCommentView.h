//
//  BDLCommentView.h
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


#import "BDLCommentInputBaseView.h"
#import <BDLiveCommon/BDLCommentModel.h>
#import "BDLNoticeService.h"
#import "BDLMessageSwitchService.h"
#import "BDLMoreOptionsController.h"
#import "BDLMenuItemsController.h"
#import <BDLiveCommon/BDLSendActivityMessageResponse.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN
/**
 * @locale zh
 * @type api
 * @brief 评论区 view。
 */
/**
 * @locale en
 * @brief The comment area view.
 */
@interface BDLCommentView : BDLCommentInputBaseView <BDLNoticeService, BDLMessageSwitchService>
/**
 * @locale zh
 * @brief 自定义更多选项弹窗 controller。
 * @param controller 更多选项弹窗 controller。详见 [BDLMoreOptionsController](1185544#BDLMoreOptionsController)。
 * @param view 评论区 view。
 * @list 评论/私聊
 */
/**
 * @locale en
 * @brief Customizes the controller of the more options dialog box.
 * @param view The comment area view.
 * @param controller The controller of the more options dialog box. For more information, see [BDLMoreOptionsController](viewer-sdk-for-ios-type-definitions#BDLMoreOptionsController).
 */
@property (nonatomic, copy) void (^customizeMoreOptionsController)(BDLCommentView *view, BDLMoreOptionsController *controller);
/**
 * @locale zh
 * @brief 评论中的链接点击回调。
 * @param commentView 评论、热门评论以及私聊共同的基类。详见 [BDLCommentBaseView](#BDLCommentBaseView)。
 * @param comment 评论 Model。详见 [BDLCommentModel](1185544#BDLCommentModel)。
 * @param url 点击的链接。
 * @list 评论/私聊
 */
/**
 * @locale en
 * @brief The callback is triggered when the URL in a comment is tapped.
 * @param commentView The common base class for comments and top comments. For more information, see [BDLCommentBaseView](#BDLCommentBaseView).
 * @param comment The comment model. For more information, see [BDLCommentModel](viewer-sdk-for-ios-type-definitions#BDLCommentModel).
 * @param url The tapped URL.
 */
@property (nonatomic, copy, nullable) void (^urlClickBlock)(__kindof BDLCommentBaseView *commentView, BDLCommentModel *comment, NSURL *url);
/**
 * @locale zh
 * @brief 昵称点击回调。
 * @param commentView 评论、热门评论以及私聊共同的基类。详见 [BDLCommentBaseView](#BDLCommentBaseView)。
 * @param comment 评论 Model。详见 [BDLCommentModel](1185544#BDLCommentModel)。
 * @list 评论/私聊
 */
/**
 * @locale en
 * @brief The callback is triggered when the nickname is tapped.
 * @param commentView The common base class for comments and top comments. For more information, see [BDLCommentBaseView](#BDLCommentBaseView).
 * @param comment The comment model. For more information, see [BDLCommentModel](viewer-sdk-for-ios-type-definitions#BDLCommentModel).
 */
@property (nonatomic, copy, nullable) void (^nicknameClickBlock)(__kindof BDLCommentBaseView *commentView, BDLCommentModel *comment);
/**
 * @locale zh
 * @brief 图片评论点击回调。
 * @param commentView 评论、热门评论以及私聊共同的基类。详见 [BDLCommentBaseView](#BDLCommentBaseView)。
 * @param comment 评论 Model。详见 [BDLCommentModel](1185544#BDLCommentModel)。
 * @list 评论/私聊
 */
/**
 * @locale en
 * @brief Callback for image comment clicks.
 * @param commentView The common base class for comments and top comments. For more information, see [BDLCommentBaseView](#BDLCommentBaseView).
 * @param comment The comment model. For more information, see [BDLCommentModel](viewer-sdk-for-ios-type-definitions#BDLCommentModel).
 * @hidden (iOS)
 */
@property (nonatomic, copy, nullable) void (^commentImageClickBlock)(__kindof BDLCommentBaseView *commentView, BDLCommentModel *comment);
/**
 * @locale zh
 * @brief 文字评论点击回调。
 * @param commentView 评论、热门评论以及私聊共同的基类。详见 [BDLCommentBaseView](#BDLCommentBaseView)。
 * @param comment 评论 Model。详见 [BDLCommentModel](1185544#BDLCommentModel)。
 */
/**
 * @locale en
 * @brief The callback is triggered when the text comment is tapped.
 * @param commentView The common base class for comments and top comments. For more information, see [BDLCommentBaseView](#BDLCommentBaseView).
 * @param comment The comment model. For more information, see [BDLCommentModel](viewer-sdk-for-ios-type-definitions#BDLCommentModel).
 */
@property (nonatomic, copy, nullable) void (^textContentClickBlock)(__kindof BDLCommentBaseView *commentView, BDLCommentModel *comment);
/**
 * @locale zh
 * @brief 评论区底部按钮的 controller。
 */
/**
 * @locale en
 * @brief The controller of the buttons at the bottom of the comment area.
 */
@property (nonatomic, strong, readonly) BDLMenuItemsController *menuItemsController;
/**
 * @locale zh
 * @brief 发送文字评论。发送评论成功或失败后，SDK 会触发对应的回调。
 * @param text 评论内容。
 * @param success 发送评论成功后触发的回调。<br>
 *         传入参数：发送评论后企业直播服务端返回的结果。详见 [BDLSendActivityMessageResponse](1185544#BDLSendActivityMessageResponse)。
 * @param failure 发送评论失败后触发的回调。<br>传入参数：错误信息。详见 [NSError](https://developer.apple.com/documentation/foundation/nserror?changes=l_1&language=objc)。
 */
/**
 * @locale en
 * @brief Sends a text comment. The SDK triggers the corresponding callback after the comment is successfully sent or failed to send.
 * @param text The comment content.
 * @param success The callback triggered when the comment is successfully sent.<br>
 *        Input parameters: The result after the comment is sent, which is returned by the BytePlus Live server. For more information, see [BDLSendActivityMessageResponse](viewer-sdk-for-ios-type-definitions#BDLSendActivityMessageResponse).
 * @param failure The callback triggered when the comment failed to send.<br>
 *        Input parameters: The error information. For more information, see [NSError](https://developer.apple.com/documentation/foundation/nserror?changes=l_1&language=objc).
 */
- (void)sendTextMessage:(NSString *)text
                success:(void (^)(BDLSendActivityMessageResponse *response))success
                failure:(void (^)(NSError *error))failure;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop

