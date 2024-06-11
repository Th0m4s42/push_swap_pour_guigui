NAME := push_swap
CC := cc
FLAGS := -Wall -Werror -Wextra -g

Black=\033[0;30m
Red=\033[0;31m
Green=\033[0;32m
Yellow=\033[0;33m
Blue=\033[0;34m
Purple=\033[0;35m
Cyan=\033[0;36m
White=\033[0;37m

SRC_DIR := srcs/
OBJ_DIR := objs/

SRCS := \
	$(SRC_DIR)main.c \
	$(SRC_DIR)utils.c \
	$(SRC_DIR)error.c \
	$(SRC_DIR)init_stack_a.c \
	$(SRC_DIR)push_command.c \
	$(SRC_DIR)swap_command.c \
	$(SRC_DIR)rotate_command.c \
	$(SRC_DIR)rev_rot_command.c \
	$(SRC_DIR)sort_three.c \
	$(SRC_DIR)setting_up.c \
	$(SRC_DIR)sort_stacks.c \

LIBFT_DIR := libft/
LIBFT_LIB := libft/libft.a
LIBFT := -L $(LIBFT_DIR) -lft
LIBFT_FLAGS := -Llibft -l:libft.a

INCLUDES := -I includes

OBJS := $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<
	@echo "$(Cyan)Compiling $<...$(White)"

$(NAME) : $(LIBFT_LIB) $(OBJS)
	@$(CC) $(FLAGS) $(INCLUDES) $(LIBFT_LIB) $(OBJS) -o $(NAME) $(LIBFT_FLAGS)
	@echo "$(Green)$(NAME) CREATED $(White)"

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

all : $(NAME)

clean :
	@make clean -C ./libft
	@echo "$(Red)Cleaning object files...$(White)"
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean : clean
	@make fclean -C ./libft
	@rm -f $(NAME)
	@echo "$(Red)$(NAME) DELETED $(White)"

re : fclean all

.PHONY: re clean fclean