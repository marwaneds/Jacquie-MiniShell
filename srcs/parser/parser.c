/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-faqu <mel-faqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:35:47 by mel-faqu          #+#    #+#             */
/*   Updated: 2023/06/16 15:16:55 by mel-faqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_simple_cmds	*init_cmd(t_data *data)
{
	char	**str;
	int		i;
	int		arg_size;
	t_lexer	*tmp;
	
	i = 0;
	rm_redirections(parser);
	arg_size = count_args(data->lexer);
	str = ft_calloc(arg_size + 1, sizeof(char *));
	if (!str)
	{
		if (tmp->str)
		{
			str[i++] = ft_strdup(tmp->str);
			lexer_delone(&data->lexer, tmp->i);
			tmp = data->lexer;
		}
		arg_size--;
	}
	return (simple_cmdsnew(str, data->simple_cmd->num_redirections, data->simple_cmd->redirections));
}

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
	t_data		parser_tools;

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
		parser_tools = init_paser_tools(data->lexer, data);
		node = init_cmd(&parser_tools);
		if (!node)
			parser_error(0, data, parser_tools.lexer);
		if (!data->simple_cmd)
			data->simple_cmd = node;
		else
			simple_cmdadd_back(&data->simple_cmd, node);
		data->lexer= parser_tools.lexer;
	}
	return (EXIT_SUCCESS);
	
}