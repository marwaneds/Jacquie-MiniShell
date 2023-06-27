/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-faqu <mel-faqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:38:23 by mel-faqu          #+#    #+#             */
/*   Updated: 2023/06/27 16:14:54 by mel-faqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error_double_token(t_data *data, t_lexer *lexer_list,
	t_tokens token)
{
	ft_putstr_fd("minishell: syntax error near unexpected token ",
		STDERR_FILENO);
	if (token == GREAT)
		ft_putstr_fd("'>'\n", STDERR_FILENO);
	else if (token == GREAT_GREAT)
		ft_putstr_fd("'>>'\n", STDERR_FILENO);
	else if (token == LESS)
		ft_putstr_fd("'<'\n", STDERR_FILENO);
	else if (token == LESS_LESS)
		ft_putstr_fd("'<<'\n", STDERR_FILENO);
	else if (token == PIPE)
		ft_putstr_fd("'|'\n", STDERR_FILENO);
	else
		ft_putstr_fd("\n", STDERR_FILENO);
	lexer_clear(&lexer_list);
	reset_tools(data);
	return (EXIT_FAILURE);
}

int	add_new_redirection(t_lexer *tmp, t_data *data)
{
	t_lexer	*node;
	int		i1;
	int		i2;

	node = lexer_new(ft_strdup(tmp->next->str), tmp->token);
	if (!node)
		parser_error(1, data, data->lexer);
	lexer_adback(&data->simple_cmd->redirections, node);
	i1 = tmp->i;
	i2 = tmp->next->i;
	lexer_delone(&data->lexer, i1);
	lexer_delone(&data->lexer, i2);
	data->simple_cmd->num_redirections++;
	return (0);
}

void	rm_redirections(t_data *data)
{
	t_lexer	*tmp;

	tmp = data->lexer;
	while (tmp && tmp->token == 0)
		tmp = tmp->next;
	if (!tmp || tmp->token == PIPE)
		return ;
	if (!tmp->next)
		parser_error(0, data, data->lexer);
	if (tmp->next->token)
		parser_double_token(data, data->lexer, tmp->next->token);
	if ((tmp->token >= GREAT && tmp->token <= LESS_LESS))
		add_new_redirection(tmp, parser);
	rm_redirections(parser);
}
