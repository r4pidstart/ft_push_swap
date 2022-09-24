/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duallist2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:08:46 by tjo               #+#    #+#             */
/*   Updated: 2022/09/25 02:28:10 by tjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_header.h"

int	dl_push_back(t_stack *stk, int target)
{
	t_dl	*tmp;

	tmp = (t_dl *)malloc(sizeof(t_dl));
	if (!tmp)
		return (1);
	tmp->data = target;
	tmp->next = stk->back;
	tmp->prev = stk->back->prev;
	tmp->prev->next = tmp;
	tmp->next->prev = tmp;
	stk->size++;
	return (0);
}

int	dl_push_front(t_stack *stk, int target)
{
	t_dl	*tmp;

	tmp = (t_dl *)malloc(sizeof(t_dl));
	if (!tmp)
		return (1);
	tmp->data = target;
	tmp->next = stk->front->next;
	tmp->prev = stk->front;
	tmp->next->prev = tmp;
	stk->front->next = tmp;
	stk->size++;
	return (0);
}

int	dl_iterate(t_stack *stk, int stack)
{
	static t_dl	*iter[2];
	int			ret;

	if (stk->size == 1)
		return (stk->front->next->data);
	if (!iter[stack])
		iter[stack] = stk->front->next;
	ret = iter[stack]->data;
	iter[stack] = iter[stack]->next;
	if (iter[stack] == stk->back)
		iter[stack] = 0;
	return (ret);
}

int	dl_find(t_stack *stk, int target)
{
	t_dl	*iter;
	int		cnt;

	iter = stk->front->next;
	cnt = 0;
	while (iter && iter->data != target)
	{
		cnt++;
		iter = iter->next;
	}
	return (cnt);
}

int	dl_modify(t_stack *stk, int target)
{
	static int	idx = 1;
	t_dl		*iter;

	iter = stk->front->next;
	while (iter != stk->back)
	{
		if (iter->data == target)
		{
			iter->data = idx++;
			return (0);
		}
		iter = iter->next;
	}
	return (1);
}
