/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fothman <fothman@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:34:26 by fothman           #+#    #+#             */
/*   Updated: 2022/07/09 13:41:55 by fothman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*nodes;

	if (!lst)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		nodes = ft_lstnew(f(lst->content));
		if (!nodes)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, nodes);
		lst = lst->next;
	}
	return (new_list);
}
