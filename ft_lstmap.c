/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egerin <egerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:31:12 by egerin            #+#    #+#             */
/*   Updated: 2025/05/20 14:15:42 by egerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	tmp = ft_lstnew(f(lst->content));
	lst2 = tmp;
	while (lst && lst->next)
	{
		if (!lst2)
			return (NULL);
		lst2->next = ft_lstnew(f(lst->next->content));
		lst2 = lst2->next;
		lst = lst->next;
	}
	return (tmp);
}
