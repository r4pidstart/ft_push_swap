/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reading_line_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 22:39:29 by tjo               #+#    #+#             */
/*   Updated: 2022/09/26 16:03:45 by tjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_header_bonus.h"

static int	list_swap(int stk, int tmp[])
{
	tmp[0] = dlist(stk, pop_front, 0);
	tmp[1] = dlist(stk, pop_front, 0);
	dlist(stk, push_front, tmp[0]);
	dlist(stk, push_front, tmp[1]);
	return (0);
}

static int	do_instruction2(char *line)
{
	if (!ft_strncmp(line, "rra", 4) && dlist(0, size, 0))
		return (dlist(0, push_front, dlist(0, pop_back, 0)));
	if (!ft_strncmp(line, "rrb", 4) && dlist(1, size, 0))
		return (dlist(1, push_front, dlist(1, pop_back, 0)));
	if (!ft_strncmp(line, "rrr", 4) \
	&& dlist(0, size, 0) && dlist(1, size, 0))
		return (dlist(0, push_front, dlist(0, pop_back, 0)) \
			|| dlist(1, push_front, dlist(1, pop_back, 0)));
	if (!ft_strncmp(line, "ra", 3) && dlist(0, size, 0))
		return (dlist(0, push_back, dlist(0, pop_front, 0)));
	if (!ft_strncmp(line, "rb", 3) && dlist(1, size, 0))
		return (dlist(1, push_back, dlist(1, pop_front, 0)));
	if (!ft_strncmp(line, "rr", 3) \
		&& dlist(0, size, 0) && dlist(1, size, 0))
		return (dlist(0, push_back, dlist(0, pop_front, 0)) \
			|| dlist(1, push_back, dlist(1, pop_front, 0)));
	return (1);
}

int	do_instruction(int tmp[], char *line)
{
	if (!ft_strncmp(line, "sa", 3) && dlist(0, size, 0) >= 2)
		return (list_swap(0, tmp));
	if (!ft_strncmp(line, "sb", 3) && dlist(1, size, 0) >= 2)
		return (list_swap(1, tmp));
	if (!ft_strncmp(line, "ss", 3) \
		&& dlist(0, size, 0) < 2 && dlist(1, size, 0) < 2)
		return (list_swap(0, tmp) || list_swap(1, tmp));
	if (!ft_strncmp(line, "pa", 3) && dlist(1, size, 0))
		return (dlist(0, push_front, dlist(1, pop_front, 0)));
	if (!ft_strncmp(line, "pb", 3) && dlist(0, size, 0))
		return (dlist(1, push_front, dlist(0, pop_front, 0)));
	return (do_instruction2(line));
}
