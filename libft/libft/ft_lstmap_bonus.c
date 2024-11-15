/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:19:27 by lguerbig          #+#    #+#             */
/*   Updated: 2024/10/16 18:11:35 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*tmp;

	if (!lst || !del || !f)
		return (0);
	res = 0;
	while (lst)
	{
		tmp = ft_lstnew(lst->content);
		if (!tmp)
		{
			ft_lstclear(&res, del);
			return (0);
		}
		tmp->content = (*f)(tmp->content);
		ft_lstadd_back(&res, tmp);
		lst = lst->next;
	}
	return (res);
}
