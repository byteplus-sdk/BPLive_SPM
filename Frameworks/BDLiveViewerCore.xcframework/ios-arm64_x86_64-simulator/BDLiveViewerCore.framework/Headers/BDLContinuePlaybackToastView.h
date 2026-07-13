//
//  BDLContinuePlaybackToastView.h
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


#import <BDLiveCommon/BDLDefines.h>

#import <UIKit/UIKit.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 断点续播提示 view。仅在观看页语言为简体中文时显示该提示。
 */
/**
 * @locale en
 * @brief The breakpoint resumption prompt view. The prompt is displayed only when the viewing page language is Simplified Chinese.
 */
@interface BDLContinuePlaybackToastView : UIView

/**
 * @locale zh
 * @brief 断点续播提示 label。不支持自定义 `text`。
 */
/**
 * @locale en
 * @brief The breakpoint resumption prompt label. All properties except `text` can be customized.
 */
@property (nonatomic, strong) UILabel *label;
/**
 * @locale zh
 * @brief 初始化。
 * @param time 断点续播时间，即上次播放结束的时间点。单位：秒。
 * @param languageType 当前的语言类型。详见 [BDLLanguageType](1185544#BDLLanguageType)。
 * @list 其他
 * @return 断点续播提示 view 实例。
 */
/**
 * @locale en
 * @brief Initializes the instance of the breakpoint resumption prompt view.
 * @param time The position to which the video seeks after automatically resuming from where it stopped. Unit: seconds.
 * @param languageType The current language type. For more information, see [BDLLanguageType](viewer-sdk-for-ios-type-definitions#BDLLanguageType).
 * @return The instance of the breakpoint resumption prompt view.
 */
- (instancetype)initWithPlaybackTime:(NSTimeInterval)time languageType:(BDLLanguageType)languageType;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
