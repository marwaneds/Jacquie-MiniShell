/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-faqu <mel-faqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:33:50 by mel-faqu          #+#    #+#             */
/*   Updated: 2023/06/09 11:37:59 by mel-faqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lexer_error(int error, t_data *data)
{
	
}

//print "minishell: [str] : command not found" in the error file descriptor
int	cmd_not_found(char *str)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	return (127);
}