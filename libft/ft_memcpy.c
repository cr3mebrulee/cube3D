/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:31:22 by dbisko            #+#    #+#             */
/*   Updated: 2023/11/17 13:31:26 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*source_char_ptr;
	char		*dest_char_ptr;
	size_t		index;

	if ((dst == src) || n == 0)
		return (dst);
	if (!dst && !src)
		return (NULL);
	dest_char_ptr = (char *)dst;
	source_char_ptr = (const char *)src;
	index = 0;
	while (index < n)
	{
		dest_char_ptr[index] = source_char_ptr[index];
		index++;
	}
	return (dst);
}
