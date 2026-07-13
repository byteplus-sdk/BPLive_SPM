/*
 * Copyright (c) 2020 The BytePlusRTC project authors. All Rights Reserved.
 * @brief BytePlusRTC Internal API
*/

#pragma once

#include "bytertc_defines.h"
#include <stdint.h>
#include <stdarg.h>

namespace bytertc {

/** 
 * @brief Customize user roles
 * @notes You should call this method before entering the room.
 */
BYTERTC_API void setCustomUserRole(void* engine, const char* role);

/** 
 * @brief Set ByteRTC SDK to use QUIC to get configuration by default
 * @notes Generally used in the SDK for Linux
 */
BYTERTC_API void setDefaultEnableQuicGetAccess();

/** 
 * @brief Set ByteRTC SDK to use KCP to get configuration by default
 * @notes Generally used in the SDK for Linux
 */
BYTERTC_API void setDefaultEnableKcpGetAccess();

/** 
 * @brief Set ByteRTC SDK to enable pre-call network detection by default
 * @notes Generally used in the SDK for Linux
 */
BYTERTC_API void setDefaultEnableNetworkDetect();

/** 
 * @brief Set ByteRTC SDK to use KCP message channel by default
 * @notes Generally used in the SDK for Linux
 */
BYTERTC_API void setDefaultEnableKcpDataChannel();

struct VideoStreamDescription {
    unsigned int width;
    unsigned int height;
    unsigned int frame_rate;
    unsigned int max_kbps;
};

enum class PixelFormat {
      kDefault = 0,
      kI420 = 1,
      kRGBA = 2,
      kTexture = 3,
};

enum class NetworkFamily {
    kNetworkFamilyNone = 0,
    kNetworkFamilyIPv4 = 1,
    kNetworkFamilyIPv6 = 2,
    kNetworkFamilyBoth = 3,
};

enum StreamFlag {
    kStreamFlagNone = 0,
    kStreamFlagNormal = 1 << 0,
    kStreamFlagDocShare = 1 << 1,
    kStreamFlagMCU = 1 << 2,
    kStreamFlagMeetTogether = 1 << 3,
    
    kStreamFlagMultiStream = 1 << 6,
};

}  

