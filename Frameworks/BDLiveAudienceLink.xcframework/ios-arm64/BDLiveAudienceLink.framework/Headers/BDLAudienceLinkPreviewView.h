//
//  BDLAudienceLinkPreviewView.h
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


#import <BDLiveCommon/BDLBaseView.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * @locale zh
 * @type api
 * @brief 连麦本地画面预览 view，用于展示当前连麦观众的本地视频画面。
 */
/**
 * @locale en
 * @type api
 * @hidden (iOS)
 */
@interface BDLAudienceLinkPreviewView : BDLBaseView

/**
 * @locale zh
 * @brief 连麦本地画面预览 view，用于展示当前连麦观众的本地视频画面。
 */
@property (nonatomic, strong) UIView *previewView;
/**
 * @locale zh
 * @brief 占位 view。仅在未开启摄像头时显示。
 */
@property (nonatomic, strong) UIImageView *placeholderView;
/**
 * @locale zh
 * @brief 右上角的更多（...）按钮。
 */
@property (nonatomic, strong) UIButton *actionButton;
/**
 * @locale zh
 * @brief 昵称底部的阴影 view。
 */
@property (nonatomic, strong) UIView *titleShadowView;
/**
 * @locale zh
 * @brief 昵称 label。
 */
@property (nonatomic, strong) UILabel *nameLabel;
/**
 * @locale zh
 * @brief 静音图标 view。
 */
@property (nonatomic, strong) UIImageView *muteMicIconView;
/**
 * @locale zh
 * @brief 连麦本地画面预览 view 点击回调。
 * @param view 当前点击的连麦本地画面预览 view。
 * @type keytype
 * @list 连麦
 */
/**
 * @locale en
 * @type keytype
 */
@property (nonatomic, copy) void(^onTapBlock)(BDLAudienceLinkPreviewView *view);

/**
 * @locale zh
 * @brief 显示静音图标。
 * @type keytype
 * @list 连麦
 */
/**
 * @locale en
 * @type keytype
 */
- (void)showMuteMicIconView;
/**
 * @locale zh
 * @brief 隐藏静音图标。
 * @type keytype
 * @list 连麦
 */
/**
 * @locale en
 * @type keytype
 */
- (void)hideMuteMicIconView;
/**
 * @locale zh
 * @brief 显示占位 view。
 * @type keytype
 * @list 连麦
 */
/**
 * @locale en
 * @type keytype
 */
- (void)showPlaceHolderView;
/**
 * @locale zh
 * @brief 隐藏占位 view。
 * @type keytype
 * @list 连麦
 */
/**
 * @locale en
 * @type keytype
 */
- (void)hidePlaceHolderView;

@end

NS_ASSUME_NONNULL_END
