//
//  BDLActivityService.h
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
#import <BDLiveCommon/BDLSendActivityMessageResponse.h>
#import "BDLLikeActivityMessageResponse.h"
#import "BDLVodUrlResponse.h"
#import "BDLGetShareUrlResponse.h"
#import "BDLRegisterResponse.h"
#import <BDLiveCommon/BDLCommentModel.h>
#import "BDLActivityModel.h"
#import "BDLInteractiveToolModel.h"
#import "BDLLiveRoomConfiguration.h"
#import <BDLivePullBase/BDLReportActivityDataResponse.h>
#import "BDLUpdateAwardContactResponse.h"
#import "BDLAwardUserResponse.h"
#import "BDLAwardWinnersResponse.h"
#import <BDLiveCommon/BDLDefines.h>
#import <BDLiveCommon/BDLSendMessageAtUserModel.h>
#import "BDLTipOffCommentResponse.h"
#import "BDLGetShareInfoResponse.h"
#import "BDLGetInviteTokenResponse.h"
#import "BDLStartPrivateChatResponse.h"
#import "BDLSendPrivateChatMessageResponse.h"
#import "BDLGetPrivateChatMessageResponse.h"
#import <BDLiveCommon/BDLImageUploadTokenResponse.h>
#import "BDLImageCheckResponse.h"
#import "BDLQuestionnaireUpdateBodyModel.h"
#import "BDLVoteDetailResponse.h"
#import "BDLQuizResultResponse.h"
#import "BDLTaskAwardWatchTimeResponse.h"
#import "BDLBasePOSTResponse.h"
#import "BDLTaskAwardRecordResponse.h"
#import "BDLTaskAwardResultListResponse.h"
#import "BDLOpenTaskAwardResponse.h"
#import "BDLGiftRewardResponse.h"
#import "BDLGiftRewardUserPointResponse.h"
#import "BDLGiftRewardSendGiftResponse.h"
#import <BDLiveCommon/BDLGiftRewardResultModel.h>
#import "BDLParticipateAwardResponse.h"
#import "BDLReserveActivityResponse.h"
#import "BDLReservationStatusResponse.h"
#import "BDLCheckInInfoResponse.h"
#import "BDLCheckInCheckResponse.h"
#import <BDLivePullBase/BDLPullBaseDefines.h>
#import "BDLRegisterController.h"
#import "BDLSendInPurchaseProductMessageResponse.h"

#if BDL_SG
#import "BDLChangeTokenWithAuthResponse.h"
#endif

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

@class BDLReportManager;

/**
 * @locale zh
 * @type keytype
 * @brief 网络失败回调。
 * @param response 一个提供响应元数据的对象，例如 HTTP headers 和状态码。如果您在发送 HTTP 或 HTTPS 请求，返回的对象实际上是一个 `NSHTTPURLResponse` 对象。
 * @param error 一个错误对象，用于表明请求失败的原因。
 */
/**
 * @locale en
 * @type keytype
 * @param response An object that provides response metadata, such as HTTP headers and status codes. If you are sending an HTTP or HTTPS request, the returned object is actually an `NSHTTPURLResponse` object.
 * @param error An error object, which is used to indicate the reason for the request failure.
 * @brief The callback is triggered when a network failure occurs.
 */
typedef void (^BDLHttpFailureBlock)(NSHTTPURLResponse * _Nullable response, NSError *error);

/**
 * @locale zh
 * @type keytype
 * @brief 活动相关service
 * @hidden (iOS)
 */
/**
 * @locale en
 * @type keytype
 * @hidden (Windows,Linux,macOS,iOS,Android)
 * @brief services related to events
 */
@protocol BDLActivityService <NSObject>

/**
 * @locale zh
 * @brief 获取历史消息
 * @param success 成功的回调, 数据靠 BDLCommentService 的 commentsDidChange 给出, 这个回调用于处理UI
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief Retrieve Historical Messages
 * @param success The callback for success provides data through `BDLCommentService`'s `commentsDidChange`, and this callback is used to handle the UI.
 * @param failure failure callback
 */
