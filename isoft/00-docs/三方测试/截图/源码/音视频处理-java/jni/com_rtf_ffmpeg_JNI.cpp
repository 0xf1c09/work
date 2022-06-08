#include "com_rtf_ffmpeg_JNI.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#ifdef __cplusplus
extern "C" { 
#endif
        int audio_record(int len, char** array);
        int video_record(int len, char** array);
        int encoding_audio(int len, char** array);
        int encoding_video(int len, char** array);
        int demuxing_decoding(int len, char** array);
        int encoding_muxing(int len, char** array);
#ifdef __cplusplus
}
#endif
JNIEXPORT jint JNICALL Java_com_rtf_ffmpeg_JNI_invokeMethod
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
//    if(!strcmp(array[0], "audio_capture")){
//	    printf("%s\n", "音频采集");
//	    return audio_capture(len, array);
//    }
//    else if(!strcmp(array[0], "video_capture")){
//	    printf("%s\n", "视频采集");
//	    return video_capture(len, array);
//    }
    if(!strcmp( array[0], "audio_record")){
	    printf("%s\n", "音频采集");
	    return audio_record(len, array);
    }
    else if(!strcmp( array[0], "video_record")){
	    printf("%s\n", "视频采集");
	    return video_record(len, array);
    }
    else if(!strcmp( array[0],"encode_audio")){
	    printf("%s\n", "音频编码");
	    return encoding_audio(len, array);
    }
    else if(!strcmp( array[0],"encode_video")){
	    printf("%s\n", "视频编码");
	    return encoding_video(len, array);
    }
    else if(!strcmp( array[0],"demuxing_decoding")){
	    printf("%s\n", "音视频分离");
	    return demuxing_decoding(len, array);
    }
    else if(!strcmp( array[0],"encoding_muxing")){
	    printf("%s\n", "合成视频");
	    return encoding_muxing(len, array);
    }
    else{
	    printf("audio_record 音频采集\n");
	    printf("video_record 视频采集\n");
	    printf("encoding_audio 音频编码，生成一个音频\n");
	    printf("encoding_video 视频编码，生成一个视频\n");
	    printf("demuxing_decoding 将视频分离为音频和视频\n");
	    printf("encoding_muxing 合成带视频和音频的视频\n");
    }
    return 0;

}
