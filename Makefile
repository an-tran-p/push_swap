# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atran <atran@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/04 22:38:29 by atran             #+#    #+#              #
#    Updated: 2025/01/28 12:07:10 by atran            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = ft_atoi.c ft_printf.c ft_print_nbr.c libft_utils.c linked_lst_utils.c \
		check.c push_swap_ops.c rotate_ops.c base_cases.c ops_calculation.c \
		push_to_b.c solve.c ft_split.c main.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
			$(CC) $(CFLAG) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean: clean
			$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
