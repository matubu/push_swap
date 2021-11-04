/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:02:30 by mberger-          #+#    #+#             */
/*   Updated: 2021/11/04 19:06:39 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err(void)
{
	write(2, "Error\n", 6);
	while (1)
		;
	exit(1);
}

#include <stdio.h>

void	print_stacks(t_stack *stack)
{
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

	stack = stacknew(input);

	print_stacks(stack);

	i = lstsize(stack->a);
	while (i-- > 0)
	{
		if (stack->a->v > stack->a->next->v)
		{
			printf("push\n");
			lstpush(&stack->a, &stack->b);
			print_stacks(stack);
		}
		else
		{
			printf("rotate\n");
			lstrotate(&stack->a);
			print_stacks(stack);
		}
	}

/*
	printf("swap\n");
	lstswap(&stack->a);
	push_swap(stack);
	printf("swap\n");
	lstswap(&stack->a);
	push_swap(stack);

	printf("push\n");
	lstpush(&stack->b, &stack->a);
	push_swap(stack);
	printf("push\n");
	lstpush(&stack->b, &stack->a);
	push_swap(stack);

	printf("rotate\n");
	lstrotate(&stack->a);
	push_swap(stack);
	printf("rotate\n");
	lstrotate(&stack->a);
	push_swap(stack);

	printf("rrotate\n");
	lstrrotate(&stack->a);
	push_swap(stack);
	printf("rrotate\n");
	lstrrotate(&stack->a);
	push_swap(stack);
*/
	stackclear(stack);
	return (NULL);
}

//TODO error same value
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
	while (1)
		;
	return (0);
}
