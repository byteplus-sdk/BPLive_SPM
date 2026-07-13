/*
 * Copyright (c) 2022 The BytePlusRTC project authors. All Rights Reserved.
 * @brief Objective-C BytePlusRTC Common Defines
*/

#import <CoreMedia/CMTime.h>
#if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
#import <UIKit/UIKit.h>
typedef UIView   ByteRTCView;
typedef UIImage  ByteRTCImage;
#elif TARGET_OS_MAC
#import <AppKit/AppKit.h>
typedef NSView   ByteRTCView;
typedef NSImage  ByteRTCImage;
#endif

#ifdef __APPLE__
#define _BYTERTC_PLATFORM_APPLE 1
#include <TargetConditionals.h>
#if TARGET_OS_IPHONE
#define _BYTERTC_PLATFORM_MAC 0
#define _BYTERTC_PLATFORM_IOS 1
#elif TARGET_IPHONE_SIMULATOR
#define _BYTERTC_PLATFORM_MAC 0
#define _BYTERTC_PLATFORM_IOS 1
#elif TARGET_OS_MAC
#define _BYTERTC_PLATFORM_MAC 1
#define _BYTERTC_PLATFORM_IOS 0
#else
#error "Unknown Apple platform"
#endif
#endif

#define BYTERTC_TARGET_MAC (_BYTERTC_PLATFORM_MAC == 1)
#define BYTERTC_TARGET_IOS (_BYTERTC_PLATFORM_IOS == 1)

#define BYTERTC_APPLE_EXPORT __attribute__((visibility("default")))



/**
 * 
 * @type keytype
 * @hidden currently not available
 */
typedef NS_ENUM(NSInteger, ByteRTSReturnStatus) {
   
    /**
    * 
    * @hidden currently not available
    */
    ByteRTSReturnStatusSuccess = 0,
   
    /**
    * 
    * @hidden currently not available
    */
    ByteRTSReturnStatusFailure = -1,
   
    /**
    * 
    * @hidden currently not available
    */
    ByteRTSReturnStatusParameterErr = -2,
   
    /**
    * 
    * @hidden currently not available
    */
    ByteRTSReturnStatusWrongState = -3,
   
    /**
    * 
    * @hidden currently not available
    */
    ByteRTSReturnStatusHasInRoom = -4,
   
    /**
    * 
    * @hidden currently not available
    */
    ByteRTSReturnStatusHasInLogin = -5,
   
    /**
    * 
    * @hidden currently not available
    */
    ByteRTSReturnStatusRoomIdInUse = -8,
};



/**
 * 
 *  @type keytype
 *  @brief  The reason why the user leaves the room.
 */
typedef NS_ENUM(NSUInteger, ByteRTCUserOfflineReason) {
    
    /**
     * 
     * @brief The remote user calls `leaveRoom` and leaves the room.
     */
    ByteRTCUserOfflineReasonQuit = 0,
    
    /**
     * 
     * @brief The remote user is offline.
     */
    ByteRTCUserOfflineReasonDropped = 1,
    
     /**
      * 
      * @brief The remote user switches to invisible.
      */
    ByteRTCUserOfflineReasonSwitchToInvisible = 2,
    
    /**
     * 
     * @brief The remote user is kicked out of the room. <br>
     *        Is kicked out of the room due to calling the kicked out user's OpenAPI.
     */
    ByteRTCUserOfflineReasonKickedByAdmin = 3,
};


/**
 * 
 * @type keytype
 * @brief SDK  Connection status with the signaling server.
 */
typedef NS_ENUM(NSInteger, ByteRTCConnectionState) {
    
    /**
     * 
     * @brief Disconnected for 12s, SDK will try to reconnect automatically.
     */
    ByteRTCConnectionStateDisconnected = 1,
    
    /**
     * 
     * @brief The first request to connect to the server. Connecting.
     */
    ByteRTCConnectionStateConnecting = 2,
    
    /**
     * 
     * @brief The first connection was successful.
     */
    ByteRTCConnectionStateConnected = 3,
    
    /**
     * 
     * @brief The code includes the following status: <br>
     *        - The first connection is not successful for 10s.
     *        - The connection has been lost for 10s. Auto reconnecting.
     */
    ByteRTCConnectionStateReconnecting = 4,
    
    /**
     * 
     * @brief Successful reconnection after disconnection.
     */
    ByteRTCConnectionStateReconnected = 5,
    
    /**
     * 
     * @brief In status `ByteRTCConnectionStateDisconnected` for more than 10s without a successful reconnection. SDK will still continue to try to reconnect.
     */
    ByteRTCConnectionStateLost = 6,
    
    /**
     * 
     * @brief Connection failure caused by abnormal state of the server. SDK will not automatically reconnect, please re-enter the room or contact technical support.
     */
    ByteRTCConnectionStateFailed = 7,
};


