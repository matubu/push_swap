/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:01:14 by mberger-          #+#    #+#             */
/*   Updated: 2021/11/05 14:15:19 by mberger-         ###   ########.fr       */
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

void	lstdel(t_lst **lst)
{
	t_lst	*temp;

	temp = (*lst)->next;
	free(*lst);
	*lst = temp;
}
