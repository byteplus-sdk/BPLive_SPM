//
//  BDLCountdownView.h
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

#import <BDLiveCommon/BDLBaseView.h>
#import "BDLBasicService.h"
#import <BDLiveCommon/BDLLanguageService.h>
#import "BDLActivityBookingModel.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

@class BDLCountdownView;

/**
 * @locale zh
 * @type callback
 * @brief 直播间倒计时 view 的代理方法。
 */
/**
 * @locale en
 * @type callback
 * @brief The delegate methods for the live room countdown view.
 */
@protocol BDLCountdownViewDelegate <NSObject>

/**
 * @locale zh
 * @brief 在倒计时结束时，SDK 调用该方法。
 * @param countdownView 直播间倒计时 view。详见 [BDLCountdownView](1185540#BDLCountdownView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the countdown ends.
 * @param countdownView The live room countdown view. For more information, see [BDLCountdownView](docs-bdlliveengine#BDLCountdownView).
 */
- (void)countdownViewDidFinish:(BDLCountdownView *)countdownView;
/**
 * @locale zh
 * @brief 在倒计时被取消时，SDK 调用该方法。
 * @param countdownView 直播间倒计时 view。详见 [BDLCountdownView](1185540#BDLCountdownView)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when the countdown is canceled.
 * @param countdownView The live room countdown view. For more information, see [BDLCountdownView](docs-bdlliveengine#BDLCountdownView).
 */
- (void)countdownViewDidCancel:(BDLCountdownView *)countdownView;

@end

/**
 * @locale zh
 * @type api
 * @brief 直播间倒计时 view，包含直播预约。
 */
/**
 * @locale en
 * @brief The live room countdown view, including the live booking.
 */
@interface BDLCountdownView : BDLBaseView <BDLBasicService, BDLLanguageService>

/**
 * @locale zh
 * @brief 初始化。
 * @param isPortrait 是否以竖屏直播间初始化。<br>
 *        - `YES`：以竖屏直播间初始化。
 *        - `NO`：以横屏直播间初始化。
 * @list 其他
 * @return 直播间倒计时 view 实例。
 */
/**
 * @locale en
 * @brief Initializes the instance of the live room countdown view.
 * @param isPortrait Whether to initialize in portrait mode.
 *        - `YES`: Portrait mode.
 *        - `NO`: Landscape mode.
 * @return The instance of the live room countdown view.
 */
- (instancetype)initWithPortrait:(BOOL)isPortrait;

/**
 * @locale zh
 * @brief 代理方法。详见 [BDLCountdownViewDelegate](1185541#BDLCountdownViewDelegate)。
 */
/**
 * @locale en
 * @brief The delegate method. For more information, see [BDLCountdownViewDelegate](viewer-SDK-for-ios-callbacks#BDLCountdownViewDelegate).
 */
@property (nonatomic, weak) id<BDLCountdownViewDelegate> delegate;

/**
 * @locale zh
 * @brief “距离直播开始还有”文案的 label。不支持自定义 `frame` 和 `text`。
 */
/**
 * @locale en
 * @brief The text label of "The live stream will start in". All properties except `frame` and `text` can be customized.
 */
@property (nonatomic, strong, readonly) UILabel *hintLabel;
/**
 * @locale zh
 * @brief 当前剩余时间的 label。不支持自定义 `text`。
 */
/**
 * @locale en
 * @brief The label of the current remaining time. All properties except `text` can be customized.
 */
@property (nonatomic, strong, readonly) UILabel *countdownLabel;
/**
 * @locale zh
 * @brief 预约按钮。仅在开启直播预约功能后显示。不支持设置 `Normal` 和 `Disabled` 状态的 `text`。
 */
/**
 * @locale en
 * @brief The book button, which is displayed only when the live booking feature is enabled. The `text` in the `Normal` and `Disabled` status cannot be customized.
 */
@property (nonatomic, strong, readonly) UIButton *bookingButton;

/**
 * @locale zh
 * @brief 预约成功的 toast 文案。
 */
/**
 * @locale en
 * @brief The text of the toast indicating that booking the live stream is successful.
 */
