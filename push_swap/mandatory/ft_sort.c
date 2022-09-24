/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:43:56 by tjo               #+#    #+#             */
/*   Updated: 2022/09/24 16:25:08 by tjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_header.h"

static int	partitioning(void)
{
	t_partitioning	pt;

	pt = (t_partitioning){.idx = -1, .pt1 = duallist(0, size, 0) / 3 + 1, \
		.pt2 = duallist(0, size, 0) / 3 * 2 + 1, .siz = duallist(0, size, 0)};
	while (++pt.idx < pt.siz)
	{
		pt.tmp = duallist(0, pop_front, 0);
		if (pt.tmp <= pt.pt1)
		{
			duallist(0, push_back, pt.tmp);
			pt.ret += (int)(size_t)record(ra);
		}
		else if (pt.tmp <= pt.pt2)
		{
			duallist(1, push_front, pt.tmp);
			pt.ret += (int)(size_t)record(pb);
		}
		else
		{
			duallist(1, push_back, pt.tmp);
			pt.ret += (int)(size_t)record(pb);
			pt.ret += (int)(size_t)record(rb);
		}
	}
	return (pt.ret);
}

static int	merging(void)
{
	int	siz;
	int	cnt;
	int	ret;

	siz = duallist(0, size, 0);
	cnt = -1;
	ret = 0;
	while (++cnt < siz)
	{
		duallist(1, push_front, duallist(0, pop_front, 0));
		ret += (int)(size_t)record(pb);
	}
	return (ret);
}

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
	int	r_cnt0;
	int	r_cnt1;

	r_cnt0 = duallist(0, size, 0) - cnt0;
	r_cnt1 = duallist(1, size, 0) - cnt1;
	total_mov = ft_max(cnt0, cnt1);
	*mov0 = cnt0;
	*mov1 = cnt1;
	if (total_mov > ft_max(r_cnt0, r_cnt1))
	{
		total_mov = ft_max(r_cnt0, r_cnt1);
		*mov0 = -r_cnt0;
		*mov1 = -r_cnt1;
	}
	if (total_mov > cnt0 + r_cnt1)
	{
		total_mov = cnt0 + r_cnt1;
		*mov0 = cnt0;
		*mov1 = -r_cnt1;
	}
	if (total_mov > r_cnt0 + cnt1)
	{
		total_mov = r_cnt0 + cnt1;
		*mov0 = -r_cnt0;
		*mov1 = cnt1;
	}
	return (total_mov);
}

typedef struct s_greedy
{
	int		min_count;
	t_dl	*p0;
	t_dl	*p1;
	t_dl	*tmp0;
	t_dl	*tmp1;
	int		cnt0;
	int		cnt1;
	int		mov0;
	int		mov1;
	int		tmp;
}t_greedy;

static int	case1(t_greedy *g)
{
	int	ret;

	ret = 0;
	while (ft_min(g->mov0, g->mov1))
	{
		ret += (int)(size_t)record(rr);
		duallist(0, push_back, duallist(0, pop_front, 0));
		duallist(1, push_back, duallist(1, pop_front, 0));
		g->mov0--;
		g->mov1--;
	}
	while (g->mov0)
	{
		ret += (int)(size_t)record(ra);
		duallist(0, push_back, duallist(0, pop_front, 0));
		g->mov0--;
	}
	while (g->mov1)
	{
		ret += (int)(size_t)record(rb);
		duallist(1, push_back, duallist(1, pop_front, 0));
		g->mov1--;
	}
	return (ret);
}

static int	case2(t_greedy *g)
{
	int	ret;

	ret = 0;
	while (ft_max(g->mov0, g->mov1))
	{
		ret += (int)(size_t)record(rrr);
		duallist(0, push_front, duallist(0, pop_back, 0));
		duallist(1, push_front, duallist(1, pop_back, 0));
		g->mov0++;
		g->mov1++;
	}
	while (g->mov0)
	{
		ret += (int)(size_t)record(rra);
		duallist(0, push_front, duallist(0, pop_back, 0));
		g->mov0++;
	}
	while (g->mov1)
	{
		ret += (int)(size_t)record(rrb);
		duallist(1, push_front, duallist(1, pop_back, 0));
		g->mov1++;
	}
	return (ret);
}

static int	case3(t_greedy *g)
{
	int	ret;

	ret = 0;
	while (g->mov0 > 0)
	{
		ret += (int)(size_t)record(ra);
		duallist(0, push_back, duallist(0, pop_front, 0));
		g->mov0--;
	}
	while (g->mov1 > 0)
	{
		ret += (int)(size_t)record(rb);
		duallist(1, push_back, duallist(1, pop_front, 0));
		g->mov1--;
	}
	while (g->mov0 < 0)
	{
		ret += (int)(size_t)record(rra);
		duallist(0, push_front, duallist(0, pop_back, 0));
		g->mov0++;
	}
	while (g->mov1 < 0)
	{
		ret += (int)(size_t)record(rrb);
		duallist(1, push_front, duallist(1, pop_back, 0l));
		g->mov1++;
	}
	return (ret);
}

static int	greedy_method(void)
{
	t_greedy	g;
	int			ret;

	g = (t_greedy){.min_count = INT32_MAX, .cnt0 = -1, .cnt1 = -1, \
		.p0 = get_list(0)->front->next, .p1 = get_list(1)->front->next};
	while (++g.cnt1 < duallist(1, size, 0))
	{
		if (duallist(0, size, 0) < 2)
			break ;
		g.cnt0 = find_target_in_0(get_list(0), g.p1->data);
		if (g.cnt0 == -1)
			g.cnt0 = find_target_in_0_min_max(get_list(0));
		if (find_shortest_path(g.cnt0, g.cnt1, &g.tmp, &g.tmp) < g.min_count)
			g.min_count = find_shortest_path(g.cnt0, g.cnt1, &g.mov0, &g.mov1);
		g.p1 = g.p1->next;
	}
	if (g.mov0 > 0 && g.mov1 > 0)
		ret = case1(&g);
	else if (g.mov0 < 0 && g.mov1 < 0)
		ret = case2(&g);
	else
		ret = case3(&g);
	ret += (int)(size_t)record(pa);
	duallist(0, push_front, duallist(1, pop_front, 0));
	return (ret);
}

int	one_to_top(void)
{
	int	ret;

	ret = 0;
	if (duallist(0, find, 1) < duallist(0, size, 0) / 2)
	{
		while (get_list(0)->front->next->data != 1)
		{
			ret += (int)(size_t)record(ra);
			duallist(0, push_back, duallist(0, pop_front, 0));
		}
	}
	else
	{
		while (get_list(0)->front->next->data != 1)
		{
			ret += (int)(size_t)record(rra);
			duallist(0, push_front, duallist(0, pop_back, 0));
		}
	}
	return (ret);
}

int	sort(void)
{
	if (partitioning() || merging())
		return (1);
	while (duallist(1, size, 0))
		if (greedy_method())
			return (1);
	if (one_to_top())
		return (1);
	return (0);
}
