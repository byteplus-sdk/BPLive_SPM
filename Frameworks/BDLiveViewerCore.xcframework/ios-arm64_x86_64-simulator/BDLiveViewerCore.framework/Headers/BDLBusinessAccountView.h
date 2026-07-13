//
//  BDLBusinessAccountView.h
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
#import <BDLiveCommon/BDLLanguageService.h>
#import "BDLBusinessAccountService.h"
#import "BDLPopularityService.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 主播账号 view，对应企业直播服务端的主播/品牌方账号功能。
 */
/**
 * @locale en
 * @brief The host account view, which corresponds to the host account feature of BytePlus Live.
 */
@interface BDLBusinessAccountView : BDLBaseView <BDLBusinessAccountService, BDLLanguageService, BDLPopularityService>

/**
 * @locale zh
 * @brief 头像。可自定义除圆角、图片、 `frame` 外的属性。
 */
/**
 * @locale en
 * @brief The avatar. All properties except rounded corners, image, and `frame` can be customized.
 */
@property (nonatomic, strong, readonly) UIImageView *avatarImageView;
/**
 * @locale zh
 * @brief 账号名称 label。可自定义除 `text` 和 `frame` 外的所有属性。
 */
/**
 * @locale en
 * @brief The account name label. All properties except `text` and `frame` can be customized.
 */
@property (nonatomic, strong, readonly) UILabel *nameLabel;
/**
 * @locale zh
 * @brief 人气 label，包含人气值和人气图标。可自定义除 `text`、`frame` 外的所有属性。
 */
/**
 * @locale en
 * @brief The popularity label, including the popularity value and popularity icon. All properties except `text` and `frame` can be customized.
 */
@property (nonatomic, strong, readonly) UILabel *popularityLabel;
/**
 * @locale zh
 * @brief 点击回调。
 * @param urlStr 企业直播服务端返回的跳转链接。
 */
/**
 * @locale en
 * @brief The callback is triggered when the host account view is tapped.
 * @param urlStr The embedded link, which is returned by the BytePlus Live server.
 */
@property (nonatomic, copy, nullable) void (^viewTappedBlock)(NSString * _Nullable urlStr);

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
