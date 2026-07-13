#pragma once

#include "bytertc_ktv_defines.h"
namespace bytertc {


/**
 * 
 * @hidden currently not available
 * @type callback
 * @brief KTV manager event handler. <br>
 * Note: Callback functions are thrown synchronously in a non-UI thread within the SDK. Therefore, you must not perform any time-consuming operations or direct UI operations within the callback function, as this may cause the app to crash.
 */
class IKTVManagerEventHandler {

public:
    
    /**
     * 
     * @hidden constructor/destructor
     */
    virtual ~IKTVManagerEventHandler() {
    }

    
    /**
     * 
     * @type callback
     * @brief The music list callback.
     * @param music_infos Array of the music information. See MusicInfo{@link #MusicInfo}.
     * @param music_count The size of the requested music list.
     * @param total_musics_size The total size of the music list.
     * @param error_code Error code. The value 0 indicates success. For the indications of other values, see KTVErrorCode{@link #KTVErrorCode}.
     * @list Online KTV
     * @order 0
     */
    virtual void onMusicListResult(MusicInfo* music_infos, int music_count, int total_musics_size, KTVErrorCode error_code) {
        (void)music_infos;
        (void)music_count;
        (void)total_musics_size;
        (void)error_code;
    }

    
    /**
     * 
     * @type callback
     * @brief The search music callback.
     * @param music_infos Array of the music information. See MusicInfo{@link #MusicInfo}.
     * @param music_count The size of the requested music list.
     * @param total_musics_size The total size of the music list.
     * @param error_code Error code. The value 0 indicates success. For the indications of other values, see KTVErrorCode{@link #KTVErrorCode}.
     * @list Online KTV
     * @order 1
     */
    virtual void onSearchMusicResult(MusicInfo* music_infos, int music_count, int total_musics_size, KTVErrorCode error_code) {
        (void)music_infos;
        (void)music_count;
        (void)total_musics_size;
        (void)error_code;
    }

    
    /**
     * 
     * @type callback
     * @brief The hot music callback.
     * @param hot_infos Array of the hot music information. See HotMusicInfo{@link #HotMusicInfo}.
     * @param hot_count The size of the requested hot music list.
     * @param error_code Error code. The value 0 indicates success. For the indications of other values, see KTVErrorCode{@link #KTVErrorCode}.
     * @list Online KTV
     * @order 2
     */
    virtual void onHotMusicResult(HotMusicInfo* hot_infos, int hot_count, KTVErrorCode error_code) {
        (void)hot_infos;
        (void)hot_count;
        (void)error_code;
    }

    
    /**
     * 
     * @type callback
     * @brief The music detail callback.
     * @param music_info Music information. See MusicInfo{@link #MusicInfo}.
     * @param error_code Error code. The value 0 indicates success. For the indications of other values, see KTVErrorCode{@link #KTVErrorCode}.
     * @list Online KTV
     * @order 3
     */
    virtual void onMusicDetailResult(MusicInfo* music_info, KTVErrorCode error_code) {
        (void)music_info;
        (void)error_code;        
    }

    
    /**
     * 
     * @type callback
     * @brief Download success callback.
     * @param download_id Download task ID.
     * @param download_info Download result. See DownloadResult{@link #DownloadResult}.
     * @list Online KTV
     * @order 4
     */
    virtual void onDownloadSuccess(int download_id, DownloadResult* download_info) {
        (void)download_id;
        (void)download_info; 
    }

    
    /**
     * 
     * @type callback
     * @brief Download failure callback.
     * @param download_id Download task ID.
     * @param error_code Error code. See KTVErrorCode{@link #KTVErrorCode}.
     * @list Online KTV
     * @order 5
     */
    virtual void onDownloadFailed(int download_id, KTVErrorCode error_code) {
        (void)download_id;
        (void)error_code; 
    }

    
    /**
     * 
     * @type callback
     * @brief Music file download progress callback.
     * @param download_id Download task ID.
     * @param download_percentage The percentage of download progress, in the range of [0,100].
     * @list Online KTV
     * @order 6
     */
    virtual void onDownloadMusicProgress(int download_id, int download_percentage) {
        (void)download_id;
        (void)download_percentage;
    }
    
