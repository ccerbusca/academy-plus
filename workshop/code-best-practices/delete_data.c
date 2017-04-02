/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/19 15:09:57 by ccerbusc          #+#    #+#             */
/*   Updated: 2015/11/19 15:16:50 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_stud.h"

void	delete_data()
{
	ft_strclr(fname);
	ft_strclr(lname);
	ft_strclr(email);
	ft_strclr(grade);
	ft_strclr(city);
}
