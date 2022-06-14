CC = gcc
CPP = g++
INCLUDE = 
TARGET = libffmpeg.so libffmpeg-jni.so
C_FLAGS = -shared -fpic
CPP_FLAGS = -I $(shell find /usr/lib/jvm/ -name java-*-openjdk-*|head -n 1)/include/ -I $(shell find /usr/lib/jvm/ -name java-*-openjdk-*|head -n 1)/include/linux/
LIBS = -lavdevice -lavformat -lavfilter -lavcodec -lswresample -lswscale -lavutil -lm 
C_SRCS := $(wildcard ./src/*.c)
CPP_SRCS := $(wildcard ./src/jni/*.cpp)

all: $(TARGET)
libffmpeg.so:
	${CC} $(C_SRCS) $(LIBS) $(C_FLAGS) -o $@
libffmpeg-jni.so:
	${CPP} $(CPP_SRCS) $(C_FLAGS) $(CPP_FLAGS) libffmpeg.so -o $@

clean:
	rm -rf $(TARGET)
