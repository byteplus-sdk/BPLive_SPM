//
//  BDLShareView.h
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


#import <BDLiveCommon/BDLPopupBaseView.h>
#import "BDLBasicService.h"
#import "BDLGetInviteTokenResponse.h"
#import "BDLGetShareInfoResponse.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 分享弹窗 view。
 */
/**
 * @locale en
 * @brief The sharing dialog box view.
 */
@interface BDLShareView : BDLPopupBottomShowBaseView <BDLBasicService>

/**
 * @locale zh
 * @brief 初始化。
 * @param shareInfo 分享信息。详见 [BDLGetShareInfoResult](1185544#BDLGetShareInfoResult)。
 * @param url 分享的 URL。如果 `shareInfo.customAddress` 为空，则分享该 URL。
 * @param inviteTokenModel 分享者信息。详见 [BDLGetInviteTokenResult](1185544#BDLGetInviteTokenResult)。<br>
 *         :::tip 如观众未登录直播间，则为空值。<br>
 *         :::
 * @list 其他
 * @return 分享弹窗 view 实例。
 */
/**
 * @locale en
 * @brief Initializes the instance of the sharing dialog box view.
 * @param shareInfo The sharing information. For more information, see [BDLGetShareInfoResult](viewer-sdk-for-ios-type-definitions#BDLGetShareInfoResult).
 * @param url The shared URL. If `shareInfo.customAddress` is `nil`, share this URL.
 * @param inviteTokenModel The sharer information. For more information, see [BDLGetInviteTokenResult](viewer-sdk-for-ios-type-definitions#BDLGetInviteTokenResult).
 *        :::tip The value is `nil` if the viewer does not log in to the live room.
 *        :::
 * @return The instance of the sharing dialog box view.
 */
- (instancetype)initWithShareInfo:(BDLGetShareInfoResult *)shareInfo url:(NSString *)url inviteTokenModel:(BDLGetInviteTokenResult *)inviteTokenModel;

/**
 * @locale zh
 * @brief 分享的 URL。由初始化方法 [initWithShareInfo:url:inviteTokenModel:](#BDLShareView-initwithshareinfo-url-invitetokenmodel) 传入。
 */
/**
 * @locale en
 * @brief The shared URL, which is passed in through the initialization method [initWithShareInfo:url:inviteTokenModel:](#BDLShareView-initwithshareinfo-url-invitetokenmodel).
 */
@property (nonatomic, strong, readonly, nullable) NSString *url;
/**
 * @locale zh
 * @brief 分享信息。由初始化方法 [initWithShareInfo:url:inviteTokenModel:](#BDLShareView-initwithshareinfo-url-invitetokenmodel) 传入。
 */
/**
 * @locale en
 * @brief The sharing information, which is passed in through the initialization method [initWithShareInfo:url:inviteTokenModel:](#BDLShareView-initwithshareinfo-url-invitetokenmodel).
 */
@property (nonatomic, strong, readonly) BDLGetShareInfoResult *shareInfo;
/**
 * @locale zh
 * @brief 分享者信息。由初始化方法 [initWithShareInfo:url:inviteTokenModel:](#BDLShareView-initwithshareinfo-url-invitetokenmodel) 传入。
 */
/**
 * @locale en
 * @brief The sharer information, which is passed in through the initialization method [initWithShareInfo:url:inviteTokenModel:](#BDLShareView-initwithshareinfo-url-invitetokenmodel).
 */
@property (nonatomic, strong, readonly, nullable) BDLGetInviteTokenResult *inviteTokenModel;
/**
 * @locale zh
 * @brief 保存按钮。不支持自定义 `Normal` 状态的文字。
 */
/**
 * @locale en
 * @brief The save button. The `text` in the `Normal` status cannot be customized.
 */
@property (nonatomic, strong, readonly) UIButton *saveButton;
/**
 * @locale zh
 * @brief 海报按钮。不支持自定义 `Normal` 状态的文字。
 */
/**
 * @locale en
 * @brief The poster button. The `text` in the `Normal` status cannot be customized.
 */
@property (nonatomic, strong, readonly) UIButton *inviteButton;
/**
 * @locale zh
 * @brief 复制链接按钮。不支持自定义 `Normal` 状态的文字。
 */
/**
 * @locale en
 * @brief The copy link button. The `text` in the `Normal` status cannot be customized.
 */
@property (nonatomic, strong, readonly) UIButton *linkButton;
/**
 * @locale zh
 * @brief 二维码按钮。不支持自定义 `Normal` 状态的文字。
 */
/**
 * @locale en
 * @brief The QR code button. The `text` in the `Normal` status cannot be customized.
 */
@property (nonatomic, strong, readonly) UIButton *qrCodeButton;
/**
 * @locale zh
 * @brief 取消按钮。不支持自定义 `Normal` 状态的文字。
 */
/**
 * @locale en
 * @brief The cancel button. The `text` in the `Normal` status cannot be customized.
 */
@property (nonatomic, strong, readonly) UIButton *cancelButton;

/**
 * @locale zh
 * @brief 海报按钮点击回调。
 * @param view 分享弹窗 view。
 * @list 其他
 */
/**
 * @locale en
 * @brief The callback is triggered when the poster button is tapped.
 * @param view The sharing dialog box view.
 */
@property (nonatomic, copy, nullable) void (^onInviteButtonClickBlock)(BDLShareView *view);
/**
 * @locale zh
 * @brief 复制链接按钮点击回调。
 * @param view 分享弹窗 view。
 * @list 其他
 */
/**
 * @locale en
 * @brief The callback is triggered when the copy link button is tapped.
 * @param view The sharing dialog box view.
 */
@property (nonatomic, copy, nullable) void (^onCopyLinkButtonClickBlock)(BDLShareView *view);
/**
 * @locale zh
 * @brief 二维码按钮点击回调。
 * @param view 分享弹窗 view。
 * @list 其他
 */
/**
 * @locale en
 * @brief The callback is triggered when the QR code button is tapped.
 * @param view The sharing dialog box view.
 */
@property (nonatomic, copy, nullable) void (^onQRCodeButtonClickBlock)(BDLShareView *view);

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
