/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_coordinates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 09:19:10 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/11 09:19:43 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		coordinates_are_not_ok(unsigned char *coordinates)
{
	int		index;

	index = 0;
	while (index < 8)
	{
		if (coordinates[index] == 0)
			return (0);
		index += 2;
	}
	return (1);
}

void	adjust_one_coordinate(unsigned char *coordinates)
{
	int		index;

	while (coordinates_are_not_ok(coordinates))
	{
		index = 0;
		while (index < 8)
		{
			(coordinates[index])--;
			index += 2;
		}
	}
}

void	adjust_coordinates(unsigned char *coordinates)
{
	adjust_one_coordinate(coordinates);
	adjust_one_coordinate(coordinates + 1);
}
