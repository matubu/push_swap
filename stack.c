/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:58:50 by mberger-          #+#    #+#             */
/*   Updated: 2021/11/04 17:31:43 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stacknew(char **input)
{
	int		e;
	int		n;
	t_stack	*stack;
	t_lst	*elm;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->a = NULL;
	while (*input)
	{
		e = ft_atoi(*input++, &n);
		elm = lstnew(n);
		if (stack->a == NULL)
			stack->a = elm;
		else
			(*lstlast(&stack->a))->next = elm;
		if (e || elm == NULL)
		{
			lstclear(&stack->a);
			err();
		}
	}
	stack->b = NULL;
	return (stack);
}

void	stackclear(t_stack *stack)
{
	lstclear(&stack->a);
	lstclear(&stack->b);
	free(stack);
}
