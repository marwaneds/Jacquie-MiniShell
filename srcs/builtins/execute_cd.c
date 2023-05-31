/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-faqu <mel-faqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:01:26 by mel-faqu          #+#    #+#             */
/*   Updated: 2023/05/31 13:57:23 by mel-faqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *find_path(char *str, t_data *data)
{
	int	i;
	
	i = 0;
	while (data->env[i])
	{
		if (!ft_strncmp(data->env[i], str, ft_strlen(str)))
			return (ft_substr(data->env[i], ft_strlen(str),
					ft_strlen(data->env[i]) - ft_strlen(str)));
		i++;
	}
	return NULL;
}

int	specific_path(t_data *data, char *str)
{
	char	*tmp;
	int		ret;
	
	tmp = find_path(str, data);
	ret = chdir(tmp);
	//FAUX FREE TMP
	if (ret != 0)
	{
		str = ft_substr(str, 0, ft_strlen(str) - 1);
		ft_putstr_fd(str, STDERR_FILENO);
		//FO FRI STR
		ft_putendl_fd(" not set", STDERR_FILENO);
	}
	return (ret);
}

void	add_path_to_env(t_data *data)
{
	int		i;
	char	*tmp;
	
	for (i = 0; data->env[i]; i++)
	{
		if (strncmp(data->env[i], "PWD=", 4) == 0)
		{
			tmp = ft_strjoin("PWD=", data->pwd);
			data->env[i] = tmp;
		}
		else if (strncmp(data->env[i], "OLDPWD=", 7) == 0 && data->oldpwd)
		{
			tmp = ft_strjoin("OLDPWD=", data->oldpwd);
			//FO FREE
			data->env[i] = tmp;
		}
	}
}

int	execute_cd(t_data *data, t_simple_cmds *simple_cmd)
{
	int	ret;
	
	ret = EXIT_SUCCESS;
	
	if (!simple_cmd->str[1])
		ret = specific_path(data, "HOME=");
	else if (simple_cmd->str[1][0] == '-')
		ret = specific_path(data, "OLDPWD=");
	else
	{
		if (chdir(simple_cmd->str[1]) != 0)
		{
			ft_putstr_fd("minishell: ", STDERR_FILENO);
			ft_putstr_fd(simple_cmd->str[1], STDERR_FILENO);
			perror(" ");
			ret = EXIT_FAILURE;
		}
	}
	if (ret == EXIT_SUCCESS)
	{
		change_path(data);
		add_path_to_env(data);
	}
	return (ret);
}