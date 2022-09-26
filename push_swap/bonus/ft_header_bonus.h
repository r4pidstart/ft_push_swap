/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 02:43:37 by tjo               #+#    #+#             */
/*   Updated: 2022/09/26 20:07:31 by tjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_BONUS_H
# define FT_HEADER_BONUS_H

# include<stdlib.h>
# include"../ft_mylibft/libft.h"

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
	find = 9
};

/* ft_main.c */
t_stack	*get_list(int num);

/* ft_duallist1.c */
int		dlist(int stack, int cmd, int target);

/* ft_duallist2.c */
int		dl_push_back(t_stack *stk, int target);
int		dl_push_front(t_stack *stk, int target);
int		dl_iterate(t_stack *stk, int stack);
int		dl_find(t_stack *stk, int target);
int		dl_modify(t_stack *stk, int target);

/* ft_reading_arg.c */
int		read_argument(char *str);
int		is_duplicated(void);

/* ft_reading_line.c */
int		do_instruction(int tmp[], char *line);

#endif