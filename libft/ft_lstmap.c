/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 04:40:40 by bait-sli          #+#    #+#             */
/*   Updated: 2016/11/12 09:21:22 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list*))
{
	t_list	*nlst;
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst || !f)
		return (NULL);
	tmp2 = f(lst);
	nlst = ft_lstnew(tmp2->content, tmp2->content_size);
	if (nlst)
	{
		tmp = nlst;
		lst = lst->next;
		while (lst)
		{
			tmp2 = f(lst);
			tmp->next = ft_lstnew(tmp2->content, tmp2->content_size);
			if (!(tmp->next))
				return (NULL);
			tmp = tmp->next;
			lst = lst->next;
		}
	}
	return (nlst);
}
