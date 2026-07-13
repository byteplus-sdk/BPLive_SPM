//
//  BDLLiveEngine.h
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
#import <BDLiveCommon/BDLDefines.h>
#import "BDLActivity.h"
#import "BDLActivityListener.h"
#import "BDLLivePullViewController.h"
#import "BDLLiveRoomConfiguration.h"
#import "BDLLoginProvider.h"
#import "BDLActivityService.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 企业直播观播 SDK 入口类。
 */
/**
 * @locale en
 * @brief The entry class of the Viewer SDK.
 */
@interface BDLLiveEngine : NSObject

/**
 * @locale zh
 * @brief 是否正在进入直播间。<br>
 *        - `YES`：正在进入。
 *        - `NO`：未在进入。
 */
/**
 * @locale en
 * @brief Whether the user is joining the live room.
 *        - `YES`: Joining.
 *        - `NO`: Not joining.
 */
@property (nonatomic, assign, readonly) BOOL isJoining;

/**
 * @locale zh
 * @brief 直播间配置信息。详见 [BDLLiveRoomConfiguration](1185544#BDLLiveRoomConfiguration)。
 */
/**
 * @locale en
 * @brief The live room configuration. For more information, see [BDLLiveRoomConfiguration](viewer-sdk-for-ios-type-definitions#BDLLiveRoomConfiguration).
 */
@property (nonatomic, strong, readonly) BDLLiveRoomConfiguration *liveRoomConfiguration;
/**
 * @locale zh
 * @brief 获取 `BDLLiveEngine` 实例。
 * @return `BDLLiveEngine` 实例。
 */
/**
 * @locale en
 * @brief Gets the `BDLLiveEngine` instance.
 * @return The `BDLLiveEngine` instance.
 */
+ (instancetype)sharedInstance;
/**
 * @locale zh
 * @brief 获取 SDK 版本号。
 * @return SDK 版本号。
 */
/**
 * @locale en
 * @brief Gets the SDK version number.
 * @return The SDK version number.
 */
+ (NSString *)sdkVersion;
/**
 * @locale zh
 * @brief 清除观众当前设备上 SDK 的所有本地缓存。本地缓存包含：<br>
 *        - 弹出风险提示框的记录。清除后，观众重进直播间，风险提示框会重新弹出。
 *        - 鉴权模式为公开时，在系统日历预约直播的记录。清除后，**预约**按钮会恢复为**立即预约**，但不会清除系统日历中的日程。
 *        - 点播视频断点续播的记录。清除后，观众重进直播间，点播视频会从头播放。
 */
/**
 * @locale en
 * @brief Clears all local caches of the SDK on the viewer's current device. The local cache includes:
 *        - Records of reminder dialog boxes. After the cache is cleared, viewers will see the dialog box again when they rejoin the live room.
 *        - Records of live stream bookings in the system calendar when the authentication mode is public. After the cache is cleared, the **Book** button will revert to **Book now**, but the events in the system calendar will remain.
 *        - Records of VOD video playback progress. After the cache is cleared, VOD videos will start from the beginning when viewers rejoin the live room.
 */
+ (void)clearCache;
/**
 * @locale zh
 * @brief 获取用户的唯一 ID，在用户成功进入直播间后调用。在反馈问题时，可以提供给企业直播技术支持，用于排查与解决问题。
 * @return 用户的唯一 ID。
 */
/**
 * @locale en
 * @brief Gets the user's unique ID. Call this method after the user successfully joins the live room. This ID can be provided to BytePlus Live technical support when reporting issues to help diagnose and resolve problems.
 * @return The unique ID of the user.
 */
+ (NSString *)userUniqueId;
/**
 * @locale zh
 * @brief 设置直播间的监听器。
 * @param listener 直播间的监听器。详见 [BDLActivityListener](1185541#BDLActivityListener)。
 */
/**
 * @locale en
 * @brief Sets the live room listener.
 * @param listener The live room listener. For more information, see [BDLActivityListener](viewer-SDK-for-ios-callbacks#BDLActivityListener).
 */
- (void)setActivityListener:(nullable id<BDLActivityListener>)listener;
/**
 * @locale zh
 * @brief 设置自定义登录直播间代理。
 * @param loginProvider 自定义登录直播间代理。详见 [BDLLoginProvider](1185541#BDLLoginProvider)。
 * @return - `YES`：设置成功。
 *         - `NO`：如果您未实现 [loginWithActivity:completion:](1185541#BDLLoginProvider-loginwithactivity-completion) 方法，返回 `NO`，设置失败。
 */
