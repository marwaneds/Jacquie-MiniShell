/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   petitmain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cortiz <cortiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:08:09 by mel-faqu          #+#    #+#             */
/*   Updated: 2023/07/07 10:43:37 by cortiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft/libft.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int ft_strcmp(const char *str1, const char *str2)
{
    int i = 0;

    while (str1[i] == str2[i])
	{
        if (str1[i] == '\0')
		{
            return 0;
        }
        i++;
    }
    return (int)(str1[i] - str2[i]);
}

int	is_builtin(char *command)
{
	int		i;
	int		j;
	char	*builtins[7];
	char	*command_trim;

	i = 0;
	j = 0;
	builtins[0] = "echo";
	builtins[1] = "env";
	builtins[2] = "cd";
	builtins[3] = "pwd";
	builtins[4] = "export";
	builtins[5] = "unset";
	builtins[6] = "exit";
	command_trim = ft_strtrim(command, "\'\"");
	while (j < 7)
	{
		if (!ft_strcmp(builtins[j], command_trim))
				return (1);
		i = 0;
		j++;
	}
	free(command_trim);
	return (0);
}

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
	char *command = "echo";
	if (is_builtin(command))
		printf ("(%s) est un builtin\n", command);
	else
		printf("(%s) n'est pas un builtin\n", command);
}
