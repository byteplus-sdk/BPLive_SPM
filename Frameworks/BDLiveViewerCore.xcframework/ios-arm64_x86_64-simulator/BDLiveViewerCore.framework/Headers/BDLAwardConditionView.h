//
//  BDLAwardConditionView.h
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


#import <BDLiveCommon/BDLBaseView.h>
#import <BDLiveCommon/BDLLanguageService.h>
#import "BDLInteractiveToolService.h"
#import "BDLParticipateAwardResponse.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 抽奖详情中参与条件 view。
 */
/**
 * @locale en
 * @brief The view of the participation condtions in the lucky draw details.
 */
@interface BDLAwardConditionView : BDLBaseView <BDLLanguageService>

/**
 * @locale zh
 * @brief “参与条件”文案的 label。不支持自定义 `text`。
 */
/**
 * @locale en
 * @brief The text label of "Condition". All properties except `text` can be customized.
 */
@property (nonatomic, strong, readonly) UILabel *titleLabel;
/**
 * @locale zh
 * @brief “点击一键参与自动完成”文案的 label。不支持自定义 `text`。
 */
/**
 * @locale en
 * @brief The text label of "Click Participate to automatically send the bullet comment password and take part in the lucky draw". All properties except `text` can be customized.
 */
@property (nonatomic, strong, readonly) UILabel *subTitleLabel;
/**
 * @locale zh
 * @brief 具体参与条件的 label。不支持自定义 `text`。
 */
/**
 * @locale en
 * @brief The label for specific participation conditions. All properties except `text` can be customized.
 */
@property (nonatomic, strong, readonly) UILabel *conditionLabel;
/**
 * @locale zh
 * @brief 参与条件勾选状态的 imageView。支持自定义图片。
 */
/**
 * @locale en
 * @brief The imageView for the participation condition selection status. Custom images are supported.
 */
@property (nonatomic, strong, readonly) UIImageView *checkMarkImageView;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
