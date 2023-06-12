/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-faqu <mel-faqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:38:23 by mel-faqu          #+#    #+#             */
/*   Updated: 2023/06/12 11:07:39 by mel-faqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_new_redirection(t_lexer *tmp,t_parser *parser)
{
	t_lexer *node;
	int		i1;
	int		i2;
	
	node = lexer_new(ft_strdup(tmp->next->str), tmp->token);
	if (!node)
		parser_error(1, parser->data, parser->lexer_list);
	lexer_adback(&parser->redirections, node);
	i1 = tmp->i;
	i2 = tmp->next->i;
	lexer_delone(&parser->lexer_list, i1);
	lexer_delone(&parser->lexer_list, i2);
	parser->num_red++;
	return (0);
}

void	rm_redirections(t_parser *parser)
{
	t_lexer	*tmp;

	tmp = parser->lexer_list;
	while (tmp && tmp->token == 0)
		tmp = tmp->next;
	if (!tmp || tmp->token == PIPE)
		return ;
	if (!tmp->next)
		parser_error(0, parser->data, parser->lexer_list);
	if (tmp->next->token)
		parser_double_token(parser->data, parser->lexer_list, tmp->next->token);
	if ((tmp->token >= GREAT && tmp->token <= LESS_LESS))
		add_new_redirection(tmp, parser);
	rm_redirections(parser);
}