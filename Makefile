# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chervy <chervy@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 14:35:43 by chervy            #+#    #+#              #
#    Updated: 2023/12/28 15:45:46 by chervy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = computorv1

SRCS_PATH   = ./srcs
SRCS         = ${wildcard ${SRCS_PATH}/*.cpp}

INC_PATH    = ./inc
INC         = ${wildcard ${INC_PATH}/*.hpp}

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
