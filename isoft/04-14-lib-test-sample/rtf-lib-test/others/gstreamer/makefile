CC = gcc
CPP = g++
LIBS = `pkg-config --cflags --libs gstreamer-1.0 gstreamer-video-1.0 gtk+-3.0 gstreamer-pbutils-1.0`
INCLUDE = 
C_FLAGS = 
C_SRCS := $(wildcard *.c)
C_TARGET  := $(patsubst %.c, %, $(C_SRCS))
CPP_SRCS := $(wildcard *.cpp)
CPP_TARGET  := $(patsubst %.cpp, %, $(CPP_SRCS))
OBJDIR = ../../test_bin/gstreamer

.c:
	$(CC) $(C_FLAGS) -o $@ $< $(INCLUDE) $(LIBS)
	mv $@ $(OBJDIR)
.cpp:
	$(CPP) $(C_FLAGS) -o $@ $< $(INCLUDE) $(LIBS)
	mv $@ $(OBJDIR)
all: $(C_TARGET) $(CPP_TARGET)
clean:
	rm -rf $(OBJDIR)
