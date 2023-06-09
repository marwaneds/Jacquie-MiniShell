/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lexer_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-faqu <mel-faqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:54:42 by mel-faqu          #+#    #+#             */
/*   Updated: 2023/06/09 11:31:45 by mel-faqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer	*lexer_clearone(t_lexer	**lst)
{
	if ((*lst)->str)
	{
		free((*lst)->str);
		(*lst)->str = NULL;
	}
	free(*lst);
	*lst = NULL;
	return (NULL);
}

//delete the first element of a list
void	lexer_delfirst(t_lexer **lst)
{
	t_lexer	*node;

	node = *lst;
	*lst = node->next;
	lexer_clearone(&node);
	if (*lst)
		(*lst)->prev = NULL;
}

//Remove element at location 'key'
void	lexer_delone(t_lexer **lst, int key)
{
	t_lexer	*node;
	t_lexer	*prev;
	t_lexer	*start;
	
	start = *lst;
	node = start;
	if ((*lst)->i == key)
	{
		lexer_delfirst(lst);
		return ;
	}
	while (node && node->i != key)
	{
		prev = node;
		node = node->next;
	}
	if (node)
		prev->next = node->next;
	else
		prev->next = node->next;
	if (prev->next)
		prev->next->prev = prev;
	lexer_clearone(&node);
	*lst = start;
}

//Removes items from lexer
void	lexer_clear(t_lexer **lst)
{
	t_lexer *tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		if ((*lst)->str)
			free((*lst)->str);
		free((*lst));
		*lst = tmp;
	}
	*lst = NULL;
}