/**
 * 
 * @type keytype
 * @brief SDK  Network connection type.
 */
typedef NS_ENUM(NSInteger, ByteRTCNetworkType) {
    
    /**
     * 
     * @brief Network connection type unknown.
     */
    ByteRTCNetworkTypeUnknown = -1,
    
    /**
     * 
     * @brief The network connection has been disconnected.
     */
    ByteRTCNetworkTypeDisconnected = 0,
    
    /**
     * 
     * @brief The network connection type is LAN.
     */
    ByteRTCNetworkTypeLAN = 1,
    
    /**
     * 
     * @brief The network connection type is Wi-Fi (including hotspots).
     */
    ByteRTCNetworkTypeWIFI = 2,
    
    /**
     * 
     * @brief The network connection type is 2G mobile network.
     */
    ByteRTCNetworkTypeMobile2G = 3,
    
    /**
     * 
     * @brief The network connection type is 3G mobile network.
     */
    ByteRTCNetworkTypeMobile3G = 4,
    
    /**
     * 
     * @brief The network connection type is 4G mobile network.
     */
    ByteRTCNetworkTypeMobile4G = 5,
    
    /**
     * 
     * @brief The network connection type is 5G mobile network.
     */
    ByteRTCNetworkTypeMobile5G = 6,
};


/**
 * 
 * @type keytype
 * @brief Media streaming network quality.
 */
typedef NS_ENUM(NSUInteger, ByteRTCNetworkQuality) {
    
    /**
     * 
     * @brief Network quality unknown.
     */
    ByteRTCNetworkQualityUnknown = 0,
    
    /**
     * 
     * @brief The network quality is excellent.
     */
    ByteRTCNetworkQualityExcellent = 1,
    
    /**
     * 
     * @brief The subjective feeling is similar to kNetworkQualityExcellent, but the bit rate may be slightly lower.
     */
    ByteRTCNetworkQualityGood = 2,
    
    /**
     * 
     * @brief Subjective feelings are flawed but do not affect communication.
     */
    ByteRTCNetworkQualityPoor = 3,
    
    /**
     * 
     * @brief Can barely communicate but not smoothly.
     */
    ByteRTCNetworkQualityBad = 4,
    
    /**
     * 
     * @brief The quality of the network is very poor and communication is basically impossible.
     */
    ByteRTCNetworkQualityVeryBad = 5,
    
    /**
     * 
     * @brief The network is down. It may be down due to no answer within 12s, airplane mode on, disconnected cable, etc. <br>
     *        Refer to [Get connection state](https:
     */
    ByteRTCNetworkQualityDown = 6,
};


/**
 * 
 * @type errorcode
 * @brief  Callback error code. When an unrecoverable error is encountered internally in the <br>
 *        SDK, the user is notified via an `rtcEngine:onError:` callback.
 */
