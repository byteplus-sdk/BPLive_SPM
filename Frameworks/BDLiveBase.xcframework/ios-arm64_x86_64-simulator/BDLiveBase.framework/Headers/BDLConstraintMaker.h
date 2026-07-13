//
//  BDLConstraintMaker.h
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

#import "BDLConstraint.h"
#import "BDLUtilities.h"

typedef NS_OPTIONS(NSInteger, BDLAttribute) {
    BDLAttributeLeft = 1 << NSLayoutAttributeLeft,
    BDLAttributeRight = 1 << NSLayoutAttributeRight,
    BDLAttributeTop = 1 << NSLayoutAttributeTop,
    BDLAttributeBottom = 1 << NSLayoutAttributeBottom,
    BDLAttributeLeading = 1 << NSLayoutAttributeLeading,
    BDLAttributeTrailing = 1 << NSLayoutAttributeTrailing,
    BDLAttributeWidth = 1 << NSLayoutAttributeWidth,
    BDLAttributeHeight = 1 << NSLayoutAttributeHeight,
    BDLAttributeCenterX = 1 << NSLayoutAttributeCenterX,
    BDLAttributeCenterY = 1 << NSLayoutAttributeCenterY,
    BDLAttributeBaseline = 1 << NSLayoutAttributeBaseline,
    
#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__TV_OS_VERSION_MIN_REQUIRED >= 9000) || (__MAC_OS_X_VERSION_MIN_REQUIRED >= 101100)
    
    BDLAttributeFirstBaseline = 1 << NSLayoutAttributeFirstBaseline,
    BDLAttributeLastBaseline = 1 << NSLayoutAttributeLastBaseline,
    
#endif
    
#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__TV_OS_VERSION_MIN_REQUIRED >= 9000)
    
    BDLAttributeLeftMargin = 1 << NSLayoutAttributeLeftMargin,
    BDLAttributeRightMargin = 1 << NSLayoutAttributeRightMargin,
    BDLAttributeTopMargin = 1 << NSLayoutAttributeTopMargin,
    BDLAttributeBottomMargin = 1 << NSLayoutAttributeBottomMargin,
    BDLAttributeLeadingMargin = 1 << NSLayoutAttributeLeadingMargin,
    BDLAttributeTrailingMargin = 1 << NSLayoutAttributeTrailingMargin,
    BDLAttributeCenterXWithinMargins = 1 << NSLayoutAttributeCenterXWithinMargins,
    BDLAttributeCenterYWithinMargins = 1 << NSLayoutAttributeCenterYWithinMargins,

#endif
    
};

/**
 *  Provides factory methods for creating MASConstraints.
 *  Constraints are collected until they are ready to be installed
 *
 */
@interface BDLConstraintMaker : NSObject

/**
 *	The following properties return a new MASViewConstraint
 *  with the first item set to the makers associated view and the appropriate MASViewAttribute
 */
@property (nonatomic, strong, readonly) BDLConstraint *left;
@property (nonatomic, strong, readonly) BDLConstraint *top;
@property (nonatomic, strong, readonly) BDLConstraint *right;
@property (nonatomic, strong, readonly) BDLConstraint *bottom;
@property (nonatomic, strong, readonly) BDLConstraint *leading;
@property (nonatomic, strong, readonly) BDLConstraint *trailing;
@property (nonatomic, strong, readonly) BDLConstraint *width;
@property (nonatomic, strong, readonly) BDLConstraint *height;
@property (nonatomic, strong, readonly) BDLConstraint *centerX;
@property (nonatomic, strong, readonly) BDLConstraint *centerY;
@property (nonatomic, strong, readonly) BDLConstraint *baseline;

#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__TV_OS_VERSION_MIN_REQUIRED >= 9000) || (__MAC_OS_X_VERSION_MIN_REQUIRED >= 101100)

@property (nonatomic, strong, readonly) BDLConstraint *firstBaseline;
@property (nonatomic, strong, readonly) BDLConstraint *lastBaseline;

#endif

#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__TV_OS_VERSION_MIN_REQUIRED >= 9000)

@property (nonatomic, strong, readonly) BDLConstraint *leftMargin;
@property (nonatomic, strong, readonly) BDLConstraint *rightMargin;
@property (nonatomic, strong, readonly) BDLConstraint *topMargin;
@property (nonatomic, strong, readonly) BDLConstraint *bottomMargin;
@property (nonatomic, strong, readonly) BDLConstraint *leadingMargin;
@property (nonatomic, strong, readonly) BDLConstraint *trailingMargin;
@property (nonatomic, strong, readonly) BDLConstraint *centerXWithinMargins;
@property (nonatomic, strong, readonly) BDLConstraint *centerYWithinMargins;

#endif

/**
 *  Returns a block which creates a new MASCompositeConstraint with the first item set
 *  to the makers associated view and children corresponding to the set bits in the
 *  BDLAttribute parameter. Combine multiple attributes via binary-or.
 */
@property (nonatomic, strong, readonly) BDLConstraint *(^attributes)(BDLAttribute attrs);

/**
 *	Creates a MASCompositeConstraint with type MASCompositeConstraintTypeEdges
 *  which generates the appropriate MASViewConstraint children (top, left, bottom, right)
 *  with the first item set to the makers associated view
 */
@property (nonatomic, strong, readonly) BDLConstraint *edges;

/**
 *	Creates a MASCompositeConstraint with type MASCompositeConstraintTypeSize
 *  which generates the appropriate MASViewConstraint children (width, height)
 *  with the first item set to the makers associated view
 */
@property (nonatomic, strong, readonly) BDLConstraint *size;

/**
 *	Creates a MASCompositeConstraint with type MASCompositeConstraintTypeCenter
 *  which generates the appropriate MASViewConstraint children (centerX, centerY)
 *  with the first item set to the makers associated view
 */
@property (nonatomic, strong, readonly) BDLConstraint *center;

/**
 *  Whether or not to check for an existing constraint instead of adding constraint
 */
@property (nonatomic, assign) BOOL updateExisting;

/**
 *  Whether or not to remove existing constraints prior to installing
 */
@property (nonatomic, assign) BOOL removeExisting;

/**
 *	initialises the maker with a default view
 *
 *	@param	view	any BDLConstraint are created with this view as the first item
 *
 *	@return	a new BDLConstraintMaker
 */
- (id)initWithView:(BDL_VIEW *)view;

/**
 *	Calls install method on any MASConstraints which have been created by this maker
 *
 *	@return	an array of all the installed MASConstraints
 */
- (NSArray *)install;

- (BDLConstraint * (^)(dispatch_block_t))group;

@end
