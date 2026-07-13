//
//  BDLYYClassInfo.h
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
#import <objc/runtime.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Type encoding's type.
 */
typedef NS_OPTIONS(NSUInteger, BDLYYEncodingType) {
    BDLYYEncodingTypeMask       = 0xFF, ///< mask of type value
    BDLYYEncodingTypeUnknown    = 0, ///< unknown
    BDLYYEncodingTypeVoid       = 1, ///< void
    BDLYYEncodingTypeBool       = 2, ///< bool
    BDLYYEncodingTypeInt8       = 3, ///< char / BOOL
    BDLYYEncodingTypeUInt8      = 4, ///< unsigned char
    BDLYYEncodingTypeInt16      = 5, ///< short
    BDLYYEncodingTypeUInt16     = 6, ///< unsigned short
    BDLYYEncodingTypeInt32      = 7, ///< int
    BDLYYEncodingTypeUInt32     = 8, ///< unsigned int
    BDLYYEncodingTypeInt64      = 9, ///< long long
    BDLYYEncodingTypeUInt64     = 10, ///< unsigned long long
    BDLYYEncodingTypeFloat      = 11, ///< float
    BDLYYEncodingTypeDouble     = 12, ///< double
    BDLYYEncodingTypeLongDouble = 13, ///< long double
    BDLYYEncodingTypeObject     = 14, ///< id
    BDLYYEncodingTypeClass      = 15, ///< Class
    BDLYYEncodingTypeSEL        = 16, ///< SEL
    BDLYYEncodingTypeBlock      = 17, ///< block
    BDLYYEncodingTypePointer    = 18, ///< void*
    BDLYYEncodingTypeStruct     = 19, ///< struct
    BDLYYEncodingTypeUnion      = 20, ///< union
    BDLYYEncodingTypeCString    = 21, ///< char*
    BDLYYEncodingTypeCArray     = 22, ///< char[10] (for example)
    
    BDLYYEncodingTypeQualifierMask   = 0xFF00,   ///< mask of qualifier
    BDLYYEncodingTypeQualifierConst  = 1 << 8,  ///< const
    BDLYYEncodingTypeQualifierIn     = 1 << 9,  ///< in
    BDLYYEncodingTypeQualifierInout  = 1 << 10, ///< inout
    BDLYYEncodingTypeQualifierOut    = 1 << 11, ///< out
    BDLYYEncodingTypeQualifierBycopy = 1 << 12, ///< bycopy
    BDLYYEncodingTypeQualifierByref  = 1 << 13, ///< byref
    BDLYYEncodingTypeQualifierOneway = 1 << 14, ///< oneway
    
    BDLYYEncodingTypePropertyMask         = 0xFF0000, ///< mask of property
    BDLYYEncodingTypePropertyReadonly     = 1 << 16, ///< readonly
    BDLYYEncodingTypePropertyCopy         = 1 << 17, ///< copy
    BDLYYEncodingTypePropertyRetain       = 1 << 18, ///< retain
    BDLYYEncodingTypePropertyNonatomic    = 1 << 19, ///< nonatomic
    BDLYYEncodingTypePropertyWeak         = 1 << 20, ///< weak
    BDLYYEncodingTypePropertyCustomGetter = 1 << 21, ///< getter=
    BDLYYEncodingTypePropertyCustomSetter = 1 << 22, ///< setter=
    BDLYYEncodingTypePropertyDynamic      = 1 << 23, ///< @dynamic
};

/**
 Get the type from a Type-Encoding string.
 
 @discussion See also:
 https://developer.apple.com/library/mac/documentation/Cocoa/Conceptual/ObjCRuntimeGuide/Articles/ocrtTypeEncodings.html
 https://developer.apple.com/library/mac/documentation/Cocoa/Conceptual/ObjCRuntimeGuide/Articles/ocrtPropertyIntrospection.html
 
 @param typeEncoding  A Type-Encoding string.
 @return The encoding type.
 */
BDLYYEncodingType BDLYYEncodingGetType(const char *typeEncoding);


/**
 Instance variable information.
 */
@interface BDLYYClassIvarInfo : NSObject
@property (nonatomic, assign, readonly) Ivar ivar;              ///< ivar opaque struct
@property (nonatomic, strong, readonly) NSString *name;         ///< Ivar's name
@property (nonatomic, assign, readonly) ptrdiff_t offset;       ///< Ivar's offset
@property (nonatomic, strong, readonly) NSString *typeEncoding; ///< Ivar's type encoding
@property (nonatomic, assign, readonly) BDLYYEncodingType type;    ///< Ivar's type

