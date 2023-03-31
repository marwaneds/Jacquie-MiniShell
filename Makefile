NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

INC_DIR = -I includes
SRCS_DIR = srcs
OBJS_DIR = objs

SRCS = main.c \

OBJS = $(addprefix ${OBJS_DIR}/, ${SRCS:%.c=%.o})

# LIBFT_PATH = libft
# LIBFT_LIB = ${LIBFT_PATH}/libft.a
# LIBFT_INC = ${LIBFT_PATH}

all: ${NAME}

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@mkdir -p ${@D} >/dev/null
	@${CC} ${CFLAGS} ${INC_DIR} -c $< -o $@ >/dev/null

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME} >/dev/null
	@echo "\033[1;32mCompilation successful: $(NAME)\033[0m"

clean:
	@${RM} ${OBJS_DIR} >/dev/null
	@echo "\033[1;33mObject files deleted.\033[0m"

fclean: clean
	@@${RM} ${NAME} >/dev/null
	@echo "\033[1;31m$(NAME) deleted.\033[0m"

re: fclean all

.PHONY: all clean fclean re