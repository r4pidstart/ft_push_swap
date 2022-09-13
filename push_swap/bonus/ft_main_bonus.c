/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 02:43:26 by tjo               #+#    #+#             */
/*   Updated: 2022/09/13 22:51:07 by tjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_header_bonus.h"

static int	read_lines(void)
{
	char	*line;
	int		tmp[2];

	(void)tmp;
	line = get_next_line(0);
	while (line)
	{
		if (do_instruction(tmp, line))
			return (1);
		line = get_next_line(0);
	}
}

static void	check(void)
{
	int		flag;
	long	prev;
	int		tmp;

	flag = 0;
	prev = -2147483648 - 1;
	flag += duallist(1, size, 0);
	while (duallist(0, size, 0))
	{
		tmp = duallist(0, pop_front, 0);
		flag += (prev > tmp);
		prev = tmp;
	}
	duallist(0, delete, 0);
	duallist(1, delete, 0);
	if (flag)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}

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
			return (!ft_printf("Wrong argument\n"));
		}	
	}
	if (read_lines())
	{
		duallist(0, delete, 0);
		duallist(1, delete, 0);
		return (!ft_printf("Wrong instruction\n"));
	}
	check();
}