/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-faqu <mel-faqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:43:13 by mel-faqu          #+#    #+#             */
/*   Updated: 2023/06/08 13:48:30 by mel-faqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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