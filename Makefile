# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: belhatho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/30 20:21:59 by belhatho          #+#    #+#              #
#    Updated: 2020/01/15 20:15:22 by belhatho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = main.c extract_cmds.c ft_lstsplit.c
SRC += environment.c run_env.c run_cd.c run_setenv.c

SRCS = $(SRC:%=srcs/%)
OBJS = $(SRC:%.c=objs/%.o)
LIBFT = ./libft/ -lft

FLAGS =  
CREATE_OBJ = objs

all: $(NAME)

$(NAME): $(CREATE_OBJ) $(OBJS)
	@make -C libft
	@gcc $(FLAGS) -o $(NAME) $(OBJS) -L $(LIBFT)

$(CREATE_OBJ):
	@mkdir -p $@

objs/%.o: srcs/%.c srcs/minishell.h libft/libft.h
	@gcc $(FLAGS) -c $< -o $@

clean:
		@make clean -C libft
		@rm -f $(OBJS)

fclean: clean
	        @make fclean -C libft
			        @rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
