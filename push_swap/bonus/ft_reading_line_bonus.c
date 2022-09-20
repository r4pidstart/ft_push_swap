/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reading_line_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 22:39:29 by tjo               #+#    #+#             */
/*   Updated: 2022/09/21 02:22:12 by tjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_header_bonus.h"

static int	list_swap(int stk, int tmp[])
{
	tmp[0] = duallist(stk, pop_front, 0);
	tmp[1] = duallist(stk, pop_front, 0);
	duallist(stk, push_front, tmp[0]);
	duallist(stk, push_front, tmp[1]);
	return (0);
}

static int	do_instruction2(char *line)
{
	if (!ft_strncmp(line, "ra", -1) && duallist(0, size, 0))
		return (duallist(0, push_back, duallist(0, pop_front, 0)));
	if (!ft_strncmp(line, "rb", -1) && duallist(1, size, 0))
		return (duallist(1, push_back, duallist(1, pop_front, 0)));
	if (!ft_strncmp(line, "rr", -1) \
		&& duallist(0, size, 0) && duallist(1, size, 0))
		return (duallist(0, push_back, duallist(0, pop_front, 0)) \
			|| duallist(1, push_back, duallist(1, pop_front, 0)));
	if (!ft_strncmp(line, "rra", -1) && duallist(0, size, 0))
		return (duallist(0, push_front, duallist(0, pop_back, 0)));
	if (!ft_strncmp(line, "rrb", -1) && duallist(1, size, 0))
		return (duallist(1, push_front, duallist(1, pop_back, 0)));
	if (!ft_strncmp(line, "rrr", -1) \
	&& duallist(0, size, 0) && duallist(1, size, 0))
		return (duallist(0, push_front, duallist(0, pop_back, 0)) \
			|| duallist(1, push_front, duallist(1, pop_back, 0)));
	return (1);
}

int	do_instruction(int tmp[], char *line)
{
	if (!ft_strncmp(line, "sa", -1) && duallist(0, size, 0) < 2)
		return (list_swap(0, tmp));
	if (!ft_strncmp(line, "sb", -1) && duallist(1, size, 0) < 2)
		return (list_swap(1, tmp));
	if (!ft_strncmp(line, "ss", -1) \
		&& duallist(0, size, 0) < 2 && duallist(1, size, 0) < 2)
		return (list_swap(0, tmp) || list_swap(1, tmp));
	if (!ft_strncmp(line, "pa", -1) && duallist(1, size, 0))
		return (duallist(0, push_front, duallist(1, pop_front, 0)));
	if (!ft_strncmp(line, "pb", -1) && duallist(0, size, 0))
		return (duallist(1, push_front, duallist(0, pop_front, 0)));
	return (do_instruction2(line));
}