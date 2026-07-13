//
//  BDLCalendarUtils.h
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

#import <EventKit/EventKit.h>
#import <Foundation/Foundation.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 日历工具类。
 */
/**
 * @locale en
 * @brief The calendar utility class.
 */
@interface BDLCalendarUtils : NSObject

/**
 * @locale zh
 * @brief 创建系统日历日程。
 * @param eventTitle 日程的标题，即直播名称。
 * @param alarms 提前直播开始时间多久提醒直播即将开始。详见 [EKAlarm](https://developer.apple.com/documentation/eventkit/ekalarm?language=objc)。<br>:::tip 支持设置多个提醒时间。<br>:::
 * @param startDate 直播开始时间。
 * @param endDate 直播结束时间。
 * @param completion 系统日历日程创建完成后触发的回调。<br>传入参数：<br>
 *        - `success`：系统日历日程是否创建成功。
 *          - `YES`：创建成功。
 *          - `NO`：创建失败。
 *        - `error`：错误信息。详见 [NSError](https://developer.apple.com/documentation/foundation/nserror?changes=l_1&language=objc)。
 * @list 其他
 */
/**
 * @locale en
 * @brief Creates a system calendar event.
 * @param eventTitle The event title, namely the live room name.
 * @param alarms How long a notification is sent in advance of the start time of the live stream. For more information, see [EKAlarm](https://developer.apple.com/documentation/eventkit/ekalarm?language=objc).
 *        :::tip
 *        Multiple reminder times can be set.
 *        :::
 * @param startDate The start time of the live stream.
 * @param endDate The end time of the live stream.
 * @param completion The callback triggered when the system calendar event is created.<br>
 *        Input parameters:
 *        - `success`: Whether the system calendar event creation is successful.
 *          - `YES`: Successful.
 *          - `NO`: Failed.
 *        - `error`: The error information. For more information, see [NSError](https://developer.apple.com/documentation/foundation/nserror?changes=l_1&language=objc).
 */
+ (void)addCalendarEvent:(NSString *)eventTitle 
                  alarms:(NSArray<EKAlarm *> *)alarms
               startDate:(NSDate *)startDate
                 endDate:(NSDate *)endDate
              completion:(void(^)(BOOL success, NSError *error))completion;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
