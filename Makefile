# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 08:55:20 by mkaruvan          #+#    #+#              #
#    Updated: 2023/02/10 14:53:42 by mkaruvan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := push_swap

INC_DIR     := -I ./libft/includes -I ./includes

CC          := gcc

CFLAGS      := -Wall -Wextra -Werror 

RM          := rm -f

LIBFT	    := libft/libft.a

SRCS        := srcs/main.c

OBJS        := $(SRCS:.c=.o)

%.o: %.c
	${CC} ${CFLAGS} ${INC_DIR} -c $< -o $@

CLR_RMV     := \033[0m
RED         := \033[1;31m
GREEN       := \033[1;32m
YELLOW      := \033[1;33m
BLUE        := \033[1;34m
CYAN        := \033[1;36m

${NAME}: ${LIBFT} ${OBJS}
		 @echo "$(GREEN)Compilation of ${YELLOW}$(NAME)...${CLR_RMV}"
		 ${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}
		 @echo "$(GREEN)$(NAME) created[0m ✔️${CLR_RMV}"

all         : ${NAME}

bonus       : all

${LIBFT}:
		 @make -C libft bonus

clean:
			  @ ${RM} *.o */*.o */*/*.o
			  @ make clean -C libft
			  @ echo "$(RED)Deleting $(CYAN)$(NAME) objs ✔️${CLR_RMV}"

fclean: clean
			@ ${RM} ${NAME}
			@ make fclean -C libft
			@ echo "$(RED)Deleting $(CYAN)$(NAME) binary ✔️${CLR_RMV}"

re:         fclean all

.PHONY:     all clean fclean re


