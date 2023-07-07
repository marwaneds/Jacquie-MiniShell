#include "minishell.h"

int	prev_is_heredoc(t_lexer *tmp)
{
	if (!tmp->prev)
		return (0);
	if (tmp->prev->token == LESS_LESS)
		return (1);
	else
		return (0);
}

char	*word_after_dollar(int i, char *str,int *j)
{
	char	*index;

	i++;
	while (ft_isalnum(str[i + *j]))
		*j += 1;
	index = malloc(sizeof(char) * (*j + 1));
	index[*j] = 0;
	ft_memcpy(index, &str[i], *j);
	return (index);
}

char	*get_env_data(char *index, t_data *data)
{
	int		i;
	int		size;

	i = 0;
	while (data->env[i])
	{
		size = len_env_index(data->env[i]);
		// printf("VALEUR DE ENV LAAAAAAAAAAAA = %s\n", data->env[i]);
		if (!ft_strncmp(data->env[i], index, size) && size == (int)ft_strlen(index))
			return (&data->env[i][size + 1]);
		i++;
	}
	return (0);
}
