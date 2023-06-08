/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-faqu <mel-faqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:57:55 by mel-faqu          #+#    #+#             */
/*   Updated: 2023/06/08 12:22:24 by mel-faqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_export(t_data *data, t_simple_cmds	*simple_cmd)
{
	char	**tmp;
	int		i;

	i = 1;
	if (!simple_cmd->str[1] || simple_cmd->str[1][0] == '\0')
		mini_env(data, simple_cmd);
	else
	{
		while (simple_cmd->str[i])
		{
			if (check_parameter(simple_cmd->str[i]) == 0
				&& variable_exist(data, simple_cmd->str[i]) == 0)
			{
				if (simple_cmd->str[i])
				{
					tmp = add_var(data->env, simple_cmd->str[i]);
					//FO FRI
					data->env = tmp;
				}
			}
			i++;
		}
	}
	return (EXIT_SUCCESS);
}