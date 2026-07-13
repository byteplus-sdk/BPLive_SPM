//
//  BDLButton.h
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

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, BDLButtonHeight) {
    BDLButtonHeight44 = 44,
    BDLButtonHeight36 = 36,
    BDLButtonHeight28 = 28,
    BDLButtonHeight24 = 24,
};

/**
 * @locale zh
 * @type keytype
 * @brief 按钮类型，详见设计稿 https://www.figma.com/design/jNzPo6m6U91uJa3kXEl1Rx/%E4%BC%81%E4%B8%9A%E7%9B%B4%E6%92%AD-%E7%A7%BB%E5%8A%A8%E7%AB%AFUI%E8%A7%84%E8%8C%83?node-id=49-4044&p=f&m=dev
 */
typedef NS_ENUM(NSInteger, BDLButtonType) {
    /**
     * @locale zh
     * @brief 主要，根据mainColor颜色会变
     */
    BDLButtonTypeMain,
    /**
     * @locale zh
     * @brief 次要，根据mainColor颜色会变
     */
    BDLButtonTypeSecondary,
    /**
     * @locale zh
     * @brief 普通，不受主色变化影响
     */
    BDLButtonTypeNormal,
    /**
     * @locale zh
     * @brief 线性，不受主色变化影响
     */
    BDLButtonTypeLinear,
};

/// 如需禁用，设置 userInteractionEnabled 为NO
@interface BDLButton : UIControl

/// 这里只是看上去像不可点击, 但实际还是会响应点击事件, 主要用作禁用状态下, 弹出Toast使用
@property (nonatomic, assign) BOOL seemsDisabled;

+ (instancetype)buttonWithButtonHeight:(BDLButtonHeight)height type:(BDLButtonType)type;

/// 设置文字左边图片，内部会按需修改图片颜色
- (void)setLeftImage:(UIImage *)image;
/// 设置文字右边图片，内部会按需修改图片颜色
- (void)setRightImage:(UIImage *)image;
/// 设置文字
- (void)setTitle:(NSString *)title;

/**
 * @locale zh
 * @brief 禁用点击时候阴影效果，默认NO
 */
@property (nonatomic, assign) BOOL forbidTouchShadow;
- (void)startLoadingAnimation;
- (void)stopLoadingAnimation;

@end

NS_ASSUME_NONNULL_END