- (BOOL)searchMessageWithCount:(NSInteger)count
                       success:(void(^)(void))success
                       failure:(BDLHttpFailureBlock)failure;
/**
 * @locale zh
 * @brief 发送图片消息
 * @param success 成功的回调
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief Send Image Message
 * @param success Successful callback
 * @param failure failure callback
 */
- (BOOL)sendImageMessage:(UIImage *)image
                 success:(void (^)(BDLSendActivityMessageResponse *response))success
                 failure:(BDLHttpFailureBlock)failure;
/**
 * @locale zh
 * @brief 发送评论
 * @param textContent 消息内容
 * @param atUserArray @用户列表，详见BDLSendMessageAtUserModel
 * @param success 成功的回调（发送成功的消息会在 BDLCommentService 的 commentsDidChange中给出）
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief Send Comment
 * @param textContent Message Content
 * @param atUserArray @User list, see BDLSendMessageAtUserModel for details
 * @param success Successful callback (messages sent successfully will be provided in commentsDidChange of BDLCommentService)
 * @param failure failure callback
 */
- (BOOL)sendTextMessage:(NSString *)textContent
            atUserArray:(nullable NSArray<BDLSendMessageAtUserModel *> *)atUserArray
                success:(void (^)(BDLSendActivityMessageResponse *response))success
                failure:(BDLHttpFailureBlock)failure;
/**
 * @locale zh
 * @brief 消息点赞
 * @param commentId 需要点赞的评论内容
 * @param status 0: 取消点赞 1: 点赞
 * @param success 成功的回调（需要在这里做出UI的更改（如有））
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief Message Like
 * @param commentId The comment content that needs to be liked
 * @param status 0: Unlike 1: Like
 * @param success Callback for success (any necessary UI changes should be made here)
 * @param failure failure callback
 */
- (BOOL)likeMessageWithCommentId:(NSNumber *)commentId
                          status:(BOOL)status
                         success:(void (^)(BDLLikeActivityMessageResponse *response))success
                         failure:(BDLHttpFailureBlock)failure;
/**
 * @locale zh
 * @brief 直播间点赞
 * @param incrThumbNumber 新增的点赞数量
 * @param success 成功的回调
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief Live Room Likes
 * @param incrThumbNumber Newly Added Likes
 * @param success Successful Callback
 * @param failure failure callback
 */
- (BOOL)thumbUpWithIncrThumbNumber:(NSInteger)incrThumbNumber
                            success:(void (^)(BDLLikeActivityMessageResponse * _Nonnull))success
                            failure:(BDLHttpFailureBlock)failure;
/**
 * @locale zh
 * @brief 开始私聊
 * @param success 成功的回调
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief Start a Private Chat
 * @param success Success Callback
 * @param failure Failure Callback
 */
- (BOOL)startPrivateChat:(void (^)(BDLStartPrivateChatResponse *response))success
                 failure:(BDLHttpFailureBlock)failure;
/**
 * @locale zh
 * @brief 发送私聊消息
 * @param textContent 消息内容
 * @param success 成功的回调
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief Send Private Message
 * @param textContent Message Content
 * @param success Successful Callback
 * @param failure Failure Callback
 */
- (BOOL)sendPrivateChatMessage:(NSString *)textContent
                       success:(void (^)(BDLSendPrivateChatMessageResponse *response))success
                       failure:(BDLHttpFailureBlock)failure;
/**
 * @locale zh
 * @brief 获取 当前 私聊消息
 * @param count 需要获取的数量
 * @param lastMsgId 本地持有的最新的消息id
 * @param success 成功的回调
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief Get Current Private Messages
 * @param count Quantity to be obtained
 * @param lastMsgId The most recent locally stored message ID
 * @param success success callback
 * @param failure failure callback
 */
- (BOOL)getCurrentPrivateChatMessage:(NSInteger)count
                           lastMsgId:(NSInteger)lastMsgId
                             success:(void (^)(BDLGetPrivateChatMessageResponse *response))success
                             failure:(BDLHttpFailureBlock)failure;
/**
 * @locale zh
 * @brief 获取 历史 私聊消息
 * @param success 成功的回调
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief Retrieve Historical Private Messages
 * @param success success callback
 * @param failure failure callback
 */
