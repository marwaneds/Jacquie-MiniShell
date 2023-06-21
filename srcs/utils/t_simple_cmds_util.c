/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_simple_cmds_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-faqu <mel-faqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:55:29 by mel-faqu          #+#    #+#             */
/*   Updated: 2023/06/20 12:13:42 by mel-faqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_simple_cmds	*simple_cmdsnew(char **str, int num_redirections,
	t_lexer *redirections)
{
	t_simple_cmds	*new_element;
	
	new_element = (t_simple_cmds *)malloc(sizeof(t_simple_cmds));
	if (!new_element)
		return (0);
	new_element->str = str;
	new_element->builtins = builtin_arr(str[0]);
	new_element->hd_file_name = NULL;
	new_element->num_redirections = num_redirections;
	new_element->redirections = redirections;
	new_element->next = NULL;
	new_element->prev = NULL;
	return (new_element);
}