#include "minishell.h"

int	tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	ft_iswhitespace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

void	lexer_adback(t_lexer **lexer, t_lexer *new)
{
	t_lexer	*back;

	back = *lexer;
	if (!*lexer)
		*lexer = new;
	else
	{
		while (back->next)
			back = back->next;
		back->next = new;
		new->prev = back;
	}
	// printf("str = %s\nand\n", lexer->str);
	// printf("token = %d\n\n", lexer->token);
}