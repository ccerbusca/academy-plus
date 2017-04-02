/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/18 16:59:42 by ccerbusc          #+#    #+#             */
/*   Updated: 2015/11/18 17:22:39 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_stud.h"

void	create_log_file()
{
	fd = fopen("file.log", "a+");
	if (fd == NULL)
		write(2, "Log file could not be created.\n", 31);
}

void	write_log(char *str)
{
	if (fd == NULL)
		return ;
	fprintf(fd, "%s", str);
}
