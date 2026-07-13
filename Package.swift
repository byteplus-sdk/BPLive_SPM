// swift-tools-version: 5.9

import PackageDescription

let package = Package(
    name: "BPLive",
    defaultLocalization: "zh-Hans",
    platforms: [
        .iOS(.v12)
    ],
    products: [
        .library(name: "BDLiveBaseLibrary", targets: ["BDLiveBaseWrapper"]),
        .library(name: "BDLiveCommonLibrary", targets: ["BDLiveCommonWrapper"]),
        .library(name: "BDLivePullBaseLibrary", targets: ["BDLivePullBaseWrapper"]),

        .library(name: "BDLiveViewerLibrary", targets: ["BDLiveViewerWrapper"]),
        .library(name: "BDLiveViewerWithoutRTCLibrary", targets: ["BDLiveViewerWithoutRTCWrapper"]),

        // .library(name: "BDLiveVodPlayerLibrary", targets: ["BDLiveVodPlayerWrapper"]),

        .library(name: "BDLiveLiveStreamingLibrary", targets: ["BDLiveLiveStreamingWrapper"]),
        .library(name: "BDLiveLiveStreamingWithoutRTCLibrary", targets: ["BDLiveLiveStreamingWithoutRTCWrapper"]),

        .library(name: "BDLiveScreenShareLibrary", targets: ["BDLiveScreenShareWrapper"]),
    ],
    dependencies: [
        .package(url: "git@github.com:SDWebImage/SDWebImage.git", from: "5.0.0"),
        .package(url: "git@github.com:SDWebImage/SDWebImageWebPCoder.git", from: "0.14.0"),
        .package(url: "git@github.com:jdg/MBProgressHUD.git", from: "1.2.0"),
        .package(url: "git@github.com:CoderMJLee/MJRefresh.git", from: "3.7.0"),
        // .package(url: "git@github.com:volcengine/TTSDK_SPM.git", exact: "1.49.3-premium"),
        .package(url: "git@github.com:byteplus-sdk/TTSDK_BytePlus_SPM.git", exact: "1.49.300-premium"),
    ],
    targets: [
        // ================================================================
        // MARK: - Binary Targets (本地 xcframework)
        // ================================================================
        // 自有模块
        .binaryTarget(name: "BDLiveBaseBinary", path: "Frameworks/BDLiveBase.xcframework"),
        .binaryTarget(name: "BDLiveCommonBinary", path: "Frameworks/BDLiveCommon.xcframework"),
        .binaryTarget(name: "BDLivePullBaseBinary", path: "Frameworks/BDLivePullBase.xcframework"),
        .binaryTarget(name: "BDLiveViewerCoreBinary", path: "Frameworks/BDLiveViewerCore.xcframework"),
        .binaryTarget(name: "BDLiveAudienceLinkBinary", path: "Frameworks/BDLiveAudienceLink.xcframework"),
        // .binaryTarget(name: "BDLiveVodPlayerBinary", path: "Frameworks/BDLiveVodPlayer.xcframework"),
        .binaryTarget(name: "BDLiveLiveStreamingCoreBinary", path: "Frameworks/BDLiveLiveStreamingCore.xcframework"),
        .binaryTarget(name: "BDLiveScreenShareRTCBinary", path: "Frameworks/BDLiveScreenShareRTC.xcframework"),

        // 内部 vendored 依赖
        .binaryTarget(name: "TTNetworkManagerBinary", path: "Frameworks/Vendor/TTNetworkManager.xcframework"),
        .binaryTarget(name: "BytedEffectSDKBinary", path: "Frameworks/Vendor/effect-sdk.xcframework"),
        // .binaryTarget(name: "RangersAppLogBinary", path: "Frameworks/Vendor/RangersAppLog.xcframework"),
        // .binaryTarget(name: "VolcEngineEncryptorBinary", path: "Frameworks/Vendor/VolcEngineEncryptor.xcframework"),
        // .binaryTarget(name: "VolcEngineRTCScreenCaptureBinary", path: "Frameworks/Vendor/VolcEngineRTCScreenCapturer.xcframework"),
        .binaryTarget(name: "BytePlusRTCScreenCapturerBinary", path: "Frameworks/Vendor/BytePlusRTCScreenCapturer.xcframework"),
        // .binaryTarget(name: "VolcEngineRTCBinary", path: "Frameworks/Vendor/VolcEngineRTC.xcframework"),
        .binaryTarget(name: "BytePlusRTCBinary", path: "Frameworks/Vendor/BytePlusRTC.xcframework"),
        .binaryTarget(name: "ByteRTCFFmpegAudioExtensionBinary", path: "Frameworks/Vendor/ByteRTCFFmpegAudioExtension.xcframework"),

        // ================================================================
        // MARK: - Wrapper Targets
        // ================================================================

        // ---- Base ----
        .target(
            name: "BDLiveBaseWrapper",
            dependencies: [
                "BDLiveBaseBinary",
            ],
            path: "Sources/BDLiveBaseWrapper",
            resources: [
                .copy("PrivacyInfo.xcprivacy"),
            ],
            linkerSettings: [
                .linkedFramework("WebKit"),
                .linkedFramework("AVKit"),
            ]
        ),

        // ---- Common ----
        .target(
            name: "BDLiveCommonWrapper",
            dependencies: [
                "BDLiveCommonBinary",
                "BDLiveBaseWrapper",
                "TTNetworkManagerBinary",
                // "RangersAppLogBinary",
                // "VolcEngineEncryptorBinary",
                .product(name: "MJRefresh", package: "MJRefresh"),
                .product(name: "MBProgressHUD", package: "MBProgressHUD"),
                .product(name: "SDWebImage", package: "SDWebImage"),
                .product(name: "SDWebImageWebPCoder", package: "SDWebImageWebPCoder"),
                .product(name: "TTSDK_Uploader", package: "TTSDK_BytePlus_SPM"),
            ],
            path: "Sources/BDLiveCommonWrapper",
            resources: [
                .copy("Resources/BDLEmoji.bundle"),
                .copy("Resources/BDLGifEmoji.bundle"),
                .copy("Resources/BDLCommonImageResource.bundle"),
            ]
        ),

        // ---- PullBase ----
        .target(
            name: "BDLivePullBaseWrapper",
            dependencies: [
                "BDLivePullBaseBinary",
            ],
            path: "Sources/BDLivePullBaseWrapper"
        ),

        // ---- ViewerCore ----
        .target(
            name: "BDLiveViewerCoreWrapper",
            dependencies: [
                "BDLiveViewerCoreBinary",
                "BDLiveCommonWrapper",
                "BDLivePullBaseWrapper",
                .product(name: "TTSDK_Player", package: "TTSDK_BytePlus_SPM"),

            ],
            path: "Sources/BDLiveViewerCoreWrapper",
            resources: [
                .copy("Resources/BDLViewerAssets.bundle"),
                .copy("Resources/BDLViewerLanguage.bundle"),
                .copy("Resources/BDLViewerGif.bundle"),
            ],
            linkerSettings: [
                .linkedFramework("EventKit"),
                .linkedFramework("MobileCoreServices"),
                .linkedFramework("Photos"),
                .linkedFramework("AVFoundation"),
                .linkedFramework("MediaPlayer"),
            ]
        ),

        // ---- AudienceLink ----
        .target(
            name: "BDLiveAudienceLinkWrapper",
            dependencies: [
                "BDLiveAudienceLinkBinary",
                "BDLiveViewerCoreWrapper",
            ],
            path: "Sources/BDLiveAudienceLinkWrapper",
            resources: [
                .copy("Resources/BDLAudienceLinkAssert.bundle"),
                .copy("Resources/BDLAudienceLinkLanguage.bundle"),
            ]
        ),

        // ---- Viewer (带 RTC + 连麦) ----
        .target(
            name: "BDLiveViewerWrapper",
            dependencies: [
                "BDLiveAudienceLinkWrapper",
                .product(name: "TTSDK_LivePull-RTS", package: "TTSDK_BytePlus_SPM"),
                .product(name: "TTSDK_Player", package: "TTSDK_BytePlus_SPM"),
                .product(name: "TTSDK_LivePush", package: "TTSDK_BytePlus_SPM"),
                // "VolcEngineRTCBinary",
                "BytePlusRTCBinary",
                "ByteRTCFFmpegAudioExtensionBinary",
            ],
            path: "Sources/BDLiveViewerWrapper"
        ),

        // ---- ViewerWithoutRTC ----
        .target(
            name: "BDLiveViewerWithoutRTCWrapper",
            dependencies: [
                "BDLiveViewerCoreWrapper",
                .product(name: "TTSDK_LivePull", package: "TTSDK_BytePlus_SPM"),
                .product(name: "TTSDK_Player", package: "TTSDK_BytePlus_SPM"),
            ],
            path: "Sources/BDLiveViewerWithoutRTCWrapper"
        ),

        // ---- VodPlayer ----
        // .target(
            // name: "BDLiveVodPlayerWrapper",
            // dependencies: [
                // "BDLiveVodPlayerBinary",
                // "BDLiveBaseWrapper",
                // "BDLivePullBaseWrapper",
                // .product(name: "TTSDK_Player", package: "TTSDK_BytePlus_SPM"),
            // ],
            // path: "Sources/BDLiveVodPlayerWrapper"
        // ),

        // ---- LiveStreamingCore ----
        .target(
            name: "BDLiveLiveStreamingCoreWrapper",
            dependencies: [
                "BDLiveLiveStreamingCoreBinary",
                "BDLiveCommonWrapper",
                "BytedEffectSDKBinary",
            ],
            path: "Sources/BDLiveLiveStreamingCoreWrapper",
            resources: [
                .copy("Resources/BDLLiveStreamingImageResource.bundle"),
                .copy("Resources/BDLLanguageStreaming.bundle"),
                .copy("Resources/BDLLiveStreamingAudioResource.bundle"),
            ],
            linkerSettings: [
                .linkedFramework("Accelerate"),
                .linkedFramework("AssetsLibrary"),
                .linkedFramework("AVFoundation"),
                .linkedFramework("CoreGraphics"),
                .linkedFramework("CoreImage"),
                .linkedFramework("CoreMedia"),
                .linkedFramework("CoreVideo"),
                .linkedFramework("QuartzCore"),
                .linkedFramework("CoreMotion"),
                .linkedFramework("GLKit"),
                .linkedFramework("Metal"),
                .linkedFramework("MetalPerformanceShaders"),
                .linkedFramework("Photos"),
                .linkedFramework("CoreML"),
                .linkedFramework("PhotosUI"),
                .linkedLibrary("stdc++"),
                .linkedLibrary("z"),
            ]
        ),

        // ---- ScreenShareRTC (主 App 侧) ----
        .target(
            name: "BDLiveScreenShareRTCWrapper",
            dependencies: [
                "BDLiveScreenShareRTCBinary",
                "BDLiveLiveStreamingCoreWrapper",
            ],
            path: "Sources/BDLiveScreenShareRTCWrapper"
        ),

        // ---- LiveStreaming (带 RTC + 屏幕共享) ----
        .target(
            name: "BDLiveLiveStreamingWrapper",
            dependencies: [
                "BDLiveScreenShareRTCWrapper",
                .product(name: "TTSDK_LivePush", package: "TTSDK_BytePlus_SPM"),
                // "VolcEngineRTCBinary",
                "BytePlusRTCBinary",
                "ByteRTCFFmpegAudioExtensionBinary",
            ],
            path: "Sources/BDLiveLiveStreamingWrapper"
        ),

        // ---- LiveStreamingWithoutRTC ----
        .target(
            name: "BDLiveLiveStreamingWithoutRTCWrapper",
            dependencies: [
                "BDLiveLiveStreamingCoreWrapper",
                .product(name: "TTSDK_LivePush", package: "TTSDK_BytePlus_SPM"),
            ],
            path: "Sources/BDLiveLiveStreamingWithoutRTCWrapper"
        ),

        // ---- ScreenShare (Broadcast Upload Extension) ----
        // CN 版使用 VolcEngineRTC，SG 版使用 BytePlusRTC
        // 默认 CN 版；SG 版需用户手动切换依赖
        .target(
            name: "BDLiveScreenShareWrapper",
            dependencies: [
                // "VolcEngineRTCScreenCaptureBinary",
                "BytePlusRTCScreenCapturerBinary",
            ],
            path: "Sources/BDLiveScreenShareWrapper"
        ),
    ]
)
