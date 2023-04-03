/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cortiz <cortiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:53:13 by cortiz            #+#    #+#             */
/*   Updated: 2023/04/03 12:01:33 by cortiz           ###   ########.fr       */
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

	i = 0;
	cbontkt = 0;
	while(str[i])
	{
		if (str[i] == '\"');
			cbontkt++;
	}
	return (cbontkt);
}

int main(int ac, char **av, char **envp)
{
	t_data	data;
	char	*tmp;

	int	i = 0;
	while (1)
	{
		tmp = readline("Jacquie&Minishell <3 ");
		add_history(tmp);
		printf("%s\n", tmp);
	}
	ac = 0;
	av = NULL;
	data.env = tab_dup(envp);
	while (data.env[i])
	{
		printf("line %d -> %s\n", i + 1, data.env[i]);
		i++;
	}
	data.path = get_all_path(envp, "PATH=");
	data.pwd = get_all_path(envp, "PWD=");
	return (0);
}
