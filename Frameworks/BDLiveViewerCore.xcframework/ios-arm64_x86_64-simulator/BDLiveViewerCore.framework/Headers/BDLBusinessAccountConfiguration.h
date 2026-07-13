//
//  BDLBusinessAccountConfiguration.h
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

#import "BDLRTBaseConfiguration.h"
#import <BDLiveBase/BDLBaseModel.h>
#import "BDLCustomUserModel.h"
#import <BDLiveCommon/BDLBusinessAccountModel.h>
#import "BDLHostFollowInfoModel.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type keytype
 * @brief 主播账号配置。
 */
/**
 * @locale en
 * @brief The host account configuration.
 * @type keytype
 */
@interface BDLBusinessAccountConfiguration : BDLRTBaseConfiguration
@end

/**
 * @locale zh
 * @type keytype
 * @brief 主播账号配置。
 */
/**
 * @locale en
 * @brief The host account configuration.
 * @type keytype
 */
@interface BDLBusinessAccountConfiguration (Config)

/**
 * @locale zh
 * @type api
 * @brief 未关注主播时的按钮文字。
 */
/**
 * @locale en
 * @brief The button text when the host is not followed.
 */
@property (nonatomic, copy, nullable) NSString *followText;
/**
 * @locale zh
 * @type api
 * @brief 已关注主播时的按钮文字。
 */
/**
 * @locale en
 * @brief The button text when the host is followed.
 */
@property (nonatomic, copy, nullable) NSString *followedText;
/**
 * @locale zh
 * @type api
 * @brief 未关注主播时按钮的背景图片。
 */
/**
 * @locale en
 * @brief The background image of the button when the host is not followed.
 */
@property (nonatomic, strong, nullable) UIImage *followBackgroundImage;
/**
 * @locale zh
 * @type api
 * @brief 已关注主播时按钮的背景图片。
 */
/**
 * @locale en
 * @brief The background image of the button when the host is followed.
 */
@property (nonatomic, strong, nullable) UIImage *followedBackgroundImage;

/**
 * @locale zh
 * @brief 在显示关注主播按钮时，SDK 调用该方法获取观众的关注状态。您可以在该方法内执行具体的获取关注状态逻辑，并在执行完成后，通过 `complete` 回调返回执行结果。
 * @param model 关注主播所需的信息。详见 [BDLHostFollowInfoModel](#BDLHostFollowInfoModel)。
 * @param complete 获取关注主播状态完成回调。
 *        传入参数：
 *        `followed`：观众是否已关注主播。
 *        - `YES`：已关注。
 *        - `NO`：未关注。
 */
/**
 * @locale en
 * @brief The SDK calls this method to get the viewer's follow status when the button to follow the host is displayed. You can implement the specific logic for getting the follow status within this method and return the result through the `complete` callback upon completion.
 * @param model The information required to follow the host. For more information, see [BDLHostFollowInfoModel](#BDLHostFollowInfoModel).
 * @param complete The callback triggered when the viewer's follow status is obtained.<br>
 *        Input parameters:<br>
 *        `followed`: Whether the viewer has followed the host.
 *        - `YES`: Followed.
 *        - `NO`: Not followed.
 */
@property (nonatomic, copy, nullable) void(^getUserFollowStatusBlock)(BDLHostFollowInfoModel *model, void(^complete)(BOOL followed));

/**
 * @locale zh
 * @brief 在观众点击关注或取消关注主播按钮时，SDK 调用该方法。您可以在该方法内执行具体的关注或取消关注逻辑，并在执行完成后，通过 `complete` 回调返回执行结果。
 * @param model 关注主播所需的信息。详见 [BDLHostFollowInfoModel](#BDLHostFollowInfoModel)。
 * @param followed 观众点击按钮时的关注状态。
 *        - `YES`：已关注。
 *        - `NO`：未关注。
 * @param complete 观众关注或取消关注主播操作执行完成回调。
 *        传入参数:
 *        `followed`：观众最新的关注状态。
 *        - `YES`：已关注。
 *        - `NO`：未关注。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the viewer taps the button to follow or unfollow the host. You can implement the specific logic for following or unfollowing the host within this method and return the result through the `complete` callback upon completion.
 * @param model The information required to follow the host. For more information, see [BDLHostFollowInfoModel](#BDLHostFollowInfoModel).
 * @param followed The follow status when the viewer taps the button.
 *        - `YES`: Followed.
 *        - `NO`: Not followed.
 * @param complete The callback triggered when the viewer's follow or unfollow action is completed.<br>
 *        Input parameters:<br>
 *        `followed`: The viewer's latest follow status.
 *        - `YES`: Followed.
 *        - `NO`: Not followed.
 */
@property (nonatomic, copy, nullable) void(^onFollowClickBlock)(BDLHostFollowInfoModel *model, BOOL followed, void(^complete)(BOOL followed));

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
