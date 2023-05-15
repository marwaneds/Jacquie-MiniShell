/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosortiz <carlosortiz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 06:46:40 by cortiz            #+#    #+#             */
/*   Updated: 2023/05/14 13:29:33 by carlosortiz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_quote(char c)
{
	return (c == '"' | c == '\'');
}

// char	*get_env_data(char *index)
// {
	
// }

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

void	handle_quotes(char *str)
{
	int		i;
	// int		j;
	// int		inquotes;
	// char	*env_data;
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
					// i++;
					// while (ft_isalpha(str[i + j]))
					// 	j++;
					// index = malloc(sizeof(char) * (j + 1));
					// index[j] = 0;
					// strncpy(index, &str[i], j);
					index = word_after_dollar(i, str);
					printf("%s\n", index);
					// env_data = get_env_data();
				}
				i++;
			}
		}
		i++;
	}
}

void	expander(t_lexer *lexer)
{
	t_lexer	*tmp;

	tmp = lexer;
	while (tmp)
	{
		handle_quotes(tmp->str);
		tmp = tmp->next;
	}
}
