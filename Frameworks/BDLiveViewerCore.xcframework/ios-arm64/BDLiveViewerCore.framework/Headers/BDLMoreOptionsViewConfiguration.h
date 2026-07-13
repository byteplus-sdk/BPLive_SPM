//
//  BDLMoreOptionsViewConfiguration.h
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

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type keytype
 * @brief 更多选项弹窗配置。<br>:::tip
 *        在竖屏直播间内点击右下方的更多（...）图标后，即可弹出更多选项弹窗。<br>:::
 */
/**
 * @locale en
 * @type keytype
 * @brief The configuration of the more options dialog box.
 *        :::tip
 *        The more options dialog box is displayed after viewers tap the more (...) icon in the lower-right corner of the live room in portrait mode.
 *        :::
 */
@interface BDLMoreOptionsViewConfiguration : BDLRTBaseConfiguration

@end

/**
 * @locale zh
 * @type keytype
 * @brief 更多选项弹窗配置。<br>:::tip
 *        在竖屏直播间内点击右下方的更多（...）图标后，即可弹出更多选项弹窗。<br>:::
 */
/**
 * @locale en
 * @type keytype
 * @brief The configuration of the more options dialog box.
 *        :::tip
 *        The more options dialog box is displayed after viewers tap the more (...) icon in the lower-right corner of the live room in portrait mode.
 *        :::
 */
@interface BDLMoreOptionsViewConfiguration (Config)

/**
 * @locale zh
 * @brief 多语言切换按钮图片。
 */
/**
 * @locale en
 * @brief The language selection button image.
 */
@property (nonatomic, strong) UIImage *multiLanguageImage;
/**
 * @locale zh
 * @brief 清屏按钮图片。
 */
/**
 * @locale en
 * @brief The clear screen button image.
 */
@property (nonatomic, strong) UIImage *clearScreenImage;
/**
 * @locale zh
 * @brief 清晰度选择按钮图片。
 */
/**
 * @locale en
 * @brief The resolution selection button image.
 */
@property (nonatomic, strong) UIImage *resolutionImage;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
