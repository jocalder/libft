/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:24:50 by jocalder          #+#    #+#             */
/*   Updated: 2024/09/23 19:28:00 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p1;
	size_t			i;

	i = 0;
	p1 = (unsigned char *)s;
	while (i < n)
	{
		if (*p1 == (unsigned char)c)
			return ((void *)p1);
		p1++;
		i++;
	}
	return (NULL);
}
