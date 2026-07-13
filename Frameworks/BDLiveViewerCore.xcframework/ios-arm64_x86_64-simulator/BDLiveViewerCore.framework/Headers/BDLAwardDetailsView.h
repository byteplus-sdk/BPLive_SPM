//
//  BDLAwardDetailsView.h
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
#import "BDLAwardConditionView.h"
#import "BDLAwardNumberView.h"
#import "BDLAwardCountdownView.h"
#import <BDLiveCommon/BDLLanguageService.h>
#import "BDLInteractiveToolService.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 抽奖详情 view。
 */
/**
 * @locale en
 * @brief The lucky draw details view.
 */
@interface BDLAwardDetailsView : BDLPopupBottomShowBaseView <BDLLanguageService, BDLInteractiveToolService>

/**
 * @locale zh
 * @brief 初始化。
 * @param model 抽奖信息。详见 [BDLInteractiveAwardModel](1185544#BDLInteractiveAwardModel)。
 * @list 抽奖
 * @return 抽奖详情 view 实例。
 */
/**
 * @locale en
 * @brief Initializes the instance of the lucky draw details view.
 * @param model The lucky draw information. For more information, see [BDLInteractiveAwardModel](viewer-sdk-for-ios-type-definitions#BDLInteractiveAwardModel).
 * @return The instance of the lucky draw details view.
 */
- (instancetype)initWithModel:(BDLInteractiveAwardModel *)model;

/**
 * @locale zh
 * @brief 关闭按钮点击回调。
 * @param view 抽奖详情 view。
 * @list 抽奖
 */
/**
 * @locale en
 * @brief The callback is triggered when the close button is tapped.
 * @param view The lucky draw details view.
 */
@property (nonatomic, copy, nullable) void (^closeButtonClickedBlock)(BDLAwardDetailsView *view);
/**
 * @locale zh
 * @brief 参与按钮点击回调。
 * @param view 抽奖详情 view。
 * @list 抽奖
 */
/**
 * @locale en
 * @brief The callback is triggered when the participate button is tapped.
 * @param view The lucky draw details view.
 */
@property (nonatomic, copy, nullable) void (^participateButtonClickedBlock)(BDLAwardDetailsView *view);
/**
 * @locale zh
 * @brief 抽奖信息。由初始化方法 [initWithModel:](#BDLAwardDetailsView-initwithmodel) 传入。
 */
/**
 * @locale en
 * @brief The lucky draw information, which is passed in through the initialization method [initWithModel:](#BDLAwardDetailsView-initwithmodel).
 */
@property (nonatomic, strong, readonly) BDLInteractiveAwardModel *model;
/**
 * @locale zh
 * @brief 关闭按钮。支持自定义所有属性。
 */
/**
 * @locale en
 * @brief The close button. All properties can be customized.
 */
@property (nonatomic, strong, readonly) UIButton *closeButton;
/**
 * @locale zh
 * @brief 顶部的 imageView。支持自定义所有属性。
 */
/**
 * @locale en
 * @brief The top imageView. All properties can be customized.
 */
@property (nonatomic, strong, readonly) UIImageView *headerImageView;
/**
 * @locale zh
 * @brief 即将开奖 label。不支持自定义 `text`。
 */
/**
 * @locale en
 * @brief The about to draw label. All properties except `text` can be customized.
 */
@property (nonatomic, strong, readonly) UILabel *titleLabel;
/**
 * @locale zh
 * @brief 倒计时 view。详见 [BDLAwardCountdownView](#BDLAwardCountdownView)。
 */
/**
 * @locale en
 * @brief The countdown view. For more information, see [BDLAwardCountdownView](#BDLAwardCountdownView).
 */
@property (nonatomic, strong, readonly) BDLAwardCountdownView *countdownView;
/**
 * @locale zh
 * @brief 奖品信息 label。不支持自定义 `text`。
 */
/**
 * @locale en
 * @brief The prize information label. All properties except `text` can be customized.
 */
@property (nonatomic, strong, readonly) UILabel *awardLabel;
/**
 * @locale zh
 * @brief 奖品数量 label。不支持自定义 `text`。
 */
/**
 * @locale en
 * @brief The label for the number of prizes. All properties except `text` can be customized.
 */
@property (nonatomic, strong, readonly) UILabel *awardCountLabel;
/**
 * @locale zh
 * @brief 参与条件 view。详见 [BDLAwardConditionView](#BDLAwardConditionView)。
 */
/**
 * @locale en
 * @brief The participation condition view. For more information, see [BDLAwardConditionView](#BDLAwardConditionView).
 */
@property (nonatomic, strong, readonly, nullable) BDLAwardConditionView *conditionView;
/**
 * @locale zh
 * @brief 参与按钮。
 */
/**
 * @locale en
 * @brief The participate button.
 */
@property (nonatomic, strong, readonly) UIButton *participateButton;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