typedef NS_ENUM(NSInteger, ByteRTSErrorCode) {
    
    /**
     * 
     * @brief Token is invalid. <br>
     *         The token used when joining the room is invalid or expired. The user is required to retrieve the token and update it by calling `updateToken:`.
     */
    ByteRTSErrorCodeInvalidToken               = -1000,
    
    /**
     * 
     * @brief Join room error. <br>
     *        An unknown error occurred when joining the room, which caused the room to fail to join. Users are required to rejoin the room.
     */
    ByteRTSErrorCodeJoinRoom             = -1001,
    
    /**
     * 
     * @brief The user has been removed from the room because the same user joined the room on the other client.
     */
    ByteRTSErrorCodeDuplicateLogin             = -1004,

    
    /**
     * 
     * @brief The user has been removed from the room by the administrator via a OpenAPI call.
     */
    ByteRTSErrorCodeKickedOut = -1006,

    
    /**
     * 
     * @brief When calling `createRtcRoom:`, if the roomId is illegal, it will return null and throw the error
     */
    ByteRTSErrorCodeRoomIdIllegal = -1007,

    
    /**
     * 
     * @brief Token expired. Call `joinRoomByKey:roomId:userInfo:rtcRoomConfig:` to rejoin with a valid Token.
     */
    ByteRTSErrorCodeTokenExpired            = -1009,
        
    /**
     * 
     * @brief The Token you provided when calling `updateToken:` is invalid.
     */
    ByteRTSErrorCodeUpdateTokenWithInvalidToken     = -1010,

    
    /**
     * 
     * @brief Users have been removed from the room because the administrator dismissed the room by calling OpenAPI.
     */
    ByteRTSErrorCodeRoomDismiss = -1011,

    
    /**
     * 
     * @brief there is a room with the same roomId，whose room id is the same with echo test
     */
    ByteRTSErrorRoomAlreadyExist = -1013,

    
    /**
     * 
     * @brief The local user joins multiple rooms with different uid. <br>
     *        In the same engine instance, users need to use the same uid to join different rooms.
     */
    ByteRTSErrorUserIDDifferent = -1014,

    
    /**
     * 
     * @brief The user has been removed from the room due to the abnormal status of server. <br>
     *        SDK  is disconnected with the signaling server. It will not reconnect automatically. Please contact technical support.
     */
    ByteRTSErrorCodeAbnormalServerStatus = -1084,
};


/**
 * 
 * @type errorcode
 * @brief  Callback warning code. The warning code indicates that there is a problem within the SDK and is trying to recover. Warning codes are for notification only.
 */
typedef NS_ENUM(NSInteger, ByteRTSWarningCode) {
    
    /**
     * 
     * @brief Failed to enter the room. <br>
     *        When entering the room for the first time or when the network is disconnected and reconnected due to poor network conditions, entering the room failed due to a server error. The SDK automatically retries the room.
     */
    ByteRTSWarningCodeJoinRoomFailed             = -2001,
    
    /**
     * 
     * @brief Release audio & video stream failed. <br>
     *        When you publish audio & video streams in your room, the release fails due to a server error. The SDK automatically retries the release.
     */
    ByteRTSWarningCodePublishStreamFailed        = -2002,
    
    /**
     * 
     * @hidden currently not available
     * @brief  Function call order is wrong and is not used in the current code.
     */
    ByteRTSWarningCodeInvokeError = -2005,
    
    /**
     * 
     * @hidden for internal use only
     * @brief Scheduling exception, the media server address returned by the server is unavailable.
     */
    ByteRTSWarningCodeInvalidExpectMediaServerAddress = -2007,
    
    /**
     * 
     * @brief Sending a custom broadcast message failed, you are not currently in the room.
     */
    ByteRTSWarningCodeSendCustomMessage = -2011,
    
    /**
     * 
     * @hidden
     * @deprecated since 3.46 and will be deleted in 3.52.
     * @brief there is a room with the same roomId
     */
    ByteRTSWarningCodeRoomAlreadyExist = -2015,

    
    /**
     * 
     * @brief The old room has been replaced by new room with the same roomId
     */
    ByteRTSWarningCodeOldRoomBeenReplaced = -2016
};


/**
 * 
 * @type keytype
 * @brief Log level.
 */
typedef NS_ENUM(NSUInteger, ByteRTCLogLevel) {
    
    /**
     * 
     * @brief Print trace level and above information.
     */
    ByteRTCLogLevelTrace,
    
    /**
     * 
     * @brief  Print debug level and above information.
     */
    ByteRTCLogLevelDebug,
    
    /**
     * 
     * @brief  Print info level and above information.
     */
    ByteRTCLogLevelInfo,
    
    /**
     * 
     * @brief  Print warning level and above information.
     */
    ByteRTCLogLevelWarning,
    
    /**
     * 
     * @brief  Print error level information.
     */
    ByteRTCLogLevelError,
};


/**
 * 
 * @type errorcode
 * @brief  Login result <br>
 *        The result of calling `login:uid:` will notify the user through `rtcEngine:onLoginResult:errorCode:elapsed:` callback.
 */
