/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosortiz <carlosortiz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:53:13 by cortiz            #+#    #+#             */
/*   Updated: 2023/04/03 19:55:44 by carlosortiz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	checkfermer(char *str)
{
	int	i;
	int	cbontkt;

	i = -1;
	cbontkt = 0;
	while (str[++i])
	{
		if (str[i] == '\"')
		{
			cbontkt++;
			i++;
			while (str[i] != '\"' && str[i])
				i++;
			if (str[i] == '\"')
			{
				cbontkt++;
				i++;
			}
		}
		if (str[i] == '\'')
		{
			cbontkt++;
			i++;
			while (str[i] != '\'' && str[i])
				i++;
			if (str[i] == '\'')
				cbontkt++;
		}
	}
	return (cbontkt);
}

int main(int ac, char **av, char **envp)
{
	// t_data	data;
	char	*tmp;

	(void)ac;
	(void)av;
	(void)envp;
	// int	i = 0;
	while (1)
	{
		tmp = readline("Jacquie&Minishell <3 ");
		add_history(tmp);
		// printf("%d\n", checkfermer(tmp));
		if (checkfermer(tmp) % 2)
		{
			printf("oulala la grosse erreur\n");
			free(tmp);
		}
		// printf("%s\n", tmp);
	}
	// data.env = tab_dup(envp);
	// while (data.env[i])
	// {
	// 	printf("line %d -> %s\n", i + 1, data.env[i]);
	// 	i++;
	// }
	// data.path = get_all_path(envp, "PATH=");
	// data.pwd = get_all_path(envp, "PWD=");
	return (0);
}
