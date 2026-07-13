/*
 * Copyright (c) 2020 The BytePlusRTC project authors. All Rights Reserved.
 * @brief BytePlusRTC Room Internal API
*/

@interface RTSRoom ()

- (instancetype _Nonnull)initWithRtsRoom:(bytertc::IRTSRoom *_Nonnull)rtsRoom roomId:(NSString *_Nonnull)roomId;

@end
