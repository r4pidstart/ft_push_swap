/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:17:19 by tjo               #+#    #+#             */
/*   Updated: 2022/09/14 00:34:58 by tjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_header.h"

static void	comp_assign(t_compress *comp)
{
	comp->idx[0] = -1;
	while (++comp->idx[0] < comp->siz)
		duallist(0, modify, comp->compressed[comp->idx[0]]);
}

int	compress(void)
{
	t_compress	comp;

	ft_memset(comp.compressed, 0, sizeof(comp.compressed));
	comp = (t_compress){.prev = INT32_MIN - 1, .tmp = INT32_MIN - 1, \
		.siz = duallist(0, size, 0), .idx[0] = -1};
	while (++comp.idx[0] < comp.siz)
	{
		comp.idx[1] = -1;
		while (++comp.idx[1] < comp.siz)
		{
			comp.now = duallist(0, iterate, 0);
			if (comp.prev < comp.now)
			{
				if (comp.tmp == comp.now)
					return (1);
				comp.tmp = comp.now;
			}
		}
		comp.compressed[comp.idx[0]] = comp.tmp; 
		comp.prev = comp.tmp;
	}
	comp_assign(&comp);
	return (0);
}
