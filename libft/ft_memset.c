/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 07:00:24 by bait-sli          #+#    #+#             */
/*   Updated: 2016/11/12 09:34:24 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	arm;
	unsigned char	*str;

	str = (unsigned char *)b;
	i = 0;
	arm = (unsigned char)c;
	while (i < len)
	{
		str[i] = arm;
		i++;
	}
	return (b);
}
