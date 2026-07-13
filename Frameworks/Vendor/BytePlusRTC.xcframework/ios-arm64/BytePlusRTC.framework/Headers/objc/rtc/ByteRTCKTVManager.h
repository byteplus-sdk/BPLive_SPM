/*
 * Copyright (c) 2022 The BytePlusRTC project authors. All Rights Reserved.
 * @brief ByteRTCKTVManager
*/

#import <Foundation/Foundation.h>
#import "ByteRTCKTVDefines.h"
@class ByteRTCKTVManager;
@class ByteRTCKTVPlayer;

NS_ASSUME_NONNULL_BEGIN


/**
 * 
 * @hidden currently not available
 * @type callback
 * @brief KTV manager event handler. <br>
 * Note: Callback functions are thrown synchronously in a non-UI thread within the SDK. Therefore, you must not perform any time-consuming operations or direct UI operations within the callback function, as this may cause the app to crash.
 */
@protocol ByteRTCKTVManagerDelegate <NSObject>
@optional


/**
 * 
 * @type callback
 * @brief The music list callback.
 * @param musics Array of the music information. See ByteRTCMusicInfo{@link #ByteRTCMusicInfo}.
 * @param totalSize The total size of the music list.
 * @param errorCode Error code. The value 0 indicates success. For the indications of other values, see ByteRTCKTVErrorCode{@link #ByteRTCKTVErrorCode}.
 */
- (void)ktvManager:(ByteRTCKTVManager *)ktvManager onMusicListResult:(NSArray<ByteRTCMusicInfo *> * _Nullable)musics totalSize:(int)totalSize errorCode:(ByteRTCKTVErrorCode)errorCode;


/**
 * 
 * @type callback
 * @brief The search music callback.
 * @param musics Array of the music information. See ByteRTCMusicInfo{@link #ByteRTCMusicInfo}.
 * @param totalSize The total size of the music list.
 * @param errorCode Error code. The value 0 indicates success. For the indications of other values, see ByteRTCKTVErrorCode{@link #ByteRTCKTVErrorCode}.
 */
- (void)ktvManager:(ByteRTCKTVManager *)ktvManager onSearchMusicResult:(NSArray<ByteRTCMusicInfo *> * _Nullable)musics totalSize:(int)totalSize errorCode:(ByteRTCKTVErrorCode)errorCode;


/**
 * 
 * @type callback
 * @brief The hot music callback.
 * @param hotMusicInfos Array of the hot music information. See ByteRTCHotMusicInfo{@link #ByteRTCHotMusicInfo}.
 * @param errorCode Error code. The value 0 indicates success. For the indications of other values, see ByteRTCKTVErrorCode{@link #ByteRTCKTVErrorCode}.
 */
- (void)ktvManager:(ByteRTCKTVManager *)ktvManager onHotMusicResult:(NSArray<ByteRTCHotMusicInfo *> * _Nullable)hotMusicInfos errorCode:(ByteRTCKTVErrorCode)errorCode;


/**
 * 
 * @type callback
 * @brief The music detail callback.
 * @param music Music information. See ByteRTCMusicInfo{@link #ByteRTCMusicInfo}.
 * @param errorCode Error code. The value 0 indicates success. For the indications of other values, see ByteRTCKTVErrorCode{@link #ByteRTCKTVErrorCode}.
 */
- (void)ktvManager:(ByteRTCKTVManager *)ktvManager onMusicDetailResult:(ByteRTCMusicInfo * _Nullable)music errorCode:(ByteRTCKTVErrorCode)errorCode;


/**
 * 
 * @type callback
 * @brief Download success callback.
 * @param downloadId Download task ID.
 * @param result Download result. See ByteRTCDownloadResult{@link #ByteRTCDownloadResult}.
 */
- (void)ktvManager:(ByteRTCKTVManager *)ktvManager onDownloadSuccess:(int)downloadId downloadResult:(ByteRTCDownloadResult *)result;


/**
 * 
 * @type callback
 * @brief Download failure callback.
 * @param downloadId Download task ID.
 * @param errorCode Error code. See ByteRTCKTVErrorCode{@link #ByteRTCKTVErrorCode}.
 */
- (void)ktvManager:(ByteRTCKTVManager *)ktvManager onDownloadFailed:(int)downloadId errorCode:(ByteRTCKTVErrorCode)errorCode;


/**
 * 
 * @type callback
 * @brief Music file download progress callback.
 * @param downloadId Download task ID.
 * @param downloadPercentage The percentage of download progress, in the range of [0,100].
 */
- (void)ktvManager:(ByteRTCKTVManager *)ktvManager onDownloadMusicProgress:(int)downloadId progress:(int)downloadPercentage;


/**
 * 
 * @type callback
 * @brief Clear Cache result callback.
 * @param errorCode  Error code. See ByteRTCKTVErrorCode{@link #ByteRTCKTVErrorCode}.
 */
- (void)ktvManager:(ByteRTCKTVManager *)ktvManager onClearCacheResult:(ByteRTCKTVErrorCode)errorCode;
@end


/**
 * 
 * @hidden currently not available
 * @type api
 * @brief KTV manager interfaces.
 */
BYTERTC_APPLE_EXPORT @interface ByteRTCKTVManager : NSObject

@property(nonatomic, weak) id<ByteRTCKTVManagerDelegate> delegate;

#pragma mark - Core Methods


/**
 * 
 * @type api
 * @brief Gets the music list.
 * @param pageNumber Page number. The default value is 1.
 * @param pageSize The number of the music that displays on one page.
 * @param filterType The filter type of the music list. See ByteRTCMusicFilterType{@link #ByteRTCMusicFilterType}. Multiple filters can be combined by the bitwise-or operator.
 * @note After calling this API, you will receive the music list through ktvManager:onMusicListResult:totalSize:errorCode:{@link #ByteRTCKTVManagerDelegate#ktvManager:onMusicListResult:totalSize:errorCode:} callback.
 */
