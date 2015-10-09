# Discovery paths for sources and headers
vpath %.cpp $(SRCDIR)
vpath   %.c $(SRCDIR)
vpath %.hpp $(INCDIR)
vpath   %.h $(INCDIR)

INCDIR=./include/
SRCDIR=./source/
OBJDIR=./objects/
BINDIR=./build/

WFLAGS?=-Wall
SHELL?=shell


## CXX?=clang++# clang++, g++, etc.
## CXXFLAGS?=$(WFLAGS)	-std=c++11 -pthread \
##	$(shell pkg-config --cflags python3)
##	# -I$(shell octave-config -p INCLUDEDIR)


CPP?=gcc# clang++, g++, etc.
CPPFLAGS?=$(WFLAGS)	-std=c1x -pthread \
	$(shell pkg-config --cflags python3)
	# -I$(shell octave-config -p INCLUDEDIR)

LIBS?=$(shell pkg-config --libs python3 sfml-graphics)\
	 -lboost_system -lpthread -lGL -lGLU -lGLEW
	 # -L$(shell octave-config -p LIBDIR)
TARGET?=spide

INCLUDES=$(INCDIR)util.h\
		 $(INCDIR)main.h\
		 $(INCDIR)ioq.h\
		 $(INCDIR)net.h\
		 $(INCDIR)gfx.h
SRCS=$(SRCDIR)main.c\
	 $(SRCDIR)gfx.p
OBJS=$(OBJDIR)main.o\
	 $(OBJDIR)ioq.o\
	 $(OBJDIR)gfx.o
PROGRAM=$(BINDIR)$(TARGET)

all:$(PROGRAM)

## $(OBJDIR)%.o:$(SRCDIR)%.cpp $(INCLUDES)
$(OBJDIR)%.o:%(SRCDIR)%.c $(INCLUDES)
	@echo Compiling $@
	$(CPP) $(CPPFLAGS) -c -o $@ $<
	## $(CXX) $(CXXFLAGS) -c -o $@ $<

$(PROGRAM):$(OBJS)
	@echo Linking $(PROGRAM)
	## $(CXX) -o $(PROGRAM) $(OBJS) $(LIBS)
	$(CPP) -o $(PROGRAM) $(OBJS) $(LIBS)

check:
	@echo "TODO: Check dependencies"
	@gcc --version
	## clang++ --version

clean:
	@echo Cleaning $(PROGRAM) $(OBJS)
	@rm -f $(PROGRAM) $(OBJS) 

do:$(PROGRAM)
	@echo "Running" $(PROGRAM)
	@$(PROGRAM)

.PHONY: all clean check install do
