//
//  BDLMenuBarModel.h
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
#import "BDLProductModel.h"
#import "BDLMarketingPromotionModel.h"
#import "BDLVerticalIconUrlModel.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

/**
 * @locale zh
 * @type keytype
 * @brief 菜单类型。
 */
/**
 * @locale en
 * @type keytype
 * @brief The menu type.
 */
typedef NS_ENUM(NSInteger, BDLMenuType) {
    /**
     * @locale zh
     * @brief 图文介绍。
     */
   /**
    * @locale en
    * @brief Graphics.
    */
    BDLMenuTypeImageText = 1,
    /**
     * @locale zh
     * @brief 商品卡片。
     */
   /**
    * @locale en
    * @brief Product cards.
    */
    BDLMenuTypeCard,
    /**
     * @locale zh
     * @brief 聊天互动。
     */
   /**
    * @locale en
    * @brief Chat interaction.
    */
    BDLMenuTypeComment,
    /**
     * @locale zh
     * @brief 互动工具。
     */
   /**
    * @locale en
    * @brief Interaction tools.
    */
    BDLMenuTypeInteractiveTool,
    /**
     * @locale zh
     * @brief 内嵌链接。
     */
   /**
    * @locale en
    * @brief Embedded link.
    */
    BDLMenuTypeEmbeddedWebUrl = 7,
    /**
     * @locale zh
     * @brief 私聊互动。
     */
   /**
    * @locale en
    * @hidden (iOS)
    * @brief Direct messaging interaction.
    */
    BDLMenuTypePrivateChat = 8,
};

/**
 * @locale zh
 * @type keytype
 * @brief 内嵌链接菜单 Model。
 */
/**
 * @locale en
 * @type keytype
 * @brief The model of embedded link menu.
 */
@interface BDLEmbeddedWebModel : BDLBaseModel
/**
 * @locale zh
 * @brief Model ID。
 */
/**
 * @locale en
 * @brief The ID of this model.
 */
@property (nonatomic, assign) NSInteger embeddedWebId;
/**
 * @locale zh
 * @brief URL。
 */
/**
 * @locale en
 * @brief The URL.
 */
@property (nonatomic, copy) NSString *mobileUrl;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 菜单栏信息 Model。
 */
/**
 * @locale en
 * @type keytype
 * @brief The model of menu bar information.
 */
@interface BDLMenuModel : BDLBaseModel

/**
 * @locale zh
 * @brief 菜单名称。
 */
/**
 * @locale en
 * @brief The menu name.
 */
@property (nonatomic, copy) NSString *name;
/**
 * @locale zh
 * @brief 菜单类型。详见 [BDLMenuType](#BDLMenuType)。
 */
/**
 * @locale en
 * @brief The menu type. For more information, see [BDLMenuType](#BDLMenuType).
 */
@property (nonatomic, assign) BDLMenuType type;
/**
 * @locale zh
 * @brief 菜单显示索引。
 */
/**
 * @locale en
 * @brief The display index of the menu.
 */
@property (nonatomic, assign) NSInteger index;

/**
 * @locale zh
 * @brief 内嵌链接信息 Model。详见 [BDLEmbeddedWebModel](#BDLEmbeddedWebModel)。非企业直播服务端返回数据。
 */
/**
 * @locale en
 * @brief The model of embedded link information. Not returned by the BytePlus Live server. For more information, see [BDLEmbeddedWebModel](#BDLEmbeddedWebModel).
 */
@property (nonatomic, weak) BDLEmbeddedWebModel *localEmbeddedWebModel;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 私聊配置。
 */
/**
 * @locale en
 * @type keytype
 * @hidden (iOS)
 * @brief Private chat configuration.
 */
@interface BDLPrivateChatConfig : BDLBaseModel

/**
 * @locale zh
 * @brief 主持人昵称。
 */
/**
 * @locale en
 * @brief Host Nickname.
 */
@property (nonatomic, copy) NSString *nickname;
/**
 * @locale zh
 * @brief 输入框提示。
 */
/**
 * @locale en
 * @brief Input field placeholder.
 */
@property (nonatomic, copy) NSString *textTip;
/**
 * @locale zh
 * @brief 发言间隔。单位：秒。
 */
/**
 * @locale en
 * @brief Speech interval. Unit: seconds.
 */
@property (nonatomic, assign) NSInteger commentInterval;
/**
 * @locale zh
 * @brief 菜单 ID。
 */
/**
 * @locale en
 * @brief Menu ID.
 */
@property (nonatomic, assign) NSInteger menuId;

@end

/**
 * @locale zh
 * @hidden (iOS)
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@interface BDLMenuBarModel : BDLBaseModel

// 菜单栏
@property (nonatomic, copy) NSArray<BDLMenuModel *> *menus;

// 营销推广
@property (nonatomic, strong) BDLMarketingPromotionModel *market;

// 商品卡片
@property (nonatomic, strong) NSDictionary<NSString *, BDLProductModel *> *product;

// key 图文菜单Index
// value 图文菜单内容
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> *richText;

/// 私聊配置
@property (nonatomic, strong) BDLPrivateChatConfig *privateChatConfig;

@property (nonatomic, strong) BDLVerticalIconUrlModel *verticalIconUrlModel;

@property (nonatomic, copy) NSDictionary<NSString *, BDLEmbeddedWebModel *> *embeddedWebUrls;

- (void)discardUnsupportedMenu;
- (BOOL)hasImageTextMenu;
- (BOOL)hasCardMenu;
- (BOOL)hasCommentMenu;
- (BOOL)hasInteractiveToolMenu;

- (NSArray<BDLMenuModel *> *)getImageTextMenu;
- (NSArray<BDLMenuModel *> *)getCardMenu;
- (BDLMenuModel *)getCommentMenu;
- (BDLMenuModel *)getInteractiveToolMenu;
- (BDLMenuModel *)getPrivateChatModel;

- (BOOL)isMenusEqual:(BDLMenuBarModel *)object;
- (BOOL)isMarketEqual:(BDLMenuBarModel *)object;
- (BOOL)isProductEqual:(BDLMenuBarModel *)object;
- (BOOL)isRichTextEqual:(BDLMenuBarModel *)object;


@end

#pragma clang diagnostic pop

