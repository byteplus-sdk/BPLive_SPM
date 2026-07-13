//
//  BDLAdvertisementModel.h
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

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

/**
 * @locale zh
 * @type keytype
 * @brief 广告类型。
 */
/**
 * @locale en
 * @type keytype
 * @brief The ad type.
 */
typedef NS_ENUM(NSInteger, BDLPageAdvertisementType) {
/**
 * @locale zh
 * @brief 页头广告。
 */
   /**
    * @locale en
    * @brief Header ads.
    */
    BDLPageAdvertisementTypePageHeaderAd = 1,
/**
 * @locale zh
 * @brief 页中广告。
 */
   /**
    * @locale en
    * @brief In-page ads.
    */
    BDLPageAdvertisementTypePageAd,
/**
 * @locale zh
 * @brief 浮标广告。
 */
   /**
    * @locale en
    * @brief Floating ads.
    */
    BDLPageAdvertisementTypeFloatingAd,
/**
 * @locale zh
 * @brief 商品卡片。
 */
   /**
    * @locale en
    * @brief Product cards.
    */
    BDLPageAdvertisementTypeCardAd,
};

/**
 * @locale zh
 * @type keytype
 * @brief 广告 Model。
 */
/**
 * @locale en
 * @type keytype
 * @brief The ad model.
 */
@interface BDLAdvertisementModel : BDLBaseModel
/**
 * @locale zh
 * @brief 广告 ID。
 */
/**
 * @locale en
 * @brief The ad ID.
 */
@property (nonatomic, strong) NSNumber *Id;
/**
 * @locale zh
 * @brief 广告的 index。
 */
/**
 * @locale en
 * @brief The ad index.
 */
@property (nonatomic, assign) NSInteger index;
/**
 * @locale zh
 * @brief 广告内容。当前为广告配置的图片地址。
 */
/**
 * @locale en
 * @brief The ad content, which is currently the image URL configured for the ad.
 */
@property (nonatomic, copy) NSString* advertisementContent;
/**
 * @locale zh
 * @brief 跳转链接。
 */
/**
 * @locale en
 * @brief The embedded link.
 */
@property (nonatomic, copy) NSString* advertisementRedirectUrl;
/**
 * @locale zh
 * @brief 广告类型。详见 [BDLPageAdvertisementType](#BDLPageAdvertisementType)。
 */
/**
 * @locale en
 * @brief The ad type. For more information, see [BDLPageAdvertisementType](#BDLPageAdvertisementType).
 */
@property (nonatomic, assign) BDLPageAdvertisementType pageAdvertisementType;
/**
 * @locale zh
 * @brief 是否为页头广告。
 * @return - `YES`：页头广告。
 *         - `NO`：非页头广告。
 */
/**
 * @locale en
 * @brief Whether it is a header ad.
 * @return - `YES`: A header ad.
 *         - `NO`: Not a header ad.
 */
- (BOOL)isPageHeaderAd;
/**
 * @locale zh
 * @brief 是否为页中广告。
 * @return - `YES`：页中广告。
 *         - `NO`：非页中广告。
 */
/**
 * @locale en
 * @brief Whether it is an in-page ad.
 * @return - `YES`: An in-page ad.
 *         - `NO`: Not an in-page ad.
 */
- (BOOL)isPageAd;
/**
 * @locale zh
 * @brief 是否为浮标广告。
 * @return - `YES`：浮标广告。
 *         - `NO`：非浮标广告。
 */
/**
 * @locale en
 * @brief Whether it is a floating ad.
 * @return - `YES`: A floating ad.
 *         - `NO`: Not a floating ad.
 */
- (BOOL)isPageUpperAd;
/**
 * @locale zh
 * @brief 是否为商品卡片。
 * @return - `YES`：商品卡片。
 *         - `NO`：非商品卡片。
 */
/**
 * @locale en
 * @brief Whether it is a product card.
 * @return - `YES`: A product card.
 *         - `NO`: Not a product card.
 */
- (BOOL)isCardAd;
/**
 * @locale zh
 * @brief 缩放后适合显示的大小。非企业直播服务端返回数据。
 */
/**
 * @locale en
 * @brief The size suitable for display after scaling in. Not returned by the BytePlus Live server.
 */
@property (nonatomic, assign) CGSize scaledSize;

@end

#pragma clang diagnostic pop
