/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:18:13 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/07 14:48:45 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	int				rv;
	char			*out;

	out = NULL;
	rv = BUFFER_SIZE;
	while (rv > 0)
	{
		if (*buf)
			bufcopy(buf, &out);
		if (out)
			if (out[ft_strclen(out, '\0') - 1] == '\n')
				return (out);
		rv = read(fd, buf, BUFFER_SIZE);
		if (rv < 0)
		{
			if (out)
				free(out);
			*buf = '\0';
			return (NULL);
		}
	}
	return (out);
}
