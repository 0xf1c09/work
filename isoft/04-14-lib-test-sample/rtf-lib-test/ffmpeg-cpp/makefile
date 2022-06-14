CC = gcc
CPP = g++ 
INCLUDE = 
TARGET = libffmpeg.so ffmpeg_test
C_FLAGS = -shared -fpic
LIBS = -lavdevice -lavformat -lavfilter -lavcodec -lswresample -lswscale -lavutil -lm 
C_SRCS := $(wildcard ./src/*.c)
CPP_SRCS := $(wildcard ./src/*.cpp)

all: $(TARGET)
libffmpeg.so:
	${CC} $(C_SRCS) $(LIBS) $(C_FLAGS) -o $@
ffmpeg_test:
	${CPP} $(CPP_SRCS) libffmpeg.so -o $@

clean:
	rm -rf $(TARGET)