    /**
     * 
     * @type callback
     * @brief Clear Cache result callback.
     * @param error_code Error code. See KTVErrorCode{@link #KTVErrorCode}.
     */
    virtual void onClearCacheResult(KTVErrorCode error_code) {
        (void)error_code;
    }
};


/**
 * 
 * @hidden currently not available
 * @type callback
 * @brief KTV player event handler. <br>
 * Note: Callback functions are thrown synchronously in a non-UI thread within the SDK. Therefore, you must not perform any time-consuming operations or direct UI operations within the callback function, as this may cause the app to crash.
 */
class IKTVPlayerEventHandler {
public:
    
    /**
     * 
     * @hidden constructor/destructor
     */
    virtual ~IKTVPlayerEventHandler() {
    }
    
    
    /**
     * 
     * @type callback
     * @brief Music playing progress callback.
     * @param music_id Music ID.
     * @param progress Music playing progress in milliseconds.
     * @list Online KTV
     * @order 7
     */
    virtual void onPlayProgress(const char *music_id, int64_t progress) {
        (void)music_id;
        (void)progress;
    }
    
    
    /**
     * 
     * @type callback
     * @brief Music playing state changed callback.
     * @param music_id Music ID.
     * @param play_state Music playing status. See PlayState{@link #PlayState}.
     * @param error_code Error code. See KTVPlayerErrorCode{@link #KTVPlayerErrorCode}.
     * @note
     *       You will receive this callback on following events. <br>
     *       - When you successfully start playing music by calling playMusic{@link #IKTVPlayer#playMusic}, you will receive this callback with `PlayStatePlaying` playState. Otherwise the playState will be `PlayStateFailed`.
     *       - If the music with the same music ID is playing when you call playMusic{@link #IKTVPlayer#playMusic} again, the music will restart from the starting position, and you will receive this callback with `PlayStatePlaying` playState to inform the latter music has started.
     *       - When you successfully pause the music by calling pauseMusic{@link #IKTVPlayer#pauseMusic}, you will receive this callback with `PlayStatePaused` playState. Otherwise the playState will be `PlayStateFailed`.
     *       - When you successfully resume the music by calling resumeMusic{@link #IKTVPlayer#resumeMusic}, you will receive this callback with `PlayStatePlaying` playState. Otherwise the playState will be `PlayStateFailed`.
     *       - When you successfully stop the music by calling stopMusic{@link #IKTVPlayer#stopMusic}, you will receive this callback with `PlayStateStoped` playState. Otherwise the playState will be `PlayStateFailed`.
     *       - When the music ends, you will receive this callback with `PlayStateFinished` playState.
     * @list Online KTV
     * @order 8
     */
    virtual void onPlayStateChanged(const char* music_id, PlayState play_state, bytertc::KTVPlayerErrorCode error_code) {
        (void)music_id;
        (void)play_state;
        (void)error_code;
    }
};


/**
 * 
 * @hidden currently not available
 * @type api
 * @brief KTV player interfaces.
 */
class IKTVPlayer {
public:
    
