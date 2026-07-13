//
//  BDLCardModel.h
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

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type keytype
 * @brief 商品卡片点击来源。
 */
/**
 * @locale en
 * @brief The product card tap source.
 * @type keytype
 */
typedef NS_ENUM(NSInteger, BDLShoppingCardClickPosition) {
    /**
     * @locale zh
     * @brief 浮窗卡片 view。
     */
   /**
    * @locale en
    * @brief The floating product card view.
    */
    BDLShoppingCardClickPositionFloatingCardView = 1,
    /**
     * @locale zh
     * @brief 卡片列表 view。
     */
   /**
    * @locale en
    * @brief The card list view.
    */
    BDLShoppingCardClickPositionCardView,
    /**
     * @locale zh
     * @brief 卡片搜索结果 view。
     */
   /**
    * @locale en
    * @brief The product card search result view.
    */
    BDLShoppingCardClickPositionCardSearchView,
    /**
     * @locale zh
     * @brief 聊天区域中，查看商品消息和下单购买消息中的“立即购买” view。
     */
   /**
    * @locale en
    * @brief The "Buy Now" view in the chat area for viewing product messages and order messages.
    */
    BDLShoppingCardClickPositionBuyAndOrderedNoticeView,
};

/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
typedef NS_ENUM(NSUInteger, BDLCardPromotionTagType) {
    BDLCardPromotionTagTypeNone,
    BDLCardPromotionTagTypeCustom,
    BDLCardPromotionTagTypeSuperValue,
    BDLCardPromotionTagTypeSpecialOffer,
    BDLCardPromotionTagTypeLowPrice,
};

/**
 * @locale zh
 * @type keytype
 * @brief 商品卡片 Model。
 */
/**
 * @locale en
 * @type keytype
 * @brief The product card model.
 */
@interface BDLCardModel : BDLBaseModel
/**
 * @locale zh
 * @brief 商品 ID。
 */
/**
 * @locale en
 * @brief The product ID.
 */
@property (nonatomic, strong) NSNumber *Id;
/**
 * @locale zh
 * @brief 商品序号。
 */
/**
 * @locale en
 * @brief The product index.
 */
@property (nonatomic, assign) NSInteger index;
/**
 * @locale zh
 * @brief 商品名称。
 */
/**
 * @locale en
 * @brief The product name.
 */
@property (nonatomic, copy) NSString *title;
/**
 * @locale zh
 * @brief 商品售卖价。
 */
/**
 * @locale en
 * @brief The product's retail price.
 */
@property (nonatomic, copy) NSString *highlight;
/**
 * @locale zh
 * @brief 商品参考价。
 */
/**
 * @locale en
 * @brief The product's list price.
 */
@property (nonatomic, copy) NSString *strikeThrough;
/**
 * @locale zh
 * @brief 商品图。
 */
/**
 * @locale en
 * @brief The product image.
 */
@property (nonatomic, copy) NSString *introduceImage;
/**
 * @locale zh
 * @brief 商品跳转图。
 */
/**
 * @locale en
 * @brief The product's button image.
 */
@property (nonatomic, copy) NSString *redirectImage;
/**
 * @locale zh
 * @brief 商品跳转链接。
 */
/**
 * @locale en
 * @brief The product URL.
 */
@property (nonatomic, copy) NSString *redirectUrl;
/**
 * @locale zh
 * @brief 商品直达链接。
 */
/**
 * @locale en
 * @brief The product's direct URL.
 */
@property (nonatomic, copy) NSString *directUrl;
/**
 * @locale zh
 * @brief 商品是否已上架。取值如下：
 *        - `0`：未上架。
 *        - `1`：已上架。
 */
/**
 * @locale en
 * @brief Whether the product is listed on the viewing page. Valid values:
 *        - `0`: Not listed.
 *        - `1`: Listed.
 */
