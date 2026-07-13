//
//  BDLCommentConfigModel.h
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

// 聊天互动
@interface BDLCommentConfigModel : BDLBaseModel

// 是否开启热门列表
@property (nonatomic, assign) BOOL isHotListEnable;

// 热门列表名称
@property (nonatomic, copy) NSString *hotListName;

// 热门条数
@property (nonatomic, assign) NSInteger hotListCount;

// 显示赞数 关闭后，实时评论和热门评论不显示点赞按钮及赞数
@property (nonatomic, assign) BOOL isLikeNumberShowEnable;

// 发言间隔
@property (nonatomic, assign) NSInteger voiceInterval;

// 输入框提示
@property (nonatomic, copy) NSString *inputBoxPrompt;

// 主持人昵称
@property (nonatomic, copy) NSString *presenterName;

// 是否开启弹幕
@property (nonatomic, assign) BOOL isBulletScreenEnable;

// 是否开启评论翻译 评论翻译需要打开页面语言开关才能使用
@property (nonatomic, assign) BOOL isCommentTranslateEnable;

// 是否允许发送评论
@property (nonatomic, assign) NSInteger isSendCommentEnable;

// 是否允许发送图片
@property (nonatomic, assign) BOOL isImageCommentEnable;

/// 是否开启聊天欢迎语
@property (nonatomic, assign) BOOL welcomeMessageEnable;
/// 聊天欢迎语标题
@property (nonatomic, copy) NSString *welcomeMessageTitle;
/// 聊天欢迎语内容
@property (nonatomic, copy) NSString *welcomeMessageContent;

/// 允许查看正在购买消息
@property (nonatomic, assign) BOOL isViewInPurchaseEnable;

/// 允许查看下单消息
@property (nonatomic, assign) BOOL isViewOrderEnable;

- (BOOL)isHotListEqual:(BDLCommentConfigModel *)object;

@end
