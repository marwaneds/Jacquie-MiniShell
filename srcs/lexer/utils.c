#include "minishell.h"

void printList(t_lexer *head)
{
    t_lexer *current = head;
    while (current != NULL)
	{
        printf("[%s]\n", current->str);
        printf("[%d]\n\n", current->i);
        current = current->next;
    }
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

int	is_token(char c)
{
	return (c == '<' ||  c == '>' || c == '|');
}
