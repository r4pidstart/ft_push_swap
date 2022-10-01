/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 02:43:26 by tjo               #+#    #+#             */
/*   Updated: 2022/10/01 17:12:58 by tjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_header.h"

t_stack	*get_list(int num)
{
	static t_stack	stk[2];

	return (&stk[num]);
}

static int	print_error(void)
{
	ft_lstclear(record(pointer), free);
	dlist(0, delete, 0);
	dlist(1, delete, 0);
	return (!write(2, "Error\n", 6));
}

static int	check(void)
{
	int		flag;
	long	prev;
	t_dl	*cur;

	flag = 0;
	prev = (long)INT32_MIN - 1;
	cur = get_list(0)->front->next;
	while (cur->next)
	{
		flag += (prev >= cur->data);
		prev = cur->data;
		cur = cur->next;
	}
	if (!flag)
	{
		dlist(0, delete, 0);
		dlist(1, delete, 0);
	}
	return (flag);
}

int	main(int argc, char **argv)
{
	int	idx;

	if (dlist(0, init, 0) || dlist(1, init, 0))
		return (print_error());
	idx = 1;
	while (idx < argc)
		if (read_argument(argv[idx++]))
			return (print_error());
	if (argc == 1 || !check())
		return (0);
	if (dlist(0, size, 0) < 7)
	{
		if (is_duplicated() || compress() || sort_small(0))
			return (print_error());
	}
	else
	{
		if (is_duplicated() || compress() || partitioning() || merging())
			return (print_error());
		while (dlist(1, size, 0))
			if (greedy_method())
				return (print_error());
	}
	if (one_to_top() || print())
		return (print_error());
}
