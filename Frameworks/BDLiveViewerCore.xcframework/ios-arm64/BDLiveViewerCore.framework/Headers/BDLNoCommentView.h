//
//  BDLNoCommentView.h
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

#import <BDLiveCommon/BDLBaseView.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 评论区无评论时的 view。
 */
/**
 * @locale en
 * @brief The view when there are no comments in the comment area.
 */
@interface BDLNoCommentView : BDLBaseView

/**
 * @locale zh
 * @brief imageView。可自定义除 `frame` 或 `image` 外的所有属性。如需自定义 `image`，可通过 [noCommentImage](1185544#BDLCommentBaseConfiguration(Config)-nocommentimage) 设置。
 */
/**
 * @locale en
 * @brief The `imageView`. All properties except `frame` and `image` can be customized. You can customize `image` by using [noCommentImage](viewer-sdk-for-ios-type-definitions#BDLCommentBaseConfiguration(Config)-nocommentimage).
 */
@property (nonatomic, strong) UIImageView *imageView;
/**
 * @locale zh
 * @brief 文字。可自定义除 `text` 或 `frame` 外的所有属性。
 */
/**
 * @locale en
 * @brief The text. All properties except `text` and `frame` can be customized.
 */
@property (nonatomic, strong) UILabel *titleLabel;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