/**
 * @locale en
 * @brief Sets the delegate for custom login to the live room.
 * @param loginProvider The delegate for custom login to the live room. For more information, see [BDLLoginProvider](viewer-SDK-for-ios-callbacks#BDLLoginProvider).
 * @return - `YES`: Set successfully.
 *         - `NO`: Return `NO` if the [loginWithActivity:completion:](viewer-SDK-for-ios-callbacks#BDLLoginProvider-loginwithactivity-completion) method is not implemented, indicating that the setting failed.
 */
- (BOOL)setLoginProvider:(nullable id<BDLLoginProvider>)loginProvider;

/**
 * @locale zh
 * @brief 进入直播间。
 * @deprecated 该方法自 1.40.0 版本开始已废弃。请使用 [joinLiveRoomWithActivity:success:failure:](#BDLLiveEngine-joinliveroomwithactivity-success-failure) 方法替代之。
 * @param activity 直播间信息。详见 [BDLActivity](#BDLActivity)。
 * @return - `YES`：调用方法成功。
 *         - `NO`：参数无效，即 [activityId](#BDLActivity-activityid) 或 [token](#BDLActivity-token) 的值为空。
 */
/**
 * @locale en
 * @brief Enter the live stream room.
 * @param activity Information about live streams. See [BDLActivity](#BDLActivity) for more details.
 * @hidden (iOS)
 */
-(BOOL)joinLiveRoomWithActivity:(BDLActivity *)activity DEPRECATED_MSG_ATTRIBUTE("Will be removed in the future, use joinLiveRoomWithActivity:success:failure: instead");

/**
 * @locale zh
 * @brief 进入直播间。进入直播间成功或失败后，SDK 会触发对应的回调。
 * @param activity 直播间信息。详见 [BDLActivity](#BDLActivity)。
 * @param success 进入直播间成功后触发的回调，无返回值。
 * @param failure 进入直播间失败后触发的回调，无返回值。<br>
 *         传入参数：<br>
 *         `error`：错误信息。`error.code` 的值为 `BDLError` 的枚举值，详见 [BDLError](1185543#BDLError)。<br>
 *         示例：<br>
 *         ```failure:^(NSError * _Nonnull error) { if ([error.domain isEqualToString:BDLErrorDomain]) { if (error.code == BDLErrorPullDisallowed) } else if ... { } } else { } }]; ```
 * @return - `YES`：调用方法成功。
 *         - `NO`：参数无效，即 [activityId](#BDLActivity-activityid) 或 [token](#BDLActivity-token) 的值为空。
 */
/**
 * @locale en
 * @brief Joins the live room. After successfully joining or failing to join the live room, the SDK triggers the corresponding callback.
 * @param activity The live room information. For more information, see [BDLActivity](#BDLActivity).
 * @param success The callback triggered after successfully joining the live room, with no return value.
 * @param failure The callback triggered after failing to join the live room, with no return value.<br>
 *         Input parameter:<br>
 *        `error`: The error information. The value of `error.code` is an enumeration value of `BDLError`. For more information, see [BDLError](viewer-SDK-for-ios-error-codes#BDLError).<br>
 *        Example:<br>
 *        ```failure:^(NSError * _Nonnull error) { if ([error.domain isEqualToString:BDLErrorDomain]) { if (error.code == BDLErrorPullDisallowed) } else if ... { } } else { } }];```
 * @return - `YES`: The method is called successfully.
 *         - `NO`: Invalid parameters, meaning the value of either [activityId](#BDLActivity-activityid) or [token](#BDLActivity-token) is `nil`.
 */
- (BOOL)joinLiveRoomWithActivity:(BDLActivity *)activity
                         success:(void (^)(void))success
                         failure:(void (^)(NSError *error))failure;

/**
 * @locale zh
 * @brief 更新直播间信息，即更新直播间的 [token](#BDLActivity-token) 和 [authMode](#BDLActivity-authmode)。更新直播间信息成功或失败后，SDK 会触发对应的回调。 <br>
 *         :::warning
 *        确保使用与调用 [joinLiveRoomWithActivity:success:failure:](#BDLLiveEngine-joinliveroomwithactivity-success-failure) 时相同的 [activityId](#BDLActivity-activityid) 和 [isPortrait](#BDLActivity-isportrait)，用于更新对应直播间的信息。<br>
 *         :::
 * @param activity 直播间信息。详见 [BDLActivity](#BDLActivity)。
 * @param success 更新直播间信息成功后触发的回调，无返回值。
 * @param failure 更新直播间信息失败后触发的回调，无返回值。<br>
 *         传入参数：<br>
 *         `error`：错误信息。`error.code` 的值为 `BDLError` 的枚举值，详见 [BDLError](1185543#BDLError)。<br>
 *         示例：<br>
 *         ```failure:^(NSError * _Nonnull error) { if ([error.domain isEqualToString:BDLErrorDomain]) { if (error.code == BDLErrorPullDisallowed) } else if ... { } } else { <br>
 *         } }]; ```
 * @return - `YES`：调用方法成功。
 *         - `NO`：参数无效，即 `activityId` 或 `isPortrait` 与调用 [joinLiveRoomWithActivity:success:failure:](#BDLLiveEngine-joinliveroomwithactivity-success-failure) 时使用的 [activityId](#BDLActivity-activityid) 或 [isPortrait](#BDLActivity-isportrait) 不同、或者 [activityId](#BDLActivity-activityid) 或 [token](#BDLActivity-token) 的值为空。
 */
