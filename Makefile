# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 08:55:20 by mkaruvan          #+#    #+#              #
#    Updated: 2022/04/05 15:20:11 by mkaruvan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_M = push_swap

SRC_M = big_sort.c \
		circular_linked_list_utils.c \
		libft_functions.c \
		push_swap_checks.c \
		push_swap_operations.c \
		push_swap_utils.c \
		push_swap.c \
		small_sort.c \
		ft_split.c

HEADERS_M = push_swap.h

OBJ = *.o

GREEN = \033[1;32m
RED = \033[1;31m
YEL = \033[1;33m
WHT = \033[1;37m
EOC = \033[1;0m

CC = gcc

FLAGS = -g -Wall -Wextra -Werror

all: $(NAME_M)

$(NAME_M):
	@echo "$(WHT)Compiling push_swap...$(EOC)"
	@$(CC) $(FLAGS) -c $(SRC_M)
	@$(CC) $(FLAGS) -o $(NAME_M) $(OBJ)
	@mkdir obj
	@mv $(OBJ) ./obj
	@echo "$(GREEN)push_swap build completed.$(EOC)"

clean:
	@echo "$(WHT)Removing o-files...$(EOC)"
	@/bin/rm -f $(OBJ)
	@/bin/rm -Rf obj
	@echo "$(GREEN)Clean done.$(EOC)"

fclean: clean
	@echo "$(WHT)Removing object- and binary -files...$(EOC)"
	@/bin/rm -f $(NAME_M)
	@echo "$(GREEN)Fclean done.$(EOC)"

re: fclean all

.PHONY: all clean fclean re
