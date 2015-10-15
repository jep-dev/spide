# Discovery paths for sources and headers
INCDIR=./include/
SRCDIR=./source/
OBJDIR=./objects/
BINDIR=./build/

vpath %.cpp $(SRCDIR)
vpath   %.c $(SRCDIR)
vpath %.hpp $(INCDIR)
vpath   %.h $(INCDIR)

# CSFML?=
CSFML_SRC?=../CSFML/include/
CSFML_LIB?=/usr/lib/x86_64-linux-gnu/

WFLAGS?=
SHELL?=shell
TARGET?=x86_64-linux-gnu

RM?=rm

#ifeq "$(OS)" "Windows_NT"
#	# Windows, assume 32-bit
#	LDFLAGS?=-lopengl32 -lglu32 -lcsfml32
#	EXE?=$(BINDIR)spide.exe
#else #assume Linux
#endif

LDFLAGS?=-lpthread -lGL -lGLU \
	-L$(CSFML_LIB) -lcsfml-graphics
EXE?=$(BINDIR)spide

CC?=gcc
CXX?=clang++
CFLAGS?=-g -pthread -I$(CSFML_SRC)
CXXFLAGS?=$(WFLAGS) -pthread -I$(CSFML_SRC)

CC_PROXY?=$(CC)
CC_PROXY_FLAGS?=$(CFLAGS)

INCS=util.h log.h streams.h net.h\
	view.h main.h

SRCS=log.c streams.c net.c\
	 view.c main.c

OBJS=$(OBJDIR)log.o\
	$(OBJDIR)streams.o\
	$(OBJDIR)net.o\
	$(OBJDIR)view.o\
	$(OBJDIR)main.o

all:$(EXE)

$(OBJDIR)%.o:$(SRCDIR)%.c $(INCS)
	@echo Compiling $@
	$(CC_PROXY) $(CC_PROXY_FLAGS) -c -o $@ $<

$(EXE):$(OBJS)
	@echo Linking $(EXE)
	$(CC_PROXY) $(OBJS) -o $(EXE) $(LDFLAGS)

check:
	@echo "TODO: Check dependencies"
	@$(CC) --version
	@$(CXX) --version

clean:
	@echo Cleaning $(EXE) $(OBJS)
	@$(RM) -f $(EXE) $(OBJS) 

do:$(EXE)
	@echo "Running $(EXE)"
	@$(EXE)

.PHONY: all clean check install do
