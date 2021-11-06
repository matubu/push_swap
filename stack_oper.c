/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_oper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:05:56 by mberger-          #+#    #+#             */
/*   Updated: 2021/11/06 10:38:46 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, enum e_action on)
{
	t_lst	*action;

	if (on & STACK_A)
		lstswap(&stack->a);
	if (on & STACK_B)
		lstswap(&stack->b);
	action = lstnew(SWAP | (on & STACK_BOTH));
	DEBUG("\t\tswap()\n");
	lstpush(&action, &stack->moves);
}

void	push(t_stack *stack, enum e_action on)
{
	t_lst	*action;

	if ((on & STACK_BOTH) == STACK_BOTH)
		return ;
	if (on & STACK_A)
	{
		lstpush(&stack->b, &stack->a);
		action = lstnew(PUSH_A);
	}
	else if (on & STACK_B)
	{
		lstpush(&stack->a, &stack->b);
		action = lstnew(PUSH_B);
	}
	else
		return ;
	DEBUG("\t\tpush()\n");
	lstpush(&action, &stack->moves);
}

void	rotate(t_stack *stack, enum e_action on)
{
	t_lst	*action;

	if (on & STACK_A)
		lstrotate(&stack->a);
	if (on & STACK_B)
		lstrotate(&stack->b);
	action = lstnew(ROTATE | (on & STACK_BOTH));
	DEBUG("\t\trotate()\n");
	lstpush(&action, &stack->moves);
}

void	rrotate(t_stack *stack, enum e_action on)
{
	t_lst	*action;

	if (on & STACK_A)
		lstrrotate(&stack->a);
	if (on & STACK_B)
		lstrrotate(&stack->b);
	action = lstnew(RROTATE | (on & STACK_BOTH));
	DEBUG("\t\trrotate()\n");
	lstpush(&action, &stack->moves);
}

void	rmove(t_stack *stack, int i)
{
	int	size;

	size = lstsize(stack->a);
	if (i <= size  / 2)
		while (i-- > 0)
			rotate(stack, STACK_A);
	else
		while (i++ < size)
			rrotate(stack, STACK_A);
}
