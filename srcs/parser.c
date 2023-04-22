#include "../includes/minishell.h"

void	is_builtin(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (strcmp())
	}
}

// fonction qui cree chaque node afin de l'ajouter dans notre data (add_to_parser)
void	create_node(t_data *data, t_simple_cmds *parser)
{
	if (is_builtin(data->lexer->str))
		parser->builtins = data->lexer->str;
}

// fonction qui ajoute des nodes dans le parser
void	add_to_parser(t_data *data, t_simple_cmds *parser, int i)
{
	int	j;
	char	*str

	j = 0;
	while (j < i)
	{
		create_node(data, parser);
	}
}

// fontion qui plit 
void	pipe_manager(t_data *data, t_simple_cmds *parser)
{
	while (data->lexer)
	{
		if (data->lexer->token)
		{
			add_to_parser(data, parser, data->lexer->i);
		}
	}
}

void	parser_init(t_data *data)
{
	t_simple_cmds	*parser;
	// check_les erreurs
	if (check_errors(data))
		{
			// on free tout
			// et on quitte
			free_stack();
			exit(1);
		}
	// fonction qui split par rapport aux pipes
		pipe_manager(data, parser);
	// gerer le reste (faire les redirections, check si c des builtins)

}
