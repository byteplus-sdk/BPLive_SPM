//
//  BDLToolCellModel.h
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

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, BDLToolType) { // 工具类型
    BDLToolTypeMirror = 1,                ///< 镜像
    BDLToolTypeScreenRecord,              ///< 录屏
    BDLToolTypeFlashLight,                ///< 闪光灯
    BDLToolTypeMute,                      ///< 静音
    BDLToolTypeClearScreen,               ///< 清屏
    BDLToolTypeMedia,                     ///< 媒体文件
    BDLToolTypeText,                      ///< 媒体文件
    BDLToolTypeClearComment,              ///< 清空评论
    BDLToolTypePendent,                   ///< 挂件
    BDLToolTypeLayer,                     ///< 图层
    BDLToolTypeFlip,                      ///< 翻转
    BDLToolTypeBeauty,                    ///< 美颜
    BDLToolTypeProps,                     ///< 道具
};

@interface BDLToolCellModel : NSObject

/// 是否选中
@property (nonatomic, assign) BOOL selected;

/// 标题
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *imgName;

/// 工具类型
@property (nonatomic, assign) BDLToolType toolType;

@end

NS_ASSUME_NONNULL_END
