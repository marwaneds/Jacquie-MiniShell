/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-faqu <mel-faqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:35:47 by mel-faqu          #+#    #+#             */
/*   Updated: 2023/06/08 13:40:57 by mel-faqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipe_error(t_data *data, t_tokens token)
{
	if (token == PIPE)
	{
		parser_double_token(data, data->lexer, data->lexer->token);
		return (EXIT_FAILURE);
	}
	if (!data->lexer)
	{
		error(0, data, data->lexer);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	parser(t_data *data)
{
	t_simple_cmds	*node;
	t_parser		parser_tools;

	data->simple_cmd = NULL;
	count_pipes(data->lexer, data);
	if (data->lexer->token == PIPE)
		return (error_double_token(data, data->lexer,
				data->lexer->token));
	while (data->lexer)
	{
		if (data->lexer && data->lexer->token == PIPE)
			lexer_delone(&data->lexer, data->lexer->i);
		if (pipe_error(data, data->lexer->token))
			return (EXIT_FAILURE);
	}
}