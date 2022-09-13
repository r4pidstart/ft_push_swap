/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duallist1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:46:16 by tjo               #+#    #+#             */
/*   Updated: 2022/09/13 19:36:10 by tjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_header_bonus.h"

static int	dl_pop_back(t_stack *stk)
{
	int		ret;
	t_dl	*tmp;

	tmp = stk->back->prev;
	ret = tmp->data;
	stk->back->prev->next = stk->back;
	stk->back->prev = stk->back->prev->prev;
	free(tmp);
	stk->size--;
	return (ret);
}

static int	dl_pop_front(t_stack *stk)
{
	int		ret;
	t_dl	*tmp;

	tmp = stk->front->next;
	ret = tmp->data;
	tmp->next->prev = stk->front;
	stk->front->next = tmp->next;
	free(tmp);
	stk->size--;
	return (ret);
}

static int	dl_free(t_stack *stk)
{
	t_dl	*tmp;

	while (stk->front)
	{
		tmp = stk->front;
		stk->front = stk->front->next;
		free(tmp);
	}
	return (0);
}

static int	get(t_stack *stk, int cmd)
{
	if (cmd == front)
		return (stk->front->next->data);
	else if (cmd == second_front)
		return (stk->front->next->next->data);
	else if (cmd == back)
		return (stk->back->prev->data);
	else if (cmd == second_back)
		return (stk->back->prev->prev->data);
	else
		return (-1);
}

int	duallist(int stack, int cmd, int target)
{
	static t_stack	stk[2];

	if (cmd == init)
		return (dl_init(&stk[stack]));
	else if (cmd == push_back)
		return (dl_push_back(&stk[stack], target));
	else if (cmd == push_front)
		return (dl_push_front(&stk[stack], target));
	else if (cmd == pop_back)
		return (dl_pop_back(&stk[stack]));
	else if (cmd == pop_front)
		return (dl_pop_front(&stk[stack]));
	else if (cmd == delete)
		return (dl_free(&stk[stack]));
	else if (cmd == size)
		return (stk[stack].size);
	else
		return (get(&stk[stack], cmd));
}
