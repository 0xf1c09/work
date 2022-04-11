# ace
## ace_test.cpp

# cjson

## cjson_test_01_json_package.c
json数据封装

## cjson_test_02_json_analysis.c
json数据解析+释放内存

# ffmpeg

## ffmpeg_test_01_avio_list_dir.c
初始化+读取文件夹信息

## ffmpeg_test_03_encode_audio.c
使用指定编码器对音频编码

## ffmpeg_test_04_encode_video.c
使用指定编码器对视频编码

## ffmpeg_test_05_decode_audio.c
使用指定编码器对音频解码

## ffmpeg_test_06_decode_video.c
使用指定编码器对视频解码

## ffmpeg_test_07_extract_mvs.c
获取帧的运动矢量数据

## ffmpeg_test_08_demuxing_decoding.c
对音视频数据进行解封装和解码

## ffmpeg_test_09_filtering_audio.c
对音频进行混音

## ffmpeg_test_10_filtering_video.c
对视频添加滤镜

## ffmpeg_test_11_metadata.c
获取文件的metadata信息并输出

## ffmpeg_test_12_muxing.c
制造音频和视频，并合成一个视频文件

## ffmpeg_test_13_remuxing.c
无编解码的转封装视音频文件

## ffmpeg_test_14_resampling_audio.c
音频重采样

## ffmpeg_test_15_scaling_video.c
对视频进行缩放

## ffmpeg_test_16_transcode_aac.c
将提供音频转码为AAC格式

## ffmpeg_test_17_transcoding.c
调用编解码和滤波器将提供视频转码为指定格式

# gdb
使用脚本自动对C/C++程序进行调试
使用GDB工具进入程序诊断模式
对函数设置断点，输出设置断点信息
运行程序，程序在函数断点处停止并等待gdb命令
单步进入，程序跟踪到函数内部，输出源码信息
打印基本类型变量，输出变量名对应的变量
退出程序诊断模式


# jdb
使用脚本自动对Java程序进行调试

# gstreamer

## gstreamer_test_01_get_version.c
获取gstreamer版本信息

## gstreamer_test_02_pipelines.c
直接创建管道播放视频

## gstreamer_test_03_elements.c
创建元件，放入管道中播放视频

## gstreamer_test_04_time_management.c
获取播放位置，执行跳播操作

## gstreamer_test_05_GUI_toolkit_integration.c
播放控制，使用gtk绘制ui

## gstreamer_test_06_media_information_gathering.c
快速找出文件或者URI所包含的媒体具体信息或者是否能够播放该媒体

# iniparser
## iniparser_test.c
ini文件解析库测试

# inotify-tools
## inotify_test.c
进行简单的文件系统变化通知、统计文件系统访问信息、初始化接口，返回成功、创建监控列表，将需要监控的文件或目录添加到可修改的监控列表内、针对监控列表的特定事件进行通知报告，执行时会对/tmp目录进行监控

# jsoncpp
## jsoncpp_test_01_json_read.cpp
工程内添加库+字符串解析为Json对象+读取Json字符流中Json对象

## jsoncpp_test_02_json_serialization.cpp
构建Json对象序列化为字符串

## jsoncpp_test_03_json_update.cpp
Json对象插入文件中+清空Json对象中的数组+删除Json对象

# libxml2

## libxml2_test_01_xml_analysis.c
解析xml文档查询xml文档关键词信息

## libxml2_test_02_xml_search.c
查询xml文档关键词信息

## libxml2_test_03_xml_update.c
修改xml文档内容

## libxml2_test_04_xml_create.cpp
创建xml文档

## libxml2_test_05_xml_encoding_update.c
修改xml文档编码

# pcre

## pcre_test.c
获取pcre版本信息、将正则表达式编译为库内部结构、获取编译好的模式信息、使用编译好的模式进行匹配，返回匹配串的偏移位置、释放不再需要已编译过的正则表达式，防止产生内存泄漏


# valgrind
## valgrind_test_01_base_test.cpp
对C/C++可执行程序进行基础诊断

## valgrind_test_02_uninit-mem.cpp
对未初始化内存的C/C++程序进行诊断

## valgrind_test_03_out_of_range.cpp
对内存读写越界的C/C++程序进行诊断

## valgrind_test_04_mem_cover.cpp
对内存覆盖的C/C++程序进行诊断

## valgrind_test_05_dynamic_mem_error.cpp
对动态内存管理错误的C/C++程序进行诊断

## valgrind_test_06_mem_leak.cpp
对内存泄露的C/C++程序进行诊断

