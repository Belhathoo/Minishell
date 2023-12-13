# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: belhatho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 22:11:20 by belhatho          #+#    #+#              #
#    Updated: 2022/01/18 22:11:22 by belhatho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = main.c parse_input.c signals.c run_commands.c
SRC += environment.c environment1.c exec.c utils.c
SRC += run_unsetenv.c run_echo.c run_cd.c run_setenv.c

SRCS = $(SRC:%=srcs/%)
OBJS = $(SRC:%.c=objs/%.o)

BUILD_PRINT = $(GREEN_COLOR)minishell successfully compiles$(NO_COLOR)
GREEN_COLOR=\x1b[32;01m

FLAGS = -g -Wall -Wextra -Werror
CREATE_OBJ = objs



all: $(NAME)

$(NAME): $(CREATE_OBJ) $(OBJS)
	@gcc $(FLAGS) -o $(NAME)  -I . $(OBJS)
	@echo "$(BUILD_PRINT)"

$(CREATE_OBJ):
	@mkdir -p $@

objs/%.o: srcs/%.c srcs/minishell.h
	@gcc $(FLAGS) -c $< -o $@

clean:
		@rm -f $(OBJS)

fclean: clean
			@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