/**
 * @locale en
 * @brief Updates the live room information, namely updating the live room's [token](#BDLActivity-token) and [authMode](#BDLActivity-authmode). After successfully updating or failing to update the live room information, the SDK triggers the corresponding callback.
 *        :::warning
 *        Use the [activityId](#BDLActivity-activityid) and [isPortrait](#BDLActivity-isportrait) when calling [joinLiveRoomWithActivity:success:failure:](#BDLLiveEngine-joinliveroomwithactivity-success-failure) to update the corresponding live room information.
 *        :::
 * @param activity The live room information. For more information, see [BDLActivity](#BDLActivity).
 * @param success The callback triggered after successfully updating the live room information, with no return value.
 * @param failure The callback triggered after failing to update the live room information, with no return value.<br>
 *        Input parameter:<br>
 *        `error`: The error information. The value of `error.code` is an enumeration value of `BDLError`. For more information, see [BDLError](viewer-SDK-for-ios-error-codes#BDLError).<br>
 *        Example:<br>
 *        ```failure:^(NSError * _Nonnull error) { if ([error.domain isEqualToString:BDLErrorDomain]) { if (error.code == BDLErrorPullDisallowed) } else if ... { } } else {} }];
 *        ```
 * @return - `YES`: The method is called successfully.
 *         - `NO`: Invalid parameters, meaning the value of `activityId` or `isPortrait` is different from that used when calling [joinLiveRoomWithActivity:success:failure:](#BDLLiveEngine-joinliveroomwithactivity-success-failure), or the value of [activityId](#BDLActivity-activityid) or [token](#BDLActivity-token) is `nil`.
 */
- (BOOL)updateActivity:(BDLActivity *)activity
               success:(void (^)(void))success
               failure:(void (^)(NSError *error))failure;

/**
 * @locale zh
 * @brief 获取直播间页面。<br>
 *         在 [joinLiveRoomWithActivity:success:failure:](#BDLLiveEngine-joinliveroomwithactivity-success-failure) 的 `success` 回调中调用 `getLivePullViewController`。
 * @list 直播间
 * @return - [BDLLivePullViewController](#BDLLivePullViewController) 实例。
 *         - 以下三种情况，返回值为 `nil`：
 *           - 未调用 [joinLiveRoomWithActivity:success:failure:](#BDLLiveEngine-joinliveroomwithactivity-success-failure)。
 *           - 调用 [joinLiveRoomWithActivity:success:failure:](#BDLLiveEngine-joinliveroomwithactivity-success-failure) 收到返回值 `NO`。
 *           - 调用 [joinLiveRoomWithActivity:success:failure:](#BDLLiveEngine-joinliveroomwithactivity-success-failure) 进入直播间失败。
 */
/**
 * @locale en
 * @brief Gets the live room page.
 *        Call `getLivePullViewController` in the `success` callback of [joinLiveRoomWithActivity:success:failure:](#BDLLiveEngine-joinliveroomwithactivity-success-failure).
 * @return - Instance of [BDLLivePullViewController](#BDLLivePullViewController).
 *         - The return value is `nil` in the following scenarios:
 *           - [joinLiveRoomWithActivity:success:failure:](#BDLLiveEngine-joinliveroomwithactivity-success-failure) is not called.
 *           - [joinLiveRoomWithActivity:success:failure:](#BDLLiveEngine-joinliveroomwithactivity-success-failure) is called and the return value is `NO`.
 *           - [joinLiveRoomWithActivity:success:failure:](#BDLLiveEngine-joinliveroomwithactivity-success-failure) is called but failed to join the live room.
 */
