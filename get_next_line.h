/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 01:17:10 by jonnavar          #+#    #+#             */
/*   Updated: 2024/08/01 01:17:21 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef LAST_FD
#  define LAST_FD 256
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*gnl_contains(const char *string, char character);
size_t	gnl_length(const char *string);
char	*gnl_concat(const char *source, const char *destination);
char	*gnl_copy(const char *string);
char	*gnl_cut(const char *string, size_t start, size_t length);

#endif
