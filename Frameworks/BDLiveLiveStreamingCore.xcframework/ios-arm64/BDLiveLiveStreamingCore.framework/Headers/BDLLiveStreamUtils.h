//
//  BDLLiveStreamUtils.h
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

#import <AVFoundation/AVFoundation.h>

#import <BDLiveBase/BDLUtils.h>

NS_ASSUME_NONNULL_BEGIN

@interface BDLLiveStreamUtils : BDLUtils

/// 检测是否有访问相机硬件的权限
/// @param completion 拥有相机硬件访问权限的回调block
+ (void)checkVideoPermission:(void(^)(BOOL granted))completion;

/// 检测是否有访问麦克风硬件的权限
/// @param completion 拥有麦克风硬件访问权限的回调block
+ (void)checkAudioPermission:(void(^)(BOOL granted))completion;

/// 检测是否有访问相册的权限
+ (void)checkPotoLibraryPermission:(void(^)(BOOL granted))completion;

///@return 0/90/180/270
+ (NSUInteger)getVideoRotationAngle:(AVAsset *)videoAsset;

+ (NSString *)localizedStringForKey:(NSString *)key;

/// 返回langType对应的当前SDK语言的文案
+ (NSString *)languageNameWithLangType:(BDLLanguageType)langType;

/// 返回多语言的Placeholder 如"简中|英文"，如果不支持多语言则返回defaultStr
+ (NSString *)getMultiLanguagePlaceholderWithDefault:(NSString *)defaultStr;

@end

NS_ASSUME_NONNULL_END
