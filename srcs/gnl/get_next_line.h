/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cortiz <cortiz@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:29:46 by cortiz            #+#    #+#             */
/*   Updated: 2023/06/09 12:54:43 by cortiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*get_next_line(int fd);
char	*get_left_line(char *src);
char	*get_right_line(char *str);
char	*get_all_line(int fd, char *str);
int		has_nl(char *str);
char	*gnl_strjoin(char *str1, char *str2);
char	*free_all(char **str1);
size_t	gnl_strlen(char *str);

#endif