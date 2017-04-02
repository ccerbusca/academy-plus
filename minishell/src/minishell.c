/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <ccerbusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 16:52:40 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/04/02 19:29:10 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	start_shell(t_sh *sh)
{
	ft_printf("$> ");
	while (get_next_line(0, &sh->line) > 0)
	{
		
	}
}

int		main()
{
	t_sh sh;
	start_shell(&sh);
	return (0);
}
