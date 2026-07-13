//
//  BDLAudienceLinkExitWarningView.h
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
#import <BDLiveCommon/BDLLanguageService.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 退出观众连麦时的提示 view。
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@interface BDLAudienceLinkExitWarningView : BDLPopupBottomShowBaseView <BDLLanguageService>

/**
 * @locale zh
 * @brief “确认退出观众连麦吗？” 提示 label。不支持自定义 `text`。
 */
/**
 * @locale en
 * @brief Prompt label for 'Are you sure you want to disconnect from the audience mic?'. Custom `text` is not supported.
 */
@property (nonatomic, strong, readonly) UILabel *titleLabel;
/**
 * @locale zh
 * @brief “当前正在连麦中，关闭直播连麦将\n退出当前连麦” 提示 label。不支持自定义 `text`。
 */
/**
 * @locale en
 * @brief The message 'Currently in live interaction, ending the live stream will exit the current interaction' is used as a label. Custom `text` is not supported.
 */
@property (nonatomic, strong, readonly) UILabel *subTitleLabel;
/**
 * @locale zh
 * @brief [subTitleLabel](#BDLAudienceLinkExitWarningView-subtitlelabel) 和 [confirmButton](#BDLAudienceLinkExitWarningView-confirmbutton) 之间的分割线。
 */
/**
 * @locale en
 */
@property (nonatomic, strong, readonly) UIView *sepLine;
/**
 * @locale zh
 * @brief 确认按钮。不支持自定义 `Normal` 状态的文字。
 */
/**
 * @locale en
 * @brief Confirm button. Custom text for the `Normal` state is not supported.
 */
@property (nonatomic, strong, readonly) UIButton *confirmButton;
/**
 * @locale zh
 * @brief [confirmButton](#BDLAudienceLinkExitWarningView-confirmbutton) 和 [cancelButton](#BDLAudienceLinkExitWarningView-cancelbutton) 之间的灰色区域。
 */
/**
 * @locale en
 */
@property (nonatomic, strong, readonly) UIView *greyView;
/**
 * @locale zh
 * @brief 取消按钮。不支持自定义 `Normal` 状态的文字。
 */
/**
 * @locale en
 * @brief Cancel button. Custom text for the `Normal` state is not supported.
 */
@property (nonatomic, strong, readonly) UIButton *cancelButton;
/**
 * @locale zh
 * @brief 当前的语言类型。详见 [BDLLanguageType](1185544#BDLLanguageType)。
 */
/**
 * @locale en
 */
@property (nonatomic, assign, readonly) BDLLanguageType langType;

/**
 * @locale zh
 * @brief 确认按钮点击回调。
 * @param view 退出观众连麦时的提示 view。
 * @param button 确认按钮。
 */
/**
 * @locale en
 * @brief Callback for the confirmation button click.
 * @param view Prompt view when exiting audience co-hosting.
 * @param button Confirm button.
 */
@property (nonatomic, copy, nullable) void(^onConfirmClickCallback)(BDLAudienceLinkExitWarningView *view, UIButton *button);
/**
 * @locale zh
 * @brief 取消按钮点击回调。
 * @param view 退出观众连麦时的提示 view。
 * @param button 取消按钮。
 */
/**
 * @locale en
 * @brief Callback for cancel button click.
 * @param view Prompt view when exiting audience co-hosting.
 * @param button Cancel button.
 */
@property (nonatomic, copy, nullable) void(^onCancelClickCallback)(BDLAudienceLinkExitWarningView *view, UIButton *button);

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
