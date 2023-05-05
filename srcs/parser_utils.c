#include "minishell.h"

int ft_strcmp(const char *str1, const char *str2)
{
    int i = 0;

    while (str1[i] == str2[i])
	{
        if (str1[i] == '\0')
            return 0;
        i++;
    }
    return (int)(str1[i] - str2[i]);
}

int	is_builtin(char *command)
{
	int		j;
	char	*builtins[7];
	char	*command_trim;

	j = 0;
	builtins[0] = "echo";
	builtins[1] = "env";
	builtins[2] = "cd";
	builtins[3] = "pwd";
	builtins[4] = "export";
	builtins[5] = "unset";
	builtins[6] = "exit";
	command_trim = ft_strtrim(command, "\'\"");
	while (j < 7)
	{
		if (!ft_strcmp(builtins[j], command_trim))
				return (1);
		j++;
	}
	free(command_trim);
	return (0);
}
