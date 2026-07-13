//
//  BDLLoadingView.h
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
#import "BDLPlayerConfiguration.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 加载 view。
 */
/**
 * @locale en
 * @brief The loading view.
 */
@interface BDLLoadingView : UIView

/**
 * @locale zh
 * @brief 加载图片的 imageView。
 */
/**
 * @locale en
 * @brief The imageView of the loading image.
 */
@property (nonatomic, strong, readonly) UIImageView *imageView;

/**
 * @locale zh
 * @brief 开始动画。
 * @list 其他
 */
/**
 * @locale en
 * @brief Starts the animation.
 */
- (void)showAnimation;
/**
 * @locale zh
 * @brief 结束动画。
 * @list 其他
 */
/**
 * @locale en
 * @brief Ends the animation.
 */
- (void)hideAnimation;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
