/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 12:12:48 by mberger-          #+#    #+#             */
/*   Updated: 2021/11/07 12:17:33 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lstgetclosest(t_lst *a, int v)
{
	int		diff;
	int		bestdiff;
	int		best;
	int		i;
	int		fv;

	bestdiff = ft_abs(v - a->v);
	fv = a->v;
	best = 1;
	i = 1;
	while (a->next && i++)
	{
		a = a->next;
		diff = ft_abs(v - a->v);
		if (diff < bestdiff)
		{
			bestdiff = diff;
			fv = a->v;
			best = i;
		}
	}
	if (fv > v)
		best--;
	return (best);
}

int	lstgetsmallest(t_lst *a)
{
	int		bestv;
	int		best;
	int		i;

	if (a == NULL)
		return (0);
	bestv = a->v;
	i = 1;
	best = 1;
	while (a->next && i++)
	{
		a = a->next;
		if (a->v < bestv)
		{
			bestv = a->v;
			best = i;
		}
	}
	return (best);
}

t_lst	**lstat(t_lst **a, int i)
{
	if (i < 0)
	{
		i = lstsize(*a) + i;
		if (i < 0)
			return (NULL);
	}
	while (i--)
		if (*a)
			a = &(*a)->next;
	else
		return (NULL);
	return (a);
}

int	lstvat(t_lst *a, int i)
{
	int	v;

	v = a->v;
	if (i < 0)
	{
		i = lstsize(a) + i;
		if (i < 0)
			return (v);
	}
	while (i--)
		if (a)
			a = a->next;
	else
		break ;
	if (a == NULL)
		return (v);
	return (a->v);
}

int	lstcontains(t_lst *a, int v)
{
	while (a)
	{
		if (a->v == v)
			return (1);
		a = a->next;
	}
	return (0);
}
