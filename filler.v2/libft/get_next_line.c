/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 12:37:23 by allallem          #+#    #+#             */
/*   Updated: 2018/01/27 17:01:04 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_tmpjoin(char *tmp, char *buffer)
{
	char *dr_freeman;

	dr_freeman = tmp;
	tmp = ft_strjoin(tmp, buffer);
	free(dr_freeman);
	return (tmp);
}

static	int		ft_add(t_gnlist *point, int fd)
{
	t_gnlist		*new;

	if (!(new = malloc(sizeof(t_gnlist) * 1)))
		return (0);
	new->previous = point;
	new->fd = fd;
	new->tmp = NULL;
	new->next = NULL;
	if (!(new->tmp = ft_memalloc(1)))
	{
		free(new);
		return (0);
	}
	point->next = new;
	return (1);
}

static	int		ft_check(char *tmp, char **line, int *j, int iread)
{
	int i;

	i = 0;
	while (tmp[i] != '\n' && tmp[i])
		i++;
	if (tmp[i] == '\n' || (tmp[i] == '\0' && iread < BUFF_SIZE))
	{
		*line = ft_strsub(tmp, 0, i);
		*j = i;
		return (1);
	}
	return (0);
}

static	int		ft_putinline(const int fd, char **line, t_gnlist *point)
{
	char	*buffer;
	char	*dr_freeman;
	int		i;
	int		j;

	i = BUFF_SIZE;
	if (!(buffer = ft_memalloc(BUFF_SIZE + 1)))
		return (-1);
	while (!(ft_check(point->tmp, line, &j, i)))
	{
		if ((i = read(fd, buffer, BUFF_SIZE)) < 0)
			return (-1);
		buffer[i] = '\0';
		point->tmp = ft_tmpjoin(point->tmp, buffer);
		if (i == 0 && point->tmp[0] == '\0')
		{
			*line = NULL;
			return (0);
		}
	}
	free(buffer);
	dr_freeman = point->tmp;
	point->tmp = ft_strsub(point->tmp, j + 1, ft_strlen(point->tmp) - j);
	free(dr_freeman);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnlist	*point;

	if (!point)
	{
		if (!(point = malloc(sizeof(t_gnlist) * 1)))
			return (-1);
		point->tmp = NULL;
		point->next = NULL;
		point->fd = fd;
		point->previous = NULL;
		if (!(point->tmp = ft_memalloc(1)))
			return (-1);
	}
	while (point->previous != NULL && point->fd != fd)
		point = point->previous;
	while (point->fd != fd && point->next != NULL)
		point = point->next;
	if (point->next == NULL && point->fd != fd)
	{
		if (!ft_add(point, fd))
			return (-1);
		point = point->next;
	}
	return (ft_putinline(fd, line, point));
}
