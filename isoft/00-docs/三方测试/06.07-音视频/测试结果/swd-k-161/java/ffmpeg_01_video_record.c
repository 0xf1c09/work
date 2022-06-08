#include <stdio.h>
#include "libavutil/avutil.h"
#include "libavdevice/avdevice.h"
#include "libavformat/avformat.h"
#include "libavcodec/avcodec.h"

#define V_WIDTH 640
#define V_HEIGHT 480

//@brief
//return
static AVFormatContext* open_dev(char *devicename){
	int ret = 0;
	char errors[1024] = {0, };

	//ctx
	AVFormatContext *fmt_ctx = NULL;
	AVDictionary *options = NULL;

	//register audio device
	avdevice_register_all();

	//get format
	AVInputFormat *iformat = av_find_input_format("video4linux2");

	char video_size[100];
	sprintf(video_size, "%dx%d", V_WIDTH, V_HEIGHT);
	av_dict_set(&options,"video_size", video_size, 0);
	av_dict_set(&options,"pixel_format","yuyv422", 0);

	//open device
	if((ret = avformat_open_input(&fmt_ctx, devicename, iformat, &options)) < 0 ){
		av_strerror(ret, errors, 1024);
		fprintf(stderr, "Failed to open audio device, [%d]%s\n", ret, errors);
		return NULL;
	}

	return fmt_ctx;
}
static AVFrame *create_frame(int width, int height) {
    int ret = 0;
    AVFrame *frame = NULL;

    frame = av_frame_alloc();
    if (!frame) {
        printf("Error, No Memory!\n");
        goto __ERROR;
    }

    //设置参数
    frame->width = width;
    frame->height = height;
    frame->format = AV_PIX_FMT_YUV420P;

    // alloc inner memory
    ret = av_frame_get_buffer(frame, 32); //按 32 位对齐
    if (ret < 0) {
        printf("Error, Failed to alloc buffer for frame!\n");
        goto __ERROR;
    }

    return frame;

__ERROR:
    if (frame) {
        av_frame_free(&frame);
    }

    return NULL;
}

void yuyv422ToYuv420p(AVFrame *frame, AVPacket *pkt) {
    int i = 0;
    int yuv422_length = V_WIDTH * V_HEIGHT * 2;
    int y_index = 0;
    // copy all y
    for (i = 0; i < yuv422_length; i += 2) {
        frame->data[0][y_index] = pkt->data[i];
        y_index++;
    }

    // copy u and v
    int line_start = 0;
    int is_u = 1;
    int u_index = 0;
    int v_index = 0;
    // copy u, v per line. skip a line once
    for (i = 0; i < V_HEIGHT; i += 2) {
        // line i offset
        line_start = i * V_WIDTH * 2;
        for (int j = line_start + 1; j < line_start + V_WIDTH * 2; j += 4) {
            frame->data[1][u_index] = pkt->data[j];
            u_index++;
            frame->data[2][v_index] = pkt->data[j + 2];
            v_index++;
        }
    }
}

void rec_video(char *devicename, char *filename) {
	int ret = 0;
	AVFormatContext *fmt_ctx = NULL;
	int count = 0;

	//pakcet
	AVPacket pkt;

	//set log level
	av_log_set_level(AV_LOG_DEBUG);

	//create file
	FILE *outfile = fopen(filename, "wb+");

	//打开设备
	fmt_ctx = open_dev(devicename);

	//创建 AVFrame
	AVFrame *frame = create_frame(V_WIDTH, V_HEIGHT);

	//read data from device
	while((ret = av_read_frame(fmt_ctx, &pkt)) == 0 &&
			count++ < 100) {
		av_log(NULL, AV_LOG_INFO,
				"packet size is %d(%p)\n",
				pkt.size, pkt.data);
		yuyv422ToYuv420p(frame, &pkt);

		fwrite(frame->data[0], 1, V_WIDTH * V_HEIGHT , outfile);
		fwrite(frame->data[1], 1, V_WIDTH * V_HEIGHT / 4, outfile);
		fwrite(frame->data[2], 1, V_WIDTH * V_HEIGHT / 4, outfile);

		//fwrite(pkt.data, 1, pkt.size, outfile); //614400
		fflush(outfile);
		av_packet_unref(&pkt); //release pkt
	}

__ERROR:
	if(outfile){
		//close file
		fclose(outfile);
	}

	//close device and release ctx
	if(fmt_ctx) {
		avformat_close_input(&fmt_ctx);
	}

	av_log(NULL, AV_LOG_DEBUG, "finish!\n");
	return;
}


int video_record(int argc, char *argv[])
{
	if (argc != 3) {
		fprintf(stderr, "Usage: %s <摄像头设备> <文件名称>\n"
				"%s /dev/video0 video.yuv\n",
				argv[0], argv[0]);
		exit(1);
	}

	rec_video(argv[1], argv[2]);
        printf("Play the output video file with the command:\n"
			"ffplay -f rawvideo -pix_fmt yuv420p -video_size %dx%d %s\n",
			V_WIDTH, V_HEIGHT, argv[2]);
	return 0;
}


