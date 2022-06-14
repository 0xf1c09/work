CC = gcc
INCLUDE = 
TARGET = libffmpeg.so
C_FLAGS = -shared -fpic
LIBS = -lavdevice -lavformat -lavfilter -lavcodec -lswresample -lswscale -lavutil -lm 
C_SRCS := $(wildcard *.c)

all: $(TARGET)
$(TARGET):
	${CC} $(C_SRCS) $(LIBS) $(C_FLAGS) -o $@

clean:
	rm -rf $(TARGET)
