# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stanislav <student.21-school.ru>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 18:51:40 by stanislav         #+#    #+#              #
#    Updated: 2022/03/08 17:08:15 by stanislav        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

INC_D := inc
SRC_D := src
OBJ_D := obj

ctype_d := ctype
ctype_c := ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isblank.c ft_iscntrl.c \
ft_isdigit.c ft_isdigit.c ft_isgraph.c ft_islower.c ft_isprint.c ft_ispunct.c \
ft_isspace.c ft_isupper.c ft_isxdigit.c ft_tolower.c ft_toupper.c
ctype_c := $(addprefix $(ctype_d)/, $(ctype_c))
ctype_h := ft_ctype.h

get_next_line_d := get_next_line
get_next_line_c := get_next_line.c get_next_line_utils.c
get_next_line_c := $(addprefix $(get_next_line_d)/, $(get_next_line_c))
get_next_line_h := get_next_line.h

list_d := list
slist_d := $(list_d)/slist
slist_c := ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
slist_c := $(addprefix $(slist_d)/, $(slist_c))
slist_h := ft_slist.h

mem_d := mem
mem_c := ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
ft_memmove.c ft_memrchr.c ft_memset.c
mem_c := $(addprefix $(mem_d)/, $(mem_c))
mem_h := ft_mem.h

putters_d := putters
putters_c := ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
ft_putnbr_base_fd.c ft_putnbr_fd.c ft_putunbr_base_fd.c ft_putunbr_fd.c
putters_c := $(addprefix $(putters_d)/, $(putters_c))
putters_h := ft_putters.h

stdbool_h := ft_stdbool.h

stdlib_d := stdlib
stdlib_c := ft_atoi_base.c ft_atoi.c ft_atoui_base.c ft_atoui.c \
ft_calloc.c ft_itoa_base.c ft_itoa.c ft_uitoa_base.c ft_uitoa.c
stdlib_c := $(addprefix $(stdlib_d)/, $(stdlib_c))
stdlib_h := ft_stdlib.h

string_d := string
string_c := ft_split.c ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c \
ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncat.c \
ft_strncmp.c ft_strndup.c ft_strnstr.c ft_strrchr.c ft_strspn.c ft_strstr.c \
ft_strtrim.c ft_substr.c
string_c := $(addprefix $(string_d)/, $(string_c))
string_h := ft_string.h

# Files
HEADERS := $(addprefix $(INC_D)/, $(ctype_h) $(get_next_line_h) $(slist_h) \
$(mem_h) $(putters_h) $(stdlib_h) $(string_h) $(stdbool_h))
SOURCES := $(ctype_c) $(get_next_line_c) $(slist_c) $(mem_c) $(putters_c) $(stdlib_c) $(string_c)
OBJECTS := $(addprefix $(OBJ_D)/, $(SOURCES:.c=.o))

# Compilation
CC := cc
CFLAGS := -Wall -Werror -Wextra -MMD -g

# Commands
RM := rm -rf

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	ar crs $(NAME) $(OBJECTS)

$(OBJ_D)/%.o: $(SRC_D)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INC_D) -c $< -o $@

clean:
	@$(RM) $(OBJ_D)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

-include $(OBJECTS:.o=.d)