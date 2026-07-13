//
//  BDLMultiLanguageView.h
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
#import <BDLiveCommon/BDLLanguageService.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

@class BDLMultiLanguageView;

/**
 * @locale zh
 * @type callback
 * @brief 多语言选择弹窗 view 的代理方法。
 */
/**
 * @locale en
 * @type callback
 * @brief The delegate methods for the language selection dialog box view.
 */
@protocol BDLMultiLanguageViewDelegate <NSObject>
/**
 * @locale zh
 * @brief 在隐藏多语言选择弹窗时，SDK 调用该方法。
 * @param view self，即当前隐藏的 [BDLMultiLanguageView](1185540#BDLMultiLanguageView) 实例。
 * @param superview self.superview，即当前实例的 superView。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the language selection dialog box is hidden.
 * @param view self, which is the current hidden [BDLMultiLanguageView](docs-bdlliveengine#BDLMultiLanguageView) instance.
 * @param superview self.superview, which is the superView of the current instance.
 */
- (void)multiLanguageView:(BDLMultiLanguageView *)view removeFromSuperview:(UIView *)superview;

@end

/**
 * @locale zh
 * @type api
 * @brief 多语言选择弹窗 view。
 */
/**
 * @locale en
 * @brief The language selection dialog box view.
 */
@interface BDLMultiLanguageView : BDLPopupBottomShowBaseView <BDLLanguageService>
/**
 * @locale zh
 * @brief 代理方法。详见 [BDLMultiLanguageViewDelegate](1185541#BDLMultiLanguageViewDelegate)。
 */
/**
 * @locale en
 * @brief The delegate method. For more information, see [BDLMultiLanguageViewDelegate](viewer-SDK-for-ios-callbacks#BDLMultiLanguageViewDelegate).
 */
@property (nonatomic, weak) id<BDLMultiLanguageViewDelegate> delegate;
/**
 * @locale zh
 * @brief 语言列表的容器 view。可自定义除 `hidden` 外的所有属性。如果您将 `hidden` 设为 `YES`，会出现空白的弹窗。
 */
/**
 * @locale en
 * @brief The container view of the language list. All properties except `hidden` can be customized. If `hidden` is set to `YES`, a blank dialog box will appear.
 */
@property (nonatomic, strong) UITableView *tableView;
/**
 * @locale zh
 * @brief 取消按钮。可自定义除 `normalText`、`frame` 外的所有属性。
 */
/**
 * @locale en
 * @brief The cancel button. All properties except `normalText` and `frame` can be customized.
 */
@property (nonatomic, strong) UIButton *cancelButton;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