- (BOOL)getHistoryPrivateChatMessage:(void (^)(BDLGetPrivateChatMessageResponse *response))success
                             failure:(BDLHttpFailureBlock)failure;

/**
 * @locale zh
 * @brief 当前用户注册状态，详见 [BDLRegisterStatus](1185544#BDLRegisterStatus)
 */
/**
 * @locale en
 * @brief The current user's registration status. See [BDLRegisterStatus](viewer-sdk-for-ios-type-definitions#BDLRegisterStatus) for details.
 */
- (BDLRegisterStatus)registerStatus;
/**
 * @locale zh
 * @brief 获取注册Controller
 */
- (BDLRegisterController *)getRegisterController;
/**
 * @locale zh
 * @brief 开始注册
 */
/**
 * @locale en
 * @brief Start Registration
 */
- (void)beginRegister;
/**
 * @locale zh
 * @brief 取消注册
 */
/**
 * @locale en
 * @brief Unregister
 */
- (void)cancelRegister;
/**
 * @locale zh
 * @brief 添加执行一次的注册成功事件
 * @param target 执行事件的target
 * @param invocation 执行的具体事件
 */
/**
 * @locale en
 * @brief Add a one-time registration success event
 * @param target The target of the event execution
 * @param invocation The specific events executed
 */
- (void)addOnceRegisterObserver:(id)target invocation:(NSInvocation *)invocation;
/**
 * @locale zh
 * @brief 移除所有注册监听事件
 */
/**
 * @locale en
 * @brief Remove All Registered Event Listeners
 */
- (void)removeRegisterObserver;
/**
 * @locale zh
 * @brief 是否为竖屏 
 */
/**
 * @locale en
 * @brief Is it in portrait mode
 */
- (BOOL)isPortrait;
/**
 * @locale zh
 * @brief 是否为自定义登录Mode
 */
/**
 * @locale en
 * @brief Is Custom Login Mode
 */
- (BOOL)isCustomMode;
/**
 * @locale zh
 * @brief 是否为自定义登录
 * @return YES authMode 为 BDLActivityAuthModeCustom 或者 设置 hasLoginProvider 并且 没有配置nickname
 */
/**
 * @locale en
 * @brief Is it a custom login
 */
- (BOOL)isCustomLogin;
/**
 * @locale zh
 * @brief loginProvider 是否存在
 * @return 存在返回YES，否则返回NO
 */
/**
 * @locale en
 * @brief Check if the loginProvider exists
 */
- (BOOL)hasLoginProvider;

/**
 * @locale zh
 * @brief 是否已经进入直播间
 */
/**
 * @locale en
 * @brief Has the user already entered the live room?
 */
- (BOOL)isJoined;

/**
 * @brief 调用自定义登录
 * @param complete 完成的回调 success: 是否成功 error: success为NO时候的错误信息
 */
/**
 * @locale en
 * @brief Call Custom Login
 * @param complete 完成的回调 success: 是否成功 error: success为NO时候的错误信息
 */
- (void)customLoginWithComplete:(void(^)(BOOL success, NSError * _Nullable error))complete;
/**
 * @locale zh
 * @brief 注册
 * @param nickName 注册的名字
 * @param success 成功的回调
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief Register
 * @param nickName Registered Name
 * @param success Successful Callback
 * @param failure failure callback
 */
- (BOOL)registerWithNickName:(NSString *)nickName
                     success:(void (^)(BDLRegisterResponse *response))success
                     failure:(BDLHttpFailureBlock)failure;
/**
 * @locale zh
 * @brief 数据上报
 * @param params 需要上报的参数
 * @param success 成功的回调
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief Data Reporting
 * @param params Parameters that need to be reported
 * @param success Successful callback
 * @param failure onFailure callback
 */
- (BOOL)reportActivityDataWithParams:(NSDictionary *)params
                             success:(void (^)(BDLReportActivityDataResponse *response))success
                             failure:(BDLHttpFailureBlock)failure;
