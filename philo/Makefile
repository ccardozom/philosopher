NAME = philo

SRCS_DIR = ./
OBJ_DIR = obj/
INCLUDE = -I./includes/
CXX = gcc
CFLAGS = -Wall -Werror -Wextra -g3  -fsanitize=address $(INCLUDE)
LPTHREAD = -lpthread
RM = rm -rf

SOURCES = 	check_argv.c \
			eating.c \
			ft_atoi.c \
			ft_isdigit.c \
			ft_strlen.c \
			ft_usleep.c \
			init_philo.c \
			init_thread.c \
			is_atoi.c \
			main.c \
			print_msj.c \
			print_wrong_text.c \
			routine.c \
			sleeping.c \
			time_ms.c \
			wrong_list.c

OBJS = $(addprefix $(OBJ_DIR), $(notdir $(SOURCES:.c=.o)))
CREATE_DIR = $(shell mkdir -p $(OBJ_DIR))

all: $(NAME)

$(NAME): $(CREATE_DIR) $(OBJS)
	@echo Creando1 $@... con $^
	$(CXX) $(CFLAGS) $(OBJS) -o $@ $(LPTHREAD) 

$(OBJ_DIR)%.o: %.c
	@echo Creando $@... con $^
	$(CXX) $(CFLAGS) -c $< -o $@

.PHONY: all clean

clean:
	@echo Limpiando...
	$(RM) $(OBJ_DIR)*
	$(RM) $(NAME)

fclean: clean
	$(RM) $(OBJ_DIR)

re: clean $(CREATE_DIR) all
