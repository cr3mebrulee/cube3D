/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:40:39 by dbisko            #+#    #+#             */
/*   Updated: 2023/11/17 13:40:43 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_pnt_new;
	unsigned char	*src_pnt_new;

	if (!dst && !src)
		return (NULL);
	dst_pnt_new = (unsigned char *)dst;
	src_pnt_new = (unsigned char *)src;
	if (src_pnt_new < dst_pnt_new && dst_pnt_new < src_pnt_new + len)
	{
		while (len--)
			dst_pnt_new[len] = src_pnt_new[len];
	}
	else
	{
		while (len--)
		{
			*dst_pnt_new = *src_pnt_new;
			dst_pnt_new++;
			src_pnt_new++;
		}
	}
	return (dst);
}
