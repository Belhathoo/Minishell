# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: belhatho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/30 20:21:59 by belhatho          #+#    #+#              #
#    Updated: 2019/12/21 00:08:38 by belhatho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = mainc.c extract_cmds.c ft_lstsplit.c
OBJS = $(SRCS:.c=.o)

FLAGS = 
LIBFT = ./libft/ -lft

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@gcc $(FLAGS) -o $(NAME) $(OBJS) -L $(LIBFT)

%.o: %.c minishell.h libft/libft.h
	@gcc $(FLAGS) -c $< -o $@

clean:
		@make clean -C libft
		@rm -f $(OBJS)

fclean: clean
	        @make fclean -C libft
			        @rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
