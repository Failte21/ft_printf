# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsimon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/10 10:21:00 by lsimon            #+#    #+#              #
#    Updated: 2017/03/14 14:45:23 by lsimon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

LINKS = libft/libft.a

SRC =	libft/ft_atoi.c libft/ft_bzero.c libft/ft_isalnum.c libft/ft_isalpha.c\
		libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c\
		libft/ft_itoa.c libft/ft_memalloc.c libft/ft_memccpy.c\
		libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memdel.c\
		libft/ft_memmove.c libft/ft_putchar.c libft/ft_memset.c\
		libft/ft_putchar_fd.c libft/ft_putendl.c libft/ft_putendl_fd.c\
		libft/ft_putnbr.c libft/ft_putnbr_fd.c libft/ft_putstr.c\
		libft/ft_putstr_fd.c libft/ft_strcat.c libft/ft_strchr.c\
		libft/ft_strclr.c libft/ft_strcmp.c libft/ft_strcpy.c libft/ft_strdel.c\
		libft/ft_strdup.c libft/ft_strequ.c libft/ft_striter.c\
		libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strjoinfree.c\
		libft/ft_strlcat.c libft/ft_strlen.c libft/ft_strmap.c\
		libft/ft_strmapi.c libft/ft_strncat.c libft/ft_strncmp.c\
		libft/ft_strncpy.c libft/ft_strnequ.c libft/ft_strnew.c\
		libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strsplit.c\
		libft/ft_strstr.c libft/ft_strsub.c libft/ft_strtrim.c\
		libft/ft_tolower.c libft/ft_toupper.c libft/ft_lstnew.c\
		libft/ft_lstdelone.c libft/ft_lstdel.c libft/ft_lstadd.c\
		libft/ft_lstiter.c libft/ft_lstmap.c libft/ft_swap.c\
		libft/ft_recursive_factorial.c libft/ft_sqrt.c libft/ft_print_bits.c\
		libft/ft_sort_int_tab.c libft/ft_get_next_line.c libft/ft_word_count.c\
		libft/ft_word_count_line.c libft/ft_ishex.c libft/ft_atoi_max.c\
		libft/ft_nblen.c libft/ft_atoi_base.c\
		srcs/ft_printf.c srcs/init.c srcs/parser.c srcs/error.c srcs/flags.c\
		srcs/modifiers.c srcs/print_char.c srcs/print.c srcs/conversion.c\
		srcs/len.c srcs/get.c srcs/display.c srcs/print_base.c srcs/unicode.c\
		srcs/precision.c srcs/p_conversion.c

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar -r $@ $^
	ranlib $(NAME)

%.o : %.c
	gcc -I includes -o $@ -c $^ $(FLAGS)

.PHONY: clean fclean

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf libftprintf.a

re: fclean all