@property (nonatomic, copy) NSString *addEventSuccessToast;
/**
 * @locale zh
 * @brief 预约失败的 toast 文案。
 */
/**
 * @locale en
 * @brief The text of the toast indicating that booking the live stream failed.
 */
@property (nonatomic, copy) NSString *addEventFailToast;

/**
 * @locale zh
 * @brief 停止倒计时。
 * @list 其他
 */
/**
 * @locale en
 * @brief Stops the countdown.
 */
- (void)cancel;
/**
 * @locale zh
 * @brief 创建系统日历日程成功回调。<br>
 *         您在自行创建系统日历日程并创建成功后，需调用该回调通知 SDK 观众已预约该直播。SDK 收到通知后，即可将直播预约按钮更改为已预约状态。<br>
 *         :::tip
 *        当鉴权模式为公开时，调用 [clearCache](#BDLLiveEngine-clearcache) 方法可清除观众当前设备上 SDK 的所有本地缓存，从而将观众在所有直播间内的直播预约按钮从已预约状态变更为未预约状态。<br>
 *         :::
 * @list 其他
 */
/**
 * @locale en
 * @brief The callback is triggered when the system calendar event is successfully created.
 *        After successfully creating a system calendar event on your own, you need to call this callback to notify the SDK that the viewer has booked the live stream. Once the SDK receives the notification, you can change the button for booking the live stream to the booked status.
 *         :::tip
 *        When the authentication mode is set to public, you can call the  [clearCache](#BDLLiveEngine-clearcache) method to clear all local cache of the SDK on the viewer's current device, thereby changing the button from the booked status to unbooked status in all live rooms of the viewer.
 *         :::
 */
- (void)setActivityBooked;
/**
 * @locale zh
 * @brief 直播预约按钮点击回调。
 * @param activityBookingModel 直播预约信息 Model。详见 [BDLActivityBookingModel](1185544#BDLActivityBookingModel)。
 * @list 其他
 * @return 是否需要自行创建系统日历日程。如果未实现该回调，则 SDK 会自动创建系统日历日程。<br>
 *         - `YES`：您需自行创建系统日历日程。您可以调用 SDK 的 [addCalendarEvent:alarms:startDate:endDate:completion:](#BDLCalendarUtils-addcalendarevent-alarms-startdate-enddate-completion) 方法创建系统日历日程，也可以自行通过其他方法创建系统日历日程。
 *         - `NO`：SDK 会自动创建系统日历日程。
 */
/**
 * @locale en
 * @brief The callback is triggered when the live booking button is tapped.
 * @param activityBookingModel The model of live booking information. For more information, see [BDLActivityBookingModel](viewer-sdk-for-ios-type-definitions#BDLActivityBookingModel).
 * @return Whether you need to create a system calendar event on your own. If this callback is not implemented, the SDK automatically creates a system calendar event.
 *         - `YES`: You need to create a system calendar event on your own. You can use the SDK's [addCalendarEvent:alarms:startDate:endDate:completion:](#BDLCalendarUtils-addcalendarevent-alarms-startdate-enddate-completion) method to create a system calendar event, or you can create the event in other ways.
 *         - `NO`: The SDK automatically creates a system calendar event.
 */
@property (nonatomic, copy) BOOL (^onBookingButtonClicked)(BDLActivityBookingModel *activityBookingModel);
/**
 * @locale zh
 * @brief 系统日历日程创建结果回调。
 * @param activityBookingModel 直播预约信息 Model。详见 [BDLActivityBookingModel](1185544#BDLActivityBookingModel)。
 * @param isSuccess 系统日历日程是否创建成功。<br>
 *        - `YES`：创建成功。
 *        - `NO`：创建失败。
 * @list 其他
 */
/**
 * @locale en
 * @brief The callback for system calendar event creation results.
 * @param activityBookingModel The model of live booking information. For more information, see [BDLActivityBookingModel](viewer-sdk-for-ios-type-definitions#BDLActivityBookingModel).
 * @param isSuccess Whether the system calendar event creation is successful.
 *        - `YES`: Successful.
 *        - `NO`: Failed.
 */
@property (nonatomic, copy) void (^onCalendarResult)(BDLActivityBookingModel *activityBookingModel, BOOL isSuccess);

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
