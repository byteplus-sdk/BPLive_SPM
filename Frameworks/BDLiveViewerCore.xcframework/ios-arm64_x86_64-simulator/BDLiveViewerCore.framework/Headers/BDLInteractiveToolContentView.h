//
//  BDLInteractiveToolContentView.h
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
#import <BDLiveCommon/BDLDefines.h>
#import <BDLiveCommon/BDLBaseView.h>
#import "BDLMenuService.h"
#import "BDLInteractiveToolModel.h"
#import "BDLInteractiveToolConfiguration.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type callback
 * @brief 互动工具内容 view 的代理方法。
 */
/**
 * @locale en
 * @type callback
 * @brief The delegate methods for the interaction tool content view.
 */
@protocol BDLInteractiveToolContentViewDelegate <NSObject>
/**
 * @locale zh
 * @brief 互动消息文字中的 URL 是否可以交互。
 * @param textView URL 所在的文本 view。
 * @param URL 互动消息文字中的 URL。
 * @return - `YES`：URL 可以交互。
 *         - `NO`：URL 不可以交互。
 */
/**
 * @locale en
 * @brief Whether the URL in the interaction message text is clickable.
 * @param textView The text view where the URL is located.
 * @param URL The URL in the interaction message text.
 * @return - `YES`: Clickable.
 *         - `NO`: Not clickable.
 */
- (BOOL)interactiveToolTextView:(UITextView *)textView shouldInteractWithURL:(NSURL *)URL;
/**
 * @locale zh
 * @brief 在观众点击互动工具内容 view 时，SDK 调用该方法。
 * @param model 互动工具 Model。详见 [BDLInteractiveToolModel](1185544#BDLInteractiveToolModel)。
 * @param contextModel 互动工具内容 Model。详见 [BDLInteractiveContextModel](1185540#BDLInteractiveContextModel)。
 */
/**
 * @locale en
 * @brief The SDK calls this method when viewers tap the interaction tool content view.
 * @param model The interaction tool model. For more information, see [BDLInteractiveToolModel](viewer-sdk-for-ios-type-definitions#BDLInteractiveToolModel)
 * @param contextModel The model of interaction tool content. For more information, see [BDLInteractiveContextModel](docs-bdlliveengine#BDLInteractiveContextModel).
 */
- (void)didClickContextViewWithModel:(BDLInteractiveToolModel *)model contextModel:(BDLInteractiveContextModel *)contextModel;

@end

/**
 * @locale zh
 * @type api
 * @brief 互动工具内容 view。
 */
/**
 * @locale en
 * @brief The interaction tool content view.
 */
@interface BDLInteractiveToolContentView : BDLBaseView <BDLMenuService>

/**
 * @locale zh
 * @brief 是否为竖屏直播间。<br>
 *        - `YES`：竖屏直播间。
 *        - `NO`：横屏直播间。
 */
/**
 * @locale en
 * @brief Whether the live room is in portrait mode.
 *        - `YES`: Portrait mode.
 *        - `NO`: Landscape mode.
 */
@property (nonatomic, assign, readonly) BOOL isPortrait;
/**
 * @locale zh
 * @brief 直播间内发送的互动工具总条数 label。
 */
/**
 * @locale en
 * @brief The label for the total number of interaction tools sent in the live room.
 */
@property (nonatomic, strong) UILabel *totalLabel;
/**
 * @locale zh
 * @brief 内容的容器 tableView。
 */
/**
 * @locale en
 * @brief The container tableView of the content.
 */
@property (nonatomic, strong) UITableView *tableView;
/**
 * @locale zh
 * @brief 当前的语言类型。详见 [BDLLanguageType](1185544#BDLLanguageType)。
 */
/**
 * @locale en
 * @brief The current language type. For more information, see [BDLLanguageType](viewer-sdk-for-ios-type-definitions#BDLLanguageType).
 */
@property (nonatomic, assign) BDLLanguageType langType;
/**
 * @locale zh
 * @brief 当前所有支持的语言类型。
 */
/**
 * @locale en
 * @brief All the currently supported language types.
 */
@property (nonatomic, copy) NSArray<NSNumber *> *langTypes;
/**
 * @locale zh
 * @brief 是否为暗黑模式主题。<br>
 *        - `YES`：暗黑模式。
 *        - `NO`：非暗黑模式。
 */
/**
 * @locale en
 * @brief Whether the theme is dark mode.
 *        - `YES`: Dark mode.
 *        - `NO`: Not dark mode.
 */
@property (nonatomic, assign) BOOL isDarkTheme;
/**
 * @locale zh
 * @brief 当前互动工具内容 view 对应的数据。详见 [BDLInteractiveToolModel](1185544#BDLInteractiveToolModel)。
 */
/**
 * @locale en
 * @brief The data corresponding to the current interaction tool content view. For more information, see [BDLInteractiveToolModel](viewer-sdk-for-ios-type-definitions#BDLInteractiveToolModel).
 */
@property (nonatomic, copy) NSArray<BDLInteractiveToolModel *> *interactiveTools;
/**
 * @locale zh
 * @brief 代理方法。详见 [BDLInteractiveToolContentViewDelegate](1185541#BDLInteractiveToolContentViewDelegate)。
 */
/**
 * @locale en
 * @brief The delegate method. For more information, see [BDLInteractiveToolContentViewDelegate](viewer-SDK-for-ios-callbacks#BDLInteractiveToolContentViewDelegate).
 */
@property (nonatomic, weak) id<BDLInteractiveToolContentViewDelegate> delegate;
/**
 * @locale zh
 * @brief 根据配置更新 view。
 * @param config 配置。详见 [BDLInteractiveToolConfiguration](1185544#BDLInteractiveToolConfiguration)。
 * @list 互动工具菜单
 */
/**
 * @locale en
 * @brief Updates the view based on the configuration.
 * @param config The configuration. For more information, see [BDLInteractiveToolConfiguration](viewer-sdk-for-ios-type-definitions#BDLInteractiveToolConfiguration).
 */
- (void)updateWithConfig:(BDLInteractiveToolConfiguration *)config;
/**
 * @locale zh
 * @brief 初始化。
 * @param isPortrait 是否以竖屏直播间初始化。<br>
 *        - `YES`：以竖屏直播间初始化。
 *        - `NO`：以横屏直播间初始化。
 * @list 互动工具菜单
 * @return 互动工具内容 view 实例。
 */
/**
 * @locale en
 * @brief Initializes the instance of the interaction tool content view.
 * @param isPortrait Whether to initialize in portrait mode.
 *        - `YES`: Portrait mode.
 *        - `NO`: Landscape mode.
 * @return The instance of the interaction tool content view.
 */
- (instancetype)initWithPortrait:(BOOL)isPortrait;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
