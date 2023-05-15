/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cortiz <cortiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 06:46:40 by cortiz            #+#    #+#             */
/*   Updated: 2023/05/15 11:24:08 by cortiz           ###   ########.fr       */
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

char	*word_after_dollar(int i, char *str)
{
	char	*index;
	int		j;

	j = 0;
	i++;
	while (ft_isalpha(str[i + j]))
		j++;
	index = malloc(sizeof(char) * (j + 1));
	index[j] = 0;
	strncpy(index, &str[i], j);
	return (index);
}

void	handle_quotes(char *str, t_data *data)
{
	int		i;
	// int		j;
	// int		inquotes;
	char	*env_data;
	char	*index;

	// inquotes = 0;
	// j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '"')
		{
			i++;
			while (str[i] != '"')
			{
				if (str[i] == '$' && str[i] != ' ' && str[i] != '\0')
				{
					index = word_after_dollar(i, str);
					printf("word after dollar = %s\n", index);
					env_data = get_env_data(index, data);
					printf("value of %s = %s\n", index, env_data);
				}
				i++;
			}
		}
		i++;
	}
}

void	expander(t_data *data)
{
	t_lexer	*tmp;

	tmp = data->lexer;
	while (tmp)
	{
		handle_quotes(tmp->str, data);
		tmp = tmp->next;
	}
}
