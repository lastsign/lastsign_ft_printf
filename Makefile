# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptycho <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/11 20:38:06 by ptycho            #+#    #+#              #
#    Updated: 2020/11/11 20:38:07 by ptycho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_DIR  = srcs
HEADER  = includes
OBJ_DIR  = obj

SRCS 			= ft_printf.c\
					ft_parser.c\
					ft_parser_utils.c\
					ft_parser_utils_1more.c\
					ft_print_d.c\
					ft_print_d_utils.c\
					ft_print_c.c\
					ft_print_per.c\
					ft_print_u.c\
					ft_print_u_utils.c\
					ft_print_s.c\
					ft_print_s_utils.c\
					ft_print_x.c\
					ft_print_x_utils.c\
					ft_print_p.c\
					ft_print_p_utils.c\

OBJ     = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
includes	= $(wildcard includes/*.h)

CC		= gcc
CFLAGS  = -Wall -Wextra -Werror -I$(HEADER)

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c $(includes)
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: all

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus