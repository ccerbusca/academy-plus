/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/18 15:27:58 by ccerbusc          #+#    #+#             */
/*   Updated: 2015/11/18 15:38:52 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_stud.h"

void	get_fname(char *buff, int k, int i)
{
	fname[k] = buff[i];
	if (buff[i + 1] == ';')
		fname[k + 1] = '\0';
}

void	get_lname(char *buff, int k, int i)
{
	lname[k] = buff[i];
	if (buff[i + 1] == ';')
		lname[k + 1] = '\0';
}

void	get_email(char *buff, int k, int i)
{
	email[k] = buff[i];
	if (buff[i + 1] == ';')
		email[k + 1] = '\0';
}

void	get_grade(char *buff, int k, int i)
{
	grade[k] = buff[i];
	if (buff[i + 1] == ';')
		grade[k + 1] ='\0';
}

void	get_city(char *buff, int k, int i)
{
	city[k] = buff[i];
	if (buff[i + 1] ==';')
		city[k + 1] = '\0';
}
