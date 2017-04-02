/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/18 15:43:51 by ccerbusc          #+#    #+#             */
/*   Updated: 2015/11/19 16:35:08 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_stud.h"

int		file_open_validate(FILE *fp)
{
	if (fp == NULL)
	{
		write_log("No file was opened.\n");
		return (0);
	}
	return (1);
}

void	validate_line(char *buff)
{
	int		index, nr;

	index = 0;
	nr = 0;
	while (buff[index] != '\n' && buff[index] != '\0')
	{
		if (buff[index] == ';' || buff[index] == '\0')
			nr++;
		index++;
	}
	if (nr < 4)
		write_log("ERROR : Incomplete line.\n");
	if (nr > 4)
		write_log("ERROR : Too many parameters on line.\n");
}

void	validate_fname()
{
	int i;

	if (*fname == 0)
	{
		write_log("ERROR : No first name entered.\n");
		return ;
	}
	i = 0;
	while (fname[i])
	{
		if (!isalpha(fname[i]))
		{
			write_log("ERROR : Invalid first name.\n");
			return ;
		}
		i++;
	}
}

void	validate_lname()
{
	int i;

	if (*lname == 0)
	{
		write_log("ERROR : No last name entered.\n");
		return ;
	}
	i = 0;
	while (lname[i])
	{
		if (!isalpha(lname[i]))
		{
			write_log("ERROR : Invalid last name.\n");
			return ;
		}
		i++;
	}
}

void	validate_email()
{
	int i;

	if (*email == 0)
	{
		write_log("ERROR : No email entered.\n");
		return ;
	}
	i = 0;
	if (!strchr(email, '@') || !strchr(email, '.'))
	{
		write_log("ERROR : Invalid email.\n");
		return ;
	}
}

void	validate_grade()
{
	int i;

	if (*grade == 0)
	{
		write_log("ERROR : No grade entered.\n");
		return ;
	}
	i = 0;
	while (grade[i])
	{
		if (!strchr("0123456789.", grade[i]))
		{
			write_log(" ERROR : Invalid grade entered.\n");
			return ;
		}
		i++;
	}
}

void	validate_city()
{
	int i;

	i = 0;
	if (*city == 0)
	{
		write_log("ERROR : No city entered.\n");
		return ;
	}
	while (city[i])
	{
		if (!isalpha(city[i]) || city[i] != '-')
		{
			write_log("ERROR : Invalid city.\n");
			return ;
		}
		i++;
	}
}

void	validate_get(int j)
{
	if (j == 0)
		validate_fname();
	if (j == 1)
		validate_lname();
	if (j == 2)
		validate_email();
	if (j == 3)
		validate_grade();
	if (j == 4)
		validate_city();
}
