# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chervy <chervy@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 14:35:43 by chervy            #+#    #+#              #
#    Updated: 2023/12/15 16:07:11 by chervy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = computorv1

SRCS_PATH   = ./srcs
SRC         = ${SRCS_PATH}/*

INC_PATH    = ./inc
INC         = ${INC_PATH}/*

CC          = clang++

FLAGS       = -Wall -Wextra -Werror -std=c++11

all: ${NAME}
.PHONY: all

${NAME}: ${SRCS} ${INC}
	${CC} ${FLAGS} -I ${INC_PATH} -o ${NAME} ${SRCS}

clean:
	rm -rf ${NAME}
.PHONY: clean

fclean: clean
.PHONY: fclean

re: fclean all
.PHONY: re
