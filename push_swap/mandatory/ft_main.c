/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 02:43:26 by tjo               #+#    #+#             */
/*   Updated: 2022/09/25 01:35:19 by tjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_header.h"

static int	print_error(void)
{
	ft_lstclear(record(pointer), free);
	duallist(0, delete, 0);
	duallist(1, delete, 0);
	return (!write(2, "Error\n", 6));
}

int	main(int argc, char **argv)
{
	int	idx;

	if (argc == 1)
		return (print_error());
	if (duallist(0, init, 0) || duallist(1, init, 0))
		return (print_error());
	idx = 1;
	while (idx < argc)
	{
		if (read_argument(argv[idx++]))
			return (print_error());
	}
	if (compress() || sort())
		return (print_error());
	print();
}