typedef NS_ENUM(NSInteger, ByteRTCLoginErrorCode) {
    
    /**
     * 
     * @brief Call the `login:uid:` method to log in successfully.
     */
    ByteRTCLoginErrorCodeSuccess = 0,
    
    /**
     * 
     * @brief The token used when calling the `login:uid:` method is invalid or expired. The user is required to re-acquire the token.
     */
    ByteRTCLoginErrorCodeInvalidToken = -1000,
    
    /**
     * 
     * @brief Login error <br>
     *        An unknown error occurred when calling the `login:uid:` method, which caused the login to fail. The user is required to log in again.
     */
    ByteRTCLoginErrorCodeLoginFailed = -1001,
    
    /**
     * 
     * @brief There was a problem with the incoming user ID when the `login:uid:` method was called.
     */
    ByteRTCLoginErrorCodeInvalidUserId = -1002,
    
    /**
     * 
     * @brief Call `login:uid:` server error while logging in.
     */
    ByteRTCLoginErrorCodeServerError = -1003,
};


/**
 * 
 * @type keytype
 * @brief The reason why users log out
 */
typedef NS_ENUM(NSUInteger, ByteRTCLogoutReason) {
    
    /**
     * 
     * @brief Users choose to logout by calling the `logout` to log out or terminating the engine to log out.
     */
    ByteRTCLogoutReasonLogout = 0,
    
    /**
     * 
     * @brief The current user is kicked out as another user logs in with the same UserId.
     */
    ByteRTCLogoutReasonDuplicateLogin = 1,
};


/**
 * 
 * @type keytype
 * @brief Reliable orderliness of sent messages
 */
typedef NS_ENUM(NSInteger, ByteRTCMessageConfig) {
    
    /**
     * 
     * @brief Low latency reliable and orderly message
     */
    ByteRTCMessageConfigReliableOrdered = 0,
    
    /**
     * 
     * @brief Ultra-low latency ordered message
     */
    ByteRTCMessageConfigUnreliableOrdered = 1,
    
    /**
     * 
     * @brief Ultra-low latency unordered message
     */
    ByteRTCMessageConfigUnreliableUnordered = 2,
};


/**
 * 
 * @type errorcode
 * @brief Result of sending messages and the reason of failure if it fails.
 */
typedef NS_ENUM(NSInteger, ByteRTCUserMessageSendResult) {
    
    /**
     * 
     * @brief The message has been sent successfully.
     */
    ByteRTCUserMessageSendResultSuccess = 0,
    
    /**
     * 
     * @brief Failure. Sending timeout.
     */
    ByteRTCUserMessageSendResultTimeout = 1,
    
    /**
     * 
     * @brief Failure. Channel disconnected.
     */
    ByteRTCUserMessageSendResultNetworkDisconnected = 2,
    
    /**
     * 
     * @brief Failure. Recipient not found.
     */
    ByteRTCUserMessageSendResultNoReceiver = 3,
    
    /**
     * 
     * @brief Failure. The remote user did not logged in or joining the room.
     */
    ByteRTCUserMessageSendResultNoRelayPath = 4,
    
    /**
     * 
     * @brief Failure. Exceeds QPS limit.
     */
    ByteRTCUserMessageSendResultExceedQPS = 5,
    
    /**
     * 
     * @brief Failure. The app server failed to receive the message sent by the client. <br>
     *        Triggered by calling `sendServerMessage` or `sendServerBinaryMessage`, and carried by `onServerMessageSendResult` callback.
     */
    ByteRTCUserMessageSendResultE2BSSendFailed = 17,
    
    /**
     * 
     * @brief Failure. The app server received the message sent by the client, but failed to response. <br>
     *        Triggered by calling `sendServerMessage` or `sendServerBinaryMessage`, and carried by `onServerMessageSendResult` callback.
     */
    ByteRTCUserMessageSendResultE2BSReturnFailed = 18,
    
    /**
     * 
     * @brief Failure. The sender of the message did not join the room
     */
    ByteRTCUserMessageSendResultNotJoin = 100,
    
    /**
     * 
     * @brief Failure. Connection initialization not completed
     */
    ByteRTCUserMessageSendResultInit = 101,
    
    /**
     * 
     * @brief Failure. No data transmission channel connection available
     */
    ByteRTCUserMessageSendResultNoConnection = 102,
    
    /**
     * 
     * @brief Failure. Message exceeds the range of the permitted size, 64 KB.
     */
    ByteRTCUserMessageSendResultExceedMaxLength = 103,
    
    /**
     * 
     * @brief Failure. The id of the recipient is empty
     */
    ByteRTCUserMessageSendResultEmptyUser = 104,
    
    /**
     * 
     * @brief Failure. The sender of the message did not log in.
     */
    ByteRTCUserMessageSendResultNotLogin = 105,
    
    /**
     * 
     * @brief Failure. No parameters were set before sending the message to the server
     */
    ByteRTCUserMessageSendResultServerParamsNotSet = 106,
    
    /**
     * 
     * @brief Failure. Unknown error.
     */
    ByteRTCUserMessageSendResultUnknown = 1000,
};


