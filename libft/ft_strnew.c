/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 02:49:30 by bait-sli          #+#    #+#             */
/*   Updated: 2016/11/19 01:44:29 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*buffer;
	size_t	mem;
	size_t	i;

	mem = size + 1;
	if ((buffer = (char *)malloc(mem)) == 0)
		return (NULL);
	i = 0;
	while (i < mem)
	{
		buffer[i] = '\0';
		i++;
	}
	return (buffer);
}
