//
//  BDLPopupTopCommentViewConfiguration.h
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
#import <UIKit/UIKit.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type keytype
 * @brief 置顶评论详情弹窗配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The configuration of the pinned comment details dialog box.
 */
@interface BDLPopupTopCommentViewConfiguration : BDLRTBaseConfiguration

@end

/**
 * @locale zh
 * @type keytype
 * @brief 置顶评论详情弹窗配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The configuration of the pinned comment details dialog box.
 */
@interface BDLPopupTopCommentViewConfiguration (Config)

/**
 * @locale zh
 * @brief 内容区域的高度。默认值：400。单位：point。
 */
/**
 * @locale en
 * @brief The height of the content area. Default value: 400. Unit: points.
 */
@property (nonatomic, assign) CGFloat viewHeight;

/**
 * @locale zh
 * @brief 颜色主题。参数值为 `custom` 或 `light` 时，内容区域的颜色为白色，其他情况为黑色（#20202A）。
 */
/**
 * @locale en
 * @brief The color theme. If the parameter value is `custom` or `light`, the content area color is white. Otherwise, the color is black (#20202A).
 */
@property (nonatomic, copy, nullable) NSString *colorTheme;
/**
 * @locale zh
 * @brief 竖屏背景颜色。
 */
/**
 * @locale en
 * @brief The background color for the live room in portrait mode.
 */
@property (nonatomic, strong) UIColor *portraitContentBackgroundColor;
/**
 * @locale zh
 * @brief 竖屏文字颜色。
 */
/**
 * @locale en
 * @brief The text color for the live room in portrait mode.
 */
@property (nonatomic, strong) UIColor *portraitTopFontColor;
/**
 * @locale zh
 * @brief 弹窗内容字体和字号。
 */
/**
 * @locale en
 * @brief The font and font size of the dialog box content.
 */
@property (nonatomic, strong) UIFont *contentFont;
/**
 * @locale zh
 * @brief 弹窗标题是否居左。默认值：`NO`。<br>
 *        - `YES`：居左。
 *        - `NO`：居中。
 */
/**
 * @locale en
 * @brief Whether the dialog box title is left-aligned. Default value: `NO`.
 *        - `YES`: Left-aligned.
 *        - `NO`: Center-aligned.
 */
@property (nonatomic, assign) BOOL topTitleAlignmentLeft;
/**
 * @locale zh
 * @brief 点击评论中的链接后是否在直播间浮层展示跳转内容。默认值：`NO`。<br>
 *        - `YES`：在直播间浮层展示跳转内容，观众可以边看视频边看跳转内容。
 *        - `NO`：打开新的浏览器标签页展示跳转内容，观众无法边看视频边看跳转内容。
 */
/**
 * @locale en
 * @brief Whether the redirected content is displayed on a floating page in the live room after a URL in the comment is tapped. Default value: `NO`.
 *        - `YES`: The redirected content is displayed on a floating page in the live room. Viewers can watch the video and view the redirected content at the same time.
 *        - `NO`: The redirected content is displayed on a new browser tab. Viewers cannot watch the video and view the redirected content at the same time.
 */
@property (nonatomic, assign) BOOL commentUrlFloatingEnable;

@end


NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
