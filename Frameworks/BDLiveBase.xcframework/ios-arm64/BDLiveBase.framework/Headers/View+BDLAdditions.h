//
//  View+BDLAdditions.h
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

#import "BDLUtilities.h"
#import "BDLConstraintMaker.h"
#import "BDLViewAttribute.h"

/**
 *	Provides constraint maker block
 *  and convience methods for creating MASViewAttribute which are view + NSLayoutAttribute pairs
 */
@interface BDL_VIEW (BDLAdditions)

/**
 *	following properties return a new MASViewAttribute with current view and appropriate NSLayoutAttribute
 */
@property (nonatomic, strong, readonly) BDLViewAttribute *bdl_mas_left;
@property (nonatomic, strong, readonly) BDLViewAttribute *bdl_mas_top;
@property (nonatomic, strong, readonly) BDLViewAttribute *bdl_mas_right;
@property (nonatomic, strong, readonly) BDLViewAttribute *bdl_mas_bottom;
@property (nonatomic, strong, readonly) BDLViewAttribute *bdl_mas_leading;
@property (nonatomic, strong, readonly) BDLViewAttribute *bdl_mas_trailing;
@property (nonatomic, strong, readonly) BDLViewAttribute *bdl_mas_width;
@property (nonatomic, strong, readonly) BDLViewAttribute *bdl_mas_height;
@property (nonatomic, strong, readonly) BDLViewAttribute *bdl_mas_centerX;
@property (nonatomic, strong, readonly) BDLViewAttribute *bdl_mas_centerY;
@property (nonatomic, strong, readonly) BDLViewAttribute *bdl_mas_baseline;
@property (nonatomic, strong, readonly) BDLViewAttribute *(^bdl_mas_attribute)(NSLayoutAttribute attr);

#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__TV_OS_VERSION_MIN_REQUIRED >= 9000) || (__MAC_OS_X_VERSION_MIN_REQUIRED >= 101100)

@property (nonatomic, strong, readonly) BDLViewAttribute *bdl_mas_firstBaseline;
@property (nonatomic, strong, readonly) BDLViewAttribute *bdl_mas_lastBaseline;

#endif

#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__TV_OS_VERSION_MIN_REQUIRED >= 9000)

@property (nonatomic, strong, readonly) BDLViewAttribute *bdl_mas_leftMargin;
@property (nonatomic, strong, readonly) BDLViewAttribute *bdl_mas_rightMargin;
@property (nonatomic, strong, readonly) BDLViewAttribute *bdl_mas_topMargin;
@property (nonatomic, strong, readonly) BDLViewAttribute *bdl_mas_bottomMargin;
@property (nonatomic, strong, readonly) BDLViewAttribute *bdl_mas_leadingMargin;
@property (nonatomic, strong, readonly) BDLViewAttribute *bdl_mas_trailingMargin;
@property (nonatomic, strong, readonly) BDLViewAttribute *bdl_mas_centerXWithinMargins;
@property (nonatomic, strong, readonly) BDLViewAttribute *bdl_mas_centerYWithinMargins;

#endif

#if (__IPHONE_OS_VERSION_MAX_ALLOWED >= 110000) || (__TV_OS_VERSION_MAX_ALLOWED >= 110000)

@property (nonatomic, strong, readonly) BDLViewAttribute *bdl_mas_safeAreaLayoutGuide API_AVAILABLE(ios(11.0),tvos(11.0));
@property (nonatomic, strong, readonly) BDLViewAttribute *bdl_mas_safeAreaLayoutGuideTop API_AVAILABLE(ios(11.0),tvos(11.0));
@property (nonatomic, strong, readonly) BDLViewAttribute *bdl_mas_safeAreaLayoutGuideBottom API_AVAILABLE(ios(11.0),tvos(11.0));
@property (nonatomic, strong, readonly) BDLViewAttribute *bdl_mas_safeAreaLayoutGuideLeft API_AVAILABLE(ios(11.0),tvos(11.0));
@property (nonatomic, strong, readonly) BDLViewAttribute *bdl_mas_safeAreaLayoutGuideRight API_AVAILABLE(ios(11.0),tvos(11.0));

#endif

/**
 *	a key to associate with this view
 */
@property (nonatomic, strong) id bdl_mas_key;

/**
 *	Finds the closest common superview between this view and another view
 *
 *	@param	view	other view
 *
 *	@return	returns nil if common superview could not be found
 */
- (instancetype)bdl_mas_closestCommonSuperview:(BDL_VIEW *)view;

/**
 *  Creates a BDLConstraintMaker with the callee view.
 *  Any constraints defined are added to the view or the appropriate superview once the block has finished executing
 *
 *  @param block scope within which you can build up the constraints which you wish to apply to the view.
 *
 *  @return Array of created MASConstraints
 */
- (NSArray *)bdl_mas_makeConstraints:(void(NS_NOESCAPE ^)(BDLConstraintMaker *make))block;

/**
 *  Creates a BDLConstraintMaker with the callee view.
 *  Any constraints defined are added to the view or the appropriate superview once the block has finished executing.
 *  If an existing constraint exists then it will be updated instead.
 *
 *  @param block scope within which you can build up the constraints which you wish to apply to the view.
 *
 *  @return Array of created/updated MASConstraints
 */
- (NSArray *)bdl_mas_updateConstraints:(void(NS_NOESCAPE ^)(BDLConstraintMaker *make))block;

/**
 *  Creates a BDLConstraintMaker with the callee view.
 *  Any constraints defined are added to the view or the appropriate superview once the block has finished executing.
 *  All constraints previously installed for the view will be removed.
 *
 *  @param block scope within which you can build up the constraints which you wish to apply to the view.
 *
 *  @return Array of created/updated MASConstraints
 */
- (NSArray *)bdl_mas_remakeConstraints:(void(NS_NOESCAPE ^)(BDLConstraintMaker *make))block;

@end
