/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 02:37:41 by jihonkim          #+#    #+#             */
/*   Updated: 2022/04/30 02:49:00 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*temp;

	if (!lst || !f)
		return (0);
	node = ft_lstnew(f(lst->content));
	if (!node)
		return (0);
	temp = node;
	while (lst->next != 0)
	{
		lst = lst->next;
		temp->next = ft_lstnew((f)(lst->content));
		if (!(temp->next))
		{
			ft_lstclear(&node, del);
			return (0);
		}
		temp = temp->next;
	}
	return (node);
}
