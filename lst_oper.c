/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_oper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 12:16:25 by mberger-          #+#    #+#             */
/*   Updated: 2021/11/07 15:20:31 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstswap(t_lst **a)
{
	int	v;

	if (!*a || !(*a)->next)
		return ;
	v = (*a)->v;
	(*a)->v = (*a)->next->v;
	(*a)->next->v = v;
}

void	lstpush(t_lst **a, t_lst **b)
{
	t_lst	*elm;

	if (!*a)
		return ;
	elm = *a;
	*a = (*a)->next;
	elm->next = *b;
	*b = elm;
}

void	lstrotate(t_lst **a)
{
	t_lst	*elm;

	if (!*a || !(*a)->next)
		return ;
	(*lstlast(a))->next = *a;
	elm = *a;
	*a = (*a)->next;
	elm->next = NULL;
}

void	lstrrotate(t_lst **a)
{
	t_lst	*elm;
	t_lst	*last;

	if (!*a || !(*a)->next)
		return ;
	last = *lstlast(a);
	*lstat(a, -1) = NULL;
	elm = *a;
	*a = last;
	last->next = elm;
}

int	issorted(t_lst *lst)
{
	while (lst)
	{
		if (lst->next && lst->v > lst->next->v)
			return (0);
		lst = lst->next;
	}
	return (1);
}
