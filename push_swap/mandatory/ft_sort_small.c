/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 11:12:01 by tjo               #+#    #+#             */
/*   Updated: 2022/09/25 15:14:25 by tjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_header.h"

static int	sort_2(int stack)
{
	int	tmp[2];

	tmp[0] = get_list(stack)->front->next->data;
	tmp[1] = get_list(stack)->front->next->next->data;
	if (tmp[0] > tmp[1])
	{
		(get_list(stack)->front)->next->data = tmp[1];
		(get_list(stack)->front)->next->next->data = tmp[0];
		return ((size_t)record(ra + stack));
	}
	return (0);
}

static void	__manual_sort(int stack, int a, int b, int c)
{
	int	lo;
	int	hi;

	lo = ft_min(a, ft_min(b, c));
	get_list(stack)->front->next->data = lo;
	hi = ft_max(a, ft_max(b, c));
	get_list(stack)->front->next->next->next->data = hi;
	if (lo != a && hi != a)
		get_list(stack)->front->next->next->data = a;
	else if (lo != b && hi != b)
		get_list(stack)->front->next->next->data = b;
	else
		get_list(stack)->front->next->next->data = c;
}

static int	sort_3(int stack)
{
	int	t[4];

	t[0] = get_list(stack)->front->next->data;
	t[1] = get_list(stack)->front->next->next->data;
	t[2] = get_list(stack)->front->next->next->next->data;
	t[3] = 0;
	if (t[0] < t[1] && t[1] > t[2] && t[0] < t[2])
		t[3] = (record(rra + stack) || record(sa + stack));
	else if (t[0] > t[1] && t[1] < t[2] && t[0] < t[2])
		t[3] = (int)(size_t)record(sa + stack);
	else if (t[0] < t[1] && t[1] > t[2] && t[0] > t[2])
		t[3] = (int)(size_t)record(rra + stack);
	else if (t[0] > t[1] && t[1] < t[2] && t[0] > t[2])
		t[3] = (int)(size_t)record(ra + stack);
	else if (t[0] > t[1] && t[1] > t[2] && t[0] > t[2])
		t[3] = (record(sa + stack) || record(rra + stack));
	__manual_sort(stack, t[0], t[1], t[2]);
	return (t[3]);
}

static int	sort_6(int stack)
{
	int	ret;

	ret = 0;
	while (dlist(stack, size, 0) != 3)
	{
		ret += (int)(size_t)record(pb - stack);
		dlist(!stack, push_front, dlist(stack, pop_front, 0));
	}
	if (dlist(!stack, size, 0) == 2)
		ret += sort_2(!stack);
	else if (dlist(!stack, size, 0) == 3)
		ret += sort_3(!stack);
	ret += sort_3(stack);
	while (dlist(!stack, size, 0))
		ret += greedy_method();
	return (ret);
}

int	sort_small(int stack)
{
	if (dlist(stack, size, 0) == 1)
		return (0);
	else if (dlist(stack, size, 0) == 2)
		return (sort_2(stack));
	else if (dlist(stack, size, 0) == 3)
		return (sort_3(stack));
	else
		return (sort_6(stack));
}
