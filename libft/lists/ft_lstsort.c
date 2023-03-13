/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:09:00 by samartin          #+#    #+#             */
/*   Updated: 2023/02/03 14:22:22 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

/**
 * It sorts a linked list of integers in a configurable order.
 * 
 * @param lst a pointer to the first element of a linked list.
 * @param cmp a function to be added, that takes two ints and returns 0 if they
 * are not in the expected order.
 * 
 * @return A pointer to the first element of the sorted list.
 */
t_list	*ft_lstsort(t_list *lst, int (*cmp)(int, int))
{
	t_list	*cur;
	t_list	*past_last;
	void	*swp;

	if (lst && lst->next && cmp)
	{
		cur = lst;
		past_last = NULL;
		while (cur->next != past_last)
		{
			while (cur->next != past_last)
			{
				if (!(cmp(*(int *)cur->content, *(int *)cur->next->content)))
				{
					swp = cur->content;
					cur->content = cur->next->content;
					cur->next->content = swp;
				}
				cur = cur->next;
			}
			past_last = cur;
			cur = lst;
		}
	}
	return (lst);
}
