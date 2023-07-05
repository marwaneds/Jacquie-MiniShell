/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cortiz <cortiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:53:13 by cortiz            #+#    #+#             */
/*   Updated: 2023/07/05 09:36:33 by cortiz           ###   ########.fr       */
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

void	init_data(t_data *data, char *tmp, char **envp)
{
	init_lexer(ft_strtrim(tmp, " "), data);
	data->env = tab_cpy(envp);
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
		tmp = readline("[1]    17176 abort      ./minishell ");
		if (checkfermer(tmp) % 2)
		{
			printf("oulala la grosse erreur\n");
			free(tmp);
			return(0);
		}
		add_history(tmp);
		init_data(data, tmp, envp);
		// expander(data);
		// parser_init(data);
		data->simple_cmd = malloc(sizeof(t_simple_cmds));
		data->simple_cmd->builtins = NULL;
		data->simple_cmd->hd_file_name = NULL;
		data->simple_cmd->redirections = malloc(sizeof(t_lexer));
		data->simple_cmd->redirections->token = LESS_LESS;
		data->simple_cmd->redirections->str = "salut";
		data->simple_cmd->redirections->next = malloc(sizeof(t_lexer));
		data->simple_cmd->redirections->next->token = GREAT;
		data->simple_cmd->redirections->next->str = "teste";
		data->simple_cmd->redirections->next->next = NULL;
		data->simple_cmd->str = ft_split("cat", ' ');

		data->simple_cmd->next = malloc(sizeof(t_simple_cmds));
		data->simple_cmd->next->builtins = NULL;
		data->simple_cmd->next->hd_file_name = NULL;
		data->simple_cmd->next->redirections = malloc(sizeof(t_lexer));
		data->simple_cmd->next->redirections->token = LESS_LESS;
		data->simple_cmd->next->redirections->str = "bye";
		data->simple_cmd->next->redirections->next = malloc(sizeof(t_lexer));
		data->simple_cmd->next->redirections->next->token = GREAT;
		data->simple_cmd->next->redirections->next->str = "testdeu";
		data->simple_cmd->next->redirections->next->next = NULL;
		data->simple_cmd->next->str = ft_split("cat", ' ');
		// data->nb_pipes = 1;
		// data->simple_cmd->next->next = NULL;
		
		data->simple_cmd->next->next = malloc(sizeof(t_simple_cmds));
		data->simple_cmd->next->next->builtins = NULL;
		data->simple_cmd->next->next->hd_file_name = NULL;
		// data->simple_cmd->next->next->redirections = malloc(sizeof(t_lexer));
		// data->simple_cmd->next->next->redirections->token = GREAT;
		// data->simple_cmd->next->next->redirections->str = "OUT";
		data->simple_cmd->next->next->redirections = NULL;
		// data->simple_cmd->next->next->redirections->next = NULL;
		data->simple_cmd->next->next->str = ft_split("ls", ' ');
		data->nb_pipes = 2;
		data->simple_cmd->next->next->next = NULL;
		executor(data);
		printf("on est la\n");
		break;
	}
	return (0);
}
