#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft/libft.h"

char	**ft_free(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	tab = NULL;
	return (tab);
}

void	skip_quotes(int *i, char *str, char quote)
{
	*i += 1;
	while (str[*i] && str[*i] != quote)
		*i += 1;
	if (str[*i] == quote)
		*i += 1;
}



int main(int ac, char **av)
{
	char *str = "salut \"ca vas?\"\'mec?\'t ";
	// int		i;
	// int		j;
	// char	**str_splited;
	// char	*command;
	// int		tokken;

	// i = 0;
	// while (str[i])
	// {
	// 	while (ft_iswhitespace(str[i]))
	// 		i++;
	// 	if (str[i] == '\"')
	// 	{
	// 		j = i;
	// 		skip_quotes(j, str, '\"');
	// 	}
	// }
	char *tmp = ft_substr(str, 4, 1);
	if (tmp)
	{
		printf("ya\n");
		printf("[%s]\n", tmp);
	}
	else
	{
		printf("ya pas\n");
		printf("[%s]\n", tmp);
	}
}
