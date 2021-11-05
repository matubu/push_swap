/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:01:08 by mberger-          #+#    #+#             */
/*   Updated: 2021/11/05 08:33:09 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr, int *v)
{
	int	neg;

	*v = 0;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	neg = *nptr == '-';
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
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
