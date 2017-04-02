/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stud.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 16:59:36 by ccerbusc          #+#    #+#             */
/*   Updated: 2015/11/19 16:20:56 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_STUD_H
# define PRINT_STUD_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

char	fname[20], lname[20], email[20], grade[20], city[20];
FILE	*fd;

void	print_student();
void	get_fname(char *buff, int k, int i);
void	get_lname(char *buff, int k, int i);
void	get_email(char *buff, int k, int i);
void	get_grade(char *buff, int k, int i);
void	get_city( char *buff, int k, int i);
void	stock_data(char *buff);
int		file_open_validate(FILE *fp);
void	validate_line(char *buff);
void	create_log_file();
void	write_log(char *str);
char	*ft_itoa(int n);
void	validate_fname();
void	validate_lname();
void	validate_email();
void	validate_grade();
void	validate_city();
void	validate_get(int j);
void	ft_strclr(char *s);
void	delete_data();

#endif
