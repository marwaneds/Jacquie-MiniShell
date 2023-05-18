/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cortiz <cortiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:17:30 by cortiz            #+#    #+#             */
/*   Updated: 2023/05/17 20:17:31 by cortiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	**tab_cpy(char **src)
{
	char	**dest;
	int		size;
	int		i;

	size = tab_len(src);
	dest = (char **)malloc((size + 1) * sizeof(char *));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dest[i] = ft_strdup(src[i]);
		if (dest[i] == NULL)
		{
			while (--i >= 0)
				free(dest[i]);
			free(dest);
			return (NULL);
		}
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

int	ft_iswhitespace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

void	lexer_adback(t_lexer **lexer, t_lexer *new)
{
	t_lexer	*back;

	back = *lexer;
	if (!*lexer)
		*lexer = new;
	else
	{
		while (back->next)
			back = back->next;
		back->next = new;
		new->prev = back;
	}
	// printf("str = %s\nand\n", lexer->str);
	// printf("token = %d\n\n", lexer->token);
}
char	*exp_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;
	int		j;
	int		len1;
	int		len2;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ret = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!ret)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j])
		ret[i++] = s2[j++];
	ret[i] = '\0';
	free((void *)s1);
	return (ret);
}
