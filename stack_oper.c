/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_oper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:05:56 by mberger-          #+#    #+#             */
/*   Updated: 2021/11/06 17:31:01 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_move(t_stack *stack, enum e_action both, enum e_action act,
		enum e_action with)
{
	t_lst	*move;
	t_lst	*moves;

	moves = stack->moves;
	if (moves)
		while (moves->v == (int)both)
			moves = moves->next;
	if (moves && moves->v == (int)with)
		moves->v = both;
	else
	{
		move = lstnew(act);
		lstpush(&move, &stack->moves);
	}
}

void	swap(t_stack *stack, enum e_action on)
{
	if (on & STACK_A)
		lstswap(&stack->a);
	if (on & STACK_B)
		lstswap(&stack->b);
	push_move(stack, SWAP_BOTH, (on & STACK_BOTH) | SWAP,
			((on ^ STACK_BOTH) & STACK_BOTH) | SWAP);
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
	lstpush(&action, &stack->moves);
}

void	rotate(t_stack *stack, enum e_action on)
{
	if (on & STACK_A)
		lstrotate(&stack->a);
	if (on & STACK_B)
		lstrotate(&stack->b);
	push_move(stack, ROTATE_BOTH, (on & STACK_BOTH) | ROTATE,
			((on ^ STACK_BOTH) & STACK_BOTH) | ROTATE);
}

void	rrotate(t_stack *stack, enum e_action on)
{
	if (on & STACK_A)
		lstrrotate(&stack->a);
	if (on & STACK_B)
		lstrrotate(&stack->b);
	push_move(stack, RROTATE_BOTH, (on & STACK_BOTH) | RROTATE,
			((on ^ STACK_BOTH) & STACK_BOTH) | RROTATE);
}

void	rmove(t_stack *stack, int i)
{
	int	size;

	size = lstsize(stack->a);
	if (i < size  / 2)
		while (i-- > 0)
			rotate(stack, STACK_A);
	else
		while (i++ < size)
			rrotate(stack, STACK_A);
}
