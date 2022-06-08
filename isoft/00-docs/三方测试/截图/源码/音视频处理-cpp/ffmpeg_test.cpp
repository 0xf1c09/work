#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#ifdef __cplusplus
extern "C" { 
#endif
	int audio_record(int argc, char** argv);
	int video_record(int argc, char** argv);
	int encoding_audio(int argc, char** argv);
	int encoding_video(int argc, char** argv);
	int demuxing_decoding(int argc, char** argv);
	int encoding_muxing(int argc, char** argv);
#ifdef __cplusplus
}
#endif

void profile(){
	printf("audio_record 音频采集\n");
	printf("video_record 视频采集\n");
	printf("encoding_audio 音频编码，生成一个音频\n");
	printf("encoding_video 视频编码，生成一个视频\n");
	printf("demuxing_decoding 将视频分离为音频和视频\n");
	printf("encoding_muxing 合成带视频和音频的视频\n");
}

int main(int argc, char ** argv)
{
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <测试项名称>\n", argv[0]);
		profile();
		return 0;
	}

	if(!strcmp( argv[1], "audio_record")){
		printf("%s\n", "音频采集");
		return audio_record(argc, argv);
	}
	else if(!strcmp( argv[1], "video_record")){
		printf("%s\n", "视频采集");
		return video_record(argc, argv);
	}
	else if(!strcmp( argv[1],"encode_audio")){
		printf("%s\n", "音频编码");
		return encoding_audio(argc, argv);
	}
	else if(!strcmp( argv[1],"encode_video")){
		printf("%s\n", "视频编码");
		return encoding_video(argc, argv);
	}
	else if(!strcmp( argv[1],"demuxing_decoding")){
		printf("%s\n", "音视频分离");
		return demuxing_decoding(argc, argv);
	}
	else if(!strcmp( argv[1],"encoding_muxing")){
		printf("%s\n", "合成视频");
		return encoding_muxing(argc, argv);
	}
	else{
		profile();
	}

	return 0;
}
