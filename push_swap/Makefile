# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 12:48:31 by tjo               #+#    #+#              #
#    Updated: 2022/10/03 22:20:10 by tjo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror

LIBFT = ft_mylibft/libft.a
LIBFT_SRCS = ft_mylibft
SRCS = ft_main.c ft_duallist1.c ft_duallist2.c ft_reading_arg.c ft_sort_small.c ft_compress.c \
	   ft_record.c ft_partition.c ft_greedy1.c ft_greedy2.c ft_print_inst.c

ifdef BONUS
	NAME = checker
	FOLDER = bonus/
	SRCS = ft_main_bonus.c ft_duallist1_bonus.c ft_duallist2_bonus.c \
		   ft_reading_arg_bonus.c ft_reading_line_bonus.c
else
	FOLDER = mandatory/
endif

all: $(NAME)

$(NAME): $(LIBFT) $(addprefix $(FOLDER), $(SRCS:.c=.o))
	cc -Wall -Wextra -Werror -g3 -ggdb \
	-o ./$(NAME) \
	$(addprefix $(FOLDER), $(SRCS)) \
	-L$(LIBFT_SRCS) -lft

$(LIBFT):
	make -C $(LIBFT_SRCS) all

%.o: %.c
	cc $(CFLAGS) -c $^ -o $@
	
bonus:
	$(MAKE) BONUS=1 checker

clean:
	rm -rf */*.o
	rm -rf *.o
	make clean -C $(LIBFT_SRCS)
	
fclean: clean
	rm -rf push_swap
	rm -rf checker
	make fclean -C $(LIBFT_SRCS)

re: fclean all

.PHONY: bonus all clean fclean re