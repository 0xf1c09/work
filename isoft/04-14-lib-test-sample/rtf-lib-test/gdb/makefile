CC = gcc
CPP = g++
C_FLAGS = -g
INCLUDE = 
LIBS = 

C_SRCS := $(wildcard ./libcfg/gdb/*.c)
C_TARGET  :=$(patsubst %.c, %, $(C_SRCS))
CPP_SRCS := $(wildcard ./libcfg/gdb/*.cpp)
CPP_TARGET  := $(patsubst %.cpp, %, $(CPP_SRCS))
OBJDIR = ../../test_bin/gdb

.c:
	$(CC) $(C_FLAGS) -o $@ $< $(INCLUDE) $(LIBS)
.cpp:
	$(CPP) $(C_FLAGS) -o $@ $< $(INCLUDE) $(LIBS)
all: $(C_TARGET) $(CPP_TARGET)
clean:
	rm -rf $(OBJDIR) $(C_TARGET) $(CPP_TARGET)


