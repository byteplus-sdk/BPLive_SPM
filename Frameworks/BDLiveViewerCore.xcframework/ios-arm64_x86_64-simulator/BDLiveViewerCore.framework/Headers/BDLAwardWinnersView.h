//
//  BDLAwardWinnersView.h
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
#import "BDLLoadingView.h"
#import "BDLInteractiveToolModel.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 中奖名单 view。
 */
/**
 * @locale en
 * @brief The prize winner list view.
 */
@interface BDLAwardWinnersView : BDLPopupCenterShowBaseView <BDLLanguageService>

/**
 * @locale zh
 * @brief 当前的语言类型。详见 [BDLLanguageType](1185544#BDLLanguageType)。
 */
/**
 * @locale en
 * @brief The current language type. For more information, see [BDLLanguageType](viewer-sdk-for-ios-type-definitions#BDLLanguageType).
 */
@property (nonatomic, assign, readonly) BDLLanguageType languageType;
/**
 * @locale zh
 * @brief 顶部背景的 imageView。支持自定义。
 */
/**
 * @locale en
 * @brief The imageView for the top background. Customization is supported.
 */
@property (nonatomic, strong, readonly) UIImageView *topBackgroundImageView;
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
 * @brief 中奖名单标题 label。不支持自定义 `text`。
 */
/**
 * @locale en
 * @brief The title label of the prize winner list. All properties except `text` can be customized.
 */
@property (nonatomic, strong, readonly) UILabel *titleLabel;
/**
 * @locale zh
 * @brief “共 X 人中奖”文案的 label。不支持自定义 `text`。
 */
/**
 * @locale en
 * @brief The text label of "X winners in total". All properties except `text` can be customized.
 */
@property (nonatomic, strong, readonly) UILabel *countLabel;
/**
 * @locale zh
 * @brief 中奖名单的容器 tableView。支持自定义。
 */
/**
 * @locale en
 * @brief The container tableView of the prize winner list. Customization is supported.
 */
@property (nonatomic, strong, readonly) UITableView *tableView;
/**
 * @locale zh
 * @brief 加载中的 view。详见 [BDLLoadingView](#BDLLoadingView)。
 */
/**
 * @locale en
 * @brief The loading view. For more information, see [BDLLoadingView](#BDLLoadingView).
 */
@property (nonatomic, strong, readonly) BDLLoadingView *loadingView;
/**
 * @locale zh
 * @brief 返回按钮点击回调。<br>
 * @param view 中奖名单 view。
 * @list 抽奖
 */
/**
 * @locale en
 * @brief The callback is triggered when the back button is tapped.
 * @param view The prize winner list view.
 */
@property (nonatomic, copy) void (^backButtonClickedBlock)(BDLAwardWinnersView *view);

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
