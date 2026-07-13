//
//  BDLFloatingInteractiveToolViewType.h
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

#ifndef BDLFloatingInteractiveToolViewType_h
#define BDLFloatingInteractiveToolViewType_h

/**
 * @locale zh
 * @type keytype
 * @brief 互动工具浮窗 view 的类型。
 */
/**
 * @locale en
 * @type keytype
 * @brief The type of interaction tool floating window view.
 */
typedef NS_ENUM(NSInteger, BDLFloatingInteractiveToolViewType) {
    /**
     * @locale zh
     * @brief 公告。
     */
    /**
     * @locale en
     * @brief Announcement.
     */
    BDLFloatingInteractiveToolViewTypeAnnouncement = 1,
    /**
     * @locale zh
     * @brief 投票。
     */
    /**
     * @locale en
     * @brief Vote.
     */
    BDLFloatingInteractiveToolViewTypeVote,
    /**
     * @locale zh
     * @brief 答题。
     */
    /**
     * @locale en
     * @brief Quiz.
     */
    BDLFloatingInteractiveToolViewTypeQuiz,
    /**
     * @locale zh
     * @brief 正在进行的抽奖。
     */
    /**
     * @locale en
     * @brief The lucky draw in progress.
     */
    BDLFloatingInteractiveToolViewTypeOngoingAward,
    /**
     * @locale zh
     * @brief 已开奖的抽奖。
     */
    /**
     * @locale en
     * @brief The lucky draw already drawn.
     */
    BDLFloatingInteractiveToolViewTypeOpenedAward,
    /**
     * @locale zh
     * @brief 问卷。
     */
    /**
     * @locale en
     * @brief Questionnaire.
     */
    BDLFloatingInteractiveToolViewTypeQuestionnaire = 6,
    /**
     * @locale zh
     * @brief 累计观看抽奖。
     */
    /**
     * @locale en
     * @brief Watch time-based lucky draw.
     */
    BDLFloatingInteractiveToolViewTypeTaskAward = 7,
    /**
     * @locale zh
     * @brief 签到。
     */
    /**
     * @locale en
     * @brief Check-in.
     */
    BDLFloatingInteractiveToolViewTypeCheckIn,
};


#endif /* BDLFloatingInteractiveToolViewType_h */
