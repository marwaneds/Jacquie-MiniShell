#include "minishell.h"

// void	exec_builtins(t_data *data)
// {
// 	char	*builtin;

// 	builtin = data->simple_cmd->builtins;
// 	if (builtin == "cd")
// 		execute_cd(data, data->simple_cmd);
// 	if (builtin == "exit")
// 		execute_exit(data);
// 	if (builtin == "export")
// 		execute_export(data, data->simple_cmd);
// 	if (builtin == "unset")
// 		execute_unset(data, data->simple_cmd);
// }

void	exec_cmd(t_simple_cmds *cmds)
{
	if (cmds->redirections)
		handle_redirections(cmds);
	// if (cmds->builtins)
	// 	exec_builtins();

}

void	single_cmd(t_data *data)
{
	int	pid;

	// if (is_builtin(data->simple_cmd->builtins))
		// exec_builtins(data);
	check_heredoc(data);
	pid = fork();
	if (pid == 0)
		exec_cmd(data->simple_cmd);
}

void	executor(t_data *data)
{
	if (data->nb_pipes == 0)
		single_cmd(data);
}
