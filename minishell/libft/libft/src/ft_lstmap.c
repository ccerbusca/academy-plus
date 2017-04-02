/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 18:50:19 by ccerbusc          #+#    #+#             */
/*   Updated: 2015/11/13 19:39:58 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ptr;
	t_list *aux;

	aux = (*f)(lst);
	ptr = aux;
	if (ptr == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		aux->next = (*f)(lst);
		if (aux->next == NULL)
			return (NULL);
		aux = aux->next;
	}
	return (ptr);
}
