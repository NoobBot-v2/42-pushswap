# Compiler and flags
CC = gcc
CFLAGS = 

# Source files
SRC = math_1.c more_stack_1.c radix_sort.c dest_idx.c lis_3.c main.c
OBJ = $(SRC:.c=.o)

# Executable name
NAME = pushswap

# Path to libft
LIBFT_DIR = ../libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INC = $(LIBFT_DIR)

# Default target
all: $(LIBFT_LIB) $(NAME)

# Build executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LIBFT_DIR) -lft

# Compile .c files to .o
%.o: %.c
	$(CC) $(CFLAGS) -I $(LIBFT_INC) -c $< -o $@

# Build libft first
$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

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
