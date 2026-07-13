//
//  BDLLiveDescriptionView.h
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
#import "BDLScrollTextView.h"
#import "BDLBasicService.h"
#import <BDLiveCommon/BDLLanguageService.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 直播描述 view。
 */
/**
 * @locale en
 * @brief The live room description view.
 */
@interface BDLLiveDescriptionView : BDLBaseView <
BDLBasicService
, BDLLanguageService
>

/**
 * @locale zh
 * @brief 直播描述文字 view。详见 [BDLScrollTextView](#BDLScrollTextView)。
 */
/**
 * @locale en
 * @brief The view of the live room description text. For more information, see [BDLScrollTextView](#BDLScrollTextView).
 */
@property (nonatomic, strong, readonly) BDLScrollTextView *scrollTextView;
/**
 * @locale zh
 * @brief 箭头图标。
 */
/**
 * @locale en
 * @brief The arrow icon.
 */
@property (nonatomic, strong, readonly) UIButton *arrowButton;
/**
 * @locale zh
 * @brief 箭头图标点击回调。
 * @param view 直播描述 view。
 * @list 直播描述
 */
/**
 * @locale en
 * @brief The callback is triggered when the arrow icon is tapped.
 * @param view The live room description view.
 */
@property (nonatomic, copy) void (^arrowButtonClickedBlock)(BDLLiveDescriptionView *view);

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
