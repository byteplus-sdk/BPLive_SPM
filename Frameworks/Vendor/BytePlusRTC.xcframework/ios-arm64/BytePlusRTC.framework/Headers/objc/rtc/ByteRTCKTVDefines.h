/*
 * Copyright (c) 2022 The BytePlusRTC project authors. All Rights Reserved.
 * @brief ByteRTCRtsDefines
*/

#import "ByteRTCRtsDefines.h"


/**
 * 
 * @hidden currently not available
 * @type keytype
 * @brief The filter type of the music list.
 */
typedef NS_OPTIONS(NSUInteger, ByteRTCMusicFilterType) {
    
    /**
     * 
     * @brief No filter.
     */
    ByteRTCMusicFilterTypeNone                 = 0,
    
    /**
     * 
     * @brief Remove music that does not have lyrics.
     */
    ByteRTCMusicFilterTypeWithoutLyric         = 1 << 0,
    
    /**
     * 
     * @brief Remove music that does not support scoring.
     */
    ByteRTCMusicFilterTypeUnsupportedScore     = 1 << 1,
    
    /**
     * 
     * @brief Remove music that does not support accompany mode.
     */
    ByteRTCMusicFilterTypeUnsupportedAccopmay  = 1 << 2,
    
    /**
     * 
     * @brief Remove music that does not have a climax part.
     */
    ByteRTCMusicFilterTypeUnsupportedClimx     = 1 << 3,
};


/**
 * 
 * @hidden currently not available
 * @type keytype
 * @brief Hot music type.
 */
typedef NS_OPTIONS(NSUInteger, ByteRTCMusicHotType) {
    
    /**
     * 
     * @brief Hot music in the content center.
     */
    ByteRTCMusicHotTypeContentCenter   = 1 << 0,
    
    /**
     * 
     * @brief Hot music of the project.
     */
    ByteRTCMusicHotTypeProject         = 1 << 1,
    
};


/**
 * 
 * @hidden currently not available
 * @type keytype
 * @brief Music playing status.
 */
typedef NS_ENUM(NSInteger, ByteRTCPlayState) {
    
    /**
     * 
     * @brief Playing.
     */
    ByteRTCPlayStatePlaying    = 1,
    
    /**
     * 
     * @brief Paused.
     */
    ByteRTCPlayStatePaused     = 2,
    
    /**
     * 
     * @brief Stopped.
     */
    ByteRTCPlayStateStoped     = 3,
    
    /**
     * 
     * @brief Failed to play.
     */
    ByteRTCPlayStateFailed     = 4,
    
    /**
     * 
     * @brief Finished.
     */
    ByteRTCPlayStateFinished   = 5,
};


/**
 * 
 * @hidden currently not available
 * @type keytype
 * @brief Audio track type of the KTV player.
 */
typedef NS_ENUM(NSInteger, ByteRTCAudioTrackType) {
    
    /**
     * 
     * @brief Play the original music with vocals.
     */
    ByteRTCAudioTrackTypeOriginal    = 1,
    
    /**
     * 
     * @brief Play the instrumental music without vocals.
     */
    ByteRTCAudioTrackTypeAccompy     = 2,
};


/**
 * 
 * @hidden currently not available
 * @type keytype
 * @brief Audio play type.
 */
typedef NS_ENUM(NSInteger, ByteRTCAudioPlayType) {
    
    /**
     * 
     * @brief Only play on the local side.
     */
    ByteRTCAudioPlayTypeLocal            = 0,
    
    /**
     * 
     * @brief Only play on the remote side.
     */
    ByteRTCAudioPlayTypeRemote           = 1,
    
    /**
     * 
     * @brief Play on the local and remote side.
     */
    ByteRTCAudioPlayTypeLocalAndRemote   = 2,
};


/**
 * 
 * @hidden currently not available
 * @type keytype
 * @brief The lyrics type.
 */
typedef NS_ENUM(NSInteger, ByteRTCLyricStatus) {
    
    /**
     * 
     * @brief No lyrics.
     */
    ByteRTCLyricStatusNone         = 0,
    
    /**
     * 
     * @brief KRC lyrics.
     */
    ByteRTCLyricStatusKRC          = 1,
    
    /**
     * 
     * @brief LRC lyrics.
     */
    ByteRTCLyricStatusLRC          = 2,
    
    /**
     * 
     * @brief KRC and LRC lyrics.
     */
    ByteRTCLyricStatusKRCAndLRC    = 3,
};


/**
 * 
 * @hidden currently not available
 * @type keytype
 * @brief Download file type.
 */
