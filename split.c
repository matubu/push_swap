/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:28:40 by mberger-          #+#    #+#             */
/*   Updated: 2021/11/04 13:37:45 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (--size && *src && ++i)
		*dst++ = *src++;
	*dst = '\0';
	while (*src++)
		i++;
	return (i);
}

static int	malloc_splits(char ***splits, const char *s, char c, int *len)
{
	int	i;

	*len = 0;
	i = -1;
	while (s[++i])
		if (s[i] != c && ++(*len))
			while (s[i + 1] && s[i + 1] != c)
				i++;
	*splits = malloc((*len + 1) * sizeof(char *));
	return (*splits == NULL);
}

int	free_splits(char **splits, int n)
{
	while (n--)
		free(splits[n]);
	free(splits);
	return (1);
}

char	**split(const char *s, char c, int *len)
{
	char			**out;
	unsigned int	size;
	unsigned int	n;

	if (malloc_splits(&out, s, c, len))
		return (NULL);
	n = 0;
	while (*s)
	{
		if (*s++ != c)
		{
			size = 1;
			while (*s && *s != c && size++)
				s++;
			out[n] = malloc(size + 1);
			if (out[n] == NULL && free_splits(out, n))
				return (NULL);
			ft_strlcpy(out[n++], s - size, size + 1);
		}
	}
	out[n] = NULL;
	return (out);
}
