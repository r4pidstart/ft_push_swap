/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duallist2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:08:46 by tjo               #+#    #+#             */
/*   Updated: 2022/09/13 23:58:17 by tjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_header_bonus.h"

int	dl_init(t_stack *stk)
{
	stk->front = (t_dl *)malloc(sizeof(t_dl));
	stk->back = (t_dl *)malloc(sizeof(t_dl));
	stk->front->prev = 0;
	stk->front->next = stk->back;
	stk->back->prev = stk->front;
	stk->back->next = 0;
	stk->size = 0;
	return (!stk->front || !stk->back);
}

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
	tmp->next = stk->front;
	tmp->prev = 0;
	tmp->next->prev = tmp;
	stk->front = tmp;
	stk->size++;
	return (0);
}

int	dl_iterate(t_stack *stk, int stack)
{
	static t_dl	*iter[2];
	int			ret;

	if (!iter[stack])
		iter[stack] = stk->front->next;
	ret = iter[stack]->data;
	iter[stack] = iter[stack]->next;
	if (iter[stack] == stk->back)
		iter[stack] = 0;
	return (ret);
}

int	dl_modify(t_stack *stk, int target)
{
	static t_dl	*iter;

	if (!iter)
		iter = stk->front->next;
	iter->data = target;
	iter = iter->next;
	if (iter == stk->back)
		iter = 0;
	return (0);
}