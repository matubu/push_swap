/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:21:20 by mberger-          #+#    #+#             */
/*   Updated: 2021/11/07 15:43:44 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

char	*gnl(void)
{
	char	buf;
	char	*line;

	line = NULL;
	while (read(0, &buf, 1) && buf != '\n')
		line = ft_strjoin(line, buf);
	return (line);
}

void	stack_cmd(t_stack *stack, char *s)
{
	if (!ft_strcmp(s, "sa"))
		swap(stack, STACK_A);
	else if (!ft_strcmp(s, "sb"))
		swap(stack, STACK_B);
	else if (!ft_strcmp(s, "ss"))
		swap(stack, STACK_BOTH);
	else if (!ft_strcmp(s, "pa"))
		push(stack, STACK_A);
	else if (!ft_strcmp(s, "pb"))
		push(stack, STACK_B);
	else if (!ft_strcmp(s, "ra"))
		rotate(stack, STACK_A);
	else if (!ft_strcmp(s, "rb"))
		rotate(stack, STACK_B);
	else if (!ft_strcmp(s, "rr"))
		rotate(stack, STACK_BOTH);
	else if (!ft_strcmp(s, "rra"))
		rrotate(stack, STACK_A);
	else if (!ft_strcmp(s, "rrb"))
		rrotate(stack, STACK_B);
	else if (!ft_strcmp(s, "rrr"))
		rrotate(stack, STACK_BOTH);
	else
		err();
}

int	main(int argc, char **argv)
{
	char	*s;
	t_stack	stack;

	if (argc < 2)
		return (0);
	stacknew(argv + 1, argc - 1, &stack);
	while (1)
	{
		s = gnl();
		if (s == NULL)
			break ;
		stack_cmd(&stack, s);
		free(s);
	}
	if (issorted(stack.a) && stack.b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	stackclear(&stack);
	return (0);
}
