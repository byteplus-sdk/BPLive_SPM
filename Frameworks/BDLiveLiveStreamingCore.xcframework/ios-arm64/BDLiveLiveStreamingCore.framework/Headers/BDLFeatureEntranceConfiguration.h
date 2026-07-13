//
//  BDLFeatureEntranceConfiguration.h
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

/**
 * @locale zh
 * @type keytype
 * @brief 功能开关配置。
 */
/**
 * @locale en
 * @type keytype
 */
@interface BDLFeatureEntranceConfiguration : NSObject

/**
 * @locale zh
 * @brief 是否显示美颜入口 注：需要接入CV功能，否则无法打开，默认为YES
  */
@property (nonatomic, assign) BOOL showBeautyEntrance;
/**
 * @locale zh
 * @brief 是否显示道具入口 注：需要接入CV功能，否则无法打开，默认为YES
  */
@property (nonatomic, assign) BOOL showPropsEntrance;
/**
 * @locale zh
 * @brief 是否显示挂件和图层入口 注：若此功能关闭，则云模版功能也会被关闭，默认为YES
  */
@property (nonatomic, assign) BOOL showPendentEntrance;
/**
 * @locale zh
 * @brief 是否可以编辑直播间信息（封面、标题），默认为YES
  */
@property (nonatomic, assign) BOOL editLiveInfoEnable;
/**
 * @locale zh
 * @brief 是否显示云模板入口，当挂件和图层被关闭后，云模版也会被关闭，默认为YES
  */
@property (nonatomic, assign) BOOL showCloudTemplateEntrance;
/**
 * @locale zh
 * @brief 是否可以编辑云模板，默认为YES
  */
@property (nonatomic, assign) BOOL editCloudTemplateEnable;
/**
 * @locale zh
 * @brief 是否显示切换摄像头功能，默认为YES
  */
@property (nonatomic, assign) BOOL showSwitchCamera;
/**
 * @locale zh
 * @brief 是否显示切换横竖屏功能，默认为YES
  */
@property (nonatomic, assign) BOOL showRotateScreen;
/**
 * @locale zh
 * @brief 是否显示切换清晰度功能，默认为YES
  */
@property (nonatomic, assign) BOOL showChangeResolution;
/**
 * @locale zh
 * @brief 是否显示媒体文件混流入口，默认为NO
  */
@property (nonatomic, assign) BOOL showMediaMergeEntrance;
/**
 * @locale zh
 * @brief 是否显示文字混流入口，默认为NO
  */
@property (nonatomic, assign) BOOL showTextMergeEntrance;
@end

NS_ASSUME_NONNULL_END
