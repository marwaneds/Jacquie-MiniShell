/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cortiz <cortiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:53:13 by cortiz            #+#    #+#             */
/*   Updated: 2023/04/04 11:06:40 by cortiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_all_path(char **envp, char *get)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(get, envp[i], ft_strlen(get)) == 0)
			return (&envp[i][ft_strlen(get)]);
		i++;
	}
	return (0);
}

static void fermer_utils(int *i, char quote, char *str, int *y)
{
	if (str[*i] == quote)
		{
			*y += 1;
			*i += 1;
			while (str[*i] != quote && str[*i])
				*i += 1;
			if (str[*i] == quote)
				*y += 1;
		}
}

int	checkfermer(char *str)
{
	int	i;
	int	y;

	i = -1;
	y = 0;
	while (str[++i])
	{
		fermer_utils(&i, '\"', str, &y);
		fermer_utils(&i, '\'', str, &y);
	}
	return (y);
}

int main(int ac, char **av, char **envp)
{
	t_data	data;
	char	*tmp;

	(void)ac;
	(void)av;
	(void)envp;
	// int	i = 0;
	while (1)
	{
		tmp = readline("Jacquie&Minishell <3 ");
		add_history(tmp);
		add_lexer(tmp, &data);
		if (checkfermer(tmp) % 2)
		{
			printf("oulala la grosse erreur\n");
			free(tmp);
		}
	}
	return (0);
}
