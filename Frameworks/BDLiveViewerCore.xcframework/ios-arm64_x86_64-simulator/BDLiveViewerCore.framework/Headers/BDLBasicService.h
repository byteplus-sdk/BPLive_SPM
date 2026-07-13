//
//  BDLBasicService.h
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
#import <UIKit/UIKit.h>
#import <BDLiveCommon/BDLDefines.h>
#import <BDLiveCommon/BDLBasicModel.h>
#import "BDLActivityModel.h"

NS_ASSUME_NONNULL_BEGIN

/// 活动basic改变的service
@protocol BDLBasicService <NSObject>

@optional

/// basic改变的方法
/// 只要有任一属性改变就会被调用
/// @param model 最新的数据
- (void)activityBasicDidChange:(BDLBasicModel *)model;

/// basic改变的方法
/// @param activity 最新的活动数据
/// @param basic 最新的basic数据
/// @param oldBasic old值
- (void)activity:(BDLActivityModel *)activity basicDidChange:(BDLBasicModel *)basic oldBasic:(nullable BDLBasicModel *)oldBasic;

// MARK: - 单独改变的回调

/// activity 状态改变的回调
/// @param status 改变后的状态,具体见 BDLActivityStatus
- (void)activityStatusDidChange:(BDLActivityStatus)status;

/// activity封面图改变了
/// @param url 改变后的图片地址
- (void)coverImageDidChange:(NSString *)url;

/// activity 水印图片改变了
/// @param url 改变后的图片地址
/// @param isEnabled 是否显示水印图片
- (void)watermarkImageDidChange:(NSString *)url isEnabled:(BOOL)isEnabled;

/// 移动端背景图改变
/// @param url 改变后的图片地址
/// @param isEnabled 是否显示移动端背景图
- (void)mobileBackImageDidChange:(NSString *)url isEnabled:(BOOL)isEnabled;

/// 预览状态提示文案改变
/// @param previewPrompt 改变后的文案
/// @param isEnabled 是否显示预览文案
- (void)previewPromptDidChange:(NSString *)previewPrompt isEnabled:(BOOL)isEnabled;

/// 预览视频改变
/// @param url 改变后的视频地址
/// @param isEnabled 是否显示预览视频
- (void)previewVideoDidChange:(NSString *)url isEnabled:(BOOL)isEnabled;

/// 回放数据改变了
/// @param replays 所有的回放信息列表
/// @param currentSelectedIndex 当前选中的回放的index
- (void)replaysDidChange:(NSArray<BDLReplayModel *> *)replays currentSelectedIndex:(NSUInteger)currentSelectedIndex;

/// 背景颜色改变
/// @param color 改变后的背景颜色
- (void)backgroundColorDidChange:(UIColor *)color;

/// 字体颜色改变
/// @param color 改编后的颜色
- (void)fontColorDidChange:(UIColor *)color;

/// 主题改变了
/// @param color 改变后的主题
- (void)colorThemeDidChange:(NSString *)color;

/// 主题改变了
/// @param colorTheme 改变后的主题类型
- (void)colorThemeTypeDidChange:(BDLColorThemeType)colorTheme;

/// 分享状态改变
/// @param canShare 是否可以分享
- (void)canShareDidChange:(NSInteger)canShare;

/// 分享 邀请海报状态变化
- (void)canInviteDidChange:(NSInteger)canInvite;

/// 活动倒计时改变了,  该方法不会重复调用,除非后台切换了倒计时状态（开启/关闭）或者修改了倒计时的时长
/// 如需读秒,需要自己启用timer读秒
/// @param countdown 剩余时间,单位秒
/// @param isEnabled 是否开启倒计时
- (void)activity:(BDLActivityModel *)activity countdownDidChange:(NSInteger)countdown isEnabled:(BOOL)isEnabled;

/// 活动可预约状态改变
- (void)activity:(BDLActivityModel *)activity reservationDidChange:(BOOL)isEnabled;

/// 水印开关改变
- (void)activity:(BDLActivityModel *)activity watermarkEnableDidChange:(BOOL)isEnabled;

- (void)activity:(BDLActivityModel *)activity showLineNameDidChange:(NSString *)showLineName;

- (void)activity:(BDLActivityModel *)activity showReplayNameDidChange:(NSString *)showReplayName;

/// 评论举报开关改变
- (void)activity:(BDLActivityModel *)activity tipOffCommentEnableDidChange:(BOOL)isEnabled;

@end

NS_ASSUME_NONNULL_END
