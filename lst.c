/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:01:14 by mberger-          #+#    #+#             */
/*   Updated: 2021/11/04 18:31:24 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*lstnew(int v)
{
	t_lst	*elm;

	elm = malloc(sizeof(t_lst));
	if (elm == NULL)
		return (NULL);
	elm->v = v;
	elm->next = NULL;
	return (elm);
}

int	lstsize(t_lst *lst)
{
	int	size;

	size = 0;
	while (lst && ++size)
		lst = lst->next;
	return (size);
}

t_lst	**lstat(t_lst **a, int i)
{
	if (i < 0)
	{
		i = lstsize(*a) + i;
		if (i < 0)
			return (NULL);
		lstat(a, lstsize(*a) + i);
	}
	while (i--)
		if (*a)
			a = &(*a)->next;
	else
		return (NULL);
	return (a);
}

t_lst	**lstlast(t_lst **lst)
{
	while (*lst && (*lst)->next)
		lst = &(*lst)->next;
	return (lst);
}

void	lstclear(t_lst **lst)
{
	if (*lst == NULL)
		return ;
	lstclear(&(*lst)->next);
	free(*lst);
	*lst = NULL;
}
