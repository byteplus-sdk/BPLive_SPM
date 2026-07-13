/*
 * Copyright (c) 2023 The BytePlusRTC project authors. All Rights Reserved.
 * @brief BytePlusRTC Internal
*/

#import "../ByteRTCVideo.h"

@protocol ByteRTCVideoP2PEventDelegate <NSObject>

@optional
- (void) onP2PConnectionStatusUpdated:(int)state;
- (void) onP2PSignalingStatusUpdated:(int)state;

@end

@interface ByteRTCVideo(ByteRTCVideoP2PEventDelegate)

- (void)setP2PEventDelegate:(id<ByteRTCVideoP2PEventDelegate>_Nullable)delegate;

- (int)enableP2P:(NSString *_Nonnull)roomId onlyLan:(bool)onlyLan;

@end
