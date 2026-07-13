//
//  BDLAwardNoticeView.h
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
#import <BDLiveCommon/BDLLanguageService.h>
#import "BDLInteractiveToolModel.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 抽奖通知 view。
 */
/**
 * @locale en
 * @brief The lucky draw notification view.
 */
@interface BDLAwardNoticeView : UIView <BDLLanguageService>

/**
 * @locale zh
 * @brief 当前所有支持的语言类型。
 */
/**
 * @locale en
 * @brief All the currently supported language types.
 */
@property (nonatomic, copy, readonly) NSArray *langTypes;
/**
 * @locale zh
 * @brief 当前的语言类型。详见 [BDLLanguageType](1185544#BDLLanguageType)。
 */
/**
 * @locale en
 * @brief The current language type. For more information, see [BDLLanguageType](viewer-sdk-for-ios-type-definitions#BDLLanguageType).
 */
@property (nonatomic, assign, readonly) BDLLanguageType langType;
/**
 * @locale zh
 * @brief 背景图。可自定义任意属性。
 */
/**
 * @locale en
 * @brief The background image. All properties can be customized.
 */
@property (nonatomic, strong, readonly) UIImageView *bgImageView;
/**
 * @locale zh
 * @brief “直播间发起了一场抽奖”文案 label。不支持自定义 `text`。
 */
/**
 * @locale en
 * @brief The text label of "Lucky draw in progress". The `text` cannot be customized.
 */
@property (nonatomic, strong, readonly) UILabel *titleLabel;
/**
 * @locale zh
 * @brief 参与按钮。不支持自定义 `Normal` 状态的 `text`。
 */
/**
 * @locale en
 * @brief The participate button. The `text` in the `Normal` status cannot be customized.
 */
@property (nonatomic, strong, readonly) UIButton *participateButton;
/**
 * @locale zh
 * @brief 当前通知对应的抽奖信息。详见 [BDLInteractiveAwardModel](1185544#BDLInteractiveAwardModel)。
 */
/**
 * @locale en
 * @brief The lucky draw information corresponding to the current notification. For more information, see [BDLInteractiveAwardModel](viewer-sdk-for-ios-type-definitions#BDLInteractiveAwardModel).
 */
@property (nonatomic, strong) BDLInteractiveAwardModel *award;

/**
 * @locale zh
 * @brief 参与按钮点击回调。
 * @param view 抽奖通知 view。
 * @list 抽奖
 */
/**
 * @locale en
 * @brief The callback is triggered when the participate button is tapped.
 * @param view The lucky draw notification view.
 */
@property (nonatomic, copy) void(^onParticipateClickBlock)(BDLAwardNoticeView *view);

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
