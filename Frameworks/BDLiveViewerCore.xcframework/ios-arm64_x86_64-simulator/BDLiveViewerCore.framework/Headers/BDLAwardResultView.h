//
//  BDLAwardResultView.h
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
#import "BDLInteractiveToolModel.h"
#import "BDLAwardUserResponse.h"
#import "BDLLoadingView.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 抽奖结果 view。
 */
/**
 * @locale en
 * @brief The lucky draw result view.
 */
@interface BDLAwardResultView : BDLPopupCenterShowBaseView <BDLLanguageService>

/**
 * @locale zh
 * @brief 初始化。
 * @param awardModel 抽奖信息。详见 [BDLInteractiveAwardModel](1185544#BDLInteractiveAwardModel) 。
 * @param userModel 抽奖相关的观众信息 Model。详见 [BDLAwardUserModel](1185544#BDLAwardUserModel)。
 * @list 抽奖
 * @return 抽奖结果 view 实例。
 */
/**
 * @locale en
 * @brief Initializes the instance of the lucky draw result view.
 * @param awardModel The lucky draw information. For more information, see [BDLInteractiveAwardModel](viewer-sdk-for-ios-type-definitions#BDLInteractiveAwardModel).
 * @param userModel The model of lucky draw-related viewer information. For more information, see [BDLAwardUserModel](viewer-sdk-for-ios-type-definitions#BDLAwardUserModel).
 * @return The instance of the lucky draw result view.
 */
- (instancetype)initWithAwardModel:(BDLInteractiveAwardModel *)awardModel userModel:(BDLAwardUserModel *)userModel;
/**
 * @locale zh
 * @brief 关闭按钮点击回调。
 * @param view 抽奖结果 view。
 * @list 抽奖
 */
/**
 * @locale en
 * @brief The callback is triggered when the close button is tapped.
 * @param view The lucky draw result view.
 */
@property (nonatomic, copy) void (^closeButtonClickedBlock)(BDLAwardResultView *view);
/**
 * @locale zh
 * @brief 中奖观众的完善中奖信息按钮点击回调，或未中奖观众的知道了按钮点击回调。<br>
 *         :::tip
 *        可通过调用 [shouldShowAwardContactEntrance](#BDLAwardResultView-shouldshowawardcontactentrance) 判断是否为完善中奖信息按钮。<br>
 *         :::
 * @param view 抽奖结果 view。
 * @list 抽奖
 */
/**
 * @locale en
 * @brief The callback is triggered when the update personal information button is tapped by winners or the got it button is tapped by viewers without winning prizes.
 *         :::tip
 *        You can call [shouldShowAwardContactEntrance](#BDLAwardResultView-shouldshowawardcontactentrance) to determine if the button is for updating personal information.
 *         :::
 * @param view The lucky draw result view.
 */
@property (nonatomic, copy) void (^completeInfoButtonClickedBlock)(BDLAwardResultView *view);
/**
 * @locale zh
 * @brief 查看中奖结果按钮点击回调。
 * @param view 抽奖结果 view。
 * @list 抽奖
 */
/**
 * @locale en
 * @brief The callback is triggered when the view results button is tapped.
 * @param view The lucky draw result view.
 */
@property (nonatomic, copy) void (^awardWinnersButtonClickedBlock)(BDLAwardResultView *view);
/**
 * @locale zh
 * @brief 抽奖信息。由初始化方法 [initWithAwardModel:userModel:](#BDLAwardResultView-initwithawardmodel-usermodel) 传入。
 */
/**
 * @locale en
 * @brief The lucky draw information, which is passed in through the initialization method [initWithAwardModel:userModel:](#BDLAwardResultView-initwithawardmodel-usermodel).
 */
@property (nonatomic, strong, readonly) BDLInteractiveAwardModel *awardModel;
/**
 * @locale zh
 * @brief 抽奖相关的观众信息 Model。由初始化方法 [initWithAwardModel:userModel:](#BDLAwardResultView-initwithawardmodel-usermodel) 传入。
 */
/**
 * @locale en
 * @brief The model of lucky draw-related viewer information, which is passed in through the initialization method [initWithAwardModel:userModel:](#BDLAwardResultView-initwithawardmodel-usermodel).
 */
@property (nonatomic, strong, readonly) BDLAwardUserModel *userModel;
/**
 * @locale zh
 * @brief imageView。不支持自定义 `image`。
 */
/**
 * @locale en
 * @brief imageView. All properties except `image` can be customized.
 */
@property (nonatomic, strong, readonly) UIImageView *imageView;
/**
 * @locale zh
 * @brief “恭喜你，获得奖品”或“很遗憾，你没有中奖”文案的 label。不支持自定义 `text`。
 */
/**
 * @locale en
 * @brief The text label of "Congratulations, you won the prize" or "Sorry, you did not win". All properties except `text` can be customized.
 */
@property (nonatomic, strong, readonly) UILabel *titleLabel;
/**
 * @locale zh
 * @brief 完善中奖信息按钮或知道了按钮。不支持自定义 `Normal` 状态的文字。
 */
/**
 * @locale en
 * @brief The update personal information button or got it button. The `text` in the `Normal` status cannot be customized.
 */
@property (nonatomic, strong, readonly) UIButton *completeInfoButton;
/**
 * @locale zh
 * @brief 查看中奖结果按钮。不支持自定义 `Normal` 状态的文字。
 */
/**
 * @locale en
 * @brief The view results button. The `text` in the `Normal` status cannot be customized.
 */
@property (nonatomic, strong, readonly) UIButton *awardWinnersButton;
/**
 * @locale zh
 * @brief 奖品条款 label。不支持自定义 `text`。
 */
/**
 * @locale en
 * @brief The prize terms label. All properties except `text` can be customized.
 */
@property (nonatomic, strong, readonly) UILabel *termsLabel;
/**
 * @locale zh
 * @brief 关闭按钮。支持自定义。
 */
/**
 * @locale en
 * @brief The close button. Customization is supported.
 */
@property (nonatomic, strong, readonly) UIButton *closeButton;

/**
 * @locale zh
 * @brief 是否显示完善中奖信息入口。
 * @list 抽奖
 * @return - `YES`：显示完善中奖信息入口。
 *         - `NO`：不显示完善中奖信息入口。
 */
/**
 * @locale en
 * @brief Whether to display the entry for updating personal information.
 * @return - `YES`: Display.
 *         - `NO`: Do not display.
 */
- (BOOL)shouldShowAwardContactEntrance;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
