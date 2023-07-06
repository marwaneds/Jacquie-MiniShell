/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lexer_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-faqu <mel-faqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:33:36 by mel-faqu          #+#    #+#             */
/*   Updated: 2023/07/06 14:20:57 by mel-faqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Creer un nouveau lexer	*/
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

/*	Free un tableau	*/
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

/*	reset les datas	*/
int	reset_tools(t_data *data)
{
	simple_cmdsclear(&data->simple_cmd);
	free(data->args);
	if (data->pid)
		free(data->pid);
	free_arr(data->path);
	implement_tools(data);
	data->reset = 1;
	minishell_loop(data);
	return (1);
}
   