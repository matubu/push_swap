/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:58:50 by mberger-          #+#    #+#             */
/*   Updated: 2021/11/07 10:48:06 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stacknew(char **input, t_stack	*stack)
{
	int		e;
	int		n;
	t_lst	*elm;

	stack->a = NULL;
	while (*input)
	{
		e = ft_atoi(*input++, &n);
		elm = lstnew(n);
		if (e || elm == NULL)
		{
			stackclear(stack);
			err();
		}
		if (stack->a == NULL)
			stack->a = elm;
		else
			(*lstlast(&stack->a))->next = elm;
	}
	stack->b = NULL;
	stack->moves = NULL;
	return (stack);
}

void	stackclear(t_stack *stack)
{
	lstclear(&stack->a);
	lstclear(&stack->b);
	lstclear(&stack->moves);
}
