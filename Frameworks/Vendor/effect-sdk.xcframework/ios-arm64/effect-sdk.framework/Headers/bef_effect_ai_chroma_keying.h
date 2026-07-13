#ifndef ANDROIDDEMO_BEF_EFFECT_AI_CHROMA_KEYING_H
#define ANDROIDDEMO_BEF_EFFECT_AI_CHROMA_KEYING_H

#if defined(__ANDROID__) || defined(TARGET_OS_ANDROID)
#include <jni.h>
#endif

#include "bef_effect_ai_public_define.h"

/**
 * @brief 输出结果
 *
 */
typedef struct
{
    int width;
    int height;
    unsigned char color_b;
    unsigned char color_g;
    unsigned char color_r;
    float color_h;
    float color_s;
    float color_v;
    uint8_t* mask;
    int outputTexture;
    int chromaKeyTexture;
} bef_ai_chroma_keying_ret;

typedef struct {
    int width;
    int height;
    unsigned char color_b;
    unsigned char color_g;
    unsigned char color_r;
    float color_h;
    float color_s;
    float color_v;
    uint8_t *mask;
} bef_ai_chroma_keying_algorithm_buffer_ret;

typedef struct {
    unsigned int outputTexture;
    unsigned int chromaKeyTexture;
} bef_ai_chroma_keying_process_texture_ret;

/**
 * @brief 参数枚举
 *
 */
typedef enum {
    BEF_AI_CHROMA_KEYING_METHOD = 0,    // 算法key, int。
                                        // 可选值有：0: 移动端实时方案【推荐默认】
                                        //         1: 服务端方案
    BEF_AI_CHROMA_KEYING_CAL_COLOR = 1, // 算法背景色计算key, int。
                                        // 可选值有：0：全图自动主色提取
                                        //         1： 绿幕场景精细化主色提取【默认】
                                        //         ∂2：人工设置主色提取（说明：该选项下返回变量的背景色彩为人工设置色彩）
    BEF_AI_CHROMA_KEYING_BG_R = 2,      // 背景色设置，红色，0～255【默认0】, int。
    BEF_AI_CHROMA_KEYING_BG_G = 3,      // 背景色设置，绿色，0～255【默认255】, int。
    BEF_AI_CHROMA_KEYING_BG_B = 4,      // 背景色设置，蓝色，0～255【默认0】, int。
    BEF_AI_CHROMA_KEYING_BALP = 5,      // 强度调节，float。
                                        // 色彩范围参数 case1: 小于0，自动模式，chroma_keying_cal_color为“1”时候推荐，如【默认-1】
                                        //            case2: 0～1，手动模式，chroma_keying_cal_color为“2”时候推荐设置为0.6～0.7
    BEF_AI_CHROMA_KEYING_KALP = 6,      // 强度调节：锐利度参数【推荐0.15】，建议不调节，float。
    BEF_AI_CHROMA_KEYING_SMOOTH = 7,    // 平滑系数，float。
                                        // case1:小于0时无平滑
                                        // case2:0 仅启用mask时序平滑，估色无时序平滑【推荐0】
                                        // case3:0～1 启用mask时序平滑，参数描述背景色估计平滑下强度（算法内部限制最大为1）
    BEF_AI_CHROMA_KEYING_SHARPEN = 8,   // mask边界锐化key，int。
                                        // 可选有： <=0: 不启用边界锐化
                                        //         >=1: 启用边界锐化【推荐设置为1】
    BEF_AI_CHROMA_KEYING_GET_MASK = 9,  // mask计算并返回，int。
                                        // 可选有：<=0: 不返回mask（仅获得背景色彩估计）
                                        //        >=1: 计算mask，同时获得背景色估计和背景色估值【默认请设1】
} bef_ai_chroma_keying_param_type;

bef_effect_result_t ChromaKeying_ReleaseHandle(bef_effect_handle_t handle);

BEF_SDK_API
bef_effect_result_t bef_effect_ai_chroma_keying_create(bef_effect_handle_t *handle);

BEF_SDK_API
bef_effect_result_t bef_effect_ai_chroma_keying_init(bef_effect_handle_t handle, const char *modelPath);

BEF_SDK_API
bef_effect_result_t bef_effect_ai_chroma_keying_detect(bef_effect_handle_t handle,
                                                       const unsigned char *image,
                                                       bef_ai_pixel_format pixel_format,
                                                       int image_width,
                                                       int image_height,
                                                       int image_stride,
                                                       bef_ai_rotate_type orientation,
                                                       bef_ai_chroma_keying_ret *result,
                                                       bool autoColor);