/**
 * @locale zh
 * @brief  VID换URL
 * @param vid 视频的vid
 * @param success 成功的回调
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief VID to URL
 * @param vid vid of the video
 * @param success success callback
 * @param failure failure callback
 */
- (BOOL)vodUrlWithVid:(NSString *)vid
              success:(void (^)(BDLVodUrlResponse *response))success
              failure:(BDLHttpFailureBlock)failure;
/**
 * @locale zh
 * @brief 获取分享链接
 * @param success 成功的回调
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief Get Share Link
 * @param success Successful callback
 * @param failure Failure Callback
 */
- (BOOL)getShareUrlSuccess:(void (^)(BDLGetShareUrlResponse *response))success
                   failure:(BDLHttpFailureBlock)failure;
/**
 * @locale zh
 * @brief 获取分享信息
 * @param success 成功的回调
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief Retrieve Share Information
 * @param success Successful callback
 * @param failure Failure Callback
 */
- (BOOL)getShareInfoSuccess:(void (^)(BDLGetShareInfoResponse *response))success
                    failure:(BDLHttpFailureBlock)failure;

/**
 * @locale zh
 * @brief 获取分享者的邀请token
 * @param success 成功的回调
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief Retrieve the inviter's invitation token
 * @param success Successful Callback
 * @param failure failure callback
 */
- (BOOL)getInviteTokenSuccess:(void (^)(BDLGetInviteTokenResponse *response))success
                      failure:(BDLHttpFailureBlock)failure;

/**
 * @locale zh
 * @brief 获取指定抽奖的用户参与/获奖情况
 * @param awardId 抽奖id
 * @param success 成功的回调
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief Retrieve the participation/winning status of users for a specified lottery
 * @param awardId Lottery ID
 * @param success Successful callback
 * @param failure Failure Callback
 */
- (BOOL)fetchAwardUserStatusWithAwardId:(NSNumber *)awardId
                                success:(void(^)(BDLAwardUserResponse *response))success
                                failure:(BDLHttpFailureBlock)failure;
/**
 * @locale zh
 * @brief 获取中奖名单
 * @param awardId 抽奖id
 * @param success 成功的回调
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief Retrieve the List of Winners
 * @param awardId draw id
 * @param success Successful Callback
 * @param failure failure callback
 */
- (BOOL)fetchAwardWinnersWithAwardId:(NSNumber *)awardId
                             success:(void(^)(BDLAwardWinnersResponse *response))success
                             failure:(BDLHttpFailureBlock)failure;
/**
 * @locale zh
 * @brief 完善中奖信息
 * @param awardId 抽奖id
 * @param phone 电话号码
 * @param address 收货地址
 * @param receiverName 收货人名字
 * @param email 邮箱
 * @param success 成功的回调
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief Improve Winning Information
 * @param awardId `draw_id`
 * @param phone Phone Number
 * @param address Shipping Address
 * @param receiverName Recipient Name
 * @param email email
 * @param success Successful callback
 * @param failure failure callback
 */
- (BOOL)updateAwardContactWithAwardId:(NSNumber *)awardId
                                phone:(nullable NSString *)phone
                              address:(nullable NSString *)address
                         receiverName:(nullable NSString *)receiverName
                                email:(NSString *)email
                              success:(void(^)(BDLUpdateAwardContactResponse *response))success
                              failure:(BDLHttpFailureBlock)failure;
/**
 * @locale zh
 * @brief 参与抽奖
 * @param awardId 抽奖id
 * @param barragePwd 弹幕内容
 * @param success 成功的回调
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief Participate in the lottery
 * @param awardId lotteryId
 * @param barragePwd Bullet Screen Content
 * @param success Successful Callback
 * @param failure failure callback
 */
- (BOOL)participateAwardWithAwardId:(NSNumber *)awardId
                         barragePwd:(nullable NSString *)barragePwd
                            success:(void(^)(BDLParticipateAwardResponse *result))success
                            failure:(BDLHttpFailureBlock)failure;
/**
 * @locale zh
 * @brief 获取用户是否填写问卷
 * @param questionnaireModel 问卷model
 * @param success 成功的回调
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief Check if the user has completed the survey
 * @param questionnaireModel Questionnaire model
 * @param success Successful callback
 * @param failure failure callback
 */
