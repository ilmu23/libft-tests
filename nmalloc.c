/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:11:40 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/05 14:19:21 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*malloc(size_t size)
{
	static size_t	allocs = 0;
	void			*out;

	if (allocs % 4 == 0 && allocs > 0)
		out = NULL;
	else
		out = calloc(size, 1);
	allocs++;
	return (out);
}
