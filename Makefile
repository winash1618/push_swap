# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 08:55:20 by mkaruvan          #+#    #+#              #
#    Updated: 2023/01/30 10:02:30 by mkaruvan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := push_swap

INC_DIR     := includes

CC          := gcc

FLAGS       := -Wall -Wextra -Werror 

RM          := rm -f

SRCS        := srcs/push_swap_utils.c \
               srcs/circular_linked_list_utils.c \
               srcs/push_swap.c \
               srcs/big_sort.c \
               srcs/push_swap_operations.c \
               srcs/small_sort.c \
               srcs/libft_functions.c \
               srcs/push_swap_checks.c \
               srcs/ft_split.c \

OBJS        := $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -I $(INC_DIR) -c $< -o $@

CLR_RMV     := \033[0m
RED         := \033[1;31m
GREEN       := \033[1;32m
YELLOW      := \033[1;33m
BLUE        := \033[1;34m
CYAN        := \033[1;36m

${NAME}: ${OBJS}
		 @echo "$(GREEN)Compilation of ${YELLOW}$(NAME)...${CLR_RMV}"
		 ${CC} ${FLAGS} -o ${NAME} ${OBJS}
		 @echo "$(GREEN)$(NAME) created[0m ✔️${CLR_RMV}"

all         : ${NAME}

bonus       : all

clean:
			  @ ${RM} *.o */*.o */*/*.o
			  @ echo "$(RED)Deleting $(CYAN)$(NAME) objs ✔️${CLR_RMV}"

fclean: clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) binary ✔️${CLR_RMV}"

re:         fclean all

.PHONY:     all clean fclean re


