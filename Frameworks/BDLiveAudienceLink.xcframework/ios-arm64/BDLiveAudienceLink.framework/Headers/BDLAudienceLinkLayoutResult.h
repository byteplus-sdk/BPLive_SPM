//
//  BDLAudienceLinkLayoutResult.h
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
#import "BDLAudienceLinkUser.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type keytype
 * @brief 单个连麦参与者的连麦布局信息 Model。
 */
/**
 * @locale en
 * @type keytype
 * @hidden (iOS)
 */
@interface BDLAudienceLinkLayoutRegion : BDLBaseModel
/**
 * @locale zh
 * @brief 画面左上角的 x 轴坐标。取值范围为 [0, 1]。`0` 代表最左边，`1` 代表最右边。
 */
@property (nonatomic, assign) CGFloat locationX;

/**
 * @locale zh
 * @brief 画面左上角的 y 轴坐标。取值范围为 [0, 1]。`0` 代表最上边，`1` 代表最下边。
 */
@property (nonatomic, assign) CGFloat locationY;
/**
 * @locale zh
 * @brief 相对于画布的宽度。取值范围为 [0, 1]。
 */
@property (nonatomic, assign) CGFloat widthProportion;
/**
 * @locale zh
 * @brief 相对于画布的高度。取值范围为 [0, 1]。
 */
@property (nonatomic, assign) CGFloat heightProportion;
/**
 * @locale zh
 * @brief 透明度。取值范围为 [0, 1]。取值越大，透明度越低。
 */
@property (nonatomic, assign) CGFloat alpha;
/**
 * @locale zh
 * @brief 画面左上角的 z 轴坐标。取值越大，画面越靠上。
 */
@property (nonatomic, assign) NSUInteger zOrder;
/**
 * @locale zh
 * @brief 画面的占位图地址。
 */
@property (nonatomic, copy) NSString *userCoverImage;

@end

/**
 * @locale zh
 * @brief 连麦用户信息 Model。
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@interface BDLAudienceLinkLayoutUser : BDLBaseModel

/**
 * @locale zh
 * @brief 连麦流类型。详见 [BDLAudienceLinkStreamType](1185544#BDLAudienceLinkStreamType)。
 */
@property (nonatomic, assign) BDLAudienceLinkStreamType streamType;
/**
 * @locale zh
 * @brief 连麦布局信息。详见 [BDLAudienceLinkLayoutRegion](1185544#BDLAudienceLinkLayoutRegion)。
 */
@property (nonatomic, strong) BDLAudienceLinkLayoutRegion *region;
/**
 * @locale zh
 * @brief 连麦用户信息。详见 [BDLAudienceLinkUser](1185544#BDLAudienceLinkUser)。
 */
@property (nonatomic, strong) BDLAudienceLinkUser *userInfo;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 连麦布局风格。
 */
/**
 * @locale en
 * @type keytype
 * @hidden (iOS)
 */
typedef NS_ENUM(NSUInteger, BDLAudienceLinkLayoutType) {
    /**
     * @locale zh
     * @brief 全屏模式。
     * @hidden (iOS)
     */
    BDLAudienceLinkLayoutTypeFullScreen = 1,
    /**
     * @locale zh
     * @brief 宫格视图。
     */
    BDLAudienceLinkLayoutTypeGrid,
    /**
     * @locale zh
     * @brief 演讲者视图。
     */
    BDLAudienceLinkLayoutTypePresentation,
    /**
     * @locale zh
     * @brief 特写视图。
     */
    BDLAudienceLinkLayoutTypeCloseup,
};

/**
 * @locale zh
 * @type keytype
 * @brief 连麦布局 Model。
 */
/**
 * @locale en
 * @type keytype
 * @hidden (iOS)
 */
@interface BDLAudienceLinkLayoutResult : BDLBaseModel
/**
 * @locale zh
 * @brief 布局中的连麦用户信息。详见 [BDLAudienceLinkLayoutUser](1185540#BDLAudienceLinkLayoutUser)。
 */
@property (nonatomic, copy) NSArray<BDLAudienceLinkLayoutUser *> *layoutUsers;
/**
 * @locale zh
 * @brief 布局更新时间。Unix 时间戳，单位为秒。
 */
@property (nonatomic, assign) NSInteger updateTime;
/**
 * @locale zh
 * @brief 布局风格。详见 [BDLAudienceLinkLayoutType](#BDLAudienceLinkLayoutType)。
 */
@property (nonatomic, assign) BDLAudienceLinkLayoutType layout;
/**
 * @locale zh
 * @brief 画面宽高比。
 */
@property (nonatomic, assign) double aspectRatio;

@end

NS_ASSUME_NONNULL_END
