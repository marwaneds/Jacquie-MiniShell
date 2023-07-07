#include "minishell.h"

int remove_quotes(char *cpy, char *str)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (cpy[i])
    {
        if (cpy[i] == '\"')
            while(cpy[++i] && cpy[i] != '\"')
                str[j++] = cpy[i];
        if (cpy[i] == '\"')
            i++;
        if (cpy[i] == '\'')
			while(cpy[++i] && cpy[i] != '\'')
                str[j++] = cpy[i];
        if (cpy[i] == '\'')
            i++;
        if (!is_quotes(cpy[i]))
            while (cpy[i] && !is_quotes(cpy[i]))
                str[j++] = cpy[i++];
    }
    return (j);
}

char	*expand(int *start, int end, char *str, char *new_str)
{
	// int	i;
	char	*expanded;

	(void)new_str;
	(void)end;
	expanded = malloc(sizeof(char) * (*start + 1));
	if (!expanded)
		return (0);//FO FREE ET EXIT;
	expanded[*start] = 0;
	ft_memcpy(expanded, str, *start);
	// printf("first part : %s\n", expanded);
	if (new_str)
		expanded = exp_strjoin(expanded, new_str);
	*start = ft_strlen(expanded) - 1;
	expanded = exp_strjoin(expanded, &str[end + 1]);
	// printf("final result %s:\n", expanded);
	return (expanded);
}

char	*handle_quotes(char *str, t_data *data)
{
	int		i;
	int		j;
	char	*env_data;
	char	*index;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			skip_quotes(&i, str, '\'');
		else if (str[i] == '"')
		{
			i++;
			while (str[i] != '"')
			{
				if (str[i] == '$' && str[i + 1] != ' ' && str[i + 1] != '\0' && str[i + 1] != '"' && ft_isalnum(str[i + 1]))
				{
					j = 0;
					index = word_after_dollar(i, str, &j);
					env_data = get_env_data(index, data);
					str = expand(&i, i + j, str, env_data);
				}
				i++;
			}
		}
		else
		{
			while (str[i] && !is_quotes(str[i + 1]))
			{
				if (str[i] == '$' && str[i + 1] != '\0' && ft_isalnum(str[i + 1]))
				{
					j = 0;
					index = word_after_dollar(i, str, &j);
					env_data = get_env_data(index, data);
					str = expand(&i, i + j, str, env_data);
				}
				i++;
			}
			if (str[i] == '\0')
				break;
		}
		i++;
	}
	return (str);
}

int loop_through_str(char *str)
{
    int i;
    char *cpy;

    cpy = strdup(str);
    if (!cpy)
        return (0);
    i = remove_quotes(cpy, str);
    str[i] = '\0';
    return (1);
}

void	expander(t_data *data)
{
	t_lexer	*tmp;

	tmp = data->lexer;
	while (tmp)
	{
		if (tmp->str)
		{
			// printf("valeur fontction %d\n", prev_is_heredoc(tmp));
			if (!prev_is_heredoc(tmp))
				tmp->str = handle_quotes(tmp->str, data);
			if (!loop_through_str(tmp->str))
			{
				//on free
				return ;
			}
		}
		tmp = tmp->next;
	}
	printList(data->lexer);
}
