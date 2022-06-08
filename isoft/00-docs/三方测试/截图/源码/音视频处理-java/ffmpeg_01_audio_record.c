#include <stdio.h>
#include "libavutil/avutil.h"
#include "libavdevice/avdevice.h"  //打开音频设备相关的头文件
#include "libavformat/avformat.h"  //ffmpeg下的所有文件都是以格式来呈现的


int audio_record(int argc, char **argv)
{
	if (argc != 3) {
		fprintf(stderr, "Usage: %s <采集设备> <文件名称>\n"
				"%s default audio.pcm\n"
				"%s hw:0 audio.pcm\n",
				argv[0], argv[0], argv[0]);
		exit(1);
	}
	int ret = 0;
	char errors[1024] = {0};
	//context
	AVFormatContext *fmt_ctx = NULL;   //ffmpeg下的“文件描述符”

	//paket
	int count = 0;
	AVPacket pkt;

	//create file
	char *out = argv[2];
	FILE *outfile = fopen(out,"wb+");

	char *devicename = argv[1];
	//register audio device
	avdevice_register_all();

	//get format
	AVInputFormat *iformat = av_find_input_format("alsa");

	//open audio
	if( (ret = avformat_open_input(&fmt_ctx, devicename, iformat, NULL)) < 0)
	{
		av_strerror(ret, errors, 1024);
		printf("Failed to open audio device, [%d]%s\n", ret, errors);
		return 0;
	};

	av_init_packet(&pkt);
	//read data form audio
	while(ret = (av_read_frame(fmt_ctx, &pkt))== 0&& 
			count++ < 300) {
		av_log(NULL, AV_LOG_INFO, "pkt size is %d（%p）, count=%d\n",
				pkt.size, pkt.data, count);
		fwrite(pkt.data, 1, pkt.size, outfile);
		fflush(outfile);
		av_packet_unref(&pkt);//release pkt
	}

	fclose(outfile);
	avformat_close_input(&fmt_ctx);//releas ctx
        printf("Play the output audio file with the command:\n"
               "ffplay -f s16le -ac 2 -ar 44100 %s\n",
               out);
	return 0;
}

