/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maitre_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosortiz <carlosortiz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:24:25 by cortiz            #+#    #+#             */
/*   Updated: 2023/04/15 14:22:20 by carlosortiz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_token(char c)
{
	return (c == '<' ||  c == '>' || c == '|');
}

int	get_token(char *str, int *i, int *tokken)
{
	if (str[*i] == '<' && str[*i + 1] == '<')
		*tokken = LESS_LESS;
	else if (str[*i] == '>' && str[*i + 1] == '>')
		*tokken = GREAT_GREAT;
	else if (str[*i] == '>')
		*tokken = GREAT;
	else if (str[*i] == '<')
		*tokken = LESS;
	else if (str[*i] == '|')
		*tokken = PIPE;
	else
		*tokken = 0;
	if (*tokken == LESS_LESS || *tokken == GREAT_GREAT)
		*i += 2;
	else if (*tokken)
		*i += 1;
	return (*tokken);
}

// static void	affiche(char **str)
// {
// 	int i = 0;
// 	while (str[i])
// 	{
// 		printf("%s\n", str[i]);
// 		i++;
// 	}
// }

void printList(t_lexer *head) {
    t_lexer *current = head;
    while (current != NULL) {
        printf("[%s]\n", current->str);
        printf("[%d]\n\n", current->i);
        current = current->next;
    }
}

void	add_node(t_lexer **lexer, char *str, int tokken)
{
	t_lexer 	*tmp;
	static int	i = 0;

	tmp = (t_lexer *)malloc(sizeof(t_lexer));
	if (!tmp)
		exit(1); //FO FREE
	tmp->str = str;
	tmp->token = tokken;
	tmp->i = i;
	tmp->next = NULL;
	tmp->prev = NULL;
	lexer_adback(lexer, tmp);
	i++;
}

void	skip_quotes(int *i, char *str, char quote)
{
	if (str[*i] == quote)
	{
		*i += 1;
		while (str[*i] && str[*i] != quote)
			*i += 1;
		// if (str[*i] == quote)
		// 	*i += 1;
	}
}

void	add_word(char *str, int *i, t_data *data)
{
	int		j;
	char	*tmp;

	j = *i;
	while (!is_token(str[j]) && !ft_iswhitespace(str[j]) && str[j])
	{
		skip_quotes(&j, str, '\'');
		skip_quotes(&j, str, '\"');
		j++;
	}
	tmp = ft_substr(str, *i, j - *i);
	if (tmp)
		add_node(&data->lexer, tmp, 0);
	*i = j;
}

void	init_lexer(char *str, t_data *data)
{
	int		i;
	int		tokken;

	i = 0;
	tokken = 0;
	data->lexer = NULL;
	while (str[i])
	{
		while (ft_iswhitespace(str[i]))
			i++;
		if (get_token(str, &i, &tokken))
			add_node(&data->lexer, NULL, tokken);
		else
			add_word(str, &i, data);
	}
	printList(data->lexer);
}
