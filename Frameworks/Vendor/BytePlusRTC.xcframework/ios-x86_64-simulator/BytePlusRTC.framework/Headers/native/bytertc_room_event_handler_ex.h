/*
 * Copyright (c) 2020 The BytePlusRTC project authors. All Rights Reserved.
 * @brief BytePlusRTC Event Handler Lite
*/

#pragma once

#include "rtc/bytertc_defines.h"
#include "rtc/bytertc_video_defines_ex.h"
#include "bytertc_room_event_handler.h"

namespace bytertc {

class IRTCRoomEventHandlerEx {
public:
    
    virtual ~IRTCRoomEventHandlerEx() {}
    
    virtual void onUserPublishStream(const RemoteStreamKey& stream_key, bool is_screen, MediaStreamType type) {
    }
    
    virtual void onUserUnpublishStream(
            const RemoteStreamKey& stream_key, MediaStreamType type, StreamRemoveReason reason) {
    }

    
    virtual void onStreamStateChanged(
            const StreamKey& stream_key, int state, const char* extra_info) {
    }

    
    /**
     * 
     * @type callback
     * @region Room management
     * @brief Callback on subscription status of media streams
     * @param state_code Subscription status of media streams, see SubscribeState{@link #SubscribeState}.
     * @param user_id The ID of the user who published the stream.
     * @param info Configurations of stream subscription, see SubscribeConfig{@link #SubscribeConfig}.
     * @note  
     *        Local users will receive this callback:  <br>
     *        + After calling subscribeStream{@link #IRTCRoom#subscribeStream}/unsubscribeStream{@link #IRTCRoom#unsubscribeStream} to change the subscription status of remote media streams captured by camera/microphone.  <br>
     *        + After calling subscribeScreen{@link #IRTCRoom#subscribeScreen}/unsubscribeScreen{@link #IRTCRoom#unsubscribeScreen} to change the subscription status of remote screen sharing streams.
     */
    virtual void onStreamSubscribed(SubscribeState state_code, const char* user_id,
                            const StreamIndex stream_index,
                            const SubscribeConfig& info) {
    
    }

    virtual void onAVSyncEvent(const StreamKey& stream_key, AVSyncEvent event) {
    }
}; /* class IRTCRoomEventHandlerEx */

} /* namespace bytertc */