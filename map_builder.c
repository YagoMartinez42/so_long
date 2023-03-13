/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:49:49 by samartin          #+#    #+#             */
/*   Updated: 2023/03/13 15:15:21 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	unsigned int x;
	unsigned int y;
	float den = 2.0f;
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	srand(time(NULL));
	printf ("%d0x=\n", y);
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			if (((rand() % (y + 1)) * 2) < den)
				printf ("x");
			else
				printf ("0");
			i++;
		}
		printf ("\n");
		j++;
	}
}