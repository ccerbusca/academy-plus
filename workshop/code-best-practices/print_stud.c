/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stud.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/16 15:13:05 by ccerbusc          #+#    #+#             */
/*   Updated: 2015/11/19 16:23:08 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_stud.h"

int		main()
{
	FILE	*fp;
	char	buff[255];
	int		j;

	create_log_file();
	write_log("Opening the file.\n");
	fp = fopen("students.csv", "r");
	if (!file_open_validate(fp))
		return (0);
	write_log("File got validated.\n");
	j = 1;
	while (fscanf(fp, "%s", buff) > 0)
	{
		write_log("Validating ");
		write_log(ft_itoa(j));
		write_log(" line.\n");
		validate_line(buff);
		write_log("Getting student data...\n");
		stock_data(buff);
		write_log("Check and print.\n");
		print_student();
		delete_data();
		j++;
	}
	write_log("\n\n\n");
	fclose(fd);
	return (0);
}
