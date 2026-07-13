#import "ByteRTCRoom.h"
#import "rtc/ByteRTCVideoDefinesEx.h"

@class ByteRTCRoomEx;


@protocol ByteRTCRoomDelegateEx <NSObject>
@optional

- (void)rtcRoom:(ByteRTCRoom* _Nonnull)rtcRoom
        onUserPublishStream:(ByteRTCRemoteStreamKey* _Nonnull)streamKey
                   isScreen:(BOOL)isScreen
            mediaStreamType:(ByteRTCMediaStreamType)type;

- (void)rtcRoom:(ByteRTCRoom* _Nonnull)rtcRoom
        onUserUnpublishStream:(ByteRTCRemoteStreamKey* _Nonnull)streamKey
              mediaStreamType:(ByteRTCMediaStreamType)type
                       reason:(ByteRTCStreamRemoveReason)reason;

- (void)rtcRoom:(ByteRTCRoom* _Nonnull)rtcRoom
        onStreamStateChanged:(ByteRTCStreamKey* _Nonnull)streamKey
                       state:(NSInteger)state
                   extraInfo:(NSString* _Nonnull)extraInfo;

- (void)rtcRoom:( ByteRTCRoom *_Nonnull)rtcRoom onAVSyncEvent:(ByteRTCStreamKey*)streamKey eventCode:(ByteRTCAVSyncEvent)eventCode;


/**
 * 
 * @type callback
 * @region Room management
 * @brief Callback on subscription status of media streams
 * @param rtcRoom The r rtcRoom instance.
 * @param state Subscription status of media streams, see ByteRTCSubscribeState{@link #ByteRTCSubscribeState}.
 * @param userId The ID of the user who published the stream.
 * @param info Configurations of stream subscription, see ByteRTCSubscribeConfig{@link #ByteRTCSubscribeConfig}.
 * @param streamIndex Mainstream or screen-sharing stream. Refer to  ByteRTCStreamIndex{@link #ByteRTCStreamIndex} for details
 * @note Local users will receive this callback:  <br>
 *        + After calling subscribeStream:mediaStreamType:{@link #ByteRTCRoom#subscribeStream:mediaStreamType:}/unsubscribeStream:mediaStreamType:{@link #ByteRTCRoom#unsubscribeStream:mediaStreamType:} to change the subscription status of remote media streams captured by camera/microphone.  <br>
 *        + After calling subscribeScreen:mediaStreamType:{@link #ByteRTCRoom#subscribeScreen:mediaStreamType:}/unsubscribeScreen:mediaStreamType:{@link #ByteRTCRoom#unsubscribeScreen:mediaStreamType:} to change the subscription status of remote screen sharing streams.
 */
- (void)rtcRoom:(ByteRTCRoom *_Nonnull)rtcRoom onStreamSubscribed:(ByteRTCSubscribeState)state
                userId:(NSString *_Nonnull)userId
                streamIndex:(ByteRTCStreamIndex)streamIndex
       subscribeConfig:(ByteRTCSubscribeConfig *_Nonnull)info;

@end


BYTERTC_APPLE_EXPORT @interface ByteRTCRoomEx : ByteRTCRoom

@property(nonatomic, weak) id<ByteRTCRoomDelegateEx> _Nullable delegateEx;

- (int)publishStream:(ByteRTCStreamIndex)streamIndex mediaStreamType:(ByteRTCMediaStreamType)type;

- (int)unpublishStream:(ByteRTCStreamIndex)streamIndex mediaStreamType:(ByteRTCMediaStreamType)type;

- (int)subscribeStream:(NSString* _Nonnull)userId
            streamIndex:(ByteRTCStreamIndex)streamIndex
        mediaStreamType:(ByteRTCMediaStreamType)mediaStreamType;

- (int)unsubscribeStream:(NSString* _Nonnull)userId
             streamIndex:(ByteRTCStreamIndex)streamIndex
         mediaStreamType:(ByteRTCMediaStreamType)mediaStreamType;

- (int)setRTCRoomDelegateEx:(id<ByteRTCRoomDelegateEx> _Nullable)roomDelegate;



- (int)setRemoteVideoConfig:(NSString * _Nonnull) userId streamIndex:(ByteRTCStreamIndex)streamIndex remoteVideoConfig:(ByteRTCRemoteVideoConfig *_Nonnull) remoteVideoConfig;

@end
