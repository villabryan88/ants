# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/22 20:11:16 by bvilla            #+#    #+#              #
#    Updated: 2019/09/11 21:10:47 by bvilla           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in
SOURCE = main.c handle_rooms.c handle_edges.c graph.c handle_input.c \
		 graph_dfs.c graph_bfs.c map_wrappers.c graph_edmond.c
INC = .
OBJS = $(SOURCE:%.c=%.o)

$(NAME): $(SOURCE)
	@make -C libft/ 
	@gcc -g -c -Wall -Wextra -Werror $(SOURCE) -I. -I libft/
	@gcc -g $(OBJS) -Wall -Wextra -Werror libft/libft.a -o $(NAME)
	@echo "compilation complete"
all: $(NAME)
clean:
	@rm -f $(OBJS) 
	@make clean -C libft/
	@echo "removed objects"
fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft/
	@echo "removed binary and libraries"
re: fclean all 
