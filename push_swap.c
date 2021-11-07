/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:02:30 by mberger-          #+#    #+#             */
/*   Updated: 2021/11/07 12:39:36 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	print_moves(t_lst *moves)
{
	int				i;
	const	char	*(map[64]) = {
		[SWAP_A] = "sa", [SWAP_B] = "sb", [SWAP_BOTH] = "ss",
		[PUSH_A] = "pa", [PUSH_B] = "pb",
		[ROTATE_A] = "ra", [ROTATE_B] = "rb", [ROTATE_BOTH] = "rr",
		[RROTATE_A] = "rra", [RROTATE_B] = "rrb", [RROTATE_BOTH] = "rrr"
	};

	if (moves == NULL)
		return ;
	print_moves(moves->next);
	if (!moves->v || !map[moves->v])
		return ;
	i = -1;
	while (map[moves->v][++i])
		write(1, map[moves->v] + i, 1);
	write(1, "\n", 1);
}

void	sort(t_stack *stack)
{
	int		i;
	int		closest;

	i = lstsize(stack->a);
	if (i == 3 && stack->a->v > lstvat(stack->a, 1)
		&& stack->a->v > lstvat(stack->a, 2))
		rotate(stack, STACK_A);
	if (stack->a->v > stack->a->next->v)
		swap(stack, STACK_A);
	if (issorted(stack->a))
		return ;
	while (i-- > 1)
		if ((*lstlast(&stack->a))->v > stack->a->v)
			push(stack, STACK_B);
	else
		rotate(stack, STACK_A);
	while (stack->b)
	{
		if (lstsize(stack->a) > 10)
			find_lower_cost(stack);
		closest = lstgetclosest(stack->a, stack->b->v);
		rmove(stack, closest);
		push(stack, STACK_A);
	}
	rmove(stack, lstgetsmallest(stack->a) - 1);
}

void	push_swap(char **input)
{
	t_stack	stack;

	stacknew(input, &stack);
	if (!issorted(stack.a))
		sort(&stack);
	optimize_moves(&stack.moves);
	print_moves(stack.moves);
	stackclear(&stack);
}

//TODO check leaks
int	main(int argc, char **argv)
{
	int		len;
	char	**input;

	if (argc == 1)
		return (1);
	len = argc - 1;
	input = argv + 1;
	if (argc == 2)
		input = split(argv[1], ' ', &len);
	if (!input || len < 2)
		return (1);
	push_swap(input);
	if (argc == 2)
		free_splits(input, len);
	return (0);
}
