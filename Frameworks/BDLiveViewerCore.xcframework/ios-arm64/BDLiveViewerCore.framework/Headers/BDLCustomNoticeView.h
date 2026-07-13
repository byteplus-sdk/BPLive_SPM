//
//  BDLCustomNoticeView.h
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

#import <UIKit/UIKit.h>

#import "BDLNoticeModel.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 自定义消息通知 view。
 */
/**
 * @locale en
 * @hidden (iOS)
 * @brief Custom notification message view.
 */
@interface BDLCustomNoticeView : UIView
/**
 * @locale zh
 * @brief 初始化。
 * @param notice 当前要显示的通知。详见 [BDLCustomNotice](1185544#BDLCustomNotice)。
 * @return 自定义消息通知 view 实例。
 */
/**
 * @locale en
 * @brief Initialize.
 * @param notice The notification to be displayed. For more details, refer to [BDLCustomNotice](viewer-sdk-for-ios-type-definitions#BDLCustomNotice).
 */
- (instancetype)initWithNotice:(BDLCustomNotice *)notice;
/**
 * @locale zh
 * @brief 左侧的 `imageView`。支持自定义。
 */
/**
 * @locale en
 * @brief The `imageView` on the left side. Customizable.
 */
@property (nonatomic, strong, readonly) UIImageView *imageView;
/**
 * @locale zh
 * @brief 文字 label。支持自定义。
 */
/**
 * @locale en
 * @brief Text label. Customization supported.
 */
@property (nonatomic, strong, readonly) UILabel *label;
/**
 * @locale zh
 * @brief 当前要显示的通知。由初始化方法 [initWithNotice:](#BDLCustomNoticeView-initwithnotice) 传入。
 */
/**
 * @locale en
 */
@property (nonatomic, strong, readonly) BDLCustomNotice *customNotice;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
