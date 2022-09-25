/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reading_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:44:30 by tjo               #+#    #+#             */
/*   Updated: 2022/09/25 15:43:13 by tjo              ###   ########.fr       */
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
	if (*cur == '\0')
		(*chk)++;
	while ('0' <= *cur && *cur <= '9')
		ret = ret * 10 + (*(cur++) - '0');
	if (minus_cnt)
		ret *= -1;
	if (*cur != '\0' || ft_strlen(str) > 11 \
		|| ret < INT32_MIN || ret > INT32_MAX)
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
		dlist(0, push_back, tmp);
		free(lst[idx++]);
	}
	free(lst);
	return (chk);
}

int	is_duplicated(void)
{
	t_dl	*p1;
	t_dl	*p2;

	p1 = get_list(0)->front->next;
	while (p1->next)
	{
		p2 = p1->next;
		while (p2->next)
		{
			if (p1->data == p2->data)
				return (1);
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	return (0);
}
