NAME := libftprintf.a

# Directories
HDR_DIR := inc
SRC_DIR := src
OBJ_DIR := obj
LIB_DIR := libft

# Files
HDRS := ft_printf.h
HDRS := $(addprefix $(HDR_DIR)/, $(HDRS))
SRCS := ft_printf.c ft_vasprintf.c parse_spec.c resolve_spec.c \
resolve_spec_c.c resolve_spec_s.c resolve_spec_di.c
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS := $(addprefix $(OBJ_DIR)/, $(notdir ${SRCS:.c=.o}))

# Compilation
CC := cc
CFLAGS := -Wall -Werror -Wextra -MMD -g

# Commands
RM := rm -rf

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@cp $(LIB_DIR)/libft.a .
	@mv libft.a $(NAME)
	ar crs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HDRS)
	@mkdir -p $(dir $@)
	@$(MAKE) -C $(LIB_DIR)
	$(CC) $(CFLAGS) -I$(HDR_DIR) -I$(LIB_DIR)/inc -c $< -o $@

clean:
	@$(MAKE) clean -C $(LIB_DIR)
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C $(LIB_DIR)
	@$(RM) $(NAME)

re: fclean all

-include $(OBJS:.o=.d)