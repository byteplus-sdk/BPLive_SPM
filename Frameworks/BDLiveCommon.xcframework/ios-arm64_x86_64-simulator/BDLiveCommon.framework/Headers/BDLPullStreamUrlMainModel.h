//
//  BDLPullStreamUrlMainModel.h
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
#import <BDLiveBase/BDLBaseModel.h>

/**
 * @locale zh
 * @type keytype
 * @brief url信息，包含了播放地址
 */
@interface BDLPullStreamMainUrlModel : BDLBaseModel

@property (nonatomic, copy) NSString *flvUrl;
//@property (nonatomic, copy) NSString *hlsUrl;
//@property (nonatomic, copy) NSString *rtmpUrl;

@property (nonatomic, copy) NSString *llsUrl;
/// 支持时移的流
@property (nonatomic, copy) NSString *tslUrl;

- (BOOL)isValid;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 播放地址信息的Model，包含size以及对应的主备流信息
 */
@interface BDLPullStreamUrlMainModel : BDLBaseModel

@property (nonatomic, copy) NSString *size;

@property (nonatomic, copy) NSString *vCodec;

/// 主url
@property (nonatomic, strong) BDLPullStreamMainUrlModel *url;
/// 备用url
@property (nonatomic, copy) NSArray<BDLPullStreamMainUrlModel *> *backupUrl;

- (void)resetCursor;

/// 获取当前正在播放的信息，即上次调用  getWillPlayUrlMainModel 的返回值
- (BDLPullStreamMainUrlModel *)getNowPlayingUrlMainModel:(BOOL *)isMain;

/// 获取即将播放的URL Model的信息，可能是主流，也可能是备流
/// 返回空则表示没有符合条件的可以播放的流信息
- (BDLPullStreamMainUrlModel *)getWillPlayUrlMainModel:(BOOL *)isMain;

@end
