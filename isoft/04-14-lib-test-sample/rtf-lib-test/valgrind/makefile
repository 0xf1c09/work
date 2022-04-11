CC = gcc
CPP = g++
C_FLAGS = 
INCLUDE = 
LIBS = 

C_SRCS := $(wildcard ./libcfg/valgrind/*.c)
C_TARGET  :=$(patsubst %.c, %, $(C_SRCS))
C_TARGETS  =$(notdir $(C_TARGET))

CPP_SRCS := $(wildcard ./libcfg/valgrind/*.cpp)
CPP_TARGET  := $(patsubst %.cpp, %, $(CPP_SRCS))
CPP_TARGETS  = $(notdir $(CPP_TARGET))
OBJDIR = ../../test_bin/valgrind

.c:
	$(CC) $(C_FLAGS) -o $@ $< $(INCLUDE) $(LIBS)
	mv $@ $(OBJDIR)
.cpp:
	$(CPP) $(C_FLAGS) -o $@ $< $(INCLUDE) $(LIBS)
	mv $@ $(OBJDIR)
all: $(C_TARGET) $(CPP_TARGET)
clean:
	rm -rf $(OBJDIR)
