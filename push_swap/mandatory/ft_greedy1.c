/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_greedy1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:43:56 by tjo               #+#    #+#             */
/*   Updated: 2022/09/25 02:58:16 by tjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_header.h"

static	int	find_target_in_0(t_stack *stack, int target)
{
	int		ret;
	int		cnt;
	int		prev;
	t_dl	*cur;

	ret = -1;
	cnt = 0;
	prev = stack->back->prev->data;
	cur = stack->front->next;
	while (cur)
	{
		if (prev < target && target < cur->data)
			ret = cnt;
		cnt++;
		prev = cur->data;
		cur = cur->next;
	}
	return (ret);
}

static int	find_target_in_0_min_max(t_stack *stack)
{
	int		ret;
	int		cnt;
	int		max;
	t_dl	*cur;

	ret = -1;
	cnt = 0;
	cur = stack->front->next;
	max = 0;
	while (cur)
	{
		if (max < cur->data)
		{
			ret = cnt;
			max = cur->data;
		}
		cur = cur->next;
		cnt++;
	}
	return (ret + 1);
}

static int	find_shortest_path(int cnt0, int cnt1, int *mov0, int *mov1)
{
	int	total_mov;

	total_mov = ft_max(cnt0, cnt1);
	*mov0 = cnt0;
	*mov1 = cnt1;
	if (total_mov > ft_max(dlist(0, size, 0) - cnt0, dlist(1, size, 0) - cnt1))
	{
		total_mov = ft_max(dlist(0, size, 0) - cnt0, dlist(1, size, 0) - cnt1);
		*mov0 = -(dlist(0, size, 0) - cnt0);
		*mov1 = -(dlist(1, size, 0) - cnt1);
	}
	if (total_mov > cnt0 + (dlist(1, size, 0) - cnt1))
	{
		total_mov = cnt0 + (dlist(1, size, 0) - cnt1);
		*mov0 = cnt0;
		*mov1 = -(dlist(1, size, 0) - cnt1);
	}
	if (total_mov > (dlist(0, size, 0) - cnt0) + cnt1)
	{
		total_mov = (dlist(0, size, 0) - cnt0) + cnt1;
		*mov0 = -(dlist(0, size, 0) - cnt0);
		*mov1 = cnt1;
	}
	return (total_mov);
}

int	greedy_method(void)
{
	t_greedy	g;
	int			ret;

	g = (t_greedy){.min_count = INT32_MAX, .cnt0 = -1, .cnt1 = -1, \
		.p0 = get_list(0)->front->next, .p1 = get_list(1)->front->next};
	while (++g.cnt1 < dlist(1, size, 0))
	{
		if (dlist(0, size, 0) < 2)
			break ;
		g.cnt0 = find_target_in_0(get_list(0), g.p1->data);
		if (g.cnt0 == -1)
			g.cnt0 = find_target_in_0_min_max(get_list(0));
		if (find_shortest_path(g.cnt0, g.cnt1, &g.tmp, &g.tmp) < g.min_count)
			g.min_count = find_shortest_path(g.cnt0, g.cnt1, &g.mov0, &g.mov1);
		g.p1 = g.p1->next;
	}
	ret = manipulate_stack(&g);
	return (ret);
}

int	one_to_top(void)
{
	int	ret;

	ret = 0;
	if (dlist(0, find, 1) < dlist(0, size, 0) / 2)
	{
		while (get_list(0)->front->next->data != 1)
		{
			ret += (int)(size_t)record(ra);
			dlist(0, push_back, dlist(0, pop_front, 0));
		}
	}
	else
	{
		while (get_list(0)->front->next->data != 1)
		{
			ret += (int)(size_t)record(rra);
			dlist(0, push_front, dlist(0, pop_back, 0));
		}
	}
	return (ret);
}
