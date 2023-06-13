#include "minishell.h"

// int	exec_builtins(t_data *data)
// {
// 	char	*builtin;

// 	builtin = data->simple_cmd->builtins;
// 	if (builtin == "cd")
// 		return (execute_cd(data, data->simple_cmd));
// 	if (builtin == "exit")
// 		return (execute_exit(data));
// 	if (builtin == "export")
// 		return (execute_export(data, data->simple_cmd));
// 	if (builtin == "unset")
// 		return (execute_unset(data, data->simple_cmd));
//	if (builtin == "PWD")
// 		return (execute_pwd(data, data->simple_cmd));
//	if (builtin == "echo")
// 		return (execute_echo(data, data->simple_cmd));
//	if (builtin == "env")
//		return (execute_env(data, data->simple_cmd));
// }

void	exec_cmd(t_simple_cmds *cmds, t_data *data)
{
	// int	value;
	(void)data;
	if (cmds->redirections)
		handle_redirections(cmds);
	// if (cmds->builtins)
	// {
	// 	value = exec_builtins(cmds, data);
	// 	exit(value);
	// }
}

void	single_cmd(t_data *data)
{
	int	pid;

	// if (is_builtin(data->simple_cmd->builtins))
		// exec_builtins(data);
	check_heredoc(data);
	pid = fork();
	if (pid == 0)
		exec_cmd(data->simple_cmd, data);
	waitpid(pid, NULL, 0);
}

void	executor(t_data *data)
{
	if (data->nb_pipes == 0)
		single_cmd(data);
}
