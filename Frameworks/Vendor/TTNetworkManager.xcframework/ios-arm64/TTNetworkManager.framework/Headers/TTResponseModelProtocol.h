//
//  TTResponseModelProtocol.h
//  Pods
//
//  Created by ZhangLeonardo on 15/9/7.
//
//
//  Same as TTRequestModel, this interface is also designed for scripting.
//  The difference is that the response uses the interface design, and the request uses the base class design.
//  The reason is that the modeling tools used by each business group are different.
//  In this way, as long as the interface is implemented You can choose the method you need and others.
//  

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN
@protocol TTResponseModelProtocol <NSObject>

- (id _Nullable)initWithDictionary:(nullable NSDictionary*)dict
                             error:(NSError* _Nullable * _Nullable)err;

@end
NS_ASSUME_NONNULL_END
