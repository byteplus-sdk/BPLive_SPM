//
//  BDLLivePullViewController+BDLAudienceLink.h
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

#import <BDLiveViewerCore/BDLLivePullViewController.h>
#import "BDLAudienceLinkController.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 完整直播间 controller。
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@interface BDLLivePullViewController (BDLAudienceLink)

/**
 * @locale zh
 * @brief 自定义连麦 controller。
 * @param viewController `BDLLivePullViewController` 实例。
 * @param audienceLinkController `BDLAudienceLinkController` 实例。详见 [BDLAudienceLinkController](#BDLAudienceLinkController)。
 */
@property (nonatomic, copy) void(^customizeAudienceLinkController)(BDLLivePullViewController *viewController, BDLAudienceLinkController *audienceLinkController);

/**
 * @locale zh
 * @brief 在观众连麦期间，断开观众的连麦并关闭直播间。<br>:::tip
 *        如果用户正在连麦中，调用该方法不会显示退出连麦弹窗。<br>:::
 * @param showFloatingPlayerIfAvailable 在可以显示浮窗播放器时，是否显示浮窗播放器。
 *        - `YES`：显示。
 *        - `NO`：不显示。
 */
- (void)cancelAudienceLinkIfNeededAndClose:(BOOL)showFloatingPlayerIfAvailable;

@end

NS_ASSUME_NONNULL_END
