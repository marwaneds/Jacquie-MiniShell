/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cortiz <cortiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 06:46:40 by cortiz            #+#    #+#             */
/*   Updated: 2023/05/11 11:43:32 by cortiz           ###   ########.fr       */
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

void	handle_quotes(char *str)
{
	int		i;
	int		j;
	// char	*env_data;
	char	*index;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '"')
		{
			i++;
			while (str[i] != '"')
			{
				if (str[i] == '$')
				{
					i++;
					while (ft_isalpha(str[i + j]))
						j++;
					index = malloc(sizeof(char) * (j + 1));
					index[j] = 0;
					strncpy(index, &str[i], j);
					printf("%s\n", index);
					// env_data = get_env_data();
				}
				i++;
			}
		}
		// if (str[i] == '\'')
		// {
			
		// }
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
