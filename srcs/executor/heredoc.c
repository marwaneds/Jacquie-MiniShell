#include "minishell.h"

char	*generate_file()
{
	static int	i = 0;
	char		*num;
	char		*file;

	num = ft_itoa(++i);
	file = ft_strjoin("here_doc_tmp_", num);
	return (file);
}

int	create_heredoc(t_lexer *heredoc, t_simple_cmds *cmds)
{
	char	*tmp;
	int		fd;
	size_t	len;

	fd = open(cmds->hd_file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
	{
		// free et jme casse
		return (0);
	}
	while (1)
	{
		tmp = readline(">");
		len = ft_strlen(tmp);
		if (!ft_strncmp(tmp, heredoc->str, len) && (len == ft_strlen(heredoc->str)))
			break ;
		write(fd, tmp, ft_strlen(tmp));
		write(fd, "\n", 1);
		free(tmp);
	}
	free(tmp);
	close(fd);
	return (1);
}

void	check_heredoc(t_simple_cmds *cmds)
{
	t_lexer *head;

	head = cmds->redirections;
	while (cmds->redirections)
	{
		if (cmds->redirections->token == LESS_LESS)
		{
			cmds->hd_file_name = generate_file();
			if (!create_heredoc(cmds->redirections, cmds))
			{
				// free
				return ;
			}
		}
		cmds->redirections = cmds->redirections->next;
	}
	cmds->redirections = head;
}
