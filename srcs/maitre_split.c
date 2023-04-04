/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maitre_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cortiz <cortiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:24:25 by cortiz            #+#    #+#             */
/*   Updated: 2023/04/04 11:15:16 by cortiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_token(char c)
{
	if (c == '|')
		return (PIPE);
	if (c == '>')
		return (GREAT);
	if (c == '<')
		return (LESS);
	return (0);
}

static void	affiche(char **str)
{
	int i = 0;
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
}

void	add_lexer(char *str, t_data *data)
{
	char	**tmp;
	int		i;
	// int		token;

	i = -1;
	tmp = ft_split(str, ' ');
	while (tmp[++i])
	{
		if ((int)ft_strlen(tmp[i]) == is_token(*tmp[i]))
		{
			data->lexer.str = NULL;
			data->lexer.i = is_token(*tmp[i]);
		}
		else
			data->lexer.str = tmp[i];
	}
	affiche(&data->lexer.str);
}

