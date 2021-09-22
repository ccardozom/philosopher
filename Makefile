NAME = philo

SRCS_DIR = ./
OBJ_DIR = obj/
INCLUDE = -I./includes/
CXX = gcc
CFLAGS = -Wall -Werror -Wextra -g $(INCLUDE)
LPTHREAD = -lpthread
RM = rm -rf

SOURCES = $(wildcard $(SRCS_DIR)*.c)
OBJS = $(addprefix $(OBJ_DIR), $(notdir $(SOURCES:.c=.o)))

all: $(NAME)

$(NAME): $(OBJS)
	@echo Creando1 $@... con $^
	$(CXX) $(CFLAGS) $(OBJS) -o $@ $(LPTHREAD) 

$(OBJ_DIR)%.o: %.c
	@echo Creando2 $@... con $^
	$(CXX) $(CFLAGS) -c $< -o $@

.PHONY: all clean

clean:
	@echo Limpiando...
	$(RM) $(OBJ_DIR)*
	$(RM) $(NAME)

re:		clean $(NAME)