/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:14:02 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/04 23:30:51 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	printtab(char **tab, size_t size);

int	main(void)
{
	char	**tab;

	printf("\e[1mChecking allocation failure\e[m\n\n");
	tab = ft_split("This,table,should,   ,return,,as, ,NULL, ,  ", ',');
	if (tab)
	{
		printf("\t\e[31mKO\n");
		printtab(tab, 10);
	}
	else
		printf("\t\e[32mOK\e[m\n");
	return (0);
}

void	printtab(char **tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (!tab[i])
			printf("\e[1m");
		printf("\ttab[%lu] -> %p", i, tab[i]);
		if (tab[i])
			printf("(\"%s\")", tab[i]);
		printf("\n");
		if (!tab[i])
			printf("\e[22m");
		i++;
	}
	printf("\e[m");
}
