/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/18 15:39:01 by ccerbusc          #+#    #+#             */
/*   Updated: 2015/11/19 14:48:33 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_stud.h"

void	stock_data(char *buff)
{
	int		i, j, k;
	i = 0;
	j = 0;
	k = 0;
	while (buff[i])
	{
		if (buff[i] == ';')
		{
			validate_get(j);
			j++;
			k = 0;
		}
		else
		{
			if (j == 0)
				get_fname(buff, k, i);
			if (j == 1)
				get_lname(buff, k, i);
			if (j == 2)
				get_email(buff, k, i);
			if (j == 3)
				get_grade(buff, k, i);
			if (j == 4)
				get_city(buff, k, i);
			k++;
		}
		i++;
	}
}
