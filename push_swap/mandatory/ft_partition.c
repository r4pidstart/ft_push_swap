/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_partition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 02:28:59 by tjo               #+#    #+#             */
/*   Updated: 2022/09/25 02:58:29 by tjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_header.h"

int	partitioning(void)
{
	t_partitioning	pt;

	pt = (t_partitioning){.idx = -1, .pt1 = dlist(0, size, 0) / 3 + 1, \
		.pt2 = dlist(0, size, 0) / 3 * 2 + 1, .siz = dlist(0, size, 0)};
	while (++pt.idx < pt.siz)
	{
		pt.tmp = dlist(0, pop_front, 0);
		if (pt.tmp <= pt.pt1)
		{
			dlist(0, push_back, pt.tmp);
			pt.ret += (int)(size_t)record(ra);
		}
		else if (pt.tmp <= pt.pt2)
		{
			dlist(1, push_front, pt.tmp);
			pt.ret += (int)(size_t)record(pb);
		}
		else
		{
			dlist(1, push_back, pt.tmp);
			pt.ret += (int)(size_t)record(pb);
			pt.ret += (int)(size_t)record(rb);
		}
	}
	return (pt.ret);
}

int	merging(void)
{
	int	siz;
	int	cnt;
	int	ret;

	siz = dlist(0, size, 0);
	cnt = -1;
	ret = 0;
	while (++cnt < siz)
	{
		dlist(1, push_front, dlist(0, pop_front, 0));
		ret += (int)(size_t)record(pb);
	}
	return (ret);
}