/**
 * 
 * @type keytype
 * @brief  User online status
 */
typedef NS_ENUM(NSInteger, ByteRTCUserOnlineStatus) {
    
    /**
     * 
     * @brief The peer user is offline <br>
     *        The peer user has called `logout`, or has not called `login:uid:` to log in
     */
    ByteRTCUserOnlineStatusOffline = 0,
    
    /**
     * 
     * @brief The peer user is online <br>
     *        The peer user calls `login:uid:` to log in and the connection status is normal
     */
    ByteRTCUserOnlineStatusOnline = 1,
    
    /**
     * 
     * @brief Unable to get the online state of the peer user <br>
     *        Returned when a cascade error occurs and the online state of the peer user is abnormal
     */
    ByteRTCUserOnlineStatusUnreachable = 2,
};


/**
 * 
 * @type errorcode
 * @brief Result of broadcasting messages in the room
 */
typedef NS_ENUM(NSInteger, ByteRTCRoomMessageSendResult) {
    
    /**
     * 
     * @brief The message sent successfully.
     */
    ByteRTCRoomMessageSendResultSuccess = 200,
    
    /**
     * 
     * @brief Failure. Sending timeout.
     */
    ByteRTCRoomMessageSendResultTimeout = 1,
    
    /**
     * 
     * @brief Failure. Channel disconnected.
     */
    ByteRTCRoomMessageSendResultNetworkDisconnected = 2,
    
    /**
     * 
     * @brief Failure. Exceeds QPS limit.
     */
    ByteRTCRoomMessageSendResultExceedQPS = 5,
    
    /**
     * 
     * @brief Failure. The sender has not joined a room.
     */
    ByteRTCRoomMessageSendResultNotJoin = 100,
    
    /**
     * 
     * @brief Failure. The connection has not completed initialization.
     */
    ByteRTCRoomMessageSendResultInit = 101,
    
    /**
     * 
     * @brief Failure. No connection available.
     */
    ByteRTCRoomMessageSendResultNoConnection = 102,
    
    /**
     * 
     * @brief Failure. Message exceeds the range of the permitted size, 64 KB.
     */
    ByteRTCRoomMessageSendResultExceedMaxLength = 103,
    
    /**
     * 
     * @brief Failure. Unknown error.
     */
    ByteRTCRoomMessageSendResultUnknown = 1000,
};


/**
 * 
 * @hidden for internal use only
 * @type keytype
 * @brief SDK server environment.
 */
typedef NS_ENUM(NSInteger, ByteRTCEnv) {
    
    /**
     * 
     * @brief Online environment.
     */
    ByteRTCEnvProduct = 0,
    
    /**
     * 
     * @brief BOE environment.
     */
    ByteRTCEnvBOE = 1,
    
    /**
     * 
     * @brief Test environment.
     */
    ByteRTCEnvTest = 2,
};


/**
 * 
 * @type keytype
 * @brief Local log parameters.
 */
typedef NS_ENUM(NSUInteger, ByteRTCLocalLogLevel) {
    
    /**
     * 
     * @brief Info level.
     */
    ByteRTCLocalLogLevelInfo = 0,
    
    /**
     * 
     * @brief (Default) Warning level.
     */
    ByteRTCLocalLogLevelWarning = 1,
    
    /**
     * 
     * @brief Error level.
     */
    ByteRTCLocalLogLevelError = 2,
    
    /**
     * 
     * @brief Turn off logging.
     */
    ByteRTCLocalLogLevelNone = 3
};


