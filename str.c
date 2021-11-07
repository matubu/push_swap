/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:44:01 by mberger-          #+#    #+#             */
/*   Updated: 2021/11/07 15:44:03 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
		if (*s1++ != *s2++)
			return (*(unsigned char *)--s1 - *(unsigned char *)--s2);
	return (0);
}

char	*ft_strjoin(char *s, char c)
{
	char	*out;
	int		i;

	out = malloc(ft_strlen(s) + 2);
	if (out == NULL)
		return (NULL);
	i = 0;
	while (s && s[i])
	{
		out[i] = s[i];
		i++;
	}
	out[i++] = c;
	out[i] = '\0';
	free(s);
	return (out);
}
