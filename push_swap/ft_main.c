/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 02:43:26 by tjo               #+#    #+#             */
/*   Updated: 2022/09/12 00:42:47 by tjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_header.h"

static int	ft_custom_atoi(const char *str, int *chk)
{
	char		*cur;
	int			minus_cnt;
	long long	ret;

	cur = (char *)str;
	while ((9 <= *cur && *cur <= 13) || *cur == 20 || *cur == 32)
		cur++;
	ret = 0;
	minus_cnt = 0;
	if ('+' == *cur || '-' == *cur)
	{
		if (*cur == '-')
			minus_cnt++;
		cur++;
	}
	while ('0' <= *cur && *cur <= '9')
		ret = ret * 10 + (*(cur++) - '0');
	if (minus_cnt)
		ret *= -1;
	if (*cur != '\0')
		(*chk)++;
	return (ret);
}

int	read_argument(char *str)
{
	char	**lst;
	int		idx;
	int		chk;
	int		tmp;

	lst = ft_split(str, ' ');
	if (!lst)
		return (1);
	idx = 0;
	chk = 0;
	while (lst[idx])
	{
		tmp = ft_custom_atoi(lst[idx], &chk);
		duallist(0, push_back, tmp);
		free(lst[idx++]);
	}
	free(lst);
	return (chk);
}

int	main(int argc, char **argv)
{
	int	idx;

	if (argc == 1)
		return (!ft_printf("No argument\n"));
	if (duallist(0, init, 0) || duallist(1, init, 0))
		return (!ft_printf("Malloc fail\n"));
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

	while (duallist(0, size, 0))
	{
		ft_printf("%d ", duallist(0, pop_front, 0));
	}
}