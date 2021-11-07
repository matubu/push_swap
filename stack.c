/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:58:50 by mberger-          #+#    #+#             */
/*   Updated: 2021/11/07 12:00:40 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stacknew(char **input, t_stack	*stack)
{
	int		e;
	int		n;
	t_lst	*elm;

	stack->a = NULL;
	stack->b = NULL;
	stack->moves = NULL;
	while (*input)
	{
		e = ft_atoi(*input++, &n);
		elm = lstnew(n);
		if (e || elm == NULL || lstcontains(stack->a, n))
		{
			DEBUG("CLEARING UP ELM\n");
			free(elm);
			DEBUG("CLEARING UP STACK\n");
			stackclear(stack);
			DEBUG("GENERATING ERROR\n");
			err();
		}
		if (stack->a == NULL)
			stack->a = elm;
		else
			(*lstlast(&stack->a))->next = elm;
	}
	return (stack);
}

void	stackclear(t_stack *stack)
{
	DEBUG("CLEARING UP STACK A\n");
	lstclear(&stack->a);
	DEBUG("CLEARING UP STACK B\n");
	lstclear(&stack->b);
	DEBUG("CLEARING UP MOVES\n");
	lstclear(&stack->moves);
}
