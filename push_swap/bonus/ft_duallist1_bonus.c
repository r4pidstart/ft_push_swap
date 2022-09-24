/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duallist1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:46:16 by tjo               #+#    #+#             */
/*   Updated: 2022/09/25 03:01:34 by tjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_header_bonus.h"

static int	dl_init(t_stack *stk)
{
	stk->front = (t_dl *)malloc(sizeof(t_dl));
	stk->back = (t_dl *)malloc(sizeof(t_dl));
	stk->front->prev = 0;
	stk->front->next = stk->back;
	stk->back->prev = stk->front;
	stk->back->next = 0;
	stk->size = 0;
	stk->front->data = -1;
	stk->back->data = -2;
	return (!stk->front || !stk->back);
}

static int	dl_pop_back(t_stack *stk)
{
	int		ret;
	t_dl	*tmp;

	tmp = stk->back->prev;
	ret = tmp->data;
	tmp->prev->next = stk->back;
	stk->back->prev = tmp->prev;
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

int	dlist(int stack, int cmd, int target)
{
	if (cmd == init)
		return (dl_init(get_list(stack)));
	else if (cmd == push_back)
		return (dl_push_back(get_list(stack), target));
	else if (cmd == push_front)
		return (dl_push_front(get_list(stack), target));
	else if (cmd == pop_back)
		return (dl_pop_back(get_list(stack)));
	else if (cmd == pop_front)
		return (dl_pop_front(get_list(stack)));
	else if (cmd == delete)
		return (dl_free(get_list(stack)));
	else if (cmd == size)
		return (get_list(stack)->size);
	else if (cmd == iterate)
		return (dl_iterate(get_list(stack), stack));
	else if (cmd == find)
		return (dl_find(get_list(stack), target));
	else if (cmd == modify)
		return (dl_modify(get_list(stack), target));
	return (-1);
}
