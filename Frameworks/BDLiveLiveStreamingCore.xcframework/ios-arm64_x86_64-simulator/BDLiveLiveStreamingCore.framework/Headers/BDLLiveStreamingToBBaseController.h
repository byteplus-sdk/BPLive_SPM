//
//  BDLLiveStreamingToBBaseController.h
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

#import "BDLLiveStreamingBaseController.h"
#import "UIView+BDLLandscape.h"
#import "BDLBottomButtonListView.h"
#import <BDLiveCommon/BDLPopupCustomView.h>
#import "BDLRightToolsSheetView.h"
#import <BDLiveCommon/BDLButton.h>

NS_ASSUME_NONNULL_BEGIN

/// 直播推流VC ToB only
@interface BDLLiveStreamingToBBaseController : BDLLiveStreamingBaseController

// MARK: - 给子类用的,这个文件不对外暴露

/// 开始直播
@property (nonatomic, strong) BDLButton *startBtn;

@property (nonatomic, strong, nullable) BDLPopupCustomView *popupCustomView;
/// 底部按钮组合listView
@property (nonatomic, strong, readonly) BDLBottomButtonListView *bottomButtonListView;

@property (nonatomic, assign, readonly) BOOL isEditingTemplate;

- (void)stopCaptureAndClose;

- (void)updateUIInStreamStatus __attribute__((objc_requires_super));

/// 获取 底部右侧按钮的列表, 从右往左布局
/// dictionary的key:  imageName / target /action
- (NSArray <BDLBottomButtonConfig *> *)getBottomButtonListItem;

- (void)closePopupWithFinish:(void(^)(void))complete;

- (void)toolViewDidClickCellWithCellModel:(BDLToolCellModel *)cellModel;

- (NSMutableArray<BDLToolCellModel *> *)toolViewDataArray;

@end

NS_ASSUME_NONNULL_END