- (BOOL)checkQuestionnaireFilled:(BDLQuestionnaireModel *)questionnaireModel
                         success:(void(^)(BOOL isUserFilled))success
                         failure:(BDLHttpFailureBlock)failure;
/**
 * @locale zh
 * @brief 提交问卷
 * @param  questionnaireModel 问卷model
 * @param answersModel 答案model
 * @param success 成功的回调
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief Submit Survey
 * @param questionnaireModel Questionnaire Model
 * @param answersModel Answer model
 * @param success Successful Callback
 * @param failure failure callback
 */
- (BOOL)updateQuestionnaire:(BDLQuestionnaireModel *)questionnaireModel
               answersModel:(BDLQuestionnaireAnswersModel *)answersModel
                    success:(void(^)(BOOL result))success
                    failure:(BDLHttpFailureBlock)failure;
/**
 * @locale zh
 * @brief 获取投票详情
 * @param voteId 投票Id
 * @param success 成功的回调
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief Get Voting Details
 * @param voteId Voting Id
 * @param success Success Callback
 * @param failure failure callback
 */
- (BOOL)getVoteDetailWithVoteId:(NSString *)voteId
                        success:(void (^)(BDLVoteDetailResponse *response))success
                        failure:(BDLHttpFailureBlock)failure;
/**
 * @locale zh
 * @brief 提交投票
 * @param voteId 投票Id
 * @param optionType 选项列表
 * @param success 成功的回调
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief Submit Vote
 * @param voteId VoteId
 * @param optionType Options List
 * @param success success callback
 * @param failure failure callback
 */
- (BOOL)submitVoteWithVoteId:(NSString *)voteId
                  optionType:(NSArray<NSString *> *)optionType
                     success:(void (^)(BDLVoteDetailResponse *response))success
                     failure:(BDLHttpFailureBlock)failure;

// MARK: - checkIn

- (BOOL)getCheckInInfo:(NSString *)checkInId
               success:(void (^)(BDLCheckInInfoResponse *response))success
               failure:(BDLHttpFailureBlock)failure;

- (BOOL)checkCheckIn:(NSString *)checkInId personInfo:(NSString *)personInfo
             success:(void (^)(BDLCheckInCheckResponse *response))success
             failure:(BDLHttpFailureBlock)failure;


// MARK: - quiz

/**
 * @locale zh
 * @brief 获取答题详情
 * @param quizId 答题id
 * @param success 成功的回调
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief Get Quiz Details
 * @param quizId Question ID
 * @param success Successful callback
 * @param failure failure callback
 */
- (BOOL)getQuizResultWithQuizId:(NSNumber *)quizId
                        success:(void (^)(BDLQuizResultResponse *response))success
                        failure:(BDLHttpFailureBlock)failure;
/**
 * @locale zh
 * @brief 提交答题
 * @param quizId 答题id
 * @param options 答题内容
 * @param success 成功的回调
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief Submit Answer
 * @param quizId Question ID
 * @param options Answer Content
 * @param success Success Callback
 * @param failure Failure Callback
 */
- (BOOL)submitQuizWithQuizId:(NSNumber *)quizId
                     options:(NSArray<NSString *> *)options
                     success:(void (^)(BDLQuizResultResponse *response))success
                     failure:(BDLHttpFailureBlock)failure;
/**
 * @locale zh
 * @brief 获取当前媒体(直播/点播)的index
 * @return 当前播放媒体(直播/点播)的index
 */
/**
 * @locale en
 * @brief Get the index of the current media (live/on-demand)
 */
- (NSUInteger)getCurrentMediaIndex;
/**
 * @locale zh
 * @brief 修改当前媒体(点播/直播)的index
 * @param index 需要修改到的值
 */
/**
 * @locale en
 * @brief Modify the index of the current media (on-demand/live)
 * @param index The value that needs to be modified
 */
- (void)changeCurrentPlayingMediaToIndex:(NSUInteger)index;
/**
 * @locale zh
 * @brief 下一个回放视频
 * @return 是否成功 NO: 没有next了（配置了不自动重播回放，当前是最后一个视频） YES:调用成功
 */
