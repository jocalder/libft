/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:08:01 by jocalder          #+#    #+#             */
/*   Updated: 2024/10/17 14:57:53 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*node;
	void	*cont;

	if (!lst || !f)
		return (NULL);
	new_node = NULL;
	while (lst)
	{
		cont = f(lst->content);
		if (!cont)
			return (ft_lstclear(&new_node, del), NULL);
		node = ft_lstnew(cont);
		if (!node)
		{
			del(cont);
			ft_lstclear(&new_node, del);
			return (NULL);
		}
		ft_lstadd_back(&new_node, node);
		lst = lst->next;
	}
	return (new_node);
}
