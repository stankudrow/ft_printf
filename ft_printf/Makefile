# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stanislav <student.21-school.ru>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/13 20:50:52 by stanislav         #+#    #+#              #
#    Updated: 2022/04/03 21:56:57 by stanislav        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

# Directories
HDR_DIR := inc
SRC_DIR := src
CDS_DIR := cdtors
PARS_DIR := parsers
RESLV_DIR := resolvers
UTILS_DIR := utils
OBJ_DIR := obj
LIB_DIR := libft
LIB_INC_DIR := $(LIB_DIR)/inc

# Files
HDRS := $(addprefix $(HDR_DIR)/, ft_printf.h)
CDS_SRC := cdtor_fmt.c cdtor_spec.c
CDS_SRC := $(addprefix $(CDS_DIR)/, $(CDS_SRC))
PARS_SRC := parse_spec.c set_flags.c \
set_width_precision.c set_length.c set_type.c
# parse_widprec.c parse_type.c
PARS_SRC := $(addprefix $(PARS_DIR)/, $(PARS_SRC))
#RESLV_SRC := resolve_spec.c resolve_c.c
#resolve_s.c resolve_di.c resolve_o.c resolve_u.c resolve_x.c resolve_X.c resolve_p.c
#RESLV_SRC := $(addprefix $(RESOLVERS_DIR)/, $(RESLV_SRC))
UTILS_SRC := ft_is_int_overflow.c
#ft_pad.c
UTILS_SRC := $(addprefix $(UTILS_DIR)/, $(UTILS_SRC))
SRCS := ft_printf.c ft_vasprintf.c \
$(CDS_SRC) $(PARS_SRC) $(UTILS_SRC)
#$(PARS) $(RES) $(UTS)
OBJS := $(addprefix $(OBJ_DIR)/, ${SRCS:.c=.o})
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))

# Compilation
CC := cc
CFLAGS := -Wall -Werror -Wextra -MMD -g

# Commands
RM := rm -rf

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@cp $(LIB_DIR)/libft.a .
	@mv libft.a $(NAME)
	ar crs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HDRS)
	@mkdir -p $(dir $@)
	@$(MAKE) -C $(LIB_DIR)
	$(CC) $(CFLAGS) -I$(HDR_DIR) -I$(LIB_INC_DIR) -c $< -o $@

bonus: all

clean:
	@$(MAKE) clean -C $(LIB_DIR)
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C $(LIB_DIR)
	@$(RM) $(NAME)

re: fclean all

-include $(OBJS:.o=.d)