    /**
     * 
     * @hidden constructor/destructor
     */
    virtual ~IKTVPlayer() = default;
    
    
    /**
     * 
     * @type api
     * @brief Sets the KTV player event handler.
     * @param handler KTV player event handler. See IKTVPlayerEventHandler{@link #IKTVPlayerEventHandler}.
     * @list Online KTV
     * @order 13
     */
    virtual void setPlayerEventHandler(IKTVPlayerEventHandler *handler) = 0;

    
    /**
     * 
     * @type api
     * @brief Plays the music.
     * @param music_id Music ID. <br>
     *        If the song with the same music_id is playing when you call this API, the music will restart from the starting position. An error will be triggered if the audio file corresponding to music_id does not exist.
     * @param track_type Audio track type of the KTV player. See AudioTrackType{@link #AudioTrackType}.
     * @param play_type Audio play type. See AudioPlayType{@link #AudioPlayType}.
     * @note
     *       - After calling this API, you will receive the music play state through onPlayStateChanged{@link #IKTVPlayerEventHandler#onPlayStateChanged} callback.
     *       - If the music ID is invalid, you will receive the onPlayStateChanged{@link #IKTVPlayerEventHandler#onPlayStateChanged} callback, with an error_code of -3023 and a play_state of 4.
     *       - If you didn't join the room, you will receive the onPlayStateChanged{@link #IKTVPlayerEventHandler#onPlayStateChanged} callback, with an error_code of -3022 and a play_state of 4.
     *       - If the music file does not exist, you will receive the onPlayStateChanged{@link #IKTVPlayerEventHandler#onPlayStateChanged} callback, with an error_code of -3020 and a play_state of 4.
     * @list Online KTV
     * @order 14
     */
    virtual void playMusic(const char* music_id, AudioTrackType track_type, AudioPlayType play_type) = 0;

    
    /**
     * 
     * @type api
     * @brief Pauses the music.
     * @param music_id Music ID.
     * @note
     *       - After calling this API, you will receive the music play state through onPlayStateChanged{@link #IKTVPlayerEventHandler#onPlayStateChanged} callback.
     *       - If the music ID is invalid, you will receive the onPlayStateChanged{@link #IKTVPlayerEventHandler#onPlayStateChanged} callback, with an error_code of -3023 and a play_state of 4.
     *       - If you didn't join the room, you will receive the onPlayStateChanged{@link #IKTVPlayerEventHandler#onPlayStateChanged} callback, with an error_code of -3022 and a play_state of 4.
     * @list Online KTV
     * @order 15
     */
    virtual void pauseMusic(const char *music_id) = 0;

    
    /**
     * 
     * @type api
     * @brief Resumes playing the music.
     * @param music_id Music ID.
     * @note
     *       - After calling this API, you will receive the music play state through onPlayStateChanged{@link #IKTVPlayerEventHandler#onPlayStateChanged} callback.
     *       - If the music ID is invalid, you will receive the onPlayStateChanged{@link #IKTVPlayerEventHandler#onPlayStateChanged} callback, with an error_code of -3023 and a play_state of 4.
     *       - If you didn't join the room, you will receive the onPlayStateChanged{@link #IKTVPlayerEventHandler#onPlayStateChanged} callback, with an error_code of -3022 and a play_state of 4.
     * @list Online KTV
     * @order 16
     */
    virtual void resumeMusic(const char *music_id) = 0;

    
    /**
     * 
     * @type api
     * @brief Stops playing the music.
     * @param music_id Music ID.
     * @note
     *       - After calling this API, you will receive the music play state through onPlayStateChanged{@link #IKTVPlayerEventHandler#onPlayStateChanged} callback.
     *       - If the music ID is invalid, you will receive the onPlayStateChanged{@link #IKTVPlayerEventHandler#onPlayStateChanged} callback, with an error_code of -3023 and a play_state of 4.
     *       - If you didn't join the room, you will receive the onPlayStateChanged{@link #IKTVPlayerEventHandler#onPlayStateChanged} callback, with an error_code of -3022 and a play_state of 4.
     * @list Online KTV
     * @order 17
     */
    virtual void stopMusic(const char *music_id) = 0;

    
    /**
     * 
     * @type api
     * @brief Sets the starting position of the music file.
     * @param music_id Music ID.
     * @param position The starting position of the music file in milliseconds. The value must be less than the total length of the music.
     * @note
     *       - The music must be playing when you call this API.
     *       - After calling this API, you will receive the music play state through onPlayStateChanged{@link #IKTVPlayerEventHandler#onPlayStateChanged} callback.
     *       - If the music ID is invalid, you will receive the onPlayStateChanged{@link #IKTVPlayerEventHandler#onPlayStateChanged} callback, with an error_code of -3023 and a play_state of 4.
     *       - If you didn't join the room, you will receive the onPlayStateChanged{@link #IKTVPlayerEventHandler#onPlayStateChanged} callback, with an error_code of -3022 and a play_state of 4.
     * @list Online KTV
     * @order 18
     */
    virtual void seekMusic(const char *music_id, int position) = 0;

    
    /**
     * 
     * @type api
     * @brief Sets the volume of the playing music. The music must be playing when you set the volume.
     * @param music_id Music ID.
     * @param volume Volume. Adjustment range: [0,400]. <br>
     *         - 0: Mute.
     *         - 100: Original volume.
     *         - 400: 4 times the original volume (with overflow protection).
     * @note
     *       - The music must be playing when you call this API.
     *       - If the set volume is greater than 400, it will be adjusted by the maximum value of 400; if the set volume is less than 0, it will be adjusted by the minimum value of 0.
     *       - If the music ID is invalid, you will receive the onPlayStateChanged{@link #IKTVPlayerEventHandler#onPlayStateChanged} callback, with an error_code of -3023 and a play_state of 4.
     *       - If you didn't join the room, you will receive the onPlayStateChanged{@link #IKTVPlayerEventHandler#onPlayStateChanged} callback, with an error_code of -3022 and a play_state of 4.
     * @list Online KTV
     * @order 19
     */
    virtual void setMusicVolume(const char *music_id, int volume) = 0;

    
    /**
     * 
     * @type api
     * @brief Switches the audio track type between the original track and the instrumental track.
     * @param music_id Music ID.
     * @note The music must be playing when you call this API.
     * @list Online KTV
     * @order 20
     */
    virtual void switchAudioTrackType(const char *music_id) = 0;

    
    /**
     * 
     * @type api
     * @brief Transposes up/down the music being played.
     * @param music_id Music ID.
     * @param pitch The pitch up/down value relative to the original pitch, in the range of [-12, 12], with the default value of 0. <br>
     *              The difference in pitch between two adjacent values is a semitone. A positive value indicates an increase in pitch, and a negative value indicates a decrease in pitch. A larger absolute value means more pitch increase or decrease.
     * @note
     *       - The music must be in the playing when you call this API.
     *       - If the set pitch is greater than 12, it will be adjusted by the maximum value of 12; if the set pitch is less than –12, it will be adjusted by the minimum value of –12.
     *       - If the music ID is invalid, you will receive the onPlayStateChanged{@link #IKTVPlayerEventHandler#onPlayStateChanged} callback, with an error_code of -3023 and a play_state of 4.
     *       - If you didn't join the room, you will receive the onPlayStateChanged{@link #IKTVPlayerEventHandler#onPlayStateChanged} callback, with an error_code of -3022 and a play_state of 4.
     * @list Online KTV
     * @order 21
     */
    virtual void setMusicPitch(const char* music_id, int pitch) = 0;

};


/**
 * 
 * @hidden currently not available
 * @type api
 * @brief KTV manager interfaces.
 */
class IKTVManager {
public:
    
