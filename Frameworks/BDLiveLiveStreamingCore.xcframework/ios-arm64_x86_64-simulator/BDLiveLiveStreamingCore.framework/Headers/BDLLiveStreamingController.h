//
//  BDLLiveStreamingController.h
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


#import "BDLEffectConfig.h"

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class BDLLiveStreamingController;

@protocol BDLLiveStreamingControllerDelegate <NSObject>

- (void)liveStreamingControllerCloseButtonDidClick:(BDLLiveStreamingController *)controller;

@optional
- (void)liveStreamingController:(BDLLiveStreamingController *)controller orientationDidChange:(UIInterfaceOrientation)orientation;

- (void)liveStreamingControllerDidStartStreaming:(BDLLiveStreamingController *)controller;
- (void)liveStreamingControllerDidEndStreaming:(BDLLiveStreamingController *)controller;

- (void)liveStreamingControllerDidLoad:(BDLLiveStreamingController *)controller;
- (void)liveStreamingControllerWillAppear:(BDLLiveStreamingController *)controller animated:(BOOL)animated;
- (void)liveStreamingControllerDidAppear:(BDLLiveStreamingController *)controller animated:(BOOL)animated;
- (void)liveStreamingControllerWillDisappear:(BDLLiveStreamingController *)controller animated:(BOOL)animated;
- (void)liveStreamingControllerDidDisappear:(BDLLiveStreamingController *)controller animated:(BOOL)animated;

@end

@interface BDLLiveStreamingController : UIViewController

- (void)setDelegate:(id <BDLLiveStreamingControllerDelegate>)delegate;

/// 内容的view,可以往上面加东西,区域为safeArea, viewDidLoad中赋值
@property (nonatomic, strong, readonly) UIView *contentView;

@property (nonatomic, copy, nullable) __kindof UIView *_Nullable (^customizedCommentView)(BDLLiveStreamingController *vc, UIView *commentView);
@property (nonatomic, copy, nullable) void (^customizedScreenShareBackgroundImageView)(BDLLiveStreamingController *vc, UIImageView *backgroundImageView);

@end

NS_ASSUME_NONNULL_END
