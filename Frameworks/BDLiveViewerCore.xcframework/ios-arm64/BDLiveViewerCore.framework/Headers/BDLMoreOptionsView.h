//
//  BDLMoreOptionsView.h
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


#import <BDLiveCommon/BDLPopupBaseView.h>
#import "BDLMoreOptionsViewConfiguration.h"
#import <BDLiveCommon/BDLLanguageService.h>
#import "BDLMoreOptionsProvider.h"
#import "BDLMenuItemsProvider.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

@class BDLMoreOptionsView;
/**
 * @locale zh
 * @type keytype
 * @brief 更多选项弹窗中的按钮点击回调。
 * @param moreOptionsView 更多选项弹窗 view。详见 [BDLMoreOptionsView](1185540#BDLMoreOptionsView)。
 * @param isSelected 是否点击按钮。<br>
 *        - `YES`：点击。
 *        - `NO`：未点击。
 */
/**
 * @locale en
 * @type keytype
 * @brief The callback is triggered when a button in the more options dialog box is tapped.
 * @param moreOptionsView The view of the more options dialog box. For more information, see  [BDLMoreOptionsView](docs-bdlliveengine#BDLMoreOptionsView).
 * @param isSelected Whether a button is tapped.
 *        - `YES`: Tapped.
 *        - `NO`: Not tapped.
 */
typedef void (^BDLMoreOptionsViewBlock)(BDLMoreOptionsView *moreOptionsView, BOOL isSelected);

/**
 * @locale zh
 * @brief 更多选项弹窗 view。<br>:::tip
 *        在竖屏直播间内点击右下方的更多（...）图标后，即可弹出更多选项弹窗。<br>:::
 */
/**
 * @locale en
 * @brief The more options dialog box view.
 *        :::tip
 *        The more options dialog box appears after viewers tap the more (...) icon in the lower-right corner of the live room in portrait mode.
 *        :::
 */
@interface BDLMoreOptionsView : BDLPopupBottomShowBaseView <BDLLanguageService, BDLMoreOptionsService, BDLMenuItemsService>

/**
 * @locale zh
 * @brief 关闭更多选项弹窗的点击回调。详见 [BDLMoreOptionsViewBlock](1185544#bdlmoreoptionsviewblock)。
 */
/**
 * @locale en
 * @brief The callback is triggered when viewers tap to close the more options dialog box. For more information, see [BDLMoreOptionsViewBlock](viewer-sdk-for-ios-type-definitions#bdlmoreoptionsviewblock).
 */
@property (nonatomic, copy, nullable) BDLMoreOptionsViewBlock closeClickBlock;

/**
 * @locale zh
 * @brief 选项 view。可自定义除 `frame` 外的所有属性。
 */
/**
 * @locale en
 * @brief The options view. All properties except `frame` can be customized.
 */
@property (nonatomic, strong, readonly) UICollectionView *optionsView;
/**
 * @locale zh
 * @brief 底部取消按钮和选项间的分割线。可自定义所有属性。内部使用 Masonry 进行布局，如需修改 `frame`，推荐使用 `mas_remake` 进行修改。
 */
/**
 * @locale en
 * @brief The divider line between the options and the bottom cancel button. All properties can be customized. Masonry is used internally for layout. To modify the `frame`, it is recommended to use `mas_remake`.
 */
@property (nonatomic, strong, readonly) UIView *splitView;
/**
 * @locale zh
 * @brief 底部取消按钮。可自定义所有属性。内部使用 Masonry 进行布局，如需修改 `frame`，推荐使用 `mas_remake` 进行修改。
 */
/**
 * @locale en
 * @brief The bottom cancel button. All properties can be customized. Masonry is used internally for layout. To modify the `frame`, it is recommended to use `mas_remake`.
 */
@property (nonatomic, strong, readonly) UIButton *cancelButton;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
