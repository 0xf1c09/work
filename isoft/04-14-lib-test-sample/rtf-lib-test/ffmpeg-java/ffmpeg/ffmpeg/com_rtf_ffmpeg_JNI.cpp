#include "com_rtf_ffmpeg_JNI.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#ifdef __cplusplus
extern "C" { 
#endif
	int audio_capture(int argc, char** argv);
	int video_capture(int argc, char** argv);
	int encode_audio(int argc, char** argv);
	int encode_video(int argc, char** argv);
	int decode_audio(int argc, char** argv);
	int decode_video(int argc, char** argv);
	int demuxing_decoding(int argc, char** argv);
	int muxing(int argc, char** argv);
	int remuxing(int argc, char** argv);
	int transcode_aac(int argc, char** argv);
	int transcoding(int argc, char** argv);
#ifdef __cplusplus
}
#endif
JNIEXPORT jint JNICALL Java_JNI_invokeMethod
  (JNIEnv *env, jobject obj, jint argc, jobjectArray argv)
{
    // the result array
    char** array;

    // get array value
    int i;
    jsize len = env->GetArrayLength(argv);
    array = (char**)malloc(sizeof(char*) * (len));
    for(i = 0; i < len; i++)
    {
        // get arguments value from java
        jobject str = env->GetObjectArrayElement(argv, i);
        const char* value = env->GetStringUTFChars((jstring)str, 0);
        char* c = const_cast<char*>(value);
        array[i] = c;
    }
    if(!strcmp(array[0], "audio_capture")){
	    printf("%s\n", "音频采集");
	    return audio_capture(len, array);
    }
    else if(!strcmp(array[0], "video_capture")){
	    printf("%s\n", "视频采集");
	    return video_capture(len, array);
    }
    else if(!strcmp(array[0],"encode_audio")){
	    printf("%s\n", "音频编码");
	    return encode_audio(len, array);
    }
    else if(!strcmp(array[0],"encode_video")){
	    printf("%s\n", "视频编码");
	    return encode_video(len, array);
    }
    else if(!strcmp(array[0],"decode_audio")){
	    printf("%s\n", "音频解码");
	    return decode_audio(len, array);
    }
    else if(!strcmp(array[0],"decode_video")){
	    printf("%s\n", "视频解码");
	    return decode_video(len, array);
    }
    else if(!strcmp(array[0],"demuxing_decoding")){
	    printf("%s\n", "音视频分离");
	    return demuxing_decoding(len, array);
    }
    else if(!strcmp(array[0],"muxing")){
	    printf("%s\n", "合成视频");
	    return muxing(len, array);
    }
    else if(!strcmp(array[0],"remuxing")){
	    printf("%s\n", "不带编解码的视频格式转换");
	    return remuxing(len, array);
    }
    else if(!strcmp(array[0], "transcode_aac")){
	    printf("%s\n", "音频格式转换");
	    int result = transcode_aac(len, array);
	    return result;
    }
    else if(!strcmp(array[0],"transcoding")){
	    printf("%s\n", "带编解码的视频格式转换");
	    int result = transcoding(len, array);
	    return result;
    }
    else{
    	printf("audio_capture 音频采集\n");
    	printf("video_capture 视频采集\n");
    	printf("encode_audio 音频编码，生成一个音频\n");
    	printf("encode_video 视频编码，生成一个视频\n");
    	printf("decode_audio 音频解码，将上面编码的音频进行解码，生成解码后的音频\n");
    	printf("decode_video 视频解码，将上面编码的视频进行解码，截取解码后视频的帧\n");
    	printf("demuxing_decoding 将视频分离为音频和视频\n");
    	printf("muxing 合成带视频和音频的视频\n");
    	printf("remuxing 视频格式转换\n");
    	printf("transcode_aac 提取视频内音频并以aac格式保存\n");
    	printf("transcoding 视频格式转换\n");
    }
    return 0;

}
