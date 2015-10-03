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
CXX?=clang++# clang++, g++, etc.
CXXFLAGS?=$(WFLAGS)	-std=c++11 -pthread \
	$(shell pkg-config --cflags python3)
	# -I$(shell octave-config -p INCLUDEDIR)

LIBS?=$(shell pkg-config --libs python3 sfml-graphics)\
	 -lboost_system -lpthread -lGL -lGLU -lGLEW
	 # -L$(shell octave-config -p LIBDIR)
TARGET?=spide

INCLUDES=$(INCDIR)utilities.hpp\
		 $(INCDIR)main.hpp\
		 $(INCDIR)ioq.hpp\
		 $(INCDIR)net.hpp\
		 $(INCDIR)graphics.hpp
SRCS=$(SRCDIR)main.cpp\
	 $(SRCDIR)graphics.cpp
OBJS=$(OBJDIR)main.o\
	 $(OBJDIR)ioq.o\
	 $(OBJDIR)graphics.o
PROGRAM=$(BINDIR)$(TARGET)

all:$(PROGRAM)

$(OBJDIR)%.o:$(SRCDIR)%.cpp $(INCLUDES)
	@echo Compiling $@
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(PROGRAM):$(OBJS)
	@echo Linking $(PROGRAM)
	$(CXX) -o $(PROGRAM) $(OBJS) $(LIBS)

check:
	@echo "TODO: Check dependencies"
	@gcc --version

clean:
	@echo Cleaning $(PROGRAM) $(OBJS)
	@rm -f $(PROGRAM) $(OBJS) 

do:$(PROGRAM)
	@echo "Running" $(PROGRAM)
	@$(PROGRAM)

.PHONY: all clean check install do
