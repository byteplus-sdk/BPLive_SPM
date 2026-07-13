//
//  BDMultiNetworkConfig.h
//  TTNetworkManager
//
//  The TTNetworkManager is licensed under the MIT License.
//  Copyright (c) 2023 Bytedance Inc.
//

#ifndef BDMultiNetworkConfig_h
#define BDMultiNetworkConfig_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @brief 使用此模块时，注入BDNetwork ModuleMap时用的Key
 */
extern NSString * const kBDMultiNetworkConfigKey;

/*!
 @brief WiFi切Cell状态变化的回调定义。
 @discussion changeInfo中存储有previous_state和current_state。
 */
typedef void (^WiFiToCellStateChangeCallback)(NSDictionary * _Nonnull changeInfo);

/*!
 @brief 关于WiFi切Cell状态的定义。
 */
typedef NS_ENUM(NSInteger, BDWiFiToCellState) {
    // 停止状态。当前选路管理模块不工作。可能原因如下：1. 当前安卓版本低于4.0；2. 选路管理模块还没被初始化。
    WTC_STATE_STOPPED = -1,
    // 既没有接入WiFi，也没有接入移动数据网络。
    WTC_STATE_NO_NETWORK = 0,
    // 没有接入WiFi，正在使用移动数据网络。
    WTC_STATE_DEFAULT_CELLULAR,
    // 正在使用WiFi网络，且移动数据网络关闭。一般手机连接WiFi后，移动数据网络会自动关闭。
    WTC_STATE_DEFAULT_WIFI_WITH_CELLULAR_DOWN,
    // 正在使用WiFi网络，且移动数据网络开启。
    WTC_STATE_DEFAULT_WIFI_WITH_CELLULAR_UP,
    // 管理模块正在激活手机移动网络常开。
    WTC_STATE_WAIT_CELLULAR_ALWAYS_UP,
    // 管理模块正在等待宿主APP确认，使数据链路从WiFi切换到移动网络。
    WTC_STATE_WAIT_USER_ENABLE,
    // 已连接WiFi，但是数据通过移动网络传输。
    WTC_STATE_WIFI_WITH_CELLULAR_TRANS_DATA,
    // 切换到移动网络前，探测移动网络的质量。
    WTC_STATE_EVALUATE_CELLULAR,
    WTC_STATE_COUNT
};

/*!
 @brief 多网络状态变化的回调定义。
 @discussion 分别为之前的多网络状态previousState，当前的多网络状态currentState。状态定义参考BDMultiNetState。
 */
typedef void (^MultiNetStateChangeCallback)(NSInteger previousState, NSInteger currentState);

/*!
 @brief 关于多网络状态的定义。
 */
typedef NS_ENUM(NSInteger, BDMultiNetState) {
    // 停止状态。
    MN_STATE_STOPPED = -1,
    // 既没有接入WiFi，也没有接入移动数据网络。
    MN_STATE_NO_NETWORK = 0,
    // 没有接入WiFi，正在使用移动数据网络。
    MN_STATE_DEFAULT_CELLULAR_WITH_WIFI_DOWN = 1,
    // 正在使用WiFi网络，且移动数据网络关闭。一般手机连接WiFi后，移动数据网络会自动关闭。
    MN_STATE_DEFAULT_WIFI_WITH_CELLULAR_DOWN = 2,
    // 正在使用WiFi网络，且移动数据网络开启。
    MN_STATE_DEFAULT_WIFI_WITH_CELLULAR_UP = 3,
    // 管理模块正在激活手机移动网络常开。
    MN_STATE_WAIT_CELLULAR_ALWAYS_UP = 4,
    // 正在使用VPN。
    MN_STATE_DEFAULT_VPN = 5,
    MN_STATE_COUNT
};

@interface BDMultiNetworkConfig : NSObject

/*!
 @brief optional，是否开启WiFiToCell切换模块
 @discussion 默认NO
 */
@property(atomic, assign) BOOL enable;

/*!
 @brief optional，WiFi切Cell状态变化后的回调
 @discussion 通过回调结果获取WiFi切Cell状态变化前后的值，在MNet网络线程执行，具体状态值为BDWiFiToCellState，默认nil
 */
@property(atomic, copy, nullable) WiFiToCellStateChangeCallback wiFiToCellCallback;

/*!
 @brief optional，通过WiFi网络向列表中的域名发起探测，以便从LTE恢复为WiFi。
 @discussion 至少提供两个域名，只要其中一个探测结果满足非弱网条件，就认为当前网络不是弱网了，默认Array为空
 */
@property(atomic, copy) NSArray<NSString*>* cellToWifiDetectTargetHosts;

/*!
 @brief 当NQE网络分级结果小于等于这个值时，认为进入弱网
 @discussion 默认5
 */
@property(atomic, assign) int poorNetLevel;

/*!
 @brief
 optional，当需要切换成WIFI_WITH_LTE状态时，如果此开关为1，则会自动切换；如果为0，则需要业务调接口主动切换。
 @discussion 默认NO
 */
@property(atomic, assign) BOOL autoSwitch;

/*!
 @brief optional，是否允许业务指定请求使用的默认网络或备用网络（Cell）。
 @discussion 默认NO
 */
@property(atomic, assign) BOOL enableUserCtl;

/*!
 @brief optional，多网络状态变化后的回调
 @discussion 通过回调结果获取多网络状态变化前后的值和触发时间戳，在MNet网络线程执行，具体状态值为BDMultiNetState，默认nil
 */
@property(atomic, copy, nullable) MultiNetStateChangeCallback multiNetStateCallback;

/*!
 @brief optional，通知模块是否切换网络
 @discussion 默认打开自动切换网络，如果不需要，传入NO。
 */
+ (void)notifySwitchToMultiNetwork:(BOOL)enable;

/*!
 @brief optional，触发TTNet检查当前网络状态，若符合条件（4G可用，且满足4G RTT < 100 ms）则进入切换4G流程
 */
+ (void)triggerSwitchingToCellular;

@end

NS_ASSUME_NONNULL_END

#endif /* BDMultiNetworkConfig_h */
