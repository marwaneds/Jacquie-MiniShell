/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosortiz <carlosortiz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:11:12 by carlosortiz       #+#    #+#             */
/*   Updated: 2023/05/02 17:42:57 by carlosortiz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	array_len(t_lexer *lexer)
{
	t_lexer *current;
	int		len;

	len = 0;
	current = lexer;
	while (current)
	{
		if (current->str)
			len++;
		if (current->token && current->token != LESS_LESS && current->token != PIPE)
			len--;
		current = current->next;
	}
	return (len);
}

// fonction qui cree chaque node afin de l'ajouter dans notre data (add_to_parser)
void	create_node(t_data *data, t_simple_cmds *parser)
{
	if (is_builtin(data->lexer->str))
		parser->builtins = data->lexer->str;
}

// fonction qui ajoute des nodes dans le parser
void	add_to_parser(t_lexer *lexer, t_simple_cmds *parser, int i)
{
	t_lexer	*current;
	int		len;

	len = array_len(lexer);
	parser->str = malloc(sizeof(char *) * len + 1);
	current = lexer;
	while (current->i < i)
	{
		if (current->token)
		{
			
		}
		if (is_builtin(lexer->str))
			parser->builtins = lexer->str;
		
	}
}

// fontion qui plit 
void	pipe_manager(t_data *data, t_simple_cmds *parser)
{
	t_data *current = data;

	(void)parser;
	while (current->lexer)
	{
		if (current->lexer->token == PIPE)
		{
			// add_to_parser(data, parser, current->lexer->i);
			printf("ya un pipe\n");
			printf("au %d\n", current->lexer->i);
		}
		current->lexer = current->lexer->next;
	}
}

void	parser_init(t_data *data)
{
	t_simple_cmds	*parser;
	
	parser = malloc(sizeof(t_simple_cmds));
	// check_les erreurs
	// if (check_errors(data))
	// {
	// 	// on free tout
	// 	// et on quitte
	// 	free_stack();
	// 	exit(1);
	// }
	// fonction qui split par rapport aux pipes
	pipe_manager(data, parser);
	// gerer le reste (faire les redirections, check si c des builtins)
}
