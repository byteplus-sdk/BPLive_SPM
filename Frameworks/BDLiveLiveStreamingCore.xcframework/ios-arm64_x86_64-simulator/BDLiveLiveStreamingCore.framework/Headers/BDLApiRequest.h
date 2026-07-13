//
//  BDLApiRequest.h
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

#import <Foundation/Foundation.h>
#import <BDLiveBase/BDLYYModel.h>

#import <BDLiveBase/NSError+BDLErrorCode.h>
#import <BDLiveBase/BDLBaseResponse.h>

typedef NS_ENUM(NSInteger, BDLRequestMethod) {
    BDLRequestMethodGET = 0,
    BDLRequestMethodPOST,
    BDLRequestMethodHEAD,
    BDLRequestMethodPUT,
    BDLRequestMethodDELETE,
    BDLRequestMethodPATCH,
};

NS_ASSUME_NONNULL_BEGIN

typedef void (^BDLApiFailure)(BDLBaseResponse * _Nullable baseResponse, NSError * _Nullable error);
typedef void (^BDLApiSuccess)(BDLBaseResponse * _Nullable baseResponse, NSDictionary * _Nullable data);

@interface BDLApiRequest : NSObject

/// 是否在主线程接收回调
@property (nonatomic, assign) BOOL callbackInMainThread;

@property (nonatomic, assign) BOOL verifyRequest;

@property (nonatomic, assign) BOOL CustomizedCookie;

/// 根据服务器约定， 一些接口的某些errorCode视为成功
@property (nonatomic, copy) NSArray<NSString *> *ignorErrorCode;
/// 是否需要loading - 默认YES
@property (nonatomic, assign) BOOL showLoadingAnimation;
/// 是否展示错误message - 默认YES
@property (nonatomic, assign) BOOL showErrorMessage;

/// 是否为登陆相关的接口 - 登陆相关接口header不用带JWT字段
@property (nonatomic, assign) BOOL isLogin;

@property (nonatomic, assign, readonly) BOOL success;

@property (nonatomic, copy) NSString *Action;
@property (nonatomic, copy) NSString *Version;
@property (nonatomic, assign) BOOL originSerializer;
/// 临时JWT秘钥
@property (nonatomic, copy) NSString *temJWT;

@property (nonatomic, strong, readonly) BDLBaseResponse *response;

// 异步请求
// 此方法loading通过showLoadingAnimation配置 展示error message
- (NSURLSessionDataTask *)startWithSuccess:(nullable BDLApiSuccess)success failure:(nullable BDLApiFailure)failure;
- (NSURLSessionDataTask *)rawRequestStartWithSuccess:(nullable BDLApiSuccess)success failure:(nullable BDLApiFailure)failure;

- (BDLRequestMethod)requestMethodType;

- (NSString *)apiAction;

/// 默认将model的属性转为dict作为参数，如果有本地属性，可以通过重写该方法去忽视部分属性
- (NSArray <NSString *> *)ignoredKeyForApiParameters;

- (NSDictionary *)apiAdditionalParameters;

- (NSDictionary *)defaultHeaders;

- (NSString *)requestBaseUrl;

- (NSString *)host;

+ (NSString *)globalRequestBaseUrl;

@end

NS_ASSUME_NONNULL_END
