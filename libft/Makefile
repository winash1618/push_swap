# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 14:38:28 by mkaruvan          #+#    #+#              #
#    Updated: 2023/02/26 14:11:53 by mkaruvan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := libft.a

CC          := gcc -O3

CFLAGS      := -Wall -Wextra -Werror -I includes

RM          := rm -f

AR          := ar rcs

SRCS        := srcs/ft_strmapi.c \
               srcs/ft_strjoin.c \
               srcs/ft_strlcat.c \
               srcs/ft_strlcpy.c \
               srcs/ft_substr.c \
               srcs/ft_strdup.c \
               srcs/ft_striteri.c \
               srcs/ft_strtrim.c \
               srcs/ft_split.c \
               srcs/ft_isprint.c \
               srcs/ft_isalnum.c \
               srcs/ft_isalpha.c \
               srcs/ft_isdigit.c \
               srcs/ft_isascii.c \
               srcs/ft_bzero.c \
               srcs/ft_calloc.c \
               srcs/ft_strrchr.c \
               srcs/ft_strchr.c \
               srcs/ft_strlen.c \
               srcs/ft_strnstr.c \
               srcs/ft_strncmp.c \
               srcs/ft_putnbr_fd.c \
               srcs/ft_putstr_fd.c \
               srcs/ft_putchar_fd.c \
               srcs/ft_putendl_fd.c \
               srcs/ft_tolower.c \
               srcs/ft_atoi.c \
               srcs/ft_itoa.c \
               srcs/ft_toupper.c \
               srcs/ft_memset.c \
               srcs/ft_memmove.c \
               srcs/ft_memcpy.c \
               srcs/ft_memchr.c \
               srcs/ft_memcmp.c \

SRC_BONUS   := bonus/ft_lstnew.c \
			   bonus/ft_lstadd_front.c \
			   bonus/ft_lstsize.c \
			   bonus/ft_lstlast.c \
			   bonus/ft_lstadd_back.c \
			   bonus/ft_lstdelone.c \
			   bonus/ft_lstclear.c \
			   bonus/ft_lstiter.c \
			   bonus/ft_lstmap.c \

OBJS        := $(SRCS:.c=.o)

OBJS_BONUS  := $(SRC_BONUS:.c=.o)

CLR_RMV     := \033[0m
RED         := \033[1;31m
GREEN       := \033[1;32m
YELLOW      := \033[1;33m
BLUE        := \033[1;34m
CYAN        := \033[1;36m

${NAME}:	${OBJS}
			@echo "$(GREEN) Creating archive file ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${AR} ${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

bonus:		${OBJS} ${OBJS_BONUS}
			@echo "$(GREEN) Creating archive file with bonus ${CLR_RMV} ${YELLOW}$(NAME)${CLR_RMV}..."
			${AR} ${NAME} ${OBJS} ${OBJS_BONUS}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

clean:
			@ ${RM} $(OBJS) $(OBJS_BONUS)
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean bonus

.PHONY:		all clean fclean re


