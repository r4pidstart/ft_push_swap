/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:43:56 by tjo               #+#    #+#             */
/*   Updated: 2022/09/14 21:37:08 by tjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_header.h"

static int	partitioning(void)
{
	t_partitioning	pt;

	pt = (t_partitioning){.idx = -1, .pt1 = duallist(0, size, 0) / 3, .ret = 0, \
		.pt2 = duallist(0, size, 0) / 3 * 2, .siz = duallist(0, size, 0)};
	while (++pt.idx < pt.siz)
	{
		pt.tmp = duallist(0, pop_front, 0);
		if (pt.tmp < pt.pt1)
		{
			duallist(0, push_back, pt.tmp);
			pt.ret += (int)record(ra);
		}
		else if (pt.tmp < pt.pt2)
		{
			duallist(0, push_front, pt.tmp);
			pt.ret += (int)record(pb);
		}
		else
		{
			duallist(0, push_back, pt.tmp);
			pt.ret += (int)record(pb);
			pt.ret += (int)record(rb);
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
		ret += (int)record(pb);
	}
	return (ret);
}

static int	get_dist(int now, int target)
{
	int	cnt;

	cnt = 0;
	while (duallist(1, iterate, 0) != now)
		(void)now;
	while (duallist(1, iterate, 0) != target)
		cnt++;
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
	while (++fi.idx < fi.siz)
	{
		fi.dist = get_dist(duallist(1, front, 0), fi.idx);
		fi.dir = fi.dist < (duallist(1, size, 0) / 2);
		while (duallist(1, front, 0) != fi.idx)
		{
			if (!fi.dir)
			{
				duallist(1, push_back, duallist(1, pop_front, 0));
				fi.ret += (int)record(rb);
			}
			else
			{
				duallist(1, push_front, duallist(1, pop_back, 0));
				fi.ret += (int)record(rrb);
			}
		}
		duallist(0, push_front, duallist(1, pop_front, 0));
		fi.ret += (int)record(pa);
	}
	return (fi.ret);
}

int	sort(void)
{
	if (partitioning() || merging() || find_and_push())
		return (1);
}