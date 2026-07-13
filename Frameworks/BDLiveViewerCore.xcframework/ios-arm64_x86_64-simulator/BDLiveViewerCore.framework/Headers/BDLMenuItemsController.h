//
//  BDLMenuItemsController.h
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

#import <Foundation/Foundation.h>
#import "BDLCommentViewConfiguration.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

@class BDLCommentViewConfiguration;
/**
 * @locale zh
 * @type api
 * @brief 评论区底部按钮的 controller。
 */
/**
 * @locale en
 * @brief The controller for the buttons at the bottom of the comment area.
 */
@interface BDLMenuItemsController : NSObject

/**
 * @locale zh
 * @brief 是否为竖屏直播间。<br>
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
 * @brief 购物车按钮点击回调。
 * @param controller 评论区底部按钮的 controller。
 * @list 评论/私聊
 */
/**
 * @locale en
 * @brief The callback is triggered when the shopping cart button is tapped.
 * @param controller The controller for the buttons at the bottom of the comment area.
 */
@property (nonatomic, copy, nullable) void (^shoppingCardClickBlock)(BDLMenuItemsController *controller);
/**
 * @locale zh
 * @brief 礼物按钮点击回调。
 * @param controller 评论区底部按钮的 controller。
 */
/**
 * @locale en
 * @brief The callback is triggered when the gift button is tapped.
 * @param controller The controller for the buttons at the bottom of the comment area.
 */
@property (nonatomic, copy, nullable) void (^giftClickBlock)(BDLMenuItemsController *controller);
/**
 * @locale zh
 * @brief 直播间点赞按钮点击回调。
 * @param controller 评论区底部按钮的 controller。
 * @list 评论/私聊
 * @return 是否显示点击动画。
 *         - `YES`：显示。
 *         - `NO`：不显示。
 */
/**
 * @locale en
 * @brief The callback is triggered when the button for liking the live room is tapped.
 * @param controller The controller for the buttons at the bottom of the comment area.
 * @return Whether to display the tap animation.
 *         - `YES`: Display.
 *         - `NO`: Do not display.
 */
@property (nonatomic, copy, nullable) BOOL (^likeClickBlock)(BDLMenuItemsController *controller);
/**
 * @locale zh
 * @brief 互动工具按钮点击回调。
 * @param controller 评论区底部按钮的 controller。
 * @list 评论/私聊
 */
/**
 * @locale en
 * @brief The callback is triggered when the interaction tools menu button is tapped.
 * @param controller The controller for the buttons at the bottom of the comment area.
 */
@property (nonatomic, copy, nullable) void (^interactiveToolClickBlock)(BDLMenuItemsController *controller);
/**
 * @locale zh
 * @brief 私聊互动按钮点击回调。
 * @param controller 评论区底部按钮的 controller。
 * @list 评论/私聊
 */
/**
 * @locale en
 * @list 
 * @hidden (iOS)
 */
@property (nonatomic, copy, nullable) void (^privateChatClickBlock)(BDLMenuItemsController *controller);
/**
 * @locale zh
 * @brief 图文介绍按钮点击回调。
 * @param controller 评论区底部按钮的 controller。
 * @list 评论/私聊
 */
/**
 * @locale en
 * @brief The callback is triggered when the graphics menu button is tapped.
 * @param controller The controller for the buttons at the bottom of the comment area.
 */
@property (nonatomic, copy, nullable) void (^imageTextClickBlock)(BDLMenuItemsController *controller);
/**
 * @locale zh
 * @brief 内嵌链接按钮点击回调。
 * @param controller 评论区底部按钮的 controller。
 * @list 评论/私聊
 */
/**
 * @locale en
 * @brief The callback is triggered when the embedded link menu button is tapped.
 * @param controller The controller for the buttons at the bottom of the comment area.
 */
@property (nonatomic, copy, nullable) void (^embeddedUrlClickBlock)(BDLMenuItemsController *controller);
/**
 * @locale zh
 * @brief 分享按钮点击回调。
 * @param controller 评论区底部按钮的 controller。
 * @list 评论/私聊
 */
/**
 * @locale en
 * @brief The callback is triggered when the share button is tapped.
 * @param controller The controller for the buttons at the bottom of the comment area.
 */
@property (nonatomic, copy, nullable) void (^shareClickBlock)(BDLMenuItemsController *controller);
/**
 * @locale zh
 * @brief 更多选项按钮点击回调。
 * @param controller 评论区底部按钮的 controller。
 * @list 评论/私聊
 */
/**
 * @locale en
 * @brief The callback is triggered when the more options button is tapped.
 * @param controller The controller for the buttons at the bottom of the comment area.
 */
@property (nonatomic, copy, nullable) void (^moreOptionsClickBlock)(BDLMenuItemsController *controller);
/**
 * @locale zh
 * @brief 初始化。
 * @param config 配置。详见 [BDLCommentViewConfiguration](1185544#BDLCommentViewConfiguration(Config))。
 * @param isPortrait 是否以竖屏直播间初始化。<br>
 *        - `YES`：以竖屏直播间初始化。
 *        - `NO`：以横屏直播间初始化。
 * @return 评论区底部按钮的 controller 实例。
 */
/**
 * @locale en
 * @brief Initializes the instance of the controller for the buttons at the bottom of the comment area.
 * @param config The configuration. For more information, see [BDLCommentViewConfiguration](viewer-sdk-for-ios-type-definitions#BDLCommentViewConfiguration(Config)).
 * @param isPortrait Whether to initialize in portrait mode.
 *        - `YES`: Portrait mode.
 *        - `NO`: Landscape mode.
 * @return The instance of the controller for the buttons at the bottom of the comment area.
 */
- (instancetype)initWithConfig:(BDLCommentViewConfiguration *)config portrait:(BOOL)isPortrait;

/**
 * @locale zh
 * @brief 调用指定类型的功能入口按钮的点击行为。
 * @param type 按钮类型。详见 BDLMenuItemType。
 */
/**
 * @locale en
 * @brief Invokes the click action of the specified function button.
 * @param type The button type. See BDLMenuItemType.
 */
- (void)invokeFunctionBtnClick:(BDLMenuItemType)type;
/**
 * @locale zh
 * @brief 添加一个自定义底部按钮，并根据 position 进行插入排序。
 *        - 与 BDLMenuItemModel.priority 比较：值越大越靠左，值越小越靠右。
 *        - 尺寸和间距与默认底部按钮一致。
 * @param view 自定义按钮的 view。
 * @param position 插入位置值。
 */
/**
 * @locale en
 * @brief Adds a custom bottom function button and inserts it according to position.
 *        - Compared with BDLMenuItemModel.priority: larger values appear more to the left; smaller to the right.
 *        - Size and spacing follow the default bottom buttons.
 * @param view The custom button view.
 * @param position The position value.
 */
- (void)addBottomFunctionBtn:(UIView *)view position:(NSInteger)position;
@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop