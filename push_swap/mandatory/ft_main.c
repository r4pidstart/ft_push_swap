/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 02:43:26 by tjo               #+#    #+#             */
/*   Updated: 2022/09/14 00:17:17 by tjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_header.h"

int	main(int argc, char **argv)
{
	int	idx;

	if (argc == 1)
		return (!ft_printf("No argument\n"));
	if (duallist(0, init, 0) || duallist(1, init, 0))
		return (!ft_printf("Malloc failed\n"));
	idx = 1;
	while (idx < argc)
	{
		if (read_argument(argv[idx++]))
		{
			duallist(0, delete, 0);
			duallist(1, delete, 0);
			return (!ft_printf("Error\n"));
		}	
	}
	if (compress())
	{
		duallist(0, delete, 0);
		duallist(1, delete, 0);
		return (!ft_printf("Error\n"));
	}
}
