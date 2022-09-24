/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_greedy2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 02:31:48 by tjo               #+#    #+#             */
/*   Updated: 2022/09/25 02:58:44 by tjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_header.h"

static int	case1(t_greedy *g)
{
	int	ret;

	ret = 0;
	while (ft_min(g->mov0, g->mov1))
	{
		ret += (int)(size_t)record(rr);
		dlist(0, push_back, dlist(0, pop_front, 0));
		dlist(1, push_back, dlist(1, pop_front, 0));
		g->mov0--;
		g->mov1--;
	}
	while (g->mov0)
	{
		ret += (int)(size_t)record(ra);
		dlist(0, push_back, dlist(0, pop_front, 0));
		g->mov0--;
	}
	while (g->mov1)
	{
		ret += (int)(size_t)record(rb);
		dlist(1, push_back, dlist(1, pop_front, 0));
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
		dlist(0, push_front, dlist(0, pop_back, 0));
		dlist(1, push_front, dlist(1, pop_back, 0));
		g->mov0++;
		g->mov1++;
	}
	while (g->mov0)
	{
		ret += (int)(size_t)record(rra);
		dlist(0, push_front, dlist(0, pop_back, 0));
		g->mov0++;
	}
	while (g->mov1)
	{
		ret += (int)(size_t)record(rrb);
		dlist(1, push_front, dlist(1, pop_back, 0));
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
		dlist(0, push_back, dlist(0, pop_front, 0));
		g->mov0--;
	}
	while (g->mov1 < 0)
	{
		ret += (int)(size_t)record(rrb);
		dlist(1, push_front, dlist(1, pop_back, 0));
		g->mov1++;
	}
	return (ret);
}

static int	case4(t_greedy *g)
{
	int	ret;

	ret = 0;
	while (g->mov0 < 0)
	{
		ret += (int)(size_t)record(rra);
		dlist(0, push_front, dlist(0, pop_back, 0));
		g->mov0++;
	}
	while (g->mov1 > 0)
	{
		ret += (int)(size_t)record(rb);
		dlist(1, push_back, dlist(1, pop_front, 0));
		g->mov1--;
	}
	return (ret);
}

int	manipulate_stack(t_greedy *g)
{
	int	ret;

	ret = 0;
	if (g->mov0 > 0 && g->mov1 > 0)
		ret = case1(g);
	else if (g->mov0 < 0 && g->mov1 < 0)
		ret = case2(g);
	else if (g->mov0 >= 0 && g->mov1 <= 0)
		ret = case3(g);
	else if (g->mov0 <= 0 && g->mov1 >= 0)
		ret = case4(g);
	ret += (int)(size_t)record(pa);
	dlist(0, push_front, dlist(1, pop_front, 0));
	return (ret);
}