/**
 * @locale en
 * @brief Next Playback Video
 */
- (BOOL)nextReplayVideo;
/**
 * @locale zh
 * @brief 举报评论
 * @param commentId 需要举报的评论id
 * @param reason 举报的原因
 * @param tipOffType 评论举报类型，详见 [BDLCommentTipOffType](1185544#BDLCommentTipOffType)
 * @param success 成功的回调
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief Report Comment
 * @param commentId The ID of the comment to report
 * @param reason Reason for Report
 * @param tipOffType Comment reporting types, see [BDLCommentTipOffType](viewer-sdk-for-ios-type-definitions#BDLCommentTipOffType) for details
 * @param success Successful callback
 * @param failure failure callback
 */
- (BOOL)tipOffCommentWithCommentId:(NSNumber *)commentId
                             reason:(NSString *)reason
                         tipOffType:(BDLCommentTipOffType)tipOffType
                            success:(void (^)(BDLTipOffCommentResponse *response))success
                            failure:(BDLHttpFailureBlock)failure;

// MARK: - TaskAward 累计抽奖
/**
 * @locale zh
 * @brief 获取累计观看时长
 * @param success 成功的回调
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief Get Cumulative Viewing Time
 * @param success Successful callback
 * @param failure failure callback
 */
- (BOOL)getTaskAwardWatchTimeWithSuccess:(void (^)(BDLTaskAwardWatchTimeResponse *response))success
                                 failure:(BDLHttpFailureBlock)failure;
/**
 * @locale zh
 * @brief 填写中奖信息
 * @param awardTelephone 电话
 * @param awardAddress 地址
 * @param taskAwardItemId 奖项id
 * @param receiverName 收件人
 * @param email 邮箱
 * @param success 成功的回调
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief Fill in Prize Information
 * @param awardTelephone phone
 * @param awardAddress Address
 * @param taskAwardItemId award_id
 * @param receiverName Recipient
 * @param email email 
 * @param success Callback on success
 * @param failure failure callback
 */
- (BOOL)taskAwardWinnerMessageUpdateWithAwardTelephone:(NSString *)awardTelephone
                                          awardAddress:(NSString *)awardAddress
                                       taskAwardItemId:(NSNumber *)taskAwardItemId
                                          receiverName:(NSString *)receiverName
                                                 email:(NSString *)email
                                               success:(void (^)(BDLBasePOSTResponse *response))success
                                               failure:(BDLHttpFailureBlock)failure;
/**
 * @locale zh
 * @brief 获取累计观看抽奖 中奖人轮播列表
 * @param success 成功的回调
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief Get the cumulative winner carousel list for watching the lottery
 * @param success Successful callback
 * @param failure Failure Callback
 */
- (BOOL)getTaskAwardWinnerListWithSuccess:(void (^)(BDLTaskAwardRecordResponse *response))success
                                  failure:(BDLHttpFailureBlock)failure;
/**
 * @locale zh
 * @brief 获取累计观看抽奖 当前用户中奖记录
 * @param success 成功的回调
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief Retrieve Cumulative Viewing Lottery Winning Records for Current User
 * @param success Success Callback
 * @param failure failure callback
 */
- (BOOL)getTaskAwardResultListWithSuccess:(void (^)(BDLTaskAwardResultListResponse *response))success
                                  failure:(BDLHttpFailureBlock)failure;
/**
 * @locale zh
 * @brief 累计观看抽奖 开奖
 * @param taskAwardItemId 奖项id
 * @param success 成功的回调
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief Total Watch Raffle Draw
 * @param taskAwardItemId Award ID
 * @param success Successful Callback
 * @param failure Failure Callback
 */
- (BOOL)openTaskAwardWithTaskAwardItemId:(NSNumber *)taskAwardItemId
                                 success:(void (^)(BDLOpenTaskAwardResponse *response))success
                                 failure:(BDLHttpFailureBlock)failure;

