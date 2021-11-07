/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:58:50 by mberger-          #+#    #+#             */
/*   Updated: 2021/11/07 14:33:53 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stacknew(char **input, int i, t_stack	*stack)
{
	int		e;
	int		n;
	t_lst	*elm;

	stack->a = NULL;
	stack->b = NULL;
	stack->moves = NULL;
	while (i--)
	{
		e = ft_atoi(*input++, &n);
		elm = lstnew(n);
		if (e || elm == NULL || lstcontains(stack->a, n))
		{
			free(elm);
			stackclear(stack);
			err();
		}
		if (stack->a == NULL)
			stack->a = elm;
		else
			(*lstlast(&stack->a))->next = elm;
	}
}

void	stackclear(t_stack *stack)
{
	lstclear(&stack->a);
	lstclear(&stack->b);
	lstclear(&stack->moves);
}
