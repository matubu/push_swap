/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:38:24 by mberger-          #+#    #+#             */
/*   Updated: 2021/11/07 13:38:28 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc(int a, int b, int same)
{
	if (same)
	{
		if (a > b)
			return (a);
		return (b);
	}
	return (a + b);
}

#define MAX 81
#define HALF 40

int	getcost(t_stack *stack, int bi)
{
	int	ai;
	int	mn;
	int	size;
	int	backward;

	ai = lstgetclosest(stack->a, lstvat(stack->b, bi));
	size = lstsize(stack->a);
	backward = 1;
	if (ai <= size / 2 && backward--)
		mn = ai;
	else
		mn = size - ai;
	return (calc(mn, ft_abs(bi), (bi < 0) == backward));
}

void	find_lower_cost(t_stack *stack)
{
	int		c[MAX];
	int		i;
	int		j;

	i = -1;
	while (++i < MAX)
		c[i] = getcost(stack, i - HALF);
	i = -1;
	while (++i < MAX)
	{
		j = i;
		while (++j < MAX)
			if (c[i] > c[j])
				break ;
		if (j == MAX)
		{
			if (i < HALF)
				while (i++ < HALF)
					rrotate(stack, STACK_B);
			else if (i > HALF)
				while (i-- > HALF)
					rotate(stack, STACK_B);
			return ;
		}
	}
}

void	rmove(t_stack *stack, int i)
{
	int	size;

	size = lstsize(stack->a);
	if (i <= size / 2)
		while (i-- > 0)
			rotate(stack, STACK_A);
	else
		while (i++ < size)
			rrotate(stack, STACK_A);
}