/**
 Creates and returns an ivar info object.
 
 @param ivar ivar opaque struct
 @return A new object, or nil if an error occurs.
 */
- (instancetype)initWithIvar:(Ivar)ivar;
@end


/**
 Method information.
 */
@interface BDLYYClassMethodInfo : NSObject
@property (nonatomic, assign, readonly) Method method;                  ///< method opaque struct
@property (nonatomic, strong, readonly) NSString *name;                 ///< method name
@property (nonatomic, assign, readonly) SEL sel;                        ///< method's selector
@property (nonatomic, assign, readonly) IMP imp;                        ///< method's implementation
@property (nonatomic, strong, readonly) NSString *typeEncoding;         ///< method's parameter and return types
@property (nonatomic, strong, readonly) NSString *returnTypeEncoding;   ///< return value's type
@property (nullable, nonatomic, strong, readonly) NSArray<NSString *> *argumentTypeEncodings; ///< array of arguments' type

/**
 Creates and returns a method info object.
 
 @param method method opaque struct
 @return A new object, or nil if an error occurs.
 */
- (instancetype)initWithMethod:(Method)method;
@end


/**
 Property information.
 */
@interface BDLYYClassPropertyInfo : NSObject
@property (nonatomic, assign, readonly) objc_property_t property; ///< property's opaque struct
@property (nonatomic, strong, readonly) NSString *name;           ///< property's name
@property (nonatomic, assign, readonly) BDLYYEncodingType type;      ///< property's type
@property (nonatomic, strong, readonly) NSString *typeEncoding;   ///< property's encoding value
@property (nonatomic, strong, readonly) NSString *ivarName;       ///< property's ivar name
@property (nullable, nonatomic, assign, readonly) Class cls;      ///< may be nil
@property (nullable, nonatomic, strong, readonly) NSArray<NSString *> *protocols; ///< may nil
@property (nonatomic, assign, readonly) SEL getter;               ///< getter (nonnull)
@property (nonatomic, assign, readonly) SEL setter;               ///< setter (nonnull)

/**
 Creates and returns a property info object.
 
 @param property property opaque struct
 @return A new object, or nil if an error occurs.
 */
- (instancetype)initWithProperty:(objc_property_t)property;
@end


/**
 Class information for a class.
 */
@interface BDLYYClassInfo : NSObject
@property (nonatomic, assign, readonly) Class cls; ///< class object
@property (nullable, nonatomic, assign, readonly) Class superCls; ///< super class object
@property (nullable, nonatomic, assign, readonly) Class metaCls;  ///< class's meta class object
@property (nonatomic, readonly) BOOL isMeta; ///< whether this class is meta class
@property (nonatomic, strong, readonly) NSString *name; ///< class name
@property (nullable, nonatomic, strong, readonly) BDLYYClassInfo *superClassInfo; ///< super class's class info
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, BDLYYClassIvarInfo *> *ivarInfos; ///< ivars
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, BDLYYClassMethodInfo *> *methodInfos; ///< methods
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, BDLYYClassPropertyInfo *> *propertyInfos; ///< properties

/**
 If the class is changed (for example: you add a method to this class with
 'class_addMethod()'), you should call this method to refresh the class info cache.
 
 After called this method, `needUpdate` will returns `YES`, and you should call 
 'classInfoWithClass' or 'classInfoWithClassName' to get the updated class info.
 */
- (void)setNeedUpdate;

/**
 If this method returns `YES`, you should stop using this instance and call
 `classInfoWithClass` or `classInfoWithClassName` to get the updated class info.
 
 @return Whether this class info need update.
 */
- (BOOL)needUpdate;

/**
 Get the class info of a specified Class.
 
 @discussion This method will cache the class info and super-class info
 at the first access to the Class. This method is thread-safe.
 
 @param cls A class.
 @return A class info, or nil if an error occurs.
 */
+ (nullable instancetype)classInfoWithClass:(Class)cls;

/**
 Get the class info of a specified Class.
 
 @discussion This method will cache the class info and super-class info
 at the first access to the Class. This method is thread-safe.
 
 @param className A class name.
 @return A class info, or nil if an error occurs.
 */
+ (nullable instancetype)classInfoWithClassName:(NSString *)className;

@end

NS_ASSUME_NONNULL_END
