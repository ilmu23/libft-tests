/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hpatcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:39:47 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/07 16:59:16 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static void	ft_putstr_fd(const char *s, int fd);
static int	ft_strncmp(const char *s1, const char *s2, size_t n);
static int	closefiles(int fd1, int fd2);

int	main(int argc, char **argv)
{
	int		fd1;
	int		fd2;
	char	*line;

	if (argc < 3)
		return (1);
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_WRONLY | O_CREAT, 00644);
	if (fd1 < 0 || fd2 < 0)
		return (closefiles(fd1, fd2));
	line = get_next_line(fd1);
	while (line)
	{
		if (ft_strncmp("#endif", line, 6) == 0)
		{
			ft_putstr_fd("#define malloc nmalloc\n\n", fd2);
			ft_putstr_fd("void\t*nmalloc(size_t size);\n\n", fd2);
		}
		ft_putstr_fd(line, fd2);
		free(line);
		line = get_next_line(fd1);
	}
	return (closefiles(fd1, fd2));
}

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s1 == *s2 && n > 1)
	{
		s1++;
		s2++;
		n--;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

static int	closefiles(int fd1, int fd2)
{
	int	ret;

	ret = 0;
	if (fd1 < 0)
		ret++;
	else
		close(fd1);
	if (fd2 < 0)
		ret++;
	else
		close(fd2);
	return (ret);
}

static void	ft_putstr_fd(const char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
}
