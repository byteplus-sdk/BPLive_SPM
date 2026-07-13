//
//  BDLUtils.h
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
#import "BDLBaseDefines.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, BDLProductType) {
    BDLProductTypeSDKPull,
    BDLProductTypeSDKPush,
    BDLProductTypeAppVolclive,
};

@interface BDLUtils : NSObject

+ (uint32_t)randomNumberBetween:(uint32_t)from and:(uint32_t)to;

+ (NSString *)generateUserUniqueId;

+ (NSString *)userUniqueId;

+ (nullable UIColor *)colorWithHexString:(NSString *)hexString;

+ (nullable UIColor *)colorWithHexString:(NSString *)hexString alpha:(CGFloat)alpha;

+ (nullable NSString *)hexStringFromColor:(UIColor *)color;

+ (nullable UIColor *)gradientColorWithRect:(CGRect)rect topHexString:(NSString *)topHexString bottomHexString:(NSString *)bottomHexString;

+ (nullable UIColor *)gradientColorWithRect:(CGRect)rect leftHexString:(NSString *)leftHexString rightHexString:(NSString *)rightHexString;

+ (nullable UIColor *)gradientColorWithRect:(CGRect)rect colors:(NSArray *)colors locations:(NSArray<NSNumber *> * _Nullable)locations startPoint:(CGPoint)startPoint endPoint:(CGPoint)endPoint;

+ (BDLLanguageType)getSystemLanguage;

+ (BOOL)isValidLanguageType:(BDLLanguageType)langType;

// 获取资源bundle
+ (NSBundle *)bundleWithName:(NSString *)name;

// 获取 BDLViewerAssets.bundle 中的图片
+ (UIImage *)imageNamed:(NSString *)name;

// 获取 BDLLiveStreamingImageResource.bundle 中的图片
+ (UIImage *)imageNamedForLiveStreaming:(NSString *)name;

// 获取 BDLCommonImageResource.bundle 中的图片
+ (UIImage *)imageNamedForCommon:(NSString *)name;

+ (NSData *)gifDataWithName:(NSString *)name;

+ (NSString *)localizedStringWithBundleName:(NSString *)bundleName key:(NSString *)key langType:(BDLLanguageType)langType;

+ (NSString *)titleFromLanguageType:(BDLLanguageType)type;

+ (NSString *)audienceLinkLocalizedStringForKey:(NSString *)key langType:(BDLLanguageType)langType;

+ (NSString *)liveStreamingAudioFilePathWithFileName:(NSString *)fileName;

+ (CGSize)portraitScreenSize;
+ (CGSize)landscapeScreenSize;

+ (NSArray<NSNumber *> *)configurationLangTypesArray;

/// 获取配置里面的多语言文本,langTypes固定为[简体中文, 英文, 日文, 繁体中文]
+ (NSString *)stringFromConfigMultiLangString:(NSString *)multiLangString
                                     langType:(BDLLanguageType)langType;

/// 根据 语言列表 切割控制台配置的多语言
/// @param langTypes  如果长度为0，则返回原字符串
+ (NSString *)stringFromMultiLangString:(NSString *)multiLangString
                              langTypes:(NSArray<NSNumber *> *)langTypes
                               langType:(BDLLanguageType)langType;

+ (NSURL * _Nullable)httpsURLFromString:(NSString * _Nullable)urlString;

/// 如果没有scheme或scheme为http, 则补充/修改为https:, 如果有其他scheme则原样转为NSURL返回
+ (NSURL * _Nullable)secureURLFromString:(NSString * _Nullable)urlString;

+ (NSString * _Nullable)httpURLStringFromString:(NSString * _Nullable)urlString;

+ (NSString * _Nullable)httpsURLStringFromString:(NSString * _Nullable)urlString;

+ (NSString *)unicodeStringFromDigitalString:(NSString *)digitalString;

+ (NSAttributedString *)tagStringFromText:(NSString *)text 
                                 maxWidth:(CGFloat)maxWidth
                                     font:(UIFont *)font
                                textColor:(nullable UIColor *)textColor
                                  bgColor:(UIColor *)bgColor;

/// @Param horizontalMargin 左右的间距
+ (NSAttributedString *)tagStringFromText:(NSString *)text
                                 maxWidth:(CGFloat)maxWidth
                                     font:(UIFont *)font
                                textColor:(nullable UIColor *)textColor
                                  bgColor:(UIColor *)bgColor
                             cornerRadius:(CGFloat)cornerRadius
                         horizontalMargin:(CGFloat)horizontalMargin;

