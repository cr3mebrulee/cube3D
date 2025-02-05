/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:33:13 by dbisko            #+#    #+#             */
/*   Updated: 2023/11/29 10:33:26 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	const char	*s1_copy;
	size_t		str_len;

	str_len = ft_strlen(s1);
	s1_copy = malloc((str_len +1) * sizeof(const char));
	if (s1_copy != NULL)
		ft_strlcpy((char *)s1_copy, s1, str_len + 1);
	return ((char *)s1_copy);
}
