#include <minishell.h>

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
		dup2(fd, INFILE_STD);
	}
	return (0);
}

int	handle_redirections(t_simple_cmds *cmd)
{
	t_lexer *head;

	head = cmd->redirections;
	if (head->token == LESS)
	{
		if (handle_infile(head->str))
			return (1);
	}
	return (0);
}
