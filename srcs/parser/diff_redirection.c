/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-faqu <mel-faqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:38:23 by mel-faqu          #+#    #+#             */
/*   Updated: 2023/06/12 10:55:42 by mel-faqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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