typedef NS_ENUM(NSInteger, ByteRTCDownloadFileType) {
    
    /**
     * 
     * @brief Audio file.
     */
    ByteRTCDownloadFileTypeMusic     = 1,
    
    /**
     * 
     * @brief KRC lyrics file.
     */
    ByteRTCDownloadFileTypeKRC       = 2,
    
    /**
     * 
     * @brief LRC lyrics file.
     */
    ByteRTCDownloadFileTypeLRC       = 3,
    
    /**
     * 
     * @brief MIDI file.
     */
    ByteRTCDownloadFileTypeMIDI      = 4,
};


/**
 * 
 * @hidden currently not available
 * @type keytype
 * @brief The lyrics file's format.
 */
typedef NS_ENUM(NSInteger, ByteRTCDownloadLyricType) {
    
    /**
     * 
     * @brief KRC lyrics file.
     */
    ByteRTCDownloadLyricTypeKRC = 0,
    
    /**
     * 
     * @brief LRC lyrics file.
     */
    ByteRTCDownloadLyricTypeLRC = 1,
};


/**
 * 
 * @hidden currently not available
 * @type errorcode
 * @brief KTV error code.
 */
typedef NS_ENUM(NSInteger, ByteRTCKTVErrorCode) {
    
    /**
     * 
     * @brief Success.
     */
    ByteRTCKTVErrorCodeOK = 0,
    
    /**
     * 
     * @brief Invalid AppID.
     */
    ByteRTCKTVErrorCodeAppidInValid = -3000,
    
    /**
     * 
     * @brief Invalid parameter.
     */
    ByteRTCKTVErrorCodeParasInValid = -3001,
    
    /**
     * 
     * @brief Failed to get music resources.
     */
    ByteRTCKTVErrorCodeGetMusicFailed = -3002,
    
    /**
     * 
     * @brief Failed to get lyrics.
     */
    ByteRTCKTVErrorCodeGetLyricFailed = -3003,
    
    /**
     * 
     * @brief The music is removed.
     */
    ByteRTCKTVErrorCodeMusicTakedown = -3004,
    
    /**
     * 
     * @brief Failed to download the music file.
     */
    ByteRTCKTVErrorCodeMusicDownload = -3005,
    
    /**
     * 
     * @brief Failed to download the MIDI file.
     */
    ByteRTCKTVErrorCodeMidiDownloadFailed = -3006,
    
    /**
     * 
     * @brief The system is busy.
     */
    ByteRTCKTVErrorCodeSystemBusy = -3007,
    
    /**
     * 
     * @brief Network anomaly.
     */
    ByteRTCKTVErrorCodeNetwork = -3008,
    
    /**
     * 
     * @brief The KTV feature is not added to the room.
     */
    ByteRTCKTVErrorCodeNotJoinRoom = -3009,
    
    /**
     * 
     * @brief Failed to parse data.
     */
    ByteRTCKTVErrorCodeParseData = -3010,
    
    /**
     * 
     * @hidden
     * @deprecated since 353.
     * @brief Failed to download.
     */
    ByteRTCKTVErrorCodeDownload = -3011,
    
    /**
     * 
     * @brief Already downloading.
     */
    ByteRTCKTVErrorCodeDownloading = -3012,
    
    /**
     * 
     * @brief Internal error. Contact the technical support representatives for help.
     */
    ByteRTCKTVErrorCodeInternal = -3013,
    
    /**
     * 
     * @brief Failed to download because of insufficient disk space. Please retry after clearing cache.
     */
    ByteRTCKTVErrorCodeInsufficientDiskSpace = -3014,
    
    /**
     * 
     * @brief Failed to download because of music decryption failed. Contact the technical support representatives for help.
     */
    ByteRTCKTVErrorCodeMusicDecryptionFailed = -3015,
    
    /**
     * 
     * @brief Failed to download because of music rename failed. Please retry.
     */
    ByteRTCKTVErrorCodeFileRenameFailed = -3016,
    
    /**
     * 
     * @brief Failed to download because of network failure. Please retry.
     */
    ByteRTCKTVErrorCodeDownloadTimeOut = -3017,
    
    /**
     * 
     * @brief Failed to clear cache because the file is occupied or the system is abnormal. Please retry.
     */
    ByteRTCKTVErrorCodeClearCacheFailed = -3018,
    
    /**
     * 
     * @brief Cancel download task.
     */
    ByteRTCKTVErrorCodeDownloadCanceled = -3019
};


/**
 * 
 * @hidden currently not available
 * @type keytype
 * @brief KTV player error code.
 */
