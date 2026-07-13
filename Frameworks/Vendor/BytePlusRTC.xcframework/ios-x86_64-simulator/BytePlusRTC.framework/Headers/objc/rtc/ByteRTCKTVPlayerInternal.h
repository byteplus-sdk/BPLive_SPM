/*
 * Copyright (c) 2022 The BytePlusRTC project authors. All Rights Reserved.
 * @brief ByteRTCKTVPlayer
*/

@interface ByteRTCKTVPlayer ()

- (instancetype)initWithKTVPlayer:(bytertc::IKTVPlayer *)ktvPlayer;

- (void)destroyResourceInternal;

@end
