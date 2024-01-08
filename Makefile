# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chervy <chervy@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 14:35:43 by chervy            #+#    #+#              #
#    Updated: 2024/01/08 14:56:42 by chervy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = computor

SRCS_PATH   = ./srcs
SRCS         = ${wildcard ${SRCS_PATH}/*.cpp} \
				${wildcard ${SRCS_PATH}/*/*.cpp}

INC_PATH    = ./inc
INC         = ${wildcard ${INC_PATH}/*.hpp}

CC          = clang++

FLAGS       = -Wall -Wextra -Werror -std=c++11

OBJS		= ${SRCS:.cpp=.o}

%.o: %.cpp ${INC}
	${CC} ${FLAGS} -I ${INC_PATH} -c $< -o ${<:.cpp=.o}

all: ${NAME}
.PHONY: all

${NAME}: ${OBJS}
	${CC} ${FLAGS} -I ${INC_PATH} -o ${NAME} ${OBJS}

clean:
	rm -rf ${OBJS}
.PHONY: clean

fclean: clean
	rm -rf ${NAME}
.PHONY: fclean

re: fclean all
.PHONY: re
