/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-faqu <mel-faqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:52:04 by mel-faqu          #+#    #+#             */
/*   Updated: 2023/05/30 15:52:30 by mel-faqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	mini_pwd(t_data *data, t_simple_cmds *simple_cmd)
{
	(void) simple_cmd;
	ft_putendl_fd(data->pwd, STDOUT_FILENO);
	return (EXIT_SUCCESS);
}