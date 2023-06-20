#include "minishell.h"

void	executor(t_data *data)
{
	if (data->nb_pipes == 0)
		single_cmd(data);
	else
	{

	}
}
