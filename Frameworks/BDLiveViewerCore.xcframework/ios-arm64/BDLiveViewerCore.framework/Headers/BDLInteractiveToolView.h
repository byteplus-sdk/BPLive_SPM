//
//  BDLInteractiveToolView.h
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
#import "BDLMenuService.h"
#import "BDLBasicService.h"
#import <BDLiveCommon/BDLLanguageService.h>
#import "BDLInteractiveToolService.h"
#import "BDLInteractiveToolContentView.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 互动工具菜单 view。
 */
/**
 * @locale en
 * @brief The interaction tools menu view.
 */
@interface BDLInteractiveToolView : BDLBaseView <BDLInteractiveToolService, BDLLanguageService, BDLMenuService, BDLBasicService>

/**
 * @locale zh
 * @brief 竖屏直播间的名字 label。可自定义除 `text`、`textColor`、`frame` 外的所有属性。
 */
/**
 * @locale en
 * @brief The name label for live rooms in portrait mode. All properties except `text`, `textColor`, and `frame` can be customized.
 */
@property (nonatomic, strong, readonly) UILabel *nameLabel;
/**
 * @locale zh
 * @brief 互动工具弹窗关闭按钮。
 */
/**
 * @locale en
 * @brief The close button of the interaction tools dialog box.
 */
@property (nonatomic, strong, readonly) UIButton *closeButton;
/**
 * @locale zh
 * @brief 是否为竖屏直播间。<br><br>
 *        - `YES`：竖屏直播间。
 *        - `NO`：横屏直播间。
 */
/**
 * @locale en
 * @brief Whether the live room is in portrait mode.
 *        - `YES`: Portrait mode.
 *        - `NO`: Landscape mode.
 */
@property (nonatomic, assign, readonly) BOOL isPortrait;
/**
 * @locale zh
 * @brief 点击链接后是否在直播间浮层展示跳转内容。<br>
 *        - `YES`：在直播间浮层展示跳转内容，观众可以边看视频边看跳转内容。
 *        - `NO`：打开新的浏览器标签页展示跳转内容，观众无法边看视频边看跳转内容。
 */
/**
 * @locale en
 * @brief Whether the redirected content is displayed on a floating page in the live room after viewers tap the URL.
 *        - `YES`: The redirected content is displayed on a floating page in the live room. Viewers can watch the video and view the redirected content at the same time.
 *        - `NO`: The redirected content is displayed on a new browser tab. Viewers cannot watch the video and view the redirected content at the same time.
 */
@property (nonatomic, assign, readonly) BOOL urlFloatingEnable;
/**
 * @locale zh
 * @brief 互动工具菜单配置。详见 [BDLInteractiveToolConfiguration](1185544#BDLInteractiveToolConfiguration)。
 */
/**
 * @locale en
 * @brief The configuration of interaction tools menu. For more information, see [BDLInteractiveToolConfiguration](viewer-sdk-for-ios-type-definitions#BDLInteractiveToolConfiguration).
 */
@property (nonatomic, strong, readonly) BDLInteractiveToolConfiguration *config;
/**
 * @locale zh
 * @brief 互动工具中 URL 的点击回调。
 * @param view 互动工具菜单 view。
 * @param url 点击的 URL。
 */
/**
 * @locale en
 * @brief The callback is triggered when the URL under the menu for interaction tools is tapped.
 * @param view The interaction tools menu view.
 * @param url The tapped URL.
 */
@property (nonatomic, copy, nullable) void (^urlClickBlock)(BDLInteractiveToolView *view, NSURL *url);

/**
 * @locale zh
 * @brief 在观众点击互动工具 context 时，SDK 调用该方法。互动工具 context 指互动工具菜单下的抽奖、投票、问卷等。
 * @param view 互动工具菜单 view。
 * @param model 互动工具 Model。详见 [BDLInteractiveToolModel](1185544#BDLInteractiveToolModel)。
 * @param context 互动工具内容 Model。详见 [BDLInteractiveContextModel](#BDLInteractiveContextModel)。
 */
/**
 * @locale en
 * @brief The callback is triggered when the context of interaction tools is tapped. The context of interaction tools refers to interaction tools such as lucky draws, quizzes, and questionnaires under the menu for interaction tools.
 * @param view The interaction tools menu view.
 * @param model The model of interaction tools. For more information, see [BDLInteractiveToolModel](viewer-sdk-for-ios-type-definitions#BDLInteractiveToolModel).
 * @param context The content model of interaction tools. For more information, see [BDLInteractiveContextModel](#BDLInteractiveContextModel).
 */
@property (nonatomic, copy, nullable) void (^onContextClickBlock)(BDLInteractiveToolView *view, BDLInteractiveToolModel *model, BDLInteractiveContextModel *context);
/**
 * @locale zh
 * @brief 互动工具弹窗关闭按钮点击回调。
 * @param view 互动工具菜单 view。
 */
/**
 * @locale en
 * @brief The callback is triggered when the close button of the interaction tools dialog box is tapped.
 * @param view The interaction tools menu view.
 */
@property (nonatomic, copy, nullable) void (^onCloseBlock)(BDLInteractiveToolView *view);
/**
 * @locale zh
 * @brief 初始化。
 * @param isPortrait 是否以竖屏直播间初始化。<br>
 *        - `YES`：以竖屏直播间初始化。
 *        - `NO`：以横屏直播间初始化。
 * @return 互动工具菜单 view 实例。
 */
/**
 * @locale en
 * @brief Initializes the instance of the interaction tools menu view.
 * @param isPortrait Whether to initialize in portrait mode.
 *        - `YES`: Portrait mode.
 *        - `NO`: Landscape mode.
 * @return The instance of the interaction tools menu view.
 */
- (instancetype)initWithPortrait:(BOOL)isPortrait;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
