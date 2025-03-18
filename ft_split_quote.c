#include "pipex.h"

static char	**free_array_split(char **p, int i)
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
			if (s[i] == 39)
			{
				count++;
				i++;
				while (s[i] && s[i] != 39)
					i++;
				i++;
			}
			else if (s[i] && s[i] != c && s[i] != 39)
			{
				count++;
				while (s[i] && s[i] != c)
					i++;
			}
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
		if (s[i] == 39)
		{
			j = i + 1;
			i++;
			while (s[i] && s[i] != 39)
				i++;
			aux[idx] = ft_substr(s, j, (i - j));
			i++;
		}
		else
		{
			while (s[i] && s[i] != c && s[i] != 39)
				i++;
			aux[idx] = ft_substr(s, j, (i - j));
		}
		if (i > j)
		{
			if (!aux[idx])
				return (free_array_split(aux, idx));
			idx++;
		}
	}
	aux[idx] = NULL;
	return (aux);
}

char	**ft_split_quote(char const *s, char c)
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
