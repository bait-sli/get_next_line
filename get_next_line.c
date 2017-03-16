/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 12:46:20 by bait-sli          #+#    #+#             */
/*   Updated: 2017/02/02 16:22:22 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			ft_check_stock(char **stock, char **line)
{
	char			*tmp;

	tmp = NULL;
	if (*stock)
	{
		if ((tmp = ft_strchr((const char*)*stock, '\n')))
		{
			*line = ft_strsub((char const*)*stock, 0, tmp - *stock);
			ft_memmove(*stock, tmp + 1, ft_strlen(tmp));
			return (1);
		}
	}
	return (0);
}

static	int			cpy_fd_in_stock(int fd, char **stock, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	char			*tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		tmp = *stock;
		if (*stock)
		{
			*stock = ft_strjoin((char const*)tmp, (char const*)buf);
			free(tmp);
		}
		else
			*stock = ft_strdup((const char*)buf);
		if (ft_check_stock(stock, line))
			return (1);
	}
	return (0);
}

int					get_next_line(int const fd, char **line)
{
	static	char	*ret[FD_VALUE];
	int				result;

	if (!line || fd < 0)
		return (-1);
	if (ret[fd] && ft_check_stock(&ret[fd], line))
		return (1);
	result = cpy_fd_in_stock(fd, &ret[fd], line);
	if (result != 0)
		return (result);
	if (ret[fd] == NULL || ret[fd][0] == '\0')
		return (0);
	*line = ret[fd];
	ret[fd] = NULL;
	return (1);
}
