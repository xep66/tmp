NAME = pipex.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs

SRC_DIR = src
OBJ_DIR = objs

SRCS = $(wildcard $(SRC_DIR)/*.c)

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBS = ./libs
PRINTF_PATH = $(LIBS)/ft_printf
PRINTF = $(PRINTF_PATH)/libftprintf.a

LIBFT_PATH = $(PRINTF_PATH)/libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(PRINTF):
	make -C $(PRINTF_PATH)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(NAME): $(PRINTF) $(LIBFT) $(OBJS)
	cp $(PRINTF) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

test: $(NAME)
	$(CC) $(CFLAGS) test.c -o test -L. -l:pipex.a -L$(PRINTF_PATH) -lftprintf -L$(LIBFT_PATH) -lft

clean:
	make -C $(PRINTF_PATH) clean
	make -C $(LIBFT_PATH) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(PRINTF_PATH) clean
	make -C $(LIBFT_PATH) clean
	rm -f $(NAME)
	rm -f test

re: fclean all

.PHONY: all clean fclean re test
