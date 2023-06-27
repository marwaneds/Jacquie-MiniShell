#include "minishell.h"

void	c(t_data *data, int n)
{
	while (--n >= 0 && data->pipes[n])
	{
		close(data->pipes[n][0]);
		close(data->pipes[n][1]);
	}
}

int	init_pipes(t_data *data)
{
	int	i;

	i = 0;
	data->pipes = malloc(sizeof(int *) * (data->nb_pipes + 1));
	if (!data->pipes)
		return (0);
	data->pipes[data->nb_pipes] = NULL;
	while (i < data->nb_pipes)
	{
		data->pipes[i] = malloc(sizeof(int) * 2);
		if (!data->pipes[i])
			return (0);
		ft_memset(data->pipes[i], 0, sizeof(int) * 2);
		if (pipe(data->pipes[i]) == -1)
			return (0);
		i++;
	}
	return (1);
}

void	pre_redirect(t_data *data, int i)
{
	if (i == 0)
		dup2(data->pipes[i][1], 1);
	else
	{
		dup2(data->pipes[i - 1][0], 0);
		dup2(data->pipes[i][1], 1);
	}
}

void	create_child(t_data *data, t_simple_cmds *cmd, int i)
{
	data->pid[i] = fork();
	if (data->pid[i] == 0)
	{
		pre_redirect(data, i);
		exec_cmd(cmd, data);
	}
}

void	severals_cmds(t_data *data, t_simple_cmds *simple_cmd)
{
	int	i;

	if (!init_pipes(data))
	{
		return ;
	}
	i = 0;
	while (simple_cmd->next)
	{
		check_heredoc(simple_cmd);
		create_child(data, simple_cmd, i);
		i++;
		simple_cmd = simple_cmd->next;
	}
	waitpid(-1, NULL, 0);
}

void	executor(t_data *data)
{
	printf("dans l'execution\n");
	if (data->nb_pipes == 0)
	{
		printf("dans le single\n");
		single_cmd(data);
	}
	else
	{
		data->pid = malloc(sizeof(int) * data->nb_pipes + 1);
		if (!data->pid)
		{
			return ;
		}
		severals_cmds(data, data->simple_cmd);
	}
}
