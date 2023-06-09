/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-faqu <mel-faqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:33:50 by mel-faqu          #+#    #+#             */
/*   Updated: 2023/06/09 14:29:10 by mel-faqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parser_error(int error, t_data *data, t_lexer *lexer)
{
	lexer_clear(&lexer);
	ft_error(error, data);
}

int	parser_double_token(t_data *data, t_lexer *lexer, t_tokens token)
{
	ft_putstr_fd("minishell: syntax error near unexpected token ",
		STDERR_FILENO);
	if (token = GREAT)
		ft_putstr_fd("'>'\n", STDERR_FILENO);
	else if (token = GREAT_GREAT)
		ft_putstr_fd("'>>'\n", STDERR_FILENO);
	else if (token = LESS)
		ft_putstr_fd("'<'\n", STDERR_FILENO);
	else if (token = LESS_LESS)
		ft_putstr_fd("'<<'\n", STDERR_FILENO);
	else if (token = PIPE)
		ft_putstr_fd("'|'\n", STDERR_FILENO);
	else
		ft_putstr_fd("\n", STDERR_FILENO);
	lexer_clear(&lexer);
	reset_data(data);
	return (EXIT_FAILURE);
}

int	export_error(char *str)
{
	ft_putstr_fd("minishell: export: ", STDERR_FILENO);
	if (str)
	{
		ft_putstr_fd('\'', STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putstr_fd('\': is', STDERR_FILENO);
	}
	ft_putendl_fd("not a valid indentifier", STDERR_FILENO);
	return (EXIT_FAILURE);
}

void	lexer_error(int error, t_data *data)
{
	lexer_clear(&data->lexer);
	ft_error(error, data);
}

//print "minishell: [str] : command not found" in the error file descriptor
int	cmd_not_found(char *str)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	return (127);
}