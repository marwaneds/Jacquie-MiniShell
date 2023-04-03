/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cortiz <cortiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 09:03:31 by cortiz            #+#    #+#             */
/*   Updated: 2023/04/03 09:04:04 by cortiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**tab_dup(char **tab)
{
	int		i;
	char	**tabdup;

	i = 0;
	while (tab[i])
		i++;
	tabdup = malloc(sizeof(char *) * i + 1);
	if (!tabdup)
		return (0);
	i = 0;
	while (tab[i])
	{
		tabdup[i] = ft_strdup(tab[i]);
		i++;
	}
	tabdup[i] = 0;
	return (tabdup);
}
