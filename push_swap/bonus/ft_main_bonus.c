/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 02:43:26 by tjo               #+#    #+#             */
/*   Updated: 2022/09/25 03:26:48 by tjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_header_bonus.h"

t_stack	*get_list(int num)
{
	static t_stack	stk[2];

	return (&stk[num]);
}

static int	read_lines(void)
{
	char	*line;
	int		tmp[2];

	(void)tmp;
	line = get_next_line(0);
	while (line)
	{
		if (do_instruction(tmp, line))
		{
			ft_printf("%s", line);
			free(line);
			return (1);
		}
		free(line);
		line = get_next_line(0);
	}
	return (0);
}

static void	check(void)
{
	int		flag;
	long	prev;
	int		tmp;

	flag = 0;
	prev = (long)INT32_MIN - 1;
	flag += dlist(1, size, 0);
	while (dlist(0, size, 0))
	{
		tmp = dlist(0, pop_front, 0);
		ft_printf("%d ", tmp);
		flag += (prev > tmp);
		prev = tmp;
	}
	dlist(0, delete, 0);
	dlist(1, delete, 0);
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
	if (dlist(0, init, 0) || dlist(1, init, 0))
		return (!ft_printf("Malloc failed\n"));
	idx = 1;
	while (idx < argc)
	{
		if (read_argument(argv[idx++]))
		{
			dlist(0, delete, 0);
			dlist(1, delete, 0);
			return (!ft_printf("Error\n"));
		}	
	}
	// compress();
	if (read_lines())
	{
		dlist(0, delete, 0);
		dlist(1, delete, 0);
		return (!ft_printf("Wrong instruction\n"));
	}
	check();
}
