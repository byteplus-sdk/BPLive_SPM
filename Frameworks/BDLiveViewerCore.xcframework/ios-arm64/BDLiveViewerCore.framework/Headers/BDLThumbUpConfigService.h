//
//  BDLThumbUpConfigService.h
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
#import <BDLiveCommon/BDLThumbUpConfigModel.h>

NS_ASSUME_NONNULL_BEGIN

/// 点赞相关配置的service
@protocol BDLThumbUpConfigService <NSObject>

/// 点赞图片改变
/// @param url 改变后的图片地址
/// @param isEnabled 是否支持点赞
- (void)thumbUpDidChange:(NSString *)url isEnabled:(BOOL)isEnabled;

- (void)thumbUpConfigDidChangeFrom:(nullable BDLThumbUpConfigModel *) oldModel to:(BDLThumbUpConfigModel *)toModel;

@end

NS_ASSUME_NONNULL_END
