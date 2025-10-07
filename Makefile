# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = math_1.c \
	more_stack_1.c \
	master_controller.c \
	radix_sort.c \
	dest_idx.c \
	lis_1.c \
	main.c \
	operators_1.c \
	operators_2.c \
	helper_1.c \
	lis_helper.c \
	algo_1.c \
	algo_2.c \
	cost_1.c \
	guard_1.c \
	3_sort.c \
	5_sort.c \
	guarded_atoi.c

OBJ = $(SRC:.c=.o)

# Executable name
NAME = push_swap

# Path to libft
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INC = $(LIBFT_DIR)

# -----------------------------
# Targets
# -----------------------------
all: $(LIBFT_LIB) $(NAME)

# Build libft first
$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR) all

# Build pushswap
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft -I$(LIBFT_INC)

# Compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_INC) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

# Full clean including executable
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
