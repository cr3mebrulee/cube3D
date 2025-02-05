/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:44:16 by dbisko            #+#    #+#             */
/*   Updated: 2023/11/20 12:44:22 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dest_size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	total_len;
	size_t	index;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	total_len = dest_len + src_len;
	index = dest_len;
	if (dest_size <= dest_len)
		return (dest_size + src_len);
	while (src[index - dest_len] && index < dest_size - 1)
	{
		dest[index] = src[index - dest_len];
		index++;
	}
	dest[index] = '\0';
	return (total_len);
}
