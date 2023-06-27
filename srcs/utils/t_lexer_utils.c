/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lexer_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-faqu <mel-faqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:33:36 by mel-faqu          #+#    #+#             */
/*   Updated: 2023/06/27 16:01:50 by mel-faqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer	*lexer_new(char *str, int token)
{
	t_lexer		*new_element;
	static int	i;

	i = 0;
	new_element = (t_lexer *)malloc(sizeof(t_lexer));
	if (!new_element)
		return (0);
	new_element->str = str;
	new_element->token = token;
	new_element->i = i++;
	new_element->next = NULL;
	new_element->prev = NULL;
	return (new_element);
}

void	free_arr(char **split_arr)
{
	int	i;

	i = 0;
	while (split_arr[i])
	{
		free(split_arr[i]);
		i++;
	}
	free(split_arr);
}

int	reset_tools(t_data *data)
{
	simple_cmdsclear(&data->simple_cmds);
	free(data->args);
	if (data->pid)
		free(data->pid);
	free_arr(data->paths);
	implement_tools(data);
	data->reset = TRUE;
	minishell_loop(data);
	return (1);
}
