//
//  BDLVoteQuizOptionModel.h
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

#import <BDLiveBase/BDLBaseModel.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type keytype
 * @brief 答题、投票的选项 Model。
 */
/**
 * @locale en
 * @type keytype
 * @brief The model of quiz and vote options.
 */
@interface BDLVoteQuizOptionModel : BDLBaseModel

/**
 * @locale zh
 * @brief 选项的 index。
 */
/**
 * @locale en
 * @brief The option index.
 */
@property (nonatomic, copy) NSString *optionSite;
/**
 * @locale zh
 * @brief 选项内容。
 */
/**
 * @locale en
 * @brief The option content.
 */
@property (nonatomic, copy) NSString *optionName;
/**
 * @locale zh
 * @brief 选择该选项的人数百分比。
 */
/**
 * @locale en
 * @brief The percentage of people who chose this option.
 */
@property (nonatomic, copy) NSString *optionPercent;
/**
 * @locale zh
 * @brief 选择该选项的人数。
 */
/**
 * @locale en
 * @brief The number of people who chose this option.
 */
@property (nonatomic, assign) NSInteger optionCount;

/**
 * @locale zh
 * @brief 当前观众是否选择了。
 *        - `YES`：选择了。
 *        - `NO`：未选择。
 */
/**
 * @locale en
 * @brief Whether the current viewer chose this option.
 *        - `YES`: Chose.
 *        - `NO`: Did not choose.
 */
@property (nonatomic, assign) BOOL selected;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
