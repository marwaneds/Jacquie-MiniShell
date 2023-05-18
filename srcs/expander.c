/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cortiz <cortiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 06:46:40 by cortiz            #+#    #+#             */
/*   Updated: 2023/05/18 14:33:59 by cortiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_quote(char c)
{
	return (c == '"' | c == '\'');
}

char	*get_env_data(char *index, t_data *data)
{
	int		i;
	int		size;

	size = ft_strlen(index);
	i = 0;
	while (data->env[i])
	{
		if (!ft_strncmp(data->env[i], index, size))
			return (&data->env[i][size + 1]);
		i++;
	}
	return (0);
}

char	*word_after_dollar(int i, char *str,int *j)
{
	char	*index;

	i++;
	while (ft_isalpha(str[i + *j]))
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
	printf("first part : %s\n", expanded);
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
	// int		inquotes;
	char	*env_data;
	char	*index;

	// inquotes = 0;
	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '"')
		{
			i++;
			while (str[i] != '"')
			{
				if (str[i] == '$' && str[i + 1] != ' ' && str[i + 1] != '\0' && str[i + 1] != '\"' && ft_isalpha(str[i + 1]))
				{
					j = 0;
					index = word_after_dollar(i, str, &j);
					printf("word after dollar = %s\n", index);
					env_data = get_env_data(index, data);
					printf("value of %s = %s\n", index, env_data);
					printf("valeur de i%d\n", i);
					printf("valeur de j%d\n", j);
					str = expand(&i, i + j, str, env_data);
					// str = remove_quotes(str);
					// printf("mon STR VAUT : %s\n", str);
					// i += j;
				}
				i++;
			}
		}
		i++;
	}
	return (str);
}

void	expander(t_data *data)
{
	t_lexer	*tmp;

	tmp = data->lexer;
	while (tmp)
	{
		if (tmp->str)
			tmp->str = handle_quotes(tmp->str, data);
		printf("mon str = %s\n", tmp->str);
		tmp = tmp->next;
	}
}
