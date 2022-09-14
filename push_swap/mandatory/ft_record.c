/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_record.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:54:10 by tjo               #+#    #+#             */
/*   Updated: 2022/09/14 20:19:04 by tjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_header.h"

static int	make_node(int type)
{
	int	*tmp;

	tmp = (int *)malloc(sizeof(int));
	if (!tmp)
		return (0);
	*tmp = type;
	return (tmp);
}

t_list	**record(int type)
{
	static t_list	*lst;
	int				*node;

	if (type == pointer)
		return (&lst);
	else
	{
		node = make_node(type);
		if (!node)
			return (1);
		ft_lstadd_back(&lst, ft_lstnew(node));
		return (0);
	}
}