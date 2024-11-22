/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:18:48 by paprzyby          #+#    #+#             */
/*   Updated: 2024/03/28 08:05:53 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*current;
	void	*tmp;

	new = NULL;
	while (lst)
	{
		tmp = f(lst -> content);
		if (!tmp)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		current = ft_lstnew(tmp);
		if (!current)
		{
			del(tmp);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, current);
		lst = lst -> next;
	}
	return (new);
}
