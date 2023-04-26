#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft/libft.h"

int ft_strcmp(const char *str1, const char *str2)
{
    int i = 0;

    while (str1[i] == str2[i])
	{
        if (str1[i] == '\0')
		{
            return 0;
        }
        i++;
    }
    return (int)(str1[i] - str2[i]);
}

// int is_builtin(char *command) 
// {
// 	char *builtins[] = {"echo", "env"};
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (command[i] == '\'' || command[i] == '\"')
// 		i++;
// 	if (!ft_strncmp("echo", &command[i], ft_strlen("echo")) &&
// 		(ft_strlen(&command[i]) - i) == ft_strlen("echo"))
// 		return (1);
// 	if (!ft_strncmp("cd", &command[i], ft_strlen("echo")) &&
// 		(ft_strlen(&command[i]) - i) == ft_strlen("echo"))
// 		return (1);
// 	if (!ft_strncmp("pwd", &command[i], ft_strlen("echo")) &&
// 		(ft_strlen(&command[i]) - i) == ft_strlen("echo"))
// 		return (1);
// 	if (!ft_strncmp("export", &command[i], ft_strlen("echo")) &&
// 		(ft_strlen(&command[i]) - i) == ft_strlen("echo"))
// 		return (1);
// 	if (!ft_strncmp("unset", &command[i], ft_strlen("echo")) &&
// 		(ft_strlen(&command[i]) - i) == ft_strlen("echo"))
// 		return (1);
// 	if (!ft_strncmp("env", &command[i], ft_strlen("echo")) &&
// 		(ft_strlen(&command[i]) - i) == ft_strlen("echo"))
// 		return (1);
// 	if (!ft_strncmp("exit", &command[i], ft_strlen("echo")) &&
// 		(ft_strlen(&command[i]) - i) == ft_strlen("echo"))
// 		return (1);
// 	return (0);
// }

int	is_builtin(char *command) 
{
	char	*builtins[7];

	builtins = {"echo", "env", "cd", "pwd", "export", "unset", "exit"};
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < 7)
	{
		while (command[i] == '\'' || command[i] == '\"')
			i++;
		if (!ft_strncmp(builtins[j], &command[i], ft_strlen(builtins[j]))
			&& (ft_strlen(&command[i]) - i) == ft_strlen(builtins[j]))
			return (1);
		i = 0;
		j++;
	}
	return (0);
}

char	**ft_free(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	tab = NULL;
	return (tab);
}

void	skip_quotes(int *i, char *str, char quote)
{
	*i += 1;
	while (str[*i] && str[*i] != quote)
		*i += 1;
	if (str[*i] == quote)
		*i += 1;
}

int main(int ac, char **av)
{
	char *command = "\"\"\"\"\"exit\"";
	if (is_builtin(command))
		printf ("(%s) est un builtin\n", command);
	else
		printf("(%s) n'est pas un builtin\n", command);
}
