/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:17:11 by samartin          #+#    #+#             */
/*   Updated: 2025/01/02 18:36:33 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	pos;

	pos = 0;
	while (pos < n)
	{	
		if (((unsigned char *)s)[pos] == (unsigned char)c)
			return ((void *)s + pos);
		pos++;
	}
	return (0);
}
