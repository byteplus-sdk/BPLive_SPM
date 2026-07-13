//
//  BDLAudienceLinkMenuView.h
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
 * @type keytype
 * @brief 连麦按钮类型。
 */
/**
 * @locale en
 * @type keytype
 * @hidden (iOS)
 * @brief Type of join audio button.
 */
typedef NS_ENUM(NSInteger, BDLAudienceLinkMenuViewButtonTag) {
/**
 * @locale zh
 * @brief 翻转摄像头。
 */
   /**
    * @locale en
    * @brief Flip the camera.
    */
    BDLAudienceLinkMenuViewButtonTagSwitchCamera,
/**
 * @locale zh
 * @brief 静音或取消静音。
 */
   /**
    * @locale en
    * @brief Mute or unmute.
    */
    BDLAudienceLinkMenuViewButtonTagAudioSwitch,
/**
 * @locale zh
 * @brief 打开摄像头或关闭摄像头。
 */
   /**
    * @locale en
    * @brief Turn on the camera or turn off the camera.
    */
    BDLAudienceLinkMenuViewButtonTagVideoSwitch,
/**
 * @locale zh
 * @brief 断开连麦。
 */
   /**
    * @locale en
    * @brief Disconnect from the microphone.
    */
    BDLAudienceLinkMenuViewButtonTagEndLink,
};

/**
 * @locale zh
 * @type api
 * @brief 连麦菜单选项 view。
 */
/**
 * @locale en
 * @brief Options for co-hosting view.
 * @hidden (iOS)
 */
@interface BDLAudienceLinkMenuView : BDLPopupBottomShowBaseView <BDLLanguageService>

/**
 * @locale zh
 * @brief 包含选项的容器 view。<br>可通过 `containerView.arrangedSubviews` 获取到选项按钮(UIButton)。可通过 `tag` 区分不同的按钮、通过 `button.select` 设置按钮的选中与未选中状态。其中静音按钮的选中状态为取消静音按钮，摄像头按钮的选中状态为打开摄像头按钮、未选中状态为关闭摄像头按钮，翻转摄像头和断开连麦按钮无选中状态的变化。不支持自定义 `Normal` 状态的文字。
 */
/**
 * @locale en
 * @brief Container view with options.<br>Options buttons (UIButton) can be accessed via `containerView.arrangedSubviews`. Different buttons can be distinguished using `tag`, and button selection states can be set using `button.select`. The mute button's selected state represents the unmute button, while the camera button's selected state represents the open camera button and the unselected state represents the close camera button. The flip camera and disconnect buttons do not have selectable state changes. Custom text for the `Normal` state is not supported.
 */
@property (nonatomic, strong, readonly) UIStackView *containerView;
/**
 * @locale zh
 * @brief 选项按钮和取消按钮之间的分割线。
 */
/**
 * @locale en
 * @brief The divider between the option button and the cancel button.
 */
@property (nonatomic, strong, readonly) UIView *sepLine;
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
 * @brief The current language type. See [BDLLanguageType](viewer-sdk-for-ios-type-definitions#BDLLanguageType) for details.
 */
@property (nonatomic, assign, readonly) BDLLanguageType langType;
/**
 * @locale zh
 * @brief 翻转摄像头按钮点击回调。
 * @param view 连麦菜单选项 view。
 * @param button 翻转摄像头按钮。
 */
/**
 * @locale en
 * @brief Callback for the camera flip button click.
 * @param view Co-hosting menu options view.
 * @param button Flip Camera Button.
 */
@property (nonatomic, copy, nullable) void(^onSwitchCameraClickCallback)(BDLAudienceLinkMenuView *view, UIButton *button);
/**
 * @locale zh
 * @brief 静音或取消静音按钮点击回调。
 * @param view 连麦菜单选项 view。
 * @param button 静音或取消静音按钮。
 */
/**
 * @locale en
 * @brief Callback for mute or unmute button click.
 * @param view Option view for joining a call.
 * @param button Mute or unmute button.
 */
@property (nonatomic, copy, nullable) void(^onAudioClickCallback)(BDLAudienceLinkMenuView *view, UIButton *button);
/**
 * @locale zh
 * @brief 打开摄像头或关闭摄像头按钮点击回调。
 * @param view 连麦菜单选项 view。
 * @param button 打开摄像头或关闭摄像头按钮。
 */
/**
 * @locale en
 * @brief Callback for the camera toggle button.
 * @param view Live Stream Interaction Menu Options View.
 * @param button Open Camera or Close Camera Button.
 */
@property (nonatomic, copy, nullable) void(^onVideoClickCallback)(BDLAudienceLinkMenuView *view, UIButton *button);
/**
 * @locale zh
 * @brief 断开连麦按钮点击回调。
 * @param view 连麦菜单选项 view。
 * @param button 断开连麦按钮。
 */
/**
 * @locale en
 * @brief Callback for the disconnect button click.
 * @param view Options for Real-time Communication View.
 * @param button Disconnect Co-host Button.
 */
@property (nonatomic, copy, nullable) void(^onExitClickCallback)(BDLAudienceLinkMenuView *view, UIButton *button);
/**
 * @locale zh
 * @brief 取消按钮点击回调。
 * @param view 连麦菜单选项 view。
 * @param button 取消按钮。
 */
/**
 * @locale en
 * @brief Callback for cancel button click.
 * @param view Options for the co-broadcasting menu view.
 * @param button Cancel button.
 */
@property (nonatomic, copy, nullable) void(^onCancelClickCallback)(BDLAudienceLinkMenuView *view, UIButton *button);

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
