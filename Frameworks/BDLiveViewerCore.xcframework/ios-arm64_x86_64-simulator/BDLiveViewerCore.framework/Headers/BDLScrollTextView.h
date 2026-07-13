//
//  BDLScrollTextView.h
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

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type keytype
 * @brief 滚动方向。
 */
/**
 * @locale en
 * @type keytype
 * @brief The scrolling direction.
 */
typedef NS_ENUM(NSInteger, BDLScrollDirection) {
    /**
     * @locale zh
     * @brief 向右。
     */
    /**
     * @locale en
     * @brief To the right.
     */
    BDLScrollDirectionRight,
    /**
     * @locale zh
     * @brief 向左。
     */
    /**
     * @locale en
     * @brief To the left.
     */
    BDLScrollDirectionLeft
};

/**
 * @locale zh
 * @type api
 * @brief 直播描述文字 view。
 */
/**
 * @locale en
 * @brief The live room description text view.
 */
@interface BDLScrollTextView : UIView

/**
 * @locale zh
 * @brief 滚动方向。详见 [BDLScrollDirection](1185544#BDLScrollDirection)。
 */
/**
 * @locale en
 * @brief The scroll direction. For more information, see [BDLScrollDirection](viewer-sdk-for-ios-type-definitions#BDLScrollDirection).
 */
@property (nonatomic, assign) BDLScrollDirection scrollDirection;
/**
 * @locale zh
 * @brief 滚动速度，即每秒滚动的 point 数量。单位：point。默认值：30。
 */
/**
 * @locale en
 * @brief The scroll speed, namely the number of points scrolled per second. Unit: points. Default value: `30`.
 */
@property (nonatomic, assign) float scrollSpeed;
/**
 * @locale zh
 * @brief 两次滚动之间的停顿间隔。单位：秒。默认为 0.0，即连续滚动。
 */
/**
 * @locale en
 * @brief The interval of pause between two scrolls. Unit: seconds. The default value is `0.0`, indicating continuous scrolling.
 */
@property (nonatomic, assign) NSTimeInterval pauseInterval;
/**
 * @locale zh
 * @brief Label 左侧空白。单位：point。默认值：20。
 */
/**
 * @locale en
 * @brief The blank space on the left side of the label. Unit: points. Default value: `20`.
 */
@property (nonatomic, assign) NSInteger labelSpacing;
/**
 * @locale zh
 * @brief 滚动时的动画选项。
 */
/**
 * @locale en
 * @brief The animation options during scrolling.
 */
@property (nonatomic, assign) UIViewAnimationOptions animationOptions;
/**
 * @locale zh
 * @brief 是否正在滚动。
 *        - `YES`：正在滚动。
 *        - `NO`：未在滚动。
 */
/**
 * @locale en
 * @brief Whether scrolling。
 *        - `YES`: Scrolling.
 *        - `NO`: Not scrolling.
 */
@property (nonatomic, assign, readonly) BOOL scrolling;
/**
 * @locale zh
 * @brief 渐变遮罩的长度。单位：point。默认值：7.0
 */
/**
 * @locale en
 * @brief The length of the gradient mask. Unit: points. Default value: `7.0`.
 */
@property (nonatomic, assign) CGFloat fadeLength;
/**
 * @locale zh
 * @brief 字体和字号。
 */
/**
 * @locale en
 * @brief The font and font size.
 */
@property (nonatomic, strong) UIFont *font;
/**
 * @locale zh
 * @brief 文字。
 */
/**
 * @locale en
 * @brief The text.
 */
@property (nonatomic, copy, nullable) NSString *text;
/**
 * @locale zh
 * @brief 富文本。
 */
/**
 * @locale en
 * @brief The rich text.
 */
@property (nonatomic, copy, nullable) NSAttributedString *attributedText;
/**
 * @locale zh
 * @brief 文字颜色。
 */
/**
 * @locale en
 * @brief The text color.
 */
@property (nonatomic, strong) UIColor *textColor;
/**
 * @locale zh
 * @brief 文本对齐方式。不自动滚动时生效。
 */
/**
 * @locale en
 * @brief The text alignment. Effective when not scrolling automatically.
 */
@property (nonatomic, assign) NSTextAlignment textAlignment;
/**
 * @locale zh
 * @brief 阴影颜色。
 */
/**
 * @locale en
 * @brief The shadow color.
 */
@property (nonatomic, strong, nullable) UIColor *shadowColor;
/**
 * @locale zh
 * @brief 阴影偏移量。
 */
/**
 * @locale en
 * @brief The shadow offset.
 */
@property (nonatomic, assign) CGSize shadowOffset;
/**
 * @locale zh
 * @brief 刷新 label。
 * @list 直播描述
 */
/**
 * @locale en
 * @brief Refreshes the label.
 */
- (void)refreshLabels;
/**
 * @locale zh
 * @brief 设置文本。
 * @param refresh 是否需要刷新。
 *        - `YES`：需要刷新。
 *        - `NO`：不需要刷新。
 * @param text 文本。
 * @list 直播描述
 */
/**
 * @locale en
 * @brief Sets the text.
 * @param text The text.
 * @param refresh Whether refresh is needed.
 *        - `YES`: Needed.
 *        - `NO`: Not needed.
 */
- (void)setText:(nullable NSString *)text refreshLabels:(BOOL)refresh;
/**
 * @locale zh
 * @brief 设置富文本。
 * @param refresh 是否需要刷新。
 *        - `YES`：需要刷新。
 *        - `NO`：不需要刷新。
 * @param theText 富文本。
 * @list 直播描述
 */
/**
 * @locale en
 * @brief Sets the rich text.
 * @param theText The rich text.
 * @param refresh Whether refresh is needed.
 *        - `YES`: Needed.
 *        - `NO`: Not needed.
 */
- (void)setAttributedText:(nullable NSAttributedString *)theText refreshLabels:(BOOL)refresh;
/**
 * @locale zh
 * @brief 滚动 label。
 * @list 直播描述
 */
/**
 * @locale en
 * @brief Scrolls the label.
 */
- (void)scrollLabelIfNeeded;
/**
 * @locale zh
 * @brief 监听进入前台的通知（`UIApplicationDidBecomeActiveNotification` 和 `UIApplicationWillEnterForegroundNotification`），从而刷新并开始滚动 label。
 * @list 直播描述
 */
/**
 * @locale en
 * @brief Listens to notifications (`UIApplicationDidBecomeActiveNotification` and `UIApplicationWillEnterForegroundNotification`) when the app enters the foreground to refresh and start scrolling the label.
 */
- (void)observeApplicationNotifications;

@end


NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
