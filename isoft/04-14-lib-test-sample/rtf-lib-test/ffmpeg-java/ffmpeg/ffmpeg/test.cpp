#include <iostream>
using namespace std;

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

int main(int argc, char ** argv)
{
	printf("1: int audio_capture(int argc, char** argv);\n");
	printf("2: int video_capture(int argc, char** argv);\n");
	printf("3: int encode_audio(int argc, char** argv);\n");
	printf("4: int encode_video(int argc, char** argv);\n");
	printf("5: int decode_audio(int argc, char** argv);\n");
	printf("6: int decode_video(int argc, char** argv);\n");
	printf("7: int audio_capture(int argc, char** argv);\n");
	printf("8: int audio_capture(int argc, char** argv);\n");
	printf("9: int audio_capture(int argc, char** argv);\n");
	printf("10: int audio_capture(int argc, char** argv);\n");
	printf("11: int audio_capture(int argc, char** argv);\n");
	int i;
	cin>>i;
	switch(i){
		case 1:
			audio_capture(argc,  argv);
			break;
		case 2:
			video_capture(argc,  argv);
			break;
		case 3:
			encode_audio(argc,  argv);
			break;
		case 4:
			encode_video(argc, argv);
			break;
		case 5:
			decode_audio(argc, argv);
			break;
		case 6:
			decode_video(argc, argv);
			break;
		case 7:
			demuxing_decoding(argc, argv);
			break;
		case 8:
			muxing(argc, argv);
			break;
		case 9:
			remuxing(argc, argv);
			break;
		case 10:
			transcode_aac(argc, argv);
			break;
		case 11:
			transcoding(argc, argv);
			break;
	}
	return 0;
}
