/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:09:41 by jocalder          #+#    #+#             */
/*   Updated: 2024/10/08 16:52:49 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_array(char **p, int i)
{
	while (i >= 0)
	{
		free(p[i]);
		i--;
	}
	free(p);
	return (NULL);
}

static int	countword(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	**array(char **aux, char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		idx;

	i = 0;
	idx = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			aux[idx] = ft_substr(s, j, (i - j));
			if (!aux[idx])
				return (free_array(aux, idx));
			idx++;
		}
	}
	aux[idx] = NULL;
	return (aux);
}

char	**ft_split(char const *s, char c)
{
	char	**aux;
	int		words;

	if (!s)
		return (NULL);
	if (*s == '\0')
	{
		aux = malloc(sizeof(char *));
		if (!aux)
			return (NULL);
		aux[0] = NULL;
		return (aux);
	}
	words = countword(s, c);
	aux = malloc((words + 1) * sizeof(char *));
	if (!aux)
		return (NULL);
	aux = array(aux, s, c);
	return (aux);
}
