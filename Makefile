CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ilibft       # include headers from libft/
LDFLAGS = -Llibft                             # where to find libft.a
LDLIBS = -lft                                 # link with libft.a

SRC = $(wildcard *.c)
OBJDIR = obj
OBJ = $(patsubst %.c,$(OBJDIR)/%.o,$(SRC))
EXEC = program

# Default target
all: $(EXEC)

# Link executable (add library here)
$(EXEC): $(OBJ) libft/libft.a
	$(CC) $(OBJ) -o $(EXEC) $(LDFLAGS) $(LDLIBS)

# Compile each .c into obj/.o, ensure obj/ exists first
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Build libft.a by calling its own Makefile
libft/libft.a:
	$(MAKE) -C libft

# Create obj directory if it doesn't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR) $(EXEC)
	$(MAKE) -C libft clean
