/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-faqu <mel-faqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:43:23 by mel-faqu          #+#    #+#             */
/*   Updated: 2023/06/27 16:12:41 by mel-faqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Initialise un parser	*/
t_data	init_paser_tools(t_lexer *lexer, t_data *data)
{
	t_data	parser;

	parser.lexer = lexer;
	parser.simple_cmd.redirections = NULL;
	parser.simple_cmd->num_redirections = 0;
	parser = data;
	return (parser);
}

/*	Compte le nombre de pipe	*/
void	count_pipes(t_lexer *lexer, t_data	*data)
{
	t_lexer	*tmp;

	tmp = lexer;
	data->pipes = 0;
	while (tmp)
	{
		if (tmp->token == PIPE)
			data->pipes++;
		tmp = tmp->next;
	}
}

/*	Compte le nombre d'argument	*/
int	count_args(t_lexer *lexer)
{
	t_lexer	*tmp;
	int		i;

	i = 0;
	tmp = lexer;
	while (tmp && tmp->token != PIPE)
	{
		if (tmp->i >= 0)
			i++;
		tmp = tmp->next;
	}
	return (i);
}
