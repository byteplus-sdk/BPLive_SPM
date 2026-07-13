//
//  BDLCommentBaseView.h
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
#import "BDLCommentBaseConfiguration.h"
#import <BDLiveCommon/BDLCommentModel.h>
#import "BDLPopupInputView.h"
#import "BDLNoCommentView.h"
#import "BDLPopupInputView.h"
#import "BDLBasicService.h"
#import "BDLCommentConfigService.h"

#import <BDLiveBase/BDLMasonry.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 评论、热门评论以及私聊共同的基类。
 */
/**
 * @locale en
 * @brief The common base class for comments and top comments.
 */
@interface BDLCommentBaseView : BDLBaseView
<
UITableViewDelegate,
UITableViewDataSource,
BDLLanguageService,
BDLBasicService,
BDLCommentConfigService
>

/**
 * @locale zh
 * @brief 初始化。
 * @param isPortrait 是否以竖屏直播间初始化。<br>
 *        - `YES`：以竖屏直播间初始化。
 *        - `NO`：以横屏直播间初始化。
 * @list 评论/私聊
 * @return 评论、热门评论以及私聊共同的基类实例。
 */
/**
 * @locale en
 * @brief Initializes the instance of the base class for comments and top comments.
 * @param isPortrait Whether to initialize in portrait mode.
 *        - `YES`: Portrait mode.
 *        - `NO`: Landscape mode.
 * @return The instance of the base class for comments and top comments.
 */
- (instancetype)initWithPortrait:(BOOL)isPortrait;
/**
 * @locale zh
 * @brief 是否为竖屏直播间。<br>
 *        - `YES`：竖屏直播间。
 *        - `NO`：横屏直播间。
 */
/**
 * @locale en
 * @brief Whether the live room is in portrait mode.<br>
 *        - `YES`: Portrait mode.
 *        - `NO`: Landscape mode.
 */
@property (nonatomic, assign, readonly) BOOL isPortrait;
/**
 * @locale zh
 * @brief 基类配置。详见 [BDLCommentBaseConfiguration](1185544#BDLCommentBaseConfiguration)。
 */
/**
 * @locale en
 * @brief The base class configuration. For more information, see [BDLCommentBaseConfiguration](viewer-sdk-for-ios-type-definitions#BDLCommentBaseConfiguration).
 */
@property (nonatomic, strong, readonly) BDLCommentBaseConfiguration *config;
/**
 * @locale zh
 * @brief 是否开启评论翻译。
 *        - `YES`：开启。
 *        - `NO`：不开启。
 */
/**
 * @locale en
 * @brief Whether to enable the comment translation.
 *        - `YES`: Enable.
 *        - `NO`: Disable.
 */
@property (nonatomic, assign, readonly) BOOL isCommentTranslateEnable;
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
 * @brief 评论区无评论时的 view。详见 [BDLNoCommentView](#BDLNoCommentView)。可自定义除 `frame`、`hidden` 外的所有属性。
 */
/**
 * @locale en
 * @brief The view when there are no comments in the comment area. For more information, see [BDLNoCommentView](#BDLNoCommentView). All properties except `frame` and `hidden` can be customized .
 */
@property (nonatomic, strong) BDLNoCommentView *noCommentView;
/**
 * @locale zh
 * @brief 更新评论区无评论时的占位图。
 * @list 评论/私聊
 */
/**
 * @locale en
 * @brief Updates the placeholder image for the comment area without comments.
 */
- (void)refreshNoCommentView;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
