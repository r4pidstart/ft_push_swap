/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_inst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:34:26 by tjo               #+#    #+#             */
/*   Updated: 2022/09/25 15:47:32 by tjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_header.h"

static void	print_inst(int type)
{
	if (type == 1)
		ft_printf("sa\n");
	else if (type == 2)
		ft_printf("sb\n");
	else if (type == 3)
		ft_printf("ss\n");
	else if (type == 4)
		ft_printf("pa\n");
	else if (type == 5)
		ft_printf("pb\n");
	else if (type == 6)
		ft_printf("ra\n");
	else if (type == 7)
		ft_printf("rb\n");
	else if (type == 8)
		ft_printf("rr\n");
	else if (type == 9)
		ft_printf("rra\n");
	else if (type == 10)
		ft_printf("rrb\n");
	else if (type == 11)
		ft_printf("rrr\n");
}

int	inst_optimazation(int ty, t_list **tmp, t_list **now)
{
	if ((*tmp)->next && ((ty == ra && *((int *)(*tmp)->next->content) == rb) \
		|| (ty == rb && *((int *)(*tmp)->next->content) == ra)))
	{
		print_inst(rr);
		(*now) = (*tmp);
		(*tmp) = (*tmp)->next->next;
		ft_lstdelone((*now)->next, free);
		ft_lstdelone((*now), free);
		return (1);
	}
	if ((*tmp)->next && ((ty == rra && *((int *)(*tmp)->next->content) == rrb) \
		|| (ty == rrb && *((int *)(*tmp)->next->content) == rra)))
	{
		print_inst(rrr);
		(*now) = (*tmp);
		(*tmp) = (*tmp)->next->next;
		ft_lstdelone((*now)->next, free);
		ft_lstdelone((*now), free);
		return (1);
	}
	return (0);
}

int	print(void)
{
	t_list	**inst;
	t_list	*tmp;
	t_list	*now;
	int		type;

	inst = record(pointer);
	tmp = *inst;
	while (tmp)
	{
		type = *((int *)tmp->content);
		if (inst_optimazation(type, &tmp, &now))
			continue ;
		print_inst(type);
		now = tmp;
		tmp = tmp->next;
		ft_lstdelone(now, free);
	}
	return (0);
}