/**
 * 
 * @type keytype
 * @brief The cpu and memory information used by App <br>
 *         Information is periodically (2s) notified to the user by the SDK via the `reportSysStats` callback event.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCSysStats : NSObject

/**
 * 
 * @brief Current system cpu number
 */
@property(assign, nonatomic) unsigned int cpuCores;

/**
 * 
 * @brief The CPU usage of the current application, the value range is [0,1].
 */
@property(assign, nonatomic) double cpuAppUsage;

/**
 * 
 * @hidden currently not available
 * @brief The current system CPU usage, the value range is [0,1].
 */
@property(assign, nonatomic) double cpuTotalUsage;

/**
 * 
 * @brief Memory usage of the current app (in MB)
 */
@property(assign, nonatomic) double memoryUsage;

/**
 * 
 * @brief Full memory (in MB)
 */
@property(assign, nonatomic) unsigned long long fullMemory;

/**
 * 
 * @brief System used memory (in MB)
 */
@property(assign, nonatomic) unsigned long long totalMemoryUsage;

/**
 * 
 * @brief Free allocable memory (in MB)
 */
@property(assign, nonatomic) unsigned long long freeMemory;

/**
 * 
 * @brief Memory usage of the current application (in %)
 */
@property(assign, nonatomic) double memoryRatio;

/**
 * 
 * @brief System memory usage (in %)
 */
@property(assign, nonatomic) double totalMemoryRatio;
@end


/**
 * 
 * @type keytype
 * @brief Local log parameters.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCLogConfig : NSObject

/**
 * 
 * @brief (Required) Local log directory.
 */
@property(copy, nonatomic) NSString *_Nonnull logPath;


/**
 * 
 * @brief (Optional) The logging level. See ByteRTCLocalLogLevel{@link #ByteRTCLocalLogLevel}. The default is warning level.
 */
@property(assign, nonatomic) ByteRTCLocalLogLevel logLevel;


/**
 * 
 * @brief (Optional) The limits for total log file size in MB. The range is 1 to 100 MB, and the default value is 10 MB. <br>
 *        If `logFileSize` < 1, it will be set to 1 MB. If `logFileSize` > 100, it will be set to 100 MB. <br>
 *        The maximum size for a single log file is 2 MB. <br>
 *        If 1 ≤ `logFileSize` ≤ 2, one log file will be generated. If `logFileSize` > 2, the first `⌊logFileSize/2⌋` files will be filled with 2 MB each, the `⌊logFileSize/2⌋+1` fill will be filled with `logFileSize mod 2`. <br>
 *        If the size exceeds the remaining space, the oldest file will be deleted.
 */
@property(assign, nonatomic) int logFileSize;


/**
 * 
 * @brief (Optional) Local log file name prefix. It should follow the regular expression pattern of `[a-zA-Z0-9_@-.]{1,128}`. <br>
 *        The final file name will be the prefix followed by "_" and the file creation time, and "_rtclog.log" at the end. For example, `logPrefix_2023-05-25_172324_rtclog.log`.
 */
@property(copy, nonatomic) NSString *_Nonnull logFilenamePrefix;
@end


/**
 * 
 * @hidden for internal use only
 * @type callback
 * @region  monitoring
 * @brief  Non-business related monitoring event callback
 */
@protocol ByteRTCMonitorDelegate <NSObject>
@optional

/**
 * 
 * @type callback
 * @region monitoring
 * @brief Event tracking log callback
 * @param data <br>
 *        Specific event tracking content
 * @param type <br>
 *        Event tracking type
 */
- (void)onMonitorLog:(NSDictionary * _Nullable)data withType:(NSString * _Nullable)type;


/**
 * 
 * @type api
 * @region  monitor
 * @brief  Whether to output from the console
 * @return
 *         Return whether to output from the console <br>
 *         - YES output all logs to the console
 *         - NO output no console information
 */
- (BOOL)isConsole;


/**
 * 
 * @type callback
 * @region  monitor
 * @brief  Output more debugging information
 */
- (void)onVerboseLogWithLevel:(ByteRTCLogLevel)level
                     filename:(NSString * _Nonnull)filename
                          tag:(NSString * _Nonnull)tag
                         line:(int)line
                 functionName:(NSString * _Nonnull)funcName
                       format:(NSString * _Nonnull)format;
@end


