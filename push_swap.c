/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:02:30 by mberger-          #+#    #+#             */
/*   Updated: 2021/11/07 09:46:21 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	mid(t_lst *moves, int n)
{
	int	move;

	move = 0;
	while (n-- && moves)
	{
		move |= moves->v << n * 6;
		moves = moves->next;
	}
	return (move);
}

//remember moves are inversed
int	optimize_moves(t_lst **moves)
{
	int		b;

	b = 0;
	if (*moves == NULL)
		return (0);
	while (optimize_moves(&(*moves)->next))
		b = 1;
	if (mid(*moves, 2) == (PUSH_B | PUSH_A << 6) 
			|| mid(*moves, 2) == (PUSH_A | PUSH_B << 6)
			|| mid(*moves, 2) == (ROTATE_A | RROTATE_A << 6)
			|| mid(*moves, 2) == (RROTATE_A | ROTATE_A << 6))
	{
		DEBUG(">> usless\n");
		lstdel(moves);
		lstdel(moves);
	}
	else if (mid(*moves, 3) == (PUSH_B | ROTATE_A << 6 | PUSH_A << 12))
	{
		DEBUG(">> pb ra pa\n");
		lstdel(moves);
		(*moves)->next->v = SWAP_A;
		(*moves)->v = ROTATE_A;
	}
	else if (mid(*moves, 3) == (ROTATE_A | PUSH_A << 6 | RROTATE_A << 12))
	{
		DEBUG(">> ra pa rra\n");
		lstdel(moves);
		(*moves)->next->v = PUSH_A;
		(*moves)->v = SWAP_A;
	}
	else if (mid(*moves, 4) == (PUSH_B | SWAP_A << 6 | PUSH_A << 12 | ROTATE_A << 18))
	{
		DEBUG(">> pb sa pa ra\n");
		lstdel(moves);
		lstdel(moves);
		(*moves)->next->v = ROTATE_A;
		(*moves)->v = SWAP_A;
	}
	else if (mid(*moves, 4) == (ROTATE_A | PUSH_B << 6 | RROTATE_A << 12 | PUSH_A << 18))
	{
		DEBUG(">> ra pb rra pa\n");
		lstdel(moves);
		lstdel(moves);
		lstdel(moves);
		(*moves)->v = SWAP_A;
	}
	else
		return (b);
	return (1);
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

# define MAX 81
# define HALF 40

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

int	getcost(t_stack *stack, int bi)
{
	int	ai;
	int	mn;
	int	size;
	int	backward;

	ai = lstgetclosest(stack->a, lstvat(stack->b, bi));
	size = lstsize(stack->a);
	backward = 1;
	if (ai < size / 2 && backward--)
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
/*
int	isrestsorted(t_lst *lst, int i)
{
	while (lst && i--)
	{
		if (lst->next && lst->v < lst->next->v)
			return (0);
		lst = lst->next;
	}
	return (1);
}
*/
int	issorted(t_lst *lst)
{
	while (lst)
	{
		if (lst->next && lst->v > lst->next->v)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	sort(t_stack *stack)
{
	int		i;
	int		closest;

	DEBUG("\t-> 0 (push to stack b)\n");
	i = lstsize(stack->a);
	if (i <= 3)
		i--;
	if (stack->a->v > stack->a->next->v)
		swap(stack, STACK_A);
	if (issorted(stack->a))
		return ;
	rotate(stack, STACK_A);//avoid rotate and try swap ...
	rotate(stack, STACK_A);//avoid rotate and try swap ...
	while (i-- > 2)
	{
		//if (stack->a->v > stack->a->next->v)
		//	swap(stack, STACK_A);
		if ((*lstlast(&stack->a))->v > stack->a->v)
			push(stack, STACK_B);
			//TODO presort
		else// if (!isrestsorted(stack->a, i))
			rotate(stack, STACK_A);
	}
	DEBUG("\t-> 1 (push back to stack a)\n");
	while (stack->b)
	{
		if (lstsize(stack->a) > 10)
			find_lower_cost(stack);
		closest = lstgetclosest(stack->a, stack->b->v);
		rmove(stack, closest);
		push(stack, STACK_A);
	}
	DEBUG("\t-> 2 (recenter)\n");
	rmove(stack, lstgetsmallest(stack->a) - 1);

}

void	write_tab(t_lst *a)
{
	while (a)
	{
		DEBUG("-> | %i\n", a->v);
		a = a->next;
	}
}

t_stack	*push_swap(char **input)
{
	t_stack *stack;

	DEBUG("step 0 (create stack)\n");
	stack = stacknew(input);
	write_tab(stack->a);
	DEBUG("step 1 (sort)\n");
	if (!issorted(stack->a))
		sort(stack);
	else
		DEBUG("already sorted\n");
	DEBUG("step 2 (optimize)\n");
	if (DEBUG_MODE)
		print_moves(stack->moves);
	optimize_moves(&stack->moves);
	DEBUG("step 3 (print)\n");
	print_moves(stack->moves);
	DEBUG("step 4 (clear)\n");
	stackclear(stack);
	return (NULL);
}

//TODO error with double values
//TODO multiple spaces
//TODO maxint fail
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
