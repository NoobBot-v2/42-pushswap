CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
SRC     = $(wildcard *.c)
OBJDIR  = obj
OBJ     = $(patsubst %.c,$(OBJDIR)/%.o,$(SRC))
EXEC    = program

# Default target: build without libft
all: $(EXEC)

# Target to build with libft
with_libft: CFLAGS += -Ilibft
with_libft: LDLIBS += -lft
with_libft: LDFLAGS += -Llibft
with_libft: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS) $(LDLIBS)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR) $(EXEC)
	# $(MAKE) -C libft clean   # uncomment only if using libft

# Convenience target: build libft if needed
libft/libft.a:
	$(MAKE) -C libft
