/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:56:59 by jocalder          #+#    #+#             */
/*   Updated: 2024/10/16 16:05:10 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*node;

	if (!lst)
		return ;
	node = lst;
	while (node)
	{
		(*f)(node->content);
		node = node->next;
	}
}

void	print(void *content)
{
	printf("%s\n", (char *)content);
}

int main(void)
{
	t_list *list;
	t_list *node1 = ft_lstnew("node1");
	t_list *node2 = ft_lstnew("node2");

	list = node1;
	node1->next = node2;
	
	ft_lstiter(&list, print);
	free(node1);
	free(node2);
	return 0;
}