@property (nonatomic, assign) NSInteger enableStatus;
/**
 * @locale zh
 * @brief 是否浮窗展示商品卡片。取值如下：
 *        - `0`：非浮窗展示。
 *        - `1`：浮窗展示。
 *        :::tip
 *        仅在不开启直播时移功能时，该属性才生效。
 *        :::
 */
/**
 * @locale en
 * @brief Whether the product is featured, namely pinned to the top of the menu and displayed in a floating window on the viewing page. Valid values:
 *        - `0`: Unfeatured.
 *        - `1`: Featured.
 */
@property (nonatomic, assign) NSInteger floatingStatus;
/**
 * @locale zh
 * @brief 浮窗展示时间，Unix 时间戳，单位为秒。
 */
/**
 * @locale en
 * @list 
 * @brief Floating window display time, in Unix timestamp (seconds).
 * @hidden (iOS)
 */
@property (nonatomic, assign) NSInteger floatingTime;
/**
 * @locale zh
 * @brief 是否隐藏价格。商品价格隐藏后，观看页的商品售卖价将以“待开价￥???”的文案展示。取值如下：
 *        - `0`：不隐藏价格。
 *        - `1`：隐藏价格。
 */
/**
 * @locale en
 * @list 
 * @hidden (iOS)
 */
@property (nonatomic, assign) BOOL priceHidden;
/**
 * @locale zh
 * @brief 是否售罄。商品售罄后，观看页的商品图和跳转图将展示“已抢光”的文案。取值如下：
 *        - `0`：未售罄。
 *        - `1`：售罄。
 */
/**
 * @locale en
 * @list 
 * @hidden (iOS)
 */
@property (nonatomic, assign) BOOL outOfStock;
/**
 * @locale zh
 * @brief 商品是否正在讲解中。取值如下：
 *        - `0`：非讲解中。
 *        - `1`：讲解中。
 *        :::tip
 *        仅在开启直播时移功能时，该属性才生效。有关如何开启直播时移功能，详见[直播时移](https://www.volcengine.com/docs/3019/128810)。
 *        :::
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@property (nonatomic, assign) NSInteger explainStatus;
/**
 * @locale zh
 * @brief 商品介绍。
 */
/**
 * @locale en
 * @brief The product description.
 */
@property (nonatomic, copy) NSString *remark;
/**
 * @locale zh
 * @brief 商品讲解开始时间。
 */
/**
 * @locale en
 * @brief The start time when the product is pinned to the top of the menu and displayed in a floating window on the viewing page.
 */
@property (nonatomic, strong, nullable) NSDate *explainTime;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property (nonatomic, copy) NSString *sellingPointTag;
/**
 * @locale zh
 * @brief 活动标签图片地址
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property (nonatomic, copy) NSString *promotionTagUrl;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property (nonatomic, assign) BDLCardPromotionTagType promotionTagType;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property (nonatomic, assign) BOOL isOrderMsgEnable;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property (nonatomic, copy) NSArray<NSString *> *localSellingPointTags;
/**
 * @locale zh
 * @brief 按服务端返回的顺序，去除了未上架的卡片的连续的index
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property (nonatomic, assign) NSUInteger localIndex;
/**
 * @locale zh
 * @brief 浮层交互 开启后，跳转链接实现直播页内跳转
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property (nonatomic, assign) BOOL localEnableFloating;
/**
 * @locale zh
 * @brief 标记商品讲解是否是本次直播期间的，避免显示上次直播的商品讲解
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
- (void)setExplainIsEarlyThanLivingStart:(BOOL)explainIsEarlyThanLivingStart;
/**
 * @locale zh
 * @brief 商品讲解开始时间是否在直播时移的生效时间范围内，即是否距离当前方法调用时间超过 8 小时。
 * @return - `YES`：超过 8 小时，直播时移已失效，无法跳转至商品讲解开始时间。
 *         - `NO`：未超过 8小时。
 */
/**
 * @locale en
 * @hidden (iOS)
 */
- (BOOL)isExplainTimeout;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
