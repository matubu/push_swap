/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:02:30 by mberger-          #+#    #+#             */
/*   Updated: 2021/11/05 10:34:54 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err(void)
{
	write(2, "Error\n", 6);
	//while (1)
	//	;
	exit(1);
}

#include <stdio.h>

void	print_stacks(t_stack *stack)
{
	(void)stack;
	t_lst	*a;
	t_lst	*b;

	a = stack->a;
	b = stack->b;
	while (a || b)
	{
		if (a && b)
			printf("-> %5i %5i\n", a->v, b->v);
		else if (a)
			printf("-> %5i %5s\n", a->v, NULL);
		else
			printf("-> %5s %5i\n", NULL, b->v);
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
}

t_stack	*sort(char **input)
{
	t_stack *stack;
	int		i;
	int		closest;
	t_lst	*closest_elm;
	int		size;

	stack = stacknew(input);

	print_stacks(stack);

	printf("step 1 (push to stack b)\n");
	i = lstsize(stack->a);
	while (i-- > 0 && stack->a->next)
	{
		if (stack->a->v > stack->a->next->v)
		{
			printf("pb\n");
			lstpush(&stack->a, &stack->b);
			print_stacks(stack);
		}
		else
		{
			printf("ra\n");
			lstrotate(&stack->a);
			print_stacks(stack);
		}
		if (i == -1)
		{
			if (stack->a->v > (*lstlast(&stack->a))->v
					|| stack->a->v < stack->a->next->v)
				break ;
			printf("pb\n");
			lstpush(&stack->a, &stack->b);
			print_stacks(stack);
		}
	}
	printf("step 2 (push back to stack a)\n");
	i = lstsize(stack->b);
	while (i-- > 0)
	{
		closest = lstgetclosest(stack->a, stack->b->v, &closest_elm);
		if (closest_elm->v > stack->b->v)
			closest--;
		size = lstsize(stack->a);
		if (closest <= size  / 2)
			while (closest-- > 0)
			{
				printf("ra\n");
				lstrotate(&stack->a);
				print_stacks(stack);
			}
		else
			while (closest++ < size)
			{
				printf("rra\n");
				lstrrotate(&stack->a);
				print_stacks(stack);
			}
		printf("pa\n");
		lstpush(&stack->b, &stack->a);
		print_stacks(stack);
	}
	printf("step 3 (recenter)\n");
	i = lstgetsmallest(stack->a);
	while (--i > 0)
	{
		printf("ra\n");
		lstrotate(&stack->a);
		print_stacks(stack);
	}
	//printf("sorting completed\n");
	stackclear(stack);


	//step 4 (optimize)
	return (NULL);
}

//TODO error with double values
int	main(int argc, char **argv)
{
	int		len;
	char	**input;

	if (argc == 1)
		err();
	len = argc - 1;
	input = argv + 1;
	if (argc == 2)
		input = split(argv[1], ' ', &len);
	if (!input || len < 2)
		err();
	sort(input);
	if (argc == 2)
		free_splits(input, len);
	//while (1)
	//	;
	return (0);
}
