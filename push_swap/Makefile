# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 12:48:31 by tjo               #+#    #+#              #
#    Updated: 2022/09/12 00:30:10 by tjo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror

LIBFT = mylibft/libft.a
LIBFT_SRCS = mylibft
SRCS = ft_main.c ft_duallist1.c ft_duallist2.c

ifdef BONUS
	FOLDER = bonus/
else
	FOLDER = 
endif

all: $(NAME)

$(NAME): $(LIBFT) $(addprefix $(FOLDER), $(SRCS:.c=.o))
	clang -Wall -Wextra -Werror -g3 -ggdb \
	-o ./$(NAME) \
	$(addprefix $(FOLDER), $(SRCS)) \
	-Lmylibft -lft

$(LIBFT):
	make -C $(LIBFT_SRCS) all

%.o: %.c
	gcc $(CFLAGS) -c $^ -o $@
	
bonus:
	$(MAKE) BONUS=1 $(NAME)

clean:
	rm -rf */*.o
	rm -rf *.o
	make clean -C $(LIBFT_SRCS)
	
fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_SRCS)

re: fclean all

.PHONY: bonus all clean fclean re