# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cortiz <cortiz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 15:02:30 by fluchten          #+#    #+#              #
#    Updated: 2023/06/08 09:33:23 by cortiz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
RM = rm -rf

INC_DIR = includes
SRCS_DIR = srcs
OBJS_DIR = objs

SRCS =	main.c			\
		maitre_split.c 	\
		utils.c			\
		signal.c		\
		parser_utils.c	\
		parser.c		\
		expander.c		\
		executor.c		\

OBJS = $(addprefix ${OBJS_DIR}/, ${SRCS:%.c=%.o})

LIBFT_PATH = libft
LIBFT_LIB = ${LIBFT_PATH}/libft.a
LIBFT_INC = ${LIBFT_PATH}

READLINE_PATH = $(shell brew --prefix readline)
READLINE_LIB = -lreadline -lhistory -L $(READLINE_PATH)/lib
READLINE_INC = -I $(READLINE_PATH)

COLOR_CYAN = \033[1;36m
COLOR_RED = \033[0;31m
COLOR_GREEN	= \033[0;32m
COLOR_RESET = \033[0m

all: ${NAME}

${OBJS_DIR}:
	@echo "${COLOR_CYAN}${NAME} ${COLOR_GREEN}COMPILING ->${COLOR_RESET}"

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c | ${OBJS_DIR}
	@mkdir -p ${@D}
	@${CC} ${CFLAGS} -I ${INC_DIR} -I ${LIBFT_INC} ${READLINE_INC} -c $< -o $@
	@echo "${COLOR_GREEN}.${COLOR_RESET}\c"

${NAME}: ${OBJS}
	@make -C ${LIBFT_PATH}
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT_LIB} ${READLINE_LIB} -o ${NAME}
	@echo "${COLOR_CYAN}${NAME} ${COLOR_GREEN}${OBJS_DIR} were created${COLOR_RESET}"
	@echo "${COLOR_CYAN}${NAME} ${COLOR_GREEN}${NAME} was created${COLOR_RESET}"

clean:
	@make clean -C ${LIBFT_PATH}
	@${RM} ${OBJS_DIR}
	@echo "${COLOR_CYAN}${NAME} ${COLOR_RED}${OBJS_DIR} were deleted${COLOR_RESET}"

fclean:	clean
	@make fclean -C ${LIBFT_PATH}
	@${RM} ${NAME}
	@echo "${COLOR_CYAN}${NAME} ${COLOR_RED}${NAME} was deleted${COLOR_RESET}"

re: fclean all

.PHONY: all clean fclean re
