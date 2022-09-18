/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 02:43:37 by tjo               #+#    #+#             */
/*   Updated: 2022/09/19 01:29:10 by tjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

# include<stdlib.h>
# include"../mylibft/libft.h"

typedef struct s_dl
{
	long		data;
	struct s_dl	*next;
	struct s_dl	*prev;
}t_dl;

typedef struct s_stack
{
	t_dl	*front;
	t_dl	*back;
	int		size;
}t_stack;

typedef struct s_compress
{
	int		compressed[500];
	int		idx[2];
	long	prev;
	long	tmp;
	int		now;
	int		siz;
}t_compress;

typedef struct s_partitioning
{
	int	siz;
	int	pt1;
	int	pt2;
	int	tmp;
	int	idx;
	int	ret;
}t_partitioning;

typedef struct s_finding
{
	int	dist;
	int	idx;
	int	dir;
	int	ret;
}t_finding;

enum e_cmd
{
	init = 0,
	push_back = 1,
	push_front = 2,
	pop_back = 3,
	pop_front = 4,
	delete = 5,
	size = 6,
	iterate = 7,
	modify = 8,
	find = 9,
	front = 11,
	second_front = 12,
	back = 13,
	second_back = 14
};

enum e_instruction
{
	sa = 1,
	sb = 2,
	ss = 3,
	pa = 4,
	pb = 5,
	ra = 6,
	rb = 7,
	rr = 8,
	rra = 9,
	rrb = 10,
	rrr = 11,
	pointer = 20
};

/* ft_duallist1.c */
int		duallist(int stack, int cmd, int target);

/* ft_duallist2.c */
int		dl_init(t_stack *stk);
int		dl_push_back(t_stack *stk, int target);
int		dl_push_front(t_stack *stk, int target);
int		dl_iterate(t_stack *stk, int stack);
int		dl_find(t_stack *stk, int target);
int		dl_modify(t_stack *stk, int target);

/* ft_reading_arg.c */
int		read_argument(char *str);

/* ft_compress.c */
int		compress(void);

/* ft_record.c */
t_list	**record(int type);

/* ft_sort.c */
int		sort(void);

/* ft_print_inst.c */
int		print(void);

#endif