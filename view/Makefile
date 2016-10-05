ECHO 		=	printf
CAT 		=	cat
RM      =	rm
FIND 		=	find
UNAME		= $(shell uname)
CPPFLAGS	=	-std=c++11 -ggdb -Wall -W -Wextra -Wno-unused-parameter -Wno-deprecated-declarations
LDFLAGS		=
CC   		= 	g++
LD   		= 	g++

SRCD = src
INCD = include -I/usr/include/ -I./GL -I. -I../include
OBJD = obj
BIND = bin
LIBD =
LIBS = -L/usr/X11/lib  -lGL -lGLU -lglut

EXEC 	=  interpol
SRCS	=  $(wildcard $(SRCD)/*.cpp)
OBJ		=  $(SRCS:.cpp=.o)
OBJS 	:= $(addprefix $(OBJD)/, $(notdir $(OBJ)))

default: $(BIND) $(OBJD) $(BIND)/$(EXEC)

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
