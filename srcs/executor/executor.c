#include "minishell.h"

void	severals_cmds(t_data *data, t_simple_cmds *simple_cmd)
{
	while (simple_cmd->next)
	{
		(void)data;
		simple_cmd = simple_cmd->next;
	}
}

void	executor(t_data *data)
{
	if (data->nb_pipes == 0)
		single_cmd(data);
	else
	{
		severals_cmds(data, data->simple_cmd);
	}
}
