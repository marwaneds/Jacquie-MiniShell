#include "minishell.h"

int	exec_builtins(t_data *data)
{
	(void)data;
	return (0);
	// char	*builtin;

	// builtin = data->simple_cmd->builtins;
	// if (builtin == "cd")
	// 	return (execute_cd(data, data->simple_cmd));
	// if (builtin == "exit")
	// 	return (execute_exit(data));
	// if (builtin == "export")
	// 	return (execute_export(data, data->simple_cmd));
	// if (builtin == "unset")
	// 	return (execute_unset(data, data->simple_cmd));
	// if (builtin == "PWD")
	// 	return (execute_pwd(data, data->simple_cmd));
	// if (builtin == "echo")
	// 	return (execute_echo(data, data->simple_cmd));
	// if (builtin == "env")
	// 	return (execute_env(data, data->simple_cmd));
}

int	start_cmd(t_simple_cmds *cmds, t_data *data)
{
	char	*path;

	path = get_cmd_path(data->env, cmds->str[0]);
	if (!path)
		return (error_cmd(127, cmds->str[0]));
	execve(path, cmds->str, data->env);
	return (0);
}

void	exec_cmd(t_simple_cmds *cmds, t_data *data)
{
	int	value;

	value = 0;
	if (cmds->redirections)
		handle_redirections(cmds);
	if (cmds->builtins)
	{
		value = exec_builtins(data);
		exit(value);
	}
	else if (cmds->str[0][0])
		value = start_cmd(cmds, data);
	exit(value);
}

void	single_cmd(t_data *data)
{
	int	pid;
	int	status;

	// if (is_builtin(data->simple_cmd->builtins))
	// 	exec_builtins(data);
	check_heredoc(data);
	pid = fork();
	if (pid == 0)
		exec_cmd(data->simple_cmd, data);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
            global.return_value = WEXITSTATUS(status);
	// if (status == SIGINT || status == SIGQUIT)
	// 	set_status();
	// else
		// global = status / 256;
}
