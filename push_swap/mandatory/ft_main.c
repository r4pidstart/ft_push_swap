/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 02:43:26 by tjo               #+#    #+#             */
/*   Updated: 2022/09/25 02:58:26 by tjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_header.h"

t_stack	*get_list(int num)
{
	static t_stack	stk[2];

	return (&stk[num]);
}

static int	print_error(void)
{
	ft_lstclear(record(pointer), free);
	dlist(0, delete, 0);
	dlist(1, delete, 0);
	return (!write(2, "Error\n", 6));
}

int	main(int argc, char **argv)
{
	int	idx;

	if (argc == 1)
		return (print_error());
	if (dlist(0, init, 0) || dlist(1, init, 0))
		return (print_error());
	idx = 1;
	while (idx < argc)
	{
		if (read_argument(argv[idx++]))
			return (print_error());
	}
	if (compress() || partitioning() || merging())
		return (print_error());
	while (dlist(1, size, 0))
		if (greedy_method())
			return (print_error());
	if (one_to_top())
		return (print_error());
	print();
}
