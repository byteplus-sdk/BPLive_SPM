//
//  BDLBasicModel.h
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
#import "BDLReplayModel.h"
#import "BDLDefines.h"
#import "BDLRiskWarningSettingModel.h"
#import "BDLAttentionDetectionConfigModel.h"
#import "BDLActTagModel.h"

@interface BDLBasicModel : BDLBaseModel

#pragma mark - 基本设置

// 活动名称
@property (nonatomic, copy) NSString *name;

// 活动状态 1直播中 2预告中 3回放 4结束
@property (nonatomic, assign) BDLActivityStatus status;

// 是否开启自动开播
//@property (nonatomic, assign) BOOL isAutoStartEnable;

// 活动描述
@property (nonatomic, assign) BOOL isAnnouncementEnable;
@property (nonatomic, copy) NSString *announcement;

/// 是否限制开播时间后才能开播
@property (nonatomic, assign) BOOL isBeginLiveEnable;
// 开播时间，unix时间戳
@property (nonatomic, strong) NSDate *liveTime;
/// 是否开启预约
@property (nonatomic, assign) BOOL reservationEnable;
@property (nonatomic, strong) NSDate *livingStartTime;

@property (nonatomic, copy) NSArray<BDLReplayModel *> *replays;

@property (nonatomic, copy) NSString *showLineName;
@property (nonatomic, copy) NSString *showReplayName;
#pragma mark - 高级功能

// 是否开启页面语言
@property (nonatomic, assign) BOOL isLanguageEnable;

// 所选的页面语言数组
@property (nonatomic, copy) NSArray<NSNumber *> *languageTypes;

// 直播间标签
@property (nonatomic, copy) NSArray<BDLActTagModel *> *siteTags;

// 是否开启倒计时
@property (nonatomic, assign) BOOL isCountdownEnable;
@property (nonatomic, assign) NSInteger countdown;

// 是否开启预告文案
@property (nonatomic, assign) BOOL isPreviewPromptEnable;

// 预告文案
@property (nonatomic, copy) NSString *previewPrompt;

// 是否开启预告片
@property (nonatomic, assign) BOOL isPreviewVideoEnable;
@property (nonatomic, copy) NSString *previewVideoUrl;

// 人气显示 开启后，在观看页显示观看人数
@property (nonatomic, assign) BOOL isPeopleCountEnable;

// 是否开启分享图标
@property (nonatomic, assign) BOOL isShareIconEnable;

// 分享图标
@property (nonatomic, copy) NSString *shareIconUrl;

// 是否开启页面限制
@property (nonatomic, assign) NSInteger isPageLimitEnable;

// 页面限制 mobile移动端
@property (nonatomic, copy) NSString *pageLimitType;

/// 评论举报功能开关
@property (nonatomic, assign) BOOL isTipOffCommentEnable;

@property (nonatomic, assign) BOOL isAutoEndEnable;

@property (nonatomic, strong) NSDate *endTime;

// MARK: - 认真度检测
@property (nonatomic, copy) NSArray<BDLAttentionDetectionConfigModel *> *attentionDetectionConfigArray;

#pragma mark - 外观设置

// 外观主题
@property (nonatomic, copy) NSString *colorThemeIndex;

// 外观主题类型
@property (nonatomic, assign, readonly) BDLColorThemeType localColorThemeType;  

// 直播封面
@property (nonatomic, copy) NSString *coverImageUrl;

/// 竖屏封面
@property (nonatomic, copy) NSString *verticalCoverImageUrl;

// 是否开启移动端背景图
@property (nonatomic, assign) BOOL isMobileBackImageEnable;

// 移动端背景图
@property (nonatomic, copy) NSString *mobileBackImage;

// 是否开启移动端页头图
@property (nonatomic, assign) BOOL isHeaderImageEnable;

// 移动端页头图
@property (nonatomic, copy) NSString *headerImageUrl;

// 背景模糊 开启后，将支持对PC端部分模块和移动端背景进行模糊处理
@property (nonatomic, assign) BOOL isBackgroundBlur;

// 水印
@property (nonatomic, assign) BOOL isWatermarkImageEnable;
@property (nonatomic, copy) NSString *watermarkImageUrl;
@property (nonatomic, assign) NSInteger watermarkPosition;

// 播放器置顶 开启后，将隐藏头图显示区域
@property (nonatomic, assign) BOOL isPlayerTopEnable;

// 互动区底色
@property (nonatomic, copy) NSString *interactionColor;

// 移动端评论底色
@property (nonatomic, copy) NSString *backgroundColor;
@property (nonatomic, copy) NSString *mobileBackgroundColor;
@property (nonatomic, copy) NSString *mobileChatBackgroundColor;
@property (nonatomic, assign) BOOL isColorSync;

// 文字颜色，默认为白色
@property (nonatomic, copy) NSString *fontColor;

// 主持人发言色
@property (nonatomic, copy) NSString *presenterChatColor;

@property (nonatomic, assign) BOOL isPlayPageWatermarkEnable;

/// 是否开启礼物打赏
@property (nonatomic, assign) BOOL isGiftRewardEnable;

#pragma mark - 分享海报

// 是否开启直播分享，开启后，观众可以在观看页将直播链接分享到微信、飞书等
// 1关闭 2开启
@property (nonatomic, assign) NSInteger canShare;
/// 是否开启邀请海报
@property (nonatomic, assign) NSInteger canInvite;

@property (nonatomic, strong) BDLRiskWarningSettingModel *riskWarningSetting;

- (BDLAttentionDetectionConfigModel *)attentionDetectionModelWithType:(BDLAttentionDetectionConfigType)type;
- (BOOL)isMobilePullAllowed;
- (BOOL)isCoverImageEqual:(BDLBasicModel *)object;
- (BOOL)isVerticalCoverImageEqual:(BDLBasicModel *)object;
- (BOOL)isHeaderImageEqual:(BDLBasicModel *)object;
- (BOOL)isWatermarkImageEqual:(BDLBasicModel *)object;
- (BOOL)isPreviewPromptEqual:(BDLBasicModel *)object;
- (BOOL)isPreviewVideoEqual:(BDLBasicModel *)object;
- (BOOL)isMobileBackImageEqual:(BDLBasicModel *)object;
- (BOOL)isBackgroundColorEqual:(BDLBasicModel *)object;
- (BOOL)isFontColorEqual:(BDLBasicModel *)object;
- (BOOL)isColorThemeIndexEqual:(BDLBasicModel *)object;
- (BOOL)isLanguageTypeArrayEqual:(BDLBasicModel *)object;
- (BOOL)containsLanguageType:(BDLLanguageType)langType;
- (BOOL)isLanguageEqual:(BDLBasicModel *)object;
- (BOOL)isMultiLanguageEnabled;
- (BOOL)isReplaysEqual:(BDLBasicModel *)object;
- (BOOL)isCountdownEqual:(BDLBasicModel *)object;
- (BOOL)shouldShowCountdown;
- (BOOL)shouldShowPreviewPrompt;

- (BOOL)isLightColorTheme;

@end