BEF_SDK_API
bef_effect_result_t bef_effect_ai_chroma_keying_algorithm_buffer(bef_effect_handle_t handle,
                                                                 const unsigned char *image,
                                                                 bef_ai_pixel_format pixel_format,
                                                                 int image_width,
                                                                 int image_height,
                                                                 int image_stride,
                                                                 bef_ai_rotate_type orientation,
                                                                 bef_ai_chroma_keying_algorithm_buffer_ret *result);

BEF_SDK_API
bef_effect_result_t bef_effect_ai_chroma_keying_process_texture(bef_effect_handle_t handle,
                                                                unsigned int srcTexture,
                                                                int image_width,
                                                                int image_height,
                                                                bef_ai_chroma_keying_algorithm_buffer_ret algorithm_ret,
                                                                bef_ai_chroma_keying_process_texture_ret *result);

typedef enum{
    BEF_AI_CHROMA_KEYING_UNIFORM_COLOR = 0,         // COLOR：[0,360]，算法会自动调色，可以手动更改微调绿幕主色
    BEF_AI_CHROMA_KEYING_UNIFORM_INTENSITY = 1,     // INTENSITY：[0,1]，抠图强度，以COLOR为中心，影响抠除色域的范围
    BEF_AI_CHROMA_KEYING_UNIFORM_SPILL = 2,         // SPILL：[0,1]，去溢色能力，对于绿幕，会把前景里泛绿的颜色矫正
    BEF_AI_CHROMA_KEYING_UNIFORM_EDGE_SMOOTH = 3,   // EDGE_SMOOTH：[0,1]，边缘平滑能力，适当的值可以去锯齿，值过大可能会导致前景模糊
    BEF_AI_CHROMA_KEYING_UNIFORM_DETAIL = 4,        // DETAIL：[0,1]，细节增强能力，0为通用方案，1为精细方案，之间进行效果加权
    BEF_AI_CHROMA_KEYING_UNIFORM_SHADOW = 5,         // SHADOW：[0,1]，阴影增强能力，可用于保留阴影
    BEF_AI_CHROMA_KEYING_UNIFORM_CONTRAST = 6,      // CONTRAST: [0,1]，对比度
    BEF_AI_CHROMA_KEYING_UNIFORM_BRIGHTNESS = 7,    // BRIGHTNESS: [0,1]，亮度
    BEF_AI_CHROMA_KEYING_UNIFORM_OPACITY = 8,       // OPACITY: [0, 1], 透明度
}bef_ai_chroma_keying_uniform_type;

BEF_SDK_API
void bef_effect_ai_chroma_keying_set_processParam(bef_effect_handle_t handle, bef_ai_chroma_keying_uniform_type uniformType, float value);

BEF_SDK_API
bef_effect_result_t bef_effect_ai_chroma_keying_set_paramF(bef_effect_handle_t handle, bef_ai_chroma_keying_param_type type, float value);

BEF_SDK_API
bef_effect_result_t bef_effect_ai_chroma_keying_set_paramI(bef_effect_handle_t handle, bef_ai_chroma_keying_param_type type, int value);

BEF_SDK_API
bef_effect_result_t bef_effect_ai_chroma_keying_release(bef_effect_handle_t handle);

/**
 * @brief 绿幕抠图授权
 * @param [in] handle Created skeleton detect handle
 *                    已创建的绿幕抠图句柄
 * @param [in] license 授权文件字符串
 * @param [in] length  授权文件字符串长度
 * @return If succeed return BEF_RESULT_SUC, other value please refer bef_effect_ai_public_define.h
 *         成功返回 BEF_RESULT_SUC, 授权码非法返回 BEF_RESULT_INVALID_LICENSE ，其它失败返回相应错误码, 具体请参考 bef_effect_ai_public_define.h
 */

BEF_SDK_API
bef_effect_result_t bef_effect_ai_chroma_keying_check_license(bef_effect_handle_t handle, const char *licensePath);

BEF_SDK_API
bef_effect_result_t bef_effect_ai_chroma_keying_check_online_license(bef_effect_handle_t handle, const char *licensePath);

#endif //ANDROIDDEMO_BEF_EFFECT_AI_SKIN_SEGMENTATION_H