// MARK: - Gift Reward 打赏
/**
 * @locale zh
 * @hidden (Windows,Linux,macOS,iOS,Android)
 * @brief 获取礼物配置信息
 * @param success 成功的回调
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief Retrieve Gift Configuration Information
 * @param success successful callback
 * @param failure Failure Callback
 */
- (BOOL)getGiftRewardWithSuccess:(void (^)(BDLGiftRewardResponse *response))success
                          failure:(BDLHttpFailureBlock)failure;
/**
 * @locale zh
 * @hidden (Windows,Linux,macOS,iOS,Android)
 * @brief 获取用户积分
 * @param success 成功的回调
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief Get User Points
 * @param success Successful callback
 * @param failure Failure Callback
 */
- (BOOL)getGiftRewardUserPointWithSuccess:(void (^)(BDLGiftRewardUserPointResponse *response))success
                                                             failure:(BDLHttpFailureBlock)failure;
/**
 * @locale zh
 * @hidden (Windows,Linux,macOS,iOS,Android)
 * @brief 打赏主播
 * @param giftId 礼物id
 * @param giftCount 礼物数量
 * @param success 成功的回调
 * @param failure 失败回调
 * @return 是否调用成功
 */
/**
 * @locale en
 * @brief Reward the Streamer
 * @param giftId Gift ID
 * @param giftCount Number of Gifts
 * @param success Successful Callback
 * @param failure failure callback
 */
- (BOOL)sendGiftRewardWithGiftId:(NSNumber *)giftId
                       giftCount:(NSUInteger)giftCount
                         success:(void (^)(BDLGiftRewardSendGiftResponse *response))success
                         failure:(BDLHttpFailureBlock)failure;

/**
 * @locale zh
 * @hidden (Windows,Linux,macOS,iOS,Android)
 * @brief 取出并移除新的打赏信息
 * @return 最新的打赏信息
 */
/**
 * @locale en
 * @brief Retrieve and remove new reward information
 */
- (nullable BDLGiftRewardResultModel *)popGiftRewardResult;
/**
 * @locale zh
 * @hidden (Windows,Linux,macOS,iOS,Android)
 * @brief 获取未显示的打赏缓存队列
 * @return 未显示的打赏缓存数据
 */
/**
 * @locale en
 * @brief Retrieve the undisplayed reward cache queue
 */
- (NSArray<BDLGiftRewardResultModel *> *)giftRewardResults;
/**
 * @locale zh
 * @hidden (Windows,Linux,macOS,iOS,Android)
 * @brief 是否开启了礼物打赏特效
 * @return YES: 开启了 NO: 未开启
 */
/**
 * @locale en
 * @brief Is the gift reward effect enabled
 */
- (BOOL)isEnableGiftRewardEffect;
/**
 * @locale zh
 * @hidden (Windows,Linux,macOS,iOS,Android)
 * @brief 设置是否开启了礼物打赏特效
 * @param enableGiftRewardEffect YES: 开启 NO: 未开启
 */
/**
 * @locale en
 * @brief Set whether the gift reward effect is enabled
 * @param enableGiftRewardEffect YES: Enabled NO: Disabled
 */
- (void)setEnableGiftRewardEffect:(BOOL)enableGiftRewardEffect;

// MARK: - 预约

/// 获取直播预约状态
- (BOOL)getReservationStatusWithSuccess:(void (^)(BDLReservationStatusResponse *response))success
                                failure:(BDLHttpFailureBlock)failure;

/// 预约直播
- (BOOL)reserveActivityWithSuccess:(void (^)(BDLReserveActivityResponse *response))success
                           failure:(BDLHttpFailureBlock)failure;

/// 商品购买中状态上报
- (BOOL)sendInPurchaseProductMessageWithProductId:(NSNumber *)productId
                                          success:(void (^_Nullable)(BDLSendInPurchaseProductMessageResponse *response))success
                                          failure:(BDLHttpFailureBlock _Nullable)failure;

/**
 * @locale zh
 * @brief 获取活动的数据
 * @return 活动数据
 */
/**
 * @locale en
 * @brief Retrieve event data
 */
- (nullable BDLActivityModel *)getActivityModel;
/**
 * @locale zh
 * @brief 获取互动工具的数据
 */
