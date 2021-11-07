/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:01:08 by mberger-          #+#    #+#             */
/*   Updated: 2021/11/07 15:26:33 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr, int *v)
{
	int	neg;

	*v = 0;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	neg = *nptr == '-';
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	if (!*nptr)
		return (1);
	while (*nptr >= '0' && *nptr <= '9')
		if (*v * 10 - *nptr + '0' > *v)
			return (1);
	else
		*v = *v * 10 - *nptr++ + '0';
	if (!neg)
		*v = -*v;
	if (*nptr)
		return (1);
	return (0);
}

int	ft_abs(int v)
{
	if (v < 0)
		return (-v);
	return (v);
}
