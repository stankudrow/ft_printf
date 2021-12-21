NAME := libftprintf.a

# Files
SRC_DIR := srcs
SRCS := srcs/ft_is_valid_base.c \
		srcs/ft_nbr.c \
		srcs/ft_parse_chr_fd.c \
		srcs/ft_parse_int_fd.c \
		srcs/ft_parse_ptr_fd.c \
		srcs/ft_parse_spec_fd.c \
		srcs/ft_parse_str_fd.c \
		srcs/ft_parse_ull_fd.c \
		srcs/ft_printf.c \
		srcs/ft_putchar_fd.c \
		srcs/ft_strlen.c \
		srcs/ft_unbr.c \
		srcs/ft_vdprintf.c

HEADER_DIR := inc
HEADER := inc/ft_printf.h

OBJ_DIR := objs
OBJS := $(addprefix $(OBJ_DIR)/,$(notdir ${SRCS:.c=.o}))

# Compilation flags
CC := cc
CFLAGS := -Wall -Werror -Wextra

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar crs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all