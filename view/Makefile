ECHO 		=	printf
CAT 		=	cat
RM      =	rm
FIND 		=	find
UNAME		= $(shell uname)
CPPFLAGS	=	-std=c++11 -ggdb -Wall -W -Wextra -Wno-unused-parameter -Wno-deprecated-declarations
LDFLAGS		=
CC   		= 	g++
LD   		= 	g++

OS := $(shell uname)
ARCH := $(shell uname -m)

ifeq ($(OS), Linux)
  ifeq ($(ARCH), x86_64)
    LEAP_LIBRARY := ./LeapSDK/lib/x64/libLeap.so -Wl,-rpath,./LeapSDK/lib/x64
  else
    LEAP_LIBRARY := ./LeapSDK/lib/x86/libLeap.so -Wl,-rpath,./LeapSDK/lib/x86
  endif
else
  # OS X
  LEAP_LIBRARY := ./LeapSDK/lib/libLeap.dylib
endif

SRCD = src
INCD = include -I/usr/include/ -I./GL -I. -I../include -I./LeapSDK/include
OBJD = obj
BIND = bin
LIBD =
LIBS = -L/usr/X11/lib  -lGL -lGLU -lglut

EXEC 	=  interpol
SRCS	=  $(wildcard $(SRCD)/*.cpp)
OBJ		=  $(SRCS:.cpp=.o)
OBJS 	:= $(addprefix $(OBJD)/, $(notdir $(OBJ)))

default: $(BIND) $(OBJD) $(BIND)/$(EXEC)

ifeq ($(OS), Darwin)
				echo $(OS)
				install_name_tool -change @loader_path/libLeap.dylib LeapSDK/lib/libLeap.dylib $(BIND)/$(EXEC)
endif

$(BIND)/$(EXEC): $(OBJS)
	@$(ECHO) "Linking ..\n"
	$(LD) -o $@ $^ $(LDFLAGS) $(LIBD) $(LIBS) -Wl,-rpath ./

$(OBJD)/%.o: $(SRCD)/%.cpp
	@$(ECHO) "Compiling source file ..\n"
	$(CC) -o $@ -c $< $(CPPFLAGS) -I$(INCD)

$(OBJD):
	@mkdir -p $(OBJD)
$(BIND):
	@mkdir -p $(BIND)

clean:
	@$(FIND) $(OBJD) -name *.o -delete

mrproper: clean
	@$(RM) -f $(BIND)/$(EXEC)
	@$(RM) -rf $(OBJD) $(BIND)
