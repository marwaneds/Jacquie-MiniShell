#include "minishell.h"

// void	exec_builtins(t_data *data)
// {
// 	char	*builtin;

// 	builtin = data->simple_cmds->builtins;
// 	if (builtin == "cd")
// 		execute_cd(data, data->simple_cmds);
// 	if (builtin == "exit")
// 		execute_exit(data);
// 	if (builtin == "export")
// 		execute_export(data, data->simple_cmds);
// 	if (builtin == "unset")
// 		execute_unset(data, data->simple_cmds);
// }

// void	check_heredoc(t_data *data)
// {
// 	if (data->simple_cmds)
// }

// void	single_cmd(t_data *data)
// {
// 	// if (is_builtin(data->simple_cmds->builtins))
// 		// exec_builtins(data);
// 	check_heredoc(data);
// }

// void	executor(t_data *data)
// {
// 	if (data->nb_pipes == 0)
// 		single_cmd(data);
// }
