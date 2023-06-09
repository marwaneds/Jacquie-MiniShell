/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-faqu <mel-faqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:43:23 by mel-faqu          #+#    #+#             */
/*   Updated: 2023/06/08 12:46:51 by mel-faqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	count_pipes(t_lexer *lexer, t_data	*data)
{
	t_lexer	*tmp;
	
	tmp = lexer;
	data->pipes = 0;
	while (tmp)
	{
		if (tmp->token == PIPE)
			data->pipes++;
		tmp = tmp->next;
	}
}