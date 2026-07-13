//
//  BDLStreamingCommentView.h
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
#import <BDLiveCommon/BDLBaseView.h>
#import "BDLSCommentService.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 开播端评论区 view。
 */
@interface BDLStreamingCommentView : BDLBaseView <BDLSCommentService>
/**
 * @locale zh
 * @brief 评论点击回调。
 * @param view 评论区 view。
 * @param comment 评论 Model。详见 [BDLCommentModel](#BDLCommentModel)。
 */
@property (nonatomic, copy) void (^onCommentTapped)(BDLStreamingCommentView *view, BDLCommentModel* comment);

@end

NS_ASSUME_NONNULL_END
