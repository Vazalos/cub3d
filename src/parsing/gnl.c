/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:37:55 by gumendes          #+#    #+#             */
/*   Updated: 2025/09/17 10:58:04 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_gnl_free(char **ptr);
static char	*set_line(char *str);
static char	*fill_line(int fd, char *nxt, char *buf);

char	*gnl(int fd)
{
	char		*line;
	char		*buf;
	static char	*nxt;

	buf = malloc((100 + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	line = fill_line(fd, nxt, buf);
	ft_gnl_free(&buf);
	if (!line)
	{
		ft_gnl_free(&nxt);
		ft_gnl_free(&line);
		return (NULL);
	}
	nxt = set_line(line);
	return (line);
}

static void	ft_gnl_free(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

static char	*set_line(char *str)
{
	char	*nxt;
	size_t	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	nxt = ft_substr(str, i + 1, ft_strlen(str) - i);
	if (!nxt || nxt[0] == '\0')
	{
		ft_gnl_free(&nxt);
		return (NULL);
	}
	str[i + 1] = 0;
	return (nxt);
}

static char	*handle_read_error(int check, char **nxt)
{
	if (check == 0)
		return (*nxt);
	ft_gnl_free(nxt);
	return (NULL);
}

static char	*fill_line(int fd, char *nxt, char *buf)
{
	char		*str;
	int			check;

	check = 1;
	while (check > 0)
	{
		check = read(fd, buf, 100);
		if (check <= 0)
			return (handle_read_error(check, &nxt));
		buf[check] = '\0';
		if (!nxt)
			nxt = ft_strdup("");
		str = nxt;
		nxt = ft_strjoin(str, buf);
		ft_gnl_free(&str);
		if (!nxt)
			return (NULL);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (nxt);
}
