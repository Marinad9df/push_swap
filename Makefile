# DIRECTORIES
OBJS_DIR = objs/
SRC_DIR = srcs/
INC_DIR = includes/

# SOURCE FILES
SRCS_FILES = parse_utils.c parse_numbers.c parse_arguments.c instructions.c push_swap.c sort.c sort_utils.c stack_utils.c push_swap_utils.c

SRC = $(addprefix $(SRC_DIR), $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_DIR), $(SRCS_FILES:%.c=%.o))

# VARIABLES
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR)
RM = rm -rf

# LIBFT
LIBFT_DIR = ./libft/
LIBFT = libft.a
LIBFT_AR = $(addprefix $(LIBFT_DIR), $(LIBFT))

# TARGETS
all: $(NAME)

$(OBJS_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_AR):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_AR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_AR) -o $(NAME)

clean:
	@make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS_DIR)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

norminette:
	norminette $(SRC_DIR)
	norminette $(INC_DIR)
	@make norminette -C $(LIBFT_DIR)

.PHONY: all clean fclean re norminette
