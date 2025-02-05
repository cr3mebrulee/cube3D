/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:01:28 by dbisko            #+#    #+#             */
/*   Updated: 2023/11/20 15:01:30 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	index;

	index = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)(s + index));
	index--;
	while (index != (size_t) -1)
	{
		if (s[index] == (char)c)
			return ((char *)s + index);
		index--;
	}
	return (NULL);
}