    /**
     * 
     * @hidden constructor/destructor
     */
    virtual ~IKTVManager() = default;
    
    
    /**
     * 
     * @type api
     * @brief Sets the maximum cache for storing music files.
     * @param max_cache_size_mb The maximum cache to be set in MB. <br>
     *        If the setting value is less than or equal to 0, it will be adjusted to 1,024 MB.
     * @list Online KTV
     * @order 1
     */
    virtual void setMaxCacheSize(int max_cache_size_mb) = 0;

    
    /**
     * 
     * @type api
     * @brief Sets the KTV event handler.
     * @param ktv_manager_event_handler KTV event handler. See IKTVManagerEventHandler{@link #IKTVManagerEventHandler}.
     * @list Online KTV
     * @order 2
     */
    virtual void setKTVManagerEventHandler(IKTVManagerEventHandler *ktv_manager_event_handler) = 0;

    
    /**
     * 
     * @type api
     * @brief Gets the music list.
     * @param page_num Page number. The default value is 1.
     * @param page_size The number of the music that displays on one page.
     * @param filters The filter type of the music list. See MusicFilterType{@link #MusicFilterType}.
     * @note After calling this API, you will receive the music list through onMusicListResult{@link #IKTVManagerEventHandler#onMusicListResult} callback.
     * @list Online KTV
     * @order 3
     */
    virtual void getMusicList(int page_num, int page_size,  int filters) = 0;

    
    /**
     * 
     * @type api
     * @brief Search music by keywords.
     * @param key_word Keyword. The string should be no more than 20 characters.
     * @param page_num Page number. The default value is 1.
     * @param page_size The number of the music that displays on one page.
     * @param filters The filter type of the music list. See MusicFilterType{@link #MusicFilterType}.
     * @note After calling this API, you will receive the music list through onSearchMusicResult{@link #IKTVManagerEventHandler#onSearchMusicResult} callback.
     * @list Online KTV
     * @order 4
     */
    virtual void searchMusic(const char* key_word, int page_num, int page_size, int filters) = 0;

    
    /**
     * 
     * @type api
     * @brief Gets hot music according to music types.
     * @param hot_types Hot music type. See MusicHotType{@link #MusicHotType}.
     * @param filters The filter type of the music list. See MusicFilterType{@link #MusicFilterType}.
     * @note After calling this API, you will receive the music list through onHotMusicResult{@link #IKTVManagerEventHandler#onHotMusicResult} callback.
     * @list Online KTV
     * @order 5
     */
    virtual void getHotMusic(int hot_types, int filters) = 0;


    
    /**
     * 
     * @type api
     * @brief Gets music detail.
     * @param music_id Music ID.
     * @note After calling this API, you will receive the music detail through onMusicDetailResult{@link #IKTVManagerEventHandler#onMusicDetailResult} callback.
     * @list Online KTV
     * @order 6
     */
    virtual void getMusicDetail(const char* music_id) = 0;

    
    /**
     * 
     * @type api
     * @brief Download music.
     * @param music_id Music ID.
     * @return Download task ID.
     * @note
     *       - If the music is successfully downloaded, you will receive onDownloadSuccess{@link #IKTVManagerEventHandler#onDownloadSuccess}.
     *       - If the music fails to download, you will receive onDownloadFailed{@link #IKTVManagerEventHandler#onDownloadFailed}.
     *       - When the music download progress is updated, you will receive onDownloadMusicProgress{@link #IKTVManagerEventHandler#onDownloadMusicProgress}.
     * @list Online KTV
     * @order 7
     */
    virtual int downloadMusic(const char* music_id) = 0;

    
    /**
     * 
     * @type api
     * @brief Download lyrics.
     * @param music_id Music ID.
     * @param type The lyrics file's format. See DownloadLyricType{@link #DownloadLyricType}.
     * @return Download task ID.
     * @note
     *       - If the lyrics are successfully downloaded, you will receive onDownloadSuccess{@link #IKTVManagerEventHandler#onDownloadSuccess}.
     *       - If the lyrics fail to download, you will receive onDownloadFailed{@link #IKTVManagerEventHandler#onDownloadFailed}.
     * @list Online KTV
     * @order 8
     */
    virtual int downloadLyric(const char* music_id, DownloadLyricType type) = 0;

    
    /**
     * 
     * @type api
     * @brief Download MIDI files.
     * @param music_id Music ID.
     * @return Download task ID.
     * @note
     *       - If the file is successfully downloaded, you will receive onDownloadSuccess{@link #IKTVManagerEventHandler#onDownloadSuccess}.
     *       - If the file fails to download, you will receive onDownloadFailed{@link #IKTVManagerEventHandler#onDownloadFailed}.
     * @list Online KTV
     * @order 9
     */
    virtual int downloadMidi(const char* music_id) = 0;

    
    /**
     * 
     * @type api
     * @brief Cancels download task.
     * @param download_id Download task ID.
     * @list Online KTV
     * @order 10
     */
    virtual void cancelDownload(int download_id) = 0;


    
    /**
     * 
     * @type api
     * @brief Clear music cache, including music and lyrics.
     * @list Online KTV
     * @order 11
     */
    virtual void clearCache() = 0;

    
    /**
     * 
     * @type api
     * @brief Gets the KTV player.
     * @return KTV player interfaces. See IKTVPlayer{@link #IKTVPlayer}.
     * @list Online KTV
     * @order 12
     */
    virtual IKTVPlayer *getKTVPlayer() = 0;

};

} 