typedef NS_ENUM(NSInteger, ByteRTCKTVPlayerErrorCode) {
    
    /**
     * 
     * @brief Success.
     */
    ByteRTCKTVPlayerErrorCodeOK = 0,
    
    /**
     * 
     * @brief Failed to play the music. Download first.
     */
    ByteRTCKTVPlayerErrorCodeFileNotExist = -3020,
    
    /**
     * 
     * @brief Failed to play the music. Check the file's format.
     */
    ByteRTCKTVPlayerErrorCodeFileError = -3021,
    
    /**
     * 
     * @brief Failed to play the music. Join a room first.
     */
    ByteRTCKTVPlayerErrorCodeNotJoinRoom = -3022,
    
    /**
     * 
     * @brief Invalid parameter.
     */
    ByteRTCKTVPlayerErrorCodeParam = -3023,
    
    /**
     * 
     * @brief Failed to play the music. Invalid path or failed to open the file.
     */
    ByteRTCKTVPlayerErrorCodeStartError = -3024,
    
    /**
     * 
     * @brief Invalid mixing ID.
     */
    ByteRTCKTVPlayerErrorCodeMixIdError = -3025,
    
    /**
     * 
     * @brief Invalid position.
     */
    ByteRTCKTVPlayerErrorCodePositionError = -3026,
    
    /**
     * 
     * @brief Invalid volume.
     */
    ByteRTCKTVPlayerErrorCodeAudioVolumeError = -3027,
    
    /**
     * 
     * @brief Do not support the mix type.
     */
    ByteRTCKTVPlayerErrorCodeTypeError = -3028,
    
    /**
     * 
     * @brief Invalid pitch.
     */
    ByteRTCKTVPlayerErrorCodePitchError = -3029,
    
    /**
     * 
     * @brief Invalid audio track.
     */
    ByteRTCKTVPlayerErrorCodeAudioTrackError = -3030,
    
    /**
     * 
     * @brief Mixing in process.
     */
    ByteRTCKTVPlayerErrorCodeStartingError = -3031,
};


/**
 * 
 * @hidden currently not available
 * @type keytype
 * @brief Music information.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCMusicInfo : NSObject

/**
 * 
 * @brief Music ID.
 */
@property (nonatomic, copy) NSString * _Nonnull musicId;

/**
 * 
 * @brief Music name.
 */
@property (nonatomic, copy) NSString * _Nonnull musicName;

/**
 * 
 * @brief Singer.
 */
@property (nonatomic, copy) NSString * _Nonnull singer;

/**
 * 
 * @brief Vendor ID.
 */
@property (nonatomic, copy) NSString * _Nonnull vendorId;

/**
 * 
 * @brief Vendor name.
 */
@property (nonatomic, copy) NSString * _Nonnull vendorName;

/**
 * 
 * @brief Latest update timestamp in milliseconds.
 */
@property (nonatomic, assign) int64_t updateTimestamp;

/**
 * 
 * @brief The URL of the music cover.
 */
@property (nonatomic, copy) NSString * _Nonnull posterUrl;

/**
 * 
 * @brief The lyrics type. See ByteRTCLyricStatus{@link #ByteRTCLyricStatus}.
 */
@property (nonatomic, assign) ByteRTCLyricStatus lyricStatus;

/**
 * 
 * @brief The length of the song in milliseconds.
 */
@property (nonatomic, assign) int duration;

/**
 * 
 * @brief Whether the song supports scoring.
 */
@property (nonatomic, assign) BOOL enableScore;

/**
 * 
 * @brief The starting time of the climax part in milliseconds.
 */
@property (nonatomic, assign) int climaxStartTime;

/**
 * 
 * @brief The ending time of the climax part in milliseconds.
 */
@property (nonatomic, assign) int climaxEndTime;
@end


/**
 * 
 * @hidden currently not available
 * @type keytype
 * @brief Hot music information.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCHotMusicInfo : NSObject

/**
 * 
 * @brief Hot music type. See ByteRTCMusicHotType{@link #ByteRTCMusicHotType}.
 */
@property (nonatomic, assign) ByteRTCMusicHotType hotType;

/**
 * 
 * @brief Hot list name.
 */
@property (nonatomic, copy) NSString * _Nullable hotName;

/**
 * 
 * @brief Music information. See ByteRTCMusicInfo{@link #ByteRTCMusicInfo}.
 */
@property (nonatomic, copy) NSArray<ByteRTCMusicInfo *> * _Nullable musics;
@end


/**
 * 
 * @hidden currently not available
 * @type keytype
 * @brief Download music information.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCDownloadResult : NSObject

/**
 * 
 * @brief Music ID.
 */
@property (nonatomic, copy) NSString * _Nonnull musicId;

/**
 * 
 * @brief Download file type. See ByteRTCDownloadFileType{@link #ByteRTCDownloadFileType}.
 */
@property (nonatomic, assign) ByteRTCDownloadFileType fileType;

/**
 * 
 * @brief Download file path.
 */
@property (nonatomic, copy) NSString * _Nullable filePath;

@end