/**
 * 
 * @type keytype
 * @brief Cloud Proxy Information
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCCloudProxyInfo: NSObject

/**
 * 
 * @type keytype
 * @brief Cloud proxy IP
 */
@property(strong, nonatomic) NSString* _Nonnull cloudProxyIp;

/**
 * 
 * @type keytype
 * @brief Cloud proxy Port
 */
@property(assign, nonatomic) int cloudProxyPort;
@end


/**
 * 
 * @type keytype
 * @brief Types of local proxies.
 */
typedef NS_ENUM(NSUInteger, ByteRTCLocalProxyType) {
    
    /**
     * 
     * @brief Socks5 proxy. If you chose Socks5 as the local proxy, you need to make sure all requirements listed in the Socks5 document are satisfied.
     */
    ByteRTCLocalProxyTypeSocks5 = 1,
    
    /**
     * 
     * @brief Http tunnel proxy.
     */
    ByteRTCLocalProxyTypeHttpTunnel = 2,
};


/**
 * 
 * @type keytype
 * @brief Detailed information of local proxy configurations.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCLocalProxyInfo : NSObject

/**
 * 
 * @brief Types of the local proxies. Refer to ByteRTCLocalProxyType{@link #ByteRTCLocalProxyType} for details.
 */
@property(assign, nonatomic) ByteRTCLocalProxyType localProxyType;

/**
 * 
 * @type keytype
 * @brief Local proxy IP.
 */
@property(copy, nonatomic) NSString * _Nullable localProxyIp;

/**
 * 
 * @type keytype
 * @brief Local proxy port.
 */
@property(assign, nonatomic) int localProxyPort;
 
 /**
  * 
  * @type keytype
  * @brief The username of the local proxy.
  */
@property(copy, nonatomic) NSString * _Nullable localProxyUsername;
 
 /**
  * 
  * @brief The password of the local proxy.
  */
@property(copy, nonatomic) NSString * _Nullable localProxyPassword;
@end


/**
 * 
 * @type keytype
 * @brief The states of local proxy connection.
 */
typedef NS_ENUM(NSUInteger, ByteRTCLocalProxyState) {
    
    /**
     * 
     * @brief TCP proxy server is connected.
     */
    ByteRTCLocalProxyStateInited = 0,

    
    /**
     * 
     * @brief The local proxy is connected.
     */
    ByteRTCLocalProxyStateConnected = 1,

    
    /**
     * 
     * @brief Errors occurred when connecting to the local proxy.
     */
    ByteRTCLocalProxyStateError = 2,
};


/**
 * 
 * @type keytype
 * @brief The errors of local proxy connection.
 */
typedef NS_ENUM(NSUInteger, ByteRTCLocalProxyError) {
    
    /**
     * 
     * @brief There are no errors in local proxies.
     */
    ByteRTCLocalProxyErrorOK = 0,

    
    /**
     * 
     * @brief The connection to Socks5 proxy failed because the proxy server replies wrong version numbers which don't accord with the Socks5 document. Please check the proxy server.
     */
    ByteRTCLocalProxyErrorSocks5VersionError = 1,

    
    /**
     * 
     * @brief The connection to Socks5 proxy failed because the format of the proxy's replies doesn't accord with the Socks5 document. Please check the proxy server.
     */
    ByteRTCLocalProxyErrorSocks5FormatError = 2,

    
    /**
     * 
     * @brief The connection to Socks5 proxy failed because the proxy replies wrong information which doesn't accord with the Socks5 document. Please check the proxy server.
     */
    ByteRTCLocalProxyErrorSocks5InvalidValue = 3,

    
    /**
     * 
     * @brief The connection to Socks5 proxy failed because the username and password of the local proxy are not provided. Please call `setLocalProxy` and enter your username and password.
     */
    ByteRTCLocalProxyErrorSocks5UserPassNotGiven = 4,

    
    /**
     * 
     * @brief The connection to Socks5 proxy failed because TCP is closed. Please check the proxy server and your network connection status.
     */
    ByteRTCLocalProxyErrorSocks5TcpClosed = 5,

    
    /**
     * 
     * @brief Errors in Http tunnel proxy. Please check Http tunnel proxy and your network connection status.
     */
    ByteRTCLocalProxyErrorHttpTunnelFailed = 6,
};