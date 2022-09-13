/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reading_arg_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:44:30 by tjo               #+#    #+#             */
/*   Updated: 2022/09/13 22:56:38 by tjo              ###   ########.fr       */
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
	if (*cur != '\0' || ft_strlen(str) > 11 \
		|| ret < -2147483648 || ret > 2147483647)
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