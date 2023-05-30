/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-faqu <mel-faqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:50:48 by mel-faqu          #+#    #+#             */
/*   Updated: 2023/05/30 15:42:38 by mel-faqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print(int i, char **str, int fd)
{
	while(str[i])
	{
		ft_putstr_fd(str[i++], fd);
		if (str[i])
			ft_putchar_fd(' ', fd);
	}
}

int execute_echo(t_simple_cmds *simple_cmd)
{
	int	i;
	int	j;
	int	n_option;
	
	i = 1;
	n_option = 0;
	while (simple_cmd->str[i] && simple_cmd->str[i][0] == '-'
		&& simple_cmd->str[i][1] == 'n')
	{
		j = 1;
		while (simple_cmd->str[i][j] == 'n')
			j++;
		if (simple_cmd->str[i][j] == '\0')
			n_option = 1;
		else
			break;
		i++;
	}
	print(i, simple_cmd->str, STDOUT_FILENO);
	if (n_option == 0)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (EXIT_SUCCESS);
}