- (nullable BDLLivePullViewController *)getLivePullViewController;
/**
 * @locale zh
 * @brief 通过传入一个已经在播放的 `basePlayerView` 来获取直播间页面。将 `basePlayerView` 传入该方法后，可以避免视频内容的重新获取和重新播放，让观众在进入直播间后无缝继续观看之前的视频内容。<br>
 *         在 [joinLiveRoomWithActivity:success:failure:](#BDLLiveEngine-joinliveroomwithactivity-success-failure) 的 `success` 回调中调用 `getLivePullViewControllerWithBasePlayerView:`。
 * @param basePlayerView 用于提前展示直播间视频内容的独立播放器。详见 [BDLBasePlayerView](#BDLBasePlayerView)。
 * @list 直播间
 * @return - [BDLLivePullViewController](#BDLLivePullViewController) 实例。
 *         - 以下三种情况，返回值为 `nil`：
 *           - 未调用 [joinLiveRoomWithActivity:success:failure:](#BDLLiveEngine-joinliveroomwithactivity-success-failure)。
 *           - 调用 [joinLiveRoomWithActivity:success:failure:](#BDLLiveEngine-joinliveroomwithactivity-success-failure) 收到返回值 `NO`。
 *           - 调用 [joinLiveRoomWithActivity:success:failure:](#BDLLiveEngine-joinliveroomwithactivity-success-failure) 进入直播间失败。
 */
/**
 * @locale en
 * @brief Gets the live room page by passing an already playing `basePlayerView`. After passing the `basePlayerView` into this method, you can  avoid getting and playing the video content again, allowing viewers to seamlessly continue watching the previous video content upon joining the live room.
 *        Call `getLivePullViewControllerWithBasePlayerView:` in the `success` callback of [joinLiveRoomWithActivity:success:failure:](#BDLLiveEngine-joinliveroomwithactivity-success-failure).
 * @param basePlayerView The custom player, which is used to display the live room video content in advance. For more information, see [BDLBasePlayerView](#BDLBasePlayerView).
 * @return - Instance of [BDLLivePullViewController](#BDLLivePullViewController).
 *         - The return value is `nil` in the following scenarios:
 *           - [joinLiveRoomWithActivity:success:failure:](#BDLLiveEngine-joinliveroomwithactivity-success-failure) is not called.
 *           - [joinLiveRoomWithActivity:success:failure:](#BDLLiveEngine-joinliveroomwithactivity-success-failure) is called and the return value is `NO`.
 *           - [joinLiveRoomWithActivity:success:failure:](#BDLLiveEngine-joinliveroomwithactivity-success-failure) is called but failed to join the live room.
 */
- (nullable BDLLivePullViewController *)getLivePullViewControllerWithBasePlayerView:(nullable BDLBasePlayerView *)basePlayerView;
/**
 * @locale zh
 * @brief 注册服务。
 * @param service 需要注册的实例。
 * @hidden (iOS)
 */
/**
 * @locale en
 * @hidden (iOS)
 * @brief Register Service.
 * @param service Instances that require registration.
 */
- (void)registerService:(id)service;
/**
 * @locale zh
 * @brief 取消注册服务。
 * @param service 需要取消注册的实例。
 * @hidden (iOS)
 */
/**
 * @locale en
 * @hidden (iOS)
 * @brief Unregister the service.
 * @param service The instance that needs to be unregistered.
 */
- (void)unregisterSercice:(id)service;
/**
 * @locale zh
 * @brief 获取服务提供者。
 * @param protocol 需要遵守的 protocol。
 * @return 遵守了 `protocol` 协议的类的实例。
 */
/**
 * @locale en
 * @brief Gets the service provider.
 * @param protocol The protocol to conform to.
 * @return Instances of classes that conform to the `protocol` protocol.
 */
- (nullable id)getProviderWithProtocol:(Protocol *)protocol;
/**
 * @locale zh
 * @brief 获取 `ActivityService`。需在 [joinLiveRoomWithActivity:success:failure:](#BDLLiveEngine-joinliveroomwithactivity-success-failure) 成功后调用。
 * @return 遵守了 `BDLActivityService` 协议的类的实例。
 */
/**
 * @locale en
 * @brief Gets `ActivityService`. Call this method after [joinLiveRoomWithActivity:success:failure:](#BDLLiveEngine-joinliveroomwithactivity-success-failure) succeeds.
 * @return Instances of classes that conform to the `BDLActivityService` protocol.
 */
- (nullable id <BDLActivityService>)getActivityService;
/**
 * @locale zh
 * @brief 根据 protocol 查找遵守该 protocol 类的实例。
 * @param protocol 需要遵守的 protocol。
 * @return 遵守该 protocol 的类的实例。
 */
/**
 * @locale en
 * @brief Find instances of classes that conform to the protocol based on the protocol.
 * @param protocol The protocol to conform to.
 * @return Instances of classes that conform to the protocol.
 */
- (nullable id)serviceWithProtocol:(Protocol *)protocol;
/**
 * @locale zh
 * @brief 离开直播间。
 */
/**
 * @locale en
 * @brief Leaves the live room.
 */
- (void)leaveLiveRoom;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
