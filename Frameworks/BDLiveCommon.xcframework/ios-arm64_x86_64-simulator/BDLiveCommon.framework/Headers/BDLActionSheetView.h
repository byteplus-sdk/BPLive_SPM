//
//  BDLActionSheetView.h
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


#import "BDLPopupBaseView.h"
#import "BDLLanguageService.h"

NS_ASSUME_NONNULL_BEGIN

@class BDLActionSheetView, BDLActionSheetAction;

typedef void(^BDLActionSheetHandler)(BDLActionSheetView *view, BDLActionSheetAction *action);

@interface BDLActionSheetAction : NSObject

/// 创建 BDLActionSheetAction
/// - Parameters:
///   - title: title
///   - handler: handler
+ (instancetype)actionWithTitle:(nullable NSString *)title handler:(BDLActionSheetHandler)handler;

/// 创建 BDLActionSheetAction
/// - Parameters:
///   - titleKey: titleKey 支持多语言, 直接传入strings key
///   - handler: handler
+ (instancetype)actionWithTitleKey:(nullable NSString *)titleKey handler:(BDLActionSheetHandler)handler;

@property (nonatomic, copy) BDLActionSheetHandler handler;
@property (nonatomic, strong, readonly) UIButton *button;

@end

@interface BDLActionSheetView : BDLPopupBottomShowBaseView <
BDLLanguageService
>

- (void)addAction:(BDLActionSheetAction *)action;

@property (nonatomic, strong, readonly) UIView *separator;
@property (nonatomic, strong, readonly) UIButton *cancelButton;
@property (nonatomic, readonly) NSArray<BDLActionSheetAction *> *actions;

@end

NS_ASSUME_NONNULL_END
