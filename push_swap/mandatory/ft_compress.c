/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:17:19 by tjo               #+#    #+#             */
/*   Updated: 2022/09/25 10:48:29 by tjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_header.h"

static void	comp_assign(int	*arr)
{
	t_dl	*p;
	int		idx;

	idx = 0;
	p = get_list(0)->front->next;
	while (p->next)
	{
		p->data = arr[idx++];
		p = p->next;
	}
	free(arr);
}

int	compress(void)
{
	t_compress	comp;

	comp.cnt = -1;
	comp.tmp = (int *)ft_calloc(dlist(0, size, 0), sizeof(int));
	if (!comp.tmp)
		return (1);
	while (++comp.cnt <= dlist(0, size, 0))
	{
		comp.prev_min = (long)INT32_MAX + 1;
		comp.p = get_list(0)->front->next;
		comp.idx = 0;
		while (comp.p->next)
		{	
			if (comp.p->data < comp.prev_min && !comp.tmp[comp.idx])
			{
				comp.prev_idx = comp.idx;
				comp.prev_min = comp.p->data;
			}
			comp.idx++;
			comp.p = comp.p->next;
		}
		comp.tmp[comp.prev_idx] = comp.cnt;
	}
	comp_assign(comp.tmp);
	return (0);
}
