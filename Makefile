all:
	clang -g3 -ggdb \
	-o test \
	push_swap/*.c \
	-Lpush_swap/mylibft -lft