+ (NSAttributedString *)tagStringFromText:(NSString *)text 
                                 maxWidth:(CGFloat)maxWidth
                                     font:(UIFont *)font
                                textColor:(nullable UIColor *)textColor
                              borderColor:(UIColor *)borderColor;

+ (NSAttributedString *)tagStringFromImage:(UIImage *)image
                                     frame:(CGRect)frame;

+ (NSAttributedString *)tagStringFromText:(NSString *)text
                                 maxWidth:(CGFloat)maxWidth
                                     font:(UIFont *)font
                                textColor:(UIColor *)textColor
                              borderColor:(nullable UIColor *)borderColor
                                  bgColor:(nullable UIColor *)bgColor
                             cornerRadius:(CGFloat)cornerRadius
                         horizontalMargin:(CGFloat)horizontalMargin
                           verticalMargin:(CGFloat)verticalMargin;

+ (CVPixelBufferRef)pixelBufferFromCGImage:(CGImageRef)image;

+ (UIImage *)imageWithUIView:(UIView *)view;

+ (CAGradientLayer *)getGradientLayerWithFrame:(CGRect)frame
                                        colors:(NSArray *)colors
                                     locations:(NSArray<NSNumber *> * _Nullable)locations
                                    startPoint:(CGPoint)startPoint
                                      endPoint:(CGPoint)endPoint;


+ (UIImage *)imageWithColor:(UIColor *)color;

+ (void)openURL:(NSURL *)url;

+ (BOOL)isValidPhoneNumber:(NSString *)phone;

+ (BOOL)isValidEmail:(NSString *)email;

/// 字符串打码，一般用于敏感信息上报时使用
+ (NSString *)pixelatedStringWith:(NSString *)string;

+ (BOOL)isBDLBPLObject:(id)object;

+ (BOOL)isBDLBPLClass:(Class)cls;

#pragma mark - Container Safe Methods

+ (BOOL)isEmptyArray:(NSArray *)array;

+ (BOOL)isEmptyString:(NSString *)string;

+ (BOOL)isEmptyDictionary:(NSDictionary *)dict;

+ (BOOL)isEmptyNumber:(NSNumber *)num;

+ (NSString *)userAgent;

+ (NSString *)userMobileWithProductType:(BDLProductType)type;

+ (NSString *)productTypeStrWithProductType:(BDLProductType)type;

+ (NSString *)sdkVersion;

+ (CGFloat)widthForText:(NSString *)text font:(UIFont *)font;

+ (CGSize)sizeForAttributeText:(NSAttributedString *)text size:(CGSize)size;

+ (NSArray<NSArray<NSString *> *> *)countryCodeArray;

// MARK: - animation

+ (void)runUIUpdateWithoutAnimation:(void(^)(void))block;

+ (BOOL)hasCommonSuperView:(UIView *)firstView secondView:(UIView *)secondView;

+ (BOOL)isValidPhoneNumberWithAreaCode:(NSString *)phone;

+ (BOOL)checkIsPhoneNumber:(NSString *)number;

+ (BOOL)isPureNumber:(NSString *)string;

// MARK: - app info

+ (NSString *)appDisplayName;

@end

typedef void (^bdl_dispatch_cancelable_block_t)(BOOL cancelled);

FOUNDATION_EXTERN void bdl_dispatch_main_async(dispatch_block_t block);
FOUNDATION_EXTERN void bdl_dispatch_main_sync(dispatch_block_t block);
FOUNDATION_EXTERN void bdl_enumerator_block(NSEnumerator *objects, void (^block)(id object));
FOUNDATION_EXTERN bdl_dispatch_cancelable_block_t bdl_dispatch_main_after(NSTimeInterval delayInSeconds, dispatch_block_t block);
FOUNDATION_EXTERN void bdl_cancel_block(bdl_dispatch_cancelable_block_t block);

#ifndef kBDLPortraitScreenSize
#define kBDLPortraitScreenSize [BDLUtils portraitScreenSize]
#endif

#ifndef kBDLPortraitScreenWidth
#define kBDLPortraitScreenWidth [BDLUtils portraitScreenSize].width
#endif

#ifndef kBDLPortraitScreenHeight
#define kBDLPortraitScreenHeight [BDLUtils portraitScreenSize].height
#endif

#ifndef kBDLLandscapeScreenSize
#define kBDLLandscapeScreenSize [BDLUtils landscapeScreenSize]
#endif

#ifndef kBDLLandscapeScreenWidth
#define kBDLLandscapeScreenWidth [BDLUtils landscapeScreenSize].width
#endif

#ifndef kBDLLandscapeScreenHeight
#define kBDLLandscapeScreenHeight [BDLUtils landscapeScreenSize].height
#endif

NS_ASSUME_NONNULL_END
