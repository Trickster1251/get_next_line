/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 21:35:25 by walethea          #+#    #+#             */
/*   Updated: 2020/12/02 18:40:30 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

int			get_next_line(int fd, char	**line);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(char *str);
char		*ft_strjoin(char *s1, const char *s2);
char		*ft_strdup(const char *src);
char		*ft_strchr(const char *str, int symbol);

#endif
