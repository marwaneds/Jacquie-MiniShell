/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cortiz <cortiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 06:46:40 by cortiz            #+#    #+#             */
/*   Updated: 2023/06/08 09:12:56 by cortiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_data(char *index, t_data *data)
{
	int		i;
	int		size;

	i = 0;
	while (data->env[i])
	{
		size = len_env_index(data->env[i]);
		// printf("VALEUR DE ENV LAAAAAAAAAAAA = %s\n", data->env[i]);
		if (!ft_strncmp(data->env[i], index, size) && size == (int)ft_strlen(index))
			return (&data->env[i][size + 1]);
		i++;
	}
	return (0);
}

char	*word_after_dollar(int i, char *str,int *j)
{
	char	*index;

	i++;
	while (ft_isalnum(str[i + *j]))
		*j += 1;
	index = malloc(sizeof(char) * (*j + 1));
	index[*j] = 0;
	ft_memcpy(index, &str[i], *j);
	return (index);
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
		// printf("debut boucle = %s\n", &str[i]);
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
					// printf("word after dollar = %s\n", index);
					env_data = get_env_data(index, data);
					// printf("value of %s = %s\n", index, env_data);
					// printf("valeur de i%d\n", i);
					// printf("valeur de j%d\n", j);
					str = expand(&i, i + j, str, env_data);
					// printf("mon STR VAUT : %s\n", str);
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
				// printf("%s:\n", &str[i]);
			}
			if (str[i] == '\0')
				break;
		}
		i++;
	}
	return (str);
}

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

int	prev_is_heredoc(t_lexer *tmp)
{
	if (!tmp->prev)
		return (0);
	if (tmp->prev->token == LESS_LESS)
		return (1);
	else
		return (0);
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
