//
//  BDLBottomButtonListView.h
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

typedef __kindof UIButton *_Nullable (^CustomizeButtonBlock)(UIButton *button);

@interface BDLBottomButtonConfig : NSObject

@property (nonatomic, assign) SEL action;
@property (nonatomic, strong, nullable) id target;
@property (nonatomic, strong, nullable) UIImage *image;
@property (nonatomic, assign) NSInteger number;
@property (nonatomic, copy, nullable) CustomizeButtonBlock customizeButtonBlock;

+ (instancetype)configWithAction:(SEL)action target:(nullable id)target image:(nullable UIImage *)image customizeBlock:(nullable CustomizeButtonBlock)customizeBlock;

@end

@interface BDLBottomButtonListView : UIView

/// 初始化方法 - 必走
/// @param configArray 配置参数数组
+ (instancetype)bottomButtonListViewInitWithConfigArray:(NSArray <BDLBottomButtonConfig *>*)configArray;

@property (nonatomic, copy, readonly) NSArray<UIButton *> *buttons;

- (void)updateWithConfigArray:(NSArray <BDLBottomButtonConfig *>*)configArray;

@end

NS_ASSUME_NONNULL_END
