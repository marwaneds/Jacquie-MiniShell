#include "minishell.h"

int	error_cmd(int error, char *msg)
{
	ft_putstr_fd("[1]    17176 abort      ./minishell: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("command not found", 2);
	return (error);
}

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	if (tab)
	{
		while (tab[++i])
			free(tab[i]);
		free(tab);
	}
}

char	*get_cmd_path(char **env, char *cmd)
{
	char	**splited_path;
	char	*path;
	char	*tmp;
	char	*all_path;
	int		i;

	i = -1;
	all_path = get_all_path(env, "PATH");
	splited_path = ft_split(all_path, ':');
	while (splited_path[++i])
	{
		tmp = ft_strjoin(splited_path[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK) == 0)
		{
			free_tab(splited_path);
			return (path);
		}
		free(path);
	}
	free_tab(splited_path);
	return (NULL);
}