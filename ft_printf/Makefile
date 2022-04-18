# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stanislav <student.21-school.ru>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/18 00:27:18 by stanislav         #+#    #+#              #
#    Updated: 2022/04/18 15:40:14 by stanislav        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

# Directories
HDR_DIR := inc
SRC_DIR := src
CDS_DIR := cdtors
PARS_DIR := parsers
RES_DIR := resolvers
UTILS_DIR := utils
OBJ_DIR := obj
LIB_DIR := libftx/libft
LIB_INC_DIR := $(LIB_DIR)/inc

# Files
HDRS := $(addprefix $(HDR_DIR)/, ft_printf.h)
CDS_SRC := fmt_cdtors.c spec_cdtors.c
CDS_SRC := $(addprefix $(CDS_DIR)/, $(CDS_SRC))
PARS_SRC := parse_spec.c set_flags.c set_length.c \
set_width_precision.c  set_type.c
PARS_SRC := $(addprefix $(PARS_DIR)/, $(PARS_SRC))
RES_SRC := resolve_spec.c resolve_chr.c resolve_str.c \
resolve_ptr.c resolve_unbr.c resolve_nbr.c
RES_SRC := $(addprefix $(RES_DIR)/, $(RES_SRC))
UTILS_SRC := pf_atoi.c pf_intop_overflow.c pf_pad.c
UTILS_SRC := $(addprefix $(UTILS_DIR)/, $(UTILS_SRC))
SRCS := ft_printf.c ft_vasprintf.c \
$(CDS_SRC) $(PARS_SRC) $(RES_SRC) $(UTILS_SRC)
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