/**
 * @locale en
 * @brief Retrieve Interaction Tool Data
 */
- (nullable NSArray<BDLInteractiveToolModel *> *)getInteractiveTools;
/**
 * @locale zh
 * @brief 获取未开奖的抽奖数据
 */
/**
 * @locale en
 * @brief Retrieve Unawarded Lottery Data
 */
- (nullable NSArray<BDLInteractiveAwardModel *> *)getOngoingAwards;
/**
 * @locale zh
 * @brief 获取累计抽奖中奖的名单
 */
/**
 * @locale en
 * @brief Get the list of cumulative lottery winners
 */
- (nullable NSArray<BDLTaskAwardItemRecordModel *> *)getTaskAwardWinnerRecords;
/**
 * @locale zh
 * @brief 获取当前的累计观看抽奖数据
 */
/**
 * @locale en
 * @brief Get the current cumulative viewership lottery data
 */
- (nullable BDLTaskAwardConfigModel *)getCurrentTaskAwardModel;
/**
 * @locale zh
 * @brief 获取进入直播间时候的问卷
 */
/**
 * @locale en
 * @brief Retrieve the questionnaire upon entering the live room
 */
- (nullable BDLQuestionnaireModel *)getLivePageInQuestionnaire;
/**
 * @locale zh
 * @brief 获取当前的语言类型
 */
/**
 * @locale en
 * @brief Get the current language type
 */
- (BDLLanguageType)getCurrentLangType;
/**
 * @locale zh
 * @brief 设置当前的语言, 用于 自定义实现多语言弹框, 选中语言后, 可以通过该方法修改当前的语言
 * @param selectedLangType 选中语言类型，详见 [BDLLanguageType](1185544#BDLLanguageType)
 */
/**
 * @locale en
 * @brief Set the current language for customizing multi-language pop-ups. After selecting a language, use this method to modify the current language.
 * @param selectedLangType Select language type, refer to [BDLLanguageType](viewer-sdk-for-ios-type-definitions#BDLLanguageType) for details.
 */
- (void)setSelectedLangType:(BDLLanguageType)selectedLangType;
/**
 * @locale zh
 * @brief 获取当前已有的评论数据
 */
/**
 * @locale en
 * @brief Retrieve Existing Comment Data
 */
- (NSArray<BDLCommentModel *> *)getCurrentCommentArray;
/**
 * @locale zh
 * @brief 获取当前已有的热评数据
 */
/**
 * @locale en
 * @brief Retrieve current hot comment data
 */
- (NSArray<BDLCommentModel *> *)getCurrentHotCommentArray;
/**
 * @locale zh
 * @brief 获取当前已有的置顶数据
 */
/**
 * @locale en
 * @brief Retrieve the existing pinned data
 */
- (NSArray<BDLCommentModel *> *)getCurrentTopCommentArray;
/**
 * @locale zh
 * @brief 获取当前私聊数据
 */
/**
 * @locale en
 * @brief Get Current Private Chat Data
 */
- (NSArray<BDLPrivateChatMessageModel *> *)getCurrentPrivateChatMessageArray;
/**
 * @locale zh
 * @brief 获取数据上报的实例
 */
/**
 * @locale en
 * @brief Get data reporting instance
 */
- (BDLReportManager *)getReportManager;
/**
 * @locale zh
 * @brief 获取直播间配置
 */
/**
 * @locale en
 * @brief Get Live Room Configuration
 */
- (BDLLiveRoomConfiguration *)getLiveRoomConfiguration;
/**
 * @locale zh
 * @brief 当前用户的id
 */
/**
 * @locale en
 * @brief The current user's ID
 */
- (NSNumber *)userId;
/**
 * @locale zh
 * @brief 当前用户的昵称
 */
/**
 * @locale en
 * @brief The nickname of the current user
 */
- (NSString *)nickname;
/**
 * @locale zh
 * @brief 更新当前用户的昵称
 * @return nickname 需要更新的昵称
 */
/**
 * @locale en
 * @brief Update the current user's nickname
 */
- (void)updateNickname:(NSString *)nickname;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
