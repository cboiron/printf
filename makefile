# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cboiron <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/02 06:20:35 by cboiron           #+#    #+#              #
#    Updated: 2017/02/21 16:19:04 by cboiron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_conv_cs.c \
	  ft_str_capitalize.c \
	  ft_prec.c \
	  ft_plus_flag.c \
	  ft_print_arg.c \
	  ft_space_flag.c \
	  ft_printf.c \
	  ft_add_arg.c \
	  ft_lst_arg.c \
	  ft_flag.c \
	  ft_get_modifier.c \
	  ft_parser.c \
	  ft_get_arg.c \
	  ft_conv_d.c \
	  ft_conv_uox.c \
	  ft_itoa_base.c \
	  ft_width.c \
	  ft_free_liste.c \
	  ft_isdigit.c \
	  ft_memset.c \
	  ft_isalpha.c \
	  ft_strdup.c \
	  ft_strjoin.c \
	  ft_strlen.c \
	  ft_strnew.c \
	  ft_strsub.c \
	  ft_putchar.c \
	  ft_treat_perc.c \
	  ft_strdel.c \
	  ft_memdel.c \
	  ft_conv_p.c \
	  ft_move.c \
	  ft_conv_c_up.c \
	  ft_invalid_conv.c \
	  ft_conv_b.c



OBJ = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc -I ft_printf.h -o $@ -c $< $(FLAG)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
