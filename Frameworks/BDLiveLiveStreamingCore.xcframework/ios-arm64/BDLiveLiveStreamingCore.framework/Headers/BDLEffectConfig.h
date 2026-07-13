//
//  BDLEffectConfig.h
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

#import <Foundation/Foundation.h>

#import "BDLEffectBeautyModel.h"
#import "BDLEffectFilterModel.h"
#import "BDLEffectStickerModel.h"

NS_ASSUME_NONNULL_BEGIN

/// 美颜相关的配置
@interface BDLEffectConfig : NSObject

// 默认为mainBundle Path
@property (nonatomic, copy) NSString *resourceBundlePath;
// 这个是通过iconName获取icon的Bundle
@property (nonatomic, strong) NSBundle *iconBundle;

/// 自定义美颜
/// 在需要自定义美颜时, SDK会调用此Block, 您可实现此Block, 直接修改beauties数组
@property (nonatomic, copy) void (^customizeBeauties)(NSMutableArray<BDLEffectBeautyModel *> *beauties);

/// 自定义滤镜
/// 您可直接修改filters数组
@property (nonatomic, copy) void (^customizeFilters)(NSMutableArray<BDLEffectFilterModel *> *filters);

/// 自定义贴纸
/// 您可直接修改stickers数组
@property (nonatomic, copy) void (^customizeStickers)(NSMutableArray<BDLEffectStickerModel *> *stickers);

@end

NS_ASSUME_NONNULL_END
