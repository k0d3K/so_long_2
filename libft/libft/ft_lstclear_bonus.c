/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:45:54 by lguerbig          #+#    #+#             */
/*   Updated: 2024/10/16 18:11:08 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*tmpnext;

	if (!lst || !del)
		return ;
	tmp = *lst;
	while (tmp)
	{
		tmpnext = tmp->next;
		ft_lstdelone(tmp, *del);
		tmp = tmpnext;
	}
	*lst = 0;
}
