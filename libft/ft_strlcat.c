/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 08:22:00 by bait-sli          #+#    #+#             */
/*   Updated: 2016/11/15 16:02:57 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	s1_end;

	i = 0;
	while (dst[i] && i < size)
		i++;
	s1_end = i;
	while (src[i - s1_end] && i < size - 1)
	{
		dst[i] = src[i - s1_end];
		i++;
	}
	if (s1_end < size)
		dst[i] = '\0';
	return (s1_end + ft_strlen((char *)src));
}
