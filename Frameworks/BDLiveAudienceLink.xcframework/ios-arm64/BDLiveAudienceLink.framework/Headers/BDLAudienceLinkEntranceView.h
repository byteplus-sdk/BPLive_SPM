//
//  BDLAudienceLinkEntranceView.h
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
#import <BDLiveCommon/UIView+BDLDraggable.h>
#import <BDLiveCommon/BDLLanguageService.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type keytype
 * @brief 连麦入口 view 的协议。
 */
/**
 * @locale en
 * @type keytype
 * @hidden (iOS)
 */
@protocol BDLAudienceLinkEntranceViewProtocol <NSObject>

/**
 * @locale zh
 * @brief 开始展示连麦动画。SDK 会在第一次显示连麦入口 view 时调用该方法。
 */
- (void)startAnimating;

@end
/**
 * @locale zh
 * @type api
 * @brief 连麦入口 view，用于展示申请连麦按钮。
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@interface BDLAudienceLinkEntranceView : BDLBaseView <BDLAudienceLinkEntranceViewProtocol, BDLLanguageService>
/**
 * @locale zh
 * @brief 是否正在申请连麦。<br>
 *        - `YES`: 正在申请连麦。
 *        - `NO:` 未申请连麦或已连麦。
 */
@property (nonatomic, assign) BOOL linking;

/**
 * @locale zh
 * @brief 显示连麦图标以及动画的 imageView。
 */
@property (nonatomic, strong) UIImageView *imageView;
/**
 * @locale zh
 * @brief 显示“申请连麦”和“申请中...”文字的 label。
 */
@property (nonatomic, strong) UILabel *label;

@end

NS_ASSUME_NONNULL_END
