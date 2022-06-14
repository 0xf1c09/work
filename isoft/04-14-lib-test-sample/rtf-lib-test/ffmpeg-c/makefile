CC = gcc
CPP = g++
C_FLAGS = 
INCLUDE = 
LIBS = -lavdevice -lavformat -lavfilter -lavcodec -lswresample -lswscale -lavutil -lm 
C_SRCS := $(wildcard *.c)
C_TARGET  := $(patsubst %.c, %, $(C_SRCS))
CPP_SRCS := $(wildcard *.cpp)
CPP_TARGET  := $(patsubst %.cpp, %, $(CPP_SRCS))
OBJDIR = ../../test_bin/ffmpeg-c

.c:
	$(CC) $(C_FLAGS) -o $@ $< $(INCLUDE) $(LIBS)

.cpp:
	$(CPP) $(C_FLAGS) -o $@ $< $(INCLUDE) $(LIBS)

all: $(C_TARGET) $(CPP_TARGET)

clean:
	rm $(C_TARGET) $(CPP_TARGET)