- (void)getMusicList:(int)pageNumber pageSize:(int)pageSize filterType:(ByteRTCMusicFilterType)filterType;


/**
 * 
 * @type api
 * @brief Search music by keywords.
 * @param keyWord Keyword. The string should be no more than 20 characters.
 * @param pageNumber Page number. The default value is 1.
 * @param pageSize The number of the music that displays on one page.
 * @param filterType The filter type of the music list. See ByteRTCMusicFilterType{@link #ByteRTCMusicFilterType}. Multiple filters can be combined by the bitwise-or operator.
 * @note After calling this API, you will receive the music list through ktvManager:onSearchMusicResult:totalSize:errorCode:{@link #ByteRTCKTVManagerDelegate#ktvManager:onSearchMusicResult:totalSize:errorCode:} callback.
 */
- (void)searchMusic:(NSString * _Nonnull)keyWord pageNumber:(int)pageNumber pageSize:(int)pageSize filterType:(ByteRTCMusicFilterType)filterType;


/**
 * 
 * @type api
 * @brief Gets hot music according to music types.
 * @param hotType Hot music type. See ByteRTCMusicHotType{@link #ByteRTCMusicHotType}. Multiple hot music types can be combined by the bitwise-or operator.
 * @param filterType The filter type of the music list. See ByteRTCMusicFilterType{@link #ByteRTCMusicFilterType}. Multiple filters can be combined by the bitwise-or operator.
 * @note After calling this API, you will receive the music list through ktvManager:onHotMusicResult:errorCode:{@link #ByteRTCKTVManagerDelegate#ktvManager:onHotMusicResult:errorCode:} callback.
 */
- (void)getHotMusic:(ByteRTCMusicHotType)hotType filterType:(ByteRTCMusicFilterType)filterType;


/**
 * 
 * @type api
 * @brief Gets music detail.
 * @param musicId Music ID.
 * @note After calling this API, you will receive the music detail through ktvManager:onMusicDetailResult:errorCode:{@link #ByteRTCKTVManagerDelegate#ktvManager:onMusicDetailResult:errorCode:} callback.
 */
- (void)getMusicDetail:(NSString * _Nonnull)musicId;


/**
 * 
 * @type api
 * @brief Download music.
 * @param musicId Music ID.
 * @return Download task ID.
 * @note
 *       - If the music is successfully downloaded, you will receive ktvManager:onDownloadSuccess:downloadResult:{@link #ByteRTCKTVManagerDelegate#ktvManager:onDownloadSuccess:downloadResult:}.
 *       - If the music fails to download, you will receive ktvManager:onDownloadFailed:errorCode:{@link #ByteRTCKTVManagerDelegate#ktvManager:onDownloadFailed:errorCode:}.
 *       - When the music download progress is updated, you will receive ktvManager:onDownloadMusicProgress:progress:{@link #ByteRTCKTVManagerDelegate#ktvManager:onDownloadMusicProgress:progress:}.
 */
- (int)downloadMusic:(NSString * _Nonnull)musicId;


/**
 * 
 * @type api
 * @brief Download lyrics.
 * @param musicId Music ID.
 * @param lyricType The lyrics file's format. See ByteRTCDownloadLyricType{@link #ByteRTCDownloadLyricType}.
 * @return Download task ID.
 * @note
 *       - If the lyrics are successfully downloaded, you will receive ktvManager:onDownloadSuccess:downloadResult:{@link #ByteRTCKTVManagerDelegate#ktvManager:onDownloadSuccess:downloadResult:}.
 *       - If the lyrics fail to download, you will receive ktvManager:onDownloadFailed:errorCode:{@link #ByteRTCKTVManagerDelegate#ktvManager:onDownloadFailed:errorCode:}.
 */
- (int)downloadLyric:(NSString * _Nonnull)musicId lyricType:(ByteRTCDownloadLyricType)lyricType;


/**
 * 
 * @type api
 * @brief Download MIDI files.
 * @param musicId Music ID.
 * @return Download task ID.
 * @note
 *       - If the file is successfully downloaded, you will receive ktvManager:onDownloadSuccess:downloadResult:{@link #ByteRTCKTVManagerDelegate#ktvManager:onDownloadSuccess:downloadResult:}.
 *       - If the file fails to download, you will receive ktvManager:onDownloadFailed:errorCode:{@link #ByteRTCKTVManagerDelegate#ktvManager:onDownloadFailed:errorCode:}.
 */
- (int)downloadMidi:(NSString * _Nonnull)musicId;


/**
 * 
 * @type api
 * @brief Cancels download task.
 * @param downloadId Download task ID.
 */
- (void)cancelDownload:(int)downloadId;


/**
 * 
 * @type api
 * @brief Clear music cache, including music and lyrics.
 */
- (void)clearCache;


/**
 * 
 * @type api
 * @brief Sets the maximum cache for storing music files.
 * @param maxCacheSizeMB The maximum cache to be set in MB. <br>
 *        If the setting value is less than or equal to 0, it will be adjusted to 1,024 MB.
 */
- (void)setMaxCacheSize:(int)maxCacheSizeMB;


/**
 * 
 * @type api
 * @brief Gets the KTV player.
 * @return KTV player interfaces. See ByteRTCKTVPlayer{@link #ByteRTCKTVPlayer}.
 */
- (ByteRTCKTVPlayer * _Nullable)getKTVPlayer;


@end

NS_ASSUME_NONNULL_END