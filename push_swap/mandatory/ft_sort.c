/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:43:56 by tjo               #+#    #+#             */
/*   Updated: 2022/09/15 00:08:05 by tjo              ###   ########.fr       */
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

static int	get_dist(int now, int target)
{
	int	cnt;

	cnt = 1;
	int test=-1;
	while (test != now)
		test = duallist(1, iterate, 0);
	while (test != target)
	{
		test = duallist(1, iterate, 0);
		cnt++;
	}
	return (cnt);
}

typedef struct s_finding
{
	int	dist;
	int	idx;
	int	siz;
	int	dir;
	int	ret;
}t_finding;

static int	find_and_push(void)
{
	t_finding	fi;

	fi = (t_finding){.idx = 0, .siz = duallist(1, size, 0), .ret = 0};
	while (++fi.idx <= fi.siz)
	{
		fi.dist = get_dist(duallist(1, front, 0), fi.idx);
		fi.dir = fi.dist > (duallist(1, size, 0) / 2 + 1);
		while (duallist(1, front, 0) != fi.idx)
		{
			(void)fordebug;
			if (!fi.dir)
			{
				duallist(1, push_back, duallist(1, pop_front, 0));
				fi.ret += (int)(size_t)record(rb);
			}
			else
			{
				duallist(1, push_front, duallist(1, pop_back, 0));
				fi.ret += (int)(size_t)record(rrb);
			}
		}
		duallist(1, iterate, 0);
		duallist(0, push_front, duallist(1, pop_front, 0));
		fi.ret += (int)(size_t)record(pa);
	}
	return (fi.ret);
}

int test()
{
	while (duallist(0, size, 0))
		ft_printf("%d ", duallist(0, pop_front, 0));
	ft_printf("\n");
	while (duallist(1, size, 0))
		ft_printf("%d ", duallist(1, pop_front, 0));
	return (1);
}
int	sort(void)
{
	if (partitioning() || merging() || find_and_push() || test())
		return (1);
	return (0);
}