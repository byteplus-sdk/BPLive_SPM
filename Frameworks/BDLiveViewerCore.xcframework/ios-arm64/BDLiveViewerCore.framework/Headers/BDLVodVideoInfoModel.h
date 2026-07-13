//
//  BDLVodVideoInfoModel.h
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
#import "BDLVideoInfoModel.h"

@interface BDLVodVideoInfoModel : BDLBaseModel

@property (nonatomic, assign) NSInteger status;
@property (nonatomic, copy) NSString *message;
@property (nonatomic, copy) NSString *mediaType;
@property (nonatomic, copy) NSString *posterUrl;
@property (nonatomic, strong) BDLVideoInfoModel *originalVideoInfo;
@property (nonatomic, copy) NSArray<BDLVideoInfoModel *> *videoInfos;

/// an array of numbers(BDLVideoResolution)
@property (nonatomic, copy) NSArray<NSNumber *> *bdlSupportedVideoResolutions;
@property (nonatomic, copy) NSString *bdlVideoId;

- (void)keepSupportedVideoInfos;
- (BOOL)isValid;

- (BDLVideoResolution)bestVideoResolution;
- (BDLVideoInfoModel *)videoInfoModelWithVideoResolution:(BDLVideoResolution)videoResolution;
- (NSString *)videoUrlWithVideoResolution:(BDLVideoResolution)videoResolution;
- (NSString *)videoKeyWithVideoResolution:(BDLVideoResolution)videoResolution;

@end
