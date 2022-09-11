/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duallist2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:08:46 by tjo               #+#    #+#             */
/*   Updated: 2022/09/12 00:14:53 by tjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_header.h"

int	dl_init(t_stack *stk)
{
	stk->front = (t_dl *)malloc(sizeof(t_dl));
	stk->back = stk->front;
	stk->size = 0;
	return (!stk->front);
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
	stk->back->prev->next = tmp;
	stk->back->prev = tmp;
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
	stk->front->prev = tmp;
	stk->front = tmp;
	stk->size++;
	return (0);
}