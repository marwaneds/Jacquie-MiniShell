/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosortiz <carlosortiz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:53:13 by cortiz            #+#    #+#             */
/*   Updated: 2023/04/28 10:53:44 by carlosortiz      ###   ########.fr       */
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

	i = 0;
	y = 0;
	while (str[i])
	{
		fermer_utils(&i, '\"', str, &y);
		fermer_utils(&i, '\'', str, &y);
		if (!(str[i]))
			break;
		i++;
	}
	return (y);
}

int main(int ac, char **av, char **envp)
{
	t_data	*data;
	char	*tmp;

	(void)ac;
	(void)av;
	(void)envp;
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	while (1)
	{
		signal(SIGINT, c_handler);
		signal(SIGQUIT, SIG_IGN);
		// signal(SIGINT, handle_sigint);
		// signal(SIGQUIT, handle_sigquit);
		tmp = readline("[1]    17176 abort      ./minishell");
		if (checkfermer(tmp) % 2)
		{
			printf("oulala la grosse erreur\n");
			free(tmp);
			return(0);
		}
		add_history(tmp);
		init_lexer(ft_strtrim(tmp, " "), data);
		parser_init(data);
	}
	return (0);
}
