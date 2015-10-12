# Discovery paths for sources and headers
vpath %.cpp $(SRCDIR)
vpath   %.c $(SRCDIR)
vpath %.hpp $(INCDIR)
vpath   %.h $(INCDIR)

INCDIR=./include/
SRCDIR=./source/
OBJDIR=./objects/
BINDIR=./build/

# CSFML?=/usr/lib/x86_64-linux-gnu

WFLAGS?=
SHELL?=shell

TARGET?=spide 

CSFML?=/usr/lib/x86_64-linux-gnu/

CXX?=clang++
CXXFLAGS?=$(WFLAGS) -std=c++11 -pthread \
		  -I../CSFML/include/

CPP=gcc
CPPFLAGS?=$(WFLAGS)	-std=c1x -pthread \
		  -I../CSFML/include/
	# $(shell pkg-config --cflags sfml-graphics)

CC_PROXY?=$(CPP)
CC_PROXY_FLAGS?=$(CPPFLAGS)

LIBS?=-lpthread -lGL -lGLU -lGLEW \
	-lcsfml-graphics
	# -lsfml-system -lsfml-graphics
	# $(shell pkg-config --libs python3 sfml-graphics) 

INCS=$(INCDIR)util.h \
	$(INCDIR)streams.h \
	$(INCDIR)net.h \
	$(INCDIR)view.h \
	$(INCDIR)main.h 

SRCS=$(SRCDIR)net.c \
	$(SRCDIR)streams.c \
	$(SRCDIR)view.c \
	$(SRCDIR)main.c 

OBJS=$(OBJDIR)net.o \
	$(OBJDIR)streams.o \
	$(OBJDIR)view.o \
	$(OBJDIR)main.o 

PROGRAM=$(BINDIR)$(TARGET)

all:$(PROGRAM)

$(OBJDIR)%.o:$(SRCDIR)%.c $(INCs)
	@echo Compiling $@
	$(CC_PROXY) $(CC_PROXY_FLAGS) -c -o $@ $<

$(PROGRAM):$(OBJS)
	@echo Linking $(PROGRAM)
	$(CC_PROXY) $(OBJS) -o $(PROGRAM) $(LIBS)

check:
	@echo "TODO: Check dependencies"
	@$(CPP) --version
	@$(CXX) --version

clean:
	@echo Cleaning $(PROGRAM) $(OBJS)
	@rm -f $(PROGRAM) $(OBJS) 

do:$(PROGRAM)
	@echo "Running" $(PROGRAM)
	@$(PROGRAM)

.PHONY: all clean check install do
