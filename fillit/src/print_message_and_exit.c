/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message_and_exit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:25:24 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/11 10:25:26 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_message_and_exit(char *message, int output)
{
	ft_putendl_fd(message, output);
	exit(0);
}

void	print_map_and_exit(char *str, int output)
{
	ft_putstr_fd(str, output);
	exit(0);
}
