#include <minishell.h>

int	open_file(t_lexer *redirections)
{
	int	fd;

	if (redirections->token == GREAT_GREAT)
		fd = open(redirections->str, O_CREAT | O_RDWR | O_APPEND, 0644);
	else
		fd = open(redirections->str, O_CREAT | O_RDWR | O_TRUNC, 0644);
	return (fd);
}

int	handle_infile(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(1, "file does not exist\n", 20);
		return (1);
	}
	if (fd > 0)
	{
		if (dup2(fd, INFILE_STD) == -1)
			return (1);
	}
	close(fd);
	return (0);
}

int	handle_outfile(t_lexer *redirections)
{
	int	fd;

	fd = open_file(redirections);
	if (fd < 0)
	{
		write(1, "minishell: infile: No such file or directory\n", 45);
		return (1);
	}
	if (fd > 0)
	{
		if (dup2(fd, OUTFILE_STD))
			return (1);
	}
	return (0);
}

int	handle_redirections(t_simple_cmds *cmd)
{
	t_simple_cmds *head;

	head = cmd;
	if (cmd->redirections->token == LESS)
		if (handle_infile(cmd->redirections->str))
			return (1);
	if (cmd->redirections->token == GREAT || cmd->redirections->token == GREAT_GREAT)
		if (handle_outfile(cmd->redirections))
			return (1);
	if (cmd->redirections->token == LESS_LESS)
		if (handle_infile(head->hd_file_name))
			return (1);
	cmd->redirections = cmd->redirections->next;
	return (0);
}
