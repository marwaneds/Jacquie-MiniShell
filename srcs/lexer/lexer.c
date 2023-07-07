#include "minishell.h"

void	add_node(t_lexer **lexer, char *str, int tokken)
{
	t_lexer 	*tmp;
	static int	i = 0;

	tmp = (t_lexer *)malloc(sizeof(t_lexer));
	if (!tmp)
		exit(1); //FO FREE
	tmp->str = str;
	tmp->token = tokken;
	tmp->i = i;
	tmp->next = NULL;
	tmp->prev = NULL;
	lexer_adback(lexer, tmp);
	i++;
}

void	add_word(char *str, int *i, t_data *data)
{
	int		j;
	char	*tmp;

	j = *i;
	while (!is_token(str[j]) && !ft_iswhitespace(str[j]) && str[j])
	{
		skip_quotes(&j, str, '\'');
		skip_quotes(&j, str, '\"');
		j++;
	}
	tmp = ft_substr(str, *i, j - *i);
	if (tmp)
		add_node(&data->lexer, tmp, 0);
	*i = j;
}

void	init_lexer(char *str, t_data *data)
{
	int		i;
	int		tokken;

	i = 0;
	tokken = 0;
	data->lexer = NULL;
	while (str[i])
	{
		while (ft_iswhitespace(str[i]))
			i++;
		if (get_token(str, &i, &tokken))
			add_node(&data->lexer, NULL, tokken);
		else
			add_word(str, &i, data);
	}
}